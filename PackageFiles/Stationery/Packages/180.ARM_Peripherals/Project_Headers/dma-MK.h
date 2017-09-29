/*
 * dma.h  (180.ARM_Peripherals/Project_Headers/dma-MK.h)
 *
 *  Created on: 08/07/2014
 *      Author: podonoghue
 */

#ifndef INCLUDE_USBDM_DMA_H_
#define INCLUDE_USBDM_DMA_H_

#include "derivative.h"
#include "hardware.h"
/*
 * *****************************
 * *** DO NOT EDIT THIS FILE ***
 * *****************************
 *
 * This file is generated automatically.
 * Any manual changes will be lost.
 */
namespace USBDM {

/**
 * @addtogroup DMA_Group DMA, Direct Memory Access (DMA)
 * @brief Support for DMA operations
 * @{
 */

/**
 * Type definition for DMA interrupt call back
 */
typedef void (*DmaCallbackFunction)(void);

/**
 * Controls operation of DMA-MUX channel
 */
enum DmaMuxEnable {
   DmaMuxEnable_Disable    = DMAMUX_CHCFG_ENBL(0),                      //!< DMA channel is disabled
   DmaMuxEnable_Continuous = DMAMUX_CHCFG_ENBL(1)|DMAMUX_CHCFG_TRIG(0), //!< DMA channel is enabled
   DmaMuxEnable_Triggered  = DMAMUX_CHCFG_ENBL(1)|DMAMUX_CHCFG_TRIG(1), //!< DMA channel is enabled and triggered by PIT channel
};

/**
 * How to arbitrate between requests from different channels
 */
enum DmaArbitration {
   DmaArbitration_Fixed       = DMA_CR_ERCA(0), //!< Fixed arbitration between channels
   DmaArbitration_RoundRobin  = DMA_CR_ERCA(1), //!< Round-robin arbitration between channels
};

/**
 * Whether to halt when a DMA error occurs
 */
enum DmaOnError {
   DmaOnError_Continue = DMA_CR_HOE(0), //!< DMA transfer continues on any error
   DmaOnError_Halt     = DMA_CR_HOE(1), //!< DMA transfer halt on any error
};

/**
 * Whether to enable continuous link mode
 */
enum DmaLink {
   DmaLink_Disabled  = DMA_CR_CLM(0), //!< Link mode disabled
   DmaLink_Enabled   = DMA_CR_CLM(1), //!< Link mode enabled
};

/**
 * Whether to enable minor loop mapping
 */
enum DmaMinorLoopMapping {
   DmaMinorLoopMapping_Disabled  = DMA_CR_EMLM(0), //!< Minor loop disabled
   DmaMinorLoopMapping_Enabled   = DMA_CR_EMLM(1), //!< Minor loop enabled
};

/**
 * Channel numbers
 */
enum DmaChannelNum {
   DmaChannelNum_0 = 0,     //!< Channel 0
   DmaChannelNum_1 = 1,     //!< Channel 1
   DmaChannelNum_2 = 2,     //!< Channel 2
   DmaChannelNum_3 = 3,     //!< Channel 3

