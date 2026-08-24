#ifndef ULTRASONIC_H
#define ULTRASONIC_H

#include <Arduino.h>

void ultrasonicInit();

void ultrasonicUpdate();

bool ultrasonicDataAvailable();

float ultrasonicGetDistanceCm();

void ultrasonicStartMeasurement();

#endif