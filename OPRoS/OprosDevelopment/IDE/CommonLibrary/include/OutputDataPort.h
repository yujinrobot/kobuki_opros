/*
 *  OPRoS Component Engine (OCE)
 *  Copyright (c) 2008 ETRI. http://www.etri.re.kr.
 *  Distributed under the OPRoS License, Version 1.0.
 *
 *  @Created : 2009. 2. 23
 *  @Author  : sby (sby@etri.re.kr)
 *
 *  @File    : OutputDataPort.h
 *
 *
 */

#ifndef OUTPUTDATAPORT_H_
#define OUTPUTDATAPORT_H_

#include <OutputDataPortInterface.h>

template<typename dataType>
class OutputDataPort: public OutputDataPortInterface {
public:
	OutputDataPort() {
	}

	OutputDataPort(const std::string &name) :
		OutputDataPortInterface(name) {
	}
	virtual ~OutputDataPort() {
	}

	virtual bool checkType(opros_any & data) {
		if (data.empty())
			return false;

		dataType *p=0;

		if (data.type() == getTypeName(p))
			return true;

		return false;
	}
	virtual bool checkType(DataPort *dst) {
		dataType sdata;

		opros_any tdata = sdata;

		return dst->checkType(tdata);
	}

	virtual ReturnType push(opros_any &data)
	{
		return push_data(data);
	}

	virtual ReturnType push(const dataType &data) {
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

		in >> portData;

		//in >> boost::serialization::make_nvp(PORTDATA_NVP, portData);

		mdata = portData;

		return push(mdata);
	}

protected:
	virtual ReturnType marshal(opros_any &data, std::string &outdata)
	{
		if (m_arc== NULL)
		{
			return OPROS_UNSUPPORTED_METHOD;
		}

		dataType *portData = ANY_CASTING(dataType,&data);

		std::stringstream s_str;

		opros::archive::oarchive  *arc = m_arc->getOutputArchive(
						&s_str);

		//(*arc) << boost::serialization::make_nvp(PORTDATA_NVP, (*portData));
		(*arc) <<  (*portData);

		outdata.assign(s_str.str());

		m_arc->release(arc);

		return OPROS_SUCCESS;
	}

};

#endif /* OUTPUTDATAPORT_H_ */
