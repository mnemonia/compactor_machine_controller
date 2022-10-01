#ifndef SetSetupOperationModeCommand_h
#define SetSetupOperationModeCommand_h

#include "MachineBehavior.h"
#include "Command.h"
#include "CommandPanel.h"

class SetSetupOperationModeCommand: public Command {
public:
	SetSetupOperationModeCommand(MachineBehavior *machine_behavior, CommandPanel *command_panel);
	void execute();
	void cancel();

private:
  MachineBehavior *_machine_behavior;
  CommandPanel *_command_panel;
};
#endif
