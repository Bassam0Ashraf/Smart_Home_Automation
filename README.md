# Smart Home Automation System

## 📖 Project Overview  
Develop a smart home system using ATmega32 microcontroller to automate lighting, fan speed control, and fire detection with real-time display on an LCD.

## 🎯 Objectives  
- Control lighting levels based on ambient light intensity using an LDR sensor.  
- Adjust fan speed dynamically based on temperature readings from an LM35 sensor.  
- Detect fire and trigger alerts using a flame sensor, buzzer, and LCD display.  
- Display real-time system status on a 16x2 LCD.

## 💡 Features  
- **Lighting Control:** Automatic adjustment of three LEDs (Red, Green, Blue) based on LDR intensity thresholds.
- **Fan Speed Control:** Dynamic fan speed via PWM based on LM35 temperature ranges.
- **Fire Detection:** Immediate alert with buzzer and LCD display when fire is detected.
- **LCD Display:** Real-time temperature, light intensity, and fan status display.

## 📚 System Hardware & Components  
- **Microcontroller:** ATmega32.
- **Sensors:** LDR for light, LM35 for temperature, flame sensor for fire detection.
- **Display:** 16x2 LCD (8-bit mode).
- **Actuators:** DC-motor controlled via H-Bridge, buzzer for alerts.
- **Visual Indicators:** Three LEDs representing light levels.
- **Software:** C, Proteus, Eclipse.
- **Design:** Modular code for lighting, fan control, and fire detection.


## 🚀 Implementation Highlights  
- **Lighting Logic:**
  - <15%: All LEDs ON.
  - 16–50%: Red & Green LEDs ON.
  - 51–70%: Red LED ON.
  - >70%: All LEDs OFF.
- **Fan Speed Logic:**
  - ≥40°C: 100% speed.
  - 35–40°C: 75% speed.
  - 30–35°C: 50% speed.
  - 25–30°C: 25% speed.
  - <25°C: Fan OFF.
- **Fire Alert Logic:** Flame sensor detection triggers buzzer and displays "Critical alert!" on LCD.
- **LCD Feedback:**
  - Row 1: "FAN is ON" or "FAN is OFF".
  - Row 2: "Temp= xxC LDR= xxx%".

![Smart Home System](https://github.com/user-attachments/assets/ae9747bc-f58f-4bb3-8f26-d5a0cdfd34b0)
