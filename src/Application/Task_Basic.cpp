#include "ComProplist.h"

void Uno_WakingUp();
void Uno_Waiting();

void Task_State()
{
    while (1)
    {
        if(UnoState == UNO_SLEEP)
        {
            printf("待机中，等待开机信号\n");
            while(UnoState == UNO_SLEEP)
            {
                digitalWrite(LED_BOARD,HIGH);
                vTaskDelay(50/portTICK_PERIOD_MS);
                Uno_Waiting();
                UART_SendByte(0,0x01);
                digitalWrite(LED_BOARD,LOW);
                vTaskDelay(450/portTICK_PERIOD_MS);
            }
        }else 
        if(UnoState == UNO_WAKEUP)
        {
            printf("开机中。。。\n");
            Uno_WakingUp();
            printf("启动成功\n");
            while(UnoState == UNO_WAKEUP)vTaskDelay(100/portTICK_PERIOD_MS);
        }
        vTaskDelay(100/portTICK_PERIOD_MS);
    }
}

void Uno_WakingUp()
{
  taskENTER_CRITICAL();           //进入临界区
  digitalWrite(LED_BOARD,HIGH);

  taskEXIT_CRITICAL();            //退出临界区
}


void Uno_Waiting()
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
}