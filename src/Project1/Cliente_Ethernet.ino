
#include <SPI.h>
#include <Ethernet.h>


byte mac[] = {  0x98, 0x4F, 0xEE, 0x01, 0x42, 0xFB };
IPAddress server(192,168,1,1);// Server Address
IPAddress ip(192,168,1,2);

int sensorPinTemp = A0;
int sensorTemp =0;
EthernetClient client;
void setup() {
  Ethernet.begin(mac, ip);
  Serial.begin(9600);
  delay(1000);
  Serial.println("connecting...");

  // if you get a connection, report back via serial:
  if (client.connect(server, 10002)) { //Server PORT
    Serial.println("connected");
  } 
   else {
    // if you didn't get a connection to the server:
    Serial.println("connection failed");
  }
}

void loop() {
  // put your main code here, to run repeatedly:
    sensorTemp = analogRead(sensorPinTemp);
    
    if (client.connect(server, 10002)) { //Server PORT
    Serial.println("connected");
  } 
   else {
    // if you didn't get a connection to the server:
    Serial.println("connection failed");
  }
    
//  if (client.available()) {
          Serial.println("Available");
    char c = client.read();
    if (client.connected()){
      Serial.println("Connected");
      delay(1000);
      client.println(ip);
      client.println(sensorTemp);
      Serial.println("Sensor");
      Serial.println(sensorTemp);
      Serial.println("read c");
      Serial.println(c);
      client.stop();
    }
  //}
}
