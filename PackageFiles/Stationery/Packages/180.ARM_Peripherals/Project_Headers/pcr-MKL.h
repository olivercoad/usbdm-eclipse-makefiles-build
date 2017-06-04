/**
 * @file     pcr.h
 * @brief    Port Control Register interface (generated from pcr-MKL.h)
 *
 * @version  V4.12.1.80
 * @date     13 April 2016
 */
#ifndef HEADER_PCR_H
#define HEADER_PCR_H
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
namespace USBDM {

/*
 * PORT clock masks
 */
#ifdef SIM_SCGC5_PORTA_MASK
constexpr   uint32_t PORTA_CLOCK_MASK         = SIM_SCGC5_PORTA_MASK;
#endif

#ifdef SIM_SCGC5_PORTB_MASK
constexpr   uint32_t PORTB_CLOCK_MASK         = SIM_SCGC5_PORTB_MASK;
#endif

#ifdef SIM_SCGC5_PORTC_MASK
constexpr   uint32_t PORTC_CLOCK_MASK         = SIM_SCGC5_PORTC_MASK;
#endif

#ifdef SIM_SCGC5_PORTD_MASK
constexpr   uint32_t PORTD_CLOCK_MASK         = SIM_SCGC5_PORTD_MASK;
#endif

#ifdef SIM_SCGC5_PORTE_MASK
constexpr   uint32_t PORTE_CLOCK_MASK         = SIM_SCGC5_PORTE_MASK;
#endif

#ifdef SIM_SCGC5_PORTF_MASK
constexpr   uint32_t PORTF_CLOCK_MASK         = SIM_SCGC5_PORTF_MASK;
#endif

extern volatile uint32_t SystemMcgffClock;
extern volatile uint32_t SystemMcgOutClock;
extern volatile uint32_t SystemMcgFllClock;
extern volatile uint32_t SystemMcgPllClock;
extern volatile uint32_t SystemCoreClock;
extern volatile uint32_t SystemBusClock;
extern volatile uint32_t SystemLpoClock;

/*
 * Enable clock to ports
 *
 * @param mask Mask for PORTs to enable
 */
static inline void enablePortClocks(uint32_t clockMask) {
   bmeOr(SIM->SCGC5, clockMask);
   __DMB();
};

/*
 * Disable clock to ports
 *
 * @param mask Mask for PORTs to disable
 */
static inline void disablePortClocks(uint32_t clockMask) {
   bmeAnd(SIM->SCGC5, ~clockMask);
   __DMB();
};

/**
 * @addtogroup PeripheralPinTables Peripheral Information Classes
 * @brief Provides information about pins used by a peripheral
 * @{
 */

/** Indicates the function has a fixed mapping to a pin */
constexpr   int8_t FIXED_NO_PCR         = 0x00;

/** Indicates the function doesn't exist */
constexpr   int8_t INVALID_PCR          = 0xA5;

/** Indicates the function is not currently mapped to a pin */
constexpr   int8_t UNMAPPED_PCR         = 0xA4;

/**
 * Struct for Pin Control Register information\n
 * Information required to configure the PCR for a particular function
 */
struct PcrInfo {
   uint32_t clockMask;   //!< Clock mask for PORT
   uint32_t pcrAddress;  //!< PCR register array address
   uint32_t gpioAddress; //!< Address of GPIO hardware associated with pin
   int8_t   gpioBit;     //!< Bit number of pin in GPIO
   uint32_t pcrValue;    //!< PCR value including MUX value to select this function
};

#ifndef PORT_PCR_DSE
// Some device don't have DSE
#define PORT_PCR_DSE(x) (0)
#endif

#ifndef PORT_PCR_ODE
/**
 * Some devices don't have ODE function on pin
 * The open-drain mode is automatically selected when I2C function is selected for the pin
 */
#define PORT_PCR_ODE(x) 0
#endif

/**
 * Pull device modes
 */
enum PullMode {
   PullNone = PORT_PCR_PE(0),                //!< No pull device
   PullUp   = PORT_PCR_PE(1)|PORT_PCR_PS(1), //!< Weak pull-up
   PullDown = PORT_PCR_PE(1)|PORT_PCR_PS(0), //!< Weak pull-down
};

/**
 * Pin drive strengths
 */
enum DriveStrength {
   DriveLow  = PORT_PCR_DSE(0), //!< Low drive strength
   DriveHigh = PORT_PCR_DSE(1), //!< High drive strength
};

/**
 * Pin drive mode
 */
enum DriveMode {
   PushPull      = PORT_PCR_ODE(0), //!< Push-pull output
   OpenDrain     = PORT_PCR_ODE(1), //!< Open-drain output
   OpenCollector = OpenDrain,       //!< For oldies like me
};

/**
 * Pin interrupt/DMA modes
 */
enum InterruptMode {
   PinIrqNone     = PORT_PCR_IRQC(0),   //!< No interrupt or DMA function

