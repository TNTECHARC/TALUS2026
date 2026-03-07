#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

// Create the PCA9685 object (controls the servo driver board)
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

// Pulse length limits for MG996R servos -- ADJUST FOR HS-805BB+ SERVOS!!!!!!!!!!
#define SERVOMIN 76   // pulse for 0°
#define SERVOMAX 500 //pulse for 180˚

// Channels where each servo is plugged in on the PCA9685
int servoChannels[2] = {0, 1};

// Converts an angle (0–180°) into a pulse length the driver understands
int angleToPulse(int angle) {
  return map(angle, 0, 180, SERVOMIN, SERVOMAX);
}
// Does the INVERSE of the function above ... ADJUST THE THIRD AND FOURTH PARAMETER FOR HS-805BB+!!!!!!!!!!!!!!!!!!
int angleToPulseREVERSE(int angle){
  return map(180 - angle, 0, 180, 100, 540);
}

void setup() {
  Serial.begin(9600);     // Start Serial Monitor
  pwm.begin();            // Initialize PCA9685
  pwm.setPWMFreq(50);     // Standard servo frequency (50 Hz)
 


  Serial.println("=== Servo Control Ready ===");
  Serial.println("\nType angle (0º - 180º) --> "); //Adjust once attatched to TALUS to say (lean left/right....)
}

void loop() {

  // Check if the user typed something in Serial Monitor
  if (Serial.available()) {
    
    // Read desired angle (0–180)
    int angle = Serial.parseInt();

    // Validate input
    if ( angle >= -200 && angle <= 360) {
      int pulse = angleToPulse(angle);
      int negPulse = angleToPulseREVERSE(angle);

    
      //Sends signal to whichever servo is attached to the first or second channel
      pwm.setPWM(servoChannels[0], 0, pulse);
      pwm.setPWM(servoChannels[1], 0, negPulse); //enacts the inverse of pulse

      Serial.print("Moved servo 1 to ");
      Serial.print(angle);
      Serial.print(".\n");
      
      Serial.print("Moved servo 2 to ");
      Serial.print(angle);
      Serial.print(".\n");

    } else {
      Serial.println("Invalid input. Only angle 0º - 180º is valid.");
    }

    // Clear any leftover serial data 
    while (Serial.available()) Serial.read();
  }
}
