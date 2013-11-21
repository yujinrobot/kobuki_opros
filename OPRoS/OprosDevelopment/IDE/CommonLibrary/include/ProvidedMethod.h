/*
 *  OPRoS Component Engine (OCE)
 *  Copyright (c) 2008 ETRI. http://www.etri.re.kr.
 *  Distributed under the OPRoS License, Version 1.0.
 *
 *  @Created : 2009. 2. 18
 *  @Modified: 2011. 3. 18 (arity and returnType info are added, use opros archive)
 *  @Author  : sby (sby@etri.re.kr)
 *
 *  @File    : ProvidedMethod.h
 *
 *
 */

#ifndef PROVIDEDMETHOD_H_
#define PROVIDEDMETHOD_H_

#include <Method.h>
#include <ArgumentNumberException.h>

class GenericClass {
};
class GenericClass;

template<typename RetType>
class ProvidedMethod: public Method {
protected:
	typedef RetType (GenericClass::*GenericMemberFunc)();
	typedef RetType (*functionPtrFunc)();

	functionPtrFunc functionPtr;
	GenericMemberFunc memberFunction;

	GenericClass *mmPtr;

	const int arity;

	std::string m_returnType;


public:	

	virtual std::string &getReturnType()
	{
		return m_returnType;
	}


	virtual int getArity()
	{
		return arity;
	}

	ProvidedMethod(int argNum) :
		arity(argNum) {		
		RetType *p=0;
		m_returnType = getTypeName(p);
	}

	virtual ReturnType call(opros::archive::iarchive &in,
			opros::archive::oarchive &out) = 0;

	RetType operator()() {
		if (arity != 0) {
			throw ArgumentNumberException(__LINE__, arity);
		}
		if (mmPtr == NULL) {
			if (functionPtr != NULL)
				return (*functionPtr)();
		}

		return (mmPtr ->* memberFunction)();
	}

	template<typename P1>
	RetType operator()(P1 param1) {
		typedef RetType (GenericClass::*GenericMemberFuncP1)(P1);
		typedef RetType (*funcType)(P1);

		if (arity != 1) {
			throw ArgumentNumberException(__LINE__, arity);
		}

		if (mmPtr == NULL) {
			if (functionPtr != NULL) {
				funcType p1func = reinterpret_cast<funcType> (functionPtr);

				return (*p1func)(param1);
			}

		}

		GenericMemberFuncP1 paFunction;

		paFunction = reinterpret_cast<GenericMemberFuncP1> (memberFunction);

		return (mmPtr ->* paFunction)(param1);
	}

	template<typename P1, typename P2>
	RetType operator()(P1 param1, P2 param2) {
		typedef RetType (GenericClass::*GenericMemberFuncP2)(P1, P2);
		typedef RetType (*funcType)(P1, P2);
		if (arity != 2) {
			throw ArgumentNumberException(__LINE__, arity);
		}

		if (mmPtr == NULL) {
			if (functionPtr != NULL) {
				funcType p1func = reinterpret_cast<funcType> (functionPtr);

				return (*p1func)(param1, param2);
			}

		}

		GenericMemberFuncP2 paFunction;

		paFunction = reinterpret_cast< GenericMemberFuncP2 > (memberFunction);
		
		return (mmPtr ->* paFunction)(param1, param2);
	}

	template<typename P1, typename P2, typename P3>
	RetType operator()(P1 param1, P2 param2, P3 param3) {
		typedef RetType (GenericClass::*GenericMemberFuncP3)(P1, P2, P3);
		typedef RetType (*funcType)(P1, P2, P3);
		if (arity != 3) {
			throw ArgumentNumberException(__LINE__, arity);
		}

		if (mmPtr == NULL) {
			if (functionPtr != NULL) {
				funcType p1func = reinterpret_cast<funcType> (functionPtr);

				return (*p1func)(param1, param2, param3);
			}

		}

		GenericMemberFuncP3 paFunction;

		paFunction = reinterpret_cast<GenericMemberFuncP3> (memberFunction);

		return (mmPtr ->* paFunction)(param1, param2, param3);
	}

	template<typename P1, typename P2, typename P3, typename P4>
	RetType operator()(P1 param1, P2 param2, P3 param3, P4 param4) {
		typedef RetType (GenericClass::*GenericMemberFuncP4)(P1, P2, P3, P4);
		typedef RetType (*funcType)(P1, P2, P3, P4);
		if (arity != 4) {
			throw ArgumentNumberException(__LINE__, arity);
		}

		if (mmPtr == NULL) {
			if (functionPtr != NULL) {
				funcType p1func = reinterpret_cast<funcType> (functionPtr);

				return (*p1func)(param1, param2, param3, param4);
			}
		}

		GenericMemberFuncP4 paFunction;

		paFunction = reinterpret_cast<GenericMemberFuncP4> (memberFunction);

		return (mmPtr ->* paFunction)(param1, param2, param3, param4);
	}

	template<typename P1, typename P2, typename P3, typename P4, typename P5>
	RetType operator()(P1 param1, P2 param2, P3 param3, P4 param4, P5 param5) {
		typedef RetType
				(GenericClass::*GenericMemberFuncP5)(P1, P2, P3, P4, P5);
		typedef RetType (*funcType)(P1, P2, P3, P4, P5);
		if (arity != 5) {
			throw ArgumentNumberException(__LINE__, arity);
		}

		if (mmPtr == NULL) {
			if (functionPtr != NULL) {
				funcType p1func = reinterpret_cast<funcType> (functionPtr);

				return (*p1func)(param1, param2, param3, param4, param5);
			}
		}

		GenericMemberFuncP5 paFunction;

		paFunction = reinterpret_cast<GenericMemberFuncP5> (memberFunction);

		return (mmPtr ->* paFunction)(param1, param2, param3, param4, param5);
	}

	template<typename P1, typename P2, typename P3, typename P4, typename P5,
			typename P6>
	RetType operator()(P1 param1, P2 param2, P3 param3, P4 param4, P5 param5, P6 param6) {
		typedef RetType (GenericClass::*GenericMemberFuncP6)(P1, P2, P3, P4,
				P5, P6);
		typedef RetType (*funcType)(P1, P2, P3, P4, P5, P6);
		if (arity != 6) {
			throw ArgumentNumberException(__LINE__, arity);
		}

		if (mmPtr == NULL) {
			if (functionPtr != NULL) {
				funcType p1func = reinterpret_cast<funcType> (functionPtr);

				return (*p1func)(param1, param2, param3, param4, param5, param6);
			}
		}

		GenericMemberFuncP6 paFunction;

		paFunction = reinterpret_cast<GenericMemberFuncP6> (memberFunction);

		return (mmPtr ->* paFunction)(param1, param2, param3, param4, param5,
				param6);
	}

	template<typename P1, typename P2, typename P3, typename P4, typename P5,
			typename P6, typename P7>
	RetType operator()(P1 param1, P2 param2, P3 param3, P4 param4, P5 param5, P6 param6,
			P7 param7) {
		typedef RetType (GenericClass::*GenericMemberFuncP7)(P1, P2, P3, P4,
				P5, P6, P7);
		typedef RetType (*funcType)(P1, P2, P3, P4, P5, P6, P7);
		if (arity != 7) {
			throw ArgumentNumberException(__LINE__, arity);
		}

		if (mmPtr == NULL) {
			if (functionPtr != NULL) {
				funcType p1func = reinterpret_cast<funcType> (functionPtr);

				return (*p1func)(param1, param2, param3, param4, param5,
						param6, param7);
			}
		}

		GenericMemberFuncP7 paFunction;

		paFunction = reinterpret_cast<GenericMemberFuncP7> (memberFunction);

		return (mmPtr ->* paFunction)(param1, param2, param3, param4, param5,
				param6, param7);
	}

	template<typename P1, typename P2, typename P3, typename P4, typename P5,
			typename P6, typename P7, typename P8>
	RetType operator()(P1 param1, P2 param2, P3 param3, P4 param4, P5 param5, P6 param6,
			P7 param7, P8 param8) {
		typedef RetType (GenericClass::*GenericMemberFuncP8)(P1, P2, P3, P4,
				P5, P6, P7, P8);
		typedef RetType (*funcType)(P1, P2, P3, P4, P5, P6, P7, P8);
		if (arity != 8) {
			throw ArgumentNumberException(__LINE__, arity);
		}

		if (mmPtr == NULL) {
			if (functionPtr != NULL) {
				funcType p1func = reinterpret_cast<funcType> (functionPtr);

				return (*p1func)(param1, param2, param3, param4, param5,
						param6, param7, param8);
			}
		}

		GenericMemberFuncP8 paFunction;

		paFunction = reinterpret_cast<GenericMemberFuncP8> (memberFunction);

		return (mmPtr ->* paFunction)(param1, param2, param3, param4, param5,
				param6, param7, param8);
	}

	template<typename P1, typename P2, typename P3, typename P4, typename P5,
			typename P6, typename P7, typename P8, typename P9>
	RetType operator()(P1 param1, P2 param2, P3 param3, P4 param4, P5 param5, P6 param6,
			P7 param7, P8 param8, P9 param9) {
		typedef RetType (GenericClass::*GenericMemberFuncP9)(P1, P2, P3, P4,
				P5, P6, P7, P8, P9);
		typedef RetType (*funcType)(P1, P2, P3, P4, P5, P6, P7, P8, P9);
		if (arity != 9) {
			throw ArgumentNumberException(__LINE__, arity);
		}

		if (mmPtr == NULL) {
			if (functionPtr != NULL) {
				funcType p1func = reinterpret_cast<funcType> (functionPtr);

				return (*p1func)(param1, param2, param3, param4, param5,
						param6, param7, param8, param9);
			}
		}

		GenericMemberFuncP9 paFunction;

		paFunction = reinterpret_cast<GenericMemberFuncP9> (memberFunction);

		return (mmPtr ->* paFunction)(param1, param2, param3, param4, param5,
				param6, param7, param8, param9);
	}

	template<typename P1, typename P2, typename P3, typename P4, typename P5,
			typename P6, typename P7, typename P8, typename P9, typename P10>
	RetType operator()(P1 param1, P2 param2, P3 param3, P4 param4, P5 param5, P6 param6,
			P7 param7, P8 param8, P9 param9, P10 param10) {
		typedef RetType (GenericClass::*GenericMemberFuncP10)(P1, P2, P3, P4,
				P5, P6, P7, P8, P9, P10);
		typedef RetType (*funcType)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10);
		if (arity != 10) {
			throw ArgumentNumberException(__LINE__, arity);
		}

		if (mmPtr == NULL) {
			if (functionPtr != NULL) {
				funcType p1func = reinterpret_cast<funcType> (functionPtr);

				return (*p1func)(param1, param2, param3, param4, param5,
						param6, param7, param8, param9, param10);
			}
		}

		GenericMemberFuncP10 paFunction;

		paFunction = reinterpret_cast<GenericMemberFuncP10> (memberFunction);

		return (mmPtr ->* paFunction)(param1, param2, param3, param4, param5,
				param6, param7, param8, param9, param10);
	}

	template<typename P1, typename P2, typename P3, typename P4, typename P5,
			typename P6, typename P7, typename P8, typename P9, typename P10,
			typename P11>
	RetType operator()(P1 param1, P2 param2, P3 param3, P4 param4, P5 param5, P6 param6,
			P7 param7, P8 param8, P9 param9, P10 param10, P11 param11) {
		typedef RetType (GenericClass::*GenericMemberFuncP11)(P1, P2, P3, P4,
				P5, P6, P7, P8, P9, P10, P11);
		typedef RetType (*funcType)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10,
				P11);
		if (arity != 11) {
			throw ArgumentNumberException(__LINE__, arity);
		}

		if (mmPtr == NULL) {
			if (functionPtr != NULL) {
				funcType p1func = reinterpret_cast<funcType> (functionPtr);

				return (*p1func)(param1, param2, param3, param4, param5,
						param6, param7, param8, param9, param10, param11);
			}
		}

		GenericMemberFuncP11 paFunction;

		paFunction = reinterpret_cast<GenericMemberFuncP11> (memberFunction);

		return (mmPtr ->* paFunction)(param1, param2, param3, param4, param5,
				param6, param7, param8, param9, param10, param11);
	}

	template<typename P1, typename P2, typename P3, typename P4, typename P5,
			typename P6, typename P7, typename P8, typename P9, typename P10,
			typename P11, typename P12>
	RetType operator()(P1 param1, P2 param2, P3 param3, P4 param4, P5 param5, P6 param6,
			P7 param7, P8 param8, P9 param9, P10 param10, P11 param11,
			P12 param12) {
		typedef RetType (GenericClass::*GenericMemberFuncP12)(P1, P2, P3, P4,
				P5, P6, P7, P8, P9, P10, P11, P12);
		typedef RetType (*funcType)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10,
				P11, P12);
		if (arity != 12) {
			throw ArgumentNumberException(__LINE__, arity);
		}

		if (mmPtr == NULL) {
			if (functionPtr != NULL) {
				funcType p1func = reinterpret_cast<funcType> (functionPtr);

				return (*p1func)(param1, param2, param3, param4, param5,
						param6, param7, param8, param9, param10, param11,
						param12);
			}
		}

		GenericMemberFuncP12 paFunction;

		paFunction = reinterpret_cast<GenericMemberFuncP12> (memberFunction);

		return (mmPtr ->* paFunction)(param1, param2, param3, param4, param5,
				param6, param7, param8, param9, param10, param11, param12);
	}

	template<typename P1, typename P2, typename P3, typename P4, typename P5,
			typename P6, typename P7, typename P8, typename P9, typename P10,
			typename P11, typename P12, typename P13>
	RetType operator()(P1 param1, P2 param2, P3 param3, P4 param4, P5 param5, P6 param6,
			P7 param7, P8 param8, P9 param9, P10 param10, P11 param11,
			P12 param12, P13 param13) {
		typedef RetType (GenericClass::*GenericMemberFuncP13)(P1, P2, P3, P4,
				P5, P6, P7, P8, P9, P10, P11, P12, P13);
		typedef RetType (*funcType)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10,
				P11, P12, P13);
		if (arity != 13) {
			throw ArgumentNumberException(__LINE__, arity);
		}

		if (mmPtr == NULL) {
			if (functionPtr != NULL) {
				funcType p1func = reinterpret_cast<funcType> (functionPtr);

				return (*p1func)(param1, param2, param3, param4, param5,
						param6, param7, param8, param9, param10, param11,
						param12, param13);
			}
		}

		GenericMemberFuncP13 paFunction;

		paFunction = reinterpret_cast<GenericMemberFuncP13> (memberFunction);

		return (mmPtr ->* paFunction)(param1, param2, param3, param4, param5,
				param6, param7, param8, param9, param10, param11, param12,
				param13);
	}

	template<typename P1, typename P2, typename P3, typename P4, typename P5,
			typename P6, typename P7, typename P8, typename P9, typename P10,
			typename P11, typename P12, typename P13, typename P14>
	RetType operator()(P1 param1, P2 param2, P3 param3, P4 param4, P5 param5, P6 param6,
			P7 param7, P8 param8, P9 param9, P10 param10, P11 param11,
			P12 param12, P13 param13, P14 param14) {
		typedef RetType (GenericClass::*GenericMemberFuncP14)(P1, P2, P3, P4,
				P5, P6, P7, P8, P9, P10, P11, P12, P13, P14);
		typedef RetType (*funcType)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10,
				P11, P12, P13, P14);
		if (arity != 14) {
			throw ArgumentNumberException(__LINE__, arity);
		}

		if (mmPtr == NULL) {
			if (functionPtr != NULL) {
				funcType p1func = reinterpret_cast<funcType> (functionPtr);

				return (*p1func)(param1, param2, param3, param4, param5,
						param6, param7, param8, param9, param10, param11,
						param12, param13, param14);
			}
		}

		GenericMemberFuncP14 paFunction;

		paFunction = reinterpret_cast<GenericMemberFuncP14> (memberFunction);

		return (mmPtr ->* paFunction)(param1, param2, param3, param4, param5,
				param6, param7, param8, param9, param10, param11, param12,
				param13, param14);
	}

	template<typename P1, typename P2, typename P3, typename P4, typename P5,
			typename P6, typename P7, typename P8, typename P9, typename P10,
			typename P11, typename P12, typename P13, typename P14,
			typename P15>
	RetType operator()(P1 param1, P2 param2, P3 param3, P4 param4, P5 param5, P6 param6,
			P7 param7, P8 param8, P9 param9, P10 param10, P11 param11,
			P12 param12, P13 param13, P14 param14, P15 param15) {
		typedef RetType (GenericClass::*GenericMemberFuncP15)(P1, P2, P3, P4,
				P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15);
		typedef RetType (*funcType)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10,
				P11, P12, P13, P14, P15);
		if (arity != 15) {
			throw ArgumentNumberException(__LINE__, arity);
		}

		if (mmPtr == NULL) {
			if (functionPtr != NULL) {
				funcType p1func = reinterpret_cast<funcType> (functionPtr);

				return (*p1func)(param1, param2, param3, param4, param5,
						param6, param7, param8, param9, param10, param11,
						param12, param13, param14, param15);
			}
		}

		GenericMemberFuncP15 paFunction;

		paFunction = reinterpret_cast<GenericMemberFuncP15> (memberFunction);

		return (mmPtr ->* paFunction)(param1, param2, param3, param4, param5,
				param6, param7, param8, param9, param10, param11, param12,
				param13, param14, param15);
	}
};

template<>
class ProvidedMethod<void> : public Method {
protected:
	typedef void (GenericClass::*GenericMemberFunc)();
	typedef void (*functionPtrFunc)();

	functionPtrFunc functionPtr;
	GenericMemberFunc memberFunction;

	GenericClass *mmPtr;

	const int arity;

	std::string m_returnType;


public:

	virtual std::string &getReturnType()
	{
		return m_returnType;
	}


	virtual int getArity()
	{
		return arity;
	}

	ProvidedMethod(int argNum) :
		arity(argNum) {
		m_returnType = "void";
	}

	virtual ReturnType call(opros::archive::iarchive &in,
			opros::archive::oarchive &out) = 0;

	void operator()() {
		if (arity != 0) {
			throw ArgumentNumberException(__LINE__, arity);
		}

		if (mmPtr == NULL) {
			if (functionPtr != NULL)
				(*functionPtr)();
			return;
		} else

			(mmPtr ->* memberFunction)();
	}
	;

	template<typename P1>
	void operator()(P1 param1) {
		typedef void (GenericClass::*GenericMemberFuncP1)(P1);
		typedef void (*funcType)(P1);

		if (arity != 1) {
			throw ArgumentNumberException(__LINE__, arity);
		}

		if (mmPtr == NULL) {
			if (functionPtr != NULL) {
				funcType p1func = reinterpret_cast<funcType> (functionPtr);

				(*p1func)(param1);
				return;
			}
		}

		GenericMemberFuncP1 paFunction;

		paFunction = reinterpret_cast<GenericMemberFuncP1> (memberFunction);

		(mmPtr ->* paFunction)(param1);
	}
	;

	template<typename P1, typename P2>
	void operator()(P1 param1, P2 param2) {
		typedef void (GenericClass::*GenericMemberFuncP2)(P1, P2);
		typedef void (*funcType)(P1, P2);
		if (arity != 2) {
			throw ArgumentNumberException(__LINE__, arity);
		}

		if (mmPtr == NULL) {
			if (functionPtr != NULL) {
				funcType p1func = reinterpret_cast<funcType> (functionPtr);

				(*p1func)(param1, param2);
				return;
			}
		}

		GenericMemberFuncP2 paFunction;

		paFunction = reinterpret_cast<GenericMemberFuncP2> (memberFunction);

		(mmPtr ->* paFunction)(param1, param2);
	}
	;

