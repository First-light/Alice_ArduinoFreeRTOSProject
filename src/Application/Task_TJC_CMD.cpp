#include "ComProplist.h"
#include "TaskBasic.h"

#ifdef USE_DEV_TJC
    
typedef enum{
    LAN_NULL,
    LAN_UNO_WAKEUP,
    LAN_UNO_SLEEP,
    LAN_ALICE_BYE,
}LanguageType;

typedef struct language {
    const char* code;
    LanguageType type;
}Language;

//函数声明
void Alice_ReplyInput(uint8_t USARTx,char* string,String reply);
void Alice_Tip(uint8_t USARTx,char* string);
void Alice_Chat(uint8_t USARTx,String string);
void WaitInput(uint8_t USARTx);
void CMDReply();
void CMDClear();
void CMDlanguage(char* cmd);

//语言声明
Language LanguageList[] = {
    {"uno wakeup",LAN_UNO_WAKEUP},
    {"uno sleep",LAN_UNO_SLEEP},
    {"bye",LAN_ALICE_BYE},
};

const uint16_t LanguageCount =  sizeof(LanguageList)/
                                sizeof(LanguageList[0]);

//函数                           
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
                CMDlanguage(CMD_Stack);
                CMDClear();
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

void CMDlanguage(char* cmd)
{
    LanguageType lang = LAN_NULL;
    Language* p = LanguageList;
    for (size_t i = 0; i < LanguageCount; i++)
    {
        if (strcmp(cmd, p->code) == 0)
        {
            lang = p->type;
            break;
        }
        p++;
    }
    switch (lang)
    {

    case LAN_UNO_WAKEUP:
        UnoState = UNO_WAKEUP; 
        Alice_ReplyInput(USART_LOG,CMD_Stack,"OK");
        break;

    case LAN_UNO_SLEEP:
        UnoState = UNO_SLEEP;
        Alice_ReplyInput(USART_LOG,CMD_Stack,"OK"); 
        break;
    case LAN_ALICE_BYE:
        CMDstate = CMD_OFF;
        break;
    default:
        Alice_ReplyInput(USART_LOG,CMD_Stack,"No Such Language");
        break;
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

#endif 