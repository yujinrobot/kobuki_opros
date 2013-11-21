//
// #LICENSE#
//
//
//  @ Project : OPROS_Component
//  @ File Name : IDataPortLink.h
//  @ Date : 2008-09-23
//  @ Author :
//
//


#if !defined(_IDATAPORTLINK_H)
#define _IDATAPORTLINK_H

#include <OPRoSTypes.h>
#include <DataPort.h>
#include <RemoteDataPort.h>
/*
 * Connection은 하나로 하고 Dataport 자체를 remote와 local로 함
 */



class IDataPortLink {
public:
	virtual ReturnType push(opros_any & data) = 0;
	virtual ReturnType setSource(DataPort *src) = 0;
	virtual ReturnType addDestination(DataPort *dest) = 0;
	virtual ReturnType addDestination(RemoteDataPort *dest)=0;
	virtual ReturnType removeDestination(DataPort *dest)=0;
	virtual ReturnType removeDestination(RemoteDataPort *dest)=0;
	virtual ReturnType clearDestination() = 0;
	virtual ReturnType clearSource() = 0;
};

#endif  //_IDATAPORTLINK_H
