#ifndef CONFIG_H
#define CONFIG_H

#include <Arduino.h>

constexpr uint8_t LED_PIN = 23;
constexpr uint8_t BUTTON_PIN = 18;
constexpr uint8_t PIR_PIN = 19;

constexpr uint32_t BUTTON_DEBOUNCE_TIME_MS = 30;

#endif