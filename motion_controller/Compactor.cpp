//#include "Arduino.h”
#include "Compactor.h"


Compactor::Compactor(Configuration *config, IoConfiguration *io_config):
 _config(config),
 _io_config(io_config),
 _pid_open(),
 _pid_close() 
{
  //pinMode(closing_pressure_ai_pin, INPUT);
  //pinMode(stamp_position_end_switch_di_pin, INPUT);
  //_closing_pressure_ai_pin = closing_pressure_ai_pin;
  //_end_switch_input_pin = stamp_position_end_switch_di_pin;
  // _config->get_stamp_duration();
 // _pid_open.setpoint();
 // _pid_open.limit();
}

void Compactor::open(){
}

void Compactor::close(){
}

void Compactor::stamp(){
}

void Compactor::update(){
}

void Compactor::execute(){
}

void Compactor::tick(){
}

