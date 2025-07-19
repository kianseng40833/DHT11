#include <Arduino.h>
bool isLow = LOW; //OR false

void textVarSetup(){

}

void textVarLoop(){
    int temp = random(20,40);
    Serial.println("Temperature " + String(temp) + " °C");
    delay(1000);
}