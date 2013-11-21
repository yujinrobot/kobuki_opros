/*
 *  OPRoS Component Engine (OCE)
 *  Copyright (c) 2008 ETRI. http://www.etri.re.kr.
 *  Distributed under the OPRoS License, Version 1.0.
 *
 *  @Created : 2009. 2. 20
 *  @Author  : sby (sby@etri.re.kr)
 *
 *  @File    : OutputEventPortInterface.h
 *
 *
 */

#ifndef OUTPUTEVENTPORTINTERFACE_H_
#define OUTPUTEVENTPORTINTERFACE_H_

#include <OPRoSTypes.h>
 
#include <EventPort.h>
#include <ReturnType.h>
#include <ArchiveFactory.h>
#include <IEventPortLink.h>


class OutputEventPortImpl;

class OutputEventPortInterface: public EventPort {
protected:
	friend class OutputEventPortImpl;
	OutputEventPortImpl *m_impl;
	ArchiveFactory *m_arc;

	virtual ReturnType push_event(Event *data);

public:
	OutputEventPortInterface();
	OutputEventPortInterface(const std::string &name);

	virtual ReturnType push(Event *data)=0;
	virtual ReturnType pushEvent(unsigned char *data, int size)=0;
	virtual ReturnType marshal(Event *data, std::string &outdata) = 0;
	virtual bool checkType(Event *data) = 0;
	virtual bool checkType(EventPort *dst) = 0;
	virtual EventPortRole getRole();
	virtual void setArchiveFactory(ArchiveFactory *darc);

	virtual void addConnection(IEventPortLink * connection);
	virtual void removeConnection(IEventPortLink *connection);
	virtual void clearConnection();


	virtual ~OutputEventPortInterface();
};

#endif /* OUTPUTEVENTPORTINTERFACE_H_ */
