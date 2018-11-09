;/******************************************************************************
; * @file     startup_Mini51Series.s
; * @version  V1.00
; * $Revision: 4 $
; * $Date: 13/10/07 4:32p $ 
; * @brief    CMSIS ARM Cortex-M0 Core Device Startup File
; *
; * @note
; * Copyright (C) 2013 Nuvoton Technology Corp. All rights reserved.
;*****************************************************************************/  



    MODULE  ?cstartup

    ;; Forward declaration of sections.
    SECTION CSTACK:DATA:NOROOT(3) ;; 8 bytes alignment

    SECTION .intvec:CODE:NOROOT(2);; 4 bytes alignment

    EXTERN  __iar_program_start
    PUBLIC  __vector_table

    DATA
__vector_table
    DCD     sfe(CSTACK)
    DCD     __iar_program_start

    DCD     NMI_Handler
    DCD     HardFault_Handler
    DCD     0
    DCD     0
    DCD     0
    DCD     0
    DCD     0
    DCD     0
    DCD     0
    DCD     SVC_Handler
    DCD     0
    DCD     0
    DCD     PendSV_Handler
    DCD     SysTick_Handler

    ; External Interrupts
    DCD     BOD_IRQHandler              ; Brownout low voltage detected interrupt                 
    DCD     WDT_IRQHandler              ; Watch Dog Timer interrupt                              
    DCD     EINT0_IRQHandler            ; External signal interrupt from PB.14 pin                
    DCD     EINT1_IRQHandler            ; External signal interrupt from PB.15 pin                
    DCD     GPIO01_IRQHandler           ; External signal interrupt from P0[7:0] / P1[7:0]     
    DCD     GPIO234_IRQHandler          ; External interrupt from P2[7:0]/P3[7:0]/P4[7:0]     
    DCD     PWM_IRQHandler              ; PWM interrupt                                 
    DCD     FB_IRQHandler                                 
    DCD     TMR0_IRQHandler             ; Timer 0 interrupt                                      
    DCD     TMR1_IRQHandler             ; Timer 1 interrupt                                      
    DCD     Default_Handler
    DCD     Default_Handler
    DCD     UART_IRQHandler             ; UART interrupt                                        
    DCD     Default_Handler
    DCD     SPI_IRQHandler             ; SPI interrupt                                         
    DCD     Default_Handler
    DCD     GPIO5_IRQHandler            ; GP5[7:0] interrupt                                         
    DCD     HIRC_IRQHandler             ; HIRC interrupt                                         
    DCD     I2C_IRQHandler              ; I2C interrupt                                         
    DCD     Default_Handler
    DCD     Default_Handler
    DCD     Default_Handler
    DCD     Default_Handler
    DCD     Default_Handler
    DCD     Default_Handler
    DCD     ACMP_IRQHandler
    DCD     Default_Handler
    DCD     Default_Handler
    DCD     PDWU_IRQHandler
    DCD     ADC_IRQHandler              ; ADC interrupt                                          
    DCD     Default_Handler
    DCD     Default_Handler

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;
;; Default interrupt handlers.
;;
    THUMB
    PUBWEAK Reset_Handler   
    SECTION .text:CODE:REORDER(2)       ; 4 bytes alignment
Reset_Handler
             
        LDR      R0, =__iar_program_start
        BX       R0

    PUBWEAK NMI_Handler       
    PUBWEAK SVC_Handler       
    PUBWEAK PendSV_Handler    
    PUBWEAK SysTick_Handler   
    PUBWEAK BOD_IRQHandler   
    PUBWEAK WDT_IRQHandler   
    PUBWEAK EINT0_IRQHandler 
    PUBWEAK EINT1_IRQHandler 
    PUBWEAK GPIO01_IRQHandler  
    PUBWEAK GPIO234_IRQHandler
    PUBWEAK PWM_IRQHandler 
    PUBWEAK FB_IRQHandler 
    PUBWEAK TMR0_IRQHandler 
    PUBWEAK TMR1_IRQHandler 
    PUBWEAK UART_IRQHandler 
    PUBWEAK SPI_IRQHandler 
    PUBWEAK GPIO5_IRQHandler 
    PUBWEAK HIRC_IRQHandler 
    PUBWEAK I2C_IRQHandler 
    PUBWEAK ACMP_IRQHandler  
    PUBWEAK PDWU_IRQHandler 
    PUBWEAK ADC_IRQHandler    
    SECTION .text:CODE:REORDER(2)
HardFault_Handler 
#ifdef DEBUG_ENABLE_SEMIHOST
                MOV     R0, LR
                LSLS    R0,R0, #29            ; Check bit 2
                BMI     SP_is_PSP             ; previous stack is PSP
                MRS     R0, MSP               ; previous stack is MSP, read MSP
                B       SP_Read_Ready
SP_is_PSP
                MRS     R0, PSP               ; Read PSP
SP_Read_Ready
                LDR     R1, [R13, #24]         ; Get previous PC
                LDRH    R3, [R1]              ; Get instruction
                LDR    R2, =0xBEAB           ; The sepcial BKPT instruction
                CMP     R3, R2                ; Test if the instruction at previous PC is BKPT
                BNE    HardFault_Handler_Ret ; Not BKPT
        
                ADDS    R1, #4                ; Skip BKPT and next line
                STR     R1, [R13, #24]         ; Save previous PC
        
                BX     LR
HardFault_Handler_Ret
#endif

NMI_Handler       
SVC_Handler       
PendSV_Handler    
SysTick_Handler   
BOD_IRQHandler   
WDT_IRQHandler   
EINT0_IRQHandler 
EINT1_IRQHandler 
GPIO01_IRQHandler  
GPIO234_IRQHandler 
PWM_IRQHandler  
FB_IRQHandler  
TMR0_IRQHandler  
TMR1_IRQHandler  
UART_IRQHandler 
SPI_IRQHandler  
GPIO5_IRQHandler  
HIRC_IRQHandler  
I2C_IRQHandler  
ACMP_IRQHandler  
PDWU_IRQHandler
ADC_IRQHandler    
Default_Handler          
    B Default_Handler         

#ifdef DEBUG_ENABLE_SEMIHOST

; int SH_DoCommand(int n32In_R0, int n32In_R1, int *pn32Out_R0);
; Input
;   R0,n32In_R0: semihost register 0
;   R1,n32In_R1: semihost register 1
; Output
;   R2,*pn32Out_R0: semihost register 0
; Return
;   0: No ICE debug
;   1: ICE debug
SH_DoCommand
                EXPORT SH_DoCommand
                BKPT   0xAB                  ; Wait ICE or HardFault
                                             ; ICE will step over BKPT directly
                                             ; HardFault will step BKPT and the next line
                B      SH_ICE
SH_HardFault                                 ; Captured by HardFault
                MOVS   R0, #0                ; Set return value to 0
                BX     lr                    ; Return
SH_ICE                                       ; Captured by ICE
                ; Save return value
                CMP    R2, #0
                BEQ    SH_End
                STR    R0, [R2]              ; Save the return value to *pn32Out_R0
SH_End
                MOVS   R0, #1                ; Set return value to 1
                BX     lr                    ; Return

#endif
    

    
    END
;/*** (C) COPYRIGHT 2013 Nuvoton Technology Corp. ***/
