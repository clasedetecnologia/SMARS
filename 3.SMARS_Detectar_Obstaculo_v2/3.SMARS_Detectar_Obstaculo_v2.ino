
/********************************************************************************
*********************************************************************************
********************************   SMARS ROVER  *********************************
Programa que permite esquivar obstáculos
@pedro_b_m 
https://github.com/clasedetecnologia/SMARS/
********************************************************************************
********************************************************************************/
#include <AFMotor.h> //importamos la librería AFMotor, para controlar el shield de motores 
AF_DCMotor motorIZQ(1); // set up motor1. motorIZQ es el nombre, conectado al puerto 1
AF_DCMotor motorDER(2); // set up motor2. motorDER es el nombre, conectado al puerto 2
long duracion, distancia;
void setup() { 
  //velocidades de los distintos motores
  int v_der = 100;
  int v_izq = 100;
  
  motorIZQ.setSpeed(v_izq); //set the speed of the motors, between 0-255 
  motorDER.setSpeed (v_der); 
  motorDER.run(RELEASE);         //turns L motor on
  motorIZQ.run(RELEASE);         //turns R motor on
  Serial.begin(9600); // Arranco puerto serie 
  pinMode(A0, OUTPUT);// Trigger (disparador) como puerto de salida
  pinMode(A1, INPUT);// Echo (receptor) como puerto de entrada
 
}
  
void loop() { 
  motorIZQ.run(FORWARD); 
  motorDER.run(FORWARD);
  
  distancia = medirDistancia();// Mide distancia en cm
  
  if (distancia < 10){
    //Haz algo....

       
  } //fin if
}
 
 //Función que usa el sensor de ultrasonidos para medir distancias. 
 long medirDistancia(){ 
  digitalWrite(A0, LOW); 
  delayMicroseconds(2); // Se requiere retardo para dar tiempo al sensor
  digitalWrite(A0, HIGH); 
  delayMicroseconds(10); 
  digitalWrite(A0, LOW); 
  duracion = pulseIn(A1, HIGH);
  // Convertimos la distancia a cm
  distancia = 0.017*duracion;
  //V= Espacio/tiempo; Vsonido= 340 m/s = 34*10^3 cm/s; De ahí el 0,017
  delay (50); 
  Serial.print("Distancia: "); 
  Serial.println(distancia);
  return distancia;
  }       
