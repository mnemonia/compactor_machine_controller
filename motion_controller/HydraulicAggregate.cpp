//#include "Arduino.h”
#include "HydraulicAggregate.h"


HydraulicAggregate::HydraulicAggregate(int aggregate_index, int pin_aggregate):
 _current_state(0),
 _aggregate_index(aggregate_index),
 _pin_aggregate(pin_aggregate)
{
  pinMode(_pin_aggregate, OUTPUT);
}

void HydraulicAggregate::turn_on(){
  _current_state = 1;
}

void HydraulicAggregate::turn_off(){
  _current_state = 0;
}

void HydraulicAggregate::update(){
}

void HydraulicAggregate::execute(){
}

void HydraulicAggregate::tick(){
  switch(_current_state){
    default:
    case 0:
      digitalWrite(_pin_aggregate, LOW);
      break;
    case 1:
      digitalWrite(_pin_aggregate, HIGH);
      break;
  }
}

int HydraulicAggregate::state(){
  return _current_state;
}

void HydraulicAggregate::next_state(){
  switch(_current_state){
    default:
    case 0:
      turn_on();
      break;
    case 1:
      turn_off();
      break;
  }
}
