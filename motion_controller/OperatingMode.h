#ifndef OperatingMode_h
#define OperatingMode_h

#include "Stateable.h"

class OperatingMode: public Stateable {
public:
	OperatingMode();
  void set_setup();
  void set_manual();
  void set_automatic();
  int get_current();

	int state();
	void next_state();

private:
  int _current_operating_mode;
  int SETUP;
  int MANUAL;
  int AUTOMATIC;
};
#endif
