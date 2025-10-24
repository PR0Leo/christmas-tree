#include <ntc_light_effects.h>
#include "Arduino.h"
#include <Adafruit_NeoPixel.h>

void tempBasedLedFaded(float tempC, float brightnessLevel)
{
  int red, green, blue, r, g, b;
  float tempRange = tempC - 25; // my range is from 0 - 10 for 25C to 35C.
  if (tempRange >= 10)
  {
    tempRange = 10;
  }
  float floaty = 1024.0 * tempRange / 10.0;
  int colorRange = floaty;

  if (colorRange < 256)
  {
    red = 0;
    green = colorRange;
    blue = 0;
  }
  else if (colorRange < 512)
  {
    red = 0;
    green = 255;
    blue = 256 - (colorRange - 256);
  }
  else if (colorRange < 768)
  {
    red = colorRange - 512;
    green = 255;
    blue = 0;
  }
  else if (colorRange <= 1024)
  {
    red = 255;
    green = 1024 - colorRange;
    blue = 0;
  }
  else
  {
    red = 0;
    green = 0;
    blue = 0;
  }

  r = 1.0 * red * brightnessLevel;
  g = 1.0 * green * brightnessLevel;
  b = 1.0 * blue * brightnessLevel;
  for (int i = 0; i < strip.numPixels(); i++)
  {
    strip.setPixelColor(i, strip.Color(r, g, b)); // Rot, gruen, blau
  }
  noInterrupts();
  strip.show();
  interrupts();

  //  Serial.println("TempRange: " + String(tempRange));
  //  Serial.println("ColorRange: " + String(colorRange));
  //  Serial.println("b = " + String(b) + "blue = " + String(blue));
}

void tempBasedLed(float tempC, float brightnessLevel)
{
  if (tempC <= 28)
  {
    for (int i = 0; i < strip.numPixels(); i++)
    {
      strip.setPixelColor(i, strip.Color(0, 255 * brightnessLevel, 0)); // How t mix blue?
    }
  noInterrupts();
  strip.show();
  interrupts();
  }
  else if (tempC <= 33)
  {
    for (int i = 0; i < strip.numPixels(); i++)
    {
      strip.setPixelColor(i, strip.Color(255 * brightnessLevel, 200 * brightnessLevel, 0)); // How to mix orange?
    }
    noInterrupts();
    strip.show();
    interrupts();
  }
  else if (tempC <= 35)
  {
    for (int i = 0; i < strip.numPixels(); i++)
    {
      strip.setPixelColor(i, strip.Color(255 * brightnessLevel, 0, 0)); // How to mix red?
    }
    noInterrupts();
    strip.show();
    interrupts();
  }
}
