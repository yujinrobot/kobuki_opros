/*
 *  OPRoS Component Engine (OCE)
 *  Copyright (c) 2008 ETRI. http://www.etri.re.kr.
 *  Distributed under the OPRoS License, Version 1.0.
 *
 *  @Created : 2009. 2. 18
 *  @Author  : sby (sby@etri.re.kr)
 *
 *  @File    : EventPort.h
 *
 *
 */

#ifndef EVENTPORT_H_
#define EVENTPORT_H_

#include <Port.h>
#include <ReturnType.h>
#include <OPRoSTypes.h>
#include <Event.h>

class EventPort : public Port{

public:
	EventPort();
	EventPort(const std::string &name);

	virtual ReturnType push(Event *data) = 0;
	virtual bool checkType(Event *data) = 0;
	virtual bool checkType(EventPort *dst) = 0;
	virtual EventPortRole getRole() = 0;
	virtual ReturnType pushEvent(unsigned char *data, int size) = 0;
	virtual void reset(){};
	virtual ~EventPort();
};
#endif /* EVENTPORT_H_ */
