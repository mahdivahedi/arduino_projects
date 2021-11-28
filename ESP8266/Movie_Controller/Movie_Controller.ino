#define SS_PIN 16  //D0
#define RST_PIN 5 //D1
#include <ESP8266WiFi.h>
#include <WiFiClient.h>

//ESP Web Server Library to host a web page
#include <ESP8266WebServer.h>
#include <MFRC522.h>

MFRC522 mfrc522(SS_PIN, RST_PIN);
//---------------------------------------------------------------
//Our HTML webpage contents in program memory
const char MAIN_page[] PROGMEM = R"=====(
<!DOCTYPE html>
<html>
<body>
<center>
<h1>Mahdi Vahedi</h1><br>
 <a href="play"><button type="button">play</button></a><br>
 <a href="pause"><button type="button">pause</button></a><br>
 <a href="volumeUp"><button type="button">+</button></a><br>
 <a href="volumeDown"><button type="button">-</button></a><br>
 <a href="name"><button type="button">name</button></a><br>
 
<hr>

</center>

</body>
</html>
)=====";
const char MOVIE1_page[] PROGMEM = R"=====(
<!DOCTYPE html>
<html>
<body>
<center>
<h1>Macbook</h1><br>
<img src = "https://www.digikala.com/mag/wp-content/uploads/2021/11/MacBook-1.jpg" alt = "Macbook"/>
<hr>

</center>

</body>
</html>
)=====";
const char MOVIE2_page[] PROGMEM = R"=====(
<!DOCTYPE html>
<html>
<body>
<center>
<h1>Golden d'Or</h1><br>
<img src = "https://static2.farakav.com/files/pictures/01668402.jpg" alt = "Golden d'Or"/>
<hr>

</center>

</body>
</html>
)=====";



//SSID and Password of your WiFi router
const char* ssid = "Huawei";
const char* password = "99999999";


ESP8266WebServer server(80); //Server on port 80

void handleRoot() {
 Serial.println("You called root page");
 String s = MAIN_page; //Read HTML contents
 server.send(200, "text/html", MAIN_page); //Send web page
}

void handlePlay() { 
 Serial.println("play");
 
 server.send(200, "text/html", MAIN_page); //Send ADC value only to client ajax request
}

void handlePause() { 
 Serial.println("pause");
 server.send(200, "text/html", MAIN_page); //Send ADC value only to client ajax request
}

void handleVolumeDown() { 
 Serial.println("volumeDown");
 server.send(200, "text/html", MAIN_page); //Send ADC value only to client ajax request
}
void handleVolumeUp() { 
 Serial.println("volumeUp");
 server.send(200, "text/html", MAIN_page); //Send ADC value only to client ajax request
}
void handleName(){
  while (true){
    if ( ! mfrc522.PICC_IsNewCardPresent()) 
  {
    return;
  }
  // Select one of the cards
  if ( ! mfrc522.PICC_ReadCardSerial()) 
  {
    return;
  }
  //Show UID on serial monitor
  Serial.println();
  Serial.print(" UID tag :");
  String content= "";
  byte letter;
  for (byte i = 0; i < mfrc522.uid.size; i++) 
  {
     Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
     Serial.print(mfrc522.uid.uidByte[i], HEX);
     content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
     content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  content.toUpperCase();
  if (content.substring(1) == "5B 6D B5 21")
  {
      server.send(200, "text/html", MOVIE1_page);
      break;
  }
  else{
    server.send(200, "text/html", MOVIE2_page);
    break;
  }
  
  
  }

}

void setup(void){
  Serial.begin(115200);
  WiFi.begin(ssid, password);     //Connect to your WiFi router
  Serial.println("");
  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  SPI.begin();      // Initiate  SPI bus
  mfrc522.PCD_Init();   // Initiate MFRC522
  //If connection successful show IP address in serial monitor
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());  //IP address assigned to your ESP
 
  server.on("/", handleRoot);      //Which routine to handle at root location. This is display page
  server.on("/play", handlePlay); //as Per  <a href="ledOn">, Subroutine to be called
  server.on("/pause", handlePause);
  server.on("/volumeUp", handleVolumeUp); //as Per  <a href="ledOn">, Subroutine to be called
  server.on("/volumeDown", handleVolumeDown);
  server.on("/name", handleName);

  server.begin();                  //Start server
  Serial.println("HTTP server started");
}

void loop(void){
  server.handleClient();          //Handle client requests
}
