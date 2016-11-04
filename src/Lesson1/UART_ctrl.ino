int incomingByte = 0; 
void setup() {
        Serial.begin(9600);
        pinMode(13, OUTPUT);
}

void loop() {
        if (Serial.available() > 0) {
                incomingByte = Serial.read();
                if ((char)incomingByte == 'C'){
                    Serial.println(incomingByte, DEC);
                    digitalWrite(13, LOW);
                  }
                if ((char)incomingByte == 'S'){
                    digitalWrite(13, HIGH);
                }
                if ((char)incomingByte == 'U'){
                    digitalWrite(13, HIGH);
                    delay(1000);
                    digitalWrite(13, LOW);
                }
                if ((char)incomingByte == 'D'){
                    digitalWrite(13, HIGH);
                    delay(2000);
                    digitalWrite(13, LOW);
                }
        }
}
