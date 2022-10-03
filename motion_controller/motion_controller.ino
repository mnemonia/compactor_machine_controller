#include "IoConfiguration.h"
#include "Configuration.h"
#include "MachineBehavior.h"
#include "EmergencyStop.h"
#include "Compactor.h"
#include "CommandPanel.h"
#include "OperatingMode.h"
#include "Heating.h"
#include "Lamp.h"
#include "DebugService.h"
#include "CommunicationService.h"
#include "Machine.h"
#include "RemoteControlService.h"
#include "HydraulicAggregate.h"


IoConfiguration *io_config;
Configuration *config;
Compactor *compactor;
HydraulicAggregate *aggregate;
Heating *heating_upper_upper;
Heating *heating_upper_lower;
Heating *heating_lower_upper;
Heating *heating_lower_lower;
Lamp *lamp_orange;
Lamp *lamp_blue;
Lamp *lamp_green;
MachineBehavior *machine_behavior;
EmergencyStop *emergency_stop;
CommandPanel *command_panel;
OperatingMode *operating_mode;
unsigned long _current_slow_tick = 0;
unsigned long _max_slow_tick = 300;
DebugService *debug_service;
CommunicationService *communication_service;
Machine *machine;
RemoteControlService *remote_control_service;

void setup() {
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
  Serial.flush();
  Serial.setTimeout(5);
  Serial.println("Kessler Compactor Motion Controller");
  Serial.println("starting...");

  io_config = new IoConfiguration();
  config = new Configuration();
  compactor = new Compactor(config, io_config);
  debug_service = new DebugService();

  Serial.println("init hydraulics");
  aggregate = new HydraulicAggregate(1, io_config->pin_aggregate());

  Serial.println("init lamps");
  lamp_orange = new Lamp(1, io_config->pin_lamp_orange(), debug_service);
  lamp_blue = new Lamp(2, io_config->pin_lamp_blue(), debug_service);
  lamp_green = new Lamp(3, io_config->pin_lamp_green(), debug_service);

  Serial.println("init heating");
  heating_upper_upper = new Heating(1, io_config->pin_heating_upper_upper_temperature_sensor(), io_config->pin_heating_upper_upper_oil_valve(), io_config->pin_heating_upper_upper_water_valve(), config);
  heating_upper_lower = new Heating(2, io_config->pin_heating_upper_lower_temperature_sensor(), io_config->pin_heating_upper_lower_oil_valve(), io_config->pin_heating_upper_lower_water_valve(), config);
  heating_lower_upper = new Heating(3, io_config->pin_heating_lower_upper_temperature_sensor(), io_config->pin_heating_lower_upper_oil_valve(), io_config->pin_heating_lower_upper_water_valve(), config);
  heating_lower_lower = new Heating(4, io_config->pin_heating_lower_lower_temperature_sensor(), io_config->pin_heating_lower_lower_oil_valve(), io_config->pin_heating_lower_lower_water_valve(), config);

  Serial.println("init machine");
  machine = new Machine(compactor, lamp_orange, lamp_blue, lamp_green, heating_upper_upper, heating_upper_lower, heating_lower_upper, heating_lower_lower, aggregate);

  Serial.println("init remote interface");
  remote_control_service = new RemoteControlService(config, machine);
  communication_service = new CommunicationService(config, remote_control_service);

  machine_behavior = new MachineBehavior();
  operating_mode = new OperatingMode();

  Serial.println("init conrtol panel");
  command_panel = new CommandPanel(machine_behavior, machine, config, io_config, operating_mode, debug_service);

  Serial.println("init emergency stop");
  emergency_stop = new EmergencyStop(machine_behavior, io_config);

  Serial.println("ready");
  Serial.flush();
  //debug_service->info("ready");
  //lamp_blue->turn_on();
}

void update() {
  communication_service->update();
  aggregate->update();
  compactor->update();
  heating_upper_upper->update();
  heating_upper_lower->update();
  heating_lower_upper->update();
  heating_lower_lower->update();
 // debug_service->info("update");
}

void check() {
  emergency_stop->check();
  //command_panel->check();
}

void tick() {
  aggregate->tick();
  compactor->tick();
}

void _run_slow_tick() {
  // debug_service->info("slow tick");
  heating_upper_upper->tick();
  heating_upper_lower->tick();
  heating_lower_upper->tick();
  heating_lower_lower->tick();
 // Serial.print("heating_nominal_temperature_analog_value_1 is ");
  Serial.println(config->get_heating_nominal_temperature_analog_value(1));
  //Serial.flush();
}

void slow_tick() {
  if (_current_slow_tick >= _max_slow_tick) {
    _current_slow_tick = 0;
    _run_slow_tick();
  } else {
    _current_slow_tick++;
  }
}

// the loop function runs over and over again forever
void loop() {
  debug_service->emit();
  update();
  check();
  tick();
  slow_tick();
  delay(2);
 // debug_service->info("loop");
}

/*
  SerialEvent occurs whenever a new data comes in the hardware serial RX. This
  routine is run between each time loop() runs, so using delay inside loop can
  delay response. Multiple bytes of data may be available.
*/
void serialEvent() {
  communication_service->update();
}