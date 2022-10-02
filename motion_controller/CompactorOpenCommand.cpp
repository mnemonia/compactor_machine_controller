#include "CompactorOpenCommand.h"

CompactorOpenCommand::CompactorOpenCommand(Compactor *compactor): _compactor(compactor)
{
}

void CompactorOpenCommand::execute() {
    _compactor->open();
}
void CompactorOpenCommand::cancel() {
    _compactor->stop();
}

