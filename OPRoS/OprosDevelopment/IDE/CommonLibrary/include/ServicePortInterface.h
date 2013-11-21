/*
 *  OPRoS Component Engine (OCE)
 *  Copyright (c) 2008 ETRI. http://www.etri.re.kr.
 *  Distributed under the OPRoS License, Version 1.0.
 *
 *  @Created : 2009. 2. 27
 *  @Author  : sby (sby@etri.re.kr)
 *
 *  @File    : ServicePortInterface.h
 *
 *
 */

#ifndef SERVICEPORTINTERFACE_H_
#define SERVICEPORTINTERFACE_H_

#include "ServicePort.h"
#include <Method.h>

class ServicePortImpl;

class ServicePortInterface: public ServicePort {
protected:
	ServicePortImpl *m_impl;

	typedef std::map<std::string, Method *> service_base;

	virtual service_base::iterator getFirst();
	virtual service_base::iterator getEnd();
public:
	ServicePortInterface();
	ServicePortInterface(const std::string &name);
	virtual ~ServicePortInterface();
	virtual ReturnType addMethod(const std::string &name, Method *srv);
	virtual Method *getMethod(const std::string &name);
	virtual void setArchiveFactory(ArchiveFactory *darc);
	virtual ReturnType callService(std::string &name, std::string &invalue,
			std::string &outvalue)=0;
};

#endif /* SERVICEPORTINTERFACE_H_ */
