#ifndef LIGHT_EFFECTS_H_
#define LIGHT_EFFECTS_H_
#include <Adafruit_NeoPixel.h>

extern Adafruit_NeoPixel strip;

void specialFadeEffect(int stepSize, float brightnessLevel);
void addAdjustedDelay(int r, int g, int b, int maxBrightness);

void tempBasedLedFaded(float tempC, float brightnessLevel);
void tempBasedLed(float tempC, float brightnessLevel);
void randomChristmasBalls(int speed, float brightnessLevel);
void setPixelColorRed(int pixelNumber, int maxBrightness);
void setPixelColorGreen(int pixelNumber, int maxBrightness);
void setPixelColorBlue(int pixelNumber, int maxBrightness);
void setPixelColorOrange(int pixelNumber, int maxBrightness);
void setPixelColorPurple(int pixelNumber, int maxBrightness);
void setPixelColorViolet(int pixelNumber, int maxBrightness);
void setPixelColorCyan(int pixelNumber, int maxBrightness);
void setPixelColorYellow(int pixelNumber, int maxBrightness);

struct ColorState {
    int r, g, b;
    int phase; // 0=r up, 1=b down, 2=g up, 3=r down, 4=b up, 5=g down
    unsigned long lastUpdate;
    unsigned long delayTime;
};

void specialFadeEffectNonBlocking(int stepSize, float brightnessLevel);


#endif
