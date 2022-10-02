#ifndef DebugService_h
#define DebugService_h

#include "Arduino.h"

class DebugService {
public:
	DebugService();
	void info(String msg);

private:
  bool _is_enabled;
  void _emit(String msg);
};
#endif
