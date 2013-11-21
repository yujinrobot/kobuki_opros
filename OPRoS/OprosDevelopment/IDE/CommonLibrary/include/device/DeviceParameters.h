/*************************************************************

 file: DeviceParameters.cpp
 author: Byung Chul Choi
 begin: April 12 2013
 copyright: (c) 2013 SIMLAB, OPRoS
 email: bcchoi@simlab.co.kr

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

namespace OPRoS
{
        class CDeviceParameters
        {       
                string deviceName;
                double x;
                double y;
                double z;
                double roll;
                double pitch;
                double yaw;
                double min;
                double max;
        public:
                CDeviceParameters(std::vector<string>& tokens){                 
                        if (tokens.size() != 9) return ;

                        deviceName = tokens[0];                 
                        try
                        {
                                x = atof(tokens[1].c_str());
                                y = atof(tokens[2].c_str()); 
                                z = atof(tokens[3].c_str());
                                roll    = atof(tokens[4].c_str());
                                pitch   = atof(tokens[5].c_str());
                                yaw = atof(tokens[6].c_str());                          
                                min = atof(tokens[7].c_str());
                                max = atof(tokens[8].c_str());
                        }
                        catch (std::exception& e)
                        {
                                std::cerr << e.what() << "tokens error\n";
                        }
                        
                }
                string getDeviceName(){return deviceName;}
                double getX(){return x;}
                double getY(){return y;}
                double getZ(){return z;}
                double getRoll(){return roll;}
                double getPitch(){return pitch;}
                double getYaw(){return yaw;}
                double getMin(){return min;}
                double getMax(){return max;}
                
        };
}       // namespace OPRoS 
