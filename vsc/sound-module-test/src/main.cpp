//#include "avr8-stub.h"
//#include "app_api.h"
#include <Arduino.h>
#include <SoftwareSerial.h>
// #include <HardwareSerial.h>
#include <DFRobotDFPlayerMini.h>

SoftwareSerial mySerial(10, 11); // RX, TX
DFRobotDFPlayerMini myDFPlayer;

int buttonNext = 5;
int buttonPause = 4;
int buttonPrevious = 3;
int buttonIncVolume = 6;
int buttonDecVolume = 2;
boolean isPlaying = false;

void setup()
{
  //debug_init();
  pinMode(buttonPause, INPUT_PULLUP);
  pinMode(buttonNext, INPUT_PULLUP);
  pinMode(buttonPrevious, INPUT_PULLUP);
  pinMode(buttonIncVolume, INPUT_PULLUP);
  pinMode(buttonDecVolume, INPUT_PULLUP);

  mySerial.begin(9600);
  if (!myDFPlayer.begin(mySerial))
  {
    while (true)
      ; // stop if DFPlayer not found
  }

  myDFPlayer.volume(5); // set initial volume
  myDFPlayer.play(1);   // play first track
  isPlaying = true;
}

void loop()
{
  if (digitalRead(buttonPause) == LOW)
  {
    if (isPlaying)
    {
      myDFPlayer.pause();
      isPlaying = false;
    }
    else
    {
      myDFPlayer.start();
      isPlaying = true;
    }
    delay(150); // simple debounce
  }

  if (digitalRead(buttonNext) == LOW)
  {
    myDFPlayer.next();
    delay(150);
  }

  if (digitalRead(buttonPrevious) == LOW)
  {
    myDFPlayer.previous();
    delay(150);
  }

  if (digitalRead(buttonDecVolume) == LOW)
  {
    myDFPlayer.volumeDown();
    delay(150);
  }

  if (digitalRead(buttonIncVolume) == LOW)
  {
    myDFPlayer.volumeUp();
    delay(150);
  }
  delay(500);
}
