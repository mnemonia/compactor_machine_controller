#include "CompactorStopCommand.h"

CompactorStopCommand::CompactorStopCommand(Compactor *compactor): _compactor(compactor)
{
}

void CompactorStopCommand::execute() {
    _compactor->stop();
}
void CompactorStopCommand::cancel() {;}

