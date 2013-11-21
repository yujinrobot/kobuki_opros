

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




/*
 * 
 * LEDControllerService : public RequiredServicePort
 *
 */
class LEDControllerServiceRequired
   :public RequiredServicePort
{
protected:

	typedef RequiredMethod<void> SetLEDFuncType;
	SetLEDFuncType *SetLEDFunc;

public:
	//
	// Constructor
	//
	LEDControllerServiceRequired()
	{
            SetLEDFunc = NULL;
            
	   setup();
	}

	// method implementation for required method
	void SetLED(int32_t nID,int32_t nPattern,int32_t nData,int32_t nColor,int32_t nRepeat,int32_t nInterval,int32_t nBrightness)
	{
            opros_assert(SetLEDFunc != NULL);
	
            (*SetLEDFunc)(nID,nPattern,nData,nColor,nRepeat,nInterval,nBrightness);
		
	}

	

    // generated setup function
    virtual void setup()
    {
        Method *ptr_method;
    
        ptr_method = makeRequiredMethod(&LEDControllerServiceRequired::SetLED,"SetLED");
        opros_assert(ptr_method != NULL);
        addMethod("SetLED",ptr_method);
        SetLEDFunc = reinterpret_cast<SetLEDFuncType *>(ptr_method);
        ptr_method = NULL;

    
    }
};
#endif
