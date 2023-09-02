#ifndef _TASKBASIC_H_
#define _TASKBASIC_H_
/******************************任务宏**********************************/
#define USART_IRQHandler_STK            128
#define USART_IRQHandler_PRI            0x10
#define USART_Buffer_STK                128

#define Task_RGBLED_STK                 64
#define Task_RGBLED_PRI                 0x00

#define Task_State_STK                  128
#define Task_State_PRI                  0x10

#define Task_CMD_STK                    128
#define Task_CMD_PRI                    0x09
#define CMD_MAX_STACK                   64
/******************************类型**********************************/
typedef enum {
    CMD_OFF,
    CMD_ON,
}CMDStateTypedef;

/******************************任务函数**********************************/
void Task_CMD(void);
void Open_Task_CMD(void);

//任务及内存分配
extern Uno_State_Typedef UnoState; 

extern StackType_t USART_IRQHandlerStack[USART_IRQHandler_STK];
extern StaticTask_t USART_IRQHandler_TCB;

extern StackType_t Task_StateStack[Task_State_STK];
extern StaticTask_t Task_State_TCB;

extern TaskHandle_t Task_CMD_Handle;
extern StaticTask_t Task_CMD_TCB;
extern CMDStateTypedef CMDstate;
/******************************任务变量声明**********************************/
extern char USART_Receive_Buffer[USART_Buffer_STK];
extern char CMD_Stack[CMD_MAX_STACK];

#endif 