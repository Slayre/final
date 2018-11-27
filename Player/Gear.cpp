/*
 * Weapons.cpp
 *
 *  Created on: Nov 27, 2018
 *      Author: d294m567
 */

#include "Gear.hpp"

#include <iostream>
using namespace std;

Gear::Gear()
{
	name = "Helmet";
	type = "Gear";
	damage = 0;
	protection = 1;
}

/*
Gear & Gear::generateGear(string t)
{
	if ( t == "sword"){
		Gear *s = new Gear("sword","sword",25, 3);
		return s;
	}
	if (t == "armor"){
		Gear *a = new Gear("armor","armor", 2, 20);
		return a;
	}

}
*/
