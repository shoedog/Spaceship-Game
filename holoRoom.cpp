/****************************************************************************************
 *	Program Name: holoRooom.cpp
 *	Author: Wesley Jinks
 *	Description: the implementation file for the mothership hallway
 *	Input: None
 *	Output: a room description, and a list of items in the room.
 *	************************************************************************************/

#include "holoRoom.hpp"

/****************************************************************************************
 *	Function: HoloR()
 *	Description: constructor
 *	Parameters: name, vector of items
 *	PreConditions: None
 *	PostConditions: the ship room is created
 ***************************************************************************************/
HoloR::HoloR()
	: Room( "Hologram Room" )
{
	fillRoom( items );
	this->itemFlag = 0;
	actionItem = "message";
}

void HoloR::itemAction()
{
	if( this->itemFlag == 1 )
	{
		cout << "This is a message from the captain. He says we are headed for a black hole\n"
			 << "I need to find the bridge.";
	}
}
void HoloR::viewItems()
{
	cout << "\nHere are some things you see in the room: \n";
	for( unsigned i = 0; i< this->items.size(); i++ )
		cout << "   " << this->items[i] << "\n";
}

void HoloR::fillRoom( vector<string> &items )
{
	items.push_back( " " );
}

void HoloR::viewRoom()
{
	cout << "\nmessage";
}


Room* HoloR::chooseDoor( Room *door, char dir )
{
	Room* newRoom;

	if( dir == 's' )
	{
		if( door->south == NULL )
		{
			cout << "\nThis appears to be a teleporter, but it doesn't have any power.";
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
			cout << "\nBack to the crew room.";
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
			cout << "\nThis is just a shimmering wall to make holograms.";
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
			cout << "\nBack to the second hallway.";
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
