/********************************************************************************
*********************************************************************************
********************************   SMARS ROVER  *********************************
Programa básico para leer del sensor de humedad y temperatura DHT11
@pedro_b_m 
https://github.com/clasedetecnologia/SMARS/
********************************************************************************
********************************************************************************/
#include <DHT.h>
#include <DHT_U.h>
#define DHTTYPE DHT11   // DHT 11

 
// Connect pin 1 (on the left) of the sensor to +5V
// Connect pin 2 of the sensor to whatever your DHTPIN is
// Connect pin 4 (on the right) of the sensor to GROUND
// Connect a 10K resistor from pin 2 (data) to pin 1 (power) of the sensor
 
#define DHTPin A5     // what digital pin we're connected to
DHT dht(DHTPin, DHTTYPE);
 
void setup() {
   Serial.begin(9600); 
   dht.begin();
}
 
void loop() {
   // Wait a few seconds between measurements.
   delay(2000);
   // Reading temperature or humidity takes about 250 milliseconds!
   float h = dht.readHumidity();//Leo humedad
   float t = dht.readTemperature();//Leo temperatura
   
   if (isnan(h) || isnan(t)) {
      Serial.println("Failed to read from DHT sensor!");
      return;
   } 
   
   //¿Qué hacen estas lineas?
   //Busca información acerca del puerto serie en Arduino
   Serial.print("Humidity: ");
   Serial.print(h);
   Serial.print(" %\t");
   Serial.print("Temperature: ");
   Serial.print(t);
   Serial.println(" *C ");
}
