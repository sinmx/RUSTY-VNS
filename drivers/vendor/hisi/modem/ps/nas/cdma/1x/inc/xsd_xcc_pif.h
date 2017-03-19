/** ****************************************************************************

                    Huawei Technologies Sweden AB (C), 2001-2011

 ********************************************************************************
 * @author    Automatically generated by DAISY
 * @version
 * @date      2014-07-02
 * @file
 * @brief
 * Physical interface between XSD and XCC
 * @copyright Huawei Technologies Sweden AB
 *******************************************************************************/
#ifndef XSD_XCC_PIF_H
#define XSD_XCC_PIF_H

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
 * Name        : XSD_XCC_PIF_MSG_TYPE_ENUM_UINT16
 * Description :
 *******************************************************************************/
enum XSD_XCC_PIF_MSG_TYPE_ENUM
{
    ID_XSD_XCC_START_REQ                = 0x0000, /* _H2ASN_MsgChoice XSD_XCC_START_REQ_STRU*/ /**< @sa XSD_XCC_START_REQ_STRU */
    ID_XCC_XSD_START_CNF                = 0x0001, /* _H2ASN_MsgChoice XCC_XSD_START_CNF_STRU*/ /**< @sa XCC_XSD_START_CNF_STRU */
    ID_XSD_XCC_POWER_OFF_REQ            = 0x0002, /* _H2ASN_MsgChoice XSD_XCC_POWER_OFF_REQ_STRU*/ /**< @sa XSD_XCC_POWER_OFF_REQ_STRU */
    ID_XCC_XSD_POWER_OFF_CNF            = 0x0003, /* _H2ASN_MsgChoice XCC_XSD_POWER_OFF_CNF_STRU*/ /**< @sa XCC_XSD_POWER_OFF_CNF_STRU */
    ID_XCC_XSD_DEREGISTER_IND           = 0x0004, /* _H2ASN_MsgChoice XCC_XSD_DEREGISTER_IND_STRU*/ /**< @sa XCC_XSD_DEREGISTER_IND_STRU */
    ID_XSD_XCC_NDSS_RESULT_IND          = 0x0005, /* _H2ASN_MsgChoice XSD_XCC_NDSS_RESULT_IND_STRU*/ /**< @sa XSD_XCC_NDSS_RESULT_IND_STRU */
    ID_XSD_XCC_PIF_MSG_TYPE_ENUM_BUTT   = 0xFFFF
};
typedef VOS_UINT16 XSD_XCC_PIF_MSG_TYPE_ENUM_UINT16;

/** ****************************************************************************
 * Name        : XCC_XSD_START_RESULT_ENUM_UINT32
 * Description : Start result
 *******************************************************************************/
enum XCC_XSD_START_RESULT_ENUM
{
    XCC_XSD_START_RESULT_SUCC           = 0x00000000,
    XCC_XSD_START_RESULT_FAIL           = 0x00000001,
    XCC_XSD_START_RESULT_BUTT           = 0x00000002
};
typedef VOS_UINT32 XCC_XSD_START_RESULT_ENUM_UINT32;

/** ****************************************************************************
 * Name        : XSD_XCC_DEREGISTER_REASON_ENUM
 * Description : deregister reason
 *******************************************************************************/
enum XSD_XCC_DEREGISTER_REASON_ENUM
{
    XSD_XCC_DEREGISTER_REASON_POWEROFF                         = 0x00000000,
    XSD_XCC_DEREGISTER_REASON_BUTT                             = 0x00000001
};
typedef VOS_UINT8 XSD_XCC_DEREGISTER_REASON_ENUM_UINT8;


/** ****************************************************************************
 * Name        : XSD_XCC_NDSS_RESULT_ENUM_UINT8
 * Description :
 *******************************************************************************/
enum XSD_XCC_NDSS_RESULT_ENUM
{
    XSD_XCC_NDSS_RESULT_SUCCESS         = 0x00,
    XSD_XCC_NDSS_RESULT_FAILURE         = 0x01,

    XSD_XCC_NDSS_RESULT_BUTT            = 0x02
};
typedef VOS_UINT8 XSD_XCC_NDSS_RESULT_ENUM_UINT8;

/** ****************************************************************************
 * Name        : XCC_XSD_POWER_OFF_REASON_ENUM
 * Description : Poweroff Reason
 *******************************************************************************/
enum XCC_XSD_POWER_OFF_REASON_ENUM
{
    XCC_XSD_POWER_OFF_REASON_POWER_OFF          = 0x00000000,
    XCC_XSD_POWER_OFF_REASON_POWER_SAVE         = 0x00000001,
    XCC_XSD_POWER_OFF_REASON_BUTT               = 0x00000002
};
typedef VOS_UINT32 XCC_XSD_POWER_OFF_REASON_ENUM_UINT32;


