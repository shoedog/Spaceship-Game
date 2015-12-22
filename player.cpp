/****************************************************************************************
 * Program Name: player.cpp
 * Author: Wesley Jinks
 * Description: A class that represents the player
 * Input: None
 * Output: None
 *
 * *************************************************************************************/

#include "player.hpp"
#include<iostream>

using std::string;
using std::vector;
using std::cout;
using std::cin;

Player::Player()
{
	this->bSize = 0;
}

void Player::viewItems()
{
	cout << "\nThis is what your have: \n";
	for( unsigned i = 0; i < this->bag.size(); i++ )
		cout << "  " << i + 1 << ": " << bag[i] << "\n";
}
		
void Player::takeItem()
{
	string item;
	bool itemFound = 0;
	bagFull();

	if( this->bSize == 0 )
	{
		cout << "What do you want to pick up: ";
		cin.clear();
		cin.ignore();
		getline( cin, item );

		for( unsigned i = 0; i < this->room->items.size(); i++ )
		{
			if( item == this->room->items[i] )
			{
				bag.push_back( item );
				this->room->items.erase( this->room->items.begin() + i );
				itemFound = 1;
				cout << "\nYou picked it up.\n";
			}
		}	

		if( itemFound == 0 )
			cout << "\nThere is no item like that here. View the room again or try to pick up "
				 << "something else. \n";
	}
	else if( this->bSize == 1 )
		cout << "Your bag is full! You are too weak to carry anything else. Do you really need\n"
			 << "all that stuff? Stop being a hoarder and get rid of some stuff.\n";
}

void Player::bagFull()
{
	if( this->bag.size() > 5 )
		this->bSize = 1;
	else if( this->bag.size() < 5 )
		this->bSize = 0;
}

void Player::dropItem()
{
	string item;
	bool itemFound = 0;
	bagFull();

	cout << "What do you want to drop from your bag: ";
	cin.clear();
	cin.ignore();
	getline( cin, item );

	for( unsigned i = 0; i < this->bag.size(); i++ )
	{
		if( item == this->bag[i] )
		{
			this->room->items.push_back( item );
			this->bag.erase( this->bag.begin() + i );
			itemFound = 1;
			cout << "\nYou dropped the item.\n";
		}
	}	

	if( itemFound == 0 )
	{
		cout << "\nThere is no item like that in your bag. Humans are prone to error "
				<< "so check your bag again. \n";
	}

}

void Player::useItem()
{
	bool itemFound = 0;
	string bItem;

	cout << "What do you want to use from your bag?";
	cin.clear();
	cin.ignore();
	getline( cin, bItem );

	for( unsigned i = 0; i < this->bag.size(); i++ )
	{
		if( bItem == this->bag[i] )
		{
			itemFound = 1;
			if( bItem == this->room->getActionItem() )
			{
			//	this->room->action();
				this->room->itemFlag = 1;
				this->room->itemAction();
			}
			else
				cout << "\n" << bItem << "doesn't do anything here.\n";
		}
	}

	if( itemFound == 0 )
		cout << "\nYou don't have that in your bag, check it again!\n";
}

void Player::viewRoom()
{
	this->room->viewRoom();
}

void Player::setRoom( Room *newRoom )
{
	this->room = newRoom;
}
		
void Player::move()
{
	char dir;
	cout << "Where would you like to move: \n'W' = North\n'A' = East\n"
		 <<"'S' = South\n'D' = West\n ";
	cin >> dir;
	dir = tolower(dir);
	if( dir != 'w' && dir != 'a' && dir != 's' && dir != 'd' )
		cout << "\nYou can only move with WASD.\n ";
	else
		setRoom( this->room->chooseDoor( this->room, dir ) );
}

void Player::itemInteract()
{
	char dir;
	cout << "\n  B: View Bag\n  I: View Items in Room\n  U: Use Item\n" 
		 << "  P: Pick Up Item\n  R: Remove Item From Bag\n";

	cout << "\nWhat would you like to do?\n";
	cin >> dir;
	dir = toupper( dir );
	switch( dir )
	{
		case 'B':
			viewItems();
			break;
		case 'I':
			viewRItems();
			break;
		case 'U':
			useItem();
			break;
		case 'P':
			takeItem();
			break;
		case 'R':
			dropItem();
			break;
		default:
			cout << "\nYou did not enter a valid option.\n";
	}
}

void Player::viewRItems()
{
	this->room->viewItems();
}

