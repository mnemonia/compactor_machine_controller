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
	_heating_lower_lower_nominal_cooling_temperature_in_celsius(19),
	_compactor_endposition_close_status(0),
	_compactor_endposition_open_status(1)
{

}

void Configuration::apply(int key, int value) {
	switch(key) {
		case 100:
			_stamp_duration_in_s = value;
			break;
		case 11:
		    digitalWrite(13, HIGH);
			_heating_upper_upper_nominal_temperature_in_celsius = value;
			break;
		case 12:
			_heating_upper_lower_nominal_temperature_in_celsius = value;
			break;
		case 13:
			_heating_lower_upper_nominal_temperature_in_celsius = value;
			break;
		case 14:
			_heating_lower_lower_nominal_temperature_in_celsius = value;
			break;
		case 21:
			_heating_upper_upper_nominal_cooling_temperature_in_celsius = value;
			break;
		case 22:
			_heating_upper_lower_nominal_cooling_temperature_in_celsius = value;
			break;
		case 23:
			_heating_lower_upper_nominal_cooling_temperature_in_celsius = value;
			break;
		case 24:
			_heating_lower_lower_nominal_cooling_temperature_in_celsius = value;
			break;
	}
}

int Configuration::get_stamp_duration(){
  return _stamp_duration_in_s;
}

void Configuration::set_stamp_duration(int stamp_duration_in_s){
	_stamp_duration_in_s = stamp_duration_in_s;
}

int Configuration::get_heating_nominal_temperature_in_celsius(int heating_index) {
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

int Configuration::get_heating_nominal_cooling_temperature_in_celsius(int heating_index) {
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

int Configuration::get_compactor_endposition_close_status() {
	return _compactor_endposition_close_status;
}

int Configuration::set_compactor_endposition_close_status(int value) {
	_compactor_endposition_close_status = value;
	return _compactor_endposition_close_status;
}

int Configuration::get_compactor_endposition_open_status(){
	return _compactor_endposition_open_status;
}

int Configuration::set_compactor_endposition_open_status(int value){
	_compactor_endposition_open_status = value;
	return _compactor_endposition_open_status;
}
