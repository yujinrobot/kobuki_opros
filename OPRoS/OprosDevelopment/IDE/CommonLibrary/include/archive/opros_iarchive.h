/*
 * OPRoS Component Engine (OCE)
 * Copyright (c) 2008 ETRI. http://www.etri.re.kr.
 * Distributed under the OPRoS License, Version 1.0.
 *
 *  @Created : 2010. 8. 11
 *  @Author  : sby (sby@etri.re.kr)
 *
 *  @File    : opros_iarchive.h
 *
 *
 *
 *  Archive class for serialization support
 */

#ifndef _OPROS_IARHIVE_H
#define _OPROS_IARHIVE_H

#include <iostream>
#include "opros_archive_common.h"
#include "opros_type_info.h"
#include "opros_type_traits.h"
#include "opros_access.h"



namespace opros {
	namespace archive {


class iarchive : public archive  {	

protected:
	virtual iarchive& read_class_head(const std::string &name)=0;
	virtual iarchive& read_class_end(const std::string &name)=0;
	virtual iarchive& read_array_head(long &sz,char &code, char &bsz) = 0;
	virtual iarchive& read_array_end(long &sz,char &code, char &bsz) = 0;

public:
	virtual iarchive& read_start_tag(std::string &name)=0;
	virtual iarchive& read_end_tag(std::string &name)=0;	

public:	
	virtual ~iarchive() {};


	virtual iarchive& load(bool &val)=0;

	virtual iarchive& load(short &val)=0;
	virtual iarchive& load(unsigned short &val)=0;

	virtual iarchive& load(int &val)=0;
	virtual iarchive& load(unsigned int &val)=0;

	virtual iarchive& load(long &val)=0;
	virtual iarchive& load(unsigned long &val)=0;

	virtual iarchive& load(long long &val)=0;
	virtual iarchive& load(unsigned long long &val)=0;

	virtual iarchive& load(float &val)=0;
	virtual iarchive& load(double &val)=0;
	virtual iarchive& load(long double &val)=0;

	virtual iarchive& load(char &val)=0;
	virtual iarchive& load(unsigned char &val)=0;

	virtual iarchive& load(wchar_t &val)=0;

	virtual iarchive& load_binary(char **p, long &sz) = 0;

protected:
	virtual iarchive& load_array(bool **s, long &sz)=0;

	virtual iarchive& load_array(char **s, long &sz)=0;
	virtual iarchive& load_array(unsigned char **s, long &sz)=0;

	virtual iarchive& load_array(wchar_t **s, long &sz)=0;

	virtual iarchive& load_array(short **s, long &sz)=0;
	virtual iarchive& load_array(unsigned short **s, long &sz)=0;

	virtual iarchive& load_array(int **s, long &sz)=0;
	virtual iarchive& load_array(unsigned int **s, long &sz)=0;

	virtual iarchive& load_array(long **s, long &sz)=0;
	virtual iarchive& load_array(unsigned long **s, long &sz)=0;
	
	virtual iarchive& load_array(float **s, long &sz)=0;
	virtual iarchive& load_array(double **s, long &sz)=0;
	virtual iarchive& load_array(long double **s, long &sz)=0;

	virtual iarchive& load_array(long long **s, long &sz)=0;
	virtual iarchive& load_array(unsigned long long **s, long &sz)=0;

	template <typename T>
	iarchive& load_array(T **x, long &sz)
	{
		char code = type_code((T *)(*x));
		char bsz=0;

		read_array_head(sz,code, bsz);
		if (*x == NULL) {
			*x = new T[sz];
			if (*x==NULL) throw archive_system_exception();
		}

		for (long i=0;i<sz;i++) *this >> (*x)[i];
		read_array_end(sz, code,bsz);

		return (*this);
	}

public:
	template <typename T>
	iarchive& load(const opros::nvp<T> &t)
	{
		opros::nvp<T> &p = (opros::nvp<T> &)t;
		
		read_start_tag(p.getName());

		(*this) >> p.getData();

		read_end_tag(p.getName());

		return (*this);
	}
	
	
	template <typename T>
	iarchive& load(T &t)
	{		
		T *tt=0;		

		read_class_head(getTypeName(tt));

		load_class(*this, t);

		read_class_end(getTypeName(tt));


		return (*this);
	}

	template <typename T, size_t N>
	iarchive& load( T(&x)[N])
	{
		T *tt = &x[0];
		long sz = N;

		load(&tt,sz);		

		return (*this);
	}

	/*
	** if val is not zero, can throw array_size_mismatch_exception
	*/
	template <typename T>
	iarchive& load( T **x, long &sz)	
	{
		return load_array(x,sz);
	}

