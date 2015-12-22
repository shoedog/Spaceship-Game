/****************************************************************************************
 * Program Name: crewQuarters.hpp
 * Author: Wesley Jinks
 * Description: A room child class that represents the crew quarters hanger
 * Input: None
 * Output: None
 *
 * *************************************************************************************/

#ifndef CREWQUARTERS_HPP
#define CREWQUARTERS_HPP

#include "room.hpp"
#include<iostream>

using std::string;
using std::vector;
using std::cout;

class CrewQ:public Room
{
	public:
		CrewQ();
		virtual void viewItems();
		virtual void viewRoom();
		virtual void itemAction();
		virtual void fillRoom( vector<string> &items );
		virtual Room* chooseDoor( Room *door, char dir );
		~CrewQ()
		{};
};

#endif
