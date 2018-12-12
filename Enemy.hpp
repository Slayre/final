/*
 * enemy.hpp
 *
 *  Created on: Nov 1, 2018
 *      Author: d294m567
 *
 *      Class: Enemy
 *      Description: single class for every enemy in the game
 *      Member variables:
 *      int health, maxhealth, gold, followers, damage, defense
 *      	health - health
 *      	maxhealth - highest health can go
 *      	damage - the amount of damage the enemy does
 *      string name
 *      	name - stores enemy's name
 *      Constructors
 *      	Default Enemy named enemy, maxhealth of 100, damage = 10
 *      	Enemy(string n, int mh, int d)
 *      		name = n, maxhealth = mh, damage = d;
 *      Getters
 *      	getName - returns name
 *      	getHealth - returns health
 *
 *      Setters
 *      	addFollowers(int i) - adds i amount of followers to player
 *      	purchase(int g) - subtracts money from user
 *
 *      Member Functions
 *      	takeDamage(int d)
				health -= damage
			attack(EnemyType & enemy)
				calls player member function takeDamage
 *
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
public:
	Enemy() : name("Enemy"), maxhealth(100), health(maxhealth), damage(10){};
	Enemy(string n, int mh, int dmg) : name(n), maxhealth(mh),
								health(maxhealth), damage(dmg){};
	~Enemy(){};

	//getters
	string getName(){return this->name;};
	int getHealth(void){return this->health;};


	void takeDamage(int damage){health -= damage;};

	template<class Player>
	void attack(Player & player){player.takeDamage(damage);};

};



#endif /* ENEMY_HPP_ */
