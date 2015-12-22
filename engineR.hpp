/****************************************************************************************
 * Program Name: engineR.hpp
 * Author: Wesley Jinks
 * Description: A room child class that represents the mothership engine room
 * Input: None
 * Output: None
 *
 * *************************************************************************************/

#ifndef ENGINER_HPP
#define ENGINER_HPP

#include "room.hpp"
#include<iostream>

using std::string;
using std::vector;
using std::cout;

class EngineR:public Room
{
	public:
		EngineR();
		virtual void viewItems();
		virtual void viewRoom();
		virtual void itemAction();
		virtual void fillRoom( vector<string> &items );
		virtual Room* chooseDoor( Room *door, char dir );
		~EngineR()
		{};
};

#endif
