/****************************************************************************************
 *	Program Name: engineR.cpp
 *	Author: Wesley Jinks
 *	Description: the implementation file for the mothership engine room and engineering
 *	Input: None
 *	Output: a room description, and a list of items in the room.
 *	************************************************************************************/

#include "engineR.hpp"

/****************************************************************************************
 *	Function: Hanger()
 *	Description: constructor
 *	Parameters: name, vector of items
 *	PreConditions: None
 *	PostConditions: the ship room is created
 ***************************************************************************************/
EngineR::EngineR()
	: Room( "Engine Room and Engineering" )
{
	fillRoom( items );
	this->itemFlag = 0;
	this->actionItem = "energy block";
}

void EngineR::itemAction()
{
	if( this->itemFlag == 1 )
	{
		cout << "You boosted the engines power by installing the energy block.\n"
			 << "I bet some other parts of the ship are working now.";
	}
}

void EngineR::viewItems()
{
	cout << "\nHere are some things you see in the room: \n";
	for( unsigned i = 0; i< this->items.size(); i++ )
		cout << "   " << this->items[i] << "\n";
}

void EngineR::fillRoom( vector<string> &items )
{
	items.push_back( " " );
}

void EngineR::viewRoom()
{
	cout << "\nThere is a loud hum and arcs of blue energy flowing between these machines.";
}

Room* EngineR::chooseDoor( Room *door, char dir )
{
	Room* newRoom;

	if( dir == 's' )
	{
		if( door->south == NULL )
		{
			cout << "\nThis appears to be a teleporter, but it doesn't have power.";
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
			cout << "\nWhy can't go exit to the hallway?.";
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
			cout << "\nThere are rows and rows of engines, you should stay back.";
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
			cout << "\nThere are rows and rows of engines, you should stay back.";
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
