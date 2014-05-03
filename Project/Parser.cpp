#include "Parser.h"
#include <sstream>
#include <string>
#include <vector>

Parser::Parser() : _commandWords(CommandWords::getInstance()){}

Command Parser::getCommand(){
	string inputLine = "";

	cout << ">";
	getline(cin, inputLine);

	stringstream ss(inputLine);
	string aToken;
	vector<string> tokens;

	while (ss >> aToken){
		tokens.push_back(aToken);
	}

	cout << endl;
	if (_commandWords->isCommand(tokens[0])){
		if (tokens.size() == 2){ return Command(tokens[0], tokens[1]); }
		else { return Command(tokens[0]); }
	}

	else{ return Command("", tokens[0]); }
}

void Parser::showCommands() { _commandWords->showAll(); }