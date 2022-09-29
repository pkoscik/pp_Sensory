#include <Arduino.h>
#include <IRremote.h>

#define RECV_PIN 4


// Receive
IRrecv irrecv(RECV_PIN);
decode_results results;


void setup() {
  Serial.begin(115200);
  irrecv.enableIRIn();
}

void loop() {
  // Receive
  if (IrReceiver.decode()) {
    IrReceiver.printIRResultShort(&Serial);
    Serial.println();
    delay (100);
    IrReceiver.resume();
  }
}