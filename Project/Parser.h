#ifndef __ZorkProject__Parser__
#define __ZorkProject__Parser__

#include <iostream>
using namespace std;
#include "Command.h"
#include "CommandWords.h"

class Parser{
public:
	Parser();

	Command getCommand();

	void showCommands();

	friend ostream& operator<<(ostream& os, const Parser& pars);

private:
	CommandWords* _commandWords;
};

#endif