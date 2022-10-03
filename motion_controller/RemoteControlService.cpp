//#include "Arduino.h”
#include "RemoteControlService.h"


RemoteControlService::RemoteControlService(Configuration *config, Machine *machine): _config(config), _machine(machine), _is_enabled(true) {
}

void RemoteControlService::trigger(int command_id){
  if (!_is_enabled) { return; }

  Serial.println(command_id);
  switch(command_id) {
    case 101:
      _machine->lamp_orange()->turn_on();
      break;
    case 102:
      _machine->lamp_blue()->turn_on();
      break;
    case 103:
      _machine->lamp_green()->turn_on();
      break;
    case 111:
      _machine->lamp_orange()->turn_off();
      break;
    case 112:
      _machine->lamp_blue()->turn_off();
      break;
    case 113:
      _machine->lamp_green()->turn_off();
      break;    
    case 201:
      _machine->heating_upper_upper()->stop();
      break;    
    case 202:
      _machine->heating_upper_lower()->stop();
      break;    
    case 203:
      _machine->heating_lower_upper()->stop();
      break;    
    case 204:
      _machine->heating_lower_lower()->stop();
      break;    
    case 211:
      _machine->heating_upper_upper()->heat_up();
      break;    
    case 212:
      _machine->heating_upper_lower()->heat_up();
      break;    
    case 213:
      _machine->heating_lower_upper()->heat_up();
      break;    
    case 214:
      _machine->heating_lower_lower()->heat_up();
      break;    
    case 221:
      _machine->heating_upper_upper()->cool_down();
      break;    
    case 222:
      _machine->heating_upper_lower()->cool_down();
      break;    
    case 223:
      _machine->heating_lower_upper()->cool_down();
      break;    
    case 224:
      _machine->heating_lower_lower()->cool_down();
      break;    
    case 300:
      _machine->compactor()->stop();
      break;    
    case 301:
      _machine->compactor()->open();
      break;    
    case 302:
      _machine->compactor()->close();
      break;    
    case 303:
      _machine->compactor()->stamp();
      break;    
    case 400:
      _machine->aggregate()->turn_off();
      break;    
    case 401:
      _machine->aggregate()->turn_on();
      break;    
    case 200:
      // _machine->execute_command(command_id);
      break;
  }

}