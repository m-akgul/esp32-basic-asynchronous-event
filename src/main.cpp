#include <Arduino.h>

#include "button.h"
#include "led.h"
#include "pir.h"
#include "ultrasonic.h"

constexpr uint32_t ULTRASONIC_INTERVAL_MS = 100;

static uint32_t lastUltrasonicMeasurementTime = 0;


void setup()
{
    Serial.begin(115200);

    buttonInit();
    ledInit();
    pirInit();
    ultrasonicInit();

    Serial.println("System started");
}


void loop()
{
    ultrasonicUpdate();


    // Button event
    if (buttonPressed())
    {
        ledToggle();

        if (ledIsOn())
        {
            Serial.println("Button: LED ON");
        }
        else
        {
            Serial.println("Button: LED OFF");
        }
    }


    // PIR event
    if (pirMotionDetected())
    {
        Serial.println("Motion detected!");
    }


    // Start a new ultrasonic measurement every 100 ms
    uint32_t currentTime = millis();

    if (currentTime - lastUltrasonicMeasurementTime >=
        ULTRASONIC_INTERVAL_MS)
    {
        lastUltrasonicMeasurementTime = currentTime;

        ultrasonicStartMeasurement();
    }


    // Process a completed measurement
    if (ultrasonicDataAvailable())
    {
        float distance = ultrasonicGetDistanceCm();

        if (distance >= 0.0f)
        {
            Serial.print("Distance: ");
            Serial.print(distance);
            Serial.println(" cm");
        }
        else
        {
            Serial.println("Ultrasonic timeout");
        }
    }
}