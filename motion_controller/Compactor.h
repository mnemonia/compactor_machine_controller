#ifndef Compactor_h
#define Compactor_h

#include "Arduino.h"
#include "Executable.h"
#include "Stateable.h"
#include "Configuration.h"
#include "IoConfiguration.h"
#include "PIDController.h"

class Compactor: public Executable, Stateable {
public:
	Compactor(Configuration *config, IoConfiguration *io_config);
	void stop();
	void open();
	void close();
  void stamp();

  void update();
  void execute();
  void tick();

	int state();
	void next_state();

private:
	//int _closing_pressure_ai_pin;
  //int _stamp_position_end_switch_di_pin;
  Configuration *_config;
  IoConfiguration *_io_config;
  PIDController _pid_open;
  PIDController _pid_close;
  int _current_state;
  void _continue_open();
  void _continue_close();
  void _continue_stop();
  void _continue_stamp();
  bool _in_endposition_open();
  bool _in_endposition_close();
  bool _in_endposition_stamp();
};
#endif
