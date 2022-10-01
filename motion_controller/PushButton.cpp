#include "PushButton.h"

PushButton::PushButton(int di_pin, Command *down_command, Command *up_command): _di_pin(di_pin), _down_command(down_command), _up_command(up_command), _state_last_read(LOW), _is_enabled(false)
{
  pinMode(_di_pin, INPUT);
}

void PushButton::check() {
  if (_is_enabled == false) {
    return;
  }

  int pin_state = digitalRead(_di_pin);
  if (pin_state == _state_last_read) {
    return;
  }

  if (pin_state == LOW) {
    _up_command->cancel();
    _down_command->execute();
  } else {
    _down_command->cancel();
    _up_command->execute();
  }

  _state_last_read = pin_state;  
}

void PushButton::enable() {
  _is_enabled = true;
}
void PushButton::disable() {
  _is_enabled = false;
}


