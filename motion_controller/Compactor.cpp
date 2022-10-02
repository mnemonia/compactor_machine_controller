//#include "Arduino.h”
#include "Compactor.h"


Compactor::Compactor(Configuration *config, IoConfiguration *io_config):
 _config(config),
 _io_config(io_config),
 _pid_open(),
 _pid_close(),
 _current_state(0)
{
  pinMode(_io_config->pin_compactor_close(), INPUT);
  pinMode(_io_config->pin_compactor_open(), INPUT);
  //pinMode(stamp_position_end_switch_di_pin, INPUT);
  //_closing_pressure_ai_pin = closing_pressure_ai_pin;
  //_end_switch_input_pin = stamp_position_end_switch_di_pin;
  // _config->get_stamp_duration();
 // _pid_open.setpoint();
 // _pid_open.limit();
}

void Compactor::stop(){
  _current_state = 0;
}

void Compactor::open(){
  _current_state = 1;
}

void Compactor::close(){
  _current_state = 2;  
}

void Compactor::stamp(){
  _current_state = 3;
}

void Compactor::update(){
 /* int new_temperature_nominal_value = _config->(_heating_index);
  if (new_temperature_nominal_value != _current_temperature_nominal_value) {
    _current_temperature_nominal_value = new_temperature_nominal_value;
    _pid_heat_up.setpoint(new_temperature_nominal_value);
  }*/

}

void Compactor::execute(){
}

void Compactor::tick(){
  switch(_current_state) {
    default:
    case 0:
      _continue_stop();
      break;
    case 1:
      if (! _in_endposition_open()) {
        _continue_open();
      } else {
        _continue_stop();
      }
      break;
    case 2:
      if (! _in_endposition_close()) {
        _continue_close();
      } else {
        _continue_stop();
      }
      break;
  }  
}

void Compactor::_continue_open() {
  digitalWrite(_io_config->pin_compactor_open(), HIGH);
  digitalWrite(_io_config->pin_compactor_close(), LOW);
}

void Compactor::_continue_close() {
  digitalWrite(_io_config->pin_compactor_open(), LOW);
  digitalWrite(_io_config->pin_compactor_close(), HIGH);
}

void Compactor::_continue_stop() {
  digitalWrite(_io_config->pin_compactor_open(), LOW);
  digitalWrite(_io_config->pin_compactor_close(), LOW);
}

bool Compactor::_in_endposition_close() {
  return digitalRead(-_io_config->pin_compactor_endposition_close_sensor()) == HIGH;
}

bool Compactor::_in_endposition_open() {
  return digitalRead(-_io_config->pin_compactor_endposition_open_sensor()) == HIGH;
}