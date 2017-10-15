/**
 * @file     pdb.h (180.ARM_Peripherals/Project_Headers/pdb.h)
 * @brief    Programmable Delay Block
 *
 * @version  V4.12.1.80
 * @date     13 April 2016
 */

#ifndef HEADER_PDB_H
#define HEADER_PDB_H
 /*
 * *****************************
 * *** DO NOT EDIT THIS FILE ***
 * *****************************
 *
 * This file is generated automatically.
 * Any manual changes will be lost.
 */
#include "hardware.h"

namespace USBDM {

/**
 * @addtogroup PDB_Group PDB, Programmable Delay Block
 * @brief Peripheral information for Programmable Delay Block
 * @{
 */
/**
 * Type definition for PDB interrupt call back
 */
typedef void (*PDBCallbackFunction)();

/**
 * Select the PDB clock pre-scale which affects counter speed
 */
enum PdbPrescale {
   PdbPrescale_1      = PDB_SC_PRESCALER(0),   //!< Divide by 1
   PdbPrescale_2      = PDB_SC_PRESCALER(1),   //!< Divide by 2
   PdbPrescale_4      = PDB_SC_PRESCALER(2),   //!< Divide by 4
   PdbPrescale_8      = PDB_SC_PRESCALER(3),   //!< Divide by 8
   PdbPrescale_16     = PDB_SC_PRESCALER(4),   //!< Divide by 16
   PdbPrescale_32     = PDB_SC_PRESCALER(5),   //!< Divide by 32
   PdbPrescale_64     = PDB_SC_PRESCALER(6),   //!< Divide by 64
   PdbPrescale_128    = PDB_SC_PRESCALER(7),   //!< Divide by 128
};

/**
 * Select the PDB clock pre-scale multiplier
 */
enum PdbMultiplier {
   PdbMultiplier_1      = PDB_SC_MULT(0),   //!< Prescaler multiplied by 1
   PdbMultiplier_10     = PDB_SC_MULT(1),   //!< Prescaler multiplied by 10
   PdbMultiplier_20     = PDB_SC_MULT(2),   //!< Prescaler multiplied by 20
   PdbMultiplier_40     = PDB_SC_MULT(3),   //!< Prescaler multiplied by 40
};

/**
 * Selects the PDB Trigger source
 */
enum PdbTrigger {
   PdbTrigger_External     = PDB_SC_TRGSEL(0),   //!< External Trigger Source PDBx_EXTRG
   PdbTrigger_Cmp0         = PDB_SC_TRGSEL(1),   //!< Comparator 0
   PdbTrigger_Cmp1         = PDB_SC_TRGSEL(2),   //!< Comparator 1
   PdbTrigger_3            = PDB_SC_TRGSEL(3),   //!< Reserved
   PdbTrigger_PitCh0       = PDB_SC_TRGSEL(4),   //!< PIT Channel 0
   PdbTrigger_PitCh1       = PDB_SC_TRGSEL(5),   //!< PIT Channel 1
   PdbTrigger_PitCh2       = PDB_SC_TRGSEL(6),   //!< PIT Channel 2
   PdbTrigger_PitCh3       = PDB_SC_TRGSEL(7),   //!< PIT Channel 3
   PdbTrigger_Ftm0         = PDB_SC_TRGSEL(8),   //!< FTM0 Init and Ext Trigger Outputs
   PdbTrigger_Ftm1         = PDB_SC_TRGSEL(9),   //!< FTM1 Init and Ext Trigger Outputs
   PdbTrigger_10           = PDB_SC_TRGSEL(10),  //!< Reserved
   PdbTrigger_11           = PDB_SC_TRGSEL(11),  //!< Reserved
   PdbTrigger_RtcAlarm     = PDB_SC_TRGSEL(12),  //!< RTC Alarm
   PdbTrigger_RtcSeconds   = PDB_SC_TRGSEL(13),  //!< RTC Seconds
   PdbTrigger_Lptrm        = PDB_SC_TRGSEL(14),  //!< LPTMR
   PdbTrigger_Software     = PDB_SC_TRGSEL(15),  //!< Software Trigger
};

/**
 * Controls the loading of MOD, IDLY, CHnDLYm, DACINTx,and POyDLY register from holding registers
 */
enum PdbLoadMode {
   PdbLoadMode_Immediate = PDB_SC_LDMOD(0), //!< The register are loaded immediately after LD_OK is set
   PdbLoadMode_Modulo    = PDB_SC_LDMOD(1), //!< The register are loaded when the counter reaches the modulo value
   PdbLoadMode_Event     = PDB_SC_LDMOD(2), //!< The register are loaded when a trigger event occurs
   PdbLoadMode_Both      = PDB_SC_LDMOD(3), //!< The register are loaded when either counter reaches the modulo value or trigger event occurs
};

/**
 * Controls whether the PDB interrupt is enabled
 */
enum PdbInterrupt {
   PdbInterrupt_Disable = PDB_SC_PDBIE(0),  //!< Sequence interrupt disabled
   PdbInterrupt_Enable  = PDB_SC_PDBIE(1),  //!< Sequence interrupt enabled
};

/**
 * Controls whether the PDB operates in one-shot or continuous mode
 */
enum PdbMode {
   PdbMode_OneShot    = PDB_SC_CONT(0),  //!< Sequence runs once only
   PdbMode_Continuous = PDB_SC_CONT(1),  //!< Sequence runs continuously once triggered
};

/**
 * Controls whether the PDB generates DMA requests
 */
enum PdbDma {
   PdbDma_Disable  = PDB_SC_CONT(0),  //!< DMA is disabled
   PdbDma_Enable   = PDB_SC_CONT(1),  //!< DMA enabled
};

/**
 * Controls whether the PDB error interrupt is enabled
 */
enum PdbErrorInterrupt {
   PdbErrorInterrupt_Disable = PDB_SC_PDBEIE(0),   //!< Sequence error disabled
   PdbErrorInterrupt_Enable  = PDB_SC_PDBEIE(1),   //!< Sequence error enabled
};

enum PdbPretrigger0 {
   PdbPretrigger0_Disable = PDB_C1_EN(0<<0),                   //!< Pretrigger 0 disabled
   PdbPretrigger0_Bypass  = PDB_C1_EN(1<<0)|PDB_C1_TOS(0<<0),  //!< Pretrigger 0 asserts 1 clock after trigger
   PdbPretrigger0_Delay   = PDB_C1_EN(1<<0)|PDB_C1_TOS(1<<0),  //!< Pretrigger 0 asserts 1 clock + delay after trigger
};

enum PdbPretrigger1 {
   PdbPretrigger1_Disable = PDB_C1_EN(0<<1),                   //!< Pretrigger 1 disabled
   PdbPretrigger1_Bypass  = PDB_C1_EN(1<<1)|PDB_C1_TOS(0<<1),  //!< Pretrigger 1 asserts 1 clock after trigger
   PdbPretrigger1_Delay   = PDB_C1_EN(1<<1)|PDB_C1_TOS(1<<1),  //!< Pretrigger 1 asserts 1 clock + delay after trigger
};

/**
 * Template class providing interface to Programmable Delay Block
 *
 * @tparam info      Information class for PDB
 *
 * @code
 * using pdb = PdbBase_T<PdbInfo>;
 *
 *  pdb::configure();
 *
 * @endcode
 */
template <class Info>
class PdbBase_T {

protected:
   /** Callback function for ISR */
   static PDBCallbackFunction callback;
   /** Callback function for error ISR */
   static PDBCallbackFunction errorCallback;
   /** Handler for unexpected interrupts */
   static void illegalInterruptHandler() {
      setAndCheckErrorCode(E_NO_HANDLER);
   }
public:
   /**
    * IRQ handler
    */
   static void irqHandler(void) {

      if (PdbBase_T<Info>::pdb->SC & PDB_SC_PDBIF_MASK) {
         // Clear interrupt flag
         PdbBase_T<Info>::pdb->SC  &= ~PDB_SC_PDBIF_MASK;
         // Handle expected interrupt
         callback();
         return;
      }
      // Assume sequence error
      errorCallback();
   }

