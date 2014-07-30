#ifndef __ZorkProject__Door__
#define __ZorkProject__Door__

#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

class Room;


#include "Key.h"
#include "GameObject.h"
#include "Room.h"
#include "Location.h"

class Door : public GameObject, public Location{
public:
	Door();
	Door(string const& name, string const& desc, Room* room1, Room* room2, int lockCode = 0, bool isLocked = true, bool isOpen = false);
	virtual ~Door();

	Room* nextRoom(Character& character) const;
	Room* room1() const;
	Room* room2() const;

	virtual bool enter(Character& character);
	virtual bool open();
	virtual bool close();
	virtual bool unlockWith(Key const& key);
	virtual bool lockWith(Key const& key);

	friend ostream& operator<<(ostream& os, Door const& door);

protected:
	Room *_room1, *_room2;
	int _lockCode;
	bool _isLocked, _isOpen;

};

#endif