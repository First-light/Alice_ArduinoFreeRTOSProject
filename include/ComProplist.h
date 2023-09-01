/**
 ******************************************************************************
 * @file    ComProplist.h
 * @brief   串口发送及接收处理函数头文件，包含以下内容：
 *          - 各串口属性方法词典声明
 *          - 各串口属性值定义
 *          - 各串口方法函数声明
 * @verbatim
 *          添加新的处理函数后要对这里进行维护
 * @endverbatim
 * @edit date
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
