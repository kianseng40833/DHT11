# 🌡️ DHT11 OLED Environmental Monitor

A simple and aesthetic Arduino project that reads **temperature** and **humidity** using the DHT11 sensor, displays the values on an **OLED screen**, and uses **LED indicators** to show the environment status (Cold, Hot, Humid, Dry, or Ideal).

![OLED Demo](images/oled_demo.jpg)

---

## 📸 Video Demo

<video src="videos/demo.mp4" controls width="600">
  Your browser does not support the video tag.
</video>

> 📌 *If video doesn’t load, [click here to watch on YouTube](https://youtu.be/your_video_id)*

---

## 🔧 Features

- 📲 Real-time temperature & humidity monitoring
- 🖥️ OLED display with environmental status
- 🚦 LED alerts:
  - 🟢 Green = Ideal
  - 🔴 Red = Alert (Temp/Humidity issue)
  - ⚠️ Blue = Unusual condition
- 🔁 Continuous looping with error handling
- 📦 Clean, modular structure using a custom `.h` file

---

## 🛠️ Wiring Diagram

| Component    | Pin       |
|--------------|-----------|
| DHT11 VCC    | 5V        |
| DHT11 GND    | GND       |
| DHT11 DATA   | D11       |
| OLED VCC     | 3.3V or 5V|
| OLED GND     | GND       |
| OLED SDA     | A4        |
| OLED SCL     | A5        |
| LED_GREEN    | D7        |
| LED_RED      | D3        |
| LED_BLUE     | D2        |

> Note: Replace color LED pins based on your LED configuration.

---

## 📦 Libraries Used

Make sure you install these in the Arduino IDE:

- [`Adafruit_SSD1306`](https://github.com/adafruit/Adafruit_SSD1306)
- [`Adafruit_GFX`](https://github.com/adafruit/Adafruit-GFX-Library)
- [`DHT Sensor Library`](https://github.com/adafruit/DHT-sensor-library)

---

## 📁 Project Structure