	template <typename T>
	iarchive& load( T **x, const long &sz)	
	{
		long tsz = sz;

		return load(x,tsz);
	}

};



template <bool n, typename T>
class pointer_load{
public:
	virtual iarchive &load(iarchive &ar, T &x){return ar;}
};

template <typename T>
class pointer_load<false, T>{
public:
	virtual iarchive &load(iarchive &ar, T &x){return ar;}
};

template <typename T>
class pointer_load<true, T *>{
public:
	virtual iarchive &load(iarchive &ar, T *&x)
	{
		ar.load(x);
		return ar;
	}
};


template <bool n, typename T>
class enum_load{
public:
	virtual iarchive &load(iarchive &ar, T &x){return ar;}
};

template <typename T>
class enum_load<true, T>{
public:
	virtual iarchive &load(iarchive &ar, T &x)
	{
		int v;
		ar.load(v);
		x = (T)v;
		return ar;
	}
};

template <typename T>
class enum_load<false, T>{
public:
	virtual iarchive &load(iarchive &ar, T &x)
	{		
		return ar;
	}
};

template <bool n, typename T>
class general_load
{
public:
	virtual iarchive &load(iarchive &ar, T &x)
	{
		return ar;
	}
};

template <typename T>
class general_load<true, T>
{
public:
	virtual iarchive &load(iarchive &ar, T &x)
	{
		return ar;
	}
};

template <typename T>
class general_load<false, T>
{
public:
	virtual iarchive &load(iarchive &ar, T &x)
	{
		ar.load(x);
		return ar;
	}
};

template <typename T>
class load_selector
{
public:
	virtual iarchive &load(iarchive &ar, T &x)
	{
		if (opros::is_enum<T>::value)
		{
			enum_load<opros::is_enum<T>::value, T> loader;
			loader.load(ar, x);
		}
		else 
		if (opros::is_pointer<T>::value)
		{
			pointer_load<opros::is_pointer<T>::value, T> loader;
			loader.load(ar, x);
		}
		else		
		{
			general_load< opros::is_enum<T>::value | opros::is_pointer<T>::value, T> loader;
			loader.load(ar,x);
		}

		return ar;
	}

};

template <bool n, typename T>
class load_class_selector
{
public:
	virtual iarchive &load(iarchive &ar, T &x);
};


template <typename T>
class load_class_selector<true, T>
{
public:
	virtual iarchive &load(iarchive &ar, T &t)
	{
		opros::archive::access::load(ar,t);
		return ar;
	}
};

template <typename T>
class load_class_selector<false, T>
{
public:
	virtual iarchive &load(iarchive &ar, T &t)
	{
		load_this(ar, t);
		return ar;
	}
};





	} // namespace archive 
} // amespace opros


//opros::archive::iarchive &operator>>(opros::archive::iarchive &ar, char &val);
//
//opros::archive::iarchive &operator>>(opros::archive::iarchive &ar, unsigned char &val);
//
//opros::archive::iarchive &operator>>(opros::archive::iarchive &ar, bool &val);
//
//opros::archive::iarchive &operator>>(opros::archive::iarchive &ar, short &val);
//
//opros::archive::iarchive &operator>>(opros::archive::iarchive &ar, unsigned short &val);
//
//opros::archive::iarchive &operator>>(opros::archive::iarchive &ar, int &val);
//
//opros::archive::iarchive &operator>>(opros::archive::iarchive &ar, unsigned int &val);
//
//opros::archive::iarchive &operator>>(opros::archive::iarchive &ar, long &val);
//
//opros::archive::iarchive &operator>>(opros::archive::iarchive &ar, unsigned long &val);
//
//opros::archive::iarchive &operator>>(opros::archive::iarchive &ar, float &val);
//
//opros::archive::iarchive &operator>>(opros::archive::iarchive &ar, double &val);
//
//opros::archive::iarchive &operator>>(opros::archive::iarchive &ar, long double &val);


template <typename T>
opros::archive::iarchive &operator>>(opros::archive::iarchive &ar, T &val)
{
	opros::archive::load_selector<T> loader;

	loader.load(ar, val);
	return ar;
}

template <typename T>
void load_class(opros::archive::iarchive &ar, T &t)
{
	opros::archive::load_class_selector<has_opros_serialization<T>::value, T> loader;

	loader.load(ar,t);
}

template <typename T>
opros::archive::iarchive &operator&(opros::archive::iarchive &ar, T &val)
{
	return ar >> val;
}

#endif // _OPROS_IARHIVE_H
