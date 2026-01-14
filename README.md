# Intelligent-Pedestrian-Crossing-System

## AIM
This is an embedded system project using Arduino.

## THE SYSTEM INCLUDES
- Pedestrian gate
- Vehicle gate
- Traffic signals (Red & Green LEDs)
- Moving zebra crossing lines

## FEATURES
- Automated pedestrian and vehicle gates using servo motors
- Traffic signal-based control
- Moving zebra crossing lines using DC motors
- Motor control using L298N motor driver

## COMPONENTS USED
- Arduino Uno
- Servo Motor ×2
- L298N Motor Driver
- DC Motors
- Red LED
- Green LED
- Power Supply(Battery)
- Connecting Wires
- Bread board

## BLOCK DIAGRAM
<img width="946" height="749" alt="Screenshot 2026-01-11 193647" src="https://github.com/user-attachments/assets/58875cc1-5aae-484e-ba3b-41cb3a039ef9" />

## CIRCUIT DIAGRAM
<img width="1918" height="1152" alt="image" src="https://github.com/user-attachments/assets/804755d5-0c48-4213-ade9-f9eb6e31909e" />
Circuit diagram is created using Tinkercad for reference. 


## WORKING PRINCIPLE
### RED light:
  - Vehicle gate closes
  - Pedestrian gate opens
  - Zebra crossing lines move

## CODE
```
#include <Servo.h>

Servo passengerGate;  // Servo 1
Servo vehicleGate;    // Servo 2

// Motor pins (L298N)
int IN1 = 2;
int IN2 = 3;
int IN3 = 4;
int IN4 = 5;

// LED pins
int redLED = 8;
int greenLED = 7;

void setup() {
  // Motor pins
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  // LED pins
  pinMode(redLED, OUTPUT);
  pinMode(greenLED, OUTPUT);

  // Attach servos
  passengerGate.attach(9);
  vehicleGate.attach(10);

  // Initial positions (both closed)
  passengerGate.write(0);
  vehicleGate.write(0);
}

void loop() {
  //  RED LIGHT → VEHICLE STOP, PASSENGER GO
  digitalWrite(redLED, HIGH);
  digitalWrite(greenLED, LOW);

  // Motors ON (vehicle stopped but machine runs)
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);

  // Passenger gate open, vehicle gate close
  passengerGate.write(90); // Open
  vehicleGate.write(0);    // Closed
  delay(5000);

  //  GREEN LIGHT → VEHICLE GO, PASSENGER STOP
  digitalWrite(redLED, LOW);
  digitalWrite(greenLED, HIGH);

  // Motors OFF
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);

  // Passenger gate close, vehicle gate open
  passengerGate.write(0);   // Closed
  vehicleGate.write(90);    // Open
  delay(5000);
}
```

### GREEN light:
  - Vehicle gate opens
  - Pedestrian gate closes
  - Zebra crossing stops

## Applications
- Smart pedestrian crossings
- School zones
- High traffic areas

  
