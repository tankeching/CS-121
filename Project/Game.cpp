#include "Game.h"
#include "Item.h"
#include "Character.h"
#include "Weapon.h"
#include "Inventory.h"
#include "Door.h"
#include "Room.h"
#include "NoCloseDoor.h"
#include "NoLockDoor.h"
#include "Key.h"
#include "Location.h"
#include "Food.h"


Game* Game::__instance = NULL;

Game::Game() : _parser(Parser()) { createRooms(); }

Game::~Game() { deleteRooms(); }

Game* Game::getInstance() {
	if (__instance == NULL){
		__instance = new Game();
	}

	return __instance;
}

void Game::play() {
	printWelcome();

	bool finished = false;
	while (!finished) {
		Command cmd = _parser.getCommand();
		finished = processCommand(cmd);
	}

	cout << "Thank you for playing. Goodbye." << endl;
	cout << "...done." << endl;
}

void Game::createRooms(){

	Weapon* M4 = new Weapon("M4", "standard issue assault rifle");
	Character* Zombie = new Character("Zombie", "a flesh-eating monster");
	Key* schoolkey = new Key("schoolkey", "school master key", 2);
	Key* gatekey = new Key("gatekey", "school gate key", 1);
	Key* garagekey = new Key("garagekey", "garage key", 3);
	Key* bathroomkey = new Key("bathroomkey", "bathroom key", 4);

	Room* crashsite = new Room("Helicopter crash site", "at the crash site in the middle of a city square");
	Room* generalstore = new Room("Abandoned general store", "inside an abandoned general store. It has been scavenged already");
	Room* school = new Room("Barricaded school", "at the school. It is barricaded enough to look like a fortress");
	Room* northstreet = new Room("Deserted street", "on North St. It is a deserted street. Looks like the place went to hell");
	Room* northneighbor = new Room("North St Neighborhood", "in the North St. neighborhood. The houses are dark");
	Room* policeCar = new Room("Abandoned police car", "The radio is silent. The car radio is non-responsive");
	Room* openHouse = new Room("Open house", "The  front door is broken down and the power is out");
	Room* garage = new Room("House garage", "There is no car. Anything work taking is gone");
	Room* bedroom = new Room("House bedroom", "Picture frames are broken on the ground. Clothing drawers are hanging out.");
	Room* bathroom = new Room("House bathroom", "The shower was left running");
	Room* bedcloset = new Room("Bedroom closet", "There is just clothes and shoes");
	Room* kitchen = new Room("House kitchen", "The fridge is open. Pans and pots are all over the room");
	Room* schoolmainHallway = new Room("School hallway", "in the hallway. All the furniture is on the floor");
	Room* schoolnorthHall = new Room("North school hallway", "in the northern hallway. The lights are flickering");
	Room* schoolsouthHall = new Room("South school hallway", "in the southern hallway. There are signs of combat");
	Room* cafeteria = new Room("School cafeteria", "in the school cafeteria");
	Room* cafeStorage = new Room("Cafeteria storage", "in the storage room. There is are food boxes");
	Room* class5 = new Room("Classroom 5", "in classroom 5. The desks are out of line. Backpacks are all over the room");
	Room* class8 = new Room("Classroom 8", "in classroom 6. The lights are on. There are food wrappers on the floor");
	Room* principal = new Room("Principal's office", "in the Principal's office. There is a ey on the rack on the wall");
	Room* janitorCloset = new Room("Janitor's closet", "there is custodial equipment around. There is a toolbox as well");
	Room* playground = new Room("School playground", "at the school playground. Someone hung themselves on the basketball court");
	Room* library = new Room("School library", "in the library. Shelves and books are scattered on the floor");
	Room* alley = new Room("Rundown alleyway", "in the alley way, there is nothing here but trash");
	
	_rooms.push_back(crashsite);
	_rooms.push_back(generalstore);
	_rooms.push_back(school);
	_rooms.push_back(northstreet);
	_rooms.push_back(northneighbor);
	_rooms.push_back(policeCar);
	_rooms.push_back(openHouse); _rooms.push_back(bedroom); _rooms.push_back(garage); _rooms.push_back(kitchen); _rooms.push_back(bathroom); _rooms.push_back(bedcloset);
	_rooms.push_back(schoolmainHallway);
	_rooms.push_back(schoolnorthHall); _rooms.push_back(class5); _rooms.push_back(class8); _rooms.push_back(principal);
	_rooms.push_back(schoolsouthHall); _rooms.push_back(janitorCloset); _rooms.push_back(playground); _rooms.push_back(library);
	_rooms.push_back(cafeteria); _rooms.push_back(cafeStorage);
	
	Door* CStoNS = new NoCloseDoor("CStoNS", "door between northstreet and crashsite", crashsite, northstreet);
	Door* CStoS = new Door("CStoS", "door between crashsite and school", crashsite, school, 1);
	Door* CStoGS = new NoLockDoor("CstoGS", "door between crashsite and general store", crashsite, generalstore);
	Door* GStoA = new NoLockDoor("GStoA", "door between generalstore and alley", generalstore, alley);
	Door* AtoS = new NoCloseDoor("AtoS", "door between alley and school", alley, school);
	Door* StoMHW = new NoCloseDoor("StoMHW", "door between front of school and main hallway", school, schoolmainHallway);
	Door* MHWtoC = new NoLockDoor("MHWtoC", "door between main hallway and cafeteria", schoolmainHallway, cafeteria);
	Door* MHWtoSH = new NoCloseDoor("MHWtoSH", "door between main hallway and south hallway", schoolmainHallway, schoolsouthHall);
	Door* MHWtoNH = new NoCloseDoor("MHWtoNH", "door between main hallway and north hallway", schoolmainHallway, schoolnorthHall);
	Door* NHtoPO = new NoLockDoor("NHtoPO", "door between north hallway and principal's office", schoolnorthHall, principal);
	Door* NHtoC5 = new Door("NHtoC5", "door between north hallway and Room 5", schoolnorthHall, class5, 2);
	Door* NHtoC8 = new Door("NHtoC8", "door between north hallway and Room 8", schoolnorthHall, class8, 2);
	Door* SHtoPG = new NoLockDoor("SHtoPG", "door between south hallway and playground", schoolsouthHall, playground);
	Door* SHtoL = new NoCloseDoor("SHtoL", "door between south hallway and library", schoolsouthHall, library);
	Door* SHtoJC = new Door("SHtoJC", "door between south hallway and janitor's closet", schoolsouthHall, janitorCloset, 2);
	Door* CtoSR = new Door("CtoSR", "door between cafeteria and cafeteria storge room", cafeteria, cafeStorage, 2);
	Door* NStoNN = new NoCloseDoor("NStoNN", "door between north street and north neightborhood", northstreet, northneighbor);
	Door* NNtoPC1 = new NoLockDoor("NNtoPC", "door between north neighborhood and police car", northneighbor, policeCar);
	Door* NNtoPC2 = new NoLockDoor("NNtoPC", "door between north neighborhood and police car", northneighbor, policeCar);
	Door* NNtoOH = new NoCloseDoor("NNtoOH", "door between north neighborhood and open house", northneighbor, openHouse);
	Door* OHtoBR = new NoLockDoor("OHtoBR", "door between open house and bedroom", openHouse, bedroom);
	Door* OHtoK = new NoCloseDoor("OHtoK", "door between open house and kitchen", openHouse, kitchen);
	Door* OHtoG = new Door("OHtoG", "door between open house and garage", openHouse, garage, 3);
	Door* BRtoB = new Door("BRtoB", "door between bedroom and bathroom", bedroom, bathroom, 4);
	Door* BRtoBC = new NoLockDoor("BRtoBC", "door between bedroom and bedroom closet", bedroom, bedcloset);

	crashsite->setExits(CStoNS, CStoS, CStoGS, nullptr);	
	generalstore->setExits(nullptr, GStoA, nullptr, nullptr);
	alley->setExits(AtoS, nullptr, nullptr, GStoA);
	school->setExits(nullptr, StoMHW, AtoS, CStoS);
	schoolmainHallway->setExits(MHWtoNH, MHWtoC, MHWtoSH, StoMHW);
	schoolnorthHall->setExits(NHtoPO, NHtoC5, MHWtoNH, NHtoC8);
	schoolsouthHall->setExits(MHWtoSH, SHtoPG, SHtoL, SHtoJC);
	schoolsouthHall->setExits(MHWtoSH, SHtoPG, SHtoL, SHtoJC);
	class5->setExits(nullptr, nullptr, nullptr, NHtoC5);
	class8->setExits(nullptr, NHtoC8, nullptr, nullptr);
	principal->setExits(nullptr, nullptr, NHtoPO, nullptr);
	library->setExits(SHtoL, nullptr, nullptr, nullptr);
	playground->setExits(nullptr, nullptr, nullptr, SHtoPG);
	janitorCloset->setExits(nullptr, SHtoJC, nullptr, nullptr);
	cafeteria->setExits(CtoSR, nullptr, nullptr, MHWtoC);
	cafeStorage->setExits(nullptr, nullptr, CtoSR, nullptr);
	northstreet->setExits(NStoNN, nullptr, CStoNS, nullptr);
	northneighbor->setExits(nullptr, NNtoPC1, NStoNN, NNtoOH);
	policeCar->setExits(nullptr, NNtoPC1, nullptr, NNtoPC2);
	openHouse->setExits(OHtoBR, OHtoK, OHtoG, NNtoOH);
	bedroom->setExits(nullptr, BRtoB, OHtoBR, BRtoBC);
	bathroom->setExits(nullptr, nullptr, nullptr, BRtoB);
	bedcloset->setExits(nullptr, BRtoBC, nullptr, nullptr);
	garage->setExits(OHtoG, nullptr, nullptr, nullptr);
	kitchen->setExits(nullptr, nullptr, nullptr, OHtoK);

	_Player->currentRoom(crashsite);
	_Player->addItem(M4);
	crashsite->setCharacters({ _Player, Zombie });
	crashsite->setItems({ gatekey });
	bedroom->setItems({ bathroomkey });
	kitchen->setItems({ garagekey });
	principal->setItems({ schoolkey });
	bathroom->setCharacters({ Zombie });
	northneighbor->setCharacters({ Zombie });
	library->setCharacters({ Zombie });
	class8->setCharacters({ Zombie });
	

}

