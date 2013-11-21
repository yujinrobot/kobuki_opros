/*
 *  OPRoS Component Engine (OCE)
 *  Copyright (c) 2008 ETRI. http://www.etri.re.kr.
 *  Distributed under the OPRoS License, Version 1.0.
 *
 *  @Created : 2009. 2. 18
 *  @Modified: 2011. 3. 18 (arity and returnType info are added, use opros archive)
 *  @Author  : sby (sby@etri.re.kr)
 *
 *  @File    : RequiredMethod.h
 *
 *
 */

#if !defined(_REQUIREDMETHOD_H)
#define _REQUIREDMETHOD_H


#include <ArgumentNumberException.h>

#include <OPRoSTypes.h>
#include <ArchiveFactory.h>
#include <ProvidedMethod.h>
#include <Method.h>
#include <MethodInvokeException.h>
#include <RequiredMethodInterface.h>

template<typename RetType>
class RequiredMethod: public RequiredMethodInterface {
protected:
	typedef ProvidedMethod<RetType> provided_method_type;

	ProvidedMethod<RetType> *m_peer;
	;
	ServicePortConnector *m_con;


	const int m_arity;
	std::string m_returnType;


public:
	virtual ReturnType call(opros::archive::iarchive &in,
			opros::archive::oarchive &out) {
		if (m_peer != NULL)
			return m_peer->call(in, out);

		return OPROS_UNSUPPORTED_METHOD;
	}


	RequiredMethod(const std::string &name, int arity) :
	    RequiredMethodInterface(name),
	    m_arity(arity)
		 {
		m_peer = NULL;
		m_con = NULL;
		//m_returnType = typeid(RetType).name();
		RetType *p=0;
		m_returnType = getTypeName(p);
	}

	virtual std::string &getReturnType()
	{
		return m_returnType;
	}


	virtual int getArity()
	{
		return m_arity;
	}

	virtual ~RequiredMethod() {

	}

	virtual ReturnType Disconnect() {
		m_peer = NULL;
		m_con = NULL;

		return OPROS_SUCCESS;
	}

	virtual ReturnType Connect(Method *peer) {
		m_peer = reinterpret_cast<provided_method_type *> (peer);
		return OPROS_SUCCESS;
	}

	virtual ReturnType Connect(ServicePortConnector *peer) {
		m_peer = NULL;
		m_con = peer;
		return OPROS_SUCCESS;
	}

	RetType operator()() {
		if (m_peer != NULL) {
			return (*m_peer)();
		} else if (m_con != NULL) {
			if (m_arc == NULL) {
				throw MethodInvokeException(
						"you have to call setArchiveFactory for RequiredMethod.");
			}
			std::string sname = m_name;

			std::string outvalue;
			std::stringstream instr;
			std::string void_str("v");

			opros::archive::oarchive *inV =
			m_arc->getOutputArchive(&instr);
			
			(*inV) << OPROS_SERIALIZATION_NVP(void_str);
			std::string invalue = instr.str();

			outvalue.reserve(1);
			if (m_con!=NULL) m_con->requestService(sname, invalue, outvalue);
			std::stringstream retstr(outvalue);

			opros::archive::iarchive *retV =
					m_arc->getInputArchive(&retstr);

			RetType resultData;

			(*retV) >> OPROS_SERIALIZATION_NVP(resultData);

			m_arc->release(retV);
			m_arc->release(inV);

			return resultData;
		} else {
			throw MethodInvokeException("method peer can not be NULL.");
		}
	}

	template<typename P1>
	RetType operator()(P1 param1) {
		if (m_peer != NULL) {
			return (*m_peer).operator ()<P1>(param1);
		} else if (m_con != NULL) {
			if (m_arc == NULL) {
				throw MethodInvokeException(
						"you have to call setArchiveFactory for RequiredMethod.");
			}
			std::string sname = m_name;
			std::string outvalue;
			std::stringstream instr;

			opros::archive::oarchive *inV =
			m_arc->getOutputArchive(&instr);

			(*inV) << OPROS_SERIALIZATION_NVP(param1);
			std::string invalue = instr.str();

			outvalue.reserve(1);
			if (m_con!=NULL) m_con->requestService(sname, invalue, outvalue);
			std::stringstream retstr(outvalue);

			opros::archive::iarchive *retV =
			m_arc->getInputArchive(&retstr);

			RetType resultData;

			(*retV) >> OPROS_SERIALIZATION_NVP(resultData);

			m_arc->release(retV);
			m_arc->release(inV);

			return resultData;

		} else {
			throw MethodInvokeException("method peer can not be NULL.");
		}

	}

	template<typename P1, typename P2>
	RetType operator()(P1 param1, P2 param2) {
		if (m_peer != NULL) {
			return (*m_peer).operator ()<P1,P2>(param1, param2);
		} else if (m_con != NULL) {
			if (m_arc == NULL) {
				throw MethodInvokeException(
						"you have to call setArchiveFactory for RequiredMethod.");
			}
			std::string sname = m_name;
			std::string outvalue;
			std::stringstream instr;

			opros::archive::oarchive *inV =
			m_arc->getOutputArchive(&instr);

			(*inV) << OPROS_SERIALIZATION_NVP(param1);
			(*inV) << OPROS_SERIALIZATION_NVP(param2);
			std::string invalue = instr.str();

			outvalue.reserve(1);
			if (m_con!=NULL) m_con->requestService(sname, invalue, outvalue);
			std::stringstream retstr(outvalue);

			opros::archive::iarchive *retV =
			m_arc->getInputArchive(&retstr);

			RetType resultData;

			(*retV) >> OPROS_SERIALIZATION_NVP(resultData);

			m_arc->release(retV);
			m_arc->release(inV);

			return resultData;

		} else {
			throw MethodInvokeException("method peer can not be NULL.");
		}
	}

	template<typename P1, typename P2, typename P3>
	RetType operator()(P1 param1, P2 param2, P3 param3) {
		if (m_peer != NULL) {
			return (*m_peer).operator ()<P1,P2,P3>(param1, param2, param3);
		} else if (m_con != NULL) {
			if (m_arc == NULL) {
				throw MethodInvokeException(
						"you have to call setArchiveFactory for RequiredMethod.");
			}
			std::string sname = m_name;
			std::string outvalue;
			std::stringstream instr;

			opros::archive::oarchive *inV =
			m_arc->getOutputArchive(&instr);

			(*inV) << OPROS_SERIALIZATION_NVP(param1);
			(*inV) << OPROS_SERIALIZATION_NVP(param2);
			(*inV) << OPROS_SERIALIZATION_NVP(param3);
			std::string invalue = instr.str();

			outvalue.reserve(1);
			if (m_con!=NULL) m_con->requestService(sname, invalue, outvalue);
			std::stringstream retstr(outvalue);

			opros::archive::iarchive *retV =
			m_arc->getInputArchive(&retstr);

			RetType resultData;

			(*retV) >> OPROS_SERIALIZATION_NVP(resultData);

			m_arc->release(retV);
			m_arc->release(inV);

			return resultData;

		} else {
			throw MethodInvokeException("method peer can not be NULL.");
		}
	}

	template<typename P1, typename P2, typename P3, typename P4>
	RetType operator()(P1 param1, P2 param2, P3 param3, P4 param4) {
		if (m_peer != NULL) {
			return (*m_peer).operator ()<P1,P2,P3,P4>(param1, param2, param3, param4);
		} else if (m_con != NULL) {
			if (m_arc == NULL) {
				throw MethodInvokeException(
						"you have to call setArchiveFactory for RequiredMethod.");
			}
			std::string sname = m_name;
			std::string outvalue;
			std::stringstream instr;

			opros::archive::oarchive *inV =
			m_arc->getOutputArchive(&instr);

			(*inV) << OPROS_SERIALIZATION_NVP(param1);
			(*inV) << OPROS_SERIALIZATION_NVP(param2);
			(*inV) << OPROS_SERIALIZATION_NVP(param3);
			(*inV) << OPROS_SERIALIZATION_NVP(param4);
			std::string invalue = instr.str();

			outvalue.reserve(1);
			if (m_con!=NULL) m_con->requestService(sname, invalue, outvalue);
			std::stringstream retstr(outvalue);

			opros::archive::iarchive *retV =
			m_arc->getInputArchive(&retstr);

			RetType resultData;

			(*retV) >> OPROS_SERIALIZATION_NVP(resultData);

			m_arc->release(retV);
			m_arc->release(inV);

			return resultData;

		} else {
			throw MethodInvokeException("method peer can not be NULL.");
		}
	}

