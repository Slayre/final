/*
 * player.hpp
 *
 *  Created on: Nov 1, 2018
 *      Author: d294m567
 */

#ifndef PLAYER_HPP_
#define PLAYER_HPP_

#include "\final\GameHandling\Event.hpp"
#include <iostream>
using namespace std;

class Player
{
	int health, maxhealth, gold, followers;
	double exp, exptonextlevel, sworddmg;
	string name;

	void setLevel();


public:
	//Default player with name Frodo
	Player();
	//Default player with name n
	Player (string n);
	~Player(){};

	//getters
	int getFollowers(void){return this->followers;};
	int getHealth(void){return this->health;};

	template<class EnemyType>
	void attack(EnemyType & enemy){enemy.takeDamage(sworddmg);};
	void takeDamage(int damage);
	void loot(Event event);
};




#endif /* PLAYER_HPP_ */
