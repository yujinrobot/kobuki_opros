/*************************************************************

 file: GyroSensorComp.cpp
 author: E.C. Shin
 begin: January 31 2011
 copyright: (c) 2011 KITECH, OPRoS
 email: unchol@kitech.re.kr

***************************************************************

OPRoS source code is provided under a dual license mode:
 LGPL and OPRoS individually.

LGPL: You can redistribute it and/or modify it under the terms
 of the Less GNU General Public License as published by the Free
 Software Foundation, either version 3 of the License.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of 
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the 
 Less GNU General Public License for more details. 

 You should have received a copy of the Less GNU General Public
 License along with this program. If not, see 
 <http://www.gnu.org/licenses/>.

OPRoS individual license: An individual license is a license for
 modifying the source code of OPRoS and distiributing it in a
 closed format for commercial purposes.

 If you are interested in this option, please see 
 <http://www.opros.or.kr>.

This license policy may be changed without prior notice.

***************************************************************/

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

#include "GyroSensorComp.h"
#include "OprosPrintMessage.h"
#include "ObjectPositionData.h"

//#include "../CommonLib/StatusTester.h"

//
// constructor declaration
//
GyroSensorComp::GyroSensorComp()
{
	hOprosAPI = NULL;
	gyroSensor = NULL;
	lastError = OPROS_SUCCESS;
	
	portSetup();
}

//
// constructor declaration (with name)
//
GyroSensorComp::GyroSensorComp(const std::string &name):Component(name)
{
	hOprosAPI = NULL;
	gyroSensor = NULL;
	lastError = OPROS_SUCCESS;
	
	portSetup();
}

//
// destructor declaration
//

GyroSensorComp::~GyroSensorComp() 
{
	onDestroy();
}

ReturnType GyroSensorComp::SetProperty(OPRoS::Property props)
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
		if (props.GetValue(name)!="GYRO")	return lastError = OPROS_BAD_INPUT_PARAMETER;
	
		sprintf(name, "x%d", i);		if(props.FindName(name) == false)	return lastError = OPROS_BAD_INPUT_PARAMETER;
		sprintf(name, "y%d", i);		if(props.FindName(name) == false)	return lastError = OPROS_BAD_INPUT_PARAMETER;
		sprintf(name, "z%d", i);		if(props.FindName(name) == false)	return lastError = OPROS_BAD_INPUT_PARAMETER;
		sprintf(name, "roll%d", i);		if(props.FindName(name) == false)	return lastError = OPROS_BAD_INPUT_PARAMETER;
		sprintf(name, "pitch%d", i);	if(props.FindName(name) == false)	return lastError = OPROS_BAD_INPUT_PARAMETER;
		sprintf(name, "yaw%d", i);		if(props.FindName(name) == false)	return lastError = OPROS_BAD_INPUT_PARAMETER;
	}
	
	parameter = props;

	// Set property
	if(gyroSensor != NULL) {
		int32_t ret = gyroSensor->SetProperty(props);
		if(ret == API_ERROR) {
			return lastError = OPROS_CALL_API_ERROR;
		}
	}

	return lastError = OPROS_SUCCESS;
}

OPRoS::Property GyroSensorComp::GetProperty()
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

ReturnType GyroSensorComp::GetError()
{
	return lastError;
}

ReturnType GyroSensorComp::Enable()
{
	if(gyroSensor == NULL) {
		PrintMessage("ERROR : GyroSensorComp::Enable() -> The handle of API is not created.\n");
		return lastError = OPROS_PRECONDITION_NOT_MET;
	}

	int32_t ret = gyroSensor->Enable();
	if(ret == API_ERROR) {
		return lastError = OPROS_ENABLE_API_ERROR;
	}
	else if(ret == API_NOT_SUPPORTED) {
		return lastError = OPROS_API_NOT_SUPPORTED_ERROR;
	}
	
	return lastError = OPROS_SUCCESS;
}

