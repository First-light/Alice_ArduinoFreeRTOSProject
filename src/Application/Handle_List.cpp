#include "Handle_List.h"

void HList_Insert_T(HandleList* List,TaskHandle_t* H)
{
    if(List == NULL)
    {
        HandleList  *L;
        L = (HandleList*)malloc(sizeof(HandleList));
        L->next = NULL;
        L->Handle = H;
        List = L;
    }
    else
    {
        HandleList * pre;
        pre = List ;
        while (pre->next != NULL)
        {
            pre = pre->next;
        }
        HandleList * N;
        N = (HandleList*)malloc(sizeof(HandleList));
        pre->next = N;
        N->Handle = H;
        N->next = NULL;
    }
}

void HList_TaskOverALL(HandleList* List)
{
    HandleList* pre = List;
    do{
        vTaskDelete(*(pre->Handle));
        pre = pre->next;
    }while(pre != NULL);
    pre = List;
    do{
        HandleList* lef = pre;
        pre = pre->next;
        free(lef);
    }while(pre != NULL);
}