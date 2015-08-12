/**
 * @file      lptmr.h
 * @version   1.0.0
 * @brief     Low Power Timer
 */

#ifndef LPTMR_H_
#define LPTMR_H_

#include "derivative.h"
#include "system.h"
#include "pin_mapping.h"

/**
 * @addtogroup LPTMR_Group Low Power Timer
 * @brief Abstraction for Low Power Timer
 * @{
 */

//-------- <<< Use Configuration Wizard in Context Menu >>> -----------------

//===================================
// Validators

// Convention
// name_V = field value
// name_M = field mask i.e. value in correct position for register

// LPTMR_PSR_PCS ==============================
//
//   <o> LPTMR Clock Source
//   <i> Low Power Timer clock source - [LPTMR_PSR_PCS]
//     <0=> MCG Internal Reference Clock (MCGIRCLK)
//     <1=> Low power oscillator (LPO - 1kHz)
//     <2=> 32kHz Clock Source (ERCLK32)
//     <3=> Oscillator External Reference Clock (OSCERCLK)
//! Default value for LPTMR_PSR_PCS - LPTMR clock source
#define LPTMR_PSR_PCS_M (0<<LPTMR_PSR_PCS_SHIFT)

#if (LPTMR_PSR_PCS_M == (0<<LPTMR_PSR_PCS_SHIFT))
#define SYSTEM_LPTMR_CLOCK SYSTEM_MCGIR_CLOCK
#elif (LPTMR_PSR_PCS_M == (1<<LPTMR_PSR_PCS_SHIFT))
#define SYSTEM_LPTMR_CLOCK SYSTEM_LOW_POWER_CLOCK
#elif (LPTMR_PSR_PCS_M == (2<<LPTMR_PSR_PCS_SHIFT))
#define SYSTEM_LPTMR_CLOCK SYSTEM_ERCLK32_CLOCK
#elif (LPTMR_PSR_PCS_M == (3<<LPTMR_PSR_PCS_SHIFT))
#define SYSTEM_LPTMR_CLOCK SYSTEM_OSCER_CLOCK
#endif

// LPTMR_PBSR_PBYP ==============================
//
//   <q> LPTMR Prescaler Bypass
//   <i> When PBYP is set, the selected prescaler clock in Time Counter mode or
//	  <i> selected input source in Pulse Counter mode directly clocks the CNR.
//   <i> When PBYP is clear, the CNR is clocked by the output of the prescaler/glitch filter. - [LPTMR_PBSR_PBYP]
//     <0=> Prescaler/glitch filter is enabled
//     <1=> Prescaler/glitch filter is bypassed
//! Default value for LPTMR_PBSR_PBYP - Determines if LPTMR prescaler is used
#define LPTMR_PSR_PBYP_M (0<<LPTMR_PSR_PBYP_SHIFT)

// LPTMR_PSR_PRESCALE ==============================
//
//   <o> LPTMR Prescaler Value
//   <i> Configures the size of the Prescaler in Time Counter mode or
//   <i> width of the glitch filter in Pulse Counter mode.  - [LPTMR_PSR_PRESCALE]
//     <0=> Prescaler = 2, no glitch filter
//     <1=> Prescaler = 4, 2 clock glitch filter
//     <2=> Prescaler = 8, 4 clock glitch filter
//     <3=> Prescaler = 16, 8 clock glitch filter
//     <4=> Prescaler = 32, 16 clock glitch filter
//     <5=> Prescaler = 64, 32 clock glitch filter
//     <6=> Prescaler = 128, 64 clock glitch filter
//     <7=> Prescaler = 256, 128 clock glitch filter
//     <8=> Prescaler = 512, 256 clock glitch filter
//     <9=> Prescaler = 1024, 512 clock glitch filter
//     <10=> Prescaler = 2048, 1024 clock glitch filter
//     <11=> Prescaler = 4096, 2048 clock glitch filter
//     <12=> Prescaler = 8192, 4096 clock glitch filter
//     <13=> Prescaler = 16384, 8192 clock glitch filter
//     <14=> Prescaler = 32768, 16384 clock glitch filter
//     <15=> Prescaler = 65536, 32768 clock glitch filter
//! Default value for LPTMR_PSR_PRESCALE - LPTMR prescaler
#define LPTMR_PSR_PRESCALE_M (11<<LPTMR_PSR_PRESCALE_SHIFT)

// LPTMR_CSR_TMS ==============================
//
//   <q> LPTMR Timer Mode Select
//   <i> Configures the mode of the LPTMR. - [LPTMR_CSR_TMS]
//     <0=> Time Counter mode.
//     <1=> Pulse Counter mode.
//! Default value for LPTMR_CSR_TMS - determines whether LPTMR operates as time or pulse counter
#define LPTMR_CSR_TMS_M (0<<LPTMR_CSR_TMS_SHIFT)

// LPTMR_CSR_TFC ==============================
//
//   <q> LPTMR Timer Free-Running Counter
//   <i> When clear, TFC configures the CNR to reset whenever TCF is set.
//   <i> When set, TFC configures the CNR to reset on overflow. - [LPTMR_CSR_TFC]
//     <0=> CNR is reset whenever TCF is set.
//     <1=> CNR is reset on overflow
//! Default value for LPTMR_CSR_TFC - Determines if LPTMR is free running or resets on event
#define LPTMR_CSR_TFC_M (0<<LPTMR_CSR_TFC_SHIFT)

