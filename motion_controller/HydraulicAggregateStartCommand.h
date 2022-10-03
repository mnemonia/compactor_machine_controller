#ifndef HydraulicAggregateStartCommand_h
#define HydraulicAggregateStartCommand_h

#include "HydraulicAggregate.h"
#include "Command.h"

class HydraulicAggregateStartCommand: public Command {
public:
	HydraulicAggregateStartCommand(HydraulicAggregate *aggregate);
	void execute();
	void cancel();

private:
  HydraulicAggregate *_aggregate;
};
#endif
