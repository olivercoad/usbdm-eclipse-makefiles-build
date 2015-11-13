/**
 * @file      gpio.h (derived from gpio-MK64F12.h)
 * @version   1.0.0
 * @brief     Pin declarations for MK64F12
 */

#ifndef GPIO_H_
#define GPIO_H_

#include "derivative.h"
#include "pin_mapping.h"
#include "gpio_defs.h"

/**
* @addtogroup DigitalIO_Group Digital Input/Output
* @brief Allows use of port pins as simple digital inputs or outputs
* @{
*/
extern const DigitalIO digitalIO_PTA0;          //!< DigitalIO on pin PTA0
#define digitalIO_D8         digitalIO_PTA0
extern const DigitalIO digitalIO_PTA1;          //!< DigitalIO on pin PTA1
#define digitalIO_D3         digitalIO_PTA1
extern const DigitalIO digitalIO_PTA2;          //!< DigitalIO on pin PTA2
#define digitalIO_D5         digitalIO_PTA2
extern const DigitalIO digitalIO_PTA3;          //!< DigitalIO on pin PTA3
extern const DigitalIO digitalIO_PTA4;          //!< DigitalIO on pin PTA4
extern const DigitalIO digitalIO_PTA5;          //!< DigitalIO on pin PTA5
extern const DigitalIO digitalIO_PTA6;          //!< DigitalIO on pin PTA6
extern const DigitalIO digitalIO_PTA7;          //!< DigitalIO on pin PTA7
extern const DigitalIO digitalIO_PTA8;          //!< DigitalIO on pin PTA8
extern const DigitalIO digitalIO_PTA9;          //!< DigitalIO on pin PTA9
extern const DigitalIO digitalIO_PTA10;         //!< DigitalIO on pin PTA10
extern const DigitalIO digitalIO_PTA11;         //!< DigitalIO on pin PTA11
extern const DigitalIO digitalIO_PTA12;         //!< DigitalIO on pin PTA12
extern const DigitalIO digitalIO_PTA13;         //!< DigitalIO on pin PTA13
extern const DigitalIO digitalIO_PTA14;         //!< DigitalIO on pin PTA14
extern const DigitalIO digitalIO_PTA15;         //!< DigitalIO on pin PTA15
extern const DigitalIO digitalIO_PTA16;         //!< DigitalIO on pin PTA16
extern const DigitalIO digitalIO_PTA17;         //!< DigitalIO on pin PTA17
extern const DigitalIO digitalIO_PTA18;         //!< DigitalIO on pin PTA18
extern const DigitalIO digitalIO_PTA19;         //!< DigitalIO on pin PTA19
extern const DigitalIO digitalIO_PTA24;         //!< DigitalIO on pin PTA24
extern const DigitalIO digitalIO_PTA25;         //!< DigitalIO on pin PTA25
extern const DigitalIO digitalIO_PTA26;         //!< DigitalIO on pin PTA26
extern const DigitalIO digitalIO_PTA27;         //!< DigitalIO on pin PTA27
extern const DigitalIO digitalIO_PTA28;         //!< DigitalIO on pin PTA28
extern const DigitalIO digitalIO_PTA29;         //!< DigitalIO on pin PTA29
extern const DigitalIO digitalIO_PTB0;          //!< DigitalIO on pin PTB0
extern const DigitalIO digitalIO_PTB1;          //!< DigitalIO on pin PTB1
extern const DigitalIO digitalIO_PTB2;          //!< DigitalIO on pin PTB2
#define digitalIO_A0         digitalIO_PTB2
extern const DigitalIO digitalIO_PTB3;          //!< DigitalIO on pin PTB3
#define digitalIO_A1         digitalIO_PTB3
extern const DigitalIO digitalIO_PTB4;          //!< DigitalIO on pin PTB4
extern const DigitalIO digitalIO_PTB5;          //!< DigitalIO on pin PTB5
extern const DigitalIO digitalIO_PTB6;          //!< DigitalIO on pin PTB6
extern const DigitalIO digitalIO_PTB7;          //!< DigitalIO on pin PTB7
extern const DigitalIO digitalIO_PTB8;          //!< DigitalIO on pin PTB8
extern const DigitalIO digitalIO_PTB9;          //!< DigitalIO on pin PTB9
#define digitalIO_D2         digitalIO_PTB9
extern const DigitalIO digitalIO_PTB10;         //!< DigitalIO on pin PTB10
#define digitalIO_A2         digitalIO_PTB10
extern const DigitalIO digitalIO_PTB11;         //!< DigitalIO on pin PTB11
#define digitalIO_A3         digitalIO_PTB11
extern const DigitalIO digitalIO_PTB12;         //!< DigitalIO on pin PTB12
extern const DigitalIO digitalIO_PTB13;         //!< DigitalIO on pin PTB13
extern const DigitalIO digitalIO_PTB16;         //!< DigitalIO on pin PTB16
extern const DigitalIO digitalIO_PTB17;         //!< DigitalIO on pin PTB17
extern const DigitalIO digitalIO_PTB18;         //!< DigitalIO on pin PTB18
extern const DigitalIO digitalIO_PTB19;         //!< DigitalIO on pin PTB19
extern const DigitalIO digitalIO_PTB20;         //!< DigitalIO on pin PTB20
extern const DigitalIO digitalIO_PTB21;         //!< DigitalIO on pin PTB21
#define digitalIO_LED_BLUE   digitalIO_PTB21
extern const DigitalIO digitalIO_PTB22;         //!< DigitalIO on pin PTB22
#define digitalIO_LED_RED    digitalIO_PTB22
extern const DigitalIO digitalIO_PTB23;         //!< DigitalIO on pin PTB23
#define digitalIO_D4         digitalIO_PTB23
extern const DigitalIO digitalIO_PTC0;          //!< DigitalIO on pin PTC0
extern const DigitalIO digitalIO_PTC1;          //!< DigitalIO on pin PTC1
extern const DigitalIO digitalIO_PTC2;          //!< DigitalIO on pin PTC2
#define digitalIO_D6         digitalIO_PTC2
extern const DigitalIO digitalIO_PTC3;          //!< DigitalIO on pin PTC3
#define digitalIO_D7         digitalIO_PTC3
extern const DigitalIO digitalIO_PTC4;          //!< DigitalIO on pin PTC4
#define digitalIO_D9         digitalIO_PTC4
extern const DigitalIO digitalIO_PTC5;          //!< DigitalIO on pin PTC5
extern const DigitalIO digitalIO_PTC6;          //!< DigitalIO on pin PTC6
extern const DigitalIO digitalIO_PTC7;          //!< DigitalIO on pin PTC7
extern const DigitalIO digitalIO_PTC8;          //!< DigitalIO on pin PTC8
extern const DigitalIO digitalIO_PTC9;          //!< DigitalIO on pin PTC9
extern const DigitalIO digitalIO_PTC10;         //!< DigitalIO on pin PTC10
#define digitalIO_A5         digitalIO_PTC10
extern const DigitalIO digitalIO_PTC11;         //!< DigitalIO on pin PTC11
#define digitalIO_A4         digitalIO_PTC11
extern const DigitalIO digitalIO_PTC12;         //!< DigitalIO on pin PTC12
extern const DigitalIO digitalIO_PTC13;         //!< DigitalIO on pin PTC13
extern const DigitalIO digitalIO_PTC14;         //!< DigitalIO on pin PTC14
extern const DigitalIO digitalIO_PTC15;         //!< DigitalIO on pin PTC15
extern const DigitalIO digitalIO_PTC16;         //!< DigitalIO on pin PTC16
#define digitalIO_D0         digitalIO_PTC16
extern const DigitalIO digitalIO_PTC17;         //!< DigitalIO on pin PTC17
#define digitalIO_D1         digitalIO_PTC17
extern const DigitalIO digitalIO_PTC18;         //!< DigitalIO on pin PTC18
extern const DigitalIO digitalIO_PTC19;         //!< DigitalIO on pin PTC19
extern const DigitalIO digitalIO_PTD0;          //!< DigitalIO on pin PTD0
#define digitalIO_D10        digitalIO_PTD0
extern const DigitalIO digitalIO_PTD1;          //!< DigitalIO on pin PTD1
#define digitalIO_D13        digitalIO_PTD1
extern const DigitalIO digitalIO_PTD2;          //!< DigitalIO on pin PTD2
#define digitalIO_D11        digitalIO_PTD2
extern const DigitalIO digitalIO_PTD3;          //!< DigitalIO on pin PTD3
#define digitalIO_D12        digitalIO_PTD3
extern const DigitalIO digitalIO_PTD4;          //!< DigitalIO on pin PTD4
#define digitalIO_nRF24L01_cs digitalIO_PTD4
extern const DigitalIO digitalIO_PTD5;          //!< DigitalIO on pin PTD5
#define digitalIO_nRF24L01_sck digitalIO_PTD5
extern const DigitalIO digitalIO_PTD6;          //!< DigitalIO on pin PTD6
#define digitalIO_nRF24L01_mosi digitalIO_PTD6
extern const DigitalIO digitalIO_PTD7;          //!< DigitalIO on pin PTD7
#define digitalIO_nRF24L01_miso digitalIO_PTD7
extern const DigitalIO digitalIO_PTD8;          //!< DigitalIO on pin PTD8
extern const DigitalIO digitalIO_PTD9;          //!< DigitalIO on pin PTD9
extern const DigitalIO digitalIO_PTD10;         //!< DigitalIO on pin PTD10
extern const DigitalIO digitalIO_PTD11;         //!< DigitalIO on pin PTD11
extern const DigitalIO digitalIO_PTD12;         //!< DigitalIO on pin PTD12
extern const DigitalIO digitalIO_PTD13;         //!< DigitalIO on pin PTD13
extern const DigitalIO digitalIO_PTD14;         //!< DigitalIO on pin PTD14
extern const DigitalIO digitalIO_PTD15;         //!< DigitalIO on pin PTD15
extern const DigitalIO digitalIO_PTE0;          //!< DigitalIO on pin PTE0
extern const DigitalIO digitalIO_PTE1;          //!< DigitalIO on pin PTE1
extern const DigitalIO digitalIO_PTE2;          //!< DigitalIO on pin PTE2
extern const DigitalIO digitalIO_PTE3;          //!< DigitalIO on pin PTE3
extern const DigitalIO digitalIO_PTE4;          //!< DigitalIO on pin PTE4
extern const DigitalIO digitalIO_PTE5;          //!< DigitalIO on pin PTE5
extern const DigitalIO digitalIO_PTE6;          //!< DigitalIO on pin PTE6
extern const DigitalIO digitalIO_PTE7;          //!< DigitalIO on pin PTE7
extern const DigitalIO digitalIO_PTE8;          //!< DigitalIO on pin PTE8
extern const DigitalIO digitalIO_PTE9;          //!< DigitalIO on pin PTE9
extern const DigitalIO digitalIO_PTE10;         //!< DigitalIO on pin PTE10
extern const DigitalIO digitalIO_PTE11;         //!< DigitalIO on pin PTE11
extern const DigitalIO digitalIO_PTE12;         //!< DigitalIO on pin PTE12
extern const DigitalIO digitalIO_PTE24;         //!< DigitalIO on pin PTE24
#define digitalIO_D15        digitalIO_PTE24
extern const DigitalIO digitalIO_PTE25;         //!< DigitalIO on pin PTE25
#define digitalIO_D14        digitalIO_PTE25
extern const DigitalIO digitalIO_PTE26;         //!< DigitalIO on pin PTE26
#define digitalIO_LED_GREEN  digitalIO_PTE26
extern const DigitalIO digitalIO_PTE27;         //!< DigitalIO on pin PTE27
extern const DigitalIO digitalIO_PTE28;         //!< DigitalIO on pin PTE28
/**
 * @}
 */
