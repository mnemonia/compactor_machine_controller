#ifndef Configuration_h
#define Configuration_h

#include "Arduino.h"

class Configuration {
public:
	Configuration();
	void apply(int key, int value);
	int get_stamp_duration();
	void set_stamp_duration(int stamp_duration_in_s);
	int get_heating_nominal_temperature_analog_value(int heating_index);
	int get_heating_nominal_cooling_temperature_analog_value(int heating_index);
private:
	int _stamp_duration_in_s;
	int _heating_upper_upper_nominal_temperature_in_celsius;
	int _heating_upper_lower_nominal_temperature_in_celsius;
	int _heating_lower_upper_nominal_temperature_in_celsius;
	int _heating_lower_lower_nominal_temperature_in_celsius;
	int _heating_upper_upper_nominal_cooling_temperature_in_celsius;
	int _heating_upper_lower_nominal_cooling_temperature_in_celsius;
	int _heating_lower_upper_nominal_cooling_temperature_in_celsius;
	int _heating_lower_lower_nominal_cooling_temperature_in_celsius;
	//bool _is_heating_with_master;
};
#endif
