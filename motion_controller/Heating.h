#ifndef Heating_h
#define Heating_h

#include "Arduino.h"
#include "Executable.h"
#include "Configuration.h"
#include "PIDController.h"

class Heating: public Executable {
public:
	Heating(int pin_temperature_sensor, int pin_oil_valve, int pin_water_valve, Configuration *config);
	void heat_up();
	void cool_down();

  void update();
  void execute();
  void tick();

private:
	//int _closing_pressure_ai_pin;
  //int _stamp_position_end_switch_di_pin;
  Configuration *_config;
  PIDController _pid_open;
  PIDController _pid_close;
};
#endif
