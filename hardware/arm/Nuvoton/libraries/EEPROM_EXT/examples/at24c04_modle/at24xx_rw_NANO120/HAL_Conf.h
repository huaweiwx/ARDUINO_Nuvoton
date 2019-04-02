/*   ARDUINO HAL special config file, overriden default define
     config arduino/hal/os/interupt priority/......
     ARDUINO HAL 项目配置文件， 改写 系统、库、缺省定义，配置改变系统的缺省参数/中断优先级等,节约内存；

     define priority(配置的优先次序):
      1  HAL_Conf.h in sketch project path
 	  2  HAL_Conf.h in variants/{variant}/configs.
 	  3  use default define  (in cores/arduino/stm32/stm32_build_defines.h)

     !!! Don't rename this file, 请不要改变文件名和扩展名!!!
     use this config file for save space
     2017.12 by huawei
*/

#ifndef __HALSPECELCONFIG_H__
#define __HALSPECELCONFIG_H__


# define AT24CXX_TYPE   AT24C32
# define AT24CXX_A2A1A0 0
# define AT24CXX_DEV    I2C1
//# define VCC_PIN    PA8
//# define GND_PIN    PB10
# define AT24CXX_SDA    PA_12
# define AT24CXX_SCL    PA_13



#define  USE_ARDUINOSTREAMING	1

/*
  for stl begin/end is keywords for iteration
  if set USE_ITERATOR, arduino lib SPI/SOFTSPI/WARE/SOFTWARE use Init/deInit instead of begin/end
*/
#define  USE_ITERATOR  1   

/* Some external eeprom are not connected to any i2c port. using a software emulate i2c port*/
#define  USE_WARESOFT  0

#ifdef   USE_FULL_ASSERT /*DEBUG*/
/* ------------------------------------------------------------------
 * set USE_ERRORBLINK 1  for _Error_Handler/AssertError output information redirect to led blinking the err code 
   blink err code:
     HardFault       31
     MemManage fault 32
     BusFault        33
     UsageFault      34
     MallocFailed    22 (freertos if set configUSE_MALLOC_FAILED_HOOK 1)
     StackOverflow   23 (freertos if configCHECK_FOR_STACK_OVERFLOW 1)
     others          __LINE__   (err line from assert_failed or _Error_Handler )
*/
#define USE_ERRORBLINK 1
#endif /* USE_FULL_ASSERT */


#endif
