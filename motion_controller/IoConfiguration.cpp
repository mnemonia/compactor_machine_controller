//#include "Arduino.h”
#include "IoConfiguration.h"

IoConfiguration::IoConfiguration() {
  _pin_compactor_pressure_sensor = A1;
  _pin_compactor_open_button = A2;
  _pin_compactor_close_button = A3;
  _pin_operating_mode_automatic_switch = A4;
  _pin_operating_mode_setup_switch = A6;
  _pin_heating_upper_upper_temperature_sensor = A7;
  _pin_heating_upper_lower_temperature_sensor = A8;
  _pin_heating_lower_upper_temperature_sensor = A9;
  _pin_heating_lower_lower_temperature_sensor = A10;
  _pin_heating_upper_upper_oil_valve = 22;
  _pin_heating_upper_lower_oil_valve = 23;
  _pin_heating_lower_upper_oil_valve = 24;
  _pin_heating_lower_lower_oil_valve = 26;
  _pin_heating_upper_upper_water_valve = 27;
  _pin_heating_upper_lower_water_valve = 28;
  _pin_heating_lower_upper_water_valve = 29;
  _pin_heating_lower_lower_water_valve = 30;
  _pin_lamp_orange = 31;
  _pin_lamp_blue = 32;
  _pin_lamp_green = 33;
  _pin_compactor_endposition_close_sensor = A11;
  _pin_compactor_endposition_open_sensor = A12;
  _pin_compactor_open_valve = 34;
  _pin_compactor_close_valve = 36;
  _pin_aggregate = 37;
  _pin_aggregate_start_button = A13;
  _pin_aggregate_stop_button = A14;

  pinMode(13, OUTPUT);
  //digitalWrite(13, HIGH);
  //pinMode(_pin_operating_mode_setup_switch, INPUT);
  //pinMode(_pin_operating_mode_automatic_switch, INPUT);
  //pinMode(_pin_button_compactor_open, INPUT);
  //pinMode(_pin_compactor_close, INPUT);
  // pinMode(_pin_compactor_pressure_sensor, INPUT);
  // pinMode(_pin_compactor_endposition_close_sensor, INPUT);
  // pinMode(_pin_compactor_endposition_open_sensor, INPUT);
  //pinMode(_pin_heating_upper_upper_temperature_sensor, INPUT);
  //pinMode(_pin_heating_upper_lower_temperature_sensor, INPUT);
  //pinMode(_pin_heating_lower_upper_temperature_sensor, INPUT);
  //pinMode(_pin_heating_lower_lower_temperature_sensor, INPUT);
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
int IoConfiguration::pin_aggregate(){
  return _pin_aggregate;
}

int IoConfiguration::pin_aggregate_start_button(){
  return _pin_aggregate_start_button;
}

int IoConfiguration::pin_aggregate_stop_button(){
  return _pin_aggregate_stop_button;
}