void Game::deleteRooms() {
		for (vector<Room*>::iterator iter = _rooms.begin(); iter != _rooms.end(); iter++){
			delete *iter;
		}
}

void Game::goRoom(Command command){
	
	if (!command.hasSecondWord()){
		cout << "Go where? " << endl;
		return;
	}
	string dir = command.getSecondWord();
	Door* door = _Player->currentRoom()->door(_Player->currentRoom()->direction( dir ));

		if (door == NULL){
			cout << "There is no door!" << endl;
		}
		else{
//			Door* thisDoor = _currentRoom->door(_currentRoom->direction( dir ));
			door->enter(*_Player);
			cout << _Player->currentRoom()->longDescription() << endl;
			//cout << _Player->currentRoom()->longDescription();
			//cout << _Player->currentRoom()->exits();
		}
}

void Game::takeItem(Command command){
	if (!command.hasSecondWord()){
		cout << "Take what? " << endl;
		return;
	}

	string item = command.getSecondWord();
	_Player->take(item);

}

void Game::openDoor(Command command){
	if (!command.hasSecondWord()){
		cout << "Open what? " << endl;
		return;
	}


	else if (command.hasSecondWord()){
		string dir = command.getSecondWord();
		 _Player->currentRoom()->door(_Player->currentRoom()->direction(dir))->open();
	}
}