	template<typename P1, typename P2, typename P3>
	void operator()(P1 param1, P2 param2, P3 param3) {
		typedef void (GenericClass::*GenericMemberFuncP3)(P1, P2, P3);
		typedef void (*funcType)(P1, P2, P3);
		if (arity != 3) {
			throw ArgumentNumberException(__LINE__, arity);
		}

		if (mmPtr == NULL) {
			if (functionPtr != NULL) {
				funcType p1func = reinterpret_cast<funcType> (functionPtr);

				(*p1func)(param1, param2, param3);
				return;
			}
		}

		GenericMemberFuncP3 paFunction;

		paFunction = reinterpret_cast<GenericMemberFuncP3> (memberFunction);

		(mmPtr ->* paFunction)(param1, param2, param3);
	}
	;

	template<typename P1, typename P2, typename P3, typename P4>
	void operator()(P1 param1, P2 param2, P3 param3, P4 param4) {
		typedef void (GenericClass::*GenericMemberFuncP4)(P1, P2, P3, P4);
		typedef void (*funcType)(P1, P2, P3, P4);
		if (arity != 4) {
			throw ArgumentNumberException(__LINE__, arity);
		}

		if (mmPtr == NULL) {
			if (functionPtr != NULL) {
				funcType p1func = reinterpret_cast<funcType> (functionPtr);

				(*p1func)(param1, param2, param3, param4);
				return;
			}
		}

		GenericMemberFuncP4 paFunction;

		paFunction = reinterpret_cast<GenericMemberFuncP4> (memberFunction);

		(mmPtr ->* paFunction)(param1, param2, param3, param4);
	}
	;

	template<typename P1, typename P2, typename P3, typename P4, typename P5>
	void operator()(P1 param1, P2 param2, P3 param3, P4 param4, P5 param5) {
		typedef void (GenericClass::*GenericMemberFuncP5)(P1, P2, P3, P4, P5);
		typedef void (*funcType)(P1, P2, P3, P4, P5);
		if (arity != 5) {
			throw ArgumentNumberException(__LINE__, arity);
		}

		if (mmPtr == NULL) {
			if (functionPtr != NULL) {
				funcType p1func = reinterpret_cast<funcType> (functionPtr);

				(*p1func)(param1, param2, param3, param4, param5);
				return;
			}
		}

		GenericMemberFuncP5 paFunction;

		paFunction = reinterpret_cast<GenericMemberFuncP5> (memberFunction);

		(mmPtr ->* paFunction)(param1, param2, param3, param4, param5);
	}
	;

	template<typename P1, typename P2, typename P3, typename P4, typename P5,
			typename P6>
	void operator()(P1 param1, P2 param2, P3 param3, P4 param4, P5 param5, P6 param6) {
		typedef void (GenericClass::*GenericMemberFuncP6)(P1, P2, P3, P4, P5,
				P6);
		typedef void (*funcType)(P1, P2, P3, P4, P5, P6);
		if (arity != 6) {
			throw ArgumentNumberException(__LINE__, arity);
		}

		if (mmPtr == NULL) {
			if (functionPtr != NULL) {
				funcType p1func = reinterpret_cast<funcType> (functionPtr);

				(*p1func)(param1, param2, param3, param4, param5, param6);
				return;
			}
		}

		GenericMemberFuncP6 paFunction;

		paFunction = reinterpret_cast<GenericMemberFuncP6> (memberFunction);

		(mmPtr ->* paFunction)(param1, param2, param3, param4, param5, param6);
	}
	;

	template<typename P1, typename P2, typename P3, typename P4, typename P5,
			typename P6, typename P7>
	void operator()(P1 param1, P2 param2, P3 param3, P4 param4, P5 param5, P6 param6,
			P7 param7) {
		typedef void (GenericClass::*GenericMemberFuncP7)(P1, P2, P3, P4, P5,
				P6, P7);
		typedef void (*funcType)(P1, P2, P3, P4, P5, P6, P7);
		if (arity != 7) {
			throw ArgumentNumberException(__LINE__, arity);
		}

		if (mmPtr == NULL) {
			if (functionPtr != NULL) {
				funcType p1func = reinterpret_cast<funcType> (functionPtr);

				(*p1func)(param1, param2, param3, param4, param5, param6,
						param7);
				return;
			}
		}

		GenericMemberFuncP7 paFunction;

		paFunction = reinterpret_cast<GenericMemberFuncP7> (memberFunction);

		(mmPtr ->* paFunction)(param1, param2, param3, param4, param5, param6,
				param7);
	}
	;

	template<typename P1, typename P2, typename P3, typename P4, typename P5,
			typename P6, typename P7, typename P8>
	void operator()(P1 param1, P2 param2, P3 param3, P4 param4, P5 param5, P6 param6,
			P7 param7, P8 param8) {
		typedef void (GenericClass::*GenericMemberFuncP8)(P1, P2, P3, P4, P5,
				P6, P7, P8);
		typedef void (*funcType)(P1, P2, P3, P4, P5, P6, P7, P8);
		if (arity != 8) {
			throw ArgumentNumberException(__LINE__, arity);
		}

		if (mmPtr == NULL) {
			if (functionPtr != NULL) {
				funcType p1func = reinterpret_cast<funcType> (functionPtr);

				(*p1func)(param1, param2, param3, param4, param5, param6,
						param7, param8);
				return;
			}
		}

		GenericMemberFuncP8 paFunction;

		paFunction = reinterpret_cast<GenericMemberFuncP8> (memberFunction);

		(mmPtr ->* paFunction)(param1, param2, param3, param4, param5, param6,
				param7, param8);
	}
	;

	template<typename P1, typename P2, typename P3, typename P4, typename P5,
			typename P6, typename P7, typename P8, typename P9>
	void operator()(P1 param1, P2 param2, P3 param3, P4 param4, P5 param5, P6 param6,
			P7 param7, P8 param8, P9 param9) {
		typedef void (GenericClass::*GenericMemberFuncP9)(P1, P2, P3, P4, P5,
				P6, P7, P8, P9);
		typedef void (*funcType)(P1, P2, P3, P4, P5, P6, P7, P8, P9);
		if (arity != 9) {
			throw ArgumentNumberException(__LINE__, arity);
		}

		if (mmPtr == NULL) {
			if (functionPtr != NULL) {
				funcType p1func = reinterpret_cast<funcType> (functionPtr);

				(*p1func)(param1, param2, param3, param4, param5, param6,
						param7, param8, param9);
				return;
			}
		}

		GenericMemberFuncP9 paFunction;

		paFunction = reinterpret_cast<GenericMemberFuncP9> (memberFunction);

		(mmPtr ->* paFunction)(param1, param2, param3, param4, param5, param6,
				param7, param8, param9);
	}
	;

	template<typename P1, typename P2, typename P3, typename P4, typename P5,
			typename P6, typename P7, typename P8, typename P9, typename P10>
	void operator()(P1 param1, P2 param2, P3 param3, P4 param4, P5 param5, P6 param6,
			P7 param7, P8 param8, P9 param9, P10 param10) {
		typedef void (GenericClass::*GenericMemberFuncP10)(P1, P2, P3, P4, P5,
				P6, P7, P8, P9, P10);
		typedef void (*funcType)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10);
		if (arity != 10) {
			throw ArgumentNumberException(__LINE__, arity);
		}

		if (mmPtr == NULL) {
			if (functionPtr != NULL) {
				funcType p1func = reinterpret_cast<funcType> (functionPtr);

				(*p1func)(param1, param2, param3, param4, param5, param6,
						param7, param8, param9, param10);
				return;
			}
		}

		GenericMemberFuncP10 paFunction;

		paFunction = reinterpret_cast<GenericMemberFuncP10> (memberFunction);

		(mmPtr ->* paFunction)(param1, param2, param3, param4, param5, param6,
				param7, param8, param9, param10);
	}

	template<typename P1, typename P2, typename P3, typename P4, typename P5,
			typename P6, typename P7, typename P8, typename P9, typename P10,
			typename P11>
	void operator()(P1 param1, P2 param2, P3 param3, P4 param4, P5 param5, P6 param6,
			P7 param7, P8 param8, P9 param9, P10 param10, P11 param11) {
		typedef void (GenericClass::*GenericMemberFuncP11)(P1, P2, P3, P4, P5,
				P6, P7, P8, P9, P10, P11);
		typedef void (*funcType)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11);
		if (arity != 11) {
			throw ArgumentNumberException(__LINE__, arity);
		}

		if (mmPtr == NULL) {
			if (functionPtr != NULL) {
				funcType p1func = reinterpret_cast<funcType> (functionPtr);

				(*p1func)(param1, param2, param3, param4, param5, param6,
						param7, param8, param9, param10, param11);
				return;
			}
		}

		GenericMemberFuncP11 paFunction;

		paFunction = reinterpret_cast<GenericMemberFuncP11> (memberFunction);

		(mmPtr ->* paFunction)(param1, param2, param3, param4, param5, param6,
				param7, param8, param9, param10, param11);
	}

	template<typename P1, typename P2, typename P3, typename P4, typename P5,
			typename P6, typename P7, typename P8, typename P9, typename P10,
			typename P11, typename P12>
	void operator()(P1 param1, P2 param2, P3 param3, P4 param4, P5 param5, P6 param6,
			P7 param7, P8 param8, P9 param9, P10 param10, P11 param11,
			P12 param12) {
		typedef void (GenericClass::*GenericMemberFuncP12)(P1, P2, P3, P4, P5,
				P6, P7, P8, P9, P10, P11, P12);
		typedef void (*funcType)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11,
				P12);
		if (arity != 12) {
			throw ArgumentNumberException(__LINE__, arity);
		}

		if (mmPtr == NULL) {
			if (functionPtr != NULL) {
				funcType p1func = reinterpret_cast<funcType> (functionPtr);

				(*p1func)(param1, param2, param3, param4, param5, param6,
						param7, param8, param9, param10, param11, param12);
				return;
			}
		}

		GenericMemberFuncP12 paFunction;

		paFunction = reinterpret_cast<GenericMemberFuncP12> (memberFunction);

		(mmPtr ->* paFunction)(param1, param2, param3, param4, param5, param6,
				param7, param8, param9, param10, param11, param12);
	}

	template<typename P1, typename P2, typename P3, typename P4, typename P5,
			typename P6, typename P7, typename P8, typename P9, typename P10,
			typename P11, typename P12, typename P13>
	void operator()(P1 param1, P2 param2, P3 param3, P4 param4, P5 param5, P6 param6,
			P7 param7, P8 param8, P9 param9, P10 param10, P11 param11,
			P12 param12, P13 param13) {
		typedef void (GenericClass::*GenericMemberFuncP13)(P1, P2, P3, P4, P5,
				P6, P7, P8, P9, P10, P11, P12, P13);
		typedef void (*funcType)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11,
				P12, P13);
		if (arity != 13) {
			throw ArgumentNumberException(__LINE__, arity);
		}

		if (mmPtr == NULL) {
			if (functionPtr != NULL) {
				funcType p1func = reinterpret_cast<funcType> (functionPtr);

				(*p1func)(param1, param2, param3, param4, param5, param6,
						param7, param8, param9, param10, param11, param12,
						param13);
				return;
			}
		}

		GenericMemberFuncP13 paFunction;

		paFunction = reinterpret_cast<GenericMemberFuncP13> (memberFunction);

		(mmPtr ->* paFunction)(param1, param2, param3, param4, param5, param6,
				param7, param8, param9, param10, param11, param12, param13);
	}

	template<typename P1, typename P2, typename P3, typename P4, typename P5,
			typename P6, typename P7, typename P8, typename P9, typename P10,
			typename P11, typename P12, typename P13, typename P14>
	void operator()(P1 param1, P2 param2, P3 param3, P4 param4, P5 param5, P6 param6,
			P7 param7, P8 param8, P9 param9, P10 param10, P11 param11,
			P12 param12, P13 param13, P14 param14) {
		typedef void (GenericClass::*GenericMemberFuncP14)(P1, P2, P3, P4, P5,
				P6, P7, P8, P9, P10, P11, P12, P13, P14);
		typedef void (*funcType)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11,
				P12, P13, P14);
		if (arity != 14) {
			throw ArgumentNumberException(__LINE__, arity);
		}

		if (mmPtr == NULL) {
			if (functionPtr != NULL) {
				funcType p1func = reinterpret_cast<funcType> (functionPtr);

				(*p1func)(param1, param2, param3, param4, param5, param6,
						param7, param8, param9, param10, param11, param12,
						param13, param14);
				return;
			}
		}

		GenericMemberFuncP14 paFunction;

		paFunction = reinterpret_cast<GenericMemberFuncP14> (memberFunction);

		(mmPtr ->* paFunction)(param1, param2, param3, param4, param5, param6,
				param7, param8, param9, param10, param11, param12, param13,
				param14);
	}

	template<typename P1, typename P2, typename P3, typename P4, typename P5,
			typename P6, typename P7, typename P8, typename P9, typename P10,
			typename P11, typename P12, typename P13, typename P14,
			typename P15>
	void operator()(P1 param1, P2 param2, P3 param3, P4 param4, P5 param5, P6 param6,
			P7 param7, P8 param8, P9 param9, P10 param10, P11 param11,
			P12 param12, P13 param13, P14 param14, P15 param15) {
		typedef void (GenericClass::*GenericMemberFuncP15)(P1, P2, P3, P4, P5,
				P6, P7, P8, P9, P10, P11, P12, P13, P14, P15);
		typedef void (*funcType)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11,
				P12, P13, P14, P15);
		if (arity != 15) {
			throw ArgumentNumberException(__LINE__, arity);
		}

		if (mmPtr == NULL) {
			if (functionPtr != NULL) {
				funcType p1func = reinterpret_cast<funcType> (functionPtr);

				(*p1func)(param1, param2, param3, param4, param5, param6,
						param7, param8, param9, param10, param11, param12,
						param13, param14, param15);
				return;
			}
		}

		GenericMemberFuncP15 paFunction;

		paFunction = reinterpret_cast<GenericMemberFuncP15> (memberFunction);

		(mmPtr ->* paFunction)(param1, param2, param3, param4, param5, param6,
				param7, param8, param9, param10, param11, param12, param13,
				param14, param15);
	}
};

template<typename RetType>
class ProvidedMethod_0: public ProvidedMethod<RetType> {
	typedef RetType (GenericClass::*GenericMemberFunc)();
	typedef RetType (*functionType)();

	template<typename R>
	inline ReturnType _call(opros::archive::iarchive & in,
			opros::archive::oarchive & out) {
		R resultData;

		resultData = (*this)();

		out << OPROS_SERIALIZATION_NVP(resultData);

		return OPROS_SUCCESS;
	}
public:

	virtual ReturnType call(opros::archive::iarchive & in,
			opros::archive::oarchive & out) {
		return _call<typename opros::remove_const<
				typename opros::remove_reference<RetType>::type>::type> (in,
				out);
	}

	template<typename R, typename C>
	ProvidedMethod_0(R(C::* function)(), C *classPtr, char *fname) :
		ProvidedMethod<RetType> (0) {
		this->m_name = fname;

		this->memberFunction = reinterpret_cast<GenericMemberFunc> (function);

		this->mmPtr = reinterpret_cast<GenericClass *> (classPtr);

		this->functionPtr = NULL;
	}

	template<typename R>
	ProvidedMethod_0(R(*function)(), char *fname) :
		ProvidedMethod<RetType> (0) {
		this->m_name = fname;

		this->memberFunction = NULL;

		this->mmPtr = NULL;

		this->functionPtr = reinterpret_cast<functionType> (function);
	}

};

template<typename RetType, typename PA1>
class ProvidedMethod_1: public ProvidedMethod<RetType> {
	typedef RetType (GenericClass::*GenericMemberFunc)();
	typedef RetType (*functionType)();


	template<typename R, typename TPA1>
	 inline ReturnType _call(opros::archive::iarchive & in,
			opros::archive::oarchive & out) {
		R resultData;

		TPA1 param1;

		in >> OPROS_SERIALIZATION_NVP(param1);

#ifdef _MSC_VER
		resultData = (*this).operator()<PA1>(param1);
#else
		resultData = (*this).template operator()<PA1>(param1);

#endif

		out << OPROS_SERIALIZATION_NVP(resultData);

		return OPROS_SUCCESS;
	}

public:

	virtual ReturnType call(opros::archive::iarchive & in,
			opros::archive::oarchive & out) {

		return _call<typename opros::remove_const<
		typename opros::remove_reference<RetType>::type>::type,
		typename opros::remove_const<typename opros::remove_reference<
		PA1>::type>::type> (in, out);
	}

	template<typename R, typename P1, typename C>
	ProvidedMethod_1(R(C::* function)(P1), C *classPtr, char *fname) :
	ProvidedMethod<RetType> (1) {
		this->m_name = fname;

		this->memberFunction = reinterpret_cast<GenericMemberFunc> (function);

		this->mmPtr = reinterpret_cast<GenericClass *> (classPtr);

		this->functionPtr = NULL;
	}

	template<typename R, typename P1>
	ProvidedMethod_1(R(*function)(P1), char *fname) :
	ProvidedMethod<RetType> (1) {
		this->m_name = fname;

		this->memberFunction = NULL;

		this->mmPtr = NULL;

		this->functionPtr = reinterpret_cast<functionType> (function);
	}
};

template<typename RetType, typename PA1, typename PA2>
class ProvidedMethod_2: public ProvidedMethod<RetType> {
	typedef RetType (GenericClass::*GenericMemberFunc)();
	typedef RetType (*functionType)();

	template<typename R, typename TPA1, typename TPA2>
	inline ReturnType _call(opros::archive::iarchive & in,
			opros::archive::oarchive & out) {
		R resultData;

		TPA1 param1;
		TPA2 param2;

		in >> OPROS_SERIALIZATION_NVP(param1);
		in >> OPROS_SERIALIZATION_NVP(param2);
#ifdef _MSC_VER
		resultData = (*this).operator()<PA1,PA2>(param1, param2);
#else
		resultData = (*this).template operator()<PA1,PA2>(param1, param2);
#endif

		out << OPROS_SERIALIZATION_NVP(resultData);

		return OPROS_SUCCESS;
	}

public:

	virtual ReturnType call(opros::archive::iarchive & in,
			opros::archive::oarchive & out) {
		return _call<typename opros::remove_const<
		typename opros::remove_reference<RetType>::type>::type,
		typename opros::remove_const<typename opros::remove_reference<
		PA1>::type>::type, typename opros::remove_const<
		typename opros::remove_reference<PA2>::type>::type> (
				in, out);
	}

	template<typename R, typename P1, typename P2, typename C>
	ProvidedMethod_2(R(C::* function)(P1, P2), C *classPtr, char *fname) :
	ProvidedMethod<RetType> (2) {
		this->m_name = fname;

		this->memberFunction = reinterpret_cast<GenericMemberFunc> (function);

		this->mmPtr = reinterpret_cast<GenericClass *> (classPtr);
	}

	template<typename R, typename P1, typename P2>
	ProvidedMethod_2(R(*function)(P1, P2), char *fname) :
	ProvidedMethod<RetType> (2) {
		this->m_name = fname;

		this->memberFunction = NULL;

		this->mmPtr = NULL;

		this->functionPtr = reinterpret_cast<functionType> (function);
	}
};

template<typename RetType, typename PA1, typename PA2, typename PA3>
class ProvidedMethod_3: public ProvidedMethod<RetType> {
	typedef RetType (GenericClass::*GenericMemberFunc)();
	typedef RetType (*functionType)();

	template<typename R, typename TPA1, typename TPA2, typename TPA3>
	inline ReturnType _call(opros::archive::iarchive & in,
			opros::archive::oarchive & out) {
		R resultData;

		TPA1 param1;
		TPA2 param2;
		TPA3 param3;

		in >> OPROS_SERIALIZATION_NVP(param1);
		in >> OPROS_SERIALIZATION_NVP(param2);
		in >> OPROS_SERIALIZATION_NVP(param3);

#ifdef _MSC_VER
		resultData = (*this).operator()<PA1,PA2,PA3>(param1, param2, param3);
#else
		resultData = (*this).template operator()<PA1,PA2,PA3>(param1, param2, param3);
#endif


		out << OPROS_SERIALIZATION_NVP(resultData);

		return OPROS_SUCCESS;
	}

public:

