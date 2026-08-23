#include <Arduino.h>

#include "button.h"
#include "led.h"
#include "pir.h"


void setup()
{
    Serial.begin(115200);

    buttonInit();
    ledInit();
    pirInit();

    Serial.println("System started");
}


void loop()
{
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
}