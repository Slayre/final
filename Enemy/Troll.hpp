/*
 * Troll.hpp
 *
 *  Created on: Nov 7, 2018
 *      Author: Cole-LENOVO
 */

#ifndef ENEMY_TROLL_HPP_
#define ENEMY_TROLL_HPP_
#include "Enemy.hpp"

class Troll : public Enemy
{

public:
	Troll();
	~Troll(){};
	int getHealth(void){return this->health;};
	void takeDamage(int damage){health -= damage; cout << name<< " : " << health <<endl;};

	template<class Player>
	void attack(Player & player){player.takeDamage(damage);};
};




#endif /* ENEMY_Troll_HPP_ */
