#ifndef	_CARTESIAN_COORDINATE_H_
#define	_CARTESIAN_COORDINATE_H_

#include <ApiTypes.h>

namespace OPRoS
{
class CartesianCoordinate
{
public:
	CartesianCoordinate(void) {
		x = 0.0;		y = 0.0;		z = 0.0;
		roll = 0.0;		pitch = 0.0;	yaw = 0.0;
		status = OPROS_SUCCESS;
	}
	CartesianCoordinate(float64_t x, float64_t y, float64_t z, float64_t roll, float64_t pitch, float64_t yaw) {
		this->x = x;				this->y = y;				this->z = z;
		this->roll = roll;		this->pitch = pitch;		this->yaw = yaw;
	}
	virtual ~CartesianCoordinate() { };

	friend class opros::archive::access;
	
	float64_t x, y, z;
	float64_t roll, pitch, yaw;

	void save(opros::archive::oarchive &ar, const unsigned int)
	{
		ar << x;			ar << y;			ar << z;
		ar << roll;			ar << pitch;		ar << yaw;
	}

	void load(opros::archive::iarchive &ar, const unsigned int)
	{
		ar >> x;			ar >> y;			ar >> z;
		ar >> roll;			ar >> pitch;		ar >> yaw;
	}

	CartesianCoordinate operator=(const CartesianCoordinate &cartesianCoordinate)
	{
		this->x = cartesianCoordinate.x;
		this->y = cartesianCoordinate.y;
		this->z = cartesianCoordinate.z;
		this->roll = cartesianCoordinate.roll;
		this->pitch = cartesianCoordinate.pitch;
		this->yaw = cartesianCoordinate.yaw;

		return *this;
	}

	CartesianCoordinate operator+(const CartesianCoordinate &cartesianCoordinate)
	{
		this->x += cartesianCoordinate.x;
		this->y += cartesianCoordinate.y;
		this->z += cartesianCoordinate.z;
		this->roll += cartesianCoordinate.roll;
		this->pitch += cartesianCoordinate.pitch;
		this->yaw += cartesianCoordinate.yaw;

		return *this;
	}

	CartesianCoordinate operator-(const CartesianCoordinate &cartesianCoordinate)
	{
		this->x -= cartesianCoordinate.x;
		this->y -= cartesianCoordinate.y;
		this->z -= cartesianCoordinate.z;
		this->roll -= cartesianCoordinate.roll;
		this->pitch -= cartesianCoordinate.pitch;
		this->yaw -= cartesianCoordinate.yaw;

		return *this;
	}
};
inline std::string typeName(CartesianCoordinate *p)	{ return "CartesianCoordinate"; }
}

#endif // _CARTESIAN_COORDINATE_H_
