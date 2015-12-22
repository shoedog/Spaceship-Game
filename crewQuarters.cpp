/****************************************************************************************
 *	Program Name: crewQuarters.cpp
 *	Author: Wesley Jinks
 *	Description: the implementation file for the mothership crew quarters
 *	Input: None
 *	Output: a room description, and a list of items in the room.
 *	************************************************************************************/

#include "crewQuarters.hpp"

/****************************************************************************************
 *	Function: CrewQ()
 *	Description: constructor
 *	Parameters: name, vector of items
 *	PreConditions: None
 *	PostConditions: the ship room is created
 ***************************************************************************************/
CrewQ::CrewQ()
	: Room( "Crew Quarters" )
{
	fillRoom( items );
}

void CrewQ::viewItems()
{
	cout << "\nHere are some things you see in the room: \n";
	for( unsigned i = 0; i< this->items.size(); i++ )
		cout << "   " << this->items[i] << "\n";
}

void CrewQ::itemAction()
{}

void CrewQ::fillRoom( vector<string> &items )
{
	items.push_back( "key card" );
	items.push_back( "family picture" );
	items.push_back( "note" );
}

void CrewQ::viewRoom()
{
	cout << "\nIt looks like the crew bunked here. There are beds, games, and pictures.\n"
		 << "I wonder where everyone is.";
}

Room* CrewQ::chooseDoor( Room *door, char dir )
{
	Room* newRoom;

	if( dir == 's' )
	{
		if( door->south == NULL )
		{
			cout << "\nThis is a Hologram Room. There would be games to play in here.";
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
			cout << "\nThere are a bunch of beds stacked against the wall.";
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
			cout << "\nYou must be hungry if you want to get into the kitchen.";
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
			cout << "\nBack to the hallway.";
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
