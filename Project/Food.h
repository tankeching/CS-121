#ifndef __ZorkProject__Food__
#define __ZorkProject__Food__

#include <iostream>
#include <string>
using namespace std;

#include "Item.h"

class Food : public Item{
public:
	Food(string const& name, string const& desc, int keycode);

	void use(GameObject& go);


private:
	int _heal;
};

#endif