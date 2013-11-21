/*
 *  OPRoS Component Engine (OCE)
 *  Copyright (c) 2008 ETRI. http://www.etri.re.kr.
 *  Distributed under the OPRoS License, Version 1.0.
 *
 *  @Created : 2009. 2. 18
 *  @Author  : sby (sby@etri.re.kr)
 *
 *  @File    : DataPort.h
 *
 *
 */

#ifndef DATAPORT_H_
#define DATAPORT_H_

#include <Port.h>
#include <ReturnType.h>
#include <OPRoSTypes.h>

/**
 * DataPort is the abstract base class for input or output data port classes
 *
 */
class DataPort : public Port{

public:
	DataPort();
	DataPort(const std::string &name);

	/**
	 * Push or Send one data to the DataPort.
	 *
	 * @param data		data to be stored or sent
	 *
	 * @return			<code>OPROS_SUCCESS</code>  if there is no error.
	 * 					otherwise:
	 * 					<code>OPROS_BAD_INPUT_PARAMETER</code> if the type of the data does not match defined data type for the data port.
	 */
	virtual ReturnType push(opros_any & data) = 0;

	/**
	 * Push or Send encoded data to the DataPort
	 *
	 * @param data		encoded or serialized data to be stored or sent
	 * @param size		size of data
	 *
	 * @return			<code>OPROS_SUCCESS</code>  if there is no error.
	 * 					otherwise:
	 * 					<code>OPROS_UNSUPPORTED_METHOD</code> if the data port cannot decode the encoded data.
	 * 					<code>OPROS_BAD_INPUT_PARAMETER</code> if the type of the data does not match defined data type for the data port.
	 */
	virtual ReturnType pushData(unsigned char *data, int size) = 0;

	/**
	 * Pop or Get one data from the DataPort
	 *
	 * @return			NULL if queue of data port is empty.
	 * 					opros_any data instance pointer if there is one or more data in the data port queue.
	 * 					then, the data is removed from the data port queue.
	 *
	 */
	virtual opros_any* pop() = 0;

	/**
	 * Peek at the data port.
	 *
	 * @return			NULL if queue of data port is empty.
	 * 					opros_any data instance pointer if there is one or more data in the data port queue.
	 * 					but the data port does not remove this data from the queue.
	 */
	virtual opros_any* peek() = 0;

	/**
	 * Check whether the type of the data matches with the defined data type of the data port or not.
	 *
	 * @param	data	data to be examined.
	 *
	 * @return			TRUE if the type corresponds with the type of data port.
	 * 					otherwise
	 * 					FALSE
	 */
	virtual bool checkType(opros_any & data) = 0;

	/**
	 * Check whether the type of DataPort dst matches with the defined data type of the data port or not.
	 *
	 * @param	dst		Dataport to be examined.
	 *
	 * @return			TRUE if the type corresponds with the type of data port.
	 * 					otherwise
	 * 					FALSE
	 */
	virtual bool checkType(DataPort *dst) = 0;

	/**
	 * Get the role of the data port
	 *
	 * @return			<code>OPROS_DATA_PORT_INPUT</code> if the data port is an input data port,
	 * 					<code>OPROS_DATA_PORT_OUTPUT</code> if the data port is an output data port.
	 */
	virtual DataPortRole getRole() = 0;

	/**
	 * Clear data port queue
	 */
	virtual void reset(){};
	virtual ~DataPort();
};

#endif /* DATAPORT_H_ */
