#include "light_effects.h"
#include "Arduino.h"
#include <Adafruit_NeoPixel.h>

void specialFadeEffect(int stepSize, float brightnessLevel)
{
    int maxBrightness = brightnessLevel * 255;
    static int r = 0;
    static int g = 0;
    static int b = maxBrightness;

    while (r < maxBrightness)
    {
        r = r + stepSize;
        if (r > maxBrightness)
            r = maxBrightness;
        for (int i = 0; i < strip.numPixels(); i++)
        {
            strip.setPixelColor(i, strip.Color(r, g, b)); // Rot, gruen, blau
        }
        noInterrupts();
        strip.show();
        interrupts();

        addAdjustedDelay(r, g, b, maxBrightness);
    }

    while (b > 0)
    {
        b = b - stepSize;
        if (b < 0)
            b = 0;
        for (int i = 0; i < strip.numPixels(); i++)
        {
            strip.setPixelColor(i, strip.Color(r, g, b)); // Rot, gruen, blau
        }
        noInterrupts();
        strip.show();
        interrupts();

        addAdjustedDelay(r, g, b, maxBrightness);
    }

    while (g < maxBrightness)
    {
        g = g + stepSize;
        if (g > maxBrightness)
            g = maxBrightness;
        for (int i = 0; i < strip.numPixels(); i++)
        {
            strip.setPixelColor(i, strip.Color(r, g, b)); // Rot, gruen, blau
        }
        noInterrupts();
        strip.show();
        interrupts();

        addAdjustedDelay(r, g, b, maxBrightness);
    }

    while (r > 0)
    {
        r = r - stepSize;
        if (r < 0)
            r = 0;
        for (int i = 0; i < strip.numPixels(); i++)
        {
            strip.setPixelColor(i, strip.Color(r, g, b)); // Rot, gruen, blau
        }
        noInterrupts();
        strip.show();
        interrupts();

        addAdjustedDelay(r, g, b, maxBrightness);
    }

    while (b < maxBrightness)
    {
        b = b + stepSize;
        if (b > maxBrightness)
            b = maxBrightness;
        for (int i = 0; i < strip.numPixels(); i++)
        {
            strip.setPixelColor(i, strip.Color(r, g, b)); // Rot, gruen, blau
        }
        noInterrupts();
        strip.show();
        interrupts();

        addAdjustedDelay(r, g, b, maxBrightness);
    }

    while (g > 0)
    {
        g = g - stepSize;
        if (g < 0)
            g = 0;
        for (int i = 0; i < strip.numPixels(); i++)
        {
            strip.setPixelColor(i, strip.Color(r, g, b)); // Rot, gruen, blau
        }
        noInterrupts();
        strip.show();
        interrupts();

        addAdjustedDelay(r, g, b, maxBrightness);
    }
}

void addAdjustedDelay(int r, int g, int b, int maxBrightness)
{
    if ((r == maxBrightness && g == 0 && b == 0) || (r == 0 && g == maxBrightness && b == 0) || (r == 0 && g == 0 && b == maxBrightness))
    {
        delay(60);
    }
    else if ((r > 0 && r < 50) || (g > 0 && g < 100) || (b > 0 && b < 50))
    {
        delay(30);
    }
    else
    {
        delay(10);
    }
}

void randomChristmasBalls(int speed, float brightnessLevel)
{
    int maxBrightness = brightnessLevel * 255;
    for (int i = 0; i < strip.numPixels(); i++)
    {
        int randomNumber = random(8);
        switch (randomNumber)
        {
        case 0:
            setPixelColorRed(i, maxBrightness);
            break;
        case 1:
            setPixelColorGreen(i, maxBrightness);
            break;
        case 2:
            setPixelColorBlue(i, maxBrightness);
            break;
        case 3:
            setPixelColorOrange(i, maxBrightness);
            break;
        case 4:
            setPixelColorPurple(i, maxBrightness);
            break;
        case 5:
            setPixelColorViolet(i, maxBrightness);
            break;
        case 6:
            setPixelColorCyan(i, maxBrightness);
            break;
        case 7:
            setPixelColorYellow(i, maxBrightness);
            break;
        }
    }
    strip.show();
    delay(3000);
}

void tempBasedLedFaded(float tempC, float brightnessLevel)
{
  int red, green, blue, r, g, b;
  float tempRange = tempC - 25; // my range is from 0 - 10 for 25C to 35C.
  if (tempRange >= 10)
  {
    tempRange = 10;
  }
  if (tempRange <= 0){
    tempRange = 0;
  }
  float floaty = 512 * tempRange / 10.0;
  int colorRange = floaty;

  if (colorRange < 256)
  {
    red = colorRange;
    green = 255;
    blue = 0;
  }
  else if (colorRange < 512)
  {
    red = 255;
    green = 512 - colorRange;
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

void setPixelColorRed(int pixelNumber, int maxBrightness)
{
    strip.setPixelColor(pixelNumber, strip.Color(maxBrightness, 0, 0));
}

void setPixelColorGreen(int pixelNumber, int maxBrightness)
{
    strip.setPixelColor(pixelNumber, strip.Color(0, maxBrightness, 0));
}

void setPixelColorBlue(int pixelNumber, int maxBrightness)
{
    strip.setPixelColor(pixelNumber, strip.Color(0, 0, maxBrightness));
}

void setPixelColorOrange(int pixelNumber, int maxBrightness)
{
    strip.setPixelColor(pixelNumber, strip.Color(maxBrightness, maxBrightness / 11, 0));
}

void setPixelColorPurple(int pixelNumber, int maxBrightness)
{
    strip.setPixelColor(pixelNumber, strip.Color(maxBrightness, 0, maxBrightness / 2));
}

void setPixelColorViolet(int pixelNumber, int maxBrightness)
{
    strip.setPixelColor(pixelNumber, strip.Color(maxBrightness / 1.5, 0, maxBrightness));
}

void setPixelColorCyan(int pixelNumber, int maxBrightness)
{
    strip.setPixelColor(pixelNumber, strip.Color(0, maxBrightness, maxBrightness));
}

void setPixelColorYellow(int pixelNumber, int maxBrightness)
{
    strip.setPixelColor(pixelNumber, strip.Color(maxBrightness, maxBrightness / 1.2, 0));
}
