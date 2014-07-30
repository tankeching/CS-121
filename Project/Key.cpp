#include "Key.h"
#include "Item.h"
#include "GameObject.h"
#include "Character.h"


Key::Key(string const& name, string const& desc, int keycode) : Item(name, desc), _keycode(keycode){}

void Key::use(GameObject& go){
	Character* pc;
	if ((pc = dynamic_cast<Character*>(&go)) != NULL){
		pc->use(*this);
	}
}

int Key::keycode() const{
	return _keycode;
}