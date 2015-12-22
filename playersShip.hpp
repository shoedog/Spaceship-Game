/****************************************************************************************
 * Program Name: playersShip.hpp
 * Author: Wesley Jinks
 * Description: A room child class that represents the player's spaceship
 * Input: None
 * Output: None
 *
 * *************************************************************************************/

#ifndef PLAYERSSHIP_HPP
#define PLAYERSSHIP_HPP

#include "room.hpp"
#include<iostream>

using std::string;
using std::vector;
using std::cout;

class PShip:public Room
{		
	public:
		PShip();
		virtual void viewItems();
		virtual void viewRoom();
		virtual void fillRoom( vector<string> &items );
		virtual Room* chooseDoor( Room *door, char dir );
		virtual void itemAction();
		~PShip()
		{};
};

#endif
