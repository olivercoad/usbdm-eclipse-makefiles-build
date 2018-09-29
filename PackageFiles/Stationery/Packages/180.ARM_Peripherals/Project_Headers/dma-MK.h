/**
 * @file    dma.h  (180.ARM_Peripherals/Project_Headers/dma-MK.h)
 * @brief   Direct Memory Controller
 *
 * @version  V4.12.1.210
 * @date     30 September 2017
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
 * Controls operation of DMA-MUX channel.
 */
enum DmaMuxEnable {
   DmaMuxEnable_Disable    = DMAMUX_CHCFG_ENBL(0),                      //!< DMA channel is disabled
   DmaMuxEnable_Continuous = DMAMUX_CHCFG_ENBL(1)|DMAMUX_CHCFG_TRIG(0), //!< DMA channel is enabled continuously
   DmaMuxEnable_Triggered  = DMAMUX_CHCFG_ENBL(1)|DMAMUX_CHCFG_TRIG(1), //!< DMA channel is enabled and triggered by PIT channel
};

/**
 * How to arbitrate between requests from different channels.
 */
enum DmaArbitration {
   DmaArbitration_Fixed       = DMA_CR_ERCA(0), //!< Fixed arbitration between channels within a group
   DmaArbitration_RoundRobin  = DMA_CR_ERCA(1), //!< Round-robin arbitration between channels within a group
};

/**
 * Controls priority of DMA groups.
 */
enum DmaGroupArbitration {
#if defined DMA_CR_ERGA
   DmaGroupArbitration_RoundRobin = DMA_CR_ERGA(1)|DMA_CR_GRP1PRI(0)|DMA_CR_GRP0PRI(1), //!< Round-robin group priority
   DmaGroupArbitration_01         = DMA_CR_ERGA(0)|DMA_CR_GRP1PRI(0)|DMA_CR_GRP0PRI(1), //!< Group 0 > Group 1
   DmaGroupArbitration_10         = DMA_CR_ERGA(0)|DMA_CR_GRP1PRI(1)|DMA_CR_GRP0PRI(0), //!< Group 1 > Group 0
#else
   DmaGroupArbitration_RoundRobin = 0, //!< Group priority not supported
#endif
};

/**
 * Whether to halt when a DMA error occurs.
 */
enum DmaOnError {
   DmaOnError_Continue = DMA_CR_HOE(0), //!< DMA transfer continues on any error
   DmaOnError_Halt     = DMA_CR_HOE(1), //!< DMA transfer halt on any error
};

/**
 * Whether to enable continuous link mode.
 */
enum DmaLink {
   DmaLink_Disabled  = DMA_CR_CLM(0), //!< Link mode disabled
   DmaLink_Enabled   = DMA_CR_CLM(1), //!< Link mode enabled
};

/**
 * Whether to enable minor loop mapping.
 */
enum DmaMinorLoopMapping {
   DmaMinorLoopMapping_Disabled  = DMA_CR_EMLM(0), //!< Minor loop disabled
   DmaMinorLoopMapping_Enabled   = DMA_CR_EMLM(1), //!< Minor loop enabled
};

/**
 * Channel numbers.
 */
enum DmaChannelNum {
   DmaChannelNum_0,      //!< Channel  0
   DmaChannelNum_1,      //!< Channel  1
   DmaChannelNum_2,      //!< Channel  2
   DmaChannelNum_3,      //!< Channel  3
   DmaChannelNum_4,      //!< Channel  4
   DmaChannelNum_5,      //!< Channel  5
   DmaChannelNum_6,      //!< Channel  6
   DmaChannelNum_7,      //!< Channel  7
   DmaChannelNum_8,      //!< Channel  8
   DmaChannelNum_9,      //!< Channel  9
   DmaChannelNum_10,     //!< Channel 10
   DmaChannelNum_11,     //!< Channel 11
   DmaChannelNum_12,     //!< Channel 12
   DmaChannelNum_13,     //!< Channel 13
   DmaChannelNum_14,     //!< Channel 14
   DmaChannelNum_15,     //!< Channel 15
   DmaChannelNum_16,     //!< Channel 16
   DmaChannelNum_17,     //!< Channel 17
   DmaChannelNum_18,     //!< Channel 18
   DmaChannelNum_19,     //!< Channel 19
   DmaChannelNum_20,     //!< Channel 20
   DmaChannelNum_21,     //!< Channel 21
   DmaChannelNum_22,     //!< Channel 22
   DmaChannelNum_23,     //!< Channel 23
   DmaChannelNum_24,     //!< Channel 24
   DmaChannelNum_25,     //!< Channel 25
   DmaChannelNum_26,     //!< Channel 26
   DmaChannelNum_27,     //!< Channel 27
   DmaChannelNum_28,     //!< Channel 28
   DmaChannelNum_29,     //!< Channel 29
   DmaChannelNum_30,     //!< Channel 30
   DmaChannelNum_31,     //!< Channel 31

   DmaChannelNum_All  = (1<<6),  //!< All channels, some operations may be applied to all channels
   DmaChannelNum_None = (1<<7),  //!< Used to indicate failed channel allocation 
};

