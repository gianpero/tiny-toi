#include <SPI.h>
#include <Ethernet.h>

#include <Wire.h>
#include "rgb_lcd.h"

rgb_lcd lcd;

const int colorR = 255;
const int colorG = 255;
const int colorB = 0;


// Enter a MAC address and IP address for your controller below.
// The IP address will be dependent on your local network:
byte mac[] = {
  0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED
};
IPAddress ip(192, 168, 1, 1);
int lastData1;
int lastData2;

EthernetServer server(10002);
EthernetServer serverWeb(80);
void setup() {
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
  // start the Ethernet connection and the server:
  Ethernet.begin(mac, ip);
  server.begin();
  serverWeb.begin();
  Serial.print("serverCom is at ");
  Serial.println(Ethernet.localIP());
  lcd.begin(16, 2);
  lcd.setRGB(colorR, colorG, colorB);
  lcd.print("Actual m3/s: ");
}


void loop() {
 // listen for incoming clients
  EthernetClient client = server.available();
  if (client) {
    Serial.println("new client");
    while (client.connected()) {
      if (client.available()) {
        char c = client.read();
        lastData1 = c;
        lastData2 = c*2;
        Serial.print(c);
      }
    }
    // close the connection:
    //client.stop();
    Serial.println("client disonnected");
  }
  EthernetClient clientWeb = serverWeb.available();
  if (clientWeb) {
    Serial.println("new client");
    // an http request ends with a blank line
    boolean currentLineIsBlank = true;
    while (clientWeb.connected()) {
      if (clientWeb.available()) {
        char requestWeb = clientWeb.read();
        Serial.write(requestWeb);
        // if you've gotten to the end of the line (received a newline
        // character) and the line is blank, the http request has ended,
        // so you can send a reply
        if (requestWeb == '\n' && currentLineIsBlank) {
          // send a standard http response header
          clientWeb.println("HTTP/1.1 200 OK");
          clientWeb.println("Content-Type: text/html");
          clientWeb.println("Connection: close");  // the connection will be closed after completion of the response
          clientWeb.println("Refresh: 5");  // refresh the page automatically every 5 sec
          clientWeb.println();
          clientWeb.println("<!DOCTYPE HTML>");
          clientWeb.println("<html>");
          clientWeb.println("Actual m3/s: ");
          clientWeb.println(analogRead(0));
          clientWeb.println("<br>");
          clientWeb.println("Node 1:");
          clientWeb.println(lastData1);
          clientWeb.println("<br>");
          clientWeb.println("Node 1:");
          clientWeb.println(lastData2);
          clientWeb.println("</html>");
          break;
        }
        if (requestWeb == '\n') {
          // you're starting a new line
          currentLineIsBlank = true;
        } else if (requestWeb != '\r') {
          // you've gotten a character on the current line
          currentLineIsBlank = false;
        }
      }
    }
    // give the web browser time to receive the data
    delay(1);
    clientWeb.stop();
    Serial.println("client disconnected");
  }
  lcd.setCursor(0, 1);
  lcd.print(analogRead(0));

}
