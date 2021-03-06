/******************************************************************************

                  版权所有 (C), 2001-2011, 华为技术有限公司

 ******************************************************************************
  文 件 名   : CnasHsdFsmMainTbl.h
  版 本 号   : 初稿
  作    者   : h00300778
  生成日期   : 2014年12月9日
  最近修改   :
  功能描述   : CnasHsdFsmMainTbl.c 的头文件
  函数列表   :
  修改历史   :
  1.日    期   : 2014年12月9日
    作    者   : h00300778
    修改内容   : 创建文件

******************************************************************************/

#ifndef __CNAS_HSD_FSM_MAIN_TBL_H__
#define __CNAS_HSD_FSM_MAIN_TBL_H__

/*****************************************************************************
  1 其他头文件包含
*****************************************************************************/
#include  "vos.h"
#include  "NasFsm.h"


#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif


#pragma pack(4)

/*****************************************************************************
  2 全局变量声明
*****************************************************************************/
extern NAS_STA_STRU                                         g_astCnasHsdL1MainStaTbl[];


/*****************************************************************************
  3 宏定义
*****************************************************************************/
#define CNAS_HSD_GetL1MainStaTbl()                          (g_astCnasHsdL1MainStaTbl)

/*****************************************************************************
  4 枚举定义
*****************************************************************************/
/*****************************************************************************
 枚举名    : CNAS_HSD_L1_STA_ENUM
 枚举说明  : L1状态机ID枚举定义
 1.日    期   : 2014年12月9日
   作    者   : h00300778
   修改内容   : 新建
*****************************************************************************/
enum CNAS_HSD_L1_STA_ENUM
{

    CNAS_HSD_L1_STA_NULL                        = 0x00,     /* 开机初始化状态*/
    CNAS_HSD_L1_STA_INACTIVE                    = 0x01,     /* 去激活状态 */
    CNAS_HSD_L1_STA_INITIAL                     = 0x02,     /* 系统选择状态 */
    CNAS_HSD_L1_STA_IDLE                        = 0x03,     /* 驻留状态 */
    CNAS_HSD_L1_STA_OOC                         = 0x04,     /* 系统丢失状态 */

    CNAS_HSD_L1_STA_PREPROC,                                /* 预处理 */
    CNAS_HSD_L1_STA_BUTT
};
typedef VOS_UINT32 CNAS_HSD_L1_STA_ENUM_UINT32;


/*****************************************************************************
  5 消息头定义
*****************************************************************************/


/*****************************************************************************
  6 消息定义
*****************************************************************************/


/*****************************************************************************
  7 STRUCT定义
*****************************************************************************/


/*****************************************************************************
  8 UNION定义
*****************************************************************************/


/*****************************************************************************
  9 OTHERS定义
*****************************************************************************/


/*****************************************************************************
  10 函数声明
*****************************************************************************/
#if (FEATURE_ON == FEATURE_UE_MODE_CDMA)

VOS_UINT32 CNAS_HSD_GetL1MainStaTblSize(VOS_VOID);
NAS_FSM_DESC_STRU* CNAS_HSD_GetMainFsmDescAddr(VOS_VOID);


#endif





#if (VOS_OS_VER == VOS_WIN32)
#pragma pack()
#else
#pragma pack(0)
#endif




#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif

#endif /* end of CnasHsdFsmMainTbl.h */
