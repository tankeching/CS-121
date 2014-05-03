#ifndef __ZorkProject__Game__
#define __ZorkProject__Game__

#include <vector>
#include <iostream>
using namespace std;

#include "Parser.h"
#include "Room.h"
#include "Door.h"

class Game{
private:
	Game();
	Game(const Game& other);
	Game& operator=(const Game& other);

public:
	~Game();
	void play();
	static Game* getInstance();

private:
	void createRooms();
	void deleteRooms();

	void goRoom(Command command);
	bool processCommand(Command command);

	void printHelp();
	void printWelcome();

	friend ostream& operator<<(ostream& os, const Game& game);

private:
	Parser _parser;
	Room* _currentRoom;
	Door* _ahead;
	vector<Room*> _rooms;
	static Game* __instance;
};

#endif