#include "MyProtection.h"
#include "MyValue.h"
#include "MySystem.h"
/*目前沒考慮EEPROM的動態特性所以先定值尚未有效正*/

/**
 * @brief
 * 12V UVP保護事件
 */
void LLC_Vo_UVP(void)
{
    while (_LLC_ADC->adc_12V_Vo_Sense < LLC_UVP_Threshold)
    {
        _Prot_CNT->UVP_CNT++;
        if (_Prot_CNT->UVP_CNT >= Protect_Time)
        {
            /*Latch Event*/
            Latch_Flag = True;
            LLC_State = Shunt_Down_State;
        }
    }
}

/**
 * @brief
 * PSU 12V OCP EVENT over peak load
 */
void LLC_Io_OCP(void)
{
    while (_LLC_ADC->adc_12V_Io_Sense >= LLC_OCP_Threshold)
    {
        _Prot_CNT->OCP_CNT++;
        if (_Prot_CNT->OCP_CNT >= Protect_Time)
        {
            /*Latch Event*/
            Latch_Flag = True;
            LLC_State = Shunt_Down_State;
        }
    }
}

/**
 * @brief
 * 目前打算以duty方式偵測
 */
void LLC_Io_SCP(void)
{
}

/**
 * @brief
 * NTC 過熱保護
 */
void LLC_OTP(void)
{
    while (_LLC_ADC->adc_Temp_Sense < LLC_OTP_Threshold)
    {
        _Prot_CNT->OTP_CNT++;
        if (_Prot_CNT->OTP_CNT >= Protect_Time)
        {
            /*Latch Event*/
            Latch_Flag = True;
            LLC_State = Shunt_Down_State;
        }
    }
}

/**
 * @brief
 * DD 5V/3.3V potect event
 */
void LLC_DD_OCP(void)
{
    if ((_LLC_ADC->adc_5V_Io_Sense >= LLC_DD_5V_Threshold) ||
        (_LLC_ADC->adc_3_3V_Io_Sense >= LLC_DD_3_3V_Threshold))
    {
        _Prot_CNT->DD_OCP_CNT++;
        if (_Prot_CNT->DD_OCP_CNT >= Protect_Time)
        {
            /*Latch Event*/
            Latch_Flag = True;
            LLC_State = Shunt_Down_State;
        }
    }
}
