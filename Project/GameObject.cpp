#include "GameObject.h"

GameObject::GameObject(string name, string desc) : _name(name),_desc(desc){}

GameObject::~GameObject() {}

const string& GameObject::name() const { return _name; }
const string& GameObject::desc() const { return _desc; }

ostream& operator<<(ostream& os, const GameObject& go){
	return os << "GameObj[" << go._name << "," << go._desc << "]";
}