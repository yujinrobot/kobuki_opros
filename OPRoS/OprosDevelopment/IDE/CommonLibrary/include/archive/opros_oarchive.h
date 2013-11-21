/*
 * OPRoS Component Engine (OCE)
 * Copyright (c) 2008 ETRI. http://www.etri.re.kr.
 * Distributed under the OPRoS License, Version 1.0.
 *
 *  @Created : 2010. 8. 11
 *  @Author  : sby (sby@etri.re.kr)
 *
 *  @File    : opros_oarchive.h
 *
 *
 *
 *  OPROS output archive definition
 */

#ifndef _OPROS_OARHIVE_H
#define _OPROS_OARHIVE_H


#include <iostream>
#include "opros_archive_common.h"
#include "opros_type_info.h"
#include "opros_type_traits.h"
#include "opros_access.h"


namespace opros {
	namespace archive {


class oarchive : public archive {

protected:
	virtual oarchive& write_class_head(const std::string &name)=0;
	virtual oarchive& write_class_end(const std::string &name)=0;
	virtual oarchive& write_array_head(long sz, char code, char bsz ) = 0;
	virtual oarchive& write_array_end(long sz, char code, char bsz ) = 0;
	
public:	
	virtual oarchive& write_start_tag(const std::string &name)=0;
	virtual oarchive& write_end_tag(const std::string &name)=0;

public:	
	virtual ~oarchive() {};

	virtual oarchive& save(bool val)=0;

	virtual oarchive& save(short val)=0;
	virtual oarchive& save(unsigned short val)=0;

	virtual oarchive& save(int val)=0;
	virtual oarchive& save(unsigned int val)=0;

	virtual oarchive& save(long val)=0;
	virtual oarchive& save(unsigned long val)=0;

	virtual oarchive& save(long long val)=0;
	virtual oarchive& save(unsigned long long val)=0;
	
	virtual oarchive& save(float val)=0;
	virtual oarchive& save(double val)=0;
	virtual oarchive& save(long double val)=0;

	virtual oarchive& save(char val)=0;
	virtual oarchive& save(unsigned char val)=0;

	virtual oarchive& save(wchar_t val)=0;

	virtual oarchive& save_binary(char *p, const long sz) = 0;

protected:
	virtual oarchive& save_array(bool *p, const long sz)=0;

	virtual oarchive& save_array(char *p, const long sz)=0;
	virtual oarchive& save_array(unsigned char *p, const long sz)=0;

	virtual oarchive& save_array(wchar_t *p, const long sz)=0;

	virtual oarchive& save_array(short *p, const long sz)=0;
	virtual oarchive& save_array(unsigned short *p, const long sz)=0;

	virtual oarchive& save_array(int *p, const long sz)=0;
	virtual oarchive& save_array(unsigned int *p, const long sz)=0;

	virtual oarchive& save_array(long *p, const long sz)=0;
	virtual oarchive& save_array(unsigned long *p, const long sz)=0;
	
	virtual oarchive& save_array(float *p, const long sz)=0;
	virtual oarchive& save_array(double *p, const long sz)=0;
	virtual oarchive& save_array(long double *p, const long sz)=0;

	virtual oarchive& save_array(long long *p, const long sz)=0;
	virtual oarchive& save_array(unsigned long long *p, const long sz)=0;

	template <typename T>
	oarchive &save_array(T *x, const long sz)
	{
		write_array_head( sz, type_code(x), (char) sizeof(T));
		
		for (long i=0;i<sz;i++) *this << x[i];

		write_array_end(sz, type_code(x), (char) sizeof(T));

		return (*this);
	}

public:

	template <typename T>
	oarchive& save(opros::nvp<T> &t)
	{
		write_start_tag(t.getName());

		(*this) << t.getData();

		write_end_tag(t.getName());

		return (*this);
	}


	template <typename T>
	oarchive& save(T &t)
	{		
		T *tt=0;

		write_class_head(getTypeName(tt));

		save_class(*this, t);

		write_class_end(getTypeName(tt));

		return (*this);
	}	

	
	template <typename T, size_t N>
	oarchive &save(T (&x)[N])
	{
		typename opros::remove_const<T>::type * tt= (typename opros::remove_const<T>::type *)&x[0];

		save(tt,N);

		return (*this);
	}


