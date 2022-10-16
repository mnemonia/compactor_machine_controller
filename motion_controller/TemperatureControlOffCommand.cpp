#include "TemperatureControlOffCommand.h"

TemperatureControlOffCommand::TemperatureControlOffCommand(Machine *machine): _machine(machine)
{
}

void TemperatureControlOffCommand::execute() {
    _machine->heating_upper_upper()->stop();
    _machine->heating_upper_lower()->stop();
    _machine->heating_lower_upper()->stop();
    _machine->heating_lower_lower()->stop();
}

void TemperatureControlOffCommand::cancel() {
    _machine->heating_upper_upper()->stop();
    _machine->heating_upper_lower()->stop();
    _machine->heating_lower_upper()->stop();
    _machine->heating_lower_lower()->stop();
}

