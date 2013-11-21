/*************************************************************

 file: ObjectAccelerationData.h
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

class ObjectAccelerationData
{
public:
	ObjectAccelerationData(void) {
		status = OPROS_SUCCESS;
		x = y = z = roll = pitch = yaw = 0.0;
	}
	ObjectAccelerationData(float64_t x, float64_t y, float64_t z, float64_t roll, float64_t pitch, float64_t yaw) {
		status = OPROS_SUCCESS;
		this->x = x;
		this->y = y;
		this->z = z;
		this->roll = roll;
		this->pitch = pitch;
		this->yaw = yaw;
	}
	virtual ~ObjectAccelerationData(void) {
	}

	ReturnType status;
	float64_t	x;
	float64_t	y;
	float64_t	z;
	float64_t	roll;
	float64_t	pitch;
	float64_t	yaw;

	void save(opros::archive::oarchive &ar, const unsigned int)
	{
		ar << status;
		ar << x;		ar << y;		ar << z;
		ar << roll;		ar << pitch;	ar << yaw;
	}

	void load(opros::archive::iarchive &ar, const unsigned int)
	{
		ar >> status;
		ar >> x;		ar >> y;		ar >> z;
		ar >> roll;		ar >> pitch;	ar >> yaw;
	}

	ObjectAccelerationData operator=(const ObjectAccelerationData &arg)
	{
		this->status = arg.status;
		this->x = arg.x;
		this->y = arg.y;
		this->z = arg.z;
		this->roll = arg.roll;
		this->pitch = arg.pitch;
		this->yaw = arg.yaw;

		return *this;
	}
};
inline std::string typeName(ObjectAccelerationData *p)	{ return "ObjectAccelerationData"; }

}
