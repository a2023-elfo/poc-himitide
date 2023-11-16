#include <pompe/pompe.h>

void Pompe::setupPompe(uint8_t pin){
    this->_pin = pin;
    this->_state=LOW;
    pinMode(_pin,OUTPUT);
}
void Pompe::pompeOFF(){
   _state=LOW;
   digitalWrite(this->_pin,LOW);
}
void Pompe::pompeON(int temps){
   _state=HIGH;
   digitalWrite(this->_pin,HIGH);
   delay(temps * 1000); //temps = durée d'arrosage
}
int Pompe::getStatePompe(){
    return this->_state;
}