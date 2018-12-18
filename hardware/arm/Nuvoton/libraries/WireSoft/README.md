# WireSoft
A Wire Software emulate I2C library for STM32/EFM32/NUVOTON

## Requirement
* [STM32/EFM32/NUVOTON] (https://github.com/huaweiwx) version >= 1.3.0


# API

This library allows to take control of the software emulate I2C port of the STM32/EFM32/NUVOTON boards.


stl and c++11/14  `begin/end` is keywords for iteration. if use iterator wei can use Init/deInit instead of begin/end.
we can  set `USE_ITERATOR` in `HAL_Conf.h` file as: <br>
 **#define  USE_ITERATOR   1**   


For more information about it, please visit:
http://www.arduino.cc/en/Reference/Wire


