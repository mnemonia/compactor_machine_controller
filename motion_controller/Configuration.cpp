//#include "Arduino.h”
#include "Configuration.h"


Configuration::Configuration():
	_stamp_duration_in_s(5),
	_heating_1_top_nominal_temperature_in_celsius(22.0),
	_heating_1_bottom_nominal_temperature_in_celsius(22.0),
	_heating_2_top_nominal_temperature_in_celsius(22.0),
	_heating_2_bottom_nominal_temperature_in_celsius(22.0)
{

}

int Configuration::get_stamp_duration(){
  return 0;
}

void Configuration::set_stamp_duration(int stamp_duration_in_s){
}

