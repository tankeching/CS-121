#include "Food.h"

#include "Item.h"
#include "GameObject.h"
#include "Character.h"

Food::Food(string const& name, string const& desc, int heal) : Item(name, desc), _heal(heal){}

void Food::use(GameObject& go){
	Character* pc;
	if ((pc = dynamic_cast<Character*>(&go)) != NULL){
		pc->use(*this);
		pc->health(100);
	}
}
