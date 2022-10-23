#ifndef TemperatureSensor_h
#define TemperatureSensor_h

#include <Wire.h>
#include <Adafruit_I2CDevice.h>
#include <Adafruit_I2CRegister.h>
#include "Adafruit_MCP9600.h"

#include "Arduino.h"
#include "Executable.h"
#include "Configuration.h"

#define I2C_ADDRESS_1 (0x67)
#define I2C_ADDRESS_2 (0x68)
#define I2C_ADDRESS_3 (0x69)
#define I2C_ADDRESS_4 (0x6A)

class TemperatureSensor: public Executable {
public:
	TemperatureSensor(int index, Configuration *config);
	void turn_on();
	void turn_off();

  void update();
  void execute();
  void tick();

private:
  int _current_state;
  int _index;
  Configuration *_config;
  Adafruit_MCP9600 _mcp;
  int _i2c_address;
};
#endif
