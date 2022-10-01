#include "OperatingModeButton.h"


OperatingModeButton::OperatingModeButton(int di_pin, Command *manual_cmd, Command *automatic_cmd): _di_pin(di_pin), _manual_cmd(manual_cmd), _automatic_cmd(automatic_cmd), _state_last_read(LOW), _current_operating_mode(0)
{
  pinMode(_di_pin, INPUT);
}

void OperatingModeButton::check() {
  int pin_state = digitalRead(_di_pin);
  if (pin_state == _state_last_read) {
    return;
  }
  if (pin_state == LOW) {
    return;
  }
  switch(_current_operating_mode) {
    case 1:
      _manual_cmd->cancel();
      _automatic_cmd->execute();
      break;
    default:
    case 0:
      _automatic_cmd->cancel();
      _manual_cmd->execute();
      break;
  }
  _state_last_read = pin_state;
}

void OperatingModeButton::enable() {}
void OperatingModeButton::disable() {}