   DmaChannelNum_All = (1<<6),  //!< All channels, some operations may be applied to all channels
};

/**
 * DMA transfer sizes
 */
enum DmaSize : uint8_t {
   DmaSize_8bit    = 0,  //!< 8-bit transfer
   DmaSize_16bit   = 1,  //!< 16-bit transfer
   DmaSize_32bit   = 2,  //!< 32-bit transfer
   DmaSize_16byte  = 4,  //!< 16-byte transfer
   DmaSize_32byte  = 5,  //!< 32-byte transfer
   DmaSize_Illegal = 7,  //!< Illegal transfer
};

/*
 * Controls whether a channel can be suspended by a higher priority channel
 */
enum DmaCanBePreempted {
   DmaCanBePreempted_Disable = DMA_DCHPRI_ECP(0), //!< Channel N cannot be suspended by a higher priority channel's service request
   DmaCanBePreempted_Enable  = DMA_DCHPRI_ECP(1), //!< Channel N can be temporarily suspended by the service request of a higher priority channel
};

/*
 * Controls whether a channel can suspend a lower priority channel
 */
enum DmaCanPreemptLower {
   DmaCanPreemptLower_Enable  = DMA_DCHPRI_DPA(0), //!< Channel N can suspend a lower priority channel
   DmaCanPreemptLower_Disable = DMA_DCHPRI_DPA(1), //!< Channel N cannot suspend a lower priority channel
};

/**
 * Get DMA size of object.\n
 * For use in TCD ATTR value
 *
 * @param[in] obj Object to obtain DMA size value for
 *
 * @return one of the DmaSize_xxxx values
 */
template <class T>
static constexpr DmaSize getDmaSize(const T &obj) {
   static_assert(((sizeof(obj)==1)||(sizeof(obj)==2)||(sizeof(obj)==4)||(sizeof(obj)==16)||(sizeof(obj)==32)), "Illegal DMA transfer size");
   return
      (sizeof(obj)==1) ?DmaSize_8bit:
      (sizeof(obj)==2) ?DmaSize_16bit:
      (sizeof(obj)==4) ?DmaSize_32bit:
      (sizeof(obj)==16)?DmaSize_16byte:
      (sizeof(obj)==32)?DmaSize_32byte:
            DmaSize_Illegal;
};

/**
 * Get DMA source size of object.\n
 * For use in TCD ATTR value
 *
 * @param[in] obj Object to get size of
 *
 * @return mask suitable for use as part of TCD.ATTR value
 */
template <class T>
static constexpr uint32_t dmaSSize(const T &obj) {
   return DMA_ATTR_SSIZE(getDmaSize(obj));
}

/**
 * Get DMA destination size of object.\n
 * For use in TCD ATTR value
 *
 * @param[in] obj Object to get size of
 *
 * @return mask suitable for use as part of TCD.ATTR value
 */
template <class T>
static constexpr uint32_t dmaDSize(const T &obj) {
   return DMA_ATTR_DSIZE(getDmaSize(obj));
}

/**
 * Get DMA source and destination size of objects.\n
 * For use in TCD ATTR value
 *
 * @param[in] sobj DMA source object to get size of
 * @param[in] dobj DMA destination object to get size of
 *
 * @return mask suitable for use as part of TCD.ATTR value
 */
template <class Ts, class Td>
static constexpr uint16_t dmaSize(const Ts &sobj, const Td &dobj) {
   return DMA_ATTR_SSIZE(getDmaSize(sobj))|DMA_ATTR_DSIZE(getDmaSize(dobj));
}

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
 * | |   SADDR += SOFF          | |             - SLAST Adjustment applied to SADDR after major loop
 * | |   DADDR += DOFF          | |             - DLAST Adjustment applied to DADDR after major loop
 * | | Total transfer is NBYTES | |             - CITER Major loop counter - counts how many minor loops
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
struct DmaTcd {
   uint32_t  SADDR;    //!< Source address
   uint16_t  SOFF;     //!< SADDR offset
   uint16_t  ATTR;     //!< Transfer attributes
   uint32_t  NBYTES;   //!< Minor loop byte count
   uint32_t  SLAST;    //!< Last SADDR adjustment
   uint32_t  DADDR;    //!< Destination address
   uint16_t  DOFF;     //!< DADDR offset
   uint16_t  CITER;    //!< Major loop count
   uint32_t  DLAST;    //!< Last DADDR adjustment
   uint16_t  CSR;      //!< Control and Status
};

/**
 * Template class providing interface to DMA Multiplexor
 *
 * @tparam info      Information class for DMAMux
 *
 * @code
 * using dmamux = DmaMux_T<DmaMuxInfo>;
 *
 *  dmamux::configure();
 *
 * @endcode
 */
template <class DmaMuxInfo>
class DmaMux_T {

public:
   /**
    * Configures and enable hardware requests on a channel
    *
    * @param[in] dmaChannel   The DMA channel being enabled
    * @param[in] dmaSlot      The DMA slot (source) to connect to this channel
    * @param[in] dmaMuxEnable The mode for the channel
    */
   static void configure(DmaChannelNum dmaChannel, DmaSlot dmaSlot, DmaMuxEnable dmaMuxEnable=DmaMuxEnable_Continuous) {
#ifdef DEBUG_BUILD
      if ((dmaMuxEnable == DmaMuxEnable_Triggered) && (dmaChannel>USBDM::PitInfo::irqCount)) {
         // PIT triggering only available on channels corresponding to PIT channels
         setAndCheckErrorCode(E_ILLEGAL_PARAM);
      }
      if (dmaChannel >= DmaMuxInfo::NumChannels) {
         // Channel doesn't exists
         setAndCheckErrorCode(E_ILLEGAL_PARAM);
      }
#endif
      // Enable clock to peripheral
      *DmaMuxInfo::clockReg  |= DmaMuxInfo::clockMask;

      // Configure channel
      DmaMuxInfo::dmamux->CHCFG[dmaChannel] = dmaMuxEnable|DMAMUX_CHCFG_SOURCE(dmaSlot);
   }
   /**
    * Disable hardware requests on channel
    */
   static void disable(DmaChannelNum dmaChannel) {
      // Enable clock to peripheral
      *DmaMuxInfo::clockReg  |= DmaMuxInfo::clockMask;

      // Disable channel
      DmaMuxInfo::dmamux->CHCFG[dmaChannel] = 0;
   }
};

/**
 * Class representing a DMA controller
 *
 * @tparam Info Information describing DMA controller
 */
template<class Info>
class DmaBase_T {

