

#ifndef _LEDControllerService_PROVIDED_PORT_H
#define _LEDControllerService_PROVIDED_PORT_H

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

#ifndef _ILEDControllerService_CLASS_DEF
#define _ILEDControllerService_CLASS_DEF
/*
 * ILEDControllerService
 *
 *  The comonent inherits this class and implements methods. 
 */
class ILEDControllerService
{
 public:
    virtual ReturnType SetProperty(OPRoS::Property props)=0;
	virtual OPRoS::Property GetProperty()=0;
    virtual ReturnType GetError()=0;
	virtual ReturnType Enable()=0;
	virtual ReturnType Disable()=0;
	virtual void SetLED(int32_t nID,int32_t nPattern,int32_t nData,int32_t nColor,int32_t nRepeat,int32_t nInterval,int32_t nBrightness)=0;
 };
#endif

/*
 * 
 * LEDControllerService : public ProvidedServicePort
 *
 */
class LEDControllerServiceProvided
	:public ProvidedServicePort, public ILEDControllerService
{
protected:
    ILEDControllerService *pcom;


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

   typedef ProvidedMethod<void> SetLEDFuncType;
   SetLEDFuncType *SetLEDFunc;


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

	virtual void SetLED(int32_t nID,int32_t nPattern,int32_t nData,int32_t nColor,int32_t nRepeat,int32_t nInterval,int32_t nBrightness)
   {
		opros_assert(SetLEDFunc != NULL);
		(*SetLEDFunc)(nID,nPattern,nData,nColor,nRepeat,nInterval,nBrightness);
   }


public:
    //
    // Constructor
    //
    LEDControllerServiceProvided(ILEDControllerService *fn)
    {
        pcom = fn;

        SetPropertyFunc = NULL;
        GetPropertyFunc = NULL;
        GetErrorFunc = NULL;
		EnableFunc = NULL;
		DisableFunc = NULL;
		SetLEDFunc = NULL;
        

        setup();
    }

    // generated setup function
    virtual void setup()
    {
        Method *ptr_method;
    
        ptr_method = makeProvidedMethod(&ILEDControllerService::SetProperty,pcom,"SetProperty");
		opros_assert(ptr_method != NULL);
		addMethod("SetProperty",ptr_method);
		SetPropertyFunc = reinterpret_cast<SetPropertyFuncType *>(ptr_method);
		ptr_method = NULL;

		ptr_method = makeProvidedMethod(&ILEDControllerService::GetProperty,pcom,"GetProperty");
		opros_assert(ptr_method != NULL);
		addMethod("GetProperty",ptr_method);
		GetPropertyFunc = reinterpret_cast<GetPropertyFuncType *>(ptr_method);
		ptr_method = NULL;

		ptr_method = makeProvidedMethod(&ILEDControllerService::GetError,pcom,"GetError");
		opros_assert(ptr_method != NULL);
		addMethod("GetError",ptr_method);
		GetErrorFunc = reinterpret_cast<GetErrorFuncType *>(ptr_method);
		ptr_method = NULL;

		ptr_method = makeProvidedMethod(&ILEDControllerService::Enable,pcom,"Enable");
		opros_assert(ptr_method != NULL);
		addMethod("Enable",ptr_method);
		EnableFunc = reinterpret_cast<EnableFuncType *>(ptr_method);
		ptr_method = NULL;

		ptr_method = makeProvidedMethod(&ILEDControllerService::Disable,pcom,"Disable");
		opros_assert(ptr_method != NULL);
		addMethod("Disable",ptr_method);
		DisableFunc = reinterpret_cast<DisableFuncType *>(ptr_method);
		ptr_method = NULL;

		ptr_method = makeProvidedMethod(&ILEDControllerService::SetLED,pcom,"SetLED");

        opros_assert(ptr_method != NULL);
        addMethod("SetLED",ptr_method);
        SetLEDFunc = reinterpret_cast<SetLEDFuncType *>(ptr_method);
        ptr_method = NULL;

    
    }
};
#endif
