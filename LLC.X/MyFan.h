#ifndef __MYFAN_H_
#define __MYFAN_H_

#include "MySystem.h"

/*Struct*/
typedef struct 
{
    uint16_t Fan_load;
    uint16_t Fan_DD_3_3V;
    uint16_t Fan_DD_5V;
    uint16_t Fan_Temp;
    uint16_t Fan_Control;
    uint8_t  Fan_Fg;
    uint8_t Fan_det;

}Fan;

/*obj 聲明類別區*/
extern Fan my_Fan;
/*指標聲明類別區*/
extern Fan *_my_Fan;



#endif