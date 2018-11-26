/*
 * menu.cpp
 *
 *  Created on: Nov 1, 2018
 *      Author: d294m567
 */

#include <iostream>

#include "Menu.hpp"
#include <vector>
using namespace std;


const string Menu::menuend{"END"};

Menu::Menu(const string &name, const string &prompt,
        const vector<pair<string, string> > &choices)
		  : name(name), prompt(prompt), choices(choices)
{}

const string& Menu::getChoice() const
{
	if (choices.size() == 0){
		cout << prompt;
		return menuend;
	}

	unsigned choice;
	int i;
	do
	{
		cout << prompt;
		i = 1;
		for ( auto ch : choices)
			cout << i++ << ": " << ch.first << '\n';
		cin >> choice;
		--choice;
	} while (choice >= choices.size());
	return choices[choice].second;
}


