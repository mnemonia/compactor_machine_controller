//#include "Arduino.h”
#include "Heating.h"


Heating::Heating(int heating_index, int pin_temperature_sensor, int pin_oil_valve, int pin_water_valve, Configuration *config):
 _heating_index(heating_index),
 _pin_temperature_sensor(pin_temperature_sensor),
 _pin_oil_valve(pin_oil_valve),
 _pin_water_valve(pin_water_valve),
 _config(config),
 _pid_heat_up(),
 _pid_cool_down(),
 _current_temperature_measurement_value(20),
 _current_temperature_nominal_value(20),
 _current_cooling_temperature_nominal_value(20),
 _next_heat_up_temperature_measurement_value(20),
 _next_cool_down_temperature_measurement_value(20)
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
  _pid_heat_up.begin();
  _pid_heat_up.setpoint(_current_temperature_nominal_value);
  _pid_heat_up.tune(1, 0, 1);
  _pid_heat_up.limit(0, 255);
}

void Heating::cool_down(){
  _pid_cool_down.begin();
  _pid_cool_down.setpoint(_current_cooling_temperature_nominal_value);
  _pid_cool_down.tune(1, 0, 1);
  _pid_cool_down.limit(0, 255);
}

void Heating::stop() {

}

void Heating::update(){
  _current_temperature_measurement_value = analogRead(_pin_temperature_sensor);
  _current_temperature_nominal_value = _config->get_heating_nominal_temperature_analog_value(_heating_index);
  _current_cooling_temperature_nominal_value = _config->get_heating_nominal_cooling_temperature_analog_value(_heating_index);
  _next_heat_up_temperature_measurement_value = _pid_heat_up.compute(_current_temperature_measurement_value);
  _next_cool_down_temperature_measurement_value = _pid_cool_down.compute(_current_temperature_measurement_value);
}

void Heating::execute(){
}

void Heating::tick(){
}

