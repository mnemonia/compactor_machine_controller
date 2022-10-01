#include "SetManualOperationModeCommand.h"

SetManualOperationModeCommand::SetManualOperationModeCommand(MachineBehavior *machine_behavior, CommandPanel *command_panel): _machine_behavior(machine_behavior), _command_panel(command_panel)
{
}

void SetManualOperationModeCommand::execute() {
  _command_panel->set_operating_mode_manual();
}
void SetManualOperationModeCommand::cancel() {}

