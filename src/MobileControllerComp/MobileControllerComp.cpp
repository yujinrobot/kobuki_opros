/*************************************************************

 file: MobileControllerComp.cpp
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
#include <OprosMath.h>
#include "MobileControllerComp.h"
#include "OprosPrintMessage.h"
//#include "../CommonLib/StatusTester.h"

DWORD MobileControllerComp::lastUntilTick;
bool MobileControllerComp::bIsTimingMode = false;
bool MobileControllerComp::bTimingLoopContinue = true;
MobileControllerComp* MobileControllerComp::mcc = NULL;
bool MobileControllerComp::bBaseRunning = false;
HANDLE MobileControllerComp::hThread = NULL;

void MobileControllerComp::TimingManager()
{
	while (bTimingLoopContinue)
	{
		if (bIsTimingMode)
		{
			if (GetTickCount() >= lastUntilTick)
			{
				mcc->StopBase();
			}
		}
		Sleep(50);
	}

	hThread = NULL;
}

//
// constructor declaration
//
MobileControllerComp::MobileControllerComp()
{
	hOprosAPI = NULL;
	mobileController = NULL;
	lastError = OPROS_SUCCESS;
	
	mcc = this;
	hThread = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)TimingManager, NULL, 0, 0);

	portSetup();
}

//
// constructor declaration (with name)
//
MobileControllerComp::MobileControllerComp(const std::string &name):Component(name)
{
	hOprosAPI = NULL;
	mobileController = NULL;
	lastError = OPROS_SUCCESS;
	
	mcc = this;
	hThread = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)TimingManager, NULL, 0, 0);

	portSetup();
}

//
// destructor declaration
//

MobileControllerComp::~MobileControllerComp() 
{
	bTimingLoopContinue = false;
	while(hThread)
		Sleep(10);

	onDestroy();
}

ReturnType MobileControllerComp::SetProperty(OPRoS::Property props)
{
	// Check property integrity
	if(props.FindName("Version") == false) {
		return lastError = OPROS_BAD_INPUT_PARAMETER;
	}
	if(atof(props.GetValue("Version").c_str()) != 1.1) {
		return lastError = OPROS_BAD_INPUT_PARAMETER;
	}

	parameter = props;

	// Set property
	if(mobileController != NULL) {
		int32_t ret = mobileController->SetProperty(props);
		if(ret == API_ERROR) {
			return lastError = OPROS_CALL_API_ERROR;
		}
	}
	return lastError = OPROS_SUCCESS;
}

OPRoS::Property MobileControllerComp::GetProperty()
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

ReturnType MobileControllerComp::GetError()
{
	return lastError;
}

ReturnType MobileControllerComp::Enable()
{
	if(mobileController == NULL) {
		PrintMessage("ERROR : MobileControllerComp::Enable() -> The handle of API is not created.\n");
		return lastError = OPROS_PRECONDITION_NOT_MET;
	}

	int32_t ret = mobileController->Enable();
	if(ret == API_ERROR) {
		return lastError = OPROS_ENABLE_API_ERROR;
	}
	else if(ret == API_NOT_SUPPORTED) {
		return lastError = OPROS_API_NOT_SUPPORTED_ERROR;
	}
	
	PrintMessage("[SUCCESS : %s::%s]\n", __FILE__, __FUNCTION__);
	return lastError = OPROS_SUCCESS;
}

ReturnType MobileControllerComp::Disable()
{
	if(mobileController == NULL) {
		PrintMessage("ERROR : MobileControllerComp::Disable() -> The handle of API is not created.\n");
		return lastError = OPROS_PRECONDITION_NOT_MET;
	}

	bIsTimingMode = false;
	int32_t ret = mobileController->Disable();
	if(ret == API_ERROR) {
		return lastError = OPROS_DISABLE_API_ERROR;
	}
	else if(ret == API_NOT_SUPPORTED) {
		return lastError = OPROS_API_NOT_SUPPORTED_ERROR;
	}
	
	PrintMessage("[SUCCESS : %s::%s]\n", __FILE__, __FUNCTION__);
	return lastError = OPROS_SUCCESS;
}

std::vector<OPRoS::Int32> MobileControllerComp::GetOdometry()
{
	std::vector<OPRoS::Int32> odometry;

	LifecycleState lifeStat = getStatus();
	if (lifeStat != OPROS_CS_ACTIVE)
	{
		lastError = OPROS_ERROR;
	}
	else if(mobileController == NULL) {
		PrintMessage("[ERROR : MobileControllerComp::GetOdometry()] : The handle of API is not created.\n");
		lastError = OPROS_PRECONDITION_NOT_MET;
	}
	else
	{
		int32_t ret = mobileController->GetOdometry(odometry);
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
		odometry.resize(1);
		odometry[0].status = OPROS_ERROR;
	}

	PrintMessage("[ODOMETRY :");
	for each(OPRoS::Int32 odom in odometry)
	{
		PrintMessage("status=%d,data=%d     ", odom.status, odom.data); 
	}
	PrintMessage("]\n");
	return odometry;
}

ReturnType MobileControllerComp::SetVelocity(OPRoS::MobileVelocityData velocity)
{
	LifecycleState lifeStat = getStatus();
	if (lifeStat != OPROS_CS_ACTIVE)
	{
		lastError = OPROS_ERROR;
	}
	else if(mobileController == NULL) {
		PrintMessage("ERROR : MobileControllerComp::SetVelocity() -> The handle of API is not created.\n");
		lastError = OPROS_PRECONDITION_NOT_MET;
	}
	else
	{
		bIsTimingMode = false;
		int32_t ret = mobileController->SetVelocity(velocity);
		if(ret == API_ERROR) {
			lastError = OPROS_CALL_API_ERROR;
		}
		else if(ret == API_NOT_SUPPORTED) {
			lastError = OPROS_API_NOT_SUPPORTED_ERROR;
		}
		else {
			if (velocity.x == 0 && velocity.y == 0 && velocity.theta == 0)
				bBaseRunning = false;
			else
				bBaseRunning = true;

			lastError = OPROS_SUCCESS;
		}
	}

	PrintMessage("[%s::%s] x=%f, y = %f, theta = %f\n", __FILE__, __FUNCTION__, velocity.x, velocity.y, velocity.theta);
	return lastError;
}

ReturnType MobileControllerComp::SetPosition(OPRoS::MobilePositionData position)
{
	LifecycleState lifeStat = getStatus();
	if (lifeStat != OPROS_CS_ACTIVE)
	{
		lastError = OPROS_ERROR;
	}
	else if(mobileController == NULL) {
		PrintMessage("ERROR : MobileControllerComp::SetPosition() -> The handle of API is not created.\n");
		lastError = OPROS_PRECONDITION_NOT_MET;
	}
	else
	{
		bIsTimingMode = false;
		int32_t ret = mobileController->SetPosition(position);
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
	PrintMessage("[%s::%s] x=%f, y = %f, theta = %f\n", __FILE__, __FUNCTION__, position.x, position.y, position.theta);
	return lastError;
}

OPRoS::MobilePositionData MobileControllerComp::GetPosition()
{
	OPRoS::MobilePositionData position;

	LifecycleState lifeStat = getStatus();
	if (lifeStat != OPROS_CS_ACTIVE)
	{
		lastError = OPROS_ERROR;
	}
	else if(mobileController == NULL) {
		PrintMessage("ERROR : MobileControllerComp::GetPosition() -> The handle of API is not created.\n");
		lastError = OPROS_PRECONDITION_NOT_MET;
	}
	else
	{
		int32_t ret = mobileController->GetPosition(position);
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
		position.status = OPROS_ERROR;
	}
	PrintMessage("[%s::%s] x=%f, y = %f, theta = %f\n", __FILE__, __FUNCTION__, position.x, position.y, position.theta);
	return position;
}

ReturnType MobileControllerComp::MoveBase(float64_t distance, float64_t velocity)
{
	LifecycleState lifeStat = getStatus();
	if (lifeStat != OPROS_CS_ACTIVE)
	{
		lastError = OPROS_ERROR;
	}
	else if(mobileController == NULL) {
		PrintMessage("ERROR : MobileControllerComp::SetPosition() -> The handle of API is not created.\n");
		lastError = OPROS_PRECONDITION_NOT_MET;
	}
	else
	{	
		int32_t ret = mobileController->SetVelocity(OPRoS::MobileVelocityData(velocity, 0, 0));
		if(ret == API_ERROR) {
			lastError = OPROS_CALL_API_ERROR;
		}
		else if(ret == API_NOT_SUPPORTED) {
			lastError = OPROS_API_NOT_SUPPORTED_ERROR;
		}
		else {
			lastUntilTick = GetTickCount() + (DWORD)(1000.0 * distance / velocity);
			bIsTimingMode = true;
			bBaseRunning = true;
			lastError = OPROS_SUCCESS;
		}
	}

	PrintMessage("[%s::%s] dist=%f, vel = %f\n", __FILE__, __FUNCTION__, distance, velocity);
	return lastError;
}

ReturnType MobileControllerComp::RotateBase(float64_t angle, float64_t velocity)
{
	LifecycleState lifeStat = getStatus();
	if (lifeStat != OPROS_CS_ACTIVE)
	{
		lastError = OPROS_ERROR;
	}
	else if(mobileController == NULL) {
		PrintMessage("ERROR : MobileControllerComp::SetPosition() -> The handle of API is not created.\n");
		lastError = OPROS_PRECONDITION_NOT_MET;
	}
	else
	{	
		//float64_t radian = velocity * M_PI / 180; 
		//int32_t ret = mobileController->SetVelocity(OPRoS::MobileVelocityData(0, 0, radian));
		int32_t ret = mobileController->SetVelocity(OPRoS::MobileVelocityData(0, 0, velocity));
		if(ret == API_ERROR) {
			lastError = OPROS_CALL_API_ERROR;
		}
		else if(ret == API_NOT_SUPPORTED) {
			lastError = OPROS_API_NOT_SUPPORTED_ERROR;
		}
		else {
			lastUntilTick = GetTickCount() + (DWORD)(1000.0 * angle / velocity);
			bIsTimingMode = true;
			bBaseRunning = true;
			lastError = OPROS_SUCCESS;
		}
	}
	PrintMessage("[%s::%s] ang=%f, vel = %f\n", __FILE__, __FUNCTION__, angle, velocity);
	return lastError;
}

ReturnType MobileControllerComp::StopBase()
{
	LifecycleState lifeStat = getStatus();
	if (lifeStat != OPROS_CS_ACTIVE)
	{
		lastError = OPROS_ERROR;
	}
	else if(mobileController == NULL) {
		PrintMessage("ERROR : MobileControllerComp::SetPosition() -> The handle of API is not created.\n");
		lastError = OPROS_PRECONDITION_NOT_MET;
	}
	else
	{	
		bIsTimingMode = false;
		bBaseRunning = false;
		int32_t ret = mobileController->SetVelocity(OPRoS::MobileVelocityData(0, 0, 0));
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
	PrintMessage("[%s::%s]\n", __FILE__, __FUNCTION__);
	return lastError;
}

bool MobileControllerComp::IsBaseRunning()
{
	LifecycleState lifeStat = getStatus();
	if (lifeStat != OPROS_CS_ACTIVE)
	{
		lastError = OPROS_ERROR;
	}
	else 
		lastError = OPROS_SUCCESS;

	PrintMessage("[%s::%s] baseRunning = %d\n", __FILE__, __FUNCTION__, bBaseRunning);
	return bBaseRunning;
}

void MobileControllerComp::portSetup() 
{
	ProvidedServicePort *pa1;
	pa1=new MobileControllerServiceProvided(this);
	addPort("MobileControllerService",pa1);

	// export variable setup
}

// Call back Declaration
ReturnType MobileControllerComp::onInitialize()
{
	// Check if already initialized
	if (hOprosAPI != NULL)
		return lastError =OPROS_SUCCESS;

	//OPRoS::Property parameter;
	std::map<std::string, std::string> temp = getPropertyMap();
	parameter.SetProperty(temp);
	
	if(parameter.FindName("ApiName") == false) {
		PrintMessage("ERROR : MobileControllerComp::onInitialize() -> Can't find the APIName in property\n");
		return lastError = OPROS_FIND_PROPERTY_ERROR;
	}

	
#if defined(WIN32)
	//	DLL 로드
	hOprosAPI = LoadLibrary((LPCSTR)parameter.GetValue("ApiName").c_str());
	if(hOprosAPI == NULL) {
		PrintMessage("ERROR : MobileControllerComp::onInitialize() -> Can't find the %s\n", parameter.GetValue("ApiName").c_str());
		return lastError = OPROS_FIND_DLL_ERROR;
	}
	
	//	API 로드
	GET_OPROS_DEVICE getOprosAPI;
	getOprosAPI = (GET_OPROS_DEVICE)GetProcAddress(hOprosAPI, "GetAPI");
	if(getOprosAPI == NULL) {
		PrintMessage("ERROR : MobileControllerComp::onInitialize() -> Can't get a handle of GetAPI Funtion\n");
		FreeLibrary(hOprosAPI);
		hOprosAPI = NULL;
		return lastError = OPROS_LOAD_DLL_ERROR;
	}
#else
	hOprosAPI = dlopen(parameter.GetValue("ApiName").c_str(), RTLD_LAZY);
	if(hOprosAPI == NULL) {
		PrintMessage("ERROR : MobileControllerComp::onInitialize() -> Can't find the %s\n", parameter.GetValue("ApiName").c_str());
		return lastError = OPROS_FIND_DLL_ERROR;
	}

	GET_OPROS_DEVICE getOprosAPI;
	getOprosAPI = (GET_OPROS_DEVICE)dlsym(hOprosAPI, "GetAPI");
	char *error = dlerror();
	if(error != NULL) {
		PrintMessage("ERROR : MobileControllerComp::onInitialize() -> Can't get a handle of GetAPI Funtion\n");
		dlclose(hOprosAPI);
		hOprosAPI = NULL;
		return lastError = OPROS_LOAD_DLL_ERROR;
	}
#endif
	
	mobileController = dynamic_cast<MobileController *>(getOprosAPI());
	if(mobileController == NULL) {
		PrintMessage("ERROR : MobileControllerComp::onInitialize() -> Can't get a handle of MobileController API\n");
#if defined(WIN32)
		FreeLibrary(hOprosAPI);
#else
		dlclose(hOprosAPI);
#endif
		hOprosAPI = NULL;
		return lastError = OPROS_LOAD_DLL_ERROR;
	}

	if(mobileController->Initialize(parameter) != API_SUCCESS) {
		delete mobileController;
		mobileController = NULL;

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

ReturnType MobileControllerComp::onStart()
{
	return Enable();
}
	
ReturnType MobileControllerComp::onStop()
{
	return Disable();
}

ReturnType MobileControllerComp::onReset()
{
	if(mobileController == NULL) {
		PrintMessage("[ERROR : MobileControllerComp::onReset()] : The handle of API is not created.\n");
		return lastError = OPROS_PRECONDITION_NOT_MET;
	}
	
	if (mobileController->Finalize() != API_SUCCESS)
		return lastError = OPROS_RESET_API_ERROR;

	if (mobileController->Initialize(parameter) != API_SUCCESS)
		return lastError = OPROS_RESET_API_ERROR;

	if (mobileController->Enable() != API_SUCCESS)
	{
		if (mobileController->Finalize() != API_SUCCESS)
		{
			return lastError = OPROS_RESET_API_ERROR;
		}
	}	

	return  lastError = OPROS_SUCCESS;
}

ReturnType MobileControllerComp::onError()
{
	return Disable();
}

ReturnType MobileControllerComp::onRecover()
{
	if(mobileController == NULL) {
		PrintMessage("[ERROR : MobileControllerComp::onRecover()] : The handle of API is not created.\n");
		return lastError = OPROS_PRECONDITION_NOT_MET;
	}
	
	if (mobileController->Finalize() != API_SUCCESS)
		return lastError = OPROS_RESET_API_ERROR;

	if (mobileController->Initialize(parameter) != API_SUCCESS)
		return lastError = OPROS_RESET_API_ERROR;

	return  lastError = OPROS_SUCCESS;
}

ReturnType MobileControllerComp::onDestroy()
{
	if (getStatus() == OPROS_CS_DESTROYED)
		return lastError = OPROS_SUCCESS;

	if(mobileController != NULL) {
		mobileController->Finalize();
		delete mobileController;
		mobileController = NULL;
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

ReturnType MobileControllerComp::onEvent(Event *evt)
{
	return lastError = OPROS_SUCCESS;
}

ReturnType MobileControllerComp::onExecute()
{
	if(mobileController == NULL) {
		PrintMessage("[ERROR : MobileControllerComp::onExecute()] : The handle of API is not created.\n");
		return lastError = OPROS_PRECONDITION_NOT_MET;
	}

	// velocity port
	if (&velocity)
	{
		if( velocity.getSize() > 0 )
		{
			opros_any	*pData = velocity.pop();
			OPRoS::MobileVelocityData newVelocity = opros_any_cast< OPRoS::MobileVelocityData >( *pData );
			bIsTimingMode = false;
			int32_t ret = mobileController->SetVelocity(newVelocity);
			if(ret == API_ERROR) {
				return lastError = OPROS_CALL_API_ERROR;
			}
			else if(ret == API_NOT_SUPPORTED) {
				return lastError = OPROS_API_NOT_SUPPORTED_ERROR;
			}
		}
	}

	// OdoMetry port
	std::vector<OPRoS::Int32> odom;
	int32_t ret = mobileController->GetOdometry(odom);
	if(ret == API_ERROR) {
		return lastError = OPROS_CALL_API_ERROR;
	}
	else if(ret == API_NOT_SUPPORTED) {
		return lastError = OPROS_API_NOT_SUPPORTED_ERROR;
	}
	else {
		OdoMetry.push(odom);
	}
	
	return lastError = OPROS_SUCCESS;
}
	
ReturnType MobileControllerComp::onUpdated()
{
	return lastError = OPROS_SUCCESS;
}

ReturnType MobileControllerComp::onPeriodChanged()
{
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
	return new MobileControllerComp();
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
	return new MobileControllerComp();
}

void releaseComponent(Component *com)
{
	delete com;
}
#endif
#endif

