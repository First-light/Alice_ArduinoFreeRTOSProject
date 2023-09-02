#include "ComProplist.h"
#include "TaskBasic.h"



//函数声明
void Alice_ReplyInput(uint8_t USARTx,char* string,String reply);
void Alice_Tip(uint8_t USARTx,char* string);
void Alice_Chat(uint8_t USARTx,String string);
void WaitInput(uint8_t USARTx);
void CMDReply();
void CMDClear();

void Task_CMD(void)
{
    while (1)
    {
        if (CMDstate == CMD_ON)
        {
            Alice_Chat(USART_LOG,"Hello,Nice to meet you.");
            CMDClear();
            while(CMDstate == CMD_ON)
            {
                WaitInput(USART_LOG);
                vTaskDelay(100/portTICK_PERIOD_MS);
            }
        }else 
        if (CMDstate == CMD_OFF)
        {
            Alice_Chat(USART_LOG,"See you soon.");
            vTaskDelete(NULL);
        }

    }
}
void CMDClear()
{
    for (size_t i = 0; i < CMD_MAX_STACK; i++)
    {
        CMD_Stack[i] = '\0';
    }
}

void CMDReply()
{
    UART_SendChars(USART_LOG,CMD_Stack);
}

void Alice_ReplyInput(uint8_t USARTx,char* string,String reply)
{
    UART_SendString(USARTx,"Alice : ");
    UART_SendChars(USARTx,string);
    UART_SendString(USARTx," : ");
    UART_SendString(USARTx,reply);
    UART_SendString(USARTx," \n");
}

void Alice_Chat(uint8_t USARTx,String string)
{
    UART_SendString(USARTx,"Alice : ");
    UART_SendString(USARTx,string);
    UART_SendString(USARTx,"\n");
}

void Alice_Tip(uint8_t USARTx,char* string)
{
    UART_SendString(USARTx,"Alice : ");
    UART_SendChars(USARTx,string);
}

void WaitInput(uint8_t USARTx)
{
    UART_SendString(USARTx,">");
    while(CMD_Stack[0] == '\0' || CMD_Stack[0] == 0xEE )vTaskDelay(100/portTICK_PERIOD_MS);
    UART_SendString(USARTx,CMD_Stack);
    UART_SendString(USARTx,"\n");
    Alice_ReplyInput(USARTx,CMD_Stack,"");
    CMDClear();
}

void Open_Task_CMD(void)
{
    CMDstate = CMD_ON;
    taskENTER_CRITICAL();
    xTaskCreate((TaskFunction_t     ) Task_CMD,
                (const char * const ) "Task_CMD", 
                (uint16_t           ) Task_CMD_STK,
                (void * const       ) NULL,
                (UBaseType_t        ) Task_CMD_PRI,
                (TaskHandle_t      *) &Task_CMD_Handle);
    taskEXIT_CRITICAL();
}