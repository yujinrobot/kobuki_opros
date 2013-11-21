/*
 *  OPRoS Component Engine (OCE)
 *  Copyright (c) 2008 ETRI. http://www.etri.re.kr.
 *  Distributed under the OPRoS License, Version 1.0.
 *
 *  @Created : 2011. 2. 23
 *  @Author  : sby (sby@etri.re.kr)
 *
 *  @File    : EventCallback.h
 *
 *
 */
#ifndef EVENTCALLBACK_H
#define EVENTCALLBACK_H

#include <ReturnType.h>
#include <Event.h>
#include <archive/opros_iarchive.h>
#include <EventData.h>
class EventCallBack
{
public:
	virtual ReturnType onEvent(opros::archive::iarchive &in)=0;
	virtual ReturnType onEvent(Event *p) =0;
	virtual ~EventCallBack(){};
};

template <typename T,typename C>
class EventCallBackMethod : public EventCallBack
{	
	typedef ReturnType (C::*GenericMemberFunc)(Event *);
	GenericMemberFunc memberFunction;

	C *mmPtr;


public:
	virtual ReturnType onEvent(opros::archive::iarchive &in)
	{
		EventData<T> *evt = new EventData<T>();

		in >> OPROS_SERIALIZATION_MAKE_NVP(EVENTDATA_NVP, *evt);

		ReturnType ret = onEvent((Event *)evt);

		delete evt;

		return ret;
	}

	virtual ReturnType onEvent(Event *p)
	{
		if (mmPtr == NULL || memberFunction==NULL) return OPROS_INTERNAL_FAULT;
		return (mmPtr->*memberFunction)(p);
	}
	
	virtual ~EventCallBackMethod (){};

	EventCallBackMethod(ReturnType (C::* function)(Event *), C *classPtr)
	{
		memberFunction = reinterpret_cast<GenericMemberFunc> (function);
		mmPtr = classPtr;
	}

};

template <typename T>
class EventCallBackMethod<T,void> : public EventCallBack
{	
	typedef ReturnType (*functionPtrFunc)(Event *);

	functionPtrFunc functionPtr;
	

public:
	virtual ReturnType onEvent(opros::archive::iarchive &in)
	{
		EventData<T> *evt = new EventData<T>();

		in >> OPROS_SERIALIZATION_MAKE_NVP(EVENTDATA_NVP, *evt);

		ReturnType ret = onEvent((Event *)&evt);

		delete evt;

		return ret;
	}

	virtual ReturnType onEvent(Event *p)
	{
		if (functionPtr== NULL) return OPROS_INTERNAL_FAULT;
		return (*functionPtr)(p);
	}

	virtual ~EventCallBackMethod(){};
		
	EventCallBackMethod(ReturnType (*function)(Event *))
	{
		functionPtr = reinterpret_cast<functionPtrFunc> (function);
	}
};


template <typename T,typename C>
EventCallBack *make_EventCallBack( ReturnType (C::*function)(Event *), C *classPtr)
{
	EventCallBackMethod<T,C> *r = new EventCallBackMethod<T,C>(function, classPtr);

	EventCallBack *results = reinterpret_cast<EventCallBack *>(r);

	return results;
}


template <typename T>
EventCallBack *make_EventCallBack( ReturnType (*function)(Event *))
{
	EventCallBackMethod<T,void> *r = new EventCallBackMethod<T,void>(function);

	EventCallBack *results = reinterpret_cast<EventCallBack *>(r);

	return results;
}

#define MakeEventCallBackClassFunction(func, classPtr, contentType) make_EventCallBack<contentType>(func,classPtr)

#define MakeEventCallBackFunction(func, contentType) make_EventCallBack<contentType>(func)

#endif // EVENTCALLBACK_H

