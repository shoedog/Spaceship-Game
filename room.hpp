/****************************************************************************************
 *  Program Name: room.hpp
 *  Author: Wesley Jinks
 *  Date: 3/15/2015
 *  Description: Room SuperClass header file
 *  Input: None
 *  Output: None
 * 
 * *************************************************************************************/

#ifndef ROOM_HPP
#define ROOM_HPP

#include <string>
#include <cstddef>
#include <vector>

using std::string;
using std::vector;

class Room
{

public:
	string roomLabel;
	Room *north;
	Room *south;
	Room *east;
	Room *west;
	vector<string> items;
	bool itemFlag;
	string actionItem;
	/*	RoomN()
		{
			north = NULL;
			south = NULL;
			east = NULL;
			west = NULL;
		}	
	*/	
	Room( string label )
	{
		this->roomLabel = label;
		north = NULL;
		south = NULL;
		east = NULL;
		west = NULL;
	}
	void setLabel( string label )
	{ this->roomLabel = label; }
	string getLabel()
	{ return this->roomLabel; }
	string getActionItem()
	{ return this->actionItem; }
	virtual void itemAction() = 0;
	virtual void viewItems() = 0;
	virtual void viewRoom() = 0;
	virtual Room* chooseDoor( Room *door, char dir ) = 0;
/*	{
		Room* newRoom;
		newRoom = door->south;
		return newRoom;
	}*/
	virtual void fillRoom( vector<string> &items ) = 0;
	~Room()
	{}

};

#endif
