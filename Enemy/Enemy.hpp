/*
 * enemy.hpp
 *
 *  Created on: Nov 1, 2018
 *      Author: d294m567
 */

#ifndef ENEMY_HPP_
#define ENEMY_HPP_

#include <iostream>
using namespace std;


class Enemy
{
protected:
	string name;
	int maxhealth, health, damage;
	//int level, atklevel, deflevel, rewardexp;
public:
	Enemy();
	Enemy(string n, int mh, int dmg);
	~Enemy(){};
	void takeDamage(int damage){health -= damage;};
	//int getAtkLevel(){return atklevel;};
	template<class Player>
	void attack(Player & player);

};



#endif /* ENEMY_HPP_ */
