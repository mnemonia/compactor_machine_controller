#ifndef PushButton_h
#define PushButton_h

#include "Arduino.h"
#include "Button.h"
#include "Command.h"
#include "DebugService.h"


class DebounceButton: public Button {
public:
	DebounceButton(int di_pin, Command *down_command, Command *up_command, DebugService *debug_service);
	void check();
  void enable();
  void disable();

private:
  int _di_pin;
  Command *_down_command;
  Command *_up_command;
  DebugService *_debug_service;  
  int _button_state;
  int _state_last_read;
  unsigned long _last_debounce_time;
  unsigned long _debounce_delay;
  bool _is_enabled;
};
#endif
