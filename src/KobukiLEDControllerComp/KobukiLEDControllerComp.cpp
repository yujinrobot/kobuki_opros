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

/*
 *  Generated sources by OPRoS Component Generator (OCG V2.1 [Symbol,Topic])
 *  
 */
#include <Component.h>
#include <InputDataPort.h>
#include <OutputDataPort.h>
#include <InputEventPort.h>
#include <OutputEventPort.h>
#include <OPRoSTypes.h>
#include <EventData.h>
#include <ServiceUtils.h>
#include <OprosPrintMessage.h>


#include "KobukiLEDControllerComp.h"

//
// constructor declaration
//
KobukiLEDControllerComp::KobukiLEDControllerComp()
{
	portSetup();
}

//
// constructor declaration (with name)
//
KobukiLEDControllerComp::KobukiLEDControllerComp(const std::string &name):Component(name)
{
	portSetup();
}

//
// destructor declaration
//

KobukiLEDControllerComp::~KobukiLEDControllerComp() {
	onDestroy();
}

ReturnType KobukiLEDControllerComp::SetProperty(OPRoS::Property props)
{
	// Check property integrity
	if(props.FindName("Version") == false) {
		return lastError = OPROS_BAD_INPUT_PARAMETER;
	}
	if(atof(props.GetValue("Version").c_str()) != 1.1) {
		return lastError = OPROS_BAD_INPUT_PARAMETER;
	}
		
	parameter = props;

	return lastError = OPROS_SUCCESS;
}

OPRoS::Property KobukiLEDControllerComp::GetProperty()
{
	OPRoS::Property retParameter = parameter;
	if (retParameter.GetProperty().size() == 0)
	{
		lastError = OPROS_FIND_PROPERTY_ERROR;
		retParameter.status = lastError;
	}

	LifecycleState lifeStat = getStatus() ;
	if (lifeStat == OPROS_CS_CREATED || lifeStat == OPROS_CS_DESTROYED)
	{
		lastError = OPROS_ERROR;
		retParameter.status = lastError;
	}
	return retParameter;
}

ReturnType KobukiLEDControllerComp::GetError()
{
	return lastError;
}

ReturnType KobukiLEDControllerComp::Enable()
{
	return lastError = OPROS_SUCCESS;
}

ReturnType KobukiLEDControllerComp::Disable()
{
	SetLED(0, 0, 0, 0, 0, 0, 0);
	return lastError = OPROS_SUCCESS;
}

/* 
* SetLED Specification
[ nID, nPattern, nData, nColor, nRepeat, nInterval, nBrightness ]

nId[0-2]: 
0: Both of LED
1: LED1
2: LED2

nPattern: 
0: Turn off
0 이외의 값: Turn on

nData: 
미사용

nColor:
1: Orange
2: Green
3: Red
이외의 값: Black

nRepeat: 
미사용

nInterva: 
미사용

nBrightness: 
미사용
*/
void KobukiLEDControllerComp::SetLED(int32_t nID,int32_t nPattern,int32_t nData,int32_t nColor,int32_t nRepeat,int32_t nInterval,int32_t nBrightness)
{
	kobuki::LedColour ledColor = kobuki::LedColour::Black;
	if (nPattern)
	{
		switch(nColor)
		{
		case 1:
			ledColor = kobuki::LedColour::Orange;
			break;
		case 2:
			ledColor = kobuki::LedColour::Green;
			break;
		case 3:
			ledColor = kobuki::LedColour::Red;
		}
	}
	
	switch(nID)
	{
	case 0:
		kobuki->setLed(kobuki::LedNumber::Led1, ledColor);
		kobuki->setLed(kobuki::LedNumber::Led2, ledColor);
		break;
	case 1:
		kobuki->setLed(kobuki::LedNumber::Led1, ledColor);
		break;
	case 2:
		kobuki->setLed(kobuki::LedNumber::Led2, ledColor);
		break;
	}
}



