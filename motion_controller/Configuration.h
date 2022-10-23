#ifndef Configuration_h
#define Configuration_h

#include "Arduino.h"

class Configuration {
public:
	Configuration();
	void apply(int key, int value);
	int get_stamp_duration();
	void set_stamp_duration(int stamp_duration_in_s);
	int get_heating_nominal_temperature_in_celsius(int heating_index);
	int get_heating_nominal_cooling_temperature_in_celsius(int heating_index);
	int get_compactor_endposition_close_status();
	int set_compactor_endposition_close_status(int value);
	int get_compactor_endposition_open_status();
	int set_compactor_endposition_open_status(int value);
	int get_heating_actual_temperature_in_celsius(int heating_index);
	int get_environment_actual_temperature_in_celsius(int heating_index);
	void set_heating_actual_temperature_in_celsius(int heating_index, float value);
	void set_environment_actual_temperature_in_celsius(int heating_index, float value);
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
	int _compactor_endposition_close_status;
	int _compactor_endposition_open_status;

	int _heating_upper_upper_actual_temperature_in_celsius;
	int _heating_upper_lower_actual_temperature_in_celsius;
	int _heating_lower_upper_actual_temperature_in_celsius;
	int _heating_lower_lower_actual_temperature_in_celsius;

	int _environment_upper_upper_actual_temperature_in_celsius;
	int _environment_upper_lower_actual_temperature_in_celsius;
	int _environment_lower_upper_actual_temperature_in_celsius;
	int _environment_lower_lower_actual_temperature_in_celsius;

};
#endif
