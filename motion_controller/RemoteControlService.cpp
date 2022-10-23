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
    case 40:
      _machine->operating_mode()->set_setup();
      break;
    case 41:
      _machine->operating_mode()->set_manual();
      break;
    case 42:
      _machine->operating_mode()->set_automatic();
      break;
  }
}

void RemoteControlService::writeParamsToSerial() {
  Serial.print("15=");
  Serial.print(_config->get_heating_actual_temperature_in_celsius(1));
  Serial.print(";16=");
  Serial.print(_config->get_heating_actual_temperature_in_celsius(2));
  Serial.print(";17=");
  Serial.print(_config->get_heating_actual_temperature_in_celsius(3));
  Serial.print(";18=");
  Serial.print(_config->get_heating_actual_temperature_in_celsius(4));
  Serial.print("\n");

  // Serial.print("11=");
  // Serial.print(_config->get_heating_nominal_temperature_in_celsius(1));
  // Serial.print(";12=");
  // Serial.print(_config->get_heating_nominal_temperature_in_celsius(2));
  // Serial.print(";13=");
  // Serial.print(_config->get_heating_nominal_temperature_in_celsius(3));
  // Serial.print(";14=");
  // Serial.print(_config->get_heating_nominal_temperature_in_celsius(4));
  // Serial.print("\n");

  // Serial.print("21=");
  // Serial.print(_config->get_heating_nominal_cooling_temperature_in_celsius(1));
  // Serial.print(";22=");
  // Serial.print(_config->get_heating_nominal_cooling_temperature_in_celsius(2));
  // Serial.print(";23=");
  // Serial.print(_config->get_heating_nominal_cooling_temperature_in_celsius(3));
  // Serial.print(";24=");
  // Serial.print(_config->get_heating_nominal_cooling_temperature_in_celsius(4));
  // Serial.print("\n");

  // Serial.print("330=");
  // Serial.print(_config->get_compactor_endposition_open_status());
  // Serial.print(";331=");
  // Serial.println(_config->get_compactor_endposition_close_status());
}

void RemoteControlService::writeStatesToSerial() {
  Serial.print("400=");
  Serial.print(_machine->operating_mode()->state());
  Serial.print(";401=");
  Serial.print(_machine->aggregate()->state());
  Serial.print(";402=");
  Serial.print(_machine->compactor()->state());
  Serial.print("\n");

  Serial.print("410=");
  Serial.print(_machine->heating_upper_upper()->state());
  Serial.print(";411=");
  Serial.print(_machine->heating_upper_lower()->state());
  Serial.print(";412=");
  Serial.print(_machine->heating_lower_upper()->state());
  Serial.print(";413=");
  Serial.print(_machine->heating_lower_lower()->state());
  Serial.print("\n");

  Serial.print("414=");
  Serial.print(_machine->heating_upper_upper()->sensor_state());
  Serial.print(";415=");
  Serial.print(_machine->heating_upper_lower()->sensor_state());
  Serial.print(";416=");
  Serial.print(_machine->heating_lower_upper()->sensor_state());
  Serial.print(";417=");
  Serial.print(_machine->heating_lower_lower()->sensor_state());
  Serial.print("\n");

  //Serial.print(";402=");
  //Serial.println(_machine->compactor()->state());
}