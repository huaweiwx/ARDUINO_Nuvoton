/* ***************************************************************************
 * @file     M483KIDAE(LQFP128)
 * @version  V1.00
 * @Date     2018/10/19-20:44:46 
 * @brief    arduino pin descriptions file
 * Copyright (C) 2018 huaweiwx@sina.com.
*****************************************************************************/

#ifndef _CHIP128_PINLIST_H_
#define _CHIP128_PINLIST_H_

#if USE_ICE >0
  #define CHIP_PIN_LIST \
  PIN(B,5 ,1   ), /* EADC0_CH5/ACMP1_N/EBI_ADR0/SD0_DAT3/EMAC_RMII_REFCLK/SPI1_MISO/I2C0_SCL/UART5_TXD/USCI1_CTL0/SC0_CLK/I2S0_BCLK/EPWM0_CH0/TM0/INT0                  */\
  PIN(B,4 ,2   ), /* EADC0_CH4/ACMP1_P1/EBI_ADR1/SD0_DAT2/EMAC_RMII_RXD0/SPI1_MOSI/I2C0_SDA/UART5_RXD/USCI1_CTL1/SC0_DAT/I2S0_MCLK/EPWM0_CH1/TM1/INT1                   */\
  PIN(B,3 ,3   ), /* EADC0_CH3/ACMP0_N/EBI_ADR2/SD0_DAT1/EMAC_RMII_RXD1/SPI1_CLK/UART1_TXD/UART5_nRTS/USCI1_DAT1/SC0_RST/I2S0_DI/EPWM0_CH2/TM2/INT2                     */\
  PIN(B,2 ,4   ), /* EADC0_CH2/ACMP0_P1/OPA0_O/EBI_ADR3/SD0_DAT0/EMAC_RMII_CRSDV/SPI1_SS/UART1_RXD/UART5_nCTS/USCI1_DAT0/SC0_PWR/I2S0_DO/EPWM0_CH3/TM3/INT3             */\
  PIN(C,12,5   ), /* EBI_ADR4/UART0_TXD/I2C0_SCL/SPI3_MISO/SC0_nCD/ECAP1_IC2/EPWM1_CH0/ACMP0_O                                                                          */\
  PIN(C,11,6   ), /* EBI_ADR5/UART0_RXD/I2C0_SDA/SPI3_MOSI/ECAP1_IC1/EPWM1_CH1/ACMP1_O                                                                                  */\
  PIN(C,10,7   ), /* EBI_ADR6/SPI3_CLK/UART3_TXD/CAN1_TXD/ECAP1_IC0/EPWM1_CH2                                                                                           */\
  PIN(C,9 ,8   ), /* EBI_ADR7/SPI3_SS/UART3_RXD/CAN1_RXD/EPWM1_CH3                                                                                                      */\
  PIN(B,1 ,9   ), /* EADC0_CH1/OPA0_N/EBI_ADR8/SD0_CLK/EMAC_RMII_RXERR/SPI1_I2SMCLK/SPI3_I2SMCLK/UART2_TXD/USCI1_CLK/I2C1_SCL/I2S0_LRCK/EPWM0_CH4/EPWM1_CH4/EPWM0_BRAKE0*/\
  PIN(B,0 ,10  ), /* EADC0_CH0/OPA0_P/EBI_ADR9/SD0_CMD/UART2_RXD/SPI0_I2SMCLK/I2C1_SDA/EPWM0_CH5/EPWM1_CH5/EPWM0_BRAKE1                                                 */\
       /*   11    VSS                                                                                                                                                   */\
       /*   12    VDD                                                                                                                                                   */\
  PIN(A,11,13  ), /* ACMP0_P0/EBI_nRD/SC2_PWR/SPI2_SS/SD1_DAT3/USCI0_CLK/I2C2_SCL/BPWM0_CH0/EPWM0_SYNC_OUT/TM0_EXT/DAC1_ST                                              */\
  PIN(A,10,14  ), /* ACMP1_P0/OPA1_O/EBI_nWR/SC2_RST/SPI2_CLK/SD1_DAT2/USCI0_DAT0/I2C2_SDA/BPWM0_CH1/QEI1_INDEX/ECAP0_IC0/TM1_EXT/DAC0_ST                               */\
  PIN(A,9 ,15  ), /* OPA1_N/EBI_MCLK/SC2_DAT/SPI2_MISO/SD1_DAT1/USCI0_DAT1/UART1_TXD/BPWM0_CH2/QEI1_A/ECAP0_IC1/TM2_EXT                                                 */\
  PIN(A,8 ,16  ), /* OPA1_P/EBI_ALE/SC2_CLK/SPI2_MOSI/SD1_DAT0/USCI0_CTL1/UART1_RXD/BPWM0_CH3/QEI1_B/ECAP0_IC2/TM3_EXT/INT4                                             */\
  PIN(C,13,17  ), /* EBI_ADR10/SC2_nCD/SPI2_I2SMCLK/CAN1_TXD/USCI0_CTL0/UART2_TXD/BPWM0_CH4/CLKO/EADC0_ST                                                               */\
  PIN(D,12,18  ), /* OPA2_O/EBI_nCS0/CAN1_RXD/UART2_RXD/BPWM0_CH5/QEI0_INDEX/CLKO/EADC0_ST/INT5                                                                         */\
  PIN(D,11,19  ), /* OPA2_N/EBI_nCS1/UART1_TXD/CAN0_TXD/QEI0_A/INT6                                                                                                     */\
  PIN(D,10,20  ), /* OPA2_P/EBI_nCS2/UART1_RXD/CAN0_RXD/QEI0_B/INT7                                                                                                     */\
  PIN(G,2 ,21  ), /* EBI_ADR11/SPI2_SS/I2C0_SMBAL/I2C1_SCL/TM0                                                                                                          */\
  PIN(G,3 ,22  ), /* EBI_ADR12/SPI2_CLK/I2C0_SMBSUS/I2C1_SDA/TM1                                                                                                        */\
  PIN(G,4 ,23  ), /* EBI_ADR13/SPI2_MISO/TM2                                                                                                                            */\
  PIN(F,11,24  ), /* EBI_ADR14/SPI2_MOSI/TAMPER5/TM3                                                                                                                    */\
  PIN(F,10,25  ), /* EBI_ADR15/SC0_nCD/I2S0_BCLK/SPI0_I2SMCLK/TAMPER4                                                                                                   */\
  PIN(F,9 ,26  ), /* EBI_ADR16/SC0_PWR/I2S0_MCLK/SPI0_SS/TAMPER3                                                                                                        */\
  PIN(F,8 ,27  ), /* EBI_ADR17/SC0_RST/I2S0_DI/SPI0_CLK/TAMPER2                                                                                                         */\
  PIN(F,7 ,28  ), /* EBI_ADR18/SC0_DAT/I2S0_DO/SPI0_MISO/UART4_TXD/TAMPER1                                                                                              */\
  PIN(F,6 ,29  ), /* EBI_ADR19/SC0_CLK/I2S0_LRCK/SPI0_MOSI/UART4_RXD/EBI_nCS0/TAMPER0                                                                                   */\
       /*   30       VDD                                                                                                                                                */\
  PIN(F,5 ,31  ), /* UART2_RXD/UART2_nCTS/BPWM0_CH4/EPWM0_SYNC_OUT/X32_IN/EADC0_ST                                                                                      */\
  PIN(F,4 ,32  ), /* UART2_TXD/UART2_nRTS/BPWM0_CH5/X32_OUT                                                                                                             */\
  PIN(H,4 ,33  ), /* EBI_ADR3/SPI1_MISO                                                                                                                                 */\
  PIN(H,5 ,34  ), /* EBI_ADR2/SPI1_MOSI                                                                                                                                 */\
  PIN(H,6 ,35  ), /* EBI_ADR1/SPI1_CLK                                                                                                                                  */\
  PIN(H,7 ,36  ), /* EBI_ADR0/SPI1_SS                                                                                                                                   */\
  PIN(F,3 ,37  ), /* EBI_nCS0/UART0_TXD/I2C0_SCL/XT1_IN/BPWM1_CH0                                                                                                       */\
  PIN(F,2 ,38  ), /* EBI_nCS1/UART0_RXD/I2C0_SDA/QSPI0_CLK/XT1_OUT/BPWM1_CH1                                                                                            */\
       /*  39        VSS                                                                                                                                               */\
       /*  40        VDD                                                                                                                                               */\
  PIN(E,8 ,41  ), /* EBI_ADR10/EMAC_RMII_MDC/I2S0_BCLK/SPI2_CLK/USCI1_CTL1/UART2_TXD/EPWM0_CH0/EPWM0_BRAKE0/ECAP0_IC0/TRACE_DATA3                                       */\
  PIN(E,9 ,42  ), /* EBI_ADR11/EMAC_RMII_MDIO/I2S0_MCLK/SPI2_MISO/USCI1_CTL0/UART2_RXD/EPWM0_CH1/EPWM0_BRAKE1/ECAP0_IC1/TRACE_DATA2                                     */\
  PIN(E,10,43  ), /* EBI_ADR12/EMAC_RMII_TXD0/I2S0_DI/SPI2_MOSI/USCI1_DAT0/UART3_TXD/EPWM0_CH2/EPWM1_BRAKE0/ECAP0_IC2/TRACE_DATA1                                       */\
  PIN(E,11,44  ), /* EBI_ADR13/EMAC_RMII_TXD1/I2S0_DO/SPI2_SS/USCI1_DAT1/UART3_RXD/UART1_nCTS/EPWM0_CH3/EPWM1_BRAKE1/ECAP1_IC2/TRACE_DATA0                              */\
  PIN(E,12,45  ), /* EBI_ADR14/EMAC_RMII_TXEN/I2S0_LRCK/SPI2_I2SMCLK/USCI1_CLK/UART1_nRTS/EPWM0_CH4/ECAP1_IC1/TRACE_CLK                                                 */\
  PIN(E,13,46  ), /* EBI_ADR15/EMAC_PPS/I2C0_SCL/UART4_nRTS/UART1_TXD/EPWM0_CH5/EPWM1_CH0/BPWM1_CH5/ECAP1_IC0                                                           */\
  PIN(C,8 ,47  ), /* EBI_ADR16/EMAC_RMII_REFCLK/I2C0_SDA/UART4_nCTS/UART1_RXD/EPWM1_CH1/BPWM1_CH4                                                                       */\
  PIN(C,7 ,48  ), /* EBI_AD9/EMAC_RMII_RXD0/SPI1_MISO/UART4_TXD/SC2_PWR/UART0_nCTS/I2C1_SMBAL/EPWM1_CH2/BPWM1_CH0/TM0/INT3                                              */\
  PIN(C,6 ,49  ), /* EBI_AD8/EMAC_RMII_RXD1/SPI1_MOSI/UART4_RXD/SC2_RST/UART0_nRTS/I2C1_SMBSUS/EPWM1_CH3/BPWM1_CH1/TM1/INT2                                             */\
  PIN(A,7 ,50  ), /* EBI_AD7/EMAC_RMII_CRSDV/SPI1_CLK/SC2_DAT/UART0_TXD/I2C1_SCL/EPWM1_CH4/BPWM1_CH2/ACMP0_WLAT/TM2/INT1                                                */\
  PIN(A,6 ,51  ), /* EBI_AD6/EMAC_RMII_RXERR/SPI1_SS/SD1_nCD/SC2_CLK/UART0_RXD/I2C1_SDA/EPWM1_CH5/BPWM1_CH3/ACMP1_WLAT/TM3/INT0                                         */\
       /*  52        VSS                                                                                                                                                */\
       /*  53        VDD                                                                                                                                                */\
       /*  54        LDO_CAP                                                                                                                                            */\
  PIN(A,5 ,55  ), /* SPIM_D2/QSPI0_MISO1/SPI1_I2SMCLK/SD1_CMD/SC2_nCD/UART0_nCTS/UART5_TXD/I2C0_SCL/CAN0_TXD/BPWM0_CH5/EPWM0_CH0/QEI0_INDEX                             */\
  PIN(A,4 ,56  ), /* SPIM_D3/QSPI0_MOSI1/SPI0_I2SMCLK/SD1_CLK/SC0_nCD/UART0_nRTS/UART5_RXD/I2C0_SDA/CAN0_RXD/BPWM0_CH4/EPWM0_CH1/QEI0_A                                 */\
  PIN(A,3 ,57  ), /* SPIM_SS/QSPI0_SS/SPI0_SS/SD1_DAT3/SC0_PWR/UART4_TXD/UART1_TXD/I2C1_SCL/BPWM0_CH3/EPWM0_CH2/QEI0_B                                                  */\
  PIN(A,2 ,58  ), /* SPIM_CLK/QSPI0_CLK/SPI0_CLK/SD1_DAT2/SC0_RST/UART4_RXD/UART1_RXD/I2C1_SDA/BPWM0_CH2/EPWM0_CH3                                                      */\
  PIN(A,1 ,59  ), /* SPIM_MISO/QSPI0_MISO0/SPI0_MISO/SD1_DAT1/SC0_DAT/UART0_TXD/UART1_nCTS/I2C2_SCL/BPWM0_CH1/EPWM0_CH4/DAC1_ST                                         */\
  PIN(A,0 ,60  ), /* SPIM_MOSI/QSPI0_MOSI0/SPI0_MOSI/SD1_DAT0/SC0_CLK/UART0_RXD/UART1_nRTS/I2C2_SDA/BPWM0_CH0/EPWM0_CH5/DAC0_ST                                         */\
       /*  61        VDDIO                                                                                                                                              */\
  PIN(E,14,62  ), /* EBI_AD8/UART2_TXD/CAN0_TXD/SD1_nCD                                                                                                                 */\
  PIN(E,15,63  ), /* EBI_AD9/UART2_RXD/CAN0_RXD                                                                                                                         */\
       /*  64        nRESET                                                                                                                                             */\
  /* PIN(F,0 ,65  ), /UART1_TXD/I2C1_SCL/BPWM1_CH0/ICE_DAT                                                                                                              */\
  /* PIN(F,1 ,66  ), /UART1_RXD/I2C1_SDA/BPWM1_CH1/ICE_CLK                                                                                                              */\
  PIN(D,9 ,67  ), /* EBI_AD7/I2C2_SCL/UART2_nCTS                                                                                                                        */\
  PIN(D,8 ,68  ), /* EBI_AD6/I2C2_SDA/UART2_nRTS                                                                                                                        */\
  PIN(C,5 ,69  ), /* EBI_AD5/SPIM_D2/QSPI0_MISO1/UART2_TXD/I2C1_SCL/CAN0_TXD/UART4_TXD/EPWM1_CH0                                                                        */\
  PIN(C,4 ,70  ), /* EBI_AD4/SPIM_D3/QSPI0_MOSI1/SC1_nCD/I2S0_BCLK/SPI1_I2SMCLK/UART2_RXD/I2C1_SDA/CAN0_RXD/UART4_RXD/EPWM1_CH1                                         */\
  PIN(C,3 ,71  ), /* EBI_AD3/SPIM_SS/QSPI0_SS/SC1_PWR/I2S0_MCLK/SPI1_MISO/UART2_nRTS/I2C0_SMBAL/CAN1_TXD/UART3_TXD/EPWM1_CH2                                            */\
  PIN(C,2 ,72  ), /* EBI_AD2/SPIM_CLK/QSPI0_CLK/SC1_RST/I2S0_DI/SPI1_MOSI/UART2_nCTS/I2C0_SMBSUS/CAN1_RXD/UART3_RXD/EPWM1_CH3                                           */\
  PIN(C,1 ,73  ), /* EBI_AD1/SPIM_MISO/QSPI0_MISO0/SC1_DAT/I2S0_DO/SPI1_CLK/UART2_TXD/I2C0_SCL/EPWM1_CH4/ACMP0_O                                                        */\
  PIN(C,0 ,74  ), /* EBI_AD0/SPIM_MOSI/QSPI0_MOSI0/SC1_CLK/I2S0_LRCK/SPI1_SS/UART2_RXD/I2C0_SDA/EPWM1_CH5/ACMP1_O                                                       */\
       /*  75        VSS                                                                                                                                                */\
       /*  76        VDD                                                                                                                                                */\
  PIN(G,9 ,77  ), /* EBI_AD0/SD1_DAT3/SPIM_D2/BPWM0_CH5                                                                                                                 */\
  PIN(G,10,78  ), /* EBI_AD1/SD1_DAT2/SPIM_D3/BPWM0_CH4                                                                                                                 */\
  PIN(G,11,79  ), /* EBI_AD2/SD1_DAT1/SPIM_SS/BPWM0_CH3                                                                                                                 */\
  PIN(G,12,80  ), /* EBI_AD3/SD1_DAT0/SPIM_CLK/BPWM0_CH2                                                                                                                */\
  PIN(G,13,81  ), /* EBI_AD4/SD1_CMD/SPIM_MISO/BPWM0_CH1                                                                                                                */\
  PIN(G,14,82  ), /* EBI_AD5/SD1_CLK/SPIM_MOSI/BPWM0_CH0                                                                                                                */\
  PIN(G,15,83  ), /* SD1_nCD/CLKO/EADC0_ST                                                                                                                              */\
  PIN(D,13,84  ), /* EBI_AD10/SD0_nCD/SPI0_I2SMCLK/SPI1_I2SMCLK/SC2_nCD                                                                                                 */\
  PIN(A,12,85  ), /* I2S0_BCLK/UART4_TXD/I2C1_SCL/SPI2_SS/CAN0_TXD/SC2_PWR/BPWM1_CH2/QEI1_INDEX/USB_VBUS                                                                */\
  PIN(A,13,86  ), /* I2S0_MCLK/UART4_RXD/I2C1_SDA/SPI2_CLK/CAN0_RXD/SC2_RST/BPWM1_CH3/QEI1_A/USB_D-                                                                     */\
  PIN(A,14,87  ), /* I2S0_DI/UART0_TXD/SPI2_MISO/I2C2_SCL/SC2_DAT/BPWM1_CH4/QEI1_B/USB_D+                                                                               */\
  PIN(A,15,88  ), /* I2S0_DO/UART0_RXD/SPI2_MOSI/I2C2_SDA/SC2_CLK/BPWM1_CH5/EPWM0_SYNC_IN/USB_OTG_ID                                                                    */\
       /*  89        HSUSB_VRES                                                                                                                                         */\
       /*  90        HSUSB_VDD33                                                                                                                                        */\
       /*  91        HSUSB_VBUS                                                                                                                                         */\
       /*  92        HSUSB_D-                                                                                                                                           */\
       /*  93        HSUSB_VSS                                                                                                                                          */\
       /*  94        HSUSB_D+                                                                                                                                           */\
       /*  95        HSUSB_VDD12_CAP                                                                                                                                    */\
       /*  96        HSUSB_ID                                                                                                                                           */\
  PIN(E,7 ,97  ), /* SD0_CMD/SPIM_D2/UART5_TXD/CAN1_TXD/QEI1_INDEX/EPWM0_CH0/BPWM0_CH5                                                                                  */\
  PIN(E,6 ,98  ), /* SD0_CLK/SPIM_D3/SPI3_I2SMCLK/SC0_nCD/USCI0_CTL0/UART5_RXD/CAN1_RXD/QEI1_A/EPWM0_CH1/BPWM0_CH4                                                      */\
  PIN(E,5 ,99  ), /* EBI_nRD/SD0_DAT3/SPIM_SS/SPI3_SS/SC0_PWR/USCI0_CTL1/QEI1_B/EPWM0_CH2/BPWM0_CH3                                                                     */\
  PIN(E,4 ,100 ), /* EBI_nWR/SD0_DAT2/SPIM_CLK/SPI3_CLK/SC0_RST/USCI0_DAT1/QEI0_INDEX/EPWM0_CH3/BPWM0_CH2                                                               */\
  PIN(E,3 ,101 ), /* EBI_MCLK/SD0_DAT1/SPIM_MISO/SPI3_MISO/SC0_DAT/USCI0_DAT0/QEI0_A/EPWM0_CH4/BPWM0_CH1                                                                */\
  PIN(E,2 ,102 ), /* EBI_ALE/SD0_DAT0/SPIM_MOSI/SPI3_MOSI/SC0_CLK/USCI0_CLK/QEI0_B/EPWM0_CH5/BPWM0_CH0                                                                  */\
       /*  103       VSS                                                                                                                                                */\
       /*  104       VDD                                                                                                                                                */\
  PIN(E,1 ,105 ), /* EBI_AD10/QSPI0_MISO0/SC2_DAT/I2S0_BCLK/SPI1_MISO/UART3_TXD/I2C1_SCL/UART4_nCTS                                                                     */\
  PIN(E,0 ,106 ), /* EBI_AD11/QSPI0_MOSI0/SC2_CLK/I2S0_MCLK/SPI1_MOSI/UART3_RXD/I2C1_SDA/UART4_nRTS                                                                     */\
  PIN(H,8 ,107 ), /* EBI_AD12/QSPI0_CLK/SC2_PWR/I2S0_DI/SPI1_CLK/UART3_nRTS/I2C1_SMBAL/I2C2_SCL/UART1_TXD                                                               */\
  PIN(H,9 ,108 ), /* EBI_AD13/QSPI0_SS/SC2_RST/I2S0_DO/SPI1_SS/UART3_nCTS/I2C1_SMBSUS/I2C2_SDA/UART1_RXD                                                                */\
  PIN(H,10,109 ), /* EBI_AD14/QSPI0_MISO1/SC2_nCD/I2S0_LRCK/SPI1_I2SMCLK/UART4_TXD/UART0_TXD                                                                            */\
  PIN(H,11,110 ), /* EBI_AD15/QSPI0_MOSI1/UART4_RXD/UART0_RXD/EPWM0_CH5                                                                                                 */\
  PIN(D,14,111 ), /* EBI_nCS0/SPI3_I2SMCLK/SC1_nCD/EPWM0_CH4                                                                                                            */\
       /*  112       VSS                                                                                                                                                 */\
       /*  113       LDO_CAP                                                                                                                                             */\
       /*  114       VDD                                                                                                                                                 */\
  PIN(C,14,115 ), /* EBI_AD11/SC1_nCD/SPI0_I2SMCLK/USCI0_CTL0/QSPI0_CLK/EPWM0_SYNC_IN/TM1/USB_VBUS_ST/HSUSB_VBUS_ST                                                     */\
  PIN(B,15,116 ), /* EADC0_CH15/EBI_AD12/SC1_PWR/SPI0_SS/USCI0_CTL1/UART0_nCTS/UART3_TXD/I2C2_SMBAL/EPWM1_CH0/TM0_EXT/USB_VBUS_EN/HSUSB_VBUS_EN                         */\
  PIN(B,14,117 ), /* EADC0_CH14/EBI_AD13/SC1_RST/SPI0_CLK/USCI0_DAT1/UART0_nRTS/UART3_RXD/I2C2_SMBSUS/EPWM1_CH1/TM1_EXT/CLKO                                            */\
  PIN(B,13,118 ), /* EADC0_CH13/DAC1_OUT/ACMP0_P3/ACMP1_P3/EBI_AD14/SC1_DAT/SPI0_MISO/USCI0_DAT0/UART0_TXD/UART3_nRTS/I2C2_SCL/EPWM1_CH2/TM2_EXT                        */\
  PIN(B,12,119 ), /* EADC0_CH12/DAC0_OUT/ACMP0_P2/ACMP1_P2/EBI_AD15/SC1_CLK/SPI0_MOSI/USCI0_CLK/UART0_RXD/UART3_nCTS/I2C2_SDA/SD0_nCD/EPWM1_CH3/TM3_EXT                 */\
       /*  120      AVDD                                                                                                                                               */\
       /*  121      VREF                                                                                                                                               */\
       /*  122      AVSS                                                                                                                                               */\
  PIN(B,11,123 ), /* EADC0_CH11/EBI_ADR16/EMAC_RMII_MDC/UART0_nCTS/UART4_TXD/I2C1_SCL/CAN0_TXD/SPI0_I2SMCLK/BPWM1_CH0/SPI3_CLK/HSUSB_VBUS_ST                            */\
  PIN(B,10,124 ), /* EADC0_CH10/EBI_ADR17/EMAC_RMII_MDIO/USCI1_CTL0/UART0_nRTS/UART4_RXD/I2C1_SDA/CAN0_RXD/BPWM1_CH1/SPI3_SS/HSUSB_VBUS_EN                              */\
  PIN(B,9 ,125 ), /* EADC0_CH9/EBI_ADR18/EMAC_RMII_TXD0/USCI1_CTL1/UART0_TXD/UART1_nCTS/I2C1_SMBAL/BPWM1_CH2/SPI3_MISO/INT7                                              */\
  PIN(B,8 ,126 ), /* EADC0_CH8/EBI_ADR19/EMAC_RMII_TXD1/USCI1_CLK/UART0_RXD/UART1_nRTS/I2C1_SMBSUS/BPWM1_CH3/SPI3_MOSI/INT6                                              */\
  PIN(B,7 ,127 ), /* EADC0_CH7/EBI_nWRL/EMAC_RMII_TXEN/USCI1_DAT0/CAN1_TXD/UART1_TXD/SD1_CMD/EBI_nCS0/BPWM1_CH4/EPWM1_BRAKE0/EPWM1_CH4/INT5/USB_VBUS_ST/ACMP0_O          */\
  PIN(B,6 ,128 ) /* EADC0_CH6/EBI_nWRH/EMAC_PPS/USCI1_DAT1/CAN1_RXD/UART1_RXD/SD1_CLK/EBI_nCS1/BPWM1_CH5/EPWM1_BRAKE1/EPWM1_CH5/INT4/USB_VBUS_EN/ACMP1_O                */

