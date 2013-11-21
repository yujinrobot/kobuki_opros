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


#include "KobukiGyroSensor.h"

KobukiGyroSensor::KobukiGyroSensor(void)
{
}


KobukiGyroSensor::~KobukiGyroSensor(void)
{
	Finalize();
}


int32_t KobukiGyroSensor::Initialize(OPRoS::Property props)
{
	hKobukiLinker = LoadLibrary("KobukiLinker");
	if (hKobukiLinker)
	{
		//typedef void* (*GetKobukiInstance)();
		//GetKobukiInstance getKobukiInstance = (GetKobukiInstance)GetProcAddress(hKobukiLinker, "GetKobukiInstance");
		getGyroData = (GetGyroData)GetProcAddress(hKobukiLinker, "GetGyroData");
		//if (getKobukiInstance)
		if (getGyroData)
		{
			//kobuki = (kobuki::Kobuki *)(getKobukiInstance());
			return API_SUCCESS;
		}
	}
	return API_ERROR;
}


int32_t KobukiGyroSensor::Finalize(void)
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


int32_t KobukiGyroSensor::Enable(void)
{
	return API_SUCCESS;
}


int32_t KobukiGyroSensor::Disable(void)
{
	return API_SUCCESS;
}


int32_t KobukiGyroSensor::SetProperty(OPRoS::Property props)
{
	Disable();
	parameter = props;
	Enable();
	
	return API_SUCCESS;
}


int32_t KobukiGyroSensor::GetProperty(OPRoS::Property &props)
{
	props = parameter;
	return API_SUCCESS;
}


int32_t KobukiGyroSensor::GetSensorValue(std::vector<OPRoS::GyroSensorData> &sensorValue)
{
	sensorValue.resize(1);
	//kobuki::Inertia::Data data = kobuki->getInertiaData();
	//sensorValue[0].zAngle = data.angle;
	//sensorValue[0].zAngleRate = data.angle_rate;
	//printf_s("Gyro Angle:%f, AngleRate :%f\n", sensorValue[0].zAngle, sensorValue[0].zAngleRate);
	double yaw_radian;
	getGyroData(yaw_radian);
	sensorValue[0].zAngle = yaw_radian * 180.0 / M_PI;
	/*getGyroData(sensorValue[0].zAngle);*/
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
	return new KobukiGyroSensor();
}

void ReleaseAPI(OprosDevice *api)
{
	delete api;
}
#endif