   /**
    * Set Callback function
    *
    *   @param[in]  theCallback - Callback function to be executed on PDB interrupt
    */
   static void setCallback(PDBCallbackFunction theCallback) {
      if (theCallback == nullptr) {
         callback = illegalInterruptHandler;
         return;
      }
      callback = theCallback;
   }
   /**
    * Set Callback function
    *
    *   @param[in]  theCallback - Callback function to be executed on PDB interrupt
    */
   static void setErrorCallback(PDBCallbackFunction theCallback) {
      if (theCallback == nullptr) {
         errorCallback = illegalInterruptHandler;
         return;
      }
      errorCallback = theCallback;
   }


protected:
   static constexpr volatile PDB_Type *pdb      = Info::pdb;
   static constexpr volatile uint32_t *clockReg = Info::clockReg;

public:
   /**
    * Configures all mapped pins associated with this peripheral
    */
   static void __attribute__((always_inline)) configureAllPins() {
      // Configure pins
      Info::initPCRs();
   }

   /**
    * Enable clock to the PDB
    */
   static void  __attribute__((always_inline)) enable() {
      configureAllPins();

      *clockReg |= Info::clockMask;
      __DMB();
   }

   /**
    * Enables PDB and sets to default configuration.
    *
    * Includes enabling clock and any pins used.\n
    * Sets PDB to default configuration.
    */
   static void configure() {
      enable();

      pdb->MOD  = Info::pdb_mod;
      pdb->IDLY = Info::pdb_idly;
      pdb->CH[0].C1     = Info::pdb_ch[0].c1;
      pdb->CH[0].DLY[0] = Info::pdb_ch[0].dly0;
      pdb->CH[0].DLY[1] = Info::pdb_ch[0].dly1;
      if (Info::numChannels>1) {
         pdb->CH[1].C1     = Info::pdb_ch[1].c1;
         pdb->CH[1].DLY[0] = Info::pdb_ch[1].dly0;
         pdb->CH[1].DLY[1] = Info::pdb_ch[1].dly1;
      }
#ifdef PDB_INT_INT
      if (Info::numDacs>0) {
         pdb->DAC[0].INTC = Info::pdb_dac[0].dacintc;
         pdb->DAC[0].INT  = Info::pdb_dac[0].dacint;
      }
      if (Info::numDacs>1) {
         pdb->DAC[1].INTC = Info::pdb_dac[1].dacintc;
         pdb->DAC[1].INT  = Info::pdb_dac[1].dacint;
      }
#endif
#ifdef PDB_POEN_POEN
      pdb->POEN = Info::pdb_poen;
      if (Info::numPulseOutputs>0) {
         pdb->PODLY[0]     = Info::pdb_podly[0];
      }
      if (Info::numPulseOutputs>1) {
         pdb->PODLY[1]     = Info::pdb_podly[1];
      }
      if (Info::numPulseOutputs>2) {
         pdb->PODLY[2]     = Info::pdb_podly[2];
      }
      if (Info::numPulseOutputs>3) {
         pdb->PODLY[3]     = Info::pdb_podly[3];
      }
#endif
      // Configure and trigger register load
      pdb->SC = Info::pdb_sc|PDB_SC_PDBEN_MASK|PDB_SC_LDOK_MASK;
      enableNvicInterrupts();
   }

