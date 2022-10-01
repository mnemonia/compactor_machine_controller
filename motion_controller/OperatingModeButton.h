#ifndef OperatingModeButton_h
#define OperatingModeButton_h

#include "Arduino.h"
#include "Button.h"
#include "Command.h"

class OperatingModeButton: public Button {
public:
	OperatingModeButton(int pin, Command *manual_cmd, Command *automatic_cmd);
	void check();
	void enable();
	void disable();
private:
  int _di_pin;
  int _state_last_read;
  int _current_operating_mode;
  Command *_manual_cmd;
  Command *_automatic_cmd;
};
#endif