	template<typename P1, typename P2, typename P3, typename P4, typename P5>
	RetType operator()(P1 param1, P2 param2, P3 param3, P4 param4, P5 param5) {
		if (m_peer != NULL) {
			return (*m_peer).operator ()<P1,P2,P3,P4,P5>(param1, param2, param3, param4, param5);
		} else if (m_con != NULL) {
			if (m_arc == NULL) {
				throw MethodInvokeException(
						"you have to call setArchiveFactory for RequiredMethod.");
			}
			std::string sname = m_name;
			std::string outvalue;
			std::stringstream instr;

			opros::archive::oarchive *inV =
			m_arc->getOutputArchive(&instr);

			(*inV) << OPROS_SERIALIZATION_NVP(param1);
			(*inV) << OPROS_SERIALIZATION_NVP(param2);
			(*inV) << OPROS_SERIALIZATION_NVP(param3);
			(*inV) << OPROS_SERIALIZATION_NVP(param4);
			(*inV) << OPROS_SERIALIZATION_NVP(param5);
			std::string invalue = instr.str();

			outvalue.reserve(1);
			if (m_con!=NULL) m_con->requestService(sname, invalue, outvalue);
			std::stringstream retstr(outvalue);

			opros::archive::iarchive *retV =
			m_arc->getInputArchive(&retstr);

			RetType resultData;

			(*retV) >> OPROS_SERIALIZATION_NVP(resultData);

			m_arc->release(retV);
			m_arc->release(inV);

			return resultData;

		} else {
			throw MethodInvokeException("method peer can not be NULL.");
		}
	}

	template<typename P1, typename P2, typename P3, typename P4, typename P5,
	typename P6>
	RetType operator()(P1 param1, P2 param2, P3 param3, P4 param4, P5 param5, P6 param6) {
		if (m_peer != NULL) {
			return (*m_peer).operator ()<P1,P2,P3,P4,P5,P6>(param1, param2, param3, param4, param5, param6);
		} else if (m_con != NULL) {
			if (m_arc == NULL) {
				throw MethodInvokeException(
						"you have to call setArchiveFactory for RequiredMethod.");
			}
			std::string sname = m_name;
			std::string outvalue;
			std::stringstream instr;

			opros::archive::oarchive *inV =
			m_arc->getOutputArchive(&instr);

			(*inV) << OPROS_SERIALIZATION_NVP(param1);
			(*inV) << OPROS_SERIALIZATION_NVP(param2);
			(*inV) << OPROS_SERIALIZATION_NVP(param3);
			(*inV) << OPROS_SERIALIZATION_NVP(param4);
			(*inV) << OPROS_SERIALIZATION_NVP(param5);
			(*inV) << OPROS_SERIALIZATION_NVP(param6);
			std::string invalue = instr.str();

			outvalue.reserve(1);
			if (m_con!=NULL) m_con->requestService(sname, invalue, outvalue);
			std::stringstream retstr(outvalue);

			opros::archive::iarchive *retV =
			m_arc->getInputArchive(&retstr);

			RetType resultData;

			(*retV) >> OPROS_SERIALIZATION_NVP(resultData);

			m_arc->release(retV);
			m_arc->release(inV);

			return resultData;

		} else {
			throw MethodInvokeException("method peer can not be NULL.");
		}
	}

	template<typename P1, typename P2, typename P3, typename P4, typename P5,
	typename P6, typename P7>
	RetType operator()(P1 param1, P2 param2, P3 param3, P4 param4, P5 param5, P6 param6,
			P7 param7) {
		if (m_peer != NULL) {
			return (*m_peer).operator ()<P1,P2,P3,P4,P5,P6,P7>(param1, param2, param3, param4, param5, param6,
					param7);
		} else if (m_con != NULL) {
			if (m_arc == NULL) {
				throw MethodInvokeException(
						"you have to call setArchiveFactory for RequiredMethod.");
			}
			std::string sname = m_name;
			std::string outvalue;
			std::stringstream instr;

			opros::archive::oarchive *inV =
			m_arc->getOutputArchive(&instr);

			(*inV) << OPROS_SERIALIZATION_NVP(param1);
			(*inV) << OPROS_SERIALIZATION_NVP(param2);
			(*inV) << OPROS_SERIALIZATION_NVP(param3);
			(*inV) << OPROS_SERIALIZATION_NVP(param4);
			(*inV) << OPROS_SERIALIZATION_NVP(param5);
			(*inV) << OPROS_SERIALIZATION_NVP(param6);
			(*inV) << OPROS_SERIALIZATION_NVP(param7);
			std::string invalue = instr.str();

			outvalue.reserve(1);
			if (m_con!=NULL) m_con->requestService(sname, invalue, outvalue);
			std::stringstream retstr(outvalue);

			opros::archive::iarchive *retV =
			m_arc->getInputArchive(&retstr);

			RetType resultData;

			(*retV) >> OPROS_SERIALIZATION_NVP(resultData);

			m_arc->release(retV);
			m_arc->release(inV);

			return resultData;

		} else {
			throw MethodInvokeException("method peer can not be NULL.");
		}
	}

	template<typename P1, typename P2, typename P3, typename P4, typename P5,
	typename P6, typename P7, typename P8>
	RetType operator()(P1 param1, P2 param2, P3 param3, P4 param4, P5 param5, P6 param6,
			P7 param7, P8 param8) {
		if (m_peer != NULL) {
			return (*m_peer).operator ()<P1,P2,P3,P4,P5,P6,P7,P8>(param1, param2, param3, param4, param5, param6,
					param7, param8);
		} else if (m_con != NULL) {
			if (m_arc == NULL) {
				throw MethodInvokeException(
						"you have to call setArchiveFactory for RequiredMethod.");
			}
			std::string sname = m_name;
			std::string outvalue;
			std::stringstream instr;

			opros::archive::oarchive *inV =
			m_arc->getOutputArchive(&instr);

			(*inV) << OPROS_SERIALIZATION_NVP(param1);
			(*inV) << OPROS_SERIALIZATION_NVP(param2);
			(*inV) << OPROS_SERIALIZATION_NVP(param3);
			(*inV) << OPROS_SERIALIZATION_NVP(param4);
			(*inV) << OPROS_SERIALIZATION_NVP(param5);
			(*inV) << OPROS_SERIALIZATION_NVP(param6);
			(*inV) << OPROS_SERIALIZATION_NVP(param7);
			(*inV) << OPROS_SERIALIZATION_NVP(param8);
			std::string invalue = instr.str();

			outvalue.reserve(1);
			if (m_con!=NULL) m_con->requestService(sname, invalue, outvalue);
			std::stringstream retstr(outvalue);

			opros::archive::iarchive *retV =
			m_arc->getInputArchive(&retstr);

			RetType resultData;

			(*retV) >> OPROS_SERIALIZATION_NVP(resultData);

			m_arc->release(retV);
			m_arc->release(inV);

			return resultData;

		} else {
			throw MethodInvokeException("method peer can not be NULL.");
		}
	}

