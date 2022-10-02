#ifndef CommunicationService_h
#define CommunicationService_h

#include "Arduino.h"
#include "Configuration.h"


class CommunicationService {
public:
	CommunicationService(Configuration *config);
  void write();
  void update();

private:
  Configuration *_config;
  bool _is_enabled;
};
#endif
