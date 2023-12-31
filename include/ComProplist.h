/**
  ******************************************************************************
  * @file    ComProplist.h
  * @author  徐哲轩
  * @brief   串口协议字典头文件
  * @verbatim
  *             本头文件定义已下内容：
  *             -串口号及其标签的宏
  *             -字典数组声明
  *             -字典属性值
  *             -处理函数声明
  *             -发送函数声明
  * @endverbatim
  ******************************************************************************  
  */ 
#ifndef _COMPROPLIST_H_
#define _COMPROPLIST_H_

#include "ComLib.h"

/* ************************************ 全局声明 **************************************** */


#define USART_0 0
#define USART_1 1
#define USART_2 2
#define USART_3 3
#define USART_4 4

#define USART_SERIAL0 Serial
/*
#define USART_SERIAL1 Serial1
#define USART_SERIAL2 Serial2
#define USART_SERIAL3 Serial3
#define USART_SERIAL4 Serial4
*/
#define USART_LOG           USART_0
#define USART_LOG_SERIAL    USART_SERIAL0

/* ************************************ 字典声明 **************************************** */

extern COMFunDict My_USART1_Prop_Array[];
extern COMFunDict My_USART2_Prop_Array[];
extern COMFunDict My_USART3_Prop_Array[];
extern COMFunDict My_USART4_Prop_Array[];

/* ************************************ 属性值 **************************************** */

#define USART_UNO_1CLAW 0x99

/* ************************************ 处理函数 **************************************** */
void Usart_Uno_1Claw(COMFrame *Frame);

/* ************************************ 发送函数 **************************************** */
	 
#endif
