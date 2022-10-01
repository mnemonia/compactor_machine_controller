#include "IoConfiguration.h"
#include "Configuration.h"
#include "MachineBehavior.h"
#include "EmergencyStop.h"
#include "Compactor.h"
#include "CommandPanel.h"
#include "OperatingMode.h"

IoConfiguration *io_config;
Configuration *config;
Compactor *compactor;
MachineBehavior *machine_behavior;
EmergencyStop *emergency_stop;
CommandPanel *command_panel;
OperatingMode *operating_mode;

void setup() {
  io_config = new IoConfiguration();
  config = new Configuration();
  compactor = new Compactor(config, io_config);
  machine_behavior = new MachineBehavior();
  emergency_stop = new EmergencyStop(machine_behavior, io_config);
  operating_mode = new OperatingMode();
  command_panel = new CommandPanel(machine_behavior, config, io_config, operating_mode);
}

// the loop function runs over and over again forever
void loop() {
  emergency_stop->check();
  command_panel->check();

  //compactor->configure();
  //compactor->execute();
  // emergency_stop->check();
  delay(25);
}
