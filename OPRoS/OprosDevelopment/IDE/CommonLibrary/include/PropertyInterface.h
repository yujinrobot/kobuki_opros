/*
 *  OPRoS Component Engine (OCE)
 *  Copyright (c) 2008 ETRI. http://www.etri.re.kr.
 *  Distributed under the OPRoS License, Version 1.0.
 *
 *  @Created : 2009. 2. 18
 *  @Author  : sby (sby@etri.re.kr)
 *
 *  @File    : PropertyInterface.h
 *
 *
 */

#ifndef PROPERTYINTERFACE_H_
#define PROPERTYINTERFACE_H_

#include <string>
#include <map>
#include <ReturnType.h>

class PropertyInterfaceImpl;

class PropertyInterface {
	PropertyInterfaceImpl *m_impl;
public:
	PropertyInterface();
	virtual ~PropertyInterface();

	virtual void setProperty(const std::string &name, const std::string &value);
	virtual std::string &getProperty(const std::string &name);
	virtual std::map<std::string, std::string> &getPropertyMap();
};

#endif /* PROPERTYINTERFACE_H_ */
