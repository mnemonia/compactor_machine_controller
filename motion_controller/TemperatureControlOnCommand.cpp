#include "TemperatureControlOnCommand.h"

TemperatureControlOnCommand::TemperatureControlOnCommand(Machine *machine): _machine(machine)
{
}

void TemperatureControlOnCommand::execute() {
    _machine->heating_upper_upper()->heat_up();
    _machine->heating_upper_lower()->heat_up();
    _machine->heating_lower_upper()->heat_up();
    _machine->heating_lower_lower()->heat_up();
}

void TemperatureControlOnCommand::cancel() {
    _machine->heating_upper_upper()->stop();
    _machine->heating_upper_lower()->stop();
    _machine->heating_lower_upper()->stop();
    _machine->heating_lower_lower()->stop();
}

