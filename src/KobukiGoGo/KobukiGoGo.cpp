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
#include <OprosMath.h>

#include "KobukiGoGo.h"

//
// constructor declaration
//
KobukiGoGo::KobukiGoGo()
	:BumperSensorDataIn(OPROS_FIFO,1)
	,GyroSensorDataIn(OPROS_FIFO,1)
	,CliffSensorDataIn(OPROS_FIFO,1)
	,WheelDropSensorDataIn(OPROS_FIFO,1)
{
	ptrMobileControllerServiceReq = NULL;

	ptrLEDControllerServiceReq = NULL;

	ptrBeepControllerServiceReq = NULL;


	
	portSetup();
}

//
// constructor declaration (with name)
//
KobukiGoGo::KobukiGoGo(const std::string &name):Component(name)
	,BumperSensorDataIn(OPROS_FIFO,1)
	,GyroSensorDataIn(OPROS_FIFO,1)
	,CliffSensorDataIn(OPROS_FIFO,1)
	,WheelDropSensorDataIn(OPROS_FIFO,1)
{
	ptrMobileControllerServiceReq = NULL;

	ptrLEDControllerServiceReq = NULL;

	ptrBeepControllerServiceReq = NULL;


	
	portSetup();
}

//
// destructor declaration
//

KobukiGoGo::~KobukiGoGo() {
}

void KobukiGoGo::portSetup() {
	ptrMobileControllerServiceReq=new MobileControllerServiceRequired();
	addPort("MobileControllerServiceReq",ptrMobileControllerServiceReq);

	ptrLEDControllerServiceReq=new LEDControllerServiceRequired();
	addPort("LEDControllerServiceReq",ptrLEDControllerServiceReq);

	ptrBeepControllerServiceReq=new BeepControllerServiceRequired();
	addPort("BeepControllerServiceReq",ptrBeepControllerServiceReq);

	//event port setup
	addPort("Kobuki2BtnEvtIn", &Kobuki2BtnEvtIn);
	Kobuki2BtnEvtIn.setOwner(this);

	//event port setup
	addPort("Kobuki1BtnEvtIn", &Kobuki1BtnEvtIn);
	Kobuki1BtnEvtIn.setOwner(this);

	//event port setup
	addPort("Kobuki0BtnEvtIn", &Kobuki0BtnEvtIn);
	Kobuki0BtnEvtIn.setOwner(this);

	//data port setup
	addPort("WheelDropSensorDataIn", &WheelDropSensorDataIn);

	//data port setup
	addPort("CliffSensorDataIn", &CliffSensorDataIn);

	//data port setup
	addPort("GyroSensorDataIn", &GyroSensorDataIn);

	//data port setup
	addPort("BumperSensorDataIn", &BumperSensorDataIn);




	// export variable setup


}

// Call back Declaration
ReturnType KobukiGoGo::onInitialize()
{
	// user code here
	return OPROS_SUCCESS;
}

ReturnType KobukiGoGo::onStart()
{
	// user code here
	mode = KOBUKIGOGO_MODE::STOPPED;
	ledParam.nColor = 0;
	ledParam.nID = 0;
	ledParam.nPattern = 0;
	return OPROS_SUCCESS;
}
	
ReturnType KobukiGoGo::onStop()
{
	// user code here
	return OPROS_SUCCESS;
}

ReturnType KobukiGoGo::onReset()
{
	// user code here
	return OPROS_SUCCESS;
}

ReturnType KobukiGoGo::onError()
{
	// user code here
	return OPROS_SUCCESS;
}

ReturnType KobukiGoGo::onRecover()
{
	// user code here
	return OPROS_SUCCESS;
}

ReturnType KobukiGoGo::onDestroy()
{
	// user code here
	return OPROS_SUCCESS;
}

ReturnType KobukiGoGo::onEvent(Event *evt)
{
	// user code here
	OPRoS::Bool bBtnPushed;
	std::string evtID = evt->getId();

	// Button events
	if (evtID == EVENT_ID_BTN0 || evtID == EVENT_ID_BTN1 || evtID == EVENT_ID_BTN2)
	{
		bBtnPushed = opros_any_cast< OPRoS::Bool >(evt->getContent());
		if (bBtnPushed.data)
		{
			if (evtID == EVENT_ID_BTN0)
			{
				ptrBeepControllerServiceReq->PlaySoundSequence(PLAYSEQUENCE_ID::BTN0);
				ptrMobileControllerServiceReq->SetVelocity(OPRoS::MobileVelocityData(0.1, 0, 0));
				mode = KOBUKIGOGO_MODE::GOING_AHEAD;
			}
			else if (evtID == EVENT_ID_BTN1)
			{
				ptrBeepControllerServiceReq->PlaySoundSequence(PLAYSEQUENCE_ID::BTN1);
				bumpedTick = GetTickCount();
				ptrMobileControllerServiceReq->SetVelocity(OPRoS::MobileVelocityData(-0.1, 0, 0));
				mode = KOBUKIGOGO_MODE::GOING_BACK;
			}
			else if (evtID == EVENT_ID_BTN2)
			{
				ptrBeepControllerServiceReq->PlaySoundSequence(PLAYSEQUENCE_ID::BTN2);
				ptrMobileControllerServiceReq->StopBase();
				mode = KOBUKIGOGO_MODE::STOPPED;
			}
		}
	}

	return OPROS_SUCCESS;
}

