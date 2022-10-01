#ifndef Executable_h
#define Executable_h

#include "Arduino.h"

class Executable {
public:
	virtual void configure() = 0;
	virtual void execute() = 0;
};
#endif
