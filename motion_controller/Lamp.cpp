//#include "Arduino.h”
#include "Lamp.h"


Lamp::Lamp(int lamp_index, int pin_lamp, DebugService *debug_service):
 _current_state(0),
 _lamp_index(lamp_index),
 _pin_lamp(pin_lamp),
 _debug_service(debug_service)
{
  pinMode(_pin_lamp, OUTPUT);
}

void Lamp::turn_on(){
  _current_state = 1;
  digitalWrite(_pin_lamp, HIGH);
  //_debug_service->info("lamp " + String(_lamp_index) + " on");
}

void Lamp::turn_off(){
  _current_state = 0;
  digitalWrite(_pin_lamp, LOW);
  //_debug_service->info("lamp " + String(_lamp_index) + " off");
}

void Lamp::update(){
}

void Lamp::execute(){
}

void Lamp::tick(){
}
