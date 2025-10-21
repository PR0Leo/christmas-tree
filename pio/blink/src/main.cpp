#include <Arduino.h>
#include <SoftwareSerial.h>

#define GRN_LED 16
#define YLW_LED 17
#define RED_LED 18

void setup ()
{
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(GRN_LED, OUTPUT);
  pinMode(YLW_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);
}

void loop ()
{
  Serial.println("LEDS: ON");
  digitalWrite(LED_BUILTIN, HIGH);
  digitalWrite(GRN_LED, HIGH);
  digitalWrite(YLW_LED, HIGH);
  digitalWrite(RED_LED, HIGH);
  delay(1000);
  Serial.println("LEDS: OFF");
  digitalWrite(LED_BUILTIN, LOW);
  digitalWrite(GRN_LED, LOW);
  digitalWrite(YLW_LED, LOW);
  digitalWrite(RED_LED, LOW);
  delay(1000);
}
