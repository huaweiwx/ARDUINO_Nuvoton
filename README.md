# Nuvoton Arduino core
Generic implementation of Arduino for Nuvoton boards

### Supported hardware

* **Upload methods:** Nulink/jlink
* **Chip families:** Nuvoton M4/M0

## Board Package Installation Steps
1. Download the Nuvoton Arduino core latest version from [https://github.com/huaweiwx/Nuvoton_arduino_core](https://github.com/huaweiwx/Nuvoton_arduino_core)
2. Unzip it into [Arduino]/hardware folder (Arduino must be ver1.8.5 or newer)
3. Unzip hardware/tools/win/NuLink.rar to hardware/tools/win/NuLink folder. 
4. Install Arduino Zero or Arduino Sam from the board manager for the arm-none-eabi-gcc compiler
5. Download the [GNU ARM Embedded Toolchain](https://developer.arm.com/open-source/gnu-toolchain/gnu-rm/downloads).
   Recommended use GCC ver 6.3.1-2017q2,Change compiler.path in [platform.txt](https://github.com/danieleff/STM32GENERIC/blob/master/STM32/platform.txt#L21) to point to that you downloaded.
   Example for default position:  C:\Users\Administrator\AppData\Local\Arduino15\packages\arduino\tools\arm-none-eabi-gcc\
6. Create a folder c:\Tmp
7. Modify environment variables TEMP and TMP as: 
   TEMP=c:\Tmp
   TMP=c:\Tmp
   Because of the Windows command line length limit, we need to modify the environment variables to compile more files (Such as uCGUI)

## ARDUINO foot Number definition
Arduino official foot number using digital serial number `1,2,3 ...`<br>
, but in most unofficial version of Arduino transplants, more memorable and meaningful naming rules have been added, allowing us to know the corresponding ports and bits, such as:<br>
  STM32/EFM32: `PA5`<br>
  Represents port `A`, bit `5`<br>

This is the exception in Nuvoton ARDUINO, where the above expression has a specific meaning in the Nuvoton Stddriver BSP Lib and has been defined as the Bitband address of the Nuvoton chip corresponding to the GPIO BIT. In the Arduino enhancements core, I add an underscore between the port and bit to avoid conflicts:<br>
`Pn_m`
　　　Where: n port name; m port bit number;
For example:<br>
`PA5` marked as `PA_5`<br>

There are two rules for naming the port number of the Nuvoton chip, specifically M4/NUC/NANO most of which are represented by uppercase letters A/B/C, while mini51/m051 uses a naming rule similar to 51. represented by a digital 0/1/2/3.<br>
Therefore, it is also named in my Nuvoton Arduino by naming methods in the corresponding Stddrive lib, as in the case of numbers represented by the port number: <br>
such as Port `0` Bit`5`: <br>
expressed as `P0_5`<br>

There are two representations in the same transplant package, whether it's confusing for the developer or the actual user, and it's also inconvenient for me to provide sample code to distinguish between the two different chips, so in the system, in addition to naming by rules, you can use its alias for each foot,
This is equivalent to using standard naming and aliases, such as:
`PA_5` equivalent to `P0_5`