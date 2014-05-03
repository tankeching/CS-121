#include "Game.h"
#include "Item.h"
#include "Character.h"
#include "Weapon.h"
#include "Inventory.h"
#include "Door.h"
#include "Room.h"

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
	Room *crashsite, *generalstore, *school, *northstreet, *northneighbor, *policeCar, *openHouse, *garage, *bedroom, *bathroom, *kitchen, *bedcloset,
		*schoolmainHallway, *schoolnorthHall, 
		*schoolsouthHall, *cafeteria, *cafeStorage, *alley,
		*class5, *class8, *principal, *janitorCloset, *playground, *library;


	crashsite = new Room("Helicopter crash site", "at the crash site in the middle of a city square");
	generalstore = new Room("Abandoned general store", "inside an abandoned general store. It has been scavenged already");
	school = new Room("Barricaded school", "at the school. It is barricaded enough to look like a fortress");
	northstreet = new Room("Deserted street", "on North St. It is a deserted street. Looks like the place went to hell");
	northneighbor = new Room("North St Neighborhood", "in the North St. neighborhood. The houses are dark");
	policeCar = new Room("Abandoned police car", "The radio is silent. The car radio is non-responsive");
	openHouse = new Room("Open house", "The  front door is broken down and the power is out");
	garage = new Room("House garage", "There is no car. Anything work taking is gone");
	bedroom = new Room("House bedroom", "Picture frames are broken on the ground. Clothing drawers are hanging out.");
	bathroom = new Room("House bathroom", "The shower was left running");
	bedcloset = new Room("Bedroom closet", "There is just clothes and shoes");
	kitchen = new Room("House kitchen", "The fridge is open. Pans and pots are all over the room");
	schoolmainHallway = new Room("School hallway", "in the hallway. Everything is furniture on the floor");
	schoolnorthHall = new Room("North school hallway", "in the northern hallway. The lights are flickering");
	schoolsouthHall = new Room("South school hallway", "in the southern hallway. There are signs of combat");
	cafeteria = new Room("School cafeteria", "in the school cafeteria");
	cafeStorage = new Room("Cafeteria storage", "in the storage room. There is are food boxes");
	class5 = new Room("Classroom 5", "in classroom 5. The desks are out of line. Backpacks are all over the room");
	class8 = new Room("Classroom 8", "in classroom 6. The lights are on. There are food wrappers on the floor");
	principal = new Room("Principal's office", "in the Principal's office. There is a keyrack on the wall");
	janitorCloset = new Room("Janitor's closet", "there is custodial equipment around. There is a toolbox as well");
	playground = new Room("School playground", "at the school playground. Someone hung themselves on the basketball court");
	library = new Room("School library", "in the library. Shelves and books are scattered on the floor");
	alley = new Room("Rundown alleyway", "in the alley way, there is nothing here but trash");
	
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
	



	crashsite->setExits(northstreet, school, generalstore, NULL);
	generalstore->setExits(NULL,alley,NULL,NULL);
	alley->setExits(school, NULL, NULL, generalstore);
	school->setExits(NULL, schoolmainHallway, alley, crashsite);
	schoolmainHallway->setExits(schoolnorthHall, cafeteria, schoolsouthHall, school);
	schoolnorthHall->setExits(principal, class5, schoolmainHallway, class8);
	schoolsouthHall->setExits(schoolmainHallway, playground, library, janitorCloset);
	class5->setExits(NULL, NULL, NULL, schoolnorthHall);
	class8->setExits(NULL, schoolnorthHall, NULL, NULL);
	principal->setExits(NULL, NULL, schoolnorthHall, NULL);
	library->setExits(schoolsouthHall, NULL, NULL, NULL);
	playground->setExits(NULL, NULL, NULL, schoolsouthHall);
	janitorCloset->setExits(NULL, schoolsouthHall, NULL, NULL);
	cafeteria->setExits(cafeStorage, NULL, NULL, schoolmainHallway);
	cafeStorage->setExits(NULL, NULL, cafeteria, NULL);
	northstreet->setExits(northneighbor, NULL, crashsite, NULL);
	northneighbor->setExits(NULL, policeCar, northstreet, openHouse);
	policeCar->setExits(NULL, northneighbor, NULL, northneighbor);
	openHouse->setExits(bedroom, kitchen, garage, northneighbor);
	bedroom->setExits(NULL, bathroom, openHouse, bedcloset);
	bathroom->setExits(NULL, NULL, NULL, bedroom);
	bedcloset->setExits(NULL, bedroom, NULL, NULL);
	garage->setExits(openHouse, NULL, NULL, NULL);
	kitchen->setExits(NULL, NULL, NULL, openHouse);



	_currentRoom = crashsite;
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
	string direction = command.getSecondWord();
	Room* nextRoom = _currentRoom->nextRoom(direction);

		if (nextRoom == NULL){
			cout << "There is no door!" << endl;
		}
		else{
			_currentRoom = nextRoom;
			cout << _currentRoom->longDescription();
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
	cout << _currentRoom->longDescription() << endl;
}

ostream& operator<<(ostream& os, const Game& game);

int main(){
	typedef Inventory<Character*> Cinventory;
	Weapon M4("M4 Carbine", "Standard issue assault rifle");
	Character Zombie("Zombie", "a flesh-eating monster");
	Character hero("Thor", "legendary lightning hero from Asgard");

	Cinventory cinv;

	cout << M4 << endl;
	cout << Zombie << endl;
	cout << hero << endl;

	hero.use(M4, Zombie);
	hero.use(M4, Zombie);
	hero.use(M4, Zombie);

	cout << Zombie << endl;

	Game* game = Game::getInstance();
	game->play();
}