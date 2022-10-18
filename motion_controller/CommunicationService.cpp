//#include "Arduino.h”
#include "CommunicationService.h"


CommunicationService::CommunicationService(Configuration *config, RemoteControlService *remote_control_service): _config(config), _remote_control_service(remote_control_service), _is_enabled(true) {
  if (_is_enabled) {
    // Serial.begin(9600);
  }
}

void CommunicationService::write(){
  if (!_is_enabled) { return; }
  
  Serial.println("CommunicationService actual-values to serial");
}

void CommunicationService::update(){
  if (!_is_enabled) { return; }
  
  int index;
  uint16_t param_id;
  uint16_t value;
  uint16_t command_id;

  const int BUFFER_SIZE = 100;
  char buf[BUFFER_SIZE];

  int rlen = Serial.readBytesUntil('\n', buf, BUFFER_SIZE);
  if (rlen <= 0) {
    return;
  }
  if (buf[0] == 0x01) {
    param_id = 0;
    param_id = buf[1] << 8;
    param_id |= buf[2];
    value = 0;
    value = buf[3] << 8;
    value |= buf[4];
    _config->apply(param_id, value);
  } else if (buf[0] == 0x02) {
    command_id = 0;
    command_id = buf[1] << 8;
    command_id += int(buf[2]);
    _remote_control_service->trigger(command_id);
  }
}


String CommunicationService::_cleanup_cmd(String value) {
  // Serial.print("[");
  // Serial.print(value);
  // Serial.println("]");
  value.remove(value.length() - 1, 1);
  value.remove(0, 1);
  // Serial.print("[[");
  // Serial.print(value);
  // Serial.println("]]");
  return value;
}

String CommunicationService::_cleanup_param(String value) {
  /* Serial.print("[");
  Serial.print(value);
  Serial.println("]"); */
  if (value.length() > 2) {
    value.remove(value.length() - 1, 1);
    value.remove(0, 1);
  }
  /* Serial.print("[[");
  Serial.print(value);
  Serial.println("]]"); */
  return value;
}