	virtual ReturnType call(opros::archive::iarchive & in,
			opros::archive::oarchive & out) {

		return _call<typename opros::remove_const<
		typename opros::remove_reference<RetType>::type>::type,
		typename opros::remove_const<typename opros::remove_reference<
		PA1>::type>::type, typename opros::remove_const<
		typename opros::remove_reference<PA2>::type>::type,
		typename opros::remove_const<typename opros::remove_reference<
		PA3>::type>::type> (in, out);
	}

	template<typename R, typename P1, typename P2, typename P3, typename C>
	ProvidedMethod_3(R(C::* function)(P1, P2, P3), C *classPtr, char *fname) :
	ProvidedMethod<RetType> (3) {
		this->m_name = fname;

		this->memberFunction = reinterpret_cast<GenericMemberFunc> (function);

		this->mmPtr = reinterpret_cast<GenericClass *> (classPtr);
	}

	template<typename R, typename P1, typename P2, typename P3>
	ProvidedMethod_3(R(*function)(P1, P2, P3), char *fname) :
	ProvidedMethod<RetType> (3) {
		this->m_name = fname;

		this->memberFunction = NULL;

		this->mmPtr = NULL;

		this->functionPtr = reinterpret_cast<functionType> (function);
	}
};

template<typename RetType, typename PA1, typename PA2, typename PA3,
		typename PA4>
class ProvidedMethod_4: public ProvidedMethod<RetType> {
	typedef RetType (GenericClass::*GenericMemberFunc)();
	typedef RetType (*functionType)();

	template<typename R, typename TPA1, typename TPA2, typename TPA3,
			typename TPA4>
	inline ReturnType _call(opros::archive::iarchive & in,
			opros::archive::oarchive & out) {
		R resultData;

		TPA1 param1;
		TPA2 param2;
		TPA3 param3;
		TPA4 param4;

		in >> OPROS_SERIALIZATION_NVP(param1);
		in >> OPROS_SERIALIZATION_NVP(param2);
		in >> OPROS_SERIALIZATION_NVP(param3);
		in >> OPROS_SERIALIZATION_NVP(param4);

#ifdef _MSC_VER
		resultData = (*this).operator()<PA1,PA2,PA3,PA4>(param1, param2, param3, param4);
#else
		resultData = (*this).template operator()<PA1,PA2,PA3,PA4>(param1, param2, param3, param4);
#endif


		out << OPROS_SERIALIZATION_NVP(resultData);

		return OPROS_SUCCESS;
	}

public:

	virtual ReturnType call(opros::archive::iarchive & in,
			opros::archive::oarchive & out) {
		return _call<typename opros::remove_const<
		typename opros::remove_reference<RetType>::type>::type,
		typename opros::remove_const<typename opros::remove_reference<
		PA1>::type>::type, typename opros::remove_const<
		typename opros::remove_reference<PA2>::type>::type,
		typename opros::remove_const<typename opros::remove_reference<
		PA3>::type>::type, typename opros::remove_const<
		typename opros::remove_reference<PA4>::type>::type> (
				in, out);
	}

	template<typename R, typename P1, typename P2, typename P3, typename P4,
	typename C>
	ProvidedMethod_4(R(C::* function)(P1, P2, P3, P4), C *classPtr, char *fname) :
	ProvidedMethod<RetType> (4) {
		this->m_name = fname;

		this->memberFunction = reinterpret_cast<GenericMemberFunc> (function);

		this->mmPtr = reinterpret_cast<GenericClass *> (classPtr);
	}

	template<typename R, typename P1, typename P2, typename P3, typename P4>
	ProvidedMethod_4(R(*function)(P1, P2, P3, P4), char *fname) :
	ProvidedMethod<RetType> (4) {
		this->m_name = fname;

		this->memberFunction = NULL;

		this->mmPtr = NULL;

		this->functionPtr = reinterpret_cast<functionType> (function);
	}
};

template<typename RetType, typename PA1, typename PA2, typename PA3,
		typename PA4, typename PA5>
class ProvidedMethod_5: public ProvidedMethod<RetType> {
	typedef RetType (GenericClass::*GenericMemberFunc)();
	typedef RetType (*functionType)();

	template<typename R, typename TPA1, typename TPA2, typename TPA3,
			typename TPA4, typename TPA5>
	inline ReturnType _call(opros::archive::iarchive & in,
			opros::archive::oarchive & out) {
		R resultData;

		TPA1 param1;
		TPA2 param2;
		TPA3 param3;
		TPA4 param4;
		TPA5 param5;

		in >> OPROS_SERIALIZATION_NVP(param1);
		in >> OPROS_SERIALIZATION_NVP(param2);
		in >> OPROS_SERIALIZATION_NVP(param3);
		in >> OPROS_SERIALIZATION_NVP(param4);
		in >> OPROS_SERIALIZATION_NVP(param5);

#ifdef _MSC_VER
		resultData = (*this).operator()<PA1,PA2,PA3,PA4,PA5>(param1, param2, param3, param4, param5);
#else
		resultData = (*this).template operator()<PA1,PA2,PA3,PA4,PA5>(param1, param2, param3, param4, param5);
#endif

		out << OPROS_SERIALIZATION_NVP(resultData);

		return OPROS_SUCCESS;
	}

public:

	virtual ReturnType call(opros::archive::iarchive & in,
			opros::archive::oarchive & out) {
		return _call<typename opros::remove_const<
		typename opros::remove_reference<RetType>::type>::type,
		typename opros::remove_const<typename opros::remove_reference<
		PA1>::type>::type, typename opros::remove_const<
		typename opros::remove_reference<PA2>::type>::type,
		typename opros::remove_const<typename opros::remove_reference<
		PA3>::type>::type, typename opros::remove_const<
		typename opros::remove_reference<PA4>::type>::type,
		typename opros::remove_const<typename opros::remove_reference<
		PA5>::type>::type> (in, out);
	}

	template<typename R, typename P1, typename P2, typename P3, typename P4,
	typename P5, typename C>
	ProvidedMethod_5(R(C::* function)(P1, P2, P3, P4, P5), C *classPtr,
			char *fname) :
	ProvidedMethod<RetType> (5) {
		this->m_name = fname;

		this->memberFunction = reinterpret_cast<GenericMemberFunc> (function);

		this->mmPtr = reinterpret_cast<GenericClass *> (classPtr);
	}

	template<typename R, typename P1, typename P2, typename P3, typename P4,
	typename P5>
	ProvidedMethod_5(R(*function)(P1, P2, P3, P4, P5), char *fname) :
	ProvidedMethod<RetType> (5) {
		this->m_name = fname;

		this->memberFunction = NULL;

		this->mmPtr = NULL;

		this->functionPtr = reinterpret_cast<functionType> (function);
	}
};

template<typename RetType, typename PA1, typename PA2, typename PA3,
		typename PA4, typename PA5, typename PA6>
class ProvidedMethod_6: public ProvidedMethod<RetType> {
	typedef RetType (GenericClass::*GenericMemberFunc)();
	typedef RetType (*functionType)();

	template<typename R, typename TPA1, typename TPA2, typename TPA3,
			typename TPA4, typename TPA5, typename TPA6>
	inline ReturnType _call(opros::archive::iarchive & in,
			opros::archive::oarchive & out) {
		R resultData;

		TPA1 param1;
		TPA2 param2;
		TPA3 param3;
		TPA4 param4;
		TPA5 param5;
		TPA6 param6;

		in >> OPROS_SERIALIZATION_NVP(param1);
		in >> OPROS_SERIALIZATION_NVP(param2);
		in >> OPROS_SERIALIZATION_NVP(param3);
		in >> OPROS_SERIALIZATION_NVP(param4);
		in >> OPROS_SERIALIZATION_NVP(param5);
		in >> OPROS_SERIALIZATION_NVP(param6);

#ifdef _MSC_VER
		resultData = (*this).operator ()<PA1,PA2,PA3,PA4,PA5,PA6>(param1, param2, param3, param4, param5, param6);
#else
		resultData = (*this).template operator ()<PA1,PA2,PA3,PA4,PA5,PA6>(param1, param2, param3, param4, param5, param6);
#endif

		out << OPROS_SERIALIZATION_NVP(resultData);

		return OPROS_SUCCESS;
	}
public:

	virtual ReturnType call(opros::archive::iarchive & in,
			opros::archive::oarchive & out) {
		return _call<typename opros::remove_const<
		typename opros::remove_reference<RetType>::type>::type,
		typename opros::remove_const<typename opros::remove_reference<
		PA1>::type>::type, typename opros::remove_const<
		typename opros::remove_reference<PA2>::type>::type,
		typename opros::remove_const<typename opros::remove_reference<
		PA3>::type>::type, typename opros::remove_const<
		typename opros::remove_reference<PA4>::type>::type,
		typename opros::remove_const<typename opros::remove_reference<
		PA5>::type>::type, typename opros::remove_const<
		typename opros::remove_reference<PA6>::type>::type> (
				in, out);
	}

	template<typename R, typename P1, typename P2, typename P3, typename P4,
	typename P5, typename P6, typename C>
	ProvidedMethod_6(R(C::* function)(P1, P2, P3, P4, P5, P6), C *classPtr,
			char *fname) :
	ProvidedMethod<RetType> (6) {
		this->m_name = fname;

		this->memberFunction = reinterpret_cast<GenericMemberFunc> (function);

		this->mmPtr = reinterpret_cast<GenericClass *> (classPtr);
	}

	template<typename R, typename P1, typename P2, typename P3, typename P4,
	typename P5, typename P6>
	ProvidedMethod_6(R(*function)(P1, P2, P3, P4, P5, P6), char *fname) :
	ProvidedMethod<RetType> (6) {
		this->m_name = fname;

		this->memberFunction = NULL;

		this->mmPtr = NULL;

		this->functionPtr = reinterpret_cast<functionType> (function);
	}
};

template<typename RetType, typename PA1, typename PA2, typename PA3,
		typename PA4, typename PA5, typename PA6, typename PA7>
class ProvidedMethod_7: public ProvidedMethod<RetType> {
	typedef RetType (GenericClass::*GenericMemberFunc)();
	typedef RetType (*functionType)();

	template<typename R, typename TPA1, typename TPA2, typename TPA3,
			typename TPA4, typename TPA5, typename TPA6, typename TPA7>
	inline ReturnType _call(opros::archive::iarchive & in,
			opros::archive::oarchive & out) {
		R resultData;

		TPA1 param1;
		TPA2 param2;
		TPA3 param3;
		TPA4 param4;
		TPA5 param5;
		TPA6 param6;
		TPA7 param7;

		in >> OPROS_SERIALIZATION_NVP(param1);
		in >> OPROS_SERIALIZATION_NVP(param2);
		in >> OPROS_SERIALIZATION_NVP(param3);
		in >> OPROS_SERIALIZATION_NVP(param4);
		in >> OPROS_SERIALIZATION_NVP(param5);
		in >> OPROS_SERIALIZATION_NVP(param6);
		in >> OPROS_SERIALIZATION_NVP(param7);

#ifdef _MSC_VER
		resultData = (*this).operator ()<PA1,PA2,PA3,PA4,PA5,PA6,PA7>(param1, param2, param3, param4, param5, param6,
						param7);
#else
		resultData = (*this).template operator ()<PA1,PA2,PA3,PA4,PA5,PA6,PA7>(param1, param2, param3, param4, param5, param6,
				param7);
#endif

		out << OPROS_SERIALIZATION_NVP(resultData);

		return OPROS_SUCCESS;
	}

public:

	virtual ReturnType call(opros::archive::iarchive & in,
			opros::archive::oarchive & out) {
		return _call<typename opros::remove_const<typename opros::remove_reference<RetType>::type>::type,
		typename opros::remove_const<typename opros::remove_reference<PA1>::type>::type,
		typename opros::remove_const<	typename opros::remove_reference<PA2>::type>::type,
		typename opros::remove_const<typename opros::remove_reference<PA3>::type>::type,
		typename opros::remove_const<typename opros::remove_reference<PA4>::type>::type,
		typename opros::remove_const<typename opros::remove_reference<PA5>::type>::type,
		typename opros::remove_const<typename opros::remove_reference<PA6>::type>::type,
		typename opros::remove_const<typename opros::remove_reference<PA7>::type>::type> (in, out);
	}

	template<typename R, typename P1, typename P2, typename P3, typename P4,
	typename P5, typename P6, typename P7, typename C>
	ProvidedMethod_7(R(C::* function)(P1, P2, P3, P4, P5, P6, P7), C *classPtr,
			char *fname) :
	ProvidedMethod<RetType> (7) {
		this->m_name = fname;

		this->memberFunction = reinterpret_cast<GenericMemberFunc> (function);

		this->mmPtr = reinterpret_cast<GenericClass *> (classPtr);
	}

	template<typename R, typename P1, typename P2, typename P3, typename P4,
	typename P5, typename P6, typename P7>
	ProvidedMethod_7(R(*function)(P1, P2, P3, P4, P5, P6, P7), char *fname) :
	ProvidedMethod<RetType> (7) {
		this->m_name = fname;

		this->memberFunction = NULL;

		this->mmPtr = NULL;

		this->functionPtr = reinterpret_cast<functionType> (function);
	}
};

template<typename RetType, typename PA1, typename PA2, typename PA3,
		typename PA4, typename PA5, typename PA6, typename PA7, typename PA8>
class ProvidedMethod_8: public ProvidedMethod<RetType> {
	typedef RetType (GenericClass::*GenericMemberFunc)();
	typedef RetType (*functionType)();

	template<typename R, typename TPA1, typename TPA2, typename TPA3,
			typename TPA4, typename TPA5, typename TPA6, typename TPA7,
			typename TPA8>
	inline ReturnType _call(opros::archive::iarchive & in,
			opros::archive::oarchive & out) {
		R resultData;

		TPA1 param1;
		TPA2 param2;
		TPA3 param3;
		TPA4 param4;
		TPA5 param5;
		TPA6 param6;
		TPA7 param7;
		TPA8 param8;

		in >> OPROS_SERIALIZATION_NVP(param1);
		in >> OPROS_SERIALIZATION_NVP(param2);
		in >> OPROS_SERIALIZATION_NVP(param3);
		in >> OPROS_SERIALIZATION_NVP(param4);
		in >> OPROS_SERIALIZATION_NVP(param5);
		in >> OPROS_SERIALIZATION_NVP(param6);
		in >> OPROS_SERIALIZATION_NVP(param7);
		in >> OPROS_SERIALIZATION_NVP(param8);

#ifdef _MSC_VER
		resultData = (*this).operator ()<PA1,PA2,PA3,PA4,PA5,PA6,PA7,PA8>(param1, param2, param3, param4, param5, param6,
						param7, param8);
#else
		resultData = (*this).template operator ()<PA1,PA2,PA3,PA4,PA5,PA6,PA7,PA8>(param1, param2, param3, param4, param5, param6,
				param7, param8);
#endif

		out << OPROS_SERIALIZATION_NVP(resultData);

		return OPROS_SUCCESS;
	}
public:

	virtual ReturnType call(opros::archive::iarchive & in,
			opros::archive::oarchive & out) {
		return _call<typename opros::remove_const<
		typename opros::remove_reference<RetType>::type>::type,
		typename opros::remove_const<typename opros::remove_reference<
		PA1>::type>::type, typename opros::remove_const<
		typename opros::remove_reference<PA2>::type>::type,
		typename opros::remove_const<typename opros::remove_reference<
		PA3>::type>::type, typename opros::remove_const<
		typename opros::remove_reference<PA4>::type>::type,
		typename opros::remove_const<typename opros::remove_reference<
		PA5>::type>::type, typename opros::remove_const<
		typename opros::remove_reference<PA6>::type>::type,
		typename opros::remove_const<typename opros::remove_reference<
		PA7>::type>::type, typename opros::remove_const<
		typename opros::remove_reference<PA8>::type>::type> (
				in, out);
	}

	template<typename R, typename P1, typename P2, typename P3, typename P4,
	typename P5, typename P6, typename P7, typename P8, typename C>
	ProvidedMethod_8(R(C::* function)(P1, P2, P3, P4, P5, P6, P7, P8),
			C *classPtr, char *fname) :
	ProvidedMethod<RetType> (8) {
		this->m_name = fname;

		this->memberFunction = reinterpret_cast<GenericMemberFunc> (function);

		this->mmPtr = reinterpret_cast<GenericClass *> (classPtr);
	}

	template<typename R, typename P1, typename P2, typename P3, typename P4,
	typename P5, typename P6, typename P7, typename P8>
	ProvidedMethod_8(R(*function)(P1, P2, P3, P4, P5, P6, P7, P8), char *fname) :
	ProvidedMethod<RetType> (8) {
		this->m_name = fname;

		this->memberFunction = NULL;

		this->mmPtr = NULL;

		this->functionPtr = reinterpret_cast<functionType> (function);
	}
};

template<typename RetType, typename PA1, typename PA2, typename PA3,
		typename PA4, typename PA5, typename PA6, typename PA7, typename PA8,
		typename PA9>
class ProvidedMethod_9: public ProvidedMethod<RetType> {
	typedef RetType (GenericClass::*GenericMemberFunc)();
	typedef RetType (*functionType)();

	template<typename R, typename TPA1, typename TPA2, typename TPA3,
			typename TPA4, typename TPA5, typename TPA6, typename TPA7,
			typename TPA8, typename TPA9>
	inline ReturnType _call(opros::archive::iarchive & in,
			opros::archive::oarchive & out) {
		R resultData;

		TPA1 param1;
		TPA2 param2;
		TPA3 param3;
		TPA4 param4;
		TPA5 param5;
		TPA6 param6;
		TPA7 param7;
		TPA8 param8;
		TPA9 param9;

		in >> OPROS_SERIALIZATION_NVP(param1);
		in >> OPROS_SERIALIZATION_NVP(param2);
		in >> OPROS_SERIALIZATION_NVP(param3);
		in >> OPROS_SERIALIZATION_NVP(param4);
		in >> OPROS_SERIALIZATION_NVP(param5);
		in >> OPROS_SERIALIZATION_NVP(param6);
		in >> OPROS_SERIALIZATION_NVP(param7);
		in >> OPROS_SERIALIZATION_NVP(param8);
		in >> OPROS_SERIALIZATION_NVP(param9);

#ifdef _MSC_VER
		resultData = (*this).operator ()<PA1,PA2,PA3,PA4,PA5,PA6,PA7,PA8,PA9>(param1, param2, param3, param4, param5, param6,
				param7, param8, param9);
#else
		resultData = (*this).template operator ()<PA1,PA2,PA3,PA4,PA5,PA6,PA7,PA8,PA9>(param1, param2, param3, param4, param5, param6,
						param7, param8, param9);
#endif

		out << OPROS_SERIALIZATION_NVP(resultData);

		return OPROS_SUCCESS;
	}
public:

	virtual ReturnType call(opros::archive::iarchive & in,
			opros::archive::oarchive & out) {
		return _call<typename opros::remove_const<
		typename opros::remove_reference<RetType>::type>::type,
		typename opros::remove_const<typename opros::remove_reference<
		PA1>::type>::type, typename opros::remove_const<
		typename opros::remove_reference<PA2>::type>::type,
		typename opros::remove_const<typename opros::remove_reference<
		PA3>::type>::type, typename opros::remove_const<
		typename opros::remove_reference<PA4>::type>::type,
		typename opros::remove_const<typename opros::remove_reference<
		PA5>::type>::type, typename opros::remove_const<
		typename opros::remove_reference<PA6>::type>::type,
		typename opros::remove_const<typename opros::remove_reference<
		PA7>::type>::type, typename opros::remove_const<
		typename opros::remove_reference<PA8>::type>::type,
		typename opros::remove_const<typename opros::remove_reference<
		PA9>::type>::type> (in, out);
	}

