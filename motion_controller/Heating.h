#ifndef Heating_h
#define Heating_h

#include "Arduino.h"
#include "Executable.h"
#include "Configuration.h"
#include "PIDController.h"

class Heating: public Executable {
public:
	Heating(int heating_index, int pin_temperature_sensor, int pin_oil_valve, int pin_water_valve, Configuration *config);
	void heat_up();
	void cool_down();
  void stop();

  void update();
  void execute();
  void tick();

private:
  int _current_state;
  int _heating_index;
  int _pin_temperature_sensor;
  int _pin_oil_valve;
  int _pin_water_valve;
  Configuration *_config;
  PIDController _pid_heat_up;
  PIDController _pid_cool_down;
  int _current_temperature_measurement_value_in_celsius;
  int _current_temperature_nominal_value_in_celsius;
  int _current_cooling_temperature_nominal_value_in_celsius;
  int _next_heat_up_temperature_measurement_value_in_celsius;
  int _next_cool_down_temperature_measurement_value_in_celsius;
  bool _in_temperature_tolerance(int actual_value, int nominal_value);
  void _pause_all();
  void _continue_heating();
  void _continue_cooling();
  int _rawToCelsius(int analog_sensor_data);

};
#endif
