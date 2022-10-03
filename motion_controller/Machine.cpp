#include "Machine.h"

Machine::Machine(Compactor* compactor, Lamp *lamp_orange, Lamp *lamp_blue, Lamp *lamp_green, Heating *heating_upper_upper, Heating *heating_upper_lower, Heating *heating_lower_upper, Heating *heating_lower_lower, HydraulicAggregate *aggregate):
 _compactor(compactor),
 _lamp_orange(lamp_orange),
 _lamp_blue(lamp_blue),
 _lamp_green(lamp_green),
 _heating_upper_upper(heating_upper_upper),
 _heating_upper_lower(heating_upper_lower),
 _heating_lower_upper(heating_lower_upper),
 _heating_lower_lower(heating_lower_lower),
 _aggregate(aggregate)
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

void Machine::add_command(Command *command) {
   // _commands[0] = command;
}

void Machine::execute_command(String command_id) {
   // _commands[0]->execute();
}

Heating* Machine::heating_upper_upper(){
    return _heating_upper_upper;
}

Heating* Machine::heating_upper_lower(){
    return _heating_upper_lower;    
}

Heating* Machine::heating_lower_upper(){
    return _heating_lower_upper;
}

Heating* Machine::heating_lower_lower(){
    return _heating_lower_lower;
}

HydraulicAggregate* Machine::aggregate(){
    return _aggregate;
}