	template<typename P1, typename P2, typename P3, typename P4, typename P5,
	typename P6, typename P7, typename P8, typename P9>
	RetType operator()(P1 param1, P2 param2, P3 param3, P4 param4, P5 param5, P6 param6,
			P7 param7, P8 param8, P9 param9) {
		if (m_peer != NULL) {
			return (*m_peer).operator ()<P1,P2,P3,P4,P5,P6,P7,P8,P9>(param1, param2, param3, param4, param5, param6,
					param7, param8, param9);
		} else if (m_con != NULL) {
			if (m_arc == NULL) {
				throw MethodInvokeException(
						"you have to call setArchiveFactory for RequiredMethod.");
			}
			std::string sname = m_name;
			std::string outvalue;
			std::stringstream instr;

			opros::archive::oarchive *inV =
			m_arc->getOutputArchive(&instr);

			(*inV) << OPROS_SERIALIZATION_NVP(param1);
			(*inV) << OPROS_SERIALIZATION_NVP(param2);
			(*inV) << OPROS_SERIALIZATION_NVP(param3);
			(*inV) << OPROS_SERIALIZATION_NVP(param4);
			(*inV) << OPROS_SERIALIZATION_NVP(param5);
			(*inV) << OPROS_SERIALIZATION_NVP(param6);
			(*inV) << OPROS_SERIALIZATION_NVP(param7);
			(*inV) << OPROS_SERIALIZATION_NVP(param8);
			(*inV) << OPROS_SERIALIZATION_NVP(param9);
			std::string invalue = instr.str();

			outvalue.reserve(1);
			if (m_con!=NULL) m_con->requestService(sname, invalue, outvalue);
			std::stringstream retstr(outvalue);

			opros::archive::iarchive *retV =
			m_arc->getInputArchive(&retstr);

			RetType resultData;

			(*retV) >> OPROS_SERIALIZATION_NVP(resultData);

			m_arc->release(retV);
			m_arc->release(inV);

			return resultData;

		} else {
			throw MethodInvokeException("method peer can not be NULL.");
		}
	}

	template<typename P1, typename P2, typename P3, typename P4, typename P5,
	typename P6, typename P7, typename P8, typename P9, typename P10>
	RetType operator()(P1 param1, P2 param2, P3 param3, P4 param4, P5 param5, P6 param6,
			P7 param7, P8 param8, P9 param9, P10 param10) {
		if (m_peer != NULL) {
			return (*m_peer).operator ()<P1,P2,P3,P4,P5,P6,P7,P8,P9,P10>(param1, param2, param3, param4, param5, param6,
					param7, param8, param9, param10);
		} else if (m_con != NULL) {
			if (m_arc == NULL) {
				throw MethodInvokeException(
						"you have to call setArchiveFactory for RequiredMethod.");
			}
			std::string sname = m_name;
			std::string outvalue;
			std::stringstream instr;

			opros::archive::oarchive *inV =
			m_arc->getOutputArchive(&instr);

			(*inV) << OPROS_SERIALIZATION_NVP(param1);
			(*inV) << OPROS_SERIALIZATION_NVP(param2);
			(*inV) << OPROS_SERIALIZATION_NVP(param3);
			(*inV) << OPROS_SERIALIZATION_NVP(param4);
			(*inV) << OPROS_SERIALIZATION_NVP(param5);
			(*inV) << OPROS_SERIALIZATION_NVP(param6);
			(*inV) << OPROS_SERIALIZATION_NVP(param7);
			(*inV) << OPROS_SERIALIZATION_NVP(param8);
			(*inV) << OPROS_SERIALIZATION_NVP(param9);
			(*inV) << OPROS_SERIALIZATION_NVP(param10);
			std::string invalue = instr.str();

			outvalue.reserve(1);
			if (m_con!=NULL) m_con->requestService(sname, invalue, outvalue);
			std::stringstream retstr(outvalue);

			opros::archive::iarchive *retV =
			m_arc->getInputArchive(&retstr);

			RetType resultData;

			(*retV) >> OPROS_SERIALIZATION_NVP(resultData);

			m_arc->release(retV);
			m_arc->release(inV);

			return resultData;

		} else {
			throw MethodInvokeException("method peer can not be NULL.");
		}
	}

	template<typename P1, typename P2, typename P3, typename P4, typename P5,
	typename P6, typename P7, typename P8, typename P9, typename P10,
	typename P11>
	RetType operator()(P1 param1, P2 param2, P3 param3, P4 param4, P5 param5, P6 param6,
			P7 param7, P8 param8, P9 param9, P10 param10, P11 param11) {
		if (m_peer != NULL) {
			return (*m_peer).operator ()<P1,P2,P3,P4,P5,P6,P7,P8,P9,P10,P11>(param1, param2, param3, param4, param5, param6,
					param7, param8, param9, param10, param11);
		} else if (m_con != NULL) {
			if (m_arc == NULL) {
				throw MethodInvokeException(
						"you have to call setArchiveFactory for RequiredMethod.");
			}
			std::string sname = m_name;
			std::string outvalue;
			std::stringstream instr;

			opros::archive::oarchive *inV =
			m_arc->getOutputArchive(&instr);

			(*inV) << OPROS_SERIALIZATION_NVP(param1);
			(*inV) << OPROS_SERIALIZATION_NVP(param2);
			(*inV) << OPROS_SERIALIZATION_NVP(param3);
			(*inV) << OPROS_SERIALIZATION_NVP(param4);
			(*inV) << OPROS_SERIALIZATION_NVP(param5);
			(*inV) << OPROS_SERIALIZATION_NVP(param6);
			(*inV) << OPROS_SERIALIZATION_NVP(param7);
			(*inV) << OPROS_SERIALIZATION_NVP(param8);
			(*inV) << OPROS_SERIALIZATION_NVP(param9);
			(*inV) << OPROS_SERIALIZATION_NVP(param10);
			(*inV) << OPROS_SERIALIZATION_NVP(param11);
			std::string invalue = instr.str();

			outvalue.reserve(1);
			if (m_con!=NULL) m_con->requestService(sname, invalue, outvalue);
			std::stringstream retstr(outvalue);

			opros::archive::iarchive *retV =
			m_arc->getInputArchive(&retstr);

			RetType resultData;

			(*retV) >> OPROS_SERIALIZATION_NVP(resultData);

			m_arc->release(retV);
			m_arc->release(inV);

			return resultData;

		} else {
			throw MethodInvokeException("method peer can not be NULL.");
		}
	}

	template<typename P1, typename P2, typename P3, typename P4, typename P5,
	typename P6, typename P7, typename P8, typename P9, typename P10,
	typename P11, typename P12>
	RetType operator()(P1 param1, P2 param2, P3 param3, P4 param4, P5 param5, P6 param6,
			P7 param7, P8 param8, P9 param9, P10 param10, P11 param11,
			P12 param12) {
		if (m_peer != NULL) {
			return (*m_peer).operator ()<P1,P2,P3,P4,P5,P6,P7,P8,P9,P10,P11,P12>(param1, param2, param3, param4, param5, param6,
					param7, param8, param9, param10, param11, param12);
		} else if (m_con != NULL) {
			if (m_arc == NULL) {
				throw MethodInvokeException(
						"you have to call setArchiveFactory for RequiredMethod.");
			}
			std::string sname = m_name;
			std::string outvalue;
			std::stringstream instr;

			opros::archive::oarchive *inV =
			m_arc->getOutputArchive(&instr);

			(*inV) << OPROS_SERIALIZATION_NVP(param1);
			(*inV) << OPROS_SERIALIZATION_NVP(param2);
			(*inV) << OPROS_SERIALIZATION_NVP(param3);
			(*inV) << OPROS_SERIALIZATION_NVP(param4);
			(*inV) << OPROS_SERIALIZATION_NVP(param5);
			(*inV) << OPROS_SERIALIZATION_NVP(param6);
			(*inV) << OPROS_SERIALIZATION_NVP(param7);
			(*inV) << OPROS_SERIALIZATION_NVP(param8);
			(*inV) << OPROS_SERIALIZATION_NVP(param9);
			(*inV) << OPROS_SERIALIZATION_NVP(param10);
			(*inV) << OPROS_SERIALIZATION_NVP(param11);
			(*inV) << OPROS_SERIALIZATION_NVP(param12);
			std::string invalue = instr.str();

			outvalue.reserve(1);
			if (m_con!=NULL) m_con->requestService(sname, invalue, outvalue);
			std::stringstream retstr(outvalue);

			opros::archive::iarchive *retV =
			m_arc->getInputArchive(&retstr);

			RetType resultData;

			(*retV) >> OPROS_SERIALIZATION_NVP(resultData);

			m_arc->release(retV);
			m_arc->release(inV);

			return resultData;

		} else {
			throw MethodInvokeException("method peer can not be NULL.");
		}
	}

