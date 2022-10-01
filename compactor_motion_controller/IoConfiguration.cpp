//#include "Arduino.h”
#include "IoConfiguration.h"

IoConfiguration::IoConfiguration() {

	_pin_compactor_pressure_sensor = 0;
	_pin_heating_1_top_temperature_sensor = 0;
	_pin_heating_1_bottom_temperature_sensor = 0;
	_pin_heating_2_top_temperature_sensor = 0;
	_pin_heating_2_bottom_temperature_sensor = 0;

  pinMode(_pin_compactor_pressure_sensor, INPUT);
  pinMode(_pin_heating_1_top_temperature_sensor, INPUT);
  pinMode(_pin_heating_1_bottom_temperature_sensor, INPUT);
  pinMode(_pin_heating_2_top_temperature_sensor, INPUT);
  pinMode(_pin_heating_2_bottom_temperature_sensor, INPUT);

}

int IoConfiguration::pin_compactor_pressure_sensor(){
  return _pin_compactor_pressure_sensor;
}

int IoConfiguration::pin_heating_1_top_temperature_sensor(){
  return 0;
}

int IoConfiguration::pin_heating_1_bottom_temperature_sensor(){
  return 0;
}

int IoConfiguration::pin_heating_2_top_temperature_sensor(){
  return 0;
}

int IoConfiguration::pin_heating_2_bottom_temperature_sensor(){
  return 0;
}
