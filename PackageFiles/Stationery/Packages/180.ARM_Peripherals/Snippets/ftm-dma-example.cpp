/**
 ============================================================================
 * @file ftm-dma-example.cpp (180.ARM_Peripherals/Snippets)
 * @brief   FTM example using DMA
 *
 *  Created on: 19 Jun 2018
 *      Author: podonoghue
 ============================================================================
 */
#include <algorithm>    // std::max
#include "hardware.h"
#include "dma.h"

using namespace USBDM;

// LED
using Led = GpioC<3,ActiveLow>;

// Timer being used - change as required
using Timer = Ftm0;

// Timer channel being used - change as required
using TimerChannel = Ftm0Channel<7>;

// DMA channel number to use (must agree with PIT channel used)
static constexpr DmaChannelNum DMA_CHANNEL = DmaChannelNum_1;

// Slot number to use (must agree with FTM channel used)
static constexpr DmaSlot DMA_SLOT = static_cast<DmaSlot>(Dma0Slot_FTM0_Ch0+TimerChannel::CHANNEL);

// Waveform to generate
static uint16_t data[4]= {};

/**
 * @verbatim
 * +------------------------------+            Simple DMA mode (MLNO = Minor Loop Mapping Disabled)
 * | Major Loop =                 |            ==================================================
 * |    CITER x Minor Loop        |
 * |                              |            Each DMA request triggers a minor-loop transfer sequence.
 * | +--------------------------+ |<-DMA Req.  The minor loops are counted in the major-loop.
 * | | Minor Loop               | |
 * | | Each transfer            | |            The following are used during a minor loop:
 * | |   SADDR->DADDR           | |             - SADDR Source address
 * | |   SADDR += SOFF          | |             - SOFF  Adjustment applied to SADDR after each transfer
 * | |   DADDR += DOFF          | |             - DADDR Destination address
 * | | Total transfer is NBYTES | |             - DOFF  Adjustment applied to DADDR after each transfer
 * | +--------------------------+ |             - NBYTES Number of bytes to transfer
 * | +--------------------------+ |<-DMA Req.   - Attributes
 * | | Minor Loop               | |               - ATTR_SSIZE, ATTR_DSIZE Source and destination transfer sizes
 * |..............................|               - ATTR_SMOD, ATTR_DMOD Modulo --TODO
 * | |                          | |
 * | +--------------------------+ |             The number of reads and writes done will depend on NBYTES, SSIZE and DSIZE
 * | +--------------------------+ |<-DMA Req.   For example: NBYTES=12, SSIZE=16-bits, DSIZE=32-bits => 6 reads, 3 writes
 * | | Minor Loop               | |             NBYTES must be an even multiple of SSIZE and DSIZE in bytes.
 * | | Each transfer            | |
 * | |   SADDR->DADDR           | |            The following are used by the major loop
 * | |   SADDR += SOFF          | |             - SLAST Adjustment applied to SADDR at the end of each major loop
 * | |   DADDR += DOFF          | |             - DLAST Adjustment applied to DADDR at the end of each major loop
 * | | Total transfer is NBYTES | |             - CITER Major loop counter - counts how many completed major loops
 * | +--------------------------+ |
 * |                              |            SLAST and DLAST may be used to reset the addresses to the initial value or
 * | At end of Major Loop         |            link to the next transfer.
 * |    SADDR += SLAST            |            The total transferred for the entire sequence is CITER x NBYTES.
 * |    DADDR += DLAST            |
 * |                              |            Important options in the CSR:
 * | Total transfer =             |              - DMA_CSR_INTMAJOR = Generate interrupt at end of Major-loop
 * |    CITER*NBYTES              |              - DMA_CSR_DREQ     = Clear hardware request at end of Major-loop
 * +------------------------------+              - DMA_CSR_START    = Start transfer. Used for software transfers. Automatically cleared.
 * @endverbatim
 *
 * Structure to define a DMA transfer
 */
