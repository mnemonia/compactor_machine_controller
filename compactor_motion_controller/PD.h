#ifndef PD_h
#define PD_h

#include "Arduino.h"

class PD {
public:
	PD();
  void start();
  void tick();
  void stop();
private:
	int _p_value;
	int _d_value;
};
#endif
