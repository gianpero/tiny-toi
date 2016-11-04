
int tempRaw;
float temp;
int B=4250;
float equivResistance;

void setup()
{
  Serial.begin(9600);
  pinMode(3, OUTPUT);
}

void loop()
{
  tempRaw=analogRead(0);
  equivResistance=(float)(1023-tempRaw)*10000/tempRaw;
  temp=1/(log(equivResistance/10000)/B+1/298.15)-273.15;
  if (temp > 27){
    digitalWrite(3, HIGH);
    delay(1000);
    digitalWrite(3, LOW);
    }
  Serial.println(temp);
  delay(2000);
 }
