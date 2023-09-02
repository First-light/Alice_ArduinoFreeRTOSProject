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
      while(Serial.available())
      {
        temp = Serial.read();
        temp_char = (char)temp;
        Get_Frame_COM(temp,&MY_USART0);
        if(count <= CMD_MAX_STACK-1-1)
        {
          CMD_Stack[count] = temp_char;
          count++;
        }
      }
      CMD_Stack[count] = '\0';
      if(strcmp(CMD_Stack,"Alice") == 0 && CMDstate == CMD_OFF)
      {
        Open_Task_CMD();
      }
    }
    vTaskDelay(100/portTICK_PERIOD_MS);//每100ms读一次串口
  }
}
