/*
 * Bandit.hpp
 *
 *  Created on: Nov 7, 2018
 *      Author: Cole-LENOVO
 */

#ifndef ENEMY_BANDIT_HPP_
#define ENEMY_BANDIT_HPP_
#include "Enemy.hpp"

class Bandit : public Enemy
{

public:
	Bandit();
	~Bandit();
	void attack();
};




#endif /* ENEMY_Bandit_HPP_ */
