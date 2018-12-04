/*
 * main.cpp
 *
 *  Created on: Nov 1, 2018
 *      Author: d294m567
 *
 *
 *      Main.cpp
 *      functions:
 *      vector<Menu> generateRoute
 *      	used to initialize all of the menu options and returns it in a
 *      		vector
 *      vector<vector<Gear>> generateGear
 *      	used to initialize all of the gear and returns it in a
 *      		vector of vectors
 *      	weapons is stored in one vector and armor is stored in the other
 *      	and then we concatenate them onto one vector called "gear" and
 *      	return it.
 *      start(vector<Menu> &game)
 *      	while loop that goes until iterator hits menu.end()
 *      	if statements for nearly every menu option so specific things
 *      	can happen at specific places and not out of order.
 *      fight(Type 1 & player, Type2& enemy)
 *      	if player has a follower than they attack twice before the enemy
 *      		does. If they player has 2 followers then they attack 3 total
 *      		times before the enemy does.
 *      	Enemy always attacks just once
 *      	for loop for while the player is attacking the enemy and a seperate
 *      	one for enemy attacking player.
 *      	both for loops in a while loop until either the player has 0 health
 *      	or the enemy does
 *      main
 *      	generates route and stores it into vector to be passed into function
 *      	start, which is surrounded by try block waiting to catch if the
 *      	player ever dies.
 *
 *
 *
 *
 *
 *
 */

#include <vector>
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <exception>
#include <algorithm>

#include "GameHandling\Menu.hpp"
#include "Enemy\Enemy.hpp"
#include "GameHandling\Event.hpp"
#include "GameHandling\Exception.hpp"
#include "Player\Player.hpp"
#include "Player\Gear.hpp"
using namespace std;

vector<Menu> generateRoute(void);
vector<vector<Gear>> generateGear(void);

void start(vector<Menu> &game);

template<class Type1, class Type2>
void fight(Type1 & player, Type2 & enemy);

int main()
{
	vector<Menu> game = generateRoute();
	srand(time(NULL));
	try
	{
		start(game);
	}
	catch (const My_Exception::My_exception&)
	{
		cout << "You are dead!" << endl;
	}
	return 0;
}

