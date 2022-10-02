//#include "Arduino.h”
#include "Heating.h"


Heating::Heating(int heating_index, int pin_temperature_sensor, int pin_oil_valve, int pin_water_valve, Configuration *config):
 _current_state(0),
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
  pinMode(_pin_oil_valve, OUTPUT);
  pinMode(_pin_water_valve, OUTPUT);
  //_closing_pressure_ai_pin = closing_pressure_ai_pin;
  //_end_switch_input_pin = stamp_position_end_switch_di_pin;
  _config->get_stamp_duration();
 // _pid_open.setpoint();
 // _pid_open.limit();
}

void Heating::heat_up(){
  _current_state = 1;
  _pid_heat_up.begin();
  _pid_heat_up.setpoint(_current_temperature_nominal_value);
  _pid_heat_up.tune(1, 0, 1);
  _pid_heat_up.limit(0, 255);
}

void Heating::cool_down(){
  _current_state = 2;
  _pid_cool_down.begin();
  _pid_cool_down.setpoint(_current_cooling_temperature_nominal_value);
  _pid_cool_down.tune(1, 0, 1);
  _pid_cool_down.limit(0, 255);
}

void Heating::stop() {
  _current_state = 0;
}

void Heating::update(){
  _current_temperature_measurement_value = analogRead(_pin_temperature_sensor);
  int new_temperature_nominal_value = _config->get_heating_nominal_temperature_analog_value(_heating_index);
  if (new_temperature_nominal_value != _current_temperature_nominal_value) {
    _current_temperature_nominal_value = new_temperature_nominal_value;
    _pid_heat_up.setpoint(new_temperature_nominal_value);
  }
  int new_cooling_temperature_nominal_value = _config->get_heating_nominal_cooling_temperature_analog_value(_heating_index);
  if (new_cooling_temperature_nominal_value != _current_cooling_temperature_nominal_value) {
    _current_cooling_temperature_nominal_value = new_cooling_temperature_nominal_value;
    _pid_cool_down.setpoint(new_cooling_temperature_nominal_value);
  }
  _next_heat_up_temperature_measurement_value = _pid_heat_up.compute(_current_temperature_measurement_value);
  _next_cool_down_temperature_measurement_value = _pid_cool_down.compute(_current_temperature_measurement_value);
}

void Heating::execute(){
}

void Heating::tick(){
  switch(_current_state) {
    default:
    case 0:
      _pause_all();
      break;
    case 1:
      if (! _in_temperature_tolerance(_current_temperature_measurement_value, _current_temperature_nominal_value)) {
        _continue_heating();
      } else {
        _pause_all();
      }
      break;
    case 2:
      if (! _in_temperature_tolerance(_current_temperature_measurement_value, _current_cooling_temperature_nominal_value)) {
        _continue_cooling();
      } else {
        _pause_all();
      }
      break;
  }
}

bool Heating::_in_temperature_tolerance(int actual_value, int nominal_value) {
  int delta = abs(nominal_value - actual_value);
  return delta < 5;
}

void Heating::_pause_all() {
  digitalWrite(_pin_oil_valve, LOW);
  digitalWrite(_pin_water_valve, LOW);
}

void Heating::_continue_heating() {
  digitalWrite(_pin_oil_valve, HIGH);
  digitalWrite(_pin_water_valve, LOW);
}

void Heating::_continue_cooling() {
  digitalWrite(_pin_oil_valve, LOW);
  digitalWrite(_pin_water_valve, HIGH);
}
