#include "leoLib.h"
leoLib::leoLib(uint8_t trigger,uint8_t echo){
     _trigger =trigger;
     _echo=echo;
     pinMode(_trigger,OUTPUT);
     pinMode(_echo,INPUT);     
};
long leoLib::SomaIntera(){
         digitalWrite(_trigger,1);
         delayMicroseconds(10);
         digitalWrite(_trigger,0);
         long time=pulseIn(_echo,1);
         return time*0.0343;
    }
void leogad::ledMode(uint8_t pin){
     ___led=pin;
     pinMode(___led,OUTPUT);
}
void leogad::itaraAka(uint8_t ledPin){
     digitalWrite(ledPin,1);
}
void leogad::itaraZima(uint8_t ledPin){
     digitalWrite(ledPin,0);
}
void leogad::itaraBlink(uint8_t ledPin,uint8_t Delay){
     // ___led=ledPin;
     // pinMode(___led,OUTPUT);
	digitalWrite(ledPin,1);
	delay(Delay);
	digitalWrite(ledPin,0);
	delay(Delay);
}
long leoLib::readDistance(){
     digitalWrite(_trigger,1);
     delayMicroseconds(10);
     digitalWrite(_trigger,0);
     long time=pulseIn(_echo,1);
     return time*0.0343;
}
