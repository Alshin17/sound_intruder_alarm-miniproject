# Sound Intruder Alarm System

## Overview
The **Sound Intruder Alarm System** is designed to detect intrusions using a combination of a **PIR motion sensor**, a **digital sound sensor**, and a **GSM module**. When an intrusion is detected, the system triggers an alarm by activating a buzzer and LED, and it sends an SMS alert to the user's mobile phone.

## Features
- **Intrusion Detection**: Utilizes a PIR sensor for motion detection and a digital sound sensor to detect sound.
- **Alarm Activation**: Activates an LED and a buzzer when an intrusion is detected.
- **SMS Alerts**: Sends SMS notifications to the user's phone using a GSM module.
- **Easy to Use**: Simple setup and operation.

## Components Required
1. **Arduino Board** (e.g., Arduino UNO)
2. **PIR Motion Sensor**
3. **Digital Sound Sensor**
4. **GSM Module** (e.g., SIM800)
5. **LED**
6. **Buzzer**
7. **Resistor** (for the LED, typically 220 ohm)
8. **Jumper Wires**
9. **Breadboard** (optional for prototyping)


## Connections
| Component              | Arduino Pin |
|------------------------|-------------|
| PIR Sensor             | 2           |
| Digital Sound Sensor   | 3           |
| LED                    | 13          |
| Buzzer                 | 12          |
| GSM Module RX          | 8           |
| GSM Module TX          | 7           |

## Code
The code is written in **C++** and utilizes the `SoftwareSerial` library for communication with the GSM module. Ensure that you replace `+91xxxxxxxxxx` with your actual phone number in the code to receive SMS alerts.

## Setup Instructions
**Connect Components:** Use jumper wires to connect the components according to the circuit diagram and the connections table.

**Upload Code**: Open the Arduino IDE, copy the complete code, and upload it to the Arduino board.

**Test the System:**

1. Power on the system.

2. Wave your hand in front of the PIR sensor or make a sound to trigger the alarm.

3. Check your phone for an SMS alert.
