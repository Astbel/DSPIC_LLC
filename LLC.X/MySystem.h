#ifndef __MYSYSTEM_H_
#define __MYSYSTEM_H_

#include <xc.h>
#include "stdlib.h"
#include "string.h"

/*DD 輸出瓦數 =5*20A+3.3*20A*/
#define DD_Power 166
/*LLC 抽載配置係數計算,用於回傳一次側PFC*/
#define Io_ADC_Gain 1
#define DD_5V_ADC_Gain   (1 / DD_Power)
#define DD_3_3V_ADC_Gain (1 / DD_Power)
#define ADC_Reslotion    (4096)

/*上限值Max&Min設置**暫定**/
#define MAX_DUTY 314
#define MIN_DUTY 0

/*時序定義*/
#define Vo_Sequence 20000

/*12V 數位值暫定 12bit 解析度*/
#define Vout_Digit 1785
/*保護時間 ISR 100us*/
#define Protect_Time 1000
/*各保護目標定義 12bit resloution*/
#define LLC_UVP_Threshold 1607 // 10.8v
#define LLC_OTP_Threshold 1224 // 110度
/*duty 判斷 or LLC 側電流*/
#define LLC_SCP_Threshold 4.6 // duty大小
/*12V OCP 暫定義 須修正成dynamic */
#define LLC_OCP_Threshold 4096 // Full Scale
/*DD 保護需修正為動態事件目前暫定*/
#define LLC_DD_5V_Threshold 1843
#define LLC_DD_3_3V_Threshold 1843

/*Boolean*/
#define True 1
#define False 0
/*High Low*/
#define High 1
#define Low 0

/*ISR 這裡預定義事件發生為 100us*/
/*定義TimeStick*/
#define PGI_Time_Stick 100

/*定義 PowerFail 時間 先定義為ms*/
#define Power_Fail_Seq_Time 20

#endif
