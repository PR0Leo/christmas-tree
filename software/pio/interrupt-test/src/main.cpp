#include "pins_arduino.h"
#include <Arduino.h>

// #define LED_GRN 16
// #define LED_YLW 17
// #define LED_RED 18
#define LED_BUILTIN 13
#define BUTTON 2

volatile boolean LedState = 1;

void myISRFunction();


void setup (){

//   pinMode(LED_GRN, OUTPUT);
//   pinMode(LED_YLW, OUTPUT);
//   pinMode(LED_RED, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(BUTTON, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(BUTTON), myISRFunction, LOW);

  digitalWrite(LED_BUILTIN, HIGH);
  delay(1000);
  digitalWrite(LED_BUILTIN, !LedState);
}

void loop ()
{
//   digitalWrite(LED_GRN, HIGH);
//   if (!digitalRead(BUTTON)){
//     digitalWrite(LED_BUILTIN, !LedState);
//     LedState = !LedState;
//   }
// delay(500);

}

void myISRFunction()
{
    digitalWrite(LED_BUILTIN, !LedState);
    LedState = !LedState;
}
