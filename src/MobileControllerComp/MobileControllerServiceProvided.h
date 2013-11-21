#ifndef _MobileControllerService_PROVIDED_PORT_H
#define _MobileControllerService_PROVIDED_PORT_H

#include <OPRoSTypes.h>
#include <InputDataPort.h>
#include <OutputDataPort.h>
#include <InputEventPort.h>
#include <OutputEventPort.h>
#include <ProvidedServicePort.h>
#include <RequiredServicePort.h>
#include <ProvidedMethod.h>
#include <RequiredMethod.h>

#include "Property.h"
#include "ApiTypes.h"
#include <MobileVelocityData.h>
#include <MobilePositionData.h>

#ifndef _IMobileControllerService_CLASS_DEF
#define _IMobileControllerService_CLASS_DEF
/*
 * IMobileControllerService
 *
 *  The comonent inherits this class and implements methods. 
 */
class IMobileControllerService
{
public:
	virtual ReturnType SetProperty(OPRoS::Property parameter)=0;
	virtual OPRoS::Property GetProperty()=0;
	virtual ReturnType GetError()=0;
	virtual ReturnType Enable()=0;
	virtual ReturnType Disable()=0;
	virtual std::vector<OPRoS::Int32> GetOdometry()=0;
	virtual ReturnType SetVelocity(OPRoS::MobileVelocityData velocity)=0;
	virtual ReturnType SetPosition(OPRoS::MobilePositionData position)=0;
	virtual OPRoS::MobilePositionData GetPosition()=0;	
	virtual ReturnType MoveBase(float64_t distance,float64_t linearVelocity)=0;
	virtual ReturnType RotateBase(float64_t angle,float64_t angularVelocity)=0;
	virtual ReturnType StopBase()=0;
	virtual bool IsBaseRunning()=0;
};
#endif

/*
 * 
 * MobileControllerService : public ProvidedServicePort
 *
 */
class MobileControllerServiceProvided : public ProvidedServicePort, public IMobileControllerService
{
protected:
	IMobileControllerService *pcom;

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

	typedef ProvidedMethod<std::vector<OPRoS::Int32> > GetOdometryFuncType;
	GetOdometryFuncType *GetOdometryFunc;

	typedef ProvidedMethod<ReturnType> SetVelocityFuncType;
	SetVelocityFuncType *SetVelocityFunc;

	typedef ProvidedMethod<ReturnType> SetPositionFuncType;
	SetPositionFuncType *SetPositionFunc;

	typedef ProvidedMethod<OPRoS::MobilePositionData> GetPositionFuncType;
	GetPositionFuncType *GetPositionFunc;

	typedef ProvidedMethod<ReturnType> MoveBaseFuncType;
	MoveBaseFuncType *MoveBaseFunc;

	typedef ProvidedMethod<ReturnType> RotateBaseFuncType;
	RotateBaseFuncType *RotateBaseFunc;

	typedef ProvidedMethod<ReturnType> StopBaseFuncType;
	StopBaseFuncType *StopBaseFunc;