	template<typename P1, typename P2, typename P3, typename P4, typename P5,
	typename P6, typename P7, typename P8, typename P9, typename P10,
	typename P11, typename P12, typename P13>
	RetType operator()(P1 param1, P2 param2, P3 param3, P4 param4, P5 param5, P6 param6,
			P7 param7, P8 param8, P9 param9, P10 param10, P11 param11,
			P12 param12, P13 param13) {
		if (m_peer != NULL) {
			return (*m_peer).operator ()<P1,P2,P3,P4,P5,P6,P7,P8,P9,P10,P11,P12,P13>(param1, param2, param3, param4, param5, param6,
					param7, param8, param9, param10, param11, param12, param13);
		} else if (m_con != NULL) {
			if (m_arc == NULL) {
				throw MethodInvokeException(
						"you have to call setArchiveFactory for RequiredMethod.");
			}
			std::string sname = m_name;
			std::string outvalue;
			std::stringstream instr;

			opros::archive::oarchive *inV =
			m_arc->getOutputArchive(&instr);

			(*inV) << OPROS_SERIALIZATION_NVP(param1);
			(*inV) << OPROS_SERIALIZATION_NVP(param2);
			(*inV) << OPROS_SERIALIZATION_NVP(param3);
			(*inV) << OPROS_SERIALIZATION_NVP(param4);
			(*inV) << OPROS_SERIALIZATION_NVP(param5);
			(*inV) << OPROS_SERIALIZATION_NVP(param6);
			(*inV) << OPROS_SERIALIZATION_NVP(param7);
			(*inV) << OPROS_SERIALIZATION_NVP(param8);
			(*inV) << OPROS_SERIALIZATION_NVP(param9);
			(*inV) << OPROS_SERIALIZATION_NVP(param10);
			(*inV) << OPROS_SERIALIZATION_NVP(param11);
			(*inV) << OPROS_SERIALIZATION_NVP(param12);
			(*inV) << OPROS_SERIALIZATION_NVP(param13);
			std::string invalue = instr.str();

			outvalue.reserve(1);
			if (m_con!=NULL) m_con->requestService(sname, invalue, outvalue);
			std::stringstream retstr(outvalue);

			opros::archive::iarchive *retV =
			m_arc->getInputArchive(&retstr);

			RetType resultData;

			(*retV) >> OPROS_SERIALIZATION_NVP(resultData);

			m_arc->release(retV);
			m_arc->release(inV);

			return resultData;

		} else {
			throw MethodInvokeException("method peer can not be NULL.");
		}
	}

	template<typename P1, typename P2, typename P3, typename P4, typename P5,
	typename P6, typename P7, typename P8, typename P9, typename P10,
	typename P11, typename P12, typename P13, typename P14>
	RetType operator()(P1 param1, P2 param2, P3 param3, P4 param4, P5 param5, P6 param6,
			P7 param7, P8 param8, P9 param9, P10 param10, P11 param11,
			P12 param12, P13 param13, P14 param14) {
		if (m_peer != NULL) {
			return (*m_peer).operator ()<P1,P2,P3,P4,P5,P6,P7,P8,P9,P10,P11,P12,P13,P14>(param1, param2, param3, param4, param5, param6,
					param7, param8, param9, param10, param11, param12, param13,
					param14);
		} else if (m_con != NULL) {
			if (m_arc == NULL) {
				throw MethodInvokeException(
						"you have to call setArchiveFactory for RequiredMethod.");
			}
			std::string sname = m_name;
			std::string outvalue;
			std::stringstream instr;

			opros::archive::oarchive *inV =
			m_arc->getOutputArchive(&instr);

			(*inV) << OPROS_SERIALIZATION_NVP(param1);
			(*inV) << OPROS_SERIALIZATION_NVP(param2);
			(*inV) << OPROS_SERIALIZATION_NVP(param3);
			(*inV) << OPROS_SERIALIZATION_NVP(param4);
			(*inV) << OPROS_SERIALIZATION_NVP(param5);
			(*inV) << OPROS_SERIALIZATION_NVP(param6);
			(*inV) << OPROS_SERIALIZATION_NVP(param7);
			(*inV) << OPROS_SERIALIZATION_NVP(param8);
			(*inV) << OPROS_SERIALIZATION_NVP(param9);
			(*inV) << OPROS_SERIALIZATION_NVP(param10);
			(*inV) << OPROS_SERIALIZATION_NVP(param11);
			(*inV) << OPROS_SERIALIZATION_NVP(param12);
			(*inV) << OPROS_SERIALIZATION_NVP(param13);
			(*inV) << OPROS_SERIALIZATION_NVP(param14);
			std::string invalue = instr.str();

			outvalue.reserve(1);
			if (m_con!=NULL) m_con->requestService(sname, invalue, outvalue);
			std::stringstream retstr(outvalue);

			opros::archive::iarchive *retV =
			m_arc->getInputArchive(&retstr);

			RetType resultData;

			(*retV) >> OPROS_SERIALIZATION_NVP(resultData);

			m_arc->release(retV);
			m_arc->release(inV);

			return resultData;

		} else {
			throw MethodInvokeException("method peer can not be NULL.");
		}
	}

	template<typename P1, typename P2, typename P3, typename P4, typename P5,
	typename P6, typename P7, typename P8, typename P9, typename P10,
	typename P11, typename P12, typename P13, typename P14,
	typename P15>
	RetType operator()(P1 param1, P2 param2, P3 param3, P4 param4, P5 param5, P6 param6,
			P7 param7, P8 param8, P9 param9, P10 param10, P11 param11,
			P12 param12, P13 param13, P14 param14, P15 param15) {
		if (m_peer != NULL) {
			return (*m_peer).operator ()<P1,P2,P3,P4,P5,P6,P7,P8,P9,P10,P11,P12,P13,P14,P15>(param1, param2, param3, param4, param5, param6,
					param7, param8, param9, param10, param11, param12, param13,
					param14, param15);
		} else if (m_con != NULL) {
			if (m_arc == NULL) {
				throw MethodInvokeException(
						"you have to call setArchiveFactory for RequiredMethod.");
			}
			std::string sname = m_name;
			std::string outvalue;
			std::stringstream instr;

			opros::archive::oarchive *inV =
			m_arc->getOutputArchive(&instr);

			(*inV) << OPROS_SERIALIZATION_NVP(param1);
			(*inV) << OPROS_SERIALIZATION_NVP(param2);
			(*inV) << OPROS_SERIALIZATION_NVP(param3);
			(*inV) << OPROS_SERIALIZATION_NVP(param4);
			(*inV) << OPROS_SERIALIZATION_NVP(param5);
			(*inV) << OPROS_SERIALIZATION_NVP(param6);
			(*inV) << OPROS_SERIALIZATION_NVP(param7);
			(*inV) << OPROS_SERIALIZATION_NVP(param8);
			(*inV) << OPROS_SERIALIZATION_NVP(param9);
			(*inV) << OPROS_SERIALIZATION_NVP(param10);
			(*inV) << OPROS_SERIALIZATION_NVP(param11);
			(*inV) << OPROS_SERIALIZATION_NVP(param12);
			(*inV) << OPROS_SERIALIZATION_NVP(param13);
			(*inV) << OPROS_SERIALIZATION_NVP(param14);
			(*inV) << OPROS_SERIALIZATION_NVP(param15);
			std::string invalue = instr.str();

			outvalue.reserve(1);
			if (m_con!=NULL) m_con->requestService(sname, invalue, outvalue);
			std::stringstream retstr(outvalue);

			opros::archive::iarchive *retV =
			m_arc->getInputArchive(&retstr);

			RetType resultData;

			(*retV) >> OPROS_SERIALIZATION_NVP(resultData);

			m_arc->release(retV);
			m_arc->release(inV);

			return resultData;

		} else {
			throw MethodInvokeException("method peer can not be NULL.");
		}
	}
};

//
//
// void required method

template<>
class RequiredMethod<void> : public RequiredMethodInterface {
protected:
	typedef ProvidedMethod<void> provided_method_type;

	ProvidedMethod<void> *m_peer;
	;
	ServicePortConnector *m_con;


	int m_arity;
	std::string m_returnType;


public:
	virtual ReturnType call(opros::archive::iarchive &in,
			opros::archive::oarchive &out) {
		if (m_peer != NULL)
			return m_peer->call(in, out);

		return OPROS_UNSUPPORTED_METHOD;
	}