void start(vector<Menu> &game)
{
	Player player;
	vector<vector<Gear>> gear = generateGear();

	vector<Menu>::iterator menu;
	menu = find(game.begin(), game.end(), "mainroad");
	while (menu != game.end())
	{
		menu = find(game.begin(), game.end(), menu->getChoice());
		cin.ignore();
		if (menu == find(game.begin(), game.end(), "trollfight"))
		{
			Enemy troll("Troll", 100, 10);
			fight(player, troll);

		}
		if (menu == find(game.begin(), game.end(), "trolltreasure"))
		{
			cout << "You swing your sword at the lock and break it.\n"
					"Brushing off the dust, you see shimmering gold inside.\n"
					"A weapon lays across horizontally.\n";
			//Event Trollchest with 50 gold and only stores weapons.
			Event trollchest("Trollchest", 50, gear.front());
			//rand number between 0 and total size of weapon vector
			int i = rand() % trollchest.getVecSize();
			Gear tempwep = trollchest.getLoot(i);
			char choice;
			cout << "You've found: " << tempwep.getName() << " And "
					<< trollchest.getGold() << " gold. \n"
							"Would you like to loot the weapon? (Y/N)" << endl;
			cin >> choice;
			if (choice == 'Y' || choice == 'y')
				player.lootGear(tempwep);
			//player always loots gold
			player.lootGold(trollchest.getGold());

		}
		//Shop Menu
		if (menu == find(game.begin(), game.end(), "shop"))
		{
			cout
			<< "As the you get nearer you realize it's a traveling merchant.\n"
			   "You approach him and ask what he is doing around these parts.\n"
				"He tells you he used to be a wizard but got tired of"
				" practicing the art.\n"
				"And he now travels kingdom to kingdom to sell his goods.\n"
				"He then asks you why you are this far away from home.\n"
				"Enchanted by your story, he lets you shop for a discount.\n\n";
			//Event Shop with 25 starting gold and only stores armor.
			Event shop("Shop", 25, gear.back());
			char choice;
			int item;
			cout << "Would you like to view his shop? (Y/N)" << endl;
			cin >> choice;

			//try block detecting if player wants to quit shop after viewing

			if (choice == 'Y' || choice == 'y')
			{
				shop.print();
				cout << "You may purchase one item from the kind Wizard."
						<< endl << "Please enter the number of the item you "
								"wish to buy: ";
				cin >> item;
				Gear temp = shop.getLoot(--item);
				if (player.getGold() < temp.getGold())
				{
					Enemy wizard("Wizard", 100, 10);
					cout << "You cannot afford that item." << endl
							<< "The wizard is disgusted with you "
									"after he offered you his kindness."
									"Now you must fight!" << endl;
					fight(player, wizard);
				}
				else
				{
					player.lootGear(temp);
					player.purchase(temp.getGold());
				}
			}
		}
		if (menu == find(game.begin(), game.end(), "bandits"))
		{
			cout << player.getDamage() << endl;
			Enemy bandits("Bandits", 185, 18);
			fight(player, bandits);
		}
		if (menu == find(game.begin(), game.end(), "wanderingknight"))
		{
			player.addFollowers(1);
		}
		if (menu == find(game.begin(), game.end(), "adventurers"))
			player.addFollowers(2);
		if (menu == find(game.begin(), game.end(), "spiderattack"))
		{
			cout
		<< "You frantically start cutting away the web stuck to your feet.\n"
				"The spider races towards you, ready to entrap it's dinner.\n"
				"The spider is within inches but you manage to break free!\n"
				"You start swinging your sword! \n\n";
			Enemy spider("Spider", 100, 10);
			fight(player, spider);
		}
		if (menu == find(game.begin(), game.end(), "magician"))
		{
			cout
			<< "Continuing your journey, you forge onwards.\n"
					"Tired and bruised, you seek a place to rest.\n"
					"You stop for a second to sit on a log.\n"
					"Out of nowhere, a man appears in front of you!"
					"It is a tall man with a wizard's hat.\n"
					"He approaches you and asks what brings you here. \n"
					"After telling him your quest, he offers some gear to"
					" you in aid.\n\n";
			Event magician("Magician", 25, gear.back());
			int i = rand() % magician.getVecSize();
			player.lootGear(magician.getLoot(i));

		}
		if (menu == find(game.begin(), game.end(), "goblins"))
		{
			Enemy goblins("Goblins", 75, 10);
			fight(player, goblins);
		}
		if (menu == find(game.begin(), game.end(), "deadknight"))
		{
			cout
			<< "Just over the horizon, you begin to see the castle.\n"
				"Continuing on, you begin to come near the long "
				"narrow stone walkway That leads to the entrance of "
				"the castle.\n Just before the bridge lies a fallen knight."
				"You pay your respects however, you cannot take on the dragon\n"
				"with the gear you currently have.\n\n";
			int i = rand() % 5;
			Gear newgear = gear[1][i];
			player.lootGear(newgear);
			cout << "Upon removing his armor, you find a healing potion.\n";
			player.heal(50);

		}
		if (menu == find(game.begin(), game.end(), "hauntedforest"))
		{
			cout << "You manage to escape into the woods and hear evil witch\n"
					"laughs further along the path. You continue along the\n"
					"path but the forest has put a spell on you!.\n"
					"You have lost 6% of your current health.\n\n";
			player.takeDamage(player.getHealth() * .06);
		}
		if (menu == find(game.begin(), game.end(), "witch"))
		{
			cout << "The witch is taken back by a visitor! She tries rushing\n"
					"inside, but you already have her in your reach.\n"
					"'Oh fine! I'll deal with you!' she cackles.\n\n";
			Enemy witch("Witch", 65, 26);
			fight(player, witch);
		}
		if (menu == find(game.begin(), game.end(), "potion"))
		{
			cout
			<< "You discover a book next to the vial that is badly beaten up.\n"
					"You manage to make out the word 'Health' \n"
					"and assume she must be making health potions!\n"
					"You take one.\n\n";
			player.heal(50);
		}
		if (menu == find(game.begin(), game.end(), "dragon"))
		{
			cout
			<<"Once in the castle, the dragon immediately turns towards you\n"
				"Wasting no time, he breathes fire directly at you causing you"
				"severe burns.\n" "Angry, you climb the spiral stairs and jump"
				"on it's back.\n" "The fight has begun!\n\n";
			Enemy dragon("Dragon", 300, 30);
			fight(player,dragon);

		}
	}

} // end of while loop for game != end

