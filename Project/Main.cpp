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

		Game* game = Game::getInstance();
		game->play();
}