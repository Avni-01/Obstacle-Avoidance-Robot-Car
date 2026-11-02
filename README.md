
# 🚗 Obstacle Avoidance Robot Car

An Arduino-based robot car that drives forward, detects obstacles with an ultrasonic sensor, and steers toward the side with more free space.

🎥 **Demo video:** [add link]

## ⚙️ How it works

1. The car drives forward while the ultrasonic sensor measures the distance ahead.
2. If an obstacle is closer than **25 cm**, it stops and reverses briefly.
3. The servo turns the sensor to the right (30°) and left (150°) to measure both sides.
4. The car turns toward the side with more space, then continues forward.

## 🧰 Components

- Arduino Uno
- Motor driver shield (compatible with the AFMotor library)
- 4 × DC motors with wheels
- HC-SR04 ultrasonic sensor
- Servo motor (SG90)
- Battery pack, chassis, jumper wires

## 🔌 Pin connections

| Component | Pin |
|-----------|-----|
| Ultrasonic Trig | A0 |
| Ultrasonic Echo | A1 |
| Servo signal | 10 |
| Motors | M1 (left front), M2 (left back), M3 (right back), M4 (right front) |

## 🚀 Getting started

1. Install the **Adafruit Motor Shield V1 (AFMotor)** library in the Arduino IDE.
2. Open `ObstacleAvoidanceRobotCarFinalCode.ino`.
3. Select your board and port, then click **Upload**.
4. Power the car from the battery pack and place it on the floor.

## 🔧 Tuning

- `25` in `if (dist > 25)` sets how far away the car reacts to obstacles.
- `delay(2200)` controls how long it turns. Adjust it for your wheels and surface.

## 👩‍💻 Author

**Avni Sen** · [@Avni-01](https://github.com/Avni-01)
