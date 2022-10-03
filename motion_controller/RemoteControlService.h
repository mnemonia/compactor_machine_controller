#ifndef RemoteControlService_h
#define RemoteControlService_h

#include "Arduino.h"
#include "Configuration.h"
#include "Machine.h"


class RemoteControlService {
public:
	RemoteControlService(Configuration *config, Machine *machine);
  void trigger(int command_id);
  void writeParamsToSerial();

private:
  Configuration *_config;
  Machine *_machine;
  bool _is_enabled;
};
#endif
