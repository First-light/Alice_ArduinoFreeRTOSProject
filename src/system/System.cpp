/**
  ******************************************************************************
  * @file    System.cpp
  * @author  徐哲轩
  * @brief   硬件设备初始化
  * @verbatim
  * @endverbatim
  ******************************************************************************  
*/ 

#include "System.h"

void Device_Init()
{
  Serial.begin(USART_BaudRate);
  pinMode(LED_BOARD,OUTPUT);
}



