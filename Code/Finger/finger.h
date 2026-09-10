#ifndef FINGER_H
#define FINGER_H

#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

// Create the PCA9685 object (controls the servo driver board)
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

// Pulse length limits for MG996R servos -- ADJUST FOR HS-805BB+ SERVOS!!!!!!!!!!
#define SERVOMIN 76   // pulse for 0°
#define SERVOMAX 500 //pulse for 180˚

// Channels where each servo is plugged in on the PCA9685
extern int servoChannels[];
/*Finger SETUP for channels:
  Thumb   : 0
  Pointer : 1
  Middle  : 2
  Ring    : 3
  Pinkie  : 4
  WRIST   : 5
*/

// Converts an angle (0 to 180) into a pulse length the driver understands
int angleToPulse(int);

void pointFinger();

void flipOff();

void wingsUp();

void thumbsUp();

void moveAll();

void fistGrasp();

void individualFinger();

void menu();

void neutral();

void peaceSign();

void rockOn();

#endif
