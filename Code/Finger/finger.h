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

// Converts an angle (0–180°) into a pulse length the driver understands
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
