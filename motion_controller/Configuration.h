#ifndef Configuration_h
#define Configuration_h

#include "Arduino.h"

class Configuration {
public:
	Configuration();
	int get_stamp_duration();
	void set_stamp_duration(int stamp_duration_in_s);
private:
	int _stamp_duration_in_s;
};
#endif
