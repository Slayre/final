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
void start(vector<Menu> &game);

//Usually a vector member function but rewritten for use with a template
template<class InputIterator, class T>
InputIterator find (InputIterator first, InputIterator last, const T& val);

int main()
{
	//generateRoute();
	vector <Menu> game = generateRoute();
	start(game);
    return 0;
}

void start(vector<Menu> &game) {
    vector<Menu>::iterator menu;
	menu = find( game.begin(), game.end(), "mainroad");
    while (menu != game.end()){
        menu = find(game.begin(), game.end(), menu->getChoice());

    }
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
	            "You begin your quest along the path to the castle.\n"
	            "You come up to a fork in the road. Which way will you go?\n",
				std::vector<std::pair<string,string> >{
	                {"Go left", "spider"},
	                {"Go right", "troll"},}),
//right path
	    Menu("troll",
	           "Trotting along to the right, you come across a bridge.\n"
	           "A troll appears and dubs himself 'The Gate Keeper'.\n"
	    	   "And annouces the only way through the gate is him.",
	             std::vector<std::pair<string,string> >{
	                 {"Fight the Troll", "trollfight"},
	                 {"Attempt to out-brain the Troll", "trick"},}),
//after tricking the troll, player goes to shop
		Menu("trick",
				"'Aye, if there is only one way through, then what if I were Bill Gates?' You say.\n"
				 "'Well then you would have to go through me!' The troll responds.\n"
				 "'But he only uses windows!' You retort.\n"
				 "The troll, angry, cannot combat your logic and lets you pass.\n",
				 std::vector<std::pair<string,string> >{
					  {"Continue along your path.", "shop"},}),
//player must fight troll then continues to shop.
		Menu("trollfight",
				"The troll swings his giant fist at you.\n"
				"As you dodge his fist, you manage to get some swipe with your sword in at him.\n"
				"As he falls to the ground, you notice he was standing in front of a wooden chest.\n"
				"You choose to loot it.\n",
				std::vector<std::pair<string,string> >{
					 {"Loot", "trolltreasure"},}),
		Menu("trolltreasure",
				"'Aye, if there is only one way through, then what if I were Bill Gates?' You say.\n"
				"'Well then you would have to go through me!' The troll responds.\n"
				"'But he only uses windows!' You retort.\n"
				"The troll, angry, cannot combat your logic and lets you pass.\n",
				std::vector<std::pair<string,string> >{
					 {"Fight the Troll", "trollfight"},
					 {"Attempt to out-brain the Troll", "trick"},}),
		Menu("shop",
				"Further along the path, you come across a traveling merchant.\n"
				"Enchanted by your story, he lets you shop for a discount.\n",
				std::vector<std::pair<string,string> >{
					{"Continue along path.", "bandits"},}),
		Menu("bandits",
				"Just after purchasing your gear, you notice a ruffle in the grass\n"
				"Two squirrelly bandits jump out!\n"
				"'We were trying to rob your friend but you'll do too!' They exclaim.\n",
				std::vector<std::pair<string,string> >{
					{"Fight the Bandits!", "wanderingknight"},}),
		Menu("wanderingknight",
				"Bruised and tired, you carry forward with your quest\n"
				"Laying just off the path, you see a knight resting on a log.\n"
				"After talking to him, he tells you he has just failed to save his King's daughter"
				"trapped in another castle and is afraid to return home to his King."
				"You convince him to help you in your journey and if you are successful"
				"Your King will compensate him tremendously.\n"
				"He agrees, grabs his sword, and follows alongside you.\n",
				std::vector<std::pair<string,string> >{
					{"Continue along path.", "deadknight"},}),
//left
	    Menu("spider",
	            "You travel down the road, about only 100 metres and you encounter \n"
	            "a giant spider with vicious poison coated fangs.\n"
	            "its hideous appearance causes your throat to dry and your knees to shake!\n"
	            "What on earth will you do?\n\n",
				std::vector<std::pair<string, string> >{
	                {"Attempt to attack the spider with your sword.","spiderattack"},
	                {"Throw your sword in the off chance it might kill it.","hauntedforest"},}),
//fight spider
	    Menu("spiderattack",
	            "You viscously swing your sword at the spiders general direction.\n"
	            "The swing was so great, your arms jolts out of place,\n"
	            "creating a surge of pain.\n"
	            "Your arm is now broken, and you fall to the ground in pain....\n"
	            "The spider launches 3 metres straight into your body...\n"
	            "What on earth is it doing?\n"
	            "Oh My God! The spider is devouring everything....\n"
	            "All that remained was bones of the once mobile adventurer.\n"),
//2 adventurers in web, player can either flee or free them
		Menu("adventurers",
			    "After defeating the spider, you notice two adventurers stuck in it's web. \n"
			    "They yell for your help but you seem to sense danger nearby.\n",
				std::vector<std::pair<string, string> >{
			                {"Help the stranded adventurers.","helpweb"},
			                {"Flee the area and leave the adventurers","fleeweb"},}),
//flee and help web, user ends up at magician either way
		 Menu("fleeweb",
				"You slash through the web as you trying to make it out.\n"
			    "As you're nearing the end, you notice something moving in the distance.\n",
				std::vector<std::pair<string, string> >{
	                {"Investigate..","magician"},}),
		 Menu("helpweb",
				"The web is thick and begins to weigh down your sword.\n"
				"But you manage to cut the adventurers free.\n"
				"They thank you and would like to join you along your quest.\n",
				std::vector<std::pair<string, string> >{
				      {"'Sure! Could always use the extra help!'","magician"},
	    			  {"'It's too dangerous for you two.. Stay here.'","magician"}}),
//magician gives gear to gear up for goblins
		Menu("magician",
				"As you continue on the trail, you begin to make out what is ahead of you.\n"
				"It is a tall man with a wizard's hat.\n"
				"He approaches you and is intrigued by your quest. \n"
				"He offers some gear to you in aid.\n",
				std::vector<std::pair<string, string> >{
					  {"Take gear","goblins"},}),
//last fight for middle path
		Menu("goblins",
				"Continuing your route, your eyes fixate on the castle just over the horizon.\n"
				"Two snarling, green goblins ambush you!\n"
				"Your only option is to fight!\n",
				std::vector<std::pair<string, string> >{
						{"Fight!","deadknight"},}),
//escape spider
	    Menu("hauntedforest",
	            "You manage to escape into the woods and hear evil witch laughs further along the path.\n"
	            "You continue along the path but the witch has put a curse on you!.\n"
	            "You will now lose 5% health per turn.\n",
				std::vector<std::pair<string, string> >{
	                {"Continue along the path.", "witch"},}),
		 Menu("witch",
			    "You catch the witch off-guard while she is brewing a potion.\n"
				"Sneak up on her and take her out!\n",
				std::vector<std::pair<string, string> >{
				    {"Attack!", "witchshouse"},}),
		Menu("witchshouse",
			"After defeating the witch, you aren't able to tell what potion she was creating.\n"
			"Although you see an empty vial sitting next to her cauldron.\n",
			  std::vector<std::pair<string, string> >{
					{"Fill Vial!", "potion"},
	    			{"Leave House", "deadknight"}}),
	};

	return game;
}