   /**
    * Calculate interval in ticks
    *
    * @param[in] period  Required period in seconds
    *
    * @return Number of tick corresponding to the period
    *
    * @note This uses the current PDB clock settings (pdb_sc_mult, pdb_sc_prescaler)
    */
   static uint32_t calcTicksFromTime(float period) {

      float clockFrequency = Info::getInputClockFrequency();
      int multValue        = (pdb->SC&PDB_SC_MULT_MASK)>>PDB_SC_MULT_SHIFT;
      int prescaleValue    = (pdb->SC&PDB_SC_PRESCALER_MASK)>>PDB_SC_PRESCALER_SHIFT;

      // Multiplier factors for prescale divider
      static const int multFactors[] = {1,10,20,40};
      float clock = clockFrequency/(multFactors[multValue]*(1<<prescaleValue));
      return round(period*clock)-1;
   }

   /**
    * Get 'best' dividers for given period.
    * This involves finding the smallest prescaler that allows the PDB period to be set to greater
    * than the given period.\n
    * This produces the highest resolution.\n
    * It is quite possible that other values would be more suitable for a particular application.
    * For example, carefully chosen prescalers may result in less rounding for the needed intermediate
    * points for pulse outputs etc.
    *
    * @param[in]  period          Period in seconds as a float
    * @param[out] multValue       Determined pdb_sc_mult value
    * @param[out] prescaleValue   Determined pdb_sc_prescaler value
    *
    * @return E_NO_ERROR  => success
    * @return E_ERROR     => failed to find suitable values
    */
   static ErrorCode getDividers(float period, uint32_t &multValue, int &prescaleValue) {

      // Multiplier factors for prescale divider
      static const int   multFactors[] = {1,10,20,40};

      float inputClock = Info::getInputClockFrequency();

      // No MOD value found so far
      uint32_t mod = 0;

      // Try each divider multiplier
      for (unsigned trialMultValue=0; trialMultValue<(sizeof(multFactors)/sizeof(multFactors[0])); trialMultValue++) {
         int multfactor = multFactors[trialMultValue];

         // Try prescalers from smallest to largest
         // Find first prescaler for which a suitable modulo exists
         int prescaleFactor=1;
         for (unsigned trialPrescaleValue=0; trialPrescaleValue<=7; trialPrescaleValue++) {
            float clock = inputClock/(multfactor*prescaleFactor);
            uint32_t trialMod = round(period*clock)-1;
//            console.
//               write("multfactor = ").write(multfactor).
//               write(", prescaleFactor = ").write(prescaleFactor).
//               write(", mod = ").write(trialMod).
//               write(", period = ").writeln(period);
            if (trialMod <= 0) {
               // Too short a period
               return E_TOO_SMALL;
            }
            if (trialMod <= 65535) {
               if (trialMod>mod) {
                  // Better value - save
                  prescaleValue = trialPrescaleValue;
                  multValue     = trialMultValue;
                  mod           = trialMod;
               }
               break;
            }
            prescaleFactor <<= 1;
         }
      }
      return setErrorCode((mod==0)?E_ERROR:E_NO_ERROR);
   }