	template<typename R, typename P1, typename P2, typename P3, typename P4,
	typename P5, typename P6, typename P7, typename P8, typename P9,
	typename C>
	ProvidedMethod_9(R(C::* function)(P1, P2, P3, P4, P5, P6, P7, P8, P9),
			C *classPtr, char *fname) :
	ProvidedMethod<RetType> (9) {
		this->m_name = fname;

		this->memberFunction = reinterpret_cast<GenericMemberFunc> (function);

		this->mmPtr = reinterpret_cast<GenericClass *> (classPtr);
	}

	template<typename R, typename P1, typename P2, typename P3, typename P4,
	typename P5, typename P6, typename P7, typename P8, typename P9>
	ProvidedMethod_9(R(*function)(P1, P2, P3, P4, P5, P6, P7, P8, P9),
			char *fname) :
	ProvidedMethod<RetType> (9) {
		this->m_name = fname;

		this->memberFunction = NULL;

		this->mmPtr = NULL;

		this->functionPtr = reinterpret_cast<functionType> (function);
	}

};

template<typename RetType, typename PA1, typename PA2, typename PA3,
		typename PA4, typename PA5, typename PA6, typename PA7, typename PA8,
		typename PA9, typename PA10>
class ProvidedMethod_10: public ProvidedMethod<RetType> {
	typedef RetType (GenericClass::*GenericMemberFunc)();
	typedef RetType (*functionType)();

	template<typename R, typename TPA1, typename TPA2, typename TPA3,
			typename TPA4, typename TPA5, typename TPA6, typename TPA7,
			typename TPA8, typename TPA9, typename TPA10>
	inline ReturnType _call(opros::archive::iarchive & in,
			opros::archive::oarchive & out) {
		R resultData;

		TPA1 param1;
		TPA2 param2;
		TPA3 param3;
		TPA4 param4;
		TPA5 param5;
		TPA6 param6;
		TPA7 param7;
		TPA8 param8;
		TPA9 param9;
		TPA10 param10;

		in >> OPROS_SERIALIZATION_NVP(param1);
		in >> OPROS_SERIALIZATION_NVP(param2);
		in >> OPROS_SERIALIZATION_NVP(param3);
		in >> OPROS_SERIALIZATION_NVP(param4);
		in >> OPROS_SERIALIZATION_NVP(param5);
		in >> OPROS_SERIALIZATION_NVP(param6);
		in >> OPROS_SERIALIZATION_NVP(param7);
		in >> OPROS_SERIALIZATION_NVP(param8);
		in >> OPROS_SERIALIZATION_NVP(param9);
		in >> OPROS_SERIALIZATION_NVP(param10);

#ifdef _MSC_VER
		resultData = (*this).operator ()<PA1,PA2,PA3,PA4,PA5,PA6,PA7,PA8,PA9,PA10>(param1, param2, param3, param4, param5, param6,
				param7, param8, param9, param10);
#else
		resultData = (*this).template operator ()<PA1,PA2,PA3,PA4,PA5,PA6,PA7,PA8,PA9,PA10>(param1, param2, param3, param4, param5, param6,
						param7, param8, param9, param10);
#endif

		out << OPROS_SERIALIZATION_NVP(resultData);

		return OPROS_SUCCESS;
	}

public:

	virtual ReturnType call(opros::archive::iarchive & in,
			opros::archive::oarchive & out) {
		return _call<typename opros::remove_const<
		typename opros::remove_reference<RetType>::type>::type,
		typename opros::remove_const<typename opros::remove_reference<
		PA1>::type>::type, typename opros::remove_const<
		typename opros::remove_reference<PA2>::type>::type,
		typename opros::remove_const<typename opros::remove_reference<
		PA3>::type>::type, typename opros::remove_const<
		typename opros::remove_reference<PA4>::type>::type,
		typename opros::remove_const<typename opros::remove_reference<
		PA5>::type>::type, typename opros::remove_const<
		typename opros::remove_reference<PA6>::type>::type,
		typename opros::remove_const<typename opros::remove_reference<
		PA7>::type>::type, typename opros::remove_const<
		typename opros::remove_reference<PA8>::type>::type,
		typename opros::remove_const<typename opros::remove_reference<
		PA9>::type>::type, typename opros::remove_const<
		typename opros::remove_reference<PA10>::type>::type> (
				in, out);
	}

	template<typename R, typename P1, typename P2, typename P3, typename P4,
	typename P5, typename P6, typename P7, typename P8, typename P9,
	typename P10, typename C>
	ProvidedMethod_10(
			R(C::* function)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10),
			C *classPtr, char *fname) :
	ProvidedMethod<RetType> (10) {
		this->m_name = fname;

		this->memberFunction = reinterpret_cast<GenericMemberFunc> (function);

		this->mmPtr = reinterpret_cast<GenericClass *> (classPtr);
	}

	template<typename R, typename P1, typename P2, typename P3, typename P4,
	typename P5, typename P6, typename P7, typename P8, typename P9,
	typename P10>
	ProvidedMethod_10(R(*function)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10),
			char *fname) :
	ProvidedMethod<RetType> (10) {
		this->m_name = fname;

		this->memberFunction = NULL;

		this->mmPtr = NULL;

		this->functionPtr = reinterpret_cast<functionType> (function);
	}
};

template<typename RetType, typename PA1, typename PA2, typename PA3,
		typename PA4, typename PA5, typename PA6, typename PA7, typename PA8,
		typename PA9, typename PA10, typename PA11>
class ProvidedMethod_11: public ProvidedMethod<RetType> {
	typedef RetType (GenericClass::*GenericMemberFunc)();
	typedef RetType (*functionType)();

	template<typename R, typename TPA1, typename TPA2, typename TPA3,
			typename TPA4, typename TPA5, typename TPA6, typename TPA7,
			typename TPA8, typename TPA9, typename TPA10, typename TPA11>
	inline ReturnType _call(opros::archive::iarchive & in,
			opros::archive::oarchive & out) {
		R resultData;

		TPA1 param1;
		TPA2 param2;
		TPA3 param3;
		TPA4 param4;
		TPA5 param5;
		TPA6 param6;
		TPA7 param7;
		TPA8 param8;
		TPA9 param9;
		TPA10 param10;
		TPA11 param11;

		in >> OPROS_SERIALIZATION_NVP(param1);
		in >> OPROS_SERIALIZATION_NVP(param2);
		in >> OPROS_SERIALIZATION_NVP(param3);
		in >> OPROS_SERIALIZATION_NVP(param4);
		in >> OPROS_SERIALIZATION_NVP(param5);
		in >> OPROS_SERIALIZATION_NVP(param6);
		in >> OPROS_SERIALIZATION_NVP(param7);
		in >> OPROS_SERIALIZATION_NVP(param8);
		in >> OPROS_SERIALIZATION_NVP(param9);
		in >> OPROS_SERIALIZATION_NVP(param10);
		in >> OPROS_SERIALIZATION_NVP(param11);

#ifdef _MSC_VER
		resultData = (*this).operator ()<PA1,PA2,PA3,PA4,PA5,PA6,PA7,PA8,PA9,PA10,PA11>(param1, param2, param3, param4, param5, param6,
				param7, param8, param9, param10, param11);
#else
		resultData = (*this).template operator ()<PA1,PA2,PA3,PA4,PA5,PA6,PA7,PA8,PA9,PA10,PA11>(param1, param2, param3, param4, param5, param6,
				param7, param8, param9, param10, param11);
#endif

		out << OPROS_SERIALIZATION_NVP(resultData);

		return OPROS_SUCCESS;
	}

public:

	virtual ReturnType call(opros::archive::iarchive & in,
			opros::archive::oarchive & out) {
		return _call<typename opros::remove_const<
		typename opros::remove_reference<RetType>::type>::type,
		typename opros::remove_const<typename opros::remove_reference<
		PA1>::type>::type, typename opros::remove_const<
		typename opros::remove_reference<PA2>::type>::type,
		typename opros::remove_const<typename opros::remove_reference<
		PA3>::type>::type, typename opros::remove_const<
		typename opros::remove_reference<PA4>::type>::type,
		typename opros::remove_const<typename opros::remove_reference<
		PA5>::type>::type, typename opros::remove_const<
		typename opros::remove_reference<PA6>::type>::type,
		typename opros::remove_const<typename opros::remove_reference<
		PA7>::type>::type, typename opros::remove_const<
		typename opros::remove_reference<PA8>::type>::type,
		typename opros::remove_const<typename opros::remove_reference<
		PA9>::type>::type, typename opros::remove_const<
		typename opros::remove_reference<PA10>::type>::type,
		typename opros::remove_const<typename opros::remove_reference<
		PA11>::type>::type> (in, out);
	}

	template<typename R, typename P1, typename P2, typename P3, typename P4,
	typename P5, typename P6, typename P7, typename P8, typename P9,
	typename P10, typename P11, typename C>
	ProvidedMethod_11(R(C::* function)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10,
					P11), C *classPtr, char *fname) :
	ProvidedMethod<RetType> (11) {
		this->m_name = fname;

		this->memberFunction = reinterpret_cast<GenericMemberFunc> (function);

		this->mmPtr = reinterpret_cast<GenericClass *> (classPtr);
	}

	template<typename R, typename P1, typename P2, typename P3, typename P4,
	typename P5, typename P6, typename P7, typename P8, typename P9,
	typename P10, typename P11>
	ProvidedMethod_11(
			R(*function)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11),
			char *fname) :
	ProvidedMethod<RetType> (11) {
		this->m_name = fname;

		this->memberFunction = NULL;

		this->mmPtr = NULL;

		this->functionPtr = reinterpret_cast<functionType> (function);
	}
};

template<typename RetType, typename PA1, typename PA2, typename PA3,
		typename PA4, typename PA5, typename PA6, typename PA7, typename PA8,
		typename PA9, typename PA10, typename PA11, typename PA12>
class ProvidedMethod_12: public ProvidedMethod<RetType> {
	typedef RetType (GenericClass::*GenericMemberFunc)();
	typedef RetType (*functionType)();

	template<typename R, typename TPA1, typename TPA2, typename TPA3,
			typename TPA4, typename TPA5, typename TPA6, typename TPA7,
			typename TPA8, typename TPA9, typename TPA10, typename TPA11,
			typename TPA12>
	inline ReturnType _call(opros::archive::iarchive & in,
			opros::archive::oarchive & out) {
		R resultData;

		TPA1 param1;
		TPA2 param2;
		TPA3 param3;
		TPA4 param4;
		TPA5 param5;
		TPA6 param6;
		TPA7 param7;
		TPA8 param8;
		TPA9 param9;
		TPA10 param10;
		TPA11 param11;
		TPA12 param12;

		in >> OPROS_SERIALIZATION_NVP(param1);
		in >> OPROS_SERIALIZATION_NVP(param2);
		in >> OPROS_SERIALIZATION_NVP(param3);
		in >> OPROS_SERIALIZATION_NVP(param4);
		in >> OPROS_SERIALIZATION_NVP(param5);
		in >> OPROS_SERIALIZATION_NVP(param6);
		in >> OPROS_SERIALIZATION_NVP(param7);
		in >> OPROS_SERIALIZATION_NVP(param8);
		in >> OPROS_SERIALIZATION_NVP(param9);
		in >> OPROS_SERIALIZATION_NVP(param10);
		in >> OPROS_SERIALIZATION_NVP(param11);
		in >> OPROS_SERIALIZATION_NVP(param12);

#ifdef _MSC_VER
		resultData = (*this).operator ()<PA1,PA2,PA3,PA4,PA5,PA6,PA7,PA8,PA9,PA10,PA11,PA12>(param1, param2, param3, param4, param5, param6,
						param7, param8, param9, param10, param11, param12);
#else

		resultData = (*this).template operator ()<PA1,PA2,PA3,PA4,PA5,PA6,PA7,PA8,PA9,PA10,PA11,PA12>(param1, param2, param3, param4, param5, param6,
				param7, param8, param9, param10, param11, param12);
#endif

		out << OPROS_SERIALIZATION_NVP(resultData);

		return OPROS_SUCCESS;
	}

public:

	virtual ReturnType call(opros::archive::iarchive & in,
			opros::archive::oarchive & out) {
		return _call<typename opros::remove_const<
		typename opros::remove_reference<RetType>::type>::type,
		typename opros::remove_const<typename opros::remove_reference<
		PA1>::type>::type, typename opros::remove_const<
		typename opros::remove_reference<PA2>::type>::type,
		typename opros::remove_const<typename opros::remove_reference<
		PA3>::type>::type, typename opros::remove_const<
		typename opros::remove_reference<PA4>::type>::type,
		typename opros::remove_const<typename opros::remove_reference<
		PA5>::type>::type, typename opros::remove_const<
		typename opros::remove_reference<PA6>::type>::type,
		typename opros::remove_const<typename opros::remove_reference<
		PA7>::type>::type, typename opros::remove_const<
		typename opros::remove_reference<PA8>::type>::type,
		typename opros::remove_const<typename opros::remove_reference<
		PA9>::type>::type, typename opros::remove_const<
		typename opros::remove_reference<PA10>::type>::type,
		typename opros::remove_const<typename opros::remove_reference<
		PA11>::type>::type, typename opros::remove_const<
		typename opros::remove_reference<PA12>::type>::type> (
				in, out);
	}

	template<typename R, typename P1, typename P2, typename P3, typename P4,
	typename P5, typename P6, typename P7, typename P8, typename P9,
	typename P10, typename P11, typename P12, typename C>
	ProvidedMethod_12(R(C::* function)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10,
					P11, P12), C *classPtr, char *fname) :
	ProvidedMethod<RetType> (12) {
		this->m_name = fname;

		this->memberFunction = reinterpret_cast<GenericMemberFunc> (function);

		this->mmPtr = reinterpret_cast<GenericClass *> (classPtr);
	}

	template<typename R, typename P1, typename P2, typename P3, typename P4,
	typename P5, typename P6, typename P7, typename P8, typename P9,
	typename P10, typename P11, typename P12>
	ProvidedMethod_12(R(*function)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10,
					P11, P12), char *fname) :
	ProvidedMethod<RetType> (12) {
		this->m_name = fname;

		this->memberFunction = NULL;

		this->mmPtr = NULL;

		this->functionPtr = reinterpret_cast<functionType> (function);
	}
};

template<typename RetType, typename PA1, typename PA2, typename PA3,
		typename PA4, typename PA5, typename PA6, typename PA7, typename PA8,
		typename PA9, typename PA10, typename PA11, typename PA12,
		typename PA13>
class ProvidedMethod_13: public ProvidedMethod<RetType> {
	typedef RetType (GenericClass::*GenericMemberFunc)();
	typedef RetType (*functionType)();

	template<typename R, typename TPA1, typename TPA2, typename TPA3,
			typename TPA4, typename TPA5, typename TPA6, typename TPA7,
			typename TPA8, typename TPA9, typename TPA10, typename TPA11,
			typename TPA12, typename TPA13>
	inline ReturnType _call(opros::archive::iarchive & in,
			opros::archive::oarchive & out) {
		R resultData;

		TPA1 param1;
		TPA2 param2;
		TPA3 param3;
		TPA4 param4;
		TPA5 param5;
		TPA6 param6;
		TPA7 param7;
		TPA8 param8;
		TPA9 param9;
		TPA10 param10;
		TPA11 param11;
		TPA12 param12;
		TPA13 param13;

		in >> OPROS_SERIALIZATION_NVP(param1);
		in >> OPROS_SERIALIZATION_NVP(param2);
		in >> OPROS_SERIALIZATION_NVP(param3);
		in >> OPROS_SERIALIZATION_NVP(param4);
		in >> OPROS_SERIALIZATION_NVP(param5);
		in >> OPROS_SERIALIZATION_NVP(param6);
		in >> OPROS_SERIALIZATION_NVP(param7);
		in >> OPROS_SERIALIZATION_NVP(param8);
		in >> OPROS_SERIALIZATION_NVP(param9);
		in >> OPROS_SERIALIZATION_NVP(param10);
		in >> OPROS_SERIALIZATION_NVP(param11);
		in >> OPROS_SERIALIZATION_NVP(param12);
		in >> OPROS_SERIALIZATION_NVP(param13);

#ifdef _MSC_VER
		resultData = (*this).operator ()<PA1,PA2,PA3,PA4,PA5,PA6,PA7,PA8,PA9,PA10,PA11,PA12,PA13>(param1, param2, param3, param4, param5, param6,
				param7, param8, param9, param10, param11, param12, param13);
#else
		resultData = (*this).template operator ()<PA1,PA2,PA3,PA4,PA5,PA6,PA7,PA8,PA9,PA10,PA11,PA12,PA13>(param1, param2, param3, param4, param5, param6,
				param7, param8, param9, param10, param11, param12, param13);
#endif

		out << OPROS_SERIALIZATION_NVP(resultData);

		return OPROS_SUCCESS;
	}

public:

	virtual ReturnType call(opros::archive::iarchive & in,
			opros::archive::oarchive & out) {
		return _call<typename opros::remove_const<
		typename opros::remove_reference<RetType>::type>::type,
		typename opros::remove_const<typename opros::remove_reference<
		PA1>::type>::type, typename opros::remove_const<
		typename opros::remove_reference<PA2>::type>::type,
		typename opros::remove_const<typename opros::remove_reference<
		PA3>::type>::type, typename opros::remove_const<
		typename opros::remove_reference<PA4>::type>::type,
		typename opros::remove_const<typename opros::remove_reference<
		PA5>::type>::type, typename opros::remove_const<
		typename opros::remove_reference<PA6>::type>::type,
		typename opros::remove_const<typename opros::remove_reference<
		PA7>::type>::type, typename opros::remove_const<
		typename opros::remove_reference<PA8>::type>::type,
		typename opros::remove_const<typename opros::remove_reference<
		PA9>::type>::type, typename opros::remove_const<
		typename opros::remove_reference<PA10>::type>::type,
		typename opros::remove_const<typename opros::remove_reference<
		PA11>::type>::type, typename opros::remove_const<
		typename opros::remove_reference<PA12>::type>::type,
		typename opros::remove_const<typename opros::remove_reference<
		PA13>::type>::type> (in, out);
	}

	template<typename R, typename P1, typename P2, typename P3, typename P4,
	typename P5, typename P6, typename P7, typename P8, typename P9,
	typename P10, typename P11, typename P12, typename P13, typename C>
	ProvidedMethod_13(R(C::* function)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10,
					P11, P12, P13), C *classPtr, char *fname) :
	ProvidedMethod<RetType> (13) {
		this->m_name = fname;

		this->memberFunction = reinterpret_cast<GenericMemberFunc> (function);

		this->mmPtr = reinterpret_cast<GenericClass *> (classPtr);
	}

	template<typename R, typename P1, typename P2, typename P3, typename P4,
	typename P5, typename P6, typename P7, typename P8, typename P9,
	typename P10, typename P11, typename P12, typename P13>
	ProvidedMethod_13(R(*function)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10,
					P11, P12, P13), char *fname) :
	ProvidedMethod<RetType> (13) {
		this->m_name = fname;

		this->memberFunction = NULL;

		this->mmPtr = NULL;

		this->functionPtr = reinterpret_cast<functionType> (function);
	}
};

template<typename RetType, typename PA1, typename PA2, typename PA3,
		typename PA4, typename PA5, typename PA6, typename PA7, typename PA8,
		typename PA9, typename PA10, typename PA11, typename PA12,
		typename PA13, typename PA14>
class ProvidedMethod_14: public ProvidedMethod<RetType> {
	typedef RetType (GenericClass::*GenericMemberFunc)();
	typedef RetType (*functionType)();

