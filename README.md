# **Project Overview:**
This project involves developing a smart home system that adjusts lighting, fan speed, and safety
alerts based on environmental conditions:
1. **Lighting Control:**
    - The LDR detects ambient light intensity and controls three LEDs to indicate different levels of light.
2. **Fan Speed Control:**
   - The LM35 temperature sensor adjusts the fan speed proportionally to the room temperature.
3. **Fire Detection:**
   - A flame sensor detects fire, triggers an alarm, and displays a critical alert on the LCD.
4. **LCD Display:**
   - Shows real-time temperature readings, fan status, light intensity, and alerts.

 # **Features:**
### 1. **Automatic Lighting Control:**
Based on the LDR readings, the system controls three LEDs according to light intensity thresholds:
- Intensity < 15%: All 3 LEDs (Red, Green, and Blue) turn ON.
- Intensity 16–50%: Red and Green LEDs turn ON.
- Intensity 51–70%: Only the Red LED turns ON.
- Intensity > 70%: All LEDs are turned OFF.


### 2. **Automatic Fan Speed Control:**
Fan speed is automatically adjusted based on room temperature, controlled by a PWM signal. The fan operates at different speeds based on
temperature ranges:
- Temperature ≥ 40°C: Fan ON at 100% speed.
- Temperature ≥ 35°C and < 40°C: Fan ON at 75% speed.
- Temperature ≥ 30°C and < 35°C: Fan ON at 50% speed.
- Temperature ≥ 25°C and < 30°C: Fan ON at 25% speed.
- Temperature < 25°C: Fan OFF.
  
### 3.  **Fire Detection and Alert:**
The system raises an alarm and displays "Critical alert!" on the LCD if fire is detected. The system remains in alert mode until the flame is no longer detected.

### 4. **LCD Display:**
   Real-time feedback on system status:
- First Row: Displays "FAN is ON" or "FAN is OFF" based on the fan's state.
- Second Row: Displays "Temp= xxC LDR= xxx%" showing temperature and light intensity.


# **Hardware Components:**
 1. **Microcontroller:** ATmega32.
 2. **Light Sensor:** LDR.
 3. **Temperature Sensor:** LM35 Temperature Sensor.
 4. **Display:** 16x2 LCD in 8-bit mode.
 5. **Motor Control:** H-Bridge.
 6. **Motor:** DC-motor.
 7. **LEDs:** Red,Green and Blue.
 8. **Flame Sensor:** to detect fire.
 9. **Buzzer:** activated during fire alert.


![Screenshot 2024-10-26 000256](https://github.com/user-attachments/assets/ae9747bc-f58f-4bb3-8f26-d5a0cdfd34b0)



# **Operation Description:**
### 1. **Lighting Control (LDR):**
- The LDR monitors light intensity, and the three LEDs are controlled based on the previous mentioned thresholds.
### 2. **Temperature Control (LM35):** 
- The LM35 sensor measures room temperature. The fan speed is controlled using a PWM signal adjusting speed according to temperature ranges specified above.
### 3. **Fire Detection:** 
- The flame sensor triggers an alert when fire is detected:
  - Displays "Critical alert!" on the LCD.
  - Activates the buzzer.
  - The system stays in alert mode until the flame sensor no longer detects fire.
### 4. **LCD Display:**
- First Row: Indicates the fan status ("FAN is ON" or "FAN is OFF").
- Second Row: Displays temperature ("Temp= xxx") and light intensity ("LDR= xx%").