	RequiredMethod(const std::string &name, int arity) :
		m_arity(arity),
		RequiredMethodInterface(name) {
		m_peer = NULL;
		m_con = NULL;
		m_returnType ="void";
	}

	virtual std::string &getReturnType()
	{
		return m_returnType;
	}

	virtual int getArity()
	{
		return m_arity;
	}

	virtual ~RequiredMethod() {

	}

	virtual ReturnType Disconnect() {
		m_peer = NULL;
		m_con = NULL;

		return OPROS_SUCCESS;
	}

	virtual ReturnType Connect(Method *peer) {
		m_peer = reinterpret_cast<provided_method_type *> (peer);
		return OPROS_SUCCESS;
	}

	virtual ReturnType Connect(ServicePortConnector *peer) {
		m_peer = NULL;
		m_con = peer;
		return OPROS_SUCCESS;
	}

	void operator()() {
		if (m_peer != NULL) {
			return (*m_peer)();
		} else if (m_con != NULL) {
			if (m_arc == NULL) {
				throw MethodInvokeException(
						"you have to call setArchiveFactory for RequiredMethod.");
			}
			
			std::string sname = m_name;

			std::string outvalue;
			std::stringstream instr;
			std::string void_str("v");

			opros::archive::oarchive *inV =
			m_arc->getOutputArchive(&instr);
			
			(*inV) << OPROS_SERIALIZATION_NVP(void_str);
			std::string invalue = instr.str();

			outvalue.reserve(1);
			if (m_con!=NULL) m_con->requestService(sname, invalue, outvalue);

			m_arc->release(inV);

		} else {
			throw MethodInvokeException("method peer can not be NULL.");
		}
	}

	template<typename P1>
	void operator()(P1 param1) {
		if (m_peer != NULL) {
			return (*m_peer).operator ()<P1>(param1);
		} else if (m_con != NULL) {
			if (m_arc == NULL) {
				throw MethodInvokeException(
						"you have to call setArchiveFactory for RequiredMethod.");
			}
			std::string sname = m_name;
			std::string outvalue;
			std::stringstream instr;

			opros::archive::oarchive *inV =
			m_arc->getOutputArchive(&instr);

			(*inV) << OPROS_SERIALIZATION_NVP(param1);
			std::string invalue = instr.str();

			outvalue.reserve(1);
			if (m_con!=NULL) m_con->requestService(sname, invalue, outvalue);
			m_arc->release(inV);

		} else {
			throw MethodInvokeException("method peer can not be NULL.");
		}

	}

	template<typename P1, typename P2>
	void operator()(P1 param1, P2 param2) {
		if (m_peer != NULL) {
			return (*m_peer).operator ()<P1,P2>(param1, param2);
		} else if (m_con != NULL) {
			if (m_arc == NULL) {
				throw MethodInvokeException(
						"you have to call setArchiveFactory for RequiredMethod.");
			}
			std::string sname = m_name;
			std::string outvalue;
			std::stringstream instr;

			opros::archive::oarchive *inV =
			m_arc->getOutputArchive(&instr);

			(*inV) << OPROS_SERIALIZATION_NVP(param1);
			(*inV) << OPROS_SERIALIZATION_NVP(param2);
			std::string invalue = instr.str();

			outvalue.reserve(1);
			if (m_con!=NULL) m_con->requestService(sname, invalue, outvalue);
			m_arc->release(inV);

		} else {
			throw MethodInvokeException("method peer can not be NULL.");
		}
	}

	template<typename P1, typename P2, typename P3>
	void operator()(P1 param1, P2 param2, P3 param3) {
		if (m_peer != NULL) {
			return (*m_peer).operator ()<P1,P2,P3>(param1, param2, param3);
		} else if (m_con != NULL) {
			if (m_arc == NULL) {
				throw MethodInvokeException(
						"you have to call setArchiveFactory for RequiredMethod.");
			}
			std::string sname = m_name;
			std::string outvalue;
			std::stringstream instr;

			opros::archive::oarchive *inV =
			m_arc->getOutputArchive(&instr);

			(*inV) << OPROS_SERIALIZATION_NVP(param1);
			(*inV) << OPROS_SERIALIZATION_NVP(param2);
			(*inV) << OPROS_SERIALIZATION_NVP(param3);
			std::string invalue = instr.str();

			outvalue.reserve(1);
			if (m_con!=NULL) m_con->requestService(sname, invalue, outvalue);

			m_arc->release(inV);

		} else {
			throw MethodInvokeException("method peer can not be NULL.");
		}
	}

	template<typename P1, typename P2, typename P3, typename P4>
	void operator()(P1 param1, P2 param2, P3 param3, P4 param4) {
		if (m_peer != NULL) {
			return (*m_peer).operator ()<P1,P2,P3,P4>(param1, param2, param3, param4);
		} else if (m_con != NULL) {
			if (m_arc == NULL) {
				throw MethodInvokeException(
						"you have to call setArchiveFactory for RequiredMethod.");
			}
			std::string sname = m_name;
			std::string outvalue;
			std::stringstream instr;

			opros::archive::oarchive *inV =
			m_arc->getOutputArchive(&instr);

			(*inV) << OPROS_SERIALIZATION_NVP(param1);
			(*inV) << OPROS_SERIALIZATION_NVP(param2);
			(*inV) << OPROS_SERIALIZATION_NVP(param3);
			(*inV) << OPROS_SERIALIZATION_NVP(param4);
			std::string invalue = instr.str();

			outvalue.reserve(1);
			if (m_con!=NULL) m_con->requestService(sname, invalue, outvalue);

			m_arc->release(inV);

		} else {
			throw MethodInvokeException("method peer can not be NULL.");
		}
	}

	template<typename P1, typename P2, typename P3, typename P4, typename P5>
	void operator()(P1 param1, P2 param2, P3 param3, P4 param4, P5 param5) {
		if (m_peer != NULL) {
			return (*m_peer).operator ()<P1,P2,P3,P4,P5>(param1, param2, param3, param4, param5);
		} else if (m_con != NULL) {
			if (m_arc == NULL) {
				throw MethodInvokeException(
						"you have to call setArchiveFactory for RequiredMethod.");
			}
			std::string sname = m_name;
			std::string outvalue;
			std::stringstream instr;

			opros::archive::oarchive *inV =
			m_arc->getOutputArchive(&instr);

			(*inV) << OPROS_SERIALIZATION_NVP(param1);
			(*inV) << OPROS_SERIALIZATION_NVP(param2);
			(*inV) << OPROS_SERIALIZATION_NVP(param3);
			(*inV) << OPROS_SERIALIZATION_NVP(param4);
			(*inV) << OPROS_SERIALIZATION_NVP(param5);
			std::string invalue = instr.str();

			outvalue.reserve(1);
			if (m_con!=NULL) m_con->requestService(sname, invalue, outvalue);

			m_arc->release(inV);

		} else {
			throw MethodInvokeException("method peer can not be NULL.");
		}
	}

	template<typename P1, typename P2, typename P3, typename P4, typename P5,
	typename P6>
	void operator()(P1 param1, P2 param2, P3 param3, P4 param4, P5 param5, P6 param6) {
		if (m_peer != NULL) {
			return (*m_peer).operator ()<P1,P2,P3,P4,P5,P6>(param1, param2, param3, param4, param5, param6);
		} else if (m_con != NULL) {
			if (m_arc == NULL) {
				throw MethodInvokeException(
						"you have to call setArchiveFactory for RequiredMethod.");
			}
			std::string sname = m_name;
			std::string outvalue;
			std::stringstream instr;

			opros::archive::oarchive *inV =
			m_arc->getOutputArchive(&instr);

			(*inV) << OPROS_SERIALIZATION_NVP(param1);
			(*inV) << OPROS_SERIALIZATION_NVP(param2);
			(*inV) << OPROS_SERIALIZATION_NVP(param3);
			(*inV) << OPROS_SERIALIZATION_NVP(param4);
			(*inV) << OPROS_SERIALIZATION_NVP(param5);
			(*inV) << OPROS_SERIALIZATION_NVP(param6);
			std::string invalue = instr.str();

			outvalue.reserve(1);
			if (m_con!=NULL) m_con->requestService(sname, invalue, outvalue);

			m_arc->release(inV);

		} else {
			throw MethodInvokeException("method peer can not be NULL.");
		}
	}

