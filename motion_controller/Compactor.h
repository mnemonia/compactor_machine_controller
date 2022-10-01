#ifndef Compactor_h
#define Compactor_h

#include "Arduino.h"
#include "Executable.h"
#include "Configuration.h"
#include "IoConfiguration.h"
#include "PD.h"

class Compactor: public Executable {
public:
	Compactor(Configuration *config, IoConfiguration *io_config);
	void open();
	void close();
  void stamp();
  void configure();
  void execute();

private:
	//int _closing_pressure_ai_pin;
  //int _stamp_position_end_switch_di_pin;
  Configuration *_config;
  IoConfiguration *_io_config;
  PD pd;
};
#endif
