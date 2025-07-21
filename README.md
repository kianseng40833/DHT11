🌡️ DHT11 Temperature & Humidity Display with OLED and LED Alerts
This Arduino-based project is a compact environmental monitoring system that reads real-time temperature and humidity from a DHT11 sensor, and displays the results on a 0.96" OLED screen (SSD1306). It also features a LED indicator system to visually alert users about different environmental conditions.

💡 This project is great for:

Beginner Arduino learners

Real-time sensor monitoring

Mini IoT environmental stations

DIY hobby or educational demos

🧠 What It Does
📊 Reads humidity and temperature from the DHT11 sensor.

🖥️ Displays live readings on an OLED display (128x64 via I2C).

🚦 Triggers LED indicators based on environmental condition ranges:

🟢 Green = Ideal

🔴 Red = Alert (Cold/Hot/Dry/Humid)

⚠️ Blue or any custom color = Unusual

⚙️ How It Works (Code Summary)
The OLEDSetup() function:

Initializes serial, OLED, DHT sensor, and LED pins.

Displays a welcome message.

The OLEDLoop() function:

Reads temperature and humidity values.

Handles sensor errors (like NaN values).

Displays current readings.

Determines environment status with if-else logic.

Lights up corresponding LED.

cpp
Copy
Edit
if (t < 18 && h < 40) {
  display.println("Cold & Dry");
  digitalWrite(LED_ALERT, HIGH);
}
All logic is neatly modularized in a custom header file: OLEDwDHT11.h.