	template<typename R, typename TPA1, typename TPA2, typename TPA3,
			typename TPA4, typename TPA5, typename TPA6, typename TPA7,
			typename TPA8, typename TPA9, typename TPA10, typename TPA11,
			typename TPA12, typename TPA13, typename TPA14>
	inline ReturnType _call(opros::archive::iarchive & in,
			opros::archive::oarchive & out) {
		R resultData;

		TPA1 param1;
		TPA2 param2;
		TPA3 param3;
		TPA4 param4;
		TPA5 param5;
		TPA6 param6;
		TPA7 param7;
		TPA8 param8;
		TPA9 param9;
		TPA10 param10;
		TPA11 param11;
		TPA12 param12;
		TPA13 param13;
		TPA14 param14;

		in >> OPROS_SERIALIZATION_NVP(param1);
		in >> OPROS_SERIALIZATION_NVP(param2);
		in >> OPROS_SERIALIZATION_NVP(param3);
		in >> OPROS_SERIALIZATION_NVP(param4);
		in >> OPROS_SERIALIZATION_NVP(param5);
		in >> OPROS_SERIALIZATION_NVP(param6);
		in >> OPROS_SERIALIZATION_NVP(param7);
		in >> OPROS_SERIALIZATION_NVP(param8);
		in >> OPROS_SERIALIZATION_NVP(param9);
		in >> OPROS_SERIALIZATION_NVP(param10);
		in >> OPROS_SERIALIZATION_NVP(param11);
		in >> OPROS_SERIALIZATION_NVP(param12);
		in >> OPROS_SERIALIZATION_NVP(param13);
		in >> OPROS_SERIALIZATION_NVP(param14);

#ifdef _MSC_VER
		resultData = (*this).operator ()<PA1,PA2,PA3,PA4,PA5,PA6,PA7,PA8,PA9,PA10,PA11,PA12,PA13,PA14>(param1, param2, param3, param4, param5, param6,
				param7, param8, param9, param10, param11, param12, param13,
				param14);
#else

		resultData = (*this).template operator ()<PA1,PA2,PA3,PA4,PA5,PA6,PA7,PA8,PA9,PA10,PA11,PA12,PA13,PA14>(param1, param2, param3, param4, param5, param6,
				param7, param8, param9, param10, param11, param12, param13,
				param14);
#endif
		out << OPROS_SERIALIZATION_NVP(resultData);

		return OPROS_SUCCESS;
	}

public:

	virtual ReturnType call(opros::archive::iarchive & in,
			opros::archive::oarchive & out) {
		return _call<typename opros::remove_const<
		typename opros::remove_reference<RetType>::type>::type,
		typename opros::remove_const<typename opros::remove_reference<
		PA1>::type>::type, typename opros::remove_const<
		typename opros::remove_reference<PA2>::type>::type,
		typename opros::remove_const<typename opros::remove_reference<
		PA3>::type>::type, typename opros::remove_const<
		typename opros::remove_reference<PA4>::type>::type,
		typename opros::remove_const<typename opros::remove_reference<
		PA5>::type>::type, typename opros::remove_const<
		typename opros::remove_reference<PA6>::type>::type,
		typename opros::remove_const<typename opros::remove_reference<
		PA7>::type>::type, typename opros::remove_const<
		typename opros::remove_reference<PA8>::type>::type,
		typename opros::remove_const<typename opros::remove_reference<
		PA9>::type>::type, typename opros::remove_const<
		typename opros::remove_reference<PA10>::type>::type,
		typename opros::remove_const<typename opros::remove_reference<
		PA11>::type>::type, typename opros::remove_const<
		typename opros::remove_reference<PA12>::type>::type,
		typename opros::remove_const<typename opros::remove_reference<
		PA13>::type>::type, typename opros::remove_const<
		typename opros::remove_reference<PA14>::type>::type> (
				in, out);
	}

	template<typename R, typename P1, typename P2, typename P3, typename P4,
	typename P5, typename P6, typename P7, typename P8, typename P9,
	typename P10, typename P11, typename P12, typename P13,
	typename P14, typename C>
	ProvidedMethod_14(R(C::* function)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10,
					P11, P12, P13, P14), C *classPtr, char *fname) :
	ProvidedMethod<RetType> (14) {
		this->m_name = fname;

		this->memberFunction = reinterpret_cast<GenericMemberFunc> (function);

		this->mmPtr = reinterpret_cast<GenericClass *> (classPtr);
	}

	template<typename R, typename P1, typename P2, typename P3, typename P4,
	typename P5, typename P6, typename P7, typename P8, typename P9,
	typename P10, typename P11, typename P12, typename P13,
	typename P14>
	ProvidedMethod_14(R(*function)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10,
					P11, P12, P13, P14), char *fname) :
	ProvidedMethod<RetType> (14) {
		this->m_name = fname;

		this->memberFunction = NULL;

		this->mmPtr = NULL;

		this->functionPtr = reinterpret_cast<functionType> (function);
	}
};

template<typename RetType, typename PA1, typename PA2, typename PA3,
		typename PA4, typename PA5, typename PA6, typename PA7, typename PA8,
		typename PA9, typename PA10, typename PA11, typename PA12,
		typename PA13, typename PA14, typename PA15>
class ProvidedMethod_15: public ProvidedMethod<RetType> {
	typedef RetType (GenericClass::*GenericMemberFunc)();
	typedef RetType (*functionType)();

	template<typename R, typename TPA1, typename TPA2, typename TPA3,
			typename TPA4, typename TPA5, typename TPA6, typename TPA7,
			typename TPA8, typename TPA9, typename TPA10, typename TPA11,
			typename TPA12, typename TPA13, typename TPA14, typename TPA15>
	inline ReturnType _call(opros::archive::iarchive & in,
			opros::archive::oarchive & out) {
		R resultData;

		TPA1 param1;
		TPA2 param2;
		TPA3 param3;
		TPA4 param4;
		TPA5 param5;
		TPA6 param6;
		TPA7 param7;
		TPA8 param8;
		TPA9 param9;
		TPA10 param10;
		TPA11 param11;
		TPA12 param12;
		TPA13 param13;
		TPA14 param14;
		TPA15 param15;

		in >> OPROS_SERIALIZATION_NVP(param1);
		in >> OPROS_SERIALIZATION_NVP(param2);
		in >> OPROS_SERIALIZATION_NVP(param3);
		in >> OPROS_SERIALIZATION_NVP(param4);
		in >> OPROS_SERIALIZATION_NVP(param5);
		in >> OPROS_SERIALIZATION_NVP(param6);
		in >> OPROS_SERIALIZATION_NVP(param7);
		in >> OPROS_SERIALIZATION_NVP(param8);
		in >> OPROS_SERIALIZATION_NVP(param9);
		in >> OPROS_SERIALIZATION_NVP(param10);
		in >> OPROS_SERIALIZATION_NVP(param11);
		in >> OPROS_SERIALIZATION_NVP(param12);
		in >> OPROS_SERIALIZATION_NVP(param13);
		in >> OPROS_SERIALIZATION_NVP(param14);
		in >> OPROS_SERIALIZATION_NVP(param15);

#ifdef _MSC_VER
		resultData
				= (*this).operator ()<PA1,PA2,PA3,PA4,PA5,PA6,PA7,PA8,PA9,PA10,PA11,PA12,PA13,PA14,PA15>(param1, param2, param3, param4, param5, param6,
						param7, param8, param9, param10, param11, param12, param13,
						param14, param15);
#else

		resultData
				= (*this).template operator ()<PA1,PA2,PA3,PA4,PA5,PA6,PA7,PA8,PA9,PA10,PA11,PA12,PA13,PA14,PA15>(param1, param2, param3, param4, param5, param6,
						param7, param8, param9, param10, param11, param12, param13,
						param14, param15);

				out << OPROS_SERIALIZATION_NVP(resultData);
#endif

				return OPROS_SUCCESS;
			}
		public:

			virtual ReturnType call(opros::archive::iarchive & in,
					opros::archive::oarchive & out) {
				return _call<typename opros::remove_const<
				typename opros::remove_reference<RetType>::type>::type,
				typename opros::remove_const<typename opros::remove_reference<
				PA1>::type>::type, typename opros::remove_const<
				typename opros::remove_reference<PA2>::type>::type,
				typename opros::remove_const<typename opros::remove_reference<
				PA3>::type>::type, typename opros::remove_const<
				typename opros::remove_reference<PA4>::type>::type,
				typename opros::remove_const<typename opros::remove_reference<
				PA5>::type>::type, typename opros::remove_const<
				typename opros::remove_reference<PA6>::type>::type,
				typename opros::remove_const<typename opros::remove_reference<
				PA7>::type>::type, typename opros::remove_const<
				typename opros::remove_reference<PA8>::type>::type,
				typename opros::remove_const<typename opros::remove_reference<
				PA9>::type>::type, typename opros::remove_const<
				typename opros::remove_reference<PA10>::type>::type,
				typename opros::remove_const<typename opros::remove_reference<
				PA11>::type>::type, typename opros::remove_const<
				typename opros::remove_reference<PA12>::type>::type,
				typename opros::remove_const<typename opros::remove_reference<
				PA13>::type>::type, typename opros::remove_const<
				typename opros::remove_reference<PA14>::type>::type,
				typename opros::remove_const<typename opros::remove_reference<
				PA15>::type>::type> (in, out);
			}

			template<typename R, typename P1, typename P2, typename P3, typename P4,
			typename P5, typename P6, typename P7, typename P8, typename P9,
			typename P10, typename P11, typename P12, typename P13,
			typename P14, typename P15, typename C>
			ProvidedMethod_15(R(C::* function)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10,
							P11, P12, P13, P14, P15), C *classPtr, char *fname) :
			ProvidedMethod<RetType> (15) {
				this->m_name = fname;

				this->memberFunction = reinterpret_cast<GenericMemberFunc> (function);

				this->mmPtr = reinterpret_cast<GenericClass *> (classPtr);
			}

			template<typename R, typename P1, typename P2, typename P3, typename P4,
			typename P5, typename P6, typename P7, typename P8, typename P9,
			typename P10, typename P11, typename P12, typename P13,
			typename P14, typename P15>
			ProvidedMethod_15(R(*function)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10,
							P11, P12, P13, P14, P15), char *fname) :
			ProvidedMethod<RetType> (15) {
				this->m_name = fname;

				this->memberFunction = NULL;

				this->mmPtr = NULL;

				this->functionPtr = reinterpret_cast<functionType> (function);
			}
		};
		// void functions-------------
template<>
class ProvidedMethod_0<void> : public ProvidedMethod<void> {
	typedef void (GenericClass::*GenericMemberFunc)();
	typedef void (*functionType)();
public:

	virtual ReturnType call(opros::archive::iarchive & in,
			opros::archive::oarchive & out) {
		ProvidedMethod<void> *ptr = this;

		(*ptr)();

		return OPROS_SUCCESS;
	}

	template<typename R, typename C>
	ProvidedMethod_0(R(C::* function)(), C *classPtr, char *fname) :
		ProvidedMethod<void> (0) {
		this->m_name = fname;

		this->memberFunction = reinterpret_cast<GenericMemberFunc> (function);

		this->mmPtr = reinterpret_cast<GenericClass *> (classPtr);
	}

	template<typename R>
	ProvidedMethod_0(R(*function)(), char *fname) :
		ProvidedMethod<void> (0) {
		this->m_name = fname;

		this->memberFunction = NULL;

		this->mmPtr = NULL;

		this->functionPtr = reinterpret_cast<functionType> (function);
	}
};

template<typename PA1>
class ProvidedMethod_1<void, PA1> : public ProvidedMethod<void> {
	typedef void (GenericClass::*GenericMemberFunc)();
	typedef void (*functionType)();

	template<typename TPA1>
	inline ReturnType _call(opros::archive::iarchive & in,
			opros::archive::oarchive & out) {
		TPA1 param1;

		in >> OPROS_SERIALIZATION_NVP(param1);

#ifdef _MSC_VER
		(*this).operator ()<PA1>(param1);
#else
		(*this).template operator ()<PA1>(param1);
#endif

		return OPROS_SUCCESS;
	}

public:

	virtual ReturnType call(opros::archive::iarchive & in,
			opros::archive::oarchive & out) {
		return _call<typename opros::remove_const<
		typename opros::remove_reference<PA1>::type>::type> (in, out);
	}

	template<typename R, typename P1, typename C>
	ProvidedMethod_1(R(C::* function)(P1), C *classPtr, char *fname) :
	ProvidedMethod<void> (1) {
		this->m_name = fname;

		this->memberFunction = reinterpret_cast<GenericMemberFunc> (function);

		this->mmPtr = reinterpret_cast<GenericClass *> (classPtr);
	}

	template<typename R, typename P1>
	ProvidedMethod_1(R(*function)(P1), char *fname) :
	ProvidedMethod<void> (1) {
		this->m_name = fname;

		this->memberFunction = NULL;

		this->mmPtr = NULL;

		this->functionPtr = reinterpret_cast<functionType> (function);
	}
};

template<typename PA1, typename PA2>
class ProvidedMethod_2<void, PA1, PA2> : public ProvidedMethod<void> {
	typedef void (GenericClass::*GenericMemberFunc)();
	typedef void (*functionType)();

	template<typename TPA1, typename TPA2>
	inline ReturnType _call(opros::archive::iarchive & in,
			opros::archive::oarchive & out) {

		TPA1 param1;
		TPA2 param2;

		in >> OPROS_SERIALIZATION_NVP(param1);
		in >> OPROS_SERIALIZATION_NVP(param2);

#ifdef _MSC_VER
		(*this).operator ()<PA1,PA2>(param1, param2);
#else
		(*this).template operator ()<PA1,PA2>(param1, param2);
#endif
		return OPROS_SUCCESS;
	}
public:

	virtual ReturnType call(opros::archive::iarchive & in,
			opros::archive::oarchive & out) {

		return _call<typename opros::remove_const<
		typename opros::remove_reference<PA1>::type>::type,
		typename opros::remove_const<typename opros::remove_reference<
		PA2>::type>::type> (in, out);
	}

	template<typename R, typename P1, typename P2, typename C>
	ProvidedMethod_2(R(C::* function)(P1, P2), C *classPtr, char *fname) :
	ProvidedMethod<void> (2) {
		this->m_name = fname;

		this->memberFunction = reinterpret_cast<GenericMemberFunc> (function);

		this->mmPtr = reinterpret_cast<GenericClass *> (classPtr);
	}

	template<typename R, typename P1, typename P2>
	ProvidedMethod_2(R(*function)(P1, P2), char *fname) :
	ProvidedMethod<void> (2) {
		this->m_name = fname;

		this->memberFunction = NULL;

		this->mmPtr = NULL;

		this->functionPtr = reinterpret_cast<functionType> (function);
	}

};

template<typename PA1, typename PA2, typename PA3>
class ProvidedMethod_3<void, PA1, PA2, PA3> : public ProvidedMethod<void> {
	typedef void (GenericClass::*GenericMemberFunc)();
	typedef void (*functionType)();

	template<typename TPA1, typename TPA2, typename TPA3>
	inline ReturnType _call(opros::archive::iarchive & in,
			opros::archive::oarchive & out) {

		TPA1 param1;
		TPA2 param2;
		TPA3 param3;

		in >> OPROS_SERIALIZATION_NVP(param1);
		in >> OPROS_SERIALIZATION_NVP(param2);
		in >> OPROS_SERIALIZATION_NVP(param3);

#ifdef _MSC_VER
		(*this).operator ()<PA1,PA2,PA3>(param1, param2, param3);
#else
		(*this).template operator ()<PA1,PA2,PA3>(param1, param2, param3);
#endif

		return OPROS_SUCCESS;
	}
public:

	virtual ReturnType call(opros::archive::iarchive & in,
			opros::archive::oarchive & out) {

		return _call<typename opros::remove_const<
		typename opros::remove_reference<PA1>::type>::type,
		typename opros::remove_const<typename opros::remove_reference<
		PA2>::type>::type, typename opros::remove_const<
		typename opros::remove_reference<PA3>::type>::type> (
				in, out);
	}

	template<typename R, typename P1, typename P2, typename P3, typename C>
	ProvidedMethod_3(R(C::* function)(P1, P2, P3), C *classPtr, char *fname) :
	ProvidedMethod<void> (3) {
		this->m_name = fname;

		this->memberFunction = reinterpret_cast<GenericMemberFunc> (function);

		this->mmPtr = reinterpret_cast<GenericClass *> (classPtr);
	}

	template<typename R, typename P1, typename P2, typename P3>
	ProvidedMethod_3(R(*function)(P1, P2, P3), char *fname) :
	ProvidedMethod<void> (3) {
		this->m_name = fname;

		this->memberFunction = NULL;

		this->mmPtr = NULL;

		this->functionPtr = reinterpret_cast<functionType> (function);
	}
};

template<typename PA1, typename PA2, typename PA3, typename PA4>
class ProvidedMethod_4<void, PA1, PA2, PA3, PA4> : public ProvidedMethod<void> {
	typedef void (GenericClass::*GenericMemberFunc)();
	typedef void (*functionType)();

	template<typename TPA1, typename TPA2, typename TPA3, typename TPA4>
	inline ReturnType _call(opros::archive::iarchive & in,
			opros::archive::oarchive & out) {

		TPA1 param1;
		TPA2 param2;
		TPA3 param3;
		TPA4 param4;

		in >> OPROS_SERIALIZATION_NVP(param1);
		in >> OPROS_SERIALIZATION_NVP(param2);
		in >> OPROS_SERIALIZATION_NVP(param3);
		in >> OPROS_SERIALIZATION_NVP(param4);

#ifdef _MSC_VER
		(*this).operator ()<PA1,PA2,PA3,PA4>(param1, param2, param3, param4);
#else

		(*this).template operator ()<PA1,PA2,PA3,PA4>(param1, param2, param3, param4);
#endif

		return OPROS_SUCCESS;

	}

public:

	virtual ReturnType call(opros::archive::iarchive & in,
			opros::archive::oarchive & out) {

		return _call<typename opros::remove_const<
		typename opros::remove_reference<PA1>::type>::type,
		typename opros::remove_const<typename opros::remove_reference<
		PA2>::type>::type, typename opros::remove_const<
		typename opros::remove_reference<PA3>::type>::type,
		typename opros::remove_const<typename opros::remove_reference<
		PA4>::type>::type> (in, out);

	}

	template<typename R, typename P1, typename P2, typename P3, typename P4,
	typename C>
	ProvidedMethod_4(R(C::* function)(P1, P2, P3, P4), C *classPtr, char *fname) :
	ProvidedMethod<void> (4) {
		this->m_name = fname;

		this->memberFunction = reinterpret_cast<GenericMemberFunc> (function);

		this->mmPtr = reinterpret_cast<GenericClass *> (classPtr);
	}

	template<typename R, typename P1, typename P2, typename P3, typename P4>
	ProvidedMethod_4(R(*function)(P1, P2, P3, P4), char *fname) :
	ProvidedMethod<void> (4) {
		this->m_name = fname;

		this->memberFunction = NULL;

		this->mmPtr = NULL;

		this->functionPtr = reinterpret_cast<functionType> (function);
	}
};

