#ifndef __ZorkProject__Key__
#define __ZorkProkect__Key__

#include <iostream>
#include <string>
using namespace std;

#include "Item.h"

class Key : public Item{
public:
	Key(string const& name, string const& desc);

	void use(GameObject& go);

	int keycode();
};

#endif