/**
 * DMA transfer sizes.
 */
enum DmaSize {
   DmaSize_8bit    = 0b000,  //!< 8-bit transfer
   DmaSize_16bit   = 0b001,  //!< 16-bit transfer
   DmaSize_32bit   = 0b010,  //!< 32-bit transfer
   DmaSize_16byte  = 0b100,  //!< 16-byte transfer
   DmaSize_32byte  = 0b101,  //!< 32-byte transfer
};

/**
 * DMA modulo size
 */
enum DmaModulo {
   DmaModulo_Disabled   = 0b00000, //!< Modulo function disabled
   DmaModulo_2byte      = 0b00001, //!< 2-byte modulo
   DmaModulo_4byte      = 0b00010, //!< 4-byte modulo
   DmaModulo_8byte      = 0b00011, //!< 8-byte modulo
   DmaModulo_16byte     = 0b00100, //!< 16-byte modulo
   DmaModulo_32byte     = 0b00101, //!< 32-byte modulo
   DmaModulo_64byte     = 0b00110, //!< 64-byte modulo
   DmaModulo_128byte    = 0b00111, //!< 128-byte modulo
   DmaModulo_256byte    = 0b01000, //!< 256-byte modulo
   DmaModulo_512byte    = 0b01001, //!< 512-byte modulo
   DmaModulo_1KiByte    = 0b01010, //!< 1-Kibibyte modulo
   DmaModulo_2KiByte    = 0b01011, //!< 2-Kibibyte modulo
   DmaModulo_4KiByte    = 0b01100, //!< 4-Kibibyte modulo
   DmaModulo_8KiByte    = 0b01101, //!< 5-Kibibyte modulo
   DmaModulo_16KiByte   = 0b01110, //!< 16-Kibibyte modulo
   DmaModulo_32KiByte   = 0b01111, //!< 32-Kibibyte modulo
   DmaModulo_64KiByte   = 0b10000, //!< 64-Kibibyte modulo
   DmaModulo_128KiByte  = 0b10001, //!< 128-Kibibyte modulo
   DmaModulo_256KiByte  = 0b10010, //!< 256-Kibibyte modulo
   DmaModulo_512KiByte  = 0b10011, //!< 512-Kibibyte modulo
   DmaModulo_1MiByte    = 0b10100, //!< 1-Mebibyte  modulo
   DmaModulo_2MiByte    = 0b10101, //!< 2-Mebibyte modulo
   DmaModulo_4MiByte    = 0b10110, //!< 4-Mebibyte modulo
   DmaModulo_8MiByte    = 0b10111, //!< 8-Mebibyte modulo
   DmaModulo_16MiByte   = 0b11000, //!< 16-Mebibyte modulo
   DmaModulo_32MiByte   = 0b11001, //!< 32-Mebibyte modulo
   DmaModulo_64MiByte   = 0b11010, //!< 64-Mebibyte modulo
   DmaModulo_128MiByte  = 0b11011, //!< 128-Mebibyte modulo
   DmaModulo_256MiByte  = 0b11100, //!< 256-Mebibyte modulo
   DmaModulo_512MiByte  = 0b11101, //!< 512-Mebibyte modulo
   DmaModulo_1GiByte    = 0b11110, //!< 1-Gibibyte modulo
   DmaModulo_2GiByte    = 0b11111, //!< 2-Gibibyte modulo

};

/**
 * Controls whether a channel can be suspended by a higher priority channel.
 */
enum DmaCanBePreempted {
   DmaCanBePreempted_Disable = DMA_DCHPRI_ECP(0), //!< Channel N cannot be suspended by a higher priority channel's service request
   DmaCanBePreempted_Enable  = DMA_DCHPRI_ECP(1), //!< Channel N can be temporarily suspended by the service request of a higher priority channel
};

/**
 * Controls whether a channel can suspend a lower priority channel.
 */
enum DmaCanPreemptLower {
   DmaCanPreemptLower_Enable  = DMA_DCHPRI_DPA(0), //!< Channel N can suspend a lower priority channel
   DmaCanPreemptLower_Disable = DMA_DCHPRI_DPA(1), //!< Channel N cannot suspend a lower priority channel
};

/**
 * Calculate a DMA slot number using an offset from an existing number
 *
 * @param slot    Base slot to use
 * @param offset  Offset from base slot
 *
 * @return  DMA slot number calculated from slot+offset
 */
constexpr DmaSlot inline operator+(DmaSlot slot, unsigned offset) {
   return (DmaSlot)((unsigned)slot + offset);
}

/**
 * Calculate a DMA slot number using an offset from an existing number
 *
 * @param slot    Base slot to use
 * @param offset  Offset from base slot
 *
 * @return  DMA slot number calculated from slot+offset
 */
constexpr DmaSlot inline operator+(DmaSlot slot, int offset) {
   return slot + (unsigned)offset;
}

/**
 * Type definition for DMA interrupt call back.
 *
 * @param[in] dmaChannelNum
 */
