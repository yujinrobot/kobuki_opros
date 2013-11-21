/*
 *  OPRoS Component Engine (OCE)
 *  Copyright (c) 2008 ETRI. http://www.etri.re.kr.
 *  Distributed under the OPRoS License, Version 1.0.
 *
 *  @Created : 2009. 2. 19
 *  @Author  : sby (sby@etri.re.kr)
 *
 *  @File    : ArchiveFactory.h
 *    ArchiveFactory for Task 
 *
 *
 */

#ifndef ARCHIVEFACTORY_H_
#define ARCHIVEFACTORY_H_

#include <sstream>
#include "archive/opros_archive.h"

/**
 * ArchiveFactory is the abstract base class for all boost archive instance creation factory
 *
 */
class ArchiveFactory {
public:
	/**
	 *  Create opros output archive instance related to output stream
	 *
	 *  @param str		stream reference used by opros output archive.
	 *  				After serialization process, the engine gets string from str and
	 *  				send a message including the string to target host
	 */
	virtual opros::archive::oarchive *getOutputArchive(std::ostream *str) =0;

	/**
	 *  Create opros input archive instance related to input stream
	 *
	 *	@param str		stream reference used by opros input archive.
	 *					There are serialized data in the stream from other hosts or components.
	 */
	virtual opros::archive::iarchive *getInputArchive(std::istream *str) =0;

	/**
	 * Release output archive instance
	 *
	 *	@param arc		oarchive instance pointer.
	 *					the pointer had to be created from getOutputArchive() function.
	 */
	virtual void release(opros::archive::oarchive *arc)=0;

	/**
	 * Release input archive instance
	 *
	 *	@param arc		iarchive instance pointer.
	 *					the pointer had to be created from getInputArchive() function.
	 */
	virtual void release(opros::archive::iarchive *arc)=0;

	ArchiveFactory();
	virtual ~ArchiveFactory();
};
#endif /* ARCHIVEFACTORY_H_ */
