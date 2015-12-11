/**
 * @file     mag3310.h
 * @brief    Interface for MAG3310 3-axis magnetometer
 *
 * @version  V4.11.1.70
 * @date     18 June 2015
 */

#ifndef INCLUDE_USBDM_MAG3310_H_
#define INCLUDE_USBDM_MAG3310_H_

#include <stdint.h>
#include "i2c.h"

namespace USBDM {

/**
 * @addtogroup MAG3310_Group MAG3310 3-axis magnetometer
 * @brief C++ Class allowing interface to MAG3310
 * @{
 */

#define MAG3310_CTRL_REG1_AC_MASK             (1<<0) // Operating mode 0=>STANDBY mode, 1=>ACTIVE mode.
#define MAG3310_CTRL_REG1_TM_MASK             (1<<1) // Trigger immediate measurement
#define MAG3310_CTRL_REG1_FR_MASK             (1<<2) // Fast Read selection 0=> 16-bit values, 1=>Only MSB are read
#define MAG3310_CTRL_REG1_OS_OFF              (3)    // This register configures the over sampling ratio for the measurement
#define MAG3310_CTRL_REG1_OS_MASK             (0x3<<MAG3310_CTRL_REG1_OS_OFF)
#define MAG3310_CTRL_REG1_OS(x)               (((x)<<MAG3310_CTRL_REG1_OS_OFF)&MAG3310_CTRL_REG1_OS_MASK)
#define MAG3310_CTRL_REG1_OS_16               (MAG3310_CTRL_REG1_OS(0))
#define MAG3310_CTRL_REG1_OS_32               (MAG3310_CTRL_REG1_OS(1))
#define MAG3310_CTRL_REG1_OS_64               (MAG3310_CTRL_REG1_OS(2))
#define MAG3310_CTRL_REG1_OS_128              (MAG3310_CTRL_REG1_OS(3))
#define MAG3310_CTRL_REG1_OS(x)               (((x)<<MAG3310_CTRL_REG1_OS_OFF)&MAG3310_CTRL_REG1_OS_MASK)
#define MAG3310_CTRL_REG1_OS(x)               (((x)<<MAG3310_CTRL_REG1_OS_OFF)&MAG3310_CTRL_REG1_OS_MASK)
#define MAG3310_CTRL_REG1_OS(x)               (((x)<<MAG3310_CTRL_REG1_OS_OFF)&MAG3310_CTRL_REG1_OS_MASK)

#define MAG3310_CTRL_REG1_DR_OFF              (5)    // Output data rate selection
#define MAG3310_CTRL_REG1_DR_MASK             (0x7<<MAG3310_CTRL_REG1_DR_OFF)
#define MAG3310_CTRL_REG1_DR(x)               (((x)<<MAG3310_CTRL_REG1_DR_OFF)&MAG3310_CTRL_REG1_DR_MASK)

#define MAG3310_CTRL_REG2_MAG_RST_MASK        (1<<4)
#define MAG3310_CTRL_REG2_RAW_MASK            (1<<5)
#define MAG3310_CTRL_REG2_AUTO_MRST_EN_MASK   (1<<7)

#define MAG3310_DR_STATUS_XDR_MASK            (1<<0) // X-axis new Data Available
#define MAG3310_DR_STATUS_YDR_MASK            (1<<1) // Y-axis new Data Available
#define MAG3310_DR_STATUS_ZDR_MASK            (1<<2) // Z-axis new Data Available
#define MAG3310_DR_STATUS_XYZDR_MASK          (1<<3) // X or Y or Z-axis new Data Available
#define MAG3310_DR_STATUS_XOW_MASK            (1<<4) // X-axis Data Overwrite
#define MAG3310_DR_STATUS_YOW_MASK            (1<<5) // Y-axis Data Overwrite
#define MAG3310_DR_STATUS_ZOW_MASK            (1<<6) // Z-axis Data Overwrite
#define MAG3310_DR_STATUS_ZYXOW_MASK          (1<<7) // ZYX-axis Data Overwrite

#define MAG3310_SYSMOD_SYSMOD_OFF              (5)
#define MAG3310_SYSMOD_SYSMOD_MASK             (0x7<<MAG3310_SYSMOD_SYSMOD_OFF)
#define MAG3310_SYSMOD_SYSMOD(x)               (((x)<<MAG3310_SYSMOD_SYSMOD_OFF)&MAG3310_SYSMOD_SYSMOD_MASK)

#define MAG3310_XYZ_DATA_CFG_FS(x)          (((x)<<0)&0x03)
#define MAG3310_XYZ_DATA_CFG_HPF_OUT_MASK   (1<<4)

/**
 * @brief Class representing an interface for MAG3310 3-axis magnetometer over I2C
 *
 * <b>Example</b>
 * @code
 *  // Instantiate interface
 *  I2c     *i2c   = new I2C_0();
 *  MAG3310 *magnetometer = new MAG3310(i2c);
 *
 *  int      status;
 *  int16_t  x, y, z;
 *
 *  magnetometer->readMagnetometerXYZ(&status, &x, &y, &z);
 *
 * @endcode
 */
class MAG3310 {

private:
   USBDM::I2c *i2c;
   static const uint8_t  DEVICE_ADDRESS = 0x0E<<1;
   static const uint8_t  WHO_AM_I_VALUE = 0xC4;

   /**
    * Read Accelerometer register
    *
    * @param regNum  - Register number
    */
   uint8_t readReg(uint8_t regNum);
   /**
    * Write Accelerometer register
    *
    * @param regNum  - Register number
    * @param value   - Value to write
    */
   void    writeReg(uint8_t regNum, uint8_t value);
   /**
    * Reset Accelerometer
    */
   void    reset(void);
   bool    failedInit;

public:

   struct Data {
      uint8_t magnetometerStatus;
      uint8_t magnetometer_X;
      uint8_t magnetometer_Y;
      uint8_t magnetometer_Z;
   };

   /**
    * Constructor
    *
    * @param i2c  - The I2C interface to use
    */
   MAG3310(USBDM::I2c *i2c);
   /**
    * Put accelerometer into Standby mode
    */
   void standby();
   /**
    * Put accelerometer into Active mode
    */
   void active();
   /*
    * Obtains measurements from the Magnetometer
    *
    * @param status  - Indicates status of x, y & z measurements
    * @param x       - X axis value
    * @param y       - Y axis value
    * @param z       - Z axis value
    */
   void readMagnetometerXYZ(int *status, int16_t *x, int16_t *y, int16_t *z);

   /*!
    * Read ID from accelerometer
    *
    * @return ID value as 8-bit number (0x1A for MMA8451Q)
    */
   uint32_t readID();
   /**
    * Simple calibration of magnetometer
    * Requires user to rotate the board in all dimensions
    */
   void calibrateMagnetometer();

};

/**
 * @}
 */

} // End namespace USBDM

#endif /* INCLUDE_USBDM_MAG3310_H_ */