typedef void (*DmaCallbackFunction)(DmaChannelNum dmaChannelNum);

/**
 * Type definition for DMA error interrupt call back.
 *
 * @param errorFlags Channel error information (DMA_ES)
 */
typedef void (*DmaErrorCallbackFunction)(uint32_t errorFlags);

/**
 * Get DMA size of object.
 * For use in TCD.SMOD, TCD.DMOD value
 *
 * @param[in] obj Object to obtain DMA size value for
 *
 * @return one of the DmaSize_xxxx values
 */
template <class Td>
static constexpr DmaSize dmaSize(const Td &obj) {
   static_assert(((sizeof(obj)==1)||(sizeof(obj)==2)||(sizeof(obj)==4)||(sizeof(obj)==16)||(sizeof(obj)==32)), "Illegal DMA transfer size");
   return
      (sizeof(obj)==1) ?DmaSize_8bit:
      (sizeof(obj)==2) ?DmaSize_16bit:
      (sizeof(obj)==4) ?DmaSize_32bit:
      (sizeof(obj)==16)?DmaSize_16byte:
      /*          ==32*/DmaSize_32byte;
}

/**
 * Get DMA source size of object.
 * For use in TCD ATTR value
 *
 * @param[in] obj Object to get size of
 *
 * @return mask suitable for use as part of TCD.ATTR value
 */
template <class T>
static constexpr uint32_t dmaSSize(const T &obj) {
   return DMA_ATTR_SSIZE(dmaSize(obj));
}

/**
 * Get DMA destination size of object.
 * For use in TCD ATTR value
 *
 * @param[in] obj Object to get size of
 *
 * @return mask suitable for use as part of TCD.ATTR value
 */
template <class T>
static constexpr uint32_t dmaDSize(const T &obj) {
   return DMA_ATTR_DSIZE(dmaSize(obj));
}

/**
 * Get DMA source and destination size of objects.
 * For use in TCD ATTR value
 *
 * @param[in] sobj DMA source object to get size of
 * @param[in] dobj DMA destination object to get size of
 *
 * @return mask suitable for use as part of TCD.ATTR value
 */
template <class Ts, class Td>
static constexpr uint16_t dmaSize(const Ts &sobj, const Td &dobj) {
   return DMA_ATTR_SSIZE(dmaSize(sobj))|DMA_ATTR_DSIZE(dmaSize(dobj));
}

enum DmaSpeed {
   DmaSpeed_NoStalls = 0b00, //!< No DMA engine stalls
   DmaSpeed_4_Stalls = 0b10, //!< DMA engine stalls for 4 cycles after each R/W.
   DmaSpeed_8_Stalls = 0b11, //!< DMA engine stalls for 8 cycles after each R/W.
};

struct __attribute__((__packed__)) DmaTcdAttr {
   union {
      struct {
         DmaSize       DSIZE:3;       //!< Destination size
         DmaModulo     DMOD:5;        //!< Destination modulo
         DmaSize       SSIZE:3;       //!< Source size
         DmaModulo     SMOD:5;        //!< Source modulo
      };
      uint16_t data;
   };
};

struct __attribute__((__packed__)) DmaTcdCsr {
   union {
      struct {
         bool          START:1;       //!< Channel Start
         bool          INTMAJOR:1;    //!< Interrupt on major complete
         bool          INTHALF:1;     //!< Interrupt on major half complete
         bool          DREQ:1;        //!< Disable Request
         bool          ESG:1;         //!< Enable Scatter/Gather
         bool          MAJORELINK:1;  //!< Enable channel linking
         bool          ACTIVE:1;      //!< Channel Active
         bool          DONE:1;        //!< Channel Done
         unsigned      MAJORLINKCH:4; //!< Link Channel Number
         unsigned      :2;
         DmaSpeed      BWC:2;         //!< Bandwidth Control
      };
      uint16_t data;
   };
};
/**
 * Transfer Control Descriptor
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
 * |..............................|               - ATTR_SMOD, ATTR_DMOD Modulo
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
struct __attribute__((__packed__)) DmaTcd {
   uint32_t      SADDR;         //!< :00 Source address
   uint16_t      SOFF;          //!< :04 Source offset
   DmaTcdAttr    ATTR;          //!< :06 Transfer attributes
   uint32_t      NBYTES;        //!< :08 Minor loop byte count
   uint32_t      SLAST;         //!< :0C Last source adjustment
   uint32_t      DADDR;         //!< :10 Destination address
   uint16_t      DOFF;          //!< :14 Destination offset
   uint16_t      CITER;         //!< :16 Major loop count
   uint32_t      DLAST;         //!< :18 Last destination adjustment
   DmaTcdCsr     CSR;           //!< :1C Control and Status
//   uint16_t      BITER;         //!< :1E Byte iterator.  Must always equal initial CITER
};

/**
 * Template class providing interface to DMA Multiplexor.
 *
 * @tparam DmaMuxInfo  Information class for DMAMux
 * @tparam NumChannels Number of DMA channels in associated DMA controller
 *
 * @code
 * using dmamux = DmaMux_T<DmaMuxInfo>;
 *
 *  dmamux::configure();
 *
 * @endcode
 */
