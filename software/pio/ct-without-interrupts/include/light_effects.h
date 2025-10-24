#ifndef LIGHT_EFFECTS_H_
#define LIGHT_EFFECTS_H_
#include <Adafruit_NeoPixel.h>

extern Adafruit_NeoPixel strip;

void specialFadeEffect(int stepSize, float brightnessLevel);
void addAdjustedDelay(int r, int g, int b, int maxBrightness);

void randomChristmasBalls(int speed, float brightnessLevel);
void setPixelColorRed(int pixelNumber, int maxBrightness);
void setPixelColorGreen(int pixelNumber, int maxBrightness);
void setPixelColorBlue(int pixelNumber, int maxBrightness);
void setPixelColorOrange(int pixelNumber, int maxBrightness);
void setPixelColorPurple(int pixelNumber, int maxBrightness);
void setPixelColorViolet(int pixelNumber, int maxBrightness);
void setPixelColorCyan(int pixelNumber, int maxBrightness);
void setPixelColorYellow(int pixelNumber, int maxBrightness);

#endif
