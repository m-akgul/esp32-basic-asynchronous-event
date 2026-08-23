#include <Arduino.h>

#include "button.h"
#include "led.h"


void setup()
{
    Serial.begin(115200);

    buttonInit();
    ledInit();

    Serial.println("System started");
}


void loop()
{
    if (buttonPressed())
    {
        ledToggle();

        if (ledIsOn())
        {
            Serial.println("LED ON");
        }
        else
        {
            Serial.println("LED OFF");
        }
    }
}