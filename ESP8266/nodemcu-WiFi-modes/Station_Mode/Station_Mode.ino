#include "ESP8266WiFi.h"

const int RSSI_MAX =-50;// define maximum strength of signal in dBm
const int RSSI_MIN =-100;// define minimum strength of signal in dBm

const int displayEnc=1;// set to 1 to display Encryption or 0 not to display

#define WIFI_SSID "POCO X3 NFC"
#define WIFI_PASS "12345678"

void setup() {
  Serial.begin(115200);
  Serial.println("Robojax Wifi Signal Scan");
  // Set WiFi to station mode and disconnect from an AP if it was previously connected
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(2000);

  Serial.println("Setup done");

  Serial.println("Wifi scan started");

  // WiFi.scanNetworks will return the number of networks found
  int n = WiFi.scanNetworks();
  Serial.println("Wifi scan ended");
  if (n == 0) {
    Serial.println("no networks found");
  } else {
    Serial.print(n);
    Serial.println(" networks found");
    for (int i = 0; i < n; ++i) {
      // Print SSID and RSSI for each network found
      Serial.print(i + 1);
      Serial.print(") ");
      Serial.print(WiFi.SSID(i));// SSID

                  
      Serial.print(WiFi.RSSI(i));//Signal strength in dBm  
      Serial.print("dBm (");

      
      Serial.print(dBmtoPercentage(WiFi.RSSI(i)));//Signal strength in %  
     Serial.print("% )"); 
      if(WiFi.encryptionType(i) == ENC_TYPE_NONE)
      {
          Serial.println(" <<***OPEN***>>");        
      }else{
          Serial.println();        
      }

      delay(10);
    }
  }
  Serial.println("");

  // Wait a bit before scanning again
  delay(5000);
  WiFi.scanDelete();  

  WiFi.begin(WIFI_SSID, WIFI_PASS);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(100);
    Serial.print(".");
  }
  
  // Connected to WiFi
  Serial.println();
  Serial.print("Connected! IP address: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  
}// loop



/*
 * Written by Ahmad Shamshiri
  * with lots of research, this sources was used:
 * https://support.randomsolutions.nl/827069-Best-dBm-Values-for-Wifi 
 * This is approximate percentage calculation of RSSI
 * WiFi Signal Strength Calculation
 * Written Aug 08, 2019 at 21:45 in Ajax, Ontario, Canada
 */

int dBmtoPercentage(int dBm)
{
  int quality;
    if(dBm <= RSSI_MIN)
    {
        quality = 0;
    }
    else if(dBm >= RSSI_MAX)
    {  
        quality = 100;
    }
    else
    {
        quality = 2 * (dBm + 100);
   }

     return quality;
}//dBmtoPercentage
