#ifndef RemoteControlService_h
#define RemoteControlService_h

#include "Arduino.h"
#include "Configuration.h"
#include "Machine.h"


class RemoteControlService {
public:
	RemoteControlService(Configuration *config, Machine *machine);
  void trigger(String command_id);

private:
  Configuration *_config;
  Machine *_machine;
  bool _is_enabled;
};
#endif
