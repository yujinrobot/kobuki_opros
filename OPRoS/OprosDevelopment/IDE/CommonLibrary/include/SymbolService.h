/*
 *  OPRoS Component Engine (OCE)
 *  Copyright (c) 2011 ETRI. http://www.etri.re.kr.
 *  Distributed under the OPRoS License, Version 1.0.
 *  @Created : 2011. 7. 10
 *  @Author  : sby (sby@etri.re.kr)
 *
 *  @File    : TopicServicePort.h
 *
 *
 *
 */
#ifndef _OPROS_SYMBOL_SERVICE_H
#define _OPROS_SYMBOL_SERVICE_H

#include <OPRoSTypes.h>
#include <InputDataPort.h>
#include <OutputDataPort.h>
#include <InputEventPort.h>
#include <OutputEventPort.h>
#include <ProvidedServicePort.h>
#include <RequiredServicePort.h>
#include <ProvidedMethod.h>
#include <RequiredMethod.h>
#include "archive/opros_archive.h"
#include <Component.h>

enum SymbolEncodingRule
{
	OPROS_SYMBOL_ENCODING_STR  = 0,
	OPROS_SYMBOL_ENCODING_BIN  = 1
};


class SymbolObject {	
public:
	virtual void getValue(opros::archive::oarchive &ar) = 0;
	virtual void setValue(opros::archive::iarchive &ar) = 0;
};



template <typename T>
class SymbolAccessObject: public SymbolObject
{
	T *m_p;
public:
	SymbolAccessObject(T *p)
	{
		 m_p = p;
	}

	virtual void getValue(opros::archive::oarchive &ar)
	{
		ar << (*m_p);
	}

	virtual void setValue(opros::archive::iarchive &ar)
	{
		ar >> (*m_p);
	}

};

template <typename T>
SymbolObject *makeSymbolObject(T *p)
{
	SymbolAccessObject<T> *pout = new SymbolAccessObject<T>(p);

	return pout;
}

ReturnType symbolservice_exportSymbol(Component *comp, const std::string &name, SymbolObject *p);

#define EXPORT_VARIABLE(a,b) (symbolservice_exportSymbol(this, a, makeSymbolObject(&b)))
#endif // _OPROS_SYMBOL_SERVICE_H
