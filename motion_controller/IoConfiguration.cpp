//#include "Arduino.h”
#include "IoConfiguration.h"

IoConfiguration::IoConfiguration() {

	_pin_compactor_pressure_sensor = 0;
	_pin_heating_1_top_temperature_sensor = 0;
	_pin_heating_1_bottom_temperature_sensor = 0;
	_pin_heating_2_top_temperature_sensor = 0;
	_pin_heating_2_bottom_temperature_sensor = 0;
  _pin_button_compactor_open = 0;
  _pin_compactor_close = 0;
  _pin_operating_mode_switch = 0;

  pinMode(_pin_compactor_pressure_sensor, INPUT);
  pinMode(_pin_heating_1_top_temperature_sensor, INPUT);
  pinMode(_pin_heating_1_bottom_temperature_sensor, INPUT);
  pinMode(_pin_heating_2_top_temperature_sensor, INPUT);
  pinMode(_pin_heating_2_bottom_temperature_sensor, INPUT);
  pinMode(_pin_heating_2_bottom_temperature_sensor, INPUT);
  pinMode(_pin_button_compactor_open, INPUT);
  pinMode(_pin_compactor_close, INPUT);
  pinMode(_pin_operating_mode_switch, INPUT);

}

int IoConfiguration::pin_compactor_pressure_sensor(){
  return _pin_compactor_pressure_sensor;
}

int IoConfiguration::pin_heating_1_top_temperature_sensor(){
  return _pin_heating_1_top_temperature_sensor;
}

int IoConfiguration::pin_heating_1_bottom_temperature_sensor(){
  return _pin_heating_1_bottom_temperature_sensor;
}

int IoConfiguration::pin_heating_2_top_temperature_sensor(){
  return _pin_heating_2_top_temperature_sensor;
}

int IoConfiguration::pin_heating_2_bottom_temperature_sensor(){
  return _pin_heating_2_bottom_temperature_sensor;
}

int IoConfiguration::pin_compactor_open(){
  return _pin_button_compactor_open;
}

int IoConfiguration::pin_compactor_close(){
  return _pin_compactor_close;
}

int IoConfiguration::pin_operating_mode_switch(){
  return _pin_operating_mode_switch;
}