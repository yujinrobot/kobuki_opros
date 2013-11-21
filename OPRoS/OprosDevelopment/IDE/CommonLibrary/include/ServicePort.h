/*
 *  OPRoS Component Engine (OCE)
 *  Copyright (c) 2008 ETRI. http://www.etri.re.kr.
 *  Distributed under the OPRoS License, Version 1.0.
 *
 *  @Created : 2009. 2. 18
 *  @Author  : sby (sby@etri.re.kr)
 *
 *  @File    : ServicePort.h
 *
 *
 */

#ifndef SERVICEPORT_H_
#define SERVICEPORT_H_

#include <Port.h>
#include <ReturnType.h>
#include <ArchiveFactory.h>

class ServicePort : public Port{
public:
	ServicePort();
	ServicePort(const std::string &name);
	virtual ~ServicePort();
	virtual ReturnType callService(std::string &name, std::string &invalue, std::string &outvalue)=0;
	virtual ServicePortRole getRole() = 0;
	virtual void reset(){};
};

#endif /* SERVICEPORT_H_ */

