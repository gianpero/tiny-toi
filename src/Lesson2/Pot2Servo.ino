
int inputPot = 0;
void setup() {
  pinMode(3, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  inputPot = analogRead(0)/4;
  analogWrite(3,inputPot);
}
