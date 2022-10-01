#ifndef OperatingMode_h
#define OperatingMode_h

class OperatingMode {
public:
	OperatingMode();
  void set_manual();
  void set_automatic();
  int get_current();
private:
  int _current_operating_mode;
  int MANUAL;
  int AUTOMATIC;
};
#endif
