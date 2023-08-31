#include "System.h"

char USART_Buffer[USART_Buffer_STK];

static TaskHandle_t Task_BoardLED_Handle;
StackType_t Task_BoardLEDStack[Task_BoardLED_STK];
StaticTask_t Task_BoardLED_TCB;

static TaskHandle_t USART_IRQHandler_Handle;
StackType_t USART_IRQHandlerStack[USART_IRQHandler_STK];
StaticTask_t USART_IRQHandler_TCB;

void System_Init(void)
{
  Device_Init();
  printf("硬件初始化完成！");
  Task_Start();
  printf("操作系统初始化完成！");

}

void Device_Init()
{
  Serial.begin(USART_BaudRate);
  pinMode(LED_BOARD,OUTPUT);
}

void Task_Start()
{
  Task_BoardLED_Handle = xTaskCreateStatic( (TaskFunction_t     ) Task_BoardLED,
                                            (const char *const  ) "Task_BoardLED",
                                            (const uint32_t     ) Task_BoardLED_STK,
                                            (void *const        ) NULL,
                                            (UBaseType_t        ) Task_BoardLED_PRI,
                                            (StackType_t *const ) Task_BoardLEDStack,  
                                            (StaticTask_t*const ) &Task_BoardLED_TCB );  

  USART_IRQHandler_Handle = xTaskCreateStatic(  (TaskFunction_t     ) USART_IRQHandler,
                                                (const char *const  ) "USART_IRQHandler",
                                                (const uint32_t     ) USART_IRQHandler_STK,
                                                (void *const        ) NULL,
                                                (UBaseType_t        ) USART_IRQHandler_PRI,
                                                (StackType_t *const ) USART_IRQHandlerStack,  
                                                (StaticTask_t*const ) &USART_IRQHandler_TCB );   

  vTaskStartScheduler();
}

void Alice_WakingUp();
{
  taskENTER_CRITICAL();           //进入临界区


  taskEXIT_CRITICAL();            //退出临界区
}

void Task_RGBLED()
{
  uint8_t Red     =   0;
  uint8_t Greem   =   0;
  uint8_t Yellow  =   0;
  while(1)
  {

  }
}

void Task_BoardLED()
{
  while(1)
  {
    if (UnoState == UNO_SLEEP)
    {
      digitalWrite(LED_BOARD,HIGH);
      vTaskDelay(100);
      digitalWrite(LED_BOARD,LOW);
      vTaskDelay(700);
    }
    else if(UnoState == UNO_WAKEUP)
    {
      digitalWrite(LED_BOARD,HIGH);
    }
    vTaskDelay(300);
  }
}

void USART_IRQHandler()//伪中断
{
  while(!Serial)vTaskDelay(100);//等待串口连接
  while(1)
  {
    if( Serial.available() ) 
    {
      Serial.readBytes( USART_Buffer,min( Serial.available(),USART_Buffer_STK-1-1) );  
    }
    vTaskDelay(100);//每100ms读一次串口，读取255字节
  }
}