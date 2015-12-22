/****************************************************************************************
 *	Program Name: medbay.cpp
 *	Author: Wesley Jinks
 *	Description: the implementation file for the mothership medbay
 *	Input: None
 *	Output: a room description, and a list of items in the room.
 *	************************************************************************************/

#include "medbay.hpp"

/****************************************************************************************
 *	Function: Medbay()
 *	Description: constructor
 *	Parameters: name, vector of items
 *	PreConditions: None
 *	PostConditions: the ship room is created
 ***************************************************************************************/
Medbay::Medbay()
	: Room( "Medbay" )
{
	fillRoom( items );
	this->actionItem = "space suit";
}

void Medbay::itemAction()
{
	if( this->itemFlag == 1 )
	{
		cout << "You put on the space suit. This should protect you from radiation.\n"
			 << "I bet it is safe to go in the engine room";
	}
}
void Medbay::viewItems()
{
	cout << "\nHere are some things you see in the room: \n";
	for( unsigned i = 0; i< this->items.size(); i++ )
		cout << "   " << this->items[i] << "\n";
}

void Medbay::fillRoom( vector<string> &items )
{
	items.push_back( "space suit" );
	items.push_back( "medicine" );
	items.push_back( "scanner" );
}

void Medbay::viewRoom()
{
	cout << "\nThis is the medical bay. For an abandoned ship there doesn't even appear\n"
		  << "to be any medical emergencies that happened recently here.";
}

Room* Medbay::chooseDoor( Room *door, char dir )
{
	Room* newRoom;

	if( dir == 's' )
	{
		if( door->south == NULL )
		{
			cout << "\nThere s some medicine and healing machines here.";
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
			cout << "\nThis door appears to only open from the inside.";
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
			cout << "\nWhy can't you get to hallway 2?";
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
			cout << "\nThere are a bunch of shiny devices. You don't know what they do.";
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
