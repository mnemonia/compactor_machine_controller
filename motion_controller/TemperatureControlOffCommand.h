#ifndef TemperatureControlOffCommand_h
#define TemperatureControlOffCommand_h

#include "Machine.h"
#include "Command.h"


class TemperatureControlOffCommand: public Command {
public:
	TemperatureControlOffCommand(Machine *machine);
	void execute();
	void cancel();

private:
  Machine *_machine;
};
#endif
