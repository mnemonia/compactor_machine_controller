//#include "Arduino.h”
#include "IoInitializationService.h"


IoInitializationService::IoInitializationService(Machine *machine): _machine(machine) {
}

void IoInitializationService::initialize(){
  Serial.println("IoInitializationService initialize");
  digitalWrite(13, HIGH);
  _machine->aggregate()->update();
  _machine->aggregate()->turn_on();
  _machine->aggregate()->tick();
  delay(1000);
  _machine->aggregate()->update();
  _machine->aggregate()->turn_off();
  _machine->aggregate()->tick();
  delay(1000);
  _machine->compactor()->update();
  _machine->compactor()->open();
  _machine->compactor()->tick();
  delay(1000);
  _machine->compactor()->update();
  _machine->compactor()->stop();
  _machine->compactor()->tick();

  _machine->compactor()->update();
  _machine->compactor()->close();
  _machine->compactor()->tick();
  delay(1000);
  _machine->compactor()->update();
  _machine->compactor()->stop();
  _machine->compactor()->tick();

  _machine->lamp_blue()->update();
  _machine->lamp_blue()->turn_on();
  _machine->lamp_blue()->tick();
  delay(1000);
  _machine->lamp_blue()->update();
  _machine->lamp_blue()->turn_off();
  _machine->lamp_blue()->tick();
  delay(1000);
  _machine->heating_upper_upper()->update();
  _machine->heating_upper_upper()->heat_up();
  _machine->heating_upper_upper()->tick();
  delay(1000);
  _machine->heating_upper_upper()->update();
  _machine->heating_upper_upper()->cool_down();
  _machine->heating_upper_upper()->tick();
  delay(1000);
  _machine->heating_upper_upper()->update();
  _machine->heating_upper_upper()->stop();
  _machine->heating_upper_upper()->tick();

  _machine->heating_upper_lower()->update();
  _machine->heating_upper_lower()->heat_up();
  _machine->heating_upper_lower()->tick();
  delay(1000);
  _machine->heating_upper_lower()->update();
  _machine->heating_upper_lower()->cool_down();
  _machine->heating_upper_lower()->tick();
  delay(1000);
  _machine->heating_upper_lower()->update();
  _machine->heating_upper_lower()->stop();
  _machine->heating_upper_lower()->tick();

  _machine->heating_lower_upper()->update();
  _machine->heating_lower_upper()->heat_up();
  _machine->heating_lower_upper()->tick();
  delay(1000);
  _machine->heating_lower_upper()->update();
  _machine->heating_lower_upper()->cool_down();
  _machine->heating_lower_upper()->tick();
  delay(1000);
  _machine->heating_lower_upper()->update();
  _machine->heating_lower_upper()->stop();
  _machine->heating_lower_upper()->tick();

  _machine->heating_lower_lower()->update();
  _machine->heating_lower_lower()->heat_up();
  _machine->heating_lower_lower()->tick();
  delay(1000);
  _machine->heating_lower_lower()->update();
  _machine->heating_lower_lower()->cool_down();
  _machine->heating_lower_lower()->tick();
  delay(1000);
  _machine->heating_lower_lower()->update();
  _machine->heating_lower_lower()->stop();
  _machine->heating_lower_lower()->tick();
  
  delay(1000);

  digitalWrite(13, LOW);
  //delay(1000);
}

