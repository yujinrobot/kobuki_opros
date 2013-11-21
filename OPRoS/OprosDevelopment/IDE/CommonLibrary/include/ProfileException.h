/*
 *  OPRoS Component Engine (OCE)
 *  Copyright (c) 2008 ETRI. http://www.etri.re.kr.
 *  Distributed under the OPRoS License, Version 1.0.
 *
 *  @Created : 2008. 11. 25
 *  @Author  : sby (sby@etri.re.kr)
 *
 *  @File    : ProfileException.h
 *
 *
 */

#ifndef PROFILE_EXECPTION_H
#define PROFILE_EXECPTION_H

#include <string>

class ProfileException {
private:
	std::string m_message;


public:
	ProfileException(const std::string &message)
	{
		m_message = message;
	}
	inline std::string &getMessage()
	{
		return m_message;
	}

	virtual ~ProfileException(){};
};

#endif /* PROFILE_EXECPTION_H*/