/**
* @addtogroup AnalogueIO_Group Analogue Input
* @brief Allows use of port pins as analogue inputs
* @{
*/
extern const AnalogueIO analogueIO_ADC0_SE19;    //!< AnalogueIO on pin ADC0_DM0
extern const AnalogueIO analogueIO_ADC0_SE20;    //!< AnalogueIO on pin ADC0_DM1
extern const AnalogueIO analogueIO_ADC0_SE0;     //!< AnalogueIO on pin ADC0_DP0
extern const AnalogueIO analogueIO_ADC0_SE1;     //!< AnalogueIO on pin ADC0_DP1
extern const AnalogueIO analogueIO_ADC0_SE16;    //!< AnalogueIO on pin ADC0_SE16
extern const AnalogueIO analogueIO_ADC0_SE21;    //!< AnalogueIO on pin ADC0_SE16
extern const AnalogueIO analogueIO_ADC0_SE23;    //!< AnalogueIO on pin ADC0_SE23
extern const AnalogueIO analogueIO_ADC1_SE19;    //!< AnalogueIO on pin ADC1_DM0
extern const AnalogueIO analogueIO_ADC1_SE20;    //!< AnalogueIO on pin ADC1_DM1
extern const AnalogueIO analogueIO_ADC1_SE0;     //!< AnalogueIO on pin ADC1_DP0
extern const AnalogueIO analogueIO_ADC0_SE3;     //!< AnalogueIO on pin ADC1_DP0
extern const AnalogueIO analogueIO_ADC1_SE1;     //!< AnalogueIO on pin ADC1_DP1
extern const AnalogueIO analogueIO_ADC1_SE16;    //!< AnalogueIO on pin ADC1_SE16
extern const AnalogueIO analogueIO_ADC0_SE22;    //!< AnalogueIO on pin ADC1_SE16
extern const AnalogueIO analogueIO_ADC1_SE18;    //!< AnalogueIO on pin ADC1_SE18
extern const AnalogueIO analogueIO_ADC1_SE23;    //!< AnalogueIO on pin ADC1_SE23
#if (PTA7_SIG_SEL == 0)
extern const AnalogueIO analogueIO_ADC0_SE10;    //!< AnalogueIO on pin PTA7
#endif
#if (PTA8_SIG_SEL == 0)
extern const AnalogueIO analogueIO_ADC0_SE11;    //!< AnalogueIO on pin PTA8
#endif
#if (PTA17_SIG_SEL == 0)
extern const AnalogueIO analogueIO_ADC1_SE17;    //!< AnalogueIO on pin PTA17
#endif
#if (PTB0_SIG_SEL == 0)
extern const AnalogueIO analogueIO_ADC0_SE8;     //!< AnalogueIO on pin PTB0
#endif
#if (PTB0_SIG_SEL == 0)
extern const AnalogueIO analogueIO_ADC1_SE8;     //!< AnalogueIO on pin PTB0
#endif
#if (PTB1_SIG_SEL == 0)
extern const AnalogueIO analogueIO_ADC0_SE9;     //!< AnalogueIO on pin PTB1
#endif
#if (PTB1_SIG_SEL == 0)
extern const AnalogueIO analogueIO_ADC1_SE9;     //!< AnalogueIO on pin PTB1
#endif
#if (PTB2_SIG_SEL == 0)
extern const AnalogueIO analogueIO_ADC0_SE12;    //!< AnalogueIO on pin PTB2
#define analogueIO_A0        analogueIO_ADC0_SE12
#endif
#if (PTB3_SIG_SEL == 0)
extern const AnalogueIO analogueIO_ADC0_SE13;    //!< AnalogueIO on pin PTB3
#define analogueIO_A1        analogueIO_ADC0_SE13
#endif
#if (PTB4_SIG_SEL == 0)
extern const AnalogueIO analogueIO_ADC1_SE10;    //!< AnalogueIO on pin PTB4
#endif
#if (PTB5_SIG_SEL == 0)
extern const AnalogueIO analogueIO_ADC1_SE11;    //!< AnalogueIO on pin PTB5
#endif
#if (PTB6_SIG_SEL == 0)
extern const AnalogueIO analogueIO_ADC1_SE12;    //!< AnalogueIO on pin PTB6
#endif
#if (PTB7_SIG_SEL == 0)
extern const AnalogueIO analogueIO_ADC1_SE13;    //!< AnalogueIO on pin PTB7
#endif
#if (PTB10_SIG_SEL == 0)
extern const AnalogueIO analogueIO_ADC1_SE14;    //!< AnalogueIO on pin PTB10
#define analogueIO_A2        analogueIO_ADC1_SE14
#endif
#if (PTB11_SIG_SEL == 0)
extern const AnalogueIO analogueIO_ADC1_SE15;    //!< AnalogueIO on pin PTB11
#define analogueIO_A3        analogueIO_ADC1_SE15
#endif
#if (PTC0_SIG_SEL == 0)
extern const AnalogueIO analogueIO_ADC0_SE14;    //!< AnalogueIO on pin PTC0
#endif
#if (PTC1_SIG_SEL == 0)
extern const AnalogueIO analogueIO_ADC0_SE15;    //!< AnalogueIO on pin PTC1
#endif
#if (PTC2_SIG_SEL == 0)
extern const AnalogueIO analogueIO_ADC0_SE4b;    //!< AnalogueIO on pin PTC2
#define analogueIO_D6        analogueIO_ADC0_SE4b
#endif
#if (PTC8_SIG_SEL == 0)
extern const AnalogueIO analogueIO_ADC1_SE4b;    //!< AnalogueIO on pin PTC8
#endif
#if (PTC9_SIG_SEL == 0)
extern const AnalogueIO analogueIO_ADC1_SE5b;    //!< AnalogueIO on pin PTC9
#endif
#if (PTC10_SIG_SEL == 0)
extern const AnalogueIO analogueIO_ADC1_SE6b;    //!< AnalogueIO on pin PTC10
#define analogueIO_A5        analogueIO_ADC1_SE6b
#endif
#if (PTC11_SIG_SEL == 0)
extern const AnalogueIO analogueIO_ADC1_SE7b;    //!< AnalogueIO on pin PTC11
#define analogueIO_A4        analogueIO_ADC1_SE7b
#endif
#if (PTD1_SIG_SEL == 0)
extern const AnalogueIO analogueIO_ADC0_SE5b;    //!< AnalogueIO on pin PTD1
#define analogueIO_D13       analogueIO_ADC0_SE5b
#endif
#if (PTD5_SIG_SEL == 0)
extern const AnalogueIO analogueIO_ADC0_SE6b;    //!< AnalogueIO on pin PTD5
#define analogueIO_nRF24L01_sck analogueIO_ADC0_SE6b
#endif
#if (PTD6_SIG_SEL == 0)
extern const AnalogueIO analogueIO_ADC0_SE7b;    //!< AnalogueIO on pin PTD6
#define analogueIO_nRF24L01_mosi analogueIO_ADC0_SE7b
#endif
#if (PTE0_SIG_SEL == 0)
extern const AnalogueIO analogueIO_ADC1_SE4a;    //!< AnalogueIO on pin PTE0
#endif
#if (PTE1_SIG_SEL == 0)
extern const AnalogueIO analogueIO_ADC1_SE5a;    //!< AnalogueIO on pin PTE1
#endif
#if (PTE2_SIG_SEL == 0)
extern const AnalogueIO analogueIO_ADC1_SE6a;    //!< AnalogueIO on pin PTE2
#endif
#if (PTE2_SIG_SEL == 0)
extern const AnalogueIO analogueIO_ADC0_SE2;     //!< AnalogueIO on pin PTE2
#endif
#if (PTE3_SIG_SEL == 0)
extern const AnalogueIO analogueIO_ADC1_SE7a;    //!< AnalogueIO on pin PTE3
#endif
#if (PTE24_SIG_SEL == 0)
extern const AnalogueIO analogueIO_ADC0_SE17;    //!< AnalogueIO on pin PTE24
#define analogueIO_D15       analogueIO_ADC0_SE17
#endif
#if (PTE25_SIG_SEL == 0)
extern const AnalogueIO analogueIO_ADC0_SE18;    //!< AnalogueIO on pin PTE25
#define analogueIO_D14       analogueIO_ADC0_SE18
#endif
/**
 * @}
 */
