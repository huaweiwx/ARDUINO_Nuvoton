# EEPROM_EXT
A AT24Cxx EEPROM library for STM32GENERIC

## Requirement
* [STM32GENERIC] (https://github.com/huaweiwx/STM32GENERIC) version >= 1.3.0



This library is based on the STM32 HAL/LL lib allows to take read/write of the hard or software emulate I2C port EEPROM.<br>
## creat instence:<br>
`EXTEEPROM myat24cxx(SDAPIN,SCLPIN,DEVADR,DEVTYPE);`

 parm:
 
* `SDAPIN,SCLPIN` is AT24CXX sda,scl conected with mcu arduio pin number.The default is `AT24CXX_SDA` and `AT24CXX_SCL` define at file `variant/configs/i2cEepromConfig.h`<br>
* `DEVADR` AT24CXX device adress, the default is `0x50` as AT24CXX's `A2A1A0 = 000`. 
* `DEVTYPE` is AT24CXX type, the  default is `AT24CXX_DEV` define at file `variant/configs/i2cEepromConfig.h`<br>  

# API

stl and c++11/14  `begin/end` is keywords for iteration. if use iterator we can use Init/deInit instead of begin/end.
it will be set `USE_ITERATOR` in `HAL_Conf.h` file as: <br>
 **#define  USE_ITERATOR   1**   


For more information about it, please visit:
http://www.arduino.cc/en/Reference/EEPROM


