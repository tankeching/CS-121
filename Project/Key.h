#ifndef __ZorkProject__Key__
#define __ZorkProject__Key__

#include <iostream>
#include <string>
using namespace std;

#include "Item.h"

class Key : public Item{
public:
	Key(string const& name, string const& desc, int keycode);

	void use(GameObject& go);

	int keycode() const;
private:
	int _keycode;
};

#endif