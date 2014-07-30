#include "Game.h"
#include "Door.h"
#include "Room.h"
#include "NoCloseDoor.h"
#include "NoLockDoor.h"

Door::Door() : Door("no name door", "no desc", nullptr, nullptr, 0, true, false){}
Door::Door(string const& name, string const& desc, Room* room1, Room* room2, int lockCode, bool isLocked, bool isOpen)
: GameObject(name, desc), _room1(room1), _room2(room2), _lockCode(lockCode), _isLocked(isLocked), _isOpen(isOpen){}
Door::~Door(){}


Room* Door::nextRoom(Character& character) const{
	Room* currentRoom = character.currentRoom();
	if (currentRoom == nullptr) { return currentRoom; }
	else if (currentRoom != _room1 && currentRoom != _room2){ return nullptr; }
	return (_room1 == currentRoom ? _room2 : _room1);
}

bool Door::enter(Character& character){
	bool entered = false;
	Room*  next = nextRoom(character);
	if (next == nullptr) { cout << "has no next room" << endl; }
	else if (_isLocked) { cout << "is locked. Cannot enter." << endl; }
	else if (!_isOpen) { cout << "closed. Cannot enter." << endl; }
	else{
		entered = true;
		character.currentRoom()->exit(character);
		next->enter(character);
	}
	return entered;
}

bool Door::open(){
	if (_isLocked) { cout << "Door is locked and cannot be opened." << endl; }
	else { _isOpen = true; cout << "Door is now open." << endl; }
	return _isOpen;
}

bool Door::close() { _isOpen = false; cout << "now closed" << endl; return !_isOpen; }
bool Door::unlockWith(Key const& key){
	if (_isOpen){ cout << "is already unlocked and open." << endl; }
	else if (_lockCode == key.keycode()){ _isLocked = false; cout << "is now unlocked." << endl; }
	else { cout << "is still locked. Key doesn't match door." << endl; }
	return _isLocked;
}

bool Door::lockWith(Key const& key){
	if (_isOpen) { cout << "Door is open and cannot be locked." << endl; }
	else if (!_isOpen && (_lockCode == key.keycode())) { _isLocked = true; cout << "is now locked." << endl; }
	else { cout << "Door is still unlocked, Key doesn't match door." << endl; }
	return _isLocked;
}

Room* Door::room1() const { return _room1; }
Room* Door::room2() const { return _room2; }

ostream& operator<<(ostream& os, Door const& door){

	if (door._isLocked){ os << "[LOCKED "; }
	else { os << "[unlocked "; }
	if (door._isOpen){ os << "open]" << endl; }
	else { os << "CLOSED]" << endl;}

	return os;


}

