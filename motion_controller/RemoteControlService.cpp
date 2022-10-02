//#include "Arduino.h”
#include "RemoteControlService.h"


RemoteControlService::RemoteControlService(Configuration *config, Machine *machine): _config(config), _machine(machine), _is_enabled(true) {
}

void RemoteControlService::trigger(int command_id){
  if (!_is_enabled) { return; }
  //_machine->lamp_blue()->turn_on();
  Serial.print("[");
  Serial.print(command_id);
  Serial.println("]");
  //Serial.println(command_id.startsWith("C1"));
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
    case 200:
      // _machine->execute_command(command_id);
      break;
  }

}