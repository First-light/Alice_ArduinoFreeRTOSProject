#include "ComProplist.h"

void Uno_WakingUp();
void Uno_Waiting();

void Task_State()
{
    while (1)
    {
        if(UnoState == UNO_SLEEP)
        {
            UART_SendString(USART_LOG,"Uno_Sleep");
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
            UART_SendString(USART_LOG,"Uno_Waking :");
            Uno_WakingUp();
            printf("Complete !\n");
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

void Uno_Sleeping()
{
  taskENTER_CRITICAL();

  taskEXIT_CRITICAL();   
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