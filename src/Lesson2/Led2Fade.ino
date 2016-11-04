
int inputPot = 0;
int outToPWM = 0;
void setup() {
  pinMode(3, OUTPUT);
  Serial.begin(9600);
}

// the loop function runs over and over again forever
void loop() {
  inputPot = analogRead(0);
  outToPWM = map(inputPot, 420, 200, 0, 255);
  Serial.println(inputPot);
  analogWrite(3,outToPWM);
}
