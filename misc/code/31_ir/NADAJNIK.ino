#include <Arduino.h>
#include <IRremote.h>

// Send
#define PIN_SEND 3

void setup() {
  Serial.begin(115200);
  IrSender.begin(PIN_SEND);
}

void loop() {
  // Send (address, command)
  IrSender.sendNEC(0x01, 0x11, true, 0);
	delay (1000);
  IrSender.sendNEC(0x02, 0x22, true, 0);
  delay (1000);
}