	typedef ProvidedMethod<bool> IsBaseRunningFuncType;
	IsBaseRunningFuncType *IsBaseRunningFunc;

		
public: // default method
	virtual ReturnType SetProperty(OPRoS::Property parameter)
	{
		opros_assert(SetPropertyFunc != NULL);

		return (*SetPropertyFunc)(parameter);
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

	virtual std::vector<OPRoS::Int32> GetOdometry()
	{
		opros_assert(GetOdometryFunc != NULL);

		return (*GetOdometryFunc)();
	}

	virtual ReturnType SetVelocity(OPRoS::MobileVelocityData velocity)
	{
		opros_assert(SetVelocityFunc != NULL);

		return (*SetVelocityFunc)(velocity);
	}

	virtual ReturnType SetPosition(OPRoS::MobilePositionData position)
	{
		opros_assert(SetPositionFunc != NULL);

		return (*SetPositionFunc)(position);
	}

	virtual OPRoS::MobilePositionData GetPosition()
	{
		opros_assert(GetPositionFunc != NULL);

		return (*GetPositionFunc)();
	}

	virtual ReturnType MoveBase(float64_t distance,float64_t linearVelocity)
	{
		opros_assert(MoveBaseFunc != NULL);

		return (*MoveBaseFunc)(distance, linearVelocity);
	}

	virtual ReturnType RotateBase(float64_t angle,float64_t angularVelocity)
	{
		opros_assert(RotateBaseFunc != NULL);

		return (*RotateBaseFunc)(angle, angularVelocity);
	}

	virtual ReturnType StopBase()
	{
		opros_assert(StopBaseFunc != NULL);

		return (*StopBaseFunc)();
	}

	virtual bool IsBaseRunning()
	{
		opros_assert(IsBaseRunningFunc != NULL);

		return (*IsBaseRunningFunc)();
	}


public:
	//
	// Constructor
	//
	MobileControllerServiceProvided(IMobileControllerService *fn)
	{
		pcom = fn;

		SetPropertyFunc = NULL;
		GetPropertyFunc = NULL;
		GetErrorFunc = NULL;
		EnableFunc = NULL;
		DisableFunc = NULL;
		GetOdometryFunc = NULL;
		SetVelocityFunc = NULL;
		SetPositionFunc = NULL;
		GetPositionFunc = NULL;
		MoveBaseFunc = NULL;
		RotateBaseFunc = NULL;
		StopBaseFunc = NULL;
		IsBaseRunningFunc = NULL;

		setup();
    }

	// generated setup function
	virtual void setup()
	{
		Method *ptr_method;

		ptr_method = makeProvidedMethod(&IMobileControllerService::SetProperty,pcom,"SetProperty");
		opros_assert(ptr_method != NULL);
		addMethod("SetProperty",ptr_method);
		SetPropertyFunc = reinterpret_cast<SetPropertyFuncType *>(ptr_method);
		ptr_method = NULL;

		ptr_method = makeProvidedMethod(&IMobileControllerService::GetProperty,pcom,"GetProperty");
		opros_assert(ptr_method != NULL);
		addMethod("GetProperty",ptr_method);
		GetPropertyFunc = reinterpret_cast<GetPropertyFuncType *>(ptr_method);
		ptr_method = NULL;

		ptr_method = makeProvidedMethod(&IMobileControllerService::GetError,pcom,"GetError");
		opros_assert(ptr_method != NULL);
		addMethod("GetError",ptr_method);
		GetErrorFunc = reinterpret_cast<GetErrorFuncType *>(ptr_method);
		ptr_method = NULL;

		ptr_method = makeProvidedMethod(&IMobileControllerService::Enable,pcom,"Enable");
		opros_assert(ptr_method != NULL);
		addMethod("Enable",ptr_method);
		EnableFunc = reinterpret_cast<EnableFuncType *>(ptr_method);
		ptr_method = NULL;

		ptr_method = makeProvidedMethod(&IMobileControllerService::Disable,pcom,"Disable");
		opros_assert(ptr_method != NULL);
		addMethod("Disable",ptr_method);
		DisableFunc = reinterpret_cast<DisableFuncType *>(ptr_method);
		ptr_method = NULL;

		ptr_method = makeProvidedMethod(&IMobileControllerService::GetOdometry,pcom,"GetOdometry");
		opros_assert(ptr_method != NULL);
		addMethod("GetOdometry",ptr_method);
		GetOdometryFunc = reinterpret_cast<GetOdometryFuncType *>(ptr_method);
		ptr_method = NULL;

		ptr_method = makeProvidedMethod(&IMobileControllerService::SetVelocity,pcom,"SetVelocity");
		opros_assert(ptr_method != NULL);
		addMethod("SetVelocity",ptr_method);
		SetVelocityFunc = reinterpret_cast<SetVelocityFuncType *>(ptr_method);
		ptr_method = NULL;

		ptr_method = makeProvidedMethod(&IMobileControllerService::SetPosition,pcom,"SetPosition");
		opros_assert(ptr_method != NULL);
		addMethod("SetPosition",ptr_method);
		SetPositionFunc = reinterpret_cast<SetPositionFuncType *>(ptr_method);
		ptr_method = NULL;

		ptr_method = makeProvidedMethod(&IMobileControllerService::GetPosition,pcom,"GetPosition");
		opros_assert(ptr_method != NULL);
		addMethod("GetPosition",ptr_method);
		GetPositionFunc = reinterpret_cast<GetPositionFuncType *>(ptr_method);
		ptr_method = NULL;

		ptr_method = makeProvidedMethod(&IMobileControllerService::MoveBase,pcom,"MoveBase");
		opros_assert(ptr_method != NULL);
		addMethod("MoveBase",ptr_method);
		MoveBaseFunc = reinterpret_cast<MoveBaseFuncType *>(ptr_method);
		ptr_method = NULL;

		ptr_method = makeProvidedMethod(&IMobileControllerService::RotateBase,pcom,"RotateBase");
		opros_assert(ptr_method != NULL);
		addMethod("RotateBase",ptr_method);
		RotateBaseFunc = reinterpret_cast<RotateBaseFuncType *>(ptr_method);
		ptr_method = NULL;

		ptr_method = makeProvidedMethod(&IMobileControllerService::StopBase,pcom,"StopBase");
		opros_assert(ptr_method != NULL);
		addMethod("StopBase",ptr_method);
		StopBaseFunc = reinterpret_cast<StopBaseFuncType *>(ptr_method);
		ptr_method = NULL;

		ptr_method = makeProvidedMethod(&IMobileControllerService::IsBaseRunning,pcom,"IsBaseRunning");
		opros_assert(ptr_method != NULL);
		addMethod("IsBaseRunning",ptr_method);
		IsBaseRunningFunc = reinterpret_cast<IsBaseRunningFuncType *>(ptr_method);
		ptr_method = NULL;
    }
};
#endif
