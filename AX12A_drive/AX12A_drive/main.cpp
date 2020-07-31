//
//  main.cpp
//  AX12A_drive
//
//  Created by 西北偏北 on 2020/7/31.
//  Copyright © 2020 西北偏北. All rights reserved.
//

#include <iostream>
#include "SerialPort.hpp"
#include "DynamixelAx.hpp"




int main(int argc, const char * argv[]) {
    // insert code here...
    //std::cout << "Hello, World!\n";
    
    SerialPort port;
    dxlAx dxlCom(&port);
    
    dxlCom.ping(1);
    
    unsigned char Data[7];
    Data[0] = 0xff;
    Data[1] = 0xff;
    Data[2] = 0x01;
    Data[3] = 0x02;
    Data[4] = 0x00;
    Data[5] = 0xfc;
    port.init_Data(Data);
    printf("%02x",dxlCom.readDxlResult());
//    //dxlCom.setGoalPosition(1, 1023);

    return 0;
}
