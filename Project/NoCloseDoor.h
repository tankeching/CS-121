#ifndef __ZorkProject__NoCloseDoor__
#define __ZorkProkect__NoCloseDoor__

#include "NoLockDoor.h"

class NoCloseDoor : public NoLockDoor{
public:
	NoCloseDoor();
	NoCloseDoor(string const& name, string const& desc, Room* room1, Room* room2, int lockCode = 0, bool isLocked = false, bool isOpen = true);

	virtual bool open();
	virtual bool close();

	friend ostream& operator<<(ostream& os, NoCloseDoor const& door);

private:
};

#endif