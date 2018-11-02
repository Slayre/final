/*
 * Player.cpp
 *
 *  Created on: Nov 1, 2018
 *      Author: d294m567
 */

#include "Player.hpp"

#include <iostream>
using namespace std;

Player::Player()
{
	name = "Frodo";
	maxhealth = 100;
	health = maxhealth;
	level = 1;
	atklvl = 1;
	deflvl = 1;
	exp = 0;
}

Player::Player(string n)
{
	name = n;
	maxhealth = 100;
	health = maxhealth;
	level = 1;
	atklvl = 1;
	deflvl = 1;
	exp = 0;
}
