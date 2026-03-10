#ifndef FINGER_H

#define FINGER_H

#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

// Create the PCA9685 object (controls the servo driver board)
extern Adafruit_PWMServoDriver pwm;

// Pulse length limits for HIGH TORQUE MG966R SERVOS
#define SERVOMIN 75   // pulse for 0Â° 
#define SERVOMAX 500   // pulse for 180Â°

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

// Converts an angle (0â180Â°) into a pulse length the driver understands
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

#endif