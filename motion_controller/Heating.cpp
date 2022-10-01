//#include "Arduino.h”
#include "Heating.h"


Heating::Heating(int heating_index, int pin_temperature_sensor, int pin_oil_valve, int pin_water_valve, Configuration *config):
 _heating_index(heating_index),
 _pin_temperature_sensor(pin_temperature_sensor),
 _pin_oil_valve(pin_oil_valve),
 _pin_water_valve(pin_water_valve),
 _config(config),
 _pid_open(),
 _pid_close(),
 _current_temperature_measurement_value(0)
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
  _current_temperature_measurement_value = analogRead(_pin_temperature_sensor);
  _current_temperature_nominal_value = _config->get_heating_nominal_temperature_analog_value(_heating_index);
}

void Heating::execute(){
}

void Heating::tick(){
}

