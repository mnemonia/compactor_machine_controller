#include "DebounceButton.h"


DebounceButton::DebounceButton(int di_pin, Command *down_command, Command *up_command): 
  _di_pin(di_pin),
  _down_command(down_command),
  _up_command(up_command),
  _button_state(LOW),
  _state_last_read(LOW),
  _last_debounce_time(0),
  _debounce_delay(50),
  _is_enabled(false)
{
  pinMode(_di_pin, INPUT);
}

void DebounceButton::check() {
  if (_is_enabled == false) {
    return;
  }

 // read the state of the switch into a local variable:
  int pin_state = digitalRead(_di_pin);

  // check to see if you just pressed the button
  // (i.e. the input went from LOW to HIGH), and you've waited long enough
  // since the last press to ignore any noise:

  // If the switch changed, due to noise or pressing:
  if (pin_state != _state_last_read) {
    // reset the debouncing timer
    _last_debounce_time = millis();
  }

  if ((millis() - _last_debounce_time) > _debounce_delay) {
    // whatever the pin_state is at, it's been there for longer than the debounce
    // delay, so take it as the actual current state:

    // if the button state has changed:
    if (pin_state != _button_state) {
      _button_state = pin_state;

      if (_button_state == HIGH) {
        _up_command->cancel();
        _down_command->execute();
      } else {
        _down_command->cancel();
        _up_command->execute();
      }
    }
  }

  // save the pin_state. Next time through the loop, it'll be the lastButtonState:
  _state_last_read = pin_state;  
}

void DebounceButton::enable() {
  _is_enabled = true;
}
void DebounceButton::disable() {
  _is_enabled = false;
}

