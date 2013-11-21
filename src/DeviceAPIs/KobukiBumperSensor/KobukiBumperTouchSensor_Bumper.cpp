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


#include "KobukiBumperTouchSensor_Bumper.h"

KobukiBumperTouchSensor_Bumper::KobukiBumperTouchSensor_Bumper(void)
{
}


KobukiBumperTouchSensor_Bumper::~KobukiBumperTouchSensor_Bumper(void)
{
	Finalize();
}


int32_t KobukiBumperTouchSensor_Bumper::Initialize(OPRoS::Property props)
{
	hKobukiLinker = LoadLibrary("KobukiLinker");
	if (hKobukiLinker)
	{
		 //typedef void* (*GetKobukiInstance)();
		//GetKobukiInstance getKobukiInstance = (GetKobukiInstance)GetProcAddress(hKobukiLinker, "GetKobukiInstance");
		getCoresensorData = (GetCoresensorData)GetProcAddress(hKobukiLinker, "GetCoresensorData");
		//if (getKobukiInstance)
		 if (getCoresensorData)
		{
			//kobuki = (kobuki::Kobuki *)(getKobukiInstance());
			return API_SUCCESS;
		}
	}
	return API_ERROR;
}


int32_t KobukiBumperTouchSensor_Bumper::Finalize(void)
{
	if (hKobukiLinker)
	{
		/*typedef void (*ReleaseKobukiInstance)(kobuki::Kobuki* pkobuki);
		ReleaseKobukiInstance releaseKobukiInstance = (ReleaseKobukiInstance)GetProcAddress(hKobukiLinker, "ReleaseKobukiInstance");
		if (releaseKobukiInstance)
			releaseKobukiInstance(kobuki);*/

		FreeLibrary(hKobukiLinker);
	}
	
	return API_SUCCESS;
}


int32_t KobukiBumperTouchSensor_Bumper::Enable(void)
{
	return API_SUCCESS;
}


int32_t KobukiBumperTouchSensor_Bumper::Disable(void)
{
	return API_SUCCESS;
}


int32_t KobukiBumperTouchSensor_Bumper::SetProperty(OPRoS::Property props)
{
	Disable();
	parameter = props;
	Enable();

	return API_SUCCESS;
}


int32_t KobukiBumperTouchSensor_Bumper::GetProperty(OPRoS::Property &props)
{
	props = parameter;
	return API_SUCCESS;
}


int32_t KobukiBumperTouchSensor_Bumper::GetSensorValue(std::vector<OPRoS::Bool> &sensorValue)
{
	sensorValue.resize(3, false);
	//kobuki::CoreSensors::Data data = kobuki->getCoreSensorData();
	kobuki::CoreSensors::Data data;
	getCoresensorData(data);
	sensorValue[0].data = data.bumper & kobuki::CoreSensors::Flags::LeftBumper;
	sensorValue[1].data = data.bumper & kobuki::CoreSensors::Flags::CenterBumper;
	sensorValue[2].data = data.bumper & kobuki::CoreSensors::Flags::RightBumper;
	return API_SUCCESS;
}


#if defined(WIN32)
extern "C"
{
__declspec(dllexport) OprosDevice *GetAPI();
__declspec(dllexport) void ReleaseAPI(OprosDevice *api);
}

OprosDevice *GetAPI()
{
	return new KobukiBumperTouchSensor_Bumper();
}

void ReleaseAPI(OprosDevice *api)
{
	delete api;
}
#endif

