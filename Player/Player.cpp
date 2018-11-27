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
	gold = 50;
	sworddmg = 15;
	defense = 0;
	followers = 0;
}

Player::Player(string n)
{
	name = n;
	maxhealth = 100;
	health = maxhealth;
	gold = 50;
	sworddmg = 15;
	defense = 0;
	followers = 0;
}

void Player::takeDamage(int damage){
	health -= (damage - defense);
	cout <<name << " : " << this->health<<endl;
	if (health <= 0){
		throw health;
	}
}

void Player::loot(Gear gear)
{
	sworddmg = gear.getDamage();
	defense += gear.getProtection();
}


