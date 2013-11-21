#ifndef _VisionRecognitionResult_REQUIRED_PORT_H
#define _VisionRecognitionResult_REQUIRED_PORT_H

#include <ApiTypes.h>

namespace OPRoS
{
class VisionRecognitionResult
{
public:
	VisionRecognitionResult(void)
	{
	}
	virtual ~VisionRecognitionResult(void) { }

	friend class opros::archive::access;
	void save(opros::archive::oarchive &ar, const unsigned int)
	{
		ar << name;
		ar << point1X;				ar << point1Y;
		ar << point2X;				ar << point2Y;
		ar << point3X;				ar << point3Y;
		ar << point4X;				ar << point4Y;
	}

	void load(opros::archive::iarchive &ar, const unsigned int)
	{
		ar >> name;
		ar >> point1X;				ar >> point1Y;
		ar >> point2X;				ar >> point2Y;
		ar >> point3X;				ar >> point3Y;
		ar >> point4X;				ar >> point4Y;
	}
    
	VisionRecognitionResult operator=(const VisionRecognitionResult &visionRecognitionData)
	{
		this->name = visionRecognitionData.name;
		this->point1X = visionRecognitionData.point1X;
		this->point1Y = visionRecognitionData.point1Y;
		this->point2X = visionRecognitionData.point2X;
		this->point2Y = visionRecognitionData.point2Y;
		this->point3X = visionRecognitionData.point3X;
		this->point3Y = visionRecognitionData.point3Y;
		this->point4X = visionRecognitionData.point4X;
		this->point4Y = visionRecognitionData.point4Y;

		return *this;
	}

	std::string name;
	int point1X;
	int point1Y;
	int point2X;
	int point2Y;
	int point3X;
	int point3Y;
	int point4X;
	int point4Y;
};
inline std::string typeName(VisionRecognitionResult *p)	{ return "VisionRecognitionResult"; }
}

#endif