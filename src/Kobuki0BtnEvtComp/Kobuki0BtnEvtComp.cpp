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



#include "Kobuki0BtnEvtComp.h"

#include <tchar.h>

//
// constructor declaration
//
Kobuki0BtnEvtComp::Kobuki0BtnEvtComp()
{

	
	portSetup();
}

//
// constructor declaration (with name)
//
Kobuki0BtnEvtComp::Kobuki0BtnEvtComp(const std::string &name):Component(name)
{

	
	portSetup();
}

//
// destructor declaration
//

Kobuki0BtnEvtComp::~Kobuki0BtnEvtComp() {
}


OPRoS::Bool Kobuki0BtnEvtComp::GetBtnState( )
{
	OPRoS::Bool ret;

	kobuki::CoreSensors::Data data;
	getCoresensorData(data);
	ret.data = data.buttons & kobuki::CoreSensors::Flags::Button0;
	return ret;
}


void Kobuki0BtnEvtComp::portSetup() {
	//event port setup
	addPort("BtnEvent", &BtnEvent);

	ProvidedServicePort *pa1;
	pa1=new BtnStateServiceProvided(this);
	addPort("BtnStateService",pa1);




	// export variable setup
}

// Call back Declaration
ReturnType Kobuki0BtnEvtComp::onInitialize()
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

ReturnType Kobuki0BtnEvtComp::onStart()
{
	// user code here
	_iLastState = GetBtnState();
	return OPROS_SUCCESS;
}
	
ReturnType Kobuki0BtnEvtComp::onStop()
{	
	// user code here
	return OPROS_SUCCESS;
}

ReturnType Kobuki0BtnEvtComp::onReset()
{
	// user code here
	return OPROS_SUCCESS;
}

ReturnType Kobuki0BtnEvtComp::onError()
{
	// user code here
	return OPROS_SUCCESS;
}

ReturnType Kobuki0BtnEvtComp::onRecover()
{
	// user code here
	return OPROS_SUCCESS;
}

ReturnType Kobuki0BtnEvtComp::onDestroy()
{
	// user code here
	if (hKobukiLinker)
		FreeLibrary(hKobukiLinker);

	return OPROS_SUCCESS;
}

ReturnType Kobuki0BtnEvtComp::onEvent(Event *evt)
{
	// user code here
	return OPROS_SUCCESS;
}

ReturnType Kobuki0BtnEvtComp::onExecute()
{
	// 현재의 버튼 상태가 이전의 버튼 상태와 다른 경우, 이벤트 포트를 통해 이벤트 전송
	OPRoS::Bool iNewState = GetBtnState();
	if (_iLastState.data != iNewState.data)
	{
		_iLastState = iNewState;
		EventData<OPRoS::Bool> evt;
		evt.setId(EVENT_ID);
		evt.setContentData(_iLastState);
		BtnEvent.push(&evt);
	}
	//printf_s("BtnEvt0 : %d\n", _iLastState.data);
	return OPROS_SUCCESS;
}
	
ReturnType Kobuki0BtnEvtComp::onUpdated()
{
	// user code here
	return OPROS_SUCCESS;
}

ReturnType Kobuki0BtnEvtComp::onPeriodChanged()
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
	return new Kobuki0BtnEvtComp();
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
	return new Kobuki0BtnEvtComp();
}

void releaseComponent(Component *com)
{
	delete com;
}
#endif
#endif