template <class DmaMuxInfo, unsigned NumChannels>
class DmaMux_T {

public:
   /**
    * Configures and enable hardware requests on a channel.
    *
    * @param[in] dmaChannelNum   The DMA channel being enabled
    * @param[in] dmaSlot         The DMA slot (source) to connect to this channel
    * @param[in] dmaMuxEnable    The mode for the channel
    */
   static void configure(DmaChannelNum dmaChannelNum, DmaSlot dmaSlot, DmaMuxEnable dmaMuxEnable=DmaMuxEnable_Continuous) {
#ifdef DEBUG_BUILD
      if (dmaChannelNum >= NumChannels) {
         // Channel doesn't exists
         setAndCheckErrorCode(E_ILLEGAL_PARAM);
      }
      if ((dmaMuxEnable == DmaMuxEnable_Triggered) && (dmaChannelNum>USBDM::PitInfo::numChannels)) {
         // PIT triggering only available on channels corresponding to PIT channels
         setAndCheckErrorCode(E_ILLEGAL_PARAM);
      }
      if (((dmaChannelNum>=16)&&(dmaSlot<64))||((dmaChannelNum<16)&&(dmaSlot>=64))) {
         // DmaSlots 0-63 must associate with DMA channels 0-15
         // DmaSlots 64-128 must associate with DMA channels 15-31
         setAndCheckErrorCode(E_ILLEGAL_PARAM);
      }
#endif
      // Enable clock to peripheral
      DmaMuxInfo::clockReg()  |= DmaMuxInfo::clockMask;

      // Configure channel - must be disabled to change
      DmaMuxInfo::dmamux().CHCFG[dmaChannelNum] = 0;
      DmaMuxInfo::dmamux().CHCFG[dmaChannelNum] = dmaMuxEnable|DMAMUX_CHCFG_SOURCE(dmaSlot);
   }

   /**
    * Disable hardware requests on channel
    *
    * @param dmaChannelNum Channel to modify
    */
   static void disable(DmaChannelNum dmaChannelNum) {
#ifdef DEBUG_BUILD
      if (dmaChannelNum>=NumChannels) {
         setAndCheckErrorCode(E_ILLEGAL_PARAM);
      }
#endif
      // Enable clock to peripheral
      DmaMuxInfo::clockReg()  |= DmaMuxInfo::clockMask;

      // Disable channel
      DmaMuxInfo::dmamux().CHCFG[dmaChannelNum] = 0;
   }
};

/**
 * Class representing a DMA controller.
 *
 * @tparam Info Information describing DMA controller
 */
template<class Info>
class DmaBase_T {

   using MuxInfo = Dmamux0Info;

protected:
   /** Hardware instance pointer */
   static __attribute__((always_inline)) volatile DMA_Type &dmac() { return Info::dma(); }

   /** Clock register mask for peripheral */
   static __attribute__((always_inline)) volatile uint32_t &clockReg() { return Info::clockReg(); }

   /** Callback functions for ISRs */
   static DmaCallbackFunction callbacks[Info::NumVectors];

   /** Bit-mask of allocated channels */
   static uint32_t allocatedChannels;

   /** Callback functions for errors */
   static DmaErrorCallbackFunction errorCallback;

   /** Callback to catch unhandled interrupt */
   static void noHandlerCallback(DmaChannelNum) {
      setAndCheckErrorCode(E_NO_HANDLER);
   }

   /** Callback to catch unhandled error interrupt */
   static void noHandlerErrorCallback(uint32_t) {
      setAndCheckErrorCode(E_NO_HANDLER);
   }

public:
   /** DMA interrupt handler -  Error callback */
   static void irqErrorHandler() {

      // Capture error status
      uint32_t errorFlags = dmac().ES;

      // Clear channel error flag
      dmac().CERR = DMA_CERR_CERR(dmac().ES>>DMA_ES_ERRCHN_SHIFT);

      errorCallback(errorFlags);
   }

   /** DMA interrupt handler -  Calls DMA 0 callback */
   static void irq0Handler() {
      callbacks[0](DmaChannelNum_0);
   }

   /** DMA interrupt handler -  Calls DMA 1 callback */
   static void irq1Handler() {
      callbacks[1](DmaChannelNum_1);
   }

   /** DMA interrupt handler -  Calls DMA 2 callback */
   static void irq2Handler() {
      callbacks[2](DmaChannelNum_2);
   }

   /** DMA interrupt handler -  Calls DMA 3 callback */
   static void irq3Handler() {
      callbacks[3](DmaChannelNum_3);
   }

   /** DMA interrupt handler -  Calls DMA 4 callback */
   static void irq4Handler() {
      callbacks[4](DmaChannelNum_4);
   }

   /** DMA interrupt handler -  Calls DMA 5 callback */
   static void irq5Handler() {
      callbacks[5](DmaChannelNum_5);
   }

   /** DMA interrupt handler -  Calls DMA 6 callback */
   static void irq6Handler() {
      callbacks[6](DmaChannelNum_6);
   }