   PinDmaRising   = PORT_PCR_IRQC(1),   //!< Generate DMA request on rising edge
   PinDmaFalling  = PORT_PCR_IRQC(2),   //!< Generate DMA request on falling edge
   PinDmaEither   = PORT_PCR_IRQC(3),   //!< Generate DMA request on either edge

   PinIrqLow      = PORT_PCR_IRQC(8),   //!< Generate IRQ request when low
   PinIrqRising   = PORT_PCR_IRQC(9),   //!< Generate IRQ request on rising edge
   PinIrqFalling  = PORT_PCR_IRQC(10),  //!< Generate IRQ request on falling edge
   PinIrqEither   = PORT_PCR_IRQC(11),  //!< Generate IRQ request on either edge
   PinIrqHigh     = PORT_PCR_IRQC(12),  //!< Generate IRQ request when high
};

/**
 * Pin Multiplexor setting
 */
enum PinMux {
   PinMuxNone      = (0),   //!< Used for default/no mapping
   PinMuxAnalogue  = (0),   //!< Analogue function
   PinMuxAnalog    = PinMuxAnalogue,
   PinMuxTsi       = PinMuxAnalogue,    //!< Touch Sense function is analogue
   PinMuxGpio      = (1),   //!< Gpio function
   PinMux2         = (2),   //!< Mux 2
   PinMux3         = (3),   //!< Mux 3
   PinMux4         = (4),   //!< Mux 4
   PinMux5         = (5),   //!< Mux 5
   PinMux6         = (6),   //!< Mux 6
   PinMux7         = (7),   //!< Mux 7
};

using PcrValue = uint32_t;

/**
 * Construct PCR value from individual bit masks
 *
 * @param pullMode      One of PullNone, PullUp, PullDown, (defaults to PullNone)
 * @param driveStrength One of DriveLow, DriveHigh, (defaults to DriveLow)
 * @param driveMode     One of PushPull, OpenDrain, OpenCollector, (defaults to PushPull)
 * @param interruptMode One of PinIrqNone, etc (defaults to PinIrqNone)
 * @param muxValue      Multiplexor setting (defaults to 0)
 */
constexpr PcrValue pcrValue(
      PullMode       pullMode       = PullNone,
      DriveStrength  driveStrength  = DriveLow,
      DriveMode      driveMode      = PushPull,
      InterruptMode  interruptMode  = PinIrqNone,
      PinMux         muxValue       = PinMuxNone) {
   return pullMode|driveStrength|driveMode|interruptMode|((muxValue<<8)&0x700);
}

/**
 * Construct PCR value from existing PcrValue and extra flags
 *
 * @param original      Original value
 * @param extraFlags    Extra flags
 */
constexpr PcrValue pcrValue(PcrValue original, uint32_t extraFlags) {
   return original|extraFlags;
}

/**
 * Construct PCR value from flags
 *
 * @param flags Extra flags
 */
constexpr PcrValue pcrValue(uint32_t flags) {
   return flags;
}

/**
 * Default PCR setting for pins (excluding multiplexor value)
 * High drive strength + Pull-up
 */
static constexpr PcrValue DEFAULT_PCR = pcrValue(PullUp, DriveHigh);

/**
 * Default PCR value for pins used as GPIO (including multiplexor value)
 * High drive strength + Pull-up + GPIO_MUX value
 */
static constexpr PcrValue GPIO_DEFAULT_PCR = pcrValue(PullUp, DriveHigh, PushPull, PinIrqNone, PinMuxGpio);

/**
 * Default PCR setting for I2C pins (excluding multiplexor value)
 * High drive strength + Pull-up + Open-drain (if available)
 */
static constexpr PcrValue I2C_DEFAULT_PCR =  pcrValue(PullUp, DriveHigh, OpenDrain, PinIrqNone);

/**
 * Default PCR setting for (E)XTAL pins (excluding multiplexor value)
 */
static constexpr PcrValue XTAL_DEFAULT_PCR = pcrValue(PullNone, DriveLow, PushPull, PinIrqNone);

/**
 * Type definition for PIT interrupt call back
 *
 * @param status 32-bit value from ISFR (each bit indicates an interrupt source)
 */
typedef void (*PinCallbackFunction)(uint32_t status);

template<uint32_t pcrAddress>
class PcrBase_T {

private:
   static constexpr volatile PORT_Type *port = reinterpret_cast<volatile PORT_Type *>(pcrAddress);

