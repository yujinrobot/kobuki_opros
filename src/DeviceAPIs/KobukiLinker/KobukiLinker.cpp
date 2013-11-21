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


// KobukiLinker.cpp : DLL 응용 프로그램을 위해 내보낸 함수를 정의합니다.
//

#include "stdafx.h"
#include "KobukiLinker.h"

kobuki::Kobuki* _kobuki = NULL;
ecl::Slot<ecl::Void>* _slot = NULL;
ecl::Pose2D<double> _pose;
double _yaw = 0;
kobuki::CoreSensors::Data _coresenData;

void Feedback()
{
	// odometry
	ecl::Pose2D<double> pose_update;
	ecl::linear_algebra::Vector3d pose_update_rates;
	
	_kobuki->updateOdometry(pose_update, pose_update_rates);

	_pose *= pose_update;

	// wheel state
	//double l, r, lrate, rrate;
	//_kobuki->getWheelJointStates(l, lrate, r, rrate);

	// gyro
	ecl::Angle<double> yaw = _kobuki->getHeading(); // yaw, radian
	_yaw = (double)yaw;

	// core sensor data
	_coresenData = _kobuki->getCoreSensorData();
}


KOBUKILINKER_API void* GetKobukiInstance()
{
	if (!_kobuki)
	{
		// Get portname
		char buf[256] = {0,};
		char iniDir[MAX_PATH];
		GetModuleFileNameA(GetModuleHandleA("KobukiLinker"), iniDir, sizeof(iniDir));
		*(strrchr(iniDir, '\\')+1)='\0';
		sprintf_s(iniDir, "%s\\KobukiPortName.ini", iniDir);
		GetPrivateProfileStringA("KOBUKI_PORT", "NAME", "COM1", buf, sizeof(buf), iniDir);

		kobuki::Parameters parameters;
		parameters.sigslots_namespace = "/mobile_base";
		parameters.device_port = buf;
		parameters.enable_acceleration_limiter = false;

		try
		{
			_pose.setIdentity();
			_slot = new ecl::Slot<ecl::Void>(&Feedback);

			_kobuki = new kobuki::Kobuki();
			_kobuki->init(parameters);
			_kobuki->enable();

			_slot->connect("/mobile_base/stream_data");
		}
		catch (ecl::StandardException& e)
		{
			std::cout << e.what() << std::endl;

			return FALSE;
		}
	}
	return _kobuki;
}

KOBUKILINKER_API void ReleaseKobukiInstance(kobuki::Kobuki* pkobuki)
{
	if (_slot)
	{
		delete _slot;
		_slot = NULL;
	}

	if (_kobuki)
	{
		_kobuki->~Kobuki();
		_kobuki = NULL;
	}
	pkobuki = NULL;
}

KOBUKILINKER_API void GetOdometry(double &x, double &y, double &theta)
{
	x = _pose.x(); // meter
	y = _pose.y(); // meter
	theta = _pose.heading(); // radian

}

KOBUKILINKER_API void GetGyroData(double &yaw)
{
	yaw = _yaw;	// radian
}

KOBUKILINKER_API void GetCoresensorData(kobuki::CoreSensors::Data &coresenData)
{
	memcpy((void*)&coresenData, (void*)&_coresenData, sizeof(kobuki::CoreSensors::Data));
}

// 내보낸 클래스의 생성자입니다.
// 클래스 정의를 보려면 KobukiLinker.h를 참조하십시오.
/*CKobukiLinker::CKobukiLinker()
{
}


CKobukiLinker::~CKobukiLinker(void)
{
}


// 내보낸 변수의 예제입니다.
KOBUKILINKER_API int nKobukiLinker=0;

// 내보낸 함수의 예제입니다.
KOBUKILINKER_API int fnKobukiLinker(void)
{
	return 42;
}
*/