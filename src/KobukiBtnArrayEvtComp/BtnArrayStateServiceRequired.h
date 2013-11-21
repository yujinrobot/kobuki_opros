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


#ifndef _BtnArrayStateService_REQUIRED_PORT_H
#define _BtnArrayStateService_REQUIRED_PORT_H

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




/*
 * 
 * BtnArrayStateService : public RequiredServicePort
 *
 */
class BtnArrayStateServiceRequired
   :public RequiredServicePort
{
protected:

	typedef RequiredMethod<std::vector<OPRoS::Bool> > GetBtnArrayStateFuncType;
	GetBtnArrayStateFuncType *GetBtnArrayStateFunc;

public:
	//
	// Constructor
	//
	BtnArrayStateServiceRequired()
	{
            GetBtnArrayStateFunc = NULL;
            
	   setup();
	}

	// method implementation for required method
	std::vector<OPRoS::Bool> GetBtnArrayState()
	{
            opros_assert(GetBtnArrayStateFunc != NULL);
	
            return (*GetBtnArrayStateFunc)();
		
	}

	

    // generated setup function
    virtual void setup()
    {
        Method *ptr_method;
    
        ptr_method = makeRequiredMethod(&BtnArrayStateServiceRequired::GetBtnArrayState,"GetBtnArrayState");
        opros_assert(ptr_method != NULL);
        addMethod("GetBtnArrayState",ptr_method);
        GetBtnArrayStateFunc = reinterpret_cast<GetBtnArrayStateFuncType *>(ptr_method);
        ptr_method = NULL;

    
    }
};
#endif
