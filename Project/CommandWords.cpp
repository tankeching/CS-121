#include "CommandWords.h"
CommandWords* CommandWords::__instance = NULL;

CommandWords::CommandWords(): 
//_validCommands{ "go", "quit", "help" }, 
_length(sizeof(_validCommands) / sizeof(string)){

	_validCommands[0] = "go";
	_validCommands[1] = "quit";
	_validCommands[2] = "help";
	_validCommands[3] = "take";
	_validCommands[4] = "open";
	_validCommands[5] = "close";
	_validCommands[6] = "unlock";
	_validCommands[7] = "lock";
}

CommandWords::~CommandWords() { delete __instance; }

bool CommandWords::isCommand(string cmd){
	for (int i = 0; i < _length; i++){
		if (_validCommands[i] == cmd) { return true; }
	}
	return false;
}

CommandWords* CommandWords::getInstance() {
	if (__instance == NULL) { __instance = new CommandWords(); }
	return __instance;
}

void CommandWords::showAll() const { cout << *this; }

ostream& operator<<(ostream& os, const CommandWords& cmdWords){
	
	for (int i = 0; i < cmdWords._length; i++){
		os << cmdWords._validCommands[i] << endl;
	}

	return os << endl;
}