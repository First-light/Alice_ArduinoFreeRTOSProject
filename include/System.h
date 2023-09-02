#ifndef _SYSTEM_H_
#define _SYSTEM_H_
//问题：
//1.尽可能减少头文件的添加
//2.因为Arduino性能 vTaskDelay(20/portTICK_PERIOD_MS);最低delay20ms

/******************************系统头文件**********************************/
#include <Arduino_FreeRTOS.h>
#include <Arduino.h>
#include <string.h>
/******************************参数宏定义**********************************/
#define USART_BaudRate              115200

#define USART_IRQHandler_STK            128
#define USART_IRQHandler_PRI            0x10
#define USART_Buffer_STK                128

#define Task_RGBLED_STK                 64
#define Task_RGBLED_PRI                 0x00

#define Task_State_STK                  128
#define Task_State_PRI                  0x10

/******************************引脚定义**********************************/

#define RGB_PIN_RED                 9
#define RGB_PIN_GREED               10
#define RGB_PIN_BLUE                11
#define LED_BOARD                   13

//注意13 11 10 9 8 7号脚pwm有问题
/******************************初始化函数定义**********************************/
void Device_Init();
/******************************核心函数定义**********************************/
void USART_IRQHandler(void);
void Task_State();
//数值转化函数
int32_t INT_CHAR_Change(char* ar);
void CHAR_INT_Change(char* ar2,int32_t b);
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
extern char USART_Buffer[USART_Buffer_STK];
extern Uno_State_Typedef UnoState; 
extern Uno_ERROR_Typedef UnoError; 

#endif 