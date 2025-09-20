# Dam-Water-Level-Sensing-and-Alert-System

Overview
The Dam Water Level Sensing and Alert System is an IoT-based solution designed to monitor water levels in dams in real-time. The system provides automatic alerts when water levels cross predefined thresholds, helping authorities take timely preventive actions to avoid flooding or water shortages.

Objective
To continuously monitor water levels in a dam.
To provide real-time alerts via buzzer and display.
To ensure safety and efficient water management using IoT technology.

Features
Real-time water level monitoring.
Threshold-based alerts using buzzer and LEDs.
LCD display for current water level.
User-configurable high and low water level thresholds.
IoT integration for remote monitoring (optional, via Blynk or other platforms).

Components Required
Hardware:
ESP32 Microcontroller
Ultrasonic Sensor (HC-SR04 or similar)
Buzzer
LEDs (Red & Blue)
I2C LCD Display
Breadboard & Jumper Wires
Power Supply (Battery or Adapter)

Software:
Arduino IDE
Blynk Cloud (optional for IoT integration)

System Architecture
The system consists of three main modules:
Sensing Module: Ultrasonic sensor detects the water level in the dam.
Processing Module: ESP32 reads sensor data, compares it with threshold values, and triggers alerts.
Alert & Display Module: Alerts are displayed on the LCD, buzzer, and LEDs. Optionally, the system can send data to Blynk Cloud for remote monitoring.

Working Principle
The ultrasonic sensor continuously measures the distance between the sensor and the water surface.
ESP32 calculates the water level based on the distance measured.
If water exceeds the high-level threshold, the system triggers a red LED and buzzer alert.
If water drops below the low-level threshold, the system triggers a blue LED.
Current water level is displayed in real-time on the LCD display.
Optional: Water level data can be sent to an IoT dashboard for remote monitoring.

Circuit Diagram
VCC of sensor → 5V of ESP32
GND of sensor → GND of ESP32
TRIG → GPIO 5
ECHO → GPIO 18
Buzzer → GPIO 19
Red LED → GPIO 4
SDA & SCL → ESP32 I2C pins for LCD

Software Implementation
Arduino IDE is used for programming the ESP32.
The program reads the ultrasonic sensor data, calculates the water level, and triggers alerts accordingly.
Optional Blynk integration allows sending real-time water level data to a smartphone app.

Key Libraries Used:
Wire.h for I2C communication with LCD
LiquidCrystal_I2C.h for LCD display
BlynkSimpleEsp32.h (optional) for IoT integration

Installation & Usage
Connect the hardware as per the circuit diagram.
Install required Arduino libraries.
Upload the code to ESP32 via Arduino IDE.
Adjust high and low water level thresholds in the code as per dam specifications.
Power on the system.
Monitor water level and receive alerts via buzzer, LEDs, and LCD.
(Optional) Connect ESP32 to Blynk Cloud for remote monitoring.

Future Enhancements
Integration with GSM module for SMS alerts.
Cloud-based analytics for predicting flood conditions.
Automated water release system based on water level thresholds.
Integration with multiple sensors for monitoring multiple dam sections.

Authors
Aman Vishwash Singh – Embedded engineer

This project is licensed under the MIT License – see the LICENSE
 file for details.
