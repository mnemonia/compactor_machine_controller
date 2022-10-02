#ifndef Machine_h
#define Machine_h

#include "Arduino.h"
#include "Compactor.h"


class Machine {
public:
	Machine(Compactor* compactor);
  Compactor* compactor();
/*
  void tick();  
  void stop();
  void set_state_opening();
  void set_state_closing();
  void set_state_stamping();
  void set_state_heating();
  void set_state_cooling();

  void set_state_emergency_stop();
*/
private:
	Compactor *_compactor;
};
#endif
