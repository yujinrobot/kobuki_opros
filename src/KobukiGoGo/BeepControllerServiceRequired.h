

#ifndef _BeepControllerService_REQUIRED_PORT_H
#define _BeepControllerService_REQUIRED_PORT_H

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
 * BeepControllerService : public RequiredServicePort
 *
 */
class BeepControllerServiceRequired
   :public RequiredServicePort
{
protected:

	typedef RequiredMethod<void> PlaySoundSequenceFuncType;
	PlaySoundSequenceFuncType *PlaySoundSequenceFunc;

public:
	//
	// Constructor
	//
	BeepControllerServiceRequired()
	{
            PlaySoundSequenceFunc = NULL;
            
	   setup();
	}

	// method implementation for required method
	void PlaySoundSequence(int8_t sequenceID)
	{
            opros_assert(PlaySoundSequenceFunc != NULL);
	
            (*PlaySoundSequenceFunc)(sequenceID);
		
	}

	

    // generated setup function
    virtual void setup()
    {
        Method *ptr_method;
    
        ptr_method = makeRequiredMethod(&BeepControllerServiceRequired::PlaySoundSequence,"PlaySoundSequence");
        opros_assert(ptr_method != NULL);
        addMethod("PlaySoundSequence",ptr_method);
        PlaySoundSequenceFunc = reinterpret_cast<PlaySoundSequenceFuncType *>(ptr_method);
        ptr_method = NULL;

    
    }
};
#endif