/**
* @addtogroup PwmIO_Group PWM, Input capture, Output compare
* @brief Allows use of port pins as PWM outputs
* @{
*/
#if (PTA0_SIG_SEL == 3)
extern const PwmIO pwmIO_FTM0_CH5;          //!< PwmIO on pin PTA0
#define pwmIO_D8             pwmIO_FTM0_CH5
#endif
#if (PTA1_SIG_SEL == 3)
extern const PwmIO pwmIO_FTM0_CH6;          //!< PwmIO on pin PTA1
#define pwmIO_D3             pwmIO_FTM0_CH6
#endif
#if (PTA2_SIG_SEL == 3)
extern const PwmIO pwmIO_FTM0_CH7;          //!< PwmIO on pin PTA2
#define pwmIO_D5             pwmIO_FTM0_CH7
#endif
#if (PTA3_SIG_SEL == 3)
extern const PwmIO pwmIO_FTM0_CH0;          //!< PwmIO on pin PTA3
#endif
#if (PTA4_SIG_SEL == 3)
extern const PwmIO pwmIO_FTM0_CH1;          //!< PwmIO on pin PTA4
#endif
#if (PTA5_SIG_SEL == 3)
extern const PwmIO pwmIO_FTM0_CH2;          //!< PwmIO on pin PTA5
#endif
#if (PTA6_SIG_SEL == 3)
extern const PwmIO pwmIO_FTM0_CH3;          //!< PwmIO on pin PTA6
#endif
#if (PTA7_SIG_SEL == 3)
extern const PwmIO pwmIO_FTM0_CH4;          //!< PwmIO on pin PTA7
#endif
#if (PTA8_SIG_SEL == 3)
extern const PwmIO pwmIO_FTM1_CH0;          //!< PwmIO on pin PTA8
#endif
#if (PTA9_SIG_SEL == 3)
extern const PwmIO pwmIO_FTM1_CH1;          //!< PwmIO on pin PTA9
#endif
#if (PTA10_SIG_SEL == 3)
extern const PwmIO pwmIO_FTM2_CH0;          //!< PwmIO on pin PTA10
#endif
#if (PTA11_SIG_SEL == 3)
extern const PwmIO pwmIO_FTM2_CH1;          //!< PwmIO on pin PTA11
#endif
#if (PTA12_SIG_SEL == 3)
extern const PwmIO pwmIO_FTM1_CH0;          //!< PwmIO on pin PTA12
#endif
#if (PTA13_SIG_SEL == 3)
extern const PwmIO pwmIO_FTM1_CH1;          //!< PwmIO on pin PTA13
#endif
#if (PTB0_SIG_SEL == 3)
extern const PwmIO pwmIO_FTM1_CH0;          //!< PwmIO on pin PTB0
#endif
#if (PTB1_SIG_SEL == 3)
extern const PwmIO pwmIO_FTM1_CH1;          //!< PwmIO on pin PTB1
#endif
#if (PTB12_SIG_SEL == 3)
extern const PwmIO pwmIO_FTM1_CH0;          //!< PwmIO on pin PTB12
#endif
#if (PTB12_SIG_SEL == 4)
extern const PwmIO pwmIO_FTM0_CH4;          //!< PwmIO on pin PTB12
#endif
#if (PTB13_SIG_SEL == 3)
extern const PwmIO pwmIO_FTM1_CH1;          //!< PwmIO on pin PTB13
#endif
#if (PTB13_SIG_SEL == 4)
extern const PwmIO pwmIO_FTM0_CH5;          //!< PwmIO on pin PTB13
#endif
#if (PTB18_SIG_SEL == 3)
extern const PwmIO pwmIO_FTM2_CH0;          //!< PwmIO on pin PTB18
#endif
#if (PTB19_SIG_SEL == 3)
extern const PwmIO pwmIO_FTM2_CH1;          //!< PwmIO on pin PTB19
#endif
#if (PTC1_SIG_SEL == 4)
extern const PwmIO pwmIO_FTM0_CH0;          //!< PwmIO on pin PTC1
#endif
#if (PTC2_SIG_SEL == 4)
extern const PwmIO pwmIO_FTM0_CH1;          //!< PwmIO on pin PTC2
#define pwmIO_D6             pwmIO_FTM0_CH1
#endif
#if (PTC3_SIG_SEL == 4)
extern const PwmIO pwmIO_FTM0_CH2;          //!< PwmIO on pin PTC3
#define pwmIO_D7             pwmIO_FTM0_CH2
#endif
#if (PTC4_SIG_SEL == 4)
extern const PwmIO pwmIO_FTM0_CH3;          //!< PwmIO on pin PTC4
#define pwmIO_D9             pwmIO_FTM0_CH3
#endif
#if (PTC5_SIG_SEL == 7)
extern const PwmIO pwmIO_FTM0_CH2;          //!< PwmIO on pin PTC5
#endif
#if (PTC8_SIG_SEL == 3)
extern const PwmIO pwmIO_FTM3_CH4;          //!< PwmIO on pin PTC8
#endif
#if (PTC9_SIG_SEL == 3)
extern const PwmIO pwmIO_FTM3_CH5;          //!< PwmIO on pin PTC9
#endif
#if (PTC10_SIG_SEL == 3)
extern const PwmIO pwmIO_FTM3_CH6;          //!< PwmIO on pin PTC10
#define pwmIO_A5             pwmIO_FTM3_CH6
#endif
#if (PTC11_SIG_SEL == 3)
extern const PwmIO pwmIO_FTM3_CH7;          //!< PwmIO on pin PTC11
#define pwmIO_A4             pwmIO_FTM3_CH7
#endif
#if (PTD0_SIG_SEL == 4)
extern const PwmIO pwmIO_FTM3_CH0;          //!< PwmIO on pin PTD0
#define pwmIO_D10            pwmIO_FTM3_CH0
#endif
#if (PTD1_SIG_SEL == 4)
extern const PwmIO pwmIO_FTM3_CH1;          //!< PwmIO on pin PTD1
#define pwmIO_D13            pwmIO_FTM3_CH1
#endif
#if (PTD2_SIG_SEL == 4)
extern const PwmIO pwmIO_FTM3_CH2;          //!< PwmIO on pin PTD2
#define pwmIO_D11            pwmIO_FTM3_CH2
#endif
#if (PTD3_SIG_SEL == 4)
extern const PwmIO pwmIO_FTM3_CH3;          //!< PwmIO on pin PTD3
#define pwmIO_D12            pwmIO_FTM3_CH3
#endif
#if (PTD4_SIG_SEL == 4)
extern const PwmIO pwmIO_FTM0_CH4;          //!< PwmIO on pin PTD4
#define pwmIO_nRF24L01_cs    pwmIO_FTM0_CH4
#endif
#if (PTD5_SIG_SEL == 4)
extern const PwmIO pwmIO_FTM0_CH5;          //!< PwmIO on pin PTD5
#define pwmIO_nRF24L01_sck   pwmIO_FTM0_CH5
#endif
#if (PTD6_SIG_SEL == 4)
extern const PwmIO pwmIO_FTM0_CH6;          //!< PwmIO on pin PTD6
#define pwmIO_nRF24L01_mosi  pwmIO_FTM0_CH6
#endif
#if (PTD7_SIG_SEL == 4)
extern const PwmIO pwmIO_FTM0_CH7;          //!< PwmIO on pin PTD7
#define pwmIO_nRF24L01_miso  pwmIO_FTM0_CH7
#endif
#if (PTE5_SIG_SEL == 6)
extern const PwmIO pwmIO_FTM3_CH0;          //!< PwmIO on pin PTE5
#endif
#if (PTE6_SIG_SEL == 6)
extern const PwmIO pwmIO_FTM3_CH1;          //!< PwmIO on pin PTE6
#endif
#if (PTE7_SIG_SEL == 6)
extern const PwmIO pwmIO_FTM3_CH2;          //!< PwmIO on pin PTE7
#endif
#if (PTE8_SIG_SEL == 6)
extern const PwmIO pwmIO_FTM3_CH3;          //!< PwmIO on pin PTE8
#endif
#if (PTE9_SIG_SEL == 6)
extern const PwmIO pwmIO_FTM3_CH4;          //!< PwmIO on pin PTE9
#endif
#if (PTE10_SIG_SEL == 6)
extern const PwmIO pwmIO_FTM3_CH5;          //!< PwmIO on pin PTE10
#endif
#if (PTE11_SIG_SEL == 6)
extern const PwmIO pwmIO_FTM3_CH6;          //!< PwmIO on pin PTE11
#endif
#if (PTE12_SIG_SEL == 6)
extern const PwmIO pwmIO_FTM3_CH7;          //!< PwmIO on pin PTE12
#endif
/**
 * @}
 */
