/**
 * @file MyControl.c
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2024-02-06
 *
 * @copyright Copyright (c) 2024
 *
 */
#include "MyControl.h"
#include "MySystem.h"
// pravite variable

// public variable

// class obj 建構區
Type_compensation Voltage_Comp;
Type_compensation *_Volt_Comp;

// pravite mehtod delcare

/**
 * @brief LLC 12V數位回授補償
 *        Type 3型
 * @param err 輸出誤差
 * Yn output
 * Xn input
 */
void Vout_Regulation(int16_t err)
{
    uint16_t output;
    _Volt_Comp->Xn[0] = err;
    /*差分方程*/
    _Volt_Comp->Yn[0] = _Volt_Comp->Bn[3] * _Volt_Comp->Xn[3] +
                        _Volt_Comp->Bn[2] * _Volt_Comp->Xn[2] +
                        _Volt_Comp->Bn[1] * _Volt_Comp->Xn[1] +
                        _Volt_Comp->Bn[0] * _Volt_Comp->Xn[0] +
                        _Volt_Comp->An[3] * _Volt_Comp->Yn[3] +
                        _Volt_Comp->An[2] * _Volt_Comp->Yn[2] +
                        _Volt_Comp->An[1] * _Volt_Comp->Yn[1];

    /*iteration 紀錄上一筆*/
    static uint8_t i;
    for (i = Order; i > 0; i--)
    {
        _Volt_Comp->Xn[i] = _Volt_Comp->Xn[i - 1];
        _Volt_Comp->Yn[i] = _Volt_Comp->Yn[i - 1];
    }
    /*限制輸出*/
    output = _Volt_Comp->Yn[0];
    if (output > MAX_DUTY)
        output = MAX_DUTY;
    if (output < MIN_DUTY)
        output = MIN_DUTY;
    
    /*輸出至DPWM*/
}
