#ifndef IoInitializationService_h
#define IoInitializationService_h

#include "Arduino.h"
#include "Machine.h"


class IoInitializationService {
public:
	IoInitializationService(Machine *machine);
  void initialize();

private:
  Machine *_machine;
};
#endif
