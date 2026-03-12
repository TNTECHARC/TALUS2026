#include "finger.h"

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

int servoChannels[6] = {0, 1, 2, 3, 4, 5};
// Converts an angle (0–180°) into a pulse length the driver understands

int angleToPulse(int angle) { //maps out position for servo based on angle given
  return map(angle, 0, 180, SERVOMIN, SERVOMAX);
}

void pointFinger(){ //iterates through channels and moves each finger EXCEPT pointer
  pwm.setPWM(servoChannels[0], 0, SERVOMAX);
  for(int i = 2; i < 5; i++){
    pwm.setPWM(servoChannels[i], 0, SERVOMAX);
  }
}

void flipOff(){ //iterates through channels and moves each finger EXCEPT middle
  for(int i = 0; i < 5; i++){
    if(i == 2){

    }else{
      pwm.setPWM(servoChannels[i], 0, SERVOMAX);
    }
  }
  
}

void wingsUp(){ //iterates through channels and moves each finger EXCEPT pinkie and thumb
  for(int i = 1; i <= 3; i++){
    pwm.setPWM(servoChannels[i], 0, SERVOMAX);
  }
}

void thumbsUp(){ //iterates through channels and moves each finger EXCEPT thumb
  for(int i = 1; i < 6; i++){
    pwm.setPWM(servoChannels[i], 0, SERVOMAX);
  }
}

void moveAll(){ //iterates through all channels and delays slightly each finger
  for(int i = 0; i < 5; i++){
    pwm.setPWM(servoChannels[i], 0, SERVOMAX);
    delay(1000);
  }
  for(int i = 0; i < 5; i++){ //returns to deafault after initial loop
    pwm.setPWM(servoChannels[i], 0, SERVOMIN);
    delay(150);
  }
}

void fistGrasp(){ //closes all fingers
  for(int i = 0; i < 5; i++){
    pwm.setPWM(servoChannels[i], 0, SERVOMAX);
  }
}

void individualFinger(){ //allows user to input finger and angle 
    if(Serial.available()){

      while(Serial.available()){ //flushes buffer
        Serial.read();
      }

      while(Serial.available() == 0){
      }
      int channel = Serial.parseInt();
      int angle = Serial.parseInt();
      int pulse = angleToPulse(angle);
      
      

      // Send signal to ONLY the selected servo
      pwm.setPWM(servoChannels[channel], 0, pulse);

      Serial.print("Moved servo ");
      Serial.print(channel);
      Serial.print(" to ");
      Serial.print(angle);
      Serial.println(" degrees");

      while (Serial.available()){
         Serial.read();
      }
    }
}

void neutral(){ //brings hand down tot neutral position
  for(int i = 0; i <= 6; i++ ){
    pwm.setPWM(servoChannels[i], 0, SERVOMIN);
  }
}

void peaceSign(){
  for(int i = 0; i < 5; i++){
    if(i == 1 || i == 2){
      pwm.setPWM(servoChannels[i], 0, SERVOMIN);
    }else{
      pwm.setPWM(servoChannels[i], 0, SERVOMAX);
    }
    

  }
}

void rockOn(){
  for(int i = 0; i <5; i++){
    if(i == 1 || i == 4){
      pwm.setPWM(servoChannels[i], 0, SERVOMIN);
    }else{
      pwm.setPWM(servoChannels[i], 0, SERVOMAX);
    }
  }
}

void menu(){ //prints menu options for user input
  Serial.println("┌───────── ∘°❉°∘ ─────────┐");
  Serial.println("|     Select an Option    |");
  Serial.println("|-------------------------|");
  Serial.println("| 1.) Finger Point        |");
  Serial.println("| 2.) Bird                |");
  Serial.println("| 3.) Wings Up            |");
  Serial.println("| 4.) Thumbs Up           |");
  Serial.println("| 5.) Move All            |");
  Serial.println("| 6.) Fist                |");
  Serial.println("| 7.) INDIVIDUAL FINGER   |");
  Serial.println("| 8.) RESET NEUTRAL       |");
  Serial.println("| 9.) Peace Sign          |");
  Serial.println("| 10.) Rock On            |");
  Serial.println("└───────── °∘❉∘° ─────────┘");
}
