//#include "Arduino.h”
#include "RemoteControlService.h"


RemoteControlService::RemoteControlService(Configuration *config, Machine *machine): _config(config), _machine(machine), _is_enabled(true) {
}

void RemoteControlService::trigger(int command_id){
  if (!_is_enabled) { return; }

  //Serial.println(command_id);
  switch(command_id) {
    case 1001:
      _machine->lamp_orange()->turn_on();
      break;
    case 1002:
      _machine->lamp_blue()->turn_on();
      break;
    case 1003:
      _machine->lamp_green()->turn_on();
      break;
    case 1011:
      _machine->lamp_orange()->turn_off();
      break;
    case 1012:
      _machine->lamp_blue()->turn_off();
      break;
    case 1013:
      _machine->lamp_green()->turn_off();
      break;    
    case 1201:
      _machine->heating_upper_upper()->stop();
      break;    
    case 1202:
      _machine->heating_upper_lower()->stop();
      break;    
    case 1203:
      _machine->heating_lower_upper()->stop();
      break;    
    case 1204:
      _machine->heating_lower_lower()->stop();
      break;    
    case 1211:
      _machine->heating_upper_upper()->heat_up();
      break;    
    case 1212:
      _machine->heating_upper_lower()->heat_up();
      break;    
    case 1213:
      _machine->heating_lower_upper()->heat_up();
      break;    
    case 1214:
      _machine->heating_lower_lower()->heat_up();
      break;    
    case 1221:
      _machine->heating_upper_upper()->cool_down();
      break;    
    case 1222:
      _machine->heating_upper_lower()->cool_down();
      break;    
    case 1223:
      _machine->heating_lower_upper()->cool_down();
      break;    
    case 1224:
      _machine->heating_lower_lower()->cool_down();
      break;    
    case 1300:
      _machine->compactor()->stop();
      break;    
    case 1301:
      _machine->compactor()->open();
      break;    
    case 1302:
      _machine->compactor()->close();
      break;    
    case 1303:
      _machine->compactor()->stamp();
      break;    
    case 200:
      // _machine->execute_command(command_id);
      break;
  }

}