ReturnType KobukiGoGo::onExecute()
{
	// user code here
	opros_any	*pData=NULL;
	
	char prtStr[255];
	
	// Gyro Sensor
	if (GyroSensorDataIn.getSize() > 0)
	{
		pData = GyroSensorDataIn.pop();
		std::vector<OPRoS::GyroSensorData> gyroData = opros_any_cast< std::vector<OPRoS::GyroSensorData> >( *pData );
		for each(OPRoS::GyroSensorData gd in gyroData)
		{
			sprintf_s(prtStr, "[GyroSensor] zAngle=%f, zAngleRate=%f\0", gd.zAngle, gd.zAngleRate);
		}
	}
	
	// Mobile position
	OPRoS::MobilePositionData posData = ptrMobileControllerServiceReq->GetPosition();
	printf_s("%s, [Mobile Position] x=%f, y=%f, theta=%f\n", prtStr, posData.x, posData.y, posData.theta);

	// Bumper Sensor
	if (BumperSensorDataIn.getSize() > 0)
	{
		pData = BumperSensorDataIn.pop();
		std::vector<OPRoS::Bool> bumperData = opros_any_cast< std::vector<OPRoS::Bool> >( *pData );
		for each(OPRoS::Bool bd in bumperData)
		{
			if (bd.data)
				mode = KOBUKIGOGO_MODE::BUMPED;
		}
	}
	
	// Wheeldrop Sensor
	if (WheelDropSensorDataIn.getSize() > 0)
	{
		pData = WheelDropSensorDataIn.pop();
		std::vector<OPRoS::Bool> wheelDropData = opros_any_cast< std::vector<OPRoS::Bool> >( *pData );
		for each(OPRoS::Bool bd in wheelDropData)
		{
			if (bd.data)
				mode = KOBUKIGOGO_MODE::WHEEL_DROPPED;
		}
	}
	
	// Cliff Sensor
	if (CliffSensorDataIn.getSize() > 0)
	{
		pData = CliffSensorDataIn.pop();
		std::vector<OPRoS::Bool> cliffData = opros_any_cast< std::vector<OPRoS::Bool> >( *pData );
		for each(OPRoS::Bool bd in cliffData)
		{
			if (bd.data)
				mode = KOBUKIGOGO_MODE::CLIFF_ENCOUNTERED;
		}
	}
	
	// Play beep sequence
	if (oldMode != mode)
	{
		switch(mode)
		{
		case KOBUKIGOGO_MODE::BUMPED:
			ptrBeepControllerServiceReq->PlaySoundSequence(PLAYSEQUENCE_ID::BUMP);
			break;
		case KOBUKIGOGO_MODE::WHEEL_DROPPED:
			ptrBeepControllerServiceReq->PlaySoundSequence(PLAYSEQUENCE_ID::WHEEL_DROP);
			break;
		case KOBUKIGOGO_MODE::CLIFF_ENCOUNTERED:
			ptrBeepControllerServiceReq->PlaySoundSequence(PLAYSEQUENCE_ID::CLIFF);
			break;
		}
	}

	oldMode = mode;

	DWORD curTick = GetTickCount();
	int16_t rotatingDeg;
	float64_t angularVel;
	switch(mode)
	{
	case KOBUKIGOGO_MODE::GOING_AHEAD:
		ptrLEDControllerServiceReq->SetLED(ledParam.nID, ledParam.nPattern, 0, ledParam.nColor,0, 0, 0);
		ledParam.nID = (ledParam.nID == 2) ? 0 : ledParam.nID + 1;
		ledParam.nPattern = (ledParam.nPattern == 1) ? 0 : ledParam.nPattern + 1;
		ledParam.nColor = (ledParam.nColor == 3) ? 0 : ledParam.nColor + 1;
		break;
	case KOBUKIGOGO_MODE::BUMPED:
		bumpedTick = curTick;
		ptrBeepControllerServiceReq->PlaySoundSequence(PLAYSEQUENCE_ID::BUMP);
		ptrMobileControllerServiceReq->SetVelocity(OPRoS::MobileVelocityData(-0.1, 0, 0));
		mode = KOBUKIGOGO_MODE::GOING_BACK;
		break;
	case KOBUKIGOGO_MODE::GOING_BACK:
		if ((curTick - bumpedTick) > 500)
		{
			rotatingDeg = (float64_t)(rand() % 180); 
			angularVel = (float64_t)rotatingDeg * M_PI / 180.0;
			//ptrMobileControllerServiceReq->SetVelocity(OPRoS::MobileVelocityData(0, 0, angularVel));
			ptrMobileControllerServiceReq->SetVelocity(OPRoS::MobileVelocityData(0, 0, rotatingDeg));
			mode = KOBUKIGOGO_MODE::ROTATING;
		}
		break;
	case KOBUKIGOGO_MODE::ROTATING:
		if ((curTick - bumpedTick) > 1000)
		{
			ptrMobileControllerServiceReq->SetVelocity(OPRoS::MobileVelocityData(0.1, 0, 0));
			mode = KOBUKIGOGO_MODE::GOING_AHEAD;
		}
		break;
	case KOBUKIGOGO_MODE::WHEEL_DROPPED:
	case KOBUKIGOGO_MODE::CLIFF_ENCOUNTERED:
		ptrMobileControllerServiceReq->SetVelocity(OPRoS::MobileVelocityData(0, 0, 0));
		mode = KOBUKIGOGO_MODE::STOPPED;
		break;
	}

	return OPROS_SUCCESS;
}
	
ReturnType KobukiGoGo::onUpdated()
{
	// user code here
	return OPROS_SUCCESS;
}

ReturnType KobukiGoGo::onPeriodChanged()
{
	// user code here
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
	return new KobukiGoGo();
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
	return new KobukiGoGo();
}

void releaseComponent(Component *com)
{
	delete com;
}
#endif
#endif

