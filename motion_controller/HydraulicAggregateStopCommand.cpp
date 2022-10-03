#include "HydraulicAggregateStopCommand.h"

HydraulicAggregateStopCommand::HydraulicAggregateStopCommand(HydraulicAggregate *aggregate): _aggregate(aggregate)
{
}

void HydraulicAggregateStopCommand::execute() {
    _aggregate->turn_off();
}
void HydraulicAggregateStopCommand::cancel() {;}

