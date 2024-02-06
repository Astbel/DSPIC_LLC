/**
 * @file MyState.c
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2024-02-05
 *
 * @copyright Copyright (c) 2024
 *
 */

// 引用區
#include "MyState.h"
#include "MyValue.h"
#include "MyGpio.h"
#include "MySystem.h"
// 變數申明區

// 私有變數申明區
uint16_t uvp_cnt;
// 類別申明區

// 私有方法申明區
void Idle_Mode(void);
void Ramp_Up(void);
void LLC_ON(void);
void Shunt_Down(void);

/*ISR 呼叫狀態機*/
void State_Mehine(void)
{
    switch (LLC_State)
    {
    case Idle_State:
        Idle_Mode();
        break;

    case Ramp_Up_State:
        Ramp_Up();
        break;

    case LLC_ON_State:
        LLC_ON();
        break;

    case Shunt_Down_State:
        Shunt_Down();
        break;
    }
}

/*Event Handle*/
/**
 * @brief Wait for Master Send PGI Signal
 *
 *
 */
void Idle_Mode(void)
{
    while (PGI == High)
    {
        LLC_Ramp_Cnt++;
        if (LLC_Ramp_Cnt == PGI_Time_Stick)
        {
            /*En Dpwm & State Change*/
            LLC_State = Ramp_Up_State;
        }
    }
}

/**
 * @brief
 * softstart
 */
void Ramp_Up(void)
{

}

/**
 * @brief
 *
 */
void LLC_ON(void)
{
    /*SR ON OFF*/

    /*Dynamic for 12V regulation*/
}

/**
 * @brief
 *
 */
void Shunt_Down(void)
{

}

/*Pravite Method*/
void Vout_Seq(void)
{
    if (_LLC_ADC->adc_12V_Vo_Sense < Vout_Digit)
    {
        uvp_cnt++;
        /*80+ define 12V 20ms have be done*/
        if (uvp_cnt >= Vo_Sequence)
            LLC_State = Shunt_Down_State;
    }
}
