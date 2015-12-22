/****************************************************************************************
 *	Program Name: bridge.cpp
 *	Author: Wesley Jinks
 *	Description: the implementation file for the mothership bridge
 *	Input: None
 *	Output: a room description, and a list of items in the room.
 *	************************************************************************************/

#include "bridge.hpp"

/****************************************************************************************
 *	Function: Bridge()
 *	Description: constructor
 *	Parameters: name, vector of items
 *	PreConditions: None
 *	PostConditions: the ship room is created
 ***************************************************************************************/
Bridge::Bridge()
	: Room( "Hallway" )
{
	fillRoom( items );
	this->itemFlag = 0;
	this->actionItem = "warp codes";
}

void Bridge::viewItems()
{
	cout << "\nHere are some things you see in the room: \n";
	for( unsigned i = 0; i< this->items.size(); i++ )
		cout << "   " << this->items[i] << "\n";
}

void Bridge::itemAction()
{
	if( this->itemFlag == 1 )
	{
		cout << "You were able to warp away from the black hole!\n"
			 << "You don't know where you are going, but at least not oblivion";
	}
}

void Bridge::fillRoom( vector<string> &items )
{
	items.push_back( " " );
}

void Bridge::viewRoom()
{
	cout << "\nThis is the ships bridge. You are facing down a black hole. You better\n"
		 << "get the ship into warp drive and out of here fast";
}

Room* Bridge::chooseDoor( Room *door, char dir )
{
	Room* newRoom;

	if( dir == 's' )
	{
		if( door->south == NULL )
		{
			cout << "\nWhy can't you go to the combat room?";
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
			cout << "\nWhy can't you go to the hologram room?";
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
			cout << "\nWhy can't you go to the hanger?";
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
			cout << "\nWhy can't you go to the engine room?";
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
