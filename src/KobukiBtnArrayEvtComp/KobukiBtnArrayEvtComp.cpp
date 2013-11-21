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



#include "KobukiBtnArrayEvtComp.h"

#include <tchar.h>

//
// constructor declaration
//
KobukiBtnArrayEvtComp::KobukiBtnArrayEvtComp()
{

	
	portSetup();
}

//
// constructor declaration (with name)
//
KobukiBtnArrayEvtComp::KobukiBtnArrayEvtComp(const std::string &name):Component(name)
{

	
	portSetup();
}

//
// destructor declaration
//

KobukiBtnArrayEvtComp::~KobukiBtnArrayEvtComp() {
}


std::vector<OPRoS::Bool>KobukiBtnArrayEvtComp::GetBtnArrayState( )
{
	std::vector<OPRoS::Bool>ret;
	ret.resize(3, false);
	kobuki::CoreSensors::Data data;
	getCoresensorData(data);
	ret[0].data = data.buttons & kobuki::CoreSensors::Flags::Button0;
	ret[1].data = data.buttons & kobuki::CoreSensors::Flags::Button1;
	ret[2].data = data.buttons & kobuki::CoreSensors::Flags::Button2;
	return ret;
}


void KobukiBtnArrayEvtComp::portSetup() {
	//event port setup
	addPort("BtnArrayEvent", &BtnArrayEvent);

	ProvidedServicePort *pa1;
	pa1=new BtnArrayStateServiceProvided(this);
	addPort("BtnArrayStateService",pa1);




	// export variable setup
}

// Call back Declaration
ReturnType KobukiBtnArrayEvtComp::onInitialize()
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

ReturnType KobukiBtnArrayEvtComp::onStart()
{
	// user code here
	_iLastState = GetBtnArrayState();
	return OPROS_SUCCESS;
}
	
ReturnType KobukiBtnArrayEvtComp::onStop()
{	
	// user code here
	return OPROS_SUCCESS;
}

ReturnType KobukiBtnArrayEvtComp::onReset()
{
	// user code here
	return OPROS_SUCCESS;
}

ReturnType KobukiBtnArrayEvtComp::onError()
{
	// user code here
	return OPROS_SUCCESS;
}

ReturnType KobukiBtnArrayEvtComp::onRecover()
{
	// user code here
	return OPROS_SUCCESS;
}

ReturnType KobukiBtnArrayEvtComp::onDestroy()
{
	// user code here
	if (hKobukiLinker)
		FreeLibrary(hKobukiLinker);

	return OPROS_SUCCESS;
}

ReturnType KobukiBtnArrayEvtComp::onEvent(Event *evt)
{
	// user code here
	return OPROS_SUCCESS;
}

ReturnType KobukiBtnArrayEvtComp::onExecute()
{
	// 현재의 버튼 상태가 이전의 버튼 상태와 다른 경우, 이벤트 포트를 통해 이벤트 전송
	std::vector<OPRoS::Bool>iNewState = GetBtnArrayState();
	bool bChanged = false;
	for(int i = 0; i < iNewState.size(); i++)
	{
		if (_iLastState[i].data != iNewState[i].data)
		{
			_iLastState[i] = iNewState[i];
			bChanged = true;
		}
	}

	if (bChanged)
	{
		EventData< std::vector<OPRoS::Bool>> evt;
		evt.setId(EVENT_ID);
		evt.setContentData(_iLastState);
		BtnArrayEvent.push(&evt);
	}

	//printf_s("BtnEvt0 : %d\n", _iLastState.data);
	return OPROS_SUCCESS;
}
	
ReturnType KobukiBtnArrayEvtComp::onUpdated()
{
	// user code here
	return OPROS_SUCCESS;
}

ReturnType KobukiBtnArrayEvtComp::onPeriodChanged()
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
	return new KobukiBtnArrayEvtComp();
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
	return new KobukiBtnArrayEvtComp();
}

void releaseComponent(Component *com)
{
	delete com;
}
#endif
#endif