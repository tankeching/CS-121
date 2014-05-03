#ifndef __ZorkProject__Character__
#define __ZorkProject__Character__

#include <iostream>
using namespace std;
#include <string>

#include "GameObject.h"
#include "Item.h"
#include "Weapon.h"

class Character : public GameObject{
public:
	Character(string name, string description, int health = 100, int strength = 50);
	int health() const;
	void health(int val);

	int strength() const;
	void strength(int val);

	void use(Item& item, GameObject& go);

	virtual void attackWith(const Weapon& w);

	friend ostream& operator<<(ostream& os, const Character& c);
	
private:
	int _health;
	int _strength;
};

#endif