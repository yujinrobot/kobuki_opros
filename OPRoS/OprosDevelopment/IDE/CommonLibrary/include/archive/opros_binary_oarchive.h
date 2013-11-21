/*
 * OPRoS Component Engine (OCE)
 * Copyright (c) 2008 ETRI. http://www.etri.re.kr.
 * Distributed under the OPRoS License, Version 1.0.
 *
 *  @Created : 2010. 8. 11
 *  @Author  : sby (sby@etri.re.kr)
 *
 *  @File    : opros_string_oarchive.h
 *
 *
 *
 *  OPROS output archive definition
 */

#ifndef _OPROS_BINARY_OARHIVE_H
#define _OPROS_BINARY_OARHIVE_H


#include <iostream>
#include "opros_archive_common.h"
#include "opros_binary.h"
#include "opros_oarchive.h"

namespace opros {
	namespace archive {


class binary_oarchive  : public oarchive  {

	std::ostream *m_is;

protected:
	virtual oarchive& write_class_head(const std::string &name);
	virtual oarchive& write_class_end(const std::string &name);
	virtual oarchive& write_array_head(long sz, char code, char bsz );
	virtual oarchive& write_array_end(long sz, char code, char bsz );

public:
	virtual oarchive& write_start_tag(const std::string &name);
	virtual oarchive& write_end_tag(const std::string &name);

public:
	binary_oarchive(std::ostream *is);
	virtual ~binary_oarchive() {};


	virtual oarchive& save(bool val);

	virtual oarchive& save(short val);
	virtual oarchive& save(unsigned short val);

	virtual oarchive& save(int val);
	virtual oarchive& save(unsigned int val);

	virtual oarchive& save(long val);
	virtual oarchive& save(unsigned long val);

	virtual oarchive& save(long long val);
	virtual oarchive& save(unsigned long long val);

	virtual oarchive& save(float val);
	virtual oarchive& save(double val);
	virtual oarchive& save(long double val);

	
	virtual oarchive& save(char val);
	virtual oarchive& save(unsigned char val);

	virtual oarchive& save(wchar_t val);

	virtual oarchive& save_binary(char *p, const long sz);

protected:
	virtual oarchive& save_array(bool *p, const long val);
	virtual oarchive& save_array(char *p, const long val);
	virtual oarchive& save_array(unsigned char *p, const long val);
	virtual oarchive& save_array(short *p, const long val);
	virtual oarchive& save_array(unsigned short *p, const long val);
	virtual oarchive& save_array(int *p, const long val);
	virtual oarchive& save_array(unsigned int *p, const long val);
	virtual oarchive& save_array(long *p, const long val);
	virtual oarchive& save_array(unsigned long *p, const long val);
	
	virtual oarchive& save_array(float *p, const long val);
	virtual oarchive& save_array(double *p, const long val);
	virtual oarchive& save_array(long double *p, const long val);

	virtual oarchive& save_array(long long *p, const long val);
	virtual oarchive& save_array(unsigned long long *p, const long val);

	virtual oarchive& save_array(wchar_t *p, const long sz);
};

	} // namespace archive 
} // namespace opros




#endif // _OPROS_BINARY_OARHIVE_H
