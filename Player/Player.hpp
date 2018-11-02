/*
 * player.hpp
 *
 *  Created on: Nov 1, 2018
 *      Author: d294m567
 */

#ifndef PLAYER_HPP_
#define PLAYER_HPP_

#include <iostream>
using namespace std;

class Player
{
	int health, maxhealth, level, atklvl, deflvl;
	double exp;
	string name;

	void setLevel();


public:
	//Default player with name Frodo
	Player();
	//Default player with name n
	Player (string n);
	~Player(){};

	void levelup();
	void takedamage();
	void givedamage();
	void attack();
	void block();

};




#endif /* PLAYER_HPP_ */
