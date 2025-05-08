 /*
 Author: "LeoGad"
 Date: 03/05/2025
 Description: "This code controll ultrasonic sensor To get Object distance"
 */
 
 #include<leoLib.h>
 leoLib ultrasonic(9,8);//define pin (Trigger,echo) on Arduino
 void setup(){
    Serial.begin(9600);
 }
 void loop(){
     //Create Variable to Store Sensor Readings
    int distance=leo.SomaIntera();
    Serial.println("distance: ");
    Serial.print(distance);
 }