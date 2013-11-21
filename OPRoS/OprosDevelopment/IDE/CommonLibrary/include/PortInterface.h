/*
 *  OPRoS Component Engine (OCE)
 *  Copyright (c) 2008 ETRI. http://www.etri.re.kr.
 *  Distributed under the OPRoS License, Version 1.0.
 *
 *  @Created : 2009. 2. 18
 *  @Author  : sby (sby@etri.re.kr)
 *
 *  @File    : PortInterface.h
 *
 *
 */

#ifndef PORTINTERFACE_H_
#define PORTINTERFACE_H_

#include <Port.h>
#include <ReturnType.h>

class PortInterfaceImpl;

class PortInterface {
	PortInterfaceImpl *m_impl;
public:
	PortInterface();
	virtual ~PortInterface();
	virtual ReturnType addPort(const std::string &name, Port *port);
	virtual Port *getPort(const std::string &name);
	virtual void portReset();
};

#endif /* PORTINTERFACE_H_ */
