#include "SetAutomaticOperationModeCommand.h"

SetAutomaticOperationModeCommand::SetAutomaticOperationModeCommand(MachineBehavior *machine_behavior, CommandPanel *command_panel): _machine_behavior(machine_behavior), _command_panel(command_panel)
{
}

void SetAutomaticOperationModeCommand::execute() {
  _command_panel->set_operating_mode_automatic();
}
void SetAutomaticOperationModeCommand::cancel() {}

