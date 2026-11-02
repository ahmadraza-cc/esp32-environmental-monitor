# esp32-environmental-monitor
# ESP32 Environmental & Safety Alarm System (Simulation)

## Project Description
This is an embedded system project I designed and simulated online using Wokwi. The goal of this project is to create a digital weather and temperature monitor that reads real-time environmental conditions and triggers a safety warning if the temperature gets too high.

I built this project using C++ logic to practice microcontroller programming, digital sensor reading, and display interfacing without physical hardware setup costs.

## Features
- Reads temperature and humidity data using a simulated **DHT22** sensor.
- Displays live readings directly on a **16x2 I2C LCD screen**.
- Transmits status logs over the **Serial Monitor** at 115200 baud rate.
- Turns on a red **Alert LED** whenever the measured temperature exceeds 35°C.

## Hardware Components (Simulated in Wokwi)
- **Microcontroller:** ESP32 Dev Module
- **Sensor:** DHT22 (Connected to GPIO Pin 15)
- **Display:** LCD 1602 with I2C Module (SDA -> GPIO 21, SCL -> GPIO 22)
- **Indicator:** Red LED (Connected to GPIO Pin 2)

## How to Test My Project Live
You can test and run this exact simulation live in your web browser:
👉 [Click Here to Run My Wokwi Simulation](https://wokwi.com/projects/479593515747496961)

### Steps to Run:
1. Open the Wokwi link above.
2. Click the green **Start Simulation** button.
3. Click on the **DHT22 sensor module** during the simulation to move the temperature slider above 35°C and watch the LED turn on!

## Author
- Built & Documented by: [Ahmad Raza]
- Goal: FSc Pre-Engineering Student exploring Embedded Systems, IoT, and C++ Programming.
