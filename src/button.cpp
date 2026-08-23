#include "button.h"
#include "config.h"


static int lastRawButtonState = HIGH;
static int stableButtonState = HIGH;

static uint32_t lastButtonChangeTime = 0;


void buttonInit()
{
    pinMode(BUTTON_PIN, INPUT_PULLUP);

    lastRawButtonState = digitalRead(BUTTON_PIN);
    stableButtonState = lastRawButtonState;
}


bool buttonPressed()
{
    int currentRawState = digitalRead(BUTTON_PIN);
    uint32_t currentTime = millis();

    // The electrical signal changed
    if (currentRawState != lastRawButtonState)
    {
        lastButtonChangeTime = currentTime;
    }

    // The signal has remained stable long enough
    if (currentTime - lastButtonChangeTime >=
        BUTTON_DEBOUNCE_TIME_MS)
    {
        if (currentRawState != stableButtonState)
        {
            stableButtonState = currentRawState;

            // INPUT_PULLUP: LOW means pressed
            if (stableButtonState == LOW)
            {
                lastRawButtonState = currentRawState;
                return true;
            }
        }
    }

    lastRawButtonState = currentRawState;

    return false;
}