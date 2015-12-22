/****************************************************************************************
 * Program Name: hanger.hpp
 * Author: Wesley Jinks
 * Description: A room child class that represents the mothership hanger
 * Input: None
 * Output: None
 *
 * *************************************************************************************/

#ifndef HANGER_HPP
#define HANGER_HPP

#include "room.hpp"
#include<iostream>

using std::string;
using std::vector;
using std::cout;

class Hanger:public Room
{
	public:
		Hanger();
		virtual void viewItems();
		virtual void viewRoom();
		virtual void itemAction();
		virtual void fillRoom( vector<string> &items );
		virtual Room* chooseDoor( Room *door, char dir );
		~Hanger()
		{};
};

#endif
