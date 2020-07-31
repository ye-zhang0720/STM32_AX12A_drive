//
//  DynamixelAx.cpp
//  AX12A_drive
//
//  Created by 西北偏北 on 2020/7/31.
//  Copyright © 2020 西北偏北. All rights reserved.
//

#include "DynamixelAx.hpp"
#include "DynamixelAxConfig.h"
#include "DynamixelConfig.h"

#define byte unsigned char

//
// Constructor
//

dxlAx::dxlAx(SerialPort* port): dxl(port)
{

}



//
//  RAM commands
//
bool dxlAx::setCWComplianceMargin(const byte  ID, const byte margin)
{ return sendDxlWrite(ID, DXL_ADD_CW_COMPLIANCE_MARGIN , &margin, 1 );}
bool dxlAx::readCWComplianceMargin(const byte ID)
{ return sendDxlRead(ID, DXL_ADD_CW_COMPLIANCE_MARGIN , 1); }

bool dxlAx::setCCWComplianceMargin(const byte  ID, const byte margin)
{ return sendDxlWrite(ID, DXL_ADD_CCW_COMPLIANCE_MARGIN , &margin, 1 );}
bool dxlAx::readCCWComplianceMargin(const byte ID)
{ return sendDxlRead(ID, DXL_ADD_CCW_COMPLIANCE_MARGIN , 1); }

bool dxlAx::setCWComplianceSlope(const byte  ID, const byte slope)
{ return sendDxlWrite(ID, DXL_ADD_CW_COMPLIANCE_SLOPE , &slope, 1 );}
bool dxlAx::readCWComplianceSlope(const byte ID)
{ return sendDxlRead(ID, DXL_ADD_CW_COMPLIANCE_SLOPE , 1); }

bool dxlAx::setCCWComplianceSlope(const byte  ID, const byte slope)
{ return sendDxlWrite(ID, DXL_ADD_CCW_COMPLIANCE_SLOPE , &slope, 1 );}
bool dxlAx::readCCWComplianceSlope(const byte ID)
{ return sendDxlRead(ID, DXL_ADD_CCW_COMPLIANCE_SLOPE , 1); } 


