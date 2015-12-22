/****************************************************************************************
 * Program Name: holoRoom.hpp
 * Author: Wesley Jinks
 * Description: A room child class that represents the mothership hologram room
 * Input: None
 * Output: None
 *
 * *************************************************************************************/

#ifndef HOLOROOM_HPP
#define HOLOROOM_HPP

#include "room.hpp"
#include<iostream>

using std::string;
using std::vector;
using std::cout;

class HoloR:public Room
{
	public:
		HoloR();
		virtual void viewItems();
		virtual void viewRoom();
		virtual void itemAction();
		virtual void fillRoom( vector<string> &items );
		virtual Room* chooseDoor( Room *door, char dir );
		~HoloR()
		{};
};

#endif
