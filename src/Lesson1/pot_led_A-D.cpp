
int inputPot = 0;
// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(3, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  inputPot = analogRead(0)/4;
  analogWrite(3,inputPot);
}
