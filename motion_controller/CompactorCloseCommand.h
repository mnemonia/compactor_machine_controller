#ifndef CompactorCloseCommand_h
#define CompactorCloseCommand_h

#include "Compactor.h"
#include "Command.h"


class CompactorCloseCommand: public Command {
public:
	CompactorCloseCommand(Compactor *compactor);
	void execute();
	void cancel();

private:
  Compactor *_compactor;
};
#endif
