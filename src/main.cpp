/**
  ******************************************************************************
  * @file    main.cpp
  * @author  徐哲轩
  * @brief   主函数
  * @verbatim
  *         FreeRTOS基本框架
  *         支持Arduino Uno，Mega等Arduino 系列板
  *         最低可在2KB RAM下运行，若RAM过小可能出现BUG
  *         基于vscode 的 platformio 开发平台
  *         最后一次修改于2023/9/3
  * @endverbatim
  ******************************************************************************  
*/ 

#include "Include.h"
/******************************变量定义**********************************/

Uno_State_Typedef UnoState = UNO_SLEEP; 
CMDStateTypedef CMDstate = CMD_OFF;
char CMD_Stack[CMD_MAX_STACK] = {0};

StackType_t USART_IRQHandlerStack[USART_IRQHandler_STK];
StaticTask_t USART_IRQHandler_TCB;
char USART_Receive_Buffer[USART_Buffer_STK];

StackType_t Task_StateStack[Task_State_STK];
StaticTask_t Task_State_TCB;

TaskHandle_t Task_CMD_Handle;

HandleList* Tasks = NULL;


/******************************主函数**********************************/
void setup() 
{
  Device_Init();
  UART_SendString(USART_LOG,"Device Ready\n");
  xTaskCreateStatic(  (TaskFunction_t     ) USART_IRQHandler,
                      (const char *const  ) "USART_IRQHandler",
                      (const uint32_t     ) USART_IRQHandler_STK,
                      (void *const        ) NULL,
                      (UBaseType_t        ) USART_IRQHandler_PRI,
                      (StackType_t *const ) USART_IRQHandlerStack,  
                      (StaticTask_t*const ) &USART_IRQHandler_TCB ); 

  xTaskCreateStatic((TaskFunction_t     ) Task_State,
                    (const char *const  ) "Task_State",
                    (const uint32_t     ) Task_State_STK,
                    (void *const        ) NULL,
                    (UBaseType_t        ) Task_State_PRI,
                    (StackType_t *const ) Task_StateStack,  
                    (StaticTask_t*const ) &Task_State_TCB ); 

  vTaskStartScheduler();  
  UART_SendString(USART_LOG,"Main Task Ready\n");
  UART_SendString(USART_LOG,"Wait Your Open\n");
}

void loop() 
{
  //不需要写东西
}
