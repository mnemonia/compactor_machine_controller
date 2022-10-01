//#include "Arduino.h”
#include "Configuration.h"


Configuration::Configuration():
	_stamp_duration_in_s(5),
	_heating_upper_upper_nominal_temperature_in_celsius(22),
	_heating_upper_lower_nominal_temperature_in_celsius(22),
	_heating_lower_upper_nominal_temperature_in_celsius(22),
	_heating_lower_lower_nominal_temperature_in_celsius(22),
	_heating_upper_upper_nominal_cooling_temperature_in_celsius(19),
	_heating_upper_lower_nominal_cooling_temperature_in_celsius(19),
	_heating_lower_upper_nominal_cooling_temperature_in_celsius(19),
	_heating_lower_lower_nominal_cooling_temperature_in_celsius(19)
{

}

int Configuration::get_stamp_duration(){
  return _stamp_duration_in_s;
}

void Configuration::set_stamp_duration(int stamp_duration_in_s){
	_stamp_duration_in_s = stamp_duration_in_s;
}

int Configuration::get_heating_nominal_temperature_analog_value(int heating_index) {
	switch(heating_index) {
		case 1: {
			return _heating_upper_upper_nominal_temperature_in_celsius;
		}
		case 2: {
			return _heating_upper_lower_nominal_temperature_in_celsius;
		}
		case 3: {
			return _heating_lower_upper_nominal_temperature_in_celsius;
		}
		case 4: {
			return _heating_lower_lower_nominal_temperature_in_celsius;
		}
	}
	return 0;
}

int Configuration::get_heating_nominal_cooling_temperature_analog_value(int heating_index) {
	switch(heating_index) {
		case 1: {
			return _heating_upper_upper_nominal_cooling_temperature_in_celsius;
		}
		case 2: {
			return _heating_upper_lower_nominal_cooling_temperature_in_celsius;
		}
		case 3: {
			return _heating_lower_upper_nominal_cooling_temperature_in_celsius;
		}
		case 4: {
			return _heating_lower_lower_nominal_cooling_temperature_in_celsius;
		}
	}
	return 0;
}


