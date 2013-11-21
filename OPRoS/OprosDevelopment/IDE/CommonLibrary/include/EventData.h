/*
 *  OPRoS Component Engine (OCE)
 *  Copyright (c) 2008 ETRI. http://www.etri.re.kr.
 *  Distributed under the OPRoS License, Version 1.0.
 *
 *  @Created : 2009. 2. 23
 *  @Author  : sby (sby@etri.re.kr)
 *
 *  @File    : EventData.h
 *
 *
 */

#ifndef EVENTDATA_H_
#define EVENTDATA_H_

#include <Event.h> 
#include <cstring>

template<typename dataType>
class EventData: public Event {

public:
	EventData() {


	}

	virtual ~EventData() {
	}

	virtual bool checkContentType(opros_any &data) {
		if (data.empty())
			return false;

		dataType *p=0;
		if (data.type() == getTypeName(p))
			return true;

		return false;
	}

	virtual dataType *getContentData() {
		dataType *somdata;

		somdata = ANY_CASTING(dataType, &getContent());

		return somdata;
	}
	virtual ReturnType setContentData(const dataType &data) {
		opros_any somdata = data;
		return setContent(somdata);
	}

	EventData<dataType> &operator=(const EventData<dataType> &rhs) {
		setId(rhs.getId());
		setTopic(rhs.getTopic());
		setComponentId(rhs.getComponentId());
		setPortId(rhs.getPortId());

		dataType *org = rhs.getContentData();

		if (org != NULL) {
			setContentData(*org);
		}

		return *this;
	}

	virtual Event *clone() {
		EventData<dataType> *ev = new EventData<dataType> ();

		ev->setId(getId());
		ev->setTopic(getTopic());
		ev->setComponentId(getComponentId());
		ev->setPortId(getPortId());

		dataType *org = getContentData();
		if (org != NULL) {
			ev->setContentData(*org);
		}

		return ev;
	}

protected:

	friend std::ostream &operator<<(std::ostream &os,
			const EventData<dataType> &ev) {
				EventData<dataType> &nv = (EventData<dataType> &)ev;
				return os << "[eventid:" << nv.getId() << ",topic:"<<nv.getTopic()<<",componentid:"
				<< nv.getComponentId() << ",portid:" << nv.getPortId() << "]";
	}

};


template<class T>
inline void save_this(opros::archive::oarchive &ar, EventData<T> &t)
{
	std::string &eventid = t.getId();
	ar << OPROS_SERIALIZATION_NVP(eventid);
	std::string &topicid = t.getTopic();
	ar << OPROS_SERIALIZATION_NVP(topicid);
	std::string &componentid = t.getComponentId();
	ar << OPROS_SERIALIZATION_NVP(componentid);
	std::string &portid = t.getPortId();
	ar << OPROS_SERIALIZATION_NVP(portid);

	bool IsContent = false;
	T *content_ptr = t.getContentData();
	if (content_ptr != NULL) {
		IsContent = true;
		T &content = *content_ptr;
		ar << OPROS_SERIALIZATION_NVP(IsContent);
		ar << OPROS_SERIALIZATION_NVP(content); // for NVP naming
	} else {
		ar << OPROS_SERIALIZATION_NVP(IsContent);
	}
}


template<class T>
inline void load_this(opros::archive::iarchive  &ar, EventData<T> &t) {

	std::string eventid;
	ar >> OPROS_SERIALIZATION_NVP(eventid);
	std::string topicid;
	ar >> OPROS_SERIALIZATION_NVP(topicid);
	std::string componentid;
	ar >> OPROS_SERIALIZATION_NVP(componentid);
	std::string portid;
	ar >> OPROS_SERIALIZATION_NVP(portid);

	t.setId(eventid);
	t.setTopic(topicid);
	t.setComponentId(componentid);
	t.setPortId(portid);

	bool IsContent;
	ar >> OPROS_SERIALIZATION_NVP(IsContent);

	if (IsContent) {
		T content;
		ar >> OPROS_SERIALIZATION_NVP(content);
		t.setContentData(content);
	}
}

template <class T>
inline std::string typeName(EventData<T> *t)
{
	std::string name("EventData<");
	T *sam=0;
	return name.append(getTypeName(sam)).append(">");
}


#endif /* EVENTDATA_H_ */
