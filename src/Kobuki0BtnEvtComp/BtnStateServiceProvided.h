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


#ifndef _BtnStateService_PROVIDED_PORT_H
#define _BtnStateService_PROVIDED_PORT_H

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


#ifndef _IBtnStateService_CLASS_DEF
#define _IBtnStateService_CLASS_DEF
/*
 * IBtnStateService
 *
 *  The comonent inherits this class and implements methods. 
 */
class IBtnStateService
{
 public:
    virtual OPRoS::Bool GetBtnState()=0;
 };
#endif

/*
 * 
 * BtnStateService : public ProvidedServicePort
 *
 */
class BtnStateServiceProvided
	:public ProvidedServicePort, public IBtnStateService
{
protected:
    IBtnStateService *pcom;


   typedef ProvidedMethod<int> GetBtnStateFuncType;
   GetBtnStateFuncType *GetBtnStateFunc;


public: // default method
   virtual OPRoS::Bool GetBtnState()
   {
		opros_assert(GetBtnStateFunc != NULL);
		
            return (*GetBtnStateFunc)();
		
   }


public:
    //
    // Constructor
    //
    BtnStateServiceProvided(IBtnStateService *fn)
    {
        pcom = fn;

        GetBtnStateFunc = NULL;
        

        setup();
    }

    // generated setup function
    virtual void setup()
    {
        Method *ptr_method;
    
        ptr_method = makeProvidedMethod(&IBtnStateService::GetBtnState,pcom,"GetBtnState");

        opros_assert(ptr_method != NULL);
        addMethod("GetBtnState",ptr_method);
        GetBtnStateFunc = reinterpret_cast<GetBtnStateFuncType *>(ptr_method);
        ptr_method = NULL;

    
    }
};
#endif
