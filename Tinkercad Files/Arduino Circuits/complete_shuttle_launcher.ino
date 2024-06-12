//STEPPER
#include <Stepper.h>

#define STEPS 2038 // the number of steps in one revolution of your motor (28BYJ-48)

Stepper stepper(STEPS, 9, 10, 11, 12);

int stepperPotVal;
int stepperPot = A1;
int stepperSpeed;


int motorPin1 = 6; // flywheel motors
int motorPin2 = 3;
int motorPot = A0; // potentiometer for speed adjustment
int potVal;
int speedVal; // scaled speed value for motor (potVal/4);
int potPower = 2;


void setup() {
  //STEPPER
  pinMode(stepperPot, INPUT);

  //DC MOTOR
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  pinMode(motorPot, INPUT);
  pinMode(potPower, OUTPUT);
  digitalWrite(potPower, HIGH);
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, LOW);
  delay(2000);
}

void loop() {
  potVal = analogRead(motorPot);
  //CHANGE THE 4TH VALUE OF THE MAP (MIN ANALOG OUTPUT) DEPENDING TO CONTROL MIN SPEED OF DC MOTOR
  speedVal = map(potVal, 0, 1023, 160, 255); // you can adjust as appropriate for your setup
  analogWrite(motorPin1, speedVal);
  analogWrite(motorPin2, speedVal);
  delay(1500);

  delay(2000);
  digitalWrite(motorPin1, LOW); 
  digitalWrite(motorPin2, LOW);
}



void runStepper()  {
  for (int i = 0; i <= 1019; i += 2) {
    stepperPotVal = analogRead(stepperPot);
    stepperSpeed = map(stepperPotVal, 0, 1023, 5, 17);
    stepper.setSpeed(stepperSpeed); 
    stepper.step(2); // step 2 poles per loop (2038 is 1 full rotation)
  }
}
