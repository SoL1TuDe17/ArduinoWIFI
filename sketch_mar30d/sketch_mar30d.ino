#include <WiFiUdp.h>
#include <ESP8266WiFi.h>

WiFiUDP myesp;
IPAddress server(192, 168, 1, 10);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  delay(100);
  WiFi.begin("iPhone", "inginirium");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("IP adress:");
  Serial.println(WiFi.localIP());
  myesp.begin(80);
}

char incomingPacket[255];

void loop() {
  // put your main code here, to run repeatedly:
  int packetSize = myesp.parsePacket();
  if (packetSize) {
    int len = myesp.read(incomingPacket, 255);
    if (len > 0)
    {
      incomingPacket[len] = 0;
    }
    String answer = incomingPacket;
    Serial.printf("incoming packet:%s\n", incomingPacket);
  }
}
