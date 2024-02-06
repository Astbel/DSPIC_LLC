#ifndef __MYSYSTEM_H_
#define __MYSYSTEM_H_

#include <xc.h>
#include "stdlib.h"
#include "string.h"

/*上限值Max&Min設置**暫定**/
#define MAX_DUTY  314 
#define MIN_DUTY    0

/*時序定義*/
#define Vo_Sequence 20000

/*12V 數位值暫定 12bit 解析度*/
#define Vout_Digit 1785

/*Boolean*/
#define True  1
#define False 0
/*High Low*/
#define High  1
#define Low   0

/*定義TimeStick*/
#define PGI_Time_Stick  100


#endif
