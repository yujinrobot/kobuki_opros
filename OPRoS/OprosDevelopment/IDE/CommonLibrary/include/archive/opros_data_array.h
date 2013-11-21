/*
 * OPRoS Component Engine (OCE)
 * Copyright (c) 2008 ETRI. http://www.etri.re.kr.
 * Distributed under the OPRoS License, Version 1.0.
 *
 *  @Created : 2010. 8. 11
 *  @Author  : sby (sby@etri.re.kr)
 *
 *  @File    : opros_data_array.h
 *
 *
 *
 *  Archive class for serialization support
 */

#ifndef _OPROS_DATA_ARRAY_H
#define _OPROS_DATA_ARRAY_H


namespace opros {
	
template <typename T>
class data_array{
protected:
	T *m_data;
	unsigned long m_sz;

public:
	data_array()
	{
		m_data = NULL;
		m_sz = 0;
	}

	data_array(T *p, unsigned long sz)
	{
		m_data = p;
		m_sz = sz;
	}

	virtual ~data_array(){}

	T *data() { return m_data;}
	unsigned long size() { return m_sz;}
	void resize(unsigned long sz)
	{
		if (m_data != NULL) delete m_data;

		m_data = new T[sz];
		m_sz = sz;
	}

	void reset(T *p, unsigned long sz)
	{
		if (m_data != NULL) delete m_data;
		m_data = p;
		m_sz = sz;
	}
};

} // namespace opros

template <typename T>
opros::data_array<T> opros_data_array(T *p, unsigned long sz)
{
	return opros::data_array<T>(p,sz);
}

#endif // _OPROS_DATA_ARRAY_H
