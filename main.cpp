/****************************************************************************************
 * Program: main.cpp
 * Name: Wesley Jinks
 * Purpose: Implements the game for the player to navigate through rooms
 * Input: Directions to go, and actions to perform, menu
 * Output: menu, options, prompts
 *
 * *************************************************************************************/

#include<iostream>
#include<cstddef>
#include<string>
#include "room.hpp"
#include "playersShip.hpp"
#include "hanger.hpp"
#include "bridge.hpp"
#include "combatRoom.hpp"
#include "crewQuarters.hpp"
#include "engineR.hpp"
#include "hallway.hpp"
#include "holoRoom.hpp"
#include "medbay.hpp"
#include "messHall.hpp"
#include "weaponRoom.hpp"
#include "player.hpp"

using std::cin;
using std::cout;
using std::string;

Room* enterDoor( Room *door );

int main()
{
	//Create SpaceShip Rooms
	PShip *pShip = new PShip;
	Hanger *hanger = new Hanger;	
	Hallway *hallway1 = new Hallway;
	Hallway *hallway2 = new Hallway;
	CrewQ *crewQ = new CrewQ;
	Mess *mess = new Mess;
	HoloR *holo = new HoloR;
	Medbay *medbay = new Medbay;
	CombatR *combatR = new CombatR;
	EngineR *engineR = new EngineR;
	WeaponR *weaponR = new WeaponR;
	Bridge *bridge = new Bridge;

	//Commands
	char dir;
	//Link SpaceShip Rooms
	hanger->south = hallway1;
	hallway1->west = crewQ;
	hallway1->south = hallway2;
	hallway1->north = hanger;
	combatR->east = weaponR;
	combatR->south = medbay;
	combatR->west = hallway1;
	weaponR->west = combatR;
	crewQ->west = mess;
	crewQ->east = hallway1;
	mess->east = crewQ;
	hallway2->north = hallway1;
	hallway2->east = medbay;
	holo->north = crewQ;
	holo->east = hallway2;
	medbay->west = hallway2;
	engineR->north = hallway2;
	engineR->south = bridge;
	bridge->west = hanger;
	bridge->east = engineR;
	bridge->south = combatR;
	bridge->north = holo;

	cout << "Welcome to the Game. Here are the commands: \n"
		 << "  M: Move\n" <<  "  V: View Room\n  I: Interact with Items\n";

	//Create Player and set initial Room( Player's Ship )
	Player p1;
	p1.setRoom( pShip );
	
	while( bridge->itemFlag != 1 )
	{
		cout << "\nWhat would you like to do?\n M: Move\n V: View Room\n I: View Room Items\n"
			 << " B: View Bag Items\n U: Use Item\n T: Take Item\n L: Drop and Leave Item\n";
		cin >> dir;
		dir = toupper( dir );
		switch( dir )
		{
			case 'M':
				p1.move();
				break;
			case 'V':
				p1.viewRoom();
				break;
			case 'I':
				p1.viewRItems();
				break;
			case 'B':
				p1.viewItems();
				break;
			case 'U':
				p1.useItem();
				break;
			case 'T':
				p1.takeItem();
				break;
			case 'L':
				p1.dropItem();
				break;
			default:
				cout << "\nYou didn't enter a valid command\n";
				break;
		}

		if( pShip->itemFlag == 1 )
			pShip->south = hanger;
		if( hallway1->itemFlag == 1 )
		{
			hallway1->east = combatR;
			medbay->north = combatR;
		}
		if( combatR->itemFlag == 1 )
		{
			crewQ->south = holo;
			hallway2->west = holo;
		}
		if( holo->itemFlag == 1 && engineR->itemFlag == 1 )
		{
			holo->south = bridge;
			combatR->north = bridge;
			engineR->south = bridge;
			hanger->east = bridge;	
		}
		if( combatR->itemFlag == 1 && medbay->itemFlag == 1 )
		{
			hallway2->south = engineR;
		}
	}

	cout << "\nYou escaped the black hole!\n";
		
	return 0;
}

