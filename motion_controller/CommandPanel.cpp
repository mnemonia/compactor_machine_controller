#include "CommandPanel.h"
#include "CompactorOpenCommand.h"
#include "CompactorStopCommand.h"
#include "CompactorCloseCommand.h"
#include "SetAutomaticOperationModeCommand.h"
#include "SetManualOperationModeCommand.h"
#include "SetSetupOperationModeCommand.h"
#include "HydraulicAggregateStartCommand.h"
#include "HydraulicAggregateStopCommand.h"
#include "TemperatureControlOnCommand.h"
#include "TemperatureControlOffCommand.h"
#include "Button.h"
#include "DebounceButton.h"
#include "OperatingModeButton.h"


CommandPanel::CommandPanel(MachineBehavior *machine_behavior, Machine *machine, Configuration *config, IoConfiguration *io_config, OperatingMode *operating_mode, DebugService *debug_service):
  _machine_behavior(machine_behavior),
  _machine(machine),
  _config(config),
  _io_config(io_config),
  _operating_mode(operating_mode),
  _debug_service(debug_service)
{
  CompactorOpenCommand *c_open_cmd = new CompactorOpenCommand(_machine->compactor());
  CompactorCloseCommand *c_close_cmd = new CompactorCloseCommand(_machine->compactor());
  CompactorStopCommand *c_stop_cmd = new CompactorStopCommand(_machine->compactor());
  _compactor_open_btn = new DebounceButton(_io_config->pin_compactor_open_button(), 1, c_open_cmd, c_stop_cmd);
  _compactor_close_btn = new DebounceButton(_io_config->pin_compactor_close_button(), 2, c_close_cmd, c_stop_cmd);

  SetManualOperationModeCommand *op_manual_cmd = new SetManualOperationModeCommand(_machine_behavior, this);
  SetAutomaticOperationModeCommand *op_automatic_cmd = new SetAutomaticOperationModeCommand(_machine_behavior, this);
  _operating_mode_automatic_btn = new DebounceButton(_io_config->pin_operating_mode_automatic_switch(), 3, op_automatic_cmd, op_manual_cmd);

  SetSetupOperationModeCommand *op_setup_cmd = new SetSetupOperationModeCommand(_machine_behavior, this);
  _operating_mode_setup_btn = new DebounceButton(_io_config->pin_operating_mode_setup_switch(), 4, op_setup_cmd, op_manual_cmd);

  HydraulicAggregateStartCommand *a_start_cmd = new HydraulicAggregateStartCommand(_machine->aggregate());
  HydraulicAggregateStopCommand *a_stop_cmd = new HydraulicAggregateStopCommand(_machine->aggregate());
  _aggregate_switch = new DebounceButton(_io_config->pin_aggregate_start_button(), 5, a_start_cmd, a_stop_cmd);

  TemperatureControlOnCommand *tc_on_cmd = new TemperatureControlOnCommand(_machine); 
  TemperatureControlOffCommand *tc_off_cmd = new TemperatureControlOffCommand(_machine); 
  _temperature_control_btn = new DebounceButton(_io_config->pin_temperature_control_button(), 6, tc_on_cmd, tc_off_cmd);

  op_manual_cmd->execute();
}

void CommandPanel::check() {
  _aggregate_switch->check();
  _compactor_open_btn->check();
  _compactor_close_btn->check();
  _operating_mode_setup_btn->check();
  _operating_mode_automatic_btn->check();
  _temperature_control_btn->check();
}

void CommandPanel::_configure() {
  // SetManualOperationModeCommand *op_manual_cmd = new SetManualOperationModeCommand(_machine_behavior, this);
  // SetAutomaticOperationModeCommand *op_automatic_cmd = new SetAutomaticOperationModeCommand(_machine_behavior, this);
  // _operating_mode_automatic_btn = new DebounceButton(_io_config->pin_operating_mode_automatic_switch(), 0x11, op_automatic_cmd, op_manual_cmd);

  // SetSetupOperationModeCommand *op_setup_cmd = new SetSetupOperationModeCommand(_machine_behavior, this);
  // _operating_mode_setup_btn = new DebounceButton(_io_config->pin_operating_mode_setup_switch(), 0x12, op_setup_cmd, op_manual_cmd);

  // CompactorOpenCommand *c_open_cmd = new CompactorOpenCommand(_machine->compactor());
  // CompactorCloseCommand *c_close_cmd = new CompactorCloseCommand(_machine->compactor());
  // CompactorStopCommand *c_stop_cmd = new CompactorStopCommand(_machine->compactor());
  // _compactor_open_btn = new DebounceButton(_io_config->pin_compactor_open_button(), 0x01, c_open_cmd, c_stop_cmd);
  // _compactor_close_btn = new DebounceButton(_io_config->pin_compactor_close_button(), 0x02, c_close_cmd, c_stop_cmd);

  // HydraulicAggregateStartCommand *hy_start_cmd = new HydraulicAggregateStartCommand(_machine->aggregate());
  // HydraulicAggregateStopCommand *hy_stop_cmd = new HydraulicAggregateStopCommand(_machine->aggregate());
  // _aggregate_switch = new DebounceButton(_io_config->pin_aggregate(), 0x21, hy_start_cmd, hy_stop_cmd);
  //_hydraulic_switch = 0;
  //_machine->add_command(c_stop_cmd);
  //_machine->add_command(c_close_cmd);
  /* _operating_mode_btn = new OperatingModeButton(
                              _io_config->pin_operating_mode_setup_switch(),
                              _io_config->pin_operating_mode_automatic_switch(),
                              op_setup_cmd,
                              op_manual_cmd,
                              op_automatic_cmd);
   */
 // set_operating_mode_manual();
}

void CommandPanel::set_operating_mode_setup() {
  _operating_mode->set_setup();
  _machine->lamp_orange()->turn_on();
  _machine->lamp_blue()->turn_off();
  _machine->lamp_green()->turn_off();
  _compactor_open_btn->disable();
  _compactor_close_btn->disable();
  _operating_mode_automatic_btn->disable();
  _aggregate_switch->enable();
  _temperature_control_btn->enable();
}

void CommandPanel::set_operating_mode_manual() {
  _operating_mode->set_manual();
  _machine->lamp_orange()->turn_off();
  _machine->lamp_blue()->turn_on();
  _machine->lamp_green()->turn_off();
  _compactor_open_btn->enable();
  _compactor_open_btn->enable();
  _compactor_close_btn->enable();
  _operating_mode_automatic_btn->enable();
  _aggregate_switch->enable();
  _temperature_control_btn->enable();
}

void CommandPanel::set_operating_mode_automatic() {
  _operating_mode->set_automatic();
  _machine->lamp_orange()->turn_off();
  _machine->lamp_blue()->turn_off();
  _machine->lamp_green()->turn_on();
  _compactor_open_btn->disable();
  _compactor_close_btn->disable();
  _operating_mode_automatic_btn->enable();
  _aggregate_switch->disable();
  _temperature_control_btn->disable();
}




