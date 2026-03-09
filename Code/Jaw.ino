#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

#define SERVOMIN 150
#define SERVOMAX 600

int servoChannels[5] = {0, 1, 2, 3, 4};  // channels used

int angleToPulse(int angle) {
  return map(angle, 0, 180, SERVOMIN, SERVOMAX);
}

void setup() {
  Serial.begin(9600);
  pwm.begin();
  pwm.setPWMFreq(50);
  delay(10);
}

void loop() {

  // Sweep 0 → 180
  for (int angle = -32; angle <= 20; angle++) { //DONT go above 40 degrees. -32 is mouth closed, 20 is mouth fully open
    int pulse = angleToPulse(angle);
    for (int i = 0; i < 5; i++) {
      pwm.setPWM(servoChannels[i], 0, pulse);
    }
    delay(10);
  }

  delay(500);

  // Sweep 180 → 0
  for (int angle = 20; angle >= -32; angle--) {
    int pulse = angleToPulse(angle);
    for (int i = 0; i < 5; i++) {
      pwm.setPWM(servoChannels[i], 0, pulse);
    }
    delay(10);
  }

  delay(500);
}
