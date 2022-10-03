#ifndef HydraulicAggregate_h
#define HydraulicAggregate_h

#include "Arduino.h"
#include "Executable.h"
#include "DebugService.h"

class HydraulicAggregate: public Executable {
public:
	HydraulicAggregate(int aggregate_index, int pin_aggregate);
	void turn_on();
	void turn_off();

  void update();
  void execute();
  void tick();

private:
  int _current_state;
  int _aggregate_index;
  int _pin_aggregate;
};
#endif
