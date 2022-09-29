#include <Wire.h>
#include "MAX30100_PulseOximeter.h"


PulseOximeter pox;

uint32_t tsLastReport = 0;
#define REPORTING_PERIOD_MS     100

// Callback (registered below) fired when a pulse is detected
void onBeatDetected()
{
    //Serial.println("Beat!");
}

void setup()
{
    Serial.begin(115200);
    pox.setOnBeatDetectedCallback(onBeatDetected);
}

void loop()
{
    // Make sure to call update as fast as possible
    pox.update();

    if (millis() - tsLastReport > REPORTING_PERIOD_MS) {
        Serial.print("Heartrate:");
        Serial.print(pox.getHeartRate());
        Serial.print(", SpO2:");
        Serial.println(pox.getSpO2());

        tsLastReport = millis();
    }
}