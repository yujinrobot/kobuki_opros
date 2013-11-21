/*
 *  OPRoS Component Engine (OCE)
 *  Copyright (c) 2008 ETRI. http://www.etri.re.kr.
 *  Distributed under the OPRoS License, Version 1.0.
 *
 *  @Created : 2008. 11. 25
 *  @Author  : sby (sby@etri.re.kr)
 *
 *  @File    : MethodInvokeException.h
 *
 *
 */

#ifndef METHODINVOKEEXCEPTION_H_
#define METHODINVOKEEXCEPTION_H_

#include <string>

class MethodInvokeException {
private:
	std::string m_message;


public:
	MethodInvokeException(const std::string &message)
	{
		m_message = message;
	}
	inline std::string &getMessage()
	{
		return m_message;
	}

	virtual ~MethodInvokeException(){};
};

#endif /* METHODINVOKEEXCEPTION_H_ */