void Game::closeDoor(Command command){
	if (!command.hasSecondWord()){
		cout << "Close what? " << endl;
		return;
	}


	else if (command.hasSecondWord()){
		string dir = command.getSecondWord();
		_Player->currentRoom()->door(_Player->currentRoom()->direction(dir))->close();
	}
}

void Game::attackMonster(Command command){
	if (!command.hasSecondWord()){
		cout << "Attack what? " << endl;
		return;
	}

	string monster = command.getSecondWord();

	_Player->use("M4", monster);
}

void Game::searchRoom(Command command){
	if (!command.hasSecondWord()){
		cout << "search what? " << endl;
		return;
	}


	else if (command.getSecondWord() == "room"){
		string dir = command.getSecondWord();
		cout << _Player->currentRoom()->items() << endl;
		cout << _Player->currentRoom()->characters() << endl;
	}

	else{
		cout << "I don't know what you mean." << endl;
	}
}

void Game::lockDoor(Command command){
	if (!command.hasSecondWord()){
		cout << "Lock what? " << endl;
		return;
	}
	else{
		string dir = command.getSecondWord();
		if (_Player->findItem("schoolkey") != NULL){
			Key* schoolkey = new Key("schoolkey", "school master key", 2);
			_Player->currentRoom()->door(_Player->currentRoom()->direction(dir))->lockWith(*schoolkey);
		}
		if (_Player->findItem("gatekey") != NULL){
			Key* gatekey = new Key("gatekey", "school gate key", 1);
			_Player->currentRoom()->door(_Player->currentRoom()->direction(dir))->lockWith(*gatekey);
		}

		if (_Player->findItem("garagekey") != NULL){
			Key* garagekey = new Key("garagekey", "garage key", 3);
			_Player->currentRoom()->door(_Player->currentRoom()->direction(dir))->lockWith(*garagekey);
		}
		if (_Player->findItem("bathroomkey") != NULL){
			Key* bathroomkey = new Key("bathroomkey", "bathroom key", 4);
			_Player->currentRoom()->door(_Player->currentRoom()->direction(dir))->lockWith(*bathroomkey);
		}
		else{
			cout << "You do not have the right key." << endl;
		}
	}
}

