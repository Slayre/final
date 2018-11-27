/*
 * Spider.hpp
 *
 *  Created on: Nov 7, 2018
 *      Author: Cole-LENOVO
 */

#ifndef ENEMY_SPIDER_HPP_
#define ENEMY_SPIDER_HPP_
#include "Enemy.hpp"

class Spider : public Enemy
{

public:
	Spider();
	~Spider(){};
	int getHealth(void){return this->health;};
	void takeDamage(int damage){health -= damage;};
	template<class Player>
	void attack(Player & player){player.takeDamage(damage);};
};




#endif /* ENEMY_SPIDER_HPP_ */
