/*
 * Event.cpp
 *
 *  Created on: Nov 28, 2018
 *      Author: d294m567
*/

#include <iostream>
#include <iomanip>
#include "Event.hpp"
#include <algorithm>
using namespace std;

void Event::print()
{
	cout <<endl;
	cout << setw(40) << "Shop" << endl;
	cout << "========================================"
			"========================================" << endl;
	cout << "# " << setw(3) <<left << "||" <<setw(22) << "Name "<< "||"
			<< setw(10)<< "Type" << "||" << setw(10) << "Damage" << "||"
			<< setw(14) << "Protection" << "||" << setw(6) << "Gold" << "||"
			<< endl;
	cout << "========================================"
			"========================================" << endl;
	for (unsigned int i = 0; i < this->loot.size(); i++){
		cout << i+1 << "." <<setw(3) <<left << "||"
					<<setw(22) << this->loot[i].getName()<< "||"
					<< setw(10)<< this->loot[i].getType() << "||"
					<< setw(10)<< this->loot[i].getDamage() << "||"
					<< setw(14) << this->loot[i].getProtection() << "||"
					<< setw(6) << this->loot[i].getGold() << "||"
					<< endl;
			cout << "----------------------------------------"
					"----------------------------------------" << endl;
	}
}

