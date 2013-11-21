/*
 *  OPRoS Component Engine (OCE)
 *  Copyright (c) 2008 ETRI. http://www.etri.re.kr.
 *  Distributed under the OPRoS License, Version 1.0.
 *
 *  @Created : 2009. 3. 17
 *  @Author  : sby (sby@etri.re.kr)
 *
 *  @File    : RequiredMethodInterface.h
 *
 *
 */

#ifndef REQUIREDMETHODINTERFACE_H_
#define REQUIREDMETHODINTERFACE_H_

#include <Method.h>
#include <ServicePortConnector.h>

class RequiredMethodInterface : public Method{
public:
	RequiredMethodInterface(){};
	RequiredMethodInterface(const std::string &name) : Method(name){};
	virtual ~RequiredMethodInterface(){};
	virtual ReturnType Disconnect() = 0;
	virtual ReturnType Connect(Method *peer) = 0;
	virtual ReturnType Connect(ServicePortConnector *peer) = 0;
	};



#endif /* REQUIREDMETHODINTERFACE_H_ */
