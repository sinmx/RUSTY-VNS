/******************************************************************************

                 版权所有 (C), 2001-2015, 华为技术有限公司

 ******************************************************************************
  文 件 名   : soc_wdtv100_interface.h
  版 本 号   : 初稿
  作    者   : Excel2Code
  生成日期   : 2015-07-14 14:25:57
  最近修改   :
  功能描述   : 接口头文件
  函数列表   :
  修改历史   :
  1.日    期   : 2015年7月14日
    作    者   : s00212991
    修改内容   : 从《Hi3650V100 SOC寄存器手册_WDTV100.xml》自动生成

******************************************************************************/

/*****************************************************************************
  1 其他头文件包含
*****************************************************************************/

#ifndef __SOC_WDTV100_INTERFACE_H__
#define __SOC_WDTV100_INTERFACE_H__

#ifdef __cplusplus
    #if __cplusplus
        extern "C" {
    #endif
#endif



/*****************************************************************************
  2 宏定义
*****************************************************************************/

/****************************************************************************
                     (1/1) register_WD
 ****************************************************************************/
/* 寄存器说明：计数器的计数初值寄存器
   位域定义UNION结构:  SOC_WDTV100_WDLOAD_UNION */
#define SOC_WDTV100_WDLOAD_ADDR(base)                 ((base) + (0x0000))

/* 寄存器说明：计数器当前值寄存器
   位域定义UNION结构:  SOC_WDTV100_WDVALUE_UNION */
#define SOC_WDTV100_WDVALUE_ADDR(base)                ((base) + (0x0004))

/* 寄存器说明：控制寄存器
   位域定义UNION结构:  SOC_WDTV100_WDCONTROL_UNION */
#define SOC_WDTV100_WDCONTROL_ADDR(base)              ((base) + (0x0008))

/* 寄存器说明：中断控制寄存器
   位域定义UNION结构:  SOC_WDTV100_WDINTCLR_UNION */
#define SOC_WDTV100_WDINTCLR_ADDR(base)               ((base) + (0x000C))

/* 寄存器说明：原始中断状态寄存器
   位域定义UNION结构:  SOC_WDTV100_WDRIS_UNION */
#define SOC_WDTV100_WDRIS_ADDR(base)                  ((base) + (0x0010))

/* 寄存器说明：屏蔽后中断状态寄存器
   位域定义UNION结构:  SOC_WDTV100_WDMIS_UNION */
#define SOC_WDTV100_WDMIS_ADDR(base)                  ((base) + (0x0014))

/* 寄存器说明：写权限控制寄存器
   位域定义UNION结构:  SOC_WDTV100_WDLOCK_UNION */
#define SOC_WDTV100_WDLOCK_ADDR(base)                 ((base) + (0x0C00))





/*****************************************************************************
  3 枚举定义
*****************************************************************************/



/*****************************************************************************
  4 消息头定义
*****************************************************************************/


/*****************************************************************************
  5 消息定义
*****************************************************************************/



/*****************************************************************************
  6 STRUCT定义
*****************************************************************************/



/*****************************************************************************
  7 UNION定义
*****************************************************************************/

/****************************************************************************
                     (1/1) register_WD
 ****************************************************************************/
/*****************************************************************************
 结构名    : SOC_WDTV100_WDLOAD_UNION
 结构说明  : WDLOAD 寄存器结构定义。地址偏移量:0x0000，初值:0xFFFFFFFF，宽度:32
 寄存器说明: 计数器的计数初值寄存器
*****************************************************************************/
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int      value;
    struct
    {
        unsigned int  wdogload : 32; /* bit[0-31]: watchdog递减计数器的初始值。一旦该计数器的值被更新，则计数器立即从新值开始递减计数 */
    } reg;
} SOC_WDTV100_WDLOAD_UNION;
#endif
#define SOC_WDTV100_WDLOAD_wdogload_START  (0)
#define SOC_WDTV100_WDLOAD_wdogload_END    (31)


/*****************************************************************************
 结构名    : SOC_WDTV100_WDVALUE_UNION
 结构说明  : WDVALUE 寄存器结构定义。地址偏移量:0x0004，初值:0xFFFFFFFF，宽度:32
 寄存器说明: 计数器当前值寄存器
*****************************************************************************/
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int      value;
    struct
    {
        unsigned int  wdogvalue : 32; /* bit[0-31]: 正在递减计数的计数器当前值 */
    } reg;
} SOC_WDTV100_WDVALUE_UNION;
#endif
#define SOC_WDTV100_WDVALUE_wdogvalue_START  (0)
#define SOC_WDTV100_WDVALUE_wdogvalue_END    (31)


