#ifndef DebugService_h
#define DebugService_h

#include "Arduino.h"

class DebugService {
public:
	DebugService();
	void info(String msg);
  void emit();
private:
  bool _is_enabled;
};
#endif
