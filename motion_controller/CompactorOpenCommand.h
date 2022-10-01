#ifndef CompactorOpenCommand_h
#define CompactorOpenCommand_h

#include "MachineBehavior.h"
#include "Command.h"

class CompactorOpenCommand: public Command {
public:
	CompactorOpenCommand(MachineBehavior *machine_behavior);
	void execute();
	void cancel();

private:
  MachineBehavior *_machine_behavior;
};
#endif
