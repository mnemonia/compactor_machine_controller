#include "OperatingMode.h"

OperatingMode::OperatingMode(): _current_operating_mode(0), MANUAL(0), AUTOMATIC(1)
{
}

void OperatingMode::set_manual() {}

void OperatingMode::set_automatic() {}

int OperatingMode::get_current() {
  return _current_operating_mode;
}