/** ****************************************************************************
 * Name        : XCC_XSD_POWER_OFF_RESULT_ENUM
 * Description : Start result
 *******************************************************************************/
enum XCC_XSD_POWER_OFF_RESULT_ENUM
{
    XCC_XSD_POWER_OFF_RESULT_SUCC           = 0x00000000,
    XCC_XSD_POWER_OFF_RESULT_FAIL           = 0x00000001,
    XCC_XSD_POWER_OFF_RESULT_BUTT           = 0x00000002
};
typedef VOS_UINT32 XCC_XSD_POWER_OFF_RESULT_ENUM_UINT32;


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
 * Name        : XSD_XCC_START_REQ_STRU
 * Description : Start request
 *******************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                               /* _H2ASN_Skip */
    XSD_XCC_PIF_MSG_TYPE_ENUM_UINT16    enMsgId; /* _H2ASN_Skip */
    VOS_UINT16                          usOpId;
}XSD_XCC_START_REQ_STRU;

/** ****************************************************************************
 * Name        : XCC_XSD_START_CNF_STRU
 * Description : Start confirm
 *******************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                               /* _H2ASN_Skip */
    XSD_XCC_PIF_MSG_TYPE_ENUM_UINT16    enMsgId; /* _H2ASN_Skip */
    VOS_UINT16                          usOpId;
    XCC_XSD_START_RESULT_ENUM_UINT32    enRslt;
}XCC_XSD_START_CNF_STRU;

/** ****************************************************************************
 * Name        : XSD_XCC_POWER_OFF_REQ_STRU
 * Description : Power off request
 *******************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                  /* _H2ASN_Skip */
    XSD_XCC_PIF_MSG_TYPE_ENUM_UINT16        enMsgId; /* _H2ASN_Skip */
    VOS_UINT16                              usOpId;
    XCC_XSD_POWER_OFF_REASON_ENUM_UINT32    enPowerOffReason;
}XSD_XCC_POWER_OFF_REQ_STRU;

/** ****************************************************************************
 * Name        : XCC_XSD_POWER_OFF_CNF_STRU
 * Description : Power off confirm
 *******************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                               /* _H2ASN_Skip */
    XSD_XCC_PIF_MSG_TYPE_ENUM_UINT16        enMsgId; /* _H2ASN_Skip */
    VOS_UINT16                              usOpId;
    XCC_XSD_POWER_OFF_RESULT_ENUM_UINT32    enRslt;
}XCC_XSD_POWER_OFF_CNF_STRU;

/** ****************************************************************************
 * Name        : XCC_XSD_DEREGISTER_IND_STRU
 * Description : Power off deregister ind
 *******************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                          /* _H2ASN_Skip */
    XSD_XCC_PIF_MSG_TYPE_ENUM_UINT16                        enMsgId; /* _H2ASN_Skip */
    VOS_UINT16                                              usOpId;
    XSD_XCC_DEREGISTER_REASON_ENUM_UINT8                    enCause;
    VOS_UINT8                                               aucRsv[3];
}XCC_XSD_DEREGISTER_IND_STRU;


/** ****************************************************************************
 * Name        : XSD_XCC_NDSS_RESULT_IND_STRU
 * Description : service redirection result ind
 *
 *******************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                   /* _H2ASN_Skip */
    XSD_XCC_PIF_MSG_TYPE_ENUM_UINT16    enMsgId;     /* _H2ASN_Skip */
    VOS_UINT16                          usOpId;
    XSD_XCC_NDSS_RESULT_ENUM_UINT8      enNsddResult;
    VOS_UINT8                           aucReserved[3];
}XSD_XCC_NDSS_RESULT_IND_STRU;

/*******************************************************************************
 8. Global  declaration
*******************************************************************************/

/*******************************************************************************
 9. Function declarations
*******************************************************************************/
/** ****************************************************************************
 * Name        : XSD_XCC_PIF_MSG_DATA
 * Description : H2ASN top level message structure definition
 *******************************************************************************/
typedef struct
{
    XSD_XCC_PIF_MSG_TYPE_ENUM_UINT16    enMsgId;     /* _H2ASN_MsgChoice_Export XSD_XCC_PIF_MSG_TYPE_ENUM_UINT16 */
    VOS_UINT8                           aucMsgBlock[2];

    /* _H2ASN_MsgChoice_When_Comment XSD_XCC_PIF_MSG_TYPE_ENUM_UINT16 */
}XSD_XCC_PIF_MSG_DATA;

/* _H2ASN_Length UINT32*/
/** ****************************************************************************
 * Name        : XSD_XCC_PIF
 * Description : H2ASN top level message structure definition
 *******************************************************************************/
typedef struct
{
    VOS_MSG_HEADER
    XSD_XCC_PIF_MSG_DATA                stMsgData;
}XSD_XCC_PIF;


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