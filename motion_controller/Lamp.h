#ifndef Lamp_h
#define Lamp_h

#include "Arduino.h"
#include "Executable.h"

class Lamp: public Executable {
public:
	Lamp(int lamp_index, int pin_lamp);
	void turn_on();
	void turn_off();

  void update();
  void execute();
  void tick();

private:
  int _current_state;
  int _lamp_index;
  int _pin_lamp;
};
#endif
