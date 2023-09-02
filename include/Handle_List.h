
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