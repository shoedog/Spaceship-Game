/****************************************************************************************
 * Program Name: combatRoom.hpp
 * Author: Wesley Jinks
 * Description: A room child class that represents the mothership combat Room
 * Input: None
 * Output: None
 *
 * *************************************************************************************/

#ifndef COMBATROOM_HPP
#define COMBATROOM_HPP

#include "room.hpp"
#include<iostream>

using std::string;
using std::vector;
using std::cout;

class CombatR:public Room
{
	public:
		CombatR();
		virtual void viewItems();
		virtual void viewRoom();
		virtual void itemAction();
		virtual void fillRoom( vector<string> &items );
		virtual Room* chooseDoor( Room *door, char dir );
		~CombatR()
		{};
};

#endif
