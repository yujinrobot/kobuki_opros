/*************************************************************

 file: OprosDevice.h
 author: E.C. Shin
 begin: December 31 2012
 copyright: (c) 2012 KITECH, OPRoS
 email: unchol@kitech.re.kr

***************************************************************

OPRoS source code is provided under a dual license mode:
 LGPL and OPRoS individually.

LGPL: You can redistribute it and/or modify it under the terms
 of the Less GNU General Public License as published by the Free
 Software Foundation, either version 3 of the License.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of 
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the 
 Less GNU General Public License for more details. 

 You should have received a copy of the Less GNU General Public
 License along with this program. If not, see 
 <http://www.gnu.org/licenses/>.

OPRoS individual license: An individual license is a license for
 modifying the source code of OPRoS and distiributing it in a
 closed format for commercial purposes.

 If you are interested in this option, please see 
 <http://www.ropros.or.kr>.

This license policy may be changed without prior notice.

***************************************************************/

#pragma once

#include "ApiTypes.h"
#include "Property.h"

#if defined(WIN32)
#include <Windows.h>

#define	OprosDeviceHandle HMODULE

#else
#include <dlfcn.h>

#define OprosDeviceHandle	void *

#endif

#define	API_SUCCESS			0
#define	API_ERROR			-1
#define	API_NOT_SUPPORTED	-2
#define	API_EXECUTING		1

class OprosDevice
{
public :
	OprosDevice(void) { };
	virtual ~OprosDevice(void) { };

public:
	virtual int32_t Initialize(OPRoS::Property props)		{ return API_NOT_SUPPORTED; }
	virtual int32_t Finalize(void)							{ return API_NOT_SUPPORTED; }
	virtual int32_t Enable(void)							{ return API_NOT_SUPPORTED; }
	virtual int32_t Disable(void)							{ return API_NOT_SUPPORTED; }
	virtual int32_t SetProperty(OPRoS::Property props)		{ return API_NOT_SUPPORTED; }
	virtual int32_t GetProperty(OPRoS::Property &props)		{ return API_NOT_SUPPORTED; }
};

typedef	OprosDevice *(*GET_OPROS_DEVICE)();
