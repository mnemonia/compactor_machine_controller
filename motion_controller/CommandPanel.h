#ifndef CommandPanel_h
#define CommandPanel_h

#include "MachineBehavior.h"
#include "Command.h"
#include "Configuration.h"
#include "IoConfiguration.h"
#include "Button.h"
#include "OperatingModeButton.h"
#include "OperatingMode.h"
#include "Lamp.h"
#include "DebugService.h"
#include "Machine.h"

class CommandPanel {
public:
	CommandPanel(MachineBehavior *machine_behavior, Machine *machine, Configuration *config, IoConfiguration *io_config, OperatingMode *operating_mode, Lamp *lamp_orange, Lamp *lamp_blue, Lamp *lamp_green, DebugService *debug_service);
  void check();
  void set_operating_mode_setup();
  void set_operating_mode_manual();
  void set_operating_mode_automatic();
private:
  MachineBehavior *_machine_behavior;
  Machine *_machine;
  Configuration *_config;
  IoConfiguration *_io_config;
  OperatingMode *_operating_mode;
  Button *_compactor_open_btn;
  Button *_compactor_close_btn;
  //OperatingModeButton *_operating_mode_btn;
  Button *_operating_mode_setup_btn;
  Button *_operating_mode_automatic_btn;
  Lamp *_lamp_orange;
  Lamp *_lamp_blue;
  Lamp *_lamp_green;
  DebugService *_debug_service;
	void _configure();
};
#endif
