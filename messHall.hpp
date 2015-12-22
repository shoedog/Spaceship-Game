/****************************************************************************************
 * Program Name: messHall.hpp
 * Author: Wesley Jinks
 * Description: A room child class that represents the mothership mess hall
 * Input: None
 * Output: None
 *
 * *************************************************************************************/

#ifndef MESSHALL_HPP
#define MESSHALL_HPP

#include "room.hpp"
#include<iostream>

using std::string;
using std::vector;
using std::cout;

class Mess:public Room
{
	public:
		Mess();
		virtual void viewItems();
		virtual void viewRoom();
		virtual void fillRoom( vector<string> &items );
		virtual void itemAction();
		virtual Room* chooseDoor( Room *door, char dir );
		~Mess()
		{};
};

#endif