template<typename PA1, typename PA2, typename PA3, typename PA4, typename PA5>
class ProvidedMethod_5<void, PA1, PA2, PA3, PA4, PA5> : public ProvidedMethod<
		void> {
	typedef void (GenericClass::*GenericMemberFunc)();
	typedef void (*functionType)();

	template<typename TPA1, typename TPA2, typename TPA3, typename TPA4,
			typename TPA5>
	inline ReturnType _call(opros::archive::iarchive & in,
			opros::archive::oarchive & out) {

		TPA1 param1;
		TPA2 param2;
		TPA3 param3;
		TPA4 param4;
		TPA5 param5;

		in >> OPROS_SERIALIZATION_NVP(param1);
		in >> OPROS_SERIALIZATION_NVP(param2);
		in >> OPROS_SERIALIZATION_NVP(param3);
		in >> OPROS_SERIALIZATION_NVP(param4);
		in >> OPROS_SERIALIZATION_NVP(param5);

#ifdef _MSC_VER
		(*this).operator ()<PA1,PA2,PA3,PA4,PA5>(param1, param2, param3, param4, param5);
#else
		(*this).template operator ()<PA1,PA2,PA3,PA4,PA5>(param1, param2, param3, param4, param5);
#endif

		return OPROS_SUCCESS;
	}

public:

	virtual ReturnType call(opros::archive::iarchive & in,
			opros::archive::oarchive & out) {

		return _call<typename opros::remove_const<
		typename opros::remove_reference<PA1>::type>::type,
		typename opros::remove_const<typename opros::remove_reference<
		PA2>::type>::type, typename opros::remove_const<
		typename opros::remove_reference<PA3>::type>::type,
		typename opros::remove_const<typename opros::remove_reference<
		PA4>::type>::type, typename opros::remove_const<
		typename opros::remove_reference<PA5>::type>::type> (
				in, out);
	}

	template<typename R, typename P1, typename P2, typename P3, typename P4,
	typename P5, typename C>
	ProvidedMethod_5(R(C::* function)(P1, P2, P3, P4, P5), C *classPtr,
			char *fname) :
	ProvidedMethod<void> (5) {
		this->m_name = fname;

		this->memberFunction = reinterpret_cast<GenericMemberFunc> (function);

		this->mmPtr = reinterpret_cast<GenericClass *> (classPtr);
	}

	template<typename R, typename P1, typename P2, typename P3, typename P4,
	typename P5>
	ProvidedMethod_5(R(*function)(P1, P2, P3, P4, P5), char *fname) :
	ProvidedMethod<void> (5) {
		this->m_name = fname;

		this->memberFunction = NULL;

		this->mmPtr = NULL;

		this->functionPtr = reinterpret_cast<functionType> (function);
	}
};

template<typename PA1, typename PA2, typename PA3, typename PA4, typename PA5,
		typename PA6>
class ProvidedMethod_6<void, PA1, PA2, PA3, PA4, PA5, PA6> : public ProvidedMethod<
		void> {
	typedef void (GenericClass::*GenericMemberFunc)();
	typedef void (*functionType)();

	template<typename TPA1, typename TPA2, typename TPA3, typename TPA4,
			typename TPA5, typename TPA6>
	inline ReturnType _call(opros::archive::iarchive & in,
			opros::archive::oarchive & out) {

		TPA1 param1;
		TPA2 param2;
		TPA3 param3;
		TPA4 param4;
		TPA5 param5;
		TPA6 param6;

		in >> OPROS_SERIALIZATION_NVP(param1);
		in >> OPROS_SERIALIZATION_NVP(param2);
		in >> OPROS_SERIALIZATION_NVP(param3);
		in >> OPROS_SERIALIZATION_NVP(param4);
		in >> OPROS_SERIALIZATION_NVP(param5);
		in >> OPROS_SERIALIZATION_NVP(param6);

#ifdef _MSC_VER
		(*this).operator ()<PA1,PA2,PA3,PA4,PA5,PA6>(param1, param2, param3, param4, param5, param6);
#else
		(*this).template operator ()<PA1,PA2,PA3,PA4,PA5,PA6>(param1, param2, param3, param4, param5, param6);
#endif

		return OPROS_SUCCESS;
	}

public:

	virtual ReturnType call(opros::archive::iarchive & in,
			opros::archive::oarchive & out) {

		return _call<typename opros::remove_const<
		typename opros::remove_reference<PA1>::type>::type,
		typename opros::remove_const<typename opros::remove_reference<
		PA2>::type>::type, typename opros::remove_const<
		typename opros::remove_reference<PA3>::type>::type,
		typename opros::remove_const<typename opros::remove_reference<
		PA4>::type>::type, typename opros::remove_const<
		typename opros::remove_reference<PA5>::type>::type,
		typename opros::remove_const<typename opros::remove_reference<
		PA6>::type>::type> (in, out);
	}

	template<typename R, typename P1, typename P2, typename P3, typename P4,
	typename P5, typename P6, typename C>
	ProvidedMethod_6(R(C::* function)(P1, P2, P3, P4, P5, P6), C *classPtr,
			char *fname) :
	ProvidedMethod<void> (6) {
		this->m_name = fname;

		this->memberFunction = reinterpret_cast<GenericMemberFunc> (function);

		this->mmPtr = reinterpret_cast<GenericClass *> (classPtr);
	}

	template<typename R, typename P1, typename P2, typename P3, typename P4,
	typename P5, typename P6>
	ProvidedMethod_6(R(*function)(P1, P2, P3, P4, P5, P6), char *fname) :
	ProvidedMethod<void> (6) {
		this->m_name = fname;

		this->memberFunction = NULL;

		this->mmPtr = NULL;

		this->functionPtr = reinterpret_cast<functionType> (function);
	}
};

template<typename PA1, typename PA2, typename PA3, typename PA4, typename PA5,
		typename PA6, typename PA7>
class ProvidedMethod_7<void, PA1, PA2, PA3, PA4, PA5, PA6, PA7> : public ProvidedMethod<
		void> {
	typedef void (GenericClass::*GenericMemberFunc)();
	typedef void (*functionType)();

	template<typename TPA1, typename TPA2, typename TPA3, typename TPA4,
			typename TPA5, typename TPA6, typename TPA7>
	inline ReturnType _call(opros::archive::iarchive & in,
			opros::archive::oarchive & out) {

		TPA1 param1;
		TPA2 param2;
		TPA3 param3;
		TPA4 param4;
		TPA5 param5;
		TPA6 param6;
		TPA7 param7;

		in >> OPROS_SERIALIZATION_NVP(param1);
		in >> OPROS_SERIALIZATION_NVP(param2);
		in >> OPROS_SERIALIZATION_NVP(param3);
		in >> OPROS_SERIALIZATION_NVP(param4);
		in >> OPROS_SERIALIZATION_NVP(param5);
		in >> OPROS_SERIALIZATION_NVP(param6);
		in >> OPROS_SERIALIZATION_NVP(param7);

#ifdef _MSC_VER
		(*this).operator ()<PA1,PA2,PA3,PA4,PA5,PA6,PA7>(param1, param2, param3, param4, param5, param6, param7);
#else
		(*this).template operator ()<PA1,PA2,PA3,PA4,PA5,PA6,PA7>(param1, param2, param3, param4, param5, param6, param7);
#endif

		return OPROS_SUCCESS;

	}

public:

	virtual ReturnType call(opros::archive::iarchive & in,
			opros::archive::oarchive & out) {

		return _call<typename opros::remove_const<
		typename opros::remove_reference<PA1>::type>::type,
		typename opros::remove_const<typename opros::remove_reference<
		PA2>::type>::type, typename opros::remove_const<
		typename opros::remove_reference<PA3>::type>::type,
		typename opros::remove_const<typename opros::remove_reference<
		PA4>::type>::type, typename opros::remove_const<
		typename opros::remove_reference<PA5>::type>::type,
		typename opros::remove_const<typename opros::remove_reference<
		PA6>::type>::type, typename opros::remove_const<
		typename opros::remove_reference<PA7>::type>::type> (
				in, out);

	}

	template<typename R, typename P1, typename P2, typename P3, typename P4,
	typename P5, typename P6, typename P7, typename C>
	ProvidedMethod_7(R(C::* function)(P1, P2, P3, P4, P5, P6, P7), C *classPtr,
			char *fname) :
	ProvidedMethod<void> (7) {
		this->m_name = fname;

		this->memberFunction = reinterpret_cast<GenericMemberFunc> (function);

		this->mmPtr = reinterpret_cast<GenericClass *> (classPtr);
	}

	template<typename R, typename P1, typename P2, typename P3, typename P4,
	typename P5, typename P6, typename P7>
	ProvidedMethod_7(R(*function)(P1, P2, P3, P4, P5, P6, P7), char *fname) :
	ProvidedMethod<void> (7) {
		this->m_name = fname;

		this->memberFunction = NULL;

		this->mmPtr = NULL;

		this->functionPtr = reinterpret_cast<functionType> (function);
	}
};

template<typename PA1, typename PA2, typename PA3, typename PA4, typename PA5,
		typename PA6, typename PA7, typename PA8>
class ProvidedMethod_8<void, PA1, PA2, PA3, PA4, PA5, PA6, PA7, PA8> : public ProvidedMethod<
		void> {
	typedef void (GenericClass::*GenericMemberFunc)();
	typedef void (*functionType)();

	template<typename TPA1, typename TPA2, typename TPA3, typename TPA4,
			typename TPA5, typename TPA6, typename TPA7, typename TPA8>
	inline ReturnType _call(opros::archive::iarchive & in,
			opros::archive::oarchive & out) {

		TPA1 param1;
		TPA2 param2;
		TPA3 param3;
		TPA4 param4;
		TPA5 param5;
		TPA6 param6;
		TPA7 param7;
		TPA8 param8;

		in >> OPROS_SERIALIZATION_NVP(param1);
		in >> OPROS_SERIALIZATION_NVP(param2);
		in >> OPROS_SERIALIZATION_NVP(param3);
		in >> OPROS_SERIALIZATION_NVP(param4);
		in >> OPROS_SERIALIZATION_NVP(param5);
		in >> OPROS_SERIALIZATION_NVP(param6);
		in >> OPROS_SERIALIZATION_NVP(param7);
		in >> OPROS_SERIALIZATION_NVP(param8);

#ifdef _MSC_VER
		(*this).operator ()<PA1,PA2,PA3,PA4,PA5,PA6,PA7,PA8>(param1, param2, param3, param4, param5, param6, param7, param8);
#else
		(*this).template operator ()<PA1,PA2,PA3,PA4,PA5,PA6,PA7,PA8>(param1, param2, param3, param4, param5, param6, param7, param8);
#endif

		return OPROS_SUCCESS;
	}

public:

	virtual ReturnType call(opros::archive::iarchive & in,
			opros::archive::oarchive & out) {

		return _call<typename opros::remove_const<
		typename opros::remove_reference<PA1>::type>::type,
		typename opros::remove_const<typename opros::remove_reference<
		PA2>::type>::type, typename opros::remove_const<
		typename opros::remove_reference<PA3>::type>::type,
		typename opros::remove_const<typename opros::remove_reference<
		PA4>::type>::type, typename opros::remove_const<
		typename opros::remove_reference<PA5>::type>::type,
		typename opros::remove_const<typename opros::remove_reference<
		PA6>::type>::type, typename opros::remove_const<
		typename opros::remove_reference<PA7>::type>::type,
		typename opros::remove_const<typename opros::remove_reference<
		PA8>::type>::type> (in, out);

	}

	template<typename R, typename P1, typename P2, typename P3, typename P4,
	typename P5, typename P6, typename P7, typename P8, typename C>
	ProvidedMethod_8(R(C::* function)(P1, P2, P3, P4, P5, P6, P7, P8),
			C *classPtr, char *fname) :
	ProvidedMethod<void> (8) {
		this->m_name = fname;

		this->memberFunction = reinterpret_cast<GenericMemberFunc> (function);

		this->mmPtr = reinterpret_cast<GenericClass *> (classPtr);
	}
	template<typename R, typename P1, typename P2, typename P3, typename P4,
	typename P5, typename P6, typename P7, typename P8>
	ProvidedMethod_8(R(*function)(P1, P2, P3, P4, P5, P6, P7, P8), char *fname) :
	ProvidedMethod<void> (8) {
		this->m_name = fname;

		this->memberFunction = NULL;

		this->mmPtr = NULL;

		this->functionPtr = reinterpret_cast<functionType> (function);
	}
};

template<typename PA1, typename PA2, typename PA3, typename PA4, typename PA5,
		typename PA6, typename PA7, typename PA8, typename PA9>
class ProvidedMethod_9<void, PA1, PA2, PA3, PA4, PA5, PA6, PA7, PA8, PA9> : public ProvidedMethod<
		void> {
	typedef void (GenericClass::*GenericMemberFunc)();
	typedef void (*functionType)();

	template<typename TPA1, typename TPA2, typename TPA3, typename TPA4,
			typename TPA5, typename TPA6, typename TPA7, typename TPA8,
			typename TPA9>
	inline ReturnType _call(opros::archive::iarchive & in,
			opros::archive::oarchive & out) {

		TPA1 param1;
		TPA2 param2;
		TPA3 param3;
		TPA4 param4;
		TPA5 param5;
		TPA6 param6;
		TPA7 param7;
		TPA8 param8;
		TPA9 param9;

		in >> OPROS_SERIALIZATION_NVP(param1);
		in >> OPROS_SERIALIZATION_NVP(param2);
		in >> OPROS_SERIALIZATION_NVP(param3);
		in >> OPROS_SERIALIZATION_NVP(param4);
		in >> OPROS_SERIALIZATION_NVP(param5);
		in >> OPROS_SERIALIZATION_NVP(param6);
		in >> OPROS_SERIALIZATION_NVP(param7);
		in >> OPROS_SERIALIZATION_NVP(param8);
		in >> OPROS_SERIALIZATION_NVP(param9);

#ifdef _MSC_VER
		(*this).operator ()<PA1,PA2,PA3,PA4,PA5,PA6,PA7,PA8,PA9>(param1, param2, param3, param4, param5, param6, param7, param8,
						param9);
#else
		(*this).template operator ()<PA1,PA2,PA3,PA4,PA5,PA6,PA7,PA8,PA9>(param1, param2, param3, param4, param5, param6, param7, param8,
				param9);
#endif

		return OPROS_SUCCESS;

	}

public:

	virtual ReturnType call(opros::archive::iarchive & in,
			opros::archive::oarchive & out) {

		return _call<typename opros::remove_const<
		typename opros::remove_reference<PA1>::type>::type,
		typename opros::remove_const<typename opros::remove_reference<
		PA2>::type>::type, typename opros::remove_const<
		typename opros::remove_reference<PA3>::type>::type,
		typename opros::remove_const<typename opros::remove_reference<
		PA4>::type>::type, typename opros::remove_const<
		typename opros::remove_reference<PA5>::type>::type,
		typename opros::remove_const<typename opros::remove_reference<
		PA6>::type>::type, typename opros::remove_const<
		typename opros::remove_reference<PA7>::type>::type,
		typename opros::remove_const<typename opros::remove_reference<
		PA8>::type>::type, typename opros::remove_const<
		typename opros::remove_reference<PA9>::type>::type> (
				in, out);

	}

	template<typename R, typename P1, typename P2, typename P3, typename P4,
	typename P5, typename P6, typename P7, typename P8, typename P9,
	typename C>
	ProvidedMethod_9(R(C::* function)(P1, P2, P3, P4, P5, P6, P7, P8, P9),
			C *classPtr, char *fname) :
	ProvidedMethod<void> (9) {
		this->m_name = fname;

		this->memberFunction = reinterpret_cast<GenericMemberFunc> (function);

		this->mmPtr = reinterpret_cast<GenericClass *> (classPtr);
	}
	template<typename R, typename P1, typename P2, typename P3, typename P4,
	typename P5, typename P6, typename P7, typename P8, typename P9>
	ProvidedMethod_9(R(*function)(P1, P2, P3, P4, P5, P6, P7, P8, P9),
			char *fname) :
	ProvidedMethod<void> (9) {
		this->m_name = fname;

		this->memberFunction = NULL;

		this->mmPtr = NULL;

		this->functionPtr = reinterpret_cast<functionType> (function);
	}
};

template<typename PA1, typename PA2, typename PA3, typename PA4, typename PA5,
		typename PA6, typename PA7, typename PA8, typename PA9, typename PA10>
class ProvidedMethod_10<void, PA1, PA2, PA3, PA4, PA5, PA6, PA7, PA8, PA9, PA10> : public ProvidedMethod<
		void> {
	typedef void (GenericClass::*GenericMemberFunc)();
	typedef void (*functionType)();

	template<typename TPA1, typename TPA2, typename TPA3, typename TPA4,
			typename TPA5, typename TPA6, typename TPA7, typename TPA8,
			typename TPA9, typename TPA10>
	inline ReturnType _call(opros::archive::iarchive & in,
			opros::archive::oarchive & out) {

		TPA1 param1;
		TPA2 param2;
		TPA3 param3;
		TPA4 param4;
		TPA5 param5;
		TPA6 param6;
		TPA7 param7;
		TPA8 param8;
		TPA9 param9;
		TPA10 param10;

		in >> OPROS_SERIALIZATION_NVP(param1);
		in >> OPROS_SERIALIZATION_NVP(param2);
		in >> OPROS_SERIALIZATION_NVP(param3);
		in >> OPROS_SERIALIZATION_NVP(param4);
		in >> OPROS_SERIALIZATION_NVP(param5);
		in >> OPROS_SERIALIZATION_NVP(param6);
		in >> OPROS_SERIALIZATION_NVP(param7);
		in >> OPROS_SERIALIZATION_NVP(param8);
		in >> OPROS_SERIALIZATION_NVP(param9);
		in >> OPROS_SERIALIZATION_NVP(param10);

#ifdef _MSC_VER
		(*this).operator ()<PA1,PA2,PA3,PA4,PA5,PA6,PA7,PA8,PA9,PA10>(param1, param2, param3, param4, param5, param6, param7, param8,
				param9, param10);
#else
		(*this).template operator ()<PA1,PA2,PA3,PA4,PA5,PA6,PA7,PA8,PA9,PA10>(param1, param2, param3, param4, param5, param6, param7, param8,
						param9, param10);
#endif

		return OPROS_SUCCESS;

	}

public:

	virtual ReturnType call(opros::archive::iarchive & in,
			opros::archive::oarchive & out) {

		return _call<typename opros::remove_const<
		typename opros::remove_reference<PA1>::type>::type,
		typename opros::remove_const<typename opros::remove_reference<
		PA2>::type>::type, typename opros::remove_const<
		typename opros::remove_reference<PA3>::type>::type,
		typename opros::remove_const<typename opros::remove_reference<
		PA4>::type>::type, typename opros::remove_const<
		typename opros::remove_reference<PA5>::type>::type,
		typename opros::remove_const<typename opros::remove_reference<
		PA6>::type>::type, typename opros::remove_const<
		typename opros::remove_reference<PA7>::type>::type,
		typename opros::remove_const<typename opros::remove_reference<
		PA8>::type>::type, typename opros::remove_const<
		typename opros::remove_reference<PA9>::type>::type,
		typename opros::remove_const<typename opros::remove_reference<
		PA10>::type>::type> (in, out);

	}

	template<typename R, typename P1, typename P2, typename P3, typename P4,
	typename P5, typename P6, typename P7, typename P8, typename P9,
	typename P10, typename C>
	ProvidedMethod_10(
			R(C::* function)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10),
			C *classPtr, char *fname) :
	ProvidedMethod<void> (10) {
		this->m_name = fname;

		this->memberFunction = reinterpret_cast<GenericMemberFunc> (function);

		this->mmPtr = reinterpret_cast<GenericClass *> (classPtr);
	}

	template<typename R, typename P1, typename P2, typename P3, typename P4,
	typename P5, typename P6, typename P7, typename P8, typename P9,
	typename P10>
	ProvidedMethod_10(R(*function)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10),
			char *fname) :
	ProvidedMethod<void> (10) {
		this->m_name = fname;

		this->memberFunction = NULL;

		this->mmPtr = NULL;

		this->functionPtr = reinterpret_cast<functionType> (function);
	}
};

template<typename PA1, typename PA2, typename PA3, typename PA4, typename PA5,
		typename PA6, typename PA7, typename PA8, typename PA9, typename PA10,
		typename PA11>
