/*
 *  OPRoS Component Engine (OCE)
 *  Copyright (c) 2008 ETRI. http://www.etri.re.kr.
 *  Distributed under the OPRoS License, Version 1.0.
 *
 *  @Created : 2009. 2. 27
 *  @Author  : sby (sby@etri.re.kr)
 *
 *  @File    : RequiredServicePort.h
 *
 *
 */

#ifndef REQUIREDSERVICEPORT_H_
#define REQUIREDSERVICEPORT_H_

#include "ServicePortInterface.h"
#include <ServicePortConnector.h>

class RequiredServicePortImpl;
class RequiredServicePort: public ServicePortInterface {
	RequiredServicePortImpl *m_rsimpl;
	friend class RequiredServicePortImpl;
public:
	RequiredServicePort();
	RequiredServicePort(const std::string &name);
	virtual ~RequiredServicePort();

	/*
	 *  Clear all connected connector or peer
	 */
	virtual ReturnType Disconnect();

	/**
	 * Set a ServicePortConnector to connect with Remote Peer (Provided Service Port)
	 * When this method is called, the peer set from calling setPeer before will be clear.
	 *
	 * @param	con 	an ServicePortConnector
	 * @return			state of operation
	 */
	virtual ReturnType setConnector(ServicePortConnector *con);

	/*
	 * Set a Peer Service Port (local Provided Service Port)
	 * When this method is called, the connector set from calling setConnector before will be clear.
	 *
	 * @param 	peer 	an ServicePort (ProvidedServicePort)
	 * @return  		state of operation
	 */
	virtual ReturnType setPeer(ServicePort *peer);

	/*
	 * In RequiredServicePort, this method just calls callService of Connector or Peer.
	 *
	 * @param  name		method name
	 * @param  invalue	encoded input argument string
	 * @param  outvalue	encoded output result string
	 */
	virtual ReturnType callService(std::string &name, std::string &invalue,
			std::string &outvalue);

	virtual ServicePortRole getRole() ;
};

#endif /* REQUIREDSERVICEPORT_H_ */
