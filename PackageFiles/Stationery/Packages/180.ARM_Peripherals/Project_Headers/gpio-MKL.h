/**
 * @file     gpio.h
 * @brief    General Purpose Input/Output (generated from gpio-MK.h)
 *
 * @version  V4.12.1.80
 * @date     13 April 2016
 */
#ifndef HEADER_GPIO_H
#define HEADER_GPIO_H
/*
 * *****************************
 * *** DO NOT EDIT THIS FILE ***
 * *****************************
 *
 * This file is generated automatically.
 * Any manual changes will be lost.
 */
#include <stddef.h>
#include <assert.h>
#include "derivative.h"
#include "bme.h"

/*
 * Default port information
 */
#ifndef FIXED_PORT_CLOCK_REG
#define FIXED_PORT_CLOCK_REG SCGC5
#endif

namespace USBDM {

enum Polarity {
   ActiveLow=false,
   ActiveHigh=true
};

/**
 * @addtogroup GPIO_Group GPIO, Digital Input/Output
 * @{
 */

/**
 * @brief Template representing a pin with Digital I/O capability
 *
 * <b>Example</b>
 * @code
 * // Instantiate
 * USBDM::Gpio_T<SIM_SCGC5_PORTA_MASK, PORTA_BasePtr, GPIOA_BasePtr, 3> pta3;
 *
 * // Set as digital output
 * pta3.setOutput();
 *
 * // Set pin high
 * pta3.set();
 *
 * // Set pin low
 * pta3.clear();
 *
 * // Toggle pin
 * pta3.toggle();
 *
 * // Set pin to boolean value
 * pta3.write(true);
 *
 * // Set pin to boolean value
 * pta3.write(false);
 *
 * // Set as digital input
 * pta3.setInput();
 *
 * // Read pin as boolean value
 * bool x = pta3.read();
 *
 * @endcode
 *
 * @tparam clockMask       Clock mask for PORT (PCR register) associated with GPIO
 * @tparam pcrAddress      Address of PORT (PCR register array) associated with GPIO
 * @tparam gpioAddress     GPIO hardware address
 * @tparam bitNum          Bit number within PORT/GPIO
 * @tparam polarity        Either USBDM::ActiveHigh or USBDM::ActiveLow
 */
template<uint32_t clockMask, uint32_t pcrAddress, uint32_t gpioAddress, uint32_t bitNum, Polarity polarity>
class GpioBase_T {

public:
   using Pcr = Pcr_T<clockMask, pcrAddress, bitNum, GPIO_DEFAULT_PCR>;

   static constexpr volatile GPIO_Type *gpio = reinterpret_cast<volatile GPIO_Type *>(gpioAddress);
   static constexpr uint32_t MASK = (1<<bitNum);

