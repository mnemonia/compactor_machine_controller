//#include "Arduino.h”
#include "DebugService.h"

DebugService::DebugService(): _is_enabled(true) {
  if (_is_enabled) {
    // Serial.begin(9600);
    // while (!Serial) {
    //   ; // wait for serial port to connect. Needed for native USB port only
    // }    
  }
}

void DebugService::info(String msg){
  _emit(msg);
}

void DebugService::_emit(String msg){
  if (_is_enabled) {
    Serial.println(msg);
  }
}
