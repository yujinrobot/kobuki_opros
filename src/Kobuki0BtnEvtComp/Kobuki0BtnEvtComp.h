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


#ifndef _Kobuki0BtnEvtComp_COMPONENT_H
#define _Kobuki0BtnEvtComp_COMPONENT_H
/*
 *  Generated sources by OPRoS Component Generator (OCG V2.0[Symbol])
 *   
 */

#include "kobuki_driver/kobuki.hpp"

#include <Component.h>
#include <InputDataPort.h>
#include <OutputDataPort.h>
#include <InputEventPort.h>
#include <OutputEventPort.h>
#include <Event.h>
#include <OPRoSTypes.h>


#include "BtnStateServiceProvided.h"

#define EVENT_ID	"btn0_state_changed"

class Kobuki0BtnEvtComp: public Component
	,public IBtnStateService
{
protected:
// event
	OutputEventPort< OPRoS::Bool > BtnEvent;

protected:
// service
// method for provider
	IBtnStateService *ptrBtnStateService;

public:
virtual OPRoS::Bool GetBtnState();

protected:
// data


//event


// method for provider
	

// method for required
	


// symbol value generation
	

public:
	Kobuki0BtnEvtComp();
	Kobuki0BtnEvtComp(const std::string &compId);
	virtual ~Kobuki0BtnEvtComp();
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

protected:
	HMODULE hKobukiLinker;
	//kobuki::Kobuki* kobuki;
	OPRoS::Bool					_iLastState;

	typedef void* (*GetCoresensorData)(kobuki::CoreSensors::Data &coresenData);
	GetCoresensorData getCoresensorData;

	//	Last Error
	ReturnType lastError;
};

#endif

