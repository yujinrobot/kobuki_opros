/*************************************************************

 file: Property.h
 author: E.C. Shin
 begin: December 31 2012
 copyright: (c) 2011 KITECH, OPRoS
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

#include <map>
#include <string>

#include "ArchiveFactory.h"
#include "ReturnType.h"

using namespace std; // Add by Donghee choi  2013.05.06

namespace OPRoS
{

class Property
{
public:
	Property(void) {
		status = OPROS_SUCCESS;
	};
	virtual ~Property(void) { };

protected:
	friend class opros::archive::access;

	std::map<std::string, std::string> data;
	
public:
	ReturnType status;

	void save(opros::archive::oarchive &ar, const unsigned int)
	{
		ar << data;		ar << status;
	}

	void load(opros::archive::iarchive &ar, const unsigned int)
	{
		ar >> data;		ar >> status;
	}

	Property operator=(const Property &data)
	{
		this->data = data.data;
		this->status = data.status;
		
		return *this;
	}

	void SetProperty(std::map<std::string, std::string> data)
	{
		this->data = data;
	}

	std::map<std::string, std::string> GetProperty(void)
	{
		return data;
	}

	void SetValue(std::string name, std::string value)
	{
		data[name] = value;
	}

	std::string GetValue(std::string name)
	{
		return data[name];
	}

	bool FindName(std::string name)
	{
		if(data.find(name) != data.end()) {
			return true;
		}
		return false;
	}
};

inline std::string typeName(Property *p)	{ return "Property"; }

}