	template<typename P1, typename P2, typename P3, typename P4, typename P5,
	typename P6, typename P7>
	void operator()(P1 param1, P2 param2, P3 param3, P4 param4, P5 param5, P6 param6,
			P7 param7) {
		if (m_peer != NULL) {
			return (*m_peer).operator ()<P1,P2,P3,P4,P5,P6,P7>(param1, param2, param3, param4, param5, param6,
					param7);
		} else if (m_con != NULL) {
			if (m_arc == NULL) {
				throw MethodInvokeException(
						"you have to call setArchiveFactory for RequiredMethod.");
			}
			std::string sname = m_name;
			std::string outvalue;
			std::stringstream instr;

			opros::archive::oarchive *inV =
			m_arc->getOutputArchive(&instr);

			(*inV) << OPROS_SERIALIZATION_NVP(param1);
			(*inV) << OPROS_SERIALIZATION_NVP(param2);
			(*inV) << OPROS_SERIALIZATION_NVP(param3);
			(*inV) << OPROS_SERIALIZATION_NVP(param4);
			(*inV) << OPROS_SERIALIZATION_NVP(param5);
			(*inV) << OPROS_SERIALIZATION_NVP(param6);
			(*inV) << OPROS_SERIALIZATION_NVP(param7);
			std::string invalue = instr.str();

			outvalue.reserve(1);
			if (m_con!=NULL) m_con->requestService(sname, invalue, outvalue);

			m_arc->release(inV);

		} else {
			throw MethodInvokeException("method peer can not be NULL.");
		}
	}

	template<typename P1, typename P2, typename P3, typename P4, typename P5,
	typename P6, typename P7, typename P8>
	void operator()(P1 param1, P2 param2, P3 param3, P4 param4, P5 param5, P6 param6,
			P7 param7, P8 param8) {
		if (m_peer != NULL) {
			return (*m_peer).operator ()<P1,P2,P3,P4,P5,P6,P7,P8>(param1, param2, param3, param4, param5, param6,
					param7, param8);
		} else if (m_con != NULL) {
			if (m_arc == NULL) {
				throw MethodInvokeException(
						"you have to call setArchiveFactory for RequiredMethod.");
			}
			std::string sname = m_name;
			std::string outvalue;
			std::stringstream instr;

			opros::archive::oarchive *inV =
			m_arc->getOutputArchive(&instr);

			(*inV) << OPROS_SERIALIZATION_NVP(param1);
			(*inV) << OPROS_SERIALIZATION_NVP(param2);
			(*inV) << OPROS_SERIALIZATION_NVP(param3);
			(*inV) << OPROS_SERIALIZATION_NVP(param4);
			(*inV) << OPROS_SERIALIZATION_NVP(param5);
			(*inV) << OPROS_SERIALIZATION_NVP(param6);
			(*inV) << OPROS_SERIALIZATION_NVP(param7);
			(*inV) << OPROS_SERIALIZATION_NVP(param8);
			std::string invalue = instr.str();

			outvalue.reserve(1);
			if (m_con!=NULL) m_con->requestService(sname, invalue, outvalue);

			m_arc->release(inV);

		} else {
			throw MethodInvokeException("method peer can not be NULL.");
		}
	}

	template<typename P1, typename P2, typename P3, typename P4, typename P5,
	typename P6, typename P7, typename P8, typename P9>
	void operator()(P1 param1, P2 param2, P3 param3, P4 param4, P5 param5, P6 param6,
			P7 param7, P8 param8, P9 param9) {
		if (m_peer != NULL) {
			return (*m_peer).operator ()<P1,P2,P3,P4,P5,P6,P7,P8,P9>(param1, param2, param3, param4, param5, param6,
					param7, param8, param9);
		} else if (m_con != NULL) {
			if (m_arc == NULL) {
				throw MethodInvokeException(
						"you have to call setArchiveFactory for RequiredMethod.");
			}
			std::string sname = m_name;
			std::string outvalue;
			std::stringstream instr;

			opros::archive::oarchive *inV =
			m_arc->getOutputArchive(&instr);

			(*inV) << OPROS_SERIALIZATION_NVP(param1);
			(*inV) << OPROS_SERIALIZATION_NVP(param2);
			(*inV) << OPROS_SERIALIZATION_NVP(param3);
			(*inV) << OPROS_SERIALIZATION_NVP(param4);
			(*inV) << OPROS_SERIALIZATION_NVP(param5);
			(*inV) << OPROS_SERIALIZATION_NVP(param6);
			(*inV) << OPROS_SERIALIZATION_NVP(param7);
			(*inV) << OPROS_SERIALIZATION_NVP(param8);
			(*inV) << OPROS_SERIALIZATION_NVP(param9);
			std::string invalue = instr.str();

			outvalue.reserve(1);
			if (m_con!=NULL) m_con->requestService(sname, invalue, outvalue);

			m_arc->release(inV);

		} else {
			throw MethodInvokeException("method peer can not be NULL.");
		}
	}

	template<typename P1, typename P2, typename P3, typename P4, typename P5,
	typename P6, typename P7, typename P8, typename P9, typename P10>
	void operator()(P1 param1, P2 param2, P3 param3, P4 param4, P5 param5, P6 param6,
			P7 param7, P8 param8, P9 param9, P10 param10) {
		if (m_peer != NULL) {
			return (*m_peer).operator ()<P1,P2,P3,P4,P5,P6,P7,P8,P9,P10>(param1, param2, param3, param4, param5, param6,
					param7, param8, param9, param10);
		} else if (m_con != NULL) {
			if (m_arc == NULL) {
				throw MethodInvokeException(
						"you have to call setArchiveFactory for RequiredMethod.");
			}
			std::string sname = m_name;
			std::string outvalue;
			std::stringstream instr;

			opros::archive::oarchive *inV =
			m_arc->getOutputArchive(&instr);

			(*inV) << OPROS_SERIALIZATION_NVP(param1);
			(*inV) << OPROS_SERIALIZATION_NVP(param2);
			(*inV) << OPROS_SERIALIZATION_NVP(param3);
			(*inV) << OPROS_SERIALIZATION_NVP(param4);
			(*inV) << OPROS_SERIALIZATION_NVP(param5);
			(*inV) << OPROS_SERIALIZATION_NVP(param6);
			(*inV) << OPROS_SERIALIZATION_NVP(param7);
			(*inV) << OPROS_SERIALIZATION_NVP(param8);
			(*inV) << OPROS_SERIALIZATION_NVP(param9);
			(*inV) << OPROS_SERIALIZATION_NVP(param10);
			std::string invalue = instr.str();

			outvalue.reserve(1);
			if (m_con!=NULL) m_con->requestService(sname, invalue, outvalue);

			m_arc->release(inV);

		} else {
			throw MethodInvokeException("method peer can not be NULL.");
		}
	}

	template<typename P1, typename P2, typename P3, typename P4, typename P5,
	typename P6, typename P7, typename P8, typename P9, typename P10,
	typename P11>
	void operator()(P1 param1, P2 param2, P3 param3, P4 param4, P5 param5, P6 param6,
			P7 param7, P8 param8, P9 param9, P10 param10, P11 param11) {
		if (m_peer != NULL) {
			return (*m_peer).operator ()<P1,P2,P3,P4,P5,P6,P7,P8,P9,P10,P11>(param1, param2, param3, param4, param5, param6,
					param7, param8, param9, param10, param11);
		} else if (m_con != NULL) {
			if (m_arc == NULL) {
				throw MethodInvokeException(
						"you have to call setArchiveFactory for RequiredMethod.");
			}
			std::string sname = m_name;
			std::string outvalue;
			std::stringstream instr;

			opros::archive::oarchive *inV =
			m_arc->getOutputArchive(&instr);

			(*inV) << OPROS_SERIALIZATION_NVP(param1);
			(*inV) << OPROS_SERIALIZATION_NVP(param2);
			(*inV) << OPROS_SERIALIZATION_NVP(param3);
			(*inV) << OPROS_SERIALIZATION_NVP(param4);
			(*inV) << OPROS_SERIALIZATION_NVP(param5);
			(*inV) << OPROS_SERIALIZATION_NVP(param6);
			(*inV) << OPROS_SERIALIZATION_NVP(param7);
			(*inV) << OPROS_SERIALIZATION_NVP(param8);
			(*inV) << OPROS_SERIALIZATION_NVP(param9);
			(*inV) << OPROS_SERIALIZATION_NVP(param10);
			(*inV) << OPROS_SERIALIZATION_NVP(param11);
			std::string invalue = instr.str();

			outvalue.reserve(1);
			if (m_con!=NULL) m_con->requestService(sname, invalue, outvalue);

			m_arc->release(inV);

		} else {
			throw MethodInvokeException("method peer can not be NULL.");
		}
	}