   using MuxInfo = Dmamux0Info;

protected:
   // Pointer to hardware
   static constexpr volatile DMA_Type    *dmac          = Info::dma;

   // Pointer to clock register
   static constexpr volatile uint32_t    *clockReg      = Info::clockReg;

   // IRQ Num
   static constexpr IRQn_Type             irqNum        = DMA0_IRQn;

   /** Callback functions for ISRs */
   static DmaCallbackFunction callbacks[Info::NumChannels];

   /** Callback to catch unhandled interrupt */
   static void noHandlerCallback() {
      setAndCheckErrorCode(E_NO_HANDLER);
   }

public:
   /** DMA interrupt handler -  Error callback */
   static void irqHandler() {
      // Clear interrupt flag
//      dmac->CINT = DMA_CINT_CINT(0);
//      callbacks[0]();
   }

   /** DMA interrupt handler -  Calls DMA 0 callback */
   static void irq0Handler() {
      // Clear interrupt flag
      dmac->CINT = DMA_CINT_CINT(0);
      callbacks[0]();
   }

   /** DMA interrupt handler -  Calls DMA 1 callback */
   static void irq1Handler() {
      // Clear interrupt flag
      dmac->CINT = DMA_CINT_CINT(1);
      callbacks[1]();
   }

   /** DMA interrupt handler -  Calls DMA 2 callback */
   static void irq2Handler() {
      // Clear interrupt flag
      dmac->CINT = DMA_CINT_CINT(2);
      callbacks[2]();
   }

   /** DMA interrupt handler -  Calls DMA 3 callback */
   static void irq3Handler() {
      // Clear interrupt flag
      dmac->CINT = DMA_CINT_CINT(3);
      callbacks[3]();
   }

   /**
    * Enable and configure shared DMA settings
    *
    * @param[in] dmaArbitration        How to arbitrate between requests from different channels
    * @param[in] dmaOnError            Whether to halt when a DMA error occurs
    * @param[in] dmaLink               Whether to enable continuous link mode
    * @param[in] dmaMinorLoopMapping   Whether to enable minor loop mapping
    */
   static void configure(
         DmaArbitration       dmaArbitration=DmaArbitration_RoundRobin,
         DmaOnError           dmaOnError=DmaOnError_Halt,
         DmaLink              dmaLink=DmaLink_Disabled,
         DmaMinorLoopMapping  dmaMinorLoopMapping=DmaMinorLoopMapping_Disabled) {

      // Enable clock to DMAC
      *clockReg  |= MuxInfo::clockMask;

      // Set shared control options
      dmac->CR = dmaArbitration|dmaOnError|dmaLink|dmaMinorLoopMapping|DMA_CR_EDBG(1);
   }