ReturnType GyroSensorComp::Disable()
{
	if(gyroSensor == NULL) {
		PrintMessage("ERROR : GyroSensorComp::Disable() -> The handle of API is not created.\n");
		return lastError = OPROS_PRECONDITION_NOT_MET;
	}

	int32_t ret = gyroSensor->Disable();
	if(ret == API_ERROR) {
		return lastError = OPROS_DISABLE_API_ERROR;
	}
	else if(ret == API_NOT_SUPPORTED) {
		return lastError = OPROS_API_NOT_SUPPORTED_ERROR;
	}
	
	return lastError = OPROS_SUCCESS;
}

std::vector<OPRoS::GyroSensorData> GyroSensorComp::GetSensorValue()
{
	std::vector<OPRoS::GyroSensorData> sensorValue;

	LifecycleState lifeStat = getStatus();
	if (lifeStat != OPROS_CS_ACTIVE)
	{
		lastError = OPROS_ERROR;
	}
	else if(gyroSensor == NULL) {
		PrintMessage("[ERROR : GyroSensorComp::GetSensorValue()] : The handle of API is not created.\n");
		lastError = OPROS_PRECONDITION_NOT_MET;
	}
	else
	{
		int32_t ret = gyroSensor->GetSensorValue(sensorValue);
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

void GyroSensorComp::portSetup() 
{
	ProvidedServicePort *pa1;
	pa1=new GyroSensorServiceProvided(this);
	addPort("GyroSensorService",pa1);

	addPort("GyroValue", &gyroSensorData);
}

// Call back Declaration
ReturnType GyroSensorComp::onInitialize()
{
	// Check if already initialized
	if (hOprosAPI != NULL)
		return lastError = OPROS_SUCCESS;

	//OPRoS::Property parameter;
	std::map<std::string, std::string> temp = getPropertyMap();
	parameter.SetProperty(temp);
	
	if(parameter.FindName("ApiName") == false) {
		PrintMessage("ERROR : GyroSensorComp::onInitialize() -> Can't find the APIName in property\n");
		return lastError = OPROS_FIND_PROPERTY_ERROR;
	}
	
#if defined(WIN32)
	//	DLL 로드
	hOprosAPI = LoadLibrary((LPCSTR)parameter.GetValue("ApiName").c_str());
	if(hOprosAPI == NULL) {
		PrintMessage("ERROR : GyroSensorComp::onInitialize() -> Can't find the %s\n", parameter.GetValue("ApiName").c_str());
		return lastError = OPROS_FIND_DLL_ERROR;
	}
	
	//	API 로드
	GET_OPROS_DEVICE getOprosAPI;
	getOprosAPI = (GET_OPROS_DEVICE)GetProcAddress(hOprosAPI, "GetAPI");
	if(getOprosAPI == NULL) {
		PrintMessage("ERROR : GyroSensorComp::onInitialize() -> Can't get a handle of GetAPI Funtion\n");
		FreeLibrary(hOprosAPI);
		hOprosAPI = NULL;
		return lastError = OPROS_LOAD_DLL_ERROR;
	}

	//	API Casting
	gyroSensor = dynamic_cast<GyroSensor *>(getOprosAPI());
	if(gyroSensor == NULL) {
		PrintMessage("ERROR : GyroSensorComp::onInitialize() -> Can't get a handle of AccelerationSensor API\n");
		FreeLibrary(hOprosAPI);
		hOprosAPI = NULL;
		return lastError = OPROS_LOAD_DLL_ERROR;
	}
#else
	//	Shared Library 로드
	hOprosAPI = dlopen(parameter.GetValue("ApiName").c_str(), RTLD_NOW);
	if(hOprosAPI == NULL) {
		PrintMessage("ERROR : GyroSensorComp::onInitialize() -> Can't find the %s\n", parameter.GetValue("ApiName").c_str());
		return lastError = OPROS_FIND_DLL_ERROR;
	}

	//	API 로드
	GET_OPROS_DEVICE getOprosAPI = (GET_OPROS_DEVICE)dlsym(hOprosAPI, "GetAPI");
	char *error = dlerror();
	if(error != NULL) {
		PrintMessage("ERROR : GyroSensorComp::onInitialize() -> Can't get a handle of GetAPI Funtion\n");
		dlclose(hOprosAPI);
		hOprosAPI = NULL;
		return lastError = OPROS_LOAD_DLL_ERROR;
	}
	
	//	API Casting
	gyroSensor = static_cast<GyroSensor *>(getOprosAPI());
	if(gyroSensor == NULL) {
		PrintMessage("ERROR : GyroSensorComp::onInitialize() -> Can't get a handle of AccelerationSensor API\n");
		dlclose(hOprosAPI);
		hOprosAPI = NULL;
		return lastError = OPROS_LOAD_DLL_ERROR;
	}
#endif

	if(gyroSensor->Initialize(parameter) != API_SUCCESS) {
		delete gyroSensor;
		gyroSensor = NULL;

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

ReturnType GyroSensorComp::onStart()
{
	return Enable();
}
	
ReturnType GyroSensorComp::onStop()
{
	return Disable();
}

ReturnType GyroSensorComp::onReset()
{
	// user code here
	if(gyroSensor == NULL) {
		PrintMessage("[ERROR : GyroSensorComp::onReset()] : The handle of API is not created.\n");
		return lastError = OPROS_PRECONDITION_NOT_MET;
	}
	
	if (gyroSensor->Finalize() != API_SUCCESS)
		return lastError = OPROS_RESET_API_ERROR;

	if (gyroSensor->Initialize(parameter) != API_SUCCESS)
		return lastError = OPROS_RESET_API_ERROR;

	if (gyroSensor->Enable() != API_SUCCESS)
	{
		if (gyroSensor->Finalize() != API_SUCCESS)
		{
			return lastError = OPROS_RESET_API_ERROR;
		}
	}	

	return  lastError = OPROS_SUCCESS;
}

ReturnType GyroSensorComp::onError()
{
	// user code here
	return Disable();
}

ReturnType GyroSensorComp::onRecover()
{
	// user code here
	if(gyroSensor == NULL) {
		PrintMessage("[ERROR : GyroSensorComp::onRecover()] : The handle of API is not created.\n");
		return lastError = OPROS_PRECONDITION_NOT_MET;
	}

	if (gyroSensor->Finalize() != API_SUCCESS)
		return lastError = OPROS_RECOVER_API_ERROR;

	if (gyroSensor->Initialize(parameter) != API_SUCCESS)
		return lastError = OPROS_RECOVER_API_ERROR;

	return lastError = OPROS_SUCCESS;
}

ReturnType GyroSensorComp::onDestroy()
{
	if (getStatus() == OPROS_CS_DESTROYED)
		return lastError = OPROS_SUCCESS;

	if(gyroSensor != NULL) {
		delete gyroSensor;
		gyroSensor = NULL;
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

ReturnType GyroSensorComp::onEvent(Event *evt)
{
	// user code here
	return lastError = OPROS_SUCCESS;
}

ReturnType GyroSensorComp::onExecute()
{
	if(gyroSensor == NULL) {
		PrintMessage("ERROR : GyroSensorComp::onExecute() -> The handle of API is not created.\n");
		return lastError = OPROS_PRECONDITION_NOT_MET;
	}

	std::vector<OPRoS::GyroSensorData> sensorValue;
	int32_t ret = gyroSensor->GetSensorValue(sensorValue);
	if(ret == API_ERROR) {
		return lastError = OPROS_CALL_API_ERROR;
	}
	else if(ret == API_NOT_SUPPORTED) {
		return lastError = OPROS_API_NOT_SUPPORTED_ERROR;
	}
	else {
		gyroSensorData.push(sensorValue);
	}

	return lastError = OPROS_SUCCESS;
}
	
ReturnType GyroSensorComp::onUpdated()
{
	// user code here
	return lastError = OPROS_SUCCESS;
}

ReturnType GyroSensorComp::onPeriodChanged()
{
	// user code here
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
	return new GyroSensorComp();
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
	return new GyroSensorComp();
}

void releaseComponent(Component *com)
{
	delete com;
}
#endif
#endif