   /**
    * Enable pin as digital output
    *
    * @param pcrValue PCR value to use in configuring port (excluding MUX value)
    */
   static void setOutput(uint32_t pcrValue=GPIO_DEFAULT_PCR) {
      bmeOr(gpio->PDDR, 1<<bitNum);
//      gpio->PDDR |= MASK;
      Pcr::setPCR((pcrValue&~PORT_PCR_MUX_MASK)|PORT_PCR_MUX(FIXED_GPIO_FN));
   }
   /**
    * Enable pin as digital input
    *
    * @param pcrValue PCR value to use in configuring port (excluding MUX value)
    */
   static void setInput(uint32_t pcrValue=GPIO_DEFAULT_PCR) {
      bmeAnd(gpio->PDDR, ~(1<<bitNum));
//      gpio->PDDR &= ~MASK;
      Pcr::setPCR((pcrValue&~PORT_PCR_MUX_MASK)|PORT_PCR_MUX(FIXED_GPIO_FN));
   }
   /**
    * Set pin as digital output
    */
   static void setOut() {
      bmeOr(gpio->PDDR, 1<<bitNum);
//      gpio->PDDR |= MASK;
   }
   /**
    * Set pin as digital input
    */
   static void setIn() {
      bmeAnd(gpio->PDDR, ~(1<<bitNum));
//      gpio->PDDR &= ~MASK;
   }
   /**
    * Toggle pin (if output)
    */
   static void toggle() {
      gpio->PTOR = MASK;
   }
   /**
    * Set pin to active level (if output)
    *
    * @note Polarity is significant
    */
   static void set() {
      if (polarity) {
         gpio->PSOR = MASK;
      }
      else {
         gpio->PCOR = MASK;
      }
   }
   /**
    * Set pin to inactive level (if output)
    *
    * @note Polarity is significant
    */
   static void clear() {
      if (polarity) {
         gpio->PCOR = MASK;
      }
      else {
         gpio->PSOR = MASK;
      }
   }
   /**
    * Write boolean value to digital output
    *
    * @param value true/false value
    * @note Polarity is significant
    */
   static void write(bool value) {
      if (value) {
         set();
      }
      else {
         clear();
      }
   }
   /**
    * Read pin value
    *
    * @return true/false reflecting pin value.
    * @note This reads the PDIR
    * @note Polarity is significant
    */
   static bool read() {
      if (polarity) {
         return bmeExtract(gpio->PDIR, bitNum, 1);
      }
      else {
         return !bmeExtract(gpio->PDIR, bitNum, 1);
      }
   }
   /**
    * Read value being driven to pin if output
    *
    * @return true/false reflecting value in output register.
    * @note This reads the PDOR
    * @note Polarity is significant
    */
   static bool readState() {
      if (polarity) {
         return bmeExtract(gpio->PDOR, bitNum, 1);
      }
      else {
         return !bmeExtract(gpio->PDOR, bitNum, 1);
      }
   }
   /**
    * Set pin high
    *
    * @note Polarity is NOT significant
    */
   static void high() {
      gpio->PSOR = MASK;
   }
   /**
    * Set pin low
    *
    * @note Polarity is NOT significant
    */
   static void low() {
      gpio->PCOR = MASK;
   }
   /**
    * Checks if pin is high
    *
    * @return true/false reflecting value on pin
    * @note This reads the PDIR
    * @note Polarity is NOT significant
    */
   static bool isHigh() {
      return bmeExtract(gpio->PDIR, bitNum, 1);
   }
   /**
    * Checks if pin is low
    *
    * @return true/false reflecting value on pin
    * @note This reads the PDIR
    * @note Polarity is NOT significant
    */
   static bool isLow() {
      return !bmeExtract(gpio->PDIR, bitNum, 1);
   }
   /**
    * Sets pin interrupt mode
    * Convenience wrapper for PCR function
    *
    * @param mode Interrupt/DMA mode
    */
   static void setIrq(InterruptMode mode) {
      Pcr::setIrq(mode);
   }

   /**
    * Clear interrupt flag for pin
    * Convenience wrapper for PCR function
    */
   static void clearIrqFlag() {
      Pcr::clearIrqFlag();
   }

   /**
    * Set pull device on pin
    * Convenience wrapper for PCR function
    *
    * @param mode Pull control value (PullNone, PullUp, PullDown)
    */
   static void setPullDevice(PullModes mode) {
      Pcr::setPullDevice(mode);
   }

   /**
    * Locks most of the pin properties e.g. drive strength, pull-device etc.
    * Convenience wrapper for PCR function
    */
   static void lock() {
      Pcr::lock();
   }

   /**
    * Enable/disable pin interrupts
    * Convenience wrapper for PCR function
    *
    * @param enable True => enable, False => disable
    */
   static void enableNvicInterrupts(bool enable=true) {
      Pcr::enableNvicInterrupts(enable);
   }

