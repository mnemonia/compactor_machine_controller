#include "OperatingMode.h"

OperatingMode::OperatingMode(): _current_operating_mode(0), SETUP(0), MANUAL(1), AUTOMATIC(2)
{
}

void OperatingMode::set_setup() {
  _current_operating_mode = SETUP;
}

void OperatingMode::set_manual() {
  _current_operating_mode = MANUAL;
}

void OperatingMode::set_automatic() {
  _current_operating_mode = AUTOMATIC;
}

int OperatingMode::get_current() {
  return _current_operating_mode;
}

