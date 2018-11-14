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
public:
	Enemy();
	~Enemy(){};
	//int getAtkLevel(){return atklevel;};
	void attack();

};



#endif /* ENEMY_HPP_ */
