/*
 *
 * Copyright (c) 2013, Yujin Robot Co., Ltd.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
 * provided that the above copyright notice and this paragraph are
 * duplicated in all such forms and that any documentation,
 * advertising materials, and other materials related to such
 * distribution and use acknowledge that the software was developed
 * by the Yujin Robot Co., Ltd.  The name of the
 * Yujin Robot Co., Ltd. may not be used to endorse or promote products derived
 * from this software without specific prior written permission.
 * THIS SOFTWARE IS PROVIDED ''AS IS'' AND WITHOUT ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
 *
 */

#ifndef _KobukiCliffSensorService_PROVIDED_PORT_H
#define _KobukiCliffSensorService_PROVIDED_PORT_H

#include <OPRoSTypes.h>
#include <InputDataPort.h>
#include <OutputDataPort.h>
#include <InputEventPort.h>
#include <OutputEventPort.h>
#include <ProvidedServicePort.h>
#include <RequiredServicePort.h>
#include <ProvidedMethod.h>
#include <RequiredMethod.h>

#include "ApiTypes.h"
#include "Property.h"

#ifndef _IKobukiCliffSensorService_CLASS_DEF
#define _IKobukiCliffSensorService_CLASS_DEF
/*
 * IKobukiCliffSensorService
 *
 *  The comonent inherits this class and implements methods. 
 */
class IKobukiCliffSensorService
{
public:
	virtual ReturnType SetProperty(OPRoS::Property props)=0;
	virtual OPRoS::Property GetProperty()=0;
	virtual ReturnType GetError()=0;
	virtual ReturnType Enable()=0;
	virtual ReturnType Disable()=0;
	virtual std::vector<OPRoS::Bool> GetSensorValue()=0;
};
#endif

/*
 * 
 * KobukiCliffSensorService : public ProvidedServicePort
 *
 */
class KobukiCliffSensorServiceProvided : public ProvidedServicePort, public IKobukiCliffSensorService
{
protected:
	IKobukiCliffSensorService *pcom;
	
	typedef ProvidedMethod<ReturnType> SetPropertyFuncType;
	SetPropertyFuncType *SetPropertyFunc;

	typedef ProvidedMethod<OPRoS::Property> GetPropertyFuncType;
	GetPropertyFuncType *GetPropertyFunc;

	typedef ProvidedMethod<ReturnType> GetErrorFuncType;
	GetErrorFuncType *GetErrorFunc;

	typedef ProvidedMethod<ReturnType> EnableFuncType;
	EnableFuncType *EnableFunc;

	typedef ProvidedMethod<ReturnType> DisableFuncType;
	DisableFuncType *DisableFunc;

	typedef ProvidedMethod< std::vector<OPRoS::Bool> > GetSensorValueFuncType;
	GetSensorValueFuncType *GetSensorValueFunc;
	
public: // default method
	virtual ReturnType SetProperty(OPRoS::Property props)
	{
		opros_assert(SetPropertyFunc != NULL);

		return (*SetPropertyFunc)(props);
	}

	virtual OPRoS::Property GetProperty()
	{
		opros_assert(GetPropertyFunc != NULL);

		return (*GetPropertyFunc)();
	}

	virtual ReturnType GetError()
	{
		opros_assert(GetErrorFunc != NULL);

		return (*GetErrorFunc)();
	}

	virtual ReturnType Enable()
	{
		opros_assert(EnableFunc != NULL);

		return (*EnableFunc)();
	}

	virtual ReturnType Disable()
	{
		opros_assert(DisableFunc != NULL);

		return (*DisableFunc)();
	}

	virtual std::vector<OPRoS::Bool> GetSensorValue()
	{
		opros_assert(GetSensorValueFunc != NULL);

		return (*GetSensorValueFunc)();
	}
	
public:
	//
	// Constructor
	//
	KobukiCliffSensorServiceProvided(IKobukiCliffSensorService *fn)
	{
		pcom = fn;

		SetPropertyFunc = NULL;
		GetPropertyFunc = NULL;
		GetErrorFunc = NULL;
		EnableFunc = NULL;
		DisableFunc = NULL;
		GetSensorValueFunc = NULL;

		setup();
	}

	// generated setup function
	virtual void setup()
	{
		Method *ptr_method;

		ptr_method = makeProvidedMethod(&IKobukiCliffSensorService::SetProperty,pcom,"SetProperty");
		opros_assert(ptr_method != NULL);
		addMethod("SetProperty",ptr_method);
		SetPropertyFunc = reinterpret_cast<SetPropertyFuncType *>(ptr_method);
		ptr_method = NULL;

		ptr_method = makeProvidedMethod(&IKobukiCliffSensorService::GetProperty,pcom,"GetProperty");
		opros_assert(ptr_method != NULL);
		addMethod("GetProperty",ptr_method);
		GetPropertyFunc = reinterpret_cast<GetPropertyFuncType *>(ptr_method);
		ptr_method = NULL;

		ptr_method = makeProvidedMethod(&IKobukiCliffSensorService::GetError,pcom,"GetError");
		opros_assert(ptr_method != NULL);
		addMethod("GetError",ptr_method);
		GetErrorFunc = reinterpret_cast<GetErrorFuncType *>(ptr_method);
		ptr_method = NULL;

		ptr_method = makeProvidedMethod(&IKobukiCliffSensorService::Enable,pcom,"Enable");
		opros_assert(ptr_method != NULL);
		addMethod("Enable",ptr_method);
		EnableFunc = reinterpret_cast<EnableFuncType *>(ptr_method);
		ptr_method = NULL;

		ptr_method = makeProvidedMethod(&IKobukiCliffSensorService::Disable,pcom,"Disable");
		opros_assert(ptr_method != NULL);
		addMethod("Disable",ptr_method);
		DisableFunc = reinterpret_cast<DisableFuncType *>(ptr_method);
		ptr_method = NULL;

		ptr_method = makeProvidedMethod(&IKobukiCliffSensorService::GetSensorValue,pcom,"GetSensorValue");
		opros_assert(ptr_method != NULL);
		addMethod("GetSensorValue",ptr_method);
		GetSensorValueFunc = reinterpret_cast<GetSensorValueFuncType *>(ptr_method);
		ptr_method = NULL;
    }
};
#endif
