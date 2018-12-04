/*
 * player.hpp
 *
 *  Created on: Nov 1, 2018
 *      Author: d294m567
 *
 *      Class: Player
 *      Description: Houses the player object for the whole game
 *      Member variables:
 *      int health, maxhealth, gold, followers, damage, defense
 *      	health - health
 *      	maxhealth - highest health can go
 *      	gold - used to buy stuff in the shop
 *      	followers - collected along the way, adds one more attack each turn
 *      	damage - the amount of damage the player does
 *      	defense - the amount of protection the player has
 *      string name
 *      	name - stores player's name
 *      Constructors
 *      	Default player named Frodo, maxhealth of 100, gold = 0
 *      		damage = 15, defense = 0, followers = 0
 *      	Player(string n)
 *      		name = n, everything else is same as base constructor
 *      Getters
 *      	getName - returns name
 *      	getFollowers - returns followers
 *      	getHealth - returns health
 *      	getGold - returns gold
 *      	getDamage - returns damage
 *
 *      Setters
 *      	addFollowers(int i) - adds i amount of followers to player
 *      	purchase(int g) - subtracts money from user
 *
 *      Member Functions
 *      	takeDamage(int d)
 *      		damagetaken = (d - (defense /2))
 *      		//if damagetaken is < 0 then player starts gaining health back
				//so we just nullify it
				 if (damagetaken < 0)
				 	 damagetaken = 0
				 health -= damagetaken;
				 if(health <= 0)
				 	 throw Exception that player is dead
			lootGear(Gear gear)
				adds the gear's damage to the player's damage
				adds gear's defense stat to player's defense stat
				everything else is just making it look pretty
			lootGold(int g)
				adds g to player's gold
				cout how much gold was looted
				cout total gold
			heal (int amount)
				heals health by the amount given.
				if health exceeds maxhealth then we reset it back to maxhealth
			attack(EnemyType & enemy)
				calls enemy member function takeDamage
 *
 */

#ifndef PLAYER_HPP_
#define PLAYER_HPP_

#include "Gear.hpp"
#include <iostream>
using namespace std;

class Player
{
	int health, maxhealth, gold, followers, damage, defense;
	string name;


public:
	//Default player with name Frodo
	Player();
	//Default player with name n
	Player (string n);
	~Player(){};

	//getters
	string getName(void){return this->name;};
	int getFollowers(void){return this->followers;};
	int getHealth(void){return this->health;};
	int getGold(void){return this->gold;};
	int getDamage(void){return this->damage;};

	//setter
	void addFollowers(int i){this->followers += i;};
	void purchase(int g){this->gold -= g;};


	template<class EnemyType>
	void attack(EnemyType & enemy){enemy.takeDamage(damage);};
	void takeDamage(int damage);
	void heal(int amount);
	void lootGear(Gear gear);
	void lootGold(int g);

};




#endif /* PLAYER_HPP_ */
