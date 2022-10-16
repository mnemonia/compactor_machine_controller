//#include "Arduino.h”
#include "Compactor.h"


Compactor::Compactor(Configuration *config, IoConfiguration *io_config):
 _config(config),
 _io_config(io_config),
 _pid_open(),
 _pid_close(),
 _current_state(0)
{
  pinMode(_io_config->pin_compactor_close_valve(), OUTPUT);
  pinMode(_io_config->pin_compactor_open_valve(), OUTPUT);
  pinMode(_io_config->pin_compactor_endposition_stamp_sensor(), INPUT);
  pinMode(_io_config->pin_compactor_endposition_open_sensor(), INPUT);
  pinMode(_io_config->pin_compactor_endposition_close_sensor(), INPUT);
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
    case 3:
      if (! _in_endposition_stamp()) {
        _continue_close();
      } else {
        _continue_stop();
      }
      break;
  }  
}

int Compactor::state(){
  return _current_state;
}

void Compactor::next_state(){
  // TODO What do here?
}

void Compactor::_continue_open() {
  digitalWrite(_io_config->pin_compactor_open_valve(), HIGH);
  digitalWrite(_io_config->pin_compactor_close_valve(), LOW);
}

void Compactor::_continue_close() {
  digitalWrite(_io_config->pin_compactor_open_valve(), LOW);
  digitalWrite(_io_config->pin_compactor_close_valve(), HIGH);
}

void Compactor::_continue_stop() {
  digitalWrite(_io_config->pin_compactor_open_valve(), LOW);
  digitalWrite(_io_config->pin_compactor_close_valve(), LOW);
}

bool Compactor::_in_endposition_close() {
  return _config->set_compactor_endposition_close_status(digitalRead(_io_config->pin_compactor_endposition_close_sensor())) == HIGH;
}

bool Compactor::_in_endposition_open() {
  return digitalRead(_io_config->pin_compactor_endposition_open_sensor()) == HIGH;
}

bool Compactor::_in_endposition_stamp() {
  //return digitalRead(_io_config->pin_compactor_endposition_stamp_sensor()) == HIGH;
  return false;
}