	template<typename P1, typename P2, typename P3, typename P4, typename P5,
	typename P6, typename P7, typename P8, typename P9, typename P10,
	typename P11, typename P12>
	void operator()(P1 param1, P2 param2, P3 param3, P4 param4, P5 param5, P6 param6,
			P7 param7, P8 param8, P9 param9, P10 param10, P11 param11,
			P12 param12) {
		if (m_peer != NULL) {
			return (*m_peer).operator ()<P1,P2,P3,P4,P5,P6,P7,P8,P9,P10,P11,P12>(param1, param2, param3, param4, param5, param6,
					param7, param8, param9, param10, param11, param12);
		} else if (m_con != NULL) {
			if (m_arc == NULL) {
				throw MethodInvokeException(
						"you have to call setArchiveFactory for RequiredMethod.");
			}
			std::string sname = m_name;
			std::string outvalue;
			std::stringstream instr;

			opros::archive::oarchive *inV =
			m_arc->getOutputArchive(&instr);

			(*inV) << OPROS_SERIALIZATION_NVP(param1);
			(*inV) << OPROS_SERIALIZATION_NVP(param2);
			(*inV) << OPROS_SERIALIZATION_NVP(param3);
			(*inV) << OPROS_SERIALIZATION_NVP(param4);
			(*inV) << OPROS_SERIALIZATION_NVP(param5);
			(*inV) << OPROS_SERIALIZATION_NVP(param6);
			(*inV) << OPROS_SERIALIZATION_NVP(param7);
			(*inV) << OPROS_SERIALIZATION_NVP(param8);
			(*inV) << OPROS_SERIALIZATION_NVP(param9);
			(*inV) << OPROS_SERIALIZATION_NVP(param10);
			(*inV) << OPROS_SERIALIZATION_NVP(param11);
			(*inV) << OPROS_SERIALIZATION_NVP(param12);
			std::string invalue = instr.str();

			outvalue.reserve(1);
			if (m_con!=NULL) m_con->requestService(sname, invalue, outvalue);

			m_arc->release(inV);

		} else {
			throw MethodInvokeException("method peer can not be NULL.");
		}
	}

	template<typename P1, typename P2, typename P3, typename P4, typename P5,
	typename P6, typename P7, typename P8, typename P9, typename P10,
	typename P11, typename P12, typename P13>
	void operator()(P1 param1, P2 param2, P3 param3, P4 param4, P5 param5, P6 param6,
			P7 param7, P8 param8, P9 param9, P10 param10, P11 param11,
			P12 param12, P13 param13) {
		if (m_peer != NULL) {
			return (*m_peer).operator ()<P1,P2,P3,P4,P5,P6,P7,P8,P9,P10,P11,P12,P13>(param1, param2, param3, param4, param5, param6,
					param7, param8, param9, param10, param11, param12, param13);
		} else if (m_con != NULL) {
			if (m_arc == NULL) {
				throw MethodInvokeException(
						"you have to call setArchiveFactory for RequiredMethod.");
			}
			std::string sname = m_name;
			std::string outvalue;
			std::stringstream instr;

			opros::archive::oarchive *inV =
			m_arc->getOutputArchive(&instr);

			(*inV) << OPROS_SERIALIZATION_NVP(param1);
			(*inV) << OPROS_SERIALIZATION_NVP(param2);
			(*inV) << OPROS_SERIALIZATION_NVP(param3);
			(*inV) << OPROS_SERIALIZATION_NVP(param4);
			(*inV) << OPROS_SERIALIZATION_NVP(param5);
			(*inV) << OPROS_SERIALIZATION_NVP(param6);
			(*inV) << OPROS_SERIALIZATION_NVP(param7);
			(*inV) << OPROS_SERIALIZATION_NVP(param8);
			(*inV) << OPROS_SERIALIZATION_NVP(param9);
			(*inV) << OPROS_SERIALIZATION_NVP(param10);
			(*inV) << OPROS_SERIALIZATION_NVP(param11);
			(*inV) << OPROS_SERIALIZATION_NVP(param12);
			(*inV) << OPROS_SERIALIZATION_NVP(param13);
			std::string invalue = instr.str();

			outvalue.reserve(1);
			if (m_con!=NULL) m_con->requestService(sname, invalue, outvalue);

			m_arc->release(inV);

		} else {
			throw MethodInvokeException("method peer can not be NULL.");
		}
	}

	template<typename P1, typename P2, typename P3, typename P4, typename P5,
	typename P6, typename P7, typename P8, typename P9, typename P10,
	typename P11, typename P12, typename P13, typename P14>
	void operator()(P1 param1, P2 param2, P3 param3, P4 param4, P5 param5, P6 param6,
			P7 param7, P8 param8, P9 param9, P10 param10, P11 param11,
			P12 param12, P13 param13, P14 param14) {
		if (m_peer != NULL) {
			return (*m_peer).operator ()<P1,P2,P3,P4,P5,P6,P7,P8,P9,P10,P11,P12,P13,P14>(param1, param2, param3, param4, param5, param6,
					param7, param8, param9, param10, param11, param12, param13,
					param14);
		} else if (m_con != NULL) {
			if (m_arc == NULL) {
				throw MethodInvokeException(
						"you have to call setArchiveFactory for RequiredMethod.");
			}
			std::string sname = m_name;
			std::string outvalue;
			std::stringstream instr;

			opros::archive::oarchive *inV =
			m_arc->getOutputArchive(&instr);

			(*inV) << OPROS_SERIALIZATION_NVP(param1);
			(*inV) << OPROS_SERIALIZATION_NVP(param2);
			(*inV) << OPROS_SERIALIZATION_NVP(param3);
			(*inV) << OPROS_SERIALIZATION_NVP(param4);
			(*inV) << OPROS_SERIALIZATION_NVP(param5);
			(*inV) << OPROS_SERIALIZATION_NVP(param6);
			(*inV) << OPROS_SERIALIZATION_NVP(param7);
			(*inV) << OPROS_SERIALIZATION_NVP(param8);
			(*inV) << OPROS_SERIALIZATION_NVP(param9);
			(*inV) << OPROS_SERIALIZATION_NVP(param10);
			(*inV) << OPROS_SERIALIZATION_NVP(param11);
			(*inV) << OPROS_SERIALIZATION_NVP(param12);
			(*inV) << OPROS_SERIALIZATION_NVP(param13);
			(*inV) << OPROS_SERIALIZATION_NVP(param14);
			std::string invalue = instr.str();

			outvalue.reserve(1);
			if (m_con!=NULL) m_con->requestService(sname, invalue, outvalue);

			m_arc->release(inV);

		} else {
			throw MethodInvokeException("method peer can not be NULL.");
		}
	}

