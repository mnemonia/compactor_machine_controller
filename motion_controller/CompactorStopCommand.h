#ifndef CompactorStopCommand_h
#define CompactorStopCommand_h

#include "MachineBehavior.h"
#include "Command.h"

class CompactorStopCommand: public Command {
public:
	CompactorStopCommand(MachineBehavior *machine_behavior);
	void execute();
	void cancel();

private:
  MachineBehavior *_machine_behavior;
};
#endif
