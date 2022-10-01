#ifndef Configuration_h
#define Configuration_h

#include "Arduino.h"

class Configuration {
public:
	Configuration();
	int get_stamp_duration();
	void set_stamp_duration(int stamp_duration_in_s);
private:
	int _stamp_duration_in_s;
	int _heating_1_top_nominal_temperature_in_celsius;
	int _heating_1_bottom_nominal_temperature_in_celsius;
	int _heating_2_top_nominal_temperature_in_celsius;
	int _heating_2_bottom_nominal_temperature_in_celsius;
	//bool _is_heating_with_master;

};
#endif
