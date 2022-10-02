#include "CompactorCloseCommand.h"

CompactorCloseCommand::CompactorCloseCommand(Compactor *compactor): _compactor(compactor)
{
}

void CompactorCloseCommand::execute() {
    _compactor->close();
}
void CompactorCloseCommand::cancel() {
    _compactor->stop();
}

