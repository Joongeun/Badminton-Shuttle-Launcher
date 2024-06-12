// C++ code
//
int Pin = 6; 
int pot_pin = A0;
int output;
int value;
void setup() {
  pinMode(Pin, OUTPUT);
  pinMode(pot_pin, INPUT);
}
void loop() {
  output = analogRead(pot_pin);
  value = map(output, 0, 1023, 0, 255);
  analogWrite(Pin, value);
  delay(1);
}