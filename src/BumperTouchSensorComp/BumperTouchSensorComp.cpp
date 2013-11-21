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

#include "BumperTouchSensorComp.h"
#include "OprosPrintMessage.h"

//#include "../CommonLib/StatusTester.h"


//
// constructor declaration
//
BumperTouchSensorComp::BumperTouchSensorComp()
{
	hOprosAPI = NULL;
	bumperTouch = NULL;
	lastError = OPROS_SUCCESS;
	
	portSetup();

}

//
// constructor declaration (with name)
//
BumperTouchSensorComp::BumperTouchSensorComp(const std::string &name):Component(name)
{
	hOprosAPI = NULL;
	bumperTouch = NULL;
	lastError = OPROS_SUCCESS;
	
	portSetup();

}

//
// destructor declaration
//

BumperTouchSensorComp::~BumperTouchSensorComp() 
{
	onDestroy();
}

ReturnType BumperTouchSensorComp::SetProperty(OPRoS::Property props)
{
	// Check property integrity
	if(props.FindName("Version") == false) {
		return lastError = OPROS_BAD_INPUT_PARAMETER;
	}
	if(atof(props.GetValue("Version").c_str()) != 1.1) {
		return lastError = OPROS_BAD_INPUT_PARAMETER;
	}

	if(props.FindName("count") == false) {
		return lastError = OPROS_BAD_INPUT_PARAMETER;
	}

	int count = atoi(props.GetValue("count").c_str());
	char name[1024];
	for(int i = 0; i < count; i++) {
		sprintf(name, "Type%d", i);	
		if(props.FindName(name) == false)	return lastError = OPROS_BAD_INPUT_PARAMETER;
		if (props.GetValue(name)!="BUMPER")	return lastError = OPROS_BAD_INPUT_PARAMETER;
	
		sprintf(name, "x%d", i);		if(props.FindName(name) == false)	return lastError = OPROS_BAD_INPUT_PARAMETER;
		sprintf(name, "y%d", i);		if(props.FindName(name) == false)	return lastError = OPROS_BAD_INPUT_PARAMETER;
		sprintf(name, "z%d", i);		if(props.FindName(name) == false)	return lastError = OPROS_BAD_INPUT_PARAMETER;
		sprintf(name, "roll%d", i);		if(props.FindName(name) == false)	return lastError = OPROS_BAD_INPUT_PARAMETER;
		sprintf(name, "pitch%d", i);	if(props.FindName(name) == false)	return lastError = OPROS_BAD_INPUT_PARAMETER;
		sprintf(name, "yaw%d", i);		if(props.FindName(name) == false)	return lastError = OPROS_BAD_INPUT_PARAMETER;
	}
	
	parameter = props;

	// Set property
	if(bumperTouch != NULL) {
		int32_t ret = bumperTouch->SetProperty(props);
		if(ret == API_ERROR) {
			return lastError = OPROS_CALL_API_ERROR;
		}
	}
	return lastError = OPROS_SUCCESS;
}

OPRoS::Property BumperTouchSensorComp::GetProperty()
{
	OPRoS::Property retParameter = parameter;
	if (retParameter.GetProperty().size() == 0)
	{
		lastError = OPROS_FIND_PROPERTY_ERROR;
		retParameter.status = lastError;
	}

	LifecycleState lifeStat = getStatus() ;
	if (lifeStat == OPROS_CS_CREATED || lifeStat == OPROS_CS_DESTROYED)
	{
		lastError = OPROS_ERROR;
		retParameter.status = lastError;
	}
	return retParameter;
}

ReturnType BumperTouchSensorComp::GetError()
{
	PrintMessage("[INFO : BumperTouchSensorComp::GetError()]\n");

	return lastError;
}

ReturnType BumperTouchSensorComp::Enable()
{
	PrintMessage("[INFO : BumperTouchSensorComp::Enable()]\n");

	if(bumperTouch == NULL) {
		PrintMessage("[ERROR : BumperTouchSensorComp::Enable()] : The handle of API is not created.\n");
		return lastError = OPROS_PRECONDITION_NOT_MET;
	}

	int32_t ret = bumperTouch->Enable();
	if(ret == API_ERROR) {
		return lastError = OPROS_ENABLE_API_ERROR;
	}
	else if(ret == API_NOT_SUPPORTED) {
		return lastError = OPROS_API_NOT_SUPPORTED_ERROR;
	}
	
	return lastError = OPROS_SUCCESS;
}

ReturnType BumperTouchSensorComp::Disable()
{
	PrintMessage("[INFO : BumperTouchSensorComp::Disable()]\n");

	if(bumperTouch == NULL) {
		PrintMessage("[ERROR : BumperTouchSensorComp::Disable()] : The handle of API is not created.\n");
		return lastError = OPROS_PRECONDITION_NOT_MET;
	}

	int32_t ret = bumperTouch->Disable();
	if(ret == API_ERROR) {
		return lastError = OPROS_DISABLE_API_ERROR;
	}
	else if(ret == API_NOT_SUPPORTED) {
		return lastError = OPROS_API_NOT_SUPPORTED_ERROR;
	}
	
	return lastError = OPROS_SUCCESS;
}

