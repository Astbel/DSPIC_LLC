/**
 * @file MyValue.c
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2024-02-05
 *
 * @copyright Copyright (c) 2024
 *
 */
// 引用區
#include "MyValue.h"
#include "MyControl.h"
#include "MyState.h"

// Class Obj Delcare
My_State LLC_State;
ADC_Result LLC_ADC;
My_Count Prot_CNT;

// Ptr of the obj
ADC_Result *_LLC_ADC;
My_Count *_Prot_CNT;

// public variable delcare
uint16_t LLC_Ramp_Cnt;
uint16_t Power_Fail_Cnt;
uint8_t Latch_Flag;

/*public method*/
void My_Value_Init(void)
{
    /*Clear Up ADC Value*/
    _LLC_ADC->adc_12V_Vo_Sense = 0;
    _LLC_ADC->adc_12V_Io_Sense = 0;
    _LLC_ADC->adc_5V_Io_Sense = 0;
    _LLC_ADC->adc_3_3V_Io_Sense = 0;
    _LLC_ADC->adc_Temp_Sense = 0;
    _LLC_ADC->adc_Io_Sense = 0;

    /*Reset Counter*/
}
