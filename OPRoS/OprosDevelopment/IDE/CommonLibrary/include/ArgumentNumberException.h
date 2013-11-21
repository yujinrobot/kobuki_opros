/*
 * ArgumentNumberException.h
 *
 *  Created on: 2008. 9. 29
 *      Author: sby
 */

#ifndef ARGUMENTNUMBEREXCEPTION_H_
#define ARGUMENTNUMBEREXCEPTION_H_

/**
 * ArgumentNumberException is the exception class
 *  if the number of called arguments does not match the number of arguments required by the function or method,
 *  the system throws an ArgumentNumberException
 *
 */

class ArgumentNumberException {
private:
	int lines;
	int arity;
	std::string m_message;
public:
	ArgumentNumberException(int lines, int arity)
	{
		this->lines = lines;
		this->arity = arity;
	};

	virtual ~ArgumentNumberException(){};

	inline std::string &getMessage()			
	{
		std::stringstream sr;

		sr<<__FILE__<<":"<<lines<<":"<<"function requires "<<arity<<" arguments\n";

		m_message  = sr.str();

		return m_message;
	}
};


#endif /* ARGUMENTNUMBEREXCEPTION_H_ */
