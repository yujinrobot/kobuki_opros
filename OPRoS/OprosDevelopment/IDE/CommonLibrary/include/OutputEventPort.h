/*
 *  OPRoS Component Engine (OCE)
 *  Copyright (c) 2008 ETRI. http://www.etri.re.kr.
 *  Distributed under the OPRoS License, Version 1.0.
 *
 *  @Created : 2009. 2. 23
 *  @Author  : sby (sby@etri.re.kr)
 *
 *  @File    : OutputEventPort.h
 *
 *
 */

#ifndef OUTPUTEVENTPORT_H_
#define OUTPUTEVENTPORT_H_

#include <OutputEventPortInterface.h>
#include <OPRoSTypes.h>

template<typename dataType>
class OutputEventPort: public OutputEventPortInterface {
public:
	OutputEventPort() {
	}

	OutputEventPort(const std::string &name) :
		OutputEventPortInterface(name) {
	}
	virtual ~OutputEventPort() {
	}

	virtual bool checkType(EventPort *dst) {
		if (dst == NULL)
			return false;

		EventData<dataType> somedata;

		return dst->checkType(&somedata);
	}

	virtual bool checkType(Event *data) {
		if (data == NULL)
			return false;

		dataType somedata;

		opros_any someany = somedata;

		return data->checkContentType(someany);
	}

	virtual ReturnType push(Event *data) {
		return push_event(data);
	}

	virtual ReturnType pushEvent(unsigned char *data, int size) {
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

		EventData<dataType> *ndata = new EventData<dataType> ();

		in >> OPROS_SERIALIZATION_MAKE_NVP(EVENTDATA_NVP, *ndata);

		ReturnType ret = push_event((Event *) ndata);
		delete ndata;

		return ret;
	}


	virtual ReturnType marshal(Event *data, std::string &outdata) {

		if (m_arc == NULL) {
			return OPROS_UNSUPPORTED_METHOD;
		}

		EventData<dataType> *ndata = SAFE_CASTING ( EventData<dataType> *, data);
		std::stringstream s_str;

		opros::archive::oarchive *arc = m_arc->getOutputArchive(
				&s_str);

		(*arc) << OPROS_SERIALIZATION_MAKE_NVP(EVENTDATA_NVP, *ndata);

		outdata = s_str.str();

		m_arc->release(arc);

		return OPROS_SUCCESS;

	}
};

#endif /* OUTPUTEVENTPORT_H_ */
