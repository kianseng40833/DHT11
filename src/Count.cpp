#include <Arduino.h> //This line tells the PLatformIO to include Arduino functions (like Serial, pinMode, digitalWrite, etc)
//If using Arduino IDE, no need to write this, it is added automatically.
#include "Count.h"

/*Serial Monitor = a live text communication window between your Arduino and your computer
  It allows your Arduino to send messages (output) or receive messages (input) using a USB cable. It's mainly used for debugging, monitoring sensor values, or sending commands to Arduino
*/

//When Press Upload:
/*
  1. Compiles your Arduino code (.ino or .cpp)
  2. Sends/Upload the compile program (firmare) to your Arduino via USB
  3. Shows a Terminal with progress logs (e.g., "Uploading...Success!")
  BUT... that upload terminal is not the Serial Monitor
  That is just a terminal windows for the upload process only. It doesn't show your Serial.println output.
*/

//Why must open Serial Monitor Separately
/*
Serial Monitor is a separate process from uploading.
  1. Upload uses the USB port to send code -> this resets Arduino automatically.
  2. After uploading, the serial port becomes busy, and PlatformIO does not automatically re-open the Serial Monitor (to avoid clashes)

  Therefore, Serial Monitor:
    - is a live chat window between your Arduino and your computer.
    - Arduino can send messages to your computer
    - You can read those messages live in Serial Monitor
    - You can even send messages back
    - Common uses:
      - Debugging (see what is going on)
      - Viewing sensor data
      - Controlling devices via keyboards
  */

void countSetup() {
//Starts communication at 9600 baud (speed unit). Always needed before using Serial.print
  /*
    9600 is the baud rate, or speed of data transmission between Arduino and your computer.
    It means 9600 bits per second (bps)
    It is the most common, safe default for Serial Monitor.
    other:
      4800, 9600, 19200, 38400, 57600, 115200 (faster)
    Both Arduino and Serial Monitor must match this value.
    Wrong baud rate = garbage output in Serial Monitor.
  */
 
  //Serial.println("Hello from Parrot~~~~"); //Send this message to Serial Monitor, adds a new line at the end.
}

void countLoop() {
  // Serial.println("Blink..."); //Print "Blink..." on a new line every second
  // delay(1000); //1000ms = 1 second for delay

  static int count = 0; 
  /*
    Static means the variable keeps its value between function calls.
    Without static, the variable resets every time loop() starts again.
    Static int count = 0; this will only run once, even though loop() runs many times.
  */
  Serial.print("Count: ");
  Serial.println(count);
  count++;
  delay(500);
}


