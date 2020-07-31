//
//  DynamixelAx.hpp
//  AX12A_drive
//
//  Created by 西北偏北 on 2020/7/31.
//  Copyright © 2020 西北偏北. All rights reserved.
//

#ifndef DynamixelAx_hpp
#define DynamixelAx_hpp

#include <stdio.h>
#include "SerialPort.hpp"
#include "Dynamixel.hpp"


class dxlAx : public dxl
{
public:
  // public methods
  dxlAx(SerialPort* port);
 
  bool setCWComplianceMargin(const byte  ID, const byte margin);
  bool readCWComplianceMargin(const byte ID);

  bool setCCWComplianceMargin(const byte  ID, const byte margin);
  bool readCCWComplianceMargin(const byte ID);

  bool setCWComplianceSlope(const byte  ID, const byte slope);
  bool readCWComplianceSlope(const byte ID);

  bool setCCWComplianceSlope(const byte  ID, const byte slope);
  bool readCCWComplianceSlope(const byte ID);

};


#endif /* DynamixelAx_hpp */
