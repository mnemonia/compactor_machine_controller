#ifndef CommunicationService_h
#define CommunicationService_h

#include "Arduino.h"
#include "Configuration.h"
#include "RemoteControlService.h"


class CommunicationService {
public:
	CommunicationService(Configuration *config, RemoteControlService *remote_control_service);
  void write();
  void update();

private:
  Configuration *_config;
  RemoteControlService *_remote_control_service;
  bool _is_enabled;
};
#endif
