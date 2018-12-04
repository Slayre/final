/*
 * Player.cpp
 *
 *  Created on: Nov 1, 2018
 *      Author: d294m567
 */

#include "Player.hpp"
#include "..\GameHandling\Exception.hpp"
#include <iostream>
#include <iomanip>

using namespace std;

Player::Player()
{
	name = "Frodo";
	maxhealth = 100;
	health = maxhealth;
	gold = 0;
	damage = 15;
	defense = 0;
	followers = 0;
}

Player::Player(string n)
{
	name = n;
	maxhealth = 100;
	health = maxhealth;
	gold = 50;
	damage = 15;
	defense = 0;
	followers = 0;
}

void Player::takeDamage(int d)
{
	int damagetaken = (d - (defense / 2));
	//if damagetaken is < 0 then player starts gaining health back
	//so we just nullify it
	if(damagetaken < 0)
		damagetaken = 0;
	health -= damagetaken;
	if (health <= 0)
		throw My_Exception::My_exception();
}

void Player::lootGear(Gear gear)
{
	this->damage += gear.getDamage();
	this->defense += gear.getProtection();
	cout << "You've Obtained New Gear!" << endl;
	cout << "========================================"
			"========================================" << endl;
	cout << setw(3) <<left << "||" <<setw(22) << "Name "<< "||"
			<< setw(10)<< "Type" << "||" << setw(10) << "Damage" << "||"
			<< setw(14) << "Protection" << "||" << setw(6) << "Gold" << "||"
			<< endl;
	cout << "========================================"
			"========================================" << endl;
	cout << setw(3) <<left << "||"
				<< setw(22) << gear.getName()<< "||"
				<< setw(10) << gear.getType() << "||"
				<< setw(10) << gear.getDamage() << "||"
				<< setw(14) << gear.getProtection() << "||"
				<< setw(6)  << gear.getGold() << "||"
				<< endl;
		cout << "----------------------------------------"
				"----------------------------------------" << endl;
}
void Player::lootGold(int g)
{
	this->gold += g;
	cout << "Looted " << g << " gold" <<endl;
	cout << "Total Gold: " << this->gold <<endl << endl;
}

void Player::heal(int amount)
{
	this->health += amount;
	if(health>100)
		health=100;
	cout << "========================================" <<endl;
	cout << setw(3) <<left << "||" <<setw(14) << "Player "<< "||"
			<< setw(12)<< "Health" << "||" << endl;
	cout <<"||"<< setw(15) << this->name << "||"
			<< setw(12)<< this->health << "||" << endl;

}


