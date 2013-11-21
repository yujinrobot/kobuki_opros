/*
 *  OPRoS Component Engine (OCE)
 *  Copyright (c) 2008 ETRI. http://www.etri.re.kr.
 *  Distributed under the OPRoS License, Version 1.0.
 *
 *  @Created : 2009. 4. 2
 *  @Author  : sby (sby@etri.re.kr)
 *
 *  @File    : ServicePortConnector.h
 *
 *
 */

#ifndef SERVICEPORTCONNECTOR_H_
#define SERVICEPORTCONNECTOR_H_
#include "ReturnType.h"
#include <string>
class ServicePortConnector {
public:
	ServicePortConnector(){};
	virtual ~ServicePortConnector(){};
	virtual ReturnType requestService(std::string &name, std::string &invalue, std::string &outvalue) = 0;
	virtual ReturnType responseService(std::string &name, std::string &invalue, std::string &outvalue) = 0;
};

#endif /* SERVICEPORTCONNECTOR_H_ */
