int inputPot = 0;
int pins[] = { 2, 3, 4};
int level[] = { 10,341,682 };
int arraySize= 3;
// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  inputPot = analogRead(0);
  for( int led = 0; led < arraySize; led++){
      if ( inputPot > level[led] ){
        digitalWrite(pins[led], HIGH);   // turn the LED on (HIGH is the voltage level)
      }
      else{
        digitalWrite(pins[led], LOW);   // turn the LED on (HIGH is the voltage level)
        }
      }
}
