#ifndef NTC_LIGHT_EFFECTS_H_
#define NTC_LIGHT_EFFECTS_H_
#include <Adafruit_NeoPixel.h>

extern Adafruit_NeoPixel strip;
#include "ntc_light_effects.h"

void tempBasedLedFaded(float tempC, float brightnessLevel);
void tempBasedLed(float tempC, float brightnessLevel);

#endif
