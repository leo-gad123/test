/*
Developer: "LeoGad"
File Name: "leoLib.h"
Date: 01/05/2025
Description:Check Decription in ReadMe file in Library folder  
*/
#include<Arduino.h>
#ifndef leoLib_h
#define leoLib_h
class leoLib{
    public:
          leoLib(uint8_t trigger, uint8_t echo);
         long SomaIntera();
         long readDistance();
    private:
         uint8_t _trigger;
         uint8_t _echo;
};
class leogad{
  public:
        void ledMode(uint8_t pin);
        void itaraAka(uint8_t ledPin);
        void itaraZima(uint8_t ledPin);
        void itaraBlink(uint8_t ledPin,uint8_t Delay);
 private:
      uint8_t ___led;
};
#endif  
