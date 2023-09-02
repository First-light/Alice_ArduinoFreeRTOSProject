#ifndef _TASKBASIC_H_
#define _TASKBASIC_H_
/******************************任务宏**********************************/
#define CMD_MAX_STACK           64
/******************************类型**********************************/
typedef enum {
    CMD_OFF,
    CMD_ON,
}CMDStateTypedef;

/******************************任务函数**********************************/
//任务及内存分配
extern Uno_State_Typedef UnoState; 
//核心任务

extern StackType_t USART_IRQHandlerStack[USART_IRQHandler_STK];
extern StaticTask_t USART_IRQHandler_TCB;

extern StackType_t Task_StateStack[Task_State_STK];
extern StaticTask_t Task_State_TCB;
// Task_State
/******************************任务变量声明**********************************/
extern char USART_Receive_Buffer[USART_Buffer_STK];
extern char CMD_Stack[64];
extern CMDStateTypedef CMDstate;
#endif 