
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <Servo.h>
#include "indexHTML.h"; 

#define output D5
const char* ssid = "POCO X3 NFC";
const char* password ="12345678";

Servo myservo;  

ESP8266WebServer server(80);

void handleRoot();
void handleServo();
void handleNotFound();


void setup() {
  Serial.begin(115200);
  delay(500);

  myservo.attach(output); 
  
  WiFi.softAP(ssid, password);  

  IPAddress apip = WiFi.softAPIP(); 
  Serial.print("Connect to this AP : ");
  Serial.println(ssid);
  Serial.print("IP : ");
  Serial.print(apip); 

  server.on("/",handleRoot);  
  server.on("/setPOS",handleServo); 
  server.onNotFound(handleNotFound); 
  server.begin();  
  Serial.println("HTTP server started");
}

void loop() {
 server.handleClient();
}

void handleRoot() {
 String s = MAIN_page; 
 server.send(200, "text/html", s); 
}

void handleNotFound(){
  server.send(404, "text/plain", "404: Not found"); 
}

void handleServo(){
  String POS = server.arg("servoPOS");
  int pos = POS.toInt();
  myservo.write(pos);   
  delay(15);
  Serial.print("Servo Angle is:");
  Serial.println(pos);
  server.send(200, "text/plane","");
}