   /** DMA interrupt handler -  Calls DMA 7 callback */
   static void irq7Handler() {
      callbacks[7](DmaChannelNum_7);
   }

   /** DMA interrupt handler -  Calls DMA 8 callback */
   static void irq8Handler() {
      callbacks[8](DmaChannelNum_8);
   }

   /** DMA interrupt handler -  Calls DMA 9 callback */
   static void irq9Handler() {
      callbacks[9](DmaChannelNum_9);
   }

   /** DMA interrupt handler -  Calls DMA 10 callback */
   static void irq10Handler() {
      callbacks[10](DmaChannelNum_10);
   }

   /** DMA interrupt handler -  Calls DMA 11 callback */
   static void irq11Handler() {
      callbacks[11](DmaChannelNum_11);
   }

   /** DMA interrupt handler -  Calls DMA 12 callback */
   static void irq12Handler() {
      callbacks[12](DmaChannelNum_12);
   }

   /** DMA interrupt handler -  Calls DMA 13 callback */
   static void irq13Handler() {
      callbacks[13](DmaChannelNum_13);
   }

   /** DMA interrupt handler -  Calls DMA 14 callback */
   static void irq14Handler() {
      callbacks[14](DmaChannelNum_14);
   }

   /** DMA interrupt handler -  Calls DMA 15 callback */
   static void irq15Handler() {
      callbacks[15](DmaChannelNum_15);
   }

   /**
    * Enable and configure shared DMA settings.
    * This also clears all DMA channels.
    *
    * @param[in] dmaArbitration        How to arbitrate between requests from different DMA channels
    * @param[in] dmaGroupArbitration   How to arbitrate between requests from different DMA groups
    * @param[in] dmaOnError            Whether to halt when a DMA error occurs
    * @param[in] dmaLink               Whether to enable continuous link mode
    * @param[in] dmaMinorLoopMapping   Whether to enable minor loop mapping
    */
   static void configure(
         DmaArbitration       dmaArbitration=DmaArbitration_RoundRobin,
         DmaGroupArbitration  dmaGroupArbitration=DmaGroupArbitration_RoundRobin,
         DmaOnError           dmaOnError=DmaOnError_Halt,
         DmaLink              dmaLink=DmaLink_Disabled,
         DmaMinorLoopMapping  dmaMinorLoopMapping=DmaMinorLoopMapping_Disabled
         ) {
      // Enable clock to DMAC
      clockReg()  |= MuxInfo::clockMask;

      // Set shared control options
      dmac().CR = dmaArbitration|dmaOnError|dmaLink|dmaMinorLoopMapping|dmaGroupArbitration|DMA_CR_EDBG(1);

      // Clear call-backs and TCDs
      for (unsigned channel=0; channel<Info::NumVectors; channel++) {
         static const DmaTcd emptyTcd {
            /* uint32_t  SADDR         Source address              */ 0,
            /* uint16_t  SOFF          Source offset               */ 0,
            /* DmaSize   DSIZE:3       Destination size            */ DmaSize_8bit,
            /* DmaModulo DMOD:5        Destination modulo          */ DmaModulo_Disabled,
            /* DmaSize   SSIZE:3       Source size                 */ DmaSize_8bit,
            /* DmaModulo SMOD:5        Source modulo               */ DmaModulo_Disabled,
            /* uint32_t  NBYTES        Minor loop byte count       */ 0,
            /* uint32_t  SLAST         Last source adjustment      */ 0,
            /* uint32_t  DADDR         Destination address         */ 0,
            /* uint16_t  DOFF          Destination offset          */ 0,
            /* uint16_t  CITER         Major loop count            */ 0,
            /* uint32_t  DLAST         Last destination adjustment */ 0,
            /* bool      START:1       Channel Start               */ false,
            /* bool      INTMAJOR:1    Interrupt on major complete */ false,
            /* bool      INTHALF:1     Interrupt on half complete  */ false,
            /* bool      DREQ:1        Disable Request             */ false,
            /* bool      ESG:1         Enable Scatter/Gather       */ false,
            /* bool      MAJORELINK:1  Enable channel linking      */ false,
            /* bool      ACTIVE:1      Channel Active              */ false,
            /* bool      DONE:1        Channel Done                */ false,
            /* unsigned  MAJORLINKCH:4 Link Channel Number         */ 0,
            /* DmaSpeed  BWC:2         Bandwidth (speed) Control   */ DmaSpeed_NoStalls
         };
         callbacks[channel] = noHandlerCallback;
         configureTransfer((DmaChannelNum)channel, emptyTcd);
      }
      // Reset record of allocated channels
      allocatedChannels = 0;
   }

   /**
    * Allocate DMA channel.
    *
    * @return DmaChannelNum_None - No suitable channel available.  Error code set.
    * @return Channel number     - Number of allocated channel
    */
   static DmaChannelNum allocateChannel() {
      unsigned channelNum = __builtin_ffs(allocatedChannels);
      if ((channelNum == 0)||(--channelNum>=Info::NumChannels)) {
         setErrorCode(E_NO_RESOURCE);
         return DmaChannelNum_None;
      }
      allocatedChannels &= ~(1<<channelNum);
      return (DmaChannelNum) channelNum;
   }

