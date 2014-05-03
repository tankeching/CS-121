#ifndef __ZorkProject__CommandWords__
#define __ZorkProject__CommandWords__

#include <iostream>
#include <string>
using namespace std;

class CommandWords{
private:
	CommandWords();
	CommandWords(const CommandWords& other);
	CommandWords& operator=(const CommandWords& other);

public:
	~CommandWords();

	bool isCommand(string cmd);
	static CommandWords* getInstance();
	void showAll() const;

	friend ostream& operator<<(ostream& os, const CommandWords& cmdWords);
private:
	string _validCommands[4];
	int _length;
	static CommandWords* __instance;

};

#endif