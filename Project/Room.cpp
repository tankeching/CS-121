#include <vector>
#include <sstream>
#include "Room.h"
#include "NoCloseDoor.h"
#include "NoLockDoor.h"

#include "Game.h"
#include "Key.h"
#include "Food.h"
//#include "Lantern.h
#include "Weapon.h"


Room::Room() : Room("no name room", "no desc", false, false){}
Room::Room(string const& name, string const& desc, bool isDark, bool isLit) : GameObject(name, desc), _isDark(isDark), _isLit(isLit){}

void Room::setExits(Door* north, Door* east, Door* south, Door* west){
	_exits[NORTH] = north;
	_exits[EAST] = east;
	_exits[SOUTH] = south;
	_exits[WEST] = west;
}


string Room::exits() const{
	ostringstream ss;
	for(int i = NORTH; i < WEST; i++){
		string direction;
		switch(i){
		case NORTH: direction = "North"; break;
		case EAST: direction = "East"; break;
		case SOUTH: direction = "South"; break;
		case WEST: direction = "West"; break;
		}
		
		if (_exits[i] != nullptr){ ss << direction << " " << *_exits[i]; }
	}
	return ss.str();
}
Door* Room::door(DIRECTION direction){ return _exits[direction]; }
Door* Room::door(string const& name){
	for (Door* door : _exits){
		if (door != nullptr && door->name() == name){ return door; }
	}
	return nullptr;
}

void Room::setCharacters(vector<Character*> cs){
	for (vector<Character*>::iterator it = cs.begin(); it != cs.end(); it++){
		_characters.add(*it);
		(*it)->currentRoom(this);
	}
}


void Room::addCharacter(Character* character){ _characters.add(character); }
void Room::removeCharacter(string const& name){ _characters.remove(name); }
Character* Room::findCharacter(string const& name){
	if (_isDark){ cout << "Room is dark. Cannot find characters." << endl; return nullptr; }
	return _characters.find(name);
}

string Room::characters() const{ return  _characters.objects(); }

void Room::setItems(vector<Item*> its){
	for (vector<Item*>::iterator it = its.begin(); it != its.end(); it++){ _items.add(*it); }
}

void Room::addItem(Item* item){ _items.add(item); }
void Room::removeItem(string const& name){ _items.remove(name); }
Item* Room::findItem(string const& name){
	if (_isDark){ cout << "Room is dark. Cannot find items." << endl; return nullptr; }
	return _items.find(name);
}
string Room::items() const{ return _items.objects(); }

string Room::shortDescription() const{ return desc(); }
string Room::longDescription() const{ return "You are " + desc() + ".\n" + exits(); }

bool Room::isDark() const { return _isDark; }

void Room::enter(Character& character){
	character.currentRoom(this);
	this->addCharacter(&character);

}

void Room::exit(Character& character){
	this->removeCharacter(character.name());

}



ostream& operator<<(ostream& os, Room const& room){
	os << "Rm[" << dynamic_cast <GameObject const&>(room)
		<< ",[" << room.exits() << "]"
		<< ",isDark=" << room._isDark << ",isLit=" << room._isLit
		<< room.characters() << "]"
		<< room.items() << "]]";


	return os;
}


