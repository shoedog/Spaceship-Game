/****************************************************************************************
 *	Program Name: combatRoom.cpp
 *	Author: Wesley Jinks
 *	Description: the implementation file for the mothership combat Room
 *	Input: None
 *	Output: a room description, and a list of items in the room.
 *	************************************************************************************/

#include "combatRoom.hpp"

/****************************************************************************************
 *	Function: CombatR()
 *	Description: constructor
 *	Parameters: name, vector of items
 *	PreConditions: None
 *	PostConditions: the ship room is created
 ***************************************************************************************/
CombatR::CombatR()
	: Room( "Combat Room" )
{
	fillRoom( items );
	this->itemFlag = 0;
	this->actionItem = "controls";
}

void CombatR::itemAction()
{
	if( this->itemFlag == 1 )
	{
		cout << "That seemed to shift power to other parts of the ship.\n"
			 << "It looks like the weapons are off, but I can hear the engines";
	}
}
void CombatR::viewItems()
{
	cout << "\nHere are some things you see in the room: \n";
	for( unsigned i = 0; i< this->items.size(); i++ )
		cout << "   " << this->items[i] << "\n";
}

void CombatR::fillRoom( vector<string> &items )
{
	items.push_back( "controls" );
}

void CombatR::viewRoom()
{
	cout << "\nThere are a bunch of displays showing space outside. It appears that this\n"
		 << "is where the weapon controls are located. Everything seems to be on, using\n"
		 << "and working normally. It looks like they had routed most of the power to the\n"
		 << "weapon systems.";
}

Room* CombatR::chooseDoor( Room *door, char dir )
{
	Room* newRoom;

	if( dir == 's' )
	{
		if( door->south == NULL )
		{
			cout << "\nWhy can't you get to the medbay?";
			return door;
		}
		else
		{
			newRoom = door->south;
			return newRoom;
		}
	}
	else if( dir == 'w' )
	{
		if( door->north == NULL )
		{
			cout << "\nThere is a teleporter here, but it doesn't have power.";
			return door;
		}
		else
		{
			newRoom = door->north;
			return newRoom;
		}
	}
	else if( dir == 'a' )
	{
		if( door->west == NULL )
		{
			cout << "\nWhy can't you get to the hallway?";
			return door;
		}
		else
		{
			newRoom = door->west;
			return newRoom;
		}
	}
	else if( dir == 'd' )
	{
		if( door->east == NULL )
		{
			cout << "\nWhy can't you get to the weapon room?";
			return door;
		}
		else
		{
			newRoom = door->east;
			return newRoom;
		}
	}
	else
		return door;
}