	template<typename P1, typename P2, typename P3, typename P4, typename P5,
	typename P6, typename P7, typename P8, typename P9, typename P10,
	typename P11, typename P12, typename P13, typename P14,
	typename P15>
	void operator()(P1 param1, P2 param2, P3 param3, P4 param4, P5 param5, P6 param6,
			P7 param7, P8 param8, P9 param9, P10 param10, P11 param11,
			P12 param12, P13 param13, P14 param14, P15 param15) {
		if (m_peer != NULL) {
			return (*m_peer).operator ()<P1,P2,P3,P4,P5,P6,P7,P8,P9,P10,P11,P12,P13,P14,P15>(param1, param2, param3, param4, param5, param6,
					param7, param8, param9, param10, param11, param12, param13,
					param14, param15);
		} else if (m_con != NULL) {
			if (m_arc == NULL) {
				throw MethodInvokeException(
						"you have to call setArchiveFactory for RequiredMethod.");
			}
			std::string sname = m_name;
			std::string outvalue;
			std::stringstream instr;

			opros::archive::oarchive *inV =
			m_arc->getOutputArchive(&instr);

			(*inV) << OPROS_SERIALIZATION_NVP(param1);
			(*inV) << OPROS_SERIALIZATION_NVP(param2);
			(*inV) << OPROS_SERIALIZATION_NVP(param3);
			(*inV) << OPROS_SERIALIZATION_NVP(param4);
			(*inV) << OPROS_SERIALIZATION_NVP(param5);
			(*inV) << OPROS_SERIALIZATION_NVP(param6);
			(*inV) << OPROS_SERIALIZATION_NVP(param7);
			(*inV) << OPROS_SERIALIZATION_NVP(param8);
			(*inV) << OPROS_SERIALIZATION_NVP(param9);
			(*inV) << OPROS_SERIALIZATION_NVP(param10);
			(*inV) << OPROS_SERIALIZATION_NVP(param11);
			(*inV) << OPROS_SERIALIZATION_NVP(param12);
			(*inV) << OPROS_SERIALIZATION_NVP(param13);
			(*inV) << OPROS_SERIALIZATION_NVP(param14);
			(*inV) << OPROS_SERIALIZATION_NVP(param15);
			std::string invalue = instr.str();

			outvalue.reserve(1);
			if (m_con!=NULL) m_con->requestService(sname, invalue, outvalue);

			m_arc->release(inV);

		} else {
			throw MethodInvokeException("method peer can not be NULL.");
		}
	}
};

//
//
//  MakeMethod
//
template<typename R, typename C>
Method* makeRequiredMethod(R(C::* function)(), char *fname) {
	RequiredMethod<R> *r = new RequiredMethod<R> (fname,0);

	Method *results = reinterpret_cast<Method *> (r);

	return results;
}

template<typename R, typename C, typename P1>
Method* makeRequiredMethod(R(C::* function)(P1), char *fname) {
	RequiredMethod<R> *r = new RequiredMethod<R> (fname,1);

	Method *results = reinterpret_cast<Method *> (r);

	return results;
}

template<typename R, typename C, typename P1, typename P2>
Method* makeRequiredMethod(R(C::* function)(P1, P2), char *fname) {
	RequiredMethod<R> *r = new RequiredMethod<R> (fname,2);

	Method *results = reinterpret_cast<Method *> (r);

	return results;
}

template<typename R, typename C, typename P1, typename P2, typename P3>
Method* makeRequiredMethod(R(C::* function)(P1, P2, P3), char *fname) {
	RequiredMethod<R> *r = new RequiredMethod<R> (fname,3);

	Method *results = reinterpret_cast<Method *> (r);

	return results;
}

template<typename R, typename C, typename P1, typename P2, typename P3,
		typename P4>
Method* makeRequiredMethod(R(C::* function)(P1, P2, P3, P4), char *fname) {
	RequiredMethod<R> *r = new RequiredMethod<R> (fname,4);

	Method *results = reinterpret_cast<Method *> (r);

	return results;
}

template<typename R, typename C, typename P1, typename P2, typename P3,
		typename P4, typename P5>
Method* makeRequiredMethod(R(C::* function)(P1, P2, P3, P4, P5), char *fname) {
	RequiredMethod<R> *r = new RequiredMethod<R> (fname,5);

	Method *results = reinterpret_cast<Method *> (r);

	return results;
}

template<typename R, typename C, typename P1, typename P2, typename P3,
		typename P4, typename P5, typename P6>
Method* makeRequiredMethod(R(C::* function)(P1, P2, P3, P4, P5, P6),
		char *fname) {
	RequiredMethod<R> *r = new RequiredMethod<R> (fname,6);

	Method *results = reinterpret_cast<Method *> (r);

	return results;
}

template<typename R, typename C, typename P1, typename P2, typename P3,
		typename P4, typename P5, typename P6, typename P7>
Method* makeRequiredMethod(R(C::* function)(P1, P2, P3, P4, P5, P6, P7),
		char *fname) {
	RequiredMethod<R> *r = new RequiredMethod<R> (fname,7);

	Method *results = reinterpret_cast<Method *> (r);

	return results;
}

template<typename R, typename C, typename P1, typename P2, typename P3,
		typename P4, typename P5, typename P6, typename P7, typename P8>
Method* makeRequiredMethod(R(C::* function)(P1, P2, P3, P4, P5, P6, P7, P8),
		char *fname) {
	RequiredMethod<R> *r = new RequiredMethod<R> (fname,8);

	Method *results = reinterpret_cast<Method *> (r);

	return results;
}

template<typename R, typename C, typename P1, typename P2, typename P3,
		typename P4, typename P5, typename P6, typename P7, typename P8,
		typename P9>
Method* makeRequiredMethod(
		R(C::* function)(P1, P2, P3, P4, P5, P6, P7, P8, P9), char *fname) {
	RequiredMethod<R> *r = new RequiredMethod<R> (fname,9);

	Method *results = reinterpret_cast<Method *> (r);

	return results;
}

template<typename R, typename C, typename P1, typename P2, typename P3,
		typename P4, typename P5, typename P6, typename P7, typename P8,
		typename P9, typename P10>
Method* makeRequiredMethod(R(C::* function)(P1, P2, P3, P4, P5, P6, P7, P8, P9,
		P10), char *fname) {
	RequiredMethod<R> *r = new RequiredMethod<R> (fname,10);

	Method *results = reinterpret_cast<Method *> (r);

	return results;
}

template<typename R, typename C, typename P1, typename P2, typename P3,
		typename P4, typename P5, typename P6, typename P7, typename P8,
		typename P9, typename P10, typename P11>
Method* makeRequiredMethod(R(C::* function)(P1, P2, P3, P4, P5, P6, P7, P8, P9,
		P10, P11), char *fname) {
	RequiredMethod<R> *r = new RequiredMethod<R> (fname,11);

	Method *results = reinterpret_cast<Method *> (r);

	return results;
}

template<typename R, typename C, typename P1, typename P2, typename P3,
		typename P4, typename P5, typename P6, typename P7, typename P8,
		typename P9, typename P10, typename P11, typename P12>
Method* makeRequiredMethod(R(C::* function)(P1, P2, P3, P4, P5, P6, P7, P8, P9,
		P10, P11, P12), char *fname) {
	RequiredMethod<R> *r = new RequiredMethod<R> (fname,12);

	Method *results = reinterpret_cast<Method *> (r);

	return results;
}

template<typename R, typename C, typename P1, typename P2, typename P3,
		typename P4, typename P5, typename P6, typename P7, typename P8,
		typename P9, typename P10, typename P11, typename P12, typename P13>
Method* makeRequiredMethod(R(C::* function)(P1, P2, P3, P4, P5, P6, P7, P8, P9,
		P10, P11, P12, P13), char *fname) {
	RequiredMethod<R> *r = new RequiredMethod<R> (fname,13);

	Method *results = reinterpret_cast<Method *> (r);

	return results;
}

template<typename R, typename C, typename P1, typename P2, typename P3,
		typename P4, typename P5, typename P6, typename P7, typename P8,
		typename P9, typename P10, typename P11, typename P12, typename P13,
		typename P14>
Method* makeRequiredMethod(R(C::* function)(P1, P2, P3, P4, P5, P6, P7, P8, P9,
		P10, P11, P12, P13, P14), char *fname) {
	RequiredMethod<R> *r = new RequiredMethod<R> (fname,14);

	Method *results = reinterpret_cast<Method *> (r);

	return results;
}

template<typename R, typename C, typename P1, typename P2, typename P3,
		typename P4, typename P5, typename P6, typename P7, typename P8,
		typename P9, typename P10, typename P11, typename P12, typename P13,
		typename P14, typename P15>
Method* makeRequiredMethod(R(C::* function)(P1, P2, P3, P4, P5, P6, P7, P8, P9,
		P10, P11, P12, P13, P14, P15), char *fname) {
	RequiredMethod<R> *r = new RequiredMethod<R> (fname,15);

	Method *results = reinterpret_cast<Method *> (r);

	return results;
}

#endif  //_REQUIREDMETHOD_H
