#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

// Create the PCA9685 object (controls the servo driver board)
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

// Pulse length limits for your servos
// You may need to adjust these if the range seems off
#define SERVOMIN 75   // pulse for 0°
#define SERVOMAX 500   // pulse for 180°

// Channels where each servo is plugged in on the PCA9685
int servoChannels[5] = {0, 1, 2, 3, 4};

// Converts an angle (0–180°) into a pulse length the driver understands
int angleToPulse(int angle) {
  return map(angle, 0, 180, SERVOMIN, SERVOMAX);
}

void setup() {
  Serial.begin(9600);     // Start Serial Monitor
  pwm.begin();            // Initialize PCA9685
  pwm.setPWMFreq(50);     // Standard servo frequency (50 Hz)

  Serial.println("=== Servo Control Ready ===");
  Serial.println("Type: servoNumber angle");
  Serial.println("Example: 2 90  -> moves servo #2 to 90 degrees");
  Serial.println("Servos available: 0, 1, 2, 3, 4");
}

void loop() {

  // Check if the user typed something in Serial Monitor
  if (Serial.available()) {

    // Read servo number (0–4)
    int servoNum = Serial.parseInt();

    // Read desired angle (0–180)
    int angle = Serial.parseInt();

    // Validate input
    // Currently set to -30 (true zero) and 167 (max servo potential tested) -- will change once we adjust servo caps
    if (servoNum >= 0 && servoNum < 5 && angle >= 0 && angle <= 180) {

      int pulse = angleToPulse(angle);

      // Send signal to ONLY the selected servo
      pwm.setPWM(servoChannels[servoNum], 0, pulse);

      Serial.print("Moved servo ");
      Serial.print(servoNum);
      Serial.print(" to ");
      Serial.print(angle);
      Serial.println(" degrees");

    } else {
      Serial.println("Invalid input. Use: servoNumber(0-4) angle(-30 - 167)");
    }

    // Clear any leftover serial data
    while (Serial.available()) Serial.read();
  }
}
