/*
 * Exception.hpp
 *
 *  Created on: Nov 27, 2018
 *      Author: d294m567
 */

#include <exception>
#include <iostream>
using namespace std;

#ifndef GAMEHANDLING_EXCEPTION_HPP_
#define GAMEHANDLING_EXCEPTION_HPP_


class My_exception : public exception
{
	string message;
public:
	My_exception()
	{
		message = "Your Player has died! ";
	}
	string what()
	{
		return message;
	}

};


#endif /* GAMEHANDLING_EXCEPTION_HPP_ */
