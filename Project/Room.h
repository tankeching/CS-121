#ifndef __ZorkProject__Room__
#define __ZorkProject__Room__

#include <unordered_map>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

class Door;
class Character;

#include "Location.h"
#include "GameObject.h"

#include "Character.h"

#include "Door.h"

class Item;
class Lantern;

class Room : public GameObject, public Location{
public:
	Room();
	Room(string const& name, string const& desc, bool isDark = false, bool isLit = false);
	void setExits(Door* north, Door* east, Door* south, Door* west);


	string exits() const;
	Door* door(DIRECTION direction);
	Door* door(string const& name);

	void setCharacters(vector<Character*> cs);
	void addCharacter(Character* character);
	Character* findCharacter(string const& name);
	void removeCharacter(string const& name);
	string characters() const;

	void setItems(vector<Item*> its);
	void addItem(Item* item);
	Item* findItem(string const& name);
	void removeItem(string const& name);
	string items() const;

	string shortDescription() const;
	string longDescription() const;
	
	bool isDark() const;

	virtual void enter(Character& character);
	virtual void exit(Character& character);

	void lightWith(Lantern* lantern);

	friend ostream& operator<<(ostream& os, Room const& room);



private:
	bool _isDark, _isLit;
	Door* _exits[4];
	Inventory<Item*> _items;
	Inventory<Character*> _characters;
};

#endif