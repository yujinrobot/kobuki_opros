/*************************************************************

 file: AccelerationSensorData.h
 author: E.C. Shin
 begin: March 13 2013
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

#include "ApiTypes.h"

namespace OPRoS
{
class AccelerationSensorData
{
public:
  AccelerationSensorData() {
		status = OPROS_SUCCESS;
		xAcceleration = yAcceleration = zAcceleration = 0.0;
	}
	AccelerationSensorData(float64_t xAcceleration, float64_t yAcceleration, float64_t zAcceleration) {
		status = OPROS_SUCCESS;
		this->xAcceleration = xAcceleration;
		this->yAcceleration = yAcceleration;
		this->zAcceleration = zAcceleration;
	}
	virtual ~AccelerationSensorData() { };

	friend class opros::archive::access;
	
	ReturnType status;
	float64_t xAcceleration;
	float64_t yAcceleration;
	float64_t zAcceleration;

	void save(opros::archive::oarchive &ar, const unsigned int)
	{
		ar << status;
		ar << xAcceleration;			ar << yAcceleration;			ar << zAcceleration;
	}

	void load(opros::archive::iarchive &ar, const unsigned int)
	{
		ar >> status;
		ar >> xAcceleration;			ar >> yAcceleration;			ar >> zAcceleration;
	}

	AccelerationSensorData operator=(const AccelerationSensorData &arg)
	{
		this->status = arg.status;
		this->xAcceleration = arg.xAcceleration;
		this->yAcceleration = arg.yAcceleration;
		this->zAcceleration = arg.zAcceleration;

		return *this;
	}
};
inline std::string typeName(AccelerationSensorData *p)	{ return "AccelerationSensorData"; }
}
