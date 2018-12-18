/*   ARDUINO HAL special config file, overriden default define
 *   config arduino/hal/os/interupt priority/......
 *   ARDUINO HAL 项目配置文件， 改写 系统、库、缺省定义，配置改变系统的缺省参数/中断优先级等,节约内存；

 *   define priority(配置的优先次序):
 *    1  HAL_Conf.h in sketch project path
 *	  2  HAL_Conf.h in variants/{variant}/configs.
 *	  3  use default define  (in cores/arduino/stm32/stm32_build_defines.h)
 *
 *   !!! Don't rename this file, 请不要改变文件名和扩展名!!!
 *   use this config file for save space 
 *   2017.12 by huawei
 */

#ifndef __HALSPECELCONFIG_H__
#define __HALSPECELCONFIG_H__

#define  USE_ARDUINOSTREAMING 1

#ifndef USE_SERIAL1
#define USE_SERIAL1 1
#endif

#ifndef USE_SERIAL2
#define USE_SERIAL2 0
#endif
#ifndef USE_SERIAL3
#define USE_SERIAL3 0
#endif
#ifndef USE_SERIAL4
#define USE_SERIAL4 0
#endif
#ifndef USE_SERIAL5
#define USE_SERIAL5 0
#endif

#ifndef USE_SERIAL6
#define USE_SERIAL6 0
#endif

#ifndef USE_USBSERIAL
#ifndef MENU_USB_IAD
#  define USE_USBSERIAL  0 /*0 if use serial1,unused serialusb save space*/
#endif
#endif

#endif
