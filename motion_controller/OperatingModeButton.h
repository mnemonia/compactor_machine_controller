#ifndef OperatingModeButton_h
#define OperatingModeButton_h

#include "Arduino.h"
#include "Button.h"
#include "Command.h"

class OperatingModeButton: public Button {
public:
	OperatingModeButton(
    int di_setup_pin,
    int di_automatic_pin,
    Command *setup_cmd,
    Command *manual_cmd,
    Command *automatic_cmd
  );
	void check();
	void enable();
	void disable();
private:
  int _di_setup_pin;
  int _di_automatic_pin;
  int _last_pin_state_setup;
  int _last_pin_state_automatic;
  int _current_operating_mode;
  Command *_setup_cmd;
  Command *_manual_cmd;
  Command *_automatic_cmd;
};
#endif
