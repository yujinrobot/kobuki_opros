/*************************************************************

 file: GyroSensorData.h
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

class GyroSensorData
{
public:
	GyroSensorData() {
		status = OPROS_SUCCESS;
		xAngle = yAngle = zAngle = 0.0;
		xAngleRate = yAngleRate = zAngleRate = 0.0;
	}
	virtual ~GyroSensorData() { };

	friend class opros::archive::access;
	
	ReturnType status;
	float64_t xAngle;
	float64_t yAngle;
	float64_t zAngle;

	float64_t xAngleRate;
	float64_t yAngleRate;
	float64_t zAngleRate;

	void save(opros::archive::oarchive &ar, const unsigned int)
	{
		ar << status;
		ar << xAngle;		ar << yAngle;		ar << zAngle;
		ar << xAngleRate;	ar << yAngleRate;	ar << zAngleRate;
	}

	void load(opros::archive::iarchive &ar, const unsigned int)
	{
		ar >> status;
		ar >> xAngle;		ar >> yAngle;		ar >> zAngle;
		ar >> xAngleRate;	ar >> yAngleRate;	ar >> zAngleRate;
	}

	GyroSensorData operator=(const GyroSensorData &gyroSensorData)
	{
		this->status = gyroSensorData.status;

		this->xAngle = gyroSensorData.xAngle;
		this->yAngle = gyroSensorData.yAngle;
		this->zAngle = gyroSensorData.zAngle;

		this->xAngleRate = gyroSensorData.xAngleRate;
		this->yAngleRate = gyroSensorData.yAngleRate;
		this->zAngleRate = gyroSensorData.zAngleRate;

		return *this;
	}
};
inline std::string typeName(GyroSensorData *p)	{ return "GyroSensorData"; }

}