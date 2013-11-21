/*
 *  OPRoS Component Engine (OCE)
 *  Copyright (c) 2008 ETRI. http://www.etri.re.kr.
 *  Distributed under the OPRoS License, Version 1.0.
 *
 *  @Created : 2009. 3. 5
 *  @Author  : sby (sby@etri.re.kr)
 *
 *  @File    : RemoteEventPort.h
 *
 *
 */

#ifndef REMOTEEVENTPORT_H_
#define REMOTEEVENTPORT_H_
#include "ReturnType.h"

class RemoteEventPort {
public:
	RemoteEventPort() {
	}

	virtual ~RemoteEventPort() {
	}


	virtual ReturnType pushEvent(unsigned char *data, int size)=0; // use encoded data
};

#endif /* REMOTEEVENTPORT_H_ */
