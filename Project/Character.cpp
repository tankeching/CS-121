#include "Character.h"
#include "Room.h"
#include "Item.h"
#include "Food.h"
#include "Weapon.h"

Character::Character() : Character("no name", "no desc"){}
Character::Character(string const& name, string const& desc, int health, int strength)
: GameObject(name, desc), _health(health), _strength(strength) {}

int Character::health() const { return _health; }
void Character::health(int health) { _health = health; }

int Character::strength() const { return _strength; }
void Character::strength(int strength) { _strength = strength; }

Room* Character::currentRoom() const { return _currentRoom; }
void Character::currentRoom(Room* currentRoom) { _currentRoom = currentRoom; }

void Character::setItems(vector<Item*> its){
	for (vector<Item*>::iterator it = its.begin(); it != its.end(); it++){ _items.add(*it); }
}

void Character::addItem(Item* item) { _items.add(item); }
string Character::items() const { return _items.objects(); }

Item* Character::findItem(string const& name) { return _items.find(name); }
void Character::removeItem(string const& name){ return _items.remove(name); }

void Character::use(Inventory<Item*>& inv, string const& nameItem, Inventory<Character*>& goinv, string const& gameObjectName){
	Item* item = inv.find(nameItem);
	GameObject* go = goinv.find(gameObjectName);

	if (item == nullptr || go == nullptr){
		cout << name() << "couldn't use " << nameItem << " on " << gameObjectName << endl; return;
	}

	use(*item, *go);
}

void Character::use(string const& itemName, string const& goName){
	Item* item = findItem(itemName);
	GameObject* go = nullptr;
	Room* current = currentRoom();
	if (goName == current->name()){ go = current; }
	if (go == nullptr){ go = findItem(goName); }
	if (go == nullptr){ go = current->findCharacter(goName); }
	if (go == nullptr){ go = current->door(goName); }

	if (item == nullptr || go == nullptr){
		cout << name() << " couldn't use " << itemName << " on " << goName << endl; return;
	}

	use(*item, *go);

}

void Character::use(Item& item, GameObject& go){ item.use(go); }
void Character::use(Item& item){ item.use(*this); }
void Character::use(Door& door){ door.enter(*this); }

void Character::attackWith(const Weapon& w){
	if (health() > 0){
		cout << name() << " is attacked with: " << w.name() << "! ";
		_health -= w.damagePotl();
	}

	if (health() > 0){ cout << name() <<"'s health is now: " << health() << endl; }
	else{ _health = 0; cout << name() << " is dead" << endl; }

}

void Character::eat(Food const& food){
	cout << name() << " eats: " << food.name() << endl;
}

bool Character::go(Room::DIRECTION direction){
	Door* door = currentRoom()->door(direction);
	if (door == nullptr){
		cout << "No door in direction: " << direction << endl; return false;
	}
	return door->enter(*this);
}

void Character::take(string const& name){
	Room* current = currentRoom();
	Item* item = current->findItem(name);
	if (item != nullptr){
		current->removeItem(name);
		addItem(item);
		cout << "character now has: " << items() << endl;
	}
}

ostream& operator<<(ostream& os, Character const& ch){
	return os << "Chr[" << dynamic_cast<GameObject const&>(ch)
		<< ch._items << ", health =" << ch._health
		<< ",str=" << ch._strength << "]";
}


