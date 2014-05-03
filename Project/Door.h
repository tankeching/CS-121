#ifndef __ZorkProject__Door__
#define __ZorkProject__Door__

#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

#include "Key.h"
#include "GameObject.h"
#include "Room.h"

class Door : public GameObject{
public:
	Door(string const& name, string const& desc);

	void open();  
	void close();
	void lock(Key const& key);
	void unlock(Key const& key);

	void enter() const;



private:
	Room* _current;
	Room* _next;
	bool _isLocked;
	bool _isClosed;
	int _password;

};

#endif