/****************************************************************************************
 *	Program Name: hallway.cpp
 *	Author: Wesley Jinks
 *	Description: the implementation file for the mothership hallway
 *	Input: None
 *	Output: a room description, and a list of items in the room.
 *	************************************************************************************/

#include "hallway.hpp"

/****************************************************************************************
 *	Function: Hanger()
 *	Description: constructor
 *	Parameters: name, vector of items
 *	PreConditions: None
 *	PostConditions: the ship room is created
 ***************************************************************************************/
Hallway::Hallway()
	: Room( "Hallway" )
{
	fillRoom( items );
	this->itemFlag = 0;
	this->actionItem = "key card";
}

void Hallway::itemAction()
{
	if( this->itemFlag == 1 )
	{
		cout << "You unlocked the Combat HQ.\n"
			 << "You should have a look around.";
	}
}

void Hallway::viewItems()
{
	cout << "\nHere are some things you see in the room: \n";
	for( unsigned i = 0; i< this->items.size(); i++ )
		cout << "   " << this->items[i] << "\n";
}

void Hallway::fillRoom( vector<string> &items )
{
	items.push_back( "There is nothing here, it is pretty clean. " );
}

void Hallway::viewRoom()
{
	cout << "\nThis is a space age hallway with white metallic walls and four doors.";
}

Room* Hallway::chooseDoor( Room *door, char dir )
{
	Room* newRoom;

	if( dir == 's' )
	{
		if( door->south == NULL )
		{
			cout << "\nThis appears to be the engine room door.";
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
			cout << "\nThere aren't any ships you can fly in the hanger.";
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
			cout << "\nThe hologram room looks fun, but it is locked.";
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
			cout << "\nThis door is locked, but has a key slot. This room looks important.";
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
