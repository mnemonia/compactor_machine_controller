//#include "Arduino.h”
#include "TemperatureSensor.h"


TemperatureSensor::TemperatureSensor(int index, Configuration *config):
 _current_state(0),
 _index(index),
 _config(config),
 _mcp()
{
  switch(_index) {
    default:
    case 1:
      _i2c_address = I2C_ADDRESS_1;
      break;
    case 2:
      _i2c_address = I2C_ADDRESS_1;
      break;
    case 3:
      _i2c_address = I2C_ADDRESS_1;
      break;
    case 4:
      _i2c_address = I2C_ADDRESS_1;
      break;
  }
  turn_on();
}

void TemperatureSensor::turn_on(){
  if (! _mcp.begin(_i2c_address)) {
      Serial.println("Sensor not found. Check wiring!");
      while (1);
  }

  Serial.print("Found MCP9600 ");
  Serial.println(_index);


  _mcp.setADCresolution(MCP9600_ADCRESOLUTION_18);
  _mcp.setThermocoupleType(MCP9600_TYPE_J);
  _mcp.setFilterCoefficient(3);
  _mcp.setAlertTemperature(1, 30);
  _mcp.configureAlert(1, true, true);  // alert 1 enabled, rising temp
  _mcp.enable(true);

  _current_state = 1;
}

void TemperatureSensor::turn_off(){
  _mcp.enable(false);
  _current_state = 0;
  //digitalWrite(_pin_TemperatureSensor, LOW);
  //_debug_service->info("TemperatureSensor " + String(_TemperatureSensor_index) + " off");
}

void TemperatureSensor::update(){
  if (_current_state == 0) {
    return;
  }
  
  _config->set_heating_actual_temperature_in_celsius(_index, _mcp.readThermocouple());
  _config->set_environment_actual_temperature_in_celsius(_index, _mcp.readAmbient());
  // Serial.print("ADC: "); Serial.print(_mcp.readADC() * 2); Serial.println(" uV");
}

void TemperatureSensor::execute(){
}

void TemperatureSensor::tick(){
}
