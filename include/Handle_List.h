/**
  ******************************************************************************
  * @file    Handle_List.h
  * @author  徐哲轩
  * @brief   任务控制块链表头文件
  * @verbatim
  *             本头文件定义已下内容：
  *             -任务控制块链表节点结构体
  *             -链表操作函数声明
  *             （如需要添加新的链表种类或者函数，可以在Handle_List.c里添加。并维护这里）
  * @endverbatim
  ******************************************************************************  
*/ 
#ifndef _HANDLE_LIST_H_
#define _HANDLE_LIST_H_

#include <Arduino_FreeRTOS.h>
#include <Arduino.h>

typedef struct handlelist {
    TaskHandle_t*      Handle;
    struct handlelist* next;
}HandleList;

void HList_Insert_T(HandleList* List,TaskHandle_t* H);
void HList_TaskOverALL(HandleList* List);

#endif 