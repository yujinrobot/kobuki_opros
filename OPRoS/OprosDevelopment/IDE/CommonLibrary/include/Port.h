/*
 *  OPRoS Component Engine (OCE)
 *  Copyright (c) 2008 ETRI. http://www.etri.re.kr.
 *  Distributed under the OPRoS License, Version 1.0.
 *
 *  @Created : 2009. 2. 18
 *  @Author  : sby (sby@etri.re.kr)
 *
 *  @File    : Port.h
 *
 *
 */

#ifndef PORT_H_
#define PORT_H_

#include <OPRoSTypes.h>
#include <string>

class Port {
protected:
	std::string m_name;
	PortType m_type;

public:
	Port();
	Port(const std::string &name, const PortType &type);
	virtual std::string &getName();
	virtual PortType getType();
	virtual ~Port();
	virtual void reset()=0;
};

#endif /* PORT_H_ */
