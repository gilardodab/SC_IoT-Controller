/* IoT Controller 
 * 
Venomshop
 */

//Library
#include "FirebaseESP8266.h"
#include <ESP8266WiFi.h>

//Firebase Setting
#define FIREBASE_URL "Firebase URL"
#define FIREBASE_AUTH "Firebase Token"
#define WIFI_SSID "SSID WIFI"
#define WIFI_PASSWORD "Password WiFi"

FirebaseData firebaseData;
FirebaseJson json;

//Pin Setting
#define LED1 D5   //Connect D5 to LED 1
#define LED2 D6   //Connect D6 to LED 2
#define LED3 D7   //Connect D7 to LED 3

void setup() {
  Serial.begin(9600);         

//Pin Configuration  
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);  

//WiFi Configuration
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Connecting");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(300);
  }
  Serial.println();
  Serial.print("Connect");
  Serial.println(WiFi.localIP());
  Serial.println();

//Firebase Configuration
  Firebase.begin(FIREBASE_URL, FIREBASE_AUTH);
  Firebase.reconnectWiFi(true);
    
}

void loop() {
//Receive Data
//LED 1
  if (Firebase.getString(firebaseData, "TERMINAL/SWITCH-001")){
    if (firebaseData.dataType() == "string"){
      String FBStatus1 = firebaseData.stringData();
      if (FBStatus1 == "1"){
        Serial.println("LED 1 ON");
        digitalWrite(LED1, HIGH);  
      }
      else if (FBStatus1 == "0"){
        Serial.println("LED 1 OFF");
        digitalWrite(LED1, LOW);
      }
    }
  }

//LED 2
  if (Firebase.getString(firebaseData, "TERMINAL/switch2")){
    if (firebaseData.dataType() == "string"){
      String FBStatus2 = firebaseData.stringData();
      if (FBStatus2 == "1"){
        Serial.println("LED 2 ON");
        digitalWrite(LED2, HIGH);  
      }
      else if (FBStatus2 == "0"){
        Serial.println("LED 2 OFF");
        digitalWrite(LED2, LOW);
      }
    }
  }

//LED 3
  if (Firebase.getString(firebaseData, "TERMINAL/Switch 300")){
    if (firebaseData.dataType() == "string"){
      String FBStatus3 = firebaseData.stringData();
      if (FBStatus3 == "1"){
        Serial.println("LED 3 ON");
        digitalWrite(LED3, HIGH);  
      }
      else if (FBStatus3 == "0"){
        Serial.println("LED 3 OFF");
        digitalWrite(LED3, LOW);
      }
    }
  }  
  
}
