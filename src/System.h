#ifndef _SYSTEM_H_
#define _SYSTEM_H_
//问题：
//1.尽可能减少头文件的添加
//2.因为Arduino性能 vTaskDelay(20/portTICK_PERIOD_MS);最低delay20ms

/******************************系统头文件**********************************/
#include <Arduino_FreeRTOS.h>
#include <Arduino.h>
/******************************参数宏定义**********************************/
#define USART_BaudRate              115200

//task
#define USART_IRQHandler_STK        128
#define USART_IRQHandler_PRI        0x10
#define USART_Buffer_STK            256

#define Task_RGBLED_STK             64
#define Task_RGBLED_PRI             0x00

#define Task_BoardLED_STK             32
#define Task_BoardLED_PRI             0x00
/******************************引脚定义**********************************/
#define RGB_PIN_RED                 9
#define RGB_PIN_GREED               10
#define RGB_PIN_BLUE                11
#define LED_BOARD                   13

//注意13 11 10 9 8 7号脚pwm有问题
/******************************进程函数定义**********************************/
void System_Init(void);
void Device_Init();
void Task_Start(void);
void Alice_WakingUp();

void USART_IRQHandler(void);

void Task_RGBLED();
/******************************枚举定义**********************************/
typedef enum {
    UNO_SLEEP,
    UNO_WAKEUP
}Uno_State_Typedef;

/******************************变量定义**********************************/
extern char USART_Buffer[USART_Buffer_STK];
extern Uno_State_Typedef UnoState; 

#endif 