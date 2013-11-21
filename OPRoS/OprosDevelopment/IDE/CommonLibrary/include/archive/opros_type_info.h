/*
 * OPRoS Component Engine (OCE)
 * Copyright (c) 2008 ETRI. http://www.etri.re.kr.
 * Distributed under the OPRoS License, Version 1.0.
 *
 *  @Created : 2010. 8. 11
 *  @Author  : sby (sby@etri.re.kr)
 *
 *  @File    : opros_type_info.h
 *
 *
 *
 *  pseudo RTTI
 */

#ifndef _OPROS_TYPE_INFO_H
#define _OPROS_TYPE_INFO_H
#include <vector>
#include <deque>
#include <queue>
#include <list>
#include <valarray>
#include <stack>
#include <set>
#include <map>
#include <complex>
#include <archive/opros_type_traits.h>

inline std::string typeName(bool *p)
{
	return "bool";
}

inline std::string typeName(short *p)
{
	return "short";
}

inline std::string typeName(unsigned short *p)
{
	return "unsigned short";
}

inline std::string typeName(int *p)
{
	return "int";
}

inline std::string typeName(unsigned int *p)
{
	return "unsigned int";
}

inline std::string typeName(long *p)
{
	return "long";
}


inline std::string typeName(unsigned long *p)
{
	return "unsigned long";
}

inline std::string typeName(float *p)
{
	return "float";
}

inline std::string typeName(double *p)
{
	return "double";
}

inline std::string typeName(long long *p)
{
	return "long long";
}

inline std::string typeName(long double *p)
{
	return "long double";
}

inline std::string typeName(char *p)
{
	return "char";
}

inline std::string typeName(wchar_t *p)
{
	return "w_char_t";
}

inline std::string typeName(signed char *p)
{
	return "signed char";
}

inline std::string typeName(unsigned char *p)
{
	return "unsigned char";
}

inline std::string typeName(std::string *p)
{
	return "std::string";
}


template <typename T1,typename T2, typename T3, typename T4, typename T5,template<typename,typename,typename,typename,typename> class C>
std::string typeName( C<T1,T2, T3,T4,T5> *p)
{
}

template <typename T1,typename T2, typename T3, typename T4,template<typename,typename,typename,typename> class C>
std::string typeName( C<T1,T2, T3,T4> *p)
{
}

template <typename T1,typename T2, typename T3, template<typename,typename,typename> class C>
std::string typeName( C<T1,T2, T3> *p)
{
}

template <typename T1,typename T2, template<typename,typename> class C>
std::string typeName( C<T1,T2> *p)
{
}

template <typename T, template<typename> class C>
std::string typeName( C<T> *p)
{
}


template <typename T>
std::string typeName( std::vector<T> *p)
{
	T *pp = NULL;

	return std::string("std::vector<").append(getTypeName(pp)).append(">");	
}

template <typename T>
std::string typeName( std::deque<T> *p)
{
	T *pp = NULL;

	return std::string("std::deque<").append(getTypeName(pp)).append(">");	
}

template <typename T>
std::string typeName( std::list<T> *p)
{
	T *pp = NULL;

	return std::string("std::list<").append(getTypeName(pp)).append(">");	
}

template <typename T>
std::string typeName( std::queue<T> *p)
{
	T *pp = NULL;

	return std::string("std::queue<").append(getTypeName(pp)).append(">");	
}

template <typename T>
std::string typeName( std::priority_queue<T> *p)
{
	T *pp = NULL;

	return std::string("std::priority_queue<").append(getTypeName(pp)).append(">");	
}

template <typename T>
std::string typeName( std::stack<T> *p)
{
	T *pp = NULL;

	return std::string("std::stack<").append(getTypeName(pp)).append(">");	
}


template <typename T>
std::string typeName( std::set<T> *p)
{
	T *pp = NULL;

	return std::string("std::set<").append(getTypeName(pp)).append(">");	
}


template <typename T>
std::string typeName( std::multiset<T> *p)
{
	T *pp = NULL;

	return std::string("std::multiset<").append(getTypeName(pp)).append(">");	
}

template <typename T>
std::string typeName( std::complex<T> *p)
{
	T *pp = NULL;

	return std::string("std::complex<").append(getTypeName(pp)).append(">");
}

template <typename T>
std::string typeName( std::valarray<T> *p)
{
	T *pp = NULL;

	return std::string("std::valarray<").append(getTypeName(pp)).append(">");
}


template <typename T1, typename T2>
std::string typeName( std::map<T1,T2> *p)
{
	T1 *pp1 = NULL;
	T2 *pp2 = NULL;

	return std::string("std::map<").append(getTypeName(pp1)).append(",").append(getTypeName(pp2)).append(">");
}

template <typename T1, typename T2>
std::string typeName( std::multimap<T1,T2> *p)
{
	T1 *pp1 = NULL;
	T2 *pp2 = NULL;

	return std::string("std::multimap<").append(getTypeName(pp1)).append(",").append(getTypeName(pp2)).append(">");
}



template <typename T>
std::string typeName(T *p)
{
}

template <typename T>
std::string typeName(T **p)
{
	T *p1 = NULL;

	return std::string(getTypeName(p1)).append("*");
}

#define DEFINE_CLASS_TYPE_NAME(a) \
	inline std::string typeName(##a *p) \
	{\
		return std::string(#a);\
	}

template <typename T,bool N>
class enumNameSelector
{
public:
	std::string typeString()
	{

	}
};

template <typename T>
class enumNameSelector<T,false>
{
public:
	std::string typeString()
	{
		T*p=NULL;
		return typeName(p);
	}
};

template <typename T>
class enumNameSelector<T,true>
{
public:
	std::string typeString()
	{
		return "Enum";
	}
};

template <typename T>
std::string getTypeName(T *p)
{
	enumNameSelector<T,opros::is_enum<T>::value> x;

	return x.typeString();
}


#endif // _OPROS_TYPE_INFO_H
