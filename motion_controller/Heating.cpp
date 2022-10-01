//#include "Arduino.h”
#include "Heating.h"


Heating::Heating(int pin_temperature_sensor, int pin_oil_valve, int pin_water_valve, Configuration *config):
 _config(config),
 _pid_open(),
 _pid_close() 
{
  //pinMode(closing_pressure_ai_pin, INPUT);
  //pinMode(stamp_position_end_switch_di_pin, INPUT);
  //_closing_pressure_ai_pin = closing_pressure_ai_pin;
  //_end_switch_input_pin = stamp_position_end_switch_di_pin;
  _config->get_stamp_duration();
 // _pid_open.setpoint();
 // _pid_open.limit();
}

void Heating::heat_up(){
}

void Heating::cool_down(){
}

void Heating::update(){
 // analogRead();
}

void Heating::execute(){
}

void Heating::tick(){
}

