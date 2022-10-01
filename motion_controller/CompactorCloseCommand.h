#ifndef CompactorCloseCommand_h
#define CompactorCloseCommand_h

#include "MachineBehavior.h"
#include "Command.h"

class CompactorCloseCommand: public Command {
public:
	CompactorCloseCommand(MachineBehavior *machine_behavior);
	void execute();
	void cancel();

private:
  MachineBehavior *_machine_behavior;
};
#endif
