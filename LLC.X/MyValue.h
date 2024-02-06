#ifndef __MYVALUE_H_
#define __MYVALUE_H_

#include "MySystem.h"

//Value
 
extern uint16_t LLC_Ramp_Cnt;
// Struct
typedef struct 
{
   uint16_t adc_12V_Vo_Sense;
   uint16_t adc_12V_Io_Sense;
   uint16_t adc_5V_Io_Sense;
   uint16_t adc_3_3V_Io_Sense;
   uint16_t adc_Temp_Sense;
   uint16_t adc_Io_Sense;

}ADC_Result;

// Enum
typedef enum
{
   Idle_State,
   Ramp_Up_State,
   LLC_ON_State,
   Shunt_Down_State 
} My_State;

//建立類別: struct enum uion 
extern My_State LLC_State;
extern ADC_Result LLC_ADC;

//Ptr of the obj
extern ADC_Result *_LLC_ADC;
//public method
void My_Value_Init(void);



#endif
