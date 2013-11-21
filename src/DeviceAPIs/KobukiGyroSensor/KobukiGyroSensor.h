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
#include "GyroSensor.h"


#define MODULE_NAME "KobukiGyroSensor.dll"

class KobukiGyroSensor :
	public GyroSensor
{
public:
	KobukiGyroSensor(void);
	virtual ~KobukiGyroSensor(void);
		
	virtual int32_t Initialize(OPRoS::Property props);
	virtual int32_t Finalize(void);
	virtual int32_t Enable(void);
	virtual int32_t Disable(void);
	virtual int32_t SetProperty(OPRoS::Property props);
	virtual int32_t GetProperty(OPRoS::Property &props);
	
	virtual int32_t GetSensorValue(std::vector<OPRoS::GyroSensorData> &sensorValue);

protected:
	HMODULE hKobukiLinker;
	//kobuki::Kobuki* kobuki;
	OPRoS::Property parameter;	

	typedef void* (*GetGyroData)(double &yaw);
	GetGyroData getGyroData;
};

