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


CommandPanel::CommandPanel(MachineBehavior *machine_behavior, Configuration *config, IoConfiguration *io_config, OperatingMode *operating_mode):
  _machine_behavior(machine_behavior),
  _config(config),
  _io_config(io_config),
  _operating_mode(operating_mode)
{
  _configure();
}

void CommandPanel::check() {
  _compactor_open_btn->check();
  _compactor_close_btn->check();
  _operating_mode_btn->check();
}

void CommandPanel::_configure() {
  CompactorOpenCommand *c_open_cmd = new CompactorOpenCommand(_machine_behavior);
  CompactorCloseCommand *c_close_cmd = new CompactorCloseCommand(_machine_behavior);
  CompactorStopCommand *c_stop_cmd = new CompactorStopCommand(_machine_behavior);
  _compactor_open_btn = new DebounceButton(_io_config->pin_compactor_open(), c_open_cmd, c_stop_cmd);
  _compactor_close_btn = new DebounceButton(_io_config->pin_compactor_close(), c_close_cmd, c_stop_cmd);

  SetManualOperationModeCommand *op_manual_cmd = new SetManualOperationModeCommand(_machine_behavior, this);
  SetAutomaticOperationModeCommand *op_automatic_cmd = new SetAutomaticOperationModeCommand(_machine_behavior, this);
  SetSetupOperationModeCommand *op_setup_cmd = new SetSetupOperationModeCommand(_machine_behavior, this);
  _operating_mode_btn = new OperatingModeButton(
                              _io_config->pin_operating_mode_setup_switch(),
                              _io_config->pin_operating_mode_automatic_switch(),
                              op_setup_cmd,
                              op_manual_cmd,
                              op_automatic_cmd);
}

void CommandPanel::set_operating_mode_setup() {
  _compactor_open_btn->disable();
  _compactor_close_btn->disable();
}

void CommandPanel::set_operating_mode_manual() {
  _compactor_open_btn->enable();
  _compactor_close_btn->enable();
}

void CommandPanel::set_operating_mode_automatic() {
  _compactor_open_btn->disable();
  _compactor_close_btn->disable();
}




