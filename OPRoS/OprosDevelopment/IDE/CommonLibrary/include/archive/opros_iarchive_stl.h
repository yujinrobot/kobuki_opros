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

#ifndef _OPROS_IARHIVE_STL_H
#define _OPROS_IARHIVE_STL_H



#include "opros_iarchive.h"
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

template <typename T>
void load_this(opros::archive::iarchive &ar, std::vector<T> &t)
{
	int size;

	ar >>OPROS_SERIALIZATION_NVP(size);

	if (size <0) throw opros::archive::archive_format_exception();

	int x;

	t.resize(size);

	for (x=0; x < size; x++)
	{
		T temp;

		ar >> OPROS_SERIALIZATION_MAKE_NVP(value,temp);

		t[x] = temp;
	}	
}


//
//  std::deque
//


template <typename T>
void load_this(opros::archive::iarchive &ar, std::deque<T> &t)
{
	int size;

	ar >>OPROS_SERIALIZATION_NVP(size);

	if (size <0) throw opros::archive::archive_format_exception();

	int x;

	t.resize(size);

	for (x=0; x < size; x++)
	{
		T temp;

		ar >> OPROS_SERIALIZATION_MAKE_NVP(value,temp);

		t[x] = temp;
	}	
}

//
//  std::list
//

template <typename T>
void load_this(opros::archive::iarchive &ar, std::list<T> &t)
{
	int size;

	ar >>OPROS_SERIALIZATION_NVP(size);

	if (size <0) throw opros::archive::archive_format_exception();

	int x;

	t.resize(size);

	for (x=0; x < size; x++)
	{
		T temp;

		ar >> OPROS_SERIALIZATION_MAKE_NVP(value,temp);

		t.push_back(temp);
	}	
}

//
//  std::valarray
//

template <typename T>
void load_this(opros::archive::iarchive &ar, std::valarray<T> &t)
{
	int size;

	ar >>OPROS_SERIALIZATION_NVP(size);

	if (size <0) throw opros::archive::archive_format_exception();

	int x;

	t.resize(size);

	for (x=0; x < size; x++)
	{
		T temp;

		ar >> OPROS_SERIALIZATION_MAKE_NVP(value,temp);

		t[x]=temp;
	}	
}



//
//  std::stack
//

template <typename T>
void load_this(opros::archive::iarchive &ar, std::stack<T> &t)
{
	int size;

	ar >>OPROS_SERIALIZATION_NVP(size);

	if (size <0) throw opros::archive::archive_format_exception();

	int x;

	for (x=0; x < size; x++)
	{
		T temp;

		ar >> OPROS_SERIALIZATION_MAKE_NVP(value,temp);

		t.push(temp);
	}	
}


//
//  std::set
//  
// ToDo: sorting problem is remained in due to key_compare of set class 
// 

template <typename T>
void load_this(opros::archive::iarchive &ar, std::set<T> &t)
{
	int size;

	ar >>OPROS_SERIALIZATION_NVP(size);

	if (size <0) throw opros::archive::archive_format_exception();

	int x;

	t.clear();

	for (x=0; x < size; x++)
	{
		T temp;

		ar >> OPROS_SERIALIZATION_MAKE_NVP(value,temp);

		t.insert(temp);
	}	
}

//
//  std::multiset
//  
// ToDo: sorting problem is remained in due to key_compare of set class 
// 

template <typename T>
void load_this(opros::archive::iarchive &ar, std::multiset<T> &t)
{
	int size;

	ar >>OPROS_SERIALIZATION_NVP(size);

	if (size <0) throw opros::archive::archive_format_exception();

	int x;

	t.clear();

	for (x=0; x < size; x++)
	{
		T temp;

		ar >> OPROS_SERIALIZATION_MAKE_NVP(value,temp);

		t.insert(temp);
	}	
}

//
//  std::queue
//  
// 
// 

template <typename T>
void load_this(opros::archive::iarchive &ar, std::queue<T> &t)
{
	int size;

	ar >>OPROS_SERIALIZATION_NVP(size);

	if (size <0) throw opros::archive::archive_format_exception();

	int x;

	for (x=0; x < size; x++)
	{
		T temp;

		ar >> OPROS_SERIALIZATION_MAKE_NVP(value,temp);

		t.push(temp);
	}	
}



//
//  std::priority_queue
//  
// 
// 

template <typename T>
void load_this(opros::archive::iarchive &ar, std::priority_queue<T> &t)
{
	int size;

	ar >>OPROS_SERIALIZATION_NVP(size);

	if (size <0) throw opros::archive::archive_format_exception();

	int x;

	for (x=0; x < size; x++)
	{
		T temp;

		ar >> OPROS_SERIALIZATION_MAKE_NVP(value,temp);

		t.push(temp);
	}	
}

//
//  std::map
//  
// 
// 

template <typename K,typename T>
void load_this(opros::archive::iarchive &ar, std::map<K,T> &t)
{
	int size;

	ar >>OPROS_SERIALIZATION_NVP(size);

	if (size <0) throw opros::archive::archive_format_exception();

	int x;

	for (x=0; x < size; x++)
	{
		K a_temp;
		T b_temp;

		ar >> OPROS_SERIALIZATION_MAKE_NVP(key,a_temp);
		ar >> OPROS_SERIALIZATION_MAKE_NVP(value,b_temp);

		t.insert( std::pair<K,T>(a_temp, b_temp));
	}	
}

//
//  std::multimap
//  
// 
// 

template <typename K,typename T>
void load_this(opros::archive::iarchive &ar, std::multimap<K,T> &t)
{
	int size;

	ar >>OPROS_SERIALIZATION_NVP(size);

	if (size <0) throw opros::archive::archive_format_exception();

	int x;

	for (x=0; x < size; x++)
	{
		K a_temp;
		T b_temp;

		ar >> OPROS_SERIALIZATION_MAKE_NVP(key,a_temp);
		ar >> OPROS_SERIALIZATION_MAKE_NVP(value,b_temp);

		t.insert( std::pair<K,T>(a_temp, b_temp));
	}	
}


//
//  std::string
//  
// 
// 

void load_this(opros::archive::iarchive &ar, std::string &t);
/*
{
	unsigned long size;

	ar >> size;

	if (size <0) throw opros::archive::archive_format_exception();

	char *dp=0;
	
	ar.load(&dp, size);

	t.assign(dp,size);

	delete dp;
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
void load_this(opros::archive::iarchive &ar, std::complex<T> &t)
{
	T r,i;

	ar >> OPROS_SERIALIZATION_MAKE_NVP(real, i);
	ar >> OPROS_SERIALIZATION_MAKE_NVP(imag,r);

	t.real(i);
	t.imag(r);
}



#endif // _OPROS_IARHIVE_STL_H
