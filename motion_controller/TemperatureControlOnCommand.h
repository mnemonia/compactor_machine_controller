#ifndef TemperatureControlOnCommand_h
#define TemperatureControlOnCommand_h

#include "Machine.h"
#include "Command.h"


class TemperatureControlOnCommand: public Command {
public:
	TemperatureControlOnCommand(Machine *machine);
	void execute();
	void cancel();

private:
  Machine *_machine;
};
#endif