	template <typename T>
	oarchive &save(T *x, const long sz)
	{
		typename opros::remove_const<T>::type *tx = (typename opros::remove_const<T>::type *)x;
		
		return save_array(tx, sz);		
	}


};


template <bool n, typename T>
class pointer_save{
public:
	virtual oarchive &save(oarchive &ar, T &x){return ar;}
};

template <typename T>
class pointer_save<false, T>{
public:
	virtual oarchive &save(oarchive &ar, T &x){return ar;}
};

template <typename T>
class pointer_save<true, T *>{
public:
	virtual oarchive &save(oarchive &ar, T *&x)
	{
		ar.save(x);
		return ar;
	}
};


template <bool n, typename T>
class enum_save{
public:
	virtual oarchive &save(oarchive &ar, T &x){return ar;}
};

template <typename T>
class enum_save<true, T>{
public:
	virtual oarchive &save(oarchive &ar, T &x)
	{
		ar.save((int)x);
		return ar;
	}
};

template <typename T>
class enum_save<false, T>{
public:
	virtual oarchive &save(oarchive &ar, T &x)
	{		
		return ar;
	}
};

template <bool n, typename T>
class general_save
{
public:
	virtual oarchive &save(oarchive &ar, T &x)
	{
		return ar;
	}
};

template <typename T>
class general_save<true, T>
{
public:
	virtual oarchive &save(oarchive &ar, T &x)
	{
		return ar;
	}
};

template <typename T>
class general_save<false, T>
{
public:
	virtual oarchive &save(oarchive &ar, T &x)
	{
		ar.save(x);
		return ar;
	}
};

template <typename T>
class save_selector
{
public:
	virtual oarchive &save(oarchive &ar, T &x)
	{
		if (opros::is_enum<T>::value)
		{
			enum_save<opros::is_enum<T>::value, T> saver;
			saver.save(ar, x);
		}
		else 
		if (opros::is_pointer<T>::value)
		{
			pointer_save<opros::is_pointer<T>::value, T> saver;
			saver.save(ar, x);
		}
		else		
		{
			general_save< opros::is_enum<T>::value | opros::is_pointer<T>::value, typename opros::remove_const<T>::type> saver;
			saver.save(ar, (typename opros::remove_const<T>::type &)x);
		}

		return ar;
	}

};

template <bool n, typename T>
class save_class_selector
{
public:
	virtual oarchive &save(oarchive &ar, T &x);
};


template <typename T>
class save_class_selector<true, T>
{
public:
	virtual oarchive &save(oarchive &ar, T &t)
	{
		opros::archive::access::save(ar,t);
		return ar;
	}
};

template <typename T>
class save_class_selector<false, T>
{
public:
	virtual oarchive &save(oarchive &ar, T &t)
	{
		save_this(ar, t);
		return ar;
	}
};

	} // namespace archive 
} // namespace opros

opros::archive::oarchive &operator<<(opros::archive::oarchive &ar, char val);

opros::archive::oarchive &operator<<(opros::archive::oarchive &ar, unsigned char val);

opros::archive::oarchive &operator<<(opros::archive::oarchive &ar, bool val);

opros::archive::oarchive &operator<<(opros::archive::oarchive &ar, short val);

opros::archive::oarchive &operator<<(opros::archive::oarchive &ar, unsigned short val);

opros::archive::oarchive &operator<<(opros::archive::oarchive &ar, int val);

opros::archive::oarchive &operator<<(opros::archive::oarchive &ar, unsigned int val);

opros::archive::oarchive &operator<<(opros::archive::oarchive &ar, long val);

opros::archive::oarchive &operator<<(opros::archive::oarchive &ar, unsigned long val);

opros::archive::oarchive &operator<<(opros::archive::oarchive &ar, float val);

opros::archive::oarchive &operator<<(opros::archive::oarchive &ar, double val);

opros::archive::oarchive &operator<<(opros::archive::oarchive &ar, long double val);

opros::archive::oarchive &operator<<(opros::archive::oarchive &ar, long long val);

opros::archive::oarchive &operator<<(opros::archive::oarchive &ar, wchar_t val);


template <typename T>
opros::archive::oarchive &operator<<(opros::archive::oarchive &ar, T &val)
{
	opros::archive::save_selector<T> saver;

	saver.save(ar, val);
	
	return ar;
}


template <typename T>
void save_class(opros::archive::oarchive &ar, T &t)
{
	opros::archive::save_class_selector<has_opros_serialization<T>::value, T> saver;

	saver.save(ar, t);
}


template <typename T>
opros::archive::oarchive &operator&(opros::archive::oarchive &ar, T &val)
{
	return ar << val;
}


#endif // _OPROS_OARHIVE_H
