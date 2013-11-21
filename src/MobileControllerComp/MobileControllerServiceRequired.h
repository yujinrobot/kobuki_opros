#ifndef _MobileControllerService_REQUIRED_PORT_H
#define _MobileControllerService_REQUIRED_PORT_H

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

/*
 * 
 * MobileControllerService : public RequiredServicePort
 *
 */
class MobileControllerServiceRequired : public RequiredServicePort
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

	typedef RequiredMethod<std::vector<OPRoS::Int32> > GetOdometryFuncType;
	GetOdometryFuncType *GetOdometryFunc;

	typedef RequiredMethod<ReturnType> SetVelocityFuncType;
	SetVelocityFuncType *SetVelocityFunc;

	typedef RequiredMethod<ReturnType> SetPositionFuncType;
	SetPositionFuncType *SetPositionFunc;

	typedef RequiredMethod<OPRoS::MobilePositionData> GetPositionFuncType;
	GetPositionFuncType *GetPositionFunc;

	typedef RequiredMethod<ReturnType> MoveBaseFuncType;
	MoveBaseFuncType *MoveBaseFunc;

	typedef RequiredMethod<ReturnType> RotateBaseFuncType;
	RotateBaseFuncType *RotateBaseFunc;

	typedef RequiredMethod<ReturnType> StopBaseFuncType;
	StopBaseFuncType *StopBaseFunc;

	typedef RequiredMethod<bool> IsBaseRunningFuncType;
	IsBaseRunningFuncType *IsBaseRunningFunc;

public:
	//
	// Constructor
	//
	MobileControllerServiceRequired()
	{
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

	// method implementation for required method
	ReturnType SetProperty(OPRoS::Property parameter)
	{
		opros_assert(SetPropertyFunc != NULL);

		return (*SetPropertyFunc)(parameter);
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

	std::vector<OPRoS::Int32> GetOdometry()
	{
		opros_assert(GetOdometryFunc != NULL);

		return (*GetOdometryFunc)();
	}

	ReturnType SetVelocity(OPRoS::MobileVelocityData velocity)
	{
		opros_assert(SetVelocityFunc != NULL);

		return (*SetVelocityFunc)(velocity);
	}

	ReturnType SetPosition(OPRoS::MobilePositionData position)
	{
		opros_assert(SetPositionFunc != NULL);

		return (*SetPositionFunc)(position);
	}

	OPRoS::MobilePositionData GetPosition()
	{
		opros_assert(GetPositionFunc != NULL);

		return (*GetPositionFunc)();
	}

	ReturnType MoveBase(float64_t distance,float64_t linearVelocity)
	{
		opros_assert(MoveBaseFunc != NULL);

		return (*MoveBaseFunc)(distance, linearVelocity);
	}

	ReturnType RotateBase(float64_t angle,float64_t angularVelocity)
	{
		opros_assert(RotateBaseFunc != NULL);

		return (*RotateBaseFunc)(angle, angularVelocity);
	}

	ReturnType StopBase()
	{
		opros_assert(StopBaseFunc != NULL);

		return (*StopBaseFunc)();
	}

	bool IsBaseRunning()
	{
		opros_assert(IsBaseRunningFunc != NULL);

		return (*IsBaseRunningFunc)();
	}


    // generated setup function
	virtual void setup()
	{
		Method *ptr_method;

		ptr_method = makeRequiredMethod(&MobileControllerServiceRequired::SetProperty,"SetProperty");
		opros_assert(ptr_method != NULL);
		addMethod("SetProperty",ptr_method);
		SetPropertyFunc = reinterpret_cast<SetPropertyFuncType *>(ptr_method);
		ptr_method = NULL;

		ptr_method = makeRequiredMethod(&MobileControllerServiceRequired::GetProperty,"GetProperty");
		opros_assert(ptr_method != NULL);
		addMethod("GetProperty",ptr_method);
		GetPropertyFunc = reinterpret_cast<GetPropertyFuncType *>(ptr_method);
		ptr_method = NULL;

		ptr_method = makeRequiredMethod(&MobileControllerServiceRequired::GetError,"GetError");
		opros_assert(ptr_method != NULL);
		addMethod("GetError",ptr_method);
		GetErrorFunc = reinterpret_cast<GetErrorFuncType *>(ptr_method);
		ptr_method = NULL;

		ptr_method = makeRequiredMethod(&MobileControllerServiceRequired::Enable,"Enable");
		opros_assert(ptr_method != NULL);
		addMethod("Enable",ptr_method);
		EnableFunc = reinterpret_cast<EnableFuncType *>(ptr_method);
		ptr_method = NULL;

		ptr_method = makeRequiredMethod(&MobileControllerServiceRequired::Disable,"Disable");
		opros_assert(ptr_method != NULL);
		addMethod("Disable",ptr_method);
		DisableFunc = reinterpret_cast<DisableFuncType *>(ptr_method);
		ptr_method = NULL;

		ptr_method = makeRequiredMethod(&MobileControllerServiceRequired::GetOdometry,"GetOdometry");
		opros_assert(ptr_method != NULL);
		addMethod("GetOdometry",ptr_method);
		GetOdometryFunc = reinterpret_cast<GetOdometryFuncType *>(ptr_method);
		ptr_method = NULL;

		ptr_method = makeRequiredMethod(&MobileControllerServiceRequired::SetVelocity,"SetVelocity");
		opros_assert(ptr_method != NULL);
		addMethod("SetVelocity",ptr_method);
		SetVelocityFunc = reinterpret_cast<SetVelocityFuncType *>(ptr_method);
		ptr_method = NULL;

		ptr_method = makeRequiredMethod(&MobileControllerServiceRequired::SetPosition,"SetPosition");
		opros_assert(ptr_method != NULL);
		addMethod("SetPosition",ptr_method);
		SetPositionFunc = reinterpret_cast<SetPositionFuncType *>(ptr_method);
		ptr_method = NULL;

		ptr_method = makeRequiredMethod(&MobileControllerServiceRequired::GetPosition,"GetPosition");
		opros_assert(ptr_method != NULL);
		addMethod("GetPosition",ptr_method);
		GetPositionFunc = reinterpret_cast<GetPositionFuncType *>(ptr_method);
		ptr_method = NULL;

		ptr_method = makeRequiredMethod(&MobileControllerServiceRequired::MoveBase,"MoveBase");
		opros_assert(ptr_method != NULL);
		addMethod("MoveBase",ptr_method);
		MoveBaseFunc = reinterpret_cast<MoveBaseFuncType *>(ptr_method);
		ptr_method = NULL;

		ptr_method = makeRequiredMethod(&MobileControllerServiceRequired::RotateBase,"RotateBase");
		opros_assert(ptr_method != NULL);
		addMethod("RotateBase",ptr_method);
		RotateBaseFunc = reinterpret_cast<RotateBaseFuncType *>(ptr_method);
		ptr_method = NULL;

		ptr_method = makeRequiredMethod(&MobileControllerServiceRequired::StopBase,"StopBase");
		opros_assert(ptr_method != NULL);
		addMethod("StopBase",ptr_method);
		StopBaseFunc = reinterpret_cast<StopBaseFuncType *>(ptr_method);
		ptr_method = NULL;

		ptr_method = makeRequiredMethod(&MobileControllerServiceRequired::IsBaseRunning,"IsBaseRunning");
		opros_assert(ptr_method != NULL);
		addMethod("IsBaseRunning",ptr_method);
		IsBaseRunningFunc = reinterpret_cast<IsBaseRunningFuncType *>(ptr_method);
		ptr_method = NULL;
    }
};
#endif
