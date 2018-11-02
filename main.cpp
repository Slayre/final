/*
 * main.cpp
 *
 *  Created on: Nov 1, 2018
 *      Author: d294m567
 */

#include <iostream>

#include "GameHandling\Menu.hpp"
#include "GameHandling\RandomEvent.hpp"
#include "Player\Player.hpp"
using namespace std;


vector<Menu> generateRoute(void);
void road(vector<Menu> &game);

template<class InputIterator, class T>
InputIterator find (InputIterator first, InputIterator last, const T& val);

int main()
{
	generateRoute();
	vector<Menu> game = generateRoute();
	road(game);
    return 0;
}

void road(vector<Menu> &game) {
    vector<Menu>::iterator menu;
	menu = find( game.begin(), game.end(), "mainroad");
    while (menu != game.end())
        menu = find(game.begin(), game.end(), menu->getChoice());
}

template<class InputIterator, class T>
  InputIterator find (InputIterator first, InputIterator last, const T& val)
{
  while (first!=last) {
    if (*first==val) return first;
    ++first;
  }
  return last;
}

vector<Menu> generateRoute(void){
	vector<Menu> game{
	    Menu("mainroad",
	            "You are on a road that heads west and east of your position.\n"
	            "Which way will you go?\n",
				std::vector<std::pair<string,string> >{
	                {"Go West", "spider"},
	                {"Go East", "brickhouse"},
	                {"Wait for something to happen", "dragon"}}),
	    Menu("spider",
	            "You travel down the road, about only 100 metres and you encounter \n"
	            "a giant spider with vicious poison coated fangs.\n"
	            "its hideous appearance causes your throat to dry and your knees to shake!\n"
	            "What on earth will you do?\n\n",
				std::vector<std::pair<string, string> >{
	                {"Attempt to attack the spider with your sword.","spiderattack"},
	                {"Throw your sword in the off chance it might kill it.","throwsword"},
	                {"RUN FOR YOUR LIFE!", "running"}}),
	    Menu("spiderattack",
	            "You viscously swing your sword at the spiders general direction.\n"
	            "The swing was so great, your arms jolts out of place,\n"
	            "creating a surge of pain.\n"
	            "Your arm is now broken, and you fall to the ground in pain....\n"
	            "The spider launches 3 metres straight into your body...\n"
	            "What on earth is it doing?\n"
	            "Oh My God! The spider is devouring everything....\n"
	            "All that remained was bones of the once mobile adventurer.\n"),
	    Menu("brickhouse",
	            "After a mile walk, you arrive at an old brick house.\n"
	            "You walk slowly inside.\n"
	            "The door slams behind you and the room lightens up.\n"
	            "What on earth is going on...?\n\n"
	            "Unable to open the door, you look around for anything of use.\n"
	            "Nothing, not a single piece of furniture.\n"
	            "What will you do?\n",
				std::vector<std::pair<string, string> >{
	                {"Wait for someone to save you.", "trapdoor"},
	                {"Or Wait for someone to save you.", "library"}})
	};
	return game;
}
