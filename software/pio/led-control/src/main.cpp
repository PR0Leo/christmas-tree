#include <Arduino.h>
#include <SoftwareSerial.h>
// #include <HardwareSerial.h>
#include <Adafruit_NeoPixel.h>
#include "light_effects.h"

#define LED_BUILTIN 13
#define LEDS 8           // Define the GPIO pin connected to the NeoPixel data input
#define NUMPIXELS 18      // range of NeoPixels in the strip //51 possible
#define MAXBRIGHTNESS 0.3 // in percent
#define LED_ON_OFF_BUTTON 2
// Create an instance of the Adafruit_NeoPixel class
Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUMPIXELS, LEDS, NEO_GRB + NEO_KHZ800);

void tempBasedLedFaded(float tempC);
void tempBasedLed(float tempC);
void setBreak();
boolean ledsOn =  0; 

void setup()
{
  // debug_init();
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(LED_ON_OFF_BUTTON, INPUT);

  strip.begin(); // Initialize the strip
  strip.show();  // Initialize all pixels to 'off'
  Serial.begin(9600);

  digitalWrite(LED_BUILTIN, HIGH);
  delay(2000);
  digitalWrite(LED_BUILTIN, LOW);
  Serial.println("Setup is completed.");
}

void loop()
{
//  tempBasedLedFaded(tempC);
//  tempBasedLed(tempC);
//  randomChristmasBalls(10, 30); 
//  specialFadeEffect(5, 100);
  if (!digitalRead(LED_ON_OFF_BUTTON) == ledsOn){
    for (int i = 0; i < strip.numPixels(); i++)
    {
      strip.setPixelColor(i, strip.Color(255, 255, 255)); // Rot, gruen, blau = max white
    }
    ledsOn = 1;
  } else {
    for (int i = 0; i < strip.numPixels(); i++)
    {
      strip.setPixelColor(i, strip.Color(0, 0, 0)); // Rot, gruen, blau = max white
    }
    ledsOn = 0;
  }
  strip.show(); // Update the strip
}

void setBreak()
{
    Serial.println("----------------------------------------------------------------------------------");
}

void tempBasedLedFaded(float tempC)
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

  r = 1.0 * red * MAXBRIGHTNESS;
  g = 1.0 * green * MAXBRIGHTNESS;
  b = 1.0 * blue * MAXBRIGHTNESS;
  for (int i = 0; i < strip.numPixels(); i++)
  {
    strip.setPixelColor(i, strip.Color(r, g, b)); // Rot, gruen, blau
  }
  strip.show(); // Update the strip

  //  Serial.println("TempRange: " + String(tempRange));
  //  Serial.println("ColorRange: " + String(colorRange));
  //  Serial.println("b = " + String(b) + "blue = " + String(blue));
}

void tempBasedLed(float tempC)
{
  if (tempC <= 28)
  {
    for (int i = 0; i < strip.numPixels(); i++)
    {
      strip.setPixelColor(i, strip.Color(0, 100, 0)); // How t mix blue?
    }
    strip.show(); // Update the strip
  }
  else if (tempC <= 33)
  {
    for (int i = 0; i < strip.numPixels(); i++)
    {
      strip.setPixelColor(i, strip.Color(80, 50, 0)); // How to mix orange?
    }
    strip.show(); // Update the strip
  }
  else if (tempC <= 35)
  {
    for (int i = 0; i < strip.numPixels(); i++)
    {
      strip.setPixelColor(i, strip.Color(100, 0, 0)); // How to mix red?
    }
    strip.show(); // Update the strip
  }
}
