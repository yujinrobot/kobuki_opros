/*
 *  OPRoS Component Engine (OCE)
 *  Copyright (c) 2008 ETRI. http://www.etri.re.kr.
 *  Distributed under the OPRoS License, Version 1.0.
 *
 *  @Created : 2009. 2. 23
 *  @Author  : sby (sby@etri.re.kr)
 *
 *  @File    : InputEventPort.h
 *
 *
 */

#ifndef INPUTEVENTPORT_H_
#define INPUTEVENTPORT_H_

#include <InputEventPortInterface.h>
#include <EventData.h>
#include <Component.h>


template<typename dataType>
class InputEventPort: public InputEventPortInterface {
protected:

public:
	InputEventPort() {
	}

	InputEventPort(const std::string &name) :
		InputEventPortInterface(name) {
	}

	virtual ~InputEventPort() {
	}

	virtual bool checkType(EventPort *dst)
	{
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


	virtual ReturnType push(Event *data)
	{
		if (data == NULL) return OPROS_BAD_INPUT_PARAMETER;

		Event *ndata = data->clone();

		ReturnType ret = push_event(ndata);

		delete ndata;

		return ret;
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

		EventData<dataType> *event_data = new EventData<dataType> ();

		in >> OPROS_SERIALIZATION_MAKE_NVP(EVENTDATA_NVP, *event_data);

		ReturnType ret = push_event( (Event *)event_data);
		delete event_data;

		return ret; 	
	}
};

#endif /* INPUTEVENTPORT_H_ */
