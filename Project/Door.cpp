#include "Door.h"


Door::Door(string const& name, string const& desc) : GameObject(name, desc){

}

void Door::open(){
	if (_isLocked == false && _isClosed == true){
		cout << "This door is now open." << endl;
		_isClosed = false;
	}
	else if (_isLocked == true){
		cout << "This door is locked. You cannot open it." << endl;
	}
}

void Door::close(){
	if (_isClosed == false){
		cout << "This door is closed. You cannot enter." << endl;
		_isClosed = true;
	}
}

void Door::lock(Key const& key){
	if (_isClosed == true){
		cout << "This door is now locked." << endl;
		_isLocked = true;
	}
}

void Door::unlock(Key const& key){
	if (_isClosed == true  /*_password == key.keycode()*/){
		cout << "This door is now unlocked." << endl;
		_isLocked = false;
	}

	else if (_isClosed == false){
		cout << "The door is already open." << endl;
	}
}

void Door::enter() const{
	if (_isClosed == true){
		cout << "You cannot enter the door while it is closed." << endl;
	}

	else if (_isClosed == false){
		 
	}
}


