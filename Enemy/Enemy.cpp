/*
 * Enemy.cpp
 *
 *  Created on: Nov 7, 2018
 *      Author: Cole-LENOVO
 */


#include "Enemy.hpp"
#include <iostream>
using namespace std;

Enemy::Enemy()
{
	name = "Enemy";
	maxhealth = 100;
	health = maxhealth;
	rewardexp = 10;
}

Enemy::Enemy(string n, int mh, int exp)
{
	name = n;
	maxhealth = mh;
	health = maxhealth;
	rewardexp = exp;
}
