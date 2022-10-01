#include "IoConfiguration.h"
#include "Configuration.h"
#include "MachineBehavior.h"
#include "EmergencyStop.h"
#include "Compactor.h"
#include "CommandPanel.h"
#include "OperatingMode.h"
#include "Heating.h"

IoConfiguration *io_config;
Configuration *config;
Compactor *compactor;
Heating *heating_upper_upper;
Heating *heating_upper_lower;
Heating *heating_lower_upper;
Heating *heating_lower_lower;
MachineBehavior *machine_behavior;
EmergencyStop *emergency_stop;
CommandPanel *command_panel;
OperatingMode *operating_mode;
unsigned long _current_slow_tick = 0;
unsigned long _max_slow_tick = 100;

void setup() {
  io_config = new IoConfiguration();
  config = new Configuration();
  compactor = new Compactor(config, io_config);
  
  heating_upper_upper = new Heating(1, io_config->pin_heating_upper_upper_temperature_sensor(), io_config->pin_heating_upper_upper_oil_valve(), io_config->pin_heating_upper_upper_water_valve(), config);
  heating_upper_lower = new Heating(2, io_config->pin_heating_upper_upper_temperature_sensor(), io_config->pin_heating_upper_upper_oil_valve(), io_config->pin_heating_upper_upper_water_valve(), config);
  heating_lower_upper = new Heating(3, io_config->pin_heating_upper_upper_temperature_sensor(), io_config->pin_heating_upper_upper_oil_valve(), io_config->pin_heating_upper_upper_water_valve(), config);
  heating_lower_lower = new Heating(4, io_config->pin_heating_upper_upper_temperature_sensor(), io_config->pin_heating_upper_upper_oil_valve(), io_config->pin_heating_upper_upper_water_valve(), config);

  machine_behavior = new MachineBehavior();
  emergency_stop = new EmergencyStop(machine_behavior, io_config);
  operating_mode = new OperatingMode();
  command_panel = new CommandPanel(machine_behavior, config, io_config, operating_mode);

}

void update() {
  compactor->update();
  heating_upper_upper->update();
  heating_upper_lower->update();
  heating_lower_upper->update();
  heating_lower_lower->update();
}

void check() {
  emergency_stop->check();
  command_panel->check();
}

void tick() {
  compactor->tick();
}

void run_slow_tick() {
  heating_upper_upper->tick();
  heating_upper_lower->tick();
  heating_lower_upper->tick();
  heating_lower_lower->tick();
}

void slow_tick() {
  if (_current_slow_tick >= _max_slow_tick) {
    _current_slow_tick = 0;
    run_slow_tick();
  } else {
    _current_slow_tick++;
  }
}

// the loop function runs over and over again forever
void loop() {
  update();
  check();
  tick();
  slow_tick();
  delay(25);
}
