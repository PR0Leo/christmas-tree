// -----------------------------------------------------------------------------
// Include Libs
// -----------------------------------------------------------------------------
#include <Arduino.h> // for Arudino syntax
// #include <SoftwareSerial.h>      // for serial communication to amplifier
#include <DFRobotDFPlayerMini.h> // for amplifier commands
#include <Adafruit_NeoPixel.h>   // for LED commands
#include "light_effects.h"       // self written lib for special led effects
#include "ntc_light_effects.h"   // self written lib for ntc based led effects
// #include <PinChangeInterrupt.h>
#include "avr8-stub.h"
#include "app_api.h"
#include <NeoSWSerial.h>
// #include <HardwareSerial.h>

// -----------------------------------------------------------------------------
// Define: Pins as in Stromlaufplan, LED Brightness, Amount of LEDs
// -----------------------------------------------------------------------------
#define LED_BUILTIN 13
#define THERMISTOR A5
#define SHIELD_LEDS 8 // Define GPIO connected to NeoPixel data
// input (christmas tree)
#define LED_SWITCH_STATE_BUTTON 2
#define PAUSE_PLAY_BUTTON 3
#define DEC_VOLUME_BUTTON 4
#define INC_VOLUME_BUTTON 5
#define PREVIOUS_BUTTON 6
#define NEXT_BUTTON 7
#define NUMPIXELS 18        // Amount of Neopixels, 51 possible
#define BRIGHTNESSLEVEL 0.1 // Brightnes of LEDs: 0 = OFF, 1 = MAX
// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// Setup NeoPixel class for LEDs, DFPlayer Class for Speaker,
// serial interface for speaker communication
// -----------------------------------------------------------------------------
Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUMPIXELS, SHIELD_LEDS, NEO_GRB + NEO_KHZ800);
DFRobotDFPlayerMini myDFPlayer;
// SoftwareSerial mySerial(10, 11); // First digit = RX of Arduino and needs to
NeoSWSerial mySerial(10, 11); // First digit = RX of Arduino and needs to
// be connected to TX of Amplifier, second digit vice versa with TX
// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// Declare functions which are later used and descriped
// -----------------------------------------------------------------------------
void switchledMode();
void pausePlay();
void setBreak();

// -----------------------------------------------------------------------------
// Declare states for LED and Music
// -----------------------------------------------------------------------------
volatile int ledMode = 1;
volatile boolean isPlaying = 1;
volatile boolean shouldPlay = 1;

