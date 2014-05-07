#include "NoCloseDoor.h"
#include "NoLockDoor.h"

NoCloseDoor::NoCloseDoor() : NoCloseDoor("no name door", "no desc", nullptr, nullptr, 0, false, true){}

NoCloseDoor::NoCloseDoor(string const& name, string const& desc, Room* room1, Room* room2, int lockCode, bool isLocked, bool isOpen){}

bool NoCloseDoor::open(){
	_isOpen = true;
	return _isOpen;
}

bool NoCloseDoor::close(){
	_isOpen = true; cout << " this door cannot be closed." << endl;
	return _isOpen;
}

ostream& operator<<(ostream& os, NoCloseDoor const& door){
	return os << "Dr[" << dynamic_cast<GameObject const&>(door)
		<< door._lockCode << ","
		<< (door._isLocked ? "LOCKED" : "unlocked") << ","
		<< (door._isOpen ? "open" : "CLOSED") << "]";
}