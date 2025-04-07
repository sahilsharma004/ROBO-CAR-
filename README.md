# ROBO-CAR

# WiFi Controlled Car with ESP32 and Blynk

This project is a WiFi-controlled car built using the ESP32 and controlled via the Blynk IoT platform. The car can move forward, backward, and turn left or right using button widgets in the Blynk app.

##  Hardware Components
- ESP32 Dev Board
- L298N Motor Driver
- 4x BO Motors / DC Motors
- Power Source (7.4V or 12V Battery)
- Jumper Wires
- Breadboard (optional)

##  Wiring Connections

| ESP32 Pin | Connected To             | Description                   |
|-----------|--------------------------|-------------------------------|
| GPIO 26   | IN1 (L298N)              | Right Motor Forward           |
| GPIO 27   | IN2 (L298N)              | Right Motor Backward          |
| GPIO 32   | IN3 (L298N)              | Left Motor Forward            |
| GPIO 33   | IN4 (L298N)              | Left Motor Backward           |
| 5V        | VCC of L298N             | Power for motor driver logic  |
| GND       | GND of L298N and Battery | Common ground                 |

## Blynk Setup
- Create a new Blynk Template.
- Add 4 buttons on the app:
  - V0: Forward
  - V1: Backward
  - V2: Right
  - V3: Left
- Set them as push buttons (not switch).

## Code Highlights
- Motor movement based on virtual pin values.
- Safe `stopMotors()` function when button is released.

## Getting Started
1. Flash code to ESP32 using Arduino IDE.
2. Replace your own Blynk credentials in the code.
3. Power the motors and ESP32.
4. Connect your phone to Blynk and start driving!
