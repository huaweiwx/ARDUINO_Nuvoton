// IRremotelib
//   test maple port of IRremote lib
//  xmit pin 24 (pwm)    timer 4 ch 4 for maple RET6
//    pin 24 to 100ohm to IR LED to ground
//  recv pin 8   whatever, using timer2 channel 1 for 50us sampling
//    pin 8 to Sharp GP1UX311QS  38khz
//   can run both xmit and recv concurrently  
// for examples/  fix SerialUSB and recv pin
//  http://www.arcfn.com/2009/08/multi-protocol-infrared-remote-library.html
//  https://github.com/shirriff/Arduino-IRremote

#include "nvtIRremote.h"

int RECV_PIN = 9;

IRrecv irrecv(RECV_PIN);
IRsend irsend;

decode_results results;

void setup()
{
  Serial.begin(115200);
  irrecv.enableIRIn(); // Start the receiver
  Serial.println("IR Remote Receive test\n");
}

// Dumps out the decode_results structure.
// Call this after IRrecv::decode()
// void * to work around compiler issue
//void dump(void *v) {
//  decode_results *results = (decode_results *)v
void dump(decode_results *results) {
  int count = results->rawlen;
  if (results->decode_type == UNKNOWN) {
    Serial.print("Unknown encoding: ");
  } 
  else if (results->decode_type == NEC) {
    Serial.print("Decoded NEC: ");
  } 
  else if (results->decode_type == SONY) {
    Serial.print("Decoded SONY: ");
  } 
  else if (results->decode_type == RC5) {
    Serial.print("Decoded RC5: ");
  } 
  else if (results->decode_type == RC6) {
    Serial.print("Decoded RC6: ");
  }
  else if (results->decode_type == PANASONIC) {	
    Serial.print("Decoded PANASONIC - Address: ");
    Serial.print(results->panasonicAddress,HEX);
    Serial.print(" Value: ");
  }
  else if (results->decode_type == JVC) {
     Serial.print("Decoded JVC: ");
  }
  Serial.print(results->value, HEX);
  Serial.print(" (");
  Serial.print(results->bits, DEC);
  Serial.println(" bits)");
  Serial.print("Raw (");
  Serial.print(count, DEC);
  Serial.print("): ");

  for (int i = 0; i < count; i++) {
    if ((i % 2) == 1) {
      Serial.print(results->rawbuf[i]*USECPERTICK, DEC);
    } 
    else {
      Serial.print(-(int)results->rawbuf[i]*USECPERTICK, DEC);
    }
    Serial.print(" ");
  }
  Serial.println("");
}


void loop() {
  long sonycmd[] = {0xA9A,0x91A,0x61A}; // power 0 7

  irsend.sendSony(sonycmd[0],12);   // run send/recv concurrently
  delay(6);   // allow gap time to grow 
  
  if (irrecv.decode(&results)) {
    Serial.println(results.value, HEX);
    dump(&results);
    irrecv.resume(); // Receive the next value
  }
  delay(3000);
}