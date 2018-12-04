/*
 * Gear.hpp
 *
 *  Created on: Nov 1, 2018
 *      Author: d294m567
 *
 *      Class Name: Gear
 *      	each piece of gear has it's own object
 *      Member variables:
 *      	name type - stores name of object and the type (sword, hammer,boots)
 *      	damage, protection, gold - all ints storing the variables assigned
 *      Constructors:
 *      	Gear() - default gear, generic name type, 0 damage, 1 protection,
 *      			worth 0 gold. Not used.
 *      	Gear(string n, string t, int dmg, int prot, int g)
 *      		all gear is initialized using this.
 *      Getters:
 *      	getName - returns name
 *      	getType - returns type
 *      	getProtection - returns protection
 *      	getGold - returns gold
 *      	getDamage - returns damage
 *
 *
 *
 *
 *
 */

#ifndef GEAR_HPP_
#define GEAR_HPP_

#include <iostream>
using namespace std;

class Gear{
	string name, type;
	int damage, protection, gold;

public:
	//Constructors
	Gear() : name("item"), type("Gear"), damage(0), protection(1), gold(0){};
	Gear(string n, string t, int dmg, int prot, int g) : name(n), type(t),
			damage(dmg), protection(prot), gold(g) {};

	//Getters
	string getName() const {return name;};
	string getType() const {return type;};
	int getDamage() const {return damage;};
	int getProtection() const {return protection;};
	int getGold() const {return gold;};


};



#endif /* GEAR_HPP_ */
