#include "Include.h"

Uno_State_Typedef UnoState = UNO_SLEEP; 
CMDStateTypedef CMDstate = CMD_OFF;
char CMD_Stack[CMD_MAX_STACK] = {0};

StackType_t USART_IRQHandlerStack[USART_IRQHandler_STK];
StaticTask_t USART_IRQHandler_TCB;
char USART_Receive_Buffer[USART_Buffer_STK];

StackType_t Task_StateStack[Task_State_STK];
StaticTask_t Task_State_TCB;

TaskHandle_t Task_CMD_Handle;
/******************************变量定义**********************************/

void setup() 
{
  Device_Init();

  printf("硬件初始化完成！");

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
    printf("操作系统初始化完成！");
}

void loop() 
{

}
