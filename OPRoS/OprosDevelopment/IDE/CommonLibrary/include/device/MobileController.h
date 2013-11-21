/*************************************************************

 file: MobileController.h
 author: E.C. Shin
 begin: December 31 2012
 copyright: (c) 2012 KITECH, OPRoS
 email: uncholshin@gmail.com

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
 <http://www.opros.or.kr>.

This license policy may be changed without prior notice.

***************************************************************/

#pragma once

#include "OprosDevice.h"
#include "MobileVelocityData.h"
#include "MobilePositionData.h"

class MobileController : public OprosDevice
{
public:
	MobileController(void)	{	}
	virtual ~MobileController(void)	{	}

	virtual int32_t GetOdometry(std::vector<OPRoS::Int32> &odometery)		{ return API_NOT_SUPPORTED; }
	virtual int32_t SetVelocity(OPRoS::MobileVelocityData mobileVelocity)	{ return API_NOT_SUPPORTED; }
	virtual int32_t SetPosition(OPRoS::MobilePositionData position)			{ return API_NOT_SUPPORTED; }	
	virtual int32_t GetPosition(OPRoS::MobilePositionData &position)		{ return API_NOT_SUPPORTED; }

};
