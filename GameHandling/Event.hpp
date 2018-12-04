/*
 * Event.hpp
 *
 *  Created on: Nov 1, 2018
 *      Author: d294m567
 *
 *		Class name: Event
 *			usually an object where you get loot from
 *		Member Variables:
 *			string name - name of event
 *			int gold - gold event gives/has
 *			vector<Gear> loot - vector with gear. You either only have weapons
 *							or you only have armor.
 *		Constructors
 *			Event() - generic event not used
 *			Event(string n, int g, vector<Gear> l) name = n, gold = g, and
 *										loot = vector<Gear> l
 *
 *		Getters:
 *			getLoot(int i) - returns Gear object from vector using i for index
 *			getGold() - returns gold of event
 *			getVecSize() - returns the size of vector for use in
 *							randomizing loot
 *
 *		Member Functions -
 *			Print()
 *				mainly used for shop. Print's out everything nice and in columns
 *
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
	int getGold(void){return this->gold;};
	int getVecSize(){return this->loot.size();};
	void print();

};



#endif /* RANDOMEVENT_HPP_ */
