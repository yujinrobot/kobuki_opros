/*
 *  OPRoS Component Engine (OCE)
 *  Copyright (c) 2008 ETRI. http://www.etri.re.kr.
 *  Distributed under the OPRoS License, Version 1.0.
 *
 *  @Created : 2009. 2. 18
 *  @Author  : sby (sby@etri.re.kr)
 *
 *  @File    : Component.h
 *
 *
 */

#ifndef COMPONENT_H_
#define COMPONENT_H_

#include <ReturnType.h>
#include <Event.h>
#include <PropertyInterface.h>
#include <LifecycleInterface.h>
#include <PortInterface.h>

/**
 * Component is the abstract base class for all user components
 */
class Component: public PropertyInterface,
		public LifecycleInterface,
		public PortInterface
{
	std::string m_compId;

public:
	Component();
	Component(const std::string &compid);
	virtual ~Component();

	/**
	 * Set component unique id.
	 *
	 * @param id		the unique id of component.
	 */
	virtual void setId(std::string id);

	/**
	 * Get component unique id
	 *
	 * @return		<code>std::string</code> type component unique id
	 */
	virtual std::string getId();

protected:

	/**
	 *  default callback function for LifecycleInterface::onInitialize();
	 *
	 *  @see	LifecycleInterface#onInitialize()
	 */
	virtual ReturnType onInitialize();

	/**
	 * default callback function for LifecycleInterface::onStart();
	 *
	 * @see		LifecycleInterface#onStart()
	 */
	virtual ReturnType onStart();

	/**
	 * default callback function for LifecycleInterface::onStop();
	 *
	 * @see		LifecycleInterface#onStop()
	 */
	virtual ReturnType onStop();

	/**
	 * default callback function for LifecycleInterface::onReset();
	 *
	 * @see		LifecycleInterface#onReset()
	 */
	virtual ReturnType onReset();

	/**
	 * default callback function for LifecycleInterface::onError();
	 *
	 * @see		LifecycleInterface#onError()
	 */
	virtual ReturnType onError();

	/**
	 * default callback function for LifecycleInterface::onRecover();
	 *
	 * @see		LifecycleInterface#onRecover()
	 */
	virtual ReturnType onRecover();

	/**
	 * default callback function for LifecycleInterface::onDestroy();
	 *
	 * @see		LifecycleInterface#onDestroy()
	 */
	virtual ReturnType onDestroy();

public:

	/**
	 * Called when an event is received on the component
	 * The users can redefine this function to process events.
	 *
	 * @param	evt		pointer of the received event object.
	 * @return			<code>OPROS_SUCCESS</code> if onEvent() is complete successfully;
	 * 						otherwise, any other return code
	 *
	 * @see			ReturnType
	 */
	virtual ReturnType onEvent(Event *evt);

	/**
	 * Called periodically or aperiodically by the component execution engine only if the state of the component is ACTIVE.
	 * The users can redefine this function to process main jobs.
	 *
	 *   periodic calling : the engine call the onExecute() function with the period specified in the component profile.
	 *   aperiodic calling: the engine call the onExecute() function once.
	 *
	 * @return			<code>OPROS_SUCCESS</code> if onExecute() is complete successfully;
	 * 						otherwise, any other return code
	 *
	 * @see			ReturnType
	 */
	virtual ReturnType onExecute();

	/**
	 * Called after the onExecute() is called.
	 * This function is prepared for two path execution.
	 * The users can redefine this function to process sub jobs.
	 *
	 * 	Two-path-execution:  onExecute() : prepare some algorithm and execute algorithm
	 * 						 onUpdated() : update algorithm results to some others.
	 *
	 * @return			<code>OPROS_SUCCESS</code> if onUpdated() is complete successfully;
	 * 						otherwise, any other return code
	 *
	 * @see			ReturnType
	 */
	virtual ReturnType onUpdated();

	/**
	 * Called if the execution period of the periodic component is changed.
	 * The users can redefine this function for the period change status.
	 *
	 * @return			<code>OPROS_SUCCESS</code> if onPeriodChanged() is complete successfully;
	 * 						otherwise, any other return code
	 *
	 * @see			ReturnType
	 */
	virtual ReturnType onPeriodChanged();
};

#endif /* COMPONENT_H_ */