/*****************************************************************************
 结构名    : SOC_WDTV100_WDCONTROL_UNION
 结构说明  : WDCONTROL 寄存器结构定义。地址偏移量:0x0008，初值:0x00000000，宽度:32
 寄存器说明: 控制寄存器
*****************************************************************************/
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int      value;
    struct
    {
        unsigned int  inten    : 1;  /* bit[0]   : 使能中断信号的输出。
                                                   0：计数器停止计数，计数值保持当前值不变；
                                                   1：既启动计数器又使能中断。
                                                   若中断先前被禁止，则当中断再次被使能时，计数器从寄存器WdogLoad中载入初值并重新开始计数。 */
        unsigned int  resen    : 1;  /* bit[1]   : 使能Watchdog模块输出复位信号。
                                                   0：禁止；
                                                   1：使能。 */
        unsigned int  reserved : 30; /* bit[2-31]: 保留。写无效，读时返回0。 */
    } reg;
} SOC_WDTV100_WDCONTROL_UNION;
#endif
#define SOC_WDTV100_WDCONTROL_inten_START     (0)
#define SOC_WDTV100_WDCONTROL_inten_END       (0)
#define SOC_WDTV100_WDCONTROL_resen_START     (1)
#define SOC_WDTV100_WDCONTROL_resen_END       (1)


/*****************************************************************************
 结构名    : SOC_WDTV100_WDINTCLR_UNION
 结构说明  : WDINTCLR 寄存器结构定义。地址偏移量:0x000C，初值:0x00000000，宽度:32
 寄存器说明: 中断控制寄存器
*****************************************************************************/
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int      value;
    struct
    {
        unsigned int  wdogxintclr : 32; /* bit[0-31]: 对该寄存器写入任意值可清除中断，并使Watchdog从寄存器WatchLoad中重新载入初值。 */
    } reg;
} SOC_WDTV100_WDINTCLR_UNION;
#endif
#define SOC_WDTV100_WDINTCLR_wdogxintclr_START  (0)
#define SOC_WDTV100_WDINTCLR_wdogxintclr_END    (31)


/*****************************************************************************
 结构名    : SOC_WDTV100_WDRIS_UNION
 结构说明  : WDRIS 寄存器结构定义。地址偏移量:0x0010，初值:0x00000000，宽度:32
 寄存器说明: 原始中断状态寄存器
*****************************************************************************/
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int      value;
    struct
    {
        unsigned int  wdogris  : 1;  /* bit[0]   : 原始中断装态，当计数器见到零时该位有效。
                                                   0：未产生中断；
                                                   1：已产生中断。 */
        unsigned int  reserved : 31; /* bit[1-31]: 保留。写无效，读时返回0。 */
    } reg;
} SOC_WDTV100_WDRIS_UNION;
#endif
#define SOC_WDTV100_WDRIS_wdogris_START   (0)
#define SOC_WDTV100_WDRIS_wdogris_END     (0)


/*****************************************************************************
 结构名    : SOC_WDTV100_WDMIS_UNION
 结构说明  : WDMIS 寄存器结构定义。地址偏移量:0x0014，初值:0x00000000，宽度:32
 寄存器说明: 屏蔽后中断状态寄存器
*****************************************************************************/
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int      value;
    struct
    {
        unsigned int  wdogmis  : 1;  /* bit[0]   : 屏蔽后中断装态。
                                                   0：未产生中断或中断被屏蔽；
                                                   1：已产生中断。 */
        unsigned int  reserved : 31; /* bit[1-31]: 保留。写无效，读时返回0。 */
    } reg;
} SOC_WDTV100_WDMIS_UNION;
#endif
#define SOC_WDTV100_WDMIS_wdogmis_START   (0)
#define SOC_WDTV100_WDMIS_wdogmis_END     (0)


/*****************************************************************************
 结构名    : SOC_WDTV100_WDLOCK_UNION
 结构说明  : WDLOCK 寄存器结构定义。地址偏移量:0x0C00，初值:0x00000000，宽度:32
 寄存器说明: 写权限控制寄存器
*****************************************************************************/
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int      value;
    struct
    {
        unsigned int  wdoglock : 32; /* bit[0-31]: 向该寄存器写入0x1ACC_E551可打开所有寄存器的写权限，写入其他值则关闭写权限。读该寄存器返回加锁的状态而不是写入该寄存器的值.0:允许写访问（未加锁）；1：禁止写访问（已加锁）。 */
    } reg;
} SOC_WDTV100_WDLOCK_UNION;
#endif
#define SOC_WDTV100_WDLOCK_wdoglock_START  (0)
#define SOC_WDTV100_WDLOCK_wdoglock_END    (31)






/*****************************************************************************
  8 OTHERS定义
*****************************************************************************/



/*****************************************************************************
  9 全局变量声明
*****************************************************************************/


/*****************************************************************************
  10 函数声明
*****************************************************************************/


#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif

#endif /* end of soc_wdtv100_interface.h */