   /** Callback functions for ISRs */
   static PinCallbackFunction fCallback;

public:
   /**
    * Interrupt handler -  Calls callback
    */
   static void irqHandler() {
      // Capture interrupt flags
      uint32_t status = port->ISFR;

      // Clear flags
      port->ISFR = status;

      if (fCallback != 0) {
         fCallback(status);
      }
      else {
         setAndCheckErrorCode(E_NO_HANDLER);
      }
   }
   /**
    * Set callback for ISR
    *
    * @param callback The function to call from stub ISR
    */
   static void setCallback(PinCallbackFunction callback) {
      fCallback = callback;
   }
};

template<uint32_t pcrAddress>
PinCallbackFunction USBDM::PcrBase_T<pcrAddress>::fCallback = nullptr;

/**
 * @brief Template representing a Pin Control Register (PCR)
 *
 * Code examples:
 * @code
 * // Create PCR type
 * using PortC_3 = USBDM::Pcr_T<SIM_SCGC5_PORTC_MASK, PORTC_BasePtr, 3, USBDM::DEFAULT_PCR>;
 *
 * // Configure PCR
 * PortC_3::setPCR(PORT_PCR_DSE_MASK|PORT_PCR_PE_MASK|PORT_PCR_PS_MASK|PORT_PCR_MUX(3));
 *
 * // Disable Port clock
 * PortC_3::disableClock();
 * @endcode
 *
 * @tparam clockMask       Mask for SIM clock register associated with this PCR
 * @tparam pcrAddress      PORT to be manipulated e.g. PORTA (PCR array)
 * @tparam bitNum          Bit number e.g. 3
 * @tparam defPcrValue     Default value for PCR (including MUX value)
 */
template<uint32_t clockMask, uint32_t pcrAddress, int32_t bitNum, PcrValue defPcrValue>
class Pcr_T : public PcrBase_T<pcrAddress> {

private:

#ifdef DEBUG_BUILD
   static_assert((bitNum != UNMAPPED_PCR), "Pcr_T: Signal is not mapped to a pin - Modify Configure.usbdm");
   static_assert((bitNum != INVALID_PCR),  "Pcr_T: Non-existent signal");
   static_assert((bitNum == UNMAPPED_PCR)||(bitNum == INVALID_PCR)||(bitNum >= 0), "Pcr_T: Illegal bit number");
#endif

   static constexpr volatile uint32_t *pcrReg = reinterpret_cast<volatile uint32_t *>(pcrAddress+offsetof(PORT_Type,PCR[bitNum]));

public:
   using PcrBase = PcrBase_T<pcrAddress>;

   /**
    * Enable/disable clock associated with PORT
    *
    * @param enable true => enable, false => disable
    */
   static void enableClock(bool enable=true) {
      if (enable) {
         enablePortClocks(clockMask);
      }
      else {
         disablePortClocks(clockMask);
      }
   }

   /**
    * Set pin PCR value\n
    * The clock to the port will be enabled before changing the PCR
    *
    * @param pcrValue PCR value constructed using pcrValue() including MUX value. See See \ref pcrValue()
    */
   static void setPCR(PcrValue pcrValue=defPcrValue) {
      if ((pcrAddress != 0) && (bitNum >= 0)) {
         enablePortClocks(clockMask);

         // Pointer to PCR register for pin
         *pcrReg = pcrValue;
      }
   }
   /**
    * Set pin PCR.MUX value\n
    * Assumes clock to the port has already been enabled\n
    *
    * @param muxValue PCR MUX value [0..7]
    */
   static void setMux(uint32_t muxValue) {
      *pcrReg = (*pcrReg&~PORT_PCR_MUX_MASK)|PORT_PCR_MUX(muxValue);
   }
   /**
    * Sets pin interrupt/DMA mode\n
    * Assumes clock to the port has already been enabled\n
    *
    * @param mode Interrupt/DMA mode
    */
   static void setIrq(InterruptMode mode) {
      *pcrReg = (*pcrReg&~PORT_PCR_IRQC_MASK) | mode;
   }

   /**
    * Clear interrupt flag\n
    * Assumes clock to the port has already been enabled\n
    */
   static void clearIrqFlag() {
      *pcrReg |= PORT_PCR_ISF_MASK;
   }

#ifdef PORT_PCR_ODE_MASK
   /**
    * Set pull device on pin\n
    * Assumes clock to the port has already been enabled\n
    *
    *  @param mode Pull selection mode
    */
   static void setPullDevice(PullMode mode) {
      *pcrReg = (*pcrReg&~PORT_PCR_PS_MASK) | mode;
   }

