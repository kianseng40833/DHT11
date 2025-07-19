#include <Arduino.h>
#include "IntroSerial.h"

void introSerialSetup(){
    Serial.print("Hi, this is Parrot~~");
    Serial.println(" Nice to Meet U!");

}

void introSerialLoop(){
    Serial.println("Blink");
    delay(500);
}