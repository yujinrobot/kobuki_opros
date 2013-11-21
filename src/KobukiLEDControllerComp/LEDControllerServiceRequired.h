

#ifndef _LEDControllerService_REQUIRED_PORT_H
#define _LEDControllerService_REQUIRED_PORT_H

#include <OPRoSTypes.h>
#include <InputDataPort.h>
#include <OutputDataPort.h>
#include <InputEventPort.h>
#include <OutputEventPort.h>
#include <ProvidedServicePort.h>
#include <RequiredServicePort.h>
#include <ProvidedMethod.h>
#include <RequiredMethod.h>
#include <ApiTypes.h>
#include <Property.h>



/*
 * 
 * LEDControllerService : public RequiredServicePort
 *
 */
class LEDControllerServiceRequired
   :public RequiredServicePort
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

	typedef RequiredMethod<void> SetLEDFuncType;
	SetLEDFuncType *SetLEDFunc;

public:
	//
	// Constructor
	//
	LEDControllerServiceRequired()
	{
            SetPropertyFunc = NULL;
		GetPropertyFunc = NULL;
		GetErrorFunc = NULL;
		EnableFunc = NULL;
		DisableFunc = NULL;
		SetLEDFunc = NULL;
            
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

	void SetLED(int32_t nID,int32_t nPattern,int32_t nData,int32_t nColor,int32_t nRepeat,int32_t nInterval,int32_t nBrightness)
	{
            opros_assert(SetLEDFunc != NULL);
	
            (*SetLEDFunc)(nID,nPattern,nData,nColor,nRepeat,nInterval,nBrightness);
		
	}

	

    // generated setup function
    virtual void setup()
    {
        Method *ptr_method;

		ptr_method = makeRequiredMethod(&LEDControllerServiceRequired::SetProperty,"SetProperty");
		opros_assert(ptr_method != NULL);
		addMethod("SetProperty",ptr_method);
		SetPropertyFunc = reinterpret_cast<SetPropertyFuncType *>(ptr_method);
		ptr_method = NULL;

		ptr_method = makeRequiredMethod(&LEDControllerServiceRequired::GetProperty,"GetProperty");
		opros_assert(ptr_method != NULL);
		addMethod("GetProperty",ptr_method);
		GetPropertyFunc = reinterpret_cast<GetPropertyFuncType *>(ptr_method);
		ptr_method = NULL;

		ptr_method = makeRequiredMethod(&LEDControllerServiceRequired::GetError,"GetError");
		opros_assert(ptr_method != NULL);
		addMethod("GetError",ptr_method);
		GetErrorFunc = reinterpret_cast<GetErrorFuncType *>(ptr_method);
		ptr_method = NULL;

		ptr_method = makeRequiredMethod(&LEDControllerServiceRequired::Enable,"Enable");
		opros_assert(ptr_method != NULL);
		addMethod("Enable",ptr_method);
		EnableFunc = reinterpret_cast<EnableFuncType *>(ptr_method);
		ptr_method = NULL;

		ptr_method = makeRequiredMethod(&LEDControllerServiceRequired::Disable,"Disable");
		opros_assert(ptr_method != NULL);
		addMethod("Disable",ptr_method);
		DisableFunc = reinterpret_cast<DisableFuncType *>(ptr_method);
		ptr_method = NULL;
    
        ptr_method = makeRequiredMethod(&LEDControllerServiceRequired::SetLED,"SetLED");
        opros_assert(ptr_method != NULL);
        addMethod("SetLED",ptr_method);
        SetLEDFunc = reinterpret_cast<SetLEDFuncType *>(ptr_method);
        ptr_method = NULL;

    
    }
};
#endif
