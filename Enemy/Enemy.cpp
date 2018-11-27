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
	damage = 10;
}

Enemy::Enemy(string n, int mh, int dmg)
{
	name = n;
	maxhealth = mh;
	health = maxhealth;
	damage = dmg;
}

template<class Player>
void Enemy::attack(Player & player){
	player.takeDamage(damage);
}
