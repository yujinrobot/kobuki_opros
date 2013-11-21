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

#include "KobukiWheelDropSensorComp.h"
#include "OprosPrintMessage.h"

//
// constructor declaration
//
KobukiWheelDropSensorComp::KobukiWheelDropSensorComp()
{
	lastError = OPROS_SUCCESS;
	
	portSetup();
}

//
// constructor declaration (with name)
//
KobukiWheelDropSensorComp::KobukiWheelDropSensorComp(const std::string &name):Component(name)
{
	lastError = OPROS_SUCCESS;
	
	portSetup();
}

//
// destructor declaration
//

KobukiWheelDropSensorComp::~KobukiWheelDropSensorComp() 
{
	onDestroy();
}

ReturnType KobukiWheelDropSensorComp::SetProperty(OPRoS::Property props)
{
	parameter = props;
	return lastError = OPROS_SUCCESS;
}

OPRoS::Property KobukiWheelDropSensorComp::GetProperty()
{
	OPRoS::Property props = parameter;
	return props;
}

ReturnType KobukiWheelDropSensorComp::GetError()
{
	PrintMessage("[INFO : KobukiWheelDropSensorComp::GetError()]\n");

	return lastError;
}

ReturnType KobukiWheelDropSensorComp::Enable()
{
	PrintMessage("[INFO : KobukiWheelDropSensorComp::Enable()]\n");

	return lastError = OPROS_SUCCESS;
}

ReturnType KobukiWheelDropSensorComp::Disable()
{
	PrintMessage("[INFO : KobukiWheelDropSensorComp::Disable()]\n");

	return lastError = OPROS_SUCCESS;
}

std::vector<OPRoS::Bool> KobukiWheelDropSensorComp::GetSensorValue()
{
	//PrintMessage("[INFO : KobukiWheelDropSensorComp::GetSensorValue()]\n");

	std::vector<OPRoS::Bool> sensorValue(2);

	kobuki::CoreSensors::Data data;
	getCoresensorData(data);
	sensorValue[0].data = data.wheel_drop & kobuki::CoreSensors::Flags::LeftWheel;
	sensorValue[1].data = data.wheel_drop & kobuki::CoreSensors::Flags::RightWheel;
	
	return sensorValue;
}

void KobukiWheelDropSensorComp::portSetup() 
{
	ProvidedServicePort *pa1;
	pa1=new KobukiWheelDropSensorServiceProvided(this);
	addPort("KobukiWheelDropSensorService",pa1);

	//data port setup
	addPort("wheelDropState", &wheelDropState);
}

// Call back Declaration
ReturnType KobukiWheelDropSensorComp::onInitialize()
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

ReturnType KobukiWheelDropSensorComp::onStart()
{
	PrintMessage("[INFO : KobukiWheelDropSensorComp::onStart()]\n");

	return lastError = OPROS_SUCCESS;
}
	
ReturnType KobukiWheelDropSensorComp::onStop()
{
	PrintMessage("[INFO : KobukiWheelDropSensorComp::onStop()]\n");

	return lastError = OPROS_SUCCESS;
}

ReturnType KobukiWheelDropSensorComp::onReset()
{
	PrintMessage("[INFO : KobukiWheelDropSensorComp::onReset()]\n");

	return OPROS_SUCCESS;
}

ReturnType KobukiWheelDropSensorComp::onError()
{
	PrintMessage("[INFO : KobukiWheelDropSensorComp::onError()]\n");

	return OPROS_SUCCESS;
}

ReturnType KobukiWheelDropSensorComp::onRecover()
{
	PrintMessage("[INFO : KobukiWheelDropSensorComp::onRecover()]\n");

	return OPROS_SUCCESS;
}

ReturnType KobukiWheelDropSensorComp::onDestroy()
{
	PrintMessage("[INFO : KobukiWheelDropSensorComp::onDestroy()]\n");
	if (hKobukiLinker)
		FreeLibrary(hKobukiLinker);

	return lastError = OPROS_SUCCESS;
}

ReturnType KobukiWheelDropSensorComp::onEvent(Event *evt)
{
	//PrintMessage("[INFO : KobukiWheelDropSensorComp::onEvent()]\n");

	return OPROS_SUCCESS;
}

ReturnType KobukiWheelDropSensorComp::onExecute()
{
	//PrintMessage("[INFO : KobukiWheelDropSensorComp::onExecute()]\n");

	std::vector<OPRoS::Bool> sensorValue = GetSensorValue();
	wheelDropState.push(sensorValue);
	//printf_s("Wheel Drop Sensor : %d, %d\n", sensorValue[0].data, sensorValue[1].data);

	return lastError = OPROS_SUCCESS;
}
	
ReturnType KobukiWheelDropSensorComp::onUpdated()
{
	//PrintMessage("[INFO : KobukiWheelDropSensorComp::onUpdated()]\n");

	return OPROS_SUCCESS;
}

ReturnType KobukiWheelDropSensorComp::onPeriodChanged()
{
	PrintMessage("[INFO : KobukiWheelDropSensorComp::onPeriodChanged()]\n");

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
	return new KobukiWheelDropSensorComp();
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
	return new KobukiWheelDropSensorComp();
}

void releaseComponent(Component *com)
{
	delete com;
}
#endif
#endif

