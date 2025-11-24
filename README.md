ESP32 Motion + Light Detection System

This project uses an ESP32 with a PIR motion sensor and an LDR (light sensor) to detect movement only in low-light conditions. When motion is detected and the light level is below a threshold, the ESP32 triggers an LED (or any output device). This demonstrates embedded programming, sensor integration, and IoT-style event logic.

 Features

PIR-based motion detection (GPIO 33)

LDR light measurement using ADC (GPIO 27, 0–4095 range)

LED activation on low-light motion detection (GPIO 2)

Serial debugging output for monitoring sensor values

Adjustable light threshold for different environments

Automatic PIR stabilization delay

 Hardware Connections
Component	ESP32 Pin
PIR OUT	GPIO 33
LDR (Analog)	GPIO 27
LED	GPIO 2

Use Cases

Smart night-light activation

Home security and motion alert systems

Energy-efficient room lighting

Basic IoT automation and sensing projects

📄 Code Overview

The main logic:

Reads motion via digitalRead()

Reads light level via analogRead()

Classifies light as Bright, Medium, or Dark

Turns LED ON only when

Motion is detected

Light value is above the lightThreshold (meaning dark)
