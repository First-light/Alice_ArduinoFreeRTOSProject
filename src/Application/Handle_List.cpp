#include "Handle_List.h"
/**
  ******************************************************************************
  * @file    Handle_List.cpp
  * @author  徐哲轩
  * @brief   任务块链表
  * @verbatim
  * @endverbatim
  ******************************************************************************  
*/ 
void HList_Insert_T(HandleList* List,TaskHandle_t* H)//尾插节点，只需要一个链表头就可以创建
{
    if(List == NULL)//如果链表无节点，创建一个节点
    {
        HandleList  *L;
        L = (HandleList*)malloc(sizeof(HandleList));
        L->next = NULL;
        L->Handle = H;
        List = L;
    }
    else//如果链表有节点，尾插
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

void HList_TaskOverALL(HandleList* List)//删除链表里所有记录的任务，并删除链表
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