// LPTMR_CSR_TPP ==============================
//
//   <q> LPTMR Timer Pin Polarity
//   <i> Configures the polarity of the input source in Pulse Counter mode - [LPTMR_CSR_TPP]
//     <0=> Active-high source, rising-edge increments CNR
//     <1=> Active-low source,  falling-edge increments CNR 
//! Default value for LPTMR_CSR_TPP - Determines polarity of LPTMR input
#define LPTMR_CSR_TPP_M (0<<LPTMR_CSR_TPP_SHIFT)

// LPTMR_CSR_TPS ==============================
//
//   <o> LPTMR Timer Pin Select
//   <i> Configures the input source to be used in Pulse Counter mode.
//   <i> The input connections vary by device. - [LPTMR_CSR_TPS]
//     <0=> CMP0 output
//     <1=> LPTMR_ALT1 pin
//     <3=> LPTMR_ALT2 pin
//     <4=> Reserved
//! Default value for LPTMR_CSR_TPS - Determines timer input
#define LPTMR_CSR_TPS_M (0<<LPTMR_CSR_TPS_SHIFT)

// LPTMR IRQ Level in NVIC ==============================
//
//   <o> LPTMR IRQ Level in NVIC <0-15>
//   <i> Configures the IRQ level set in the NVIC.
//! Default value for LPTMR interrupt level
#define LPTMR_IRQ_LEVEL_V (2)

// LPTMR_USES_NAKED_HANDLER ==============================
//
//   <q> Interrupt handler setup
//   <i> The interrupt handler may use an external function named LPTMR0_IRQHandler() or
//   <i> may be set by use of the setCallback() function  - [LPTMR_USES_NAKED_HANDLER]
//     <0=> Interrupt handler is programmatically set.
//     <1=> LPTMR0_IRQHandler() is externally provided.
//! Determines how LPTMR interrupt handler is specified
#define LPTMR_USES_NAKED_HANDLER 1

/**
 * Default PSR value for Timer
 */
#define LPTMR_PSR_DEFAULT_VALUE (LPTMR_PSR_PRESCALE_M|LPTMR_PSR_PCS_M|LPTMR_PSR_PBYP_M|LPTMR_PSR_PCS_M)
/**
 * Default CSR value for Timer
 */
#define LPTMR_CSR_DEFAULT_VALUE (LPTMR_CSR_TMS_M|LPTMR_CSR_TFC_M|LPTMR_CSR_TPP_M|LPTMR_CSR_TPS_M)

#if LPTMR_USES_NAKED_HANDLER == 0
   /**
    * Type definition for LPTMR interrupt call back
    */
   typedef void (*LPTMRCallbackFunction)(void);
#endif

   /*!
    * @brief struct representing a Low Power Timer
    *
    * <b>Example</b>
    * @code
    *
    * @endcode
    */
struct LPTMR {
            LPTMR_Type            *lptmr;
   volatile uint32_t              *clockReg;
            uint32_t               clockMask;
            IRQn_Type              interruptNumber;
            uint8_t                interruptLevel;

#if LPTMR_USES_NAKED_HANDLER == 0
            LPTMRCallbackFunction *callback;

public:
   void setCallback(LPTMRCallbackFunction callback) const {
      *(this->callback) = callback;
   }
#endif
            
   /**
    *  Configure the LPTMR
    *
    *  @param interval  Interval for the timer
    *  @param csr       Control Status Register
    *  @param psr       Prescale Register
    */
   void configure(uint16_t interval, uint32_t csr=LPTMR_CSR_DEFAULT_VALUE, uint32_t psr=LPTMR_PSR_DEFAULT_VALUE) const {
      // Enable clock
      *clockReg |= clockMask;

#ifdef LPTMR0_0_GPIO
      LPTMR0_0_GPIO.setPCR(PORT_PCR_MUX(LPTMR0_0_FN)|PORT_PCR_PE_MASK|PORT_PCR_PS_MASK);
#endif

#ifdef LPTMR0_1_GPIO
      LPTMR0_1_GPIO.setPCR(PORT_PCR_MUX(LPTMR0_1_FN)|PORT_PCR_PE_MASK|PORT_PCR_PS_MASK);
#endif

#ifdef LPTMR0_2_GPIO
      LPTMR0_2_GPIO.setPCR(PORT_PCR_MUX(LPTMR0_2_FN)|PORT_PCR_PE_MASK|PORT_PCR_PS_MASK);
#endif

#ifdef LPTMR0_3_GPIO
      LPTMR0_3_GPIO.setPCR(PORT_PCR_MUX(LPTMR0_3_FN)|PORT_PCR_PE_MASK|PORT_PCR_PS_MASK);
#endif

      // Disable timer
      lptmr->CSR = 0;
      // PCS 0,1,2,3 => MCGIRCLK, LPO, ERCLK32K, OSCERCLK
      lptmr->PSR = psr;
      // Interval/Compare value
      lptmr->CMR = interval;
      // Enable timer
      lptmr->CSR = csr|LPTMR_CSR_TEN_MASK;

      if (csr & LPTMR_CSR_TIE_MASK) {
         // Enable timer interrupts
         NVIC_EnableIRQ(interruptNumber);
         // Set arbitrary priority level
         NVIC_SetPriority(interruptNumber, interruptLevel);
      }
   }
   /**
    *   Disable the LPTMR
    */
   void finalise(void) {
      // Disable timer
      lptmr->CSR = 0;
      NVIC_DisableIRQ(interruptNumber);
      *clockReg &= ~clockMask;
   }
};

#ifdef LPTMR0
/*!
 * @brief struct representing LPTMR0
 */
extern const LPTMR LPTMR_0;
#endif

/**
 * @}
 */

#endif /* LPTMR_H_ */