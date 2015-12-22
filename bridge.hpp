/****************************************************************************************
 * Program Name: bridge.hpp
 * Author: Wesley Jinks
 * Description: A room child class that represents the mothership bridge
 * Input: None
 * Output: None
 *
 * *************************************************************************************/

#ifndef BRIDGE_HPP
#define BRIDGE_HPP

#include "room.hpp"
#include<iostream>

using std::string;
using std::vector;
using std::cout;

class Bridge:public Room
{
	public:
		Bridge();
		virtual void viewItems();
		virtual void viewRoom();
		virtual void fillRoom( vector<string> &items );
		virtual void itemAction();
		virtual Room* chooseDoor( Room *door, char dir );
		~Bridge()
		{};
};

#endif