class ProvidedMethod_11<void, PA1, PA2, PA3, PA4, PA5, PA6, PA7, PA8, PA9,
		PA10, PA11> : public ProvidedMethod<void> {
	typedef void (GenericClass::*GenericMemberFunc)();
	typedef void (*functionType)();

	template<typename TPA1, typename TPA2, typename TPA3, typename TPA4,
			typename TPA5, typename TPA6, typename TPA7, typename TPA8,
			typename TPA9, typename TPA10, typename TPA11>
	inline ReturnType _call(opros::archive::iarchive & in,
			opros::archive::oarchive & out) {

		TPA1 param1;
		TPA2 param2;
		TPA3 param3;
		TPA4 param4;
		TPA5 param5;
		TPA6 param6;
		TPA7 param7;
		TPA8 param8;
		TPA9 param9;
		TPA10 param10;
		TPA11 param11;

		in >> OPROS_SERIALIZATION_NVP(param1);
		in >> OPROS_SERIALIZATION_NVP(param2);
		in >> OPROS_SERIALIZATION_NVP(param3);
		in >> OPROS_SERIALIZATION_NVP(param4);
		in >> OPROS_SERIALIZATION_NVP(param5);
		in >> OPROS_SERIALIZATION_NVP(param6);
		in >> OPROS_SERIALIZATION_NVP(param7);
		in >> OPROS_SERIALIZATION_NVP(param8);
		in >> OPROS_SERIALIZATION_NVP(param9);
		in >> OPROS_SERIALIZATION_NVP(param10);
		in >> OPROS_SERIALIZATION_NVP(param11);

#ifdef _MSC_VER
		(*this).operator ()<PA1,PA2,PA3,PA4,PA5,PA6,PA7,PA8,PA9,PA10,PA11>(param1, param2, param3, param4, param5, param6, param7, param8,
						param9, param10, param11);
#else
		(*this).template operator ()<PA1,PA2,PA3,PA4,PA5,PA6,PA7,PA8,PA9,PA10,PA11>(param1, param2, param3, param4, param5, param6, param7, param8,
				param9, param10, param11);
#endif

		return OPROS_SUCCESS;
	}

public:

	virtual ReturnType call(opros::archive::iarchive & in,
			opros::archive::oarchive & out) {

		return _call<typename opros::remove_const<
		typename opros::remove_reference<PA1>::type>::type,
		typename opros::remove_const<typename opros::remove_reference<
		PA2>::type>::type, typename opros::remove_const<
		typename opros::remove_reference<PA3>::type>::type,
		typename opros::remove_const<typename opros::remove_reference<
		PA4>::type>::type, typename opros::remove_const<
		typename opros::remove_reference<PA5>::type>::type,
		typename opros::remove_const<typename opros::remove_reference<
		PA6>::type>::type, typename opros::remove_const<
		typename opros::remove_reference<PA7>::type>::type,
		typename opros::remove_const<typename opros::remove_reference<
		PA8>::type>::type, typename opros::remove_const<
		typename opros::remove_reference<PA9>::type>::type,
		typename opros::remove_const<typename opros::remove_reference<
		PA10>::type>::type, typename opros::remove_const<
		typename opros::remove_reference<PA11>::type>::type> (
				in, out);
	}

	template<typename R, typename P1, typename P2, typename P3, typename P4,
	typename P5, typename P6, typename P7, typename P8, typename P9,
	typename P10, typename P11, typename C>
	ProvidedMethod_11(R(C::* function)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10,
					P11), C *classPtr, char *fname) :
	ProvidedMethod<void> (11) {
		this->m_name = fname;

		this->memberFunction = reinterpret_cast<GenericMemberFunc> (function);

		this->mmPtr = reinterpret_cast<GenericClass *> (classPtr);
	}

	template<typename R, typename P1, typename P2, typename P3, typename P4,
	typename P5, typename P6, typename P7, typename P8, typename P9,
	typename P10, typename P11>
	ProvidedMethod_11(
			R(*function)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11),
			char *fname) :
	ProvidedMethod<void> (11) {
		this->m_name = fname;

		this->memberFunction = NULL;

		this->mmPtr = NULL;

		this->functionPtr = reinterpret_cast<functionType> (function);
	}
};

template<typename PA1, typename PA2, typename PA3, typename PA4, typename PA5,
		typename PA6, typename PA7, typename PA8, typename PA9, typename PA10,
		typename PA11, typename PA12>
class ProvidedMethod_12<void, PA1, PA2, PA3, PA4, PA5, PA6, PA7, PA8, PA9,
		PA10, PA11, PA12> : public ProvidedMethod<void> {
	typedef void (GenericClass::*GenericMemberFunc)();
	typedef void (*functionType)();

	template<typename TPA1, typename TPA2, typename TPA3, typename TPA4,
			typename TPA5, typename TPA6, typename TPA7, typename TPA8,
			typename TPA9, typename TPA10, typename TPA11, typename TPA12>
	inline ReturnType _call(opros::archive::iarchive & in,
			opros::archive::oarchive & out) {

		TPA1 param1;
		TPA2 param2;
		TPA3 param3;
		TPA4 param4;
		TPA5 param5;
		TPA6 param6;
		TPA7 param7;
		TPA8 param8;
		TPA9 param9;
		TPA10 param10;
		TPA11 param11;
		TPA12 param12;

		in >> OPROS_SERIALIZATION_NVP(param1);
		in >> OPROS_SERIALIZATION_NVP(param2);
		in >> OPROS_SERIALIZATION_NVP(param3);
		in >> OPROS_SERIALIZATION_NVP(param4);
		in >> OPROS_SERIALIZATION_NVP(param5);
		in >> OPROS_SERIALIZATION_NVP(param6);
		in >> OPROS_SERIALIZATION_NVP(param7);
		in >> OPROS_SERIALIZATION_NVP(param8);
		in >> OPROS_SERIALIZATION_NVP(param9);
		in >> OPROS_SERIALIZATION_NVP(param10);
		in >> OPROS_SERIALIZATION_NVP(param11);
		in >> OPROS_SERIALIZATION_NVP(param12);

#ifdef _MSC_VER
		(*this).operator ()<PA1,PA2,PA3,PA4,PA5,PA6,PA7,PA8,PA9,PA10,PA11,PA12>(param1, param2, param3, param4, param5, param6, param7, param8,
						param9, param10, param11, param12);
#else
		(*this).template operator ()<PA1,PA2,PA3,PA4,PA5,PA6,PA7,PA8,PA9,PA10,PA11,PA12>(param1, param2, param3, param4, param5, param6, param7, param8,
				param9, param10, param11, param12);
#endif

		return OPROS_SUCCESS;

	}

public:

	virtual ReturnType call(opros::archive::iarchive & in,
			opros::archive::oarchive & out) {
		return _call<typename opros::remove_const<
		typename opros::remove_reference<PA1>::type>::type,
		typename opros::remove_const<typename opros::remove_reference<
		PA2>::type>::type, typename opros::remove_const<
		typename opros::remove_reference<PA3>::type>::type,
		typename opros::remove_const<typename opros::remove_reference<
		PA4>::type>::type, typename opros::remove_const<
		typename opros::remove_reference<PA5>::type>::type,
		typename opros::remove_const<typename opros::remove_reference<
		PA6>::type>::type, typename opros::remove_const<
		typename opros::remove_reference<PA7>::type>::type,
		typename opros::remove_const<typename opros::remove_reference<
		PA8>::type>::type, typename opros::remove_const<
		typename opros::remove_reference<PA9>::type>::type,
		typename opros::remove_const<typename opros::remove_reference<
		PA10>::type>::type, typename opros::remove_const<
		typename opros::remove_reference<PA11>::type>::type,
		typename opros::remove_const<typename opros::remove_reference<
		PA12>::type>::type> (in, out);
	}

	template<typename R, typename P1, typename P2, typename P3, typename P4,
	typename P5, typename P6, typename P7, typename P8, typename P9,
	typename P10, typename P11, typename P12, typename C>
	ProvidedMethod_12(R(C::* function)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10,
					P11, P12), C *classPtr, char *fname) :
	ProvidedMethod<void> (12) {
		this->m_name = fname;

		this->memberFunction = reinterpret_cast<GenericMemberFunc> (function);

		this->mmPtr = reinterpret_cast<GenericClass *> (classPtr);
	}

	template<typename R, typename P1, typename P2, typename P3, typename P4,
	typename P5, typename P6, typename P7, typename P8, typename P9,
	typename P10, typename P11, typename P12>
	ProvidedMethod_12(R(*function)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10,
					P11, P12), char *fname) :
	ProvidedMethod<void> (12) {
		this->m_name = fname;

		this->memberFunction = NULL;

		this->mmPtr = NULL;

		this->functionPtr = reinterpret_cast<functionType> (function);
	}
};

template<typename PA1, typename PA2, typename PA3, typename PA4, typename PA5,
		typename PA6, typename PA7, typename PA8, typename PA9, typename PA10,
		typename PA11, typename PA12, typename PA13>
class ProvidedMethod_13<void, PA1, PA2, PA3, PA4, PA5, PA6, PA7, PA8, PA9,
		PA10, PA11, PA12, PA13> : public ProvidedMethod<void> {
	typedef void (GenericClass::*GenericMemberFunc)();
	typedef void (*functionType)();

	template<typename TPA1, typename TPA2, typename TPA3, typename TPA4,
			typename TPA5, typename TPA6, typename TPA7, typename TPA8,
			typename TPA9, typename TPA10, typename TPA11, typename TPA12,
			typename TPA13>
	inline ReturnType _call(opros::archive::iarchive & in,
			opros::archive::oarchive & out) {

		TPA1 param1;
		TPA2 param2;
		TPA3 param3;
		TPA4 param4;
		TPA5 param5;
		TPA6 param6;
		TPA7 param7;
		TPA8 param8;
		TPA9 param9;
		TPA10 param10;
		TPA11 param11;
		TPA12 param12;
		TPA13 param13;

		in >> OPROS_SERIALIZATION_NVP(param1);
		in >> OPROS_SERIALIZATION_NVP(param2);
		in >> OPROS_SERIALIZATION_NVP(param3);
		in >> OPROS_SERIALIZATION_NVP(param4);
		in >> OPROS_SERIALIZATION_NVP(param5);
		in >> OPROS_SERIALIZATION_NVP(param6);
		in >> OPROS_SERIALIZATION_NVP(param7);
		in >> OPROS_SERIALIZATION_NVP(param8);
		in >> OPROS_SERIALIZATION_NVP(param9);
		in >> OPROS_SERIALIZATION_NVP(param10);
		in >> OPROS_SERIALIZATION_NVP(param11);
		in >> OPROS_SERIALIZATION_NVP(param12);
		in >> OPROS_SERIALIZATION_NVP(param13);

#ifdef _MSC_VER
		(*this).operator ()<PA1,PA2,PA3,PA4,PA5,PA6,PA7,PA8,PA9,PA10,PA11,PA12,PA13>(param1, param2, param3, param4, param5, param6, param7, param8,
						param9, param10, param11, param12, param13);
#else
		(*this).template operator ()<PA1,PA2,PA3,PA4,PA5,PA6,PA7,PA8,PA9,PA10,PA11,PA12,PA13>(param1, param2, param3, param4, param5, param6, param7, param8,
				param9, param10, param11, param12, param13);
#endif

		return OPROS_SUCCESS;
	}

public:

	virtual ReturnType call(opros::archive::iarchive & in,
			opros::archive::oarchive & out) {

		return _call<typename opros::remove_const<
		typename opros::remove_reference<PA1>::type>::type,
		typename opros::remove_const<typename opros::remove_reference<
		PA2>::type>::type, typename opros::remove_const<
		typename opros::remove_reference<PA3>::type>::type,
		typename opros::remove_const<typename opros::remove_reference<
		PA4>::type>::type, typename opros::remove_const<
		typename opros::remove_reference<PA5>::type>::type,
		typename opros::remove_const<typename opros::remove_reference<
		PA6>::type>::type, typename opros::remove_const<
		typename opros::remove_reference<PA7>::type>::type,
		typename opros::remove_const<typename opros::remove_reference<
		PA8>::type>::type, typename opros::remove_const<
		typename opros::remove_reference<PA9>::type>::type,
		typename opros::remove_const<typename opros::remove_reference<
		PA10>::type>::type, typename opros::remove_const<
		typename opros::remove_reference<PA11>::type>::type,
		typename opros::remove_const<typename opros::remove_reference<
		PA12>::type>::type, typename opros::remove_const<
		typename opros::remove_reference<PA13>::type>::type> (
				in, out);
	}

	template<typename R, typename P1, typename P2, typename P3, typename P4,
	typename P5, typename P6, typename P7, typename P8, typename P9,
	typename P10, typename P11, typename P12, typename P13, typename C>
	ProvidedMethod_13(R(C::* function)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10,
					P11, P12, P13), C *classPtr, char *fname) :
	ProvidedMethod<void> (13) {
		this->m_name = fname;

		this->memberFunction = reinterpret_cast<GenericMemberFunc> (function);

		this->mmPtr = reinterpret_cast<GenericClass *> (classPtr);
	}

	template<typename R, typename P1, typename P2, typename P3, typename P4,
	typename P5, typename P6, typename P7, typename P8, typename P9,
	typename P10, typename P11, typename P12, typename P13>
	ProvidedMethod_13(R(*function)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10,
					P11, P12, P13), char *fname) :
	ProvidedMethod<void> (13) {
		this->m_name = fname;

		this->memberFunction = NULL;

		this->mmPtr = NULL;

		this->functionPtr = reinterpret_cast<functionType> (function);
	}
};

template<typename PA1, typename PA2, typename PA3, typename PA4, typename PA5,
		typename PA6, typename PA7, typename PA8, typename PA9, typename PA10,
		typename PA11, typename PA12, typename PA13, typename PA14>
class ProvidedMethod_14<void, PA1, PA2, PA3, PA4, PA5, PA6, PA7, PA8, PA9,
		PA10, PA11, PA12, PA13, PA14> : public ProvidedMethod<void> {
	typedef void (GenericClass::*GenericMemberFunc)();
	typedef void (*functionType)();

	template<typename TPA1, typename TPA2, typename TPA3, typename TPA4,
			typename TPA5, typename TPA6, typename TPA7, typename TPA8,
			typename TPA9, typename TPA10, typename TPA11, typename TPA12,
			typename TPA13, typename TPA14>
	inline ReturnType _call(opros::archive::iarchive & in,
			opros::archive::oarchive & out) {

		TPA1 param1;
		TPA2 param2;
		TPA3 param3;
		TPA4 param4;
		TPA5 param5;
		TPA6 param6;
		TPA7 param7;
		TPA8 param8;
		TPA9 param9;
		TPA10 param10;
		TPA11 param11;
		TPA12 param12;
		TPA13 param13;
		TPA14 param14;

		in >> OPROS_SERIALIZATION_NVP(param1);
		in >> OPROS_SERIALIZATION_NVP(param2);
		in >> OPROS_SERIALIZATION_NVP(param3);
		in >> OPROS_SERIALIZATION_NVP(param4);
		in >> OPROS_SERIALIZATION_NVP(param5);
		in >> OPROS_SERIALIZATION_NVP(param6);
		in >> OPROS_SERIALIZATION_NVP(param7);
		in >> OPROS_SERIALIZATION_NVP(param8);
		in >> OPROS_SERIALIZATION_NVP(param9);
		in >> OPROS_SERIALIZATION_NVP(param10);
		in >> OPROS_SERIALIZATION_NVP(param11);
		in >> OPROS_SERIALIZATION_NVP(param12);
		in >> OPROS_SERIALIZATION_NVP(param13);
		in >> OPROS_SERIALIZATION_NVP(param14);

#ifdef _MSC_VER
		(*this).operator ()<PA1,PA2,PA3,PA4,PA5,PA6,PA7,PA8,PA9,PA10,PA11,PA12,PA13,PA14>(param1, param2, param3, param4, param5, param6, param7, param8,
						param9, param10, param11, param12, param13, param14);
#else
		(*this).template operator ()<PA1,PA2,PA3,PA4,PA5,PA6,PA7,PA8,PA9,PA10,PA11,PA12,PA13,PA14>(param1, param2, param3, param4, param5, param6, param7, param8,
				param9, param10, param11, param12, param13, param14);
#endif

		return OPROS_SUCCESS;

	}

public:

	virtual ReturnType call(opros::archive::iarchive & in,
			opros::archive::oarchive & out) {

		return _call<typename opros::remove_const<
		typename opros::remove_reference<PA1>::type>::type,
		typename opros::remove_const<typename opros::remove_reference<
		PA2>::type>::type, typename opros::remove_const<
		typename opros::remove_reference<PA3>::type>::type,
		typename opros::remove_const<typename opros::remove_reference<
		PA4>::type>::type, typename opros::remove_const<
		typename opros::remove_reference<PA5>::type>::type,
		typename opros::remove_const<typename opros::remove_reference<
		PA6>::type>::type, typename opros::remove_const<
		typename opros::remove_reference<PA7>::type>::type,
		typename opros::remove_const<typename opros::remove_reference<
		PA8>::type>::type, typename opros::remove_const<
		typename opros::remove_reference<PA9>::type>::type,
		typename opros::remove_const<typename opros::remove_reference<
		PA10>::type>::type, typename opros::remove_const<
		typename opros::remove_reference<PA11>::type>::type,
		typename opros::remove_const<typename opros::remove_reference<
		PA12>::type>::type, typename opros::remove_const<
		typename opros::remove_reference<PA13>::type>::type,
		typename opros::remove_const<typename opros::remove_reference<
		PA14>::type>::type> (in, out);

	}

	template<typename R, typename P1, typename P2, typename P3, typename P4,
	typename P5, typename P6, typename P7, typename P8, typename P9,
	typename P10, typename P11, typename P12, typename P13,
	typename P14, typename C>
	ProvidedMethod_14(R(C::* function)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10,
					P11, P12, P13, P14), C *classPtr, char *fname) :
	ProvidedMethod<void> (14) {
		this->m_name = fname;

		this->memberFunction = reinterpret_cast<GenericMemberFunc> (function);

		this->mmPtr = reinterpret_cast<GenericClass *> (classPtr);
	}

	template<typename R, typename P1, typename P2, typename P3, typename P4,
	typename P5, typename P6, typename P7, typename P8, typename P9,
	typename P10, typename P11, typename P12, typename P13,
	typename P14>
	ProvidedMethod_14(R(*function)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10,
					P11, P12, P13, P14), char *fname) :
	ProvidedMethod<void> (14) {
		this->m_name = fname;

		this->memberFunction = NULL;

		this->mmPtr = NULL;

		this->functionPtr = reinterpret_cast<functionType> (function);
	}
};

template<typename PA1, typename PA2, typename PA3, typename PA4, typename PA5,
		typename PA6, typename PA7, typename PA8, typename PA9, typename PA10,
		typename PA11, typename PA12, typename PA13, typename PA14,
		typename PA15>
