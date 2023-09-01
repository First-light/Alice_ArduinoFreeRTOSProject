/**
  ******************************************************************************
  * @file    Comlib.h
  * @author  徐哲轩
  * @brief   
  * @verbatim
  * @endverbatim
  ******************************************************************************  
  */ 
#ifndef _COMLIB_H_
#define _COMLIB_H_

#include "System.h"

/******************************对COM通信协议的定义*********************************/
#define COM_FRAME_MAX_LENGTH        0XE0            //缓存最大长度
#define COM_FRAME_MARK              0XEE            //帧头
#define COM_FRAME_ESCAPE            0XFF            //转义符

/******************************对COM状态的定义*********************************/
#define HEAD_DETECT                 0
#define LENGTH_ACQUIRE              1
#define PROP_ACQUIRE                2
#define DATA_ACQUIRE                3
#define TAIL_CONFIRM                4
/******************************对COM帧内的数据格式定义*********************************/
typedef union {
    int8_t    int8_ts[128];
    int16_t   int16_ts[64];
    int32_t   int32_ts[32];
    uint8_t   uint8_ts[128];
    uint16_t  uint16_ts[64];
    uint32_t  uint32_ts[32];
    float     floats_ts[32];
} COMData;
/******************************对CAN帧内的特殊位定义*********************************/
typedef struct {
    uint8_t   Length;
    uint8_t   Prop;
    COMData   Data;
} COMFrame;

/******************************对COM状态描述定义*********************************/
typedef struct {
    uint8_t RecStatus;
    uint8_t RecCounts;
    uint8_t preData;
    uint8_t RecLength;
} COMRecStatus;

/******************************建立属性值与处理函数对应结构*********************************/
typedef struct {
    uint16_t Prop;                                  //属性名称
    void (*Fun)(COMFrame* Frm);                     //此属性对应的处理函数
} COMFunDict;

/******************************对COM结构体的定义*********************************/
typedef struct arduino_com_typedef
{
    const uint8_t    SerialNum;
    const uint8_t    Prop_Count;
    COMFunDict*      Prop_Array;
    COMFrame         COM_Rec;
    COMRecStatus     COM_Rec_Status;
}
Arduino_COM_typedef;

extern Arduino_COM_typedef MY_USART0;

/******************************核心函数*********************************/

void Send_Frame_COM(COMFrame*, Arduino_COM_typedef*);
void Get_Frame_COM(uint8_t, Arduino_COM_typedef*);
void Process_Frame_COM(COMFrame*, Arduino_COM_typedef*);
void COM_Write(uint8_t*,uint8_t,Arduino_COM_typedef*);

void UART_SendByte(uint8_t USARTx,uint8_t data);
void UART_SendString(uint8_t USARTx,char* string);
void UART_SendNum_Short(uint8_t USARTx,uint32_t Num);
//先将int转换为string，再输出，但是最大输出为64位int

#endif 


