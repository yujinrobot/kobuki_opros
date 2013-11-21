/*
 *  OPRoS Component Engine (OCE)
 *  Copyright (c) 2008 ETRI. http://www.etri.re.kr.
 *  Distributed under the OPRoS License, Version 1.0.
 *
 *  @Created : 2009. 2. 18
 *  @Author  : sby (sby@etri.re.kr)
 *
 *  @File    : LifecycleInterface.h
 *
 *
 */

#ifndef LIFECYCLEINTERFACE_H_
#define LIFECYCLEINTERFACE_H_

#include <ReturnType.h>
#include <OPRoSTypes.h>

class LifecycleInterfaceImpl;

/**
 * LifecycleInterface is the abstract base class which allows an outer module of this component
 * to control life cycle of this component.
 */

class LifecycleInterface
{
	LifecycleInterfaceImpl *m_impl;

	friend class LifecycleInterfaceImpl;

public:
	LifecycleInterface();

	//void setService(LifecycleInterfaceImpl *serv);

	virtual ~LifecycleInterface();


	/**
	 * Initialize the component after the component is created.
	 * This function calls the onInitialize() callback function internally.
	 * After the initialization is complete, the component state become the READY state.
	 *
	 * @return 		<code>OPROS_SUCCESS</code> if the initialize() is complete successfully;
	 * 						otherwise, any other return code
	 * @see			ReturnType
	 */
	virtual ReturnType initialize();

	/**
	 * Start the component.
	 * This function calls the onStart() callback function.
	 * After the start() is complete, the component state become the ACTIVE state.
	 *
	 * @return 		<code>OPROS_SUCCESS</code> if the start() is complete successfully;
	 * 						otherwise, any other return code
	 * @see			ReturnType
	 */
	virtual ReturnType start();

	/**
	 * Stop the component in ACTIVE state.
	 * This function calls the onStop() callback function.
	 * After the stop() is complete, the component state become the INACTIVE state.
	 *
	 * @return 		<code>OPROS_SUCCESS</code> if the stop() is complete successfully;
	 * 						otherwise, any other return code
	 * @see			ReturnType
	 */
	virtual ReturnType stop();

	/**
	 * Stop and delete the component instance.
	 * This function calls the onDestroy() callback function.
	 * After the destroy() is complete, the component instance is removed.
	 *
	 * @return 		<code>OPROS_SUCCESS</code> if the destroy() is complete successfully;
	 * 						otherwise, any other return code
	 * @see			ReturnType
	 */
	virtual ReturnType destroy();

	/**
	 * Initialize and Start the component afresh.
	 * This function calls the onReset() callback function ,the onInitialize() and onStart() in order.
	 *
	 * After the reset() is complete, the component state become the ACTIVE state.
	 *
	 * @return 		<code>OPROS_SUCCESS</code> if the reset() is complete successfully;
	 * 						otherwise, any other return code
	 * @see			ReturnType
	 */
	virtual ReturnType reset();


	/**
	 * Transit the component state to be the ERROR state
	 *    when this function is called because some error occurs in the ACTIVE state.
	 * This function calls the onError() callback function.
	 *
	 * @return 		<code>OPROS_SUCCESS</code> if the stopOnError() is complete successfully;
	 * 						otherwise, any other return code
	 * @see			ReturnType
	 */
	virtual ReturnType stopOnError();


	/**
	 * Transit the component state to be the READY state
	 * 	  after the component in the ERROR state is fixed.
	 * This function calls the onRecover() callback function.
	 *
	 * @return 		<code>OPROS_SUCCESS</code> if the recover() is complete successfully;
	 * 						otherwise, any other return code
	 * @see			ReturnType
	 */
	virtual ReturnType recover();


	/**
	 * Get the current life cycle state of the component.
	 *
	 * @return		<code>LifecycleState</code> of the component
	 *
	 * @see			LifecycleState
	 */
	virtual LifecycleState getStatus();

	/**
	 * Get the last RetunType of the component.
	 *
	 * @return		<code>ReturnType</code> of the component
	 *
	 * @see			ReturnType
	 */
	virtual ReturnType getErrorInfo();

protected:
	/**
	 *	Callback function executed when the initialize() function is called.
	 *	The users can redefine this function with their purpose.
	 *
	 *	@return 	<code>OPROS_SUCCESS</code> if the onInitialize() is complete successfully;
	 * 					otherwise, any other return code
	 *  @see		ReturnType
	 */
	virtual ReturnType onInitialize() = 0;

	/**
	 *	Callback function executed when the start() function is called.
	 *	The users can redefine this function with their purpose.
	 *
	 *	@return 	<code>OPROS_SUCCESS</code> if the onStart() is complete successfully;
	 * 					otherwise, any other return code
	 *  @see		ReturnType
	 */
	virtual ReturnType onStart() = 0;

	/**
	 *	Callback function executed when the stop() function is called.
	 *	The users can redefine this function with their purpose.
	 *
	 *	@return 	<code>OPROS_SUCCESS</code> if the onStop() is complete successfully;
	 * 					otherwise, any other return code
	 *  @see		ReturnType
	 */
	virtual ReturnType onStop() = 0;

	/**
	 *	Callback function executed when the destroy() function is called.
	 *	The users can redefine this function with their purpose.
	 *
	 *	@return 	<code>OPROS_SUCCESS</code> if the onDestroy() is complete successfully;
	 * 					otherwise, any other return code
	 *  @see		ReturnType
	 */
	virtual ReturnType onDestroy() = 0;

	/**
	 *	Callback function executed when the reset() function is called.
	 *	The users can redefine this function with their purpose.
	 *
	 *	@return 	<code>OPROS_SUCCESS</code> if the onReset() is complete successfully;
	 * 					otherwise, any other return code
	 *  @see		ReturnType
	 */
	virtual ReturnType onReset() = 0;

	/**
	 *	Callback function executed when the stopOnError() function is called.
	 *	The users can redefine this function with their purpose.
	 *
	 *	@return 	<code>OPROS_SUCCESS</code> if the onError() is complete successfully;
	 * 					otherwise, any other return code
	 *  @see		ReturnType
	 */
	virtual ReturnType onError() = 0;

	/**
	 *	Callback function executed when the recover() function is called.
	 *	The users can redefine this function with their purpose.
	 *
	 *	@return 	<code>OPROS_SUCCESS</code> if the onRecover() is complete successfully;
	 * 					otherwise, any other return code
	 *  @see		ReturnType
	 */
	virtual ReturnType onRecover() = 0;

};

#endif /* LIFECYCLEINTERFACE_H_ */
