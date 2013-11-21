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
#include <OprosPrintMessage.h>


#include "KobukiBeepControllerComp.h"

//
// constructor declaration
//
KobukiBeepControllerComp::KobukiBeepControllerComp()
{
	portSetup();
}

//
// constructor declaration (with name)
//
KobukiBeepControllerComp::KobukiBeepControllerComp(const std::string &name):Component(name)
{
	portSetup();
}

//
// destructor declaration
//

KobukiBeepControllerComp::~KobukiBeepControllerComp() {
}


void KobukiBeepControllerComp::PlaySoundSequence(int8_t sequenceID)
{
	kobuki::SoundSequences seqEnum = (kobuki::SoundSequences)sequenceID;
	kobuki->playSoundSequence(seqEnum);
}



void KobukiBeepControllerComp::portSetup() {
	ProvidedServicePort *pa1;
	pa1=new BeepControllerServiceProvided(this);
	addPort("BeepControllerService",pa1);




	// export variable setup


}

// Call back Declaration
ReturnType KobukiBeepControllerComp::onInitialize()
{
	// user code here
	hKobukiLinker = LoadLibrary("KobukiLinker");
	if (hKobukiLinker)
	{
		 typedef void* (*GetKobukiInstance)();
		GetKobukiInstance getKobukiInstance = (GetKobukiInstance)GetProcAddress(hKobukiLinker, "GetKobukiInstance");
		if (getKobukiInstance)
		{
			kobuki = (kobuki::Kobuki *)(getKobukiInstance());
			return OPROS_SUCCESS;
		}
	}

	return OPROS_SUCCESS;
}

ReturnType KobukiBeepControllerComp::onStart()
{
	// user code here
	return OPROS_SUCCESS;
}
	
ReturnType KobukiBeepControllerComp::onStop()
{
	// user code here
	return OPROS_SUCCESS;
}

ReturnType KobukiBeepControllerComp::onReset()
{
	// user code here
	return OPROS_SUCCESS;
}

ReturnType KobukiBeepControllerComp::onError()
{
	// user code here
	return OPROS_SUCCESS;
}

ReturnType KobukiBeepControllerComp::onRecover()
{
	// user code here
	return OPROS_SUCCESS;
}

ReturnType KobukiBeepControllerComp::onDestroy()
{
	// user code here
	if (hKobukiLinker)
	{
		typedef void (*ReleaseKobukiInstance)(kobuki::Kobuki* pkobuki);
		ReleaseKobukiInstance releaseKobukiInstance = (ReleaseKobukiInstance)GetProcAddress(hKobukiLinker, "ReleaseKobukiInstance");
		if (releaseKobukiInstance)
			releaseKobukiInstance(kobuki);

		FreeLibrary(hKobukiLinker);
	}

	return OPROS_SUCCESS;
}

ReturnType KobukiBeepControllerComp::onEvent(Event *evt)
{
	// user code here
	return OPROS_SUCCESS;
}

ReturnType KobukiBeepControllerComp::onExecute()
{
	// user code here
	/*static int i = 0;
	PlaySoundSequence(i++);*/
	return OPROS_SUCCESS;
}
	
ReturnType KobukiBeepControllerComp::onUpdated()
{
	// user code here
	return OPROS_SUCCESS;
}

ReturnType KobukiBeepControllerComp::onPeriodChanged()
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
	return new KobukiBeepControllerComp();
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
	return new KobukiBeepControllerComp();
}

void releaseComponent(Component *com)
{
	delete com;
}
#endif
#endif