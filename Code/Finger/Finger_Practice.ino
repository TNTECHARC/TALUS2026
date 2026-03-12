#include "finger.h"

void setup() {
  Serial.begin(9600);     // Start Serial Monitor
  pwm.begin();            // Initialize PCA9685
  pwm.setPWMFreq(50);     // Standard servo frequency (50 Hz)
  
  menu();
}

void loop() {
  int choice = Serial.parseInt();
  // Check if the user typed something in Serial Monitor

    switch(choice){
      case 1:
        neutral();
        pointFinger();
        break;
      case 2:
        neutral();
        flipOff();
        break;
      case 3:
        neutral();
        wingsUp();
        break;
      case 4:
        neutral();
        thumbsUp();
        break;
      case 5:
        neutral();
        moveAll();
        break;
      case 6:
        neutral();
        fistGrasp();
        break;
      case 7:
        neutral();
        Serial.println("Please type the channel number AND angle seperated by space...");
        individualFinger();

        break;
      case 8:
        neutral();
        break;
      
      case 9:
        neutral();
        peaceSign();
        break;
      
      case 10:
        neutral();
        rockOn();
    }
}
