//#include "Arduino.h”
#include "RemoteControlService.h"


RemoteControlService::RemoteControlService(Configuration *config, Machine *machine): _config(config), _machine(machine), _is_enabled(true) {
}

void RemoteControlService::trigger(String command_id){
  if (!_is_enabled) { return; }
  if (command_id.startsWith("C100.1")) {
    _machine->lamp_blue()->turn_on();
  } else if (command_id.startsWith("C101.1")) {
    _machine->lamp_blue()->turn_off();
  }
}
