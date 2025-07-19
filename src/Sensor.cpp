#include <Arduino.h>
#include "Sensor.h"


void sensorSetup(){

}

void sensorLoop(){
    int sensorValue = random(300,800); // Fake sensor value
    Serial.print("Sensor: ");
    Serial.println(sensorValue);
    delay(1000);
}