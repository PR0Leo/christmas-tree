#include "light_effects.h"
#include "Arduino.h"
#include <Adafruit_NeoPixel.h>

void specialFadeEffect(int stepSize, int maxBrightness)
{
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
        strip.show(); // Update the strip

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
        strip.show(); // Update the strip

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
        strip.show(); // Update the strip

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
        strip.show(); // Update the strip

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
        strip.show(); // Update the strip

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
        strip.show(); // Update the strip

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

void randomChristmasBalls(int speed, int maxBrightness)
{
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