template<class Type1, class Type2>
void fight(Type1 & player, Type2 & enemy)
{
	//pattacks = number of player attacks (used for loop)
	//eattacks = number of enemy attacks (always 1 for this particular game)
	int pattacks, eattacks;
	eattacks = 1;
	if (player.getFollowers() > 0)
		pattacks = player.getFollowers() + 1;
	else
		pattacks = 1;
	cout << setw(40) << "Fight!" << endl;
	cout << "========================================"
			"========================================" << endl;
	cout << setw(3) << left << "||" << setw(14) << "Player " << "||" << setw(12)
			<< "Health" << "||" << setw(10) << right << "||" << setw(14) << left
			<< "Enemy" << "||" << setw(6) << "Health" << "||" << endl;
	cout << "========================================"
			"========================================" << endl;
	cout << "||" << setw(15) << player.getName() << "||" << setw(12)
			<< player.getHealth() << "||" << setw(8) << "" << "||" << setw(14)
			<< enemy.getName() << "||" << setw(6) << enemy.getHealth() << "||"
			<< endl;
	while (player.getHealth() > 0 && enemy.getHealth() > 0)
	{
		//player attacks first
		for (int i = 0; i < pattacks; i++)
		{
			/*cout << setw(15) << player.getName()<< "||"
			 << setw(10)<< player.getHealth() << "||"
			 << setw(10)<< "" << "||"; */
			player.attack(enemy);
		}
		//then enemy
		for (int j = 0; j < eattacks; j++)
		{
			/*cout << setw(14) << enemy.getName() << "||"
			 << setw(6) << enemy.getHealth() << "||"
			 << endl;*/
			enemy.attack(player);
		}
		cout << "||" << setw(15) << player.getName() << "||" << setw(12)
				<< player.getHealth() << "||" << setw(8) << "" << "||"
				<< setw(14) << enemy.getName() << "||" << setw(6)
				<< enemy.getHealth() << "||" << endl;
	}
	cout << "========================================"
			"========================================" << endl;
}

vector<vector<Gear>> generateGear(void)
{
	//first vector for weapons
	vector<Gear> weapons { Gear("King's Mace", "mace", 25, 15, 95), Gear(
			"Steel Sword", "sword", 15, 0, 35), Gear("Knight's Sword", "sword",
			15, 5, 50), Gear("Curved Bow", "Bow", 25, 0, 150), Gear(
			"Thor's Hammer", "hammer", 30, 10, 135), Gear("Excalibur", "sword",
			35, 5, 150),

	};
	//second vector for armor
	vector<Gear> armor { Gear("Knight's Helmet", "helmet", 1, 10, 20), Gear(
			"Knight's Chestplate", "chestplate", 5, 20, 60), Gear(
			"Knight's Platelegs", "platelegs", 3, 15, 40), Gear(
			"Steadfast Boots", "boots", 0, 15, 30), Gear("Bandit Cape", "cape",
			5, 10, 30),

	};

	//create new vector to store the armor and weapons in one list
	vector<vector<Gear>> gear;
	//concatenate vectors onto our new vector gear
	gear.push_back(weapons);
	gear.push_back(armor);
	//armor is 2nd index, weapons is the 1st
	return gear;
}

