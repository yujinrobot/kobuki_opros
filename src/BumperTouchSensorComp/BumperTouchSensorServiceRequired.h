#ifndef _BumperTouchSensorService_REQUIRED_PORT_H
#define _BumperTouchSensorService_REQUIRED_PORT_H

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

/*
 * 
 * BumperTouchSensorService : public RequiredServicePort
 *
 */
class BumperTouchSensorServiceRequired : public RequiredServicePort
{
protected:
	typedef RequiredMethod<ReturnType> SetPropertyFuncType;
	SetPropertyFuncType *SetPropertyFunc;

	typedef RequiredMethod<OPRoS::Property> GetPropertyFuncType;
	GetPropertyFuncType *GetPropertyFunc;

	typedef RequiredMethod<ReturnType> GetErrorFuncType;
	GetErrorFuncType *GetErrorFunc;

	typedef RequiredMethod<ReturnType> EnableFuncType;
	EnableFuncType *EnableFunc;

	typedef RequiredMethod<ReturnType> DisableFuncType;
	DisableFuncType *DisableFunc;

	typedef RequiredMethod< std::vector<OPRoS::Bool> > GetSensorValueFuncType;
	GetSensorValueFuncType *GetSensorValueFunc;

public:
	//
	// Constructor
	//
	BumperTouchSensorServiceRequired()
	{
		SetPropertyFunc = NULL;
		GetPropertyFunc = NULL;
		GetErrorFunc = NULL;
		EnableFunc = NULL;
		DisableFunc = NULL;
		GetSensorValueFunc = NULL;

		setup();
	}

	// method implementation for required method
	ReturnType SetProperty(OPRoS::Property props)
	{
		opros_assert(SetPropertyFunc != NULL);

		return (*SetPropertyFunc)(props);
	}

	OPRoS::Property GetProperty()
	{
		opros_assert(GetPropertyFunc != NULL);

		return (*GetPropertyFunc)();
	}

	ReturnType GetError()
	{
		opros_assert(GetErrorFunc != NULL);

		return (*GetErrorFunc)();
	}

	ReturnType Enable()
	{
		opros_assert(EnableFunc != NULL);

		return (*EnableFunc)();
	}

	ReturnType Disable()
	{
		opros_assert(DisableFunc != NULL);

		return (*DisableFunc)();
	}

	std::vector<OPRoS::Bool> GetSensorValue()
	{
		opros_assert(GetSensorValueFunc != NULL);

		return (*GetSensorValueFunc)();
	}

	// generated setup function
	virtual void setup()
	{
		Method *ptr_method;

		ptr_method = makeRequiredMethod(&BumperTouchSensorServiceRequired::SetProperty,"SetProperty");
		opros_assert(ptr_method != NULL);
		addMethod("SetProperty",ptr_method);
		SetPropertyFunc = reinterpret_cast<SetPropertyFuncType *>(ptr_method);
		ptr_method = NULL;

		ptr_method = makeRequiredMethod(&BumperTouchSensorServiceRequired::GetProperty,"GetProperty");
		opros_assert(ptr_method != NULL);
		addMethod("GetProperty",ptr_method);
		GetPropertyFunc = reinterpret_cast<GetPropertyFuncType *>(ptr_method);
		ptr_method = NULL;

		ptr_method = makeRequiredMethod(&BumperTouchSensorServiceRequired::GetError,"GetError");
		opros_assert(ptr_method != NULL);
		addMethod("GetError",ptr_method);
		GetErrorFunc = reinterpret_cast<GetErrorFuncType *>(ptr_method);
		ptr_method = NULL;

		ptr_method = makeRequiredMethod(&BumperTouchSensorServiceRequired::Enable,"Enable");
		opros_assert(ptr_method != NULL);
		addMethod("Enable",ptr_method);
		EnableFunc = reinterpret_cast<EnableFuncType *>(ptr_method);
		ptr_method = NULL;

		ptr_method = makeRequiredMethod(&BumperTouchSensorServiceRequired::Disable,"Disable");
		opros_assert(ptr_method != NULL);
		addMethod("Disable",ptr_method);
		DisableFunc = reinterpret_cast<DisableFuncType *>(ptr_method);
		ptr_method = NULL;

		ptr_method = makeRequiredMethod(&BumperTouchSensorServiceRequired::GetSensorValue,"GetSensorValue");
		opros_assert(ptr_method != NULL);
		addMethod("GetSensorValue",ptr_method);
		GetSensorValueFunc = reinterpret_cast<GetSensorValueFuncType *>(ptr_method);
		ptr_method = NULL;
    }
};
#endif
