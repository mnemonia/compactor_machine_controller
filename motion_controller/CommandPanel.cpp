#include "CommandPanel.h"
#include "CompactorOpenCommand.h"
#include "CompactorStopCommand.h"
#include "CompactorCloseCommand.h"
#include "SetAutomaticOperationModeCommand.h"
#include "SetManualOperationModeCommand.h"
#include "SetSetupOperationModeCommand.h"
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
  _configure();
}

void CommandPanel::check() {
  _compactor_open_btn->check();
  _compactor_close_btn->check();
  _operating_mode_setup_btn->check();
  _operating_mode_automatic_btn->check();
}

void CommandPanel::_configure() {
  CompactorOpenCommand *c_open_cmd = new CompactorOpenCommand(_machine->compactor());
  CompactorCloseCommand *c_close_cmd = new CompactorCloseCommand(_machine->compactor());
  CompactorStopCommand *c_stop_cmd = new CompactorStopCommand(_machine->compactor());
  _compactor_open_btn = new DebounceButton(_io_config->pin_compactor_open(), "compactor.open", c_open_cmd, c_stop_cmd, _debug_service);
  _compactor_close_btn = new DebounceButton(_io_config->pin_compactor_close(), "compactor.close", c_close_cmd, c_stop_cmd, _debug_service);

  SetManualOperationModeCommand *op_manual_cmd = new SetManualOperationModeCommand(_machine_behavior, this);
  SetAutomaticOperationModeCommand *op_automatic_cmd = new SetAutomaticOperationModeCommand(_machine_behavior, this);
  SetSetupOperationModeCommand *op_setup_cmd = new SetSetupOperationModeCommand(_machine_behavior, this);

  _operating_mode_setup_btn = new DebounceButton(_io_config->pin_operating_mode_setup_switch(), "operatingmode.setup", op_setup_cmd, op_manual_cmd, _debug_service);
  _operating_mode_automatic_btn = new DebounceButton(_io_config->pin_operating_mode_automatic_switch(), "operatingmode.automatic", op_automatic_cmd, op_manual_cmd, _debug_service);

  /* _operating_mode_btn = new OperatingModeButton(
                              _io_config->pin_operating_mode_setup_switch(),
                              _io_config->pin_operating_mode_automatic_switch(),
                              op_setup_cmd,
                              op_manual_cmd,
                              op_automatic_cmd);
   */
}

void CommandPanel::set_operating_mode_setup() {
  _machine->lamp_orange()->turn_on();
  _machine->lamp_blue()->turn_off();
  _machine->lamp_green()->turn_off();
  _compactor_open_btn->disable();
  _compactor_close_btn->disable();
  _operating_mode_automatic_btn->disable();
}

void CommandPanel::set_operating_mode_manual() {
  _machine->lamp_orange()->turn_off();
  _machine->lamp_blue()->turn_on();
  _machine->lamp_green()->turn_off();
  _compactor_open_btn->enable();
  _compactor_close_btn->enable();
  _operating_mode_automatic_btn->enable();
}

void CommandPanel::set_operating_mode_automatic() {
  _machine->lamp_orange()->turn_off();
  _machine->lamp_blue()->turn_off();
  _machine->lamp_green()->turn_on();
  _compactor_open_btn->disable();
  _compactor_close_btn->disable();
  _operating_mode_automatic_btn->enable();
}