   /**
    * Sets period to given value.
    *
    * It attempts to get 'best' dividers for given period.\n
    * This involves finding the smallest prescaler that allows the PDB period
    * to be set to greater than the given period.\n
    * This produces the highest resolution.\n
    * It is quite possible that other values would be more suitable for a particular application.
    * For example, carefully chosen prescalers may result in less rounding for the needed intermediate points
    * for pulse outputs etc.
    *
    * @param[in]  period Period in seconds as a float
    *
    * @return E_NO_ERROR  => success
    * @return E_ERROR     => failed to find suitable values
    *
    * @note This affects pdb_sc_mult, pdb_sc_prescaler, pdb_mod
    */
   static ErrorCode setPeriod(float period) {
      uint32_t mult     = 0;
      int      prescale = 0;

      ErrorCode rc = getDividers(period, mult, prescale);
      if (rc != E_NO_ERROR) {
         return rc;
      }
      pdb->SC  = (pdb->SC&~(PDB_SC_MULT_MASK|PDB_SC_PRESCALER_MASK))|PDB_SC_MULT(mult)|PDB_SC_PRESCALER(prescale)|PDB_SC_PDBIF_MASK;
	  // Recalculat MOD using calcTicksFromTime() to ensure consistent results
      pdb->MOD = calcTicksFromTime(period);

      return E_NO_ERROR;
   }

   /**
    * Set clock dividers
    *
    * @param[in]  pdbPrescale    Clock pre-scale (pdb_sc_mult)
    * @param[in]  pdbMultiplier  Clock pre-scale multiplier (pdb_sc_prescaler)
    */
   static void __attribute__((always_inline)) setClock(PdbPrescale pdbPrescale, PdbMultiplier pdbMultiplier) {
      pdb->SC  = (pdb->SC&~(PDB_SC_MULT_MASK|PDB_SC_PRESCALER_MASK))|pdbPrescale|pdbMultiplier;
   }

   /**
    * Set modulo of the PDB counter (in ticks)
    *
    * @param[in] modulo Modulo value for the counter (pdb_mod)
    */
   static void __attribute__((always_inline)) setModulo(int modulo) {
      pdb->MOD = modulo;
   }

   /**
    * Set interrupt delay (in ticks)
    *
    * @param[in] delay Modulo value for the counter (pdb_mod)
    */
   static void __attribute__((always_inline)) setInterruptDelayInTicks(int delay) {
      pdb->IDLY = delay;
   }

   /**
    * Set interrupt delay (in seconds)
    *
    * @param[in] delay Modulo value for the counter (pdb_mod)
    */
   static void __attribute__((always_inline)) setInterruptDelay(float delay) {
      pdb->IDLY = calcTicksFromTime(delay);
   }

