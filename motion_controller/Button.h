#ifndef Button_h
#define Button_h

class Button {
public:
	virtual void check() = 0;
	virtual void enable() = 0;
	virtual void disable() = 0;
};
#endif
