/*
 * OPRoS Component Engine (OCE)
 * Copyright (c) 2008 ETRI. http://www.etri.re.kr.
 * Distributed under the OPRoS License, Version 1.0.
 *
 *  @Created : 2011. 5. 11
 *  @Author  : sby (sby@etri.re.kr)
 *
 *  @File    : opros_type_traits.h
 *
 *
 *
 *  type_trait 
 */

#ifndef _OPROS_TYPE_TRAIT_H
#define _OPROS_TYPE_TRAIT_H
namespace opros {	
//
//
//  is_primitive
//

#define OPROS_TRAIT_DEFINE_TYPE1(func,t, c) \
template<typename t> struct func \
{\
	enum {value = c}; \
};\

#define OPROS_TRAIT_DEFINE_SPEC1(func,t, c) \
template<> struct func<t> \
{\
	enum {value = c}; \
};\

OPROS_TRAIT_DEFINE_TYPE1(is_primitive,T, false)
OPROS_TRAIT_DEFINE_SPEC1(is_primitive,bool, true)
OPROS_TRAIT_DEFINE_SPEC1(is_primitive,char, true)
OPROS_TRAIT_DEFINE_SPEC1(is_primitive,wchar_t, true)

OPROS_TRAIT_DEFINE_SPEC1(is_primitive,float, true)
OPROS_TRAIT_DEFINE_SPEC1(is_primitive,double, true)
OPROS_TRAIT_DEFINE_SPEC1(is_primitive,long double, true)

OPROS_TRAIT_DEFINE_SPEC1(is_primitive,const bool, true)
OPROS_TRAIT_DEFINE_SPEC1(is_primitive,const char, true)
OPROS_TRAIT_DEFINE_SPEC1(is_primitive,const float, true)
OPROS_TRAIT_DEFINE_SPEC1(is_primitive,const double, true)
OPROS_TRAIT_DEFINE_SPEC1(is_primitive,const long double, true)

OPROS_TRAIT_DEFINE_SPEC1(is_primitive,signed long, true)
OPROS_TRAIT_DEFINE_SPEC1(is_primitive,signed int, true)
OPROS_TRAIT_DEFINE_SPEC1(is_primitive,signed short, true)
OPROS_TRAIT_DEFINE_SPEC1(is_primitive,signed char, true)
OPROS_TRAIT_DEFINE_SPEC1(is_primitive,signed long long, true)

OPROS_TRAIT_DEFINE_SPEC1(is_primitive,const signed long, true)
OPROS_TRAIT_DEFINE_SPEC1(is_primitive,const signed int, true)
OPROS_TRAIT_DEFINE_SPEC1(is_primitive,const signed short, true)
OPROS_TRAIT_DEFINE_SPEC1(is_primitive,const signed char, true)
OPROS_TRAIT_DEFINE_SPEC1(is_primitive,const signed long long, true)

OPROS_TRAIT_DEFINE_SPEC1(is_primitive,unsigned long, true)
OPROS_TRAIT_DEFINE_SPEC1(is_primitive,unsigned int, true)
OPROS_TRAIT_DEFINE_SPEC1(is_primitive,unsigned short, true)
OPROS_TRAIT_DEFINE_SPEC1(is_primitive,unsigned char, true)
OPROS_TRAIT_DEFINE_SPEC1(is_primitive,unsigned long long, true)

OPROS_TRAIT_DEFINE_SPEC1(is_primitive,const unsigned long, true)
OPROS_TRAIT_DEFINE_SPEC1(is_primitive,const unsigned int, true)
OPROS_TRAIT_DEFINE_SPEC1(is_primitive,const unsigned short, true)
OPROS_TRAIT_DEFINE_SPEC1(is_primitive,const unsigned char, true)
OPROS_TRAIT_DEFINE_SPEC1(is_primitive,const unsigned long long, true)


//
//
//  is_array
//

template <typename T> struct is_array{
	enum {value = false};
};

template <typename T, size_t N> struct is_array< T[N] > {
	enum {value = true};
};


//
//
//  is_pointer
//

template <typename T> struct is_pointer{
	enum {value = false};
};
template <typename T> struct is_pointer<T *>
{
	enum {value = true};
};



#if ((__GNUC__ ==4) && (__GNUC_MINOR__ >= 3)) || (_MSC_VER >=1400)

#else

#define OPROS_IS_ENUM_IS_CLASS_USE

#endif

#define OPROS_IS_ENUM_IS_CLASS_USE


#ifndef OPROS_IS_ENUM_IS_CLASS_USE

template <typename T>
struct is_class
{
	enum {value = __is_class(T) };

};

template <typename T>
struct is_enum
{
	enum {value = __is_enum(T) };

};

#else
//
//
//  is_class (struct, class, union)
//

typedef char yes_type;

struct no_type
{
	char data[2];
};

template <typename U>
yes_type if_class(void (U::*)(void));

template <typename U>
no_type if_class(...);

template <typename T>
struct is_class
{
	enum {value = (sizeof(if_class<T>(NULL)) == sizeof(yes_type)) };

};


//
//
//  is_enum (!class & !primitive)
//

template <typename T>
struct is_enum
{
	enum {value = ( !(is_class<T>::value || is_primitive<T>::value) \
			&  ( (sizeof(T) == sizeof(int)) \
			|| (sizeof(T) == sizeof(char)))) }; // In ARM, sizeof(enum) is equal with sizeof(char)
};
template <>
struct is_enum<void>
{
	enum {value=false};
};

#endif

template <typename dataType>
class remove_const
{
public:
	typedef dataType type;
	
};

template <typename dataType>
class remove_const<const dataType>
{
public:
	typedef dataType type;	
};


template <typename dataType>
class remove_reference
{
public:
	typedef dataType type;
	
};

template <typename dataType>
class remove_reference<dataType&>
{
public:
	typedef dataType type;	
};

template <typename dataType>
class remove_pointer
{
public:
	typedef dataType type;
};

template <typename dataType>
class remove_pointer<dataType *>
{
public:
	typedef dataType type;
};

}// namespace opros


#endif
