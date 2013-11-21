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

#ifndef _KobukiGoGo_COMPONENT_H
#define _KobukiGoGo_COMPONENT_H
/*
 *  Generated sources by OPRoS Component Generator (OCG V2.0[Symbol])
 *   
 */
#include <Component.h>
#include <InputDataPort.h>
#include <OutputDataPort.h>
#include <InputEventPort.h>
#include <OutputEventPort.h>
#include <Event.h>
#include <OPRoSTypes.h>
#include <ApiTypes.h>
#include <GyroSensorData.h>
#include <MobileVelocityData.h>
#include <Windows.h>

#include "BeepControllerServiceRequired.h"



#include "LEDControllerServiceRequired.h"



#include "MobileControllerServiceRequired.h"

#define EVENT_ID_BTN0	"btn0_state_changed"
#define EVENT_ID_BTN1	"btn1_state_changed"
#define EVENT_ID_BTN2	"btn2_state_changed"

enum KOBUKIGOGO_MODE
{
	STOPPED, GOING_AHEAD, BUMPED, GOING_BACK, ROTATING, WHEEL_DROPPED, CLIFF_ENCOUNTERED
};

enum PLAYSEQUENCE_ID
{
	BUMP, BTN0, BTN1, BTN2, WHEEL_DROP, CLIFF
};

struct LED_PARAM
{
	int32_t nID;
	int32_t nPattern;
	int nColor;
};

class KobukiGoGo: public Component
{
protected:
//data
	InputDataPort< std::vector<OPRoS::Bool> > BumperSensorDataIn;
	InputDataPort< std::vector<OPRoS::GyroSensorData> > GyroSensorDataIn;
	InputDataPort< std::vector<OPRoS::Bool> > CliffSensorDataIn;
	InputDataPort< std::vector<OPRoS::Bool> > WheelDropSensorDataIn;

protected:
// event
	InputEventPort< OPRoS::Bool > Kobuki0BtnEvtIn;
	InputEventPort< OPRoS::Bool > Kobuki1BtnEvtIn;
	InputEventPort< OPRoS::Bool > Kobuki2BtnEvtIn;

protected:
// service
// method for required
	BeepControllerServiceRequired *ptrBeepControllerServiceReq;
// method for required
	LEDControllerServiceRequired *ptrLEDControllerServiceReq;
// method for required
	MobileControllerServiceRequired *ptrMobileControllerServiceReq;

protected:
// data


//event


// method for provider
	

// method for required
	


// symbol value generation
	

public:
	KobukiGoGo();
	KobukiGoGo(const std::string &compId);
	virtual ~KobukiGoGo();
	virtual void portSetup();

protected:
	virtual ReturnType onInitialize();
	virtual ReturnType onStart();
	virtual ReturnType onStop();
	virtual ReturnType onReset();
	virtual ReturnType onError();
	virtual ReturnType onRecover();
	virtual ReturnType onDestroy();

public:
	virtual ReturnType onEvent(Event *evt);
	virtual ReturnType onExecute();
	virtual ReturnType onUpdated();
	virtual ReturnType onPeriodChanged();

	KOBUKIGOGO_MODE mode, oldMode;
	LED_PARAM ledParam;
	DWORD bumpedTick;
};

#endif

