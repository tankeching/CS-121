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
	Room *crashsite, *generalstore, *school, *northstreet, *schoolHallway;


	crashsite = new Room("Helicopter crash site", "at the crash site in the middle of a city square");
	generalstore = new Room("Abandoned general store", "inside an abandoned general store. Looks like it has been scavenged already");
	school = new Room("Barricaded school", "at the school. It is barricaded enough to look like a fortress");
	northstreet = new Room("Deserted street", "on a deserted street. Looks like the place went to hell");
	schoolHallway = new Room("School hallway", "in the hallway. Everything is on the floor, including trails of blood.");




	_rooms.push_back(crashsite);
	_rooms.push_back(generalstore);
	_rooms.push_back(school);
	_rooms.push_back(northstreet);
	_rooms.push_back(schoolHallway);


	crashsite->setExits(northstreet, school, generalstore, NULL);
	generalstore->setExits(NULL,NULL,NULL,NULL);
	school->setExits(NULL, crashsite, NULL, schoolHallway);
	northstreet->setExits(NULL, NULL, crashsite, NULL);



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
	Weapon sword("sword", "a long elven sword from the Goblin wars");
	Character monster("Grue", "a monster that looks like Azog");
	Character hero("Thor", "legendary lightning hero from Asgard");

	Cinventory cinv;

	cout << sword << endl;
	cout << monster << endl;
	cout << hero << endl;

	hero.use(sword, monster);
	hero.use(sword, monster);
	hero.use(sword, monster);

	cout << monster << endl;

	Game* game = Game::getInstance();
	game->play();
}