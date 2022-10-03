#include "HydraulicAggregateStartCommand.h"

HydraulicAggregateStartCommand::HydraulicAggregateStartCommand(HydraulicAggregate *aggregate): _aggregate(aggregate)
{
}

void HydraulicAggregateStartCommand::execute() {
    _aggregate->turn_on();
}
void HydraulicAggregateStartCommand::cancel() {;}

