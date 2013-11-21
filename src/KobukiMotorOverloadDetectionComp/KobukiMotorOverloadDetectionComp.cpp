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

#include "KobukiMotorOverloadDetectionComp.h"
#include "OprosPrintMessage.h"

//
// constructor declaration
//
KobukiMotorOverloadDetectionComp::KobukiMotorOverloadDetectionComp()
{
	lastError = OPROS_SUCCESS;
	
	portSetup();
}

//
// constructor declaration (with name)
//
KobukiMotorOverloadDetectionComp::KobukiMotorOverloadDetectionComp(const std::string &name):Component(name)
{
	lastError = OPROS_SUCCESS;
	
	portSetup();
}

//
// destructor declaration
//

KobukiMotorOverloadDetectionComp::~KobukiMotorOverloadDetectionComp() 
{
	onDestroy();
}

ReturnType KobukiMotorOverloadDetectionComp::SetProperty(OPRoS::Property props)
{
	parameter = props;
	return lastError = OPROS_SUCCESS;
}

OPRoS::Property KobukiMotorOverloadDetectionComp::GetProperty()
{
	OPRoS::Property props = parameter;
	return props;
}

ReturnType KobukiMotorOverloadDetectionComp::GetError()
{
	PrintMessage("[INFO : KobukiMotorOverloadDetectionComp::GetError()]\n");

	return lastError;
}

ReturnType KobukiMotorOverloadDetectionComp::Enable()
{
	PrintMessage("[INFO : KobukiMotorOverloadDetectionComp::Enable()]\n");

	return lastError = OPROS_SUCCESS;
}

ReturnType KobukiMotorOverloadDetectionComp::Disable()
{
	PrintMessage("[INFO : KobukiMotorOverloadDetectionComp::Disable()]\n");

	return lastError = OPROS_SUCCESS;
}

std::vector<OPRoS::Bool> KobukiMotorOverloadDetectionComp::GetSensorValue()
{
	//PrintMessage("[INFO : KobukiMotorOverloadDetectionComp::GetSensorValue()]\n");

	std::vector<OPRoS::Bool> sensorValue(2);

	kobuki::CoreSensors::Data data;
	getCoresensorData(data);
	sensorValue[0].data = data.over_current & kobuki::CoreSensors::Flags::LeftWheel_OC;
	sensorValue[1].data = data.over_current & kobuki::CoreSensors::Flags::RightWheel_OC;

	return sensorValue;
}

void KobukiMotorOverloadDetectionComp::portSetup() 
{
	ProvidedServicePort *pa1;
	pa1=new MotorOverloadDetectionServiceProvided(this);
	addPort("MotorOverloadDetectionService",pa1);

	//data port setup
	addPort("motorOverloadState", &motorOverloadState);
}

// Call back Declaration
ReturnType KobukiMotorOverloadDetectionComp::onInitialize()
{
	hKobukiLinker = LoadLibrary("KobukiLinker");
	if (hKobukiLinker)
	{
		getCoresensorData = (GetCoresensorData)GetProcAddress(hKobukiLinker, "GetCoresensorData");
		if (getCoresensorData)
		{
			return lastError = OPROS_SUCCESS;
		}
	}

	return lastError = OPROS_INITIALIZE_API_ERROR;
}

ReturnType KobukiMotorOverloadDetectionComp::onStart()
{
	PrintMessage("[INFO : KobukiMotorOverloadDetectionComp::onStart()]\n");

	return lastError = OPROS_SUCCESS;
}
	
ReturnType KobukiMotorOverloadDetectionComp::onStop()
{
	PrintMessage("[INFO : KobukiMotorOverloadDetectionComp::onStop()]\n");

	return lastError = OPROS_SUCCESS;
}

ReturnType KobukiMotorOverloadDetectionComp::onReset()
{
	PrintMessage("[INFO : KobukiMotorOverloadDetectionComp::onReset()]\n");

	return OPROS_SUCCESS;
}

ReturnType KobukiMotorOverloadDetectionComp::onError()
{
	PrintMessage("[INFO : KobukiMotorOverloadDetectionComp::onError()]\n");

	return OPROS_SUCCESS;
}

ReturnType KobukiMotorOverloadDetectionComp::onRecover()
{
	PrintMessage("[INFO : KobukiMotorOverloadDetectionComp::onRecover()]\n");

	return OPROS_SUCCESS;
}

ReturnType KobukiMotorOverloadDetectionComp::onDestroy()
{
	PrintMessage("[INFO : KobukiMotorOverloadDetectionComp::onDestroy()]\n");
	if (hKobukiLinker)
		FreeLibrary(hKobukiLinker);

	return lastError = OPROS_SUCCESS;
}

ReturnType KobukiMotorOverloadDetectionComp::onEvent(Event *evt)
{
	//PrintMessage("[INFO : KobukiMotorOverloadDetectionComp::onEvent()]\n");

	return OPROS_SUCCESS;
}

ReturnType KobukiMotorOverloadDetectionComp::onExecute()
{
	//PrintMessage("[INFO : KobukiMotorOverloadDetectionComp::onExecute()]\n");

	std::vector<OPRoS::Bool> sensorValue = GetSensorValue();
	motorOverloadState.push(sensorValue);
	//printf_s("Motor overload Sensor : %d, %d\n", sensorValue[0].data, sensorValue[1].data);

	return lastError = OPROS_SUCCESS;
}
	
ReturnType KobukiMotorOverloadDetectionComp::onUpdated()
{
	//PrintMessage("[INFO : KobukiMotorOverloadDetectionComp::onUpdated()]\n");

	return OPROS_SUCCESS;
}

ReturnType KobukiMotorOverloadDetectionComp::onPeriodChanged()
{
	PrintMessage("[INFO : KobukiMotorOverloadDetectionComp::onPeriodChanged()]\n");

	return OPROS_SUCCESS;
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
	return new KobukiMotorOverloadDetectionComp();
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
	return new KobukiMotorOverloadDetectionComp();
}

void releaseComponent(Component *com)
{
	delete com;
}
#endif
#endif

