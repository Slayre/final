/*
 * menu.hpp
 *
 *  Created on: Nov 1, 2018
 *      Author: d294m567
 */

#ifndef MENU_HPP_
#define MENU_HPP_

#include <iostream>
#include <vector>
using namespace std;


class Menu
{
	static const string menuend;
	string name, prompt;
	//pair is a container that stores two values mapped to each other
	vector < pair < string , string > > choices;
public:
	Menu(const string &name, const string &prompt,
			const vector<pair<string,string>> &choices =
					vector<pair<string, string>>{});
	virtual ~Menu(){};
	const string& getChoice() const;
	bool operator == (const string &n) const {return n == name;};
};




#endif /* MENU_HPP_ */
