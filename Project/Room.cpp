#include "Room.h"
#include "Door.h"

Room::Room(string name, string description) : GameObject(name, description),
_exits(unordered_map<string, Room*>()){}

void Room::setExits(Room* north, Room* east, Room* south, Room* west){
	if (north != NULL){ _exits["north"] = north; }
	if (east != NULL){ _exits["east"] = east; }
	if (south != NULL){ _exits["south"] = south; }
	if (west != NULL){ _exits["west"] = west; }
}


string Room::shortDescription() const {
	return desc();
}

string Room::longDescription() const {
	return "You are " + desc() + ".\n" + exitString();
}

string Room::exitString() const{
	string s = "Exits:";

	for(unordered_map<string, Room*>::const_iterator citer = _exits.begin(); citer != _exits.end(); citer++){
		s += " " + citer->first;
	}

	s += "\n";

	return s;
}

Room* Room::nextRoom(string direction) const {
	unordered_map<string, Room*>::const_iterator citer = _exits.find(direction);
	return (citer == _exits.end() ? NULL : citer->second);
}