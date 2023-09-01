/**
 ******************************************************************************
 * @file    comlib_proplist.c
 * @author  
 * @brief   本代码提供了COM消息处理函数词典的定义:

 *  @verbatim
 *          本字典用于ProcessFrame()中根据属性值查找对应的消息处理函数
 * 		     根据需求在ExecuteLib.c中添加相应的消息处理函数后，更新相应的proplist.c，
 * 		     在头文件中设置相应的属性值
 *  @endverbatim
 ******************************************************************************
 */
#include "ComProplist.h"

/*******************************属性和方法字典***********************************/

COMFunDict My_USART0_Prop_Array[] = { //传感器
	{USART_UNO_1CLAW,Usart_Uno_1Claw},
};

Arduino_COM_typedef MY_USART0 ={(const uint8_t)     0,
                                (const uint8_t)     sizeof(My_USART0_Prop_Array)/
                                                    sizeof(My_USART0_Prop_Array[0]),
                                (COMFunDict* )      My_USART0_Prop_Array,
                                };






