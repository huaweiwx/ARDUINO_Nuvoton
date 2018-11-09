/**************************************************************************//**
 * @file     sys.c
 * @version  V1.00
 * $Revision: 2 $
 * $Date: 14/01/10 11:40a $
 * @brief    NANO100 series SYS driver source file
 *
 * @note
 * Copyright (C) 2013 Nuvoton Technology Corp. All rights reserved.
*****************************************************************************/

#include "Nano100Series.h"
/** @addtogroup NANO100_Device_Driver NANO100 Device Driver
  @{
*/

/** @addtogroup NANO100_SYS_Driver SYS Driver
  @{
*/


/** @addtogroup NANO100_SYS_EXPORTED_FUNCTIONS SYS Exported Functions
  @{
*/

/**
  * @brief  This function clear the selected system reset source
  * @param  u32Src is system reset source
  * @return None
  */
void SYS_ClearResetSrc(uint32_t u32Src)
{
    SYS->RST_SRC |= u32Src;
}

/**
  * @brief  This function get Brown-out detector output status
  * @return 0: System voltage is higher than BOD_VL setting or BOD_EN is 0.
  *         1: System voltage is lower than BOD_VL setting.
  *         Note : If the BOD_EN is 0, this function always return 0.
  */
uint32_t SYS_GetBODStatus()
{
    return (SYS->BODSTS);
}

/**
  * @brief  This function get the system reset source register value
  * @return Reset source
  */
uint32_t SYS_GetResetSrc(void)
{
    return (SYS->RST_SRC);
}

/**
  * @brief  This function check register write-protection bit setting
  * @return 0: Write-protection function is disabled.
  *         1: Write-protection function is enabled.
  */
uint32_t SYS_IsRegLocked(void)
{
    return (SYS->RegLockAddr & SYS_RegLockAddr_RegUnLock_Msk);
}

/**
  * @brief  This function enable register write-protection function
  * @return None
  * @details To lock the protected register to forbid write access
  */
void SYS_LockReg(void)
{
    SYS->RegLockAddr = 0;
}


/**
  * @brief  This function disable register write-protection function
  * @return None
  * @details To unlock the protected register to allow write access
  */
void SYS_UnlockReg(void)
{
    while(SYS->RegLockAddr != SYS_RegLockAddr_RegUnLock_Msk) {
        SYS->RegLockAddr = 0x59;
        SYS->RegLockAddr = 0x16;
        SYS->RegLockAddr = 0x88;
    }
}

/**
  * @brief  This function get product ID.
  * @return Product ID
  */
uint32_t  SYS_ReadPDID(void)
{
    return SYS->PDID;
}

/**
  * @brief  This function reset chip.
  * @return None
  */
void SYS_ResetChip(void)
{
    SYS->IPRST_CTL1 |= SYS_IPRST_CTL1_CHIP_RST_Msk;
}

/**
  * @brief  This function reset CPU.
  * @return None
  */
void SYS_ResetCPU(void)
{
    SYS->IPRST_CTL1 |= SYS_IPRST_CTL1_CPU_RST_Msk;
}

/**
  * @brief  This function reset selected modules.
  * @param  u32ModuleIndex is module index. Including :
  *          - \ref CHIP_RST
  *          - \ref CPU_RST
  *          - \ref DMA_RST
  *          - \ref EBI_RST
  *          - \ref SC1_RST
  *          - \ref SC0_RST
  *          - \ref I2S_RST
  *          - \ref ADC_RST
  *          - \ref USBD_RST
  *          - \ref DAC_RST
  *          - \ref PWM1_RST
  *          - \ref PWM0_RST
  *          - \ref UART1_RST
  *          - \ref UART0_RST
  *          - \ref SPI2_RST
  *          - \ref SPI1_RST
  *          - \ref SPI0_RST
  *          - \ref I2C1_RST
  *          - \ref I2C0_RST
  *          - \ref TMR3_RST
  *          - \ref TMR2_RST
  *          - \ref TMR1_RST
  *          - \ref TMR0_RST
  *          - \ref GPIO_RST
  * @return None
  */
void SYS_ResetModule(uint32_t u32ModuleIndex)
{
    *(volatile uint32_t *)((uint32_t)&(SYS->IPRST_CTL1) + (u32ModuleIndex>>24)) |= 1<<(u32ModuleIndex & 0x00ffffff);
    *(volatile uint32_t *)((uint32_t)&(SYS->IPRST_CTL1) + (u32ModuleIndex>>24)) &= ~(1<<(u32ModuleIndex & 0x00ffffff));
}

/**
  * @brief  This function configure BOD function.
  *         Configure BOD reset or interrupt mode and set Brown-out voltage level.
  *         Enable Brown-out function
  * @param  i32Mode is reset or interrupt mode. Including :
  *         - \ref SYS_BODCTL_BOD25_RST_EN_Msk or  \ref SYS_BODCTL_BOD25_INT_EN_Msk
  *         - \ref SYS_BODCTL_BOD20_RST_EN_Msk or  \ref SYS_BODCTL_BOD20_INT_EN_Msk
  *         - \ref SYS_BODCTL_BOD17_RST_EN_Msk or  \ref SYS_BODCTL_BOD17_INT_EN_Msk
  * @param  u32BODLevel is Brown-out voltage level. Including :
  *         - \ref SYS_BODCTL_BOD25_EN_Msk
  *         - \ref SYS_BODCTL_BOD20_EN_Msk
  *         - \ref SYS_BODCTL_BOD17_EN_Msk
  *
  * @return None
  */
void SYS_EnableBOD(int32_t i32Mode, uint32_t u32BODLevel)
{
    SYS->BODCTL = (SYS->BODCTL & ~0xFFF) | (i32Mode | u32BODLevel);
}

/**
  * @brief  This function disable BOD function.
  * @return None
  */
void SYS_DisableBOD(void)
{
    SYS->BODCTL = SYS->BODCTL & ~(SYS_BODCTL_BOD25_EN_Msk | SYS_BODCTL_BOD20_EN_Msk | SYS_BODCTL_BOD17_EN_Msk);
}



/*@}*/ /* end of group NANO100_SYS_EXPORTED_FUNCTIONS */

/*@}*/ /* end of group NANO100_SYS_Driver */

/*@}*/ /* end of group NANO100_Device_Driver */

/*** (C) COPYRIGHT 2013 Nuvoton Technology Corp. ***/
