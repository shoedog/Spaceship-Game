/****************************************************************************************
 * Program Name: weaponRoom.hpp
 * Author: Wesley Jinks
 * Description: A room child class that represents the mothership weapon room/armoury
 * Input: None
 * Output: None
 *
 * *************************************************************************************/

#ifndef WEAPONROOM_HPP
#define WEAPONROOM_HPP

#include "room.hpp"
#include<iostream>

using std::string;
using std::vector;
using std::cout;

class WeaponR:public Room
{
	public:
		WeaponR();
		virtual void viewItems();
		virtual void viewRoom();
		virtual void itemAction();
		virtual void fillRoom( vector<string> &items );
		virtual Room* chooseDoor( Room *door, char dir );
		~WeaponR()
		{};
};

#endif
