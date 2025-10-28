#include <Arduino.h>
#include <SoftwareSerial.h>

#define GRN_LED 16
#define YLW_LED 17
#define RED_LED 18

void blinkLedTwice (int LED_PIN);

void setup ()
{
  Serial.begin(9600);
  Serial.println("The Program is starting now");
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(GRN_LED, OUTPUT);
  pinMode(YLW_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);
}

void loop ()
{
  blinkLedTwice(GRN_LED);
  blinkLedTwice(RED_LED);
}

void blinkLedTwice (int LED_PIN)
{
  Serial.println("LEDS: ON");
  digitalWrite(LED_PIN, HIGH);
  delay(500);
  Serial.println("LEDS: OFF");
  digitalWrite(LED_PIN, LOW);
  delay(500);

  Serial.println("LEDS: ON");
  digitalWrite(LED_PIN, HIGH);
  delay(500);
  Serial.println("LEDS: OFF");
  digitalWrite(LED_PIN, LOW);
  delay(500);
}
