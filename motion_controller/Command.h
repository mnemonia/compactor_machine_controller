#ifndef Command_h
#define Command_h

class Command {
public:
	virtual void execute() = 0;
	virtual void cancel() = 0;
};
#endif
