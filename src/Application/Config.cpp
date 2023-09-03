/**
  ******************************************************************************
  * @file    Config.cpp
  * @author  徐哲轩
  * @brief   伪中断
  * @verbatim
  * @endverbatim
  ******************************************************************************  
*/ 

#include "ComProplist.h"
#include "TaskBasic.h"

void USART_IRQHandler()//伪中断
{
  while(1)
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
}
