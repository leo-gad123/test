/*
Author:LeoGad
Date:28/04/2025
Description:"This codes based on controlling Lighting System in presence of an object"
Country: Rwanda
*/
#include<leoLib.h>//include header file
//Also you can declare like this (Datatype variableName =pin);
#define TRIGGER_PIN 9
#define ECHO_PIN    8
#define LED_PIN     13
#define MAX_D       100 //maximum distance to detect object You can put your own
leoLib ultrasonic(TRIGGER_PIN,ECHO_PIN);//define 
leogad led;// Create Object to access member data of Class called "leogad"
void setup(){
  //set pinMode of the led As OUTPUT
  led.ledMode(LED_PIN);
}
void loop(){
  //Declare variable to Store reading values of the sensor
  int distance=ultrasonic.SomaIntera();
  //control the led 
  if(distance>MAX_D)led.itaraAka(LED_PIN);else led.itaraZima(LED_PIN);
  
}