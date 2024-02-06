#ifndef __MYCONTROL_H_
#define __MYCONTROL_H_

#include "MySystem.h"
/*系統階數*/
#define Order 3

/*差分方程係數宣告*/
typedef struct
{
    int16_t err;
    int16_t Xn[Order];
    int16_t Yn[Order];
    int16_t An[Order];
    int16_t Bn[Order];
} Type_compensation;

/*類別聲明*/
extern Type_compensation Voltage_Comp;


/*public method*/
void Vout_Regulation(int16_t err);



#endif
