/****************************************************************************************
 *	Program Name: weaponRoom.cpp
 *	Author: Wesley Jinks
 *	Description: the implementation file for the mothership weapon room
 *	Input: None
 *	Output: a room description, and a list of items in the room.
 *	************************************************************************************/

#include "weaponRoom.hpp"

/****************************************************************************************
 *	Function: WeaponR()
 *	Description: constructor
 *	Parameters: name, vector of items
 *	PreConditions: None
 *	PostConditions: the ship room is created
 ***************************************************************************************/
WeaponR::WeaponR()
	: Room( "Weapon Room and Armoury" )
{
	fillRoom( items );
}

void WeaponR::itemAction()
{}

void WeaponR::viewItems()
{
	cout << "\nHere are some things you see in the room: \n";
	for( unsigned i = 0; i< this->items.size(); i++ )
		cout << "   " << this->items[i] << "\n";
}

void WeaponR::fillRoom( vector<string> &items )
{
	items.push_back( "Ammo Crate" );
	items.push_back( "Plasma Gun" );
	items.push_back( "Laser Knife" );
	items.push_back( "Laser Whip" );
	items.push_back( "Grendade" );
	items.push_back( "Death Bot" );
}

void WeaponR::viewRoom()
{
	cout << "\nYou should be careful not to touch anything in here. You aren't trained \n"
		 << "\nto use any kind of weapons. Do you really think any of these weapons will\n"
		 << "\nhelp you in a fight? You should just try to run or hide if it comes to that.\n"
		 << "\nThere are racks of different types of weapons for someone that knows how to\n"
		 << "\nuse them, but really, that isn't you. There is also one of the ships plasma\n"
		 << "\ncannons and a missile tube. Even though they are on, doesn't mean you need\n"
		 << "\nto play with them. What are you going to shoot at anyways?\n";
}


Room* WeaponR::chooseDoor( Room *door, char dir )
{
	Room* newRoom;

	if( dir == 's' )
	{
		if( door->south == NULL )
		{
			cout << "\nThere are just racks of guns.";
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
			cout << "\nThis looks like a missile loader.";
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
			cout << "\nWhy can't you enter the combat room?";
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
			cout << "\nThere are more weapon racks, some are empty like someone took the guns.";
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