   /**
    * Set priority for a DMA channel.
    * This is only used if DmaArbitration_Fixed is used.
    *
    * @param[in] channel            DMA channel number
    * @param[in] priority           Priority for the channel
    * @param[in] dmaCanBePreempted  Controls whether the channel can be suspended by a higher priority channel
    * @param[in] dmaCanPreemptLower Controls whether the channel can suspend a lower priority channel
    *
    * @note The priority of each channel must be a unique number from [0..NumChannel-1]
    */
   static void setChannelPriority(
         DmaChannelNum      channel,
         int                priority,
         DmaCanBePreempted  dmaCanBePreempted=DmaCanBePreempted_Enable,
         DmaCanPreemptLower dmaCanPreemptLower=DmaCanPreemptLower_Enable) {

      int index = (channel&0xFC)|(3-(channel&0x03));
      constexpr volatile uint8_t *priorities = &dmac->DCHPRI3;
      priorities[index] = dmaCanBePreempted|dmaCanPreemptLower|DMA_DCHPRI_CHPRI(priority);
   }

   /**
    * Configure channel for arbitrary transfer defined by DmaTcd
    *
    * @param[in] channel DMA channel number
    * @param[in] tcd     DMA TCD block describing the transfer
    */
   static void configureTransfer(DmaChannelNum channel, const DmaTcd &tcd) {

      // Copy TCD block to DMAC channel TCD
      dmac->TCD[channel].SADDR         = tcd.SADDR;
      dmac->TCD[channel].SOFF          = tcd.SOFF;
      dmac->TCD[channel].ATTR          = tcd.ATTR;
      dmac->TCD[channel].NBYTES_MLNO   = tcd.NBYTES;
      dmac->TCD[channel].SLAST         = tcd.SLAST;
      dmac->TCD[channel].DADDR         = tcd.DADDR;
      dmac->TCD[channel].DOFF          = tcd.DOFF;
      dmac->TCD[channel].CITER_ELINKNO = tcd.CITER;
      dmac->TCD[channel].DLASTSGA      = tcd.DLAST;
      dmac->TCD[channel].CSR           = tcd.CSR;
      dmac->TCD[channel].BITER_ELINKNO = tcd.CITER;
   }

   /**
    * Get status of last transfer error
    *
    * @return 32-bit flag register see DMA_ES definitions
    */
   static uint32_t __attribute__((always_inline)) getLastError() {
      return dmac->ES;
   }

   /**
    * Waits until the channel indicates the transaction has completed
    */
   static void waitUntilComplete(int channel) {

      int lastCiter = dmac->TCD[channel].CITER_ELINKNO;
      while ((dmac->TCD[channel].CSR & DMA_CSR_DONE_MASK) == 0) {
         int currentCiter = dmac->TCD[channel].CITER_ELINKNO;
         if (lastCiter != currentCiter) {
            lastCiter = currentCiter;
            __asm__ volatile("nop");
         }
      }
   }

   /**
    * Initiate a DMA software request on a channel.
    *
    * The channel should be configured beforehand using configureTransfer().\n
    * This is a convenience function that allows re-use of already configured channel.\n
    * All it does is set the START bit in the existing TCD.\n
    * There is no need to use this function for a single request as the START bit may be set\n
    * in the original TCD used with configureTransfer().
    *
    * @param[in]  channel Channel being modified
    *
    * @note There is no clear option as the flag is automatically cleared by the DMA controller when
    *        the transfer starts.
    */
   static void __attribute__((always_inline)) startSoftwareRequest(DmaChannelNum channel) {
      dmac->SSRT = channel;
   }

