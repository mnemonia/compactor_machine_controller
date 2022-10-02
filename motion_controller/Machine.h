#ifndef Machine_h
#define Machine_h

#include "Arduino.h"
#include "Compactor.h"
#include "Lamp.h"


class Machine {
public:
	Machine(Compactor* compactor, Lamp *lamp_orange, Lamp *lamp_blue, Lamp *lamp_green);
  Compactor* compactor();
  Lamp* lamp_orange();
  Lamp* lamp_blue();
  Lamp* lamp_green();
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
  Lamp *_lamp_orange;
  Lamp *_lamp_blue;
  Lamp *_lamp_green;
};
#endif
