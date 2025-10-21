#include <Arduino.h>
#include <SoftwareSerial.h>
#include <DFRobotDFPlayerMini.h>
#include "avr8-stub.h"
#include "app_api.h"

// DFPlayer connection
SoftwareSerial mp3Serial(10, 11); // RX, TX
DFRobotDFPlayerMini myDFPlayer;

// Logging connection (use external USB-Serial adapter on pins 8/9)
// SoftwareSerial logSerial(8, 9);   // RX, TX

void setup()
{
  debug_init(); // avr8-stub debugging on Serial (USB)

  // logSerial.begin(9600);         // start logging serial
  // logSerial.println("Booting...");

  mp3Serial.begin(9600); // DFPlayer serial
  myDFPlayer.begin(mp3Serial);

  breakpoint(); // stop in debugger
  myDFPlayer.volume(5);
  myDFPlayer.play(1);
  breakpoint(); // stop in debugger

  //  logSerial.println("DFPlayer ready, playing track 1");
  breakpoint(); // pause in debugger
}

void loop()
{
  static bool playedNext = false;

  if (!playedNext)
  {
    myDFPlayer.next();
    //  logSerial.println("Next track triggered");
    playedNext = true;
    breakpoint(); // inspect in debugger
  }

  delay(1000);
}