   /**
    * Set callback for ISR \n
    * Convenience wrapper for PCR function
    *
    * @param callback The function to call from stub ISR
    */
   static void setCallback(PinCallbackFunction callback) {
      Pcr::setCallback(callback);
   }

};

/**
 * Create GPIO from GpioInfo class
 *
 * @tparam Info          Gpio information class
 * @tparam bitNum        Bit number within PORT/GPIO
 * @tparam polarity      Either USBDM::ActiveHigh or USBDM::ActiveLow
 */
template<class Info, const uint32_t bitNum, Polarity polarity=ActiveHigh>
class  Gpio_T : public GpioBase_T<Info::clockMask, Info::pcrAddress, Info::gpioAddress, bitNum, polarity> {
   static_assert((bitNum<32), "Illegal signal");
};

/**
 * Create GPIO from Peripheral Info class
 *
 * @tparam Info          Peripheral information class
 * @tparam index         Index of signal within the info table
 * @tparam polarity      Either USBDM::ActiveHigh or USBDM::ActiveLow
 */
template<class Info, const uint32_t index, Polarity polarity=ActiveHigh>
using  GpioTable_T = GpioBase_T<Info::info[index].clockMask, Info::info[index].pcrAddress, Info::info[index].gpioAddress, Info::info[index].gpioBit, polarity>;

/**
 * @brief Template representing a field within a port
 *
 * <b>Example</b>
 * @code
 * // Instantiate object representing Port A 6 down to 3
 * Field_T<GpioAInfo, 6, 3> pta6_3;
 *
 * // Set as digital output
 * pta6_3.setOutput();
 *
 * // Write value to field
 * pta6_3.write(0x53);
 *
 * // Clear all of field
 * pta6_3.bitClear();
 *
 * // Clear lower two bits of field
 * pta6_3.bitClear(0x3);
 *
 * // Set lower two bits of field
 * pta6_3.bitSet(0x3);
 *
 * // Set as digital input
 * pta6_3.setInput();
 *
 * // Read pin as int value
 * int x = pta6_3.read();
 * @endcode
 *
 * @tparam Info           Class describing the GPIO and PORT
 * @tparam left           Bit number of leftmost bit in GPIO (inclusive)
 * @tparam right          Bit number of rightmost bit in GPIO (inclusive)
 * @tparam defPcrValue    Default value for PCR including multiplexor value
 */
template<class Info, const uint32_t left, const uint32_t right>
class Field_T {

private:
   static constexpr volatile GPIO_Type *gpio = reinterpret_cast<volatile GPIO_Type *>(Info::gpioAddress);
   static constexpr volatile PORT_Type *port = reinterpret_cast<volatile PORT_Type *>(Info::pcrAddress);
   /**
    * Mask for the bits being manipulated
    */
   static constexpr uint32_t MASK = ((1<<(left-right+1))-1)<<right;
   /**
    * Utility function to set multiple PCRs using GPCLR & GPCHR
    *
    * @param pcrValue PCR value to use in configuring port (excluding mux fn)
    */
   static void setPCRs(uint32_t pcrValue=GPIO_DEFAULT_PCR) {
      // Enable clock to GPCLR & GPCHR
      bmeOr(SIM->FIXED_PORT_CLOCK_REG, Info::clockMask);

      // Include the if's as I expect one branch to be removed by optimisation unless the field spans the boundary
      if ((MASK&0xFFFFUL) != 0) {
         port->GPCLR = PORT_GPCLR_GPWE(MASK)|(pcrValue&~PORT_PCR_MUX_MASK)|PORT_PCR_MUX(FIXED_GPIO_FN);
      }
      if ((MASK&~0xFFFFUL) != 0) {
         port->GPCHR = PORT_GPCHR_GPWE(MASK>>16)|(pcrValue&~PORT_PCR_MUX_MASK)|PORT_PCR_MUX(FIXED_GPIO_FN);
      }
   }
public:
   /**
    * Set pin as digital output
    *
    * @param pcrValue PCR value to use in configuring port (excluding mux fn)
    */
   static void setOutput(uint32_t pcrValue=GPIO_DEFAULT_PCR) {
      setPCRs(pcrValue);
      bmeOr(gpio->PDDR, MASK);
   }
   /**
    * Set pin as digital input
    *
    * @param pcrValue PCR value to use in configuring port (excluding mux fn)
    */
   static void setInput(uint32_t pcrValue=GPIO_DEFAULT_PCR) {
      setPCRs(pcrValue);
      bmeAnd(gpio->PDDR, ~MASK);
   }
   /**
    * Set individual pin directions
    *
    * @param mask Mask for pin directions (1=>out, 0=>in)
    */
   static void setDirection(uint32_t mask) {
      bmeInsert(gpio->PDDR, right, left-right+1, mask);
   }
   /**
    * Set bits in field
    *
    * @param mask Mask to apply to the field (1 => set bit, 0 => unchanged)
    */
   static void bitSet(const uint32_t mask) {
      gpio->PSOR = (mask<<right)&MASK;
   }
   /**
    * Clear bits in field
    *
    * @param mask Mask to apply to the field (1 => clear bit, 0 => unchanged)
    */
   static void bitClear(const uint32_t mask) {
      gpio->PCOR = (mask<<right)&MASK;
   }
   /**
    * Toggle bits in field
    *
    * @param mask Mask to apply to the field (1 => toggle bit, 0 => unchanged)
    */
   static void bitToggle(const uint32_t mask) {
      gpio->PTOR = (mask<<right)&MASK;
   }
   /**
    * Read field
    *
    * @return value from field
    */
   static uint32_t read() {
      return bmeExtract(gpio->PDIR, right, left-right+1);
   }
   /**
    * Write field
    *
    * @param value to insert as field
    */
   static void write(uint32_t value) {
      bmeInsert(gpio->PDOR, right, left-right+1, value);
   }
};

#ifdef USBDM_GPIOA_IS_DEFINED
/**
 * @brief Convenience template for GpioA. See @ref Gpio_T
 *
 * <b>Usage</b>
 * @code
 * // Instantiate for bit 3 of GpioA
 * GpioA<3, ActiveHigh> GpioA3
 *
 * // Set as digital output
 * GpioA3.setOutput();
 *
 * // Set pin high
 * GpioA3.set();
 *
 * // Set pin low
 * GpioA3.clear();
 *
 * // Toggle pin
 * GpioA3.toggle();
 *
 * // Set pin to boolean value
 * GpioA3.write(true);
 *
 * // Set pin to boolean value
 * GpioA3.write(false);
 *
 * // Set as digital input
 * GpioA3.setInput();
 *
 * // Read pin as boolean value
 * bool x = GpioA3.read();
 * @endcode
 *
 * @tparam bitNum        Bit number in the port
 * @tparam polarity      Either USBDM::ActiveHigh or USBDM::ActiveLow
 */
template<uint8_t bitNum, Polarity polarity=ActiveHigh> class GpioA : public Gpio_T<GpioAInfo, bitNum, polarity> {};
using PortA = PcrBase_T<GpioAInfo::pcrAddress>;

/**
 * @brief Convenience template for GpioA fields. See @ref Field_T
 *
 * <b>Usage</b>
 * @code
 * // Instantiate for bit 6 down to 3 of GpioA
 * GpioAField<6,3> GpioA6_3
 *
 * // Set as digital output
 * GpioA6_3.setOutput();
 *
 * // Write value to field
 * GpioA6_3.write(0x53);
 *
 * // Clear all of field
 * GpioA6_3.bitClear();
 *
 * // Clear lower two bits of field
 * GpioA6_3.bitClear(0x3);
 *
 * // Set lower two bits of field
 * GpioA6_3.bitSet(0x3);
 *
 * // Set as digital input
 * GpioA6_3.setInput();
 *
 * // Read pin as int value
 * int x = GpioA6_3.read();
 * @endcode
 *
 * @tparam left          Bit number of leftmost bit in port (inclusive)
 * @tparam right         Bit number of rightmost bit in port (inclusive)
 */
template<int left, int right> class GpioAField : public Field_T<GpioAInfo, left, right> {};
#endif

#ifdef USBDM_GPIOB_IS_DEFINED
/**
 * @brief Convenience template for GpioB. See @ref Gpio_T
 *
 * <b>Usage</b>
 * @code
 * // Instantiate for bit 3 of GpioB
 * GpioB<3, ActiveHigh> GpioB3
 *
 * // Set as digital output
 * GpioB3.setOutput();
 *
 * // Set pin high
 * GpioB3.set();
 *
 * // Set pin low
 * GpioB3.clear();
 *
 * // Toggle pin
 * GpioB3.toggle();
 *
 * // Set pin to boolean value
 * GpioB3.write(true);
 *
 * // Set pin to boolean value
 * GpioB3.write(false);
 *
 * // Set as digital input
 * GpioB3.setInput();
 *
 * // Read pin as boolean value
 * bool x = GpioB3.read();
 * @endcode
 *
 * @tparam bitNum        Bit number in the port
 * @tparam polarity      Either USBDM::ActiveHigh or USBDM::ActiveLow
 */
template<uint8_t bitNum, Polarity polarity=ActiveHigh> class GpioB : public Gpio_T<GpioBInfo, bitNum, polarity> {};
using PortB = PcrBase_T<GpioBInfo::pcrAddress>;

/**
 * @brief Convenience template for GpioB fields. See @ref Field_T
 *
 * <b>Usage</b>
 * @code
 * // Instantiate for bit 6 down to 3 of GpioB
 * GpioBField<6,3> GpioB6_3
 *
 * // Set as digital output
 * GpioB6_3.setOutput();
 *
 * // Write value to field
 * GpioB6_3.write(0x53);
 *
 * // Clear all of field
 * GpioB6_3.bitClear();
 *
 * // Clear lower two bits of field
 * GpioB6_3.bitClear(0x3);
 *
 * // Set lower two bits of field
 * GpioB6_3.bitSet(0x3);
 *
 * // Set as digital input
 * GpioB6_3.setInput();
 *
 * // Read pin as int value
 * int x = GpioB6_3.read();
 * @endcode
 *
 * @tparam left          Bit number of leftmost bit in port (inclusive)
 * @tparam right         Bit number of rightmost bit in port (inclusive)
 */
template<int left, int right> class GpioBField : public Field_T<GpioBInfo, left, right> {};
#endif

#ifdef USBDM_GPIOC_IS_DEFINED
/**
 * @brief Convenience template for GpioC. See @ref Gpio_T
 *
 * <b>Usage</b>
 * @code
 * // Instantiate for bit 3 of GpioC
 * GpioC<3, ActiveHigh> GpioC3
 *
 * // Set as digital output
 * GpioC3.setOutput();
 *
 * // Set pin high
 * GpioC3.set();
 *
 * // Set pin low
 * GpioC3.clear();
 *
 * // Toggle pin
 * GpioC3.toggle();
 *
 * // Set pin to boolean value
 * GpioC3.write(true);
 *
 * // Set pin to boolean value
 * GpioC3.write(false);
 *
 * // Set as digital input
 * GpioC3.setInput();
 *
 * // Read pin as boolean value
 * bool x = GpioC3.read();
 * @endcode
 *
 * @tparam bitNum        Bit number in the port
 * @tparam polarity      Either USBDM::ActiveHigh or USBDM::ActiveLow
 */
template<uint8_t bitNum, Polarity polarity=ActiveHigh> class GpioC : public Gpio_T<GpioCInfo, bitNum, polarity> {};
using PortC = PcrBase_T<GpioCInfo::pcrAddress>;

/**
 * @brief Convenience template for GpioC fields. See @ref Field_T
 *
 * <b>Usage</b>
 * @code
 * // Instantiate for bit 6 down to 3 of GpioC
 * GpioCField<6,3> GpioC6_3
 *
 * // Set as digital output
 * GpioC6_3.setOutput();
 *
 * // Write value to field
 * GpioC6_3.write(0x53);
 *
 * // Clear all of field
 * GpioC6_3.bitClear();
 *
 * // Clear lower two bits of field
 * GpioC6_3.bitClear(0x3);
 *
 * // Set lower two bits of field
 * GpioC6_3.bitSet(0x3);
 *
 * // Set as digital input
 * GpioC6_3.setInput();
 *
 * // Read pin as int value
 * int x = GpioC6_3.read();
 * @endcode
 *
 * @tparam left          Bit number of leftmost bit in port (inclusive)
 * @tparam right         Bit number of rightmost bit in port (inclusive)
 */
template<int left, int right> class GpioCField : public Field_T<GpioCInfo, left, right> {};
#endif

#ifdef USBDM_GPIOD_IS_DEFINED
/**
 * @brief Convenience template for GpioD. See @ref Gpio_T
 *
 * <b>Usage</b>
 * @code
 * // Instantiate for bit 3 of GpioD
 * GpioD<3, ActiveHigh> GpioD3
 *
 * // Set as digital output
 * GpioD3.setOutput();
 *
 * // Set pin high
 * GpioD3.set();
 *
 * // Set pin low
 * GpioD3.clear();
 *
 * // Toggle pin
 * GpioD3.toggle();
 *
 * // Set pin to boolean value
 * GpioD3.write(true);
 *
 * // Set pin to boolean value
 * GpioD3.write(false);
 *
 * // Set as digital input
 * GpioD3.setInput();
 *
 * // Read pin as boolean value
 * bool x = GpioD3.read();
 * @endcode
 *
 * @tparam bitNum        Bit number in the port
 * @tparam polarity      Either USBDM::ActiveHigh or USBDM::ActiveLow
 */
template<uint8_t bitNum, Polarity polarity=ActiveHigh> class GpioD : public Gpio_T<GpioDInfo, bitNum, polarity> {};
using PortD = PcrBase_T<GpioDInfo::pcrAddress>;

/**
 * @brief Convenience template for GpioD fields. See @ref Field_T
 *
 * <b>Usage</b>
 * @code
 * // Instantiate for bit 6 down to 3 of GpioD
 * GpioDField<6,3> GpioD6_3
 *
 * // Set as digital output
 * GpioD6_3.setOutput();
 *
 * // Write value to field
 * GpioD6_3.write(0x53);
 *
 * // Clear all of field
 * GpioD6_3.bitClear();
 *
 * // Clear lower two bits of field
 * GpioD6_3.bitClear(0x3);
 *
 * // Set lower two bits of field
 * GpioD6_3.bitSet(0x3);
 *
 * // Set as digital input
 * GpioD6_3.setInput();
 *
 * // Read pin as int value
 * int x = GpioD6_3.read();
 * @endcode
 *
 * @tparam left          Bit number of leftmost bit in port (inclusive)
 * @tparam right         Bit number of rightmost bit in port (inclusive)
 */
template<int left, int right> class GpioDField : public Field_T<GpioDInfo, left, right> {};
#endif

#ifdef USBDM_GPIOE_IS_DEFINED
/**
 * @brief Convenience template for GpioE. See @ref Gpio_T
 *
 * <b>Usage</b>
 * @code
 * // Instantiate for bit 3 of GpioE
 * GpioE<3, ActiveHigh> GpioE3
 *
 * // Set as digital output
 * GpioE3.setOutput();
 *
 * // Set pin high
 * GpioE3.set();
 *
 * // Set pin low
 * GpioE3.clear();
 *
 * // Toggle pin
 * GpioE3.toggle();
 *
 * // Set pin to boolean value
 * GpioE3.write(true);
 *
 * // Set pin to boolean value
 * GpioE3.write(false);
 *
 * // Set as digital input
 * GpioE3.setInput();
 *
 * // Read pin as boolean value
 * bool x = GpioE3.read();
 * @endcode
 *
 * @tparam bitNum        Bit number in the port
 * @tparam polarity      Either USBDM::ActiveHigh or USBDM::ActiveLow
 */
template<uint8_t bitNum, Polarity polarity=ActiveHigh> class GpioE : public Gpio_T<GpioEInfo, bitNum, polarity> {};
using PortE = PcrBase_T<GpioEInfo::pcrAddress>;

/**
 * @brief Convenience template for GpioE fields. See @ref Field_T
 *
 * <b>Usage</b>
 * @code
 * // Instantiate for bit 6 down to 3 of GpioE
 * GpioEField<6,3> GpioE6_3
 *
 * // Set as digital output
 * GpioE6_3.setOutput();
 *
 * // Write value to field
 * GpioE6_3.write(0x53);
 *
 * // Clear all of field
 * GpioE6_3.bitClear();
 *
 * // Clear lower two bits of field
 * GpioE6_3.bitClear(0x3);
 *
 * // Set lower two bits of field
 * GpioE6_3.bitSet(0x3);
 *
 * // Set as digital input
 * GpioE6_3.setInput();
 *
 * // Read pin as int value
 * int x = GpioE6_3.read();
 * @endcode
 *
 * @tparam left          Bit number of leftmost bit in port (inclusive)
 * @tparam right         Bit number of rightmost bit in port (inclusive)
 */
template<int left, int right> class GpioEField : public Field_T<GpioEInfo, left, right> {};
#endif

/**
 * End GPIO_Group
 * @}
 */
} // End namespace USBDM

#endif /* HEADER_GPIO_H */

