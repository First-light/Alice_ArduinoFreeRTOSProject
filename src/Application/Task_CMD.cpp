#include "ComProplist.h"
#include "TaskBasic.h"

//函数声明
void Alice_ReplyInput(uint8_t USARTx,char* string);
void Alice_Tip(uint8_t USARTx,char* string);
void Alice_Chat(uint8_t USARTx,String string);

void Task_CMD(void)
{
    while (1)
    {
        if (CMDstate == CMD_ON)
        {
            Alice_Chat(USART_LOG,"/nHello,Nice to meet you./n");
            UART_SendString(USART_LOG,">");
        }else 
        if (CMDstate == CMD_OFF)
        {
            Alice_Chat(USART_LOG,"/nSee you soon./n");
            vTaskDelete(NULL);
        }
    }
}

void Alice_ReplyInput(uint8_t USARTx,char* string)
{
    UART_SendString(USARTx,"Alice :/ ");
    UART_SendChars(USARTx,string);
    UART_SendString(USARTx," /: ");
}

void Alice_Chat(uint8_t USARTx,String string)
{
    UART_SendString(USARTx,"Alice : ");
    UART_SendString(USARTx,string);
}

void Alice_Tip(uint8_t USARTx,char* string)
{
    UART_SendString(USARTx,"Alice : ");
    UART_SendChars(USARTx,string);
}