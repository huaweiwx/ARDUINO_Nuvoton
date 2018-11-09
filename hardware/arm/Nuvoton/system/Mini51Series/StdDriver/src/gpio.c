/**************************************************************************//**
 * @file     gpio.c
 * @version  V1.00
 * $Revision: 6 $
 * $Date: 14/01/15 10:47a $ 
 * @brief    MINI51 series GPIO driver source file
 *
 * @note
 * Copyright (C) 2013 Nuvoton Technology Corp. All rights reserved.
*****************************************************************************/ 
#include "mini51series.h"



/** @addtogroup MINI51_Device_Driver MINI51 Device Driver
  @{
*/

/** @addtogroup MINI51_GPIO_Driver GPIO Driver
  @{
*/


/** @addtogroup MINI51_GPIO_EXPORTED_FUNCTIONS GPIO Exported Functions
  @{
*/

/**
 * @brief       Set GPIO operation mode
 *
 * @param[in]   gpio        GPIO port. It could be P0, P1, P2, P3, P4 or P5.
 * @param[in]   u32PinMask  The single or multiple pins of specified GPIO port. BIT0, BIT1, BIT2,.. BIT7
 * @param[in]   u32Mode     Operation mode. GPIO_PMD_INPUT, GPIO_PMD_OUTPUT, GPIO_PMD_OPEN_DRAIN, GPIO_PMD_QUASI
 *
 * @return      None
 *
 * @details     This function is used to set specified GPIO operation mode.
 */
void GPIO_SetMode(GPIO_T *gpio, uint32_t u32PinMask, uint32_t u32Mode)
{
    uint32_t i;

    for (i=0; i<GPIO_PIN_MAX; i++)
    {
        if (u32PinMask & (1 << i))
        {
            gpio->PMD = (gpio->PMD & ~(0x3 << (i << 1))) | (u32Mode << (i << 1));
        }
    }
}

/**
 * @brief       Enable GPIO interrupt
 *
 * @param[in]   gpio            GPIO port. It could be P0, P1, P2, P3, P4 or P5.
 * @param[in]   u32Pin          The pin of specified GPIO port. It could be 0 ~ 7.
 * @param[in]   u32IntAttribs   The interrupt attribute of specified GPIO pin. It could be \n
 *                              GPIO_INT_RISING, GPIO_INT_FALLING, GPIO_INT_BOTH_EDGE, GPIO_INT_HIGH, GPIO_INT_LOW.
 *
 * @return      None
 *
 * @details     This function is used to enable specified GPIO pin interrupt.
 */
void GPIO_EnableInt(GPIO_T *gpio, uint32_t u32Pin, uint32_t u32IntAttribs)
{
    gpio->IMD |= (((u32IntAttribs >> 24) & 0xFFUL) << u32Pin);
    gpio->IEN |= ((u32IntAttribs & 0xFFFFFFUL) << u32Pin);
}


/**
 * @brief       Disable GPIO interrupt
 *
 * @param[in]   gpio        GPIO port. It could be P0, P1, P2, P3, P4 or P5.
 * @param[in]   u32Pin      The pin of specified GPIO port. It could be 0 ~ 7.
 *
 * @return      None
 *
 * @details     This function is used to enable specified GPIO pin interrupt.
 */
void GPIO_DisableInt(GPIO_T *gpio, uint32_t u32Pin)
{
    gpio->IMD &= ~(1UL << u32Pin);
    gpio->IEN &= ~((0x00010001UL) << u32Pin);
}



/*@}*/ /* end of group MINI51_GPIO_EXPORTED_FUNCTIONS */

/*@}*/ /* end of group MINI51_GPIO_Driver */

/*@}*/ /* end of group MINI51_Device_Driver */

/*** (C) COPYRIGHT 2013 Nuvoton Technology Corp. ***/
