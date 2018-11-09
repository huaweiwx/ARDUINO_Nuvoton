/**************************************************************************//**
 * @file     Nano100Series.h
 * @version  V1.00
 * $Revision: 28 $
 * $Date: 14/03/27 10:58a $
 * @brief    Nano100 series peripheral access layer header file.
 *           This file contains all the peripheral register's definitions,
 *           bits definitions and memory mapping for NuMicro Nano100 series MCU.
 *
 * @note
 * Copyright (C) 2014 Nuvoton Technology Corp. All rights reserved.
 *****************************************************************************/
/**
   \mainpage NuMicro NANO100BN Driver Reference Guide
   *
   * <b>Introduction</b>
   *
   * This user manual describes the usage of Nano100AN Series MCU device driver
   *
   * <b>Disclaimer</b>
   *
   * The Software is furnished "AS IS", without warranty as to performance or results, and
   * the entire risk as to performance or results is assumed by YOU. Nuvoton disclaims all
   * warranties, express, implied or otherwise, with regard to the Software, its use, or
   * operation, including without limitation any and all warranties of merchantability, fitness
   * for a particular purpose, and non-infringement of intellectual property rights.
   *
   * <b>Important Notice</b>
   *
   * Nuvoton Products are neither intended nor warranted for usage in systems or equipment,
   * any malfunction or failure of which may cause loss of human life, bodily injury or severe
   * property damage. Such applications are deemed, "Insecure Usage".
   *
   * Insecure usage includes, but is not limited to: equipment for surgical implementation,
   * atomic energy control instruments, airplane or spaceship instruments, the control or
   * operation of dynamic, brake or safety systems designed for vehicular use, traffic signal
   * instruments, all types of safety devices, and other applications intended to support or
   * sustain life.
   *
   * All Insecure Usage shall be made at customer's risk, and in the event that third parties
   * lay claims to Nuvoton as a result of customer's Insecure Usage, customer shall indemnify
   * the damages and liabilities thus incurred by Nuvoton.
   *
   * Please note that all data and specifications are subject to change without notice. All the
   * trademarks of products and companies mentioned in this datasheet belong to their respective
   * owners.
   *
   * <b>Copyright Notice</b>
   *
   * Copyright (C) 2014 Nuvoton Technology Corp. All rights reserved.
   */
/**
  * \page pg1 NuMicro NANO100 BSP Directory Structure
  * The BSP directory structure is shown in following figures.
  *
  * \image html dir.jpg "BSP Directory Structure"
  * \image latex dir.jpg "BSP Directory Structure"
  *
  * \page pg2 Revision History
  *
  * <b>Revision 3.00.000</b>
  * \li Update major version number from 2 to 3
  * \li Renamed RTC_GetDatAndTime() to RTC_GetDateAndTime()
  *
  * <b>Revision 2.00.000</b>
  * \li Initial release
*/
#ifndef __NANO100SERIES_H__
#define __NANO100SERIES_H__

#ifdef __cplusplus
extern "C" {
#endif

/** @addtogroup NANO100_Definitions NANO100 Definitions
  This file defines all structures and symbols for Nano100:
    - interrupt numbers
    - registers and bit fields
    - peripheral base address
    - peripheral ID
    - Peripheral definitions
  @{
*/

/******************************************************************************/
/*                Processor and Core Peripherals                              */
/******************************************************************************/
/** @addtogroup NANO100_CMSIS Device CMSIS Definitions
  Configuration of the Cortex-M0 Processor and Core Peripherals
  @{
*/

/**
 * @details  Interrupt Number Definition. The maximum of 32 Specific Interrupts are possible.
 */
typedef enum IRQn {
    /******  Cortex-M0 Processor Exceptions Numbers *****************************************/

    NonMaskableInt_IRQn   = -14,    /*!< 2 Non Maskable Interrupt                           */
    HardFault_IRQn        = -13,    /*!< 3 Cortex-M0 Hard Fault Interrupt                   */
    SVCall_IRQn           = -5,     /*!< 11 Cortex-M0 SV Call Interrupt                     */
    PendSV_IRQn           = -2,     /*!< 14 Cortex-M0 Pend SV Interrupt                     */
    SysTick_IRQn          = -1,     /*!< 15 Cortex-M0 System Tick Interrupt                 */

    /******  Nano100 specific Interrupt Numbers ***********************************************/
    BOD_IRQn              = 0,      /*!< Brownout low voltage detected interrupt                   */
    WDT_IRQn              = 1,      /*!< Watch Dog Timer interrupt                                 */
    EINT0_IRQn            = 2,      /*!< External signal interrupt from PB.14 pin                  */
    EINT1_IRQn            = 3,      /*!< External signal interrupt from PB.15 pin                  */
    GPABC_IRQn            = 4,      /*!< External signal interrupt from PA[15:0]/PB[13:0]/PC[15:0] */
    GPDEF_IRQn            = 5,      /*!< External interrupt from PD[15:0]/PE[15:0]/PF[15:0]        */
    PWM0_IRQn             = 6,      /*!< PWM 0 interrupt                                           */
    PWM1_IRQn             = 7,      /*!< PWM 1 interrupt                                           */
    TMR0_IRQn             = 8,      /*!< Timer 0 interrupt                                         */
    TMR1_IRQn             = 9,      /*!< Timer 1 interrupt                                         */
    TMR2_IRQn             = 10,     /*!< Timer 2 interrupt                                         */
    TMR3_IRQn             = 11,     /*!< Timer 3 interrupt                                         */
    UART0_IRQn            = 12,     /*!< UART0 interrupt                                           */
    UART1_IRQn            = 13,     /*!< UART1 interrupt                                           */
    SPI0_IRQn             = 14,     /*!< SPI0 interrupt                                            */
    SPI1_IRQn             = 15,     /*!< SPI1 interrupt                                            */
    SPI2_IRQn             = 16,     /*!< SPI2 interrupt                                            */
    HIRC_IRQn             = 17,     /*!< HIRC interrupt                                            */
    I2C0_IRQn             = 18,     /*!< I2C0 interrupt                                            */
    I2C1_IRQn             = 19,     /*!< I2C1 interrupt                                            */
    SC2_IRQn              = 20,     /*!< Smart Card 2 interrupt                                    */
    SC0_IRQn              = 21,     /*!< Smart Card 0 interrupt                                    */
    SC1_IRQn              = 22,     /*!< Smart Card 1 interrupt                                    */
    USBD_IRQn             = 23,     /*!< USB FS Device interrupt                                   */
    LCD_IRQn              = 25,     /*!< LCD interrupt                                             */
    PDMA_IRQn             = 26,     /*!< PDMA interrupt                                            */
    I2S_IRQn              = 27,     /*!< I2S interrupt                                             */
    PDWU_IRQn             = 28,     /*!< Power Down Wake up interrupt                              */
    ADC_IRQn              = 29,     /*!< ADC interrupt                                             */
    DAC_IRQn              = 30,     /*!< DAC interrupt                                             */
    RTC_IRQn              = 31      /*!< Real time clock interrupt                                 */
} IRQn_Type;


/*
 * ==========================================================================
 * ----------- Processor and Core Peripheral Section ------------------------
 * ==========================================================================
 */

/* Configuration of the Cortex-M0 Processor and Core Peripherals */
#define __CM0_REV                0x0201    /*!< Core Revision r2p1                               */
#define __NVIC_PRIO_BITS         2         /*!< Number of Bits used for Priority Levels          */
#define __Vendor_SysTickConfig   0         /*!< Set to 1 if different SysTick Config is used     */
#define __MPU_PRESENT            0         /*!< MPU present or not                               */
#define __FPU_PRESENT            0         /*!< FPU present or not                               */

/*@}*/ /* end of group NANO100_CMSIS */


#include "core_cm0.h"                       /* Cortex-M0 processor and core peripherals           */
#include "system_Nano100Series.h"           /* Nano100 Series System include file                  */
#include <stdint.h>

/******************************************************************************/
/*                Device Specific Peripheral registers structures             */
/******************************************************************************/
/** @addtogroup NANO100_Peripherals NANO100 Peripherals
  NANO100 Device Specific Peripheral registers structures
  @{
*/

#if defined ( __CC_ARM  )
#pragma anon_unions
#endif


/*------------- Global Control Register (GCR) -----------------------------*/
/** @addtogroup NANO100_SYS NANO100 Global Control Register (GCR/SYS)
  Memory Mapped Structure for NANO100 Series System Global Controller
  @{
*/
/**
  * @brief GCR register map
  */
typedef struct {
    __I  uint32_t  PDID;                        /*!< Offset: 0x0000   Part Device Identification Number Register          */
    __IO uint32_t  RST_SRC;                     /*!< Offset: 0x0004   System Reset Source Register                        */
    __IO uint32_t  IPRST_CTL1;                  /*!< Offset: 0x0008   IP Reset Control Register 1                         */
    __IO uint32_t  IPRST_CTL2;                  /*!< Offset: 0x000C   IP Reset Control Register 2                         */
    uint32_t  RESERVED0[4];                /*!< Offset: 0x000C~0x001C Reserved                                       */
    __IO uint32_t  TEMCTL;                      /*!< Offset: 0x0020   Temperature Sensor Control Register                 */
    uint32_t  RESERVED1[3];                /*!< Offset: 0x0024~0x002C Reserved                                       */
    __IO uint32_t  PA_L_MFP;                    /*!< Offset: 0x0030   Port A low byte multiple function control Register  */
    __IO uint32_t  PA_H_MFP;                    /*!< Offset: 0x0034   Port A high byte multiple function control Register */
    __IO uint32_t  PB_L_MFP;                    /*!< Offset: 0x0038   Port B low byte multiple function control Register  */
    __IO uint32_t  PB_H_MFP;                    /*!< Offset: 0x003C   Port B high byte multiple function control Register */
    __IO uint32_t  PC_L_MFP;                    /*!< Offset: 0x0040   Port C low byte multiple function control Register  */
    __IO uint32_t  PC_H_MFP;                    /*!< Offset: 0x0044   Port C high byte multiple function control Register */
    __IO uint32_t  PD_L_MFP;                    /*!< Offset: 0x0048   Port D low byte multiple function control Register  */
    __IO uint32_t  PD_H_MFP;                    /*!< Offset: 0x004C   Port D high byte multiple function control Register */
    __IO uint32_t  PE_L_MFP;                    /*!< Offset: 0x0050   Port E low byte multiple function control Register  */
    __IO uint32_t  PE_H_MFP;                    /*!< Offset: 0x0054   Port E high byte multiple function control Register */
    __IO uint32_t  PF_L_MFP;                    /*!< Offset: 0x0058   Port F low byte multiple function control Register  */
    uint32_t  RESERVED3[1];                /*!< Offset: 0x005C   Reserved                                            */
    __IO uint32_t  PORCTL;                      /*!< Offset: 0x0060   Power-On-Reset Controller Register                  */
    __IO uint32_t  BODCTL;                      /*!< Offset: 0x0064   Brown-out Detector Control Register                 */
    __IO uint32_t  BODSTS;                      /*!< Offset: 0x0068   Brown-out Detector Status Register                  */
    __IO uint32_t  VREFCTL;                     /*!< Offset: 0x006C   Voltage reference Control Register                  */
    uint32_t  RESERVED4[4];                /*!< Offset: 0x0070~0x007C Reserved                                       */
    __IO uint32_t  IRCTRIMCTL;                  /*!< Offset: 0x0080   HIRC Trim Control Register                          */
    __IO uint32_t  IRCTRIMIER;                  /*!< Offset: 0x0084   HIRC Trim Interrupt Enable Register                 */
    __IO uint32_t  IRCTRIMISR;                  /*!< Offset: 0x0088   HIRC Trim Interrupt Status Register                 */
    uint32_t  RESERVED5[29];               /*!< Offset: 0x008C~0x00FC Reserved                                       */
    __IO uint32_t  RegLockAddr;                 /*!< Offset: 0x0100   Register Lock Key address                           */
    uint32_t  RESERVED6[3];                /*!< Offset: 0x0104~0x010C Reserved                                       */
    __IO uint32_t  RCADJ;                       /*!< Offset: 0x0110   RC Adjustment control register                      */
} GCR_T;



/* SYS RSTSRC Bit Field Definitions */
#define SYS_RST_SRC_RSTS_CPU_Pos                 7                                       /*!< GCR RSTSRC: RSTS_CPU Position */
#define SYS_RST_SRC_RSTS_CPU_Msk                 (1UL << SYS_RSTSRC_RSTS_CPU_Pos)        /*!< GCR RSTSRC: RSTS_CPU Mask */

#define SYS_RST_SRC_RSTS_SYS_Pos                 5                                       /*!< GCR RSTSRC: RSTS_SYS Position */
#define SYS_RST_SRC_RSTS_SYS_Msk                 (1UL << SYS_RSTSRC_RSTS_SYS_Pos)        /*!< GCR RSTSRC: RSTS_SYS Mask */

#define SYS_RST_SRC_RSTS_BOD_Pos                 4                                       /*!< GCR RSTSRC: RSTS_BOD Position */
#define SYS_RST_SRC_RSTS_BOD_Msk                 (1UL << SYS_RSTSRC_RSTS_BOD_Pos)        /*!< GCR RSTSRC: RSTS_BOD Mask */

#define SYS_RST_SRC_RSTS_WDT_Pos                 2                                       /*!< GCR RSTSRC: RSTS_WDT Position */
#define SYS_RST_SRC_RSTS_WDT_Msk                 (1UL << SYS_RSTSRC_RSTS_WDT_Pos)        /*!< GCR RSTSRC: RSTS_WDT Mask */

#define SYS_RST_SRC_RSTS_RESET_Pos               1                                       /*!< GCR RSTSRC: RSTS_RESET Position */
#define SYS_RST_SRC_RSTS_RESET_Msk               (1UL << SYS_RSTSRC_RSTS_RESET_Pos)      /*!< GCR RSTSRC: RSTS_RESET Mask */

#define SYS_RST_SRC_RSTS_POR_Pos                 0                                       /*!< GCR RSTSRC: RSTS_POR Position */
#define SYS_RST_SRC_RSTS_POR_Msk                 (1UL << SYS_RSTSRC_RSTS_POR_Pos)        /*!< GCR RSTSRC: RSTS_POR Mask */

/* SYS IPRST_CTL1 Bit Field Definitions */
#define SYS_IPRST_CTL1_EBI_RST_Pos    3                                                  /*!< GCR IPRST_CTL1: EBI_RST Position */
#define SYS_IPRST_CTL1_EBI_RST_Msk  (1UL<<SYS_IPRST_CTL1_EBI_RST_Pos)                    /*!< GCR IPRST_CTL1: EBI_RST Mask */

#define SYS_IPRST_CTL1_DMA_RST_Pos    2                                                  /*!< GCR IPRST_CTL1: DMA_RST Position */
#define SYS_IPRST_CTL1_DMA_RST_Msk  (1UL<<SYS_IPRST_CTL1_DMA_RST_Pos)                    /*!< GCR IPRST_CTL1: DMA_RST Mask */

#define SYS_IPRST_CTL1_CPU_RST_Pos    1                                                  /*!< GCR IPRST_CTL1: CPU_RST Position */
#define SYS_IPRST_CTL1_CPU_RST_Msk    (1UL<<SYS_IPRST_CTL1_CPU_RST_Pos)                  /*!< GCR IPRST_CTL1: CPU_RST Mask */

#define SYS_IPRST_CTL1_CHIP_RST_Pos    0                                                 /*!< GCR IPRST_CTL1: CHIP_RST Position */
#define SYS_IPRST_CTL1_CHIP_RST_Msk    (1UL<<SYS_IPRST_CTL1_CHIP_RST_Pos)                /*!< GCR IPRST_CTL1: CHIP_RST Mask */
/* SYS IPRST_CTL2 Bit Field Definitions */
#define SYS_IPRST_CTL2_SC1_RST_Pos    31                                                 /*!< GCR IPRST_CTL2: SC1_RST Position */
#define SYS_IPRST_CTL2_SC1_RST_Msk  (1UL<<SYS_IPRST_CTL2_SC1_RST_Pos)                    /*!< GCR IPRST_CTL2: SC1_RST Mask */

#define SYS_IPRST_CTL2_SC0_RST_Pos    30                                                 /*!< GCR IPRST_CTL2: SC0_RST Position */
#define SYS_IPRST_CTL2_SC0_RST_Msk  (1UL<<SYS_IPRST_CTL2_SC0_RST_Pos)                    /*!< GCR IPRST_CTL2: SC0_RST Mask */

#define SYS_IPRST_CTL2_I2S_RST_Pos    29                                                 /*!< GCR IPRST_CTL2: I2S_RST Position */
#define SYS_IPRST_CTL2_I2S_RST_Msk  (1UL<<SYS_IPRST_CTL2_I2S_RST_Pos)                    /*!< GCR IPRST_CTL2: I2S_RST Mask */

#define SYS_IPRST_CTL2_ADC_RST_Pos    28                                                 /*!< GCR IPRST_CTL2: ADC_RST Position */
#define SYS_IPRST_CTL2_ADC_RST_Msk  (1UL<<SYS_IPRST_CTL2_ADC_RST_Pos)                    /*!< GCR IPRST_CTL2: ADC_RST Mask */

#define SYS_IPRST_CTL2_USBD_RST_Pos   27                                                 /*!< GCR IPRST_CTL2: USBD_RST Position */
#define SYS_IPRST_CTL2_USBD_RST_Msk (1UL<<SYS_IPRST_CTL2_USBD_RST_Pos)                   /*!< GCR IPRST_CTL2: USBD_RST Mask */

#define SYS_IPRST_CTL2_LCD_RST_Pos    26                                                 /*!< GCR IPRST_CTL2: LCD_RST Position */
#define SYS_IPRST_CTL2_LCD_RST_Msk  (1UL<<SYS_IPRST_CTL2_LCD_RST_Pos)                    /*!< GCR IPRST_CTL2: LCD_RST Mask */

#define SYS_IPRST_CTL2_DAC_RST_Pos    25                                                 /*!< GCR IPRST_CTL2: DAC_RST Position */
#define SYS_IPRST_CTL2_DAC_RST_Msk  (1UL<<SYS_IPRST_CTL2_DAC_RST_Pos)                    /*!< GCR IPRST_CTL2: DAC_RST Mask */

#define SYS_IPRST_CTL2_PWM1_RST_Pos    21                                                /*!< GCR IPRST_CTL2: PWM1_RST Position */
#define SYS_IPRST_CTL2_PWM1_RST_Msk  (1UL<<SYS_IPRST_CTL2_PWM1_RST_Pos)                  /*!< GCR IPRST_CTL2: PWM1_RST Mask */

#define SYS_IPRST_CTL2_PWM0_RST_Pos    20                                                /*!< GCR IPRST_CTL2: PWM0_RST Position */
#define SYS_IPRST_CTL2_PWM0_RST_Msk  (1UL<<SYS_IPRST_CTL2_PWM0_RST_Pos)                  /*!< GCR IPRST_CTL2: PWM0_RST Mask */

#define SYS_IPRST_CTL2_UART1_RST_Pos    17                                               /*!< GCR IPRST_CTL2: UART1_RST Position */
#define SYS_IPRST_CTL2_UART1_RST_Msk  (1UL<<SYS_IPRST_CTL2_UART1_RST_Pos)                /*!< GCR IPRST_CTL2: UART1_RST Mask */

#define SYS_IPRST_CTL2_UART0_RST_Pos    16                                               /*!< GCR IPRST_CTL2: UART0_RST Position */
#define SYS_IPRST_CTL2_UART0_RST_Msk  (1UL<<SYS_IPRST_CTL2_UART0_RST_Pos)                /*!< GCR IPRST_CTL2: UART0_RST Mask */

#define SYS_IPRST_CTL2_SPI2_RST_Pos    14                                                /*!< GCR IPRST_CTL2: SPI2_RST Position */
#define SYS_IPRST_CTL2_SPI2_RST_Msk  (1UL<<SYS_IPRST_CTL2_SPI2_RST_Pos)                  /*!< GCR IPRST_CTL2: SPI2_RST Mask */

#define SYS_IPRST_CTL2_SPI1_RST_Pos    13                                                /*!< GCR IPRST_CTL2: SPI1_RST Position */
#define SYS_IPRST_CTL2_SPI1_RST_Msk  (1UL<<SYS_IPRST_CTL2_SPI1_RST_Pos)                  /*!< GCR IPRST_CTL2: SPI1_RST Mask */

#define SYS_IPRST_CTL2_SPI0_RST_Pos    12                                                /*!< GCR IPRST_CTL2: SPI0_RST Position */
#define SYS_IPRST_CTL2_SPI0_RST_Msk  (1UL<<SYS_IPRST_CTL2_SPI0_RST_Pos)                  /*!< GCR IPRST_CTL2: SPI0_RST Mask */

#define SYS_IPRST_CTL2_I2C1_RST_Pos    9                                                 /*!< GCR IPRST_CTL2: I2C1_RST Position */
#define SYS_IPRST_CTL2_I2C1_RST_Msk  (1UL<<SYS_IPRST_CTL2_I2C1_RST_Pos)                  /*!< GCR IPRST_CTL2: I2C1_RST Mask */

#define SYS_IPRST_CTL2_I2C0_RST_Pos    8                                                 /*!< GCR IPRST_CTL2: I2C0_RST Position */
#define SYS_IPRST_CTL2_I2C0_RST_Msk  (1UL<<SYS_IPRST_CTL2_I2C0_RST_Pos)                  /*!< GCR IPRST_CTL2: I2C0_RST Mask */

#define SYS_IPRST_CTL2_SC2_RST_Pos    7                                                 /*!< GCR IPRST_CTL2: SC2_RST Position */
#define SYS_IPRST_CTL2_SC2_RST_Msk  (1UL<<SYS_IPRST_CTL2_SC2_RST_Pos)                   /*!< GCR IPRST_CTL2: SC2_RST Mask */

#define SYS_IPRST_CTL2_TMR3_RST_Pos    5                                                 /*!< GCR IPRST_CTL2: TMR3_RST Position */
#define SYS_IPRST_CTL2_TMR3_RST_Msk  (1UL<<SYS_IPRST_CTL2_TMR3_RST_Pos)                  /*!< GCR IPRST_CTL2: TMR3_RST Mask */

#define SYS_IPRST_CTL2_TMR2_RST_Pos    4                                                 /*!< GCR IPRST_CTL2: TMR2_RST Position */
#define SYS_IPRST_CTL2_TMR2_RST_Msk  (1UL<<SYS_IPRST_CTL2_TMR2_RST_Pos)                  /*!< GCR IPRST_CTL2: TMR2_RST Mask */

#define SYS_IPRST_CTL2_TMR1_RST_Pos    3                                                 /*!< GCR IPRST_CTL2: TMR1_RST Position */
#define SYS_IPRST_CTL2_TMR1_RST_Msk  (1UL<<SYS_IPRST_CTL2_TMR1_RST_Pos)                  /*!< GCR IPRST_CTL2: TMR1_RST Mask */

#define SYS_IPRST_CTL2_TMR0_RST_Pos    2                                                 /*!< GCR IPRST_CTL2: TMR0_RST Position */
#define SYS_IPRST_CTL2_TMR0_RST_Msk  (1UL<<SYS_IPRST_CTL2_TMR0_RST_Pos)                  /*!< GCR IPRST_CTL2: TMR0_RST Mask */

#define SYS_IPRST_CTL2_GPIO_RST_Pos    1                                                 /*!< GCR IPRST_CTL2: GPIO_RST Position */
#define SYS_IPRST_CTL2_GPIO_RST_Msk  (1UL<<SYS_IPRST_CTL2_GPIO_RST_Pos)                  /*!< GCR IPRST_CTL2: GPIO_RST Mask */

/* SYS TEMPCTL Bit Field Definitions */
#define SYS_TEMPCTL_VTEMP_EN_Pos    0                                                    /*!< GCR TEMPCTL: VTEMP_EN Position */
#define SYS_TEMPCTL_VTEMP_EN_Msk  (1UL<<SYS_TEMPCTL_VTEMP_EN_Pos)                        /*!< GCR TEMPCTL: VTEMP_EN Mask */

/* SYS PA_L_MFP Bit Field Definitions */
#define SYS_PA_L_MFP_PA7_MFP_Pos      28                                                 /*!< GCR PA_L_MFP: PA7_MFP Position */
#define SYS_PA_L_MFP_PA7_MFP_Msk    (0xFUL<<SYS_PA_L_MFP_PA7_MFP_Pos)                    /*!< GCR PA_L_MFP: PA7_MFP Mask */

#define SYS_PA_L_MFP_PA6_MFP_Pos      24                                                 /*!< GCR PA_L_MFP: PA6_MFP Position */
#define SYS_PA_L_MFP_PA6_MFP_Msk    (0xFUL<<SYS_PA_L_MFP_PA6_MFP_Pos)                    /*!< GCR PA_L_MFP: PA6_MFP Mask */

#define SYS_PA_L_MFP_PA5_MFP_Pos      20                                                 /*!< GCR PA_L_MFP: PA5_MFP Position */
#define SYS_PA_L_MFP_PA5_MFP_Msk    (0xFUL<<SYS_PA_L_MFP_PA5_MFP_Pos)                    /*!< GCR PA_L_MFP: PA5_MFP Mask */

#define SYS_PA_L_MFP_PA4_MFP_Pos     16                                                  /*!< GCR PA_L_MFP: PA4_MFP Position */
#define SYS_PA_L_MFP_PA4_MFP_Msk    (0xFUL<<SYS_PA_L_MFP_PA4_MFP_Pos)                    /*!< GCR PA_L_MFP: PA4_MFP Mask */

#define SYS_PA_L_MFP_PA3_MFP_Pos     12                                                  /*!< GCR PA_L_MFP: PA3_MFP Position */
#define SYS_PA_L_MFP_PA3_MFP_Msk    (0xFUL<<SYS_PA_L_MFP_PA3_MFP_Pos)                    /*!< GCR PA_L_MFP: PA3_MFP Mask */

#define SYS_PA_L_MFP_PA2_MFP_Pos     8                                                   /*!< GCR PA_L_MFP: PA2_MFP Position */
#define SYS_PA_L_MFP_PA2_MFP_Msk    (0xFUL<<SYS_PA_L_MFP_PA2_MFP_Pos)                    /*!< GCR PA_L_MFP: PA2_MFP Mask */

#define SYS_PA_L_MFP_PA1_MFP_Pos     4                                                   /*!< GCR PA_L_MFP: PA1_MFP Position */
#define SYS_PA_L_MFP_PA1_MFP_Msk    (0xFUL<<SYS_PA_L_MFP_PA1_MFP_Pos)                    /*!< GCR PA_L_MFP: PA1_MFP Mask */

#define SYS_PA_L_MFP_PA0_MFP_Pos     0                                                   /*!< GCR PA_L_MFP: PA0_MFP Position */
#define SYS_PA_L_MFP_PA0_MFP_Msk    (0xFUL<<SYS_PA_L_MFP_PA0_MFP_Pos)                    /*!< GCR PA_L_MFP: PA0_MFP Mask */

/* SYS PA_H_MFP Bit Field Definitions */
#define SYS_PA_H_MFP_PA15_MFP_Pos     28                                                 /*!< GCR PA_H_MFP: PA15_MFP Position */
#define SYS_PA_H_MFP_PA15_MFP_Msk    (0xFUL<<SYS_PA_H_MFP_PA15_MFP_Pos)                  /*!< GCR PA_H_MFP: PA15_MFP Mask */

#define SYS_PA_H_MFP_PA14_MFP_Pos     24                                                 /*!< GCR PA_H_MFP: PA14_MFP Position */
#define SYS_PA_H_MFP_PA14_MFP_Msk    (0xFUL<<SYS_PA_H_MFP_PA14_MFP_Pos)                  /*!< GCR PA_H_MFP: PA14_MFP Mask */

#define SYS_PA_H_MFP_PA13_MFP_Pos     20                                                 /*!< GCR PA_H_MFP: PA13_MFP Position */
#define SYS_PA_H_MFP_PA13_MFP_Msk    (0xFUL<<SYS_PA_H_MFP_PA13_MFP_Pos)                  /*!< GCR PA_H_MFP: PA13_MFP Mask */

#define SYS_PA_H_MFP_PA12_MFP_Pos     16                                                 /*!< GCR PA_H_MFP: PA12_MFP Position */
#define SYS_PA_H_MFP_PA12_MFP_Msk    (0xFUL<<SYS_PA_H_MFP_PA12_MFP_Pos)                  /*!< GCR PA_H_MFP: PA12_MFP Mask */

#define SYS_PA_H_MFP_PA11_MFP_Pos     12                                                 /*!< GCR PA_H_MFP: PA11_MFP Position */
#define SYS_PA_H_MFP_PA11_MFP_Msk    (0xFUL<<SYS_PA_H_MFP_PA11_MFP_Pos)                  /*!< GCR PA_H_MFP: PA11_MFP Mask */

#define SYS_PA_H_MFP_PA10_MFP_Pos     8                                                  /*!< GCR PA_H_MFP: PA10_MFP Position */
#define SYS_PA_H_MFP_PA10_MFP_Msk    (0xFUL<<SYS_PA_H_MFP_PA10_MFP_Pos)                  /*!< GCR PA_H_MFP: PA10_MFP Mask */

#define SYS_PA_H_MFP_PA9_MFP_Pos     4                                                   /*!< GCR PA_H_MFP: PA9_MFP Position */
#define SYS_PA_H_MFP_PA9_MFP_Msk    (0xFUL<<SYS_PA_H_MFP_PA9_MFP_Pos)                    /*!< GCR PA_H_MFP: PA9_MFP Mask */

#define SYS_PA_H_MFP_PA8_MFP_Pos     0                                                   /*!< GCR PA_H_MFP: PA8_MFP Position */
#define SYS_PA_H_MFP_PA8_MFP_Msk    (0xFUL<<SYS_PA_H_MFP_PA8_MFP_Pos)                    /*!< GCR PA_H_MFP: PA8_MFP Mask */

/* SYS PB_L_MFP Bit Field Definitions */
#define SYS_PB_L_MFP_PB7_MFP_Pos      28                                                 /*!< GCR PB_L_MFP: PB7_MFP Position */
#define SYS_PB_L_MFP_PB7_MFP_Msk    (0xFUL<<SYS_PB_L_MFP_PB7_MFP_Pos)                    /*!< GCR PB_L_MFP: PB7_MFP Mask */

#define SYS_PB_L_MFP_PB6_MFP_Pos      24                                                 /*!< GCR PB_L_MFP: PB6_MFP Position */
#define SYS_PB_L_MFP_PB6_MFP_Msk    (0xFUL<<SYS_PB_L_MFP_PB6_MFP_Pos)                    /*!< GCR PB_L_MFP: PB6_MFP Mask */

#define SYS_PB_L_MFP_PB5_MFP_Pos      20                                                 /*!< GCR PB_L_MFP: PB5_MFP Position */
#define SYS_PB_L_MFP_PB5_MFP_Msk    (0xFUL<<SYS_PB_L_MFP_PB5_MFP_Pos)                    /*!< GCR PB_L_MFP: PB5_MFP Mask */

#define SYS_PB_L_MFP_PB4_MFP_Pos     16                                                  /*!< GCR PB_L_MFP: PB4_MFP Position */
#define SYS_PB_L_MFP_PB4_MFP_Msk    (0xFUL<<SYS_PB_L_MFP_PB4_MFP_Pos)                    /*!< GCR PB_L_MFP: PB4_MFP Mask */

#define SYS_PB_L_MFP_PB3_MFP_Pos     12                                                  /*!< GCR PB_L_MFP: PB3_MFP Position */
#define SYS_PB_L_MFP_PB3_MFP_Msk    (0xFUL<<SYS_PB_L_MFP_PB3_MFP_Pos)                    /*!< GCR PB_L_MFP: PB3_MFP Mask */

#define SYS_PB_L_MFP_PB2_MFP_Pos     8                                                   /*!< GCR PB_L_MFP: PB2_MFP Position */
#define SYS_PB_L_MFP_PB2_MFP_Msk    (0xFUL<<SYS_PB_L_MFP_PB2_MFP_Pos)                    /*!< GCR PB_L_MFP: PB2_MFP Mask */

#define SYS_PB_L_MFP_PB1_MFP_Pos     4                                                   /*!< GCR PB_L_MFP: PB1_MFP Position */
#define SYS_PB_L_MFP_PB1_MFP_Msk    (0xFUL<<SYS_PB_L_MFP_PB1_MFP_Pos)                    /*!< GCR PB_L_MFP: PB1_MFP Mask */

#define SYS_PB_L_MFP_PB0_MFP_Pos     0                                                   /*!< GCR PB_L_MFP: PB0_MFP Position */
#define SYS_PB_L_MFP_PB0_MFP_Msk    (0xFUL<<SYS_PB_L_MFP_PB0_MFP_Pos)                    /*!< GCR PB_L_MFP: PB0_MFP Mask */

/* SYS PB_H_MFP Bit Field Definitions */
#define SYS_PB_H_MFP_PB15_MFP_Pos     28                                                 /*!< GCR PB_H_MFP: PB15_MFP Position */
#define SYS_PB_H_MFP_PB15_MFP_Msk    (0xFUL<<SYS_PB_H_MFP_PB15_MFP_Pos)                  /*!< GCR PB_H_MFP: PB15_MFP Mask */

#define SYS_PB_H_MFP_PB14_MFP_Pos     24                                                 /*!< GCR PB_H_MFP: PB14_MFP Position */
#define SYS_PB_H_MFP_PB14_MFP_Msk    (0xFUL<<SYS_PB_H_MFP_PB14_MFP_Pos)                  /*!< GCR PB_H_MFP: PB14_MFP Mask */

#define SYS_PB_H_MFP_PB13_MFP_Pos     20                                                 /*!< GCR PB_H_MFP: PB13_MFP Position */
#define SYS_PB_H_MFP_PB13_MFP_Msk    (0xFUL<<SYS_PB_H_MFP_PB13_MFP_Pos)                  /*!< GCR PB_H_MFP: PB13_MFP Mask */

#define SYS_PB_H_MFP_PB12_MFP_Pos     16                                                 /*!< GCR PB_H_MFP: PB12_MFP Position */
#define SYS_PB_H_MFP_PB12_MFP_Msk    (0xFUL<<SYS_PB_H_MFP_PB12_MFP_Pos)                  /*!< GCR PB_H_MFP: PB12_MFP Mask */

#define SYS_PB_H_MFP_PB11_MFP_Pos     12                                                 /*!< GCR PB_H_MFP: PB11_MFP Position */
#define SYS_PB_H_MFP_PB11_MFP_Msk    (0xFUL<<SYS_PB_H_MFP_PB11_MFP_Pos)                  /*!< GCR PB_H_MFP: PB11_MFP Mask */

#define SYS_PB_H_MFP_PB10_MFP_Pos     8                                                  /*!< GCR PB_H_MFP: PB10_MFP Position */
#define SYS_PB_H_MFP_PB10_MFP_Msk    (0xFUL<<SYS_PB_H_MFP_PB10_MFP_Pos)                  /*!< GCR PB_H_MFP: PB10_MFP Mask */

#define SYS_PB_H_MFP_PB9_MFP_Pos     4                                                   /*!< GCR PB_H_MFP: PB9_MFP Position */
#define SYS_PB_H_MFP_PB9_MFP_Msk    (0xFUL<<SYS_PB_H_MFP_PB9_MFP_Pos)                    /*!< GCR PB_H_MFP: PB9_MFP Mask */

#define SYS_PB_H_MFP_PB8_MFP_Pos     0                                                   /*!< GCR PB_H_MFP: PB8_MFP Position */
#define SYS_PB_H_MFP_PB8_MFP_Msk    (0xFUL<<SYS_PB_H_MFP_PB8_MFP_Pos)                    /*!< GCR PB_H_MFP: PB8_MFP Mask */

/* SYS PC_L_MFP Bit Field Definitions */
#define SYS_PC_L_MFP_PC7_MFP_Pos      28                                                 /*!< GCR PC_L_MFP: PC7_MFP Position */
#define SYS_PC_L_MFP_PC7_MFP_Msk    (0xFUL<<SYS_PC_L_MFP_PC7_MFP_Pos)                    /*!< GCR PC_L_MFP: PC7_MFP Mask */

#define SYS_PC_L_MFP_PC6_MFP_Pos      24                                                 /*!< GCR PC_L_MFP: PC6_MFP Position */
#define SYS_PC_L_MFP_PC6_MFP_Msk    (0xFUL<<SYS_PC_L_MFP_PC6_MFP_Pos)                    /*!< GCR PC_L_MFP: PC6_MFP Mask */

#define SYS_PC_L_MFP_PC5_MFP_Pos      20                                                 /*!< GCR PC_L_MFP: PC5_MFP Position */
#define SYS_PC_L_MFP_PC5_MFP_Msk    (0xFUL<<SYS_PC_L_MFP_PC5_MFP_Pos)                    /*!< GCR PC_L_MFP: PC5_MFP Mask */

#define SYS_PC_L_MFP_PC4_MFP_Pos     16                                                  /*!< GCR PC_L_MFP: PC4_MFP Position */
#define SYS_PC_L_MFP_PC4_MFP_Msk    (0xFUL<<SYS_PC_L_MFP_PC4_MFP_Pos)                    /*!< GCR PC_L_MFP: PC4_MFP Mask */

#define SYS_PC_L_MFP_PC3_MFP_Pos     12                                                  /*!< GCR PC_L_MFP: PC3_MFP Position */
#define SYS_PC_L_MFP_PC3_MFP_Msk    (0xFUL<<SYS_PC_L_MFP_PC3_MFP_Pos)                    /*!< GCR PC_L_MFP: PC3_MFP Mask */

#define SYS_PC_L_MFP_PC2_MFP_Pos     8                                                   /*!< GCR PC_L_MFP: PC2_MFP Position */
#define SYS_PC_L_MFP_PC2_MFP_Msk    (0xFUL<<SYS_PC_L_MFP_PC2_MFP_Pos)                    /*!< GCR PC_L_MFP: PC2_MFP Mask */

#define SYS_PC_L_MFP_PC1_MFP_Pos     4                                                   /*!< GCR PC_L_MFP: PC1_MFP Position */
#define SYS_PC_L_MFP_PC1_MFP_Msk    (0xFUL<<SYS_PC_L_MFP_PC1_MFP_Pos)                    /*!< GCR PC_L_MFP: PC1_MFP Mask */

#define SYS_PC_L_MFP_PC0_MFP_Pos     0                                                   /*!< GCR PC_L_MFP: PC0_MFP Position */
#define SYS_PC_L_MFP_PC0_MFP_Msk    (0xFUL<<SYS_PC_L_MFP_PC0_MFP_Pos)                    /*!< GCR PC_L_MFP: PC0_MFP Mask */

/* SYS PC_H_MFP Bit Field Definitions */
#define SYS_PC_H_MFP_PC15_MFP_Pos     28                                                 /*!< GCR PC_H_MFP: PC15_MFP Position */
#define SYS_PC_H_MFP_PC15_MFP_Msk    (0xFUL<<SYS_PC_H_MFP_PC15_MFP_Pos)                  /*!< GCR PC_H_MFP: PC15_MFP Mask */

#define SYS_PC_H_MFP_PC14_MFP_Pos     24                                                 /*!< GCR PC_H_MFP: PC14_MFP Position */
#define SYS_PC_H_MFP_PC14_MFP_Msk    (0xFUL<<SYS_PC_H_MFP_PC14_MFP_Pos)                  /*!< GCR PC_H_MFP: PC14_MFP Mask */

#define SYS_PC_H_MFP_PC13_MFP_Pos     20                                                 /*!< GCR PC_H_MFP: PC13_MFP Position */
#define SYS_PC_H_MFP_PC13_MFP_Msk    (0xFUL<<SYS_PC_H_MFP_PC13_MFP_Pos)                  /*!< GCR PC_H_MFP: PC13_MFP Mask */

#define SYS_PC_H_MFP_PC12_MFP_Pos     16                                                 /*!< GCR PC_H_MFP: PC12_MFP Position */
#define SYS_PC_H_MFP_PC12_MFP_Msk    (0xFUL<<SYS_PC_H_MFP_PC12_MFP_Pos)                  /*!< GCR PC_H_MFP: PC12_MFP Mask */

#define SYS_PC_H_MFP_PC11_MFP_Pos     12                                                 /*!< GCR PC_H_MFP: PC11_MFP Position */
#define SYS_PC_H_MFP_PC11_MFP_Msk    (0xFUL<<SYS_PC_H_MFP_PC11_MFP_Pos)                  /*!< GCR PC_H_MFP: PC11_MFP Mask */

#define SYS_PC_H_MFP_PC10_MFP_Pos     8                                                  /*!< GCR PC_H_MFP: PC10_MFP Position */
#define SYS_PC_H_MFP_PC10_MFP_Msk    (0xFUL<<SYS_PC_H_MFP_PC10_MFP_Pos)                  /*!< GCR PC_H_MFP: PC10_MFP Mask */

#define SYS_PC_H_MFP_PC9_MFP_Pos     4                                                   /*!< GCR PC_H_MFP: PC9_MFP Position */
#define SYS_PC_H_MFP_PC9_MFP_Msk    (0xFUL<<SYS_PC_H_MFP_PC9_MFP_Pos)                    /*!< GCR PC_H_MFP: PC9_MFP Mask */

#define SYS_PC_H_MFP_PC8_MFP_Pos     0                                                   /*!< GCR PC_H_MFP: PC8_MFP Position */
#define SYS_PC_H_MFP_PC8_MFP_Msk    (0xFUL<<SYS_PC_H_MFP_PC8_MFP_Pos)                    /*!< GCR PC_H_MFP: PC8_MFP Mask */


/* SYS PD_L_MFP Bit Field Definitions */
#define SYS_PD_L_MFP_PD7_MFP_Pos      28                                                 /*!< GCR PD_L_MFP: PD7_MFP Position */
#define SYS_PD_L_MFP_PD7_MFP_Msk    (0xFUL<<SYS_PD_L_MFP_PD7_MFP_Pos)                    /*!< GCR PD_L_MFP: PD7_MFP Mask */

#define SYS_PD_L_MFP_PD6_MFP_Pos      24                                                 /*!< GCR PD_L_MFP: PD6_MFP Position */
#define SYS_PD_L_MFP_PD6_MFP_Msk    (0xFUL<<SYS_PD_L_MFP_PD6_MFP_Pos)                    /*!< GCR PD_L_MFP: PD6_MFP Mask */

#define SYS_PD_L_MFP_PD5_MFP_Pos      20                                                 /*!< GCR PD_L_MFP: PD5_MFP Position */
#define SYS_PD_L_MFP_PD5_MFP_Msk    (0xFUL<<SYS_PD_L_MFP_PD5_MFP_Pos)                    /*!< GCR PD_L_MFP: PD5_MFP Mask */

#define SYS_PD_L_MFP_PD4_MFP_Pos     16                                                  /*!< GCR PD_L_MFP: PD4_MFP Position */
#define SYS_PD_L_MFP_PD4_MFP_Msk    (0xFUL<<SYS_PD_L_MFP_PD4_MFP_Pos)                    /*!< GCR PD_L_MFP: PD4_MFP Mask */

#define SYS_PD_L_MFP_PD3_MFP_Pos     12                                                  /*!< GCR PD_L_MFP: PD3_MFP Position */
#define SYS_PD_L_MFP_PD3_MFP_Msk    (0xFUL<<SYS_PD_L_MFP_PD3_MFP_Pos)                    /*!< GCR PD_L_MFP: PD3_MFP Mask */

#define SYS_PD_L_MFP_PD2_MFP_Pos     8                                                   /*!< GCR PD_L_MFP: PD2_MFP Position */
#define SYS_PD_L_MFP_PD2_MFP_Msk    (0xFUL<<SYS_PD_L_MFP_PD2_MFP_Pos)                    /*!< GCR PD_L_MFP: PD2_MFP Mask */

#define SYS_PD_L_MFP_PD1_MFP_Pos     4                                                   /*!< GCR PD_L_MFP: PD1_MFP Position */
#define SYS_PD_L_MFP_PD1_MFP_Msk    (0xFUL<<SYS_PD_L_MFP_PD1_MFP_Pos)                    /*!< GCR PD_L_MFP: PD1_MFP Mask */

#define SYS_PD_L_MFP_PD0_MFP_Pos     0                                                   /*!< GCR PD_L_MFP: PD0_MFP Position */
#define SYS_PD_L_MFP_PD0_MFP_Msk    (0xFUL<<SYS_PD_L_MFP_PD0_MFP_Pos)                    /*!< GCR PD_L_MFP: PD0_MFP Mask */

/* SYS PD_H_MFP Bit Field Definitions */
#define SYS_PD_H_MFP_PD15_MFP_Pos     28                                                 /*!< GCR PD_H_MFP: PD15_MFP Position */
#define SYS_PD_H_MFP_PD15_MFP_Msk    (0xFUL<<SYS_PD_H_MFP_PD15_MFP_Pos)                  /*!< GCR PD_H_MFP: PD15_MFP Mask */

#define SYS_PD_H_MFP_PD14_MFP_Pos     24                                                 /*!< GCR PD_H_MFP: PD14_MFP Position */
#define SYS_PD_H_MFP_PD14_MFP_Msk    (0xFUL<<SYS_PD_H_MFP_PD14_MFP_Pos)                  /*!< GCR PD_H_MFP: PD14_MFP Mask */

#define SYS_PD_H_MFP_PD13_MFP_Pos     20                                                 /*!< GCR PD_H_MFP: PD13_MFP Position */
#define SYS_PD_H_MFP_PD13_MFP_Msk    (0xFUL<<SYS_PD_H_MFP_PD13_MFP_Pos)                  /*!< GCR PD_H_MFP: PD13_MFP Mask */

#define SYS_PD_H_MFP_PD12_MFP_Pos     16                                                 /*!< GCR PD_H_MFP: PD12_MFP Position */
#define SYS_PD_H_MFP_PD12_MFP_Msk    (0xFUL<<SYS_PD_H_MFP_PD12_MFP_Pos)                  /*!< GCR PD_H_MFP: PD12_MFP Mask */

#define SYS_PD_H_MFP_PD11_MFP_Pos     12                                                 /*!< GCR PD_H_MFP: PD11_MFP Position */
#define SYS_PD_H_MFP_PD11_MFP_Msk    (0xFUL<<SYS_PD_H_MFP_PD11_MFP_Pos)                  /*!< GCR PD_H_MFP: PD11_MFP Mask */

#define SYS_PD_H_MFP_PD10_MFP_Pos     8                                                  /*!< GCR PD_H_MFP: PD10_MFP Position */
#define SYS_PD_H_MFP_PD10_MFP_Msk    (0xFUL<<SYS_PD_H_MFP_PD10_MFP_Pos)                  /*!< GCR PD_H_MFP: PD10_MFP Mask */

#define SYS_PD_H_MFP_PD9_MFP_Pos     4                                                   /*!< GCR PD_H_MFP: PD9_MFP Position */
#define SYS_PD_H_MFP_PD9_MFP_Msk    (0xFUL<<SYS_PD_H_MFP_PD9_MFP_Pos)                    /*!< GCR PD_H_MFP: PD9_MFP Mask */

#define SYS_PD_H_MFP_PD8_MFP_Pos     0                                                   /*!< GCR PD_H_MFP: PD8_MFP Position */
#define SYS_PD_H_MFP_PD8_MFP_Msk    (0xFUL<<SYS_PD_H_MFP_PD8_MFP_Pos)                    /*!< GCR PD_H_MFP: PD8_MFP Mask */


/* SYS PE_L_MFP Bit Field Definitions */
#define SYS_PE_L_MFP_PE7_MFP_Pos      28                                                 /*!< GCR PE_L_MFP: PE7_MFP Position */
#define SYS_PE_L_MFP_PE7_MFP_Msk    (0xFUL<<SYS_PE_L_MFP_PE7_MFP_Pos)                    /*!< GCR PE_L_MFP: PE7_MFP Mask */

#define SYS_PE_L_MFP_PE6_MFP_Pos      24                                                 /*!< GCR PE_L_MFP: PE6_MFP Position */
#define SYS_PE_L_MFP_PE6_MFP_Msk    (0xFUL<<SYS_PE_L_MFP_PE6_MFP_Pos)                    /*!< GCR PE_L_MFP: PE6_MFP Mask */

#define SYS_PE_L_MFP_PE5_MFP_Pos      20                                                 /*!< GCR PE_L_MFP: PE5_MFP Position */
#define SYS_PE_L_MFP_PE5_MFP_Msk    (0xFUL<<SYS_PE_L_MFP_PE5_MFP_Pos)                    /*!< GCR PE_L_MFP: PE5_MFP Mask */

#define SYS_PE_L_MFP_PE4_MFP_Pos     16                                                  /*!< GCR PE_L_MFP: PE4_MFP Position */
#define SYS_PE_L_MFP_PE4_MFP_Msk    (0xFUL<<SYS_PE_L_MFP_PE4_MFP_Pos)                    /*!< GCR PE_L_MFP: PE4_MFP Mask */

#define SYS_PE_L_MFP_PE3_MFP_Pos     12                                                  /*!< GCR PE_L_MFP: PE3_MFP Position */
#define SYS_PE_L_MFP_PE3_MFP_Msk    (0xFUL<<SYS_PE_L_MFP_PE3_MFP_Pos)                    /*!< GCR PE_L_MFP: PE3_MFP Mask */

#define SYS_PE_L_MFP_PE2_MFP_Pos     8                                                   /*!< GCR PE_L_MFP: PE2_MFP Position */
#define SYS_PE_L_MFP_PE2_MFP_Msk    (0xFUL<<SYS_PE_L_MFP_PE2_MFP_Pos)                    /*!< GCR PE_L_MFP: PE2_MFP Mask */

#define SYS_PE_L_MFP_PE1_MFP_Pos     4                                                   /*!< GCR PE_L_MFP: PE1_MFP Position */
#define SYS_PE_L_MFP_PE1_MFP_Msk    (0xFUL<<SYS_PE_L_MFP_PE1_MFP_Pos)                    /*!< GCR PE_L_MFP: PE1_MFP Mask */

#define SYS_PE_L_MFP_PE0_MFP_Pos     0                                                   /*!< GCR PE_L_MFP: PE0_MFP Position */
#define SYS_PE_L_MFP_PE0_MFP_Msk    (0xFUL<<SYS_PE_L_MFP_PE0_MFP_Pos)                    /*!< GCR PE_L_MFP: PE0_MFP Mask */

/* SYS PE_H_MFP Bit Field Definitions */
#define SYS_PE_H_MFP_PE15_MFP_Pos     28                                                 /*!< GCR PE_H_MFP: PE15_MFP Position */
#define SYS_PE_H_MFP_PE15_MFP_Msk    (0xFUL<<SYS_PE_H_MFP_PE15_MFP_Pos)                  /*!< GCR PE_H_MFP: PE15_MFP Mask */

#define SYS_PE_H_MFP_PE14_MFP_Pos     24                                                 /*!< GCR PE_H_MFP: PE14_MFP Position */
#define SYS_PE_H_MFP_PE14_MFP_Msk    (0xFUL<<SYS_PE_H_MFP_PE14_MFP_Pos)                  /*!< GCR PE_H_MFP: PE14_MFP Mask */

#define SYS_PE_H_MFP_PE13_MFP_Pos     20                                                 /*!< GCR PE_H_MFP: PE13_MFP Position */
#define SYS_PE_H_MFP_PE13_MFP_Msk    (0xFUL<<SYS_PE_H_MFP_PE13_MFP_Pos)                  /*!< GCR PE_H_MFP: PE13_MFP Mask */

#define SYS_PE_H_MFP_PE12_MFP_Pos     16                                                 /*!< GCR PE_H_MFP: PE12_MFP Position */
#define SYS_PE_H_MFP_PE12_MFP_Msk    (0xFUL<<SYS_PE_H_MFP_PE12_MFP_Pos)                  /*!< GCR PE_H_MFP: PE12_MFP Mask */

#define SYS_PE_H_MFP_PE11_MFP_Pos     12                                                 /*!< GCR PE_H_MFP: PE11_MFP Position */
#define SYS_PE_H_MFP_PE11_MFP_Msk    (0xFUL<<SYS_PE_H_MFP_PE11_MFP_Pos)                  /*!< GCR PE_H_MFP: PE11_MFP Mask */

#define SYS_PE_H_MFP_PE10_MFP_Pos     8                                                  /*!< GCR PE_H_MFP: PE10_MFP Position */
#define SYS_PE_H_MFP_PE10_MFP_Msk    (0xFUL<<SYS_PE_H_MFP_PE10_MFP_Pos)                  /*!< GCR PE_H_MFP: PE10_MFP Mask */

#define SYS_PE_H_MFP_PE9_MFP_Pos     4                                                   /*!< GCR PE_H_MFP: PE9_MFP Position */
#define SYS_PE_H_MFP_PE9_MFP_Msk    (0xFUL<<SYS_PE_H_MFP_PE9_MFP_Pos)                    /*!< GCR PE_H_MFP: PE9_MFP Mask */

#define SYS_PE_H_MFP_PE8_MFP_Pos     0                                                   /*!< GCR PE_H_MFP: PE8_MFP Position */
#define SYS_PE_H_MFP_PE8_MFP_Msk    (0xFUL<<SYS_PE_H_MFP_PE8_MFP_Pos)                    /*!< GCR PE_H_MFP: PE8_MFP Mask */

/* SYS PF_L_MFP Bit Field Definitions */
#define SYS_PF_L_MFP_PF7_MFP_Pos      28                                                 /*!< GCR PF_L_MFP: PF7_MFP Position */
#define SYS_PF_L_MFP_PF7_MFP_Msk    (0xFUL<<SYS_PF_L_MFP_PF7_MFP_Pos)                    /*!< GCR PF_L_MFP: PF7_MFP Mask */

#define SYS_PF_L_MFP_PF6_MFP_Pos      24                                                 /*!< GCR PF_L_MFP: PF6_MFP Position */
#define SYS_PF_L_MFP_PF6_MFP_Msk    (0xFUL<<SYS_PF_L_MFP_PF6_MFP_Pos)                    /*!< GCR PF_L_MFP: PF6_MFP Mask */

#define SYS_PF_L_MFP_PF5_MFP_Pos      20                                                 /*!< GCR PF_L_MFP: PF5_MFP Position */
#define SYS_PF_L_MFP_PF5_MFP_Msk    (0xFUL<<SYS_PF_L_MFP_PF5_MFP_Pos)                    /*!< GCR PF_L_MFP: PF5_MFP Mask */

#define SYS_PF_L_MFP_PF4_MFP_Pos     16                                                  /*!< GCR PF_L_MFP: PF4_MFP Position */
#define SYS_PF_L_MFP_PF4_MFP_Msk    (0xFUL<<SYS_PF_L_MFP_PF4_MFP_Pos)                    /*!< GCR PF_L_MFP: PF4_MFP Mask */

#define SYS_PF_L_MFP_PF3_MFP_Pos     12                                                  /*!< GCR PF_L_MFP: PF3_MFP Position */
#define SYS_PF_L_MFP_PF3_MFP_Msk    (0xFUL<<SYS_PF_L_MFP_PF3_MFP_Pos)                    /*!< GCR PF_L_MFP: PF3_MFP Mask */

#define SYS_PF_L_MFP_PF2_MFP_Pos     8                                                   /*!< GCR PF_L_MFP: PF2_MFP Position */
#define SYS_PF_L_MFP_PF2_MFP_Msk    (0xFUL<<SYS_PF_L_MFP_PF2_MFP_Pos)                    /*!< GCR PF_L_MFP: PF2_MFP Mask */

#define SYS_PF_L_MFP_PF1_MFP_Pos     4                                                   /*!< GCR PF_L_MFP: PF1_MFP Position */
#define SYS_PF_L_MFP_PF1_MFP_Msk    (0xFUL<<SYS_PF_L_MFP_PF1_MFP_Pos)                    /*!< GCR PF_L_MFP: PF1_MFP Mask */

#define SYS_PF_L_MFP_PF0_MFP_Pos     0                                                   /*!< GCR PF_L_MFP: PF0_MFP Position */
#define SYS_PF_L_MFP_PF0_MFP_Msk    (0xFUL<<SYS_PF_L_MFP_PF0_MFP_Pos)                    /*!< GCR PF_L_MFP: PF0_MFP Mask */

/* SYS PORCTL Bit Field Definitions */
#define SYS_PORCTL_POR_DIS_CODE_Pos     0                                                /*!< GCR PORCTL: POR_DIS_CODE Position */
#define SYS_PORCTL_POR_DIS_CODE_Msk    (0xFFFFUL<<SYS_PORCTL_POR_DIS_CODE_Pos)           /*!< GCR PORCTL: POR_DIS_CODE Mask */

/* SYS BODCTL Bit Field Definitions */
#define SYS_BODCTL_BOD25_INT_EN_Pos     10                                               /*!< GCR BODCTL: BOD25_INT_EN Position */
#define SYS_BODCTL_BOD25_INT_EN_Msk    (0x1UL<<SYS_BODCTL_BOD25_INT_EN_Pos)              /*!< GCR BODCTL: BOD25_INT_EN Mask */

#define SYS_BODCTL_BOD20_INT_EN_Pos     9                                                /*!< GCR BODCTL: BOD20_INT_EN Position */
#define SYS_BODCTL_BOD20_INT_EN_Msk    (0x1UL<<SYS_BODCTL_BOD20_INT_EN_Pos)              /*!< GCR BODCTL: BOD20_INT_EN Mask */

#define SYS_BODCTL_BOD17_INT_EN_Pos     8                                                /*!< GCR BODCTL: BOD17_INT_EN Position */
#define SYS_BODCTL_BOD17_INT_EN_Msk    (0x1UL<<SYS_BODCTL_BOD17_INT_EN_Pos)              /*!< GCR BODCTL: BOD17_INT_EN Mask */

#define SYS_BODCTL_BOD25_RST_EN_Pos     6                                                /*!< GCR BODCTL: BOD25_RST_EN Position */
#define SYS_BODCTL_BOD25_RST_EN_Msk    (0x1UL<<SYS_BODCTL_BOD25_RST_EN_Pos)              /*!< GCR BODCTL: BOD25_RST_EN Mask */

#define SYS_BODCTL_BOD20_RST_EN_Pos     5                                                /*!< GCR BODCTL: BOD20_RST_EN Position */
#define SYS_BODCTL_BOD20_RST_EN_Msk    (0x1UL<<SYS_BODCTL_BOD20_RST_EN_Pos)              /*!< GCR BODCTL: BOD20_RST_EN Mask */

#define SYS_BODCTL_BOD17_RST_EN_Pos     4                                                /*!< GCR BODCTL: BOD17_RST_EN Position */
#define SYS_BODCTL_BOD17_RST_EN_Msk    (0x1UL<<SYS_BODCTL_BOD17_RST_EN_Pos)              /*!< GCR BODCTL: BOD17_RST_EN Mask */

#define SYS_BODCTL_BOD25_EN_Pos     2                                                    /*!< GCR BODCTL: BOD25_EN Position */
#define SYS_BODCTL_BOD25_EN_Msk    (0x1UL<<SYS_BODCTL_BOD25_EN_Pos)                      /*!< GCR BODCTL: BOD25_EN Mask */

#define SYS_BODCTL_BOD20_EN_Pos     1                                                    /*!< GCR BODCTL: BOD20_EN Position */
#define SYS_BODCTL_BOD20_EN_Msk    (0x1UL<<SYS_BODCTL_BOD20_EN_Pos)                      /*!< GCR BODCTL: BOD20_EN Mask */

#define SYS_BODCTL_BOD17_EN_Pos     0                                                    /*!< GCR BODCTL: BOD17_EN Position */
#define SYS_BODCTL_BOD17_EN_Msk    (0x1UL<<SYS_BODCTL_BOD17_EN_Pos)                      /*!< GCR BODCTL: BOD17_EN Mask */

/* SYS BODSTS Bit Field Definitions */
#define SYS_BODSTS_BOD25_OUT_Pos     3                                                  /*!< GCR BODSTS: BOD25_OUT Position */
#define SYS_BODSTS_BOD25_OUT_Msk    (0x1UL<<SYS_BODSTS_BOD25_OUT_Pos)                  /*!< GCR BODSTS: BOD25_OUT Mask */

#define SYS_BODSTS_BOD20_OUT_Pos     2                                                  /*!< GCR BODSTS: BOD20_OUT Position */
#define SYS_BODSTS_BOD20_OUT_Msk    (0x1UL<<SYS_BODSTS_BOD20_OUT_Pos)                  /*!< GCR BODSTS: BOD20_OUT Mask */

#define SYS_BODSTS_BOD17_OUT_Pos     1                                                  /*!< GCR BODSTS: BOD17_OUT Position */
#define SYS_BODSTS_BOD17_OUT_Msk    (0x1UL<<SYS_BODSTS_BOD17_OUT_Pos)                  /*!< GCR BODSTS: BOD17_OUT Mask */

#define SYS_BODSTS_BOD_INT_Pos     0                                                     /*!< GCR BODSTS: BOD_INT Position */
#define SYS_BODSTS_BOD_INT_Msk    (0x1UL<<SYS_BODSTS_BOD_INT_Pos)                        /*!< GCR BODSTS: BOD_INT Mask */

/* SYS Int_VREFCTL Bit Field Definitions */
#define SYS_Int_VREFCTL_VREF_TRIM_Pos     8                                              /*!< GCR Int_VREFCTL: VREF_TRIM Position */
#define SYS_Int_VREFCTL_VREF_TRIM_Msk    (0xFUL<<SYS_Int_VREFCTL_VREF_TRIM_Pos)          /*!< GCR Int_VREFCTL: VREF_TRIM Mask */

#define SYS_Int_VREFCTL_BGP_TEST_Pos     5                                               /*!< GCR Int_VREFCTL: BGP_TEST Position */
#define SYS_Int_VREFCTL_BGP_TEST_Msk    (0x1UL<<SYS_Int_VREFCTL_BGP_TEST_Pos)            /*!< GCR Int_VREFCTL: BGP_TEST Mask */

#define SYS_Int_VREFCTL_BGP_MODE_Pos     4                                               /*!< GCR Int_VREFCTL: BGP_MODE Position */
#define SYS_Int_VREFCTL_BGP_MODE_Msk    (0x1UL<<SYS_Int_VREFCTL_BGP_MODE_Pos)            /*!< GCR Int_VREFCTL: BGP_MODE Mask */

#define SYS_Int_VREFCTL_EXT_MODE_Pos     3                                               /*!< GCR Int_VREFCTL: EXT_MODE Position */
#define SYS_Int_VREFCTL_EXT_MODE_Msk    (0x1UL<<SYS_Int_VREFCTL_EXT_MODE_Pos)            /*!< GCR Int_VREFCTL: EXT_MODE Mask */

#define SYS_Int_VREFCTL_SEL25_Pos     2                                                  /*!< GCR Int_VREFCTL: SEL25 Position */
#define SYS_Int_VREFCTL_SEL25_Msk    (0x3UL<<SYS_Int_VREFCTL_SEL25_Pos)                  /*!< GCR Int_VREFCTL: SEL25 Mask */

#define SYS_Int_VREFCTL_REG_EN_Pos     1                                                 /*!< GCR Int_VREFCTL: REG_EN Position */
#define SYS_Int_VREFCTL_REG_EN_Msk    (0x1UL<<SYS_Int_VREFCTL_REG_EN_Pos)                /*!< GCR Int_VREFCTL: REG_EN Mask */

#define SYS_Int_VREFCTL_BGP_EN_Pos     0                                                 /*!< GCR Int_VREFCTL: BGP_EN Position */
#define SYS_Int_VREFCTL_BGP_EN_Msk    (0x1UL<<SYS_Int_VREFCTL_BGP_EN_Pos)                /*!< GCR Int_VREFCTL: BGP_EN Mask */

/* SYS IRCTRIMCTL Bit Field Definitions */
#define SYS_IRCTRIMCTL_TRIM_RETRY_CNT_Pos     6                                          /*!< GCR IRCTRIMCTL: TRIM_RETRY_CNT Position */
#define SYS_IRCTRIMCTL_TRIM_RETRY_CNT_Msk    (0x3UL<<SYS_IRCTRIMCTL_TRIM_RETRY_CNT_Pos)  /*!< GCR IRCTRIMCTL: TRIM_RETRY_CNT Mask */

#define SYS_IRCTRIMCTL_TRIM_LOOP_Pos     4                                               /*!< GCR IRCTRIMCTL: TRIM_LOOP Position */
#define SYS_IRCTRIMCTL_TRIM_LOOP_Msk    (0x3UL<<SYS_IRCTRIMCTL_TRIM_LOOP_Pos)            /*!< GCR IRCTRIMCTL: TRIM_LOOP Mask */

#define SYS_IRCTRIMCTL_TRIM_SEL_Pos     0                                                /*!< GCR IRCTRIMCTL: TRIM_SEL Position */
#define SYS_IRCTRIMCTL_TRIM_SEL_Msk    (0x3UL<<SYS_IRCTRIMCTL_TRIM_SEL_Pos)              /*!< GCR IRCTRIMCTL: TRIM_SEL Mask */

/* SYS IRCTRIMIEN Bit Field Definitions */
#define SYS_IRCTRIMIEN_32K_ERR_IEN_Pos     2                                             /*!< GCR IRCTRIMIEN: 32K_ERR_IEN Position */
#define SYS_IRCTRIMIEN_32K_ERR_IEN_Msk    (0x1UL<<SYS_IRCTRIMIEN_32K_ERR_IEN_Pos)        /*!< GCR IRCTRIMIEN: 32K_ERR_IEN Mask */

#define SYS_IRCTRIMIEN_TRIM_FAIL_IEN_Pos     1                                           /*!< GCR IRCTRIMIEN: TRIM_FAIL_IEN Position */
#define SYS_IRCTRIMIEN_TRIM_FAIL_IEN_Msk    (0x1UL<<SYS_IRCTRIMIEN_TRIM_FAIL_IEN_Pos)    /*!< GCR IRCTRIMIEN: TRIM_FAIL_IEN Mask */

/* SYS IRCTRIMINT Bit Field Definitions */
#define SYS_IRCTRIMINT_32K_ERR_INT_Pos     2                                             /*!< GCR IRCTRIMINT: 32K_ERR_INT Position */
#define SYS_IRCTRIMINT_32K_ERR_INT_Msk    (0x1UL<<SYS_IRCTRIMINT_32K_ERR_INT_Pos)        /*!< GCR IRCTRIMINT: 32K_ERR_INT Mask */

#define SYS_IRCTRIMINT_TRIM_FAIL_INT_Pos     1                                           /*!< GCR IRCTRIMINT: TRIM_FAIL_INT Position */
#define SYS_IRCTRIMINT_TRIM_FAIL_INT_Msk    (0x1UL<<SYS_IRCTRIMINT_TRIM_FAIL_INT_Pos)    /*!< GCR IRCTRIMINT: TRIM_FAIL_INT Mask */

#define SYS_IRCTRIMINT_FREQ_LOCK_Pos     0                                               /*!< GCR IRCTRIMINT: FREQ_LOCK Position */
#define SYS_IRCTRIMINT_FREQ_LOCK_Msk    (0x1UL<<SYS_IRCTRIMINT_FREQ_LOCK_Pos)            /*!< GCR IRCTRIMINT: FREQ_LOCK Mask */

/* SYS RegLockAddr Bit Field Definitions */
#define SYS_RegLockAddr_RegUnLock_Pos     0                                              /*!< GCR RegLockAddr: RegUnLock Position */
#define SYS_RegLockAddr_RegUnLock_Msk    (0x1UL<<SYS_RegLockAddr_RegUnLock_Pos)          /*!< GCR RegLockAddr: RegUnLock Mask */


/*@}*/ /* end of group NANO100_SYS */

/*------------- Clock Control Register (CLK) -----------------------------*/
/** @addtogroup NANO100_CLK NANO100 Clock Control Register (CLK)
  Memory Mapped Structure for NANO100 Series Clock Controller
  @{
*/
/**
  * @brief CLK register map
  */
typedef struct {
    __IO uint32_t  PWRCTL;                     /*!< Offset: 0x0000   System Power Down Control Register                 */
    __IO uint32_t  AHBCLK;                     /*!< Offset: 0x0004   AHB Devices Clock Enable Control Register          */
    __IO uint32_t  APBCLK;                     /*!< Offset: 0x0008   APB Devices Clock Enable Control Register          */
    __IO uint32_t  CLKSTATUS;                  /*!< Offset: 0x000C   Clock Status Monitor Register                      */
    __IO uint32_t  CLKSEL0;                    /*!< Offset: 0x0010   Clock Source Select Control Register 0             */
    __IO uint32_t  CLKSEL1;                    /*!< Offset: 0x0014   Clock Source Select Control Register 1             */
    __IO uint32_t  CLKSEL2;                    /*!< Offset: 0x0018   Clock Source Select Control Register 2             */
    __IO uint32_t  CLKDIV0;                    /*!< Offset: 0x001C   Clock Divider Number Register    0                 */
    __IO uint32_t  CLKDIV1;                    /*!< Offset: 0x0020   Clock Divider Number Register    1                 */
    __IO uint32_t  PLLCTL;                     /*!< Offset: 0x0024   PLL Control Register                               */
    __IO uint32_t  FRQDIV;                     /*!< Offset: 0x0028   Frequency Divider Control Register                 */
    __IO uint32_t  MCLKO;                      /*!< Offset: 0x002C   Module Clock Output Register                       */
    __IO uint32_t  WK_INTSTS;                  /*!< Offset: 0x0030   Wake-up interrupt status Register                  */
} CLK_T;
/*@}*/ /* end of group NANO100_CLK */

/* CLK PWRCTL Bit Field Definitions */
#define CLK_PWRCTL_HXT_HF_ST_Pos     11                                                            /*!< CLK PWRCTL: HXT_HF_ST Position */
#define CLK_PWRCTL_HXT_HF_ST_Msk    (0x3UL<<CLK_PWRCTL_HXT_HF_ST_Pos)                              /*!< CLK PWRCTL: HXT_HF_ST Mask */

#define CLK_PWRCTL_LXT_SCNT_Pos     10                                                             /*!< CLK PWRCTL: LXT_SCNT Position */
#define CLK_PWRCTL_LXT_SCNT_Msk    (0x1UL<<CLK_PWRCTL_LXT_SCNT_Pos)                                /*!< CLK PWRCTL: LXT_SCNT Mask */

#define CLK_PWRCTL_HXT_GAIN_Pos     9                                                              /*!< CLK PWRCTL: HXT_GAIN Position */
#define CLK_PWRCTL_HXT_GAIN_Msk    (0x1UL<<CLK_PWRCTL_HXT_GAIN_Pos)                                /*!< CLK PWRCTL: HXT_GAIN Mask */

#define CLK_PWRCTL_HXT_SELXT_Pos     8                                                             /*!< CLK PWRCTL: HXT_SELXT Position */
#define CLK_PWRCTL_HXT_SELXT_Msk    (0x1UL<<CLK_PWRCTL_HXT_SELXT_Pos)                              /*!< CLK PWRCTL: HXT_SELXT Mask */

#define CLK_PWRCTL_PD_EN_Pos     6                                                                 /*!< CLK PWRCTL: PD_EN Position */
#define CLK_PWRCTL_PD_EN_Msk    (0x1UL<<CLK_PWRCTL_PD_EN_Pos)                                      /*!< CLK PWRCTL: PD_EN Mask */

#define CLK_PWRCTL_PD_WK_IE_Pos     5                                                              /*!< CLK PWRCTL: PD_WK_IE Position */
#define CLK_PWRCTL_PD_WK_IE_Msk    (0x1UL<<CLK_PWRCTL_PD_WK_IE_Pos)                                /*!< CLK PWRCTL: PD_WK_IE Mask */

#define CLK_PWRCTL_WK_DLY_Pos     4                                                                /*!< CLK PWRCTL: WK_DLY Position */
#define CLK_PWRCTL_WK_DLY_Msk    (0x1UL<<CLK_PWRCTL_WK_DLY_Pos)                                    /*!< CLK PWRCTL: WK_DLY Mask */

#define CLK_PWRCTL_LIRC_EN_Pos     3                                                               /*!< CLK PWRCTL: LIRC_EN Position */
#define CLK_PWRCTL_LIRC_EN_Msk    (0x1UL<<CLK_PWRCTL_LIRC_EN_Pos)                                  /*!< CLK PWRCTL: LIRC_EN Mask */

#define CLK_PWRCTL_HIRC_EN_Pos     2                                                               /*!< CLK PWRCTL: HIRC_EN Position */
#define CLK_PWRCTL_HIRC_EN_Msk    (0x1UL<<CLK_PWRCTL_HIRC_EN_Pos)                                  /*!< CLK PWRCTL: HIRC_EN Mask */

#define CLK_PWRCTL_LXT_EN_Pos     1                                                                /*!< CLK PWRCTL: LXT_EN Position */
#define CLK_PWRCTL_LXT_EN_Msk    (0x1UL<<CLK_PWRCTL_LXT_EN_Pos)                                    /*!< CLK PWRCTL: LXT_EN Mask */

#define CLK_PWRCTL_HXT_EN_Pos     0                                                                /*!< CLK PWRCTL: HXT_EN Position */
#define CLK_PWRCTL_HXT_EN_Msk    (0x1UL<<CLK_PWRCTL_HXT_EN_Pos)                                    /*!< CLK PWRCTL: HXT_EN Mask */

/* CLK AHBCLK Bit Field Definitions */
#define CLK_AHBCLK_TICK_EN_Pos     5                                                               /*!< CLK AHBCLK: TICK_EN Position */
#define CLK_AHBCLK_TICK_EN_Msk    (0x1UL<<CLK_AHBCLK_TICK_EN_Pos)                                  /*!< CLK AHBCLK: TICK_EN Mask */

#define CLK_AHBCLK_SRAM_EN_Pos     4                                                               /*!< CLK AHBCLK: SRAM_EN Position */
#define CLK_AHBCLK_SRAM_EN_Msk    (0x1UL<<CLK_AHBCLK_SRAM_EN_Pos)                                  /*!< CLK AHBCLK: SRAM_EN Mask */

#define CLK_AHBCLK_EBI_EN_Pos      3                                                                /*!< CLK AHBCLK: EBI_EN Position */
#define CLK_AHBCLK_EBI_EN_Msk     (0x1UL<<CLK_AHBCLK_EBI_EN_Pos)                                    /*!< CLK AHBCLK: EBI_EN Mask */

#define CLK_AHBCLK_ISP_EN_Pos      2                                                                /*!< CLK AHBCLK: ISP_EN Position */
#define CLK_AHBCLK_ISP_EN_Msk     (0x1UL<<CLK_AHBCLK_ISP_EN_Pos)                                    /*!< CLK AHBCLK: ISP_EN Mask */

#define CLK_AHBCLK_DMA_EN_Pos      1                                                                /*!< CLK AHBCLK: DMA_EN Position */
#define CLK_AHBCLK_DMA_EN_Msk     (0x1UL<<CLK_AHBCLK_DMA_EN_Pos)                                    /*!< CLK AHBCLK: DMA_EN Mask */

#define CLK_AHBCLK_GPIO_EN_Pos     0                                                               /*!< CLK AHBCLK: GPIO_EN Position */
#define CLK_AHBCLK_GPIO_EN_Msk    (0x1UL<<CLK_AHBCLK_GPIO_EN_Pos)                                  /*!< CLK AHBCLK: GPIO_EN Mask */

/* CLK APBCLK Bit Field Definitions */
#define CLK_APBCLK_SC1_EN_Pos     31                                                               /*!< CLK APBCLK: SC1_EN Position */
#define CLK_APBCLK_SC1_EN_Msk    (0x1UL<<CLK_APBCLK_SC1_EN_Pos)                                    /*!< CLK APBCLK: SC1_EN Mask */

#define CLK_APBCLK_SC0_EN_Pos     30                                                               /*!< CLK APBCLK: SC0_EN Position */
#define CLK_APBCLK_SC0_EN_Msk    (0x1UL<<CLK_APBCLK_SC0_EN_Pos)                                    /*!< CLK APBCLK: SC0_EN Mask */

#define CLK_APBCLK_I2S_EN_Pos     29                                                               /*!< CLK APBCLK: I2S_EN Position */
#define CLK_APBCLK_I2S_EN_Msk    (0x1UL<<CLK_APBCLK_I2S_EN_Pos)                                    /*!< CLK APBCLK: I2S_EN Mask */

#define CLK_APBCLK_ADC_EN_Pos     28                                                               /*!< CLK APBCLK: ADC_EN Position */
#define CLK_APBCLK_ADC_EN_Msk    (0x1UL<<CLK_APBCLK_ADC_EN_Pos)                                    /*!< CLK APBCLK: ADC_EN Mask */

#define CLK_APBCLK_USBD_EN_Pos    27                                                               /*!< CLK APBCLK: USBD_EN Position */
#define CLK_APBCLK_USBD_EN_Msk   (0x1UL<<CLK_APBCLK_USBD_EN_Pos)                                   /*!< CLK APBCLK: USBD_EN Mask */

#define CLK_APBCLK_LCD_EN_Pos     26                                                               /*!< CLK APBCLK: LCD_EN Position */
#define CLK_APBCLK_LCD_EN_Msk    (0x1UL<<CLK_APBCLK_LCD_EN_Pos)                                    /*!< CLK APBCLK: LCD_EN Mask */

#define CLK_APBCLK_DAC_EN_Pos     25                                                               /*!< CLK APBCLK: DAC_EN Position */
#define CLK_APBCLK_DAC_EN_Msk    (0x1UL<<CLK_APBCLK_DAC_EN_Pos)                                    /*!< CLK APBCLK: DAC_EN Mask */

#define CLK_APBCLK_PWM1_CH23_EN_Pos     23                                                         /*!< CLK APBCLK: PWM1_CH23_EN Position */
#define CLK_APBCLK_PWM1_CH23_EN_Msk    (0x1UL<<CLK_APBCLK_PWM1_CH23_EN_Pos)                        /*!< CLK APBCLK: PWM1_CH23_EN Mask */

#define CLK_APBCLK_PWM1_CH01_EN_Pos     22                                                         /*!< CLK APBCLK: PWM1_CH01_EN Position */
#define CLK_APBCLK_PWM1_CH01_EN_Msk    (0x1UL<<CLK_APBCLK_PWM1_CH01_EN_Pos)                        /*!< CLK APBCLK: PWM1_CH01_EN Mask */

#define CLK_APBCLK_PWM0_CH23_EN_Pos     21                                                         /*!< CLK APBCLK: PWM0_CH23_EN Position */
#define CLK_APBCLK_PWM0_CH23_EN_Msk    (0x1UL<<CLK_APBCLK_PWM0_CH23_EN_Pos)                        /*!< CLK APBCLK: PWM0_CH23_EN Mask */

#define CLK_APBCLK_PWM0_CH01_EN_Pos     20                                                         /*!< CLK APBCLK: PWM0_CH01_EN Position */
#define CLK_APBCLK_PWM0_CH01_EN_Msk    (0x1UL<<CLK_APBCLK_PWM0_CH01_EN_Pos)                        /*!< CLK APBCLK: PWM0_CH01_EN Mask */

#define CLK_APBCLK_UART1_EN_Pos     17                                                             /*!< CLK APBCLK: UART1_EN Position */
#define CLK_APBCLK_UART1_EN_Msk    (0x1UL<<CLK_APBCLK_UART1_EN_Pos)                                /*!< CLK APBCLK: UART1_EN Mask */

#define CLK_APBCLK_UART0_EN_Pos     16                                                             /*!< CLK APBCLK: UART0_EN Position */
#define CLK_APBCLK_UART0_EN_Msk    (0x1UL<<CLK_APBCLK_UART0_EN_Pos)                                /*!< CLK APBCLK: UART0_EN Mask */

#define CLK_APBCLK_SPI2_EN_Pos     14                                                              /*!< CLK APBCLK: SPI2_EN Position */
#define CLK_APBCLK_SPI2_EN_Msk    (0x1UL<<CLK_APBCLK_SPI2_EN_Pos)                                  /*!< CLK APBCLK: SPI2_EN Mask */

#define CLK_APBCLK_SPI1_EN_Pos     13                                                              /*!< CLK APBCLK: SPI1_EN Position */
#define CLK_APBCLK_SPI1_EN_Msk    (0x1UL<<CLK_APBCLK_SPI1_EN_Pos)                                  /*!< CLK APBCLK: SPI1_EN Mask */

#define CLK_APBCLK_SPI0_EN_Pos     12                                                              /*!< CLK APBCLK: SPI0_EN Position */
#define CLK_APBCLK_SPI0_EN_Msk    (0x1UL<<CLK_APBCLK_SPI0_EN_Pos)                                  /*!< CLK APBCLK: SPI0_EN Mask */

#define CLK_APBCLK_I2C1_EN_Pos     9                                                               /*!< CLK APBCLK: I2C1_EN Position */
#define CLK_APBCLK_I2C1_EN_Msk    (0x1UL<<CLK_APBCLK_I2C1_EN_Pos)                                  /*!< CLK APBCLK: I2C1_EN Mask */

#define CLK_APBCLK_I2C0_EN_Pos     8                                                               /*!< CLK APBCLK: I2C0_EN Position */
#define CLK_APBCLK_I2C0_EN_Msk    (0x1UL<<CLK_APBCLK_I2C0_EN_Pos)                                  /*!< CLK APBCLK: I2C0_EN Mask */

#define CLK_APBCLK_SC2_EN_Pos     7                                                                /*!< CLK APBCLK: SC2 Position */
#define CLK_APBCLK_SC2_EN_Msk    (0x1UL<<CLK_APBCLK_SC2_EN_Pos)                                    /*!< CLK APBCLK: SC2 Mask */

#define CLK_APBCLK_FDIV_EN_Pos     6                                                               /*!< CLK APBCLK: FDIV_EN Position */
#define CLK_APBCLK_FDIV_EN_Msk    (0x1UL<<CLK_APBCLK_FDIV_EN_Pos)                                  /*!< CLK APBCLK: FDIV_EN Mask */

#define CLK_APBCLK_TMR3_EN_Pos     5                                                               /*!< CLK APBCLK: TMR3_EN Position */
#define CLK_APBCLK_TMR3_EN_Msk    (0x1UL<<CLK_APBCLK_TMR3_EN_Pos)                                  /*!< CLK APBCLK: TMR3_EN Mask */

#define CLK_APBCLK_TMR2_EN_Pos     4                                                               /*!< CLK APBCLK: TMR2_EN Position */
#define CLK_APBCLK_TMR2_EN_Msk    (0x1UL<<CLK_APBCLK_TMR2_EN_Pos)                                  /*!< CLK APBCLK: TMR2_EN Mask */

#define CLK_APBCLK_TMR1_EN_Pos     3                                                               /*!< CLK APBCLK: TMR1_EN Position */
#define CLK_APBCLK_TMR1_EN_Msk    (0x1UL<<CLK_APBCLK_TMR1_EN_Pos)                                  /*!< CLK APBCLK: TMR1_EN Mask */

#define CLK_APBCLK_TMR0_EN_Pos     2                                                               /*!< CLK APBCLK: TMR0_EN Position */
#define CLK_APBCLK_TMR0_EN_Msk    (0x1UL<<CLK_APBCLK_TMR0_EN_Pos)                                  /*!< CLK APBCLK: TMR0_EN Mask */

#define CLK_APBCLK_RTC_EN_Pos     1                                                                /*!< CLK APBCLK: RTC_EN Position */
#define CLK_APBCLK_RTC_EN_Msk    (0x1UL<<CLK_APBCLK_RTC_EN_Pos)                                    /*!< CLK APBCLK: RTC_EN Mask */

#define CLK_APBCLK_WDT_EN_Pos     0                                                                /*!< CLK APBCLK: WDT_EN Position */
#define CLK_APBCLK_WDT_EN_Msk    (0x1UL<<CLK_APBCLK_WDT_EN_Pos)                                    /*!< CLK APBCLK: WDT_EN Mask */

/* CLK CLKSTATUS Bit Field Definitions */
#define CLK_CLKSTATUS_CLK_SW_FAIL_Pos     7                                                        /*!< CLK CLKSTATUS: CLK_SW_FAIL Position */
#define CLK_CLKSTATUS_CLK_SW_FAIL_Msk    (0x1UL<<CLK_CLKSTATUS_CLK_SW_FAIL_Pos)                    /*!< CLK CLKSTATUS: CLK_SW_FAIL Mask */

#define CLK_CLKSTATUS_HIRC_STB_Pos     4                                                           /*!< CLK CLKSTATUS: HIRC_STB Position */
#define CLK_CLKSTATUS_HIRC_STB_Msk    (0x1UL<<CLK_CLKSTATUS_HIRC_STB_Pos)                          /*!< CLK CLKSTATUS: HIRC_STB Mask */

#define CLK_CLKSTATUS_LIRC_STB_Pos     3                                                           /*!< CLK CLKSTATUS: LIRC_STB Position */
#define CLK_CLKSTATUS_LIRC_STB_Msk    (0x1UL<<CLK_CLKSTATUS_LIRC_STB_Pos)                          /*!< CLK CLKSTATUS: LIRC_STB Mask */

#define CLK_CLKSTATUS_PLL_STB_Pos     2                                                            /*!< CLK CLKSTATUS: PLL_STB Position */
#define CLK_CLKSTATUS_PLL_STB_Msk    (0x1UL<<CLK_CLKSTATUS_PLL_STB_Pos)                            /*!< CLK CLKSTATUS: PLL_STB Mask */

#define CLK_CLKSTATUS_LXT_STB_Pos     1                                                            /*!< CLK CLKSTATUS: LXT_STB Position */
#define CLK_CLKSTATUS_LXT_STB_Msk    (0x1UL<<CLK_CLKSTATUS_LXT_STB_Pos)                            /*!< CLK CLKSTATUS: LXT_STB Mask */

#define CLK_CLKSTATUS_HXT_STB_Pos     0                                                            /*!< CLK CLKSTATUS: HXT_STB Position */
#define CLK_CLKSTATUS_HXT_STB_Msk    (0x1UL<<CLK_CLKSTATUS_HXT_STB_Pos)                            /*!< CLK CLKSTATUS: HXT_STB Mask */

/* CLK CLKSEL0 Bit Field Definitions */
#define CLK_CLKSEL0_HCLK_S_Pos     0                                                               /*!< CLK CLKSEL0: HCLK_S Position */
#define CLK_CLKSEL0_HCLK_S_Msk    (0x7UL<<CLK_CLKSEL0_HCLK_S_Pos)                                  /*!< CLK CLKSEL0: HCLK_S Mask */

/* CLK CLKSEL1 Bit Field Definitions */
#define CLK_CLKSEL1_LCD_S_Pos     18                                                              /*!< CLK CLKSEL1: LCD_S Position */
#define CLK_CLKSEL1_LCD_S_Msk    (0x1UL<<CLK_CLKSEL1_LCD_S_Pos)                                  /*!< CLK CLKSEL1: LCD_S Mask */

#define CLK_CLKSEL1_TMR1_S_Pos     12                                                              /*!< CLK CLKSEL1: TMR1_S Position */
#define CLK_CLKSEL1_TMR1_S_Msk    (0x7UL<<CLK_CLKSEL1_TMR1_S_Pos)                                  /*!< CLK CLKSEL1: TMR1_S Mask */

#define CLK_CLKSEL1_TMR0_S_Pos     8                                                               /*!< CLK CLKSEL1: TMR0_S Position */
#define CLK_CLKSEL1_TMR0_S_Msk    (0x7UL<<CLK_CLKSEL1_TMR0_S_Pos)                                  /*!< CLK CLKSEL1: TMR0_S Mask */

#define CLK_CLKSEL1_PWM0_CH23_S_Pos     6                                                          /*!< CLK CLKSEL1: PWM0_CH23_S Position */
#define CLK_CLKSEL1_PWM0_CH23_S_Msk    (0x3UL<<CLK_CLKSEL1_PWM0_CH23_S_Pos)                        /*!< CLK CLKSEL1: PWM0_CH23_S Mask */

#define CLK_CLKSEL1_PWM0_CH01_S_Pos     4                                                          /*!< CLK CLKSEL1: PWM0_CH01_S Position */
#define CLK_CLKSEL1_PWM0_CH01_S_Msk    (0x3UL<<CLK_CLKSEL1_PWM0_CH01_S_Pos)                        /*!< CLK CLKSEL1: PWM0_CH01_S Mask */

#define CLK_CLKSEL1_ADC_S_Pos     2                                                                /*!< CLK CLKSEL1: ADC_S Position */
#define CLK_CLKSEL1_ADC_S_Msk    (0x3UL<<CLK_CLKSEL1_ADC_S_Pos)                                    /*!< CLK CLKSEL1: ADC_S Mask */

#define CLK_CLKSEL1_UART_S_Pos     0                                                               /*!< CLK CLKSEL1: UART_S Position */
#define CLK_CLKSEL1_UART_S_Msk    (0x3UL<<CLK_CLKSEL1_UART_S_Pos)                                  /*!< CLK CLKSEL1: UART_S Mask */

/* CLK CLKSEL2 Bit Field Definitions */
#define CLK_CLKSEL2_SPI2_S_Pos     22                                                              /*!< CLK CLKSEL2: SPI2_S Position */
#define CLK_CLKSEL2_SPI2_S_Msk    (0x3UL<<CLK_CLKSEL2_SPI2_S_Pos)                                  /*!< CLK CLKSEL2: SPI2_S Mask */

#define CLK_CLKSEL2_SPI1_S_Pos     21                                                              /*!< CLK CLKSEL2: SPI1_S Position */
#define CLK_CLKSEL2_SPI1_S_Msk    (0x3UL<<CLK_CLKSEL2_SPI1_S_Pos)                                  /*!< CLK CLKSEL2: SPI1_S Mask */

#define CLK_CLKSEL2_SPI0_S_Pos     20                                                              /*!< CLK CLKSEL2: SPI0_S Position */
#define CLK_CLKSEL2_SPI0_S_Msk    (0x3UL<<CLK_CLKSEL2_SPI0_S_Pos)                                  /*!< CLK CLKSEL2: SPI0_S Mask */

#define CLK_CLKSEL2_SC_S_Pos     18                                                                /*!< CLK CLKSEL2: SC_S Position */
#define CLK_CLKSEL2_SC_S_Msk    (0x3UL<<CLK_CLKSEL2_SC_S_Pos)                                      /*!< CLK CLKSEL2: SC_S Mask */

#define CLK_CLKSEL2_I2S_S_Pos     16                                                               /*!< CLK CLKSEL2: I2S_S Position */
#define CLK_CLKSEL2_I2S_S_Msk    (0x3UL<<CLK_CLKSEL2_I2S_S_Pos)                                    /*!< CLK CLKSEL2: I2S_S Mask */

#define CLK_CLKSEL2_TMR3_S_Pos     12                                                              /*!< CLK CLKSEL2: TMR3_S  Position */
#define CLK_CLKSEL2_TMR3_S_Msk    (0x7UL<<CLK_CLKSEL2_TMR3_S_Pos)                                  /*!< CLK CLKSEL2: TMR3_S  Mask */

#define CLK_CLKSEL2_TMR2_S_Pos     8                                                               /*!< CLK CLKSEL2: TMR2_S  Position */
#define CLK_CLKSEL2_TMR2_S_Msk    (0x7UL<<CLK_CLKSEL2_TMR2_S_Pos)                                  /*!< CLK CLKSEL2: TMR2_S  Mask */

#define CLK_CLKSEL2_PWM1_CH23_S_Pos     6                                                          /*!< CLK CLKSEL2: PWM1_CH23_S Position */
#define CLK_CLKSEL2_PWM1_CH23_S_Msk    (0x3UL<<CLK_CLKSEL2_PWM1_CH23_S_Pos)                        /*!< CLK CLKSEL2: PWM1_CH23_S Mask */

#define CLK_CLKSEL2_PWM1_CH01_S_Pos     4                                                          /*!< CLK CLKSEL2: PWM1_CH01_S Position */
#define CLK_CLKSEL2_PWM1_CH01_S_Msk    (0x3UL<<CLK_CLKSEL2_PWM1_CH01_S_Pos)                        /*!< CLK CLKSEL2: PWM1_CH01_S Mask */

#define CLK_CLKSEL2_FRQDIV_S_Pos     2                                                             /*!< CLK CLKSEL2: FRQDIV_S  Position */
#define CLK_CLKSEL2_FRQDIV_S_Msk    (0x3UL<<CLK_CLKSEL2_FRQDIV_S_Pos)                              /*!< CLK CLKSEL2: FRQDIV_S  Mask */

/* CLK CLKDIV0 Bit Field Definitions */
#define CLK_CLKDIV0_SC0_N_Pos     28                                                               /*!< CLK CLKDIV0: SC0_N  Position */
#define CLK_CLKDIV0_SC0_N_Msk    (0xFUL<<CLK_CLKDIV0_SC0_N_Pos)                                    /*!< CLK CLKDIV0: SC0_N  Mask */

#define CLK_CLKDIV0_ADC_N_Pos     16                                                               /*!< CLK CLKDIV0: ADC_N  Position */
#define CLK_CLKDIV0_ADC_N_Msk    (0xFFUL<<CLK_CLKDIV0_ADC_N_Pos)                                   /*!< CLK CLKDIV0: ADC_N  Mask */

#define CLK_CLKDIV0_UART_N_Pos     8                                                               /*!< CLK CLKDIV0: UART_N  Position */
#define CLK_CLKDIV0_UART_N_Msk    (0xFUL<<CLK_CLKDIV0_UART_N_Pos)                                  /*!< CLK CLKDIV0: UART_N  Mask */

#define CLK_CLKDIV0_I2S_N_Pos     12                                                                /*!< CLK CLKDIV0: I2S_N  Position */
#define CLK_CLKDIV0_I2S_N_Msk    (0xFUL<<CLK_CLKDIV0_I2S_N_Pos)                                    /*!< CLK CLKDIV0: I2S_N  Mask */

#define CLK_CLKDIV0_USB_N_Pos     4                                                                /*!< CLK CLKDIV0: USB_N  Position */
#define CLK_CLKDIV0_USB_N_Msk    (0xFUL<<CLK_CLKDIV0_USB_N_Pos)                                    /*!< CLK CLKDIV0: USB_N  Mask */

#define CLK_CLKDIV0_HCLK_N_Pos     0                                                               /*!< CLK CLKDIV0: HCLK_N  Position */
#define CLK_CLKDIV0_HCLK_N_Msk    (0xFUL<<CLK_CLKDIV0_HCLK_N_Pos)                                  /*!< CLK CLKDIV0: HCLK_N  Mask */

/* CLK CLKDIV1 Bit Field Definitions */
#define CLK_CLKDIV1_SC2_N_Pos     4                                                                /*!< CLK CLKDIV1: SC2_N  Position */
#define CLK_CLKDIV1_SC2_N_Msk    (0xFUL<<CLK_CLKDIV1_SC2_N_Pos)                                    /*!< CLK CLKDIV1: SC2_N  Mask */

#define CLK_CLKDIV1_SC1_N_Pos     0                                                                /*!< CLK CLKDIV1: SC1_N  Position */
#define CLK_CLKDIV1_SC1_N_Msk    (0xFUL<<CLK_CLKDIV1_SC1_N_Pos)                                    /*!< CLK CLKDIV1: SC1_N  Mask */

/* CLK PLLCTL Bit Field Definitions */
#define CLK_PLLCTL_PLL_SRC_Pos     17                                                              /*!< CLK PLLCTL: PLL_SRC  Position */
#define CLK_PLLCTL_PLL_SRC_Msk    (0x1UL<<CLK_PLLCTL_PLL_SRC_Pos)                                  /*!< CLK PLLCTL: PLL_SRC  Mask */

#define CLK_PLLCTL_PD_Pos     16                                                                   /*!< CLK PLLCTL: PD  Position */
#define CLK_PLLCTL_PD_Msk    (0x1UL<<CLK_PLLCTL_PD_Pos)                                            /*!< CLK PLLCTL: PD  Mask */

#define CLK_PLLCTL_OUT_DV_Pos     12                                                               /*!< CLK PLLCTL: OUT_DV  Position */
#define CLK_PLLCTL_OUT_DV_Msk    (0x1UL<<CLK_PLLCTL_OUT_DV_Pos)                                    /*!< CLK PLLCTL: OUT_DV  Mask */

#define CLK_PLLCTL_IN_DV_Pos     8                                                                 /*!< CLK PLLCTL: IN_DV  Position */
#define CLK_PLLCTL_IN_DV_Msk    (0x3UL<<CLK_PLLCTL_IN_DV_Pos)                                      /*!< CLK PLLCTL: IN_DV  Mask */

#define CLK_PLLCTL_FB_DV_Pos     0                                                                 /*!< CLK PLLCTL: FB_DV  Position */
#define CLK_PLLCTL_FB_DV_Msk    (0x3FUL<<CLK_PLLCTL_FB_DV_Pos)                                     /*!< CLK PLLCTL: FB_DV  Mask */

/* CLK FRQDIV Bit Field Definitions */
#define CLK_FRQDIV_DIV1_Pos     5                                                                /*!< CLK FRQDIV: DIV1  Position */
#define CLK_FRQDIV_DIV1_Msk    (0x1UL<<CLK_FRQDIV_DIV1_Pos)                                      /*!< CLK FRQDIV: DIV1  Mask */

#define CLK_FRQDIV_FDIV_EN_Pos     4                                                             /*!< CLK FRQDIV: FDIV_EN  Position */
#define CLK_FRQDIV_FDIV_EN_Msk    (0x1UL<<CLK_FRQDIV_FDIV_EN_Pos)                                /*!< CLK FRQDIV: FDIV_EN  Mask */

#define CLK_FRQDIV_FSEL_Pos     0                                                                /*!< CLK FRQDIV: FSEL  Position */
#define CLK_FRQDIV_FSEL_Msk    (0xFUL<<CLK_FRQDIV_FSEL_Pos)                                      /*!< CLK FRQDIV: FSEL  Mask */

/* CLK MCLKO Bit Field Definitions */
#define CLK_MCLKO_MCLK_EN_Pos     7                                                              /*!< CLK MCLKO: MCLK_EN  Position */
#define CLK_MCLKO_MCLK_EN_Msk    (0x1UL<<CLK_MCLKO_MCLK_EN_Pos)                                  /*!< CLK MCLKO: MCLK_EN  Mask */

#define CLK_MCLKO_MCLK_SEL_Pos     0                                                             /*!< CLK MCLKO: MCLK_SEL  Position */
#define CLK_MCLKO_MCLK_SEL_Msk    (0x3FUL<<CLK_MCLKO_MCLK_SEL_Pos)                               /*!< CLK MCLKO: MCLK_SEL  Mask */

/* CLK PD_WK_IS Bit Field Definitions */
#define CLK_PD_WK_IS_PD_WK_IS_Pos     0                                                            /*!< CLK PD_WK_IS: PD_WK_IS  Position */
#define CLK_PD_WK_IS_PD_WK_IS_Msk    (0x1UL<<CLK_PD_WK_IS_PD_WK_IS_Pos)                            /*!< CLK PD_WK_IS: PD_WK_IS  Mask */

/*----------------------------- ADC Controller -------------------------------*/
/** @addtogroup NANO100_ADC NANO100 A/D Converter (ADC)
  Memory Mapped Structure for NANO100 Series A/D Converter
  @{
*/
/**
  * @brief ADC register map
  */
typedef struct {
    __I  uint32_t  RESULT0;                    /*!< Offset: 0x0000   A/D result Register 0                              */
    __I  uint32_t  RESULT1;                    /*!< Offset: 0x0004   A/D result Register 1                              */
    __I  uint32_t  RESULT2;                    /*!< Offset: 0x0008   A/D result Register 2                              */
    __I  uint32_t  RESULT3;                    /*!< Offset: 0x000C   A/D result Register 3                              */
    __I  uint32_t  RESULT4;                    /*!< Offset: 0x0010   A/D result Register 4                              */
    __I  uint32_t  RESULT5;                    /*!< Offset: 0x0014   A/D result Register 5                              */
    __I  uint32_t  RESULT6;                    /*!< Offset: 0x0018   A/D result Register 6                              */
    __I  uint32_t  RESULT7;                    /*!< Offset: 0x001C   A/D result Register 7                              */
    __I  uint32_t  RESULT8;                    /*!< Offset: 0x0020   A/D result Register 8                              */
    __I  uint32_t  RESULT9;                    /*!< Offset: 0x0024   A/D result Register 9                              */
    __I  uint32_t  RESULT10;                   /*!< Offset: 0x0028   A/D result Register 10                             */
    __I  uint32_t  RESULT11;                   /*!< Offset: 0x002C   A/D result Register 11                             */
    __I  uint32_t  RESULT12;                   /*!< Offset: 0x0030   A/D result Register 12                             */
    __I  uint32_t  RESULT13;                   /*!< Offset: 0x0034   A/D result Register 13                             */
    __I  uint32_t  RESULT14;                   /*!< Offset: 0x0038   A/D result Register 14                             */
    __I  uint32_t  RESULT15;                   /*!< Offset: 0x003C   A/D result Register 15                             */
    __I  uint32_t  RESULT16;                   /*!< Offset: 0x0040   A/D result Register 16                             */
    __I  uint32_t  RESULT17;                   /*!< Offset: 0x0044   A/D result Register 17                             */
    __IO uint32_t  CR;                         /*!< Offset: 0x0048   A/D Control Register                               */
    __IO uint32_t  CHER;                       /*!< Offset: 0x004C   A/D Channel Enable Register                        */
    __IO uint32_t  CMPR0;                      /*!< Offset: 0x0050   A/D Compare Register 0                             */
    __IO uint32_t  CMPR1;                      /*!< Offset: 0x0054   A/D Compare Register 1                             */
    __IO uint32_t  SR;                         /*!< Offset: 0x0058   A/D Status Register                                */
    uint32_t  RESERVED0;                       /*!< Offset: 0x005C   Reserved                                           */
    __I  uint32_t  PDMA;                       /*!< Offset: 0x0060   A/D PDMA Current Transfer Data Register            */
    __IO uint32_t  PWRCTL;                     /*!< Offset: 0x0064   A/D Power Control Register                         */
    __IO uint32_t  CALCTL;                     /*!< Offset: 0x0068   A/D Calibration Control Register                   */
    __IO uint32_t  CALWORD;                    /*!< Offset: 0x006C   A/D Calibration Load Word Register                 */
    __IO uint32_t  SMPLCNT0;                   /*!< Offset: 0x0070   A/D Sample Register 0                              */
    __IO uint32_t  SMPLCNT1;                   /*!< Offset: 0x0074   A/D Sample Register 1                              */
} ADC_T;

/* ADC RESULT Bit Field Definitions */
#define ADC_RESULT_RSLT_Pos                      0                                   /*!< ADC RESULT: RSLT Position */
#define ADC_RESULT_RSLT_Msk                      (0xFFFul << ADC_RESULT_RSLT_Pos)    /*!< ADC RESULT: RSLT Mask */

#define ADC_RESULT_VALID_Pos                     16                                  /*!< ADC RESULT: VALID Position */
#define ADC_RESULT_VALID_Msk                     (0x1ul << ADC_RESULT_VALID_Pos)     /*!< ADC RESULT: VALID Mask */

#define ADC_RESULT_OVERRUN_Pos                   17                                  /*!< ADC RESULT: OVERRUN Position */
#define ADC_RESULT_OVERRUN_Msk                   (0x1ul << ADC_RESULT_OVERRUN_Pos)   /*!< ADC RESULT: OVERRUN Mask */

/* ADC CR Bit Field Definitions */
#define ADC_CR_ADEN_Pos                          0                                   /*!< ADC CR: ADEN Position */
#define ADC_CR_ADEN_Msk                          (0x1ul << ADC_CR_ADEN_Pos)          /*!< ADC CR: ADEN Mask */

#define ADC_CR_ADIE_Pos                          1                                   /*!< ADC CR: ADIE Position */
#define ADC_CR_ADIE_Msk                          (0x1ul << ADC_CR_ADIE_Pos)          /*!< ADC CR: ADIE Mask */

#define ADC_CR_ADMD_Pos                          2                                   /*!< ADC CR: ADMD Position */
#define ADC_CR_ADMD_Msk                          (0x3ul << ADC_CR_ADMD_Pos)          /*!< ADC CR: ADMD Mask */

#define ADC_CR_TRGS_Pos                          4                                   /*!< ADC CR: TRGS Position */
#define ADC_CR_TRGS_Msk                          (0x3ul << ADC_CR_TRGS_Pos)          /*!< ADC CR: TRGS Mask */

#define ADC_CR_TRGCOND_Pos                       6                                   /*!< ADC CR: TRGCOND Position */
#define ADC_CR_TRGCOND_Msk                       (0x3ul << ADC_CR_TRGCOND_Pos)       /*!< ADC CR: TRGCOND Mask */

#define ADC_CR_TRGEN_Pos                         8                                   /*!< ADC CR: TRGEN Position */
#define ADC_CR_TRGEN_Msk                         (0x1ul << ADC_CR_TRGEN_Pos)         /*!< ADC CR: TRGEN Mask */

#define ADC_CR_PTEN_Pos                          9                                   /*!< ADC CR: PTEN Position */
#define ADC_CR_PTEN_Msk                          (0x1ul << ADC_CR_PTEN_Pos)          /*!< ADC CR: PTEN Mask */

#define ADC_CR_DIFF_Pos                          10                                  /*!< ADC CR: DIFF Position */
#define ADC_CR_DIFF_Msk                          (0x1ul << ADC_CR_DIFF_Pos)          /*!< ADC CR: DIFF Mask */

#define ADC_CR_ADST_Pos                          11                                  /*!< ADC CR: ADST Position */
#define ADC_CR_ADST_Msk                          (0x1ul << ADC_CR_ADST_Pos)          /*!< ADC CR: ADST Mask */

#define ADC_CR_TMSEL_Pos                         12                                  /*!< ADC CR: TMSEL Position */
#define ADC_CR_TMSEL_Msk                         (0x3ul << ADC_CR_TMSEL_Pos)         /*!< ADC CR: TMSEL Mask */

#define ADC_CR_TMTRGMOD_Pos                      15                                  /*!< ADC CR: TMTRGMOD Position */
#define ADC_CR_TMTRGMOD_Msk                      (0x1ul << ADC_CR_TMTRGMOD_Pos)      /*!< ADC CR: TMTRGMOD Mask */

#define ADC_CR_REFSEL_Pos                        16                                  /*!< ADC CR: REFSEL Position */
#define ADC_CR_REFSEL_Msk                        (0x3ul << ADC_CR_REFSEL_Pos)        /*!< ADC CR: REFSEL Mask */

#define ADC_CR_RESSEL_Pos                        18                                  /*!< ADC CR: RESSEL Position */
#define ADC_CR_RESSEL_Msk                        (0x3ul << ADC_CR_RESSEL_Pos)        /*!< ADC CR: RESSEL Mask */

#define ADC_CR_TMPDMACNT_Pos                     24                                  /*!< ADC CR: TMPDMACNT Position */
#define ADC_CR_TMPDMACNT_Msk                     (0xFFul << ADC_CR_TMPDMACNT_Pos)    /*!< ADC CR: TMPDMACNT Mask */

/* ADC CHER Bit Field Definitions */
#define ADC_CHER_CHEN0_Pos                       0                                   /*!< ADC CHER: CHEN0 Position */
#define ADC_CHER_CHEN0_Msk                       (0x1ul << ADC_CHER_CHEN0_Pos)       /*!< ADC CHER: CHEN0 Mask */

#define ADC_CHER_CHEN1_Pos                       1                                   /*!< ADC CHER: CHEN1 Position */
#define ADC_CHER_CHEN1_Msk                       (0x1ul << ADC_CHER_CHEN1_Pos)       /*!< ADC CHER: CHEN1 Mask */

#define ADC_CHER_CHEN2_Pos                       2                                   /*!< ADC CHER: CHEN2 Position */
#define ADC_CHER_CHEN2_Msk                       (0x1ul << ADC_CHER_CHEN2_Pos)       /*!< ADC CHER: CHEN2 Mask */

#define ADC_CHER_CHEN3_Pos                       3                                   /*!< ADC CHER: CHEN3 Position */
#define ADC_CHER_CHEN3_Msk                       (0x1ul << ADC_CHER_CHEN3_Pos)       /*!< ADC CHER: CHEN3 Mask */

#define ADC_CHER_CHEN4_Pos                       4                                   /*!< ADC CHER: CHEN4 Position */
#define ADC_CHER_CHEN4_Msk                       (0x1ul << ADC_CHER_CHEN4_Pos)       /*!< ADC CHER: CHEN4 Mask */

#define ADC_CHER_CHEN5_Pos                       5                                   /*!< ADC CHER: CHEN5 Position */
#define ADC_CHER_CHEN5_Msk                       (0x1ul << ADC_CHER_CHEN5_Pos)       /*!< ADC CHER: CHEN5 Mask */

#define ADC_CHER_CHEN6_Pos                       6                                   /*!< ADC CHER: CHEN6 Position */
#define ADC_CHER_CHEN6_Msk                       (0x1ul << ADC_CHER_CHEN6_Pos)       /*!< ADC CHER: CHEN6 Mask */

#define ADC_CHER_CHEN7_Pos                       7                                   /*!< ADC CHER: CHEN7 Position */
#define ADC_CHER_CHEN7_Msk                       (0x1ul << ADC_CHER_CHEN7_Pos)       /*!< ADC CHER: CHEN7 Mask */

#define ADC_CHER_CHEN14_Pos                      14                                  /*!< ADC CHER: CHEN14 Position */
#define ADC_CHER_CHEN14_Msk                      (0x1ul << ADC_CHER_CHEN14_Pos)      /*!< ADC CHER: CHEN14 Mask */

#define ADC_CHER_CHEN15_Pos                      15                                  /*!< ADC CHER: CHEN15 Position */
#define ADC_CHER_CHEN15_Msk                      (0x1ul << ADC_CHER_CHEN15_Pos)      /*!< ADC CHER: CHEN15 Mask */

#define ADC_CHER_CHEN16_Pos                      16                                  /*!< ADC CHER: CHEN16 Position */
#define ADC_CHER_CHEN16_Msk                      (0x1ul << ADC_CHER_CHEN16_Pos)      /*!< ADC CHER: CHEN16 Mask */

#define ADC_CHER_CHEN17_Pos                      17                                  /*!< ADC CHER: CHEN17 Position */
#define ADC_CHER_CHEN17_Msk                      (0x1ul << ADC_CHER_CHEN17_Pos)      /*!< ADC CHER: CHEN17 Mask */

/* ADC CMPR Bit Field Definitions */
#define ADC_CMPR_CMPEN_Pos                       0                                   /*!< ADC CMPR: CMPEN Position */
#define ADC_CMPR_CMPEN_Msk                       (0x1ul << ADC_CMPR_CMPEN_Pos)       /*!< ADC CMPR: CMPEN Mask */

#define ADC_CMPR_CMPIE_Pos                       1                                   /*!< ADC CMPR: CMPIE Position */
#define ADC_CMPR_CMPIE_Msk                       (0x1ul << ADC_CMPR_CMPIE_Pos)       /*!< ADC CMPR: CMPIE Mask */

#define ADC_CMPR_CMPCOND_Pos                     2                                   /*!< ADC CMPR: CMPCOND Position */
#define ADC_CMPR_CMPCOND_Msk                     (0x1ul << ADC_CMPR_CMPCOND_Pos)     /*!< ADC CMPR: CMPCOND Mask */

#define ADC_CMPR_CMPCH_Pos                       3                                   /*!< ADC CMPR: CMPCH Position */
#define ADC_CMPR_CMPCH_Msk                       (0xFul << ADC_CMPR_CMPCH_Pos)       /*!< ADC CMPR: CMPCH Mask */

#define ADC_CMPR_CMPMATCNT_Pos                   8                                   /*!< ADC CMPR: CMPMATCNT Position */
#define ADC_CMPR_CMPMATCNT_Msk                   (0xFul << ADC_CMPR_CMPMATCNT_Pos)   /*!< ADC CMPR: CMPMATCNT Mask */

#define ADC_CMPR_CMPD_Pos                        16                                  /*!< ADC CMPR: CMPD Position */
#define ADC_CMPR_CMPD_Msk                        (0xFFFul << ADC_CMPR_CMPD_Pos)      /*!< ADC CMPR: CMPD Mask */

/* ADC SR Bit Field Definitions */
#define ADC_SR_ADF_Pos                           0                                   /*!< ADC SR: ADF Position */
#define ADC_SR_ADF_Msk                           (0x1ul << ADC_SR_ADF_Pos)           /*!< ADC SR: ADF Mask */

#define ADC_SR_CMPF0_Pos                         1                                   /*!< ADC SR: CMPF0 Position */
#define ADC_SR_CMPF0_Msk                         (0x1ul << ADC_SR_CMPF0_Pos)         /*!< ADC SR: CMPF0 Mask */

#define ADC_SR_CMPF1_Pos                         2                                   /*!< ADC SR: CMPF1 Position */
#define ADC_SR_CMPF1_Msk                         (0x1ul << ADC_SR_CMPF1_Pos)         /*!< ADC SR: CMPF1 Mask */

#define ADC_SR_BUSY_Pos                          3                                   /*!< ADC SR: BUSY Position */
#define ADC_SR_BUSY_Msk                          (0x1ul << ADC_SR_BUSY_Pos)          /*!< ADC SR: BUSY Mask */

#define ADC_SR_CHANNEL_Pos                       4                                   /*!< ADC SR: CHANNEL Position */
#define ADC_SR_CHANNEL_Msk                       (0x1Ful << ADC_SR_CHANNEL_Pos)      /*!< ADC SR: CHANNEL Mask */

#define ADC_SR_INITRDY_Pos                       16                                  /*!< ADC SR: INITRDY Position */
#define ADC_SR_INITRDY_Msk                       (0x1ul << ADC_SR_INITRDY_Pos)       /*!< ADC SR: INITRDY Mask */

/* ADC PWRCTL Bit Field Definitions */
#define ADC_PWRCTL_PWUPRDY_Pos                   0                                   /*!< ADC PWRCTL: PWUPRDY Position */
#define ADC_PWRCTL_PWUPRDY_Msk                   (0x1ul << ADC_PWRCTL_PWUPRDY_Pos)   /*!< ADC PWRCTL: PWUPRDY Mask */

#define ADC_PWRCTL_PWDCALEN_Pos                  1                                   /*!< ADC PWRCTL: PWDCALEN Position */
#define ADC_PWRCTL_PWDCALEN_Msk                  (0x1ul << ADC_PWRCTL_PWDCALEN_Pos)  /*!< ADC PWRCTL: PWDCALEN Mask */

#define ADC_PWRCTL_PWDMOD_Pos                    2                                   /*!< ADC PWRCTL: PWDMOD Position */
#define ADC_PWRCTL_PWDMOD_Msk                    (0x3ul << ADC_PWRCTL_PWDMOD_Pos)    /*!< ADC PWRCTL: PWDMOD Mask */

/* ADC CALCTL Bit Field Definitions */
#define ADC_CALCTL_CALEN_Pos                     0                                   /*!< ADC CALCTL: CALEN Position */
#define ADC_CALCTL_CALEN_Msk                     (0x1ul << ADC_CALCTL_CALEN_Pos)     /*!< ADC CALCTL: CALEN Mask */

#define ADC_CALCTL_CALSTART_Pos                  1                                   /*!< ADC CALCTL: CALSTART Position */
#define ADC_CALCTL_CALSTART_Msk                  (0x1ul << ADC_CALCTL_CALSTART_Pos)  /*!< ADC CALCTL: CALSTART Mask */

#define ADC_CALCTL_CALDONE_Pos                   2                                   /*!< ADC CALCTL: CALDONE Position */
#define ADC_CALCTL_CALDONE_Msk                   (0x1ul << ADC_CALCTL_CALDONE_Pos)   /*!< ADC CALCTL: CALDONE Mask */

#define ADC_CALCTL_CALSEL_Pos                    3                                   /*!< ADC CALCTL: CALSEL Position */
#define ADC_CALCTL_CALSEL_Msk                    (0x1ul << ADC_CALCTL_CALSEL_Pos)    /*!< ADC CALCTL: CALSEL Mask */

/* ADC SMPLCNT Bit Field Definitions */
#define ADC_SMPLCNT_CH0SAMPCNT_Pos               0                                       /*!< ADC SMPLCNT: CH0SAMPCNT Position */
#define ADC_SMPLCNT_CH0SAMPCNT_Msk               (0xFul << ADC_SMPLCNT_CH0SAMPCNT_Pos)   /*!< ADC SMPLCNT: CH0SAMPCNT Mask */

#define ADC_SMPLCNT_INTCHSAMPCNT_Pos             16                                      /*!< ADC SMPLCNT: INTCHSAMPCNT Position */
#define ADC_SMPLCNT_INTCHSAMPCNT_Msk             (0xFul << ADC_SMPLCNT_INTCHSAMPCNT_Pos) /*!< ADC SMPLCNT: INTCHSAMPCNT Mask */

/*@}*/ /* end of group NANO100_ADC */

/*------------- DAC (DAC) -----------------------------*/
/** @addtogroup NANO100_DAC NANO100 DAC Control Register (DAC)
    Memory Mapped Structure for NANO100 DAC Controller
  @{
*/
typedef struct {
    __IO uint32_t  CTL0;                      /*!< Offset: 0x0000   DAC0 Control Register                              */
    __IO uint32_t  DATA0;                     /*!< Offset: 0x0004   DAC0 Data Register                                 */
    __IO uint32_t  STS0;                      /*!< Offset: 0x0008   DAC0 Status Register                               */
    uint32_t  RESERVED0;                      /*!< Offset: 0x000C   Reserved                                           */
    __IO uint32_t  CTL1;                      /*!< Offset: 0x0010   DAC1 Control Register                              */
    __IO uint32_t  DATA1;                     /*!< Offset: 0x0014   DAC1 Data Register                                 */
    __IO uint32_t  STS1;                      /*!< Offset: 0x0018   DAC1 Status Register                               */
    uint32_t  RESERVED1;                      /*!< Offset: 0x001C   Reserved                                           */
    __IO uint32_t  COMCTL;                    /*!< Offset: 0x0020   DAC01 Common Control Register                      */
} DAC_T;

/* DAC CTL Bit Field Definitions */
#define DAC_CTL_DACPWONSTBCNT_Pos               8                                         /*!< DAC CTL: DACPWONSTBCNT Position */
#define DAC_CTL_DACPWONSTBCNT_Msk               (0x3FFFul << DAC_CTL_DACPWONSTBCNT_Pos)   /*!< DAC CTL: DACPWONSTBCNT Mask */

#define DAC_CTL_DACLSEL_Pos                     4                                         /*!< DAC CTL: DACLSEL Position */
#define DAC_CTL_DACLSEL_Msk                     (0x7ul << DAC_CTL_DACLSEL_Pos)            /*!< DAC CTL: DACLSEL Mask */

#define DAC_CTL_DACIE_Pos                       1                                         /*!< DAC CTL: DACIE Position */
#define DAC_CTL_DACIE_Msk                       (0x1ul << DAC_CTL_DACIE_Pos)              /*!< DAC CTL: DACIE Mask */

#define DAC_CTL_DACEN_Pos                       0                                         /*!< DAC CTL: DACEN Position */
#define DAC_CTL_DACEN_Msk                       (0x1ul << DAC_CTL_DACEN_Pos)              /*!< DAC CTL: DACEN Mask */

/* DAC DATA Bit Field Definitions */
#define DAC_DATA_DATA_Pos                       0                                         /*!< DAC DATA: DATA Position */
#define DAC_DATA_DATA_Msk                       (0xFFFul << DAC_DATA_DATA_Pos)            /*!< DAC DATA: DATA Mask */

/* DAC STS Bit Field Definitions */
#define DAC_STS_BUSY_Pos                        2                                         /*!< DAC STS: BUSY Position */
#define DAC_STS_BUSY_Msk                        (0x1ul << DAC_STS_BUSY_Pos)               /*!< DAC STS: BUSY Mask */

#define DAC_STS_DACSTFG_Pos                     1                                         /*!< DAC STS: DACSTFG Position */
#define DAC_STS_DACSTFG_Msk                     (0x1ul << DAC_STS_DACSTFG_Pos)            /*!< DAC STS: DACSTFG Mask */

#define DAC_STS_DACUFG_Pos                      0                                         /*!< DAC STS: DACIFG Position */
#define DAC_STS_DACIFG_Msk                      (0x1ul << DAC_STS_DACIFG_Pos)             /*!< DAC STS: DACIFG Mask */

/* DAC COMCTL Bit Field Definitions */
#define DAC_COMCTL_REFSEL_Pos                   9                                         /*!< DAC COMCTL: REFSEL Position */
#define DAC_COMCTL_REFSEL_Msk                   (0x3ul << DAC_COMCTL_REFSEL_Pos)          /*!< DAC COMCTL: REFSEL Mask */

#define DAC_COMCTL_DAC01GRP_Pos                 8                                         /*!< DAC COMCTL: DAC01GRP Position */
#define DAC_COMCTL_DAC01GRP_Msk                 (0x1ul << DAC_COMCTL_DAC01GRP_Pos)        /*!< DAC COMCTL: DAC01GRP Mask */

#define DAC_COMCTL_WAITDACCONV_Pos              0                                         /*!< DAC COMCTL: WAITDACCONV Position */
#define DAC_COMCTL_WAITDACCONV_Msk              (0xFFul << DAC_COMCTL_WAITDACCONV_Pos)    /*!< DAC COMCTL: WAITDACCONV Mask */

/*@}*/ /* end of group NANO100_DAC */

/*------------- Flash Memory Controller (FMC) -----------------------------*/
/** @addtogroup NANO100_FMC NANO100 Flash Memory Controller Register (FMC)
  Memory Mapped Structure for NANO100 Series Flash Memory Controller
  @{
*/
/**
  * @brief FMC register map
  */
typedef struct {
    __IO uint32_t  ISPCON;                    /*!< Offset: 0x0000   ISP Control Register                               */
    __IO uint32_t  ISPADR;                    /*!< Offset: 0x0004   ISP Address Register                               */
    __IO uint32_t  ISPDAT;                    /*!< Offset: 0x0008   ISP Data Register                                  */
    __IO uint32_t  ISPCMD;                    /*!< Offset: 0x000C   ISP Command Register                               */
    __IO uint32_t  ISPTRG;                    /*!< Offset: 0x0010   ISP Trigger Register                               */
    __I  uint32_t  DFBADR;                    /*!< Offset: 0x0014   Data Flash Start Address (CONFIG1)                 */
    __I  uint32_t  RESERVED0[10];
    __IO uint32_t  ISPSTA;                    /*!< Offset: 0x0040   ISP Status Register                                */
} FMC_T;


/* FMC ISPCON Bit Field Definitions */
#define FMC_ISPCON_ISPFF_Pos                    6                                       /*!< FMC ISPCON: ISPFF Position */
#define FMC_ISPCON_ISPFF_Msk                    (1ul << FMC_ISPCON_ISPFF_Pos)           /*!< FMC ISPCON: ISPFF Mask */

#define FMC_ISPCON_LDUEN_Pos                    5                                       /*!< FMC ISPCON: LDUEN Position */
#define FMC_ISPCON_LDUEN_Msk                    (1ul << FMC_ISPCON_LDUEN_Pos)           /*!< FMC ISPCON: LDUEN Mask */

#define FMC_ISPCON_CFGUEN_Pos                   4                                       /*!< FMC ISPCON: CFGUEN Position */
#define FMC_ISPCON_CFGUEN_Msk                   (1ul << FMC_ISPCON_CFGUEN_Pos)          /*!< FMC ISPCON: CFGUEN Mask */

#define FMC_ISPCON_APUEN_Pos                    3                                       /*!< FMC ISPCON: APUEN Position */
#define FMC_ISPCON_APUEN_Msk                    (1ul << FMC_ISPCON_APUEN_Pos)           /*!< FMC ISPCON: APUEN Mask */

#define FMC_ISPCON_BS_Pos                       1                                       /*!< FMC ISPCON: BS Position */
#define FMC_ISPCON_BS_Msk                       (1ul << FMC_ISPCON_BS_Pos)              /*!< FMC ISPCON: BS Mask */

#define FMC_ISPCON_ISPEN_Pos                    0                                       /*!< FMC ISPCON: ISPEN Position */
#define FMC_ISPCON_ISPEN_Msk                    (1ul << FMC_ISPCON_ISPEN_Pos)           /*!< FMC ISPCON: ISPEN Mask */

/* FMC ISPCMD Bit Field Definitions */
#define FMC_ISPCMD_FOEN_Pos                     5                                       /*!< FMC ISPCMD: FOEN Position */
#define FMC_ISPCMD_FOEN_Msk                     (1ul << FMC_ISPCMD_FOEN_Pos)            /*!< FMC ISPCMD: FOEN Mask */

#define FMC_ISPCMD_FCEN_Pos                     4                                       /*!< FMC ISPCMD: FCEN Position */
#define FMC_ISPCMD_FCEN_Msk                     (1ul << FMC_ISPCMD_FCEN_Pos)            /*!< FMC ISPCMD: FCEN Mask */

#define FMC_ISPCMD_FCTRL_Pos                    0                                       /*!< FMC ISPCMD: FCTRL Position */
#define FMC_ISPCMD_FCTRL_Msk                    (0xFul << FMC_ISPCMD_FCTRL_Pos)         /*!< FMC ISPCMD: FCTRL Mask */

/* FMC ISPTRG Bit Field Definitions */
#define FMC_ISPTRG_ISPGO_Pos                    0                                       /*!< FMC ISPTRG: ISPGO Position */
#define FMC_ISPTRG_ISPGO_Msk                    (1ul << FMC_ISPTRG_ISPGO_Pos)           /*!< FMC ISPTRG: ISPGO Mask */


/*@}*/ /* end of group NANO100_FMC */


/*------------- General Purpose I/O (GPIO) -----------------------------*/
/** @addtogroup NANO100_GPIO NANO100 General Purpose I/O (GPIO)
  Memory Mapped Structure for NANO100 Series General Purpose I/O
  @{
*/
/**
  * @brief GPIO register map
  */
typedef struct {
    __IO uint32_t  PMD;                        /*!< Offset: 0x0000   GPIO Port Bit Mode Control                         */
    __IO uint32_t  OFFD;                       /*!< Offset: 0x0004   GPIO Port Bit Off Digital Enable                   */
    __IO uint32_t  DOUT;                       /*!< Offset: 0x0008   GPIO Port Data Output                              */
    __IO uint32_t  DMASK;                      /*!< Offset: 0x000C   GPIO Port Data Output Write Mask                   */
    __I  uint32_t  PIN;                        /*!< Offset: 0x0010   GPIO Port Pin Value                                */
    __IO uint32_t  DBEN;                       /*!< Offset: 0x0014   GPIO Port De-bounce Enable                         */
    __IO uint32_t  IMD;                        /*!< Offset: 0x0018   GPIO Port Interrupt Mode Select                    */
    __IO uint32_t  IER;                        /*!< Offset: 0x001C   GPIO Port Interrupt Enable                         */
    __IO uint32_t  ISR;                        /*!< Offset: 0x0020   GPIO Port Interrupt Source Flag                    */
    __IO uint32_t  PUEN;                       /*!< Offset: 0x0024   GPIO Port Pull-Up Enable                           */
} GPIO_T;


/**
  * @brief GPIO debounce control register map
  */
typedef struct {
    __IO uint32_t  DBNCECON;                        /*!< Offset: 0x0000   GPIO De-bounce Cycle Control Register              */
} GPIODBNCE_T;

/* GPIO DBNCECON Bit Field Definitions */
#define GPIO_DBNCECON_ICLK_ON_Pos   5                                           /*!< GPIO DBNCECON: ICLK_ON  Position */
#define GPIO_DBNCECON_ICLK_ON_Msk   (1ul << GPIO_DBNCECON_ICLK_ON_Pos)          /*!< GPIO DBNCECON: ICLK_ON  Mask */

#define GPIO_DBNCECON_DBCLKSRC_Pos  4                                           /*!< GPIO DBNCECON: DBCLKSRC Position */
#define GPIO_DBNCECON_DBCLKSRC_Msk  (1ul << GPIO_DBNCECON_DBCLKSRC_Pos)         /*!< GPIO DBNCECON: DBCLKSRC Mask */

#define GPIO_DBNCECON_DBCLKSEL_Pos  0                                           /*!< GPIO DBNCECON: DBCLKSEL Position */
#define GPIO_DBNCECON_DBCLKSEL_Msk  (0xFul << GPIO_DBNCECON_DBCLKSEL_Pos)       /*!< GPIO DBNCECON: DBCLKSEL Mask */

/*@}*/ /* end of group NANO100_GPIO */



/*------------- I2C Serial Interface Controller (Master/Slave) (I2C) -----------------------------*/
/** @addtogroup NANO100_I2C NANO100 I2C Controller Register (I2C)
  Memory Mapped Structure for NANO100 Series I2C Controller
  @{
*/
/**
  * @brief I2C register map
  */
typedef struct {
    __IO uint32_t  CON;                    /*!< Offset: 0x0000   I2C Control Register                               */
    __IO uint32_t  INTSTS;                 /*!< Offset: 0x0004   I2C Control Flag Register                          */
    __I  uint32_t  STATUS;                 /*!< Offset: 0x0008   I2C Status Register                                */
    __IO uint32_t  DIV;                    /*!< Offset: 0x000C   I2C Clock Divided Register                         */
    __IO uint32_t  TOUT;                   /*!< Offset: 0x0010   I2C Time Out Control Register                      */
    __IO uint32_t  DATA;                   /*!< Offset: 0x0014   I2C Data Register                                  */
    __IO uint32_t  SADDR0;                 /*!< Offset: 0x0018   Slave Address Register 0                           */
    __IO uint32_t  SADDR1;                 /*!< Offset: 0x001C   Slave Address Register 1                           */
    uint32_t  RESERVED0;
    uint32_t  RESERVED1;
    __IO uint32_t  SAMASK0;                /*!< Offset: 0x0028   Slave Address Mask Register 0                      */
    __IO uint32_t  SAMASK1;                /*!< Offset: 0x002C   Slave Address Mask Register 1                      */
    uint32_t  RESERVED2[4];
    __IO uint32_t  WKUPCON;                /*!< Offset: 0x003C   I2C Wake-up Control Register                       */
    __IO uint32_t  WKUPSTS;                /*!< Offset: 0x0040   I2C Wake-up Status Register                        */

} I2C_T;
/*@}*/ /* end of group NANO100_I2C */

/* I2C CON Bit Field Definitions */
#define I2C_CON_INTEN_Pos                   7                                                /*!< I2C CON: INTEN Position */
#define I2C_CON_INTEN_Msk                   (0x1ul << I2C_CON_INTEN_Pos)                     /*!< I2C CON: INTEN Mask */
#define I2C_CON_I2C_STS_Pos                 4                                                /*!< I2C CON: I2C_STS Position */
#define I2C_CON_I2C_STS_Msk                 (0x1ul << I2C_CON_I2C_STS_Pos)                   /*!< I2C CON: I2C_STS Mask */
#define I2C_CON_START_Pos                   3                                                /*!< I2C CON: START Position */
#define I2C_CON_START_Msk                   (0x1ul << I2C_CON_START_Pos)                     /*!< I2C CON: START Mask */
#define I2C_CON_STOP_Pos                    2                                                /*!< I2C CON: STOP Position */
#define I2C_CON_STOP_Msk                    (0x1ul << I2C_CON_STOP_Pos)                      /*!< I2C CON: STOP Mask */
#define I2C_CON_ACK_Pos                     1                                                /*!< I2C CON: ACK Position */
#define I2C_CON_ACK_Msk                     (0x1ul << I2C_CON_ACK_Pos)                       /*!< I2C CON: ACK Mask */
#define I2C_CON_IPEN_Pos                    0                                                /*!< I2C CON: IPEN Position */
#define I2C_CON_IPEN_Msk                    (0x1ul << I2C_CON_IPEN_Pos)                      /*!< I2C CON: IPEN Mask */

/* I2C INTSTS Bit Field Definitions */
#define I2C_INTSTS_TIF_Pos                  1                                                /*!< I2C INTSTS: TIF Position */
#define I2C_INTSTS_TIF_Msk                  (0x1ul << I2C_INTSTS_TIF_Pos)                    /*!< I2C INTSTS: TIF Mask */
#define I2C_INTSTS_INTSTS_Pos               0                                                /*!< I2C INTSTS: INTSTS Position */
#define I2C_INTSTS_INTSTS_Msk               (0x1ul << I2C_INTSTS_INTSTS_Pos)                 /*!< I2C INTSTS: INTSTS Mask */

/* I2C TOUT Bit Field Definitions */
#define I2C_TOUT_DIV4_Pos                   1                                                /*!< I2C TOUT: DIV4 Position */
#define I2C_TOUT_DIV4_Msk                   (0x1ul << I2C_TOUT_DIV4_Pos)                     /*!< I2C TOUT: DIV4 Mask */
#define I2C_TOUT_TOUTEN_Pos                 0                                                /*!< I2C TOUT: TOUTEN Position */
#define I2C_TOUT_TOUTEN_Msk                 (0x1ul << I2C_TOUT_TOUTEN_Pos)                   /*!< I2C TOUT: TOUTEN Mask */

/* I2C SADDR0 Bit Field Definitions */
#define I2C_SADDR0_SADDR_Pos                1                                                /*!< I2C SADDR0: SADDR Position */
#define I2C_SADDR0_SADDR_Msk                (0x7Ful << I2C_SADDR0_SADDR_Pos)                 /*!< I2C SADDR0: SADDR Mask */
#define I2C_SADDR0_GCALL_Pos                0                                                /*!< I2C SADDR0: GCALL Position */
#define I2C_SADDR0_GCALL_Msk                (0x1ul << I2C_SADDR0_GCALL_Pos)                  /*!< I2C SADDR0: GCALL Mask */

/* I2C SADDR1 Bit Field Definitions */
#define I2C_SADDR1_SADDR_Pos                1                                                /*!< I2C SADDR1: SADDR Position */
#define I2C_SADDR1_SADDR_Msk                (0x7Ful << I2C_SADDR1_SADDR_Pos)                 /*!< I2C SADDR1: SADDR Mask */
#define I2C_SADDR1_GCALL_Pos                0                                                /*!< I2C SADDR1: GCALL Position */
#define I2C_SADDR1_GCALL_Msk                (0x1ul << I2C_SADDR1_GCALL_Pos)                  /*!< I2C SADDR1: GCALL Mask */

/* I2C SAMASK0 Bit Field Definitions */
#define I2C_SAMASK0_SAMASK_Pos              1                                                /*!< I2C SAMASK0: SAMASK Position */
#define I2C_SAMASK0_SAMASK_Msk              (0x7Ful << I2C_SAMASK0_SAMASK_Pos)               /*!< I2C SAMASK0: SAMASK Mask */

/* I2C SAMASK1 Bit Field Definitions */
#define I2C_SAMASK1_SAMASK_Pos              1                                                /*!< I2C SAMASK1: SAMASK Position */
#define I2C_SAMASK1_SAMASK_Msk              (0x7Ful << I2C_SAMASK1_SAMASK_Pos)               /*!< I2C SAMASK1: SAMASK Mask */

/* I2C WKUPCON Bit Field Definitions */
#define I2C_WKUPCON_WKUPEN_Pos              0                                                /*!< I2C WKUPCON: WKUPEN Position */
#define I2C_WKUPCON_WKUPEN_Msk              (0x1ul << I2C_WKUPCON_WKUPEN_Pos)                /*!< I2C WKUPCON: WKUPEN Mask */

/* I2C WKUPSTS Bit Field Definitions */
#define I2C_WKUPSTS_WKUPIF_Pos              0                                                /*!< I2C WKUPSTS: WKUPIF Position */
#define I2C_WKUPSTS_WKUPIF_Msk              (0x1ul << I2C_WKUPSTS_WKUPIF_Pos)                /*!< I2C WKUPSTS: WKUPIF Mask */


/*------------- EBI Control Register  -----------------------------*/
/** @addtogroup NANO100_EBI NANO100 EBI Control Register (EBI)
  Memory Mapped Structure for NANO100 Series EBI Controller
  @{
*/
/**
  * @brief EBI register map
  */
typedef struct {
    __IO uint32_t  EBICON;                          /*!< Offset: 0x0000   External Bus Interface General Control Register */
    __IO uint32_t  EXTIME;                          /*!< Offset: 0x0004   External Bus Interface Timing Control Register  */
} EBI_T;


/* EBI EBICON Bit Field Definitions */
#define EBI_EBICON_ExttALE_Pos          16                                   /*!< EBI EBICON : ExttALE Position    */
#define EBI_EBICON_ExttALE_Msk          (0x7ul << EBI_EBICON_ExttALE_Pos)    /*!< EBI EBICON : ExttALE Mask        */

#define EBI_EBICON_MCLKEN_Pos           11                                   /*!< EBI EBICON : MCLKEN Position     */
#define EBI_EBICON_MCLKEN_Msk           (1ul << EBI_EBICON_MCLKEN_Pos)       /*!< EBI EBICON : MCLKEN Mask         */

#define EBI_EBICON_MCLKDIV_Pos          8                                    /*!< EBI EBICON : MCLKDIV Position    */
#define EBI_EBICON_MCLKDIV_Msk          (0x7ul << EBI_EBICON_MCLKDIV_Pos)    /*!< EBI EBICON : MCLKDIV Mask        */

#define EBI_EBICON_ExtBW16_Pos          1                                    /*!< EBI EBICON : ExtBW16 Position    */
#define EBI_EBICON_ExtBW16_Msk          (1ul << EBI_EBICON_ExtBW16_Pos)      /*!< EBI EBICON : ExtBW16 Mask        */

#define EBI_EBICON_ExtEN_Pos            0                                    /*!< EBI EBICON : ExtEN Position      */
#define EBI_EBICON_ExtEN_Msk            (1ul << EBI_EBICON_ExtEN_Pos)        /*!< EBI EBICON : ExtEN Mask          */

/* EBI EXTIME Bit Field Definitions */
#define EBI_EXTIME_ExtIR2R_Pos          24                                   /*!< EBI EXTIME : ExtIR2R Position    */
#define EBI_EXTIME_ExtIR2R_Msk          (0xful << EBI_EXTIME_ExtIR2R_Pos)    /*!< EBI EXTIME : ExtIR2R Mask        */

#define EBI_EXTIME_ExtIR2W_Pos          16                                   /*!< EBI EXTIME : ExtIR2W Position    */
#define EBI_EXTIME_ExtIR2W_Msk          (0xful << EBI_EXTIME_ExtIR2W_Pos)    /*!< EBI EXTIME : ExtIR2W Mask        */

#define EBI_EXTIME_ExtIW2X_Pos          12                                   /*!< EBI EXTIME : ExtIW2X Position    */
#define EBI_EXTIME_ExtIW2X_Msk          (0xful << EBI_EXTIME_ExtIW2X_Pos)    /*!< EBI EXTIME : ExtIW2X Mask        */

#define EBI_EXTIME_ExttAHD_Pos          8                                    /*!< EBI EXTIME : ExttAHD Position    */
#define EBI_EXTIME_ExttAHD_Msk          (0x7ul << EBI_EXTIME_ExttAHD_Pos)    /*!< EBI EXTIME : ExttAHD Mask        */

#define EBI_EXTIME_ExttACC_Pos          0                                    /*!< EBI EXTIME : ExttACC Position    */
#define EBI_EXTIME_ExttACC_Msk          (0x1ful << EBI_EXTIME_ExttACC_Pos)   /*!< EBI EXTIME : ExttACC Mask        */

/*@}*/ /* end of group NANO100_EBI */


/*------------- USB Device Controller (USBD) -----------------------------*/
/** @addtogroup NANO100_USBD NANO100 USBD Control Register (USBD)
  Memory Mapped Structure for NANO100 Series USBD Controller
  @{
*/
/**
  * @brief USBD endpoints register
  */
typedef struct {
    __IO uint32_t  BUFSEG;      /*!< USB Endpoint Buffer Segmentation Register    */
    __IO uint32_t  MXPLD;       /*!< USB Endpoint Maximal Payload Register        */
    __IO uint32_t  CFG;         /*!< USB Endpoint Configuration Register          */
    uint32_t  RESERVED;    /*!< Reserved                                     */

} USBD_EP_T;

/**
  * @brief USBD control register
  */
typedef struct {
    __IO uint32_t  CTRL;        /*!< Offset: 0x0000   USB Control Register                           */
    __I  uint32_t  BUSSTS;      /*!< Offset: 0x0004   USB Bus Status Register                        */
    __IO uint32_t  INTEN;       /*!< Offset: 0x0008   USB Interrupt Enable Register                  */
    __IO uint32_t  INTSTS;      /*!< Offset: 0x000C   USB Interrupt Event Status Register            */
    __IO uint32_t  FADDR;       /*!< Offset: 0x0010   USB Device's Function Address Register         */
    __I  uint32_t  EPSTS;       /*!< Offset: 0x0014   USB Endpoint Status Register                   */
    __IO uint32_t  STBUFSEG;    /*!< Offset: 0x0018   USB Setup Token Buffer Segmentation Register   */
    __I  uint32_t  EPSTS2;      /*!< Offset: 0x001C   USB Endpoint Status Register 2                 */
    USBD_EP_T EP[8];            /*!< Offset: 0x20     Endpoint Related Configuration Registers       */
    uint32_t  RESERVED0;   /*!< Offset: 0x00A0   Reserved                                       */
    __IO uint32_t  PDMA;        /*!< Offset: 0x00A4   USB PDMA Control Register                      */
} USBD_T;

/* USBD CTRL Bit Field Definitions */
#define USBD_CTRL_WAKEUP_EN_Pos    9                                    /*!< USB CTRL: WAKEUP_EN Position */
#define USBD_CTRL_WAKEUP_EN_Msk    (1ul << USBD_CTRL_WAKEUP_EN_Pos)     /*!< USB CTRL: WAKEUP_EN Mask */

#define USBD_CTRL_RWAKEUP_Pos      8                                    /*!< USB CTRL: RWAKEUP Position */
#define USBD_CTRL_RWAKEUP_Msk      (1ul << USBD_CTRL_RWAKEUP_Pos)       /*!< USB CTRL: RWAKEUP Mask */

#define USBD_CTRL_DRVSE0_Pos       4                                    /*!< USB CTRL: DRVSE0 Position */
#define USBD_CTRL_DRVSE0_Msk       (1ul << USBD_CTRL_DRVSE0_Pos)        /*!< USB CTRL: DRVSE0 Mask */

#define USBD_CTRL_DPPU_EN_Pos      3                                    /*!< USB CTRL: DPPU_EN Position */
#define USBD_CTRL_DPPU_EN_Msk      (1ul << USBD_CTRL_DPPU_EN_Pos)       /*!< USB CTRL: DPPU_EN Mask */

#define USBD_CTRL_PWRDB_Pos        2                                    /*!< USB CTRL: PWRDB Position */
#define USBD_CTRL_PWRDB_Msk        (1ul << USBD_CTRL_PWRDB_Pos)         /*!< USB CTRL: PWRDB Mask */

#define USBD_CTRL_PHY_EN_Pos       1                                    /*!< USB CTRL: PHY_EN Position */
#define USBD_CTRL_PHY_EN_Msk       (1ul << USBD_CTRL_PHY_EN_Pos)        /*!< USB CTRL: PHY_EN Mask */

#define USBD_CTRL_USB_EN_Pos       0                                    /*!< USB CTRL: USB_EN Position */
#define USBD_CTRL_USB_EN_Msk       (1ul << USBD_CTRL_USB_EN_Pos)        /*!< USB CTRL: USB_EN Mask */


/* USBD BUSSTS Bit Field Definitions */
#define USBD_BUSSTS_FLDET_Pos      4                                    /*!< USB BUSSTS: FLDET Position */
#define USBD_BUSSTS_FLDET_Msk      (1ul << USBD_BUSSTS_FLDET_Pos)       /*!< USB BUSSTS: FLDET Mask */

#define USBD_BUSSTS_TIMEOUT_Pos    3                                    /*!< USB BUSSTS: TIMEOUT Position */
#define USBD_BUSSTS_TIMEOUT_Msk    (1ul << USBD_BUSSTS_TIMEOUT_Pos)     /*!< USB BUSSTS: TIMEOUT Mask */

#define USBD_BUSSTS_RESUME_Pos     2                                    /*!< USB BUSSTS: RESUME Position */
#define USBD_BUSSTS_RESUME_Msk     (1ul << USBD_BUSSTS_RESUME_Pos)      /*!< USB BUSSTS: RESUME Mask */

#define USBD_BUSSTS_SUSPEND_Pos    1                                    /*!< USB BUSSTS: SUSPEND Position */
#define USBD_BUSSTS_SUSPEND_Msk    (1ul << USBD_BUSSTS_SUSPEND_Pos)     /*!< USB BUSSTS: SUSPEND Mask */

#define USBD_BUSSTS_RST_Pos        0                                    /*!< USB BUSSTS: RST Position */
#define USBD_BUSSTS_RST_Msk        (1ul << USBD_BUSSTS_RST_Pos)         /*!< USB BUSSTS: RST Mask */

/* USBD INTEN Bit Field Definitions */
#define USBD_INTEN_WAKEUP_IE_Pos   3                                    /*!< USB INTEN: WAKEUP_IE Position */
#define USBD_INTEN_WAKEUP_IE_Msk   (1ul << USBD_INTEN_WAKEUP_IE_Pos)    /*!< USB INTEN: WAKEUP_IE Mask */

#define USBD_INTEN_FLDET_IE_Pos    2                                    /*!< USB INTEN: FLDET_IE Position */
#define USBD_INTEN_FLDET_IE_Msk    (1ul << USBD_INTEN_FLDET_IE_Pos)     /*!< USB INTEN: FLDET_IE Mask */

#define USBD_INTEN_USBEVT_IE_Pos   1                                    /*!< USB INTEN: USBEVT_IE Position */
#define USBD_INTEN_USBEVT_IE_Msk   (1ul << USBD_INTEN_USBEVT_IE_Pos)    /*!< USB INTEN: USBEVT_IE Mask */

#define USBD_INTEN_BUSEVT_IE_Pos   0                                    /*!< USB INTEN: BUSEVT_IE Position */
#define USBD_INTEN_BUSEVT_IE_Msk   (1ul << USBD_INTEN_BUSEVT_IE_Pos)    /*!< USB INTEN: BUSEVT_IE Mask */

/* USBD INTSTS Bit Field Definitions */
#define USBD_INTSTS_SETUP_Pos      31                                   /*!< USB INTSTS: SETUP Position */
#define USBD_INTSTS_SETUP_Msk      (1ul << USBD_INTSTS_SETUP_Pos)       /*!< USB INTSTS: SETUP Mask */

#define USBD_INTSTS_EPEVT7_Pos     23                                   /*!< USB INTSTS: EPEVT7 Position */
#define USBD_INTSTS_EPEVT7_Msk     (1ul << USBD_INTSTS_EPEVT7_Pos)      /*!< USB INTSTS: EPEVT7 Mask */

#define USBD_INTSTS_EPEVT6_Pos     22                                   /*!< USB INTSTS: EPEVT6 Position */
#define USBD_INTSTS_EPEVT6_Msk     (1ul << USBD_INTSTS_EPEVT6_Pos)      /*!< USB INTSTS: EPEVT6 Mask */

#define USBD_INTSTS_EPEVT5_Pos     21                                   /*!< USB INTSTS: EPEVT5 Position */
#define USBD_INTSTS_EPEVT5_Msk     (1ul << USBD_INTSTS_EPEVT5_Pos)      /*!< USB INTSTS: EPEVT5 Mask */

#define USBD_INTSTS_EPEVT4_Pos     20                                   /*!< USB INTSTS: EPEVT4 Position */
#define USBD_INTSTS_EPEVT4_Msk     (1ul << USBD_INTSTS_EPEVT4_Pos)      /*!< USB INTSTS: EPEVT4 Mask */

#define USBD_INTSTS_EPEVT3_Pos     19                                   /*!< USB INTSTS: EPEVT3 Position */
#define USBD_INTSTS_EPEVT3_Msk     (1ul << USBD_INTSTS_EPEVT3_Pos)      /*!< USB INTSTS: EPEVT3 Mask */

#define USBD_INTSTS_EPEVT2_Pos     18                                   /*!< USB INTSTS: EPEVT2 Position */
#define USBD_INTSTS_EPEVT2_Msk     (1ul << USBD_INTSTS_EPEVT2_Pos)      /*!< USB INTSTS: EPEVT2 Mask */

#define USBD_INTSTS_EPEVT1_Pos     17                                   /*!< USB INTSTS: EPEVT1 Position */
#define USBD_INTSTS_EPEVT1_Msk     (1ul << USBD_INTSTS_EPEVT1_Pos)      /*!< USB INTSTS: EPEVT1 Mask */

#define USBD_INTSTS_EPEVT0_Pos     16                                   /*!< USB INTSTS: EPEVT0 Position */
#define USBD_INTSTS_EPEVT0_Msk     (1ul << USBD_INTSTS_EPEVT0_Pos)      /*!< USB INTSTS: EPEVT0 Mask */

#define USBD_INTSTS_WKEUP_STS_Pos  3                                    /*!< USB INTSTS: WKEUP_STS Position */
#define USBD_INTSTS_WKEUP_STS_Msk  (1ul << USBD_INTSTS_WKEUP_STS_Pos)   /*!< USB INTSTS: WKEUP_STS Mask */

#define USBD_INTSTS_FLD_STS_Pos    2                                    /*!< USB INTSTS: FLD_STS Position */
#define USBD_INTSTS_FLD_STS_Msk    (1ul << USBD_INTSTS_FLD_STS_Pos)     /*!< USB INTSTS: FLD_STS Mask */

#define USBD_INTSTS_USB_STS_Pos    1                                    /*!< USB INTSTS: USB_STS Position */
#define USBD_INTSTS_USB_STS_Msk    (1ul << USBD_INTSTS_USB_STS_Pos)     /*!< USB INTSTS: USB_STS Mask */

#define USBD_INTSTS_BUS_STS_Pos    0                                    /*!< USB INTSTS: BUS_STS Position */
#define USBD_INTSTS_BUS_STS_Msk    (1ul << USBD_INTSTS_BUS_STS_Pos)     /*!< USB INTSTS: BUS_STS Mask */

/* USBD FADDR Bit Field Definitions */
#define USBD_FADDR_Pos             0                                    /*!< USB FADDR: FADDR Position */
#define USBD_FADDR_Msk             (0x7Ful << USBD_FADDR_Pos)           /*!< USB FADDR: FADDR Mask */

/* USBD EPSTS Bit Field Definitions */
#define USBD_EPSTS_EPSTS5_Pos      28                                   /*!< USB EPSTS: EPSTS5 Position */
#define USBD_EPSTS_EPSTS5_Msk      (0xful << USBD_EPSTS_EPSTS5_Pos)     /*!< USB EPSTS: EPSTS5 Mask */

#define USBD_EPSTS_EPSTS4_Pos      24                                   /*!< USB EPSTS: EPSTS4 Position */
#define USBD_EPSTS_EPSTS4_Msk      (0xful << USBD_EPSTS_EPSTS4_Pos)     /*!< USB EPSTS: EPSTS4 Mask */

#define USBD_EPSTS_EPSTS3_Pos      20                                   /*!< USB EPSTS: EPSTS3 Position */
#define USBD_EPSTS_EPSTS3_Msk      (0xful << USBD_EPSTS_EPSTS3_Pos)     /*!< USB EPSTS: EPSTS3 Mask */

#define USBD_EPSTS_EPSTS2_Pos      16                                   /*!< USB EPSTS: EPSTS2 Position */
#define USBD_EPSTS_EPSTS2_Msk      (0xful << USBD_EPSTS_EPSTS2_Pos)     /*!< USB EPSTS: EPSTS2 Mask */

#define USBD_EPSTS_EPSTS1_Pos      12                                   /*!< USB EPSTS: EPSTS1 Position */
#define USBD_EPSTS_EPSTS1_Msk      (0xful << USBD_EPSTS_EPSTS1_Pos)     /*!< USB EPSTS: EPSTS1 Mask */

#define USBD_EPSTS_EPSTS0_Pos      8                                    /*!< USB EPSTS: EPSTS0 Position */
#define USBD_EPSTS_EPSTS0_Msk      (0xful << USBD_EPSTS_EPSTS0_Pos)     /*!< USB EPSTS: EPSTS0 Mask */

#define USBD_EPSTS_OVERRUN_Pos     7                                    /*!< USB EPSTS: OVERRUN Position */
#define USBD_EPSTS_OVERRUN_Msk     (1ul << USBD_EPSTS_OVERRUN_Pos)      /*!< USB EPSTS: OVERRUN Mask */

/* USBD STBUFSEG Bit Field Definitions */
#define USBD_STBUFSEG_Pos          3                                    /*!< USB STBUFSEG: STBUFSEG Position */
#define USBD_STBUFSEG_Msk          (0x3Ful << USBD_STBUFSEG_Pos)        /*!< USB STBUFSEG: STBUFSEG Mask */

/* USBD EPSTS2 Bit Field Definitions */
#define USBD_EPSTS2_EPSTS7_Pos      4                                   /*!< USB EPSTS2: EPSTS7 Position */
#define USBD_EPSTS2_EPSTS7_Msk      (0xful << USBD_EPSTS2_EPSTS7_Pos)   /*!< USB EPSTS2: EPSTS7 Mask */

#define USBD_EPSTS2_EPSTS6_Pos      0                                   /*!< USB EPSTS2: EPSTS6 Position */
#define USBD_EPSTS2_EPSTS6_Msk      (0xful << USBD_EPSTS2_EPSTS6_Pos)   /*!< USB EPSTS2: EPSTS6 Mask */

/* USBD BUFSEG Bit Field Definitions */
#define USBD_BUFSEG_BUFSEG_Pos      3                                   /*!< USB BUFSEG: BUFSEG Position */
#define USBD_BUFSEG_BUFSEG_Msk      (0x3Ful << USBD_BUFSEG_BUFSEG_Pos)  /*!< USB BUFSEG: BUFSEG Mask */

/* USBD MXPLD Bit Field Definitions */
#define USBD_MXPLD_MXPLD_Pos        0                                   /*!< USB MXPLD: MXPLD Position */
#define USBD_MXPLD_MXPLD_Msk        (0x1FFul << USBD_MXPLD_MXPLD_Pos)   /*!< USB MXPLD: MXPLD Mask */

/* USBD CFG Bit Field Definitions */
#define USBD_CFG_CLRRDY_Pos         15                                  /*!< USB CFG: CLRRDY Position */
#define USBD_CFG_CLRRDY_Msk         (1ul << USBD_CFG_CLRRDY_Pos)        /*!< USB CFG: CLRRDY Mask */

#define USBD_CFG_SSTALL_Pos         9                                   /*!< USB CFG: SSTALL Position */
#define USBD_CFG_SSTALL_Msk         (1ul << USBD_CFG_SSTALL_Pos)        /*!< USB CFG: SSTALL Mask */

#define USBD_CFG_CSTALL_Pos         8                                   /*!< USB CFG: CSTALL Position */
#define USBD_CFG_CSTALL_Msk         (1ul << USBD_CFG_CSTALL_Pos)        /*!< USB CFG: CSTALL Mask */

#define USBD_CFG_DSQ_SYNC_Pos       7                                   /*!< USB CFG: DSQ_SYNC Position */
#define USBD_CFG_DSQ_SYNC_Msk       (1ul << USBD_CFG_DSQ_SYNC_Pos)      /*!< USB CFG: DSQ_SYNC Mask */

#define USBD_CFG_EPMODE_Pos         5                                   /*!< USB CFG: EPMODE Position */
#define USBD_CFG_EPMODE_Msk         3ul << USBD_CFG_EPMODE_Pos)         /*!< USB CFG: EPMODE Mask */

#define USBD_CFG_ISOCH_Pos          4                                   /*!< USB CFG: ISOCH Position */
#define USBD_CFG_ISOCH_Msk          (1ul << USBD_CFG_ISOCH_Pos)         /*!< USB CFG: ISOCH Mask */

#define USBD_CFG_EP_NUM_Pos         0                                   /*!< USB CFG: EP_NUM Position */
#define USBD_CFG_EP_NUM_Msk         (0xFul << USBD_CFG_EP_NUM_Pos)      /*!< USB CFG: EP_NUM Mask */

/* USBD PDMA Bit Field Definitions */
#define USBD_PDMA_RST_Pos           3                                   /*!< USB PDMA: RST Position */
#define USBD_PDMA_RST_Msk           (1ul << USBD_PDMA_RST_Pos)          /*!< USB PDMA: RST Mask */

#define USBD_PDMA_BYTEM_Pos         2                                   /*!< USB PDMA: BYTEM Position */
#define USBD_PDMA_BYTEM_Msk         (1ul << USBD_PDMA_BYTEM_Pos)        /*!< USB PDMA: BYTEM Mask */

#define USBD_PDMA_TRG_Pos           1                                   /*!< USB PDMA: TRG Position */
#define USBD_PDMA_TRG_Msk           (1ul << USBD_PDMA_TRG_Pos)          /*!< USB PDMA: TRG Mask */

#define USBD_PDMA_RW_Pos            0                                   /*!< USB PDMA: RW Position */
#define USBD_PDMA_RW_Msk            (1ul << USBD_PDMA_RW_Pos)           /*!< USB PDMA: RW Mask */


/*@}*/ /* end of group NANO100_USBD */


/*------------- PDMA Control Register (PDMA) -----------------------------*/
/** @addtogroup NANO100_PDMA NANO100 PDMA Control Register (PDMA)
  Memory Mapped Structure for NANO100 Series PDMA Controller
  @{
*/

/**
  * @brief VDMA register map
  */
typedef struct {
    __IO uint32_t  CSR;                            /*!< Offset: 0x0000   VDMA Control Register                          */
    __IO uint32_t  SAR;                            /*!< Offset: 0x0004   VDMA Source Address Register                   */
    __IO uint32_t  DAR;                            /*!< Offset: 0x0008   VDMA Destination Address Register              */
    __IO uint32_t  BCR;                            /*!< Offset: 0x000C   VDMA Transfer Byte Count Register              */
    uint32_t  RESERVED0;                      /*!< Offset: 0x0010   Reserved                                       */
    __I  uint32_t  CSAR;                           /*!< Offset: 0x0014   VDMA Current Source Address Register           */
    __I  uint32_t  CDAR;                           /*!< Offset: 0x0018   VDMA Current Destination Address Register      */
    __I  uint32_t  CBCR;                           /*!< Offset: 0x001C   VDMA Current Transfer Byte Count Register      */
    __IO uint32_t  IER;                            /*!< Offset: 0x0020   VDMA Interrupt Enable Register                 */
    __IO uint32_t  ISR;                            /*!< Offset: 0x0024   VDMA Interrupt Status Register                 */
    uint32_t  RESERVED1;                      /*!< Offset: 0x0028   Reserved                                       */
    __IO uint32_t  SASOCR;                         /*!< Offset: 0x002C   VDMA Source Address Stride Offset Register     */
    __IO uint32_t  DASOCR;                         /*!< Offset: 0x0030   VDMA Destination Address Stride Offset Register*/
    uint32_t  RESERVED2[19];                  /*!< Offset: 0x0034~0x007C   Reserved                                */
    __I  uint32_t  BUF0;                           /*!< Offset: 0x0080   VDMA Internal Buffer FIFO 0                    */
    __I  uint32_t  BUF1;                           /*!< Offset: 0x0084   VDMA Internal Buffer FIFO 1                    */
} VDMA_T;

/* PDMA CSR Bit Field Definitions */
#define VDMA_CSR_TRIG_EN_Pos                        23                              /*!< VDMA CSR: TRIG_EN Position */
#define VDMA_CSR_TRIG_EN_Msk                        (1ul << VDMA_CSR_TRIG_EN_Pos)   /*!< VDMA CSR: TRIG_EN Mask */

#define VDMA_CSR_DIR_SEL_Pos                        11                              /*!< VDMA CSR: DIR_SEL Position */
#define VDMA_CSR_DIR_SEL_Msk                        (1ul << VDMA_CSR_DIR_SEL_Pos)   /*!< VDMA CSR: DIR_SEL Mask */

#define VDMA_CSR_STRIDE_EN_Pos                      10                              /*!< VDMA CSR: STRIDE_EN Position */
#define VDMA_CSR_STRIDE_EN_Msk                      (1ul << VDMA_CSR_STRIDE_EN_Pos) /*!< VDMA CSR: STRIDE_EN Mask */

#define VDMA_CSR_SW_RST_Pos                         1                               /*!< VDMA CSR: SW_RST Position */
#define VDMA_CSR_SW_RST_Msk                         (1ul << VDMA_CSR_SW_RST_Pos)    /*!< VDMA CSR: SW_RST Mask */

#define VDMA_CSR_VDMACEN_Pos                        0                               /*!< VDMA CSR: VDMACEN Position */
#define VDMA_CSR_VDMACEN_Msk                        (1ul << VDMA_CSR_VDMACEN_Pos)   /*!< VDMA CSR: VDMACEN Mask */

/* VDMA BCR Bit Field Definitions */
#define VDMA_BCR_BCR_Pos                            0                               /*!< VDMA BCR: BCR Position */
#define VDMA_BCR_BCR_Msk                            (0xFFFFul << VDMA_BCR_BCR_Pos)  /*!< VDMA BCR: BCR Mask */

/* VDMA IER Bit Field Definitions */
#define VDMA_IER_TD_IE_Pos                          1                               /*!< VDMA IER: TD_IE Position */
#define VDMA_IER_TD_IE_Msk                          (1ul << VDMA_IER_TD_IE_Pos)     /*!< VDMA IER: TD_IE Mask */

#define VDMA_IER_TABORT_IE_Pos                      0                               /*!< VDMA IER: TABORT_IE Position */
#define VDMA_IER_TABORT_IE_Msk                      (1ul << VDMA_IER_TABORT_IE_Pos) /*!< VDMA IER: TABORT_IE Mask */

/* VDMA ISR Bit Field Definitions */
#define VDMA_ISR_TD_IF_Pos                          1                               /*!< VDMA ISR: TD_IF Position */
#define VDMA_ISR_TD_IF_Msk                          (1ul << VDMA_ISR_TD_IF_Pos)     /*!< VDMA ISR: TD_IF Mask */

#define VDMA_ISR_TABORT_IF_Pos                      0                               /*!< VDMA ISR: TABORT_IF Position */
#define VDMA_ISR_TABORT_IF_Msk                      (1ul << VDMA_ISR_TABORT_IF_Pos) /*!< VDMA ISR: TABORT_IF Mask */

/* VDMA SASOCR Bit Field Definitions */
#define VDMA_SASOCR_STBC_Pos                        16                                  /*!< VDMA SASOCR: STBC Position */
#define VDMA_SASOCR_STBC_Msk                        (0xFFFFul << VDMA_SASOCR_STBC_Pos)  /*!< VDMA SASOCR: STBC Mask */

#define VDMA_SASOCR_SASTOBL_Pos                     0                                      /*!< VDMA SASOCR: SASTOBL Position */
#define VDMA_SASOCR_SASTOBL_Msk                     (0xFFFFul << VDMA_SASOCR_SASTOBL_Pos)  /*!< VDMA SASOCR: SASTOBL Mask */

/* VDMA DASOCR Bit Field Definitions */
#define VDMA_DASOCR_DASTOBL_Pos                     0                                      /*!< VDMA DASOCR: DASTOBL Position */
#define VDMA_DASOCR_DASTOBL_Msk                     (0xFFFFul << VDMA_DASOCR_DASTOBL_Pos)  /*!< VDMA DASOCR: DASTOBL Mask */


/**
  * @brief PDMA register map
  */
typedef struct {
    __IO uint32_t  CSR;                             /*!< Offset: 0x0000   PDMA Control Register                          */
    __IO uint32_t  SAR;                             /*!< Offset: 0x0004   PDMA Source Address Register                   */
    __IO uint32_t  DAR;                             /*!< Offset: 0x0008   PDMA Destination Address Register              */
    __IO uint32_t  BCR;                             /*!< Offset: 0x000C   PDMA Transfer Byte Count Register              */
    uint32_t  RESERVED0;                       /*!< Offset: 0x0010   Reserved                                       */
    __I  uint32_t  CSAR;                            /*!< Offset: 0x0014   PDMA Current Source Address Register           */
    __I  uint32_t  CDAR;                            /*!< Offset: 0x0018   PDMA Current Destination Address Register      */
    __I  uint32_t  CBCR;                            /*!< Offset: 0x001C   PDMA Current Transfer Byte Count Register      */
    __IO uint32_t  IER;                             /*!< Offset: 0x0020   PDMA Interrupt Enable Register                 */
    __IO uint32_t  ISR;                             /*!< Offset: 0x0024   PDMA Interrupt Status Register                 */
    __IO uint32_t  TCR;                             /*!< Offset: 0x0028   PDMA Timer Counter Setting Register            */
    uint32_t  RESERVED1[21];                   /*!< Offset: 0x002C~0x7C   Reserved                                  */
    __I  uint32_t  BUF0;                            /*!< Offset: 0x0080   PDMA Internal Buffer FIFO                      */
} PDMA_T;

/* PDMA CSR Bit Field Definitions */
#define PDMA_CSR_TRIG_EN_Pos                        23                              /*!< PDMA CSR: TRIG_EN Position */
#define PDMA_CSR_TRIG_EN_Msk                        (1ul << PDMA_CSR_TRIG_EN_Pos)   /*!< PDMA CSR: TRIG_EN Mask */

#define PDMA_CSR_APB_TWS_Pos                        19                              /*!< PDMA CSR: APB_TWS Position */
#define PDMA_CSR_APB_TWS_Msk                        (3ul << PDMA_CSR_APB_TWS_Pos)   /*!< PDMA CSR: APB_TWS Mask */

#define PDMA_CSR_TO_EN_Pos                          12                              /*!< PDMA CSR: TO_EN Position */
#define PDMA_CSR_TO_EN_Msk                          (1ul << PDMA_CSR_TO_EN_Pos)     /*!< PDMA CSR: TO_EN Mask */

#define PDMA_CSR_DAD_SEL_Pos                        6                               /*!< PDMA CSR: DAD_SEL Position */
#define PDMA_CSR_DAD_SEL_Msk                        (3ul << PDMA_CSR_DAD_SEL_Pos)   /*!< PDMA CSR: DAD_SEL Mask */

#define PDMA_CSR_SAD_SEL_Pos                        4                               /*!< PDMA CSR: SAD_SEL Position */
#define PDMA_CSR_SAD_SEL_Msk                        (3ul << PDMA_CSR_SAD_SEL_Pos)   /*!< PDMA CSR: SAD_SEL Mask */

#define PDMA_CSR_MODE_SEL_Pos                       2                               /*!< PDMA CSR: MODE_SEL Position */
#define PDMA_CSR_MODE_SEL_Msk                       (3ul << PDMA_CSR_MODE_SEL_Pos)  /*!< PDMA CSR: MODE_SEL Mask */

#define PDMA_CSR_SW_RST_Pos                         1                               /*!< PDMA CSR: SW_RST Position */
#define PDMA_CSR_SW_RST_Msk                         (1ul << PDMA_CSR_SW_RST_Pos)    /*!< PDMA CSR: SW_RST Mask */

#define PDMA_CSR_PDMACEN_Pos                        0                               /*!< PDMA CSR: PDMACEN Position */
#define PDMA_CSR_PDMACEN_Msk                        (1ul << PDMA_CSR_PDMACEN_Pos)   /*!< PDMA CSR: PDMACEN Mask */

/* PDMA BCR Bit Field Definitions */
#define PDMA_BCR_BCR_Pos                            0                               /*!< PDMA BCR: BCR Position */
#define PDMA_BCR_BCR_Msk                            (0xFFFFul << PDMA_BCR_BCR_Pos)  /*!< PDMA BCR: BCR Mask */

/* PDMA IER Bit Field Definitions */
#define PDMA_IER_TO_IE_Pos                          6                               /*!< PDMA IER: TO_IE Position */
#define PDMA_IER_TO_IE_Msk                          (1ul << PDMA_IER_TO_IE_Pos)     /*!< PDMA IER: TO_IE Mask */

#define PDMA_IER_WRA_HT_IE_Pos                      4                               /*!< PDMA IER: WRA_HT_IE Position */
#define PDMA_IER_WRA_HT_IE_Msk                      (1ul << PDMA_IER_WRA_HT_IE_Pos) /*!< PDMA IER: WRA_HT_IE Mask */

#define PDMA_IER_WRA_TC_IE_Pos                      2                               /*!< PDMA IER: WRA_TC_IE Position */
#define PDMA_IER_WRA_TC_IE_Msk                      (1ul << PDMA_IER_WRA_TC_IE_Pos) /*!< PDMA IER: WRA_TC_IE Mask */

#define PDMA_IER_BLKD_IE_Pos                        1                               /*!< PDMA IER: BLKD_IE Position */
#define PDMA_IER_BLKD_IE_Msk                        (1ul << PDMA_IER_BLKD_IE_Pos)   /*!< PDMA IER: BLKD_IE Mask */

#define PDMA_IER_TABORT_IE_Pos                      0                               /*!< PDMA IER: TABORT_IE Position */
#define PDMA_IER_TABORT_IE_Msk                      (1ul << PDMA_IER_TABORT_IE_Pos) /*!< PDMA IER: TABORT_IE Mask */

/* PDMA ISR Bit Field Definitions */
#define PDMA_ISR_TO_IF_Pos                          6                               /*!< PDMA ISR: TO_IF Position */
#define PDMA_ISR_TO_IF_Msk                          (1ul << PDMA_ISR_TO_IF_Pos)     /*!< PDMA ISR: TO_IF Mask */

#define PDMA_ISR_WRA_HT_IF_Pos                      4                               /*!< PDMA ISR: WRA_HT_IF Position */
#define PDMA_ISR_WRA_HT_IF_Msk                      (1ul << PDMA_ISR_WRA_HT_IF_Pos) /*!< PDMA ISR: WRA_HT_IF Mask */

#define PDMA_ISR_WRA_TC_IF_Pos                      2                               /*!< PDMA ISR: WRA_TC_IF Position */
#define PDMA_ISR_WRA_TC_IF_Msk                      (1ul << PDMA_ISR_WRA_TC_IF_Pos) /*!< PDMA ISR: WRA_TC_IF Mask */

#define PDMA_ISR_BLKD_IF_Pos                        1                               /*!< PDMA ISR: BLKD_IF Position */
#define PDMA_ISR_BLKD_IF_Msk                        (1ul << PDMA_ISR_BLKD_IF_Pos)   /*!< PDMA ISR: BLKD_IF Mask */

#define PDMA_ISR_TABORT_IF_Pos                      0                               /*!< PDMA ISR: TABORT_IF Position */
#define PDMA_ISR_TABORT_IF_Msk                      (1ul << PDMA_ISR_TABORT_IF_Pos) /*!< PDMA ISR: TABORT_IF Mask */

/* PDMA TCR Bit Field Definitions */
#define PDMA_TCR_TCR_Pos                            0                               /*!< PDMA TCR: TCR Position */
#define PDMA_TCR_TCR_Msk                            (0xFFFFul << PDMA_TCR_TCR_Pos)  /*!< PDMA TCR: TCR Mask */


/**
  * @brief PDMA global control register map
  */
typedef struct {
    __IO uint32_t  CSR;                             /*!< Offset: 0x0000   DMA Global Control Register                    */
    __IO uint32_t  PDSSR0;                          /*!< Offset: 0x0004   DMA Service Selection Control Register 0       */
    __IO uint32_t  PDSSR1;                          /*!< Offset: 0x0008   DMA Service Selection Control Register 1       */
    __I  uint32_t  ISR;                             /*!< Offset: 0x000C   DMA Global Interrupt Register                  */
} PDMAGCR_T;

/* PDMA GCRCSR Bit Field Definitions */
#define PDMA_GCRCSR_CRC_CLK_EN_Pos                  24                                  /*!< PDMA GCRCSR: CRC_CLK_EN Position */
#define PDMA_GCRCSR_CRC_CLK_EN_Msk                  (1ul << PDMA_GCRCSR_CRC_CLK_EN_Pos) /*!< PDMA GCRCSR: CRC_CLK_EN Mask */

#define PDMA_GCRCSR_CLK4_EN_Pos                     12                                  /*!< PDMA GCRCSR: CLK4_EN Position */
#define PDMA_GCRCSR_CLK4_EN_Msk                     (1ul << PDMA_GCRCSR_CLK4_EN_Pos)    /*!< PDMA GCRCSR: CLK4_EN Mask */

#define PDMA_GCRCSR_CLK3_EN_Pos                     11                                  /*!< PDMA GCRCSR: CLK3_EN Position */
#define PDMA_GCRCSR_CLK3_EN_Msk                     (1ul << PDMA_GCRCSR_CLK3_EN_Pos)    /*!< PDMA GCRCSR: CLK3_EN Mask */

#define PDMA_GCRCSR_CLK2_EN_Pos                     10                                  /*!< PDMA GCRCSR: CLK2_EN Position */
#define PDMA_GCRCSR_CLK2_EN_Msk                     (1ul << PDMA_GCRCSR_CLK2_EN_Pos)    /*!< PDMA GCRCSR: CLK2_EN Mask */

#define PDMA_GCRCSR_CLK1_EN_Pos                     9                                   /*!< PDMA GCRCSR: CLK1_EN Position */
#define PDMA_GCRCSR_CLK1_EN_Msk                     (1ul << PDMA_GCRCSR_CLK1_EN_Pos)    /*!< PDMA GCRCSR: CLK1_EN Mask */

/* PDMA PDSSR0 Bit Field Definitions */
#define PDMA_PDSSR0_CH3_SEL_Pos                     24                                  /*!< PDMA PDSSR0: CH3_SEL Position */
#define PDMA_PDSSR0_CH3_SEL_Msk                     (0x1Ful << PDMA_PDSSR0_CH3_SEL_Pos) /*!< PDMA PDSSR0: CH3_SEL Mask */

#define PDMA_PDSSR0_CH2_SEL_Pos                     16                                  /*!< PDMA PDSSR0: CH2_SEL Position */
#define PDMA_PDSSR0_CH2_SEL_Msk                     (0x1Ful << PDMA_PDSSR0_CH2_SEL_Pos) /*!< PDMA PDSSR0: CH2_SEL Mask */

#define PDMA_PDSSR0_CH1_SEL_Pos                     8                                   /*!< PDMA PDSSR0: CH1_SEL Position */
#define PDMA_PDSSR0_CH1_SEL_Msk                     (0x1Ful << PDMA_PDSSR0_CH1_SEL_Pos) /*!< PDMA PDSSR0: CH1_SEL Mask */

/* PDMA PDSSR1 Bit Field Definitions */
#define PDMA_PDSSR1_CH4_SEL_Pos                     0                                   /*!< PDMA PDSSR1: CH4_SEL Position */
#define PDMA_PDSSR1_CH4_SEL_Msk                     (0x1Ful << PDMA_PDSSR1_CH4_SEL_Pos) /*!< PDMA PDSSR1: CH4_SEL Mask */


/**
  * @brief PDMA CRC control register map
  */
typedef struct {
    __IO uint32_t  CTL;
    __IO uint32_t  DMASAR;
    uint32_t  RESERVED0;
    __IO uint32_t  DMABCR;
    uint32_t  RESERVED1;
    __I  uint32_t  DMACSAR;
    uint32_t  RESERVED2;
    __I  uint32_t  DMACBCR;
    __IO uint32_t  DMAIER;
    __IO uint32_t  DMAISR;
    uint32_t  RESERVED3[22];
    __IO uint32_t  WDATA;
    __IO uint32_t  SEED;
    __I  uint32_t  CHECKSUM;
} PDMACRC_T;

/* CRC CTL Bit Field Definitions */
#define CRC_CTL_CRC_MODE_Pos            30                                      /*!< CRC CRC_CTL : CRC_MODE Position */
#define CRC_CTL_CRC_MODE_Msk            (0x3ul << CRC_CTL_CRC_MODE_Pos)         /*!< CRC CRC_CTL : CRC_MODE Mask */

#define CRC_CTL_CPU_WDLEN_Pos           28                                      /*!< CRC CRC_CTL : CPU_WDLEN Position */
#define CRC_CTL_CPU_WDLEN_Msk           (0x3ul << CRC_CTL_CPU_WDLEN_Pos)        /*!< CRC CRC_CTL : CPU_WDLEN Mask */

#define CRC_CTL_CHECKSUM_COM_Pos        27                                      /*!< CRC CRC_CTL : CHECKSUM_COM Position */
#define CRC_CTL_CHECKSUM_COM_Msk        (1ul << CRC_CTL_CHECKSUM_COM_Pos)       /*!< CRC CRC_CTL : CHECKSUM_COM Mask */

#define CRC_CTL_WDATA_COM_Pos           26                                      /*!< CRC CRC_CTL : WDATA_COM Position */
#define CRC_CTL_WDATA_COM_Msk           (1ul << CRC_CTL_WDATA_COM_Pos)          /*!< CRC CRC_CTL : WDATA_COM Mask */

#define CRC_CTL_CHECKSUM_RVS_Pos        25                                      /*!< CRC CRC_CTL : CHECKSUM_RVS Position */
#define CRC_CTL_CHECKSUM_RVS_Msk        (1ul << CRC_CTL_CHECKSUM_RVS_Pos)       /*!< CRC CRC_CTL : CHECKSUM_RVS Mask */

#define CRC_CTL_WDATA_RVS_Pos           24                                      /*!< CRC CRC_CTL : WDATA_RVS Position */
#define CRC_CTL_WDATA_RVS_Msk           (1ul << CRC_CTL_WDATA_RVS_Pos)          /*!< CRC CRC_CTL : WDATA_RVS Mask */

#define CRC_CTL_TRIG_EN_Pos             23                                      /*!< CRC CRC_CTL : TRIG_EN Position */
#define CRC_CTL_TRIG_EN_Msk             (1ul << CRC_CTL_TRIG_EN_Pos)            /*!< CRC CRC_CTL : TRIG_EN Mask */

#define CRC_CTL_CRC_RST_Pos             1                                       /*!< CRC CRC_CTL : CRC_RST Position */
#define CRC_CTL_CRC_RST_Msk             (1ul << CRC_CTL_CRC_RST_Pos)            /*!< CRC CRC_CTL : CRC_RST Mask */

#define CRC_CTL_CRCCEN_Pos              0                                       /*!< CRC CRC_CTL : CRCCEN Position */
#define CRC_CTL_CRCCEN_Msk              (1ul << CRC_CTL_CRCCEN_Pos)             /*!< CRC CRC_CTL : CRCCEN Mask */

/* CRC DMAIER Bit Field Definitions */
#define CRC_DMAIER_CRC_BLKD_IE_Pos      1                                               /*!< CRC CRC_DMAIER : CRC_BLKD_IE Position */
#define CRC_DMAIER_CRC_BLKD_IE_Msk      (1ul << CRC_DMAIER_CRC_BLKD_IE_Pos)             /*!< CRC CRC_DMAIER : CRC_BLKD_IE Mask */

#define CRC_DMAIER_CRC_TABORT_IE_Pos    0                                               /*!< CRC CRC_DMAIER : CRC_TABORT_IE Position */
#define CRC_DMAIER_CRC_TABORT_IE_Msk    (1ul << CRC_DMAIER_CRC_TABORT_IE_Pos)           /*!< CRC CRC_DMAIER : CRC_TABORT_IE Mask */

/* CRC DMAISR Bit Field Definitions */
#define CRC_DMAISR_CRC_BLKD_IF_Pos      1                                               /*!< CRC CRC_DMAISR : CRC_BLKD_IF Position */
#define CRC_DMAISR_CRC_BLKD_IF_Msk      (1ul << CRC_DMAISR_CRC_BLKD_IF_Pos)             /*!< CRC CRC_DMAISR : CRC_BLKD_IF Mask */

#define CRC_DMAISR_CRC_TABORT_IF_Pos    0                                               /*!< CRC CRC_DMAISR : CRC_TABORT_IF Position */
#define CRC_DMAISR_CRC_TABORT_IF_Msk    (1ul << CRC_DMAISR_CRC_TABORT_IF_Pos)           /*!< CRC CRC_DMAISR : CRC_TABORT_IF Mask */

/* CRC WDATA Bit Field Definitions */
#define CRC_WDATA_CRC_WDATA_Pos         0                                               /*!< CRC CRC_WDATA : CRC_WDATA Position */
#define CRC_WDATA_CRC_WDATA_Msk         (0xFFFFFFFFul << CRC_WDATA_CRC_WDATA_Pos)       /*!< CRC CRC_WDATA : CRC_WDATA Mask */

/* CRC SEED Bit Field Definitions */
#define CRC_SEED_CRC_SEED_Pos           0                                               /*!< CRC CRC_SEED : CRC_SEED Position */
#define CRC_SEED_CRC_SEED_Msk           (0xFFFFFFFFul << CRC_SEED_CRC_SEED_Pos)         /*!< CRC CRC_SEED : CRC_SEED Mask */

/* CRC CHECKSUM Bit Field Definitions */
#define CRC_CHECKSUM_CRC_CHECKSUM_Pos   0                                               /*!< CRC CRC_CHECKSUM : CRC_CHECKSUM Position */
#define CRC_CHECKSUM_CRC_CHECKSUM_Msk   (0xFFFFFFFFul << CRC_CHECKSUM_CRC_CHECKSUM_Pos) /*!< CRC CRC_CHECKSUM : CRC_CHECKSUM Mask */


/*@}*/ /* end of group NANO100_PDMA */



/*----------------------------- PWM Controller ----------------------------*/
/** @addtogroup NANO100_PWM NANO100 PWM Control Register (PWM)
  Memory Mapped Structure for NANO100 Series PWM Controller
  @{
*/
/**
  * @brief PWM register map
  */
typedef struct {
    __IO uint32_t  PRES;                        /*!< Offset: 0x0000   PWM Prescaler Register                                */
    __IO uint32_t  CLKSEL;                      /*!< Offset: 0x0004   PWM Clock Select Register                             */
    __IO uint32_t  CTL;                         /*!< Offset: 0x0008   PWM Control Register                                 */
    __IO uint32_t  INTEN;                       /*!< Offset: 0x000C   PWM Interrupt Enable Register                         */
    __IO uint32_t  INTSTS;                      /*!< Offset: 0x0010   PWM Interrupt Indication Register                     */
    __IO uint32_t  OE;                          /*!< Offset: 0x0014   PWM Output Enable Register                            */
    uint32_t  RESERVED0;                   /*!< Offset: 0x0018   Reserved                                              */
    __IO uint32_t  DUTY0;                       /*!< Offset: 0x001C   PWM Counter/Comparator Register 0                     */
    uint32_t  RESERVED1[2];                /*!< Offset: 0x0020 ~ 0x0024 Reserved                                       */
    __IO uint32_t  DUTY1;                       /*!< Offset: 0x0028  PWM Counter/Comparator Register 1                      */
    uint32_t  RESERVED2[2];                /*!< Offset: 0x002C ~ 0x0030 Reserved                                       */
    __IO uint32_t  DUTY2;                       /*!< Offset: 0x0034  PWM Counter/Comparator Register 2                      */
    uint32_t  RESERVED3[2];                /*!< Offset: 0x0038 ~ 0x003C Reserved                                       */
    __IO uint32_t  DUTY3;                       /*!< Offset: 0x0040  PWM Counter/Comparator Register 3                      */
    uint32_t  RESERVED4[4];                /*!< Offset: 0x0044 ~ 0x0050 Reserved                                       */
    __IO uint32_t  CAPCTL;                      /*!< Offset: 0x0054  Capture Control Register                               */
    __IO uint32_t  CAPINTEN;                    /*!< Offset: 0x0058  Capture Interrupt Enable Register                      */
    __IO uint32_t  CAPINTSTS;                   /*!< Offset: 0x005C  Capture Interrupt Indication Register                  */
    __I  uint32_t  CRL0;                        /*!< Offset: 0x0060  Capture Rising Latch Register 0                        */
    __I  uint32_t  CFL0;                        /*!< Offset: 0x0064  Capture Falling Latch Register 0                       */
    __I  uint32_t  CRL1;                        /*!< Offset: 0x0068  Capture Rising Latch Register 1                        */
    __I  uint32_t  CFL1;                        /*!< Offset: 0x006C  Capture Falling Latch Register 1                       */
    __I  uint32_t  CRL2;                        /*!< Offset: 0x0070  Capture Rising Latch Register 2                        */
    __I  uint32_t  CFL2;                        /*!< Offset: 0x0074  Capture Falling Latch Register 2                       */
    __I  uint32_t  CRL3;                        /*!< Offset: 0x0078  Capture Rising Latch Register 3                        */
    __I  uint32_t  CFL3;                        /*!< Offset: 0x007C  Capture Falling Latch Register 3                       */
    __I  uint32_t  CH0PDMA;                     /*!< Offset: 0x0080  PDMA channel 0 captured data                           */
    __I  uint32_t  CH2PDMA;                     /*!< Offset: 0x0084  PDMA channel 1 captured data                           */
    __IO  uint32_t  ADCTRGEN;                    /*!< Offset: 0x0088  Enable trigger ADC                                     */
    __IO  uint32_t  ADCTRGSTS;                    /*!< Offset: 0x008C  Trigger ADC status                                     */
} PWM_T;

/* PWM PRES Bit Field Definitions */
#define PWM_PRES_CP01_Pos                      0                                   /*!< PWM PRES: CP01 Position */
#define PWM_PRES_CP01_Msk                      (0xFFul << PWM_PRES_CP01_Pos)       /*!< PWM PRES: CP01 Mask */

#define PWM_PRES_CP23_Pos                      8                                   /*!< PWM PRES: CP23 Position */
#define PWM_PRES_CP23_Msk                      (0xFFul << PWM_PRES_CP23_Pos)       /*!< PWM PRES: CP23 Mask */

#define PWM_PRES_DZ01_Pos                      16                                  /*!< PWM PRES: DZ01 Position */
#define PWM_PRES_DZ01_Msk                      (0xFFul << PWM_PRES_DZ01_Pos)       /*!< PWM PRES: DZ01 Mask */

#define PWM_PRES_DZ23_Pos                      24                                  /*!< PWM PRES: DZ23 Position */
#define PWM_PRES_DZ23_Msk                      (0xFFul << PWM_PRES_DZ23_Pos)       /*!< PWM PRES: DZ23 Mask */

/* PWM CLKSEL Bit Field Definitions */
#define PWM_CLKSEL_CLKSEL0_Pos                 0                                   /*!< PWM CLKSEL: CLKSEL0 Position */
#define PWM_CLKSEL_CLKSEL0_Msk                 (0x7ul << PWM_CLKSEL_CLKSEL0_Pos)   /*!< PWM CLKSEL: CLKSEL0 Mask */

#define PWM_CLKSEL_CLKSEL1_Pos                 4                                   /*!< PWM CLKSEL: CLKSEL1 Position */
#define PWM_CLKSEL_CLKSEL1_Msk                 (0x7ul << PWM_CLKSEL_CLKSEL1_Pos)   /*!< PWM CLKSEL: CLKSEL1 Mask */

#define PWM_CLKSEL_CLKSEL2_Pos                 8                                   /*!< PWM CLKSEL: CLKSEL2 Position */
#define PWM_CLKSEL_CLKSEL2_Msk                 (0x7ul << PWM_CLKSEL_CLKSEL2_Pos)   /*!< PWM CLKSEL: CLKSEL2 Mask */

#define PWM_CLKSEL_CLKSEL3_Pos                 12                                  /*!< PWM CLKSEL: CLKSEL3 Position */
#define PWM_CLKSEL_CLKSEL3_Msk                 (0x7ul << PWM_CLKSEL_CLKSEL3_Pos)   /*!< PWM CLKSEL: CLKSEL3 Mask */

/* PWM CTL Bit Field Definitions */
#define PWM_CTL_CH0EN_Pos                      0                                   /*!< PWM CTL: CH0EN Position */
#define PWM_CTL_CH0EN_Msk                      (0x1ul << PWM_CTL_CH0EN_Pos)        /*!< PWM CTL: CH0EN Mask */

#define PWM_CTL_CH0INV_Pos                     2                                   /*!< PWM CTL: CH0INV Position */
#define PWM_CTL_CH0INV_Msk                     (0x1ul << PWM_CTL_CH0INV_Pos)       /*!< PWM CTL: CH0INV Mask */

#define PWM_CTL_CH0MOD_Pos                     3                                   /*!< PWM CTL: CH0MOD Position */
#define PWM_CTL_CH0MOD_Msk                     (0x1ul << PWM_CTL_CH0MOD_Pos)       /*!< PWM CTL: CH0MOD Mask */

#define PWM_CTL_DZ01_Pos                       4                                   /*!< PWM CTL: DZ01 Position */
#define PWM_CTL_DZ01_Msk                       (0x1ul << PWM_CTL_DZ01_Pos)         /*!< PWM CTL: DZ01 Mask */

#define PWM_CTL_DZ23_Pos                       5                                   /*!< PWM CTL: DZ23 Position */
#define PWM_CTL_DZ23_Msk                       (0x1ul << PWM_CTL_DZ23_Pos)         /*!< PWM CTL: DZ23 Mask */

#define PWM_CTL_CH1EN_Pos                      8                                   /*!< PWM CTL: CH1EN Position */
#define PWM_CTL_CH1EN_Msk                      (0x1ul << PWM_CTL_CH1EN_Pos)        /*!< PWM CTL: CH1EN Mask */

#define PWM_CTL_CH1INV_Pos                     10                                   /*!< PWM CTL: CH1INV Position */
#define PWM_CTL_CH1INV_Msk                     (0x1ul << PWM_CTL_CH1INV_Pos)        /*!< PWM CTL: CH1INV Mask */

#define PWM_CTL_CH1MOD_Pos                     11                                   /*!< PWM CTL: CH1MOD Position */
#define PWM_CTL_CH1MOD_Msk                     (0x1ul << PWM_CTL_CH1MOD_Pos)        /*!< PWM CTL: CH1MOD Mask */

#define PWM_CTL_CH2EN_Pos                      16                                  /*!< PWM CTL: CH2EN Position */
#define PWM_CTL_CH2EN_Msk                      (0x1ul << PWM_CTL_CH2EN_Pos)        /*!< PWM CTL: CH2EN Mask */

#define PWM_CTL_CH2INV_Pos                     18                                   /*!< PWM CTL: CH2INV Position */
#define PWM_CTL_CH2INV_Msk                     (0x1ul << PWM_CTL_CH2INV_Pos)        /*!< PWM CTL: CH2INV Mask */

#define PWM_CTL_CH2MOD_Pos                     19                                   /*!< PWM CTL: CH2MOD Position */
#define PWM_CTL_CH2MOD_Msk                     (0x1ul << PWM_CTL_CH2MOD_Pos)        /*!< PWM CTL: CH2MOD Mask */

#define PWM_CTL_CH3EN_Pos                      24                                  /*!< PWM CTL: CH3EN Position */
#define PWM_CTL_CH3EN_Msk                      (0x1ul << PWM_CTL_CH3EN_Pos)        /*!< PWM CTL: CH3EN Mask */

#define PWM_CTL_CH3INV_Pos                     26                                   /*!< PWM CTL: CH3INV Position */
#define PWM_CTL_CH3INV_Msk                     (0x1ul << PWM_CTL_CH3INV_Pos)        /*!< PWM CTL: CH3INV Mask */

#define PWM_CTL_CH3MOD_Pos                     27                                   /*!< PWM CTL: CH3MOD Position */
#define PWM_CTL_CH3MOD_Msk                     (0x1ul << PWM_CTL_CH3MOD_Pos)        /*!< PWM CTL: CH3MOD Mask */

/* PWM INTEN Bit Field Definitions */
#define PWM_INTEN_TMIE0_Pos                    0                                   /*!< PWM INTEN: TMIE0 Position */
#define PWM_INTEN_TMIE0_Msk                    (0x1ul << PWM_INTEN_TMIE0_Pos)      /*!< PWM INTEN: TMIE0 Mask */

#define PWM_INTEN_TMIE1_Pos                    1                                   /*!< PWM INTEN: TMIE1 Position */
#define PWM_INTEN_TMIE1_Msk                    (0x1ul << PWM_INTEN_TMIE1_Pos)      /*!< PWM INTEN: TMIE1 Mask */

#define PWM_INTEN_TMIE2_Pos                    2                                   /*!< PWM INTEN: TMIE2 Position */
#define PWM_INTEN_TMIE2_Msk                    (0x1ul << PWM_INTEN_TMIE2_Pos)      /*!< PWM INTEN: TMIE2 Mask */

#define PWM_INTEN_TMIE3_Pos                    3                                   /*!< PWM INTEN: TMIE3 Position */
#define PWM_INTEN_TMIE3_Msk                    (0x1ul << PWM_INTEN_TMIE3_Pos)      /*!< PWM INTEN: TMIE3 Mask */

/* PWM INTSTS Bit Field Definitions */
#define PWM_INTSTS_TMINT0_Pos                  0                                   /*!< PWM INTSTS: TMINT0 Position */
#define PWM_INTSTS_TMINT0_Msk                  (0x1ul << PWM_INTSTS_TMINT0_Pos)    /*!< PWM INTSTS: TMINT0 Mask */

#define PWM_INTSTS_TMINT1_Pos                  1                                   /*!< PWM INTSTS: TMINT1 Position */
#define PWM_INTSTS_TMINT1_Msk                  (0x1ul << PWM_INTSTS_TMINT1_Pos)    /*!< PWM INTSTS: TMINT1 Mask */

#define PWM_INTSTS_TMINT2_Pos                  2                                   /*!< PWM INTSTS: TMINT2 Position */
#define PWM_INTSTS_TMINT2_Msk                  (0x1ul << PWM_INTSTS_TMINT2_Pos)    /*!< PWM INTSTS: TMINT2 Mask */

#define PWM_INTSTS_TMINT3_Pos                  3                                   /*!< PWM INTSTS: TMINT3 Position */
#define PWM_INTSTS_TMINT3_Msk                  (0x1ul << PWM_INTSTS_TMINT3_Pos)    /*!< PWM INTSTS: TMINT3 Mask */

#define PWM_INTSTS_DUTY0SYNC_Pos               4                                   /*!< PWM INTSTS: DUTY0SYNC Position */
#define PWM_INTSTS_DUTY0SYNC_Msk               (0x1ul << PWM_INTSTS_DUTY0SYNC_Pos) /*!< PWM INTSTS: DUTY0SYNC Mask */

#define PWM_INTSTS_DUTY1SYNC_Pos               5                                   /*!< PWM INTSTS: DUTY1SYNC Position */
#define PWM_INTSTS_DUTY1SYNC_Msk               (0x1ul << PWM_INTSTS_DUTY1SYNC_Pos) /*!< PWM INTSTS: DUTY1SYNC Mask */

#define PWM_INTSTS_DUTY2SYNC_Pos               6                                   /*!< PWM INTSTS: DUTY2SYNC Position */
#define PWM_INTSTS_DUTY2SYNC_Msk               (0x1ul << PWM_INTSTS_DUTY2SYNC_Pos) /*!< PWM INTSTS: DUTY2SYNC Mask */

#define PWM_INTSTS_DUTY3SYNC_Pos               7                                   /*!< PWM INTSTS: DUTY3SYNC Position */
#define PWM_INTSTS_DUTY3SYNC_Msk               (0x1ul << PWM_INTSTS_DUTY3SYNC_Pos) /*!< PWM INTSTS: DUTY3SYNC Mask */

#define PWM_INTSTS_PRESSYNC_Pos                8                                   /*!< PWM INTSTS: PRESSYNC Position */
#define PWM_INTSTS_PRESSYNC_Msk                (0x1ul << PWM_INTSTS_PRESSYNC_Pos)  /*!< PWM INTSTS: PRESSYNC Mask */

/* PWM OE Bit Field Definitions */
#define PWM_OE_CH0OE_Pos                       0                                   /*!< PWM OE: CH0OE Position */
#define PWM_OE_CH0OE_Msk                       (0x1ul << PWM_OE_CH0OE_Pos)         /*!< PWM OE: CH0OE Mask */

#define PWM_OE_CH1OE_Pos                       1                                   /*!< PWM OE: CH1OE Position */
#define PWM_OE_CH1OE_Msk                       (0x1ul << PWM_OE_CH1OE_Pos)         /*!< PWM OE: CH1OE Mask */

#define PWM_OE_CH2OE_Pos                       2                                   /*!< PWM OE: CH2OE Position */
#define PWM_OE_CH2OE_Msk                       (0x1ul << PWM_OE_CH2OE_Pos)         /*!< PWM OE: CH2OE Mask */

#define PWM_OE_CH3OE_Pos                       3                                   /*!< PWM OE: CH3OE Position */
#define PWM_OE_CH3OE_Msk                       (0x1ul << PWM_OE_CH3OE_Pos)         /*!< PWM OE: CH3OE Mask */

/* PWM DUTY Bit Field Definitions */
#define PWM_DUTY_CN_Pos                        0                                   /*!< PWM DUTY: CN Position */
#define PWM_DUTY_CN_Msk                       (0xFFFFul << PWM_DUTY_CN_Pos)        /*!< PWM DUTY: CN Mask */

#define PWM_DUTY_CM_Pos                        16                                  /*!< PWM DUTY: CM Position */
#define PWM_DUTY_CM_Msk                       (0xFFFFul << PWM_DUTY_CM_Pos)        /*!< PWM DUTY: CM Mask */

/* PWM CAPCTL Bit Field Definitions */
#define PWM_CAPCTL_INV0_Pos                    0                                   /*!< PWM CAPCTL: INV0 Position */
#define PWM_CAPCTL_INV0_Msk                    (0x1ul << PWM_CAPCTL_INV0_Pos)      /*!< PWM CAPCTL: INV0 Mask */

#define PWM_CAPCTL_CAPCH0EN_Pos                1                                   /*!< PWM CAPCTL: CAPCH0EN Position */
#define PWM_CAPCTL_CAPCH0EN_Msk                (0x1ul << PWM_CAPCTL_CAPCH0EN_Pos)  /*!< PWM CAPCTL: CAPCH0EN Mask */

#define PWM_CAPCTL_CAPCH0PADEN_Pos             2                                      /*!< PWM CAPCTL: CAPCH0PADEN Position */
#define PWM_CAPCTL_CAPCH0PADEN_Msk             (0x1ul << PWM_CAPCTL_CAPCH0PADEN_Pos)  /*!< PWM CAPCTL: CAPCH0PADEN Mask */

#define PWM_CAPCTL_CAPCH0PDMAEN_Pos            3                                      /*!< PWM CAPCTL: CAPCH0PDMAEN Position */
#define PWM_CAPCTL_CAPCH0PDMAEN_Msk            (0x1ul << PWM_CAPCTL_CAPCH0PDMAEN_Pos) /*!< PWM CAPCTL: CAPCH0PDMAEN Mask */

#define PWM_CAPCTL_PDMACAPMOD0_Pos             4                                      /*!< PWM CAPCTL: PDMACAPMOD0 Position */
#define PWM_CAPCTL_PDMACAPMOD0_Msk             (0x3ul << PWM_CAPCTL_PDMACAPMOD0_Pos)  /*!< PWM CAPCTL: PDMACAPMOD0 Mask */

#define PWM_CAPCTL_CAPRELOADREN0_Pos           6                                       /*!< PWM CAPCTL: CAPRELOADREN0 Position */
#define PWM_CAPCTL_CAPRELOADREN0_Msk           (0x1ul << PWM_CAPCTL_CAPRELOADREN0_Pos) /*!< PWM CAPCTL: CAPRELOADREN0 Mask */

#define PWM_CAPCTL_CAPRELOADFEN0_Pos           7                                       /*!< PWM CAPCTL: CAPRELOADFEN0 Position */
#define PWM_CAPCTL_CAPRELOADFEN0_Msk           (0x1ul << PWM_CAPCTL_CAPRELOADFEN0_Pos) /*!< PWM CAPCTL: CAPRELOADFEN0 Mask */

#define PWM_CAPCTL_INV1_Pos                    8                                   /*!< PWM CAPCTL: INV1 Position */
#define PWM_CAPCTL_INV1_Msk                    (0x1ul << PWM_CAPCTL_INV1_Pos)      /*!< PWM CAPCTL: INV1 Mask */

#define PWM_CAPCTL_CAPCH1EN_Pos                9                                   /*!< PWM CAPCTL: CAPCH1EN Position */
#define PWM_CAPCTL_CAPCH1EN_Msk                (0x1ul << PWM_CAPCTL_CAPCH1EN_Pos)  /*!< PWM CAPCTL: CAPCH1EN Mask */

#define PWM_CAPCTL_CAPCH1PADEN_Pos             10                                      /*!< PWM CAPCTL: CAPCH1PADEN Position */
#define PWM_CAPCTL_CAPCH1PADEN_Msk             (0x1ul << PWM_CAPCTL_CAPCH1PADEN_Pos)   /*!< PWM CAPCTL: CAPCH1PADEN Mask */

#define PWM_CAPCTL_CH0RFORDER_Pos              12                                      /*!< PWM CAPCTL: CH0RFORDER Position */
#define PWM_CAPCTL_CH0RFORDER_Msk              (0x1ul << PWM_CAPCTL_CH0RFORDER_Pos)    /*!< PWM CAPCTL: CH0RFORDER Mask */

#define PWM_CAPCTL_CH01CASK_Pos                13                                      /*!< PWM CAPCTL: CH01CASK Position */
#define PWM_CAPCTL_CH01CASK_Msk                (0x1ul << PWM_CAPCTL_CH01CASK_Pos)      /*!< PWM CAPCTL: CH01CASK Mask */

#define PWM_CAPCTL_CAPRELOADREN1_Pos           14                                       /*!< PWM CAPCTL: CAPRELOADREN1 Position */
#define PWM_CAPCTL_CAPRELOADREN1_Msk           (0x1ul << PWM_CAPCTL_CAPRELOADREN1_Pos)  /*!< PWM CAPCTL: CAPRELOADREN1 Mask */

#define PWM_CAPCTL_CAPRELOADFEN1_Pos           15                                       /*!< PWM CAPCTL: CAPRELOADFEN1 Position */
#define PWM_CAPCTL_CAPRELOADFEN1_Msk           (0x1ul << PWM_CAPCTL_CAPRELOADFEN1_Pos)  /*!< PWM CAPCTL: CAPRELOADFEN1 Mask */

#define PWM_CAPCTL_INV2_Pos                    16                                  /*!< PWM CAPCTL: INV2 Position */
#define PWM_CAPCTL_INV2_Msk                    (0x1ul << PWM_CAPCTL_INV2_Pos)      /*!< PWM CAPCTL: INV2 Mask */

#define PWM_CAPCTL_CAPCH2EN_Pos                17                                  /*!< PWM CAPCTL: CAPCH2EN Position */
#define PWM_CAPCTL_CAPCH2EN_Msk                (0x1ul << PWM_CAPCTL_CAPCH2EN_Pos)  /*!< PWM CAPCTL: CAPCH2EN Mask */

#define PWM_CAPCTL_CAPCH2PADEN_Pos             18                                      /*!< PWM CAPCTL: CAPCH2PADEN Position */
#define PWM_CAPCTL_CAPCH2PADEN_Msk             (0x1ul << PWM_CAPCTL_CAPCH2PADEN_Pos)   /*!< PWM CAPCTL: CAPCH2PADEN Mask */

#define PWM_CAPCTL_CAPCH2PDMAEN_Pos            19                                      /*!< PWM CAPCTL: CAPCH2PDMAEN Position */
#define PWM_CAPCTL_CAPCH2PDMAEN_Msk            (0x1ul << PWM_CAPCTL_CAPCH2PDMAEN_Pos)  /*!< PWM CAPCTL: CAPCH2PDMAEN Mask */

#define PWM_CAPCTL_PDMACAPMOD2_Pos             20                                      /*!< PWM CAPCTL: PDMACAPMOD2 Position */
#define PWM_CAPCTL_PDMACAPMOD2_Msk            (0x3ul << PWM_CAPCTL_PDMACAPMOD2_Pos)    /*!< PWM CAPCTL: PDMACAPMOD2 Mask */

#define PWM_CAPCTL_CAPRELOADREN2_Pos           22                                       /*!< PWM CAPCTL: CAPRELOADREN2 Position */
#define PWM_CAPCTL_CAPRELOADREN2_Msk           (0x1ul << PWM_CAPCTL_CAPRELOADREN2_Pos)  /*!< PWM CAPCTL: CAPRELOADREN2 Mask */

#define PWM_CAPCTL_CAPRELOADFEN2_Pos           23                                       /*!< PWM CAPCTL: CAPRELOADFEN2 Position */
#define PWM_CAPCTL_CAPRELOADFEN2_Msk           (0x1ul << PWM_CAPCTL_CAPRELOADFEN2_Pos)  /*!< PWM CAPCTL: CAPRELOADFEN2 Mask */

#define PWM_CAPCTL_INV3_Pos                    24                                   /*!< PWM CAPCTL: INV3 Position */
#define PWM_CAPCTL_INV3_Msk                    (0x1ul << PWM_CAPCTL_INV3_Pos)       /*!< PWM CAPCTL: INV3 Mask */

#define PWM_CAPCTL_CAPCH3EN_Pos                25                                   /*!< PWM CAPCTL: CAPCH3EN Position */
#define PWM_CAPCTL_CAPCH3EN_Msk                (0x1ul << PWM_CAPCTL_CAPCH3EN_Pos)   /*!< PWM CAPCTL: CAPCH3EN Mask */

#define PWM_CAPCTL_CAPCH3PADEN_Pos             26                                      /*!< PWM CAPCTL: CAPCH3PADEN Position */
#define PWM_CAPCTL_CAPCH3PADEN_Msk             (0x1ul << PWM_CAPCTL_CAPCH3PADEN_Pos)   /*!< PWM CAPCTL: CAPCH3PADEN Mask */

#define PWM_CAPCTL_CH2RFORDER_Pos              28                                      /*!< PWM CAPCTL: CH2RFORDER Position */
#define PWM_CAPCTL_CH2RFORDER_Msk              (0x1ul << PWM_CAPCTL_CH2RFORDER_Pos)    /*!< PWM CAPCTL: CH2RFORDER Mask */

#define PWM_CAPCTL_CH23CASK_Pos                29                                      /*!< PWM CAPCTL: CH23CASK Position */
#define PWM_CAPCTL_CH23CASK_Msk                (0x1ul << PWM_CAPCTL_CH23CASK_Pos)      /*!< PWM CAPCTL: CH23CASK Mask */

#define PWM_CAPCTL_CAPRELOADREN3_Pos           30                                       /*!< PWM CAPCTL: CAPRELOADREN3 Position */
#define PWM_CAPCTL_CAPRELOADREN3_Msk           (0x1ul << PWM_CAPCTL_CAPRELOADREN3_Pos)  /*!< PWM CAPCTL: CAPRELOADREN3 Mask */

#define PWM_CAPCTL_CAPRELOADFEN3_Pos           31                                       /*!< PWM CAPCTL: CAPRELOADFEN3 Position */
#define PWM_CAPCTL_CAPRELOADFEN3_Msk           (0x1ul << PWM_CAPCTL_CAPRELOADFEN3_Pos)  /*!< PWM CAPCTL: CAPRELOADFEN3 Mask */

/* PWM CAPINTEN Bit Field Definitions */
#define PWM_CAPINTEN_CRLIE0_Pos                0                                   /*!< PWM CAPINTEN: CRLIE0 Position */
#define PWM_CAPINTEN_CRLIE0_Msk                (0x1ul << PWM_CAPINTEN_CRLIE0_Pos)  /*!< PWM CAPINTEN: CRLIE0 Mask */

#define PWM_CAPINTEN_CFLIE0_Pos                1                                   /*!< PWM CAPINTEN: CFLIE0 Position */
#define PWM_CAPINTEN_CFLIE0_Msk                (0x1ul << PWM_CAPINTEN_CFLIE0_Pos)  /*!< PWM CAPINTEN: CFLIE0 Mask */

#define PWM_CAPINTEN_CRLIE1_Pos                8                                   /*!< PWM CAPINTEN: CRLIE1 Position */
#define PWM_CAPINTEN_CRLIE1_Msk                (0x1ul << PWM_CAPINTEN_CRLIE1_Pos)  /*!< PWM CAPINTEN: CRLIE1 Mask */

#define PWM_CAPINTEN_CFLIE1_Pos                9                                   /*!< PWM CAPINTEN: CFLIE1 Position */
#define PWM_CAPINTEN_CFLIE1_Msk                (0x1ul << PWM_CAPINTEN_CFLIE1_Pos)  /*!< PWM CAPINTEN: CFLIE1 Mask */

#define PWM_CAPINTEN_CRLIE2_Pos                16                                  /*!< PWM CAPINTEN: CRLIE2 Position */
#define PWM_CAPINTEN_CRLIE2_Msk                (0x1ul << PWM_CAPINTEN_CRLIE2_Pos)  /*!< PWM CAPINTEN: CRLIE2 Mask */

#define PWM_CAPINTEN_CFLIE2_Pos                17                                   /*!< PWM CAPINTEN: CFLIE2 Position */
#define PWM_CAPINTEN_CFLIE2_Msk                (0x1ul << PWM_CAPINTEN_CFLIE2_Pos)   /*!< PWM CAPINTEN: CFLIE2 Mask */

#define PWM_CAPINTEN_CRLIE3_Pos                24                                  /*!< PWM CAPINTEN: CRLIE3 Position */
#define PWM_CAPINTEN_CRLIE3_Msk                (0x1ul << PWM_CAPINTEN_CRLIE3_Pos)  /*!< PWM CAPINTEN: CRLIE3 Mask */

#define PWM_CAPINTEN_CFLIE3_Pos                25                                   /*!< PWM CAPINTEN: CFLIE3 Position */
#define PWM_CAPINTEN_CFLIE3_Msk                (0x1ul << PWM_CAPINTEN_CFLIE3_Pos)   /*!< PWM CAPINTEN: CFLIE3 Mask */

/* PWM CAPINTSTS Bit Field Definitions */
#define PWM_CAPINTSTS_CAPIF0_Pos                0                                   /*!< PWM CAPINTSTS: CAPIF0 Position */
#define PWM_CAPINTSTS_CAPIF0_Msk                (0x1ul << PWM_CAPINTSTS_CAPIF0_Pos) /*!< PWM CAPINTSTS: CAPIF0 Mask */

#define PWM_CAPINTSTS_CRLI0_Pos                 1                                   /*!< PWM CAPINTSTS: CRLI0 Position */
#define PWM_CAPINTSTS_CRLI0_Msk                 (0x1ul << PWM_CAPINTSTS_CRLI0_Pos)  /*!< PWM CAPINTSTS: CRLI0 Mask */

#define PWM_CAPINTSTS_CFLI0_Pos                 2                                   /*!< PWM CAPINTSTS: CFLI0 Position */
#define PWM_CAPINTSTS_CFLI0_Msk                 (0x1ul << PWM_CAPINTSTS_CFLI0_Pos)  /*!< PWM CAPINTSTS: CFLI0 Mask */

#define PWM_CAPINTSTS_CAPOVR0_Pos               3                                    /*!< PWM CAPINTSTS: CAPOVR0 Position */
#define PWM_CAPINTSTS_CAPOVR0_Msk               (0x1ul << PWM_CAPINTSTS_CAPOVR0_Pos) /*!< PWM CAPINTSTS: CAPOVR0 Mask */

#define PWM_CAPINTSTS_CAPOVF0_Pos               4                                    /*!< PWM CAPINTSTS: CAPOVF0 Position */
#define PWM_CAPINTSTS_CAPOVF0_Msk               (0x1ul << PWM_CAPINTSTS_CAPOVF0_Pos) /*!< PWM CAPINTSTS: CAPOVF0 Mask */

#define PWM_CAPINTSTS_CAPIF1_Pos                8                                   /*!< PWM CAPINTSTS: CAPIF1 Position */
#define PWM_CAPINTSTS_CAPIF1_Msk                (0x1ul << PWM_CAPINTSTS_CAPIF1_Pos) /*!< PWM CAPINTSTS: CAPIF1 Mask */

#define PWM_CAPINTSTS_CRLI1_Pos                 9                                   /*!< PWM CAPINTSTS: CRLI1 Position */
#define PWM_CAPINTSTS_CRLI1_Msk                 (0x1ul << PWM_CAPINTSTS_CRLI1_Pos)  /*!< PWM CAPINTSTS: CRLI1 Mask */

#define PWM_CAPINTSTS_CFLI1_Pos                 10                                   /*!< PWM CAPINTSTS: CFLI1 Position */
#define PWM_CAPINTSTS_CFLI1_Msk                 (0x1ul << PWM_CAPINTSTS_CFLI1_Pos)   /*!< PWM CAPINTSTS: CFLI1 Mask */

#define PWM_CAPINTSTS_CAPOVR1_Pos               11                                    /*!< PWM CAPINTSTS: CAPOVR1 Position */
#define PWM_CAPINTSTS_CAPOVR1_Msk               (0x1ul << PWM_CAPINTSTS_CAPOVR1_Pos) /*!< PWM CAPINTSTS: CAPOVR1 Mask */

#define PWM_CAPINTSTS_CAPOVF1_Pos               12                                    /*!< PWM CAPINTSTS: CAPOVF1 Position */
#define PWM_CAPINTSTS_CAPOVF1_Msk               (0x1ul << PWM_CAPINTSTS_CAPOVF1_Pos) /*!< PWM CAPINTSTS: CAPOVF1 Mask */

#define PWM_CAPINTSTS_CAPIF2_Pos                16                                  /*!< PWM CAPINTSTS: CAPIF2 Position */
#define PWM_CAPINTSTS_CAPIF2_Msk                (0x1ul << PWM_CAPINTSTS_CAPIF2_Pos) /*!< PWM CAPINTSTS: CAPIF2 Mask */

#define PWM_CAPINTSTS_CRLI2_Pos                 17                                   /*!< PWM CAPINTSTS: CRLI2 Position */
#define PWM_CAPINTSTS_CRLI2_Msk                 (0x1ul << PWM_CAPINTSTS_CRLI2_Pos)   /*!< PWM CAPINTSTS: CRLI2 Mask */

#define PWM_CAPINTSTS_CFLI2_Pos                 18                                   /*!< PWM CAPINTSTS: CFLI2 Position */
#define PWM_CAPINTSTS_CFLI2_Msk                 (0x1ul << PWM_CAPINTSTS_CFLI2_Pos)   /*!< PWM CAPINTSTS: CFLI2 Mask */

#define PWM_CAPINTSTS_CAPOVR2_Pos               19                                    /*!< PWM CAPINTSTS: CAPOVR2 Position */
#define PWM_CAPINTSTS_CAPOVR2_Msk               (0x1ul << PWM_CAPINTSTS_CAPOVR0_Pos) /*!< PWM CAPINTSTS: CAPOVR2 Mask */

#define PWM_CAPINTSTS_CAPOVF2_Pos               20                                    /*!< PWM CAPINTSTS: CAPOVF2 Position */
#define PWM_CAPINTSTS_CAPOVF2_Msk               (0x1ul << PWM_CAPINTSTS_CAPOVF0_Pos) /*!< PWM CAPINTSTS: CAPOVF2 Mask */

#define PWM_CAPINTSTS_CAPIF3_Pos                24                                  /*!< PWM CAPINTSTS: CAPIF3 Position */
#define PWM_CAPINTSTS_CAPIF3_Msk                (0x1ul << PWM_CAPINTSTS_CAPIF3_Pos) /*!< PWM CAPINTSTS: CAPIF3 Mask */

#define PWM_CAPINTSTS_CRLI3_Pos                 25                                   /*!< PWM CAPINTSTS: CRLI3 Position */
#define PWM_CAPINTSTS_CRLI3_Msk                 (0x1ul << PWM_CAPINTSTS_CRLI3_Pos)   /*!< PWM CAPINTSTS: CRLI3 Mask */

#define PWM_CAPINTSTS_CFLI3_Pos                 26                                   /*!< PWM CAPINTSTS: CFLI3 Position */
#define PWM_CAPINTSTS_CFLI3_Msk                 (0x1ul << PWM_CAPINTSTS_CFLI3_Pos)   /*!< PWM CAPINTSTS: CFLI3 Mask */

#define PWM_CAPINTSTS_CAPOVR3_Pos               27                                    /*!< PWM CAPINTSTS: CAPOVR3 Position */
#define PWM_CAPINTSTS_CAPOVR3_Msk               (0x1ul << PWM_CAPINTSTS_CAPOVR3_Pos) /*!< PWM CAPINTSTS: CAPOVR3 Mask */

#define PWM_CAPINTSTS_CAPOVF3_Pos               28                                    /*!< PWM CAPINTSTS: CAPOVF3 Position */
#define PWM_CAPINTSTS_CAPOVF3_Msk               (0x1ul << PWM_CAPINTSTS_CAPOVF3_Pos) /*!< PWM CAPINTSTS: CAPOVF3 Mask */

/*@}*/ /* end of group NANO100_PWM */



/*----------------------------- Real Time Clock Controller -------------------------------*/
/** @addtogroup NANO100_RTC NANO100 Real Time Clock (RTC)
  Memory Mapped Structure for NANO100 Series Real Time Clock
  @{
*/
/**
  * @brief RTC register map
  */
typedef struct {
    __IO uint32_t  INIR;        /*!< Offset: 0x0000   RTC Initiation Register                 */
    __IO uint32_t  AER;         /*!< Offset: 0x0004   RTC Access Enable Register              */
    __IO uint32_t  FCR;         /*!< Offset: 0x0008   RTC Frequency Compensation Register     */
    __IO uint32_t  TLR;         /*!< Offset: 0x000C   Time Loading Register                   */
    __IO uint32_t  CLR;         /*!< Offset: 0x0010   Calendar Loading Register               */
    __IO uint32_t  TSSR;        /*!< Offset: 0x0014   Time Scale Selection Register           */
    __IO uint32_t  DWR;         /*!< Offset: 0x0018   Day of the Week Register                */
    __IO uint32_t  TAR;         /*!< Offset: 0x001C   Time Alarm Register                     */
    __IO uint32_t  CAR;         /*!< Offset: 0x0020   Calendar Alarm Register                 */
    __I  uint32_t  LIR;         /*!< Offset: 0x0024   Leap year Indicator Register            */
    __IO uint32_t  RIER;        /*!< Offset: 0x0028   RTC Interrupt Enable Register           */
    __IO uint32_t  RIIR;        /*!< Offset: 0x002C   RTC Interrupt Indicator Register        */
    __IO uint32_t  TTR;         /*!< Offset: 0x0030   RTC Time Tick Register                  */
    uint32_t  RESERVED0[2];
    __IO uint32_t  SPRCTL;      /*!< Offset: 0x003C   RTC Spare Functional Control Register   */
    __IO uint32_t  SPR0;        /*!< Offset: 0x0040   RTC Spare Register 0                    */
    __IO uint32_t  SPR1;        /*!< Offset: 0x0044   RTC Spare Register 1                    */
    __IO uint32_t  SPR2;        /*!< Offset: 0x0048   RTC Spare Register 2                    */
    __IO uint32_t  SPR3;        /*!< Offset: 0x004C   RTC Spare Register 3                    */
    __IO uint32_t  SPR4;        /*!< Offset: 0x0050   RTC Spare Register 4                    */
    __IO uint32_t  SPR5;        /*!< Offset: 0x0054   RTC Spare Register 5                    */
    __IO uint32_t  SPR6;        /*!< Offset: 0x0058   RTC Spare Register 6                    */
    __IO uint32_t  SPR7;        /*!< Offset: 0x005C   RTC Spare Register 7                    */
    __IO uint32_t  SPR8;        /*!< Offset: 0x0060   RTC Spare Register 8                    */
    __IO uint32_t  SPR9;        /*!< Offset: 0x0064   RTC Spare Register 9                    */
    __IO uint32_t  SPR10;       /*!< Offset: 0x0068   RTC Spare Register 10                   */
    __IO uint32_t  SPR11;       /*!< Offset: 0x006C   RTC Spare Register 11                   */
    __IO uint32_t  SPR12;       /*!< Offset: 0x0070   RTC Spare Register 12                   */
    __IO uint32_t  SPR13;       /*!< Offset: 0x0074   RTC Spare Register 13                   */
    __IO uint32_t  SPR14;       /*!< Offset: 0x0078   RTC Spare Register 14                   */
    __IO uint32_t  SPR15;       /*!< Offset: 0x007C   RTC Spare Register 15                   */
    __IO uint32_t  SPR16;       /*!< Offset: 0x0080   RTC Spare Register 16                   */
    __IO uint32_t  SPR17;       /*!< Offset: 0x0084   RTC Spare Register 17                   */
    __IO uint32_t  SPR18;       /*!< Offset: 0x0088   RTC Spare Register 18                   */
    __IO uint32_t  SPR19;       /*!< Offset: 0x008C   RTC Spare Register 19                   */
} RTC_T;

/* RTC INIR Bit Field Definitions */
#define RTC_INIR_INIR_Pos       0                                               /*!< RTC INIR: INIR Position */
#define RTC_INIR_INIR_Msk       (0xFFFFFFFFul << RTC_INIR_INIR_Pos)             /*!< RTC INIR: INIR Mask */

#define RTC_INIR_ACTIVE_Pos     0                                               /*!< RTC INIR: ACTIVE Position */
#define RTC_INIR_ACTIVE_Msk     (1ul << RTC_INIR_ACTIVE_Pos)                    /*!< RTC INIR: ACTIVE Mask */

/* RTC AER Bit Field Definitions */
#define RTC_AER_ENF_Pos         16                                              /*!< RTC AER: ENF Position */
#define RTC_AER_ENF_Msk         (1ul << RTC_AER_ENF_Pos)                        /*!< RTC AER: ENF Mask */

#define RTC_AER_AER_Pos         0                                               /*!< RTC AER: AER Position */
#define RTC_AER_AER_Msk         (0xFFFFul << RTC_AER_AER_Pos)                   /*!< RTC AER: AER Mask */

/* RTC FCR Bit Field Definitions */
#define RTC_FCR_INTEGER_Pos     8                                               /*!< RTC FCR: INTEGER Position */
#define RTC_FCR_INTEGER_Msk     (0xFul << RTC_FCR_INTEGER_Pos)                  /*!< RTC FCR: INTEGER Mask */

#define RTC_FCR_FRACTION_Pos    0                                               /*!< RTC FCR: FRACTION Position */
#define RTC_FCR_FRACTION_Msk    (0x3Ful << RTC_FCR_FRACTION_Pos)                /*!< RTC FCR: FRACTION Mask */

/* RTC TLR Bit Field Definitions */
#define RTC_TLR_10HR_Pos        20                                              /*!< RTC TLR: 10HR Position */
#define RTC_TLR_10HR_Msk        (0x3ul << RTC_TLR_10HR_Pos)                     /*!< RTC TLR: 10HR Mask */

#define RTC_TLR_1HR_Pos         16                                              /*!< RTC TLR: 1HR Position */
#define RTC_TLR_1HR_Msk         (0xFul << RTC_TLR_1HR_Pos)                      /*!< RTC TLR: 1HR Mask */

#define RTC_TLR_10MIN_Pos       12                                              /*!< RTC TLR: 10MIN Position */
#define RTC_TLR_10MIN_Msk       (0x7ul << RTC_TLR_10MIN_Pos)                    /*!< RTC TLR: 10MIN Mask */

#define RTC_TLR_1MIN_Pos        8                                               /*!< RTC TLR: 1MIN Position */
#define RTC_TLR_1MIN_Msk        (0xFul << RTC_TLR_1MIN_Pos)                     /*!< RTC TLR: 1MIN Mask */

#define RTC_TLR_10SEC_Pos       4                                               /*!< RTC TLR: 10SEC Position */
#define RTC_TLR_10SEC_Msk       (0x7ul << RTC_TLR_10SEC_Pos)                    /*!< RTC TLR: 10SEC Mask */

#define RTC_TLR_1SEC_Pos        0                                               /*!< RTC TLR: 1SEC Position */
#define RTC_TLR_1SEC_Msk        (0xFul << RTC_TLR_1SEC_Pos)                     /*!< RTC TLR: 1SEC Mask */

/* RTC CLR Bit Field Definitions */
#define RTC_CLR_10YEAR_Pos      20                                              /*!< RTC CLR: 10YEAR Position */
#define RTC_CLR_10YEAR_Msk      (0xFul << RTC_CLR_10YEAR_Pos)                   /*!< RTC CLR: 10YEAR Mask */

#define RTC_CLR_1YEAR_Pos       16                                              /*!< RTC CLR: 1YEAR Position */
#define RTC_CLR_1YEAR_Msk       (0xFul << RTC_CLR_1YEAR_Pos)                    /*!< RTC CLR: 1YEAR Mask */

#define RTC_CLR_10MON_Pos       12                                              /*!< RTC CLR: 10MON Position */
#define RTC_CLR_10MON_Msk       (1ul << RTC_CLR_10MON_Pos)                      /*!< RTC CLR: 10MON Mask */

#define RTC_CLR_1MON_Pos        8                                               /*!< RTC CLR: 1MON Position */
#define RTC_CLR_1MON_Msk        (0xFul << RTC_CLR_1MON_Pos)                     /*!< RTC CLR: 1MON Mask */

#define RTC_CLR_10DAY_Pos       4                                               /*!< RTC CLR: 10DAY Position */
#define RTC_CLR_10DAY_Msk       (0x3ul << RTC_CLR_10DAY_Pos)                    /*!< RTC CLR: 10DAY Mask */

#define RTC_CLR_1DAY_Pos        0                                               /*!< RTC CLR: 1DAY Position */
#define RTC_CLR_1DAY_Msk        (0xFul << RTC_CLR_1DAY_Pos)                     /*!< RTC CLR: 1DAY Mask */

/* RTC TSSR Bit Field Definitions */
#define RTC_TSSR_24H_12H_Pos    0                                               /*!< RTC TSSR: 24H_12H Position */
#define RTC_TSSR_24H_12H_Msk    (1ul << RTC_TSSR_24H_12H_Pos)                   /*!< RTC TSSR: 24H_12H Mask */

/* RTC DWR Bit Field Definitions */
#define RTC_DWR_DWR_Pos         0                                               /*!< RTC DWR: DWR Position */
#define RTC_DWR_DWR_Msk         (0x7ul << RTC_DWR_DWR_Pos)                      /*!< RTC DWR: DWR Mask */

/* RTC TAR Bit Field Definitions */
#define RTC_TAR_10HR_Pos        20                                              /*!< RTC TAR: 10HR Position */
#define RTC_TAR_10HR_Msk        (0x3ul << RTC_TAR_10HR_Pos)                     /*!< RTC TAR: 10HR Mask */

#define RTC_TAR_1HR_Pos         16                                              /*!< RTC TAR: 1HR Position */
#define RTC_TAR_1HR_Msk         (0xFul << RTC_TAR_1HR_Pos)                      /*!< RTC TAR: 1HR Mask */

#define RTC_TAR_10MIN_Pos       12                                              /*!< RTC TAR: 10MIN Position */
#define RTC_TAR_10MIN_Msk       (0x7ul << RTC_TAR_10MIN_Pos)                    /*!< RTC TAR: 10MIN Mask */

#define RTC_TAR_1MIN_Pos        8                                               /*!< RTC TAR: 1MIN Position */
#define RTC_TAR_1MIN_Msk        (0xFul << RTC_TAR_1MIN_Pos)                     /*!< RTC TAR: 1MIN Mask */

#define RTC_TAR_10SEC_Pos       4                                               /*!< RTC TAR: 10SEC Position */
#define RTC_TAR_10SEC_Msk       (0x7ul << RTC_TAR_10SEC_Pos)                    /*!< RTC TAR: 10SEC Mask */

#define RTC_TAR_1SEC_Pos        0                                               /*!< RTC TAR: 1SEC Position */
#define RTC_TAR_1SEC_Msk        (0xFul << RTC_TAR_1SEC_Pos)                     /*!< RTC TAR: 1SEC Mask */

/* RTC CAR Bit Field Definitions */
#define RTC_CAR_10YEAR_Pos      20                                              /*!< RTC CAR: 10YEAR Position */
#define RTC_CAR_10YEAR_Msk      (0xFul << RTC_CAR_10YEAR_Pos)                   /*!< RTC CAR: 10YEAR Mask */

#define RTC_CAR_1YEAR_Pos       16                                              /*!< RTC CAR: 1YEAR Position */
#define RTC_CAR_1YEAR_Msk       (0xFul << RTC_CAR_1YEAR_Pos)                    /*!< RTC CAR: 1YEAR Mask */

#define RTC_CAR_10MON_Pos       12                                              /*!< RTC CAR: 10MON Position */
#define RTC_CAR_10MON_Msk       (1ul << RTC_CAR_10MON_Pos)                      /*!< RTC CAR: 10MON Mask */

#define RTC_CAR_1MON_Pos        8                                               /*!< RTC CAR: 1MON Position */
#define RTC_CAR_1MON_Msk        (0xFul << RTC_CAR_1MON_Pos)                     /*!< RTC CAR: 1MON Mask */

#define RTC_CAR_10DAY_Pos       4                                               /*!< RTC CAR: 10DAY Position */
#define RTC_CAR_10DAY_Msk       (0x3ul << RTC_CAR_10DAY_Pos)                    /*!< RTC CAR: 10DAY Mask */

#define RTC_CAR_1DAY_Pos        0                                               /*!< RTC CAR: 1DAY Position */
#define RTC_CAR_1DAY_Msk        (0xFul << RTC_CAR_1DAY_Pos)                     /*!< RTC CAR: 1DAY Mask */

/* RTC LIR Bit Field Definitions */
#define RTC_LIR_LIR_Pos         0                                               /*!< RTC LIR: LIR Position */
#define RTC_LIR_LIR_Msk         (1ul << RTC_LIR_LIR_Pos)                        /*!< RTC LIR: LIR Mask */

/* RTC RIER Bit Field Definitions */
#define RTC_RIER_SNOOPIERR_Pos  2                                               /*!< RTC RIER: SNOOPIERR Position */
#define RTC_RIER_SNOOPIER_Msk   (1ul << RTC_RIER_SNOOPIERR_Pos)                 /*!< RTC RIER: SNOOPIERR Mask */

#define RTC_RIER_TIER_Pos       1                                               /*!< RTC RIER: TIER Position */
#define RTC_RIER_TIER_Msk       (1ul << RTC_RIER_TIER_Pos)                      /*!< RTC RIER: TIER Mask */

#define RTC_RIER_AIER_Pos       0                                               /*!< RTC RIER: AIER Position */
#define RTC_RIER_AIER_Msk       (1ul << RTC_RIER_AIER_Pos)                      /*!< RTC RIER: AIER Mask */

/* RTC RIIR Bit Field Definitions */
#define RTC_RIIR_SNOOPIS_Pos    2                                              /*!< RTC RIIR: SNOOPIS Position */
#define RTC_RIIR_SNOOPIS_Msk    (1ul << RTC_RIIR_SNOOPIS_Pos)                  /*!< RTC RIIR: SNOOPIS Mask */

#define RTC_RIIR_TIF_Pos        1                                               /*!< RTC RIIR: TIF Position */
#define RTC_RIIR_TIF_Msk        (1ul << RTC_RIIR_TIF_Pos)                       /*!< RTC RIIR: TIF Mask */

#define RTC_RIIR_AIF_Pos        0                                               /*!< RTC RIIR: AIF Position */
#define RTC_RIIR_AIF_Msk        (1ul << RTC_RIIR_AIF_Pos)                       /*!< RTC RIIR: AIF Mask */

/* RTC TTR Bit Field Definitions */
#define RTC_TTR_TWKE_Pos        3                                               /*!< RTC TTR: TWKE Position */
#define RTC_TTR_TWKE_Msk        (0x1ul << RTC_TTR_TWKE_Pos)                    /*!< RTC TTR: TWKE Mask */
#define RTC_TTR_TTR_Pos         0                                               /*!< RTC TTR: TTR Position */
#define RTC_TTR_TTR_Msk         (0x7ul << RTC_TTR_TTR_Pos)                      /*!< RTC TTR: TTR Mask */

/* RTC SPRCTL Bit Field Definitions */
#define RTC_SPRCTL_SNOOPEDGE_Pos   1                                            /*!< RTC SPRCTL: SNOOPEDGE Position */
#define RTC_SPRCTL_SNOOPEDGE_Msk   (1ul << RTC_SPRCTL_SNOOPEDGE_Pos)            /*!< RTC SPRCTL: SNOOPEDGE Mask */

#define RTC_SPRCTL_SNOOPEN_Pos    0                                             /*!< RTC SPRCTL: SNOOPEN Position */
#define RTC_SPRCTL_SNOOPEN_Msk    (1ul << RTC_SPRCTL_SNOOPEN_Pos)               /*!< RTC SPRCTL: SNOOPEN Mask */

/*@}*/ /* end of group NANO100_RTC */


/*------------- Smart Card Control Register (SC) -----------------------------*/
/** @addtogroup NANO100_SC NANO100 Smart Card Control Register (SC)
  Memory Mapped Structure for NANO100 Series Smart Card Controller
  @{
*/
/**
  * @brief SC register map
  */
typedef struct {
    union {
        __I  uint32_t  RBR;                        /*!< Offset: 0x0000  SC Receiving Buffer Register                           */
        __O  uint32_t  THR;                        /*!< Offset: 0x0000  SC Transmit Holding Register                           */
    };
    __IO uint32_t  CTL;                        /*!< Offset: 0x0004  SC Control Register                                    */
    __IO uint32_t  ALTCTL;                     /*!< Offset: 0x0008  SC Alternate Control Register                          */
    __IO uint32_t  EGTR;                       /*!< Offset: 0x000C  SC Extend Guard Time Register                          */
    __IO uint32_t  RFTMR;                      /*!< Offset: 0x0010  SC Receive Buffer Time-Out Register                    */
    __IO uint32_t  ETUCR;                      /*!< Offset: 0x0014  SC ETU Control Register                                */
    __IO uint32_t  IER;                        /*!< Offset: 0x0018  SC Interrupt Enable Register                           */
    __IO uint32_t  ISR;                        /*!< Offset: 0x001C  SC Interrupt Status Register                           */
    __IO uint32_t  TRSR;                       /*!< Offset: 0x0020  SC Transfer Status Register                            */
    __IO uint32_t  PINCSR;                     /*!< Offset: 0x0024  SC Pin Control State Register                          */
    __IO uint32_t  TMR0;                       /*!< Offset: 0x0028  SC Internal Timer Control Register 0                   */
    __IO uint32_t  TMR1;                       /*!< Offset: 0x002C  SC Internal Timer Control Register 1                   */
    __IO uint32_t  TMR2;                       /*!< Offset: 0x0030  SC Internal Timer Control Register 2                   */
    __IO uint32_t  UACTL;                      /*!< Offset: 0x0034  SC UART Mode Control Register                          */
    __I  uint32_t  TDRA;                       /*!< Offset: 0x0038  SC Timer data register A                               */
    __I  uint32_t  TDRB;                       /*!< Offset: 0x003C  SC Timer data register B                               */
} SC_T;


/* SC RBR Bit Field Definitions */
#define SC_RBR_RBR_Pos                      0                                /*!< SC RBR: RBR Position */
#define SC_RBR_RBR_Msk                      (0xFFul << SC_RBR_RBR_Pos)       /*!< SC RBR: RBR Mask */

/* SC THR Bit Field Definitions */
#define SC_THR_THR_Pos                      0                                /*!< SC THR: THR Position */
#define SC_THR_THR_Msk                      (0xFFul << SC_THR_THR_Pos)       /*!< SC THR: THR Mask */

/* SC CTL Bit Field Definitions */
#define SC_CTL_CD_DEB_SEL_Pos               24                               /*!< SC CTL: CD_DEB_SEL Position */
#define SC_CTL_CD_DEB_SEL_Msk               (3ul << SC_CTL_CD_DEB_SEL_Pos)   /*!< SC CTL: CD_DEB_SEL Mask */

#define SC_CTL_TX_ERETRY_EN_Pos             23                               /*!< SC CTL: TX_ERETRY_EN Position */
#define SC_CTL_TX_ERETRY_EN_Msk             (1ul << SC_CTL_TX_ERETRY_EN_Pos) /*!< SC CTL: TX_ERETRY_EN Mask */

#define SC_CTL_TX_ERETRY_Pos                20                               /*!< SC CTL: TX_ERETRY Position */
#define SC_CTL_TX_ERETRY_Msk                (7ul << SC_CTL_TX_ERETRY_Pos)    /*!< SC CTL: TX_ERETRY Mask */

#define SC_CTL_RX_ERETRY_EN_Pos             19                               /*!< SC CTL: RX_ERETRY_EN Position */
#define SC_CTL_RX_ERETRY_EN_Msk             (1ul << SC_CTL_RX_ERETRY_EN_Pos) /*!< SC CTL: RX_ERETRY_EN Mask */

#define SC_CTL_RX_ERETRY_Pos                16                               /*!< SC CTL: RX_ERETRY Position */
#define SC_CTL_RX_ERETRY_Msk                (7ul << SC_CTL_RX_ERETRY_Pos)    /*!< SC CTL: RX_ERETRY Mask */

#define SC_CTL_SLEN_Pos                     15                               /*!< SC CTL: SLEN Position */
#define SC_CTL_SLEN_Msk                     (1ul << SC_CTL_SLEN_Pos)         /*!< SC CTL: SLEN Mask */

#define SC_CTL_TMR_SEL_Pos                  13                               /*!< SC CTL: TMR_SEL Position */
#define SC_CTL_TMR_SEL_Msk                  (3ul << SC_CTL_TMR_SEL_Pos)      /*!< SC CTL: TMR_SEL Mask */

#define SC_CTL_BGT_Pos                      8                                /*!< SC CTL: BGT Position */
#define SC_CTL_BGT_Msk                      (0x1Ful << SC_CTL_BGT_Pos)       /*!< SC CTL: BGT Mask */

#define SC_CTL_RX_FTRI_LEV_Pos              6                                /*!< SC CTL: RX_FTRI_LEV Position */
#define SC_CTL_RX_FTRI_LEV_Msk              (3ul << SC_CTL_RX_FTRI_LEV_Pos)  /*!< SC CTL: RX_FTRI_LEV Mask */

#define SC_CTL_CON_SEL_Pos                  4                                /*!< SC CTL: CON_SEL Position */
#define SC_CTL_CON_SEL_Msk                  (3ul << SC_CTL_CON_SEL_Pos)      /*!< SC CTL: CON_SEL Mask */

#define SC_CTL_AUTO_CON_EN_Pos              3                                /*!< SC CTL: AUTO_CON_EN Position */
#define SC_CTL_AUTO_CON_EN_Msk              (1ul << SC_CTL_AUTO_CON_EN_Pos)  /*!< SC CTL: AUTO_CON_EN Mask */

#define SC_CTL_DIS_TX_Pos                   2                                /*!< SC CTL: DIS_TX Position */
#define SC_CTL_DIS_TX_Msk                   (1ul << SC_CTL_DIS_TX_Pos)       /*!< SC CTL: DIS_TX Mask */

#define SC_CTL_DIS_RX_Pos                   1                                /*!< SC CTL: DIS_RX Position */
#define SC_CTL_DIS_RX_Msk                   (1ul << SC_CTL_DIS_RX_Pos)       /*!< SC CTL: DIS_RX Mask */

#define SC_CTL_SC_CEN_Pos                   0                                /*!< SC CTL: SC_CEN Position */
#define SC_CTL_SC_CEN_Msk                   (1ul << SC_CTL_SC_CEN_Pos)       /*!< SC CTL: SC_CEN Mask */

/* SC ALTCTL Bit Field Definitions */
#define SC_ALTCTL_OUTSEL_Pos                16                               /*!< SC ALTCTL: OUTSEL Position */
#define SC_ALTCTL_OUTSEL_Msk                (1ul << SC_ALTCTL_OUTSEL_Pos)    /*!< SC ALTCTL: OUTSEL Mask */

#define SC_ALTCTL_TMR2_ATV_Pos              15                               /*!< SC ALTCTL: TMR2_ATV Position */
#define SC_ALTCTL_TMR2_ATV_Msk              (1ul << SC_ALTCTL_TMR2_ATV_Pos)  /*!< SC ALTCTL: TMR2_ATV Mask */

#define SC_ALTCTL_TMR1_ATV_Pos              14                               /*!< SC ALTCTL: TMR1_ATV Position */
#define SC_ALTCTL_TMR1_ATV_Msk              (1ul << SC_ALTCTL_TMR1_ATV_Pos)  /*!< SC ALTCTL: TMR1_ATV Mask */

#define SC_ALTCTL_TMR0_ATV_Pos              13                               /*!< SC ALTCTL: TMR0_ATV Position */
#define SC_ALTCTL_TMR0_ATV_Msk              (1ul << SC_ALTCTL_TMR0_ATV_Pos)  /*!< SC ALTCTL: TMR0_ATV Mask */

#define SC_ALTCTL_RX_BGT_EN_Pos             12                               /*!< SC ALTCTL: RX_BGT_EN Position */
#define SC_ALTCTL_RX_BGT_EN_Msk             (1ul << SC_ALTCTL_RX_BGT_EN_Pos) /*!< SC ALTCTL: RX_BGT_EN Mask */

#define SC_ALTCTL_INIT_SEL_Pos              8                                /*!< SC ALTCTL: INIT_SEL Position */
#define SC_ALTCTL_INIT_SEL_Msk              (3ul << SC_ALTCTL_INIT_SEL_Pos)  /*!< SC ALTCTL: INIT_SEL Mask */

#define SC_ALTCTL_TMR2_SEN_Pos              7                                /*!< SC ALTCTL: TMR2_SEN Position */
#define SC_ALTCTL_TMR2_SEN_Msk              (1ul << SC_ALTCTL_TMR2_SEN_Pos)  /*!< SC ALTCTL: TMR2_SEN Mask */

#define SC_ALTCTL_TMR1_SEN_Pos              6                                /*!< SC ALTCTL: TMR1_SEN Position */
#define SC_ALTCTL_TMR1_SEN_Msk              (1ul << SC_ALTCTL_TMR1_SEN_Pos)  /*!< SC ALTCTL: TMR1_SEN Mask */

#define SC_ALTCTL_TMR0_SEN_Pos              5                                /*!< SC ALTCTL: TMR0_SEN Position */
#define SC_ALTCTL_TMR0_SEN_Msk              (1ul << SC_ALTCTL_TMR0_SEN_Pos)  /*!< SC ALTCTL: TMR0_SEN Mask */

#define SC_ALTCTL_WARST_EN_Pos              4                                /*!< SC ALTCTL: WARST_EN Position */
#define SC_ALTCTL_WARST_EN_Msk              (1ul << SC_ALTCTL_WARST_EN_Pos)  /*!< SC ALTCTL: WARST_EN Mask */

#define SC_ALTCTL_ACT_EN_Pos                3                                /*!< SC ALTCTL: ACT_EN Position */
#define SC_ALTCTL_ACT_EN_Msk                (1ul << SC_ALTCTL_ACT_EN_Pos)    /*!< SC ALTCTL: ACT_EN Mask */

#define SC_ALTCTL_DACT_EN_Pos               2                                /*!< SC ALTCTL: DACT_EN Position */
#define SC_ALTCTL_DACT_EN_Msk               (1ul << SC_ALTCTL_DACT_EN_Pos)   /*!< SC ALTCTL: DACT_EN Mask */

#define SC_ALTCTL_RX_RST_Pos                1                                /*!< SC ALTCTL: RX_RST Position */
#define SC_ALTCTL_RX_RST_Msk                (1ul << SC_ALTCTL_RX_RST_Pos)    /*!< SC ALTCTL: RX_RST Mask */

#define SC_ALTCTL_TX_RST_Pos                0                                /*!< SC ALTCTL: TX_RST Position */
#define SC_ALTCTL_TX_RST_Msk                (1ul << SC_ALTCTL_TX_RST_Pos)    /*!< SC ALTCTL: TX_RST Mask */

/* SC EGTR Bit Field Definitions */
#define SC_EGTR_EGT_Pos                     0                               /*!< SC EGTR: EGT Position */
#define SC_EGTR_EGT_Msk                     (0xFFul << SC_EGTR_EGT_Pos)     /*!< SC EGTR: EGT Mask */

/* SC RFTMR Bit Field Definitions */
#define SC_RFTMR_RFTM_Pos                   0                               /*!< SC RFTMR: RFTM Position */
#define SC_RFTMR_RFTM_Msk                   (0x1FFul << SC_RFTMR_RFTM_Pos)  /*!< SC RFTMR: RFTM Mask */

/* SC ETUCR Bit Field Definitions */
#define SC_ETUCR_COMPEN_EN_Pos              15                               /*!< SC ETUCR: COMPEN_EN Position */
#define SC_ETUCR_COMPEN_EN_Msk              (1ul << SC_ETUCR_COMPEN_EN_Pos)  /*!< SC ETUCR: COMPEN_EN Mask */

#define SC_ETUCR_ETU_RDIV_Pos               0                                   /*!< SC ETUCR: ETU_RDIV Position */
#define SC_ETUCR_ETU_RDIV_Msk               (0xFFFul << SC_ETUCR_ETU_RDIV_Pos)  /*!< SC ETUCR: ETU_RDIV Mask */

/* SC IER Bit Field Definitions */
#define SC_IER_ACON_ERR_IE_Pos              10                                  /*!< SC IER: ACON_ERR_IE Position */
#define SC_IER_ACON_ERR_IE_Msk              (1ul << SC_IER_ACON_ERR_IE_Pos)     /*!< SC IER: ACON_ERR_IE Mask */

#define SC_IER_RTMR_IE_Pos                  9                               /*!< SC IER: RTMR_IE Position */
#define SC_IER_RTMR_IE_Msk                  (1ul << SC_IER_RTMR_IE_Pos)     /*!< SC IER: RTMR_IE Mask */

#define SC_IER_INIT_IE_Pos                  8                               /*!< SC IER: INIT_IE Position */
#define SC_IER_INIT_IE_Msk                  (1ul << SC_IER_INIT_IE_Pos)     /*!< SC IER: INIT_IE Mask */

#define SC_IER_CD_IE_Pos                    7                               /*!< SC IER: CD_IE Position */
#define SC_IER_CD_IE_Msk                    (1ul << SC_IER_CD_IE_Pos)       /*!< SC IER: CD_IE Mask */

#define SC_IER_BGT_IE_Pos                   6                               /*!< SC IER: BGT_IE Position */
#define SC_IER_BGT_IE_Msk                   (1ul << SC_IER_BGT_IE_Pos)      /*!< SC IER: BGT_IE Mask */

#define SC_IER_TMR2_IE_Pos                  5                               /*!< SC IER: TMR2_IE Position */
#define SC_IER_TMR2_IE_Msk                  (1ul << SC_IER_TMR2_IE_Pos)     /*!< SC IER: TMR2_IE Mask */

#define SC_IER_TMR1_IE_Pos                  4                               /*!< SC IER: TMR1_IE Position */
#define SC_IER_TMR1_IE_Msk                  (1ul << SC_IER_TMR1_IE_Pos)     /*!< SC IER: TMR1_IE Mask */

#define SC_IER_TMR0_IE_Pos                  3                               /*!< SC IER: TMR0_IE Position */
#define SC_IER_TMR0_IE_Msk                  (1ul << SC_IER_TMR0_IE_Pos)     /*!< SC IER: TMR0_IE Mask */

#define SC_IER_TERR_IE_Pos                  2                               /*!< SC IER: TERR_IE Position */
#define SC_IER_TERR_IE_Msk                  (1ul << SC_IER_TERR_IE_Pos)     /*!< SC IER: TERR_IE Mask */

#define SC_IER_TBE_IE_Pos                   1                               /*!< SC IER: TBE_IE Position */
#define SC_IER_TBE_IE_Msk                   (1ul << SC_IER_TBE_IE_Pos)      /*!< SC IER: TBE_IE Mask */

#define SC_IER_RDA_IE_Pos                   0                               /*!< SC IER: RDA_IE Position */
#define SC_IER_RDA_IE_Msk                   (1ul << SC_IER_RDA_IE_Pos)      /*!< SC IER: RDA_IE Mask */

/* SC ISR Bit Field Definitions */
#define SC_ISR_ACON_ERR_IS_Pos              10                              /*!< SC ISR: ACON_ERR_IS Position */
#define SC_ISR_ACON_ERR_IS_Msk              (1ul << SC_ISR_ACON_ERR_IS_Pos) /*!< SC ISR: ACON_ERR_IS Mask */

#define SC_ISR_RTMR_IS_Pos                  9                               /*!< SC ISR: RTMR_IS Position */
#define SC_ISR_RTMR_IS_Msk                  (1ul << SC_ISR_RTMR_IS_Pos)     /*!< SC ISR: RTMR_IS Mask */

#define SC_ISR_INIT_IS_Pos                  8                               /*!< SC ISR: INIT_IS Position */
#define SC_ISR_INIT_IS_Msk                  (1ul << SC_ISR_INIT_IS_Pos)     /*!< SC ISR: INIT_IS Mask */

#define SC_ISR_CD_IS_Pos                    7                               /*!< SC ISR: CD_IS Position */
#define SC_ISR_CD_IS_Msk                    (1ul << SC_ISR_CD_IS_Pos)       /*!< SC ISR: CD_IS Mask */

#define SC_ISR_BGT_IS_Pos                   6                               /*!< SC ISR: BGT_IS Position */
#define SC_ISR_BGT_IS_Msk                   (1ul << SC_ISR_BGT_IS_Pos)      /*!< SC ISR: BGT_IS Mask */

#define SC_ISR_TMR2_IS_Pos                  5                               /*!< SC ISR: TMR2_IS Position */
#define SC_ISR_TMR2_IS_Msk                  (1ul << SC_ISR_TMR2_IS_Pos)     /*!< SC ISR: TMR2_IS Mask */

#define SC_ISR_TMR1_IS_Pos                  4                               /*!< SC ISR: TMR1_IS Position */
#define SC_ISR_TMR1_IS_Msk                  (1ul << SC_ISR_TMR1_IS_Pos)     /*!< SC ISR: TMR1_IS Mask */

#define SC_ISR_TMR0_IS_Pos                  3                               /*!< SC ISR: TMR0_IS Position */
#define SC_ISR_TMR0_IS_Msk                  (1ul << SC_ISR_TMR0_IS_Pos)     /*!< SC ISR: TMR0_IS Mask */

#define SC_ISR_TERR_IS_Pos                  2                               /*!< SC ISR: TERR_IS Position */
#define SC_ISR_TERR_IS_Msk                  (1ul << SC_ISR_TERR_IS_Pos)     /*!< SC ISR: TERR_IS Mask */

#define SC_ISR_TBE_IS_Pos                   1                               /*!< SC ISR: TXBE_IS Position */
#define SC_ISR_TBE_IS_Msk                   (1ul << SC_ISR_TBE_IS_Pos)      /*!< SC ISR: TXBE_IS Mask */

#define SC_ISR_RDA_IS_Pos                   0                               /*!< SC ISR: RDA_IS Position */
#define SC_ISR_RDA_IS_Msk                   (1ul << SC_ISR_RDA_IS_Pos)      /*!< SC ISR: RDA_IS Mask */


/* SC TRSR Bit Field Definitions */
#define SC_TRSR_TX_ATV_Pos                  31                                /*!< SC TRSR: TX_ATV Position */
#define SC_TRSR_TX_ATV_Msk                  (1ul << SC_TRSR_TX_ATV_Pos)       /*!< SC TRSR: TX_ATV Mask */

#define SC_TRSR_TX_OVER_REERR_Pos           30                                /*!< SC TRSR: TX_OVER_REERR Position */
#define SC_TRSR_TX_OVER_REERR_Msk           (1ul << SC_TRSR_TX_OVER_REERR_Pos)/*!< SC TRSR: TX_OVER_REERR Mask */

#define SC_TRSR_TX_REERR_Pos                29                                /*!< SC TRSR: TX_REERR Position */
#define SC_TRSR_TX_REERR_Msk                (1ul << SC_TRSR_TX_REERR_Pos)     /*!< SC TRSR: TX_REERR Mask */

#define SC_TRSR_TX_POINT_F_Pos              24                                /*!< SC TRSR: TX_POINT_F Position */
#define SC_TRSR_TX_POINT_F_Msk              (7ul << SC_TRSR_TX_POINT_F_Pos)   /*!< SC TRSR: TX_POINT_F Mask */

#define SC_TRSR_RX_ATV_Pos                  23                                /*!< SC TRSR: RX_ATV Position */
#define SC_TRSR_RX_ATV_Msk                  (1ul << SC_TRSR_RX_ATV_Pos)       /*!< SC TRSR: RX_ATV Mask */

#define SC_TRSR_RX_OVER_REERR_Pos           22                                /*!< SC TRSR: RX_OVER_REERR Position */
#define SC_TRSR_RX_OVER_REERR_Msk           (1ul << SC_TRSR_RX_OVER_REERR_Pos)/*!< SC TRSR: RX_OVER_REERR Mask */

#define SC_TRSR_RX_REERR_Pos                21                                /*!< SC TRSR: RX_REERR Position */
#define SC_TRSR_RX_REERR_Msk                (1ul << SC_TRSR_RX_REERR_Pos)     /*!< SC TRSR: RX_REERR Mask */

#define SC_TRSR_RX_POINT_F_Pos              16                                /*!< SC TRSR: RX_POINT_F Position */
#define SC_TRSR_RX_POINT_F_Msk              (7ul << SC_TRSR_RX_POINT_F_Pos)   /*!< SC TRSR: RX_POINT_F Mask */

#define SC_TRSR_TX_FULL_F_Pos               10                                /*!< SC TRSR: TX_FULL_F Position */
#define SC_TRSR_TX_FULL_F_Msk               (1ul << SC_TRSR_TX_FULL_F_Pos)    /*!< SC TRSR: TX_FULL_F Mask */

#define SC_TRSR_TX_EMPTY_F_Pos              9                                 /*!< SC TRSR: TX_EMPTY_F Position */
#define SC_TRSR_TX_EMPTY_F_Msk              (1ul << SC_TRSR_TX_EMPTY_F_Pos)   /*!< SC TRSR: TX_EMPTY_F Mask */

#define SC_TRSR_TX_OVER_F_Pos               8                                 /*!< SC TRSR: TX_OVER_F Position */
#define SC_TRSR_TX_OVER_F_Msk               (1ul << SC_TRSR_TX_OVER_F_Pos)    /*!< SC TRSR: TX_OVER_F Mask */

#define SC_TRSR_RX_EBR_F_Pos                6                                 /*!< SC TRSR: RX_EBR_F Position */
#define SC_TRSR_RX_EBR_F_Msk                (1ul << SC_TRSR_RX_EBR_F_Pos)     /*!< SC TRSR: RX_EBR_F Mask */

#define SC_TRSR_RX_EFR_F_Pos                5                                 /*!< SC TRSR: RX_EFR_F Position */
#define SC_TRSR_RX_EFR_F_Msk                (1ul << SC_TRSR_RX_EFR_F_Pos)     /*!< SC TRSR: RX_EFR_F Mask */

#define SC_TRSR_RX_EPA_F_Pos                4                                 /*!< SC TRSR: RX_EPA_F Position */
#define SC_TRSR_RX_EPA_F_Msk                (1ul << SC_TRSR_RX_EPA_F_Pos)     /*!< SC TRSR: RX_EPA_F Mask */

#define SC_TRSR_RX_FULL_F_Pos               2                                 /*!< SC TRSR: RX_FULL_F Position */
#define SC_TRSR_RX_FULL_F_Msk               (1ul << SC_TRSR_RX_FULL_F_Pos)    /*!< SC TRSR: RX_FULL_F Mask */

#define SC_TRSR_RX_EMPTY_F_Pos              1                                 /*!< SC TRSR: RX_EMPTY_F Position */
#define SC_TRSR_RX_EMPTY_F_Msk              (1ul << SC_TRSR_RX_EMPTY_F_Pos)   /*!< SC TRSR: RX_EMPTY_F Mask */

#define SC_TRSR_RX_OVER_F_Pos               0                                 /*!< SC TRSR: RX_OVER_F Position */
#define SC_TRSR_RX_OVER_F_Msk               (1ul << SC_TRSR_RX_OVER_F_Pos)    /*!< SC TRSR: RX_OVER_F Mask */

/* SC PINCSR Bit Field Definitions */
#define SC_PINCSR_DATA_I_ST_Pos             16                                  /*!< SC PINCSR: DATA_I_ST Position */
#define SC_PINCSR_DATA_I_ST_Msk             (1ul << SC_PINCSR_DATA_I_ST_Pos)    /*!< SC PINCSR: DATA_I_ST Mask */

#define SC_PINCSR_POW_INV_Pos               11                                  /*!< SC PINCSR: POW_INV Position */
#define SC_PINCSR_POW_INV_Msk               (1ul << SC_PINCSR_POW_INV_Pos)      /*!< SC PINCSR: POW_INV Mask */

#define SC_PINCSR_CD_LEV_Pos                10                                  /*!< SC PINCSR: CD_LEV Position */
#define SC_PINCSR_CD_LEV_Msk                (1ul << SC_PINCSR_CD_LEV_Pos)       /*!< SC PINCSR: CD_LEV Mask */

#define SC_PINCSR_SC_DATA_O_Pos             9                                   /*!< SC PINCSR: SC_DATA_O Position */
#define SC_PINCSR_SC_DATA_O_Msk             (1ul << SC_PINCSR_SC_DATA_O_Pos)    /*!< SC PINCSR: SC_DATA_O Mask */

#define SC_PINCSR_SC_OEN_ST_Pos             8                                   /*!< SC PINCSR: SC_OEN_ST Position */
#define SC_PINCSR_SC_OEN_ST_Msk             (1ul << SC_PINCSR_SC_OEN_ST_Pos)    /*!< SC PINCSR: SC_OEN_ST Mask */

#define SC_PINCSR_ADAC_CD_EN_Pos            7                                   /*!< SC PINCSR: ADAC_CD_EN Position */
#define SC_PINCSR_ADAC_CD_EN_Msk            (1ul << SC_PINCSR_ADAC_CD_EN_Pos)   /*!< SC PINCSR: ADAC_CD_EN Mask */

#define SC_PINCSR_CLK_KEEP_Pos              6                                   /*!< SC PINCSR: CLK_KEEP Position */
#define SC_PINCSR_CLK_KEEP_Msk              (1ul << SC_PINCSR_CLK_KEEP_Pos)     /*!< SC PINCSR: CLK_KEEP Mask */

#define SC_PINCSR_CLK_STOP_LEV_Pos          5                                   /*!< SC PINCSR: CLK_STOP_LEV Position */
#define SC_PINCSR_CLK_STOP_LEV_Msk          (1ul << SC_PINCSR_CLK_STOP_LEV_Pos) /*!< SC PINCSR: CLK_STOP_LEV Mask */

#define SC_PINCSR_CD_PIN_ST_Pos             4                                   /*!< SC PINCSR: CD_PIN_ST Position */
#define SC_PINCSR_CD_PIN_ST_Msk             (1ul << SC_PINCSR_CD_PIN_ST_Pos)    /*!< SC PINCSR: CD_PIN_ST Mask */

#define SC_PINCSR_CD_INS_F_Pos              3                                   /*!< SC PINCSR: CD_INS_F Position */
#define SC_PINCSR_CD_INS_F_Msk              (1ul << SC_PINCSR_CD_INS_F_Pos)     /*!< SC PINCSR: CD_INS_F Mask */

#define SC_PINCSR_CD_REM_F_Pos              2                                   /*!< SC PINCSR: CD_REM_F Position */
#define SC_PINCSR_CD_REM_F_Msk              (1ul << SC_PINCSR_CD_REM_F_Pos)     /*!< SC PINCSR: CD_REM_F Mask */

#define SC_PINCSR_SC_RST_Pos                1                                   /*!< SC PINCSR: SC_RST Position */
#define SC_PINCSR_SC_RST_Msk                (1ul << SC_PINCSR_SC_RST_Pos)       /*!< SC PINCSR: SC_RST Mask */

#define SC_PINCSR_POW_EN_Pos                0                                   /*!< SC PINCSR: POW_EN Position */
#define SC_PINCSR_POW_EN_Msk                (1ul << SC_PINCSR_POW_EN_Pos)       /*!< SC PINCSR: POW_EN Mask */

/* SC TMR0 Bit Field Definitions */
#define SC_TMR0_MODE_Pos                    24                              /*!< SC TMR0: MODE Position */
#define SC_TMR0_MODE_Msk                    (0xFul << SC_TMR0_MODE_Pos)     /*!< SC TMR0: MODE Mask */

#define SC_TMR0_CNT_Pos                     0                               /*!< SC TMR0: CNT Position */
#define SC_TMR0_CNT_Msk                     (0xFFFFFFul << SC_TMR0_CNT_Pos) /*!< SC TMR0: CNT Mask */

/* SC TMR1 Bit Field Definitions */
#define SC_TMR1_MODE_Pos                    24                              /*!< SC TMR1: MODE Position */
#define SC_TMR1_MODE_Msk                    (0xFul << SC_TMR1_MODE_Pos)     /*!< SC TMR1: MODE Mask */

#define SC_TMR1_CNT_Pos                     0                               /*!< SC TMR1: CNT Position */
#define SC_TMR1_CNT_Msk                     (0xFFul << SC_TMR1_CNT_Pos)     /*!< SC TMR1: CNT Mask */

/* SC TMR2 Bit Field Definitions */
#define SC_TMR2_MODE_Pos                    24                              /*!< SC TMR2: MODE Position */
#define SC_TMR2_MODE_Msk                    (0xFul << SC_TMR2_MODE_Pos)     /*!< SC TMR2: MODE Mask */

#define SC_TMR2_CNT_Pos                     0                               /*!< SC TMR2: CNT Position */
#define SC_TMR2_CNT_Msk                     (0xFFul << SC_TMR2_CNT_Pos)     /*!< SC TMR2: CNT Mask */

/* SC UACTL Bit Field Definitions */
#define SC_UACTL_OPE_Pos                    7                               /*!< SC UACTL: OPE Position */
#define SC_UACTL_OPE_Msk                    (0x1ul << SC_UACTL_OPE_Pos)     /*!< SC UACTL: OPE Mask */

#define SC_UACTL_PBDIS_Pos                  6                               /*!< SC UACTL: PBDIS Position */
#define SC_UACTL_PBDIS_Msk                  (0x1ul << SC_UACTL_PBDIS_Pos)   /*!< SC UACTL: PBDIS Mask */

#define SC_UACTL_DATA_LEN_Pos               5                                   /*!< SC UACTL: DATA_LEN Position */
#define SC_UACTL_DATA_LEN_Msk               (0x1ul << SC_UACTL_DATA_LEN_Pos)    /*!< SC UACTL: DATA_LEN Mask */

#define SC_UACTL_UA_MODE_EN_Pos             0                                   /*!< SC UACTL: UA_MODE_EN Position */
#define SC_UACTL_UA_MODE_EN_Msk             (0x1ul << SC_UACTL_UA_MODE_EN_Pos)  /*!< SC UACTL: UA_MODE_EN Mask */

/* SC TDRA Bit Field Definitions */
#define SC_TDRA_TDR0_Pos                    0                                   /*!< SC TDRA: TDR0 Position */
#define SC_TDRA_TDR0_Msk                    (0xFFFFFFul << SC_TDRA_TDR0_Pos)    /*!< SC TDRA: TDR0 Mask */

/* SC TDRB Bit Field Definitions */
#define SC_TDRB_TDR2_Pos                    8                               /*!< SC TDRB: TDR2 Position */
#define SC_TDRB_TDR2_Msk                    (0xFFul << SC_TDRB_TDR2_Pos)    /*!< SC TDRB: TDR2 Mask */

#define SC_TDRB_TDR1_Pos                    0                               /*!< SC TDRB: TDR1 Position */
#define SC_TDRB_TDR1_Msk                    (0xFFul << SC_TDRB_TDR1_Pos)    /*!< SC TDRB: TDR1 Mask */

/*@}*/ /* end of group NANO100_SC */


/*-------------------- Serial Peripheral Interface (SPI) ----------------------*/
/** @addtogroup NANO100_SPI NANO100 Serial Peripheral Interface (SPI)
  Memory Mapped Structure for NANO100 Series Serial Peripheral Interface
  @{
 */
/**
 * @brief SPI register map
 */
typedef struct {
    __IO uint32_t  CTL;                         /*!< Offset: 0x0000   SPI Control Register                              */
    __IO uint32_t  STATUS;                      /*!< Offset: 0x0004   SPI Status  Register                              */
    __IO uint32_t  CLKDIV;                      /*!< Offset: 0x0008   SPI Serial Clock Divider Register                 */
    __IO uint32_t  SSR;                         /*!< Offset: 0x000C   SPI Slave Select Register                         */
    __I  uint32_t  RX0;                         /*!< Offset: 0x0010   SPI Receive Data FIFO Register 0                  */
    __I  uint32_t  RX1;                         /*!< Offset: 0x0014   SPI Receive Data FIFO Register 1                  */
    uint32_t  RESERVED0;
    uint32_t  RESERVED1;
    __O  uint32_t  TX0;                         /*!< Offset: 0x0020   SPI Transmit Data FIFO Register 0                 */
    __O  uint32_t  TX1;                         /*!< Offset: 0x0024   SPI Transmit Data FIFO Register 1                 */
    uint32_t  RESERVED2;
    uint32_t  RESERVED3;
    uint32_t  RESERVED4;
    __IO uint32_t  VARCLK;                      /*!< Offset: 0x0034   SPI Variable Clock Pattern Flag Register          */
    __IO uint32_t  DMA;                         /*!< Offset: 0x0038   SPI PDMA Control Register                         */
    __IO uint32_t  FFCTL;                       /*!< Offset: 0x003C   SPI FIFO Control Register                         */
} SPI_T;
/*@}*/ /* end of group NANO100_SPI */

/* SPI_CTL Bit Field Definitions */
#define SPI_CTL_GO_BUSY_Pos       0                                   /*!< SPI CTL: GO_BUSY Position */
#define SPI_CTL_GO_BUSY_Msk       (1ul << SPI_CTL_GO_BUSY_Pos)        /*!< SPI CTL: GO_BUSY Mask */
#define SPI_CTL_RX_NEG_Pos        1                                   /*!< SPI CTL: RX_NEG Position */
#define SPI_CTL_RX_NEG_Msk        (1ul << SPI_CTL_RX_NEG_Pos)         /*!< SPI CTL: RX_NEG Mask */
#define SPI_CTL_TX_NEG_Pos        2                                   /*!< SPI CTL: TX_NEG Position */
#define SPI_CTL_TX_NEG_Msk        (1ul << SPI_CTL_TX_NEG_Pos)         /*!< SPI CTL: TX_NEG Mask */
#define SPI_CTL_TX_BIT_LEN_Pos    3                                   /*!< SPI CTL: TX_BIT_LEN Position */
#define SPI_CTL_TX_BIT_LEN_Msk    (0x1Ful << SPI_CTL_TX_BIT_LEN_Pos)  /*!< SPI CTL: TX_BIT_LEN Mask */
#define SPI_CTL_LSB_Pos           10                                  /*!< SPI CTL: LSB Position */
#define SPI_CTL_LSB_Msk           (1ul << SPI_CTL_LSB_Pos)            /*!< SPI CTL: LSB Mask */
#define SPI_CTL_CLKP_Pos          11                                  /*!< SPI CTL: CLKP Position */
#define SPI_CTL_CLKP_Msk          (1ul << SPI_CTL_CLKP_Pos)           /*!< SPI CTL: CLKP Mask */
#define SPI_CTL_SP_CYCLE_Pos      12                                  /*!< SPI CTL: SP_CYCLE Position */
#define SPI_CTL_SP_CYCLE_Msk      (0xFul << SPI_CTL_SP_CYCLE_Pos)     /*!< SPI CTL: SP_CYCLE Mask */
#define SPI_CTL_INTEN_Pos         17                                  /*!< SPI CTL: INTEN Position */
#define SPI_CTL_INTEN_Msk         (1ul << SPI_CTL_INTEN_Pos)          /*!< SPI CTL: INTEN Mask */
#define SPI_CTL_SLAVE_Pos         18                                  /*!< SPI CTL: SLAVE Position */
#define SPI_CTL_SLAVE_Msk         (1ul << SPI_CTL_SLAVE_Pos)          /*!< SPI CTL: SLAVE Mask */
#define SPI_CTL_REORDER_Pos       19                                  /*!< SPI CTL: REORDER Position */
#define SPI_CTL_REORDER_Msk       (1ul << SPI_CTL_REORDER_Pos)        /*!< SPI CTL: REORDER Mask */
#define SPI_CTL_FIFOM_Pos         21                                  /*!< SPI CTL: FIFOM Position */
#define SPI_CTL_FIFOM_Msk         (1ul << SPI_CTL_FIFOM_Pos)          /*!< SPI CTL: FIFOM Mask */
#define SPI_CTL_TWOB_Pos          22                                  /*!< SPI CTL: TWOB Position */
#define SPI_CTL_TWOB_Msk          (1ul << SPI_CTL_TWOB_Pos)           /*!< SPI CTL: TWOB Mask */
#define SPI_CTL_VARCLK_EN_Pos     23                                  /*!< SPI CTL: VARCLK_EN Position */
#define SPI_CTL_VARCLK_EN_Msk     (1ul << SPI_CTL_VARCLK_EN_Pos)      /*!< SPI CTL: VARCLK_EN Mask */
#define SPI_CTL_DUAL_IO_DIR_Pos   28                                  /*!< SPI CTL: DUAL_IO_DIR Position */
#define SPI_CTL_DUAL_IO_DIR_Msk   (1ul << SPI_CTL_DUAL_IO_DIR_Pos)    /*!< SPI CTL: DUAL_IO_DIR Mask */
#define SPI_CTL_DUAL_IO_EN_Pos    29                                  /*!< SPI CTL: DUAL_IO_EN Position */
#define SPI_CTL_DUAL_IO_EN_Msk    (1ul << SPI_CTL_DUAL_IO_EN_Pos)     /*!< SPI CTL: DUAL_IO_EN Mask */
#define SPI_CTL_WKEUP_EN_Pos      31                                  /*!< SPI CTL: WKEUP_EN Position */
#define SPI_CTL_WKEUP_EN_Msk      (1ul << SPI_CTL_WKEUP_EN_Pos)       /*!< SPI CTL: WKEUP_EN Mask */

/* SPI_STATUS Bit Field Definitions */
#define SPI_STATUS_RX_EMPTY_Pos            0                                          /*!< SPI STATUS: RX_EMPTY Position */
#define SPI_STATUS_RX_EMPTY_Msk            (1ul << SPI_STATUS_RX_EMPTY_Pos)           /*!< SPI STATUS: RX_EMPTY Mask */
#define SPI_STATUS_RX_FULL_Pos             1                                          /*!< SPI STATUS: RX_FULL Position */
#define SPI_STATUS_RX_FULL_Msk             (1ul << SPI_STATUS_RX_FULL_Pos)            /*!< SPI STATUS: RX_FULL Mask */
#define SPI_STATUS_TX_EMPTY_Pos            2                                          /*!< SPI STATUS: TX_EMPTY Position */
#define SPI_STATUS_TX_EMPTY_Msk            (1ul << SPI_STATUS_TX_EMPTY_Pos)           /*!< SPI STATUS: TX_EMPTY Mask */
#define SPI_STATUS_TX_FULL_Pos             3                                          /*!< SPI STATUS: TX_FULL Position */
#define SPI_STATUS_TX_FULL_Msk             (1ul << SPI_STATUS_TX_FULL_Pos)            /*!< SPI STATUS: TX_FULL Mask */
#define SPI_STATUS_LTRIG_FLAG_Pos          4                                          /*!< SPI STATUS: LTRIG_FLAG Position */
#define SPI_STATUS_LTRIG_FLAG_Msk          (1ul << SPI_STATUS_LTRIG_FLAG_Pos)         /*!< SPI STATUS: LTRIG_FLAG Mask */
#define SPI_STATUS_SLV_START_INTSTS_Pos    6                                          /*!< SPI STATUS: LTRIG_FLAG Position */
#define SPI_STATUS_SLV_START_INTSTS_Msk    (1ul << SPI_STATUS_SLV_START_INTSTS_Pos)   /*!< SPI STATUS: LTRIG_FLAG Mask */
#define SPI_STATUS_INTSTS_Pos              7                                          /*!< SPI STATUS: INTSTS Position */
#define SPI_STATUS_INTSTS_Msk              (1ul << SPI_STATUS_INTSTS_Pos)             /*!< SPI STATUS: INTSTS Mask */
#define SPI_STATUS_RXINT_STS_Pos           8                                          /*!< SPI STATUS: RXINT_STS Position */
#define SPI_STATUS_RXINT_STS_Msk           (1ul << SPI_STATUS_RXINT_STS_Pos)          /*!< SPI STATUS: RXINT_STS Mask */
#define SPI_STATUS_RX_OVER_RUN_Pos         9                                          /*!< SPI STATUS: RX_OVER_RUN Position */
#define SPI_STATUS_RX_OVER_RUN_Msk         (1ul << SPI_STATUS_RX_OVER_RUN_Pos)        /*!< SPI STATUS: RX_OVER_RUN Mask */
#define SPI_STATUS_TXINT_STS_Pos           10                                         /*!< SPI STATUS: TXINT_STS Position */
#define SPI_STATUS_TXINT_STS_Msk           (1ul << SPI_STATUS_TXINT_STS_Pos)          /*!< SPI STATUS: TXINT_STS Mask */
#define SPI_STATUS_TIME_OUT_STS_Pos        12                                         /*!< SPI STATUS: TIME_OUT_STS Position */
#define SPI_STATUS_TIME_OUT_STS_Msk        (1ul << SPI_STATUS_TIME_OUT_STS_Pos)       /*!< SPI STATUS: TIME_OUT_STS Mask */
#define SPI_STATUS_RX_FIFO_CNT_Pos         16                                         /*!< SPI STATUS: RX_FIFO_CNT Position */
#define SPI_STATUS_RX_FIFO_CNT_Msk         (0xFul << SPI_STATUS_RX_FIFO_CNT_Pos)      /*!< SPI STATUS: RX_FIFO_CNT Mask */
#define SPI_STATUS_TX_FIFO_CNT_Pos         20                                         /*!< SPI STATUS: TX_FIFO_CNT Position */
#define SPI_STATUS_TX_FIFO_CNT_Msk         (0xFul << SPI_STATUS_TX_FIFO_CNT_Pos)      /*!< SPI STATUS: TX_FIFO_CNT Mask */

/* SPI_CLKDIV Bit Field Definitions */
#define SPI_CLKDIV_DIVIDER1_Pos    0                                                  /*!< SPI CLKDIV: DIVIDER1 Position */
#define SPI_CLKDIV_DIVIDER1_Msk    (0xFFul << SPI_CLKDIV_DIVIDER1_Pos)                /*!< SPI CLKDIV: DIVIDER1 Mask */
#define SPI_CLKDIV_DIVIDER2_Pos    16                                                 /*!< SPI CLKDIV: DIVIDER2 Position */
#define SPI_CLKDIV_DIVIDER2_Msk    (0xFFul << SPI_CLKDIV_DIVIDER2_Pos)                /*!< SPI CLKDIV: DIVIDER2 Mask */

/* SPI_SSR Bit Field Definitions */
#define SPI_SSR_SSR_Pos          0                                                    /*!< SPI SSR: SS Position */
#define SPI_SSR_SSR_Msk          (3ul << SPI_SSR_SSR_Pos)                             /*!< SPI SSR: SS Mask */
#define SPI_SSR_SS_LVL_Pos       2                                                    /*!< SPI SSR: SS_LVL Position */
#define SPI_SSR_SS_LVL_Msk       (1ul << SPI_SSR_SS_LVL_Pos)                          /*!< SPI SSR: SS_LVL Mask */
#define SPI_SSR_AUTOSS_Pos       3                                                    /*!< SPI SSR: AUTOSS Position */
#define SPI_SSR_AUTOSS_Msk       (1ul << SPI_SSR_AUTOSS_Pos)                          /*!< SPI SSR: AUTOSS Mask */
#define SPI_SSR_SS_LTRIG_Pos     4                                                    /*!< SPI SSR: SS_LTRIG Position */
#define SPI_SSR_SS_LTRIG_Msk     (1ul << SPI_SSR_SS_LTRIG_Pos)                        /*!< SPI SSR: SS_LTRIG Mask */
#define SPI_SSR_NOSLVSEL_Pos     5                                                    /*!< SPI SSR: NOSLVSEL Position */
#define SPI_SSR_NOSLVSEL_Msk     (1ul << SPI_SSR_NOSLVSEL_Pos)                        /*!< SPI SSR: NOSLVSEL Mask */
#define SPI_SSR_SLV_ABORT_Pos    8                                                    /*!< SPI SSR: SLV_ABORT Position */
#define SPI_SSR_SLV_ABORT_Msk    (1ul << SPI_SSR_SLV_ABORT_Pos)                       /*!< SPI SSR: SLV_ABORT Mask */
#define SPI_SSR_SSTA_INTEN_Pos   9                                                    /*!< SPI SSR: SSTA_INTEN Position */
#define SPI_SSR_SSTA_INTEN_Msk   (1ul << SPI_SSR_SSTA_INTEN_Pos)                      /*!< SPI SSR: SSTA_INTEN Mask */
#define SPI_SSR_SS_INT_OPT_Pos   16                                                   /*!< SPI SSR: SS_INT_OPT Position */
#define SPI_SSR_SS_INT_OPT_Msk   (1ul << SPI_SSR_SS_INT_OPT_Pos)                      /*!< SPI SSR: SS_INT_OPT Mask */

/* SPI_DMA Bit Field Definitions */
#define SPI_DMA_TX_DMA_EN_Pos    0                                                    /*!< SPI DMA: TX_DMA_EN Position */
#define SPI_DMA_TX_DMA_EN_Msk    (1ul << SPI_DMA_TX_DMA_EN_Pos)                       /*!< SPI DMA: TX_DMA_EN Mask */
#define SPI_DMA_RX_DMA_EN_Pos    1                                                    /*!< SPI DMA: RX_DMA_EN Position */
#define SPI_DMA_RX_DMA_EN_Msk    (1ul << SPI_DMA_RX_DMA_EN_Pos)                       /*!< SPI DMA: RX_DMA_EN Mask */
#define SPI_DMA_PDMA_RST_Pos     2                                                    /*!< SPI DMA: PDMA_RST Position */
#define SPI_DMA_PDMA_RST_Msk     (1ul << SPI_DMA_PDMA_RST_Pos)                        /*!< SPI DMA: PDMA_RST Mask */

/* SPI_FFCTL Bit Field Definitions */
#define SPI_FFCTL_TX_THRESHOLD_Pos     28                                             /*!< SPI FFCTL: TX_THRESHOLD Position */
#define SPI_FFCTL_TX_THRESHOLD_Msk     (3ul << SPI_FFCTL_TX_THRESHOLD_Pos)            /*!< SPI FFCTL: TX_THRESHOLD Mask     */
#define SPI_FFCTL_RX_THRESHOLD_Pos     24                                             /*!< SPI FFCTL: RX_THRESHOLD Position */
#define SPI_FFCTL_RX_THRESHOLD_Msk     (3ul << SPI_FFCTL_RX_THRESHOLD_Pos)            /*!< SPI FFCTL: RX_THRESHOLD Mask     */
#define SPI_FFCTL_TIMEOUT_EN_Pos       7                                              /*!< SPI FFCTL: TIMEOUT_EN Position    */
#define SPI_FFCTL_TIMEOUT_EN_Msk       (1ul << SPI_FFCTL_TIMEOUT_EN_Pos)              /*!< SPI FFCTL: TIMEOUT_EN Mask        */
#define SPI_FFCTL_RXOVE_INTEN_Pos      4                                              /*!< SPI FFCTL: RXOV_INTEN Position   */
#define SPI_FFCTL_RXOVE_INTEN_Msk      (1ul << SPI_FFCTL_RXOVE_INTEN_Pos)             /*!< SPI FFCTL: RXOV_INTEN Mask       */
#define SPI_FFCTL_TX_INTEN_Pos         3                                              /*!< SPI FFCTL: TXINT_EN Position     */
#define SPI_FFCTL_TX_INTEN_Msk         (1ul << SPI_FFCTL_TX_INTEN_Pos)                /*!< SPI FFCTL: TXINT_EN Mask         */
#define SPI_FFCTL_RX_INTEN_Pos         2                                              /*!< SPI FFCTL: RXINT_EN Position     */
#define SPI_FFCTL_RX_INTEN_Msk         (1ul << SPI_FFCTL_RX_INTEN_Pos)                /*!< SPI FFCTL: RXINT_EN Mask         */
#define SPI_FFCTL_TX_CLR_Pos           1                                              /*!< SPI FFCTL: TX_CLR Position       */
#define SPI_FFCTL_TX_CLR_Msk           (1ul << SPI_FFCTL_TX_CLR_Pos)                  /*!< SPI FFCTL: TX_CLR Mask           */
#define SPI_FFCTL_RX_CLR_Pos           0                                              /*!< SPI FFCTL: RX_CLR Position       */
#define SPI_FFCTL_RX_CLR_Msk           (1ul << SPI_FFCTL_RX_CLR_Pos)                  /*!< SPI FFCTL: RX_CLR Mask           */

/*------------- Timer Control Register (TIMER) -----------------------------*/
/** @addtogroup NANO100_TIMER NANO100 TIMER Control Register (TIMER)
  Memory Mapped Structure for NANO100 Series TIMER Controller
  @{
*/
/**
  * @brief TIMER register map
  */
typedef struct {
    __IO uint32_t  CTL;                        /*!< Offset: 0x0000   Timer Control Register                            */
    __IO uint32_t  PRECNT;                     /*!< Offset: 0x0004   Timer Pre-Scale Counter Register                  */
    __IO uint32_t  CMPR;                       /*!< Offset: 0x0008   Timer Compare Register                            */
    __IO uint32_t  IER;                        /*!< Offset: 0x000C   Timer Interrupt Enable Register                   */
    __IO uint32_t  ISR;                        /*!< Offset: 0x0010   Timer Interrupt Status Register                   */
    __I  uint32_t  DR;                         /*!< Offset: 0x0014   Timer Data Register                               */
    __I  uint32_t  TCAP;                       /*!< Offset: 0x0018   Timer Capture Data Register                       */
} TIMER_T;

/* TIMER CTL Bit Field Definitions */
#define TIMER_CTL_INTR_TRG_EN_Pos       24                                              /*!< TIMER CTL : INTR_TRG_EN Position       */
#define TIMER_CTL_INTR_TRG_EN_Msk       (1ul << TIMER_CTL_INTR_TRG_EN_Pos)              /*!< TIMER CTL : INTR_TRG_EN Mask           */

#define TIMER_CTL_TCAP_DEB_EN_Pos       22                                              /*!< TIMER CTL : TCAP_DEB_EN Position       */
#define TIMER_CTL_TCAP_DEB_EN_Msk       (1ul << TIMER_CTL_TCAP_DEB_EN_Pos)              /*!< TIMER CTL : TCAP_DEB_EN Mask           */

#define TIMER_CTL_TCAP_CNT_MODE_Pos     20                                              /*!< TIMER CTL : TCAP_CNT_MODE Position     */
#define TIMER_CTL_TCAP_CNT_MODE_Msk     (1ul << TIMER_CTL_TCAP_CNT_MODE_Pos)            /*!< TIMER CTL : TCAP_CNT_MODE Mask         */

#define TIMER_CTL_TCAP_EDGE_Pos         18                                              /*!< TIMER CTL : TCAP_EDGE Position         */
#define TIMER_CTL_TCAP_EDGE_Msk         (3ul << TIMER_CTL_TCAP_EDGE_Pos)                /*!< TIMER CTL : TCAP_EDGE Mask             */

#define TIMER_CTL_TCAP_MODE_Pos         17                                              /*!< TIMER CTL : TCAP_MODE Position         */
#define TIMER_CTL_TCAP_MODE_Msk         (1ul << TIMER_CTL_TCAP_MODE_Pos)                /*!< TIMER CTL : TCAP_MODE Mask             */

#define TIMER_CTL_TCAP_EN_Pos           16                                              /*!< TIMER CTL : TCAP_EN Position           */
#define TIMER_CTL_TCAP_EN_Msk           (1ul << TIMER_CTL_TCAP_EN_Pos)                  /*!< TIMER CTL : TCAP_EN Mask               */

#define TIMER_CTL_EVENT_DEB_EN_Pos      14                                              /*!< TIMER CTL : EVENT_DEB_EN Position      */
#define TIMER_CTL_EVENT_DEB_EN_Msk      (1ul << TIMER_CTL_EVENT_DEB_EN_Pos)             /*!< TIMER CTL : EVENT_DEB_EN Mask          */

#define TIMER_CTL_EVENT_EDGE_Pos        13                                              /*!< TIMER CTL : EVENT_EDGE Position        */
#define TIMER_CTL_EVENT_EDGE_Msk        (1ul << TIMER_CTL_EVENT_EDGE_Pos)               /*!< TIMER CTL : EVENT_EDGE Mask            */

#define TIMER_CTL_EVENT_EN_Pos          12                                              /*!< TIMER CTL : EVENT_EN Position          */
#define TIMER_CTL_EVENT_EN_Msk          (1ul << TIMER_CTL_EVENT_EN_Pos)                 /*!< TIMER CTL : EVENT_EN Mask              */

#define TIMER_TMR_TRG_SEL_Pos           11                                              /*!< TIMER CTL : TMR_TRG_SEL Position        */
#define TIMER_TMR_TRG_SEL_Msk           (1ul << TIMER_TMR_TRG_SEL_Pos)                  /*!< TIMER CTL : TMR_TRG_SEL Mask            */

#define TIMER_CTL_PDMA_TEEN_Pos         10                                              /*!< TIMER CTL : PDMA_TEEN Position         */
#define TIMER_CTL_PDMA_TEEN_Msk         (1ul << TIMER_CTL_PDMA_TEEN_Pos)                /*!< TIMER CTL : PDMA_TEEN Mask             */

#define TIMER_CTL_DAC_TEEN_Pos          9                                               /*!< TIMER CTL : DAC_TEEN Position          */
#define TIMER_CTL_DAC_TEEN_Msk          (1ul << TIMER_CTL_DAC_TEEN_Pos)                 /*!< TIMER CTL : DAC_TEEN Mask              */

#define TIMER_CTL_ADC_TEEN_Pos          8                                               /*!< TIMER CTL : ADC_TEEN Position          */
#define TIMER_CTL_ADC_TEEN_Msk          (1ul << TIMER_CTL_ADC_TEEN_Pos)                 /*!< TIMER CTL : ADC_TEEN Mask              */

#define TIMER_CTL_TMR_ACT_Pos           7                                               /*!< TIMER CTL : TMR_ACT Position           */
#define TIMER_CTL_TMR_ACT_Msk           (1ul << TIMER_CTL_TMR_ACT_Pos)                  /*!< TIMER CTL : TMR_ACT Mask               */

#define TIMER_CTL_MODE_SEL_Pos          4                                               /*!< TIMER CTL : MODE_SEL Position          */
#define TIMER_CTL_MODE_SEL_Msk          (3UL << TIMER_CTL_MODE_SEL_Pos)                 /*!< TIMER CTL : MODE_SEL Mask              */

#define TIMER_CTL_DBGACK_EN_Pos         3                                               /*!< TIMER CTL : DBGACK_EN Position         */
#define TIMER_CTL_DBGACK_EN_Msk         (1ul << TIMER_CTL_DBGACK_EN_Pos)                /*!< TIMER CTL : DBGACK_EN Mask             */

#define TIMER_CTL_WAKE_EN_Pos           2                                               /*!< TIMER CTL : WAKE_EN Position           */
#define TIMER_CTL_WAKE_EN_Msk           (1ul << TIMER_CTL_WAKE_EN_Pos)                  /*!< TIMER CTL : WAKE_EN Mask               */

#define TIMER_CTL_SW_RST_Pos            1                                               /*!< TIMER CTL : SW_RST Position            */
#define TIMER_CTL_SW_RST_Msk            (1ul << TIMER_CTL_SW_RST_Pos)                   /*!< TIMER CTL : SW_RST Mask                */

#define TIMER_CTL_TMR_EN_Pos            0                                               /*!< TIMER CTL : TMR_EN Position            */
#define TIMER_CTL_TMR_EN_Msk            (1ul << TIMER_CTL_TMR_EN_Pos)                   /*!< TIMER CTL : TMR_EN Mask                */

/* TIMER PRECNT Bit Field Definitions */
#define TIMER_PRECNT_PRESCALE_CNT_Pos   0                                               /*!< TIMER PRECNT: PRESCALE_CNT Position    */
#define TIMER_PRECNT_PRESCALE_CNT_Msk   (0xFFul << TIMER_PRECNT_PRESCALE_CNT_Pos)       /*!< TIMER PRECNT: PRESCALE_CNT Mask        */

/* TIMER CMPR Bit Field Definitions */
#define TIMER_CMPR_CMP_Pos              0                                               /*!< TIMER CMPR: CMP Position               */
#define TIMER_CMPR_CMP_Msk              (0xFFFFFFul << TIMER_CMPR_CMP_Pos)              /*!< TIMER CMPR: CMP Mask                   */

/* TIMER IER Bit Field Definitions */
#define TIMER_IER_TCAP_IE_Pos           1                                               /*!< TIMER IER: TCAP_IE Position            */
#define TIMER_IER_TCAP_IE_Msk           (1ul << TIMER_IER_TCAP_IE_Pos)                  /*!< TIMER IER: TCAP_IE Mask                */

#define TIMER_IER_TMR_IE_Pos            0                                               /*!< TIMER IER: TMR_IE Position             */
#define TIMER_IER_TMR_IE_Msk            (1ul << TIMER_IER_TMR_IE_Pos)                   /*!< TIMER IER: TMR_IE Mask                 */

/* TIMER ISR Bit Field Definitions */
#define TIMER_ISR_NCAP_DET_STS_Pos      5                                               /*!< TIMER ISR: NCAP_DET_STS Position       */
#define TIMER_ISR_NCAP_DET_STS_Msk      (1ul << TIMER_ISR_NCAP_DET_STS_Pos)             /*!< TIMER ISR: NCAP_DET_STS Mask           */

#define TIMER_ISR_TMR_WAKE_STS_Pos      4                                               /*!< TIMER ISR: TMR_WAKE_STS Position       */
#define TIMER_ISR_TMR_WAKE_STS_Msk      (1ul << TIMER_ISR_TMR_WAKE_STS_Pos)             /*!< TIMER ISR: TMR_WAKE_STS Mask           */

#define TIMER_ISR_TCAP_IS_Pos           1                                               /*!< TIMER ISR: TCAP_IS Position            */
#define TIMER_ISR_TCAP_IS_Msk           (1ul << TIMER_ISR_TCAP_IS_Pos)                  /*!< TIMER ISR: TCAP_IS Mask                */

#define TIMER_ISR_TMR_IS_Pos            0                                               /*!< TIMER ISR: TMR_IS Position             */
#define TIMER_ISR_TMR_IS_Msk            (1ul << TIMER_ISR_TMR_IS_Pos)                   /*!< TIMER ISR: TMR_IS Mask                 */

/* TIMER DR Bit Field Definitions */
#define TIMER_DR_TDR_Pos                0                                               /*!< TIMER DR: TDR Position                 */
#define TIMER_DR_TDR_Msk                (0xFFFFFFul << TIMER_DR_TDR_Pos)                /*!< TIMER DR: TDR Mask                     */

/* TIMER TCAP Bit Field Definitions */
#define TIMER_TCAP_CAP_Pos              0                                               /*!< TIMER TCAP: CAP Position               */
#define TIMER_TCAP_CAP_Msk              (0xFFFFFFul << TIMER_TCAP_CAP_Pos)              /*!< TIMER TCAP: CAP Mask                   */

/*@}*/ /* end of group NANO100_TIMER */


/*
 * @brief GPIO shadow registers
 */
/*------------- GPIO Shadow Registers (SHADOW) -----------------------------*/
/** @addtogroup NANO100_SHADOW NANO100 GPIO Shadow Register (SHADOW)
  Memory Mapped Structure for NANO100 Series GPIO Shadow Register
  @{
*/
/**
  * @brief GPIO shadow register map
  */
typedef struct {
    __I uint32_t  GPA_SHADOW;                /*!< Offset: 0x0000   GPIO Port A Pin Value Shadow Register                */
    __I uint32_t  GPB_SHADOW;                /*!< Offset: 0x0004   GPIO Port B Pin Value Shadow Register                */
    __I uint32_t  GPC_SHADOW;                /*!< Offset: 0x0008   GPIO Port C Pin Value Shadow Register                */
    __I uint32_t  GPD_SHADOW;                /*!< Offset: 0x000C   GPIO Port D Pin Value Shadow Register                */
    __I uint32_t  GPE_SHADOW;                /*!< Offset: 0x0010   GPIO Port E Pin Value Shadow Register                */
    __I uint32_t  GPF_SHADOW;                /*!< Offset: 0x0014   GPIO Port F Pin Value Shadow Register                */
} SHADOW_T;
/*@}*/ /* end of group NANO100_SHADOW */



/*------------- UART -----------------------------*/
/** @addtogroup NANO100_UART NANO100 UART Control Register (UART)
  Memory Mapped Structure for NANO100 Series UART Controller
  @{
*/
/**
  * @brief UART register map
  */
typedef struct {
    union {
        __I  uint32_t  RBR;      /*!< Offset: 0x0000   UART Receive Buffer Register               */
        __O  uint32_t  THR;      /*!< Offset: 0x0000   UART Transmit Holding Register             */
    };
    __IO uint32_t  CTL;        /*!< Offset: 0x0004   UART Control State Register                */
    __IO uint32_t  TLCTL;      /*!< Offset: 0x0008   UART Transfer Line Control Register        */
    __IO uint32_t  IER;        /*!< Offset: 0x000C   UART Interrupt Enable Register             */
    __IO uint32_t  ISR;        /*!< Offset: 0x0010   UART Interrupt Status Register             */
    __IO uint32_t  TRSR;       /*!< Offset: 0x0014   UART Transfer State Status Register        */
    __IO uint32_t  FSR;        /*!< Offset: 0x0018   UART FIFO State Status Register            */
    __IO uint32_t  MCSR;       /*!< Offset: 0x001C   UART Modem State Status Register           */
    __IO uint32_t  TMCTL;      /*!< Offset: 0x0020   UART Time-Out Control State Register       */
    __IO uint32_t  BAUD;       /*!< Offset: 0x0024   UART Baud Rate Divisor Register            */
    uint32_t  RESERVED0[2];
    __IO uint32_t  IRCR;       /*!< Offset: 0x0030   UART IrDA Control Register                 */
    __IO uint32_t  ALT_CTL;    /*!< Offset: 0x0034   UART Alternate Control State Register      */
    __IO uint32_t  FUN_SEL;    /*!< Offset: 0x0038   UART Function Select Register              */
} UART_T;

/* UART THR Bit Field Definitions */
#define UART_THR_THR_Pos         0                                          /*!< UART THR: THR Position  */
#define UART_THR_THR_Msk        (0xFul << UART_THR_THR_Pos)                 /*!< UART THR: THR Mask      */

/* UART RBR Bit Field Definitions */
#define UART_RBR_RBR_Pos         0                                          /*!< UART RBR: RBR Position */
#define UART_RBR_RBR_Msk        (0xFul << UART_RBR_RBR_Pos)                 /*!< UART RBR: RBR Mask      */

/* UART CTL Bit Field Definitions */
#define UART_CTL_RX_RST_Pos      0                                          /*!< UART CTL: RX_RST Position */
#define UART_CTL_RX_RST_Msk      (0x1ul << UART_CTL_RX_RST_Pos)             /*!< UART CTL: RX_RST Mask */
#define UART_CTL_TX_RST_Pos      1                                          /*!< UART CTL: TX_RST Position */
#define UART_CTL_TX_RST_Msk      (0x1ul << UART_CTL_RX_RST_Pos)             /*!< UART CTL: TX_RST Mask */
#define UART_CTL_RX_DIS_Pos      2                                          /*!< UART CTL: RX_DIS Position */
#define UART_CTL_RX_DIS_Msk      (0x1ul << UART_CTL_RX_DIS_Pos)             /*!< UART CTL: RX_DIS Mask */
#define UART_CTL_TX_DIS_Pos      3                                          /*!< UART CTL: TX_DIS Position */
#define UART_CTL_TX_DIS_Msk      (0x1ul << UART_CTL_TX_DIS_Pos)             /*!< UART CTL: TX_DIS Mask */
#define UART_CTL_AUTO_RTS_EN_Pos 4                                          /*!< UART CTL: AUTO_RTS_EN Position */
#define UART_CTL_AUTO_RTS_EN_Msk (0x1ul << UART_CTL_AUTO_RTS_EN_Pos)        /*!< UART CTL: AUTO_RTS_EN Mask */
#define UART_CTL_AUTO_CTS_EN_Pos 5                                          /*!< UART CTL: AUTO_CTS_EN Position */
#define UART_CTL_AUTO_CTS_EN_Msk (0x1ul << UART_CTL_AUTO_CTS_EN_Pos)        /*!< UART CTL: AUTO_CTS_EN Mask */
#define UART_CTL_DMA_RX_EN_Pos   6                                          /*!< UART CTL: DMA_RX_EN Position */
#define UART_CTL_DMA_RX_EN_Msk   (0x1ul << UART_CTL_DMA_RX_EN_Pos)              /*!< UART CTL: DMA_RX_EN Mask */
#define UART_CTL_DMA_TX_EN_Pos   7                                          /*!< UART CTL: DMA_TX_EN Position */
#define UART_CTL_DMA_TX_EN_Msk   (0x1ul << UART_CTL_DMA_TX_EN_Pos)          /*!< UART CTL: DMA_TX_EN Mask */
#define UART_CTL_WAKE_CTS_EN_Pos 8                                          /*!< UART CTL: WAKE_CTS_EN Position */
#define UART_CTL_WAKE_CTS_EN_Msk (0x1ul << UART_CTL_WAKE_CTS_EN_Pos)        /*!< UART CTL: WAKE_CTS_EN Mask */
#define UART_CTL_WAKE_DATA_EN_Pos 9                                         /*!< UART CTL: WAKE_DATA_EN Position */
#define UART_CTL_WAKE_DATA_EN_Msk (0x1ul << UART_CTL_WAKE_DATA_EN_Pos)      /*!< UART CTL: WAKE_DATA_EN Mask */
#define UART_CTL_ABAUD_EN_Pos    12                                         /*!< UART CTL: ABAUD_EN Position */
#define UART_CTL_ABAUD_EN_Msk    (0x1ul << UART_CTL_ABAUD_EN_Pos)           /*!< UART CTL: ABAUD_EN Mask */
#define UART_CTL_WAKE_THRESH_EN_Pos      17                                         /*!< UART CTL: WAKE_THRESH_EN Position */
#define UART_CTL_WAKE_THRESH_EN_Msk      (0x1ul << UART_CTL_WAKE_THRESH_EN_Pos)     /*!< UART CTL: WAKE_THRESH_EN Mask */
#define UART_CTL_WAKE_RS485_AAD_EN_Pos   18                                         /*!< UART CTL: WAKE_RS485_AAD_EN Position */
#define UART_CTL_WAKE_RS485_AAD_EN_Msk   (0x1ul << UART_CTL_WAKE_RS485_AAD_EN_Pos)  /*!< UART CTL: WAKE_RS485_AAD_EN Mask */
#define UART_CTL_PWM_SEL_Pos     24                                         /*!< UART CTL: PWM_SEL Position */
#define UART_CTL_PWM_SEL_Msk     (0x7ul << UART_CTL_PWM_SEL_Pos)            /*!< UART CTL: PWM_SEL Mask */

/* UART TLCTL Bit Field Definitions */
#define UART_TLCTL_DATA_LEN_Pos  0                                          /*!< UART TLCTL: DATA_LEN Position */
#define UART_TLCTL_DATA_LEN_Msk  (0x3ul << UART_TLCTL_DATA_LEN_Pos)         /*!< UART TLCTL: DATA_LEN Mask */
#define UART_TLCTL_NSB_Pos       2                                          /*!< UART TLCTL: NSB Position */
#define UART_TLCTL_NSB_Msk       (0x1ul << UART_TLCTL_NSB_Pos)              /*!< UART TLCTL: NSB Mask */
#define UART_TLCTL_PBE_Pos       3                                          /*!< UART TLCTL: PBE Position */
#define UART_TLCTL_PBE_Msk       (0x1ul << UART_TLCTL_PBE_Pos)              /*!< UART TLCTL: PBE Mask */
#define UART_TLCTL_EPE_Pos       4                                          /*!< UART TLCTL: EPE Position */
#define UART_TLCTL_EPE_Msk       (0x1ul << UART_TLCTL_EPE_Pos)              /*!< UART TLCTL: EPE Mask */
#define UART_TLCTL_SPE_Pos       5                                          /*!< UART TLCTL: SPE Position */
#define UART_TLCTL_SPE_Msk       (0x1ul << UART_TLCTL_SPE_Pos)              /*!< UART TLCTL: SPE Mask */
#define UART_TLCTL_BCB_Pos       6                                          /*!< UART TLCTL: BCB Position */
#define UART_TLCTL_BCB_Msk       (0x1ul << UART_TLCTL_BCB_Pos)              /*!< UART TLCTL: BCB Mask */
#define UART_TLCTL_RFITL_Pos     8                                          /*!< UART TLCTL: RFITL Position */
#define UART_TLCTL_RFITL_Msk     (0x3ul << UART_TLCTL_RFITL_Pos)            /*!< UART TLCTL: RFITL Mask */
#define UART_TLCTL_RTS_TRI_LEV_Pos   12                                     /*!< UART TLCTL: RTS_TRI_LEV Position */
#define UART_TLCTL_RTS_TRI_LEV_Msk   (0x3ul << UART_TLCTL_RTS_TRI_LEV_Pos)  /*!< UART TLCTL: RTS_TRI_LEV Mask */

/* UART IER Bit Field Definitions */
#define UART_IER_RDA_IE_Pos     0                                           /*!< UART IER: RDA_IE Position */
#define UART_IER_RDA_IE_Msk     (0x1ul << UART_IER_RDA_IE_Pos)              /*!< UART IER: RDA_IE Mask */
#define UART_IER_THRE_IE_Pos    1                                           /*!< UART IER: THRE_IE Position */
#define UART_IER_THRE_IE_Msk    (0x1ul << UART_IER_THRE_IE_Pos)             /*!< UART IER: THRE_IE Mask */
#define UART_IER_RLS_IE_Pos     2                                           /*!< UART IER: RLS_IE Position */
#define UART_IER_RLS_IE_Msk     (0x1ul << UART_IER_RLS_IE_Pos)              /*!< UART IER: RLS_IE Mask */
#define UART_IER_MODEM_IE_Pos   3                                           /*!< UART IER: MODEM_IE Position */
#define UART_IER_MODEM_IE_Msk   (0x1ul << UART_IER_MODEM_IE_Pos)            /*!< UART IER: MODEM_IE Mask */
#define UART_IER_RTO_IE_Pos     4                                           /*!< UART IER: RTO_IE Position */
#define UART_IER_RTO_IE_Msk     (0x1ul << UART_IER_RTO_IE_Pos)              /*!< UART IER: RTO_IE Mask */
#define UART_IER_BUF_ERR_IE_Pos 5                                           /*!< UART IER: BUF_ERR_IE Position */
#define UART_IER_BUF_ERR_IE_Msk (0x1ul << UART_IER_BUF_ERR_IE_Pos)          /*!< UART IER: BUF_ERR_IE Mask */
#define UART_IER_WAKE_IE_Pos    6                                           /*!< UART IER: WAKE_IE Position */
#define UART_IER_WAKE_IEE_Msk   (0x1ul << UART_IER_WAKE_IE_Pos)             /*!< UART IER: WAKE_IE Mask */
#define UART_IER_ABAUD_IE_Pos   7                                           /*!< UART IER: ABAUD_IE Position */
#define UART_IER_ABAUD_IE_Msk   (0x1ul << UART_IER_ABAUD_IE_Pos)            /*!< UART IER: ABAUD_IE Mask */
#define UART_IER_LIN_IE_Pos     8                                           /*!< UART IER: LIN_IE Position */
#define UART_IER_LIN_IE_Msk     (0x1ul << UART_IER_LIN_IE_Pos)              /*!< UART IER: LIN_IE Mask */

/* UART ISR Bit Field Definitions */
#define UART_ISR_RDA_IS_Pos     0                                           /*!< UART ISR: RDA_IS Position */
#define UART_ISR_RDA_IS_Msk     (0x1ul << UART_ISR_RDA_IS_Pos)              /*!< UART ISR: RDA_IS Mask */
#define UART_ISR_THRE_IS_Pos    1                                           /*!< UART ISR: THRE_IS Position */
#define UART_ISR_THRE_IS_Msk    (0x1ul << UART_ISR_THRE_IS_Pos)             /*!< UART ISR: THRE_IS Mask */
#define UART_ISR_RLS_IS_Pos     2                                           /*!< UART ISR: RLS_IS Position */
#define UART_ISR_RLS_IS_Msk     (0x1ul << UART_ISR_RLS_IS_Pos)              /*!< UART ISR: RLS_IS Mask */
#define UART_ISR_MODEM_IS_Pos   3                                           /*!< UART ISR: MODEM_IS Position */
#define UART_ISR_MODEM_IS_Msk   (0x1ul << UART_ISR_MODEM_IS_Pos)            /*!< UART ISR: MODEM_IS Mask */
#define UART_ISR_RTO_IS_Pos     4                                           /*!< UART ISR: RTO_IS Position */
#define UART_ISR_RTO_IS_Msk     (0x1ul << UART_ISR_RTO_IS_Pos)              /*!< UART ISR: RTO_IS Mask */
#define UART_ISR_BUF_ERR_IS_Pos 5                                           /*!< UART ISR: BUF_ERR_IS Position */
#define UART_ISR_BUF_ERR_IS_Msk (0x1ul << UART_ISR_BUF_ERR_IS_Pos)          /*!< UART ISR: BUF_ERR_IS Mask */
#define UART_ISR_WAKE_IS_Pos    6                                           /*!< UART ISR: WAKE_IS Position */
#define UART_ISR_WAKE_IS_Msk    (0x1ul << UART_ISR_WAKE_IS_Pos)             /*!< UART ISR: WAKE_IS Mask */
#define UART_ISR_ABAUD_IS_Pos   7                                           /*!< UART ISR: ABAUD_IS Position */
#define UART_ISR_ABAUD_IS_Msk   (0x1ul << UART_ISR_RDA_IS_Pos)              /*!< UART ISR: ABAUD_IS Mask */
#define UART_ISR_LIN_IS_Pos     8                                           /*!< UART ISR: LIN_IS Position */
#define UART_ISR_LIN_IS_Msk     (0x1ul << UART_ISR_LIN_IS_Pos)              /*!< UART ISR: LIN_IS Mask */

/* UART TRSR Bit Field Definitions */
#define UART_TRSR_RS485_ADDET_F_Pos     0                                       /*!< UART TRSR: RS485_ADDET_F Position */
#define UART_TRSR_RS485_ADDET_F_Msk     (0x1ul << UART_TRSR_RS485_ADDET_F_Pos)  /*!< UART TRSR: RS485_ADDET_F Mask */
#define UART_TRSR_ABAUD_F_Pos           1                                       /*!< UART TRSR: ABAUD_F Position */
#define UART_TRSR_ABAUD_F_Msk           (0x1ul << UART_TRSR_ABAUD_F_Pos)        /*!< UART TRSR: ABAUD_F Mask */
#define UART_TRSR_ABAUD_TOUT_F_Pos      2                                       /*!< UART TRSR: ABAUD_TOUT_F Position */
#define UART_TRSR_ABAUD_TOUT_F_Msk      (0x1ul << UART_TRSR_ABAUD_TOUT_F_Pos)   /*!< UART TRSR: ABAUD_TOUT_F Mask */
#define UART_TRSR_LIN_TX_F_Pos          3                                       /*!< UART TRSR: LIN_TX_F Position */
#define UART_TRSR_LIN_TX_F_Msk          (0x1ul << UART_TRSR_LIN_TX_F_Pos)       /*!< UART TRSR: LIN_TX_F Mask */
#define UART_TRSR_LIN_RX_F_Pos          4                                       /*!< UART TRSR: LIN_RX_F Position */
#define UART_TRSR_LIN_RX_F_Msk          (0x1ul << UART_TRSR_LIN_RX_F_Pos)       /*!< UART TRSR: LIN_RX_F Mask */
#define UART_TRSR_BIT_ERR_F_Pos         5                                       /*!< UART TRSR: BIT_ERR_F Position */
#define UART_TRSR_BIT_ERR_F_Msk         (0x1ul << UART_TRSR_BIT_ERR_F_Pos)      /*!< UART TRSR: BIT_ERR_F Mask */
#define UART_TRSR_LIN_RX_SYNC_ERR_F_Pos 8                                           /*!< UART TRSR: LIN_RX_SYNC_ERR_F Position */
#define UART_TRSR_LIN_RX_SYNC_ERR_F_Msk (0x1ul << UART_TRSR_LIN_RX_SYNC_ERR_F_Pos)  /*!< UART TRSR: LIN_RX_SYNC_ERR_F Mask */

/* UART FSR Bit Field Definitions */
#define UART_FSR_RX_OVER_F_Pos      0                                       /*!< UART FSR: RX_OVER_F Position */
#define UART_FSR_RX_OVER_F_Msk      (0x1ul << UART_FSR_RX_OVER_F_Pos)       /*!< UART FSR: RX_OVER_F Mask */
#define UART_FSR_RX_EMPTY_F_Pos     1                                       /*!< UART FSR: RX_EMPTY_F Position */
#define UART_FSR_RX_EMPTY_F_Msk     (0x1ul << UART_FSR_RX_EMPTY_F_Pos)      /*!< UART FSR: RX_EMPTY_F Mask */
#define UART_FSR_RX_FULL_F_Pos      2                                       /*!< UART FSR: RX_FULL_F Position */
#define UART_FSR_RX_FULL_F_Msk      (0x1ul << UART_FSR_RX_FULL_F_Pos)       /*!< UART FSR: RX_FULL_F Mask */
#define UART_FSR_PE_F_Pos           4                                       /*!< UART FSR: PE_F Position */
#define UART_FSR_PE_F_Msk           (0x1ul << UART_FSR_PE_F_Pos)            /*!< UART FSR: PE_F Mask */
#define UART_FSR_FE_F_Pos           5                                       /*!< UART FSR: FE_F Position */
#define UART_FSR_FE_F_Msk           (0x1ul << UART_FSR_FE_F_Pos)            /*!< UART FSR: FE_F Mask */
#define UART_FSR_BI_F_Pos           6                                       /*!< UART FSR: BI_F Position */
#define UART_FSR_BI_F_Msk       (0x1ul << UART_FSR_RX_OVER_F_Pos)       /*!< UART FSR: BI_F Mask */
#define UART_FSR_TX_OVER_F_Pos      8                                       /*!< UART FSR: TX_OVER_F Position */
#define UART_FSR_TX_OVER_F_Msk      (0x1ul << UART_FSR_TX_OVER_F_Pos)       /*!< UART FSR: TX_OVER_F Mask */
#define UART_FSR_TX_EMPTY_F_Pos     9                                       /*!< UART FSR: TX_EMPTY_F Position */
#define UART_FSR_TX_EMPTY_F_Msk     (0x1ul << UART_FSR_TX_EMPTY_F_Pos)      /*!< UART FSR: TX_EMPTY_F Mask */
#define UART_FSR_TX_FULL_F_Pos      10                                      /*!< UART FSR: TX_FULL_F Position */
#define UART_FSR_TX_FULL_F_Msk      (0x1ul << UART_FSR_TX_FULL_F_Pos)       /*!< UART FSR: TX_FULL_F Mask */
#define UART_FSR_TE_F_Pos           11                                      /*!< UART FSR: FSR_TE_F Position */
#define UART_FSR_TE_F_Msk           (0x1ul << UART_FSR_TE_F_Pos)            /*!< UART FSR: FSR_TE_F Mask */
#define UART_FSR_RX_POINTER_F_Pos   16                                      /*!< UART FSR: RX_POINTER_F Position */
#define UART_FSR_RX_POINTER_F_Msk   (0x1Ful << UART_FSR_RX_POINTER_F_Pos)   /*!< UART FSR: RX_POINTER_F Mask */
#define UART_FSR_TX_POINTER_F_Pos   24                                      /*!< UART FSR: TX_POINTER_F Position */
#define UART_FSR_TX_POINTER_F_Msk   (0x1Ful << UART_FSR_TX_POINTER_F_Pos)   /*!< UART FSR: TX_POINTER_F Mask */

/* UART MCSR Bit Field Definitions */
#define UART_MCSR_LEV_RTS_Pos       0                                       /*!< UART MCSR: LEV_RTS Position */
#define UART_MCSR_LEV_RTS_Msk       (0x1ul << UART_MCSR_LEV_RTS_Pos)        /*!< UART MCSR: LEV_RTS Mask */
#define UART_MCSR_RTS_ST_Pos        1                                       /*!< UART MCSR: RTS_ST Position */
#define UART_MCSR_RTS_ST_Msk        (0x1ul << UART_MCSR_RTS_ST_Pos)         /*!< UART MCSR: RTS_ST Mask */
#define UART_MCSR_LEV_CTS_Pos       16                                      /*!< UART MCSR: LEV_CTS Position */
#define UART_MCSR_LEV_CTS_Msk       (0x1ul << UART_MCSR_LEV_CTS_Pos)        /*!< UART MCSR: LEV_CTS Mask */
#define UART_MCSR_CTS_ST_Pos        17                                      /*!< UART MCSR: CTS_ST Position */
#define UART_MCSR_CTS_ST_Msk        (0x1ul << UART_MCSR_CTS_ST_Pos)         /*!< UART MCSR: CTS_ST Mask */
#define UART_MCSR_DCT_F_Pos         18                                      /*!< UART MCSR: DCT_F Position */
#define UART_MCSR_DCT_F_Msk         (0x1ul << UART_MCSR_DCT_F_Pos)          /*!< UART MCSR: DCT_F Mask */

/* UART TMCTL Bit Field Definitions */
#define UART_TMCTL_TOIC_Pos         0                                       /*!< UART TMCTL: TOIC Position */
#define UART_TMCTL_TOIC_Msk         (0x1FFul << UART_TMCTL_TOIC_Pos)        /*!< UART TMCTL: TOIC Mask */
#define UART_TMCTL_DLY_Pos          16                                      /*!< UART TMCTL: DLY Position */
#define UART_TMCTL_DLY_Msk          (0xFFul << UART_TMCTL_DLY_Pos)          /*!< UART TMCTL: DLY Mask */

/* UART BAUD Bit Field Definitions */
#define UART_BAUD_BRD_Pos           0                                       /*!< UART BAUD: BRD Position */
#define UART_BAUD_BRD_Msk           (0xFFFFul << UART_BAUD_BRD_Pos)     /*!< UART BAUD: BRD Mask */
#define UART_BAUD_DIV_16_EN_Pos     31                                      /*!< UART BAUD: DIV_16_EN Position */
#define UART_BAUD_DIV_16_EN_Msk     (0x1ul << UART_BAUD_DIV_16_EN_Pos)      /*!< UART BAUD: DIV_16_EN Mask */

/* UART IRCR Bit Field Definitions */
#define UART_IRCR_TX_SELECT_Pos     1                                       /*!< UART IRCR: TX_SELECT Position */
#define UART_IRCR_TX_SELECT_Msk     (0x1ul << UART_IRCR_TX_SELECT_Pos)      /*!< UART IRCR: TX_SELECT Mask */
#define UART_IRCR_INV_TX_Pos        5                                       /*!< UART IRCR: INV_TX Position */
#define UART_IRCR_INV_TX_Msk        (0x1ul << UART_IRCR_INV_TX_Pos)         /*!< UART IRCR: INV_TX Mask */
#define UART_IRCR_INV_RX_Pos        6                                       /*!< UART IRCR: INV_RX Position */
#define UART_IRCR_INV_RX_Msk        (0x1ul << UART_IRCR_INV_RX_Pos)         /*!< UART IRCR: INV_RX Mask */

/* UART ALT_CTL Bit Field Definitions */
#define UART_ALT_CTL_LIN_TX_BCNT_Pos    0                                           /*!< UART ALT_CTL: LIN_TX_BCNT Position */
#define UART_ALT_CTL_LIN_TX_BCNT_Msk    (0x7ul << UART_ALT_CTL_LIN_TX_BCNT_Pos)     /*!< UART ALT_CTL: LIN_TX_BCNT Mask */
#define UART_ALT_CTL_LIN_HEAD_SEL_Pos   4                                           /*!< UART ALT_CTL: LIN_HEAD_SEL Position */
#define UART_ALT_CTL_LIN_HEAD_SEL_Msk   (0x3ul << UART_ALT_CTL_LIN_HEAD_SEL_Pos)    /*!< UART ALT_CTL: LIN_HEAD_SEL Mask */
#define UART_ALT_CTL_LIN_RX_EN_Pos      6                                           /*!< UART ALT_CTL: LIN_RX_EN Position */
#define UART_ALT_CTL_LIN_RX_EN_Msk      (0x1ul << UART_ALT_CTL_LIN_RX_EN_Pos)       /*!< UART ALT_CTL: LIN_RX_EN Mask */
#define UART_ALT_CTL_LIN_TX_EN_Pos      7                                           /*!< UART ALT_CTL: LIN_TX_EN Position */
#define UART_ALT_CTL_LIN_TX_EN_Msk      (0x1ul << UART_ALT_CTL_LIN_TX_EN_Pos)       /*!< UART ALT_CTL: LIN_TX_EN Mask */
#define UART_ALT_CTL_BIT_ERR_EN_Pos     8                                           /*!< UART ALT_CTL: BIT_ERR_EN Position */
#define UART_ALT_CTL_BIT_ERR_EN_Msk     (0x1ul << UART_ALT_CTL_BIT_ERR_EN_Pos)      /*!< UART ALT_CTL: BIT_ERR_EN Mask */
#define UART_ALT_CTL_RS485_NMM_Pos      16                                          /*!< UART ALT_CTL: RS485_NMM Position */
#define UART_ALT_CTL_RS485_NMM_Msk      (0x1ul << UART_ALT_CTL_RS485_NMM_Pos)       /*!< UART ALT_CTL: RS485_NMM Mask */
#define UART_ALT_CTL_RS485_AAD_Pos      17                                          /*!< UART ALT_CTL: RS485_AAD Position */
#define UART_ALT_CTL_RS485_AAD_Msk      (0x1ul << UART_ALT_CTL_RS485_AAD_Pos)       /*!< UART ALT_CTL: RS485_AAD Mask */
#define UART_ALT_CTL_RS485_AUD_Pos      18                                          /*!< UART ALT_CTL: RS485_AUD Position */
#define UART_ALT_CTL_RS485_AUD_Msk      (0x1ul << UART_ALT_CTL_RS485_AUD_Pos)       /*!< UART ALT_CTL: RS485_AUD Mask */
#define UART_ALT_CTL_RS485_ADD_EN_Pos   19                                          /*!< UART ALT_CTL: RS485_ADD_EN Position */
#define UART_ALT_CTL_RS485_ADD_EN_Msk   (0x1ul << UART_ALT_CTL_RS485_ADD_EN_Pos)    /*!< UART ALT_CTL: RS485_ADD_EN Mask */
#define UART_ALT_CTL_ADDR_PID_MATCH_Pos 24                                          /*!< UART ALT_CTL: ADDR_PID_MATCH Position */
#define UART_ALT_CTL_ADDR_PID_MATCH_Msk (0xFFul << UART_ALT_CTL_ADDR_PID_MATCH_Pos) /*!< UART ALT_CTL: ADDR_PID_MATCH Mask */

/* UART FUN_SEL Bit Field Definitions */
#define UART_FUN_SEL_FUN_SEL_Pos    0                                           /*!< UART FUN_SEL: FUN_SEL Position */
#define UART_FUN_SEL_FUN_SEL_Msk    (0x3ul << UART_FUN_SEL_FUN_SEL_Pos)         /*!< UART FUN_SEL: FUN_SEL Mask */

/*@}*/ /* end of group NANO100_UART */


/*------------- LCD (LCD) -----------------------------*/
/** @addtogroup NANO100_LCD NANO100 LCD Control Register (LCD)
  @{
*/
typedef struct {
    __IO uint32_t  CTL;       /*!< Offset: 0x0000   LCD Control Register                 */
    __IO uint32_t  DISPCTL;   /*!< Offset: 0x0004   LCD Display Control Register        */
    __IO uint32_t  MEM_0;     /*!< Offset: 0x0008   LCD SEG3 ~ SEG0 data                */
    __IO uint32_t  MEM_1;     /*!< Offset: 0x000C   LCD SEG7 ~ SEG4 data                */
    __IO uint32_t  MEM_2;     /*!< Offset: 0x0010   LCD SEG11 ~ SEG8 data               */
    __IO uint32_t  MEM_3;     /*!< Offset: 0x0014   LCD SEG15 ~ SEG12 data              */
    __IO uint32_t  MEM_4;     /*!< Offset: 0x0018   LCD SEG19 ~ SEG16 data              */
    __IO uint32_t  MEM_5;     /*!< Offset: 0x001C   LCD SEG23 ~ SEG20 data              */
    __IO uint32_t  MEM_6;     /*!< Offset: 0x0020   LCD SEG27 ~ SEG24 data              */
    __IO uint32_t  MEM_7;     /*!< Offset: 0x0024   LCD SEG31 ~ SEG28 data              */
    __IO uint32_t  MEM_8;     /*!< Offset: 0x0028   LCD SEG35 ~ SEG32 data              */
    __IO uint32_t  MEM_9;     /*!< Offset: 0x002C   LCD SEG39 ~ SEG36 data              */
    __IO uint32_t  FCR;       /*!< Offset: 0x0030   LCD frame counter control register  */
    __IO uint32_t  FCSTS;     /*!< Offset: 0x0034   LCD frame counter status            */
} LCD_T;

/* LCD CTL Bit Field Definitions */
#define LCD_CTL_EN_Pos          0                                   /*!< LCD CTL: EN Posistion */
#define LCD_CTL_EN_Msk          (0x1ul << LCD_CTL_EN_Pos)           /*!< LCD CTL: EN Mask */
#define LCD_CTL_MUX_Pos         1                                   /*!< LCD CTL: MUX Posistion */
#define LCD_CTL_MUX_Msk         (0x7ul << LCD_CTL_MUX_Pos)          /*!< LCD CTL: MUX Mask */
#define LCD_CTL_FREQ_Pos        4                                   /*!< LCD CTL: FREQ Posistion */
#define LCD_CTL_FREQ_Msk        (0x7ul << LCD_CTL_FREQ_Pos)         /*!< LCD CTL: FREQ Mask */
#define LCD_CTL_BLINK_Pos       7                                   /*!< LCD CTL: BLINK Posistion */
#define LCD_CTL_BLINK_Msk       (0x1ul << LCD_CTL_BLINK_Pos)        /*!< LCD CTL: BLINK Mask */
#define LCD_CTL_PDDISP_EN_Pos   8                                   /*!< LCD CTL: PDDISP_EN Posistion */
#define LCD_CTL_PDDISP_EN_Msk   (0x1ul << LCD_CTL_PDDISP_EN_Pos)    /*!< LCD CTL: PDDISP_EN Mask */
#define LCD_CTL_PDINT_EN_Pos    9                                   /*!< LCD CTL: PDINT_EN Posistion */
#define LCD_CTL_PDINT_EN_Msk    (0x1ul << LCD_CTL_PDINT_EN_Pos)     /*!< LCD CTL: PDINT_EN Mask */

/* LCD DISPCTL Bit Field Definitions */
#define LCD_DISPCTL_CPUMP_EN_Pos        0                                       /*!< LCD DISPCTL: CPUMP_EN Posistion */
#define LCD_DISPCTL_CPUMP_EN_Msk        (0x1ul << LCD_DISPCTL_CPUMP_EN_Pos)     /*!< LCD DISPCTL: CPUMP_EN Mask */
#define LCD_DISPCTL_BIAS_SEL_Pos        1                                       /*!< LCD DISPCTL: BIAS_SEL Posistion */
#define LCD_DISPCTL_BIAS_SEL_Msk        (0x3ul << LCD_DISPCTL_BIAS_SEL_Pos)     /*!< LCD DISPCTL: BIAS_SEL Mask */
#define LCD_DISPCTL_IBRL_EN_Pos         4                                       /*!< LCD DISPCTL: IBRL_EN Posistion */
#define LCD_DISPCTL_IBRL_EN_Msk         (0x1ul << LCD_DISPCTL_IBRL_EN_Pos)      /*!< LCD DISPCTL: IBRL_EN Mask */
#define LCD_DISPCTL_BV_SEL_Pos          6                                       /*!< LCD DISPCTL: BV_SEL Posistion */
#define LCD_DISPCTL_BV_SEL_Msk          (0x1ul << LCD_DISPCTL_BV_SEL_Pos)       /*!< LCD DISPCTL: BV_SEL Mask */
#define LCD_DISPCTL_CPUMP_VOL_SET_Pos   8                                           /*!< LCD DISPCTL: CPUMP_VOL_SET Posistion */
#define LCD_DISPCTL_CPUMP_VOL_SET_Msk   (0x7ul << LCD_DISPCTL_CPUMP_VOL_SET_Pos)    /*!< LCD DISPCTL: CPUMP_VOL_SET Mask */
#define LCD_DISPCTL_CPUMP_FREQ_Pos      11                                      /*!< LCD DISPCTL: CPUMP_FREQ Posistion */
#define LCD_DISPCTL_CPUMP_FREQ_Msk      (0x7ul << LCD_DISPCTL_CPUMP_FREQ_Pos)   /*!< LCD DISPCTL: CPUMP_FREQ Mask */
#define LCD_DISPCTL_EXT_C_Pos           16                                      /*!< LCD DISPCTL: EXT_C Posistion */
#define LCD_DISPCTL_EXT_C_Msk           (0x1ul << LCD_DISPCTL_EXT_C_Pos)        /*!< LCD DISPCTL: EXT_C Mask */
#define LCD_DISPCTL_RES_SEL_Pos         17                                      /*!< LCD DISPCTL: RES_SEL Posistion */
#define LCD_DISPCTL_RES_SEL_Msk         (0x3ul << LCD_DISPCTL_RES_SEL_Pos)      /*!< LCD DISPCTL: RES_SEL Mask */

/* LCD MEM_0 Bit Field Definitions */
#define LCD_MEM_0_SEG_0_Pos         0                                   /*!< LCD MEM_0: SEG_0 Posistion */
#define LCD_MEM_0_SEG_0_Msk         (0x3Ful << LCD_MEM_0_SEG_0_Pos)     /*!< LCD MEM_0: SEG_0 Mask */
#define LCD_MEM_0_SEG_1_Pos         8                                   /*!< LCD MEM_0: SEG_1 Posistion */
#define LCD_MEM_0_SEG_1_Msk         (0x3Ful << LCD_MEM_0_SEG_1_Pos)     /*!< LCD MEM_0: SEG_1 Mask */
#define LCD_MEM_0_SEG_2_Pos         16                                  /*!< LCD MEM_0: SEG_2 Posistion */
#define LCD_MEM_0_SEG_2_Msk         (0x3Ful << LCD_MEM_0_SEG_2_Pos)     /*!< LCD MEM_0: SEG_2 Mask */
#define LCD_MEM_0_SEG_3_Pos         24                                  /*!< LCD MEM_0: SEG_3 Posistion */
#define LCD_MEM_0_SEG_3_Msk         (0x3Ful << LCD_MEM_0_SEG_3_Pos)     /*!< LCD MEM_0: SEG_3 Mask */

/* LCD MEM_1 Bit Field Definitions */
#define LCD_MEM_1_SEG_4_Pos         0                                   /*!< LCD MEM_1: SEG_4 Posistion */
#define LCD_MEM_1_SEG_4_Msk         (0x3Ful << LCD_MEM_1_SEG_4_Pos)     /*!< LCD MEM_1: SEG_4 Mask */
#define LCD_MEM_1_SEG_5_Pos         8                                   /*!< LCD MEM_1: SEG_5 Posistion */
#define LCD_MEM_1_SEG_5_Msk         (0x3Ful << LCD_MEM_1_SEG_5_Pos)     /*!< LCD MEM_1: SEG_5 Mask */
#define LCD_MEM_1_SEG_6_Pos         16                                  /*!< LCD MEM_1: SEG_6 Posistion */
#define LCD_MEM_1_SEG_6_Msk         (0x3Ful << LCD_MEM_1_SEG_6_Pos)     /*!< LCD MEM_1: SEG_6 Mask */
#define LCD_MEM_1_SEG_7_Pos         24                                  /*!< LCD MEM_1: SEG_7 Posistion */
#define LCD_MEM_1_SEG_7_Msk         (0x3Ful << LCD_MEM_1_SEG_7_Pos)     /*!< LCD MEM_1: SEG_7 Mask */

/* LCD MEM_2 Bit Field Definitions */
#define LCD_MEM_2_SEG_8_Pos         0                                   /*!< LCD MEM_2: SEG_8 Posistion */
#define LCD_MEM_2_SEG_8_Msk         (0x3Ful << LCD_MEM_2_SEG_8_Pos)     /*!< LCD MEM_2: SEG_8 Mask */
#define LCD_MEM_2_SEG_9_Pos         8                                   /*!< LCD MEM_2: SEG_9 Posistion */
#define LCD_MEM_2_SEG_9_Msk         (0x3Ful << LCD_MEM_2_SEG_9_Pos)     /*!< LCD MEM_2: SEG_9 Mask */
#define LCD_MEM_2_SEG_10_Pos        16                                  /*!< LCD MEM_2: SEG_10 Posistion */
#define LCD_MEM_2_SEG_10_Msk        (0x3Ful << LCD_MEM_2_SEG_10_Pos)    /*!< LCD MEM_2: SEG_10 Mask */
#define LCD_MEM_2_SEG_11_Pos        24                                  /*!< LCD MEM_2: SEG_11 Posistion */
#define LCD_MEM_2_SEG_11_Msk        (0x3Ful << LCD_MEM_2_SEG_11_Pos)    /*!< LCD MEM_2: SEG_11 Mask */

/* LCD MEM_3 Bit Field Definitions */
#define LCD_MEM_3_SEG_12_Pos        0                                   /*!< LCD MEM_3: SEG_12 Posistion */
#define LCD_MEM_3_SEG_12_Msk        (0x3Ful << LCD_MEM_3_SEG_12_Pos)    /*!< LCD MEM_3: SEG_12 Mask */
#define LCD_MEM_3_SEG_13_Pos        8                                   /*!< LCD MEM_3: SEG_13 Posistion */
#define LCD_MEM_3_SEG_13_Msk        (0x3Ful << LCD_MEM_3_SEG_13_Pos)    /*!< LCD MEM_3: SEG_13 Mask */
#define LCD_MEM_3_SEG_14_Pos        16                                  /*!< LCD MEM_3: SEG_14 Posistion */
#define LCD_MEM_3_SEG_14_Msk        (0x3Ful << LCD_MEM_3_SEG_14_Pos)    /*!< LCD MEM_3: SEG_14 Mask */
#define LCD_MEM_3_SEG_15_Pos        24                                  /*!< LCD MEM_3: SEG_15 Posistion */
#define LCD_MEM_3_SEG_15_Msk        (0x3Ful << LCD_MEM_3_SEG_15_Pos)    /*!< LCD MEM_3: SEG_15 Mask */

/* LCD MEM_4 Bit Field Definitions */
#define LCD_MEM_4_SEG_16_Pos        0                                   /*!< LCD MEM_4: SEG_16 Posistion */
#define LCD_MEM_4_SEG_16_Msk        (0x3Ful << LCD_MEM_4_SEG_16_Pos)    /*!< LCD MEM_4: SEG_16 Mask */
#define LCD_MEM_4_SEG_17_Pos        8                                   /*!< LCD MEM_4: SEG_17 Posistion */
#define LCD_MEM_4_SEG_17_Msk        (0x3Ful << LCD_MEM_4_SEG_17_Pos)    /*!< LCD MEM_4: SEG_17 Mask */
#define LCD_MEM_4_SEG_18_Pos        16                                  /*!< LCD MEM_4: SEG_18 Posistion */
#define LCD_MEM_4_SEG_18_Msk        (0x3Ful << LCD_MEM_4_SEG_18_Pos)    /*!< LCD MEM_4: SEG_18 Mask */
#define LCD_MEM_4_SEG_19_Pos        24                                  /*!< LCD MEM_4: SEG_19 Posistion */
#define LCD_MEM_4_SEG_19_Msk        (0x3Ful << LCD_MEM_4_SEG_19_Pos)    /*!< LCD MEM_4: SEG_19 Mask */

/* LCD MEM_5 Bit Field Definitions */
#define LCD_MEM_5_SEG_20_Pos        0                                   /*!< LCD MEM_5: SEG_20 Posistion */
#define LCD_MEM_5_SEG_20_Msk        (0x3Ful << LCD_MEM_5_SEG_20_Pos)    /*!< LCD MEM_5: SEG_20 Mask */
#define LCD_MEM_5_SEG_21_Pos        8                                   /*!< LCD MEM_5: SEG_21 Posistion */
#define LCD_MEM_5_SEG_21_Msk        (0x3Ful << LCD_MEM_5_SEG_21_Pos)    /*!< LCD MEM_5: SEG_21 Mask */
#define LCD_MEM_5_SEG_22_Pos        16                                  /*!< LCD MEM_5: SEG_22 Posistion */
#define LCD_MEM_5_SEG_22_Msk        (0x3Ful << LCD_MEM_5_SEG_22_Pos)    /*!< LCD MEM_5: SEG_22 Mask */
#define LCD_MEM_5_SEG_23_Pos        24                                  /*!< LCD MEM_5: SEG_23 Posistion */
#define LCD_MEM_5_SEG_23_Msk        (0x3Ful << LCD_MEM_5_SEG_23_Pos)    /*!< LCD MEM_5: SEG_23 Mask */

/* LCD MEM_6 Bit Field Definitions */
#define LCD_MEM_6_SEG_24_Pos        0                                   /*!< LCD MEM_6: SEG_24 Posistion */
#define LCD_MEM_6_SEG_24_Msk        (0x3Ful << LCD_MEM_6_SEG_24_Pos)    /*!< LCD MEM_6: SEG_24 Mask */
#define LCD_MEM_6_SEG_25_Pos        8                                   /*!< LCD MEM_6: SEG_25 Posistion */
#define LCD_MEM_6_SEG_25_Msk        (0x3Ful << LCD_MEM_6_SEG_25_Pos)    /*!< LCD MEM_6: SEG_25 Mask */
#define LCD_MEM_6_SEG_26_Pos        16                                  /*!< LCD MEM_6: SEG_26 Posistion */
#define LCD_MEM_6_SEG_26_Msk        (0x3Ful << LCD_MEM_6_SEG_26_Pos)    /*!< LCD MEM_6: SEG_26 Mask */
#define LCD_MEM_6_SEG_27_Pos        24                                  /*!< LCD MEM_6: SEG_27 Posistion */
#define LCD_MEM_6_SEG_27_Msk        (0x3Ful << LCD_MEM_6_SEG_27_Pos)    /*!< LCD MEM_6: SEG_27 Mask */

/* LCD MEM_7 Bit Field Definitions */
#define LCD_MEM_7_SEG_28_Pos        0                                   /*!< LCD MEM_7: SEG_28 Posistion */
#define LCD_MEM_7_SEG_28_Msk        (0x3Ful << LCD_MEM_7_SEG_28_Pos)    /*!< LCD MEM_7: SEG_28 Mask */
#define LCD_MEM_7_SEG_29_Pos        8                                   /*!< LCD MEM_7: SEG_29 Posistion */
#define LCD_MEM_7_SEG_29_Msk        (0x3Ful << LCD_MEM_7_SEG_29_Pos)    /*!< LCD MEM_7: SEG_29 Mask */
#define LCD_MEM_7_SEG_30_Pos        16                                  /*!< LCD MEM_7: SEG_30 Posistion */
#define LCD_MEM_7_SEG_30_Msk        (0x3Ful << LCD_MEM_7_SEG_30_Pos)    /*!< LCD MEM_7: SEG_30 Mask */
#define LCD_MEM_7_SEG_31_Pos        24                                  /*!< LCD MEM_7: SEG_31 Posistion */
#define LCD_MEM_7_SEG_31_Msk        (0x3Ful << LCD_MEM_7_SEG_31_Pos)    /*!< LCD MEM_7: SEG_31 Mask */

/* LCD MEM_8 Bit Field Definitions */
#define LCD_MEM_8_SEG_32_Pos        0                                   /*!< LCD MEM_8: SEG_32 Posistion */
#define LCD_MEM_8_SEG_32_Msk        (0x3Ful << LCD_MEM_8_SEG_32_Pos)    /*!< LCD MEM_8: SEG_32 Mask */
#define LCD_MEM_8_SEG_33_Pos        8                                   /*!< LCD MEM_8: SEG_33 Posistion */
#define LCD_MEM_8_SEG_33_Msk        (0x3Ful << LCD_MEM_8_SEG_33_Pos)    /*!< LCD MEM_8: SEG_33 Mask */
#define LCD_MEM_8_SEG_34_Pos        16                                  /*!< LCD MEM_8: SEG_34 Posistion */
#define LCD_MEM_8_SEG_34_Msk        (0x3Ful << LCD_MEM_8_SEG_34_Pos)    /*!< LCD MEM_8: SEG_34 Mask */
#define LCD_MEM_8_SEG_35_Pos        24                                  /*!< LCD MEM_8: SEG_35 Posistion */
#define LCD_MEM_8_SEG_35_Msk        (0x3Ful << LCD_MEM_8_SEG_35_Pos)    /*!< LCD MEM_8: SEG_35 Mask */

/* LCD MEM_9 Bit Field Definitions */
#define LCD_MEM_9_SEG_36_Pos        0                                   /*!< LCD MEM_9: SEG_36 Posistion */
#define LCD_MEM_9_SEG_36_Msk        (0x3Ful << LCD_MEM_9_SEG_36_Pos)    /*!< LCD MEM_9: SEG_36 Mask */
#define LCD_MEM_9_SEG_37_Pos        8                                   /*!< LCD MEM_9: SEG_37 Posistion */
#define LCD_MEM_9_SEG_37_Msk        (0x3Ful << LCD_MEM_9_SEG_37_Pos)    /*!< LCD MEM_9: SEG_37 Mask */
#define LCD_MEM_9_SEG_38_Pos        16                                  /*!< LCD MEM_9: SEG_38 Posistion */
#define LCD_MEM_9_SEG_38_Msk        (0x3Ful << LCD_MEM_9_SEG_38_Pos)    /*!< LCD MEM_9: SEG_38 Mask */
#define LCD_MEM_9_SEG_39_Pos        24                                  /*!< LCD MEM_9: SEG_39 Posistion */
#define LCD_MEM_9_SEG_39_Msk        (0x3Ful << LCD_MEM_9_SEG_39_Pos)    /*!< LCD MEM_9: SEG_39 Mask */

/* LCD FCR Bit Field Definitions */
#define LCD_FCR_FCEN_Pos        0                               /*!< LCD FCR: FCEN Posistion */
#define LCD_FCR_FCEN_Msk        (0x1ul << LCD_FCR_FCEN_Pos)     /*!< LCD FCR: FCEN Mask */
#define LCD_FCR_FCINTEN_Pos     1                               /*!< LCD FCR: FCINTEN Posistion */
#define LCD_FCR_FCINTEN_Msk     (0x1ul << LCD_FCR_FCINTEN_Pos)  /*!< LCD FCR: FCINTEN Mask */
#define LCD_FCR_PRESCL_Pos      2                               /*!< LCD FCR: PRESCL Posistion */
#define LCD_FCR_PRESCL_Msk      (0x3ul << LCD_FCR_PRESCL_Pos)   /*!< LCD FCR: PRESCL Mask */
#define LCD_FCR_FCV_Pos         4                               /*!< LCD FCR: FCV Posistion */
#define LCD_FCR_FCV_Msk         (0x3Ful << LCD_FCR_FCV_Pos)     /*!< LCD FCR: FCV Mask */

/* LCD FCSTS Bit Field Definitions */
#define LCD_FCSTS_FCSTS_Pos     1                               /*!< LCD FCSTS: FCSTS Posistion */
#define LCD_FCSTS_FCSTS_Msk     (0x1ul << LCD_FCSTS_FCSTS_Pos)  /*!< LCD FCSTS: FCSTS Mask */
#define LCD_FCSTS_PDSTS_Pos     2                               /*!< LCD FCSTS: PDSTS Posistion */
#define LCD_FCSTS_PDSTS_Msk     (0x1ul << LCD_FCSTS_FCSTS_Pos)  /*!< LCD FCSTS: PDSTS Mask */


/*@}*/ /* end of group NANO100_LCD */




/*------------- Watchdog Timer Control Register (WDT) -----------------------------*/
/** @addtogroup NANO100_WDT NANO100 Watchdog Timer Control Register (WDT)
  Memory Mapped Structure for NANO100 Series Watchdog Timer Controller
  @{
*/
/**
  * @brief WDT register map
  */
typedef struct {
    __IO uint32_t  CTL;                        /*!< Offset: 0x0000   Watchdog Timer Control Register             */
    __IO uint32_t  IER;                        /*!< Offset: 0x0004   Watchdog Timer Interrupt Enable Register    */
    __IO uint32_t  ISR;                        /*!< Offset: 0x0008   Watchdog Timer Interrupt Status Register    */

} WDT_T;

/* WDT CTL Bit Field Definitions */
#define WDT_CTL_WTRDSEL_Pos    8                                            /*!< WDT CTL : WTRDSEL Position    */
#define WDT_CTL_WTRDSEL_Msk    (0x3ul << WDT_CTL_WTRDSEL_Pos)               /*!< WDT CTL : WTRDSEL Mask        */

#define WDT_CTL_WTIS_Pos       4                                            /*!< WDT CTL : WTIS Position       */
#define WDT_CTL_WTIS_Msk       (0x7ul << WDT_CTL_WTIS_Pos)                  /*!< WDT CTL : WTIS Mask           */

#define WDT_CTL_WTE_Pos        3                                            /*!< WDT CTL : WTE Position        */
#define WDT_CTL_WTE_Msk        (1ul << WDT_CTL_WTE_Pos)                     /*!< WDT CTL : WTE Mask            */

#define WDT_CTL_WTWKE_Pos      2                                            /*!< WDT CTL : WTWKE Position      */
#define WDT_CTL_WTWKE_Msk      (1ul << WDT_CTL_WTWKE_Pos)                   /*!< WDT CTL : WTWKE Mask          */

#define WDT_CTL_WTRE_Pos       1                                            /*!< WDT CTL : WTRE Position       */
#define WDT_CTL_WTRE_Msk       (1ul << WDT_CTL_WTRE_Pos)                    /*!< WDT CTL : WTRE Mask           */

#define WDT_CTL_WTR_Pos        0                                            /*!< WDT CTL : WTR Position        */
#define WDT_CTL_WTR_Msk        (1ul << WDT_CTL_WTR_Pos)                     /*!< WDT CTL : WTR Mask            */

/* WDT IER Bit Field Definitions */
#define WDT_IER_IE_Pos         0                                            /*!< WDT IER : IE Position         */
#define WDT_IER_IE_Msk         (1ul << WDT_IER_IE_Pos)                      /*!< WDT IER : IE Mask             */

/* WDT ISR Bit Field Definitions */
#define WDT_ISR_WAKE_IS_Pos    2                                            /*!< WDT ISR : WAKE_IS Position    */
#define WDT_ISR_WAKE_IS_Msk    (1ul << WDT_ISR_WAKE_IS_Pos)                 /*!< WDT ISR : WAKE_IS Mask        */

#define WDT_ISR_RST_IS_Pos     1                                            /*!< WDT ISR : RST_IS Position     */
#define WDT_ISR_RST_IS_Msk     (1ul << WDT_ISR_RST_IS_Pos)                  /*!< WDT ISR : RST_IS Mask         */

#define WDT_ISR_IS_Pos         0                                            /*!< WDT ISR : IS Position         */
#define WDT_ISR_IS_Msk         (1ul << WDT_ISR_IS_Pos)                      /*!< WDT ISR : IS Mask             */


/*@}*/ /* end of group NANO100_WDT */


/*------------- Window Watchdog Timer Control Register (WWDT) -----------------------------*/
/** @addtogroup NANO100_WWDT NANO100 Window Watchdog Timer Control Register (WWDT)
  Memory Mapped Structure for NANO100 Series Window Watchdog Timer Controller
  @{
*/
/**
  * @brief WWDT register map
  */
typedef struct {
    __O  uint32_t  RLD;                        /*!< Offset: 0x0000   Window Watchdog Timer Reload Counter Register         */
    __IO uint32_t  CR;                         /*!< Offset: 0x0004   Window Watchdog Timer Control Register                */
    __IO uint32_t  IER;                        /*!< Offset: 0x0008   Window Watchdog Timer Interrupt Enable Register       */
    __IO uint32_t  STS;                        /*!< Offset: 0x000C   Window Watchdog Timer Status Register                 */
    __I  uint32_t  VAL;                        /*!< Offset: 0x0010   Window Watchdog Counter Value Register                */
} WWDT_T;

/* WWDT RLD Bit Field Definitions */
#define WWDT_RLD_RLD_Pos     0                                   /*!< WWDT RLD : RLD Position */
#define WWDT_RLD_RLD_Msk     (0xFFFFFFFFUL)                      /*!< WWDT RLD : RLD Mask     */

/* WWDT CR Bit Field Definitions */
#define WWDT_CR_DBGEN_Pos    31                                  /*!< WWDT CR : DBGEN Position */
#define WWDT_CR_DBGEN_Msk    (1UL << WWDT_CR_DBGEN_Pos)          /*!< WWDT CR : DBGEN Mask     */

#define WWDT_CR_WINCMP_Pos   16                                  /*!< WWDT CR : WINCMP Position */
#define WWDT_CR_WINCMP_Msk   (0x3FUL << WWDT_CR_WINCMP_Pos)      /*!< WWDT CR : WINCMP Mask     */

#define WWDT_CR_PERIODSEL_Pos   8                                /*!< WWDT CR : PERIODSEL Position */
#define WWDT_CR_PERIODSEL_Msk   (0xFUL << WWDT_CR_PERIODSEL_Pos) /*!< WWDT CR : PERIODSEL Mask     */

#define WWDT_CR_EN_Pos     0                                     /*!< WWDT CR : EN Position */
#define WWDT_CR_EN_Msk     (1UL << WWDT_CR_EN_Pos)               /*!< WWDT CR : EN Mask     */

/* WWDT IER Bit Field Definitions */
#define WWDT_IER_IE_Pos    0                                     /*!< WWDT IER : IE Position */
#define WWDT_IER_IE_Msk    (1UL << WWDT_IER_IE_Pos)              /*!< WWDT IER : IE Mask     */

/* WWDT STS Bit Field Definitions */
#define WWDT_STS_RF_Pos    1                                     /*!< WWDT STS : RF Position */
#define WWDT_STS_RF_Msk    (1UL << WWDT_STS_IE_Pos)              /*!< WWDT STS : RF Mask     */

#define WWDT_STS_IF_Pos    0                                     /*!< WWDT STS : IF Position */
#define WWDT_STS_IF_Msk    (1UL << WWDT_STS_IF_Pos)              /*!< WWDT STS : IF Mask     */

/* WWDT VAL Bit Field Definitions */
#define WWDT_VAL_VAL_Pos   0                                     /*!< WWDT VAL : VAL Position */
#define WWDT_VAL_VAL_Msk   (0x3FUL << WWDT_VAL_VAL_Pos)          /*!< WWDT VAL : VAL Mask     */


/*@}*/ /* end of group NANO100_WWDT */

/*------------- I2S Control Register (I2S) -----------------------------*/
/** @addtogroup NUC400_I2S NUC400 I2S Control Register (I2S)
  Memory Mapped Structure for NANO100 Series I2S Controller
  @{
*/
/**
  * @brief I2S register map
  */
typedef struct {
    __IO uint32_t CTRL;                          /*!< Offset: 0x0000   I2S Control Register                                */
    __IO uint32_t CLKDIV;                        /*!< Offset: 0x0004   I2S Clock Divider Control Register                  */
    __IO uint32_t INTEN;                         /*!< Offset: 0x0008   I2S Interrupt Enable Register                       */
    __IO uint32_t STATUS;                        /*!< Offset: 0x000C   I2S Status Register                                 */
    __O  uint32_t TXFIFO;                        /*!< Offset: 0x0010   I2S Transmit FIFO    Register                       */
    __I  uint32_t RXFIFO;                        /*!< Offset: 0x0014   I2S Receive FIFO Register                           */
} I2S_T;

/* I2S_CTRL Bit Field Definitions */
#define I2S_CTRL_I2SEN_Pos             0                                       /*!< I2S_CTRL: I2S enable */
#define I2S_CTRL_I2SEN_Msk             (0x1ul << I2S_CTRL_I2SEN_Pos)           /*!< I2S_CTRL: I2SEN Mask */
#define I2S_CTRL_TXEN_Pos              1                                       /*!< I2S_CTRL: Data transmit enable */
#define I2S_CTRL_TXEN_Msk              (0x1ul << I2S_CTRL_TXEN_Pos)            /*!< I2S_CTRL: TXEN Mask */
#define I2S_CTRL_RXEN_Pos              2                                       /*!< I2S_CTRL: Data receive enable */
#define I2S_CTRL_RXEN_Msk              (0x1ul << I2S_CTRL_RXEN_Pos)            /*!< I2S_CTRL: RXEN Mask */
#define I2S_CTRL_MUTE_Pos              3                                       /*!< I2S_CTRL: Transmit mute enable */
#define I2S_CTRL_MUTE_Msk              (0x1ul << I2S_CTRL_MUTE_Pos)            /*!< I2S_CTRL: MUTE Mask */
#define I2S_CTRL_WORDWIDTH_Pos         4                                       /*!< I2S_CTRL: Word length */
#define I2S_CTRL_WORDWIDTH_Msk         (0x3ul << I2S_CTRL_WORDWIDTH_Pos)       /*!< I2S_CTRL: WORDWIDTH Mask */
#define I2S_CTRL_MONO_Pos              6                                       /*!< I2S_CTRL: Stereo or mono format select */
#define I2S_CTRL_MONO_Msk              (0x1ul << I2S_CTRL_MONO_Pos)            /*!< I2S_CTRL: MONO Mask */
#define I2S_CTRL_FORMAT_Pos            7                                       /*!< I2S_CTRL: I2S or MSB-justified format select */
#define I2S_CTRL_FORMAT_Msk            (0x1ul << I2S_CTRL_FORMAT_Pos)          /*!< I2S_CTRL: FORMAT Mask */
#define I2S_CTRL_SLAVE_Pos             8                                       /*!< I2S_CTRL: Slave or master mode */
#define I2S_CTRL_SLAVE_Msk             (0x1ul << I2S_CTRL_SLAVE_Pos)           /*!< I2S_CTRL: SLAVE Mask */
#define I2S_CTRL_TXTH_Pos              9                                       /*!< I2S_CTRL: Transmit FIFO threshold level */
#define I2S_CTRL_TXTH_Msk              (0x7ul << I2S_CTRL_TXTH_Pos)            /*!< I2S_CTRL: TXTH Mask */
#define I2S_CTRL_RXTH_Pos              12                                      /*!< I2S_CTRL: Receive FIFO threshold level */
#define I2S_CTRL_RXTH_Msk              (0x7ul << I2S_CTRL_RXTH_Pos)            /*!< I2S_CTRL: RXTH Mask */
#define I2S_CTRL_MCLKEN_Pos            15                                      /*!< I2S_CTRL: Master clock enable */
#define I2S_CTRL_MCLKEN_Msk            (0x1ul << I2S_CTRL_MCLKEN_Pos)          /*!< I2S_CTRL: MCLKEN Mask */
#define I2S_CTRL_RCHZCEN_Pos           16                                      /*!< I2S_CTRL: Right channel zero-cross detection enable */
#define I2S_CTRL_RCHZCEN_Msk           (0x1ul << I2S_CTRL_RCHZCEN_Pos)         /*!< I2S_CTRL: RCHZCEN Mask */
#define I2S_CTRL_LCHZCEN_Pos           17                                      /*!< I2S_CTRL: Left channel zero-cross detect enable */
#define I2S_CTRL_LCHZCEN_Msk           (0x1ul << I2S_CTRL_LCHZCEN_Pos)         /*!< I2S_CTRL: LCHZCEN Mask */
#define I2S_CTRL_CLR_TXFIFO_Pos        18                                      /*!< I2S_CTRL: Clear transmit FIFO */
#define I2S_CTRL_CLR_TXFIFO_Msk        (0x1ul << I2S_CTRL_CLR_TXFIFO_Pos)      /*!< I2S_CTRL: CLR_TXFIFO Mask */
#define I2S_CTRL_CLR_RXFIFO_Pos        19                                      /*!< I2S_CTRL: Clear receive FIFO */
#define I2S_CTRL_CLR_RXFIFO_Msk        (0x1ul << I2S_CTRL_CLR_RXFIFO_Pos)      /*!< I2S_CTRL: CLR_RXFIFO Mask */
#define I2S_CTRL_TXDMA_Pos             20                                      /*!< I2S_CTRL: Enable transmit DMA */
#define I2S_CTRL_TXDMA_Msk             (0x1ul << I2S_CTRL_TXDMA_Pos)           /*!< I2S_CTRL: TXDMA Mask */
#define I2S_CTRL_RXDMA_Pos             21                                      /*!< I2S_CTRL: Enable receive DMA */
#define I2S_CTRL_RXDMA_Msk             (0x1ul << I2S_CTRL_RXDMA_Pos)           /*!< I2S_CTRL: RXDMA Mask */
#define I2S_CTRL_RXLCH_Pos             23                                      /*!< I2S_CTRL: Receive left channel enable */
#define I2S_CTRL_RXLCH_Msk             (0x1ul << I2S_CTRL_RXLCH_Pos)           /*!< I2S_CTRL: RXLCH Mask */

/* I2S_CLKDIV Bit Field Definitions */
#define I2S_CLKDIV_MCLK_DIV_Pos        0                                       /*!< I2S_CLKDIV: Master clock divider */
#define I2S_CLKDIV_MCLK_DIV_Msk        (0x3Ful << I2S_CLKDIV_MCLK_DIV_Pos)     /*!< I2S_CLKDIV: MCLK_DIV Mask */
#define I2S_CLKDIV_BCLK_DIV_Pos        8                                       /*!< I2S_CLKDIV: Bit clock divider */
#define I2S_CLKDIV_BCLK_DIV_Msk        (0xFFul << I2S_CLKDIV_BCLK_DIV_Pos)     /*!< I2S_CLKDIV: BCLK_DIV Mask */

/* I2S_INTEN Bit Field Definitions */
#define I2S_INTEN_RXUDFIE_Pos          0                                       /*!< I2S_INTEN: Receive FIFO underflow interrupt enable */
#define I2S_INTEN_RXUDFIE_Msk          (0x1ul << I2S_INTEN_RXUDFIE_Pos)        /*!< I2S_INTEN: RXUDFIE Mask */
#define I2S_INTEN_RXOVFIE_Pos          1                                       /*!< I2S_INTEN: Receive FIFO overflow interrupt enable */
#define I2S_INTEN_RXOVFIE_Msk          (0x1ul << I2S_INTEN_RXOVFIE_Pos)        /*!< I2S_INTEN: RXOVFIE Mask */
#define I2S_INTEN_RXTHIE_Pos           2                                       /*!< I2S_INTEN: Receive FIFO underflow interrupt enable */
#define I2S_INTEN_RXTHIE_Msk           (0x1ul << I2S_INTEN_RXTHIE_Pos)         /*!< I2S_INTEN: RXTHIE Mask */
#define I2S_INTEN_TXUDFIE_Pos          8                                       /*!< I2S_INTEN: Transmit FIFO underflow interrupt enable */
#define I2S_INTEN_TXUDFIE_Msk          (0x1ul << I2S_INTEN_TXUDFIE_Pos)        /*!< I2S_INTEN: TXUDFIE Mask */
#define I2S_INTEN_TXOVFIE_Pos          9                                       /*!< I2S_INTEN: Transmit FIFO overflow interrupt enable */
#define I2S_INTEN_TXOVFIE_Msk          (0x1ul << I2S_INTEN_TXOVFIE_Pos)        /*!< I2S_INTEN: TXOVFIE_ Mask */
#define I2S_INTEN_TXTHIE_Pos           10                                      /*!< I2S_INTEN: Transmit FIFO threshold level interrupt enable */
#define I2S_INTEN_TXTHIE_Msk           (0x1ul << I2S_INTEN_TXTHIE_Pos)         /*!< I2S_INTEN: TXTHIE Mask */
#define I2S_INTEN_RZCIE_Pos            11                                      /*!< I2S_INTEN: Right channel zero-cross interrupt enable */
#define I2S_INTEN_RZCIE_Msk            (0x1ul << I2S_INTEN_RZCIE_Pos)          /*!< I2S_INTEN: RZCIE Mask */
#define I2S_INTEN_LZCIE_Pos            12                                      /*!< I2S_INTEN: Left channel zero-cross interrupt enable */
#define I2S_INTEN_LZCIE_Msk            (0x1ul << I2S_INTEN_LZCIE_Pos)          /*!< I2S_INTEN: LZCIE Mask */

/* I2S_STATUS Bit Field Definitions */
#define I2S_STATUS_I2SINT_Pos          0                                       /*!< I2S_STATUS: I2S interrupt flag */
#define I2S_STATUS_I2SINT_Msk          (0x1ul << I2S_STATUS_I2SINT_Pos)        /*!< I2S_STATUS: I2SINT Mask */
#define I2S_STATUS_I2SRXINT_Pos        1                                       /*!< I2S_STATUS: Receive interrupt flag */
#define I2S_STATUS_I2SRXINT_Msk        (0x1ul << I2S_STATUS_I2SRXINT_Pos)      /*!< I2S_STATUS: I2SRXINT Mask */
#define I2S_STATUS_I2STXINT_Pos        2                                       /*!< I2S_STATUS: Transmit interrupt flag */
#define I2S_STATUS_I2STXINT_Msk        (0x1ul << I2S_STATUS_I2STXINT_Pos)      /*!< I2S_STATUS: I2STXINT Mask */
#define I2S_STATUS_RIGHT_Pos           3                                       /*!< I2S_STATUS: Right or left channel select */
#define I2S_STATUS_RIGHT_Msk           (0x1ul << I2S_STATUS_RIGHT_Pos)         /*!< I2S_STATUS: RIGHT Mask */
#define I2S_STATUS_RXUDF_Pos           8                                       /*!< I2S_STATUS: Receive FIFO underflow flag */
#define I2S_STATUS_RXUDF_Msk           (0x1ul << I2S_STATUS_RXUDF_Pos)         /*!< I2S_STATUS: RXUDF Mask */
#define I2S_STATUS_RXOVF_Pos           9                                       /*!< I2S_STATUS: Receive FIFO overflow flag */
#define I2S_STATUS_RXOVF_Msk           (0x1ul << I2S_STATUS_RXOVF_Pos)         /*!< I2S_STATUS: RXOVF Mask */
#define I2S_STATUS_RXTHF_Pos           10                                      /*!< I2S_STATUS: Receive FIFO threshold flag */
#define I2S_STATUS_RXTHF_Msk           (0x1ul << I2S_STATUS_RXTHF_Pos)         /*!< I2S_STATUS: RXTHF Mask */
#define I2S_STATUS_RXFULL_Pos          11                                      /*!< I2S_STATUS: Receive FIFO full flag */
#define I2S_STATUS_RXFULL_Msk          (0x1ul << I2S_STATUS_RXFULL_Pos)        /*!< I2S_STATUS: RXFULL Mask */
#define I2S_STATUS_RXEMPTY_Pos         12                                      /*!< I2S_STATUS: Receive FIFO empty flag */
#define I2S_STATUS_RXEMPTY_Msk         (0x1ul << I2S_STATUS_RXEMPTY_Pos)       /*!< I2S_STATUS: RXEMPTY Mask */
#define I2S_STATUS_TXUDF_Pos           16                                      /*!< I2S_STATUS: Transmit FIFO underflow flag */
#define I2S_STATUS_TXUDF_Msk           (0x1ul << I2S_STATUS_TXUDF_Pos)         /*!< I2S_STATUS: TXUDF Mask */
#define I2S_STATUS_TXOVF_Pos           17                                      /*!< I2S_STATUS: Transmit FIFO overflow flag */
#define I2S_STATUS_TXOVF_Msk           (0x1ul << I2S_STATUS_TXOVF_Pos)         /*!< I2S_STATUS: TXOVF Mask */
#define I2S_STATUS_TXTHF_Pos           18                                      /*!< I2S_STATUS: Transmit FIFO threshold flag */
#define I2S_STATUS_TXTHF_Msk           (0x1ul << I2S_STATUS_TXTHF_Pos)         /*!< I2S_STATUS: TXTHF Mask */
#define I2S_STATUS_TXFULL_Pos          19                                      /*!< I2S_STATUS: Transmit FIFO full flag */
#define I2S_STATUS_TXFULL_Msk          (0x1ul << I2S_STATUS_TXFULL_Pos)        /*!< I2S_STATUS: TXFULL Mask */
#define I2S_STATUS_TXEMPTY_Pos         20                                      /*!< I2S_STATUS: Transmit FIFO empty flag */
#define I2S_STATUS_TXEMPTY_Msk         (0x1ul << I2S_STATUS_TXEMPTY_Pos)       /*!< I2S_STATUS: TXEMPTY Mask */
#define I2S_STATUS_TXBUSY_Pos          21                                      /*!< I2S_STATUS: Transmit under busy */
#define I2S_STATUS_TXBUSY_Msk          (0x1ul << I2S_STATUS_TXBUSY_Pos)        /*!< I2S_STATUS: TXBUSY Mask */
#define I2S_STATUS_RZCF_Pos            22                                      /*!< I2S_STATUS: Right channel zero-cross flag */
#define I2S_STATUS_RZCF_Msk            (0x1ul << I2S_STATUS_RZCF_Pos)          /*!< I2S_STATUS: RZCF Mask */
#define I2S_STATUS_LZCF_Pos            23                                      /*!< I2S_STATUS: Left channel zero-cross flag */
#define I2S_STATUS_LZCF_Msk            (0x1ul << I2S_STATUS_LZCF_Pos)          /*!< I2S_STATUS: LZCF Mask */
#define I2S_STATUS_RX_LEVEL_Pos        24                                      /*!< I2S_STATUS: Receive FIFO level */
#define I2S_STATUS_RX_LEVEL_Msk        (0xFul << I2S_STATUS_RX_LEVEL_Pos)      /*!< I2S_STATUS: RX_LEVEL Mask */
#define I2S_STATUS_TX_LEVEL_Pos        28                                      /*!< I2S_STATUS: Transmit FIFO level */
#define I2S_STATUS_TX_LEVEL_Msk        (0xFul << I2S_STATUS_TX_LEVEL_Pos)      /*!< I2S_STATUS: TX_LEVEL Mask */

/*@}*/ /* end of group NANO100_I2S */

#if defined ( __CC_ARM   )
#pragma no_anon_unions
#endif

/** @addtogroup NANO100_PERIPHERAL_MEM_MAP NANO100 Peripheral Memory Map
  Memory Mapped Structure for NANO100 Series Peripheral
  @{
 */
/*!<Peripheral and SRAM base address */
#define FLASH_BASE            ((uint32_t)0x00000000)    ///< Flash base address
#define SRAM_BASE             ((uint32_t)0x20000000)    ///< SRAM base address
#define APB1PERIPH_BASE       ((uint32_t)0x40000000)    ///< APB1 base address
#define APB2PERIPH_BASE       ((uint32_t)0x40100000)    ///< APB2 base address
#define AHBPERIPH_BASE        ((uint32_t)0x50000000)    ///< AHB base address

/*!<Peripheral memory map */

#define WDT_BASE              (APB1PERIPH_BASE + 0x04000)    ///< WDT register base address
#define WWDT_BASE             (APB1PERIPH_BASE + 0x04100)    ///< WWDT register base address
#define RTC_BASE              (APB1PERIPH_BASE + 0x08000)    ///< RTC register base address
#define TIMER0_BASE           (APB1PERIPH_BASE + 0x10000)    ///< TIMER0 register base address
#define TIMER1_BASE           (APB1PERIPH_BASE + 0x10100)    ///< TIMER1 register base address
#define I2C0_BASE             (APB1PERIPH_BASE + 0x20000)    ///< I2C0 register base address
#define SPI0_BASE             (APB1PERIPH_BASE + 0x30000)    ///< SPI0 register base address
#define PWM0_BASE             (APB1PERIPH_BASE + 0x40000)    ///< PWM0 register base address
#define UART0_BASE            (APB1PERIPH_BASE + 0x50000)    ///< UART0 register base address
#define LCD_BASE              (APB1PERIPH_BASE + 0xB0000)    ///< LCD register base address
#define SPI2_BASE             (APB1PERIPH_BASE + 0xD0000)    ///< SPI2 register base address
#define ADC_BASE              (APB1PERIPH_BASE + 0xE0000)    ///< ADC register base address

#define TIMER2_BASE           (APB2PERIPH_BASE + 0x10000)    ///< TIMER2 register base address
#define TIMER3_BASE           (APB2PERIPH_BASE + 0x10100)    ///< TIMER3 register base address
#define SHADOW_BASE           (APB1PERIPH_BASE + 0x10200)    ///< GPIO shadow register base address
#define I2C1_BASE             (APB2PERIPH_BASE + 0x20000)    ///< I2C1 register base address
#define SPI1_BASE             (APB2PERIPH_BASE + 0x30000)    ///< SPI1 register base address
#define PWM1_BASE             (APB2PERIPH_BASE + 0x40000)    ///< PWM1 register base address
#define UART1_BASE            (APB2PERIPH_BASE + 0x50000)    ///< UART1 register base address
#define USBD_BASE             (APB1PERIPH_BASE + 0x60000)    ///< USBD register base address
#define SC0_BASE              (APB2PERIPH_BASE + 0x90000)    ///< SC0 register base address
#define I2S_BASE              (APB2PERIPH_BASE + 0xA0000)    ///< I2S register base address
#define SC1_BASE              (APB2PERIPH_BASE + 0xB0000)    ///< SC1 register base address
#define SC2_BASE              (APB2PERIPH_BASE + 0xC0000)    ///< SC2 register base address

#define GCR_BASE              (AHBPERIPH_BASE + 0x00000)     ///< GCR register base address
#define CLK_BASE              (AHBPERIPH_BASE + 0x00200)     ///< CLK register base address
#define INTID_BASE            (AHBPERIPH_BASE + 0x00300)     ///< INT register base address
#define GPIOA_BASE            (AHBPERIPH_BASE + 0x04000)     ///< GPIO port A register base address
#define GPIOB_BASE            (AHBPERIPH_BASE + 0x04040)     ///< GPIO port B register base address
#define GPIOC_BASE            (AHBPERIPH_BASE + 0x04080)     ///< GPIO port C register base address
#define GPIOD_BASE            (AHBPERIPH_BASE + 0x040C0)     ///< GPIO port D register base address
#define GPIOE_BASE            (AHBPERIPH_BASE + 0x04100)     ///< GPIO port E register base address
#define GPIOF_BASE            (AHBPERIPH_BASE + 0x04140)     ///< GPIO port F register base address
#define GPIODBNCE_BASE        (AHBPERIPH_BASE + 0x04180)     ///< GPIO debounce register base address
#define GPIO_PIN_DATA_BASE    (AHBPERIPH_BASE + 0x04200)     ///< GPIO bit access register base address
#define VDMA_BASE             (AHBPERIPH_BASE + 0x08000)     ///< VDMA register base address
#define PDMA1_BASE            (AHBPERIPH_BASE + 0x08100)     ///< PDMA1 register base address
#define PDMA2_BASE            (AHBPERIPH_BASE + 0x08200)     ///< PDMA2 register base address
#define PDMA3_BASE            (AHBPERIPH_BASE + 0x08300)     ///< PDMA3 register base address
#define PDMA4_BASE            (AHBPERIPH_BASE + 0x08400)     ///< PDMA4 register base address
#define PDMA5_BASE            (AHBPERIPH_BASE + 0x08500)     ///< PDMA5 register base address
#define PDMA6_BASE            (AHBPERIPH_BASE + 0x08600)     ///< PDMA6 register base address
#define PDMACRC_BASE          (AHBPERIPH_BASE + 0x08E00)     ///< PDMA global control register base address
#define PDMAGCR_BASE          (AHBPERIPH_BASE + 0x08F00)     ///< PDMA CRC register base address
#define FMC_BASE              (AHBPERIPH_BASE + 0x0C000)     ///< FMC register base address
#define EBI_BASE              (AHBPERIPH_BASE + 0x10000)     ///< EBI register base address

/*@}*/ /* end of group NANO100_PERIPHERAL_MEM_MAP */


/** @addtogroup NANO100_PERIPHERAL_DECLARATION NANO100 Peripheral Declaration
  The Declaration of NANO100 Series Peripheral
  @{
 */
#define WDT                   ((WDT_T *) WDT_BASE)              ///< Pointer to WDT register structure
#define WWDT                  ((WWDT_T *) WWDT_BASE)            ///< Pointer to WWDT register structure
#define RTC                   ((RTC_T *) RTC_BASE)              ///< Pointer to RTC register structure
#define TIMER0                ((TIMER_T *) TIMER0_BASE)         ///< Pointer to TIMER0 register structure
#define TIMER1                ((TIMER_T *) TIMER1_BASE)         ///< Pointer to TIMER1 register structure
#define TIMER2                ((TIMER_T *) TIMER2_BASE)         ///< Pointer to TIMER2 register structure
#define TIMER3                ((TIMER_T *) TIMER3_BASE)         ///< Pointer to TIMER3 register structure
#define SHADOW                ((SHADOW_T *) SHADOW_BASE)        ///< Pointer to GPIO shadow register structure
#define I2C0                  ((I2C_T *) I2C0_BASE)             ///< Pointer to I2C0 register structure
#define I2C1                  ((I2C_T *) I2C1_BASE)             ///< Pointer to I2C1 register structure
#define SPI0                  ((SPI_T *) SPI0_BASE)             ///< Pointer to SPI0 register structure
#define SPI1                  ((SPI_T *) SPI1_BASE)             ///< Pointer to SPI1 register structure
#define SPI2                  ((SPI_T *) SPI2_BASE)             ///< Pointer to SPI2 register structure
#define PWM0                  ((PWM_T *) PWM0_BASE)             ///< Pointer to PWM0 register structure
#define PWM1                  ((PWM_T *) PWM1_BASE)             ///< Pointer to PWM1 register structure
#define UART0                 ((UART_T *) UART0_BASE)           ///< Pointer to UART0 register structure
#define UART1                 ((UART_T *) UART1_BASE)           ///< Pointer to UART1 register structure
#define LCD                   ((LCD_T *) LCD_BASE)              ///< Pointer to LCD register structure
#define ADC                   ((ADC_T *) ADC_BASE)              ///< Pointer to ADC register structure
#define SC0                   ((SC_T *) SC0_BASE)               ///< Pointer to SC0 register structure
#define SC1                   ((SC_T *) SC1_BASE)               ///< Pointer to SC1 register structure
#define SC2                   ((SC_T *) SC2_BASE)               ///< Pointer to SC2 register structure
#define USBD                  ((USBD_T *) USBD_BASE)            ///< Pointer to USBD register structure
#define I2S                   ((I2S_T *) I2S_BASE)              ///< Pointer to I2S register structure

#define SYS                   ((GCR_T *) GCR_BASE)
#define CLK                   ((CLK_T *) CLK_BASE)
#define INTID                 ((INTID_T *) INTID_BASE)
#define PA                    ((GPIO_T *) GPIOA_BASE)           ///< Pointer to GPIO port A register structure
#define PB                    ((GPIO_T *) GPIOB_BASE)           ///< Pointer to GPIO port B register structure
#define PC                    ((GPIO_T *) GPIOC_BASE)           ///< Pointer to GPIO port C register structure
#define PD                    ((GPIO_T *) GPIOD_BASE)           ///< Pointer to GPIO port D register structure
#define PE                    ((GPIO_T *) GPIOE_BASE)           ///< Pointer to GPIO port E register structure
#define PF                    ((GPIO_T *) GPIOF_BASE)           ///< Pointer to GPIO port F register structure
#define GPIO                  ((GPIODBNCE_T *) GPIODBNCE_BASE)  ///< Pointer to GPIO debounce register structure
#define VDMA                  ((VDMA_T *) VDMA_BASE)            ///< Pointer to VDMA register structure
#define PDMA1                 ((PDMA_T *) PDMA1_BASE)           ///< Pointer to PDMA1 register structure
#define PDMA2                 ((PDMA_T *) PDMA2_BASE)           ///< Pointer to PDMA2 register structure
#define PDMA3                 ((PDMA_T *) PDMA3_BASE)           ///< Pointer to PDMA3 register structure
#define PDMA4                 ((PDMA_T *) PDMA4_BASE)           ///< Pointer to PDMA4 register structure
#define PDMA5                 ((PDMA_T *) PDMA5_BASE)           ///< Pointer to PDMA5 register structure
#define PDMA6                 ((PDMA_T *) PDMA6_BASE)           ///< Pointer to PDMA6 register structure
#define PDMACRC               ((PDMACRC_T *) PDMACRC_BASE)      ///< Pointer to PDMA CRC register structure
#define PDMAGCR               ((PDMAGCR_T *) PDMAGCR_BASE)      ///< Pointer to PDMA global control register structure
#define FMC                   ((FMC_T *) FMC_BASE)              ///< Pointer to FMC register structure
#define EBI                   ((EBI_T *) EBI_BASE)              ///< Pointer to EBI register structure

/*@}*/ /* end of group NANO100_PERIPHERAL_DECLARATION */

/*@}*/ /* end of group NANO100_Peripherals */

/** @addtogroup NANO100_IO_ROUTINE NANO100 I/O routines
  The Declaration of NANO100 I/O routines
  @{
 */

typedef volatile unsigned char  vu8;        ///< Define 8-bit unsigned volatile data type
typedef volatile unsigned short vu16;       ///< Define 16-bit unsigned volatile data type
typedef volatile unsigned long  vu32;       ///< Define 32-bit unsigned volatile data type

/**
  * @brief Get a 8-bit unsigned value from specified address
  * @param[in] addr Address to get 8-bit data from
  * @return  8-bit unsigned value stored in specified address
  */
#define M8(addr)  (*((vu8  *) (addr)))

/**
  * @brief Get a 16-bit unsigned value from specified address
  * @param[in] addr Address to get 16-bit data from
  * @return  16-bit unsigned value stored in specified address
  * @note The input address must be 16-bit aligned
  */
#define M16(addr) (*((vu16 *) (addr)))

/**
  * @brief Get a 32-bit unsigned value from specified address
  * @param[in] addr Address to get 32-bit data from
  * @return  32-bit unsigned value stored in specified address
  * @note The input address must be 32-bit aligned
  */
#define M32(addr) (*((vu32 *) (addr)))

/**
  * @brief Set a 32-bit unsigned value to specified I/O port
  * @param[in] port Port address to set 32-bit data
  * @param[in] value Value to write to I/O port
  * @return  None
  * @note The output port must be 32-bit aligned
  */
#define outpw(port,value)     *((volatile unsigned int *)(port)) = value

/**
  * @brief Get a 32-bit unsigned value from specified I/O port
  * @param[in] port Port address to get 32-bit data from
  * @return  32-bit unsigned value stored in specified I/O port
  * @note The input port must be 32-bit aligned
  */
#define inpw(port)            (*((volatile unsigned int *)(port)))

/**
  * @brief Set a 16-bit unsigned value to specified I/O port
  * @param[in] port Port address to set 16-bit data
  * @param[in] value Value to write to I/O port
  * @return  None
  * @note The output port must be 16-bit aligned
  */
#define outps(port,value)     *((volatile unsigned short *)(port)) = value

/**
  * @brief Get a 16-bit unsigned value from specified I/O port
  * @param[in] port Port address to get 16-bit data from
  * @return  16-bit unsigned value stored in specified I/O port
  * @note The input port must be 16-bit aligned
  */
#define inps(port)            (*((volatile unsigned short *)(port)))

/**
  * @brief Set a 8-bit unsigned value to specified I/O port
  * @param[in] port Port address to set 8-bit data
  * @param[in] value Value to write to I/O port
  * @return  None
  */
#define outpb(port,value)     *((volatile unsigned char *)(port)) = value

/**
  * @brief Get a 8-bit unsigned value from specified I/O port
  * @param[in] port Port address to get 8-bit data from
  * @return  8-bit unsigned value stored in specified I/O port
  */
#define inpb(port)            (*((volatile unsigned char *)(port)))

/**
  * @brief Set a 32-bit unsigned value to specified I/O port
  * @param[in] port Port address to set 32-bit data
  * @param[in] value Value to write to I/O port
  * @return  None
  * @note The output port must be 32-bit aligned
  */
#define outp32(port,value)    *((volatile unsigned int *)(port)) = value

/**
  * @brief Get a 32-bit unsigned value from specified I/O port
  * @param[in] port Port address to get 32-bit data from
  * @return  32-bit unsigned value stored in specified I/O port
  * @note The input port must be 32-bit aligned
  */
#define inp32(port)           (*((volatile unsigned int *)(port)))

/**
  * @brief Set a 16-bit unsigned value to specified I/O port
  * @param[in] port Port address to set 16-bit data
  * @param[in] value Value to write to I/O port
  * @return  None
  * @note The output port must be 16-bit aligned
  */
#define outp16(port,value)    *((volatile unsigned short *)(port)) = value

/**
  * @brief Get a 16-bit unsigned value from specified I/O port
  * @param[in] port Port address to get 16-bit data from
  * @return  16-bit unsigned value stored in specified I/O port
  * @note The input port must be 16-bit aligned
  */
#define inp16(port)           (*((volatile unsigned short *)(port)))

/**
  * @brief Set a 8-bit unsigned value to specified I/O port
  * @param[in] port Port address to set 8-bit data
  * @param[in] value Value to write to I/O port
  * @return  None
  */
#define outp8(port,value)     *((volatile unsigned char *)(port)) = value

/**
  * @brief Get a 8-bit unsigned value from specified I/O port
  * @param[in] port Port address to get 8-bit data from
  * @return  8-bit unsigned value stored in specified I/O port
  */
#define inp8(port)            (*((volatile unsigned char *)(port)))

/*@}*/ /* end of group NANO100_IO_ROUTINE */

/******************************************************************************/
/*                Legacy Constants                                            */
/******************************************************************************/
/** @addtogroup NANO100_legacy_Constants NANO100 Legacy Constants
  NANO100 Legacy Constants
  @{
*/

#ifndef NULL
#define NULL           (0)      ///< NULL pointer
#endif

#define TRUE           (1)      ///< Boolean true, define to use in API parameters or return value
#define FALSE          (0)      ///< Boolean false, define to use in API parameters or return value

#define ENABLE         (1)      ///< Enable, define to use in API parameters
#define DISABLE        (0)      ///< Disable, define to use in API parameters

/* Define one bit mask */
#define BIT0     (0x00000001)       ///< Bit 0 mask of an 32 bit integer
#define BIT1     (0x00000002)       ///< Bit 1 mask of an 32 bit integer
#define BIT2     (0x00000004)       ///< Bit 2 mask of an 32 bit integer
#define BIT3     (0x00000008)       ///< Bit 3 mask of an 32 bit integer
#define BIT4     (0x00000010)       ///< Bit 4 mask of an 32 bit integer
#define BIT5     (0x00000020)       ///< Bit 5 mask of an 32 bit integer
#define BIT6     (0x00000040)       ///< Bit 6 mask of an 32 bit integer
#define BIT7     (0x00000080)       ///< Bit 7 mask of an 32 bit integer
#define BIT8     (0x00000100)       ///< Bit 8 mask of an 32 bit integer
#define BIT9     (0x00000200)       ///< Bit 9 mask of an 32 bit integer
#define BIT10    (0x00000400)       ///< Bit 10 mask of an 32 bit integer
#define BIT11    (0x00000800)       ///< Bit 11 mask of an 32 bit integer
#define BIT12    (0x00001000)       ///< Bit 12 mask of an 32 bit integer
#define BIT13    (0x00002000)       ///< Bit 13 mask of an 32 bit integer
#define BIT14    (0x00004000)       ///< Bit 14 mask of an 32 bit integer
#define BIT15    (0x00008000)       ///< Bit 15 mask of an 32 bit integer
#define BIT16    (0x00010000)       ///< Bit 16 mask of an 32 bit integer
#define BIT17    (0x00020000)       ///< Bit 17 mask of an 32 bit integer
#define BIT18    (0x00040000)       ///< Bit 18 mask of an 32 bit integer
#define BIT19    (0x00080000)       ///< Bit 19 mask of an 32 bit integer
#define BIT20    (0x00100000)       ///< Bit 20 mask of an 32 bit integer
#define BIT21    (0x00200000)       ///< Bit 21 mask of an 32 bit integer
#define BIT22    (0x00400000)       ///< Bit 22 mask of an 32 bit integer
#define BIT23    (0x00800000)       ///< Bit 23 mask of an 32 bit integer
#define BIT24    (0x01000000)       ///< Bit 24 mask of an 32 bit integer
#define BIT25    (0x02000000)       ///< Bit 25 mask of an 32 bit integer
#define BIT26    (0x04000000)       ///< Bit 26 mask of an 32 bit integer
#define BIT27    (0x08000000)       ///< Bit 27 mask of an 32 bit integer
#define BIT28    (0x10000000)       ///< Bit 28 mask of an 32 bit integer
#define BIT29    (0x20000000)       ///< Bit 29 mask of an 32 bit integer
#define BIT30    (0x40000000)       ///< Bit 30 mask of an 32 bit integer
#define BIT31    (0x80000000)       ///< Bit 31 mask of an 32 bit integer

/* Byte Mask Definitions */
#define BYTE0_Msk              (0x000000FF)         ///< Mask to get bit0~bit7 from a 32 bit integer
#define BYTE1_Msk              (0x0000FF00)         ///< Mask to get bit8~bit15 from a 32 bit integer
#define BYTE2_Msk              (0x00FF0000)         ///< Mask to get bit16~bit23 from a 32 bit integer
#define BYTE3_Msk              (0xFF000000)         ///< Mask to get bit24~bit31 from a 32 bit integer

#define GET_BYTE0(u32Param)    ((u32Param & BYTE0_Msk)      )  /*!< Extract Byte 0 (Bit  0~ 7) from parameter u32Param */
#define GET_BYTE1(u32Param)    ((u32Param & BYTE1_Msk) >>  8)  /*!< Extract Byte 1 (Bit  8~15) from parameter u32Param */
#define GET_BYTE2(u32Param)    ((u32Param & BYTE2_Msk) >> 16)  /*!< Extract Byte 2 (Bit 16~23) from parameter u32Param */
#define GET_BYTE3(u32Param)    ((u32Param & BYTE3_Msk) >> 24)  /*!< Extract Byte 3 (Bit 24~31) from parameter u32Param */

/*@}*/ /* end of group NANO100_legacy_Constants */

/*@}*/ /* end of group NANO100_Definitions */

#ifdef __cplusplus
}
#endif


/******************************************************************************/
/*                         Peripheral header files                            */
/******************************************************************************/
#include "sys.h"
#include "clk.h"
#include "adc.h"
#include "fmc.h"
#include "ebi.h"
#include "gpio.h"
#include "i2c.h"
#include "crc.h"
#include "pdma.h"
#include "pwm.h"
#include "rtc.h"
#include "sc.h"
#include "scuart.h"
#include "_spi.h"
#include "timer.h"
#include "uart.h"
#include "usbd.h"
#include "wdt.h"
#include "wwdt.h"
#include "i2s.h"

#endif  // __NANO100SERIES_H__

/*** (C) COPYRIGHT 2014 Nuvoton Technology Corp. ***/

