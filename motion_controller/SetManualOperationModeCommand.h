#ifndef SetManualOperationModeCommand_h
#define SetManualOperationModeCommand_h

#include "MachineBehavior.h"
#include "Command.h"
#include "CommandPanel.h"

class SetManualOperationModeCommand: public Command {
public:
	SetManualOperationModeCommand(MachineBehavior *machine_behavior, CommandPanel *command_panel);
	void execute();
	void cancel();

private:
  MachineBehavior *_machine_behavior;
  CommandPanel *_command_panel;
};
#endif