   /**
    * Enable/disable DMA hardware requests on a channel\n
    * The channel should be configured beforehand using configureTransfer()
    *
    * @param[in]  channel Channel being modified
    * @param[in]  enable  True => enable, False => disable
    *
    * @note May use DmaChannelNum_All to apply to all channels
    */
   static void __attribute__((always_inline)) enableRequests(DmaChannelNum channel, bool enable=true) {
      if (enable) {
         dmac->SERQ = channel;
      }
      else {
         dmac->CERQ = channel;
      }
   }

   /**
    * Enable/disable error interrupts for a channel
    *
    * @param[in]  channel Channel being modified
    * @param[in]  enable  True => enable, False => disable
    *
    * @note May use DmaChannelNum_All to apply to all channels
    */
   static void __attribute__((always_inline)) enableErrorInterrupts(DmaChannelNum channel, bool enable=true) {
      if (enable) {
         dmac->SEEI = channel;
      }
      else {
         dmac->CEEI = channel;
      }
   }

   /**
    * Clear done flag for a channel
    *
    * @param[in]  channel Channel being modified
    *
    * @note May use DmaChannelNum_All to apply to all channels
    */
   static void __attribute__((always_inline)) clearDoneFlag(DmaChannelNum channel) {
      dmac->CDNE = channel;
   }

   /**
    * Clear interrupt request flag for a channel
    *
    * @param[in]  channel Channel being modified
    *
    * @note May use DmaChannelNum_All to apply to all channels
    */
   static void __attribute__((always_inline)) clearInterruptRequest(DmaChannelNum channel) {
      dmac->CINT = channel;
   }

   /**
    * Enable/disable interrupts in NVIC
    *
    * @param[in]  channel   Channel being modified
    * @param[in]  enable    True => enable, False => disable
    * @param[in]  priority  Interrupt priority
	
    * @return E_NO_ERROR on success
    */
   static ErrorCode enableNvicInterrupts(DmaChannelNum channel, bool enable=true, uint32_t priority=NvicPriority_Normal) {
#ifdef DEBUG_BUILD
      if (channel>=Info::NumChannels) {
         setAndCheckErrorCode(E_ILLEGAL_PARAM);
      }
#endif

      IRQn_Type irqNum = (IRQn_Type)(Info::irqNums[0] + channel);
      if (enable) {
         // Enable interrupts
         NVIC_EnableIRQ(irqNum);

         // Set priority level
         NVIC_SetPriority(irqNum, priority);
      }
      else {
         // Disable interrupts
         NVIC_DisableIRQ(irqNum);
      }
      return E_NO_ERROR;
   }

   /**
    * Set callback for ISR
    *
    * @param[in]  channel  The DMA channel to set callback for
    * @param[in]  callback The function to call from stub ISR
    */
   static void __attribute__((always_inline)) setCallback(DmaChannelNum channel, DmaCallbackFunction callback) {
      if (callback == nullptr) {
         callback = noHandlerCallback;
      }
      callbacks[channel] = callback;
   }
};

/**
 * Callback table for programmatically set handlers
 */
template<class Info> DmaCallbackFunction DmaBase_T<Info>::callbacks[] = {
      noHandlerCallback,
      noHandlerCallback,
      noHandlerCallback,
      noHandlerCallback
};

#ifdef USBDM_DMAMUX0_IS_DEFINED
using DmaMux0 = DmaMux_T<Dmamux0Info>;
#endif

#ifdef USBDM_DMAMUX1_IS_DEFINED
using DmaMux1 = DmaMux_T<Dmamux1Info>;
#endif

#ifdef USBDM_DMA0_IS_DEFINED
using Dma0 = DmaBase_T<Dma0Info>;
#endif

#ifdef USBDM_DMA1_IS_DEFINED
using Dma0 = DmaBase_T<Dma1Info>;
#endif

/**
 * @}
 */
} // End namespace USBDM

#endif /* INCLUDE_USBDM_DMA_H_ */
