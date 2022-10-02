#ifndef CompactorOpenCommand_h
#define CompactorOpenCommand_h

#include "Compactor.h"
#include "Command.h"

class CompactorOpenCommand: public Command {
public:
	CompactorOpenCommand(Compactor *compactor);
	void execute();
	void cancel();

private:
  Compactor *_compactor;
};
#endif
