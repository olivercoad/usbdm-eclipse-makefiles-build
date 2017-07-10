/**
 * @file     pit.h (180.ARM_Peripherals/Project_Headers/pit-MK.h)
 *
 * @brief    Programmable Interrupt Timer interface
 *
 * @version  V4.12.1.80
 * @date     13 April 2016
 */

#ifndef INCLUDE_USBDM_PIT_H_
#define INCLUDE_USBDM_PIT_H_
/*
 * *****************************
 * *** DO NOT EDIT THIS FILE ***
 * *****************************
 *
 * This file is generated automatically.
 * Any manual changes will be lost.
 */
#include "derivative.h"
#include "system.h"
#include "hardware.h"

namespace USBDM {

/**
 * @addtogroup PIT_Group PIT, Programmable Interrupt Timer
 * @brief Abstraction for Programmable Interrupt Timer
 * @{
 */
/**
 * Type definition for PIT interrupt call back
 */
typedef void (*PITCallbackFunction)(void);

/**
 * @brief Class representing a Programmable Interrupt  Timer
 *
 * <b>Example</b>
 * @code
 *
 * @endcode
 */
template<class Info>
class Pit_T {

private:
   /**
    * This class is not intended to be instantiated
    */
   Pit_T() = delete;
   Pit_T(const Pit_T&) = delete;
   Pit_T(Pit_T&&) = delete;

protected:
   /** Default TCTRL value for timer channel */
   static constexpr uint32_t PIT_TCTRL_DEFAULT_VALUE = (PIT_TCTRL_TEN_MASK);

   /** Callback functions for ISRs */
   static PITCallbackFunction callbacks[Info::irqCount];

   /** Callback to catch unhandled interrupt */
   static void errorCallback() {
      setAndCheckErrorCode(E_NO_HANDLER);
   }
   
public:
   /** PIT interrupt handler -  Calls PIT0 callback */
   static void irq0Handler() {
      // Clear interrupt flag
      PIT->CHANNEL[0].TFLG = PIT_TFLG_TIF_MASK;
      callbacks[0]();
   }
   /** PIT interrupt handler -  Calls PIT1 callback */
   static void irq1Handler() {
      // Clear interrupt flag
      PIT->CHANNEL[1].TFLG = PIT_TFLG_TIF_MASK;
      callbacks[1]();
   }
   /** PIT interrupt handler -  Calls PIT2 callback */
   static void irq2Handler() {
      // Clear interrupt flag
      PIT->CHANNEL[2].TFLG = PIT_TFLG_TIF_MASK;
      callbacks[2]();
   }
   /** PIT interrupt handler -  Calls PIT3 callback */
   static void irq3Handler() {
      // Clear interrupt flag
      PIT->CHANNEL[3].TFLG = PIT_TFLG_TIF_MASK;
      callbacks[3]();
   }

public:
   /**
    * Enable/disable channel interrupts
    *
    * @param[in]  channel Channel being modified
    * @param[in]  enable  True => enable, False => disable
    */
   static void enableInterrupts(unsigned channel, bool enable=true) {
      if (enable) {
         pit->CHANNEL[channel].TCTRL |= PIT_TCTRL_TIE_MASK;
      }
      else {
         pit->CHANNEL[channel].TCTRL &= ~PIT_TCTRL_TIE_MASK;
      }
   }

   /**
    * Set callback for ISR
    *
    * @param[in]  channel  The PIT channel to modify
    * @param[in]  callback The function to call from stub ISR
    */
   static void setCallback(unsigned channel, PITCallbackFunction callback) {
      if (callback == nullptr) {
         callback = errorCallback;
         enableInterrupts(channel, false);
      }
      callbacks[channel] = callback;
   }

protected:
   /** Pointer to hardware */
   static constexpr volatile PIT_Type *pit       = Info::pit;

   /** Pointer to clock register */
   static constexpr volatile uint32_t *clockReg  = Info::clockReg;

public:
   /**
    * Basic enable of PIT\n
    * Includes configuring all pins
    */
   void enable() {
      // Enable clock
      *clockReg |= Info::clockMask;
      __DMB();
   }

   /**
    *  Enable the PIT with default settings
    *
    *  @param[in]  mcr       Module Control Register
    */
   static void configure(uint32_t mcr=Info::mcr) {
      // Enable clock
      *clockReg |= Info::clockMask;
      __DMB();

      // Enable timer
      pit->MCR = mcr&~PIT_MCR_MDIS_MASK;
      for (unsigned i=0; i<Info::irqCount; i++) {
         enableNvicInterrupts(i);
      }
   }

