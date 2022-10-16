#ifndef NopeCommand_h
#define NopeCommand_h

#include "Command.h"

class NopeCommand: public Command {
public:
	NopeCommand();
	void execute();
	void cancel();
};
#endif
