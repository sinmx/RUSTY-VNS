/*************************************************************************
*   版权所有(C) 2008-2013 深圳华为技术有限公司.
*
*   文 件 名 :  soc_memmap_mdm.h
*
*   作    者 :  y00184236
*
*   描    述 :  k3v3 v7r2 MODEM(A9) memory map
*
*   修改记录 :  2013年8月30日  v1.00  y00184236  创建
*************************************************************************/

#ifndef __SOC_MEMMAP_MDM_H__
#define __SOC_MEMMAP_MDM_H__
#if 0
#ifdef __cplusplus
extern "C" {
#endif

#include "soc_memmap_comm.h"
/* timer: timer 0-7 ,C CORE使用*/
#define HI_TIMER_00TO07_REGBASE_ADDR      (0xE0202000)
#define HI_TIMER_00TO07_REG_SIZE          (SZ_4K)

#define HI_TIMER_04_REGBASE_ADDR          (HI_TIMER_00TO07_REGBASE_ADDR+0x50)

#ifdef __cplusplus
}
#endif
#endif
#endif    /* __SOC_MEMMAP_MDM_H__ */

