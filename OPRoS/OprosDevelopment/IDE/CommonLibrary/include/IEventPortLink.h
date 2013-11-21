/*
 *  OPRoS Component Engine (OCE)
 *  Copyright (c) 2008 ETRI. http://www.etri.re.kr.
 *  Distributed under the OPRoS License, Version 1.0.
 *
 *  @Created : 2009. 2. 19
 *  @Author  : sby (sby@etri.re.kr)
 *
 *  @File    : IEventPortLink.h
 *
 *
 */

#if !defined(_IEVENTPORTLINK_H)
#define _IEVENTPORTLINK_H

#include <Event.h>
#include <EventPort.h>
#include <RemoteEventPort.h>
/*
 * Connection은 하나로 하고 Eventport 자체를 remote와 local로 함
 */

class IEventPortLink {
public:
	virtual ReturnType push(Event *data) = 0;
	virtual ReturnType setSource(EventPort *src) = 0;
	virtual ReturnType addDestination(EventPort *dest) = 0;
	virtual ReturnType removeDestination(EventPort *dest) = 0;
	virtual ReturnType addDestination(RemoteEventPort *dest) = 0;
	virtual ReturnType removeDestination(RemoteEventPort *dest) = 0;
	virtual ReturnType clearDestination() = 0;
	virtual ReturnType clearSource() = 0;
};

#endif  //_IEVENTPORTLINK_H
