#include <Arduino.h>
#include "Operator.h"

/*
1. Comparison Operators
- These operator compare 2 values and return a Boolean result:
- true(1), if the condition is correct
- false(0), if the condition is incorrect
- < refers LESS THAN
- > refers GREATER THAN
- <= refers LESS THAN OR EQUAL TO
- >= refers GREATER THAN OR EQUAL TO
- == refers EQUAL TO (COMPARISON)
- != refers NOT EQUAL TO

2. Logical Operators
- are used to combine multiple conditions together
- AND (&&) refers TRUE IF BOTH CONDITIONS ARE TRUE
- OR (or) refers true if at least one is true
- NOT (!) refers reverse the value 

*/

int temp = 28;
int humidity = 60;

void operatorSetup(){
    if (temp >25 && humidity < 70){
        Serial.println("Weather is okay"); //BOTH Condition must be true
    }    

    //NOT example:
    bool isOn = LOW;
    if (!isOn){
        Serial.println("System is OFF"); //~!false = true
    }

    //OR example:
    if (!isOn || isOn){
        Serial.println("System is ON or OFF");
    }
}

void operatorLoop(){

}