   /**
    * Set trigger source and whether one-shot or continuous operation
    *
    * @param[in] pdbTrigger      Trigger source (pdb_sc_trgsel)
    * @param[in] pdbMode         PDB mode. Controls if the PDB does one sequence or repeats (pdb_sc_cont)
    */
   static void __attribute__((always_inline)) setTriggerSource(PdbTrigger pdbTrigger, PdbMode pdbMode=PdbMode_OneShot) {
      pdb->SC = (pdb->SC&~PDB_SC_TRGSEL_MASK)|pdbTrigger|pdbMode|PDB_SC_PDBIF_MASK;
   }

   /**
    * Trigger PDB sequence (pdb_sc_swtrig, pdb_sc_trigsel)
    */
   static __attribute__((always_inline)) void softwareTrigger() {

      // PdbTrigger_Software must be all 1's for this to work
      static_assert(PdbTrigger_Software==PDB_SC_TRGSEL_MASK, "Unexpected value for PdbTrigger_Software");
      pdb->SC |= PdbTrigger_Software|PDB_SC_SWTRIG_MASK|PDB_SC_PDBIF_MASK;
   }

   /**
    * Enable PDB and triggers loading of MOD, IDLY, CHnDLYm, DACINTx,and POyDLY from holding registers
    *
    * @param[in]  pdbLoadMode Controls when the registers are loaded. (pdb_sc_ldmod)
    *
    * @note The actual loading time is governed by pdbLoadMode
    * @note isLoadRegistersComplete() may be used to check if the loading has occurred.
    */
   static void __attribute__((always_inline)) triggerRegisterLoad(PdbLoadMode pdbLoadMode) {
      pdb->SC = (pdb->SC&~PDB_SC_LDMOD_MASK)|pdbLoadMode|PDB_SC_PDBEN_MASK|PDB_SC_LDOK_MASK|PDB_SC_PDBIF_MASK;
   }

   /**
    * Indicates if loading of MOD, IDLY, CHnDLYm, DACINTx,and POyDLY registers is complete
    *
    * @note The loading is triggered by loadRegisters()
    */
   static bool __attribute__((always_inline)) isRegisterLoadComplete() {
      return !(pdb->SC & PDB_SC_LDOK_MASK);
   }

   /**
    * Enable/disable interrupts in NVIC
    *
    * @param[in]  enable    True => enable, False => disable
    * @param[in]  priority  Interrupt priority
    */
   static void enableNvicInterrupts(bool enable=true, uint32_t nvicPriority=NvicPriority_Normal) {

      if (enable) {
         enableNvicInterrupt(Info::irqNums[0], nvicPriority);
      }
      else {
         // Disable interrupts
         NVIC_DisableIRQ(Info::irqNums[0]);
      }
   }

   /**
    * Enable/disable sequence error interrupts (pdb_sc_pdbeie)
    *
    * @param[in]  enable True => enable, False => disable
    */
   static void enableErrorInterrupts(bool enable=true) {
      if (enable) {
         pdb->SC |= PDB_SC_PDBEIE_MASK;
      }
      else {
         pdb->SC &= ~PDB_SC_PDBEIE_MASK;
      }
   }

   /**
    * Enable/disable sequence interrupts (pdb_sc_pdbie)
    *
    * @param[in]  enable True => enable, False => disable
    */
   static void enableSequenceInterrupts(bool enable=true) {
      if (enable) {
         pdb->SC |= PDB_SC_PDBIE_MASK;
      }
      else {
         pdb->SC &= ~PDB_SC_PDBIE_MASK;
      }
   }

   /**
    * Enable/disable DMA (pdb_sc_dmaen)
    *
    * @param[in]  enable True => enable, False => disable
    */
   static void enableDma(bool enable=true) {
      if (enable) {
         pdb->SC |= PDB_SC_DMAEN_MASK;
      }
      else {
         pdb->SC &= ~PDB_SC_DMAEN_MASK;
      }
   }

   /**
    * Set Interrupts and DMA options
    *
    * @param[in] pdbInterrupt       Whether sequence interrupt requests are generated
    * @param[in] pdbErrorInterrupt  Whether error interrupt requests are generated
    * @param[in] pdbDma             Whether DMA requests are generated
    */
   static void setInterrupts(
         PdbInterrupt         pdbInterrupt      = PdbInterrupt_Disable,
         PdbErrorInterrupt    pdbErrorInterrupt = PdbErrorInterrupt_Disable,
         PdbDma               pdbDma            = PdbDma_Disable) {
      pdb->SC = (pdb->SC&~(PDB_SC_PDBIE_MASK|PDB_SC_PDBEIE_MASK|PDB_SC_DMAEN_MASK))|pdbInterrupt|pdbErrorInterrupt|pdbDma;
   }

