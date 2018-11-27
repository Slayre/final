/*
 * RandomEvent.hpp
 *
 *  Created on: Nov 1, 2018
 *      Author: d294m567
 */

#ifndef EVENT_HPP_
#define EVENT_HPP_

#include <vector>
#include <iostream>

#include "../Player/Gear.hpp"
using namespace std;

class Event{
	string name;
	int gold;
	vector<Gear> loot;

public:
	Event(){ name = "Event"; gold = 0; loot = {};};
	Event(string n, int g, vector<Gear> l) : name(n), gold(g), loot(l)
			{};
	Gear getLoot(int i){return this->loot[i];};
	int getVecSize(){return this->loot.size();};


};



#endif /* RANDOMEVENT_HPP_ */
