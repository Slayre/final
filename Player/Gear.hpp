/*
 * Gear.hpp
 *
 *  Created on: Nov 1, 2018
 *      Author: d294m567
 */

#ifndef GEAR_HPP_
#define GEAR_HPP_

#include <iostream>
using namespace std;

class Gear{
	string name, type;
	int damage, protection;

public:
	Gear();
	Gear(string n, string t, int dmg, int prot) : name(n), type(t), damage(dmg),
			protection(prot) {};
	int getDamage(){return damage;};
	int getProtection(){return protection;};
	//Gear& generateGear(string t);
};



#endif /* GEAR_HPP_ */
