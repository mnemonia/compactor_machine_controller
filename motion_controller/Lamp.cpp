//#include "Arduino.h”
#include "Lamp.h"

Lamp::Lamp(int lamp_index, int pin_lamp):
 _current_state(0),
 _lamp_index(lamp_index),
 _pin_lamp(pin_lamp)
{
  pinMode(_pin_lamp, OUTPUT);
}

void Lamp::turn_on(){
  _current_state = 1;
  digitalWrite(_pin_lamp, HIGH);
}

void Lamp::turn_off(){
  _current_state = 0;
  digitalWrite(_pin_lamp, LOW);
}

void Lamp::update(){
}

void Lamp::execute(){
}

void Lamp::tick(){
}
