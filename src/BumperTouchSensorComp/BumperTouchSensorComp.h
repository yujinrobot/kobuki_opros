#ifndef _BumperTouchSensorComp_COMPONENT_H
#define _BumperTouchSensorComp_COMPONENT_H
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

#include "BumperTouchSensorServiceProvided.h"
#include "BumperTouchSensor.h"

class BumperTouchSensorComp: public Component, public IBumperTouchSensorService
{
protected:
	//	Data Port
	OutputDataPort< std::vector<OPRoS::Bool> > bumperTouchState;

	//	Service Port
	IBumperTouchSensorService *ptrBumperTouchSensorService;

	//	Shared(Dynamic Linked) Library's Handle
	OprosDeviceHandle hOprosAPI;

	//	Last Error
	ReturnType lastError;

	//	API's Handle
	BumperTouchSensor *bumperTouch;

	// Property
	OPRoS::Property parameter;

public:
	virtual ReturnType SetProperty(OPRoS::Property props);
	virtual OPRoS::Property GetProperty();
	virtual ReturnType GetError();
	virtual ReturnType Enable();
	virtual ReturnType Disable();
	virtual std::vector< OPRoS::Bool > GetSensorValue();

public:
	BumperTouchSensorComp();
	BumperTouchSensorComp(const std::string &compId);
	virtual ~BumperTouchSensorComp();
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


};

#endif

