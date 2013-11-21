/*
 *  OPRoS Component Engine (OCE)
 *  Copyright (c) 2008 ETRI. http://www.etri.re.kr.
 *  Distributed under the OPRoS License, Version 1.0.
 *
 *  @Created : 2009. 2. 19
 *  @Author  : sby (sby@etri.re.kr)
 *
 *  @File    : InputDataPort.h
 *
 *
 */

#ifndef INPUTDATAPORT_H_
#define INPUTDATAPORT_H_
#include <OPRoSTypes.h>
#include <DataPort.h>
#include <ReturnType.h>
#include <InputDataPortInterface.h>
#include <ArchiveFactory.h>
#include <sstream>

#include <cstring>

//
//
//  Version 2. InputDataPort can contain Pointer data
// 			  auto deletion is supported.
//
//

template<typename dataType>
class InputDataPort: public InputDataPortInterface {

public:
	InputDataPort() {
	}

	InputDataPort( DataPortPolicy data_policy,unsigned int queue_limit) :
		InputDataPortInterface( data_policy, queue_limit) {	}

	InputDataPort(const std::string &name) :
		InputDataPortInterface(name) {
	}

	InputDataPort(const std::string &name,
			DataPortPolicy data_policy, unsigned int queue_limit) :
		InputDataPortInterface(name,  data_policy, queue_limit) {
	}

	virtual ~InputDataPort() {
	}


	dataType *getContentPointer(opros_any &data) {
		return UNSAFE_ANY_CASTING(dataType,&data);
	}

	dataType getContent(opros_any &data) {
		dataType *pd = ANY_CASTING(dataType, &data);
		return *pd;
	}

	virtual ReturnType push(opros_any &data) {
	/*	dataType *k;

		k = ANY_CASTING(dataType, &data);

		opros_any somedata = *k; */

		return push_data(data);
	}

	virtual ReturnType push(dataType &data) { // 
		opros_any ndata = data;

		return push(ndata);
	}

	virtual ReturnType pushData(unsigned char *data, int size) {
		if (m_arc == NULL) {
			return OPROS_UNSUPPORTED_METHOD;
		}
		std::string d_str((const char *) data, size);
		std::stringstream s_str(d_str);

		opros::archive::iarchive *arc = m_arc->getInputArchive(
				&s_str);

		ReturnType rtV = push(*arc);

		m_arc->release(arc);

		return rtV;
	}

	virtual ReturnType push(opros::archive::iarchive &in) {
		opros_any mdata;

		dataType portData;

//		in >> boost::serialization::make_nvp(PORTDATA_NVP, portData);
		in >> portData;

		mdata = portData;

		return push_data(mdata);
	}

	virtual bool checkType(DataPort *dst)
	{
		dataType sdata;

		opros_any tdata = sdata;

		return dst->checkType(tdata);
	}



	virtual bool checkType(opros_any & data) {
		if (data.empty())
			return false;

		dataType *p=0;
		if (data.type() == getTypeName(p))
			return true;

		return false;
	}

};

#endif /* INPUTDATAPORT_H_ */

