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
	int maxhealth, health;
	//int level, atklevel, deflevel, rewardexp;
	int rewardexp;
public:
	Enemy();
	Enemy(string n, int mh, int exp);
	~Enemy(){};
	//int getAtkLevel(){return atklevel;};
	void attack();

};



#endif /* ENEMY_HPP_ */
