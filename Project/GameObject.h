#ifndef __ZorkProject__GameObject__
#define __ZorkProject__GameObject__

#include <iostream>
#include <string>
using namespace std;

class GameObject{
public:
	GameObject(string name, string desc);

	const string& name() const;
	const string& desc() const;

	friend ostream& operator<<(ostream& os, const GameObject& go);
	virtual ~GameObject() = 0;

private:
	string _name;
	string _desc;
};

#endif

