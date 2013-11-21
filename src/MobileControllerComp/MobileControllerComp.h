#ifndef _MobileControllerComp_COMPONENT_H
#define _MobileControllerComp_COMPONENT_H
/*
 *  Generated sources by OPRoS Component Generator (OCG V2.0[Symbol])
 *   
 */
#include <Component.h>
#include <InputDataPort.h>
#include <OutputDataPort.h>
#include <InputEventPort.h>
#include <OutputEventPort.h>
#include <Event.h>
#include <OPRoSTypes.h>

#include "MobileControllerServiceProvided.h"
#include "MobileController.h"


class MobileControllerComp : public Component, public IMobileControllerService
{
protected:
	//	Data Port
	OutputDataPort< std::vector<OPRoS::Int32> > OdoMetry;

	InputDataPort< OPRoS::MobileVelocityData> velocity;

	//	Service Port
	IMobileControllerService *ptrMobileControllerService;

	//	Shared(Dynamic Linked) Library's Handle
	OprosDeviceHandle hOprosAPI;

	//	Last Error
	ReturnType lastError;

	//	API's Handle
	MobileController *mobileController;

	// Property
	OPRoS::Property parameter;

public:
	virtual ReturnType SetProperty(OPRoS::Property props);
	virtual OPRoS::Property GetProperty();
	virtual ReturnType GetError();
	virtual ReturnType Enable();
	virtual ReturnType Disable();
	virtual std::vector<OPRoS::Int32> GetOdometry();
	virtual ReturnType SetVelocity(OPRoS::MobileVelocityData velocity);
	virtual ReturnType SetPosition(OPRoS::MobilePositionData position);
	virtual OPRoS::MobilePositionData GetPosition();
	virtual ReturnType MoveBase(float64_t distance, float64_t velocity);
	virtual ReturnType RotateBase(float64_t angle, float64_t velocity);
	virtual ReturnType StopBase();
	virtual bool IsBaseRunning();

public:
	MobileControllerComp();
	MobileControllerComp(const std::string &compId);
	virtual ~MobileControllerComp();
	virtual void portSetup();

protected:
	virtual ReturnType onInitialize();
	virtual ReturnType onStart();
	virtual ReturnType onStop();
	virtual ReturnType onReset();
	virtual ReturnType onError();
	virtual ReturnType onRecover();
	virtual ReturnType onDestroy();

public:
	virtual ReturnType onEvent(Event *evt);
	virtual ReturnType onExecute();
	virtual ReturnType onUpdated();
	virtual ReturnType onPeriodChanged();

	static void TimingManager();

	static DWORD lastUntilTick;
	static bool bIsTimingMode;
	static bool bTimingLoopContinue;
	static MobileControllerComp* mcc;
	static bool bBaseRunning;
	static HANDLE hThread;
};

#endif

