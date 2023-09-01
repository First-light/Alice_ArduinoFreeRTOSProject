#include "System.h"

void Device_Init()
{
  Serial.begin(USART_BaudRate);
  pinMode(LED_BOARD,OUTPUT);
}



