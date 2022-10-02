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
  String input_string = "";
  while (Serial.available()) {
    // get the new byte:
    char inChar = (char)Serial.read();
    // add it to the inputString:
    input_string += inChar;
    // if the incoming character is a newline, set a flag so the main loop can
    // do something about it:
    if (inChar == '\n') {
      is_complete = true;
      Serial.println("CommunicationService received data from serial: " + input_string);
      if (input_string.startsWith("P")) {
        // Is a parameter. Let's apply it.
        int index = input_string.indexOf('=');
        String param_id = input_string.substring(0,index);
        int value = input_string.substring(index + 1).toInt();
        Serial.println(param_id);
        Serial.println(value);        
        _config->apply(param_id, value);
      }
      if (input_string.startsWith("C")) {
          Serial.println("Command: "+input_string);
          _remote_control_service->trigger(input_string);
      }
    }
  }
}
