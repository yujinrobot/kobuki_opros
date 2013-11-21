#ifndef _BumperTouchSensorService_PROVIDED_PORT_H
#define _BumperTouchSensorService_PROVIDED_PORT_H

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

#ifndef _IBumperTouchSensorService_CLASS_DEF
#define _IBumperTouchSensorService_CLASS_DEF
/*
 * IBumperTouchSensorService
 *
 *  The comonent inherits this class and implements methods. 
 */
class IBumperTouchSensorService
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
 * BumperTouchSensorService : public ProvidedServicePort
 *
 */
class BumperTouchSensorServiceProvided : public ProvidedServicePort, public IBumperTouchSensorService
{
protected:
	IBumperTouchSensorService *pcom;
	
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
	BumperTouchSensorServiceProvided(IBumperTouchSensorService *fn)
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

		ptr_method = makeProvidedMethod(&IBumperTouchSensorService::SetProperty,pcom,"SetProperty");
		opros_assert(ptr_method != NULL);
		addMethod("SetProperty",ptr_method);
		SetPropertyFunc = reinterpret_cast<SetPropertyFuncType *>(ptr_method);
		ptr_method = NULL;

		ptr_method = makeProvidedMethod(&IBumperTouchSensorService::GetProperty,pcom,"GetProperty");
		opros_assert(ptr_method != NULL);
		addMethod("GetProperty",ptr_method);
		GetPropertyFunc = reinterpret_cast<GetPropertyFuncType *>(ptr_method);
		ptr_method = NULL;

		ptr_method = makeProvidedMethod(&IBumperTouchSensorService::GetError,pcom,"GetError");
		opros_assert(ptr_method != NULL);
		addMethod("GetError",ptr_method);
		GetErrorFunc = reinterpret_cast<GetErrorFuncType *>(ptr_method);
		ptr_method = NULL;

		ptr_method = makeProvidedMethod(&IBumperTouchSensorService::Enable,pcom,"Enable");
		opros_assert(ptr_method != NULL);
		addMethod("Enable",ptr_method);
		EnableFunc = reinterpret_cast<EnableFuncType *>(ptr_method);
		ptr_method = NULL;

		ptr_method = makeProvidedMethod(&IBumperTouchSensorService::Disable,pcom,"Disable");
		opros_assert(ptr_method != NULL);
		addMethod("Disable",ptr_method);
		DisableFunc = reinterpret_cast<DisableFuncType *>(ptr_method);
		ptr_method = NULL;

		ptr_method = makeProvidedMethod(&IBumperTouchSensorService::GetSensorValue,pcom,"GetSensorValue");
		opros_assert(ptr_method != NULL);
		addMethod("GetSensorValue",ptr_method);
		GetSensorValueFunc = reinterpret_cast<GetSensorValueFuncType *>(ptr_method);
		ptr_method = NULL;
    }
};
#endif
