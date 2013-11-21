/*
 *  OPRoS Component Engine (OCE)
 *  Copyright (c) 2008 ETRI. http://www.etri.re.kr.
 *  Distributed under the OPRoS License, Version 1.0.
 *
 *  @Created : 2009. 2. 27
 *  @Author  : sby (sby@etri.re.kr)
 *
 *  @File    : ProvidedServicePort.h
 *
 *
 */

#ifndef PROVIDEDSERVICEPORT_H_
#define PROVIDEDSERVICEPORT_H_

#include "ServicePortInterface.h"

class ProvidedServicePort: public ServicePortInterface {
public:
	ProvidedServicePort();
	ProvidedServicePort(const std::string &name);
	virtual ~ProvidedServicePort();
	virtual ReturnType callService(std::string &name, std::string &invalue, std::string &outvalue);

	virtual ServicePortRole getRole() ; // added  2012/04/05 
};

#endif /* PROVIDEDSERVICEPORT_H_ */