   /**
    * Configures the pretriggers associated with a channel.
    *
    * Each pretrigger corresponds to an ADC SC1[n] R[n] register pair used in hardware triggered mode i.e.
    * Channel X, Pretrigger Y => adcX_sc1[Y], adc0_r[Y].
    * For example:
    *   Channel 0, Pretrigger 0 => adc0_sc1[0], adc0_r[0]
    *   Channel 0, Pretrigger 1 => adc0_sc1[1], adc0_r[1] etc.
    *
    * This allows multiple different ADC channels to be converted in a sequence.
    *
    * @param[in] channel         Channel to affect
    * @param[in] pdbPretrigger0  Pretrigger mode for pretrigger 0
    * @param[in] delay0          Delay for pretrigger 0 in ticks
    * @param[in] pdbPretrigger1  Pretrigger mode for pretrigger 1
    * @param[in] delay1          Delay for pretrigger 1 in ticks
    */
   static void setPretriggersInTicks(int channel,
         PdbPretrigger0 pdbPretrigger0=PdbPretrigger0_Bypass,  uint16_t delay0=0,
         PdbPretrigger1 pdbPretrigger1=PdbPretrigger0_Disable, uint16_t delay1=0) {

      pdb->CH[channel].C1     = pdbPretrigger0|pdbPretrigger1;
      pdb->CH[channel].DLY[0] = delay0;
      pdb->CH[channel].DLY[1] = delay1;
   }
   /**
    * Configures the pretriggers associated with a channel.
    *
    * Each pretrigger corresponds to an ADC SC1[n] R[n] register pair used in hardware triggered mode i.e.
    * Channel X, Pretrigger Y => adcX_sc1[Y], adc0_r[Y].
    * For example:
    *   Channel 0, Pretrigger 0 => adc0_sc1[0], adc0_r[0]
    *   Channel 0, Pretrigger 1 => adc0_sc1[1], adc0_r[1] etc.
    *
    * This allows multiple different ADC channels to be converted in a sequence.
    *
    * @param[in] channel         Channel to affect
    * @param[in] pdbPretrigger0  Pretrigger mode for pretrigger 0
    * @param[in] delay0          Delay for pretrigger 0 in seconds
    * @param[in] pdbPretrigger1  Pretrigger mode for pretrigger 1
    * @param[in] delay1          Delay for pretrigger 1 in seconds
    */
   static void setPretriggers(int channel,
         PdbPretrigger0 pdbPretrigger0,                        float delay0,
         PdbPretrigger1 pdbPretrigger1=PdbPretrigger1_Disable, float delay1=0.0) {

      pdb->CH[channel].C1     = pdbPretrigger0|pdbPretrigger1;
      pdb->CH[channel].DLY[0] = calcTicksFromTime(delay0);
      pdb->CH[channel].DLY[1] = calcTicksFromTime(delay1);
   }

   /**
    * Get error and sequence flags for the PDB channel
    *
    * @param[in] channel the PDB channel to clear
    */
   static uint32_t getChannelFlags(int channel) {
      return pdb->CH[channel].S;
   }

   /**
    * Clear error and sequence flags in the PDB channel
    *
    * @param[in] channel the PDB channel to clear
    */
   static void clearErrorFlags(int channel) {
      // Clear flags
      pdb->CH[channel].S = PDB_S_ERR_MASK; // w1c bits
   }
};

template<class Info> PDBCallbackFunction PdbBase_T<Info>::callback = PdbBase_T<Info>::illegalInterruptHandler;
template<class Info> PDBCallbackFunction PdbBase_T<Info>::errorCallback = PdbBase_T<Info>::illegalInterruptHandler;

#ifdef USBDM_PDB_IS_DEFINED
/**
 * Class representing PDB
 */
using Pdb = PdbBase_T<PdbInfo>;

#endif

#ifdef USBDM_PDB0_IS_DEFINED
/**
 * Class representing PDB
 */
using Pdb0 = PdbBase_T<Pdb0Info>;

#endif

/**
 * End PDB_Group
 * @}
 */
} // End namespace USBDM

#endif /* HEADER_PDB_H */
