/**
  ******************************************************************************
  * @file    Arduino_Command.cpp
  * @author  徐哲轩
  * @brief   串口无协议输出
  * @verbatim
  * @endverbatim
  ******************************************************************************  
*/ 

#include "ComPropList.h"

void UART_SendByte(uint8_t USARTx,uint8_t data)
{
    switch (USARTx)
    {
    #ifdef USART_SERIAL0
        case USART_0:USART_SERIAL0.print(data);break;
    #endif 

    #ifdef USART_SERIAL1
        case USART_1:USART_SERIAL1.print(data);break;
    #endif 

    #ifdef USART_SERIAL2
        case USART_2:USART_SERIAL2.print(data);break;
    #endif 

    #ifdef USART_SERIAL3
        case USART_3:USART_SERIAL3.print(data);break;
    #endif 
    
    #ifdef USART_SERIAL4
        case USART_4:USART_SERIAL4.print(data);break;
    #endif 

    default:
        break;
    }	
}


void UART_SendString(uint8_t USARTx,String string)
{
    switch (USARTx)
    {
    #ifdef USART_SERIAL0
        case USART_0:USART_SERIAL0.print(string);break;
    #endif 

    #ifdef USART_SERIAL1
        case USART_1:USART_SERIAL1.print(string);break;
    #endif 

    #ifdef USART_SERIAL2
        case USART_2:USART_SERIAL2.print(string);break;
    #endif 

    #ifdef USART_SERIAL3
        case USART_3:USART_SERIAL3.print(string);break;
    #endif 
    
    #ifdef USART_SERIAL4
        case USART_4:USART_SERIAL4.print(string);break;
    #endif 

    default:
        break;
    }	
}

void UART_SendInt(uint8_t USARTx,int Num)
{
    switch (USARTx)
    {
    #ifdef USART_SERIAL0
        case USART_0:USART_SERIAL0.print(Num);break;
    #endif 

    #ifdef USART_SERIAL1
        case USART_1:USART_SERIAL1.print(Num);break;
    #endif 

    #ifdef USART_SERIAL2
        case USART_2:USART_SERIAL2.print(Num);break;
    #endif 

    #ifdef USART_SERIAL3
        case USART_3:USART_SERIAL3.print(Num);break;
    #endif 
    
    #ifdef USART_SERIAL4
        case USART_4:USART_SERIAL4.print(Num);break;
    #endif 
    default:
        break;
    }	
}

void UART_SendChars(uint8_t USARTx,char* string)
{
    switch (USARTx)
    {
    #ifdef USART_SERIAL0
        case USART_0:USART_SERIAL0.print(string);break;
    #endif 

    #ifdef USART_SERIAL1
        case USART_1:USART_SERIAL1.print(string);break;
    #endif 

    #ifdef USART_SERIAL2
        case USART_2:USART_SERIAL2.print(string);break;
    #endif 

    #ifdef USART_SERIAL3
        case USART_3:USART_SERIAL3.print(string);break;
    #endif 
    
    #ifdef USART_SERIAL4
        case USART_4:USART_SERIAL4.print(string);break;
    #endif 

    default:
        break;
    }	
}
