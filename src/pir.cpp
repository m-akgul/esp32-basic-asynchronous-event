#include "pir.h"
#include "config.h"


static volatile bool motionDetected = false;


void IRAM_ATTR pirInterruptHandler()
{
    motionDetected = true;
}


void pirInit()
{
    pinMode(PIR_PIN, INPUT);

    attachInterrupt(
        digitalPinToInterrupt(PIR_PIN),
        pirInterruptHandler,
        RISING
    );
}


bool pirMotionDetected()
{
    if (motionDetected)
    {
        motionDetected = false;
        return true;
    }

    return false;
}