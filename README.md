# ESP32 Motion + Light Detection System

An embedded C++ sketch for the ESP32 that combines a PIR motion sensor and an LDR light sensor to trigger outputs only under low-light conditions. Demonstrates sensor fusion, ADC reading, GPIO control, and serial debugging on a microcontroller.

## How It Works

1. The LDR measures ambient light via analog read (0–4095)
2. 2. The PIR sensor detects motion via digital read
   3. 3. If motion is detected **and** light is below threshold, the LED activates
      4. 4. Sensor values stream to Serial Monitor for real-time debugging
        
         5. ## Features
        
         6. - PIR motion detection on GPIO 33
            - - LDR ambient light measurement on GPIO 27 (ADC)
              - - LED output on GPIO 2
                - - Light classified as Bright / Medium / Dark based on configurable threshold
                  - - Automatic PIR warm-up delay on startup
                    - - Serial output for live sensor monitoring
                     
                      - ## Hardware
                     
                      - | Component | ESP32 Pin |
                      - |---|---|
                      - | PIR sensor OUT | GPIO 33 |
                      - | LDR (analog) | GPIO 27 |
                      - | LED | GPIO 2 |
                      - | GND | GND |
                      - | VCC | 3.3V / 5V |
                     
                      - ## Setup
                     
                      - 1. Wire components per the table above
                        2. 2. Open `sketch.ino` in Arduino IDE
                           3. 3. Select board: **ESP32 Dev Module**
                              4. 4. Upload and open Serial Monitor at **115200 baud**
                                 5. 5. Adjust `lightThreshold` in the sketch to calibrate for your environment
                                   
                                    6. ## Use Cases
                                   
                                    7. - Smart night-light that only activates in the dark
                                       - - Low-power motion alert systems
                                         - - Energy-efficient room automation
                                           - - Entry-level IoT sensing and event-driven logic
                                            
                                             - ## Tech Stack
                                            
                                             - - C++ (Arduino framework)
                                               - - ESP32 Dev Module
                                                 - - PIR sensor (HC-SR501 or equivalent)
                                                   - - LDR + voltage divider
                                                     - - Arduino IDE
