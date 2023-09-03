#include "ComProplist.h"
#include "TaskBasic.h"
/**
  ******************************************************************************
  * @file    task_Basic.cpp
  * @author  徐哲轩
  * @brief   基础任务
  * @verbatim
  *         （需要一直运行的任务）
  * @endverbatim
  ******************************************************************************  
*/ 

void Uno_WakingUp();
void Uno_Waiting();

void Task_State()//软开关检测
{
    while (1)
    {
        if(UnoState == UNO_SLEEP)
        {
            UART_SendString(USART_LOG,"UnoState : Uno_Sleep\n");
            while(UnoState == UNO_SLEEP)
            {
                digitalWrite(LED_BOARD,HIGH);
                vTaskDelay(50/portTICK_PERIOD_MS);
                Uno_Waiting();
                digitalWrite(LED_BOARD,LOW);
                vTaskDelay(450/portTICK_PERIOD_MS);
            }
        }else 
        if(UnoState == UNO_WAKEUP)
        {
            UART_SendString(USART_LOG,"UnoState : Uno_Waking \n");
            Uno_WakingUp();
            UART_SendString(USART_LOG,"ALL Task Running\n");
            while(UnoState == UNO_WAKEUP)vTaskDelay(100/portTICK_PERIOD_MS);
        }
        vTaskDelay(100/portTICK_PERIOD_MS);
    }
}

void Uno_WakingUp()//在这里可以写需要正式执行的任务
{
  digitalWrite(LED_BOARD,HIGH);
  taskENTER_CRITICAL();           //进入临界区
  
  taskEXIT_CRITICAL();            //退出临界区
}

void Uno_Sleeping()//在这里可以删除所有不需要一直运行的任务
{
  taskENTER_CRITICAL();

  taskEXIT_CRITICAL();   
}

void Uno_Waiting()//无伪中断时也可以处理数据,可以不使用
{
   if( Serial.available()) 
    {
      uint8_t count = 0;
      uint16_t temp;
      char temp_char;
      while(Serial.available())//取完所有数据
      {
        temp = Serial.read();
        temp_char = (char)temp;
        if(UnoState == UNO_WAKEUP)//复制一份给处理函数
        {
          Get_Frame_COM(temp,&MY_USART0);
        }
        if(count <= CMD_MAX_STACK-1-1)//复制一份给CMD缓冲区
        {
          CMD_Stack[count] = temp_char;
          count++;
        }
      }
      CMD_Stack[count] = '\0';//结尾
      if(strcmp(CMD_Stack,"Alice") == 0 && CMDstate == CMD_OFF)//CMD唤醒词
      {
        Open_Task_CMD();
      }
    }
    vTaskDelay(100/portTICK_PERIOD_MS);//每100ms读一次串口
}