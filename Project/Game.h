#ifndef __ZorkProject__Game__
#define __ZorkProject__Game__

#include <vector>
#include <iostream>
#include <string>
using namespace std;

#include "Parser.h"
#include "Room.h"
#include "Door.h"
#include "Character.h"

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
	void takeItem(Command command);
	void openDoor(Command command);
	void closeDoor(Command command);
	void unlockDoor(Command command);
	void lockDoor(Command command);
	void attackMonster(Command command);
	void searchRoom(Command command);
	bool processCommand(Command command);

	void printHelp();
	void printWelcome();

	friend ostream& operator<<(ostream& os, const Game& game);

private:
	Parser _parser;
//	Room* _currentRoom;
	vector<Room*> _rooms;
	static Game* __instance;
	Inventory<Item*> _heroInventory;
	Character* _Player = new Character("Player", "the only player");
};

#endif