   /**
    *   Disable the PIT (all channels)
    */
   static void disable() {
      pit->MCR = PIT_MCR_MDIS_MASK;
      *clockReg &= ~Info::clockMask;
   }

   /**
    * Enable/disable interrupts in NVIC
    *
    * @param[in]  channel Channel being modified
    * @param[in]  enable True => enable, False => disable
    *
    * @return E_NO_ERROR on success
    */
   static ErrorCode enableNvicInterrupts(unsigned channel, bool enable=true) {
      if (channel>=Info::irqCount) {
         setAndCheckErrorCode(E_ILLEGAL_PARAM);
      }
      IRQn_Type irqNum;
      switch(channel) {
         case 0: irqNum = Info::irqNums[0]; break;
         case 1: irqNum = Info::irqNums[1]; break;
         case 2: irqNum = Info::irqNums[2]; break;
         case 3: irqNum = Info::irqNums[3]; break;
         default:
            return setErrorCode(E_ILLEGAL_PARAM);
      }
      if (enable) {
         // Enable interrupts
         NVIC_EnableIRQ(irqNum);

         // Set priority level
         NVIC_SetPriority(irqNum, Info::irqLevel);
      }
      else {
         // Disable interrupts
         NVIC_DisableIRQ(irqNum);
      }
      return E_NO_ERROR;
   }
   /**
    *  Enable/Disable the PIT channel
    *
    *  @param[in]  channel   Channel to enable
    *  @param[in]  enable    Controls whether channel is enabled or disabled
    */
   static void enableChannel(const uint8_t channel, bool enable=true) {
      if (enable) {
         pit->CHANNEL[channel].TCTRL |= PIT_TCTRL_TEN_MASK;
      }
      else {
         pit->CHANNEL[channel].TCTRL &= ~PIT_TCTRL_TEN_MASK;
      }
      enableNvicInterrupts(channel, enable);
   }
   /**
    *  Configure the PIT channel
    *
    *  @param[in]  channel   Channel to configure
    *  @param[in]  interval  Interval in timer ticks (usually bus clock period)
    *  @param[in]  tctrl     Timer Control Register value
    */
   static void configureChannel(const uint8_t channel, uint32_t interval=Info::pit_ldval, uint32_t tctrl=PIT_TCTRL_DEFAULT_VALUE) {
      pit->CHANNEL[channel].LDVAL = interval;
      pit->CHANNEL[channel].TCTRL = tctrl;
      pit->CHANNEL[channel].TFLG  = PIT_TFLG_TIF_MASK;

      enableNvicInterrupts(channel);
   }
   /**
    *  Configure the PIT channel
    *
    *  @param[in]  channel   Channel to configure
    *  @param[in]  interval  Interval in seconds
    *  @param[in]  tctrl     Timer Control Register value
    */
   static void configureChannel(const uint8_t channel, float interval, uint32_t tctrl=PIT_TCTRL_DEFAULT_VALUE) {
      configureChannel(channel, (uint32_t)round(interval*PitInfo::getClockFrequency()), tctrl);
   }
   /**
    * Set period in seconds
    *
    * @param[in]  channel Channel being modified
    * @param[in]  interval Interval in seconds
    */
   static void setPeriod(unsigned channel, float interval) {
      pit->CHANNEL[channel].LDVAL = round(interval*PitInfo::getClockFrequency());
   }
   /**
    *   Disable the PIT channel
    *
    *   @param[in]  channel Channel to disable
    */
   static void disableChannel(uint8_t channel) {

      // Disable timer channel
      pit->CHANNEL[channel].TCTRL = 0;

      // Disable timer interrupts
      enableNvicInterrupts(channel, false);
   }
   /**
    *  Use a PIT channel to implement a busy-wait delay
    *
    *  @param[in]  channel   Channel to use
    *  @param[in]  interval  Interval to wait in timer ticks (usually bus clock period)
    *
    *  @note Function doesn't return until interval has expired
    */
   static void delay(uint8_t channel, uint32_t interval) {
      configureChannel(channel, interval, PIT_TCTRL_TEN_MASK);
      while (pit->CHANNEL[channel].TFLG == 0) {
         __NOP();
      }
      configureChannel(channel, (uint32_t)0, 0);
   }

};

/**
 * Callback table for programmatically set handlers
 */
template<class Info> PITCallbackFunction Pit_T<Info>::callbacks[] = {
   errorCallback,
   errorCallback,
   errorCallback,
   errorCallback
};

#ifdef PIT
/**
 * @brief class representing the PIT
 */
using Pit = Pit_T<PitInfo>;
#endif

/**
 * @}
 */

} // End namespace USBDM

#endif /* INCLUDE_USBDM_PIT_H_ */
