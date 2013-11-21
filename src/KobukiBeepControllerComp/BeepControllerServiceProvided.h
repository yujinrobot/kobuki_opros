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


#ifndef _BeepControllerService_PROVIDED_PORT_H
#define _BeepControllerService_PROVIDED_PORT_H

#include <OPRoSTypes.h>
#include <InputDataPort.h>
#include <OutputDataPort.h>
#include <InputEventPort.h>
#include <OutputEventPort.h>
#include <ProvidedServicePort.h>
#include <RequiredServicePort.h>
#include <ProvidedMethod.h>
#include <RequiredMethod.h>
#include <ApiTypes.h>


#ifndef _IBeepControllerService_CLASS_DEF
#define _IBeepControllerService_CLASS_DEF
/*
 * IBeepControllerService
 *
 *  The comonent inherits this class and implements methods. 
 */
class IBeepControllerService
{
 public:
    virtual void PlaySoundSequence(int8_t sequenceID)=0;
 };
#endif

/*
 * 
 * BeepControllerService : public ProvidedServicePort
 *
 */
class BeepControllerServiceProvided
	:public ProvidedServicePort, public IBeepControllerService
{
protected:
    IBeepControllerService *pcom;


   typedef ProvidedMethod<void> PlaySoundSequenceFuncType;
   PlaySoundSequenceFuncType *PlaySoundSequenceFunc;


public: // default method
   virtual void PlaySoundSequence(int8_t sequenceID)
   {
		opros_assert(PlaySoundSequenceFunc != NULL);
		(*PlaySoundSequenceFunc)(sequenceID);
   }


public:
    //
    // Constructor
    //
    BeepControllerServiceProvided(IBeepControllerService *fn)
    {
        pcom = fn;

        PlaySoundSequenceFunc = NULL;
        

        setup();
    }

    // generated setup function
    virtual void setup()
    {
        Method *ptr_method;
    
        ptr_method = makeProvidedMethod(&IBeepControllerService::PlaySoundSequence,pcom,"PlaySoundSequence");

        opros_assert(ptr_method != NULL);
        addMethod("PlaySoundSequence",ptr_method);
        PlaySoundSequenceFunc = reinterpret_cast<PlaySoundSequenceFuncType *>(ptr_method);
        ptr_method = NULL;

    
    }
};
#endif
