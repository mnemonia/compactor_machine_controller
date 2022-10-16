#ifndef Stateable_h
#define Stateable_h

class Stateable {
public:
	virtual int state() = 0;
	virtual void next_state() = 0;
};
#endif
