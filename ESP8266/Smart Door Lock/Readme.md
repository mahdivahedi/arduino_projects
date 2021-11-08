This is a project about a smart door lock:

<b>Components Requird:</b>
- NodeMCU ESP8266 Development Board
- RFID MF-RC522 Module
- Servo motor
- LEDs
- Buzzerr
- Breadboard
- Jumper Wire

<b>Circuit Connections:</b>
  * D2   <------> SDA/SS 
  * D5   <------> SCK 
  * D7   <------> MOSI
  * D6   <------> MISO
  * GND  <------> GND
  * D1   <------> RST
  * 3.3V <------> 3.3V
  * D0   <------> Buzzer
  * D3   <------> LED
  
If an empeloyee puts the correct card on the RFID tag and it was the right time, the door would be open (servo motore turns 180 degrees) and LED turns on. If the empeloyee puts the correct card in illegal time or an unauthorized persons want to enter, the door will not be open.

<b>Note that;</b> You should change the UID Tag with yours and you can find out your UID Tag by opening the terminal and see the result of <b>"Serial.println(content);"</b> part, Or using dumpInfo, the example code from arduino IDE. 