   /**
    * Allocate Periodic DMA channel.
    * This is a channel that may be throttled by an associated PIT channel.
    *
    * @return Error DmaChannelNum_None - No suitable channel available.  Error code set.
    * @return Channel number           - Number of allocated channel
    */
   static DmaChannelNum allocatePeriodicChannel() {
      unsigned channelNum = __builtin_ffs(allocatedChannels);
      if ((channelNum == 0)||(--channelNum>=Info::NumChannels)||(channelNum>=USBDM::PitInfo::numChannels)) {
         setErrorCode(E_NO_RESOURCE);
         return DmaChannelNum_None;
      }
      allocatedChannels &= ~(1<<channelNum);
      return (DmaChannelNum) channelNum;
   }

   /**
    * Free DMA channel.
    *
    * @param dmaChannelNum Channel to release
    */
   static void freeChannel(DmaChannelNum dmaChannelNum) {
#ifdef DEBUG_BUILD
      if (dmaChannelNum>=Info::NumChannels) {
         setAndCheckErrorCode(E_ILLEGAL_PARAM);
      }
#endif
      allocatedChannels |= (1<<dmaChannelNum);
   }

   /**
    * Set priority for a DMA channel.
    * This is only used if DmaArbitration_Fixed is used.
    *
    * @param[in] dmaChannelNum      Channel to modify
    * @param[in] priority           Priority for the channel
    * @param[in] dmaCanBePreempted  Controls whether the channel can be suspended by a higher priority channel
    * @param[in] dmaCanPreemptLower Controls whether the channel can suspend a lower priority channel
    *
    * @note The priority of each channel must be a unique number from [0..NumChannel-1]
    */
   static void setChannelPriority(
         DmaChannelNum      dmaChannelNum,
         int                priority,
         DmaCanBePreempted  dmaCanBePreempted=DmaCanBePreempted_Enable,
         DmaCanPreemptLower dmaCanPreemptLower=DmaCanPreemptLower_Enable) {
#ifdef DEBUG_BUILD
      if (dmaChannelNum>=Info::NumChannels) {
         setAndCheckErrorCode(E_ILLEGAL_PARAM);
      }
#endif
      int index = (dmaChannelNum&0xFC)|(3-(dmaChannelNum&0x03));
      constexpr volatile uint8_t *priorities = &dmac().DCHPRI3;
      priorities[index] = dmaCanBePreempted|dmaCanPreemptLower|DMA_DCHPRI_CHPRI(priority);
   }

   /**
    * Configure channel for arbitrary transfer defined by DmaTcd.
    *
    * @param[in] dmaChannelNum DMA channel number
    * @param[in] tcd           DMA TCD block describing the transfer
    */
   static void configureTransfer(DmaChannelNum dmaChannelNum, const DmaTcd &tcd) {
#ifdef DEBUG_BUILD
      if (dmaChannelNum>=Info::NumChannels) {
         setAndCheckErrorCode(E_ILLEGAL_PARAM);
      }
#endif
      dmac().TCD[dmaChannelNum].SADDR           = tcd.SADDR;
      dmac().TCD[dmaChannelNum].SOFF            = tcd.SOFF;
      dmac().TCD[dmaChannelNum].ATTR            = tcd.ATTR.data;
      dmac().TCD[dmaChannelNum].NBYTES_MLNO     = tcd.NBYTES;
      dmac().TCD[dmaChannelNum].SLAST           = tcd.SLAST;
      dmac().TCD[dmaChannelNum].DADDR           = tcd.DADDR;
      dmac().TCD[dmaChannelNum].DOFF            = tcd.DOFF;
      dmac().TCD[dmaChannelNum].CITER_ELINKNO   = tcd.CITER;
      dmac().TCD[dmaChannelNum].DLASTSGA        = tcd.DLAST;
      dmac().TCD[dmaChannelNum].CSR             = tcd.CSR.data;
      dmac().TCD[dmaChannelNum].BITER_ELINKNO   = tcd.CITER;
   }

   /**
    * Get status of last transfer error.
    *
    * @return 32-bit flag register see DMA_ES definitions
    */
   static uint32_t __attribute__((always_inline)) getLastError() {
      return dmac().ES;
   }

