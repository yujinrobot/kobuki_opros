
/*
 *  OPRoS Component Engine (OCE)
 *  Copyright (c) 2008 ETRI. http://www.etri.re.kr.
 *  Distributed under the OPRoS License, Version 1.0.
 *
 *  @Created : 2009. 3. 5
 *  @Author  : sby (sby@etri.re.kr)
 *
 *  @File    : RemoteDataPort.h
 *
 *
 */

#ifndef REMOTEDATAPORT_H_
#define REMOTEDATAPORT_H_

#include "ReturnType.h"
class RemoteDataPort {
public:
	RemoteDataPort(){};
	virtual ~RemoteDataPort(){};

	virtual ReturnType pushData(unsigned char *data, int size)=0; // use encoded data
};

#endif /* REMOTEDATAPORT_H_ */
