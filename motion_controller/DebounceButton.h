#ifndef PushButton_h
#define PushButton_h

#include "Arduino.h"
#include "Button.h"
#include "Command.h"

class DebounceButton: public Button {
public:
	DebounceButton(int di_pin, int id, Command *down_command, Command *up_command);
	void check();
  void enable();
  void disable();

private:
  int _di_pin;
  int _id;
  Command *_down_command;
  Command *_up_command;
  int _button_state;
  int _state_last_read;
  unsigned long _last_debounce_time;
  unsigned long _debounce_delay;
  bool _is_enabled;
};
#endif
