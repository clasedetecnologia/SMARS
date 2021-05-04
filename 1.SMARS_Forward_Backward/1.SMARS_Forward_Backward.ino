/********************************************************************************
*********************************************************************************
********************************   SMARS ROVER  *********************************
Programa básico para mover el rover adelante y hacia atrás
@pedro_b_m 
https://github.com/clasedetecnologia/SMARS/
********************************************************************************
********************************************************************************/

#include <AFMotor.h> //importamos la librería AFMotor, para controlar el shield de motores 
AF_DCMotor motorIZQ(1); // set up motor1. motorIZQ es el nombre, conectado al puerto 1
AF_DCMotor motorDER(2); // set up motor2. motorDER es el nombre, conectado al puerto 2

void setup() { 
  motorIZQ.setSpeed(255); //VELOCIDAD ENTRE 0-255
  motorDER.setSpeed (255);  
  motorIZQ.run(RELEASE); //ENCENDER MOTORES
  motorDER.run(RELEASE);
}//setup

void loop() { 
    motorIZQ.run(FORWARD); //Parámetros: FORWARD, BACKWARD, RELEASE
    motorDER.run(FORWARD);
    delay(2000);//tiempo de movimiento de motores
   
    //tu programa empieza aquí...



   
}//loop

  
