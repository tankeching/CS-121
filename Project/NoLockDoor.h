#ifndef __ZorkProject__NoLockDoor__
#define __ZorkProject__NoLockDoor__

#include "Door.h"

class NoLockDoor : public Door{
public:
	NoLockDoor();
	NoLockDoor(string const& name, string const& desc, Room* room1, Room* room2, int lockCode = 0, bool isLocked = false, bool isOpen = false);

	virtual bool open();
	virtual bool close();
	virtual bool unlockWith(Key const& key);
	virtual bool lockWith(Key const& key);

	friend ostream& operator<<(ostream& os, NoLockDoor const& door);
};

#endif