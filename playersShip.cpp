/****************************************************************************************
 *	Program Name: playersShip.cpp
 *	Author: Wesley Jinks
 *	Description: the implementation file for the player's ship
 *	Input: None
 *	Output: a room description, and a list of items in the room.
 *	************************************************************************************/

#include "playersShip.hpp"

/****************************************************************************************
 *	Function: PShip()
 *	Description: constructor
 *	Parameters: name, vector of items
 *	PreConditions: None
 *	PostConditions: the ship room is created
 ***************************************************************************************/
PShip::PShip()
	: Room( "Your Ship" )
{
	fillRoom( items );
	this->itemFlag = 0;
	this->actionItem = "wrist AI";
}

void PShip::itemAction()
{
	if( this->itemFlag == 1 )
	{
		cout << "Your wrist AI opened the hatch. You can get out.\n"
			 << "You should have a look around.";
	}
}

void PShip::viewItems()
{
	cout << "\nHere are some things you see in the room: \n";
	for( unsigned i = 0; i< this->items.size(); i++ )
		cout << "   " << this->items[i] << "\n";
}

void PShip::fillRoom( vector<string> &items )
{
	items.push_back( "wrist AI" );
}

void PShip::viewRoom()
{
	cout << "\nYou are in your space-ship. It is small and fast, but only capable of \n" 
		 << "short intersteller jumps. Your warp drive and engines are too damaged \n"
		 << "to use. You are lucky you even made it here. There would probably be some\n"
		 << "useful parts to scavenge if you were an engineer, but you aren't. In fact\n"
		 << "the ship pretty much pilots itself. You better find help because you can\n"
		 << "really only follow directions, press buttons, turn knobs, and pick up\n"
		 << "things. You leave the thinking to AI.\n";
}

Room* PShip::chooseDoor( Room *door, char dir )
{
	Room* newRoom;

	if( dir == 's' )
	{
		if( door->south == NULL )
		{
			cout << "\nThe hatch cannot be opened by a human.";
			return door;
		}
		else
		{
			newRoom = door->south;
			return newRoom;
		}
	}
	if( dir == 'w' )
	{
		if( door->south == NULL )
		{
			cout << "\nThe window is cracked but you see a landing bay. You should get out\n"
				 << "of your ship and check it out";
			return door;
		}
		else
		{
			newRoom = door->north;
			return newRoom;
		}
	}
	if( dir == 'a' )
	{
		if( door->west == NULL )
		{
			cout << "\nYour engines are destroyed, you can't repair them, or go anywhere.";
			return door;
		}
		else
		{
			newRoom = door->west;
			return newRoom;
		}
	}
	if( dir == 'd' )
	{
		if( door->east == NULL )
		{
			cout << "\nThis is a wall of your junk, you collect a lot of nic-nacs.";
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
