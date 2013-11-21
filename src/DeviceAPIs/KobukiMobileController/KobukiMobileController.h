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


#pragma once

#include "kobuki_driver/kobuki.hpp"
#include "MobileController.h"
#include "OprosMath.h"

#define MODULE_NAME "KobukiMobileController.dll"
#define ARR_CNT	2

#define LINEAR_MIN_LIMIT	-0.45
#define LINEAR_MAX_LIMIT	0.45
#define ANGULAR_MIN_LIMIT	-180.0 * M_PI / 180
#define ANGULAR_MAX_LIMIT	180.0 * M_PI / 180


class KobukiMobileController :
	public MobileController
{
public:
	KobukiMobileController(void);
	virtual ~KobukiMobileController(void);
	
	virtual int32_t Initialize(OPRoS::Property props);
	virtual int32_t Finalize(void);
	virtual int32_t Enable(void);
	virtual int32_t Disable(void);
	virtual int32_t SetProperty(OPRoS::Property props);
	virtual int32_t GetProperty(OPRoS::Property &props);

	//virtual int32_t GetOdometry(vector<OPRoS::Long> &Odometry);
	virtual int32_t SetVelocity(OPRoS::MobileVelocityData velocity);
	//virtual int32_t SetPosition(OPRoS::MobilePositionData position);
	virtual int32_t GetPosition(OPRoS::MobilePositionData &position);

protected:
	HMODULE hKobukiLinker;
	kobuki::Kobuki* kobuki;
	
	typedef void* (*GetKobukiOdometry)(double &x, double &y, double &theta);
	GetKobukiOdometry getOdometry;

	double ArrLimit[ARR_CNT][2];
	OPRoS::Property parameter;
};


