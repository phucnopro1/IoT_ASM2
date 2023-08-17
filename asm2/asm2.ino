// #define BLYNK_TEMPLATE_ID "TMPL6iAeAbwAn"
// #define BLYNK_TEMPLATE_NAME "Quickstart Template"
// #define BLYNK_AUTH_TOKEN "y_C4YDHC-UcPhjkehhdf8PNzyCwKZ7p2"
// #define BLYNK_PRINT Serial
// #include <ESP8266WiFi.h>
// #include <BlynkSimpleEsp8266.h>

// // SimpleTimer timer;
// char ssid[] = "FPT Telecom-0B18";
// char pass[] = "1711998";
// float t;
// float h;


// void setup()
// {
//     Serial.println("INIT STARTED");
//     Serial.begin(9600);
//     Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
//     dht.begin();
//     Serial.println("INIT FINSHED");
// }
// void sendUptime()
// {
//   float h = dht.readHumidity();
//   float t = dht.readTemperature(); 
//   Serial.println("Humidity and temperature\n\n");
//   Serial.print("Current humidity = ");
//   Serial.print(h);
//   Serial.print("%  ");
//   Serial.print("temperature = ");
//   Serial.print(t); 
//   Blynk.virtualWrite(V6, t);
//   Blynk.virtualWrite(V5, h);
  
// }

// void loop()
// {

//  Blynk.run();
// }



#define BLYNK_TEMPLATE_ID "TMPL6Yr2pkYio"
#define BLYNK_TEMPLATE_NAME "test"
#define BLYNK_AUTH_TOKEN "xGs15ISkPNvXOzCUu-cULPZd94248T3J"
#define BLYNK_PRINT Serial

#include <BlynkSimpleEsp8266.h>
#include "DHT.h"           
#define DHTTYPE DHT11
BlynkTimer timer; 
#define dht_dpin D3
DHT dht(dht_dpin, DHTTYPE); 

#define RELAY D5

int sensorValSoild = 0; 
int status = 0; // 0 laf tat, 1 la bat

void setup()
{
  Serial.begin(115200);
  pinMode(RELAY, OUTPUT);
  Blynk.begin(BLYNK_AUTH_TOKEN, "phuc", "88888888");
  dht.begin();
  timer.setInterval(1000L, myTimer); 
}
void myTimer() 
{
  sendUptime();
}
void sendUptime()
{
  sensorValSoild = analogRead(A0); 
  float h = dht.readHumidity();
  float t = dht.readTemperature(); 
  if(isnan(h)) h = random(255);
  if(isnan(t)) t = random(255);

  Serial.println("Humidity and temperature\n\n");
  Serial.print("Current humidity =60 ");
  Serial.print(h);
  Serial.print("%  ");
  Serial.print("temperature =60 ");
  Serial.print(t); 
  Blynk.virtualWrite(V6, t);
  Blynk.virtualWrite(V5, h);
  Blynk.virtualWrite(V4, sensorValSoild);  

}
void loop()
{
  // 
  Blynk.run();
  timer.run(); 
}