std::vector<OPRoS::Bool> BumperTouchSensorComp::GetSensorValue()
{
	PrintMessage("[INFO : BumperTouchSensorComp::GetSensorValue()]\n");

	std::vector<OPRoS::Bool> sensorValue;

	LifecycleState lifeStat = getStatus();
	if (lifeStat != OPROS_CS_ACTIVE)
	{
		lastError = OPROS_ERROR;
	}
	else if(bumperTouch == NULL) {
		PrintMessage("[ERROR : BumperTouchSensorComp::GetSensorValue()] : The handle of API is not created.\n");
		lastError = OPROS_PRECONDITION_NOT_MET;
	}
	else
	{
		int32_t ret = bumperTouch->GetSensorValue(sensorValue);
		if(ret == API_ERROR) {
			lastError = OPROS_CALL_API_ERROR;
		}
		else if(ret == API_NOT_SUPPORTED) {
			lastError = OPROS_API_NOT_SUPPORTED_ERROR;
		}
		else {
			lastError = OPROS_SUCCESS;
		}
	}

	if (lastError != OPROS_SUCCESS)
	{
		sensorValue.resize(1);
		sensorValue[0].status = OPROS_ERROR;
	}

	return sensorValue;
}

void BumperTouchSensorComp::portSetup() 
{
	ProvidedServicePort *pa1;
	pa1=new BumperTouchSensorServiceProvided(this);
	addPort("BumperTouchSensorService",pa1);

	//data port setup
	addPort("bumperTouchState", &bumperTouchState);
}

// Call back Declaration
ReturnType BumperTouchSensorComp::onInitialize()
{
	// Check if already initialized
	if (hOprosAPI != NULL)
		return lastError = OPROS_SUCCESS;

	PrintMessage("[INFO : BumperTouchSensorComp::onInitialize()]\n");

	//OPRoS::Property parameter;
	std::map<std::string, std::string> temp = getPropertyMap();
	parameter.SetProperty(temp);
	
	if(parameter.FindName("ApiName") == false) {
		PrintMessage("[ERROR : BumperTouchSensorComp::onInitialize()] : Can't find the ApiName in property.\n");
		return lastError = OPROS_FIND_PROPERTY_ERROR;
	}

	
#if defined(WIN32)
	hOprosAPI = LoadLibrary((LPCSTR)parameter.GetValue("ApiName").c_str());
	if(hOprosAPI == NULL) {
		PrintMessage("[ERROR : BumperTouchSensorComp::onInitialize()] : Can't find the %s\n", parameter.GetValue("ApiName").c_str());
		return lastError = OPROS_FIND_DLL_ERROR;
	}
	
	GET_OPROS_DEVICE getOprosAPI;
	getOprosAPI = (GET_OPROS_DEVICE)GetProcAddress(hOprosAPI, "GetAPI");
	if(getOprosAPI == NULL) {
		PrintMessage("[ERROR : BumperTouchSensorComp::onInitialize()] : Can't get a handle of GetAPI Funtion\n");
		FreeLibrary(hOprosAPI);
		hOprosAPI = NULL;
		return lastError = OPROS_LOAD_DLL_ERROR;
	}
#else
	hOprosAPI = dlopen(parameter.GetValue("ApiName").c_str(), RTLD_LAZY);
	if(hOprosAPI == NULL) {
		PrintMessage("[ERROR : BumperTouchSensorComp::onInitialize()] : Can't find the %s\n", parameter.GetValue("ApiName").c_str());
		return lastError = OPROS_FIND_DLL_ERROR;
	}

	GET_OPROS_API getOprosAPI;
	getOprosAPI = (GET_OPROS_API)dlsym(hOprosAPI, "GetAPI");
	char *error = dlerror();
	if(error != NULL) {
		PrintMessage("[ERROR : BumperTouchSensorComp::onInitialize()] : Can't get a handle of GetAPI Funtion\n");
		dlclose(hOprosAPI);
		hOprosAPI = NULL;
		return lastError = OPROS_LOAD_DLL_ERROR;
	}
#endif
	
	bumperTouch = dynamic_cast<BumperTouchSensor *>(getOprosAPI());
	if(bumperTouch == NULL) {
		PrintMessage("[ERROR : BumperTouchSensorComp::onInitialize()] : Can't get a handle of BumperTouchSensor API\n");
#if defined(WIN32)
		FreeLibrary(hOprosAPI);
#else
		dlclose(hOprosAPI);
#endif
		hOprosAPI = NULL;
		return lastError = OPROS_LOAD_DLL_ERROR;
	}

	if(bumperTouch->Initialize(parameter) != API_SUCCESS) {
		delete bumperTouch;
		bumperTouch = NULL;

#if defined(WIN32)
		FreeLibrary(hOprosAPI);
#else
		dlclose(hOprosAPI);
#endif
		hOprosAPI = NULL;
		return lastError = OPROS_INITIALIZE_API_ERROR;
	}

#ifdef __STATUS_TEST_MODE__
	START_TEST(this);
#endif
	
	return lastError = OPROS_SUCCESS;
}

