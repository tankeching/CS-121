#include "NoCloseDoor.h"

NoCloseDoor::NoCloseDoor() : NoCloseDoor("no name door", "no desc", nullptr, nullptr, 0, false, true){}

NoCloseDoor::NoCloseDoor(string const& name, string const& desc, Room* room1, Room* room2, int lockCode, bool isLocked, bool isOpen)
: NoLockDoor( name, desc, room1, room2, lockCode, isLocked, isOpen )  {}

bool NoCloseDoor::open(){
	_isOpen = true;
	return _isOpen;
}

bool NoCloseDoor::close(){
	_isOpen = true; cout << " this door cannot be closed." << endl;
	return _isOpen;
}

ostream& operator<<(ostream& os, NoCloseDoor const& door){
	return os << "Dr[" << dynamic_cast<NoLockDoor const&>(door) << "]";
}