#else /* used ICE*/
  #define CHIP_PIN_LIST \
  PIN(B,5 ,1   ), /* EADC0_CH5/ACMP1_N/EBI_ADR0/SD0_DAT3/EMAC_RMII_REFCLK/SPI1_MISO/I2C0_SCL/UART5_TXD/USCI1_CTL0/SC0_CLK/I2S0_BCLK/EPWM0_CH0/TM0/INT0                  */\
  PIN(B,4 ,2   ), /* EADC0_CH4/ACMP1_P1/EBI_ADR1/SD0_DAT2/EMAC_RMII_RXD0/SPI1_MOSI/I2C0_SDA/UART5_RXD/USCI1_CTL1/SC0_DAT/I2S0_MCLK/EPWM0_CH1/TM1/INT1                   */\
  PIN(B,3 ,3   ), /* EADC0_CH3/ACMP0_N/EBI_ADR2/SD0_DAT1/EMAC_RMII_RXD1/SPI1_CLK/UART1_TXD/UART5_nRTS/USCI1_DAT1/SC0_RST/I2S0_DI/EPWM0_CH2/TM2/INT2                     */\
  PIN(B,2 ,4   ), /* EADC0_CH2/ACMP0_P1/OPA0_O/EBI_ADR3/SD0_DAT0/EMAC_RMII_CRSDV/SPI1_SS/UART1_RXD/UART5_nCTS/USCI1_DAT0/SC0_PWR/I2S0_DO/EPWM0_CH3/TM3/INT3             */\
  PIN(C,12,5   ), /* EBI_ADR4/UART0_TXD/I2C0_SCL/SPI3_MISO/SC0_nCD/ECAP1_IC2/EPWM1_CH0/ACMP0_O                                                                          */\
  PIN(C,11,6   ), /* EBI_ADR5/UART0_RXD/I2C0_SDA/SPI3_MOSI/ECAP1_IC1/EPWM1_CH1/ACMP1_O                                                                                  */\
  PIN(C,10,7   ), /* EBI_ADR6/SPI3_CLK/UART3_TXD/CAN1_TXD/ECAP1_IC0/EPWM1_CH2                                                                                           */\
  PIN(C,9 ,8   ), /* EBI_ADR7/SPI3_SS/UART3_RXD/CAN1_RXD/EPWM1_CH3                                                                                                      */\
  PIN(B,1 ,9   ), /* EADC0_CH1/OPA0_N/EBI_ADR8/SD0_CLK/EMAC_RMII_RXERR/SPI1_I2SMCLK/SPI3_I2SMCLK/UART2_TXD/USCI1_CLK/I2C1_SCL/I2S0_LRCK/EPWM0_CH4/EPWM1_CH4/EPWM0_BRAKE0*/\
  PIN(B,0 ,10  ), /* EADC0_CH0/OPA0_P/EBI_ADR9/SD0_CMD/UART2_RXD/SPI0_I2SMCLK/I2C1_SDA/EPWM0_CH5/EPWM1_CH5/EPWM0_BRAKE1                                                 */\
       /*   11     VSS                                                                                                                                                      */\
       /*   12      VDD                                                                                                                                                      */\
  PIN(A,11,13  ), /* ACMP0_P0/EBI_nRD/SC2_PWR/SPI2_SS/SD1_DAT3/USCI0_CLK/I2C2_SCL/BPWM0_CH0/EPWM0_SYNC_OUT/TM0_EXT/DAC1_ST                                              */\
  PIN(A,10,14  ), /* ACMP1_P0/OPA1_O/EBI_nWR/SC2_RST/SPI2_CLK/SD1_DAT2/USCI0_DAT0/I2C2_SDA/BPWM0_CH1/QEI1_INDEX/ECAP0_IC0/TM1_EXT/DAC0_ST                               */\
  PIN(A,9 ,15  ), /* OPA1_N/EBI_MCLK/SC2_DAT/SPI2_MISO/SD1_DAT1/USCI0_DAT1/UART1_TXD/BPWM0_CH2/QEI1_A/ECAP0_IC1/TM2_EXT                                                 */\
  PIN(A,8 ,16  ), /* OPA1_P/EBI_ALE/SC2_CLK/SPI2_MOSI/SD1_DAT0/USCI0_CTL1/UART1_RXD/BPWM0_CH3/QEI1_B/ECAP0_IC2/TM3_EXT/INT4                                             */\
  PIN(C,13,17  ), /* EBI_ADR10/SC2_nCD/SPI2_I2SMCLK/CAN1_TXD/USCI0_CTL0/UART2_TXD/BPWM0_CH4/CLKO/EADC0_ST                                                               */\
  PIN(D,12,18  ), /* OPA2_O/EBI_nCS0/CAN1_RXD/UART2_RXD/BPWM0_CH5/QEI0_INDEX/CLKO/EADC0_ST/INT5                                                                         */\
  PIN(D,11,19  ), /* OPA2_N/EBI_nCS1/UART1_TXD/CAN0_TXD/QEI0_A/INT6                                                                                                     */\
  PIN(D,10,20  ), /* OPA2_P/EBI_nCS2/UART1_RXD/CAN0_RXD/QEI0_B/INT7                                                                                                     */\
  PIN(G,2 ,21  ), /* EBI_ADR11/SPI2_SS/I2C0_SMBAL/I2C1_SCL/TM0                                                                                                          */\
  PIN(G,3 ,22  ), /* EBI_ADR12/SPI2_CLK/I2C0_SMBSUS/I2C1_SDA/TM1                                                                                                        */\
  PIN(G,4 ,23  ), /* EBI_ADR13/SPI2_MISO/TM2                                                                                                                            */\
  PIN(F,11,24  ), /* EBI_ADR14/SPI2_MOSI/TAMPER5/TM3                                                                                                                    */\
  PIN(F,10,25  ), /* EBI_ADR15/SC0_nCD/I2S0_BCLK/SPI0_I2SMCLK/TAMPER4                                                                                                   */\
  PIN(F,9 ,26  ), /* EBI_ADR16/SC0_PWR/I2S0_MCLK/SPI0_SS/TAMPER3                                                                                                        */\
  PIN(F,8 ,27  ), /* EBI_ADR17/SC0_RST/I2S0_DI/SPI0_CLK/TAMPER2                                                                                                         */\
  PIN(F,7 ,28  ), /* EBI_ADR18/SC0_DAT/I2S0_DO/SPI0_MISO/UART4_TXD/TAMPER1                                                                                              */\
  PIN(F,6 ,29  ), /* EBI_ADR19/SC0_CLK/I2S0_LRCK/SPI0_MOSI/UART4_RXD/EBI_nCS0/TAMPER0                                                                                   */\
       /*   30     VDD                                                                                                                                                      */\
  PIN(F,5 ,31  ), /* UART2_RXD/UART2_nCTS/BPWM0_CH4/EPWM0_SYNC_OUT/X32_IN/EADC0_ST                                                                                      */\
  PIN(F,4 ,32  ), /* UART2_TXD/UART2_nRTS/BPWM0_CH5/X32_OUT                                                                                                             */\
  PIN(H,4 ,33  ), /* EBI_ADR3/SPI1_MISO                                                                                                                                 */\
  PIN(H,5 ,34  ), /* EBI_ADR2/SPI1_MOSI                                                                                                                                 */\
  PIN(H,6 ,35  ), /* EBI_ADR1/SPI1_CLK                                                                                                                                  */\
  PIN(H,7 ,36  ), /* EBI_ADR0/SPI1_SS                                                                                                                                   */\
  PIN(F,3 ,37  ), /* EBI_nCS0/UART0_TXD/I2C0_SCL/XT1_IN/BPWM1_CH0                                                                                                       */\
  PIN(F,2 ,38  ), /* EBI_nCS1/UART0_RXD/I2C0_SDA/QSPI0_CLK/XT1_OUT/BPWM1_CH1                                                                                            */\
       /*   39       VSS                                                                                                                                               */\
       /*   40       VDD                                                                                                                                               */\
  PIN(E,8 ,41  ), /* EBI_ADR10/EMAC_RMII_MDC/I2S0_BCLK/SPI2_CLK/USCI1_CTL1/UART2_TXD/EPWM0_CH0/EPWM0_BRAKE0/ECAP0_IC0/TRACE_DATA3                                       */\
  PIN(E,9 ,42  ), /* EBI_ADR11/EMAC_RMII_MDIO/I2S0_MCLK/SPI2_MISO/USCI1_CTL0/UART2_RXD/EPWM0_CH1/EPWM0_BRAKE1/ECAP0_IC1/TRACE_DATA2                                     */\
  PIN(E,10,43  ), /* EBI_ADR12/EMAC_RMII_TXD0/I2S0_DI/SPI2_MOSI/USCI1_DAT0/UART3_TXD/EPWM0_CH2/EPWM1_BRAKE0/ECAP0_IC2/TRACE_DATA1                                       */\
  PIN(E,11,44  ), /* EBI_ADR13/EMAC_RMII_TXD1/I2S0_DO/SPI2_SS/USCI1_DAT1/UART3_RXD/UART1_nCTS/EPWM0_CH3/EPWM1_BRAKE1/ECAP1_IC2/TRACE_DATA0                              */\
  PIN(E,12,45  ), /* EBI_ADR14/EMAC_RMII_TXEN/I2S0_LRCK/SPI2_I2SMCLK/USCI1_CLK/UART1_nRTS/EPWM0_CH4/ECAP1_IC1/TRACE_CLK                                                 */\
  PIN(E,13,46  ), /* EBI_ADR15/EMAC_PPS/I2C0_SCL/UART4_nRTS/UART1_TXD/EPWM0_CH5/EPWM1_CH0/BPWM1_CH5/ECAP1_IC0                                                           */\
  PIN(C,8 ,47  ), /* EBI_ADR16/EMAC_RMII_REFCLK/I2C0_SDA/UART4_nCTS/UART1_RXD/EPWM1_CH1/BPWM1_CH4                                                                       */\
  PIN(C,7 ,48  ), /* EBI_AD9/EMAC_RMII_RXD0/SPI1_MISO/UART4_TXD/SC2_PWR/UART0_nCTS/I2C1_SMBAL/EPWM1_CH2/BPWM1_CH0/TM0/INT3                                              */\
  PIN(C,6 ,49  ), /* EBI_AD8/EMAC_RMII_RXD1/SPI1_MOSI/UART4_RXD/SC2_RST/UART0_nRTS/I2C1_SMBSUS/EPWM1_CH3/BPWM1_CH1/TM1/INT2                                             */\
  PIN(A,7 ,50  ), /* EBI_AD7/EMAC_RMII_CRSDV/SPI1_CLK/SC2_DAT/UART0_TXD/I2C1_SCL/EPWM1_CH4/BPWM1_CH2/ACMP0_WLAT/TM2/INT1                                                */\
  PIN(A,6 ,51  ), /* EBI_AD6/EMAC_RMII_RXERR/SPI1_SS/SD1_nCD/SC2_CLK/UART0_RXD/I2C1_SDA/EPWM1_CH5/BPWM1_CH3/ACMP1_WLAT/TM3/INT0                                         */\
       /*   52      VSS                                                                                                                                                */\
       /*   53      VDD                                                                                                                                                */\
       /*   54      LDO_CAP                                                                                                                                            */\
  PIN(A,5 ,55  ), /* SPIM_D2/QSPI0_MISO1/SPI1_I2SMCLK/SD1_CMD/SC2_nCD/UART0_nCTS/UART5_TXD/I2C0_SCL/CAN0_TXD/BPWM0_CH5/EPWM0_CH0/QEI0_INDEX                             */\
  PIN(A,4 ,56  ), /* SPIM_D3/QSPI0_MOSI1/SPI0_I2SMCLK/SD1_CLK/SC0_nCD/UART0_nRTS/UART5_RXD/I2C0_SDA/CAN0_RXD/BPWM0_CH4/EPWM0_CH1/QEI0_A                                 */\
  PIN(A,3 ,57  ), /* SPIM_SS/QSPI0_SS/SPI0_SS/SD1_DAT3/SC0_PWR/UART4_TXD/UART1_TXD/I2C1_SCL/BPWM0_CH3/EPWM0_CH2/QEI0_B                                                  */\
  PIN(A,2 ,58  ), /* SPIM_CLK/QSPI0_CLK/SPI0_CLK/SD1_DAT2/SC0_RST/UART4_RXD/UART1_RXD/I2C1_SDA/BPWM0_CH2/EPWM0_CH3                                                      */\
  PIN(A,1 ,59  ), /* SPIM_MISO/QSPI0_MISO0/SPI0_MISO/SD1_DAT1/SC0_DAT/UART0_TXD/UART1_nCTS/I2C2_SCL/BPWM0_CH1/EPWM0_CH4/DAC1_ST                                         */\
  PIN(A,0 ,60  ), /* SPIM_MOSI/QSPI0_MOSI0/SPI0_MOSI/SD1_DAT0/SC0_CLK/UART0_RXD/UART1_nRTS/I2C2_SDA/BPWM0_CH0/EPWM0_CH5/DAC0_ST                                         */\
       /*   61      VDDIO                                                                                                                                             */\
  PIN(E,14,62  ), /* EBI_AD8/UART2_TXD/CAN0_TXD/SD1_nCD                                                                                                                 */\
  PIN(E,15,63  ), /* EBI_AD9/UART2_RXD/CAN0_RXD                                                                                                                         */\
       /*   64       nRESET                                                                                                                                           */\
  PIN(F,0 ,65  ), /* UART1_TXD/I2C1_SCL/BPWM1_CH0/ICE_DAT                                                                                                               */\
  PIN(F,1 ,66  ), /* UART1_RXD/I2C1_SDA/BPWM1_CH1/ICE_CLK                                                                                                               */\
  PIN(D,9 ,67  ), /* EBI_AD7/I2C2_SCL/UART2_nCTS                                                                                                                        */\
  PIN(D,8 ,68  ), /* EBI_AD6/I2C2_SDA/UART2_nRTS                                                                                                                        */\
  PIN(C,5 ,69  ), /* EBI_AD5/SPIM_D2/QSPI0_MISO1/UART2_TXD/I2C1_SCL/CAN0_TXD/UART4_TXD/EPWM1_CH0                                                                        */\
  PIN(C,4 ,70  ), /* EBI_AD4/SPIM_D3/QSPI0_MOSI1/SC1_nCD/I2S0_BCLK/SPI1_I2SMCLK/UART2_RXD/I2C1_SDA/CAN0_RXD/UART4_RXD/EPWM1_CH1                                         */\
  PIN(C,3 ,71  ), /* EBI_AD3/SPIM_SS/QSPI0_SS/SC1_PWR/I2S0_MCLK/SPI1_MISO/UART2_nRTS/I2C0_SMBAL/CAN1_TXD/UART3_TXD/EPWM1_CH2                                            */\
  PIN(C,2 ,72  ), /* EBI_AD2/SPIM_CLK/QSPI0_CLK/SC1_RST/I2S0_DI/SPI1_MOSI/UART2_nCTS/I2C0_SMBSUS/CAN1_RXD/UART3_RXD/EPWM1_CH3                                           */\
  PIN(C,1 ,73  ), /* EBI_AD1/SPIM_MISO/QSPI0_MISO0/SC1_DAT/I2S0_DO/SPI1_CLK/UART2_TXD/I2C0_SCL/EPWM1_CH4/ACMP0_O                                                        */\
  PIN(C,0 ,74  ), /* EBI_AD0/SPIM_MOSI/QSPI0_MOSI0/SC1_CLK/I2S0_LRCK/SPI1_SS/UART2_RXD/I2C0_SDA/EPWM1_CH5/ACMP1_O                                                       */\
       /*  75        VSS                                                                                                                                              */\
       /*  76        VDD                                                                                                                                                */\
  PIN(G,9 ,77  ), /* EBI_AD0/SD1_DAT3/SPIM_D2/BPWM0_CH5                                                                                                                 */\
  PIN(G,10,78  ), /* EBI_AD1/SD1_DAT2/SPIM_D3/BPWM0_CH4                                                                                                                 */\
  PIN(G,11,79  ), /* EBI_AD2/SD1_DAT1/SPIM_SS/BPWM0_CH3                                                                                                                 */\
  PIN(G,12,80  ), /* EBI_AD3/SD1_DAT0/SPIM_CLK/BPWM0_CH2                                                                                                                */\
  PIN(G,13,81  ), /* EBI_AD4/SD1_CMD/SPIM_MISO/BPWM0_CH1                                                                                                                */\
  PIN(G,14,82  ), /* EBI_AD5/SD1_CLK/SPIM_MOSI/BPWM0_CH0                                                                                                                */\
  PIN(G,15,83  ), /* SD1_nCD/CLKO/EADC0_ST                                                                                                                              */\
  PIN(D,13,84  ), /* EBI_AD10/SD0_nCD/SPI0_I2SMCLK/SPI1_I2SMCLK/SC2_nCD                                                                                                 */\
  PIN(A,12,85  ), /* I2S0_BCLK/UART4_TXD/I2C1_SCL/SPI2_SS/CAN0_TXD/SC2_PWR/BPWM1_CH2/QEI1_INDEX/USB_VBUS                                                                */\
  PIN(A,13,86  ), /* I2S0_MCLK/UART4_RXD/I2C1_SDA/SPI2_CLK/CAN0_RXD/SC2_RST/BPWM1_CH3/QEI1_A/USB_D-                                                                     */\
  PIN(A,14,87  ), /* I2S0_DI/UART0_TXD/SPI2_MISO/I2C2_SCL/SC2_DAT/BPWM1_CH4/QEI1_B/USB_D+                                                                               */\
  PIN(A,15,88  ), /* I2S0_DO/UART0_RXD/SPI2_MOSI/I2C2_SDA/SC2_CLK/BPWM1_CH5/EPWM0_SYNC_IN/USB_OTG_ID                                                                    */\
       /*  89       HSUSB_VRES                                                                                                                                         */\
       /*  90       HSUSB_VDD33                                                                                                                                        */\
       /*  91       HSUSB_VBUS                                                                                                                                         */\
       /*  92       HSUSB_D-                                                                                                                                           */\
       /*  93       HSUSB_VSS                                                                                                                                          */\
       /*  94       HSUSB_D+                                                                                                                                           */\
       /*  95       HSUSB_VDD12_CAP                                                                                                                                    */\
       /*  96       HSUSB_ID                                                                                                                                           */\
  PIN(E,7 ,97  ), /* SD0_CMD/SPIM_D2/UART5_TXD/CAN1_TXD/QEI1_INDEX/EPWM0_CH0/BPWM0_CH5                                                                                  */\
  PIN(E,6 ,98  ), /* SD0_CLK/SPIM_D3/SPI3_I2SMCLK/SC0_nCD/USCI0_CTL0/UART5_RXD/CAN1_RXD/QEI1_A/EPWM0_CH1/BPWM0_CH4                                                      */\
  PIN(E,5 ,99  ), /* EBI_nRD/SD0_DAT3/SPIM_SS/SPI3_SS/SC0_PWR/USCI0_CTL1/QEI1_B/EPWM0_CH2/BPWM0_CH3                                                                     */\
  PIN(E,4 ,100 ), /* EBI_nWR/SD0_DAT2/SPIM_CLK/SPI3_CLK/SC0_RST/USCI0_DAT1/QEI0_INDEX/EPWM0_CH3/BPWM0_CH2                                                               */\
  PIN(E,3 ,101 ), /* EBI_MCLK/SD0_DAT1/SPIM_MISO/SPI3_MISO/SC0_DAT/USCI0_DAT0/QEI0_A/EPWM0_CH4/BPWM0_CH1                                                                */\
  PIN(E,2 ,102 ), /* EBI_ALE/SD0_DAT0/SPIM_MOSI/SPI3_MOSI/SC0_CLK/USCI0_CLK/QEI0_B/EPWM0_CH5/BPWM0_CH0                                                                  */\
       /*   103      VSS                                                                                                                                                */\
       /*   104      VDD                                                                                                                                                */\
  PIN(E,1 ,105 ), /* EBI_AD10/QSPI0_MISO0/SC2_DAT/I2S0_BCLK/SPI1_MISO/UART3_TXD/I2C1_SCL/UART4_nCTS                                                                     */\
  PIN(E,0 ,106 ), /* EBI_AD11/QSPI0_MOSI0/SC2_CLK/I2S0_MCLK/SPI1_MOSI/UART3_RXD/I2C1_SDA/UART4_nRTS                                                                     */\
  PIN(H,8 ,107 ), /* EBI_AD12/QSPI0_CLK/SC2_PWR/I2S0_DI/SPI1_CLK/UART3_nRTS/I2C1_SMBAL/I2C2_SCL/UART1_TXD                                                               */\
  PIN(H,9 ,108 ), /* EBI_AD13/QSPI0_SS/SC2_RST/I2S0_DO/SPI1_SS/UART3_nCTS/I2C1_SMBSUS/I2C2_SDA/UART1_RXD                                                                */\
  PIN(H,10,109 ), /* EBI_AD14/QSPI0_MISO1/SC2_nCD/I2S0_LRCK/SPI1_I2SMCLK/UART4_TXD/UART0_TXD                                                                            */\
  PIN(H,11,110 ), /* EBI_AD15/QSPI0_MOSI1/UART4_RXD/UART0_RXD/EPWM0_CH5                                                                                                 */\
  PIN(D,14,111 ), /* EBI_nCS0/SPI3_I2SMCLK/SC1_nCD/EPWM0_CH4                                                                                                            */\
       /*   112     VSS                                                                                                                                                 */\
       /*   113     LDO_CAP                                                                                                                                             */\
       /*   114     VDD                                                                                                                                                 */\
  PIN(C,14,115 ), /* EBI_AD11/SC1_nCD/SPI0_I2SMCLK/USCI0_CTL0/QSPI0_CLK/EPWM0_SYNC_IN/TM1/USB_VBUS_ST/HSUSB_VBUS_ST                                                     */\
  PIN(B,15,116 ), /* EADC0_CH15/EBI_AD12/SC1_PWR/SPI0_SS/USCI0_CTL1/UART0_nCTS/UART3_TXD/I2C2_SMBAL/EPWM1_CH0/TM0_EXT/USB_VBUS_EN/HSUSB_VBUS_EN                         */\
  PIN(B,14,117 ), /* EADC0_CH14/EBI_AD13/SC1_RST/SPI0_CLK/USCI0_DAT1/UART0_nRTS/UART3_RXD/I2C2_SMBSUS/EPWM1_CH1/TM1_EXT/CLKO                                            */\
  PIN(B,13,118 ), /* EADC0_CH13/DAC1_OUT/ACMP0_P3/ACMP1_P3/EBI_AD14/SC1_DAT/SPI0_MISO/USCI0_DAT0/UART0_TXD/UART3_nRTS/I2C2_SCL/EPWM1_CH2/TM2_EXT                        */\
  PIN(B,12,119 ), /* EADC0_CH12/DAC0_OUT/ACMP0_P2/ACMP1_P2/EBI_AD15/SC1_CLK/SPI0_MOSI/USCI0_CLK/UART0_RXD/UART3_nCTS/I2C2_SDA/SD0_nCD/EPWM1_CH3/TM3_EXT                 */\
       /*   120      AVDD                                                                                                                                               */\
       /*   121      VREF                                                                                                                                               */\
       /*   122      AVSS                                                                                                                                               */\
  PIN(B,11,123 ), /* EADC0_CH11/EBI_ADR16/EMAC_RMII_MDC/UART0_nCTS/UART4_TXD/I2C1_SCL/CAN0_TXD/SPI0_I2SMCLK/BPWM1_CH0/SPI3_CLK/HSUSB_VBUS_ST                            */\
  PIN(B,10,124 ), /* EADC0_CH10/EBI_ADR17/EMAC_RMII_MDIO/USCI1_CTL0/UART0_nRTS/UART4_RXD/I2C1_SDA/CAN0_RXD/BPWM1_CH1/SPI3_SS/HSUSB_VBUS_EN                              */\
  PIN(B,9 ,125 ), /* EADC0_CH9/EBI_ADR18/EMAC_RMII_TXD0/USCI1_CTL1/UART0_TXD/UART1_nCTS/I2C1_SMBAL/BPWM1_CH2/SPI3_MISO/INT7                                              */\
  PIN(B,8 ,126 ), /* EADC0_CH8/EBI_ADR19/EMAC_RMII_TXD1/USCI1_CLK/UART0_RXD/UART1_nRTS/I2C1_SMBSUS/BPWM1_CH3/SPI3_MOSI/INT6                                              */\
  PIN(B,7 ,127 ), /* EADC0_CH7/EBI_nWRL/EMAC_RMII_TXEN/USCI1_DAT0/CAN1_TXD/UART1_TXD/SD1_CMD/EBI_nCS0/BPWM1_CH4/EPWM1_BRAKE0/EPWM1_CH4/INT5/USB_VBUS_ST/ACMP0_O          */\
  PIN(B,6 ,128 )  /* EADC0_CH6/EBI_nWRH/EMAC_PPS/USCI1_DAT1/CAN1_RXD/UART1_RXD/SD1_CLK/EBI_nCS1/BPWM1_CH5/EPWM1_BRAKE1/EPWM1_CH5/INT4/USB_VBUS_EN/ACMP1_O                */
#endif

#define MISO_PIN PB_5
#define MOSI_PIN PB_4
#define  SCK_PIN PB_3
#define   SS_PIN PB_2

#define  SDA_PIN PC_0
#define  SCL_PIN PC_1

#define A0  0
#define A1  1
#define A2  2
#define A3  3
#define A4  4
#define A5  5

#endif //_CHIP128_PINLIST_H_