class ProvidedMethod_15<void, PA1, PA2, PA3, PA4, PA5, PA6, PA7, PA8, PA9,
		PA10, PA11, PA12, PA13, PA14, PA15> : public ProvidedMethod<void> {
	typedef void (GenericClass::*GenericMemberFunc)();
	typedef void (*functionType)();

	template<typename TPA1, typename TPA2, typename TPA3, typename TPA4,
			typename TPA5, typename TPA6, typename TPA7, typename TPA8,
			typename TPA9, typename TPA10, typename TPA11, typename TPA12,
			typename TPA13, typename TPA14, typename TPA15>
	inline ReturnType _call(opros::archive::iarchive & in,
			opros::archive::oarchive & out) {

		TPA1 param1;
		TPA2 param2;
		TPA3 param3;
		TPA4 param4;
		TPA5 param5;
		TPA6 param6;
		TPA7 param7;
		TPA8 param8;
		TPA9 param9;
		TPA10 param10;
		TPA11 param11;
		TPA12 param12;
		TPA13 param13;
		TPA14 param14;
		TPA15 param15;

		in >> OPROS_SERIALIZATION_NVP(param1);
		in >> OPROS_SERIALIZATION_NVP(param2);
		in >> OPROS_SERIALIZATION_NVP(param3);
		in >> OPROS_SERIALIZATION_NVP(param4);
		in >> OPROS_SERIALIZATION_NVP(param5);
		in >> OPROS_SERIALIZATION_NVP(param6);
		in >> OPROS_SERIALIZATION_NVP(param7);
		in >> OPROS_SERIALIZATION_NVP(param8);
		in >> OPROS_SERIALIZATION_NVP(param9);
		in >> OPROS_SERIALIZATION_NVP(param10);
		in >> OPROS_SERIALIZATION_NVP(param11);
		in >> OPROS_SERIALIZATION_NVP(param12);
		in >> OPROS_SERIALIZATION_NVP(param13);
		in >> OPROS_SERIALIZATION_NVP(param14);
		in >> OPROS_SERIALIZATION_NVP(param15);

#ifdef _MSC_VER
		(*this).operator ()<PA1,PA2,PA3,PA4,PA5,PA6,PA7,PA8,PA9,PA10,PA11,PA12,PA13,PA14,PA15>(param1, param2, param3, param4, param5, param6, param7, param8,
						param9, param10, param11, param12, param13, param14, param15);
#else
		(*this).template operator ()<PA1,PA2,PA3,PA4,PA5,PA6,PA7,PA8,PA9,PA10,PA11,PA12,PA13,PA14,PA15>(param1, param2, param3, param4, param5, param6, param7, param8,
				param9, param10, param11, param12, param13, param14, param15);
#endif

		return OPROS_SUCCESS;
	}
public:

	virtual ReturnType call(opros::archive::iarchive & in,
			opros::archive::oarchive & out) {

		return _call<typename opros::remove_const<
		typename opros::remove_reference<PA1>::type>::type,
		typename opros::remove_const<typename opros::remove_reference<
		PA2>::type>::type, typename opros::remove_const<
		typename opros::remove_reference<PA3>::type>::type,
		typename opros::remove_const<typename opros::remove_reference<
		PA4>::type>::type, typename opros::remove_const<
		typename opros::remove_reference<PA5>::type>::type,
		typename opros::remove_const<typename opros::remove_reference<
		PA6>::type>::type, typename opros::remove_const<
		typename opros::remove_reference<PA7>::type>::type,
		typename opros::remove_const<typename opros::remove_reference<
		PA8>::type>::type, typename opros::remove_const<
		typename opros::remove_reference<PA9>::type>::type,
		typename opros::remove_const<typename opros::remove_reference<
		PA10>::type>::type, typename opros::remove_const<
		typename opros::remove_reference<PA11>::type>::type,
		typename opros::remove_const<typename opros::remove_reference<
		PA12>::type>::type, typename opros::remove_const<
		typename opros::remove_reference<PA13>::type>::type,
		typename opros::remove_const<typename opros::remove_reference<
		PA14>::type>::type, typename opros::remove_const<
		typename opros::remove_reference<PA15>::type>::type> (
				in, out);

	}

	template<typename R, typename P1, typename P2, typename P3, typename P4,
	typename P5, typename P6, typename P7, typename P8, typename P9,
	typename P10, typename P11, typename P12, typename P13,
	typename P14, typename P15, typename C>
	ProvidedMethod_15(R(C::* function)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10,
					P11, P12, P13, P14, P15), C *classPtr, char *fname) :
	ProvidedMethod<void> (15) {
		this->m_name = fname;

		this->memberFunction = reinterpret_cast<GenericMemberFunc> (function);

		this->mmPtr = reinterpret_cast<GenericClass *> (classPtr);
	}

	template<typename R, typename P1, typename P2, typename P3, typename P4,
	typename P5, typename P6, typename P7, typename P8, typename P9,
	typename P10, typename P11, typename P12, typename P13,
	typename P14, typename P15>
	ProvidedMethod_15(R(*function)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10,
					P11, P12, P13, P14, P15), char *fname) :
	ProvidedMethod<void> (15) {
		this->m_name = fname;

		this->memberFunction = NULL;

		this->mmPtr = NULL;

		this->functionPtr = reinterpret_cast<functionType> (function);
	}
};

//
//  make Provided Method
//

template<typename R>
Method* makeProvidedMethod(R(*function)(), char *fname) {
	ProvidedMethod_0<R> *r = new ProvidedMethod_0<R> (function, fname);

	Method *results = reinterpret_cast<Method *> (r);

	return results;
}

template<typename R, typename C>
Method* makeProvidedMethod(R(C::* function)(), C *classPtr, char *fname) {
	ProvidedMethod_0<R> *r =
			new ProvidedMethod_0<R> (function, classPtr, fname);

	Method *results = reinterpret_cast<Method *> (r);

	return results;
}

template<typename R, typename P1>
Method* makeProvidedMethod(R(*function)(P1), char *fname) {
	ProvidedMethod_1<R, P1> *r = new ProvidedMethod_1<R, P1> (function, fname);

	Method *results = reinterpret_cast<Method *> (r);

	return results;
}

template<typename R, typename C, typename P1>
Method* makeProvidedMethod(R(C::* function)(P1), C *classPtr, char *fname) {
	ProvidedMethod_1<R, P1> *r = new ProvidedMethod_1<R, P1> (function,
			classPtr, fname);

	Method *results = reinterpret_cast<Method *> (r);

	return results;
}

template<typename R, typename P1, typename P2>
Method* makeProvidedMethod(R(*function)(P1, P2), char *fname) {
	ProvidedMethod_2<R, P1, P2> *r = new ProvidedMethod_2<R, P1, P2> (function,
			fname);

	Method *results = reinterpret_cast<Method *> (r);

	return results;
}

template<typename R, typename C, typename P1, typename P2>
Method* makeProvidedMethod(R(C::* function)(P1, P2), C *classPtr, char *fname) {
	ProvidedMethod_2<R, P1, P2> *r = new ProvidedMethod_2<R, P1, P2> (function,
			classPtr, fname);

	Method *results = reinterpret_cast<Method *> (r);

	return results;
}

template<typename R, typename P1, typename P2, typename P3>
Method* makeProvidedMethod(R(*function)(P1, P2, P3), char *fname) {
	ProvidedMethod_3<R, P1, P2, P3> *r = new ProvidedMethod_3<R, P1, P2, P3> (
			function, fname);

	Method *results = reinterpret_cast<Method *> (r);

	return results;
}

template<typename R, typename C, typename P1, typename P2, typename P3>
Method* makeProvidedMethod(R(C::* function)(P1, P2, P3), C *classPtr,
		char *fname) {
	ProvidedMethod_3<R, P1, P2, P3> *r = new ProvidedMethod_3<R, P1, P2, P3> (
			function, classPtr, fname);

	Method *results = reinterpret_cast<Method *> (r);

	return results;
}

template<typename R, typename P1, typename P2, typename P3, typename P4>
Method* makeProvidedMethod(R(*function)(P1, P2, P3, P4), char *fname) {
	ProvidedMethod_4<R, P1, P2, P3, P4> *r = new ProvidedMethod_4<R, P1, P2,
			P3, P4> (function, fname);

	Method *results = reinterpret_cast<Method *> (r);

	return results;
}

template<typename R, typename C, typename P1, typename P2, typename P3,
		typename P4>
Method* makeProvidedMethod(R(C::* function)(P1, P2, P3, P4), C *classPtr,
		char *fname) {
	ProvidedMethod_4<R, P1, P2, P3, P4> *r = new ProvidedMethod_4<R, P1, P2,
			P3, P4> (function, classPtr, fname);

	Method *results = reinterpret_cast<Method *> (r);

	return results;
}

template<typename R, typename P1, typename P2, typename P3, typename P4,
		typename P5>
Method* makeProvidedMethod(R(*function)(P1, P2, P3, P4, P5), char *fname) {
	ProvidedMethod_5<R, P1, P2, P3, P4, P5> *r = new ProvidedMethod_5<R, P1,
			P2, P3, P4, P5> (function, fname);

	Method *results = reinterpret_cast<Method *> (r);

	return results;
}

template<typename R, typename C, typename P1, typename P2, typename P3,
		typename P4, typename P5>
Method* makeProvidedMethod(R(C::* function)(P1, P2, P3, P4, P5), C *classPtr,
		char *fname) {
	ProvidedMethod_5<R, P1, P2, P3, P4, P5> *r = new ProvidedMethod_5<R, P1,
			P2, P3, P4, P5> (function, classPtr, fname);

	Method *results = reinterpret_cast<Method *> (r);

	return results;
}

template<typename R, typename P1, typename P2, typename P3, typename P4,
		typename P5, typename P6>
Method* makeProvidedMethod(R(*function)(P1, P2, P3, P4, P5, P6), char *fname) {
	ProvidedMethod_6<R, P1, P2, P3, P4, P5, P6> *r = new ProvidedMethod_6<R,
			P1, P2, P3, P4, P5, P6> (function, fname);

	Method *results = reinterpret_cast<Method *> (r);

	return results;
}

template<typename R, typename C, typename P1, typename P2, typename P3,
		typename P4, typename P5, typename P6>
Method* makeProvidedMethod(R(C::* function)(P1, P2, P3, P4, P5, P6),
		C *classPtr, char *fname) {
	ProvidedMethod_6<R, P1, P2, P3, P4, P5, P6> *r = new ProvidedMethod_6<R,
			P1, P2, P3, P4, P5, P6> (function, classPtr, fname);

	Method *results = reinterpret_cast<Method *> (r);

	return results;
}

template<typename R, typename P1, typename P2, typename P3, typename P4,
		typename P5, typename P6, typename P7>
Method* makeProvidedMethod(R(*function)(P1, P2, P3, P4, P5, P6, P7),
		char *fname) {
	ProvidedMethod_7<R, P1, P2, P3, P4, P5, P6, P7> *r = new ProvidedMethod_7<
			R, P1, P2, P3, P4, P5, P6, P7> (function, fname);

	Method *results = reinterpret_cast<Method *> (r);

	return results;
}

template<typename R, typename C, typename P1, typename P2, typename P3,
		typename P4, typename P5, typename P6, typename P7>
Method* makeProvidedMethod(R(C::* function)(P1, P2, P3, P4, P5, P6, P7),
		C *classPtr, char *fname) {
	ProvidedMethod_7<R, P1, P2, P3, P4, P5, P6, P7> *r = new ProvidedMethod_7<
			R, P1, P2, P3, P4, P5, P6, P7> (function, classPtr, fname);

	Method *results = reinterpret_cast<Method *> (r);

	return results;
}

template<typename R, typename P1, typename P2, typename P3, typename P4,
		typename P5, typename P6, typename P7, typename P8>
Method* makeProvidedMethod(R(*function)(P1, P2, P3, P4, P5, P6, P7, P8),
		char *fname) {
	ProvidedMethod_8<R, P1, P2, P3, P4, P5, P6, P7, P8> *r =
			new ProvidedMethod_8<R, P1, P2, P3, P4, P5, P6, P7, P8> (function,
					fname);

	Method *results = reinterpret_cast<Method *> (r);

	return results;
}

template<typename R, typename C, typename P1, typename P2, typename P3,
		typename P4, typename P5, typename P6, typename P7, typename P8>
Method* makeProvidedMethod(R(C::* function)(P1, P2, P3, P4, P5, P6, P7, P8),
		C *classPtr, char *fname) {
	ProvidedMethod_8<R, P1, P2, P3, P4, P5, P6, P7, P8> *r =
			new ProvidedMethod_8<R, P1, P2, P3, P4, P5, P6, P7, P8> (function,
					classPtr, fname);

	Method *results = reinterpret_cast<Method *> (r);

	return results;
}

template<typename R, typename P1, typename P2, typename P3, typename P4,
		typename P5, typename P6, typename P7, typename P8, typename P9>
Method* makeProvidedMethod(R(*function)(P1, P2, P3, P4, P5, P6, P7, P8, P9),
		char *fname) {
	ProvidedMethod_9<R, P1, P2, P3, P4, P5, P6, P7, P8, P9> *r =
			new ProvidedMethod_9<R, P1, P2, P3, P4, P5, P6, P7, P8, P9> (
					function, fname);

	Method *results = reinterpret_cast<Method *> (r);

	return results;
}

template<typename R, typename C, typename P1, typename P2, typename P3,
		typename P4, typename P5, typename P6, typename P7, typename P8,
		typename P9>
Method* makeProvidedMethod(
		R(C::* function)(P1, P2, P3, P4, P5, P6, P7, P8, P9), C *classPtr,
		char *fname) {
	ProvidedMethod_9<R, P1, P2, P3, P4, P5, P6, P7, P8, P9> *r =
			new ProvidedMethod_9<R, P1, P2, P3, P4, P5, P6, P7, P8, P9> (
					function, classPtr, fname);

	Method *results = reinterpret_cast<Method *> (r);

	return results;
}

template<typename R, typename P1, typename P2, typename P3, typename P4,
		typename P5, typename P6, typename P7, typename P8, typename P9,
		typename P10>
Method* makeProvidedMethod(
		R(*function)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10), char *fname) {
	ProvidedMethod_10<R, P1, P2, P3, P4, P5, P6, P7, P8, P9, P10> *r =
			new ProvidedMethod_10<R, P1, P2, P3, P4, P5, P6, P7, P8, P9, P10> (
					function, fname);

	Method *results = reinterpret_cast<Method *> (r);

	return results;
}

template<typename R, typename C, typename P1, typename P2, typename P3,
		typename P4, typename P5, typename P6, typename P7, typename P8,
		typename P9, typename P10>
Method* makeProvidedMethod(R(C::* function)(P1, P2, P3, P4, P5, P6, P7, P8, P9,
		P10), C *classPtr, char *fname) {
	ProvidedMethod_10<R, P1, P2, P3, P4, P5, P6, P7, P8, P9, P10> *r =
			new ProvidedMethod_10<R, P1, P2, P3, P4, P5, P6, P7, P8, P9, P10> (
					function, classPtr, fname);

	Method *results = reinterpret_cast<Method *> (r);

	return results;
}

template<typename R, typename P1, typename P2, typename P3, typename P4,
		typename P5, typename P6, typename P7, typename P8, typename P9,
		typename P10, typename P11>
Method* makeProvidedMethod(R(*function)(P1, P2, P3, P4, P5, P6, P7, P8, P9,
		P10, P11), char *fname) {
	ProvidedMethod_11<R, P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11> *r =
			new ProvidedMethod_11<R, P1, P2, P3, P4, P5, P6, P7, P8, P9, P10,
					P11> (function, fname);

	Method *results = reinterpret_cast<Method *> (r);

	return results;
}

template<typename R, typename C, typename P1, typename P2, typename P3,
		typename P4, typename P5, typename P6, typename P7, typename P8,
		typename P9, typename P10, typename P11>
Method* makeProvidedMethod(R(C::* function)(P1, P2, P3, P4, P5, P6, P7, P8, P9,
		P10, P11), C *classPtr, char *fname) {
	ProvidedMethod_11<R, P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11> *r =
			new ProvidedMethod_11<R, P1, P2, P3, P4, P5, P6, P7, P8, P9, P10,
					P11> (function, classPtr, fname);

	Method *results = reinterpret_cast<Method *> (r);

	return results;
}

template<typename R, typename P1, typename P2, typename P3, typename P4,
		typename P5, typename P6, typename P7, typename P8, typename P9,
		typename P10, typename P11, typename P12>
Method* makeProvidedMethod(R(*function)(P1, P2, P3, P4, P5, P6, P7, P8, P9,
		P10, P11, P12), char *fname) {
	ProvidedMethod_12<R, P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12> *r =
			new ProvidedMethod_12<R, P1, P2, P3, P4, P5, P6, P7, P8, P9, P10,
					P11, P12> (function, fname);

	Method *results = reinterpret_cast<Method *> (r);

	return results;
}

template<typename R, typename C, typename P1, typename P2, typename P3,
		typename P4, typename P5, typename P6, typename P7, typename P8,
		typename P9, typename P10, typename P11, typename P12>
Method* makeProvidedMethod(R(C::* function)(P1, P2, P3, P4, P5, P6, P7, P8, P9,
		P10, P11, P12), C *classPtr, char *fname) {
	ProvidedMethod_12<R, P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12> *r =
			new ProvidedMethod_12<R, P1, P2, P3, P4, P5, P6, P7, P8, P9, P10,
					P11, P12> (function, classPtr, fname);

	Method *results = reinterpret_cast<Method *> (r);

	return results;
}

template<typename R, typename P1, typename P2, typename P3, typename P4,
		typename P5, typename P6, typename P7, typename P8, typename P9,
		typename P10, typename P11, typename P12, typename P13>
Method* makeProvidedMethod(R(*function)(P1, P2, P3, P4, P5, P6, P7, P8, P9,
		P10, P11, P12, P13), char *fname) {
	ProvidedMethod_13<R, P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13>
			*r = new ProvidedMethod_13<R, P1, P2, P3, P4, P5, P6, P7, P8, P9,
					P10, P11, P12, P13> (function, fname);

	Method *results = reinterpret_cast<Method *> (r);

	return results;
}

template<typename R, typename C, typename P1, typename P2, typename P3,
		typename P4, typename P5, typename P6, typename P7, typename P8,
		typename P9, typename P10, typename P11, typename P12, typename P13>
Method* makeProvidedMethod(R(C::* function)(P1, P2, P3, P4, P5, P6, P7, P8, P9,
		P10, P11, P12, P13), C *classPtr, char *fname) {
	ProvidedMethod_13<R, P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13>
			*r = new ProvidedMethod_13<R, P1, P2, P3, P4, P5, P6, P7, P8, P9,
					P10, P11, P12, P13> (function, classPtr, fname);

	Method *results = reinterpret_cast<Method *> (r);

	return results;
}

template<typename R, typename P1, typename P2, typename P3, typename P4,
		typename P5, typename P6, typename P7, typename P8, typename P9,
		typename P10, typename P11, typename P12, typename P13, typename P14>
Method* makeProvidedMethod(R(*function)(P1, P2, P3, P4, P5, P6, P7, P8, P9,
		P10, P11, P12, P13, P14), char *fname) {
	ProvidedMethod_14<R, P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12,
			P13, P14> *r = new ProvidedMethod_14<R, P1, P2, P3, P4, P5, P6, P7,
			P8, P9, P10, P11, P12, P13, P14> (function, fname);

	Method *results = reinterpret_cast<Method *> (r);

	return results;
}

template<typename R, typename C, typename P1, typename P2, typename P3,
		typename P4, typename P5, typename P6, typename P7, typename P8,
		typename P9, typename P10, typename P11, typename P12, typename P13,
		typename P14>
Method* makeProvidedMethod(R(C::* function)(P1, P2, P3, P4, P5, P6, P7, P8, P9,
		P10, P11, P12, P13, P14), C *classPtr, char *fname) {
	ProvidedMethod_14<R, P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12,
			P13, P14> *r = new ProvidedMethod_14<R, P1, P2, P3, P4, P5, P6, P7,
			P8, P9, P10, P11, P12, P13, P14> (function, classPtr, fname);

	Method *results = reinterpret_cast<Method *> (r);

	return results;
}
template<typename R, typename P1, typename P2, typename P3, typename P4,
		typename P5, typename P6, typename P7, typename P8, typename P9,
		typename P10, typename P11, typename P12, typename P13, typename P14,
		typename P15>
Method* makeProvidedMethod(R(*function)(P1, P2, P3, P4, P5, P6, P7, P8, P9,
		P10, P11, P12, P13, P14, P15), char *fname) {
	ProvidedMethod_15<R, P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12,
			P13, P14, P15> *r = new ProvidedMethod_15<R, P1, P2, P3, P4, P5,
			P6, P7, P8, P9, P10, P11, P12, P13, P14, P15> (function, fname);

	Method *results = reinterpret_cast<Method *> (r);

	return results;
}

template<typename R, typename C, typename P1, typename P2, typename P3,
		typename P4, typename P5, typename P6, typename P7, typename P8,
		typename P9, typename P10, typename P11, typename P12, typename P13,
		typename P14, typename P15>
Method* makeProvidedMethod(R(C::* function)(P1, P2, P3, P4, P5, P6, P7, P8, P9,
		P10, P11, P12, P13, P14, P15), C *classPtr, char *fname) {
	ProvidedMethod_15<R, P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12,
			P13, P14, P15> *r = new ProvidedMethod_15<R, P1, P2, P3, P4, P5,
			P6, P7, P8, P9, P10, P11, P12, P13, P14, P15> (function, classPtr,
			fname);

	Method *results = reinterpret_cast<Method *> (r);

	return results;
}
#endif /* PROVIDEDMETHOD_H_ */
