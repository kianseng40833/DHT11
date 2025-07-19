#include <Arduino.h>
#include "Count.h"
#include "IntroSerial.h"
#include "Sensor.h"
#include "TextVar.h"
#include "Operator.h"
#include "LED.h"
#include "DHT11.h"

void setup(){
  Serial.begin(9600);
  DHT11Setup();
}

void loop(){
  DHT11Loop();
}