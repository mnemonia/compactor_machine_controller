#include "IoConfiguration.h"
#include "Configuration.h"
#include "MachineBehavior.h"
#include "EmergencyStop.h"
#include "Compactor.h"

IoConfiguration *io_config;
Configuration *config;
Compactor *compactor;
MachineBehavior *machine_behavior;
EmergencyStop *emergency_stop;

void setup() {
  io_config = new IoConfiguration();
  config = new Configuration();
  compactor = new Compactor(config, io_config);
  machine_behavior = new MachineBehavior();
  emergency_stop = new EmergencyStop(machine_behavior, io_config);
}

// the loop function runs over and over again forever
void loop() {
  emergency_stop->check();
  compactor->configure();
  compactor->execute();
  // emergency_stop->check();
  delay(25);
}