void Game::unlockDoor(Command command){
	if (!command.hasSecondWord()){
		cout << "Unlock what? " << endl;
		return;
	}


	else{
		string dir = command.getSecondWord();
		if (_Player->findItem("schoolkey") != NULL){ 
			Key* schoolkey = new Key("schoolkey", "school master key", 2);
			_Player->currentRoom()->door(_Player->currentRoom()->direction(dir))->unlockWith(*schoolkey);
		}
		else if (_Player->findItem("gatekey") != NULL){ 
			Key* gatekey = new Key("gatekey", "school gate key", 1);
			_Player->currentRoom()->door(_Player->currentRoom()->direction(dir))->unlockWith(*gatekey);
		}
		
		else if (_Player->findItem("garagekey") != NULL){ 
			Key* garagekey = new Key("garagekey", "garage key", 3);
			_Player->currentRoom()->door(_Player->currentRoom()->direction(dir))->unlockWith(*garagekey);
		}
		else if (_Player->findItem("bathroomkey") != NULL){ 
			Key* bathroomkey = new Key("bathroomkey", "bathroom key", 4);
			_Player->currentRoom()->door(_Player->currentRoom()->direction(dir))->unlockWith(*bathroomkey);
		}
		else{
			cout << "You do not have the right key." << endl;
		}
	}
}



bool Game::processCommand(Command command){
	if (command.isUnknown()){
		cout << "I don't know what you mean..." << endl;
		return false;
	}

	string commandWord = command.getCommandWord();
	if (commandWord == "help"){ printHelp(); }
	else if (commandWord == "go"){ goRoom(command); }
	else if (commandWord == "quit"){
		if (command.hasSecondWord()){ cout << "Quit what?" << endl; }
		else { return true; }
	}
	else if (commandWord == "take"){ takeItem(command); }
	else if (commandWord == "open"){ openDoor(command); }
	else if (commandWord == "close"){ closeDoor(command); }
	else if (commandWord == "lock"){ lockDoor(command); }
	else if (commandWord == "unlock"){ unlockDoor(command); }
	else if (commandWord == "attack"){ attackMonster(command); }
	else if (commandWord == "search"){ searchRoom(command); }

	return false;
}

void Game::printHelp(){
	cout << "You are a lost U.S Special Forces operative." << endl;
	cout << "Your helicopter malfunctioned and crashed in the middle of a city." << endl;
	cout << "Find your way to safety." << endl;
	cout << "Your command words are: " << endl;
	_parser.showCommands();
}

void Game::printWelcome() {
	cout << endl << "Welcome to Zork!" << endl;
	cout << "Zork is a new, incredible exciting advernture game" << endl;
	cout << "Type 'help' if you need help." << endl << endl;
	cout << _Player->currentRoom()->longDescription() << endl;
	cout << "You are already equipped with an M4 rifle." << endl;
}

ostream& operator<<(ostream& os, const Game& game);

