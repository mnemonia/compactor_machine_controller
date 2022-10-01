#ifndef IoConfiguration_h
#define IoConfiguration_h

#include "Arduino.h"

class IoConfiguration {
public:
	IoConfiguration();
	int pin_compactor_pressure_sensor();
	int pin_heating_1_top_temperature_sensor();
	int pin_heating_1_bottom_temperature_sensor();
	int pin_heating_2_top_temperature_sensor();
	int pin_heating_2_bottom_temperature_sensor();
private:
	int _pin_compactor_pressure_sensor;
	int _pin_heating_1_top_temperature_sensor;
	int _pin_heating_1_bottom_temperature_sensor;
	int _pin_heating_2_top_temperature_sensor;
	int _pin_heating_2_bottom_temperature_sensor;
};
#endif
