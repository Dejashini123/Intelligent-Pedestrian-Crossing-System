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
  // 🔴 RED LIGHT → VEHICLE STOP, PASSENGER GO
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

  // 🟢 GREEN LIGHT → VEHICLE GO, PASSENGER STOP
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