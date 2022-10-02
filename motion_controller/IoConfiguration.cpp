//#include "Arduino.h”
#include "IoConfiguration.h"

IoConfiguration::IoConfiguration() {
  _pin_compactor_pressure_sensor = 3;
  _pin_compactor_open_button = 4;
  _pin_compactor_close_button = 5;
  _pin_operating_mode_automatic_switch = 6;
  _pin_operating_mode_setup_switch = 7;
  _pin_heating_upper_upper_temperature_sensor = 8;
  _pin_heating_upper_lower_temperature_sensor = 9;
  _pin_heating_lower_upper_temperature_sensor = 10;
  _pin_heating_lower_lower_temperature_sensor = 11;
  _pin_heating_upper_upper_oil_valve = 12;
  _pin_heating_upper_lower_oil_valve = 14;
  _pin_heating_lower_upper_oil_valve = 15;
  _pin_heating_lower_lower_oil_valve = 16;
  _pin_heating_upper_upper_water_valve = 17;
  _pin_heating_upper_lower_water_valve = 18;
  _pin_heating_lower_upper_water_valve = 19;
  _pin_heating_lower_lower_water_valve = 20;
  _pin_lamp_orange = 21;
  _pin_lamp_blue = 22;
  _pin_lamp_green = 23;
  _pin_compactor_endposition_close_sensor = 24;
  _pin_compactor_endposition_open_sensor = 25;
  _pin_compactor_open_valve = 26;
  _pin_compactor_close_valve = 27;

  pinMode(13, OUTPUT);
  digitalWrite(13, LOW);
  pinMode(_pin_operating_mode_setup_switch, INPUT);
  pinMode(_pin_operating_mode_automatic_switch, INPUT);
  //pinMode(_pin_button_compactor_open, INPUT);
  //pinMode(_pin_compactor_close, INPUT);
  // pinMode(_pin_compactor_pressure_sensor, INPUT);
  // pinMode(_pin_compactor_endposition_close_sensor, INPUT);
  // pinMode(_pin_compactor_endposition_open_sensor, INPUT);
  pinMode(_pin_heating_upper_upper_temperature_sensor, INPUT);
  pinMode(_pin_heating_upper_lower_temperature_sensor, INPUT);
  pinMode(_pin_heating_lower_upper_temperature_sensor, INPUT);
  pinMode(_pin_heating_lower_lower_temperature_sensor, INPUT);
}

int IoConfiguration::pin_compactor_pressure_sensor(){
  return _pin_compactor_pressure_sensor;
}

int IoConfiguration::pin_compactor_open_button(){
  return _pin_compactor_open_button;
}

int IoConfiguration::pin_compactor_close_button(){
  return _pin_compactor_close_button;
}

int IoConfiguration::pin_compactor_open_valve(){
  return _pin_compactor_open_valve;
}

int IoConfiguration::pin_compactor_close_valve(){
  return _pin_compactor_close_valve;
}

int IoConfiguration::pin_compactor_endposition_open_sensor() {
  return _pin_compactor_endposition_open_sensor;
}

int IoConfiguration::pin_compactor_endposition_close_sensor() {
  return _pin_compactor_endposition_close_sensor;
}

int IoConfiguration::pin_compactor_endposition_stamp_sensor() {
  return _pin_compactor_endposition_stamp_sensor;
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
