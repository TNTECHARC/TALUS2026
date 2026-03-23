#include "finger.h"

void setup() {
  Serial.begin(9600);     // Start Serial Monitor
  pwm.begin();            // Initialize PCA9685
  pwm.setPWMFreq(50);     // Standard servo frequency (50 Hz)
  
}

void loop() {
  String pythonData = Serial.readStringUntil('\n');
  int choice = pythonData.toInt();
  // Check if the user typed something in Serial Monitor

    switch(choice){
      case 1:
        neutral();
        pointFinger();
        break;
      case 2:
        neutral();
        wingsUp();
        break;
      case 3:
        neutral();
        thumbsUp();
        break;
      case 4:
        neutral();
        rockOn();
        break;
      case 5:
        neutral();
        peaceSign();
        break;
      case 6:
        neutral();
        moveAll();
        break;
      case 7:
        neutral();
        flipOff();
        break;

      case 8:
        neutral();
        break;
      
      case 9:
        neutral();
        Serial.println("Please enter the Channel --> ");
        
        delay(10);
        while(Serial.available() > 0) { Serial.read(); } //gets rid of leftover invisble characters from buffer

        while(Serial.available() == 0){ //endless timeloop until user hits enter

        }

        String pythonData = Serial.readStringUntil('\n'); //reads string inputted in python until enter is typed
        pythonData.trim(); //gets rid of the newline
        int input = pythonData.toInt(); //converts the python string input to integer for input
        Serial.print("You typed channel ");
        Serial.println(input);

        Serial.flush(); //rids extra newline from buffer

        test(input); //TEST FUNCTION WILL ELIMINATE LATER
        break;
    }
}
