#include "EmergencyStop.h"

EmergencyStop::EmergencyStop(MachineBehavior *machine_behavior, IoConfiguration *io_config): _machine_behavior(machine_behavior), _io_config(io_config)
{
}

void EmergencyStop::check() {
  //read
}
void EmergencyStop::stop() {}

