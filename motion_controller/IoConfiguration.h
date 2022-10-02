#ifndef IoConfiguration_h
#define IoConfiguration_h

#include "Arduino.h"

class IoConfiguration {
public:
	IoConfiguration();
	int pin_operating_mode_automatic_switch();
    int pin_operating_mode_setup_switch();
    int pin_compactor_open();
	int pin_compactor_close();
	int pin_compactor_pressure_sensor();
	int pin_heating_upper_upper_temperature_sensor();
	int pin_heating_upper_lower_temperature_sensor();
	int pin_heating_lower_upper_temperature_sensor();
	int pin_heating_lower_lower_temperature_sensor();
	int pin_heating_upper_upper_oil_valve();
	int pin_heating_upper_lower_oil_valve();
	int pin_heating_lower_upper_oil_valve();
	int pin_heating_lower_lower_oil_valve();
	int pin_heating_upper_upper_water_valve();
	int pin_heating_upper_lower_water_valve();
	int pin_heating_lower_upper_water_valve();
	int pin_heating_lower_lower_water_valve();
	int pin_lamp_orange();
	int pin_lamp_blue();
	int pin_lamp_green();
private:
	int _pin_compactor_pressure_sensor;
    int _pin_button_compactor_open;
	int _pin_compactor_close;
	int _pin_operating_mode_automatic_switch;
	int _pin_operating_mode_setup_switch;
	int _pin_heating_upper_upper_temperature_sensor;
	int _pin_heating_upper_lower_temperature_sensor;
	int _pin_heating_lower_upper_temperature_sensor;
	int _pin_heating_lower_lower_temperature_sensor;
	int _pin_heating_upper_upper_oil_valve;
	int _pin_heating_upper_lower_oil_valve;
	int _pin_heating_lower_upper_oil_valve;
	int _pin_heating_lower_lower_oil_valve;
	int _pin_heating_upper_upper_water_valve;
	int _pin_heating_upper_lower_water_valve;
	int _pin_heating_lower_upper_water_valve;
	int _pin_heating_lower_lower_water_valve;
	int _pin_lamp_orange;
	int _pin_lamp_blue;
	int _pin_lamp_green;
};
#endif
