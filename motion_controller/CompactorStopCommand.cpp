#include "CompactorStopCommand.h"

CompactorStopCommand::CompactorStopCommand(MachineBehavior *machine_behavior): _machine_behavior(machine_behavior)
{
}

void CompactorStopCommand::execute() {}
void CompactorStopCommand::cancel() {}

