//
//  SerialPort.cpp
//  AX12A_drive
//
//  Created by 西北偏北 on 2020/7/31.
//  Copyright © 2020 西北偏北. All rights reserved.
//

#if !defined (__SAM3X8E__)
// When set, _DEBUG co-opts pins 11 and 13 for debugging with an
// oscilloscope or logic analyzer.  Beware: it also slightly modifies
// the bit times, so don't rely on it too much at high baud rates
#define _DEBUG 0
#define _DEBUG_PIN1 11
#define _DEBUG_PIN2 13

#include "SerialPort.hpp"

//
// Statics
//
SerialPort *SerialPort::active_object = 0;
char SerialPort::_receive_buffer[_SS_MAX_RX_BUFF];
volatile int SerialPort::_receive_buffer_tail = 0;
volatile int SerialPort::_receive_buffer_head = 0;

//
// Debugging
//
// This function generates a brief pulse
// for debugging or measuring on an oscilloscope.
#if _DEBUG
inline void DebugPulse(int pin, int count)
{
  volatile int *pport = portOutputRegister(digitalPinToPort(pin));

  int val = *pport;
  while (count--)
  {
    *pport = val | digitalPinToBitMask(pin);
    *pport = val;
  }
}
#else
inline void DebugPulse(int, int) {}
#endif

//
// Private methods
//


//
// The receive routine called by the interrupt handler
//
void SerialPort::recv()
{

}

#if defined(PCINT0_vect)
ISR(PCINT0_vect)
{
  SerialPort::handle_interrupt();
}
#endif

#if defined(PCINT1_vect)
ISR(PCINT1_vect, ISR_ALIASOF(PCINT0_vect));
#endif

#if defined(PCINT2_vect)
ISR(PCINT2_vect, ISR_ALIASOF(PCINT0_vect));
#endif

#if defined(PCINT3_vect)
ISR(PCINT3_vect, ISR_ALIASOF(PCINT0_vect));
#endif

//
// Constructor
//
//SerialPort::SerialPort(){}；
//
// Destructor
//

bool SerialPort::isListening()
{
    return false;
}

long SerialPort::subtract_cap(long num, long sub) {
  if (num > sub)
    return num - sub;
  else
    return 1;
}

void SerialPort::setRxIntMsk(bool enable)
{
    if (enable)
      *_pcint_maskreg |= _pcint_maskvalue;
    else
      *_pcint_maskreg &= ~_pcint_maskvalue;
}

//
// Public methods
//




// Read data from buffer
int SerialPort::read()
{
  if (!isListening())
    return -1;

  // Empty buffer?
  if (_receive_buffer_head == _receive_buffer_tail)
    return -1;

  // Read from "head"
  int d = _receive_buffer[_receive_buffer_head]; // grab next byte
  _receive_buffer_head = (_receive_buffer_head + 1) % _SS_MAX_RX_BUFF;
  return d;
}

int SerialPort::available()
{
  if (!isListening())
    return 0;

  return (_receive_buffer_tail + _SS_MAX_RX_BUFF - _receive_buffer_head) % _SS_MAX_RX_BUFF;
}

size_t SerialPort::write(int b)
{
  
  printf("1 okkkkkkkkkk\n %d \n",b);
  return 1;
  // return 1;
}

size_t SerialPort::write(const unsigned char *buffer, /*size_t*/ int size)
{

    printf("size:%d\n",size);
    
    for (int i=0; i<size; i++) {
        printf("%02x ",buffer[i]);
    }
  printf("\n2 okkkkkkkkkk\n",*buffer);
  return size;
}

void SerialPort::flush()
{
  // There is no tx buffering, simply return
}

void SerialPort::flushRx()
{
  // simply reinitialize the buffer
  _receive_buffer_head = _receive_buffer_tail = 0;

}





#endif  // (__SAM3X8E__)
