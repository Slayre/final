/*
 * menu.hpp
 *
 *  Created on: Nov 1, 2018
 *      Author: d294m567
 *
 *       *      Class Name: Menu
 *      Description:
 *      	Stores the menu options into one big vector
 *      Member Variables:
 *      	string menuend, name prompt
 *      		menuend stores the menu name that is at the end of the vector
 *      		name stores the menu's individual name
 *      		prompt is the text that pops up when you select an option
 *      	vector < pair < string, string > > choices
 *      		is a vector pair of string that stores the action that you are
 *      		about to do, IE. fight bandit, and stores the corresponding menu
 *      		name to that action, IE. bandits.
 *
 *      Constructors:
 *      	Menu(string &name, string &prompt, vector<pair<string,string>>
 *      		Only constructor used, puts the menu's name, the prompt to go
 *      			with it and then stores the choices in a vector pair all
 *      			in one index.
 *      	Destructor
 *      		~Menu
 *      			base destructor
 *
 *      	Getters
 *     			getChoice()
 *     				if the amount of choices available is == 0
 *     					then print prompt
 *     					and print "END" because we must be at the end.
 *     				do while loop until your input >= choices.size()
 *     				inside do while loop, it prints prompt once and then uses
 *     				for loop to print out the choices.
 *     				returns your choice for the index value of the choices
 *     				pair vector and returns .second so we get the menu name
 *     				and are able to move onto the next menu.
 *     			getName()
 *     				returns name
 *
 *			Overloaded ==
 *				used to check which menu name we are on in main
 *
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
	~Menu(){};
	const string& getChoice() const;
	const string getName() const {return this->name;};
	bool operator == (const string &n) const {return n == name;};
};




#endif /* MENU_HPP_ */