vector<Menu> generateRoute(void)
{
	vector<Menu> game {
			Menu("mainroad",
					"The King has come to you asking for you to help save his"
					"daughter! \n""The journey is long and hard but he has"
					"great promises if you bring her back safe and sound!\n\n"
					""
					"You begin your journey just outside of the Kingdom and \n"
					"face a fork in the road. What will you choose?\n\n",
					std::vector<std::pair<string, string> > {
				{ "Go left", "spider" }, { "Go right", "troll" }, }),
//right path
			Menu("troll",
					"Trotting along to the right, you come across a bridge.\n"
					"A troll appears and dubs himself 'The Gate Keeper'.\n"
					"And announces the only way through the gate is him.\n\n",
					std::vector<std::pair<string, string> > {
						{"Fight the Troll", "trollfight" },
						{"Attempt to out-brain the Troll", "trick" }, }),
//player must fight troll then continues to shop.
			Menu("trollfight",
					"The troll swings his giant fist at you.\n"
					"As you dodge his fist, you manage to get some swipes"
					" with your sword in at him.\n"
					"As he falls to the ground, you notice a wooden chest.\n\n",
					std::vector<std::pair<string, string> > {
						{ "Loot it", "trolltreasure" },
						{ "Carry on with your journey", "shop" } }),
			Menu("trolltreasure",
					"With you're newfound weapon, you feel confident in"
					" your abilities.\n"
					"Beginning again on your journey, you head "
					"off on your path.\n"
					"As the path starts to straighten, you see a figure with a "
					"pointy hat heading your way.\n\n",
					std::vector<std::pair<string, string> > {
						{"Hide in the woods and let them pass","hidefromshop" },
						{ "Approach the figure.", "shop" } }),
			Menu("hidefromshop",
					"You sneak away into the forest and let the figure pass.\n"
					"Until you notice some bandits about to sneak up on him.\n"
					"You spring into action and help the man!\n\n",
					std::vector<std::pair<string, string> > {
						{ "Help him!", "bandits" }, }),
//after tricking the troll, player goes to shop
			Menu("trick",
					"'Aye, if there is only one way through, then what if I "
					"were Bill Gates?' You say.\n"
					"'Well then you would have to go through me!' "
					"The troll responds.\n"
					"'But he only uses windows!' You retort.\n"
					"The troll, angry, cannot combat your logic and "
					"lets you pass.\n\n",
					std::vector<std::pair<string, string> > {
						{"Continue your quest.", "shop" }, }),
			Menu("shop",
					"Just after finishing up with the merchant, "
					"you notice a ruffle in the grass\n"
					"Two squirrelly bandits jump out!\n"
					"'We were trying to rob your friend but you'll do too!'"
					" They exclaim.\n\n",
					std::vector<std::pair<string, string> > {
						{"Fight the Bandits!", "bandits" }, }),
			Menu("bandits",
					"The bandits lay motionless as you sheathe your weapon.\n"
					"Bruised and tired, you carry forward with your quest\n"
					"Laying just off the path, you see a knight "
					"resting on a log.\n"
					"After talking to him, he tells you he has just failed"
					" to save his King's daughter\n"
					"trapped in another castle and is afraid to return home"
					" to his King.\n\n",
					std::vector<std::pair<string, string> > {
						{ "Ask him to join you", "wanderingknight" },
						{"Wish him luck and continue on your way.",
								"deadknight" } }),
			Menu("wanderingknight",
					"You try convincing him to help you in your journey by "
					"telling\n him all the promises your King has given you.\n"
					"He agrees, grabs his sword and follows alongside you.\n\n",
					std::vector<std::pair<string, string> > {
						{"Continue your quest.", "deadknight" }, }),
//left path
			Menu("spider",
					"You travel down the road, about only 100 metres and you "
					"encounter\n""a giant spider flaring it's fangs at you.\n"
					"You look down at your feet and they're stuck in the web!\n"
					"What on earth will you do?\n\n",
					std::vector<std::pair<string, string> > {
						{"Fight the spider off!", "spiderattack" },
						{ "Attempt to free yourself and run!",
									"hauntedforest" }, }),
//fight spider
			Menu("spiderattack",
					"Trying to catch you're breath, you notice two other "
					"adventurers\n""stuck in it's web."
					"They yell for help but you sense danger nearby.\n\n",
					std::vector<std::pair<string, string> > {
						{ "Help the stranded adventurers.", "adventurers" },
						{ "Flee the area and leave the adventurers",
								"fleeweb"},}),
//flee or help adventures caught in web, user ends up at magician either way
			Menu("adventurers",
					"After helping them down, they ask you why you're here.\n"
					"They thank you for saving their lives and insist on "
					"joining you on your quest.\n\n"
					"+2 Followers!\n\n"
					"Continuing your path you notice something"
					" strange moving ahead.\n\n",
					std::vector<std::pair<string, string> > {
						{ "Investigate..", "magician" }, }),
			Menu("fleeweb",
					"You slash through the web as you try to make it out.\n"
					"As you're nearing the end, you notice something"
					" moving in the distance.\n\n",
					std::vector<std::pair<string, string> > {
						{ "Investigate..", "magician" },
						{ "Flee the area..", "hauntedforest" } }),
//magician gives gear to gear up for goblins
			Menu("magician",
					"Continuing your route, your eyes fixate on the castle"
					" just over the horizon.\n"
					"Two snarling, green goblins ambush you from the bushes!\n"
					"Your only option is to fight!\n\n",
					std::vector<std::pair<string, string> > {
						{ "Fight!","goblins" }, }),
//last fight for middle path
			Menu("goblins", "The goblins were no match for your new gear.\n",
					std::vector<std::pair<string, string> > {
						{"Continue your journey.", "deadknight" }, }),
//escape spider
			Menu("hauntedforest",
					"Up ahead, you see the witch outside her house"
					" brewing a potion. \n"
					"She seems busy, perhaps you could sneak up "
					"on her and take her out!\n",
					std::vector<std::pair<string, string> > {
						{"Sneak up on the witch", "witch" },
						{"Sneak by the witch", "deadknight" } }),
//sneak up on witch
			Menu("witch",
					"After defeating the witch, you realize she has left her\n"
							"door to her house wide open.\n",
					std::vector<std::pair<string, string> > {
						{"Take a look around", "witchshouse" },
						{"Leave and continue on your journey","deadknight" },}),
//look around witch's house
			Menu("witchshouse",
					"After defeating the witch, you aren't able to tell"
					" what potion\n"
					"she was creating. Although you see an empty vial "
					"next to her cauldron.\n\n",
					std::vector<std::pair<string, string> > {
						{ "Fill Vial", "potion" },
						{ "Leave House", "deadknight" } }),
//fill vial
			Menu("potion",
					"There doesn't seem to be anything else of interest.",
					std::vector<std::pair<string, string> > { { "Leave House",
							"deadknight" }, }),
//Every path meets up here and then follows same route
			Menu("deadknight",
					"You respectfully remove some armor and put it on.\n"
							"You feel ready to take on the dragon.\n",
					std::vector<std::pair<string, string> > {
						{ "Forge onwards", "dragon" } }),
			Menu("dragon", "The dragon goes limp and moves no more..\n"
					"You have slain the dragon.\n"
					"Now the only thing left is to bring the princess home.\n"
					"You climb the spiral staircase up to her room.\n\n",
					std::vector<std::pair<string, string> > {
						{ "Climb the stairs to the Princess", "princess" } }),
			Menu("princess",
				"The princess thanks you and tells you she had been locked\n"
				"in that room for nearly 9 days. She is eager to go back home\n"
					"to her Kingdom and see her father. "
					"You oblige and head on your way.\n",
					std::vector<std::pair<string, string> > {
						{"Back to the Kingdom", "kingdom" } }),

			Menu("kingdom",
		"Upon arriving at the Kingdom, you are welcomed with showers\n"
			"of flower petals and all the food you can eat. The King\n"
			"thanks you and is eager to take you to his Castle.\n"
			"Once in the castle, he directs you to the throne.\n"
			"Once again thanking you, he removes his crown and sets it\n"
		"near you. He turns to face the empty ballroom and begins laughing\n"
			"Confused, you ask what he's laughing at. He replies, 'you'.\n"
		"Once again confused, you ask him what he means. Dying of laughter,\n"
			"he manages to get out the words, 'It was just a prank.'\n"
			"'It was a prank!' he screams. 'You should've seen your face\n"
			"when you saw that dragon!!' he yells while laughing. \n"
			"'What do you mean?' you reply. He then goes on to explain\n"
			"how it was all setup so him and his friends could follow you\n"
		"and watch from afar. Outraged, you tell him about the dead knight\n"
			"just before the castle entrance. 'Oh yeah that part we did not\n"
			"plan, however since you did actually complete the quest,\n"
			"I am granting you the ability to sit in my throne whenever\n"
			"you please.' Unamused, you still accept the offer and \n"
			"proceed to sit down and rest. \n\n"
			"The End.\n\n",
			std::vector<std::pair<string, string> > {}), };
	return game;
}