static const DmaTcd tcd {
   /* uint32_t  SADDR  Source address        */ (uint32_t)(data),                         // Source array
   /* uint16_t  SOFF   SADDR offset          */ sizeof(data[0]),                          // SADDR advances 1 byte for each request
   /* uint16_t  ATTR   Transfer attributes   */ dmaSSize(data[0])|                        // 16-bit read from SADDR
   /*                                        */ dmaDSize(data[0]),                        // 16-bit write to DADDR
   /* uint32_t  NBYTES Minor loop byte count */ 1*sizeof(data[0]),                        // Total transfer in one minor-loop
   /* uint32_t  SLAST  Last SADDR adjustment */ -sizeof(data),                            // Reset SADDR to start of array on completion
   /* uint32_t  DADDR  Destination address   */ (uint32_t)(&TimerChannel::channelRegs().CnV), // Destination is FTM channel CnV register
   /* uint16_t  DOFF   DADDR offset          */ 0,                                        // DADDR doesn't change
   /* uint16_t  CITER  Major loop count      */ DMA_CITER_ELINKNO_ELINK(0)|               // No ELINK
   /*                                        */ ((sizeof(data))/sizeof(data[0])),         // Transfer entire buffer
   /* uint32_t  DLAST  Last DADDR adjustment */ 0,                                        // DADDR doesn't change
   /* uint16_t  CSR    Control and Status    */ DMA_CSR_INTMAJOR(1)|                      // Generate interrupt on completion of Major-loop
   /*                                        */ DMA_CSR_DREQ(0)|                          // Don't clear hardware request when complete major loop (non-stop)
   /*                                        */ DMA_CSR_START(0),                         // Don't start (triggered by hardware)
};

bool complete = false;

/**
 * DMA complete callback
 *
 * Sets flag to indicate sequence complete.
 */
static void dmaCallback() {
   complete = true;
   Led::toggle();
}

/**
 * DMA error call back
 *
 * @param errorFlags Channel error information (DMA_ES)
 */
void dmaErrorCallbackFunction(uint32_t errorFlags) {
   console.write("DMA error DMA_ES = 0x").writeln(errorFlags, Radix_16);
   __BKPT();
}

/**
 * Configure DMA from Memory-to-UART
 */
static void configureDma() {

   // Sequence not complete yet
   complete = false;

   // Enable DMAC with default settings
   Dma0::configure();

   // Set callback (Interrupts are enabled in TCD)
   Dma0::setCallback(DMA_CHANNEL, dmaCallback);
   Dma0::setErrorCallback(dmaErrorCallbackFunction);
   Dma0::enableNvicInterrupts(DMA_CHANNEL);
   Dma0::enableNvicErrorInterrupt();

   // Connect DMA channel to UART but throttle by PIT Channel 1 (matches DMA channel 1)
   DmaMux0::configure(DMA_CHANNEL, DMA_SLOT, DmaMuxEnable_Continuous);

   // Configure the transfer
   Dma0::configureTransfer(DMA_CHANNEL, tcd);

   // Enable hardware requests
   Dma0::enableRequests(DMA_CHANNEL);

#ifdef DMA_EARS_EDREQ_0_MASK
   // Enable asynchronous requests (if available)
   Dma0::enableAsynchronousRequests(DMA_CHANNEL);
#endif

   // Enable channel interrupt requests
   Dma0::enableErrorInterrupts(DMA_CHANNEL);
}

int main() {

   configureDma();

   // Configure base FTM (affects all channels)
   // The prescaler will be recalculated later
   Timer::configure(
         FtmMode_LeftAlign,      // Left-aligned is required for OC/IC
         FtmClockSource_System); // Bus clock usually

   Timer::setPeriod(500*us);

   // Calculate waveform times in timer ticks
   data[0] = Timer::convertSecondsToTicks(100*us);
   data[1] = Timer::convertSecondsToTicks(101*us);
   data[2] = Timer::convertSecondsToTicks(250*us);
   data[3] = Timer::convertSecondsToTicks(300*us);

   // Enable interrupts for entire timer
   Timer::enableNvicInterrupts();

   // Pin high-drive
   TimerChannel::setOutput(PinDriveStrength_High);

   // Restart counter
   Timer::resetTime();

   Led::setOutput(PinDriveStrength_High);

   // Trigger 1st DMA at last event in table
   TimerChannel::setEventTime(data[3]);

   // Configure the channel
   TimerChannel::configure(
         FtmChMode_OutputCompareToggle, //  Output Compare with pin toggle
         FtmChannelAction_Dma);         //  + DMA on events

   Led::on();

   // Check if configuration failed
   USBDM::checkError();

   for(;;) {
      __asm__("wfi");
   }
}
