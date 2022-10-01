//#include "Arduino.h”
#include "Compactor.h"

Compactor::Compactor(Configuration *config, IoConfiguration *io_config): _config(config), _io_config(io_config), pd(){
  //pinMode(closing_pressure_ai_pin, INPUT);
  //pinMode(stamp_position_end_switch_di_pin, INPUT);
  //_closing_pressure_ai_pin = closing_pressure_ai_pin;
  //_end_switch_input_pin = stamp_position_end_switch_di_pin;
  _config->get_stamp_duration();
}

void Compactor::open(){
}

void Compactor::close(){
}

void Compactor::stamp(){
}

void Compactor::configure(){}
void Compactor::execute(){}

