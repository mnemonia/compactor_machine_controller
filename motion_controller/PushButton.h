#ifndef PushButton_h
#define PushButton_h

#include "Arduino.h"
#include "Button.h"
#include "Command.h"

class PushButton: public Button {
public:
	PushButton(int di_pin, Command *down_command, Command *up_command);
	void check();
  void enable();
  void disable();

private:
  int _di_pin;
  int _state_last_read;
  bool _is_enabled;
  Command *_down_command;
  Command *_up_command;
};
#endif