ReturnType BumperTouchSensorComp::onStart()
{
	PrintMessage("[INFO : BumperTouchSensorComp::onStart()]\n");

	return Enable();
}
	
ReturnType BumperTouchSensorComp::onStop()
{
	PrintMessage("[INFO : BumperTouchSensorComp::onStop()]\n");

	return Disable();
}

ReturnType BumperTouchSensorComp::onReset()
{
	PrintMessage("[INFO : BumperTouchSensorComp::onReset()]\n");
	if(bumperTouch == NULL) {
		PrintMessage("[ERROR : BumperTouchSensorComp::onReset()] : The handle of API is not created.\n");
		return lastError = OPROS_PRECONDITION_NOT_MET;
	}
	
	if (bumperTouch->Finalize() != API_SUCCESS)
		return lastError = OPROS_RESET_API_ERROR;

	if (bumperTouch->Initialize(parameter) != API_SUCCESS)
		return lastError = OPROS_RESET_API_ERROR;

	if (bumperTouch->Enable() != API_SUCCESS)
	{
		if (bumperTouch->Finalize() != API_SUCCESS)
		{
			return lastError = OPROS_RESET_API_ERROR;
		}
	}	

	return  lastError = OPROS_SUCCESS;
}

ReturnType BumperTouchSensorComp::onError()
{
	PrintMessage("[INFO : BumperTouchSensorComp::onError()]\n");

	return Disable();
}

ReturnType BumperTouchSensorComp::onRecover()
{
	PrintMessage("[INFO : BumperTouchSensorComp::onRecover()]\n");
	if(bumperTouch == NULL) {
		PrintMessage("[ERROR : BumperTouchSensorComp::onRecover()] : The handle of API is not created.\n");
		return lastError = OPROS_PRECONDITION_NOT_MET;
	}

	if (bumperTouch->Finalize() != API_SUCCESS)
		return lastError = OPROS_RECOVER_API_ERROR;

	if (bumperTouch->Initialize(parameter) != API_SUCCESS)
		return lastError = OPROS_RECOVER_API_ERROR;

	return lastError = OPROS_SUCCESS;
}

ReturnType BumperTouchSensorComp::onDestroy()
{
	PrintMessage("[INFO : BumperTouchSensorComp::onDestroy()]\n");
	if (getStatus() == OPROS_CS_DESTROYED)
		return lastError = OPROS_SUCCESS;

	if(bumperTouch != NULL) {
		bumperTouch->Finalize();
		delete bumperTouch;
		bumperTouch = NULL;
	}

	if(hOprosAPI != NULL) {
#if defined(WIN32)
		FreeLibrary(hOprosAPI);
#else
		dlclose(hOprosAPI);
#endif
		hOprosAPI = NULL;
	}

	return lastError = OPROS_SUCCESS;
}

ReturnType BumperTouchSensorComp::onEvent(Event *evt)
{
	PrintMessage("[INFO : BumperTouchSensorComp::onEvent()]\n");

	return lastError = OPROS_SUCCESS;
}

ReturnType BumperTouchSensorComp::onExecute()
{
	//PrintMessage("[INFO : BumperTouchSensorComp::onExecute()]\n");

	if(bumperTouch == NULL) {
		PrintMessage("[ERROR : BumperTouchSensorComp::onExecute()] : The handle of API is not created.\n");
		return lastError = OPROS_PRECONDITION_NOT_MET;
	}

	std::vector<OPRoS::Bool> sensorValue;
	int32_t ret = bumperTouch->GetSensorValue(sensorValue);
	if(ret == API_ERROR) {
		return lastError = OPROS_CALL_API_ERROR;
	}
	else if(ret == API_NOT_SUPPORTED) {
		return lastError = OPROS_API_NOT_SUPPORTED_ERROR;
	}
	else {
		bumperTouchState.push(sensorValue);
	}

	return lastError = OPROS_SUCCESS;
}
	
ReturnType BumperTouchSensorComp::onUpdated()
{
	//PrintMessage("[INFO : BumperTouchSensorComp::onUpdated()]\n");

	return lastError = OPROS_SUCCESS;
}

ReturnType BumperTouchSensorComp::onPeriodChanged()
{
	PrintMessage("[INFO : BumperTouchSensorComp::onPeriodChanged()]\n");

	return lastError = OPROS_SUCCESS;
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
	return new BumperTouchSensorComp();
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
	return new BumperTouchSensorComp();
}

void releaseComponent(Component *com)
{
	delete com;
}
#endif
#endif
