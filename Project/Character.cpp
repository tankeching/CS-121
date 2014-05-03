#include "Character.h"

Character::Character(string name, string description, int health, int strength)
: GameObject(name, description), _health(health), _strength(strength){}

int Character::health() const { return _health; }
void Character::health(int val) { _health = val; }

int Character::strength() const { return _strength; }
void Character::strength(int val) { _strength = val; }

void Character::use(Item& item, GameObject& go) { item.use(go); }

void Character::attackWith(const Weapon& w){
	cout << name() << " was attacked! " << endl;
	_health -= w.damagePotl();
}

ostream& operator<<(ostream& os, const Character& c){
	return os << "Character[" << dynamic_cast<const GameObject&>(c) << ",health=" << c._health
		<< ",strength=" << c._strength << "]";
}