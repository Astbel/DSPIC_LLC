#ifndef __MYVALUE_H_
#define __MYVALUE_H_

#include "MySystem.h"

//Value
extern uint16_t Load_Gear;

// Value--counter
extern uint16_t Power_Fail_Cnt;
extern uint16_t LLC_Ramp_Cnt;

// Value--Flag
extern uint8_t Latch_Flag;

// Struct
typedef struct
{
   uint16_t adc_12V_Vo_Sense;
   uint16_t adc_12V_Io_Sense;
   uint16_t adc_5V_Io_Sense;
   uint16_t adc_3_3V_Io_Sense;
   uint16_t adc_Temp_Sense;
   uint16_t adc_Io_Sense;

} ADC_Result;

typedef struct
{
   uint16_t UVP_CNT;
   uint16_t OVP_CNT;
   uint16_t OCP_CNT;
   uint16_t OTP_CNT;
   uint16_t SCP_CNT;
   uint16_t DD_OCP_CNT;
} My_Count;

// Enum
typedef enum
{
   Idle_State,
   Ramp_Up_State,
   LLC_ON_State,
   Shunt_Down_State
} My_State;

// 建立類別: struct enum uion
extern My_State LLC_State;
extern ADC_Result LLC_ADC;
extern My_Count Prot_CNT;

// Ptr of the obj
extern ADC_Result *_LLC_ADC;
extern My_Count *_Prot_CNT;

// public method
void My_Value_Init(void);

#endif
