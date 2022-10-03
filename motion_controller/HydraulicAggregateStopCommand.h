#ifndef HydraulicAggregateStopCommand_h
#define HydraulicAggregateStopCommand_h

#include "HydraulicAggregate.h"
#include "Command.h"

class HydraulicAggregateStopCommand: public Command {
public:
	HydraulicAggregateStopCommand(HydraulicAggregate *aggregate);
	void execute();
	void cancel();

private:
  HydraulicAggregate *_aggregate;
};
#endif
