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
void Vout_Seq(void);

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
            /*啟動DPWM*/
            
            /*啟動爬升 回授 slew rate 機制*/
            
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
    /*開機短路保護檢測*/

    /*Vout 爬升 80+檢測*/
    Vout_Seq();
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
 * 停機模式
 * 停止計算回授
 * 並關閉DPWM 
 * 判斷 是否進入latch事件
 */
void Shunt_Down(void)
{
    /*Freeze  DPWM for now*/
    
   /*Disable DPWM*/

   /*latch定義 :OVP OCP SCP etc...*/
   if (Latch_Flag==True)
   {
     /*Latch Event donoting stop slaver*/
   }
   else
   {
     /*Restart Event*/
     LLC_State=Idle_State;
   }
}

/*Pravite Method*/

/**
 * @brief 
 * 12V 爬升檢測UVP
 */
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

/**
 * @brief 
 * 12V緩啟動機制
 * 
 */
void Vout_SoftStart(void)
{

}

/**
 * @brief 
 * PSU PSON or AC Off line Event
 * time : 1ms
 * 
 * 先不考慮 PSON & House Keeper
 * Ver 0.1 no PSON & FPO
 */
void Power_Fail(void)
{
    if (PGI==Low)
    {
        Power_Fail_Cnt++;
        if (Power_Fail_Cnt>=Power_Fail_Seq_Time)
        {
            /*state change*/
            LLC_State = Shunt_Down_State;
        }
    }
}



