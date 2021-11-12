#include "FirebaseESP8266.h"  
#include <WiFiManager.h> 

#define FIREBASE_HOST "anderson-39bae-default-rtdb.firebaseio.com"
#define FIREBASE_AUTH "Sz9U6Zg1jyDJFBlgBJke0vvaCZBvLGZCB4JWWI4H"

int led1 = D2;  
int led2 = D3;
int led3 = D4;
int led5 = D5; //REDE Led verde RGB ou comum
int led6 = D1; //Indicação de progresso conecção

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

  pinMode(led5,OUTPUT);       //REDE Led verde RGB comentar e descomentar para led comum
  digitalWrite(led5, HIGH);   //REDE Led verde RGB comentar e descomentar para led comum

  // pinMode(led5,OUTPUT);    //Descomentar para led comum e comentar para led RGB
 // digitalWrite(led5, LOW); //Descomentar para led comum e comentar para led RGB
   
   
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

  //digitalWrite(led6, LOW); //Descomentar para led comum e comentar para led RGB
  //delay(4000);             //Descomentar para led comum e comentar para led RGB

  
  digitalWrite(led6, HIGH);  //REDE Led verde RGB descomentar e comentar para led comum
  delay(2000);                //REDE Led verde RGB descomentar e comentar para led comum 
 digitalWrite(led6, LOW);     //REDE Led verde RGB descomentar e comentar para led comum
 delay(2000);                 //REDE Led verde RGB descomentar e comentar para led comum
 digitalWrite(led6, HIGH);    //REDE Led verde RGB descomentar e comentar para led comum
     
 Serial.begin(115200);           

WiFiManager wifiManager;
    wifiManager.autoConnect("IOT Mariano");
 Serial.println("connected...yeey :)");
       
}

void loop() { 


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

if (Firebase.getString(ledData5, "led8")){             //esta Função   Descomentar para led  RGB e comentar para led comum
    Serial.println(ledData5.stringData());
    if (ledData5.stringData() == "0") {
    digitalWrite(led5, HIGH);
    }
  else if (ledData5.stringData() == "1"){
    digitalWrite(led5, LOW);
    }
  } 

/*
  if (Firebase.getString(ledData5, "led8")){             //Descomentar para led comum e comentar para led RGB
    Serial.println(ledData5.stringData());
    if (ledData5.stringData() == "1") {
    digitalWrite(led5, HIGH);
    }
  else if (ledData5.stringData() == "0"){
    digitalWrite(led5, LOW);
    }
  } 
*/


}
