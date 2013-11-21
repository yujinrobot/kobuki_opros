/*
 * OPRoS Component Engine (OCE)
 * Copyright (c) 2008 ETRI. http://www.etri.re.kr.
 * Distributed under the OPRoS License, Version 1.0.
 *
 *  @Created : 2010. 8. 11
 *  @Author  : sby (sby@etri.re.kr)
 *
 *  @File    : opros_archive_smart_ptr.h
 *
 *
 *
 *  SmartPtr archive  support class
 */

#ifndef _OPROS_ARHIVE_SMART_PTR_H
#define _OPROS_ARHIVE_SMART_PTR_H

#include "opros_oarchive.h"
#include "opros_iarchive.h"
#include "opros_smart_ptr.h"

template <typename T>
inline std::string typeName(opros::smart_ptr<T> *p)
{
	return std::string("");
}


template <typename T>
inline void save_this(opros::archive::oarchive &ar, opros::smart_ptr<T> &t)
{
	save_this(ar, *t.get());
}

template <typename T>
inline void load_this(opros::archive::iarchive &ar, opros::smart_ptr<T> &t)
{	
	load_this(ar, *t.get());
}



#endif // _OPROS_OARHIVE_SMART_PTR_H