   /**
    * Waits until the channel indicates the transaction has completed.
    *	
    * @param[in] dmaChannelNum DMA channel number
    */
   static void waitUntilComplete(DmaChannelNum dmaChannelNum) {
#ifdef DEBUG_BUILD
      if (dmaChannelNum>=Info::NumChannels) {
         setAndCheckErrorCode(E_ILLEGAL_PARAM);
      }
#endif
      int lastCiter = dmac().TCD[dmaChannelNum].CITER_ELINKNO;
      while ((dmac().TCD[dmaChannelNum].CSR & DMA_CSR_DONE_MASK) == 0) {
         int currentCiter = dmac().TCD[dmaChannelNum].CITER_ELINKNO;
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
    * @param[in] dmaChannelNum Channel being modified
    *
    * @note There is no clear option as the flag is automatically cleared by the DMA controller when
    *        the transfer starts.
    */
   static void __attribute__((always_inline)) startSoftwareRequest(DmaChannelNum dmaChannelNum) {
#ifdef DEBUG_BUILD
      if (dmaChannelNum>=Info::NumChannels) {
         setAndCheckErrorCode(E_ILLEGAL_PARAM);
      }
#endif
      dmac().SSRT = dmaChannelNum;
   }

   /**
    * Enable/disable DMA hardware requests on multiple channels.
    * The channel should be configured beforehand using configureTransfer().
    *
    * @param[in]  dmaChannelMask Mask for channels being modified
    * @param[in]  enable         True => enable, False => disable
    *
    * @note May use DmaChannelNum_All to apply to all channels
    */
   static void __attribute__((always_inline)) enableMultipleRequests(uint32_t dmaChannelMask, bool enable=true) {
#ifdef DEBUG_BUILD
      if (dmaChannelMask&~((1<<Info::NumChannels)-1)) {
         setAndCheckErrorCode(E_ILLEGAL_PARAM);
      }
#endif
      if (enable) {
         dmac().ERQ |= dmaChannelMask;
      }
      else {
         dmac().ERQ &= ~dmaChannelMask;
      }
   }

   /**
    * Enable/disable DMA hardware requests on a channel.
    * The channel should be configured beforehand using configureTransfer().
    *
    * @param[in]  dmaChannelNum  Channel being modified
    * @param[in]  enable         True => enable, False => disable
    *
    * @note May use DmaChannelNum_All to apply to all channels
    */
   static void __attribute__((always_inline)) enableRequests(DmaChannelNum dmaChannelNum, bool enable=true) {
#ifdef DEBUG_BUILD
      if (dmaChannelNum>=Info::NumChannels) {
         setAndCheckErrorCode(E_ILLEGAL_PARAM);
      }
#endif
      if (enable) {
         dmac().SERQ = dmaChannelNum;
      }
      else {
         dmac().CERQ = dmaChannelNum;
      }
   }

#ifdef DMA_EARS_EDREQ_0_MASK
   /**
    * Enable/disable DMA asynchronous requests on a channel\n
    * The channel should be configured beforehand using configureTransfer()
    *
    * @param[in]  dmaChannelNum Channel being modified
    * @param[in]  enable        True => enable, False => disable
    */
   static void __attribute__((always_inline)) enableAsynchronousRequests(DmaChannelNum dmaChannelNum, bool enable=true) {
#ifdef DEBUG_BUILD
      if (dmaChannelNum>=Info::NumChannels) {
         setAndCheckErrorCode(E_ILLEGAL_PARAM);
      }
#endif
      if (enable) {
         dmac().EARS |= (1<<dmaChannelNum);
      }
      else {
         dmac().EARS &= ~(1<<dmaChannelNum);
      }
   }
#endif

   /**
    * Enable/disable error interrupts on multiple channels.
    *
    * @param[in]  dmaChannelMask Mask for channels being modified
    * @param[in]  enable         True => enable, False => disable
    */
   static void __attribute__((always_inline)) enableMultipleErrorInterrupts(uint32_t dmaChannelMask, bool enable=true) {
#ifdef DEBUG_BUILD
      if (dmaChannelMask&~((1<<Info::NumChannels)-1)) {
         setAndCheckErrorCode(E_ILLEGAL_PARAM);
      }
#endif
      if (enable) {
         dmac().EEI |= dmaChannelMask;
      }
      else {
         dmac().EEI &= ~dmaChannelMask;
      }
   }

   /**
    * Enable/disable error interrupts for a channel.
    *
    * @param[in]  dmaChannelNum Channel being modified
    * @param[in]  enable        True => enable, False => disable
    *
    * @note May use DmaChannelNum_All to apply to all channels
    */
   static void __attribute__((always_inline)) enableErrorInterrupts(DmaChannelNum dmaChannelNum, bool enable=true) {
#ifdef DEBUG_BUILD
      if (dmaChannelNum>=Info::NumChannels) {
         setAndCheckErrorCode(E_ILLEGAL_PARAM);
      }
#endif
      if (enable) {
         dmac().SEEI = dmaChannelNum;
      }
      else {
         dmac().CEEI = dmaChannelNum;
      }
   }

   /**
    * Clear done flag for a channel.
    *
    * @param[in]  dmaChannelNum  Channel being modified
    *
    * @note May use DmaChannelNum_All to apply to all channels
    */
   static void __attribute__((always_inline)) clearDoneFlag(DmaChannelNum dmaChannelNum) {
#ifdef DEBUG_BUILD
      if (dmaChannelNum>=Info::NumChannels) {
         setAndCheckErrorCode(E_ILLEGAL_PARAM);
      }
#endif
      dmac().CDNE = dmaChannelNum;
   }

   /**
    * Clear interrupt request flags on multiple channels.
    *
    * @param[in]  dmaChannelMask Mask for channels being modified
    * @param[in]  enable         True => enable, False => disable
    */
   static void __attribute__((always_inline)) clearMultipleInterruptRequests(uint32_t dmaChannelMask, bool enable=true) {
#ifdef DEBUG_BUILD
      if (dmaChannelMask&~((1<<Info::NumChannels)-1)) {
         setAndCheckErrorCode(E_ILLEGAL_PARAM);
      }
#endif
      if (enable) {
         dmac().INT |= dmaChannelMask;
      }
      else {
         dmac().INT &= ~dmaChannelMask;
      }
   }

   /**
    * Clear interrupt request flag for a channel.
    *
    * @param[in]  dmaChannelNum  Channel being modified
    *
    * @note May use DmaChannelNum_All to apply to all channels
    */
   static void __attribute__((always_inline)) clearInterruptRequest(DmaChannelNum dmaChannelNum) {
#ifdef DEBUG_BUILD
      if (dmaChannelNum>=Info::NumChannels) {
         setAndCheckErrorCode(E_ILLEGAL_PARAM);
      }
#endif
      dmac().CINT = dmaChannelNum;
   }

   /**
    * Enable/disable interrupts in NVIC.
    *
    * @param[in]  dmaChannelNum  Channel being modified
    * @param[in]  enable         True => enable, False => disable
    * @param[in]  nvicPriority   Interrupt priority
	
    * @return E_NO_ERROR on success
    */
   static ErrorCode enableNvicInterrupts(DmaChannelNum dmaChannelNum, bool enable=true, uint32_t nvicPriority=NvicPriority_Normal) {
#ifdef DEBUG_BUILD
      if (dmaChannelNum>=Info::NumChannels) {
         setAndCheckErrorCode(E_ILLEGAL_PARAM);
      }
#endif
      IRQn_Type irqNum = Dma0Info::irqNums[0] + (dmaChannelNum&(Dma0Info::NumChannels-1));
      if (enable) {
         enableNvicInterrupt(irqNum, nvicPriority);
      }
      else {
         // Disable interrupts
         NVIC_DisableIRQ(irqNum);
      }
      return E_NO_ERROR;
   }

   /**
    * Enable/disable error interrupts in NVIC.
    *
    * @param[in]  enable        True => enable, False => disable
    * @param[in]  nvicPriority  Interrupt priority

    * @return E_NO_ERROR on success
    */
   static ErrorCode enableNvicErrorInterrupt(bool enable=true, uint32_t nvicPriority=NvicPriority_Normal) {
      if (enable) {
         enableNvicInterrupt(Info::irqNums[Info::irqCount-1], nvicPriority);
      }
      else {
         // Disable interrupts
         NVIC_DisableIRQ(Info::irqNums[Info::irqCount-1]);
      }
      return E_NO_ERROR;
   }

   /**
    * Set callback for ISR.
    *
    * @param[in]  dmaChannelNum  The DMA channel to set callback for
    * @param[in]  callback       The function to call from stub ISR
    */
   static void __attribute__((always_inline)) setCallback(DmaChannelNum dmaChannelNum, DmaCallbackFunction callback) {
#ifdef DEBUG_BUILD
      if (dmaChannelNum>=Info::NumChannels) {
         setAndCheckErrorCode(E_ILLEGAL_PARAM);
      }
#endif
      if (callback == nullptr) {
         callback = noHandlerCallback;
      }
      callbacks[dmaChannelNum] = callback;
   }

   /**
    * Set error callback for ISR.
    *
    * @param[in] callback The function to call from stub ISR
    */
   static void __attribute__((always_inline)) setErrorCallback(DmaErrorCallbackFunction callback) {
      if (callback == nullptr) {
         callback = noHandlerErrorCallback;
      }
      errorCallback = callback;
   }
};

/**
 * Callback table for programmatically set handlers.
 */
template<class Info> DmaCallbackFunction DmaBase_T<Info>::callbacks[];

/**
 * Callback for programmatically set error handler.
 */
template<class Info> DmaErrorCallbackFunction DmaBase_T<Info>::errorCallback = noHandlerErrorCallback;

/** Bit-mask of allocated channels */
template<class Info> uint32_t DmaBase_T<Info>::allocatedChannels = -1;

#ifdef USBDM_DMAMUX0_IS_DEFINED
using DmaMux0 = DmaMux_T<Dmamux0Info, Dma0Info::NumChannels>;
#endif

#ifdef USBDM_DMAMUX1_IS_DEFINED
using DmaMux1 = DmaMux_T<Dmamux1Info, Dma1Info::NumChannels>;
#endif

#ifdef USBDM_DMA0_IS_DEFINED
using Dma0 = DmaBase_T<Dma0Info>;
#endif

#ifdef USBDM_DMA1_IS_DEFINED
using Dma0 = DmaBase_T<Dma1Info>;
#endif

/**
 * End DMA_Group
 * @}
 */
} // End namespace USBDM

#endif /* INCLUDE_USBDM_DMA_H_ */
