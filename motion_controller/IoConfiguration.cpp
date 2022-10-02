//#include "Arduino.h”
#include "IoConfiguration.h"

IoConfiguration::IoConfiguration() {
  _pin_compactor_pressure_sensor = 0;
  _pin_button_compactor_open = 0;
  _pin_compactor_close = 0;
  _pin_operating_mode_automatic_switch = 0;
  _pin_operating_mode_setup_switch = 0;
  _pin_heating_upper_upper_temperature_sensor = 0;
  _pin_heating_upper_lower_temperature_sensor = 0;
  _pin_heating_lower_upper_temperature_sensor = 0;
  _pin_heating_lower_lower_temperature_sensor = 0;
  _pin_heating_upper_upper_oil_valve = 0;
  _pin_heating_upper_lower_oil_valve = 0;
  _pin_heating_lower_upper_oil_valve = 0;
  _pin_heating_lower_lower_oil_valve = 0;
  _pin_heating_upper_upper_water_valve = 0;
  _pin_heating_upper_lower_water_valve = 0;
  _pin_heating_lower_upper_water_valve = 0;
  _pin_heating_lower_lower_water_valve = 0;
  _pin_lamp_orange = 0;
  _pin_lamp_blue = 0;
  _pin_lamp_green = 0;

  pinMode(_pin_operating_mode_setup_switch, INPUT);
  pinMode(_pin_operating_mode_automatic_switch, INPUT);
  pinMode(_pin_button_compactor_open, INPUT);
  pinMode(_pin_compactor_close, INPUT);
  pinMode(_pin_compactor_pressure_sensor, INPUT);
  pinMode(_pin_heating_upper_upper_temperature_sensor, INPUT);
  pinMode(_pin_heating_upper_lower_temperature_sensor, INPUT);
  pinMode(_pin_heating_lower_upper_temperature_sensor, INPUT);
  pinMode(_pin_heating_lower_lower_temperature_sensor, INPUT);

}

int IoConfiguration::pin_compactor_pressure_sensor(){
  return _pin_compactor_pressure_sensor;
}

int IoConfiguration::pin_compactor_open(){
  return _pin_button_compactor_open;
}

int IoConfiguration::pin_compactor_close(){
  return _pin_compactor_close;
}

int IoConfiguration::pin_operating_mode_setup_switch(){
  return _pin_operating_mode_setup_switch;
}

int IoConfiguration::pin_operating_mode_automatic_switch(){
  return _pin_operating_mode_automatic_switch;
}

int IoConfiguration::pin_heating_upper_upper_temperature_sensor() {
  return _pin_heating_upper_upper_temperature_sensor;
}

int IoConfiguration::pin_heating_upper_lower_temperature_sensor() {
  return _pin_heating_upper_lower_temperature_sensor;
}
int IoConfiguration::pin_heating_lower_upper_temperature_sensor() {
  return _pin_heating_lower_upper_temperature_sensor;
}
int IoConfiguration::pin_heating_lower_lower_temperature_sensor() {
  return _pin_heating_lower_lower_temperature_sensor;
}
int IoConfiguration::pin_heating_upper_upper_oil_valve() {
  return _pin_heating_upper_upper_oil_valve;
}
int IoConfiguration::pin_heating_upper_lower_oil_valve() {
  return _pin_heating_upper_lower_oil_valve;
}
int IoConfiguration::pin_heating_lower_upper_oil_valve() {
  return _pin_heating_lower_upper_oil_valve;
}
int IoConfiguration::pin_heating_lower_lower_oil_valve() {
  return _pin_heating_lower_lower_oil_valve;
}
int IoConfiguration::pin_heating_upper_upper_water_valve() {
  return _pin_heating_upper_upper_water_valve;
}
int IoConfiguration::pin_heating_upper_lower_water_valve() {
  return _pin_heating_upper_lower_water_valve;
}
int IoConfiguration::pin_heating_lower_upper_water_valve() {
  return _pin_heating_lower_upper_water_valve;
}
int IoConfiguration::pin_heating_lower_lower_water_valve() {
  return _pin_heating_lower_lower_water_valve;
}
int IoConfiguration::pin_lamp_orange(){
  return _pin_lamp_orange;
}
int IoConfiguration::pin_lamp_blue(){
  return _pin_lamp_blue;
}
int IoConfiguration::pin_lamp_green(){
  return _pin_lamp_green;
}
