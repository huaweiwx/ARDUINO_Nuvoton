# oomlout-BMAR: the Arduino Benchmarking Project

## About the Project
The BMAR project aims to provide a detailed reference for the performance
and other characteristics of Arduino and Arduino compatible microcontroller
boards. Using a range of benchmarks, the performance of each board is measured
and stored in a handy-dandy spreadsheet. Fancy finding the Arduino with the
lowest power draw? We've got you covered. Need to do lots of floating-point
arithmetic locally? There's an Arduino for that, too. Need all the pins? Just
take a look at our results.

## About the Benchmarks
There are three main benchmark sketches used to generate BMAR results.

### Whetstone
The classic floating-point benchmark, here largely unmodified beyond a switch
to single-precision in order to not spoil the fun for 8-bit microcontrollers
incapable of handling double- or higher-precision arithmetic. This provides a
glimpse of a given microcontroller's ability to handle floating-point maths.

### Dhrystone
Where Whetstone measures floating-point chops, Dhrystone looks at integer
arithmetic. This version of Dhrystone has been modified in order to allow it
to run on the ATmega328P microcontroller found in the Arduino Uno and
compatibles, where it uses over 80 per cent of the dynamic memory (SRAM).

### IOBench
A custom benchmark written specifically for BMAR, IOBench times a number of
digitalWrite and digitalRead operations on a board's pins and provides results
in kilohertz (KHz) - i.e. how many operations the board can carry out per second
on a single pin. If you have access to a frequency counter, IOBench also has a
third test mode: at the end of the 'soft' benchmark, IOBench goes into a 'hard'
mode in which it physically toggles Pin 7 on and off using digitalWrite in an
infinite loop. Hook your frequency counter up here to get the "Digital Write
(Hard)" result.

## About the Tests
As well as the performance benchmarks, BMAR looks into other aspects of a
microcontroller's characteristics. These are:

### Power Draw
BMAR tests the power draw of the Arduino boards via the USB port in three modes:
Load, Idle, and Sleep. To test for Load draw, the Whetstone benchmark is run and
the power draw recorded via an ammeter; Idle results are obtained while the
microcontroller is in a delay() cycle; and Sleep results recorded when the
microcontroller is in its interruptable low-power sleep mode. Note, however,
that this is not always the absolute lowest power possible: for the purposes of
BMAR, only sleep modes accessible through the Arduino IDE in a simple sketch are
used. For some boards, no sleep modes are available without various workarounds
and hacks - these are immediately obvious thanks to the fact that the idle power
draw will match the sleep power draw in the results!

### Compiled Sketch Size
Having a load of flash memory available for sketches isn't much use if your
sketches are huge. To obtain these results, the BareMinimum.ino and Blink.ino
sketches included with the Arduino IDE are compiled and the size of the
resulting binaries recorded.

### Footprint
The width, breadth, and height of each board is measured with calipers. Note
that the results may differ from the official measurements found on the
manufacturer's documentation, as the measurements for BMAR take into account any
components sitting proud of the overall PCB.

## Contributing
If you've got a board you'd like to see included in BMAR, feel free to run the
tests and send us a pull request to get it added! Ideally, though, avoid boards
which are clones of existing entries: the Arduino Duemilanove, for example, is
functionally identical to the Arduino Uno (as they both use the same
microcontroller), so there's little reason to include both.