   /**
    * Set drive mode on pin\n
    * Assumes clock to the port has already been enabled\n
    *
    *  @param mode Drive mode
    */
   static void setDriveMode(DriveMode mode) {
      *pcrReg = (*pcrReg&~PORT_PCR_ODE_MASK) | mode;
   }
#else
   /**
    * Not supported
    */
   static void setPullDevice(PullMode) {
   }

   /**
    * Not supported
    */
   static void setDriveMode(DriveMode) {
   }
#endif

   /**
    * Set drive strength on pin\n
    * Assumes clock to the port has already been enabled\n
    *
    *  @param strength Drive strength to set
    */
   static void setDriveStrength(DriveStrength strength) {
      *pcrReg = (*pcrReg&~PORT_PCR_DSE_MASK) | strength;
   }

#if defined(PORT_PCR_LK_MASK)
   /**
    * Locks most of the PCR properties e.g. drive strength, pull-device etc.\n
    * Assumes clock to the port has already been enabled\n
    * The pin properties remains locked until the next reset\n
    * Not supported on all devices
    */
   static void lock() {
      *pcrReg |= PORT_PCR_LK_MASK;
   }
#else
   static void lock() {
   }
#endif

   /**
    * Enable/disable interrupts in NVIC
    *
    * @param enable true => enable, false => disable
    */
   static void enableNvicInterrupts(bool enable=true) {

      constexpr IRQn_Type irqNum = (IRQn_Type)(PORTA_IRQn+((pcrAddress-PORTA_BasePtr)/(PORTB_BasePtr-PORTA_BasePtr)));

      if (enable) {
         // Enable interrupts
         NVIC_EnableIRQ(irqNum);

         // Set priority level
         NVIC_SetPriority(irqNum, 3);
      }
      else {
         // Disable interrupts
         NVIC_DisableIRQ(irqNum);
      }
   }
};

/**
 * @brief Template function to set a PCR to the default value
 *
 * @tparam  Last PCR to modify
 */
template<typename Last>
void processPcrs() {
   Last::setPCR();
}
/**
 * @brief Template function to set a collection of PCRs to the default value
 *
 * @tparam  Pcr1 PCR to modify
 * @tparam  Pcr2 PCR to modify
 * @tparam  Rest Remaining PCRs to modify
 */
template<typename Pcr1, typename  Pcr2, typename  ... Rest>
void processPcrs() {
   processPcrs<Pcr1>();
   processPcrs<Pcr2, Rest...>();
}
/**
 * @brief Template function to set a PCR to a given value
 *
 * @param   pcrValue PCR value to set
 *
 * @tparam  Last PCR to modify
 */
template<typename Last>
void processPcrs(uint32_t pcrValue) {
   Last::setPCR(pcrValue);
}

/**
 * @brief Template function to set a collection of PCRs to a given value
 *
 * @param pcrValue PCR value to set
 *
 * @tparam  Pcr1 PCR to modify
 * @tparam  Pcr2 PCR to modify
 * @tparam  Rest Remaining PCRs to modify
 */
template<typename Pcr1, typename  Pcr2, typename  ... Rest>
void processPcrs(uint32_t pcrValue) {
   processPcrs<Pcr1>(pcrValue);
   processPcrs<Pcr2, Rest...>(pcrValue);
}

/**
 * @brief Template representing a Pin Control Register (PCR)\n
 * Makes use of a configuration class
 *
 * Code examples:
 * @code
 * // Create PCR type
 * Pcr_T<spiInfo, 3> SpiMOSI;
 *
 * // Configure PCR
 * SpiMOSI.setPCR(PORT_PCR_DSE_MASK|PORT_PCR_PE_MASK|PORT_PCR_PS_MASK|PORT_PCR_MUX(3));
 *
 * // Disable clock to associated PORT
 * SpiMOSI.disableClock();
 *
 * // Alternatively the PCR may be manipulated directly
 * Pcr_T<spiInfo, 3>::setPCR(PORT_PCR_DSE_MASK|PORT_PCR_PE_MASK|PORT_PCR_PS_MASK);
 * @endcode
 *
 * @tparam info          Configuration class
 * @tparam index         Index of pin in configuration table
 */
template<class Info, uint8_t index> using PcrTable_T =
      Pcr_T<Info::info[index].clockMask, Info::info[index].pcrAddress, Info::info[index].gpioBit, Info::info[index].pcrValue>;

/**
 * @}
 ** PeripheralPinTables
 */
} // End namespace USBDM

#endif /* HEADER_PCR_H */

