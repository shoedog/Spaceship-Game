/****************************************************************************************
 *	Program Name: messHall.cpp
 *	Author: Wesley Jinks
 *	Description: the implementation file for the mothership mess hall
 *	Input: None
 *	Output: a room description, and a list of items in the room.
 *	************************************************************************************/

#include "messHall.hpp"

/****************************************************************************************
 *	Function: Mess()
 *	Description: constructor
 *	Parameters: name, vector of items
 *	PreConditions: None
 *	PostConditions: the ship room is created
 ***************************************************************************************/
Mess::Mess()
	: Room( "Mess Hall and Kitchen" )
{
	fillRoom( items );
	this->itemFlag = 0;
	this->actionItem = "Plasma Gun";
}

void Mess::itemAction()
{
	if( this->itemFlag == 1 )
	{
		cout << "You blasted the food and turned it into energy goo.\n"
			 << "This might help power things up.";
	}
}

void Mess::viewItems()
{
	if( this->itemFlag == 1 )
		items.push_back( "energy block" );

	cout << "\nHere are some things you see in the room: \n";
	for( unsigned i = 0; i< this->items.size(); i++ )
		cout << "   " << this->items[i] << "\n";
}

void Mess::fillRoom( vector<string> &items )
{
	items.push_back( "food" );
}

void Mess::viewRoom()
{
	cout << "\nThis is the mess hall and kitchen. Pretty typical setup for a space cruiser.";
}

Room* Mess::chooseDoor( Room *door, char dir )
{
	Room* newRoom;
	
	if( dir == 's' )
	{
		if( door->south == NULL )
		{
			cout << "\nThis is the kitchen, but it is burnt and destroyed.";
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
			cout << "\nThere are rows of tables, some with food left on them.";
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
			cout << "\nThis garbage disposal shoots trash into space. Interstellar Littering!";
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
			cout << "\nBack to the crew quarters.";
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
