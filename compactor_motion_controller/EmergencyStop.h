#ifndef EmergencyStop_h
#define EmergencyStop_h

#include "Arduino.h"
#include "IoConfiguration.h"
#include "MachineBehavior.h"

class EmergencyStop {
public:
	EmergencyStop(MachineBehavior *machine_behavior, IoConfiguration *io_config);
  void check();
  void stop();
private:
  MachineBehavior *_machine_behavior;
  IoConfiguration *_io_config;
};
#endif