#if defined(DO_MAP_PINS_ON_RESET) && (DO_MAP_PINS_ON_RESET>0)
/**
 * Used to configure pin-mapping before 1st use of peripherals
 */
extern void usbdm_PinMapping();
#endif

/*
Clock Information 
ADC0       SIM->SCGC6   SIM_SCGC6_ADC0_MASK
ADC1       SIM->SCGC3   SIM_SCGC3_ADC1_MASK
CMP        SIM->SCGC4   SIM_SCGC4_CMP_MASK
CMT        SIM->SCGC4   SIM_SCGC4_CMT_MASK
DAC0       SIM->SCGC6   SIM_SCGC6_DAC0_MASK
DAC1       SIM->SCGC2   SIM_SCGC2_DAC1_MASK
DMA        SIM->SCGC7   SIM_SCGC7_DMA_MASK
DMAMUX     SIM->SCGC6   SIM_SCGC6_DMAMUX_MASK
ENET       SIM->SCGC2   SIM_SCGC2_ENET_MASK
EWM        SIM->SCGC4   SIM_SCGC4_EWM_MASK
FLEXBUS    SIM->SCGC7   SIM_SCGC7_FLEXBUS_MASK
FLEXCAN    SIM->SCGC6   SIM_SCGC6_FLEXCAN_MASK
FTM0       SIM->SCGC6   SIM_SCGC6_FTM0_MASK
FTM1       SIM->SCGC6   SIM_SCGC6_FTM1_MASK
FTM2       SIM->SCGC6   SIM_SCGC6_FTM2_MASK
FTM3       SIM->SCGC3   SIM_SCGC3_FTM3_MASK
I2C0       SIM->SCGC4   SIM_SCGC4_I2C0_MASK
I2C1       SIM->SCGC4   SIM_SCGC4_I2C1_MASK
I2C2       SIM->SCGC1   SIM_SCGC1_I2C2_MASK
I2S0       SIM->SCGC6   SIM_SCGC6_I2S0_MASK
LPTMR0     SIM->SCGC5   SIM_SCGC5_LPTMR_MASK
MPU        SIM->SCGC7   SIM_SCGC7_MPU_MASK
PDB0       SIM->SCGC6   SIM_SCGC6_PDB0_MASK
PIT        SIM->SCGC6   SIM_SCGC6_PIT_MASK
PORTA      SIM->SCGC5   SIM_SCGC5_PORTA_MASK
PORTB      SIM->SCGC5   SIM_SCGC5_PORTB_MASK
PORTC      SIM->SCGC5   SIM_SCGC5_PORTC_MASK
PORTD      SIM->SCGC5   SIM_SCGC5_PORTD_MASK
PORTE      SIM->SCGC5   SIM_SCGC5_PORTE_MASK
RNGA       SIM->SCGC6   SIM_SCGC6_RNGA_MASK
RTC        SIM->SCGC6   SIM_SCGC6_RTC_MASK
SDHC0      SIM->SCGC3   SIM_SCGC3_SDHC0_MASK
SPI0       SIM->SCGC6   SIM_SCGC6_SPI0_MASK
SPI1       SIM->SCGC6   SIM_SCGC6_SPI1_MASK
SPI2       SIM->SCGC3   SIM_SCGC3_SPI2_MASK
UART0      SIM->SCGC4   SIM_SCGC4_UART0_MASK
UART1      SIM->SCGC4   SIM_SCGC4_UART1_MASK
UART2      SIM->SCGC4   SIM_SCGC4_UART2_MASK
UART3      SIM->SCGC4   SIM_SCGC4_UART3_MASK
UART4      SIM->SCGC1   SIM_SCGC1_UART4_MASK
UART5      SIM->SCGC1   SIM_SCGC1_UART5_MASK
USBDCD     SIM->SCGC6   SIM_SCGC6_USBDCD_MASK
USBOTG     SIM->SCGC4   SIM_SCGC4_USBOTG_MASK
VREF       SIM->SCGC4   SIM_SCGC4_VREF_MASK
*/


#endif /* GPIO_H_ */