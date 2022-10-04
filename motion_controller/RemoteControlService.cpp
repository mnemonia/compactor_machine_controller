//#include "Arduino.h”
#include "RemoteControlService.h"


RemoteControlService::RemoteControlService(Configuration *config, Machine *machine): _config(config), _machine(machine), _is_enabled(true) {
}

void RemoteControlService::trigger(int command_id){
  if (!_is_enabled) { return; }

  //Serial.println(command_id);
  switch(command_id) {
    case 11:
      _machine->lamp_orange()->turn_on();
      break;
    case 12:
      _machine->lamp_blue()->turn_on();
      break;
    case 13:
      _machine->lamp_green()->turn_on();
      break;
    case 14:
      _machine->lamp_orange()->turn_off();
      break;
    case 15:
      _machine->lamp_blue()->turn_off();
      break;
    case 16:
      _machine->lamp_green()->turn_off();
      break;    
    case 17:
      _machine->heating_upper_upper()->stop();
      break;    
    case 18:
      _machine->heating_upper_lower()->stop();
      break;    
    case 19:
      _machine->heating_lower_upper()->stop();
      break;    
    case 20:
      _machine->heating_lower_lower()->stop();
      break;    
    case 21:
      _machine->heating_upper_upper()->heat_up();
      break;    
    case 22:
      _machine->heating_upper_lower()->heat_up();
      break;    
    case 23:
      _machine->heating_lower_upper()->heat_up();
      break;    
    case 24:
      _machine->heating_lower_lower()->heat_up();
      break;    
    case 25:
      _machine->heating_upper_upper()->cool_down();
      break;    
    case 26:
      _machine->heating_upper_lower()->cool_down();
      break;    
    case 27:
      _machine->heating_lower_upper()->cool_down();
      break;    
    case 28:
      _machine->heating_lower_lower()->cool_down();
      break;    
    case 29:
      _machine->compactor()->stop();
      break;    
    case 30:
      _machine->compactor()->open();
      break;    
    case 31:
      _machine->compactor()->close();
      break;    
    case 32:
      _machine->compactor()->stamp();
      break;    
    case 33:
      _machine->aggregate()->turn_off();
      break;    
    case 34:
      _machine->aggregate()->turn_on();
      break;    
    case 35:
      // _machine->execute_command(command_id);
      break;
  }
}

void RemoteControlService::writeParamsToSerial() {
  Serial.print("511=");
  Serial.print(_config->get_heating_nominal_temperature_in_celsius(1));
  Serial.print(";512=");
  Serial.println(_config->get_heating_nominal_temperature_in_celsius(2));
  Serial.print("513=");
  Serial.print(_config->get_heating_nominal_temperature_in_celsius(3));
  Serial.print(";514=");
  Serial.println(_config->get_heating_nominal_temperature_in_celsius(4));

  Serial.print("521=");
  Serial.print(_config->get_heating_nominal_cooling_temperature_in_celsius(1));
  Serial.print(";522=");
  Serial.println(_config->get_heating_nominal_cooling_temperature_in_celsius(2));
  Serial.print("523=");
  Serial.print(_config->get_heating_nominal_cooling_temperature_in_celsius(3));
  Serial.print(";524=");
  Serial.println(_config->get_heating_nominal_cooling_temperature_in_celsius(4));

  // Serial.print("330=");
  // Serial.print(_config->get_compactor_endposition_open_status());
  // Serial.print(";331=");
  // Serial.println(_config->get_compactor_endposition_close_status());
}
