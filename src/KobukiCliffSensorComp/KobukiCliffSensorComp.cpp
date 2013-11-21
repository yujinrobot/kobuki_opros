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

#include "KobukiCliffSensorComp.h"
#include "OprosPrintMessage.h"

//
// constructor declaration
//
KobukiCliffSensorComp::KobukiCliffSensorComp()
{
	lastError = OPROS_SUCCESS;
	
	portSetup();
}

//
// constructor declaration (with name)
//
KobukiCliffSensorComp::KobukiCliffSensorComp(const std::string &name):Component(name)
{
	lastError = OPROS_SUCCESS;
	
	portSetup();
}

//
// destructor declaration
//

KobukiCliffSensorComp::~KobukiCliffSensorComp() 
{
	onDestroy();
}

ReturnType KobukiCliffSensorComp::SetProperty(OPRoS::Property props)
{
	parameter = props;
	return lastError = OPROS_SUCCESS;
}

OPRoS::Property KobukiCliffSensorComp::GetProperty()
{
	OPRoS::Property props = parameter;
	return props;
}

ReturnType KobukiCliffSensorComp::GetError()
{
	PrintMessage("[INFO : KobukiCliffSensorComp::GetError()]\n");

	return lastError;
}

ReturnType KobukiCliffSensorComp::Enable()
{
	PrintMessage("[INFO : KobukiCliffSensorComp::Enable()]\n");

	return lastError = OPROS_SUCCESS;
}

ReturnType KobukiCliffSensorComp::Disable()
{
	PrintMessage("[INFO : KobukiCliffSensorComp::Disable()]\n");

	return lastError = OPROS_SUCCESS;
}

std::vector<OPRoS::Bool> KobukiCliffSensorComp::GetSensorValue()
{
	//PrintMessage("[INFO : KobukiCliffSensorComp::GetSensorValue()]\n");

	std::vector<OPRoS::Bool> sensorValue(3);

	kobuki::CoreSensors::Data data;
	getCoresensorData(data);
	sensorValue[0].data = data.cliff & kobuki::CoreSensors::Flags::LeftCliff;
	sensorValue[1].data = data.cliff & kobuki::CoreSensors::Flags::CenterCliff;
	sensorValue[2].data = data.cliff & kobuki::CoreSensors::Flags::RightCliff;

	return sensorValue;
}

void KobukiCliffSensorComp::portSetup() 
{
	ProvidedServicePort *pa1;
	pa1=new KobukiCliffSensorServiceProvided(this);
	addPort("KobukiCliffSensorService",pa1);

	//data port setup
	addPort("cliffState", &cliffState);
}

// Call back Declaration
ReturnType KobukiCliffSensorComp::onInitialize()
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

ReturnType KobukiCliffSensorComp::onStart()
{
	PrintMessage("[INFO : KobukiCliffSensorComp::onStart()]\n");

	return lastError = OPROS_SUCCESS;
}
	
ReturnType KobukiCliffSensorComp::onStop()
{
	PrintMessage("[INFO : KobukiCliffSensorComp::onStop()]\n");

	return lastError = OPROS_SUCCESS;
}

ReturnType KobukiCliffSensorComp::onReset()
{
	PrintMessage("[INFO : KobukiCliffSensorComp::onReset()]\n");

	return OPROS_SUCCESS;
}

ReturnType KobukiCliffSensorComp::onError()
{
	PrintMessage("[INFO : KobukiCliffSensorComp::onError()]\n");

	return OPROS_SUCCESS;
}

ReturnType KobukiCliffSensorComp::onRecover()
{
	PrintMessage("[INFO : KobukiCliffSensorComp::onRecover()]\n");

	return OPROS_SUCCESS;
}

ReturnType KobukiCliffSensorComp::onDestroy()
{
	PrintMessage("[INFO : KobukiCliffSensorComp::onDestroy()]\n");
	
	if (hKobukiLinker)
		FreeLibrary(hKobukiLinker);

	return lastError = OPROS_SUCCESS;
}

ReturnType KobukiCliffSensorComp::onEvent(Event *evt)
{
	//PrintMessage("[INFO : KobukiCliffSensorComp::onEvent()]\n");

	return OPROS_SUCCESS;
}

ReturnType KobukiCliffSensorComp::onExecute()
{
	//PrintMessage("[INFO : KobukiCliffSensorComp::onExecute()]\n");

	std::vector<OPRoS::Bool> sensorValue = GetSensorValue();
	cliffState.push(sensorValue);
	//printf_s("Cliff Sensor : %d, %d, %d\n", sensorValue[0].data, sensorValue[1].data, sensorValue[2].data);

	return lastError = OPROS_SUCCESS;
}
	
ReturnType KobukiCliffSensorComp::onUpdated()
{
	//PrintMessage("[INFO : KobukiCliffSensorComp::onUpdated()]\n");

	return OPROS_SUCCESS;
}

ReturnType KobukiCliffSensorComp::onPeriodChanged()
{
	PrintMessage("[INFO : KobukiCliffSensorComp::onPeriodChanged()]\n");

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
	return new KobukiCliffSensorComp();
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
	return new KobukiCliffSensorComp();
}

void releaseComponent(Component *com)
{
	delete com;
}
#endif
#endif

