#ifndef Machine_h
#define Machine_h

#include "Arduino.h"
#include "Compactor.h"
#include "Lamp.h"
#include "Command.h"
#include "Heating.h"


class Machine {
public:
	Machine(Compactor* compactor, Lamp *lamp_orange, Lamp *lamp_blue, Lamp *lamp_green, Heating *heating_upper_upper, Heating *heating_upper_lower, Heating *heating_lower_upper, Heating *heating_lower_lower);
  Compactor* compactor();
  Lamp* lamp_orange();
  Lamp* lamp_blue();
  Lamp* lamp_green();
  void add_command(Command *command);
  void execute_command(String command_id);

  Heating *heating_upper_upper();
  Heating *heating_upper_lower();
  Heating *heating_lower_upper();
  Heating *heating_lower_lower();
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
  Heating *_heating_upper_upper;
  Heating *_heating_upper_lower;
  Heating *_heating_lower_upper;
  Heating *_heating_lower_lower;
  Command *_commands[100];
};
#endif
