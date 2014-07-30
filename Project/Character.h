#ifndef __ZorkProject__Character__
#define __ZorkProject__Character__

#include <iostream>
using namespace std;
#include <string>

#include "GameObject.h"
#include "Location.h"
#include "Inventory.h"
#include "Door.h"
class Room;
class Item;
class Food;
class Weapon;

class Character : public GameObject{
public:
	Character();
	Character(string const& name, string const& description, int health = 100, int strength = 50);
	
	int health() const;
	void health(int health);

	int strength() const;
	void strength(int strength);

	Room* currentRoom() const;
	void currentRoom(Room* currentRoom);
	
	void setItems(vector<Item*> its);
	void addItem(Item* item);
	Item* findItem(string const& name);
	void removeItem(string const& name);
	string items() const;

	void use(Inventory<Item*>& inv, string const& nameItem, Inventory<Character*>& goinv, string const& gameObjectName);
	void use(Item& item, GameObject& go);
	void use(string const& itemName, string const& goName);
	void use(Item& item);
	void use(Door& door);

	bool go(Location::DIRECTION direction);

	virtual void attackWith(Weapon const& w);
	virtual void eat(Food const& f);
	virtual void take(string const& name);

	friend ostream& operator<<(ostream& os, const Character& ch);
	
private:
	int _health;
	int _strength;
	Inventory<Item*> _items;
	Room* _currentRoom;

};

#endif