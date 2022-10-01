//#include "Arduino.h”
#include "Configuration.h"


Configuration::Configuration():
	_stamp_duration_in_s(5),
	_heating_upper_upper_nominal_temperature_in_celsius(22),
	_heating_upper_lower_nominal_temperature_in_celsius(22),
	_heating_lower_upper_nominal_temperature_in_celsius(22),
	_heating_lower_lower_nominal_temperature_in_celsius(22)
{

}

int Configuration::get_stamp_duration(){
  return 0;
}

void Configuration::set_stamp_duration(int stamp_duration_in_s){
}

int Configuration::get_heating_nominal_temperature_analog_value(int heating_index) {
	return 23;
}

