//
//  SerialPort.hpp
//  AX12A_drive
//
//  Created by 西北偏北 on 2020/7/31.
//  Copyright © 2020 西北偏北. All rights reserved.
//

#ifndef SerialPort_hpp
#define SerialPort_hpp

#include <stdio.h>

#define _SS_MAX_RX_BUFF 64 // RX buffer size
#ifndef GCC_VERSION
#define GCC_VERSION (__GNUC__ * 10000 + __GNUC_MINOR__ * 100 + __GNUC_PATCHLEVEL__)
#endif

class SerialPort
{
private:
    // per object data
    int _dataPin;
    int _dataBitMask;
    volatile int *_transmitPortRegister;
    volatile int *_receivePortRegister;
    volatile int *_pcint_maskreg;
    int _pcint_maskvalue;
    unsigned char Data[7];    //接收到的数据
    unsigned char  nByteToBeRead; //应该读取的字节数
    
    // Expressed as 4-cycle delays (must never be 0!)
    int _rx_delay_centering;
    int _rx_delay_intrabit;
    int _rx_delay_stopbit;
    int _tx_delay;
    
    long _buffer_overflow:1;
    //uint16_t _inverse_logic:1;
    
    // static data
    static char _receive_buffer[_SS_MAX_RX_BUFF];
    static volatile int _receive_buffer_tail;
    static volatile int _receive_buffer_head;
    static SerialPort *active_object;
    
    // private methods
    inline void recv() __attribute__((__always_inline__));
    
    inline void setRxIntMsk(bool enable) __attribute__((__always_inline__));
    
    // Return num - sub, or 1 if the result would be < 1
    static long subtract_cap(long num, long sub);
    
    
public:
    // public methods
    bool listen();
    
    bool isListening();
    bool overflow() { bool ret = _buffer_overflow; if (ret) _buffer_overflow = false; return ret; }
    
    
    virtual size_t write(int b);
    virtual size_t write(const unsigned char *buffer, /*size_t*/ int size);
    virtual unsigned char * read();
    virtual int available();
    virtual void flush();
    virtual void flushRx();
    operator bool() { return true; }
    
    //读写标志位
    bool downDirectionPort();  //接收
    bool upDirectionPort();   //发送
    
    //初始化接收数据
    void init_Data(unsigned char * data);
    //设置应该读取的字节数
    void setnByteToBeRead(unsigned char a);
};

#endif /* SerialPort_hpp */