void KobukiLEDControllerComp::portSetup() {
	ProvidedServicePort *pa1;
	pa1=new LEDControllerServiceProvided(this);
	addPort("LEDControllerService",pa1);




	// export variable setup


}

// Call back Declaration
ReturnType KobukiLEDControllerComp::onInitialize()
{
	// user code here
	hKobukiLinker = LoadLibrary("KobukiLinker");
	if (hKobukiLinker)
	{
		 typedef void* (*GetKobukiInstance)();
		GetKobukiInstance getKobukiInstance = (GetKobukiInstance)GetProcAddress(hKobukiLinker, "GetKobukiInstance");
		if (getKobukiInstance)
		{
			kobuki = (kobuki::Kobuki *)(getKobukiInstance());
			return lastError = OPROS_SUCCESS;
		}
	}

	return lastError =  OPROS_PRECONDITION_NOT_MET;
}

ReturnType KobukiLEDControllerComp::onStart()
{
	// user code here
	return Enable();
}
	
ReturnType KobukiLEDControllerComp::onStop()
{
	// user code here
	return Disable();
}

ReturnType KobukiLEDControllerComp::onReset()
{
	// user code here
	if (onDestroy() != OPROS_SUCCESS)
		return lastError = OPROS_RESET_API_ERROR;

	if (onInitialize() != OPROS_SUCCESS)
		return lastError = OPROS_RESET_API_ERROR;

	if (Enable() != OPROS_SUCCESS)
		return lastError = OPROS_RESET_API_ERROR;

	return lastError = OPROS_SUCCESS;
}

ReturnType KobukiLEDControllerComp::onError()
{
	// user code here
	return Disable();
}

ReturnType KobukiLEDControllerComp::onRecover()
{
	// user code here
	if (onDestroy() != OPROS_SUCCESS)
		return lastError = OPROS_RECOVER_API_ERROR;

	if (onInitialize() != OPROS_SUCCESS)
		return lastError = OPROS_RECOVER_API_ERROR;

	return lastError = OPROS_SUCCESS;
}

ReturnType KobukiLEDControllerComp::onDestroy()
{
	// user code here
	if (hKobukiLinker)
	{
		typedef void (*ReleaseKobukiInstance)(kobuki::Kobuki* pkobuki);
		ReleaseKobukiInstance releaseKobukiInstance = (ReleaseKobukiInstance)GetProcAddress(hKobukiLinker, "ReleaseKobukiInstance");
		if (releaseKobukiInstance)
			releaseKobukiInstance(kobuki);

		FreeLibrary(hKobukiLinker);
	}
	
	return lastError =  OPROS_SUCCESS;
}

ReturnType KobukiLEDControllerComp::onEvent(Event *evt)
{
	// user code here
	return lastError =  OPROS_SUCCESS;
}

ReturnType KobukiLEDControllerComp::onExecute()
{
	// user code here
	/*static int color = 0;
	SetLED(0,0,0,color, 0, 0, 0);
	if (++color > 2)
		color = 0;*/
	return lastError =  OPROS_SUCCESS;
}
	
ReturnType KobukiLEDControllerComp::onUpdated()
{
	// user code here
	return lastError =  OPROS_SUCCESS;
}

ReturnType KobukiLEDControllerComp::onPeriodChanged()
{
	// user code here
	return lastError =  OPROS_SUCCESS;
}







#ifndef MAKE_STATIC_COMPONENT
#ifdef WIN32

extern "C"
{
__declspec(dllexport) Component *getComponent();
__declspec(dllexport) void releaseComponent(Component *pcom);
}

Component *getComponent()
{
	return new KobukiLEDControllerComp();
}

void releaseComponent(Component *com)
{
	delete com;
}

#else
extern "C"
{
	Component *getComponent();
	void releaseComponent(Component *com);
}
Component *getComponent()
{
	return new KobukiLEDControllerComp();
}

void releaseComponent(Component *com)
{
	delete com;
}
#endif
#endif