void setup()
{

  // ---------------------------------------------------------------------------
  // Initialize all Pins
  // ---------------------------------------------------------------------------
  debug_init();
  pinMode(PAUSE_PLAY_BUTTON, INPUT);
  // INPUT not INPUT_PULLUP
  // because all buttons already have external pullup and a filter. Meaning a
  // resistor serial. If you set internal pullup, that will create a voltage
  // divider on the GPIO.
  pinMode(NEXT_BUTTON, INPUT);
  pinMode(PREVIOUS_BUTTON, INPUT);
  pinMode(INC_VOLUME_BUTTON, INPUT);
  pinMode(DEC_VOLUME_BUTTON, INPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(LED_SWITCH_STATE_BUTTON, INPUT);
  // ---------------------------------------------------------------------------

  // ---------------------------------------------------------------------------
  // Add interrupts for Button 1 and 2 to change led-mode and play-mode to 100%
  // ---------------------------------------------------------------------------

  // attachPCINT(digitalPinToPCINT(LED_SWITCH_STATE_BUTTON), switchledMode, FALLING);
  // attachPCINT(digitalPinToPCINT(PAUSE_PLAY_BUTTON), pausePlay, FALLING);
  attachInterrupt(digitalPinToInterrupt(LED_SWITCH_STATE_BUTTON), switchledMode, FALLING);
  attachInterrupt(digitalPinToInterrupt(PAUSE_PLAY_BUTTON), pausePlay, FALLING);
  // ---------------------------------------------------------------------------

  // ---------------------------------------------------------------------------
  // Setup LED strip, serial communication to amplifier for speaker
  // ---------------------------------------------------------------------------
  strip.begin(); // Initialize the strip
  strip.show();  // Initialize all pixels to 'off'
  delay(1000);   // is needed so amplifier boots up before arduino
  // tries to connect to it
  mySerial.begin(9600);
  myDFPlayer.begin(mySerial);
  // ---------------------------------------------------------------------------

  // ---------------------------------------------------------------------------
  // Start playing music
  // ---------------------------------------------------------------------------
  myDFPlayer.volume(5); // set initial volume
  myDFPlayer.play(1);   // play first track
  // ---------------------------------------------------------------------------

  // ---------------------------------------------------------------------------
  // Turns on control LED.
  // ---------------------------------------------------------------------------
  digitalWrite(LED_BUILTIN, HIGH);
  // ---------------------------------------------------------------------------
}

void loop()
{
  // ---------------------------------------------------------------------------
  //  Check if any button is pressed
  // ---------------------------------------------------------------------------
  if (shouldPlay)
  {
    if (isPlaying)
    {
    }
    else
    {
      myDFPlayer.start(); // If interrupt changes shouldPlay state it'Ll
      // play the song if it wasn't playing
      isPlaying = 1; // Turns of Play State after stopping music
    }
  }
  else
  {
    if (isPlaying)
    {
      myDFPlayer.pause();
      isPlaying = 0;
    }
    else
    {
    }
  }
  if (digitalRead(NEXT_BUTTON) == LOW)
  {
    myDFPlayer.next(); // plays next song if next-button is pressed low
  }
  if (digitalRead(PREVIOUS_BUTTON) == LOW)
  {
    myDFPlayer.previous();
  }
  if (digitalRead(DEC_VOLUME_BUTTON) == LOW)
  {
    myDFPlayer.volumeDown();
    myDFPlayer.volumeDown();
  }
  if (digitalRead(INC_VOLUME_BUTTON) == LOW)
  {
    myDFPlayer.volumeUp();
    myDFPlayer.volumeUp();
  }
  // ---------------------------------------------------------------------------

  // ---------------------------------------------------------------------------
  // NTC Setup
  // ---------------------------------------------------------------------------
  int tempReading = analogRead(THERMISTOR); // Reads voltage level of NTC

  double tempK = log(10000.0 * ((1024.0 / tempReading - 1)));
  // ex. for 10K voltage divider. NTC->VCC
  // calculates T in Kelvin by taking voltage level and dividing it by 1024
  // resolution. Formular?
  tempK = 1 / (0.001129148 + (0.000234125 + (0.0000000876741 * tempK * tempK)) * tempK); //  Temp Kelvin
  float tempC = tempK - 273.15;                                                          // Convert Kelvin to Celcius
  // Serial.println("Analog Value: " + String(tempReading)); // This is OK
  //  Serial.println("Temperature in Celsius: " + String(tempC, 2));
  // ---------------------------------------------------------------------------

  // ---------------------------------------------------------------------------
  // Switches LED Mode depending on how often you pressed the led-mode-button
  // ---------------------------------------------------------------------------
  switch (ledMode)
  {
  case 1:
    randomChristmasBalls(10, BRIGHTNESSLEVEL);
    // uses special function which was defined in selfwritten library.
    // Todo: how to jump to lib and read param and description.
    break;
  case 2:
    specialFadeEffect(10, BRIGHTNESSLEVEL);
    break;
  case 3:
    tempBasedLedFaded(tempC, BRIGHTNESSLEVEL);
    break;
  case 4:
    tempBasedLed(tempC, BRIGHTNESSLEVEL);
    break;

  // -------------------------------------------------------------------------
  // Example
  // -------------------------------------------------------------------------
  case 5:

    // Following code shows example of how you use neopixel lib to write LEDs

    for (int i = 0; i < strip.numPixels(); i++)
    // iterrates through all LEDs(pixel) by counting from led 0 till led 17
    // => 18 leds. All will be set according to the following code.

    {
      strip.setPixelColor(i, strip.Color(255, 255, 255));
      // sets color for one LED(pixel) i which consists of 3 diods(RGB).
      // Eg.Red = 255, Green = 255, Blue = 255 => White_max.
    }

    strip.show();
    // After all colors have been set, the strip will be updated now.
    break;
    // -------------------------------------------------------------------------

  case 6:
    for (int i = 0; i < strip.numPixels(); i++)
    {
      strip.setPixelColor(i, strip.Color(0, 0, 0));
      // Red = 0, Green = 0, Blue = 0 => OFF
    }
    strip.show();
    break;
  }
  // ---------------------------------------------------------------------------
}

// -----------------------------------------------------------------------------
// Interrupt Functions
// -----------------------------------------------------------------------------
void switchledMode()
{
  ledMode++;
  if (ledMode == 7)
  { // allows for 6 modes. 7 will be 1 again.
    ledMode = 1;
  }
}

void pausePlay()
{
  shouldPlay = !shouldPlay;
}
// -----------------------------------------------------------------------------
