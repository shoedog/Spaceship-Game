/****************************************************************************************
 *	Program Name: hanger.cpp
 *	Author: Wesley Jinks
 *	Description: the implementation file for the mothership hanger
 *	Input: None
 *	Output: a room description, and a list of items in the room.
 *	************************************************************************************/

#include "hanger.hpp"

/****************************************************************************************
 *	Function: Hanger()
 *	Description: constructor
 *	Parameters: name, vector of items
 *	PreConditions: None
 *	PostConditions: the ship room is created
 ***************************************************************************************/
Hanger::Hanger()
	: Room( "MotherShip Hanger" )
{
	fillRoom( items );
	this->itemFlag = 0;
}

void Hanger::viewItems()
{
	cout << "\nHere are some things you see in the room: \n";
	for( unsigned i = 0; i< this->items.size(); i++ )
		cout << "   " << this->items[i] << "\n";
}

void Hanger::itemAction()
{
}

void Hanger::fillRoom( vector<string> &items )
{
	items.push_back( "Hanger Controls" );
	items.push_back( "warp codes" );
}

void Hanger::viewRoom()
{
	cout << "\nIt is weird that this hanger is empty. On a mother-ship this size\n"
		 << "there should be at least a couple other small ships. There is also\n"
		 << "a surprising lack of people. Usually someone would be greeting you\n"
		 << "to see why you are here. Well you aren't finding another ship to get\n"
		 << "out of here, you better find your way inside the ship and see if there\n"
		 << "is anyone here.\n"; 
}

Room* Hanger::chooseDoor( Room *door, char dir )
{
	Room* newRoom;

	if( dir == 's' )
	{
		if( door->south == NULL )
		{
			cout << "\nWhy can't you open the blast doors.";
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
			cout << "\nYour ship is locked down tight.";
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
			cout << "\nYou don't want to go out into space dressed like that.";
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
			cout << "\nThis appears to be a teleporter, but it doesn't have any power.";
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
