/*
 * OPRoS Component Engine (OCE)
 * Copyright (c) 2008 ETRI. http://www.etri.re.kr.
 * Distributed under the OPRoS License, Version 1.0.
 *
 *  @Created : 2010. 8. 11
 *  @Author  : sby (sby@etri.re.kr)
 *
 *  @File    : opros_archive.h
 *
 *
 *
 *  Archive class for serialization support
 */

#ifndef _OPROS_ARHIVE_COMMON_H
#define _OPROS_ARHIVE_COMMON_H

#include <exception>
#include <memory.h>
#include <string>
#include <archive/opros_type_traits.h>

#define BOOL_CODE 'Z'
#define SHORT_CODE 'i'
#define UNSIGNED_SHORT_CODE 'i'
#define INT_CODE 'I'
#define UNSIGNED_INT_CODE 'I'
#define LONG_CODE 'L'
#define UNSIGNED_LONG_CODE 'L'
#define FLOAT_CODE 'F'
#define DOUBLE_CODE 'd'
#define LONG_DOUBLE_CODE 'D'
#define CHAR_CODE 'C'
#define SIGNED_CHAR_CODE 'C'
#define UNSIGNED_CHAR_CODE 'C'
#define ARRAY_CODE 'A'
#define LONG_LONG_CODE 'S'
#define UNSIGNED_LONG_LONG_CODE 'S'
#define WCHAR_T_CODE 'w'


#define CLASS_CODE 'T'
#define BINARY_CODE 'G'
#define SIZE_CODE_MAX 16


namespace opros {
	namespace archive {

class archive {
public:
	virtual ~archive() {};
};


template <typename T>
char type_code(T *p)
{
	return CLASS_CODE;
}

/*
template <typename T>
char type_code(const T *p)
{
	return type_code((T*)p);
}
*/

char type_code(bool *val);
char type_code(short *val);
char type_code(unsigned short *val);
char type_code(int *val);
char type_code(unsigned int *val);
char type_code(long *val);
char type_code(unsigned long *val);
char type_code(long long*val);
char type_code(unsigned long long*val);
char type_code(float *val);
char type_code(double *val);
char type_code(long double *val);
char type_code(char *val);
char type_code(signed char *val);
char type_code(unsigned char *val);

char type_code(wchar_t *val);

//
// arhive exception
//

class archive_type_exception : public std::exception
{
public:

	archive_type_exception(){}

	virtual const char *what() const throw()
	{
		return "archive type mismatch error";
	}
};

class archive_array_size_exception: public std::exception
	{
public:
	archive_array_size_exception(){}

	virtual const char *what() const throw()
	{
		return "array size mismatch";
	}
};

class archive_system_exception: public std::exception
	{
public:
	archive_system_exception(){}

	virtual const char *what() const throw()
	{
		return "system error";
	}
};


class archive_format_exception : public std::exception
{
public:
	archive_format_exception(){}

	virtual const char *what() const throw()
	{
		return "archive format error";
	}
};

	} // namespace archive 


	// nvp set
	class nvp_base
	{
	};

	template <typename Type>
	class nvp : public nvp_base
	{
		std::string m_name;
		Type &m_data;

	public:

		std::string &getName()
		{
			return m_name;
		};

		Type& getData()
		{
			return m_data;
		};
		
		nvp(const std::string &name,  Type &a) : m_name(name), m_data(a)
		{

		};
	};

	template <typename T>
	inline const nvp<T> makenvp(const std::string &name, T & b)
	{
			return nvp<T>(name,b);
	};	

} // amespace opros

inline bool is_little_endian()
{
	unsigned short check = 12345;
	unsigned char *x = (unsigned char *)&check;

	if (x[0] == 0x30) return false;
	return true;
}

inline void change_endian(unsigned char *p, int sz)
{
	if (!is_little_endian())
	{
		unsigned char *x = new unsigned char[sz];
		memcpy(x,p,sz);
		int i;
		for (i=0;i<sz;i++)
		{
			p[i] = x[sz-1-i];
		}
		delete x;
	}
}

namespace opros {
	namespace archive {
class oarchive;
class iarchive;
	}
}


template <typename Type>
class has_opros_serialization
{
	template <typename T,T> struct type_check;

	typedef char yes;
	typedef long no;

	template <typename T> struct HasFunc
	{
		typedef void (T::*save_fptr)(opros::archive::oarchive &, const unsigned int);
		typedef void (T::*load_fptr)(opros::archive::iarchive &, const unsigned int);
	};

	template <typename T> static yes has_save( type_check< typename HasFunc<T>::save_fptr, &T::save >*);
	template <typename T> static no has_save(...);
	template <typename T> static yes has_load( type_check< typename HasFunc<T>::load_fptr, &T::load >*);
	template <typename T> static no has_load(...);

public:
	static bool const value = (sizeof(has_save<
		typename opros::remove_reference<typename opros::remove_const<typename opros::remove_pointer<Type>::type>::type>::type 
			>(0)) == sizeof(yes)  && sizeof(has_load<
			typename opros::remove_reference<typename opros::remove_const<typename opros::remove_pointer<Type>::type>::type>::type 
			>(0)) == sizeof(yes) );
};



#define OPROS_SERIALIZATION_NVP(a) opros::makenvp(#a, a)
#define OPROS_SERIALIZATION_MAKE_NVP(a,b) opros::makenvp(#a, b)
#define OPROS_SERIALIZATION_VERSION 1

#endif // _OPROS_ARHIVE_COMMON_H
