/*************************************************************

 file: GeoMagneticSensorData.h
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

class GeoMagneticSensorData
{
public:
	GeoMagneticSensorData() {
		status = OPROS_SUCCESS;
		xGauss = yGauss = zGauss = 0.0;
		xGaussRate = yGaussRate = zGaussRate = 0.0;
		xAlpha = yAlpha = zAlpha = 0.0;
	}
	GeoMagneticSensorData(float64_t xGauss, float64_t yGauss, float64_t zGauss, float64_t xGaussRate, float64_t yGaussRate, float64_t zGaussRate, float64_t xAlpha, float64_t yAlpha, float64_t zAlpha) {
		status = OPROS_SUCCESS;
		this->xGauss = xGauss;
		this->yGauss = yGauss;
		this->zGauss = zGauss;
		this->xGaussRate = xGaussRate;
		this->yGaussRate = yGaussRate;
		this->zGaussRate = zGaussRate;
		this->xAlpha = xAlpha;
		this->yAlpha = yAlpha;
		this->zAlpha = zAlpha;
	}
	virtual ~GeoMagneticSensorData() { };

	friend class opros::archive::access;
	
	ReturnType status;
	float64_t xGauss;
	float64_t yGauss;
	float64_t zGauss;
	float64_t xGaussRate;
	float64_t yGaussRate;
	float64_t zGaussRate;
	float64_t xAlpha;
	float64_t yAlpha;
	float64_t zAlpha;

	void save(opros::archive::oarchive &ar, const unsigned int)
	{
		ar << status;
		ar << xGauss;			ar << yGauss;			ar << zGauss;
		ar << xGaussRate;		ar << yGaussRate;		ar << zGaussRate;
		ar << xAlpha;			ar << yAlpha;			ar << zAlpha;
	}

	void load(opros::archive::iarchive &ar, const unsigned int)
	{
		ar >> status;
		ar >> xGauss;			ar >> yGauss;			ar >> zGauss;
		ar >> xGaussRate;		ar >> yGaussRate;		ar >> zGaussRate;
		ar >> xAlpha;			ar >> yAlpha;			ar >> zAlpha;

	}

	GeoMagneticSensorData operator=(const GeoMagneticSensorData &arg)
	{
		this->status = arg.status;
		this->xGauss = arg.xGauss;
		this->yGauss = arg.yGauss;
		this->zGauss = arg.zGauss;
		this->xGaussRate = arg.xGaussRate;
		this->yGaussRate = arg.yGaussRate;
		this->zGaussRate = arg.zGaussRate;
		this->xAlpha = arg.xAlpha;
		this->yAlpha = arg.yAlpha;
		this->zAlpha = arg.zAlpha;

		return *this;
	}
};
inline std::string typeName(GeoMagneticSensorData *p)	{ return "GeoMagneticSensorData"; }

}