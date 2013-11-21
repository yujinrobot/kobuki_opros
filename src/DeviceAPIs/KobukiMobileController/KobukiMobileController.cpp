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


#include "KobukiMobileController.h"
#include "OprosPrintMessage.h"

#include <stdio.h>
#include <time.h>

#define MAX_LASTING_TIME	6 * 60 * 60 * 1000	// 6 hour
KobukiMobileController::KobukiMobileController(void)
{
	ArrLimit[0][0] = LINEAR_MIN_LIMIT;
	ArrLimit[0][1] = LINEAR_MAX_LIMIT;
	ArrLimit[1][0] = ANGULAR_MIN_LIMIT;
	ArrLimit[1][1] = ANGULAR_MAX_LIMIT;

}


KobukiMobileController::~KobukiMobileController(void)
{
	Finalize();
}


int32_t KobukiMobileController::Initialize(OPRoS::Property props)
{
	hKobukiLinker = LoadLibrary("KobukiLinker");
	if (hKobukiLinker)
	{
		 typedef void* (*GetKobukiInstance)();
		GetKobukiInstance getKobukiInstance = (GetKobukiInstance)GetProcAddress(hKobukiLinker, "GetKobukiInstance");
		getOdometry = (GetKobukiOdometry)GetProcAddress(hKobukiLinker, "GetOdometry");
		if (getKobukiInstance && getOdometry)
		{
			kobuki = (kobuki::Kobuki *)(getKobukiInstance());
			return API_SUCCESS;
		}
	}
	return API_ERROR;
}


int32_t KobukiMobileController::Finalize(void)
{
	if (hKobukiLinker)
	{
		typedef void (*ReleaseKobukiInstance)(kobuki::Kobuki* pkobuki);
		ReleaseKobukiInstance releaseKobukiInstance = (ReleaseKobukiInstance)GetProcAddress(hKobukiLinker, "ReleaseKobukiInstance");
		if (releaseKobukiInstance)
			releaseKobukiInstance(kobuki);

		FreeLibrary(hKobukiLinker);
	}

	return API_SUCCESS;
}


int32_t KobukiMobileController::Enable(void)
{
	return API_SUCCESS;
}


int32_t KobukiMobileController::Disable(void)
{
	return API_SUCCESS;
}


int32_t KobukiMobileController::SetProperty(OPRoS::Property props)
{
	Disable();
	parameter = props;
	Enable();

	return API_SUCCESS;
}


int32_t KobukiMobileController::GetProperty(OPRoS::Property &props)
{
	props = parameter;
	return API_SUCCESS;
}


//int32_t KobukiMobileController::GetOdometry(vector<OPRoS::Long> &Odometry)
//{
//}


int32_t KobukiMobileController::SetVelocity(OPRoS::MobileVelocityData velocity)
{
	double radianVelocity = velocity.theta * M_PI / 180.0;
	kobuki->setBaseControl(velocity.x, radianVelocity);
	return API_SUCCESS;
}

//int32_t KobukiMobileController::SetPosition(OPRoS::MobilePositionData position)
//{
//}


int32_t KobukiMobileController::GetPosition(OPRoS::MobilePositionData &position)
{
	double x, y, radian;
	getOdometry(x, y, radian);
	position.x = x;
	position.y = y;
	position.theta = radian * 180.0 / M_PI;
	
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
	return new KobukiMobileController();
}

void ReleaseAPI(OprosDevice *api)
{
	delete api;
}
#endif


