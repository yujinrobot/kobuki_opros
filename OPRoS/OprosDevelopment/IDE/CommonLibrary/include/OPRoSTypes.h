#if !defined(_OPROSTYPES_H)
#define _OPROSTYPES_H
#include <AssertException.h>

typedef enum {
	OPROS_MT_PROVIDED, OPROS_MT_REQUIRED, OPROS_MT_REMOTE,
} MethodType;

typedef enum {
	OPROS_SERVICE, OPROS_EVENT, OPROS_DATA , OPROS_REMOTE_DATA
} PortType;

typedef enum {
	OPROS_FIFO, OPROS_LIFO, OPROS_UFIFO, OPROS_LAST
} DataPortPolicy;

typedef enum {
	OPROS_CS_CREATED, OPROS_CS_READY, OPROS_CS_ACTIVE, OPROS_CS_INACTIVE, OPROS_CS_ERROR, OPROS_CS_DESTROYED
} LifecycleState;

typedef enum {
	OPROS_ES_CREATED, OPROS_ES_ACTIVE, OPROS_ES_INACTIVE, OPROS_ES_ERROR, OPROS_ES_DESTROYED, OPROS_ES_PREPARE_TO_DESTROYED
} ExecutorState;

typedef enum {
	OPROS_DATA_PORT_INPUT, OPROS_DATA_PORT_OUTPUT
} DataPortRole;

typedef enum {
	OPROS_EVENT_PORT_INPUT, OPROS_EVENT_PORT_OUTPUT
} EventPortRole;

typedef enum {
	OPROS_SERVICE_PORT_REQUIRED, OPROS_SERVICE_PORT_PROVIDED
} ServicePortRole;


#define DEFAULT_QUEUE_LIMIT		15
// Message Headers..
//
#define MESSAGE_HEADER_NVP  	"OPRosHeader"
#define MESSAGE_OP_MAGIC_NVP	"OPMagic"
#define METHODCALL_NVP 			"MethodCall"
#define METHODRESULT_NVP 		"MethodResult"
#define PORTDATA_NVP	 		"PortData"
#define DATAPORT_NVP			"DataPort"
#define EVENTPORT_NVP			"EventPort"
#define EVENTDATA_NVP			"EventData"

#define OPROS_HEADER_MAGIC		"OPROS"
#define METHOD_REQUEST_MAGIC	"MQ"
#define METHOD_RESPONE_MAGIC	"MR"
#define REMOTE_DATA_MAGIC		"RD"
#define REMOTE_EVENT_MAGIC		"ED"




#define opros_assert(func)	{if (!(func)) throw AssertException();}

//
// =================== opros::any is modified boost::any for OPROS =============================

// what:  variant type boost::any
// who:   contributed by Kevlin Henney,
//        with features contributed and bugs found by
//        Ed Brey, Mark Rodgers, Peter Dimov, and James Curran
// when:  July 2001
// modified for opros
#ifndef USE_BOOST_ANY
class opros_any
{
	class holder_base
	{
		public:
		virtual ~holder_base() {}

		virtual const std::string type()  = 0;

		virtual holder_base *clone()  = 0;	
	};

	template <typename dataType>
	struct holder: public holder_base
	{
		dataType m_value;
	public:

		holder(const dataType &initValue)
		{
			m_value = initValue;
		}

		virtual const std::string type() 
		{
			return getTypeName(&m_value);
		}


		virtual holder_base *clone() 
		{
			return new holder(m_value);
		}
	};

	holder_base *content;

public: // constructor & destructor

	opros_any() : content(0)
	{
	}

	template <typename dataType>
	opros_any(const dataType &initValue)
	{
		content = new holder<dataType>(initValue);
	}

	opros_any(const opros_any &other)
	{
		content =  other.content ? other.content->clone() : 0;
	}

	~opros_any()
	{
		delete content;
	}

public:
	opros_any &swap(opros_any &rhs)
	{
		std::swap(content, rhs.content);
		return *this;
	}

	template <typename dataType>
	opros_any& operator=(const dataType &rhs)
	{
		opros_any(rhs).swap(*this);
		return *this;
	}

	opros_any& operator=(opros_any rhs)
	{
		rhs.swap(*this);
		return *this;
	}

	bool empty() 
	{
		return !content;
	}

	const std::string type() 
	{
		return content ? content->type() : std::string("void");
	}

private:
	template <typename dataType>
	friend dataType *opros_any_cast(opros_any *);

	template <typename dataType>
	friend dataType *unsafe_opros_any_cast(opros_any *);

};

template <typename dataType>
dataType *opros_any_cast(opros_any *operand)
{
	dataType *t=0;
	return operand && !operand->type().compare(getTypeName(t)) ?
		&static_cast< opros_any::holder<dataType> *>(operand->content)->m_value : 0;
}

template <typename dataType>
inline const dataType *opros_any_cast(const opros_any *operand)
{
	return opros_any_cast<dataType>(const_cast<opros_any*>(operand));
}


template <typename dataType>
dataType opros_any_cast(opros_any &operand)
{
	dataType *t=0;
	opros_any *pp = &operand;

	t = opros_any_cast<dataType>(pp);

	return *t;
}

template <typename dataType>
inline dataType *unsafe_opros_any_cast(opros_any *operand)
{	
	return &static_cast< opros_any::holder<dataType> *>(operand->content)->m_value;
}

template <typename dataType>
inline const dataType *unsafe_opros_any_cast(const opros_any *operand)
{	
	return unsafe_opros_any_cast<dataType>(const_cast<opros_any *>(operand));
}

#ifdef _MSC_VER
#define SAFE_CASTING(a,b) (dynamic_cast<a>(b))
#define ANY_CASTING(a,b) (opros_any_cast<a>(b))
#define UNSAFE_ANY_CASTING(a,b) (unsafe_opros_any_cast<a>(b))
#else
#define SAFE_CASTING(a,b) (static_cast<a>(b))
#define ANY_CASTING(a,b) (unsafe_opros_any_cast<a>(b))
#define UNSAFE_ANY_CASTING(a,b) (unsafe_opros_any_cast<a>(b))
#endif


#else
#include <boost/any.hpp>
#define opros_any	boost::any
#ifdef _MSC_VER
#define SAFE_CASTING(a,b) (dynamic_cast<a>(b))
#define ANY_CASTING(a,b) (boost::any_cast<a>(b))
#define UNSAFE_ANY_CASTING(a,b) (boost::unsafe_any_cast<a>(b))
#else
#define SAFE_CASTING(a,b) (static_cast<a>(b))
#define ANY_CASTING(a,b) (boost::unsafe_any_cast<a>(b))
#define UNSAFE_ANY_CASTING(a,b) (boost::unsafe_any_cast<a>(b))
#endif
#endif

#endif  // _OPROSTYPES_H
