#include "NoLockDoor.h"

NoLockDoor::NoLockDoor() : NoLockDoor("no name", "no desc", nullptr, nullptr, 0, false, false){}
NoLockDoor::NoLockDoor(string const& name, string const& desc, Room* room1, Room* room2, int lockCode, bool isLocked, bool isOpen)
: Door(name, desc, room1, room2, lockCode, isLocked, isOpen){}



bool NoLockDoor::open(){
	_isOpen = true; cout << "is now open." << endl;
	return _isOpen;
}

bool NoLockDoor::close(){
	_isOpen = false; cout << "is now closed." << endl;
	return _isOpen;
}

bool NoLockDoor::unlockWith(Key const& key){
	_isLocked = false; cout << "cannot be unlocked. Door was not locked." << endl;
	return _isLocked;
}

bool NoLockDoor::lockWith(Key const& key){
	_isLocked = false; cout << "door cannot be locked." << endl;
	return _isLocked;
}

ostream& operator<<(ostream& os, NoLockDoor const& door){
	return os << "Dr[" << dynamic_cast<GameObject const&>(door)
		<< door._lockCode << ","
		<< (door._isLocked ? "LOCKED" : "unlocked") << ","
		<< (door._isOpen ? "open" : "CLOSED") << "]";
}