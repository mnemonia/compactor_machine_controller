#ifndef Executable_h
#define Executable_h

#include "Arduino.h"

class Executable {
public:
	virtual void update() = 0;
	virtual void execute() = 0;
	virtual void tick() = 0;
};
#endif
