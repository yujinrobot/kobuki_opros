/*
 * OPRoS Component Engine (OCE)
 * Copyright (c) 2008 ETRI. http://www.etri.re.kr.
 * Distributed under the OPRoS License, Version 1.0.
 *
 *  @Created : 2010. 8. 11
 *  @Author  : sby (sby@etri.re.kr)
 *
 *  @File    : opros_archive_stl.h
 *
 *
 *
 *  STL template archive class
 */

#ifndef _OPROS_OARHIVE_STL_H
#define _OPROS_OARHIVE_STL_H


#include "opros_oarchive.h"
#include <vector>
#include <deque>
#include <queue>
#include <list>
#include <valarray>
#include <stack>
#include <set>
#include <map>
#include <complex>

//
//  std::vector
//

template <typename  T>
void save_this(opros::archive::oarchive &ar, std::vector<T> &t)
{
	int size = t.size();

	ar << OPROS_SERIALIZATION_NVP(size);

	typename std::vector<T>::iterator it = t.begin();

	for (;it != t.end(); it++)
	{
		T temp = *it;
		ar << OPROS_SERIALIZATION_MAKE_NVP(value, temp);
	}

}


//
//  std::deque
//

template <typename T>
void save_this(opros::archive::oarchive &ar, std::deque<T> &t)
{
	int size = t.size();

	ar << OPROS_SERIALIZATION_NVP(size);

	typename std::deque<T>::iterator it = t.begin();

	for (;it != t.end(); it++)
	{
		T temp = *it;
		ar << OPROS_SERIALIZATION_MAKE_NVP(value,temp);
	}
}

//
//  std::list
//

template <typename T>
void save_this(opros::archive::oarchive &ar, std::list<T> &t)
{
	int size = t.size();

	ar << OPROS_SERIALIZATION_NVP(size);

	typename std::list<T>::iterator it = t.begin();

	for (;it != t.end(); it++)
	{
		T temp = *it;
		ar << OPROS_SERIALIZATION_MAKE_NVP(value,temp);
	}
}

//
//  std::valarray
//



template <typename T>
void save_this(opros::archive::oarchive &ar, std::valarray<T> &t)
{
	int size = t.size();

	ar << OPROS_SERIALIZATION_NVP(size);

	int x;

	for (x=0;x<size;x++)
	{
		ar << OPROS_SERIALIZATION_MAKE_NVP(value,(T&)t[x]);
	}
}


//
//  std::stack
//


template <typename T>
void save_this(opros::archive::oarchive &ar, std::stack<T> &t)
{
	int size = t.size();

	ar << OPROS_SERIALIZATION_NVP(size);

	int x;

	std::stack<T> temp = t;

	for (x=0;x<size;x++)
	{
		T tempItem = temp.top();
		temp.pop();
		ar << OPROS_SERIALIZATION_MAKE_NVP(value,tempItem);
	}
}


//
//  std::set
//  
//  ToDo: sorting problem is remained in due to key_compare of set class 
// 


template <typename T>
void save_this(opros::archive::oarchive &ar, std::set<T> &t)
{
	int size = t.size();

	ar << OPROS_SERIALIZATION_NVP(size);

	typename std::set<T>::iterator it = t.begin();

	for (;it != t.end(); it++)
	{
		ar << OPROS_SERIALIZATION_MAKE_NVP(value,(T&)*it);
	}
}


//
//  std::multiset
//  
// ToDo: sorting problem is remained in due to key_compare of set class 
// 


template <typename T>
void save_this(opros::archive::oarchive &ar, std::multiset<T> &t)
{
	int size = t.size();

	ar << OPROS_SERIALIZATION_NVP(size);

	typename std::multiset<T>::iterator it = t.begin();

	for (;it != t.end(); it++)
	{
		ar << OPROS_SERIALIZATION_MAKE_NVP(value,(T&)*it);
	}
}


//
//  std::queue
//  
// 
// 


template <typename T>
void save_this(opros::archive::oarchive &ar, std::queue<T> &t)
{
	int size = t.size();

	ar << OPROS_SERIALIZATION_NVP(size);

	int x;

	std::queue<T> temp = t;
	
	for (x=0;x< size; x++)
	{
		T tempItem = temp.front();
		temp.pop();
		ar << OPROS_SERIALIZATION_MAKE_NVP(value,tempItem);
	}
}


//
//  std::priority_queue
//  
// 
// 


template <typename T>
void save_this(opros::archive::oarchive &ar, std::priority_queue<T> &t)
{
	int size = t.size();

	ar << OPROS_SERIALIZATION_NVP(size);

	int x;

	std::priority_queue<T> temp = t;
	
	for (x=0;x< size; x++)
	{
		T tempItem = temp.top();
		temp.pop();
		ar << OPROS_SERIALIZATION_MAKE_NVP(value,tempItem);
	}
}

//
//  std::map
//  
// 
// 


template <typename K,typename T>
void save_this(opros::archive::oarchive &ar, std::map<K,T> &t)
{
	int size = t.size();

	ar << OPROS_SERIALIZATION_NVP(size);

	
	typename std::map<K,T>::iterator it = t.begin();

	
	for (;it != t.end(); it++)
	{
		ar << OPROS_SERIALIZATION_MAKE_NVP(key,(K&)(*it).first);
		ar << OPROS_SERIALIZATION_MAKE_NVP(value,(T&)(*it).second);
	}
}


//
//  std::multimap
//  
// 
// 


template <typename K,typename T>
void save_this(opros::archive::oarchive &ar, std::multimap<K,T> &t)
{
	int size = t.size();

	ar << OPROS_SERIALIZATION_NVP(size);

	
	typename std::multimap<K,T>::iterator it = t.begin();

	
	for (;it != t.end(); it++)
	{
		ar << OPROS_SERIALIZATION_MAKE_NVP(key,(K&)(*it).first);
		ar << OPROS_SERIALIZATION_MAKE_NVP(value,(T&)(*it).second);
	}
}

//
//  std::string
//  
// 
// 
void save_this(opros::archive::oarchive &ar, std::string &t);
/*{
	int sz = t.size();

	ar << sz;

	ar.save(t.c_str(), sz);
}
*/

//
// 
//  std::complex
//
//
//
//

template <typename T>
void save_this(opros::archive::oarchive &ar, std::complex<T> &t)
{
	T t_r,t_i;
	t_r = t.real();
	t_i = t.imag();

	ar << OPROS_SERIALIZATION_MAKE_NVP(real, t_r);
	ar << OPROS_SERIALIZATION_MAKE_NVP(imag, t_i);
}






#endif // _OPROS_OARHIVE_STL_H
