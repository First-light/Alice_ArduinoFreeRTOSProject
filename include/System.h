/**
  ******************************************************************************
  * @file    System.h
  * @author  徐哲轩
  * @brief   系统头文件
  * @verbatim
  *             本头文件定义已下内容：
  *             -包含所有用于数值转换，函数定义的.h文件
  *             -系统参数宏
  *             -引脚标签
  *             -一些基本定义
  * @endverbatim
  ******************************************************************************  
*/ 
#ifndef _SYSTEM_H_
#define _SYSTEM_H_

//问题：
//1.尽可能减少头文件的添加，减少内存消耗
//2.因为Arduino性能 vTaskDelay(20/portTICK_PERIOD_MS);最低delay20ms

/******************************系统头文件**********************************/
#include <Arduino_FreeRTOS.h>
#include <Arduino.h>
#include <string.h>
#include "Device.h"
#include "Handle_List.h"
/******************************参数宏定义**********************************/
#define USART_BaudRate              115200
/******************************引脚定义**********************************/

#define RGB_PIN_RED                 9
#define RGB_PIN_GREED               10
#define RGB_PIN_BLUE                11
#define LED_BOARD                   13

/******************************初始化函数定义**********************************/
void Device_Init();//硬件初始化

/******************************核心函数定义**********************************/

void USART_IRQHandler(void);//串口伪中断
void Task_State();//初始任务创建

//数值转化函数
int32_t INT_CHAR_Change(char* ar);//char转int
void CHAR_INT_Change(char* ar2,int32_t b);//int转char，输出到ar2
/******************************枚举定义**********************************/
typedef enum {
    UNO_SLEEP,
    UNO_WAKEUP
}Uno_State_Typedef;

typedef enum {
    ZERO_ERROR,
    ERROR_TaskInitFalse,
    ERROR_DeviceInitFalse,
}Uno_ERROR_Typedef;

/******************************变量定义**********************************/

extern Uno_State_Typedef UnoState; 
extern Uno_ERROR_Typedef UnoError; 

#endif 