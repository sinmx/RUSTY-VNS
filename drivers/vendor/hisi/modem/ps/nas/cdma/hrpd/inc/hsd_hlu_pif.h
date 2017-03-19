/** ****************************************************************************

                    Huawei Technologies Sweden AB (C), 2001-2014

 ********************************************************************************
 * @author    Automatically generated by DAISY
 * @version
 * @date      2014-12-27
 * @file
 * @brief
 *
 * @copyright Huawei Technologies Sweden AB
 *******************************************************************************/
#ifndef HSD_HLU_PIF_H
#define HSD_HLU_PIF_H

/*******************************************************************************
 1. Other files included
*******************************************************************************/

#include "vos.h"

#ifdef __cplusplus
#if __cplusplus
    extern "C" {
#endif /* __cpluscplus */
#endif /* __cpluscplus */
#pragma pack(4)

/*******************************************************************************
 2. Macro definitions
*******************************************************************************/


/*******************************************************************************
 3. Enumerations declarations
*******************************************************************************/

/** ****************************************************************************
 * Name        : HSD_HLU_PIF_MSG_TYPE_ENUM_UINT16
 *
 * Description :
 *******************************************************************************/
enum HSD_HLU_PIF_MSG_TYPE_ENUM
{
    ID_HSD_HLU_START_REQ                = 0x0001, /* _H2ASN_MsgChoice HSD_HLU_START_REQ_STRU*/ /**< @sa HSD_HLU_START_REQ_STRU */
    ID_HLU_HSD_START_CNF                = 0x0002, /* _H2ASN_MsgChoice HLU_HSD_START_CNF_STRU*/ /**< @sa HLU_HSD_START_CNF_STRU */
    ID_HSD_HLU_POWER_OFF_REQ            = 0x0003, /* _H2ASN_MsgChoice HSD_HLU_POWER_OFF_REQ_STRU*/ /**< @sa HSD_HLU_POWER_OFF_REQ_STRU */
    ID_HLU_HSD_POWER_OFF_CNF            = 0x0004, /* _H2ASN_MsgChoice HLU_HSD_POWER_OFF_CNF_STRU*/ /**< @sa HLU_HSD_POWER_OFF_CNF_STRU */
    ID_HSD_HLU_PIF_MSG_TYPE_ENUM_BUTT   = 0xFFFF
};
typedef VOS_UINT16 HSD_HLU_PIF_MSG_TYPE_ENUM_UINT16;

/*******************************************************************************
 4. Message Header declaration
*******************************************************************************/

/*******************************************************************************
 5. Message declaration
*******************************************************************************/

/*******************************************************************************
 6. STRUCT and UNION declaration
*******************************************************************************/

/*******************************************************************************
 7. OTHER declarations
*******************************************************************************/

/** ****************************************************************************
 * Name        : HSD_HLU_START_REQ_STRU
 *
 * Description :
 *******************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                          /* _H2ASN_Skip */
    HSD_HLU_PIF_MSG_TYPE_ENUM_UINT16    enMsgId;            /* _H2ASN_Skip */
    VOS_UINT16                          usOpId;
    VOS_UINT8                           aucReserve[4];
} HSD_HLU_START_REQ_STRU;

/** ****************************************************************************
 * Name        : HLU_HSD_START_CNF_STRU
 *
 * Description :
 *******************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                          /* _H2ASN_Skip */
    HSD_HLU_PIF_MSG_TYPE_ENUM_UINT16    enMsgId;            /* _H2ASN_Skip */
    VOS_UINT16                          usOpId;
    VOS_UINT8                           aucReserve[4];
} HLU_HSD_START_CNF_STRU;

/** ****************************************************************************
 * Name        : HSD_HLU_POWER_OFF_REQ_STRU
 *
 * Description :
 *******************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                          /* _H2ASN_Skip */
    HSD_HLU_PIF_MSG_TYPE_ENUM_UINT16    enMsgId;            /* _H2ASN_Skip */
    VOS_UINT16                          usOpId;
    VOS_UINT8                           aucReserve[4];
} HSD_HLU_POWER_OFF_REQ_STRU;

/** ****************************************************************************
 * Name        : HLU_HSD_POWER_OFF_CNF_STRU
 *
 * Description :
 *******************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                          /* _H2ASN_Skip */
    HSD_HLU_PIF_MSG_TYPE_ENUM_UINT16    enMsgId;            /* _H2ASN_Skip */
    VOS_UINT16                          usOpId;
    VOS_UINT8                           aucReserve[4];
} HLU_HSD_POWER_OFF_CNF_STRU;

/** ****************************************************************************
 * Name        : HSD_HLU_PIF_MSG_DATA
 * Description : H2ASN top level message structure definition
 *******************************************************************************/
typedef struct
{
    HSD_HLU_PIF_MSG_TYPE_ENUM_UINT16    enMsgId;     /* _H2ASN_MsgChoice_Export HSD_HLU_PIF_MSG_TYPE_ENUM_UINT16 */
    VOS_UINT8                           aucMsgBlock[2];

    /* _H2ASN_MsgChoice_When_Comment HSD_HLU_PIF_MSG_TYPE_ENUM_UINT16 */
}HSD_HLU_PIF_MSG_DATA;

/* _H2ASN_Length UINT32*/
/** ****************************************************************************
 * Name        : HSD_HLU_PIF
 * Description : H2ASN top level message structure definition
 *******************************************************************************/
typedef struct
{
    VOS_MSG_HEADER
    HSD_HLU_PIF_MSG_DATA                stMsgData;
}HSD_HLU_PIF;

/*******************************************************************************
 8. Global  declaration
*******************************************************************************/

/*******************************************************************************
 9. Function declarations
*******************************************************************************/

#if ((VOS_OS_VER == VOS_WIN32) || (VOS_OS_VER == VOS_NUCLEUS))
#pragma pack()
#else
#pragma pack(0)
#endif

#ifdef __cplusplus
#if __cplusplus
}
#endif /* __cpluscplus */
#endif /* __cpluscplus */

#endif
