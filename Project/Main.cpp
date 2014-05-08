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
#include "Command.h"
#include "CommandWords.h"
#include "Parser.h"

int main(){
		Weapon* M4 = new Weapon("M4 Carbine", "standard issue assault rifle");
		Character* Zombie = new Character("Zombie", "a flesh-eating monster");
		Character* Player = new Character("Hero", "Test Character");

		Room* TEST = new Room("Test room", "Hero kills zombie here");
		Room* TEST2 = new Room("2nd test room", "lets go here");
		Door* openDoor = new NoCloseDoor("open door", "test open door", TEST, TEST2);
		
		cout << M4 << endl;
		TEST->setExits(NULL, NULL, NULL, NULL);
		TEST->setCharacters({ Player, Zombie });
		TEST->setItems({ M4 });

		openDoor->enter(*Player);
		cout << Player->currentRoom() << endl;
		cout << TEST << endl;
		cout << Player << endl;
		cout << Zombie << endl;

		Player->take("M4");
		Player->use("M4", "Zombie");



		Game* game = Game::getInstance();
		game->play();
}