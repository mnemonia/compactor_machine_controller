#include "Machine.h"

Machine::Machine(Compactor *compactor, Lamp *lamp_orange, Lamp *lamp_blue, Lamp *lamp_green):
 _compactor(compactor),
 _lamp_orange(lamp_orange),
 _lamp_blue(lamp_blue),
 _lamp_green(lamp_green)
{
}

Compactor* Machine::compactor() {
    return _compactor;
}

Lamp* Machine::lamp_orange(){
    return _lamp_orange;
}

Lamp* Machine::lamp_blue(){
    return _lamp_blue;
}

Lamp* Machine::lamp_green(){
    return _lamp_green;
}

