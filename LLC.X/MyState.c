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

// 變數申明區

// 私有變數申明區

// 類別申明區

// 私有方法申明區
void Idle(void);
void Ramp_Up(void);
void LLC_ON(void);
void Shunt_Down(void);

/*ISR 呼叫狀態機*/
void State_Mehine(void)
{
    switch (state)
    {
    case Idle_State:
        Idle();
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
 * @brief
 *
 */
void Idle(void)
{
}

/**
 * @brief
 *
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
}

/**
 * @brief
 *
 */
void Shunt_Down(void)
{
}
