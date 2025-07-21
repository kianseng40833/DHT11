#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>
#include <Wire.h>
#include <DHT.h>
#include <OLEDwDHT11.h>

//OLED Config
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
Adafruit_SSD1306 display(SCREEN_WIDTH,SCREEN_HEIGHT,&Wire, -1);

//DHT Config
#define DHTPIN 11
#define DHTTYPE DHT11 
DHT dht(DHTPIN, DHTTYPE);

//LED Config
#define LED_GOOD 7
#define LED_ALERT 3
#define LED_DANGER 2

void OLEDSetup(){
    Serial.begin(9600);
    Serial.println("Test");

    if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
        Serial.println("Something very longgg");
        while(true);
    }
    
    Serial.println("OLED FOUND!");
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(0,0);
    display.println("DHT11 - Humidity & Temperature Project");
    display.display();
    delay(3000);


    pinMode(LED_GOOD,OUTPUT);
    pinMode(LED_ALERT,OUTPUT);
    pinMode(LED_DANGER,OUTPUT);

    dht.begin();
    Serial.println("DHT11 Module Found!");
}

void OLEDLoop(){
    float h = dht.readHumidity();
    float t = dht.readTemperature();

    display.clearDisplay();

    if(isnan(t) || isnan(h)){ //isnan = is not a number or t = NAN;
        Serial.println("DHT11 Problem Exists - Can't retrieve Temperature or Humidity data.");
        display.setTextSize(1);
        display.setCursor(0,0); //top-left corner
        display.println("Sensor Problem!");
        display.display();
        delay(3000); 
        return; //Stops the current function (usually loop()), prevents the rest of the code (like using broken sensor values)
    }

    digitalWrite(LED_GOOD,LOW);
    digitalWrite(LED_ALERT,LOW);
    digitalWrite(LED_DANGER,LOW);

    display.setCursor(0,0);
    display.setTextSize(2);
    display.print("T: "); display.print(t); display.println(" C");
    display.print("H: "); display.print(h); display.println(" %");
    Serial.print("T: "); Serial.print(t); Serial.println(" C");
    Serial.print("H: "); Serial.print(h); Serial.println(" %");
    display.display();

    display.setTextSize(2);

  // Condition Logic
    if (t < 18 && h < 40) {
        display.println("Cold & Dry");
        Serial.println("Cold & Dry");
        digitalWrite(LED_ALERT, HIGH);
    } else if (t < 18 && h >= 40 && h <= 60) {
        display.println("Cold & Moderate");
        Serial.println("Cold & Moderate");
        digitalWrite(LED_ALERT, HIGH);
    } else if (t < 18 && h > 60) {
        display.println("Cold & Humid");
        Serial.println("Cold & Humid");
        digitalWrite(LED_ALERT, HIGH);
    } else if (t >= 18 && t <= 28 && h >= 40 && h <= 60) {
        display.println("Ideal");
        Serial.println("Ideal");
        digitalWrite(LED_GOOD, HIGH);
    } else if (t >= 18 && t <= 28 && h < 40) {
        display.println("Cool & Dry");
        Serial.println("Cool & Dry");
        digitalWrite(LED_ALERT, HIGH);
    } else if (t >= 18 && t <= 28 && h > 60) {
        display.println("Cool & Humid");
        Serial.println("Cool & Humid");
        digitalWrite(LED_ALERT, HIGH);
    } else if (t > 28 && h < 40) {
        display.println("Hot & Dry");
        Serial.println("Hot & Dry");
        digitalWrite(LED_ALERT, HIGH);
    } else if (t > 28 && h >= 40 && h <= 60) {
        display.println("Hot & Moderate");
        Serial.println("Hot & Moderate");
        digitalWrite(LED_ALERT, HIGH);
    } else if (t > 28 && h > 60) {
        display.println("Hot & Humid");
        Serial.println("Hot & Humid");
        digitalWrite(LED_ALERT, HIGH);
    } else {
        display.println("Unusual!");
        Serial.println("Unusual!");
        digitalWrite(LED_DANGER, HIGH);
    }


    display.display();
    delay(3000);
}
