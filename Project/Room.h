#ifndef __ZorkProject__Room__
#define __ZorkProject__Room__

#include <unordered_map>
#include <iostream>
using namespace std;
#include <string>

#include "GameObject.h"
#include "Inventory.h"
#include "Character.h"
#include "Item.h"


class Room : public GameObject{
public:
	Room(string name, string description);
	void setExits(Room* north, Room* east, Room* south, Room* west);


	string shortDescription() const;
	string longDescription() const;
	string exitString() const;

	Room* nextRoom(string description) const;


private:
	unordered_map< string, Room*> _exits;
	Inventory<Item*> _ritems;
	Inventory<Character*> _rchars;



};

#endif