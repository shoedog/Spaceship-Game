/****************************************************************************************
 * Program Name: player.hpp
 * Author: Wesley Jinks
 * Description: A class that represents the player
 * Input: None
 * Output: None
 *
 * *************************************************************************************/

#ifndef PLAYER_HPP
#define HLAYER_HPP

#include "room.hpp"
#include<iostream>
#include<cctype>

using std::string;
using std::vector;
using std::cout;

class Player
{
	private:
		vector<string> bag;
		Room *room;
		bool bSize;

	public:
		Player();
		void viewItems();
		void dropItem();
		void changeRoom();
		void takeItem();
		void viewRoom();
		void setRoom( Room *newRoom );
		void move();
		void bagFull();
		void useItem();
		void itemInteract();
		void viewRItems();
		~Player()
		{};
};

#endif
