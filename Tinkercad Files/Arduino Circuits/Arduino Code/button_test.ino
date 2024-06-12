int motorPin1 = 6; // flywheel motors
int motorPin2 = 10;
int potPin = A0; // potentiometer for speed adjustment 
int potVal;
int buttonPin = A1;
int speedVal; // scaled speed value for motor (potVal/4);

void setup() {
  Serial.begin(9600);
  pinMode(motorPin1, OUTPUT);
  pinMode(buttonPin, INPUT);
  pinMode(potPin, INPUT);
}

void loop() {
  potVal = analogRead(potPin);
  speedVal = map(potVal, 0, 1023, 80, 255); // you can adjust as appropriate for your setup
  analogWrite(motorPin1, speedVal);
  analogWrite(motorPin2, speedVal);
  delay(2000);
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, LOW);
}
  