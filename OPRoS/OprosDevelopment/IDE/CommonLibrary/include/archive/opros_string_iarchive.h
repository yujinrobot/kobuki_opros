/*
 * OPRoS Component Engine (OCE)
 * Copyright (c) 2008 ETRI. http://www.etri.re.kr.
 * Distributed under the OPRoS License, Version 1.0.
 *
 *  @Created : 2010. 8. 11
 *  @Author  : sby (sby@etri.re.kr)
 *
 *  @File    : opros_string_iarchive.h
 *
 *
 *
 *  Archive class for serialization support
 */

#ifndef _OPROS_STRING_IARHIVE_H
#define _OPROS_STRING_IARHIVE_H

#include <iostream>
#include "opros_archive_common.h"
#include "opros_binary.h"
#include "opros_iarchive.h"
#include "opros_iarchive_stl.h"

namespace opros {
	namespace archive {


class string_iarchive : public iarchive  {

	std::istream *m_is;

protected:

	virtual iarchive& read_class_head(const std::string &name);
	virtual iarchive& read_class_end(const std::string &name);
	virtual iarchive& read_array_head(long &sz,char &code, char &bsz);
	virtual iarchive& read_array_end(long &sz,char &code, char &bsz);

public:
	virtual iarchive& read_start_tag(std::string &name);
	virtual iarchive& read_end_tag(std::string &name);	


public:
	string_iarchive(std::istream *is);
	virtual ~string_iarchive() {};


	virtual iarchive& load(bool &val);

	virtual iarchive& load(short &val);
	virtual iarchive& load(unsigned short &val);

	virtual iarchive& load(int &val);
	virtual iarchive& load(unsigned int &val);

	virtual iarchive& load(long &val);
	virtual iarchive& load(unsigned long &val);

	virtual iarchive& load(long long &val);
	virtual iarchive& load(unsigned long long &val);

	virtual iarchive& load(float &val);
	virtual iarchive& load(double &val);
	virtual iarchive& load(long double &val);

	virtual iarchive& load(char &val);	
	virtual iarchive& load(unsigned char &val);

	virtual iarchive& load(wchar_t &val);

	virtual iarchive& load_binary(char **p, long &sz);

protected:
	virtual iarchive& load_array(bool **s, long &sz);

	virtual iarchive& load_array(char **s, long &sz);
	virtual iarchive& load_array(unsigned char **s, long &sz);

	virtual iarchive& load_array(wchar_t **s, long &sz);

	virtual iarchive& load_array(short **s, long &sz);
	virtual iarchive& load_array(unsigned short **s, long &sz);

	virtual iarchive& load_array(int **s, long &sz);
	virtual iarchive& load_array(unsigned int **s, long &sz);

	virtual iarchive& load_array(long **s, long &sz);
	virtual iarchive& load_array(unsigned long **s, long &sz);
	
	virtual iarchive& load_array(float **s, long &sz);
	virtual iarchive& load_array(double **s, long &sz);
	virtual iarchive& load_array(long double **s, long &sz);

	virtual iarchive& load_array(long long **s, long &sz);
	virtual iarchive& load_array(unsigned long long **s, long &sz);
};



	} // namespace archive 
} // amespace opros

#endif // _OPROS_STRING_IARHIVE_H
