#ifndef __ZorkProject__Weapon__
#define __ZorkProject__Weapon__

#include <iostream>
using namespace std;
#include <string>

#include "Item.h"

class Weapon : public Item{
public:
	Weapon(string name, string desc, int damagePotl = 10, int defensePotl = 20);

	int damagePotl() const;
	int defensePotl() const;

	virtual void use(GameObject& go);

	friend ostream& operator<<(ostream& os, const Weapon& w);

private:
	int _damagePotl;
	int _defensePotl;
};

#endif