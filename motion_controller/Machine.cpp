#include "Machine.h"

Machine::Machine(Compactor *compactor):
 _compactor(compactor)
{
}

Compactor* Machine::compactor() {
    return _compactor;
}
