#include "SetSetupOperationModeCommand.h"

SetSetupOperationModeCommand::SetSetupOperationModeCommand(MachineBehavior *machine_behavior, CommandPanel *command_panel): _machine_behavior(machine_behavior), _command_panel(command_panel)
{
}

void SetSetupOperationModeCommand::execute() {
  _command_panel->set_operating_mode_setup();
}
void SetSetupOperationModeCommand::cancel() {}

