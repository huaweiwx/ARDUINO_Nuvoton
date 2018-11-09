port of Arduino IRremote lib to maple
  see http://www.arcfn.com/2009/08/multi-protocol-infrared-remote-library.html
       https://github.com/shirriff/Arduino-IRremote

uses PWM on pin 24, timer 4/channel 4  (maple RET6) varies by board
      pin 24 to 100ohm to IR LED to grnd
   recv on pin 8, uses timer2/channel to do 50us samples
    pin 8 to Sharp GP1UX311QS  38khz

limited testing with Sony remote/VCR


examples/ need to fix pin number and Serial to SerialUSB

irsndrcv1.png  a scope snapshot of running an IR LED transmit with the IR 
               receiver at the same time.  Blue is pulsing (40khz) IR transmit,
               red is receiver

