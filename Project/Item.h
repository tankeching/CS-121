#ifndef __ZorkProject__Item__
#define __ZorkProject__Item__

#include <iostream>
using namespace std;
#include <string>

#include "GameObject.h"

class Item : public GameObject{
public:
	Item(string name, string desc);

	virtual void use(GameObject& go) = 0;

	friend ostream& operator<<(ostream& os, const Item& item);

private:
};

#endif