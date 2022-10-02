#ifndef CompactorStopCommand_h
#define CompactorStopCommand_h

#include "Compactor.h"
#include "Command.h"

class CompactorStopCommand: public Command {
public:
	CompactorStopCommand(Compactor *compactor);
	void execute();
	void cancel();

private:
  Compactor *_compactor;
};
#endif
