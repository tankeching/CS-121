#include "Command.h"

Command::Command(string commandWord) : Command(commandWord, "", ""){}

Command::Command(string commandWord, string secondWord) : Command(commandWord, secondWord, ""){}

Command::Command(string commandWord, string secondWord, string thirdWord)
: _commandWord(commandWord), _secondWord(secondWord), _thirdWord(thirdWord){}

string Command::getCommandWord() const { return _commandWord; }
string Command::getSecondWord() const { return _secondWord; }
string Command::getThirdWord() const { return _thirdWord; }

bool Command::isUnknown() const { return _commandWord.length() == 0; }
bool Command::hasSecondWord() const { return _secondWord.length() > 0; }
bool Command::hasThirdWord() const { return _thirdWord.length() > 0; }
