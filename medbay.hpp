/****************************************************************************************
 * Program Name: medbay.hpp
 * Author: Wesley Jinks
 * Description: A room child class that represents the medbay
 * Input: None
 * Output: None
 *
 * *************************************************************************************/

#ifndef MEDBAY_HPP
#define MEDBAY_HPP

#include "room.hpp"
#include<iostream>

using std::string;
using std::vector;
using std::cout;

class Medbay:public Room
{
	public:
		Medbay();
		virtual void viewItems();
		virtual void viewRoom();
		virtual void itemAction();
		virtual void fillRoom( vector<string> &items );
		virtual Room* chooseDoor( Room *door, char dir );
		~Medbay()
		{};
};

#endif
