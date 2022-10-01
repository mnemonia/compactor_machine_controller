#ifndef MachineBehavior_h
#define MachineBehavior_h

#include "Arduino.h"

class MachineBehavior {
public:
	MachineBehavior();
  void start();
  void tick();  
  void stop();
/*
  void set_state_opening();
  void set_state_closing();
  void set_state_stamping();
  void set_state_heating();
  void set_state_cooling();

  void set_state_emergency_stop();
*/
private:
	int _current_state_id;
};
#endif
