#ifndef __ZorkProject__Command__
#define __ZorkProject__Command__

#include <iostream>
#include <string>
using namespace std;

class Command{
public:
	Command(string secondword);
	Command(string commandWord, string secondWord);
	Command(string commandWord, string secondWord, string thirdWord);

	string getCommandWord() const;
	string getSecondWord() const;
	string getThirdWord() const;

	bool isUnknown() const;
	bool hasSecondWord() const;
	bool hasThirdWord() const;

private:
	string _commandWord;
	string _secondWord;
	string _thirdWord;
};

#endif