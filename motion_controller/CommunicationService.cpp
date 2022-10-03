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
  
  bool is_complete = false;
  int index;
  int param_id;
  int value;
  int command_id;
  // String input_string = "";
  String input_string = Serial.readStringUntil("\n");
  //char buffer[100];
  //Serial.readBytesUntil("\n", buffer, 100);
  //String input_string("P511=43");
  //Serial.println(input_string);
  if (input_string.startsWith("P")) {
    input_string = _cleanup(input_string);
    // Is a parameter. Let's apply it.
    //input_string = input_string.substring(0, input_string.length() - 1);
    //Serial.println(input_string);
    index = input_string.indexOf('=');
    String param_id_str = input_string.substring(0, index);
    param_id = param_id_str.toInt();
    String value_str = input_string.substring(index + 1);
    value = value_str.toInt();
    _config->apply(param_id, value);
  } else if (input_string.startsWith("C")) {
    input_string = _cleanup(input_string);
    command_id = input_string.toInt();
    _remote_control_service->trigger(command_id);
  }


  // while (Serial.available()) {
  //   // get the new byte:
  //   char inChar = (char)Serial.read();
  //   // add it to the inputString:
  //   if (inChar != '\n') {
  //     input_string += inChar;
  //   }
  //   // if the incoming character is a newline, set a flag so the main loop can
  //   // do something about it:
  //   if (inChar == '\n') {
  //     is_complete = true;
  //     // Serial.println("CommunicationService received data from serial: " + input_string);
  //     if (input_string.startsWith("P")) {
  //       // Is a parameter. Let's apply it.
  //       index = input_string.indexOf('=');
  //       param_id = input_string.substring(1, index).toInt();
  //       value = input_string.substring(index + 1).toInt();
  //       _config->apply(param_id, value);
  //     } else if (input_string.startsWith("C")) {
  //       command_id = input_string.substring(1).toInt();
  //       _remote_control_service->trigger(command_id);
  //     }
  //   }
  // }
}


String CommunicationService::_cleanup(String value) {
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