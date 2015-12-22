/****************************************************************************************
 * Program Name: hallway.hpp
 * Author: Wesley Jinks
 * Description: A room child class that represents a hallway on the ship
 * Input: None
 * Output: None
 *
 * *************************************************************************************/

#ifndef HALLWAY_HPP
#define HALLWAY_HPP

#include "room.hpp"
#include<iostream>

using std::string;
using std::vector;
using std::cout;

class Hallway:public Room
{
	public:
		Hallway();
		virtual void viewItems();
		virtual void viewRoom();
		virtual void itemAction();
		virtual void fillRoom( vector<string> &items );
		virtual Room* chooseDoor( Room *door, char dir );
		~Hallway()
		{};
};

#endif
