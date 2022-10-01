#ifndef SetAutomaticOperationModeCommand_h
#define SetAutomaticOperationModeCommand_h

#include "MachineBehavior.h"
#include "Command.h"
#include "CommandPanel.h"

class SetAutomaticOperationModeCommand: public Command {
public:
	SetAutomaticOperationModeCommand(MachineBehavior *machine_behavior, CommandPanel *command_panel);
	void execute();
	void cancel();

private:
  MachineBehavior *_machine_behavior;
  CommandPanel *_command_panel;
};
#endif
