/*
 * Exception.hpp
 *
 *  Created on: Nov 27, 2018
 *      Author: d294m567
 *
 *      Namespace: My_Exception
 *      Class: My_exception
 *      	custom exception object, only used to throw if the player has died.
 *
 *
 *
 */

#include <exception>
#include <iostream>

#ifndef GAMEHANDLING_EXCEPTION_HPP_
#define GAMEHANDLING_EXCEPTION_HPP_


namespace My_Exception
{
	class My_exception : public exception
	{
	public:
		My_exception(){};
		~My_exception(){};
	};
}


#endif /* GAMEHANDLING_EXCEPTION_HPP_ */
