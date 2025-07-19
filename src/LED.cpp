#include <Arduino.h>

void LEDsetup(){
 pinMode(11, OUTPUT);
 pinMode(3,OUTPUT);
 pinMode(2,OUTPUT);
}
void LEDloop(){
  int temperature = random(0,20);

  if (temperature > 15){
   	digitalWrite(11, HIGH);
    delay(1500);
    digitalWrite(11,LOW);
    Serial.println("Green LED Blink...");

  }else if(temperature > 10 && temperature <= 15){
   	digitalWrite(3,HIGH);
    delay(1500);
    digitalWrite(3,LOW);
    Serial.println("Yellow LED Blink...");  
}else{
   	digitalWrite(2,HIGH); 
    delay(1500);
    digitalWrite(2,LOW);
    Serial.println("Red LED Blink...");
  }
}