/********************************************************************************
*********************************************************************************
********************************   SMARS ROVER  *********************************
Programa sigue líneas
@pedro_b_m 
https://github.com/clasedetecnologia/SMARS/
********************************************************************************
********************************************************************************/
#include <AFMotor.h>
AF_DCMotor R_motor(2); // defines Right motor pin //
AF_DCMotor L_motor(1); // defines Left motor pin
// declare variables
int lineNumber; //En esta variable guardaremmos el valor leído por el sensor

void setup() { 
  Serial.begin(9600);// sets up Serial library at 9600 bps
  //change the following values to make the robot drive as straight as possible
  L_motor.setSpeed(50); // sets L motor speed 
  R_motor.setSpeed(50);// sets R motor speed
  
  R_motor.run(RELEASE); //turns L motor on
  L_motor.run(RELEASE); //turns R motor on
}

void loop() {
  lineNumber= analogRead(A4); //Lee sensorIR y guarda valor en lineNumber. El valor va de 0-1024
  while(lineNumber>800){ 
    L_motor.run(FORWARD); //moves motor L Forward 
    R_motor.run(FORWARD); //moves motor L Forward
    lineNumber= analogRead(A4); //reads the sensor value from pin A4 and stores it in the variable lineNumber 
  }
  if(lineNumber<800){ // repeats the following part of code until the light sensor will find a darker zone
    
    //AQUÍ FALTA CÓDIGO
  
  
      
  }
  
  Serial.println(lineNumber); //send the value to the serial monitor
}
