#ifndef __MYVALUE_H_
#define __MYVALUE_H_

#include "MySystem.h"

//Value
extern uint8_t state; 
// Struct
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

//public method
void My_Value_Init(void);



#endif
