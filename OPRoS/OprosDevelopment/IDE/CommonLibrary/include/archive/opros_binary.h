/*
 * OPRoS Component Engine (OCE)
 * Copyright (c) 2008 ETRI. http://www.etri.re.kr.
 * Distributed under the OPRoS License, Version 1.0.
 *
 *  @Created : 2010. 8. 11
 *  @Author  : sby (sby@etri.re.kr)
 *
 *  @File    : opros_binary.h
 *
 *
 *
 *  pseudo RTTI
 */

#ifndef _OPROS_BINARY_H
#define _OPROS_BINARY_H

namespace opros {

class binary
{
protected:
	char *m_data;
	unsigned long m_size;

public:

	binary()
	{
		m_data = NULL;
		m_size = 0;
	}

	virtual ~binary()
	{
		if (m_data) delete m_data;	
	}

	virtual void resize(unsigned long size)
	{
		if (m_data != NULL) delete m_data;

		m_data = new char[size];
		m_size = size;
	}

	virtual char *data()
	{
		return m_data;
	}

	virtual unsigned long size()
	{
		return m_size;
	}
};

} // namespace opros

#endif // _OPROS_BINARY_H
