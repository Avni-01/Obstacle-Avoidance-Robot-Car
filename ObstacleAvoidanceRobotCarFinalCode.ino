#include <Arduino.h>
#include <AFMotor.h>
#include <Servo.h>

// Ultrasonic Sensor Pins
#define trigPin A0
#define echoPin A1

// Servo motor
Servo myServo;

// Define Motors
AF_DCMotor motorLF(1);  // Left Front - M1
AF_DCMotor motorLB(2);  // Left Back  - M2
AF_DCMotor motorRB(3);  // Right Back - M3
AF_DCMotor motorRF(4);  // Right Front - M4

// Function to measure distance
long readDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  long duration = pulseIn(echoPin, HIGH);
  long distance = duration * 0.034 / 2; // Convert to cm
  return distance;
}

// Movement functions
void moveForward() {
  motorLF.setSpeed(200);
  motorLB.setSpeed(200);
  motorRF.setSpeed(200);
  motorRB.setSpeed(200);

  motorLF.run(BACKWARD);
  motorLB.run(BACKWARD);
  motorRF.run(BACKWARD);
  motorRB.run(BACKWARD);
}

void moveBackward() {
  motorLF.setSpeed(180);
  motorLB.setSpeed(180);
  motorRF.setSpeed(180);
  motorRB.setSpeed(180);

  motorLF.run(FORWARD);
  motorLB.run(FORWARD);
  motorRF.run(FORWARD);
  motorRB.run(FORWARD);
}

void turnLeft() {
  // Slight speed balance for smoother left turn
  motorLF.setSpeed(170);
  motorLB.setSpeed(170);
  motorRF.setSpeed(210);
  motorRB.setSpeed(210);
  
  motorLF.run(FORWARD);
  motorLB.run(FORWARD);
  motorRF.run(BACKWARD);
  motorRB.run(BACKWARD);
}

void turnRight() {
  // Slight speed balance for smoother right turn
  motorLF.setSpeed(210);
  motorLB.setSpeed(210);
  motorRF.setSpeed(170);
  motorRB.setSpeed(170);
  
  motorLF.run(BACKWARD);
  motorLB.run(BACKWARD);
  motorRF.run(FORWARD);
  motorRB.run(FORWARD);
}

void stopAll() {
  motorLF.run(RELEASE);
  motorLB.run(RELEASE);
  motorRF.run(RELEASE);
  motorRB.run(RELEASE);
}

void setup() {
  
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  myServo.attach(10);  // Servo pin (adjust if needed)
  myServo.write(90);   // Face forward
  delay(1000);
}

void loop() {
  myServo.write(90);
  delay(250);
  
  long dist = readDistance();
  Serial.print("Distance: ");
  Serial.println(dist);

  if (dist > 25) {
    moveForward();
  } else {
    stopAll();
    delay(300);

    moveBackward();
    delay(400);

    stopAll();
    delay(250);
    
    long distLeft, distRight;

    // Look Right
    myServo.write(30);
    delay(500); // allow servo to settle
    distRight = readDistance();
    
    // Look Left
    myServo.write(150);
    delay(500);
    distLeft = readDistance();
    
    myServo.write(90);
    delay(300);
    
    if (distLeft > distRight) {
      turnLeft();
      delay(2200);  // Keep your tested 90° delay
    } else {
      turnRight();
      delay(2200);
    }

    stopAll();
    delay(250);
  }
}
