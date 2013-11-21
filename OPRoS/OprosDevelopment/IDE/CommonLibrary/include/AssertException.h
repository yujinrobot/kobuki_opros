/*
 * AssertException.h
 *
 *  Created on: 2008. 9. 29
 *      Author: sby
 */

#ifndef ASSERTEXCEPTION_H_
#define ASSERTEXCEPTION_H_
#include <iostream>
/**
 * ArgumentNumberException is the exception class
 *  if the number of called arguments does not match the number of arguments required by the function or method,
 *  the system throws an ArgumentNumberException
 *
 */

class AssertException {
public:
	AssertException()
	{
	};

	virtual ~AssertException(){};

	inline void message()
	{
		std::cerr<<__FILE__<<":"<<__LINE__<<": assertion failed"<<std::endl;
	}
};

#endif /* ASSERTEXCEPTION_H_*/
