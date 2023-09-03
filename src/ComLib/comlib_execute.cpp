/**
  ******************************************************************************
  * @file    comlib_execute.cpp
  * @author  徐哲轩
  * @brief   串口接受处理函数
  * @verbatim
  * @endverbatim
  ******************************************************************************  
*/ 

#include "Comlib.h"

void Usart_Uno_1Claw(COMFrame *Frame)
{
    char temp = Frame->Data.uint8_ts[0];
    switch (temp)
    {
        
    case 0x00:  UnoState = UNO_SLEEP;   break;
    case 0x01:  UnoState = UNO_WAKEUP;  break; 

    default:break;
    }
}