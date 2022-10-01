#include "OperatingModeButton.h"


OperatingModeButton::OperatingModeButton(
    int di_setup_pin,
    int di_automatic_pin,
    Command *setup_cmd,
    Command *manual_cmd,
    Command *automatic_cmd): 
    _di_setup_pin(di_setup_pin),
    _di_automatic_pin(di_automatic_pin),
    _setup_cmd(setup_cmd),
    _manual_cmd(manual_cmd),
    _automatic_cmd(automatic_cmd),
    _last_pin_state_setup(LOW),
    _last_pin_state_automatic(LOW),
    _current_operating_mode(1)
{
  pinMode(_di_setup_pin, INPUT);
  pinMode(_di_automatic_pin, INPUT);
}

void OperatingModeButton::check() {
  int pin_state_automatic = digitalRead(_di_automatic_pin);
  if (pin_state_automatic == _last_pin_state_automatic) {
    return;
  }
  if (pin_state_automatic == LOW) {
    return;
  }
  switch(_current_operating_mode) {
    case 2:
      _manual_cmd->cancel();
      _automatic_cmd->execute();
      break;
    default:
    case 1:
      _automatic_cmd->cancel();
      _manual_cmd->execute();
      break;
  }
  _last_pin_state_automatic = pin_state_automatic;
}

void OperatingModeButton::enable() {}
void OperatingModeButton::disable() {}
