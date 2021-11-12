#include "FirebaseESP8266.h"  // Install Firebase ESP8266 library
#include <WiFiManager.h> 

#define FIREBASE_HOST "anderson-39bae-default-rtdb.firebaseio.com"
#define FIREBASE_AUTH "Sz9U6Zg1jyDJFBlgBJke0vvaCZBvLGZCB4JWWI4H"
//#define WIFI_SSID "Joao10Mariano"
//#define WIFI_PASSWORD "mariano75"

int led1 = D2;  
int led2 = D3;
int led3 = D4;
int led5 = D5;//REDE
int led6 = D1; 

//#define pinBotao1 D7
//bool pinBotao1Retencao();
//#define pinLED1  D8

//boolean Ligado = false; 
//String path = "";
//FirebaseData firebaseData1;

FirebaseData ledData1;
FirebaseData ledData2;
FirebaseData ledData3;
FirebaseData ledData5;
FirebaseJson json;

void setup()
{  
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  Firebase.reconnectWiFi(true);
  
 pinMode(led1,OUTPUT);
  digitalWrite(led1, HIGH); 
  
  pinMode(led2,OUTPUT);
  digitalWrite(led2, HIGH);
   
  pinMode(led3,OUTPUT);
  digitalWrite(led3, HIGH); 

  pinMode(led5,OUTPUT);
  digitalWrite(led5, LOW); 
   

 

  
 // pinMode(pinBotao1, INPUT_PULLUP);

 
  pinMode(led6, OUTPUT);     
  digitalWrite(led6, HIGH);

  digitalWrite(led6, HIGH);
  delay(2000);
  digitalWrite(led6, LOW);
  delay(2000);
  digitalWrite(led6, HIGH);
  delay(2000);
  digitalWrite(led6, LOW);
  delay(2000);
  digitalWrite(led6, HIGH);
  delay(2000);
  digitalWrite(led6, LOW);
  delay(2000);
  digitalWrite(led6, HIGH);
  delay(2000);
  digitalWrite(led6, LOW);
  delay(2000);
  digitalWrite(led6, HIGH);
  delay(2000);
  digitalWrite(led6, LOW);
  delay(2000);
  digitalWrite(led6, HIGH);
  delay(2000);

  digitalWrite(led6, LOW);
  delay(2000);
  digitalWrite(led6, HIGH);
  delay(4000);
  digitalWrite(led6, LOW);
  delay(4000);
  digitalWrite(led6, HIGH);
  delay(4000);
digitalWrite(led6, LOW);
  delay(4000);
  digitalWrite(led6, HIGH);
  delay(4000);
  digitalWrite(led6, LOW);
  delay(4000);
  digitalWrite(led6, HIGH);
  delay(4000);
  digitalWrite(led6, HIGH);
  delay(4000);
  digitalWrite(led6, LOW);
  delay(4000);
  digitalWrite(led6, HIGH);
  delay(4000);
 digitalWrite(led6, LOW);  
     
 Serial.begin(115200);           

WiFiManager wifiManager;
    wifiManager.autoConnect("FIREBASE");
 Serial.println("connected...yeey :)");

     

  //WiFi.persistent(true);
//WiFi.setAutoConnect(true);
//WiFi.setAutoReconnect(true);

}

void loop() { 

/*
   if (pinBotao1Retencao()) {
      Ligado = false;  
      digitalWrite(pinLED1, HIGH);   
   } else {
      Ligado = true;
      digitalWrite(pinLED1, LOW);
   } 
  
  FirebaseJson json;
    json.add("portao",Ligado);
    Serial.println("------------------------------------");
Serial.println("Update Data 1...");
    if (Firebase.updateNode(firebaseData1, path + "/", json))
    {       
      Serial.println("REASON: " + firebaseData1.errorReason());
     
    }   
*/
  if (Firebase.getString(ledData1, "led1")){
    Serial.println(ledData1.stringData());
    if (ledData1.stringData() == "1") {
    digitalWrite(led1, HIGH);
    }
  else if (ledData1.stringData() == "0"){
    digitalWrite(led1, LOW);
    }
  }
  

  if (Firebase.getString(ledData2, "led2")){
    Serial.println(ledData2.stringData());
    if (ledData2.stringData() == "1") {
    digitalWrite(led2, HIGH);
    }
  else if (ledData2.stringData() == "0"){
    digitalWrite(led2, LOW);
    }
  } 

   if (Firebase.getString(ledData3, "led")){
    Serial.println(ledData3.stringData());
    if (ledData3.stringData() == "1") {
    digitalWrite(led3, HIGH);
    }
  else if (ledData3.stringData() == "0"){
    digitalWrite(led3, LOW);
    }
  }   

if (Firebase.getString(ledData5, "led8")){ //REDE
    Serial.println(ledData5.stringData());
    if (ledData5.stringData() == "1") {
    digitalWrite(led5, HIGH);
    }
  else if (ledData5.stringData() == "0"){
    digitalWrite(led5, LOW);
    }
  } 

}
/*
bool pinBotao1Retencao() {
   #define tempoDebounce 50 //(tempo para eliminar o efeito Bounce EM MILISEGUNDOS)

   bool estadoBotao;
   static bool estadoBotaoAnt; 
   static bool estadoRet = true;
   static unsigned long delayBotao = 0;

   if ( (millis() - delayBotao) > tempoDebounce ) {
       estadoBotao = digitalRead(pinBotao1);
       if ( estadoBotao && (estadoBotao != estadoBotaoAnt) ) {
          estadoRet = !estadoRet;
          delayBotao = millis();
       }
       estadoBotaoAnt = estadoBotao;
   }

   return estadoRet;
}
*/
