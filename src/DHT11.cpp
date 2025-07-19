#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <DHT.h>

// OLED Config
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

// DHT Config
#define DHTPIN 7
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

// LED Pins
#define LED_NORMAL 11
#define LED_ALERT 3
#define LED_DANGER 2

void DHT11Setup() {
  Serial.begin(9600);

  // Setup OLED
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println("OLED Not Found! Check wiring or I2C address.");
    while (true);
  }
  Serial.println("OLED Found!");

  // Setup LEDs
  pinMode(LED_ALERT, OUTPUT);
  pinMode(LED_DANGER, OUTPUT);
  pinMode(LED_NORMAL, OUTPUT);

  // Setup DHT
  dht.begin();

  // Startup screen
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 20);
  display.println("HELLO");
  display.display();
  delay(2000);
}

void DHT11Loop() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  display.clearDisplay();

  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read from DHT11!");
    display.setTextSize(1);
    display.setCursor(0, 0);
    display.println("Sensor Error!");
    display.display();
    delay(3000);
    return;
  }

  Serial.print("Temp: "); Serial.print(t); Serial.print(" C  ");
  Serial.print("Humidity: "); Serial.print(h); Serial.println(" %");

  // Display values
  display.setTextSize(2);  // Bigger text
  display.setCursor(0, 0);
  display.print("T: "); display.print(t); display.println(" C");
  display.print("H: "); display.print(h); display.println(" %");

  // Reset all LEDs
  digitalWrite(LED_NORMAL, LOW);
  digitalWrite(LED_ALERT, LOW);
  digitalWrite(LED_DANGER, LOW);

  display.setTextSize(1);  // Smaller for condition
  display.setCursor(0, 48);

  // Condition Logic
  if (t < 18 && h < 40) {
    display.println("Cold & Dry");
    digitalWrite(LED_ALERT, HIGH);
  } else if (t < 18 && h > 60) {
    display.println("Cold & Humid");
    digitalWrite(LED_ALERT, HIGH);
  } else if (t >= 18 && t <= 28 && h >= 40 && h <= 60) {
    display.println("Ideal Environment");
    digitalWrite(LED_NORMAL, HIGH);
  } else if (t > 27 && h < 40) {
    display.println("Hot & Dry");
    digitalWrite(LED_ALERT, HIGH);
  } else if (t > 27 && h > 60) {
    display.println("Hot & Humid");
    digitalWrite(LED_ALERT, HIGH);
  } else {
    display.println("Unusual Condition!");
    digitalWrite(LED_DANGER, HIGH);
  } 

  display.display();
  delay(1000);
}
