/*
 * OPRoS Component Engine (OCE)
 * Copyright (c) 2008 ETRI. http://www.etri.re.kr.
 * Distributed under the OPRoS License, Version 1.0.
 *
 *  @Created : 2010. 8. 11
 *  @Author  : sby (sby@etri.re.kr)
 *
 *  @File    : opros_archive.h
 *
 *
 *
 *  
 */

#ifndef _OPROS_ACCESS_H
#define _OPROS_ACCESS_H

namespace opros {
	namespace archive {
class oarchive;
class iarchive;
class access
{
public:
	template <typename T>
	static void save(opros::archive::oarchive &ar, T &t)
	{
		t.save(ar, OPROS_SERIALIZATION_VERSION);
	}

	template <typename T>
	static void load(opros::archive::iarchive &ar, T &t)
	{
		t.load(ar, OPROS_SERIALIZATION_VERSION);
	}
};
	} // namespace archive
} // namespace opros


#endif // _OPROS_ACCESS_H
