#include "Weapon.h"
#include "Character.h"

Weapon::Weapon(string name, string desc, int damagePotl, int defensePotl) :
Item(name, desc), _damagePotl(damagePotl), _defensePotl(defensePotl) {}

int Weapon::damagePotl() const { return _damagePotl; }
int Weapon::defensePotl() const { return _defensePotl; }

void Weapon::use(GameObject& go){
	Character* pc;
	if ((pc = dynamic_cast<Character*>(&go)) != NULL){
		pc->attackWith(*this);
	}
}

ostream& operator<<(ostream& os, const Weapon& w){
	return os << "Weapon[" << dynamic_cast<const Item&>(w)
		<< "," << w._damagePotl << "," << w._defensePotl << "]";
}
