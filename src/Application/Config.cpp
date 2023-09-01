#include "Comlib.h"

void USART_IRQHandler()//伪中断
{
  while(1)
  {
    if( Serial.available()) 
    {
      uint16_t temp;
      while(Serial.available())
      {
        temp = Serial.read();
        Get_Frame_COM(temp,&MY_USART0);
      }
    }
    vTaskDelay(100);//每100ms读一次串口，读取255字节
  }
}
