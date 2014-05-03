#include "Item.h"

Item::Item(string name, string desc) : GameObject(name, desc){}

ostream& operator<<(ostream& os, const Item& item){
	return os << dynamic_cast<const GameObject&>(item);
}