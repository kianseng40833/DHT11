#include <Arduino.h>
/*
    Scope
    - refers to where a variable can be accessed in your code. 
    - It defines the visibility and lifetime of a variable
    - In Arduino, there are 2 main types of scope: 
        - Global 
        - Local

    Global Variable
    - is devlared outisde of all functions
    - can be used in any function throughout the entire file

    **Extra**
    1. Variable Shadowing
    - Same variable name in different scopes

    2. Why use local variable?
    - Avoid conflicts between function
    - Reduce bugs from unwanted changes
    - Keep memory usage low (locals are destroyed after function finishes.)
*/

int myGlobal = 789;

void variableSetup(){
    /*
        Local Variable
        - is declared inside a function or block (like inside setup(0, loop(), or even inside an if statement))
        - Only visible within that function or block.
    */
    
    Serial.println("Setup: " + String(myGlobal));
    int myLocal = 852;
    Serial.println("Setup: " + String(myLocal)); 
}

void variableLoop(){
    Serial.println("Loop: " + String(myGlobal));
    delay(1000);

    //Serial.println(myLocal); //Error: myLocal is not visible here
}