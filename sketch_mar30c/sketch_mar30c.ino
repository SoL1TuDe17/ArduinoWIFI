
#include <WiFiUdp.h>
#include <ESP8266WIFI.h>
WiFiUDP myesp;
IPAddress server(192,168,1,10);
void setup() 
  // put your setup code here, to run once:
Serial.begin(115200);
delay(100);
WiFi.begin("ssid","password");
while(WiFi.status()!=WL_CONNECTED){
  delay(500);
  Serial.print(".");}
  Serial.println("");
  Serial.println("IP adress:");
  Serial.println(WiFi.localIP());
  myesp.begin(80);
}

void loop() {
  // put your main code here, to run repeatedly:
Serial.println("Sending the pack...");
myesp.beginPacket(server,80);
myesp.print("THANKS FOR VISITING OUR STORE /r"
myesp.endPacket();
delay(10000);
}
