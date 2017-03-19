/************************************************************
  Copyright (C), 2004-2005, Huawei Tech. Co., Ltd.

  FileName: tafstatus.c

  Author:   Roger     Version :   1.00     Date:  2005.3.30

  Description:
    MAPS1000����Э��ջӦ�����������Ӳ�STATUSģ���API�ӿڣ�
    ΪTAFM�ṩAPP����MM/GMM�����ܵĵ��ýӿڣ�
    ΪTAFM�ṩ�ͻ��˹���MM/GMM�����ܵ�AT���
  Version:
    MAPS1000 V100R001

  Function List:
  History:
      <author>  <time>   <version >   <desc>
      1.Roger    05/03/30     1.0     build this moudle
      2.liuyang  05/10/07     1.1     add attach & detach funcation
      3.liuyang  05/10/10     1.2     add functions that print the gobal Data and Status
      4.liuyang  05/10/21     1.3     modified Sta_ServiceStatusInd(),
                                    Sta_CoverageAreaInd(), Sta_DetachInd() & Sta_TimeoutProc
                                    for Problem No.A32D00650

      5.��    ��   : 2006��3��3��
        ��    ��   : liuyang id:48197
        �޸�����   : ���ⵥ�ţ�2310�����Ӷ�ʱ�������ڲ���ʱ

      6.��    ��   : 2006��3��13��
        ��    ��   : liuyang id:48197
        �޸�����   : ���ⵥ��:A32D02500
                     ����ڲ����������������������������������

      7.��    ��   : 2006��3��21��
        ��    ��   : liuyang id:48197
        �޸�����   : ���ⵥ�ţ�A32D02602,������������״̬�л�

      8.��    ��   : 2006��3��27��
        ��    ��   : liuyang id:48197
        �޸�����   : ���ⵥ��:A32D02372

      9.��    ��   : 2006��5��20��
        ��    ��   : liuyang id:48197
        �޸�����   : ���ⵥ��:A32D00739

     10.��    ��   : 2006��9��04��
        ��    ��   : sunxibo id:46746
        �޸�����   : ���ⵥ��:A32D05624,PLMN LIST����ʱ���Ϊ0������©

     11.��    ��   : 2006��9��13��
        ��    ��   : sunxibo id:46746
        �޸�����   : ���ⵥ��:A32D05600
     12.��    ��   : 2006��11��2��
        ��    ��   : sunxibo id:46746
        �޸�����   : �������ⵥ�ţ�A32D06406

     13.��    ��   : 2006��11��07��
        ��    ��   : x51137
        �޸�����   : ���ⵥA32D06630

     14.��    ��   : 2006��12��07��
        ��    ��   : x51137
        �޸�����   : ���ⵥA32D06630

     15.��    ��   : 2006��12��7��
        ��    ��   : H59254
        �޸�����   : ���ⵥ�ţ�A32D07836 ��Ϊ�ƶ�������

     16.��    ��   : 2006��12��20��
        ��    ��   : x51137
        �޸�����   : A32D07369
     17.��    ��   : 2007��01��05��
        ��    ��   : s46746
        �޸�����   : A32D07668

     18.��    ��   : 2007��2��2��
        ��    ��   : x51137
        �޸�����   : ���ⵥ�ţ�A32D08596
     19.��    ��   : 2007��02��09��
        ��    ��   : luojian id:60022475
        �޸�����   : �������ⵥ��A32D08488
     20.��    ��   : 2007��4��30��
        ��    ��   : Li Jilin 60827
        �޸�����   : �������ⵥ�ţ�A32D10733
     21.��    ��   : 2007��5��20��
        ��    ��   : s46746
        �޸�����   : �������ⵥ�ţ�A32D11051
     22.��    ��   : 2007��6��11��
        ��    ��   : s46746
        �޸�����   : �������ⵥ�ţ�A32D11538����PIN������뿪�����̷���
     23.��    ��   : 2007��6��22��
        ��    ��   : Li Jilin 60827
        �޸�����   : A32D11885 stop the protection timer in function Sta_UpdateFsmFlag before clearing the timer ID.
     24.��    ��   : 2007��7��15��
        ��    ��   : Li Jilin 60827
        �޸�����   : A32D12429 Modify the timer length
     25.��    ��   : 2007��7��20��
        ��    ��   : Li Jilin 60827
        �޸�����   : A32D12536
     26.��    ��   : 2007��07��24��
        ��    ��   : Li Jilin
        �޸�����   : A32D12559
     27.��    ��   : 2007��07��21��
        ��    ��   : l60022475
        �޸�����   : A32D12535
     28.��    ��   : 2007��07��30��
        ��    ��   : Li Jilin
        �޸�����   : A32D12620 Modify
     29.��    ��   : 2007��10��4��
        ��    ��   : l60022475
        �޸�����   : A32D12980
     30.��    ��   : 2007��10��27��
        ��    ��   : luojian id:107747
        �޸�����   : �������ⵥ�ţ�A32D13236
     31.��    ��   : 2008��3��17��
        ��    ��   : s46746
        �޸�����   : ���ⵥ��:AT2D02570,NAS B005�汾�����������
     32.��    ��   : 2008��07��15��
        ��    ��   : s46746
        �޸�����   : ���ⵥ�ţ�AT2D04378,RF���ԣ��ṩ�ϵ��Զ���������
     33.��    ��   : 2008��7��21��
        ��    ��   : luojian 00107747
        �޸�����   : ���ⵥ�ţ�AT2D04201/AT2D04536,�޸�IMSI DETACH����
     34.��    ��   : 2008��7��28��
        ��    ��   : luojian id:107747
        �޸�����   : ���ⵥ�ţ�AT2D04707/AT2D04722���޸��ϱ���״̬ʱ��
     35.��    ��   : 2008��8��05��
        ��    ��   : s46746
        �޸�����   : ���ⵥ�ţ�AT2D04712���޸�SYSINFO�ϱ�HSPA״̬
     36.��    ��   : 2008��8��13��
        ��    ��   : s46746
        �޸�����   : ���ⵥ�ţ�AT2D05035��RF�Զ���������ʱ�����ô�RF&BBP
     37.��    ��   : 2008��09��02��
        ��    ��   : l00130025
        �޸�����   : ���ⵥ�ţ�AT2D05430,�޸�TAF_PH_EVT_PLMN_USER_SEL��TAF_PH_EVT_PLMN_RESEL�¼��ϱ�
     38.��    ��   : 2008��10��16��
        ��    ��   : l00130025
        �޸�����   : �������ⵥ�ţ�AT2D6236:����TAF_PH_EVT_SYS_CFG_CNF��Ϣ�ϱ�
     39.��    ��   : 2008��12��05��
        ��    ��   : x00115505
        �޸�����   : �������ⵥ�ţ�AT2D07039:����CFUNΪ4֮��SRVST,MODE
                     û�������ϱ�������CFUNΪ6֮��SIMST�ϱ�����
     40.��    ��   : 2008��12��06��
        ��    ��   : l00130025
        �޸�����   : ���ⵥ�ţ�AT2D07317,�б�����ʱ������״̬��ʾ��׼ȷ���ȴ�����������ʶ��Ҫ��ʱ�����ϵͳ��Ϣ��ģʽ��ʾ����
     41.��    ��   : 2008��12��08��
        ��    ��   : l00130025
        �޸�����   : ���ⵥ�ţ�AT2D07318,SYSCFG������Detach/Attach����ʱ,���ײ�����ɣ�����ȴ�Attach CNF��
     42.��    ��   : 2008��12��15��
        ��    ��   : h44270
        �޸�����   : ���ⵥ��AT2D07140
     43.��    ��   : 2008��12��20��
        ��    ��   : l65478,l00130025
        �޸�����   : ���ⵥ�ţ�AT2D07555��AT2D07488,ָ����������������˫ģ����������ע���������ϱ��������
     44.��    ��   : 2008��12��24��
        ��    ��   : x00115505
        �޸�����   : ���ⵥ�ţ�AT2D07816,AT+CFUN=4֮��^SRVST,^MODE��
                     �ϱ�����AT+CFUN=4�����ý���ϱ���
     45.��    ��   : 2008��12��25��
        ��    ��   : h44270
        �޸�����   : ���ⵥ�ţ�AT2D07647,PUK������LED��ָʾ����
                     �ϱ�����AT+CFUN=4�����ý���ϱ���
     46.��    ��   : 2008��12��30��
        ��    ��   : x00115505
        �޸�����   : ���ⵥ�ţ�AT2D07967,HSDPA������ȥ�������R99������
                     LED�����ɫΪ��Ƴ�������ʾ����
     47.��    ��   : 2008��12��31��
        ��    ��   : l65478,l00130025
        �޸�����   : ���ⵥ�ţ�AT2D07971,ServiceStatusδ��ʱ׼ȷ�ϱ�
     48.��    ��   : 2009��01��05��
        ��    ��   : l00130025
        �޸�����   : �������ⵥAT2D07968,˫ģ�б��������,����״̬�жϺ��������
     49.��    ��   : 2009��01��06��
        ��    ��   : o00132663
        �޸�����   : ���ⵥ��:AT2D08132,�ӿ���ϢID_MMA_MMC_START_REQ��ucRoamCapability��δ����ʼ����
     50.��    ��   : 2009��01��15��
        ��    ��   : l00130025
        �޸�����   : ���ⵥ��:AT2D07018,LAU��RAU������������SYSCFG����,����ײ��ͷ����ӵĲ���
     51.��    ��   : 2009��02��16��
        ��    ��   : x00115505
        �޸�����   : ���ⵥ�ţ�AT2D08454,CS��ע��ɹ���PS��ע��ʧ�ܣ�LED����ʾ����״̬
     52.��    ��   : 2009��02��17��
        ��    ��   : o00132663
        �޸�����   : ���ⵥ�ţ�AT2D09081,��GCF���ԡ�GCF���� 9.4.2.2.1����MMA,AT״̬�쳣.
     53.��    ��   : 2009��03��06��
        ��    ��   : o00132663
        �޸�����   : ���ⵥ�ţ�AT2D09746,��B036�����ն��Զ������ԡ�����ר����ԣ�ϵͳģʽָʾ���У�
                     ���ʳ����ֶ���������������ɹ������
     54.��    ��   : 2009��04��03��
        ��    ��   : s46746
        �޸�����   : ���ⵥ�ţ�AT2D10632,TA��֤����Ҫ�ϱ�����״̬�¼��Լ�EPLMN��FPLMN��IMSI Detach�¼�
     55.��    ��   : 2009��04��24��
        ��    ��   : s62952
        �޸�����   : ���ⵥAT2D11028
     56.��    ��   : 2009��4��29��
        ��    ��   : h44270
        �޸�����   : AT2D11218/AT2D11516
     57.��    ��   : 2009��08��15��
        ��    ��   : x00115505
        �޸�����   : AT2D13800,NV��ָ�����ʱ�������һ��ʽ�����Ͷ�������ʱ���Ƚϳ�
     58.��    ��   : 2009��09��01��
        ��    ��   : x00115505
        �޸�����   : AT2D14166,�ػ�֮��û�з���״̬�仯�������ϱ�^SRVST
     59.��    ��   : 2009��9��7��
        ��    ��   : s46746
        �޸�����   : �������ⵥ�ţ�AT2D14311������������GMM��������ʱ�Ƚ����������ͷţ��ᵼ�·���״̬��ʱ����ΪNormal service
     60.��    ��   : 2009��10��3��
        ��    ��   : s46746
        �޸�����   : ���ⵥ�ţ�AT2D14936,Location Status Event ���͵�ʱ������������ȷ
     61.��    ��   : 2009��10��28��
        ��    ��   : x00115505
        �޸�����   : ���ⵥ�ţ�AT2D15171,AT+COPS���ĸ�ע����3G����LED�̵Ƶ���һ��ʱ����ٸı�����Ƶ���
     62.��    ��   : 2009��11��13��
        ��    ��   : s46746
        �޸�����   : ���ⵥ�ţ�AT2D15442,NAS�·���STK���¼�Location status EVENT ����
     63.��    ��   : 2009��11��28��
        ��    ��   : s46746
        �޸�����   : ���ⵥ�ţ�AT2D15677,�Ĵ��������ζ��ƺ���
     64.��    ��   : 2010��01��11��
        ��    ��   : x00115505
        �޸�����   : ���ⵥ�ţ�AT2D16304,V2 STK������������
     65.��    ��   : 2010��04��21��
        ��    ��   : s46746
        �޸�����   : ���ⵥ�ţ�AT2D18703,����ҪPIN/PUK/PUKʣ�����Ϊ0�Լ�����ʱ,AT+CFUN=1����OK.
     66.��    ��   : 2010��07��20��
        ��    ��   : s62952
        �޸�����   : ����ģʽ����
     67.��    ��   : 2012��03��7��
        ��    ��   : z60575
        �޸�����   : ���ⵥDTS2012030702528
*****************************************************************************/

#include "MmaAppLocal.h"
#include "rfa.h"
#include "NasOmInterface.h"
#include "TTFMemInterface.h"
#include "NVIM_Interface.h"
#include "mdrv.h"
/* Deleted by z00161729 for �����ϱ�AT�������������C��, 2013-4-7, begin */
/* ɾ��ExtAppMmcInterface.h*/
/* Deleted by z00161729 for �����ϱ�AT�������������C��, 2013-4-7, end */

#include "TafAppMma.h"
#include "TafMmcInterface.h"
#if ( FEATURE_ON == FEATURE_LTE )
#include "msp_nvim.h"
#endif
#include "NasUtranCtrlInterface.h"

#include "TafSdcLib.h"
#include "Taf_Status.h"

#include "NasUsimmApi.h"
#include "TafLog.h"
/* Added by w00176964 for VoLTE_PhaseI��Ŀ, 2013-7-15, begin */
#include "TafMmaCtx.h"
/* Added by w00176964 for VoLTE_PhaseI��Ŀ, 2013-7-15, end */

#include "NasMtaInterface.h"

/* Added by l00208543 for V9R1 STK����, 2013-07-10, begin */
#include "NasStkInterface.h"
/* Added by l00208543 for V9R1 STK����, 2013-07-10, end */

/* Added by j00174725 for V9R1 ���ſ���, 2013/08/13, begin */
#if (FEATURE_MULTI_MODEM == FEATURE_ON)
#include "MtcMmaInterface.h"
#endif
/* Added by j00174725 for V9R1 ���ſ���, 2013/08/13, end */

/* Added by w00176964 for VoLTE_PhaseII ��Ŀ, 2013-10-10, begin */
#include "TafMmaSndTaf.h"
#include "TafMmaProcNvim.h"
/* Added by w00176964 for VoLTE_PhaseII ��Ŀ, 2013-10-10, end */

/* Added by w00167002 for L-C��������Ŀ, 2014-2-14, begin */
#include "TafMmaSndApp.h"
/* Added by w00167002 for L-C��������Ŀ, 2014-2-14, end */
#include "TafMmaMntn.h"
#include "TafMmaSndMscc.h"
#include "NasComm.h"
#include "NasMntn.h"
#include "TafMmaComFunc.h"

#include "TafMmaSndMtc.h"


#ifdef  __cplusplus
  #if  __cplusplus
  extern "C"{
  #endif
#endif

/*****************************************************************************
    Э��ջ��ӡ��㷽ʽ�µ�.C�ļ��궨��
*****************************************************************************/
/*lint -e767 �޸���:luojian 107747;������:sunshaohua65952;ԭ��:LOG���������Ҫ*/
#define    THIS_FILE_ID        PS_FILE_ID_TAF_STATUS_C
/*lint +e767 �޸���:luojian 107747;������:sunshaohua*/
/* Deleted by w00176964 for VoLTE_PhaseI��Ŀ, 2013-7-11, begin */

/* Deleted by w00176964 for VoLTE_PhaseI��Ŀ, 2013-7-11, end */
/* STATUS ȫ�ֹ������� */
STATUS_CONTEXT_STRU                     g_StatusContext;
extern TAF_MMA_GLOBAL_VALUE_ST          gstMmaValue;

/* Deleted by w00176964 for VoLTE_PhaseI��Ŀ, 2013-7-11, begin */

/* Deleted by w00176964 for VoLTE_PhaseI��Ŀ, 2013-7-11, end */

extern MMA_ME_PERSONALISATION_STATUS_STRU  g_stMmaMePersonalisationStatus;

MN_PH_REG_TIME_INFO_STRU            g_stRegTimeInfo = {0, 0, 0, 0};

extern MMA_TIMER_ST                            g_stPowerDownDelayTimer;

/* Deleted by w00176964 for VoLTE_PhaseI��Ŀ, 2013-7-12, begin */

/* Deleted by w00176964 for VoLTE_PhaseI��Ŀ, 2013-7-12, end */

extern VOS_UINT32                       g_ucUsimHotOutFlag;

/* Deleted by w00176964 for VoLTE_PhaseI��Ŀ, 2013-7-11, begin */

/* Deleted by w00176964 for VoLTE_PhaseI��Ŀ, 2013-7-11, end */


VOS_UINT32                              aStaTimerLen[STA_TIMER_BUTT] = {0};

/* Added by l00208543 for V9R1 STK����, 2013-08-01, begin */
extern TAF_MMA_LOCATION_STATUS_EVENT_INFO_STRU g_stMmsStkLocStaSysInfo;
/* Added by l00208543 for V9R1 STK����, 2013-08-01, end */

VOS_UINT8 g_MMA_IccStatus = 0xFE;

extern MMA_DEACT_SIM_WHEN_POWEROFF_ENUM_UINT8  g_ucMmaDeactSimWhenPoweroff;

#define STA_INFO_PRINT     PS_LOG_LEVEL_INFO
#define STA_NORMAL_PRINT   PS_LOG_LEVEL_NORMAL
#define STA_WARNING_PRINT  PS_LOG_LEVEL_WARNING
#define STA_ERROR_PRINT    PS_LOG_LEVEL_ERROR


/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
/*----------- STATUS ��TAFM�ṩ��API�ӿں��� ------------*/
/*=======================================================*/

/* Deleted by z00161729 for �����ϱ�AT�������������C��, 2013-4-4, begin */

/* Deleted by z00161729 for �����ϱ�AT�������������C��, 2013-4-4, end */

/*lint -save -e958 */

/*************************************************
  Function:
    Sta_MsgReqAbort
  Description:
     ��ֹδ��ɵ�������̣�
     ���ϱ���Ӧ�¼�֪ͨ�������ߡ�
  Calls:                 �����������õĺ����嵥
  Called By:             ���ñ������ĺ����嵥
  Input:
    VOS_UINT32  ulAbortType;    �ϱ��¼��Ĳ�������
        STA_MSGABORT_OK     ���������¼�
        STA_MSGABORT_ERR    ���ش����¼�
  Output:
    ��
  Return:
    STA_SUCCESS,        =0, �������أ�
    STA_ERROR,          =1, ���󷵻أ�
  Others:
      1.��    ��   : 2008��10��16��
        ��    ��   : l00130025
        �޸�����   : �������ⵥ�ţ�AT2D6236:����TAF_PH_EVT_SYS_CFG_CNF��Ϣ�ϱ�
      2.��    ��   : 2011��11��08��
        ��    ��   : c00173809
        �޸�����   : AT Project
      3.��    ��   : 2015��3��6��
        ��    ��   : b00269685
        �޸�����   : �б����ϱ��޸�
*************************************************/
VOS_UINT32 Sta_MsgReqAbort ( VOS_UINT32 ulAbortType )
{
    VOS_UINT32      ulEvent;        /* �¼����� */

    /* δ�������������� */
    switch ( g_StatusContext.ulFsmState )
    {
        case STA_FSM_RESTART:
            ulEvent = TAF_PH_EVT_OPER_MODE_CNF;
            break;
        case STA_FSM_STOP:
            ulEvent = TAF_PH_EVT_OPER_MODE_CNF;
            break;
        case STA_FSM_PLMN_LIST:
            if (STA_MSGABORT_OK != ulAbortType)
            {
                TAF_MMA_PlmnListQryAbortReport();
            }
            else
            {
                g_StatusContext.ucOperateType |= STA_OP_PLMNLIST;
                Sta_PlmnListEventReport();
            }
            return STA_SUCCESS;
        case STA_FSM_PLMN_SEL:
            TAF_MMA_ProcPlmnSpecialSelCnf(TAF_ERR_NO_ERROR);
            return STA_SUCCESS;

        case STA_FSM_PLMN_RESEL:
            TAF_MMA_ProcPlmnAutoReselCnf(TAF_ERR_NO_ERROR);
            return STA_SUCCESS;


        /* �����SYSCFG���̣���SYSCFG״̬���д���abort���˴�ɾ�� */

        default:
            /* δָ����������̣����ش��� */
            return STA_ERROR;
    }

    /* ȷ�������¼��������� */
    if ( STA_MSGABORT_OK != ulAbortType )
    {
        g_StatusContext.ucOperateType = STA_OP_PHONEERROR;
    }

    Sta_EventReport ( g_StatusContext.ulCurOpId, ulEvent );

    return STA_SUCCESS;
}


/*****************************************************************************
 �� �� ��  : MN_PH_UpdateBeginRegInfo
 ��������  : ���¿�ʼע�������Ϣ
 �������  : ��
 �������  : ��
 �� �� ֵ  : VOS_VOID
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2010��9��8��
    ��    ��   : zhoujun /40661
    �޸�����   : �����ɺ���
  2.��    ��   : 2013��7��30��
    ��    ��   : w00176964
    �޸�����   : VoLTE_PhaseI��Ŀ�޸�:g_ucMsccMsccNeedPin1ȫ�ֱ���ɾ��ʹ��SDC��SIM��״̬�滻
  3.��    ��   : 2014��1��28��
    ��    ��   : s00217060
    �޸�����   : DTS2014011709107
*****************************************************************************/
VOS_VOID MN_PH_UpdateBeginRegTime( VOS_VOID  )
{
    /* Modified by w00176964 for VoLTE_PhaseI��Ŀ, 2013-7-12, begin */
    VOS_UINT8                           ucSdcSimStatus;
    VOS_UINT8                           ucIsNeedPin;

    ucSdcSimStatus          = TAF_SDC_GetSimStatus();

    /* ��״̬Ϊ��ҪPIN��PUKʱ����Ϊ��ҪPIN�� */
    if ( (TAF_SDC_USIM_STATUS_SIM_PIN   == ucSdcSimStatus)
      || (TAF_SDC_USIM_STATUS_SIM_PUK   == ucSdcSimStatus) )
    {
        ucIsNeedPin = VOS_TRUE;
    }
    else
    {
        ucIsNeedPin = VOS_FALSE;
    }

    if ( ((TAF_MMA_FSM_PHONE_MODE        == TAF_MMA_GetCurrFsmId())
       || (MN_PH_REG_TIME_STATE_PINVALID == g_stRegTimeInfo.enRegTimeState))
      && (VOS_FALSE == ucIsNeedPin) )
    {
        g_stRegTimeInfo.ulBeginTick = VOS_GetSlice();
        MN_INFO_LOG1("MN_PH_UpdateBeginRegTime:first time",(VOS_INT16)g_stRegTimeInfo.ulBeginTick);
    }

    if (VOS_FALSE == ucIsNeedPin)
    /* Modified by w00176964 for VoLTE_PhaseI��Ŀ, 2013-7-12, end */
    {
        MN_INFO_LOG1("MN_PH_UpdateBeginRegTime:second time,no need pin",(VOS_INT16)g_stRegTimeInfo.ulBeginTick);
        g_stRegTimeInfo.enRegTimeState = MN_PH_REG_TIME_STATE_BEGIN;
        g_stRegTimeInfo.ulCostTime     = 0;
    }
    else
    {
        MN_INFO_LOG("MN_PH_UpdateBeginRegTime:need pin");
        g_stRegTimeInfo.enRegTimeState = MN_PH_REG_TIME_STATE_PINVALID;
    }
}

/*****************************************************************************
 �� �� ��  : MN_PH_UpdateEndRegTime
 ��������  : ����ע�����ʱ��
 �������  : ��
 �������  : ��
 �� �� ֵ  :
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2010��9��8��
    ��    ��   : zhoujun /40661
    �޸�����   : �����ɺ���
  2.��    ��   : 2013��03��07��
    ��    ��   : f00179208
    �޸�����   : timer�ɵݼ�ת��Ϊ����
  3.��    ��   : 2014��1��28��
    ��    ��   : s00217060
    �޸�����   : DTS2014011709107:MMA����ATʱ��slice�ϱ�
*****************************************************************************/
VOS_VOID  MN_PH_UpdateEndRegTime( VOS_VOID )
{
    if ( MN_PH_REG_TIME_STATE_BEGIN != g_stRegTimeInfo.enRegTimeState )
    {
        return;
    }

    g_stRegTimeInfo.ulEndTick = VOS_GetSlice();
    MN_INFO_LOG2("MN_PH_UpdateEndRegTime beginTick = 0x%x,endtick = 0x%x\r\n",
                 (VOS_INT16)g_stRegTimeInfo.ulBeginTick,(VOS_INT16)g_stRegTimeInfo.ulEndTick);

    /* ʱ�������0��ʼ���������Ե�ǰ��ʱ���Ӧ�ô����ϴΡ�����ʱ���
       ��0xFFFFFFFFʱ�����õ�0������else��֧����������� */
    /* MMA����ATʱ����slice�ϱ���(32 * 1024)��slice��1S
       ���sliceΪ0����ʾû��ע��ɹ������sliceС��1S,AT��1S�ϱ� */
    if (g_stRegTimeInfo.ulEndTick >= g_stRegTimeInfo.ulBeginTick)
    {
        g_stRegTimeInfo.ulCostTime
            = (g_stRegTimeInfo.ulEndTick - g_stRegTimeInfo.ulBeginTick);
    }
    else
    {
        /*lint -e961*/
        g_stRegTimeInfo.ulCostTime
            = (0xFFFFFFFF - g_stRegTimeInfo.ulBeginTick + g_stRegTimeInfo.ulEndTick);
        /*lint +e961*/
    }

    MN_INFO_LOG1("Into MN_PH_UpdateEndRegTime ulCostTime = 0x%x\r\n",(VOS_INT16)g_stRegTimeInfo.ulCostTime);
    g_stRegTimeInfo.enRegTimeState  = MN_PH_REG_TIME_STATE_END;
    g_stRegTimeInfo.ulEndTick       = 0;

}

/* Deleted by w00176964 for VoLTE_PhaseI��Ŀ, 2013-7-12, begin */

/* Deleted by w00176964 for VoLTE_PhaseI��Ŀ, 2013-7-12, end */


/*************************************************
  Function:
    Sta_PlmnList
  Description:
    PLMN����������ں���
  Calls:             �����������õĺ����嵥
  Called By:         ���ñ������ĺ����嵥
  Input:
    VOS_UINT32  ulOpId;  ���������ʶ
  Output:
    ��
  Return:
    ��
  Others:
      1.��    ��   : 2011��11��08��
        ��    ��   : c00173809
        �޸�����   : AT Project
  2.��    ��   : 2012��6��13��
    ��    ��   : l60609
    �޸�����   : AT&T&DCM:��ͻ����
  3.��    ��   : 2013��4��1��
    ��    ��   : z00161729
    �޸�����  : �����ϱ�AT�������������C�˼�mma��mscc�ӿڵ���
  4.��    ��   : 2015��3��12��
    ��    ��   : b00269685
    �޸�����   : �б����ϱ��޸�
*************************************************/
VOS_UINT32 Sta_PlmnList (VOS_VOID)
{
    /* Modified by z00161729 for �����ϱ�AT�������������C��, 2013-4-1, begin */
    VOS_UINT32          ulRet;
    /* Modified by z00161729 for �����ϱ�AT�������������C��, 2013-4-1, end */

    /* PLMN_LIST״̬������������쳣*/
    /* ֻ����ENABLE״̬������REFRESH�������Զ������������·�list���󣬷��򷵻ش���*/
    if (VOS_TRUE != TAF_MMA_IsEnablePlmnList())
    {
        TAF_MMA_PlmnListErrorReport(TAF_ERR_PHONE_MSG_UNMATCH);

        return STA_ERROR;       /* ���󷵻� */
    }


    /* Modified by z00161729 for �����ϱ�AT�������������C��, 2013-4-1, begin */
    ulRet = TAF_MMA_SndMsccPlmnListReq();

    if ( VOS_ERR == ulRet )
    /* Modified by z00161729 for �����ϱ�AT�������������C��, 2013-4-1, end */
    {
        STA_TRACE (STA_ERROR_PRINT,
            "Sta_PlmnList():ERROR: failed");

        TAF_MMA_PlmnListErrorReport(TAF_ERR_ERROR);

        return STA_ERROR;       /* ���󷵻� */
    }

    /* ����PLMN_LIST״̬��־�� */
    g_StatusContext.ulFsmState = STA_FSM_PLMN_LIST;

    /* ����PLMN_LIST״̬��ʱ�� */
    g_StatusContext.aucFsmSubFlag[0]         = STA_FSMSUB_MONO;
    g_StatusContext.aFsmSub[0].ucFsmStateSub = STA_FSMSUB_MONO;
    g_StatusContext.aFsmSub[0].TimerName     = STA_TIMER_PLMN_LIST;
    ulRet = NAS_StartRelTimer (
            &g_StatusContext.ahStaTimer[0],
            WUEPS_PID_MMA,
            aStaTimerLen[STA_TIMER_PLMN_LIST],
            TAF_MMA,
            MMA_MAKELPARAM(0, STA_TIMER_PLMN_LIST),
            VOS_RELTIMER_NOLOOP
            );
    if ( VOS_OK != ulRet )
    {
        /* �ָ�ԭ������״̬��־ */
        if ( STA_ERROR
            == Sta_UpdateFsmFlag(STA_FSMSUB_NULL,
                STA_FSM_NULL, STA_UPDATE_MONO_CLEAR) )
        {
            STA_TRACE (STA_ERROR_PRINT,
                "Sta_PlmnList():ERROR:timer clear failed\n");
        }
        return STA_ERROR;
    }


    return STA_SUCCESS;         /* �������� */
}

/* �ú����Ѿ��޸�ΪTAF_MMA_ProcPlmnAutoReselReq_Main */

/*************************************************
  Function:
    Sta_PlmnSelect
  Description:
    ָ��PLMNѡ�������ں���
  Calls:                 �����������õĺ����嵥
  Called By:             ���ñ������ĺ����嵥
  Input:
    VOS_UINT32            ulOpId;   ���������ʶ
    TAF_PLMN_ID_STRU  PlmnId;   ָ����PLMN
    TAF_ACCESS_MODE AccessMode  ָ���Ľ���ģʽ
    VOS_UINT8 ucReselMode       ָ��PLMNʧ�ܺ����ѡģʽ
  Output:
    ��
  Return:
    ��
  Others:
    modified by l48197 Oct.28, 2005, add a Parametre, which
    select the access mode of MS;

  1.��    ��   : 2012��6��15��
    ��    ��   : l60609
    �޸�����   : AT&T&DCM:���ӳ�ͻ����
  2.��    ��   : 2013��2��25��
    ��    ��   : s00217060
    �޸�����   : DTS2013020206377:USIM����ֹGSM���벢����G��ģʱ���������û�ָ����
                 SIM��������L��ģʱ��Ҳ�������û�ָ����
  3.��    ��  : 2013��4��1��
   ��    ��   : z00161729
   �޸�����  : �����ϱ�AT�������������C�˼�mma��mscc�ӿڵ���

  4.��    ��   : 2013��11��1��
    ��    ��   : z00161729
    �޸�����  : DTS2013111103301:svlte��Ҫ�ػ�״̬֧��cops���ã�����nv������ģʽ
  5.��    ��   : 2014��7��22��
    ��    ��   : b00269685
    �޸�����   : Fortify ����
*************************************************/
VOS_VOID Sta_PlmnSelect ( VOS_UINT32 ulOpID, TAF_PLMN_ID_STRU PlmnId,
                        TAF_PH_RA_MODE AccessMode, VOS_UINT8 ucReselMode)
{
    VOS_UINT32                      ulRet;



    /* Modified by z00161729 for �����ϱ�AT�������������C��, 2013-4-1, begin */
    /* ��¼������� */
    g_StatusContext.StaPlmnId.Mcc = PlmnId.Mcc;
    g_StatusContext.StaPlmnId.Mnc = PlmnId.Mnc;

    ulRet = TAF_MMA_SndMsccPlmnSpecialReq((MMA_MSCC_PLMN_ID_STRU *)&PlmnId, AccessMode);

    if ( VOS_ERR == ulRet )
    /* Modified by z00161729 for �����ϱ�AT�������������C��, 2013-4-1, end */
    {
        STA_TRACE (STA_WARNING_PRINT,
            "Sta_PlmnSelect():WARNING: failed");
        return;           /* ���󷵻� */
    }
    /* ��¼��ǰ�Ĳ������̱�ʶ�� */
    g_StatusContext.ulCurOpId = ulOpID;

    /* �ϱ�APP��ǰ״̬�¼� */
    /*Sta_EventReport (ulOpID, TAF_PH_EVT_PLMN_SEL);*/

    /* ����PLMN_SEL״̬��־�� */
    g_StatusContext.ulFsmState = STA_FSM_PLMN_SEL;

    STA_TRACE1(STA_NORMAL_PRINT, "@@@@Sta_PlmnSelect:FsmState=",STA_FSM_PLMN_SEL);
    /* ����PLMN_SEL״̬��ʱ�� */
    TAF_MMA_StartTimer(TI_TAF_MMA_WAIT_MSCC_PLMN_SPECIAL_SEL_CNF, TI_TAF_MMA_WAIT_MSCC_PLMN_SPECIAL_RESEL_SET_CNF_LEN);

    /* ��¼��ǰ�Ĳ������̱�ʶ�� */
    g_StatusContext.aFsmSub[0].ulOpId = ulOpID;
    /*
    ��յ�ǰ��PLMNid
    modified by liuyang id:48197 date:2005-9-5 for V200R001
    */
    /* Sta_ClearCurPlmnId( &(g_StatusContext.CurPlmnId) ); */
    return;         /* �������� */
}

/*************************************************
  Function:
    Sta_TimeoutProc
  Description:
    ��ʱ����ʱ��������
  Calls:                     �����������õĺ����嵥
  Called By:                 ���ñ������ĺ����嵥
  Input:
    REL_TIMER_MSG   *pMsg;   ��ʱ�������ṹָ��
  Output:
    ��
  Return:
    ��
  Others:

  1.��    ��   : 2006��3��14��
    ��    ��   : liuyang id:48197
    �޸�����   : ���ⵥ�ţ�A32D02500���������̸��ģ���ʱ��������

  2.��    ��   : 2006��3��27��
    ��    ��   : liuyang id:48197
    �޸�����   : ���ⵥ��:A32D02372
  3.��    ��   : 2007��07��21��
    ��    ��   : l60022475
    �޸�����   : A32D12535
  4.��    ��   : 2011��09��20��
    ��    ��   : w00176964
    �޸�����   : V7R1 PhaseII �б�����״̬������
  5.��    ��   : 2011��12��7��
    ��    ��   : z00161729
    �޸�����   : V7R1 PhaseIVָ��������abort�����޸�
  6.��    ��   : 2012��6��14��
    ��    ��   : l60609
    �޸�����   : AT&T&DCM:���ӳ�ͻ����
  7.��    ��   : 2012��8��10��
    ��    ��   : y00213812
    �޸�����   : DTS2012082204471, TQE����
  8.��    ��   : 2012��9��18��
    ��    ��   : s00217060
    �޸�����   : for V7R1C50_At_Abort
  9.��    ��   : 2013��4��1��
    ��    ��   : z00161729
    �޸�����   : �����ϱ�AT�������������C�˼�mma��mscc�ӿڵ���
 10.��    ��   : 2013��7��10��
    ��    ��   : w00176964
    �޸�����   : VoLTE_Phase1��Ŀ:���ػ���ʱ���������
***************************************************************************/
VOS_VOID Sta_TimeoutProc (REL_TIMER_MSG * pMsg)
{
    STA_TIMER_NAME_E                    TimerId;    /* ��ʱ��״̬����*/
    VOS_UINT16                          TimerIndex; /* ��ʱ����� */
    VOS_UINT32                          ulOpId;

    ulOpId  = STA_OPID_INVALID;

    /* ������� */
    if ( VOS_NULL_PTR == pMsg )
    {
        STA_TRACE (STA_ERROR_PRINT,
            "Sta_TimeoutProc():ERROR:parameter invaild null PTR");
        return;
    }

    /*��ȡϵͳ��ʱ����Ϣ,�õ���ʱ��ID�Ͷ�ʱ������*/
    TimerId     = (STA_TIMER_NAME_E)MMA_LOWORD(pMsg->ulPara);
    TimerIndex  = MMA_HIWORD(pMsg->ulPara);
    STA_TRACE1 (STA_WARNING_PRINT,
            "Sta_TimeoutProc():WARNING:Status Time Out, TimerId is ",TimerId);

    if (TimerIndex >= STA_TIMER_MAX)
    {
        STA_TRACE (STA_ERROR_PRINT,
                "Sta_TimeoutProc():TimerIndex over run.");
        return;
    }

    /* ϵͳ��ʱ����Ϣ�ַ�����*/
    switch ( TimerId )
    {
        /* Deleted by w00176964 for VoLTE_PhaseI��Ŀ, 2013-7-10, begin */

        /* Deleted by w00176964 for VoLTE_PhaseI��Ŀ, 2013-7-10, end */

        case STA_TIMER_PLMN_LIST :


            /* ��ʱ����AT�ظ�������յ�ID_MSCC_MMA_PLMN_LIST_ABORT_CNF ����
               AT�ظ�*/

            /*�����ǰ״̬��־���ص�ENABLE״̬*/
            /*  �����״̬������Ϣ */
            /*��ʱӦ��OpId��Ϊ��Чֵ*/
            ulOpId                                     = g_StatusContext.aFsmSub[TimerIndex].ulOpId;
            g_StatusContext.aFsmSub[TimerIndex].ulOpId = STA_OPID_INVALID;

            g_StatusContext.aFsmSub[TimerIndex].ucFsmStateSub
                = STA_FSMSUB_NULL;
            g_StatusContext.aFsmSub[TimerIndex].TimerName
                = STA_TIMER_NULL;
            g_StatusContext.aucFsmSubFlag[TimerIndex]
                = STA_FSMSUB_NULL;

            /* ���ô������� */
            TAF_MMA_RcvTimerPlmnListCnfExpired(ulOpId);

            break;


        default :
            /* do nothing */
            /* ������ٵ�����Ϣ */
            STA_TRACE (STA_NORMAL_PRINT,
                "Sta_TimeoutProc():NORMAL:do nothing");
            return;
    }

    return;     /* �������� */
}

/* Deleted by s00217060 for VoLTE_PhaseI  ��Ŀ, 2013-07-13, begin */
/* ɾ�� Sta_SoftReset ( VOS_UINT8 ucResetMode )*/
/* Deleted by s00217060 for VoLTE_PhaseI  ��Ŀ, 2013-07-13, end */

/* delete Sta_PlmnListAbort*/


/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
/*---------- Э��ջ��Ӧ��Ϣ��������(�ڲ�ʹ��) -----------*/
/*=======================================================*/




/*lint -e438 -e830*/


/*lint +e438 +e830*/


/* Deleted by w00176964 for VoLTE_PhaseI��Ŀ, 2013-7-12, begin */

/* Deleted by w00176964 for VoLTE_PhaseI��Ŀ, 2013-7-12, end */


/*****************************************************************************
 Prototype    : Sta_SelPlmnSpecializeCnf
 Description  : �ж�ָ��PLMN�����Ƿ�ʧ��
 Input        : None
 Output       : None
 Return Value : ��
 Calls        :
 Called By    :

  History        :
  1.Date         : 2005/11/6
    Author       : liuyang, id:48197
    Modification : Created function

  2.��    ��   : 2006��3��30��
    ��    ��   : liuyang id:48197
    �޸�����   : ���ⵥ�ţ�A32D02372

  3.��    ��   : 2007��2��2��
    ��    ��   : x51137
    �޸�����   : ���ⵥ�ţ�A32D08596
  4.��    ��   : 2010��12��04��
    ��    ��   : lijun 00171473
    �޸�����   : DTS2010112602423,PDP����ʱָ�������ĳ����뵱ǰΪ30,�ָ�Ϊ3
  5.��    ��   : 2012��4��11��
    ��    ��   : l00130025
    �޸�����   : DTS2012032600471,��ʱ��ֹͣ����û�й��������������ⶨλ
  6.��    ��   : 2012��8��10��
    ��    ��   : y00213812
    �޸�����   : DTS2012082204471, TQE����
  7.��    ��   : 2013��4��2��
    ��    ��   : z00161729
    �޸�����  : �����ϱ�AT�������������C�˼�mma��mscc�ӿڵ���
*****************************************************************************/
VOS_UINT32 Sta_SelPlmnSpecializeCnf( VOS_UINT32 ulResult )
{
    STA_TRACE1(STA_NORMAL_PRINT, "@@@@Sta_SelPlmnSpecializeCnf:FsmState=",(VOS_INT32)g_StatusContext.ulFsmState);

    /* Modified by z00161729 for �����ϱ�AT�������������C��, 2013-4-7, begin */

    /*�ڲ������ָ����������,ֻ�����ֶ���ѡ�Ĺ�����,���PLMNList��ᷢ��*/

    TAF_MMA_ReportSpecPlmnSrchResult(ulResult);
    /*modified by Y00213812 for DTS2012082204471 TQE����, 2012-08-10, begin*/
    g_StatusContext.ulFsmState = STA_FSM_ENABLE;
    /*modified by Y00213812 for DTS2012082204471 TQE����, 2012-08-10, end*/
    return MMA_SUCCESS;
}
/*****************************************************************************
 Prototype    : Sta_SelPlmnAutoSelCnf
 Description  : �ж�auto PLMN�����Ƿ�ʧ��
 Input        : None
 Output       : None
 Return Value : VOS_UINT32
 Calls        :
 Called By    :

  History        :
  1.Date         : 2005/11/6
    Author       : liuyang, id:48197
    Modification : Created function

  2.��    ��   : 2006��3��30��
    ��    ��   : liuyang id:48197
    �޸�����   : ���ⵥ�ţ�A32D02372

  3.��    ��   : 2007��2��2��
    ��    ��   : x51137
    �޸�����   : ���ⵥ�ţ�A32D08596
  4.��    ��   : 2010��12��04��
    ��    ��   : lijun 00171473
    �޸�����   : DTS2010112602423,PDP����ʱָ�������ĳ����뵱ǰΪ30,�ָ�Ϊ3
  5.��    ��   : 2012��4��11��
    ��    ��   : l00130025
    �޸�����   : DTS2012032600471,��ʱ��ֹͣ����û�й��������������ⶨλ
  6.��    ��   : 2012��8��10��
    ��    ��   : y00213812
    �޸�����   : DTS2012082204471, TQE����
  7.��    ��   : 2013��4��2��
    ��    ��   : z00161729
    �޸�����  : �����ϱ�AT�������������C�˼�mma��mscc�ӿڵ���
*****************************************************************************/
VOS_UINT32 Sta_SelPlmnAutoSelCnf( VOS_UINT32 ulResult )
{
    STA_TRACE1(STA_NORMAL_PRINT, "@@@@Sta_SelPlmnAutoSelCnf:FsmState=",(VOS_INT32)g_StatusContext.ulFsmState);

    /* Modified by z00161729 for �����ϱ�AT�������������C��, 2013-4-7, begin */
    if ((STA_FSM_PLMN_RESEL == g_StatusContext.ulFsmState)
     && (NAS_MSCC_PIF_USER_PLMN_SEARCH_RESULT_REJ == ulResult))
    /* Modified by z00161729 for �����ϱ�AT�������������C��, 2013-4-7, end */
    {
        /*������״̬*/
        /*modified by Y00213812 for DTS2012082204471 TQE����, 2012-08-10, begin*/
        g_StatusContext.ulFsmState = STA_FSM_ENABLE;
        /*modified by Y00213812 for DTS2012082204471 TQE����, 2012-08-10, end*/

         /* �ϱ���ǰָ������ʧ�� */
        MMA_WARNINGLOG("Sta_SelPlmnAutoSelCnf():WARING:REJECT PLMN USER SEL");
        /* �ϱ�APP��ǰ״̬�¼� */
        TAF_MMA_ProcPlmnAutoReselCnf(TAF_ERR_ERROR);

        return MMA_SUCCESS;
    }

    /*�ڲ������ָ����������,ֻ�����ֶ���ѡ�Ĺ�����,���PLMNList��ᷢ��*/

    TAF_MMA_ReportAutoPlmnSrchResult(ulResult);

    /*modified by Y00213812 for DTS2012082204471 TQE����, 2012-08-10, begin*/
    g_StatusContext.ulFsmState = STA_FSM_ENABLE;
    /*modified by Y00213812 for DTS2012082204471 TQE����, 2012-08-10, end*/
    return MMA_SUCCESS;
}

/*****************************************************************************
 �� �� ��  : Sta_GetSysSubMode
 ��������  : ��ȡW�µ�ϵͳ��ģʽ
 �������  : STA_DATA_TRANSFER_STATUS_UINT8 ucDataTranAttri
 �������  : ��
 �� �� ֵ  : VOS_UINT8 ϵͳ��ģʽ
 ���ú���  :
 �޸���ʷ      :
  1.��    ��   : 2009��8��31��
    ��    ��   : o00132663
    �޸�����   : �����ɺ���

  2.��    ��   : 2010��5��11��
    ��    ��   : o00132663
    �޸�����   : AT2D18058, UE����ʾHSPA+ģʽ
  3.��    ��   : 2010��08��13��
    ��    ��   : w00166186
    �޸�����   : DTS2010081301232, �������

*****************************************************************************/
VOS_UINT8 Sta_GetSysSubMode_W(STA_DATA_TRANSFER_STATUS_UINT8      ucDataTranStatus ,
                                       STA_DATA_TRANSFER_MODE_UINT8        ucDataTranMode
                                       )
{
    VOS_UINT8                          ucSysSubMode;

    if (STA_DATA_TRANSFER_PDP_ACT == ucDataTranStatus)
    {
        switch  ( ucDataTranMode )
        {
            case STA_DATA_TRANSFER_HSDPA :
                ucSysSubMode = TAF_SYS_SUBMODE_HSDPA;
                break;
            case STA_DATA_TRANSFER_HSUPA :
                ucSysSubMode = TAF_SYS_SUBMODE_HSUPA;
                break;
            case STA_DATA_TRANSFER_HSDPA_AND_HSUPA :
                ucSysSubMode = TAF_SYS_SUBMODE_HSDPA_HSUPA;
                break;
            case STA_DATA_TRANSFER_HSPA_PLUS :
                ucSysSubMode = TAF_SYS_SUBMODE_HSPA_PLUS;
                break;

            case STA_DATA_TRANSFER_DC_HSPA_PLUS:
                ucSysSubMode = TAF_SYS_SUBMODE_DC_HSPA_PLUS;
                break;

            case STA_DATA_TRANSFER_DC_MIMO:
                ucSysSubMode = TAF_SYS_SUBMODE_DC_MIMO;
                break;



            default:
                ucSysSubMode = TAF_SYS_SUBMODE_WCDMA;
                break;
        }
    }
    else
    {
        ucSysSubMode = TAF_SYS_SUBMODE_WCDMA;
    }

    return ucSysSubMode;
}

/*****************************************************************************
 �� �� ��  : Sta_GetSysSubMode_Td
 ��������  : ��ȡTD�µ�ϵͳ��ģʽ
 �������  : STA_DATA_TRANSFER_STATUS_UINT8 ucDataTranAttri
 �������  : ��
 �� �� ֵ  : VOS_UINT8 ϵͳ��ģʽ
 ���ú���  :
 �޸���ʷ      :
  1.��    ��   : 2012��8��8��
    ��    ��   : s00217060
    �޸�����   : �����ɺ���
*****************************************************************************/
VOS_UINT8 Sta_GetSysSubMode_Td(
    STA_DATA_TRANSFER_STATUS_UINT8      ucDataTranStatus,
    STA_DATA_TRANSFER_MODE_UINT8        ucDataTranMode
)
{
    VOS_UINT8                          ucSysSubMode;

    if (STA_DATA_TRANSFER_PDP_ACT == ucDataTranStatus)
    {
        switch  ( ucDataTranMode )
        {
            case STA_DATA_TRANSFER_HSDPA :
                ucSysSubMode = TAF_SYS_SUBMODE_HSDPA;
                break;

            case STA_DATA_TRANSFER_HSUPA :
                ucSysSubMode = TAF_SYS_SUBMODE_HSUPA;
                break;

            case STA_DATA_TRANSFER_HSDPA_AND_HSUPA :
                ucSysSubMode = TAF_SYS_SUBMODE_HSDPA_HSUPA;
                break;

            case STA_DATA_TRANSFER_HSPA_PLUS :
                ucSysSubMode = TAF_SYS_SUBMODE_HSPA_PLUS;
                break;

            default:
                ucSysSubMode = TAF_SYS_SUBMODE_TD_SCDMA;
                break;
        }
    }
    else
    {
        ucSysSubMode = TAF_SYS_SUBMODE_TD_SCDMA;
    }

    return ucSysSubMode;
}
/*****************************************************************************
 �� �� ��  : Sta_ModeChangeEventReport
 ��������  : �ϱ�^MODE
 �������  : �µ�ϵͳģʽ/��ģʽ
 �������  : ��
 �� �� ֵ  : ��
 ���ú���  :
 �޸���ʷ      :
  1.��    ��   : 2009��8��31��
    ��    ��   : o00132663
    �޸�����   : �����ɺ���
*****************************************************************************/
VOS_VOID Sta_ModeChangeEventReport(VOS_UINT8 ucNewSysMode, VOS_UINT8 ucNewSysSubMode)
{
    TAF_MMA_MODE_CHANGE_IND_STRU        *pstModeChangeInd;

    if ( VOS_TRUE != TAF_MMA_IsModeChangeNeedRpt())
    {
        return ;
    }

    pstModeChangeInd = (TAF_MMA_MODE_CHANGE_IND_STRU *)PS_ALLOC_MSG_WITH_HEADER_LEN(WUEPS_PID_MMA, sizeof(TAF_MMA_MODE_CHANGE_IND_STRU));

    if (VOS_NULL_PTR == pstModeChangeInd)
    {
        MMA_ERRORLOG("Sta_ModeChangeEventReport:ERROR:ALLOC MEMORY FAIL.");
        return;
    }

    PS_MEM_SET((VOS_CHAR *)pstModeChangeInd + VOS_MSG_HEAD_LENGTH,
            0x00,
            (sizeof(TAF_MMA_MODE_CHANGE_IND_STRU) - VOS_MSG_HEAD_LENGTH));

    pstModeChangeInd->MsgHeader.ulReceiverPid          = WUEPS_PID_AT;
    pstModeChangeInd->MsgHeader.ulMsgName              = ID_TAF_MMA_MODE_CHANGE_IND;
    pstModeChangeInd->usClientId                       = MN_GetRealClientId(MMA_CLIENTID_BROADCAST, WUEPS_PID_TAF);
    pstModeChangeInd->ucOpId                           = MMA_OP_ID_INTERNAL;
    pstModeChangeInd->RatType                          = ucNewSysMode;
    pstModeChangeInd->ucSysSubMode                     = ucNewSysSubMode;

    PS_SEND_MSG(WUEPS_PID_MMA, pstModeChangeInd);

    return;
}

#if (FEATURE_ON == FEATURE_PTM)
/*****************************************************************************
 �� �� ��  : TAF_MMA_CheckRatValid
 ��������  : ����Ƿ�������Ҫ��¼�ĸı������ģʽ
 �������  : ϵͳģʽ
 �������  : ��
 �� �� ֵ  : VOS_TRUE ---- �ɹ�
             VOS_FALSE --- ʧ��
 ���ú���  :
 �޸���ʷ      :
  1.��    ��   : 2015��03��13��
    ��    ��   : zwx247453
    �޸�����   : �����ɺ���
*****************************************************************************/
VOS_UINT32 TAF_MMA_CheckRatValid(VOS_UINT8 ucSysMode)
{
    switch (ucSysMode)
    {
        case TAF_PH_INFO_GSM_RAT:
        case TAF_PH_INFO_WCDMA_RAT:
        case TAF_PH_INFO_LTE_RAT:
        case TAF_PH_INFO_TD_SCDMA_RAT:
            return VOS_TRUE;

        default:
            return VOS_FALSE;
    }
}

/*****************************************************************************
 �� �� ��  : TAF_MMA_RatFrequentlySwitchProc
 ��������  : �Ƚ϶��������Ƚ�����Ԫ�ظ���������Ԫ��ʱ����Ƿ���ϼ�¼�ϱ�
 �������  :
 �������  : ��
 �� �� ֵ  :
 ���ú���  :
 �޸���ʷ      :
  1.��    ��   : 2015��03��13��
    ��    ��   : zwx247453
    �޸�����   : �����ɺ���
*****************************************************************************/
VOS_VOID TAF_MMA_RatFrequentlySwitchProc(
    NAS_ERR_LOG_RAT_SWITCH_RECORD_STRU  *pstNewRatSwitchRecord
)
{
    NAS_ERR_LOG_RAT_SWITCH_RECORD_STRU  stOldRatSwitchRecord;
    VOS_UINT32                          ulNvStatisticTime;
    VOS_UINT32                          ulLength;
    VOS_UINT32                          ulFreeSize;
    VOS_UINT32                          ulActuallyReadLength;

    ulNvStatisticTime = TAF_SDC_GetErrlogRatSwitchStatisticTime();

    ulLength = sizeof(NAS_ERR_LOG_RAT_SWITCH_RECORD_STRU);

    /* ���OldRatSwitchRecord�ṹ */
    PS_MEM_SET(&stOldRatSwitchRecord, 0x00, ulLength);

    ulFreeSize = TAF_SDC_GetRatSwitchRingBufferFreeBytes();

    /* �����Ƿ��������������ͷ��β������ʱ����Ƿ�С��NV������ */
    if (0 == ulFreeSize)
    {
        ulActuallyReadLength = TAF_SDC_GetRecordFromRatSwitchRingBuf((VOS_CHAR *)&stOldRatSwitchRecord, ulLength);
        if (ulActuallyReadLength != ulLength)
        {
            return;
        }

        if ((pstNewRatSwitchRecord->ulSystemTick - stOldRatSwitchRecord.ulSystemTick)
            < (ulNvStatisticTime * PRE_SECOND_TO_TICK))
        {
            /* NV�涨ʱ���ڣ�rat�л������ﵽNV�涨����������Ƶ���л�����Ҫ��¼ */
            TAF_MMA_RatFrequentlySwitchRecord();
        }
    }

    return;
}

/*****************************************************************************
 �� �� ��  : TAF_MMA_RatSwitchRecord
 ��������  : �洢GUTLģʽ�л�����¼Ƶ�ʹ��ߵ��л�
 �������  : VOS_VOID
 �������  : ��
 �� �� ֵ  : ��
 ���ú���  :
 �޸���ʷ      :
  1.��    ��   : 2015��03��13��
    ��    ��   : zwx247453
    �޸�����   : �����ɺ���
*****************************************************************************/
VOS_VOID TAF_MMA_RatSwitchRecord(
    VOS_UINT8                           ucNewSysMode
)
{
    NAS_ERR_LOG_RAT_SWITCH_RECORD_STRU  stNewRatSwitchRecord;
    VOS_UINT32                          ulNvSwitchNum;                          /* NV���õ�gutl�л���ͳ�ƴ��� */
    VOS_UINT32                          ulNvStatisticTime;                      /* NV���õ�ͳ��ʱ�� */
    VOS_UINT32                          ulLength;
    VOS_UINT32                          ulActuallyWriteLength;
    TAF_PH_INFO_RAT_TYPE                ucOldSysMode;

    ulNvSwitchNum     = TAF_SDC_GetErrlogRatSwitchStatisticNum();
    ulNvStatisticTime = TAF_SDC_GetErrlogRatSwitchStatisticTime();

    PS_MEM_SET(&stNewRatSwitchRecord, 0, sizeof(NAS_ERR_LOG_RAT_SWITCH_RECORD_STRU));

    stNewRatSwitchRecord.ulSystemTick   = VOS_GetTick();
    stNewRatSwitchRecord.ucRatType      = ucNewSysMode;
    NAS_MNTN_OutputPositionInfo(&stNewRatSwitchRecord.stPositionInfo);

    /* �����ǰ�仯��״̬Ϊ�޷��������������Ҫ��¼��״̬�������κδ��� */
    if (VOS_FALSE == TAF_MMA_CheckRatValid(ucNewSysMode))
    {
        return;
    }

    /* ���NV���ȡ�����������쳣���򷵻� */
    if ((0 == ulNvSwitchNum)
     || (ulNvSwitchNum > NAS_ERR_LOG_MAX_RAT_SWITCH_RECORD_MUN))
    {
        return;
    }

    if ((0 == ulNvStatisticTime)
     || (ulNvStatisticTime > NAS_ERR_LOG_MAX_RAT_SWITCH_STATISTIC_TIME))
    {
        return;
    }

    /* ��ȡ�������һ�β���Ԫ�ص�ģʽ���� */
    ucOldSysMode = TAF_SDC_GetErrLogOldRatType();

    /* �����л���ģʽ��ǰһ���л���ģʽһ�£��򲻲������ */
    if (ucNewSysMode == ucOldSysMode)
    {
        return;
    }

    ulLength = sizeof(NAS_ERR_LOG_RAT_SWITCH_RECORD_STRU);

    /* ��Ԫ�ز��뵽������ */
    ulActuallyWriteLength = TAF_SDC_PutRatSwitchRingBuf((VOS_CHAR *)&stNewRatSwitchRecord, ulLength);
    if (ulActuallyWriteLength != ulLength)
    {
        NAS_ERROR_LOG(WUEPS_PID_MMA, "TAF_MMA_RatSwitchRecord(): Push buffer error.");

        return;
    }

    /* ������л���ģʽ��¼һ�� */
    TAF_SDC_SetErrLogOldRatType(ucNewSysMode);

    /* ���ģʽ�л�����Ƶ��������NV���ù涨��������¼�ϱ� */
    TAF_MMA_RatFrequentlySwitchProc(&stNewRatSwitchRecord);

    return;
}
#endif

/*****************************************************************************
 �� �� ��  : Sta_UpdateDataTranStatusAndMode
 ��������  : ����MSCC�ϱ���MSCC_DATATRAN_ATTRI_IND��Ϣ
              ����ȫ�ֱ����е�DataTranStatus��DataTranMode
 �������  : ucDataTranAttri MSCC�ϴ�����������
 �������  : ��
 �� �� ֵ  : VOS_VOID
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2012��8��8��
    ��    ��   : s00217060
    �޸�����   : for V7R1C50_GUTL_PhaseII �����ɺ���
  2.��    ��   : 2013��4��2��
    ��    ��   : z00161729
    �޸�����   : �����ϱ�AT�������������C�˼�mma��mscc�ӿڵ���
  3.��    ��   : 2014��11��28��
   ��    ��   : l00305157
   �޸�����   : �����ɺ���
*****************************************************************************/
VOS_VOID Sta_UpdateDataTranStatusAndMode(NAS_MSCC_PIF_DATATRAN_ATTRI_ENUM_UINT8 enDataTranAttri)
{
    /* Modified by z00161729 for �����ϱ�AT�������������C��, 2013-4-2, begin */

    switch (enDataTranAttri)
    {
        case NAS_MSCC_PIF_DATATRAN_ATTRI_PDP_ACT:
            g_StatusContext.ucDataTranStatus = STA_DATA_TRANSFER_PDP_ACT;

            if ((TAF_SDC_SYS_MODE_WCDMA == TAF_SDC_GetSysMode())
             && (STA_DATA_TRANSFER_MODE_BUTT == g_StatusContext.ucDataTranMode))
            {
                g_StatusContext.ucDataTranMode = STA_DATA_TRANSFER_R99_ONLY;
            }
            break;

        case NAS_MSCC_PIF_DATATRAN_ATTRI_PDP_DEACT:
            g_StatusContext.ucDataTranStatus = STA_DATA_TRANSFER_PDP_DEACT;
            break;

        case NAS_MSCC_PIF_DATATRAN_ATTRI_R99_ONLY:
            g_StatusContext.ucDataTranMode   = STA_DATA_TRANSFER_R99_ONLY;
            break;

        case NAS_MSCC_PIF_DATATRAN_ATTRI_HSDPA:
            g_StatusContext.ucDataTranMode   = STA_DATA_TRANSFER_HSDPA;
            break;

        case NAS_MSCC_PIF_DATATRAN_ATTRI_HSUPA:
            g_StatusContext.ucDataTranMode   = STA_DATA_TRANSFER_HSUPA;
            break;
        case NAS_MSCC_PIF_DATATRAN_ATTRI_HSDPA_AND_HSUPA:
            g_StatusContext.ucDataTranMode   = STA_DATA_TRANSFER_HSDPA_AND_HSUPA;
            break;

        case NAS_MSCC_PIF_DATATRAN_ATTRI_HSPA_PLUS:
            g_StatusContext.ucDataTranMode = STA_DATA_TRANSFER_HSPA_PLUS;
            break;

        /* Modified by z40661 for V7R1 ��� , 2012-02-20, begin */
        case NAS_MSCC_PIF_DATATRAN_ATTRI_LTE_DATA:
            g_StatusContext.ucDataTranStatus = STA_DATA_TRANSFER_PDP_ACT;
            g_StatusContext.ucDataTranMode = STA_DATA_TRANSFER_LTE_DATA;
            break;

        case NAS_MSCC_PIF_DATATRAN_ATTRI_LTE_IDLE:
            g_StatusContext.ucDataTranMode = STA_DATA_TRANSFER_LTE_IDLE;
            break;
        /* Modified by z40661 for V7R1 ��� , 2012-02-20, end */

        case NAS_MSCC_PIF_DATATRAN_ATTRI_DC_HSPA_PLUS:
            g_StatusContext.ucDataTranMode = STA_DATA_TRANSFER_DC_HSPA_PLUS;
            break;

        case NAS_MSCC_PIF_DATATRAN_ATTRI_DC_MIMO:
            g_StatusContext.ucDataTranMode = STA_DATA_TRANSFER_DC_MIMO;
            break;


        /* Modified by z00161729 for �����ϱ�AT�������������C��, 2013-4-2, end */
        default:
            STA_TRACE(STA_WARNING_PRINT, "Sta_DataTranAttri:Attri incorrect.");
            break;
    }

}

/*****************************************************************************
 �� �� ��  : Sta_DataTranAttri
 ��������  : �յ�MSCC�ϱ���MSCC_DATATRAN_ATTRI_IND��Ϣ
 �������  : ucDataTranAttri MSCC�ϴ�����������
 �������  : ��
 �� �� ֵ  : VOS_VOID
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2008��6��11��
    ��    ��   : sunxibo
    �޸�����   : �����ɺ���
  2.��    ��   : 2009��9��1��
    ��    ��   : ŷ���� o00132663
    �޸�����   : AT2D14178, ��ϵͳ��ģʽ�ı�ʱ���ϱ�^mode��

  3.��    ��   : 2010��5��11��
    ��    ��   : o00132663
    �޸�����   : AT2D18058, UE����ʾHSPA+ģʽ

  4.��    ��   : 2010��5��13��
    ��    ��   : o00132663
    �޸�����   : AT2D19345,����Ż�����ΪOAM�������������ѯ��ʽ
  5.��    ��   : 2010��8��14��
    ��    ��   : w00166186
    �޸�����   : DTS2010081301232

  6.��    ��   : 2012��2��20��
    ��    ��   : z40661
    �޸�����   : ����Lģ�ĵ�ƹ���

  7.��    ��   : 2012��6��1��
    ��    ��   : z40661
    �޸�����   : DTS2012053006110,����DC-HSPA+���ϱ�
  8.��    ��   : 2012��8��8��
    ��    ��   : s00217060
    �޸�����   : for  V7R1C50_GUTL_PhaseII 3G��ʱ������TD��W
  9.��    ��   : 2013��4��2��
    ��    ��   : z00161729
    �޸�����   : �����ϱ�AT�������������C�˼�mma��mscc�ӿڵ���
 10.��    ��   : 2012��07��15��
    ��    ��   : w00176964
    �޸�����   : VoLTE_PhaseI��Ŀ�޸�:�޸ĺ��������ͷ���ֵ
 11.��    ��   : 2014��11��29��
    ��    ��   : l00305157
    �޸�����   : Service_State_Optimize_PhaseI��Ŀ�޸�
*****************************************************************************/
VOS_UINT32 Sta_DataTranAttri(
    VOS_UINT32                          ulEventType,
    struct MsgCB                       *pstMsg
)
{
    VOS_UINT8   ucOldWSysSubMode = TAF_SYS_SUBMODE_WCDMA;
    VOS_UINT8   ucNewWSysSubMode = TAF_SYS_SUBMODE_WCDMA;

    VOS_UINT8   ucOldTdSysSubMode = TAF_SYS_SUBMODE_TD_SCDMA;
    VOS_UINT8   ucNewTdSysSubMode = TAF_SYS_SUBMODE_TD_SCDMA;

    /* Modified by z00161729 for �����ϱ�AT�������������C��, 2013-4-3, begin */
    TAF_SDC_SYS_MODE_ENUM_UINT8         enSysMode;
    /* Added by w00176964 for VoLTE_PhaseI��Ŀ, 2013-7-15, begin */
    MSCC_MMA_DATATRAN_ATTRI_IND_STRU    *pstDataTranAttri;

    pstDataTranAttri = (MSCC_MMA_DATATRAN_ATTRI_IND_STRU*)pstMsg;
    /* Added by w00176964 for VoLTE_PhaseI��Ŀ, 2013-7-15, end */

    enSysMode = TAF_SDC_GetSysMode();

    /* Modified by z00161729 for �����ϱ�AT�������������C��, 2013-4-3, end */

    STA_TRACE1(STA_NORMAL_PRINT, "Sta_DataTranAttri:ucDataTranAttri=",(VOS_INT32)pstDataTranAttri->enDataTranAttri);

    /* Modified by z00161729 for �����ϱ�AT�������������C��, 2013-4-2, begin */
    if (TAF_SDC_SYS_MODE_WCDMA == enSysMode)
    /* Modified by z00161729 for �����ϱ�AT�������������C��, 2013-4-2, end */
    {
        if (NAS_UTRANCTRL_UTRAN_MODE_FDD == NAS_UTRANCTRL_GetCurrUtranMode())
        {
            ucOldWSysSubMode = Sta_GetSysSubMode_W(g_StatusContext.ucDataTranStatus,
                                                   g_StatusContext.ucDataTranMode);
        }
        else
        {
            ucOldTdSysSubMode = Sta_GetSysSubMode_Td(g_StatusContext.ucDataTranStatus,
                                                     g_StatusContext.ucDataTranMode);
        }
    }

    /* ����ȫ�ֱ����е�DataTranStatus �� DataTranStatus */
    /* Modified by z00161729 for �����ϱ�AT�������������C��, 2013-4-2, begin */
    Sta_UpdateDataTranStatusAndMode(pstDataTranAttri->enDataTranAttri);
    /* Modified by z00161729 for �����ϱ�AT�������������C��, 2013-4-2, end */


    /* �ϱ�^MODE�¼������ϵͳ��ģʽ�иı� */
    /* Modified by z00161729 for �����ϱ�AT�������������C��, 2013-4-2, begin */
    if (TAF_SDC_SYS_MODE_WCDMA == enSysMode)
    /* Modified by z00161729 for �����ϱ�AT�������������C��, 2013-4-2, end */
    {
        if (NAS_UTRANCTRL_UTRAN_MODE_FDD == NAS_UTRANCTRL_GetCurrUtranMode())
        {
            /* ��ǰUTRAN_MODEΪFDDʱ���ϱ�W��ϵͳ��ģʽ */
            ucNewWSysSubMode = Sta_GetSysSubMode_W(g_StatusContext.ucDataTranStatus,
                                                   g_StatusContext.ucDataTranMode);

            if(ucOldWSysSubMode != ucNewWSysSubMode)
            {

                Sta_ModeChangeEventReport(TAF_PH_INFO_WCDMA_RAT, ucNewWSysSubMode);

#if (FEATURE_ON == FEATURE_PTM)
                TAF_MMA_RatSwitchRecord(TAF_PH_INFO_WCDMA_RAT);
#endif
            }
        }
        else
        {
            /* ��ǰUTRAN_MODEΪTDDʱ���ϱ�TD��ϵͳ��ģʽ */
            ucNewTdSysSubMode = Sta_GetSysSubMode_Td(g_StatusContext.ucDataTranStatus,
                                                     g_StatusContext.ucDataTranMode);

            if(ucOldTdSysSubMode != ucNewTdSysSubMode)
            {

                Sta_ModeChangeEventReport(TAF_PH_INFO_TD_SCDMA_RAT, ucNewTdSysSubMode);

#if (FEATURE_ON == FEATURE_PTM)
                TAF_MMA_RatSwitchRecord(TAF_PH_INFO_TD_SCDMA_RAT);
#endif
            }
        }
    }

    /* Modified by w00176964 for VoLTE_PhaseI��Ŀ, 2013-7-15, begin */
    return VOS_TRUE;
    /* Modified by w00176964 for VoLTE_PhaseI��Ŀ, 2013-7-15, end */
}

/*****************************************************************************
 �� �� ��  : Sta_GetServiceStatus
 ��������  : �õ���ǰ�ķ���״̬
 �������  : ��
 �������  : ��
 �� �� ֵ  : VOS_UINT32  ulServiceStatus
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2009��2��10��
    ��    ��   : sunxibo
    �޸�����   : �����ɺ���
  2.��    ��   : 2013��4��3��
    ��    ��   : z00161729
    �޸�����   : �����ϱ�AT�������������C�˼�mma��mscc�ӿڵ���
*****************************************************************************/
VOS_UINT32 Sta_GetServiceStatus()
{
    /* Modified by z00161729 for �����ϱ�AT�������������C��, 2013-4-3, begin */
    return TAF_SDC_GetServiceStatus();
    /* Modified by z00161729 for �����ϱ�AT�������������C��, 2013-4-3, end */
}

/*****************************************************************************
 �� �� ��  : Sta_IccStatusReport
 ��������  : �õ���ǰ�ķ���״̬
 �������  : ��
 �������  : ��
 �� �� ֵ  : VOS_UINT32  ulServiceStatus
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2009��2��10��
    ��    ��   : sunxibo
    �޸�����   : �����ɺ���
  2.��    ��   : 2013��4��3��
    ��    ��   : z00161729
    �޸�����   : �����ϱ�AT�������������C�˼�mma��mscc�ӿڵ���
  3.��    ��   : 2013��11��04��
    ��    ��   : s00217060
    �޸�����   : VoLTE_PhaseII��Ŀ
  4.��    ��   : 2014��4��29��
    ��    ��   : w00176964
    �޸�����   : ecall��Ŀ�޸�:ɾ��TAF_SDC_SERVICE_STATUS_NO_IMSI

*****************************************************************************/
VOS_VOID Sta_IccStatusReport(
    VOS_UINT32                          ucLastSimCsRegStatus,
    VOS_UINT32                          ucLastSimPsRegStatus
)
{
    /* Modified by w00176964 for VoLTE_PhaseI��Ŀ, 2013-8-1, begin */
    VOS_UINT8                           ucSimStatus;
    VOS_UINT8                           ucSimLockStatus;
    VOS_UINT8                           ucCurSimCsRegStatus;
    VOS_UINT8                           ucCurSimPsRegStatus;

#if (FEATURE_ON == FEATURE_UE_MODE_CDMA)
    if (VOS_TRUE == TAF_SDC_IsConfigCLMode())
    {
        ucSimStatus     = MMA_GetCsimStatus(VOS_FALSE);

        /* ��ȡ����״̬ */
        if (MMA_SIM_IS_LOCK == MMA_GetCsimMeLockStatus())
        {
            ucSimLockStatus                 = VOS_TRUE;
        }
        else
        {
            ucSimLockStatus                 = VOS_FALSE;
        }
    }
    else
#endif
    {
        ucSimStatus = MMA_GetUsimStatus(VOS_FALSE);

        /* ��ȡ����״̬ */
        if (MMA_SIM_IS_LOCK == MMA_GetMeLockStatus())
        {
            ucSimLockStatus                 = VOS_TRUE;
        }
        else
        {
            ucSimLockStatus                 = VOS_FALSE;
        }
    }

    ucCurSimCsRegStatus = TAF_SDC_GetSimCsRegStatus();
    ucCurSimPsRegStatus = TAF_SDC_GetSimPsRegStatus();

    if (((ucLastSimCsRegStatus != ucCurSimCsRegStatus)
      && (VOS_FALSE            == ucCurSimCsRegStatus))
     || ((ucLastSimPsRegStatus != ucCurSimPsRegStatus)
      && (VOS_FALSE            == ucCurSimPsRegStatus)) )
    {
        if (TAF_PH_ME_SIM_UNLOCK == MMA_GetMeLockStatus())
        {
            TAF_MMA_SndAtIccStatusInd(ucSimStatus, ucSimLockStatus);
        }
    }
    /* Modified by w00176964 for VoLTE_PhaseI��Ŀ, 2013-8-1, end */

    return;
}

/*****************************************************************************
 �� �� ��  : Sta_ReportServiceEvent
 ��������  : �ϱ���ǰCS��PS�ķ���״̬
 �������  : ulCsServiceStatus �ϵ�CS����״̬
             ulPsServiceStatus �ϵ�PS����״̬
 �������  : ��
 �� �� ֵ  : ��
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2009��4��1��
    ��    ��   : s46746
    �޸�����   : �����ɺ���
  2.��    ��   : 2009��8��15��
    ��    ��   : l65478
    �޸�����   : ���ⵥ�ţ�AT2D13660,out of service֮�󣬻��ϱ�����LIMITE SERVICE�¼�
  3.��    ��   : 2013��4��3��
    ��    ��   : z00161729
    �޸�����  : �����ϱ�AT�������������C�˼�mma��mscc�ӿڵ���
*****************************************************************************/
VOS_VOID Sta_ReportServiceEvent(VOS_UINT32 ulCsServiceStatus, VOS_UINT32 ulPsServiceStatus)
{
    static VOS_UINT8   ucLimitServiceSentFlg = VOS_FALSE;/* ��־limit service�Ƿ��Ѿ��ϱ� */

    /* Modified by z00161729 for �����ϱ�AT�������������C��, 2013-4-3, begin */
    TAF_SDC_SERVICE_STATUS_ENUM_UINT8   enCsServiceStatus;
    TAF_SDC_SERVICE_STATUS_ENUM_UINT8   enPsServiceStatus;

    enCsServiceStatus = TAF_SDC_GetCsServiceStatus();
    enPsServiceStatus = TAF_SDC_GetPsServiceStatus();

    if ((enCsServiceStatus != ulCsServiceStatus)
     || (enPsServiceStatus != ulPsServiceStatus))
    {
        if ((TAF_SDC_SERVICE_STATUS_NORMAL_SERVICE == enCsServiceStatus)
         && (TAF_SDC_SERVICE_STATUS_NORMAL_SERVICE == enPsServiceStatus))
        {
            NAS_EventReport(WUEPS_PID_MMC, NAS_OM_EVENT_CS_PS_SERVICE, VOS_NULL_PTR, NAS_OM_EVENT_NO_PARA);
            ucLimitServiceSentFlg = VOS_FALSE;
        }
        else if (TAF_SDC_SERVICE_STATUS_NORMAL_SERVICE == enCsServiceStatus)
        {
            /*��ǰ��CS����normal service����֮ǰCS��Ϊnormal service��PS֮ǰΪnormal service����Ҫ�ϱ�CS_SERVICE*/
            if ((TAF_SDC_SERVICE_STATUS_NORMAL_SERVICE != ulCsServiceStatus)
             || (TAF_SDC_SERVICE_STATUS_NORMAL_SERVICE == ulPsServiceStatus))
            {
                NAS_EventReport(WUEPS_PID_MMC, NAS_OM_EVENT_CS_SERVICE, VOS_NULL_PTR, NAS_OM_EVENT_NO_PARA);
                ucLimitServiceSentFlg = VOS_FALSE;
            }
        }
        else if (TAF_SDC_SERVICE_STATUS_NORMAL_SERVICE == enPsServiceStatus)
        {
            if ((TAF_SDC_SERVICE_STATUS_NORMAL_SERVICE != ulPsServiceStatus)
             || (TAF_SDC_SERVICE_STATUS_NORMAL_SERVICE == ulCsServiceStatus))
            {
                NAS_EventReport(WUEPS_PID_MMC, NAS_OM_EVENT_PS_SERVICE, VOS_NULL_PTR, NAS_OM_EVENT_NO_PARA);
                ucLimitServiceSentFlg = VOS_FALSE;
            }
        }
        else
        {
            /*��ǰ����limit service����֮ǰCSΪnormal service��PS֮ǰΪnormal service����Ҫ�ϱ�LIMIT_SERVICE*/
            if (((TAF_SDC_SERVICE_STATUS_NO_SERVICE != enPsServiceStatus)
             || (TAF_SDC_SERVICE_STATUS_NO_SERVICE != enCsServiceStatus))
             && (VOS_FALSE == ucLimitServiceSentFlg))
            {
                NAS_EventReport(WUEPS_PID_MMC, NAS_OM_EVENT_LIMITED_SERVICE, VOS_NULL_PTR, NAS_OM_EVENT_NO_PARA);
                ucLimitServiceSentFlg = VOS_TRUE;
            }
        }
    }

    /* Modified by z00161729 for �����ϱ�AT�������������C��, 2013-4-3, end */
}


/* Added by l00208543 for V9R1 STK����, 2013-07-26, begin */
/*****************************************************************************
 �� �� ��  : TAF_MMA_ProcCsServiceStatusChanged
 ��������  : CS��ķ���״̬�����任��Ĵ���
 �������  : ucOldCsServiceStatus ��service status״̬����ǰ��Cs�����״̬
 �������  : ��
 �� �� ֵ  : ��
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2013��7��26��
    ��    ��   : l00208543
    �޸�����   : �����ɺ���

*****************************************************************************/

VOS_VOID TAF_MMA_ProcCsServiceStatusChanged(VOS_UINT8 ucOldCsServiceStatus)
{
    if(VOS_TRUE == TAF_MMA_IsCsServiceStatusChanged(ucOldCsServiceStatus))
    {
        TAF_MMA_SndStkLocationInfoInd();
    }
}

/*****************************************************************************
 �� �� ��  : TAF_MMA_IsCsServiceStatusChanged
 ��������  : �ж�CS��ķ���״̬�Ƿ����任
 �������  : ucOldCsServiceStatus ��service status״̬����ǰ��Cs�����״̬
 �������  : ��
 �� �� ֵ  : VOS_UINT8 Cs�����״̬�Ƿ����任
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2013��7��26��
    ��    ��   : l00208543
    �޸�����   : �����ɺ���

*****************************************************************************/

VOS_UINT8 TAF_MMA_IsCsServiceStatusChanged(VOS_UINT8 ucOldCsServiceStatus)
{
    if(ucOldCsServiceStatus != TAF_SDC_GetCsServiceStatus())
    {
        return VOS_TRUE;
    }
    else
    {
        return VOS_FALSE;
    }
}

/*****************************************************************************
 �� �� ��  : Sta_IsPsServiceStatusChanged
 ��������  : �ж�PS��ķ���״̬�Ƿ����任
 �������  : ucOldPsServiceStatus ��service status״̬����ǰ��Ps�����״̬
 �������  : ��
 �� �� ֵ  : VOS_UINT8 Ps�����״̬�Ƿ����任
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2013��7��26��
    ��    ��   : l00208543
    �޸�����   : �����ɺ���

*****************************************************************************/

VOS_UINT8 TAF_MMA_IsPsServiceStatusChanged(VOS_UINT8 ucOldPsServiceStatus)
{
    if(ucOldPsServiceStatus != TAF_SDC_GetPsServiceStatus())
    {
        return VOS_TRUE;
    }
    else
    {
        return VOS_FALSE;
    }
}

/* Added by l00208543 for V9R1 STK����, 2013-07-26, end */


/*****************************************************************************
 �� �� ��  : TAF_SDC_IsSpecDomainUsimStatusInvalid
 ��������  : �ж��Ƿ��������Ե�ԭ�������Ŀǰֻ���ݿ��Ƿ���Ч���ж�
 �������  : ��
 �������  : ��
 �� �� ֵ  : �Ƿ��������Ե�ԭ�����
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2015��2��11��
    ��    ��   : l00305157
    �޸�����   : �����ɺ���

*****************************************************************************/
VOS_UINT8 TAF_SDC_IsSpecDomainUsimStatusInvalid(
    NAS_MSCC_PIF_SRVDOMAIN_ENUM_UINT32        enCnDomainId
)
{

    VOS_UINT8                           ucSimCsRegStatus;
    VOS_UINT8                           ucSimPsRegStatus;
    VOS_UINT8                           ucIsReceiveInvalidCause;

    ucSimCsRegStatus = TAF_SDC_GetSimCsRegStatus();
    ucSimPsRegStatus = TAF_SDC_GetSimPsRegStatus();

    ucIsReceiveInvalidCause = VOS_FALSE;

    NAS_NORMAL_LOG2(WUEPS_PID_MMA, "TAF_SDC_IsSpecDomainUsimStatusInvalid(): ucSimCsRegStatus, ucSimPsRegStatus",
        ucSimCsRegStatus,
        ucSimPsRegStatus);

    switch ( enCnDomainId )
    {
        case NAS_MSCC_PIF_SRVDOMAIN_CS:
             if ((TAF_SDC_USIM_STATUS_NO_PRESENT == TAF_SDC_GetUsimStatus())
              || (VOS_FALSE == ucSimCsRegStatus))
             {
                 NAS_NORMAL_LOG(WUEPS_PID_MMA, "TAF_SDC_IsSpecDomainUsimStatusInvalid(): SIM CS reg status invalid");
                 ucIsReceiveInvalidCause = VOS_TRUE;
             }
            break;

        case NAS_MSCC_PIF_SRVDOMAIN_PS:
             if ((TAF_SDC_USIM_STATUS_NO_PRESENT == TAF_SDC_GetUsimStatus())
              || (VOS_FALSE == ucSimPsRegStatus))
             {
                 NAS_NORMAL_LOG(WUEPS_PID_MMA, "TAF_SDC_IsSpecDomainUsimStatusInvalid(): SIM PS reg status invalid");
                 ucIsReceiveInvalidCause = VOS_TRUE;
             }
            break;

        case NAS_MSCC_PIF_SRVDOMAIN_CS_PS:
             if (VOS_FALSE == TAF_SDC_IsUsimStausValid())
             {
                 NAS_NORMAL_LOG(WUEPS_PID_MMA, "TAF_SDC_IsSpecDomainUsimStatusInvalid(): SIM status invalid");
                 ucIsReceiveInvalidCause = VOS_TRUE;
             }
            break;

        default:
            /*���ش��� */
            ucIsReceiveInvalidCause = VOS_FALSE;
            break;
    }

    return ucIsReceiveInvalidCause;
}

/*****************************************************************************
 �� �� ��  : TAF_MMA_IsDelayRptFeatureActive
 ��������  : �ж���ʱ�ϱ������Ƿ�����
 �������  : ��
 �������  : ��
 �� �� ֵ  : VOS_UINT8 VOS_TRUE:��������ʱ�ϱ�����
                       VOS_FALSE:��������ʱ�ϱ�����
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2015��02��11��
    ��    ��   : w00281933
    �޸�����   : �����ɺ���

*****************************************************************************/
VOS_UINT8 TAF_MMA_IsDelayRptFeatureActive(VOS_VOID)
{

    if (VOS_FALSE == TAF_MMA_GetDelayReportServiceStatusFlg())
    {
        /*NV δ������ʱ�ϱ�����*/
        STA_TRACE (STA_WARNING_PRINT,
            "TAF_MMA_IsDelayRptFeatureActive():WARNING: DelayReportService NV was did not Config");
        return VOS_FALSE;
    }

    if (0 == TAF_MMA_GetDelayReportServiceStatusCfgTimerLen())
    {
        /*��ʱ�ϱ���ʱ��ʱ������Ϊ0,��������ʱ�ϱ�����*/
        STA_TRACE (STA_WARNING_PRINT,
            "TAF_MMA_IsDelayRptFeatureActive():WARNING: DelayReportServiceTimer Cfg is 0");

        return VOS_FALSE;
    }

    return VOS_TRUE;
}

/* TAF_MMA_IsSameAsAppServiceStatus �Ƶ�TafMmaComFun.c�� */



/*****************************************************************************
 �� �� ��  : Sta_UpdateServiceStatus
 ��������  : ���±���ulServiceStatus
 �������  : ucDataTranAttri MSCC�ϴ�����������
 �������  : ��
 �� �� ֵ  : VOS_VOID
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2009��2��10��
    ��    ��   : sunxibo
    �޸�����   : �����ɺ���

  2.��    ��   : 2009��4��29��
    ��    ��   : h44270

  3.��    ��   : 2011��03��07��
    ��    ��   : f00179208
    �޸�����   : ���ⵥ��:DTS2011021901753,��������30-40���Ӻ��ڴν������������̨��Ȼ��ʾ�޷��񣬵�ʵ�ʿ��Խ���ҵ��

  4.��    ��   : 2012��04��07��
    ��    ��   : l00130025
    �޸�����   : ���ⵥ��:DTS2012040106098,����DeepSleep״̬ʱ��Srvst��Sysinfo/Sysinfoex�ϱ���һ��
  5.��    ��   : 2013��4��2��
    ��    ��   : z00161729
    �޸�����   : �����ϱ�AT�������������C�˼�mma��mmc�ӿڵ���
  6.��    ��   : 2015��02��11��
    ��    ��   : w00281933
    �޸�����   : Service_State_Optimize_PhaseII�޸�
  7.��    ��   : 2015��09��11��
    ��    ��   : zwx247453
    �޸�����   : DTS2015091001134 ��Ʒ���Զ�����������hisi�����Ѿ��ò���
*****************************************************************************/
VOS_VOID Sta_UpdateServiceStatus(VOS_UINT32 ulServiceStatus, VOS_UINT32 ulCnDomainId)
{
    VOS_UINT32 ulPsServiceStatus;
    VOS_UINT32 ulCsServiceStatus;

    STA_TRACE1 (STA_INFO_PRINT,
        "Sta_UpdateServiceStatus():INFO:ulCnDomainId is: ", (VOS_INT32)ulCnDomainId);
    STA_TRACE1 (STA_INFO_PRINT,
        "Sta_UpdateServiceStatus():INFO:ulServiceStatus is: ", (VOS_INT32)ulServiceStatus);

    ulCsServiceStatus = TAF_SDC_GetCsServiceStatus();
    ulPsServiceStatus = TAF_SDC_GetPsServiceStatus();

    /* Modified by z00161729 for �����ϱ�AT�������������C��, 2013-4-3, begin */
    /* ����CS/PS����״̬ */
    switch (ulCnDomainId)
    {
        case NAS_MSCC_PIF_SRVDOMAIN_CS:
            if(NAS_MSCC_PIF_SERVICE_STATUS_NO_CHANGE != ulServiceStatus)
            {
                TAF_SDC_SetCsServiceStatus((VOS_UINT8)ulServiceStatus);
            }
            break;
        case NAS_MSCC_PIF_SRVDOMAIN_PS:
            if(NAS_MSCC_PIF_SERVICE_STATUS_NO_CHANGE != ulServiceStatus)
            {
                TAF_SDC_SetPsServiceStatus((VOS_UINT8)ulServiceStatus);
            }
            break;
        case NAS_MSCC_PIF_SRVDOMAIN_NO_CHANGE:
        case NAS_MSCC_PIF_SRVDOMAIN_CS_PS:
        case NAS_MSCC_PIF_SRVDOMAIN_NOT_REG_PLMN_SEARCHING:
            /* �����ַ�����ֻ��MSCC�Ż��ϱ������PS/CS����Ҫ���� */
            if(NAS_MSCC_PIF_SERVICE_STATUS_NO_CHANGE != ulServiceStatus)
            {
                TAF_SDC_SetCsServiceStatus((VOS_UINT8)ulServiceStatus);
                TAF_SDC_SetPsServiceStatus((VOS_UINT8)ulServiceStatus);
            }
            break;
        default:
            break;
    }

    /* Deleted by w00176964 for V3R3C60_eCall��Ŀ, 2014-4-30, begin */

    /* Deleted by w00176964 for V3R3C60_eCall��Ŀ, 2014-4-30, end */

    Sta_ReportServiceEvent(ulCsServiceStatus, ulPsServiceStatus);

    ulCsServiceStatus = TAF_SDC_GetCsServiceStatus();
    ulPsServiceStatus = TAF_SDC_GetPsServiceStatus();

    /* �����ܵķ���״̬ */
    if (  (NAS_MSCC_PIF_SERVICE_STATUS_NORMAL_SERVICE == ulCsServiceStatus)
       && (NAS_MSCC_PIF_SERVICE_STATUS_NORMAL_SERVICE == ulPsServiceStatus) )
    {
        TAF_SDC_SetServiceStatus(TAF_SDC_REPORT_SRVSTA_NORMAL_SERVICE);
        TAF_SDC_SetServiceDomain(TAF_SDC_SERVICE_DOMAIN_CS_PS);
    }
    else if (NAS_MSCC_PIF_SERVICE_STATUS_NORMAL_SERVICE == ulCsServiceStatus)
    {
        TAF_SDC_SetServiceStatus(TAF_SDC_REPORT_SRVSTA_NORMAL_SERVICE);
        TAF_SDC_SetServiceDomain(TAF_SDC_SERVICE_DOMAIN_CS);
    }
    else if (NAS_MSCC_PIF_SERVICE_STATUS_NORMAL_SERVICE == ulPsServiceStatus)
    {
        TAF_SDC_SetServiceStatus(TAF_SDC_REPORT_SRVSTA_NORMAL_SERVICE);
        TAF_SDC_SetServiceDomain(TAF_SDC_SERVICE_DOMAIN_PS);
    }
    else if ((NAS_MSCC_PIF_SERVICE_STATUS_LIMITED_SERVICE_REGION == ulCsServiceStatus)
          || (NAS_MSCC_PIF_SERVICE_STATUS_LIMITED_SERVICE_REGION == ulPsServiceStatus) )
    {
        TAF_SDC_SetServiceStatus(TAF_SDC_REPORT_SRVSTA_REGIONAL_LIMITED_SERVICE);
    }
    else if ((NAS_MSCC_PIF_SERVICE_STATUS_LIMITED_SERVICE == ulCsServiceStatus)
          || (NAS_MSCC_PIF_SERVICE_STATUS_LIMITED_SERVICE == ulPsServiceStatus) )
    {
        TAF_SDC_SetServiceStatus(TAF_SDC_REPORT_SRVSTA_LIMITED_SERVICE);
    }
    else if ((NAS_MSCC_PIF_SERVICE_STATUS_NO_IMSI == ulCsServiceStatus)
          || (NAS_MSCC_PIF_SERVICE_STATUS_NO_IMSI == ulPsServiceStatus) )
    {
        TAF_SDC_SetServiceStatus(TAF_SDC_REPORT_SRVSTA_LIMITED_SERVICE);
    }
    else
    {
        TAF_SDC_SetServiceStatus(TAF_SDC_REPORT_SRVSTA_NO_SERVICE);


        if (VOS_TRUE == gstMmaValue.pg_StatusContext->ulTimMaxFlg )
        {
            TAF_SDC_SetServiceStatus(TAF_SDC_REPORT_SRVSTA_DEEP_SLEEP);
        }

    }

    /* �����ܵķ����� */
    if (TAF_SDC_REPORT_SRVSTA_NORMAL_SERVICE != TAF_SDC_GetServiceStatus() )
    {
        if(NAS_MSCC_PIF_SRVDOMAIN_NOT_REG_PLMN_SEARCHING == ulCnDomainId)
        {
            TAF_SDC_SetServiceDomain(TAF_SDC_SERVICE_DOMAIN_SEARCHING);
        }
        else
        {
            switch(gstMmaValue.stSetMsClass.NewMsClassType)
            {
                case TAF_PH_MS_CLASS_A:
                case TAF_PH_MS_CLASS_B:
                    TAF_SDC_SetServiceDomain(TAF_SDC_SERVICE_DOMAIN_CS_PS);
                    break;
                case TAF_PH_MS_CLASS_CC:
                    TAF_SDC_SetServiceDomain(TAF_SDC_SERVICE_DOMAIN_CS);
                    break;
                case TAF_PH_MS_CLASS_CG:
                    TAF_SDC_SetServiceDomain(TAF_SDC_SERVICE_DOMAIN_PS);
                    break;
                case TAF_PH_MS_CLASS_NULL:
                    TAF_SDC_SetServiceDomain(TAF_SDC_SERVICE_DOMAIN_NO_DOMAIN);
                    break;
                default:
                    TAF_SDC_SetServiceDomain(TAF_SDC_SERVICE_DOMAIN_NO_DOMAIN);
                    break;
            }
        }
    }
    else
    {
        g_StatusContext.ulTimMaxFlg = VOS_FALSE;
    }

    if ( TAF_SDC_REPORT_SRVSTA_NORMAL_SERVICE == TAF_SDC_GetServiceStatus() )
    {
        MN_PH_UpdateEndRegTime();
    }

    /* Modified by z00161729 for �����ϱ�AT�������������C��, 2013-4-3, end */
}


/*****************************************************************************
  Function:
    Sta_UpdateLocalState
  Description:
    �ж��Ƿ�����������
  Calls:                 �����������õĺ����嵥
  Called By:             ���ñ������ĺ����嵥
  Input:
    MSCC_MMA_SERVICE_STATUS_IND_STRU *pServiceStatus; ��������ṹָ��
  Output:
    ��
  Return:
    VOS_VOID
  Others:
  1 author:   L65478 2008-12-19
  2.��    ��   : 2012��4��07��
    ��    ��   : l00130025
    �޸�����   : DTS2012032600471,ɾ��ֹͣ��ʱ���Ĵ���������:ָ�����������У��յ�����״̬�ϱ�������MMA�ı�����ʱ����ֹͣ
  3.��    ��   : 2013��4��3��
    ��    ��   : z00161729
    �޸�����   : �����ϱ�AT�������������C�˼�mma��mscc�ӿڵ���
*****************************************************************************/
VOS_VOID Sta_UpdateLocalState(
    MSCC_MMA_SERVICE_STATUS_IND_STRU    *pServiceStatus,
    VOS_UINT8                           ucFsmSubOperate
)
{
    STA_PHONE_DATA_S                    Update;

    /* Modified by z00161729 for �����ϱ�AT�������������C��, 2013-4-3, begin */
    TAF_SDC_PLMN_ID_STRU               *pstPlmnId = VOS_NULL_PTR;

    pstPlmnId = TAF_SDC_GetCurrCampPlmnId();
    Update.ulCsServiceStatus = TAF_SDC_GetCsServiceStatus();
    Update.ulPsServiceStatus = TAF_SDC_GetPsServiceStatus();
    Update.ucDomainFlag      = NAS_MSCC_PIF_SRVDOMAIN_CS_PS;
    Update.ulCsCause         = 0;
    Update.ulPsCause         = 0;

    Update.PlmnId.Mcc        = pstPlmnId->ulMcc;
    Update.PlmnId.Mnc        = pstPlmnId->ulMnc;
    /* Modified by z00161729 for �����ϱ�AT�������������C��, 2013-4-3, end */
    Update.ucFsmSubOperate   = ucFsmSubOperate;
    Update.ulFsmState        = STA_FSM_ENABLE;
    Update.ucFsmStateSub     = STA_FSMSUB_NULL;
    Update.ucFsmUpdateFlag   = STA_UPDATE_MONO_CLEAR;

    if ( STA_ERROR == Sta_UpdateData (&Update) )
    {
        STA_TRACE (STA_WARNING_PRINT,
            "Sta_UpdateLocalState():WARNING:Sta_UpdateData failed");
    }
}

/* Added by w00176964 for VoLTE_PhaseII ��Ŀ, 2013-10-10, begin */
/*****************************************************************************
 �� �� ��  : TAF_MMA_IsPsSrvStatusChanged
 ��������  : �ж�PS�ķ���״̬�Ƿ����ı�
 �������  : enCnDomainId-----ָ����
             enServiceStatus----��ǰ����״̬
 �������  : ��
 �� �� ֵ  : VOS_UINT32
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2013��10��12��
    ��    ��   : w00176964
    �޸�����   : ��������
*****************************************************************************/
VOS_UINT32 TAF_MMA_IsPsSrvStatusChanged(
    NAS_MSCC_PIF_SRVDOMAIN_ENUM_UINT32       enCnDomainId,
    NAS_MSCC_PIF_SERVICE_STATUS_ENUM_UINT32  enServiceStatus
)
{
    if ((NAS_MSCC_PIF_SRVDOMAIN_PS    == enCnDomainId)
     || (NAS_MSCC_PIF_SRVDOMAIN_CS_PS == enCnDomainId))
    {
        if (TAF_SDC_GetPsServiceStatus() != enServiceStatus)
        {
            return VOS_TRUE;
        }
    }

    return VOS_FALSE;
}


/*****************************************************************************
 �� �� ��  : TAF_MMA_IsNeedDelayReportServiceStatus
 ��������  : �ж��Ƿ���Ҫ��ʱ�ϱ�ע��״̬
 �������  : enOldPsSrvSta          -- �ɵĵ�ps�����״̬
             enOldCsSrvSta          -- �ɵĵ�cs�����״̬
 �������  : ��
 �� �� ֵ  : VOS_TRUE:  ��Ҫ��ʱ�ϱ�
             VOS_FALSE: ����Ҫ��ʱ�ϱ�
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2015��02��11��
    ��    ��   : w00281933
    �޸�����   : �����ɺ���
*****************************************************************************/
VOS_UINT32 TAF_MMA_IsNeedDelayReportServiceStatus(
    NAS_MSCC_PIF_SRVDOMAIN_ENUM_UINT32       enCnDomainId,
    NAS_MSCC_PIF_SERVICE_STATUS_ENUM_UINT32  enServiceStatus
)
{
    TAF_SDC_SERVICED_PLMN_INFO_STRU    *pstAppServPlmnInfo = VOS_NULL_PTR;
    VOS_UINT32                          ulCellInfoChg;
    VOS_UINT8                           ucIsNeedDelayRpt;


    pstAppServPlmnInfo  = &(TAF_SDC_GetAppNetworkInfo()->stAppSysInfo.stServPlmnInfo);
    ulCellInfoChg       = TAF_MMA_IsAppNetworkInfoCellChange(pstAppServPlmnInfo);
    ucIsNeedDelayRpt    = VOS_TRUE;

    /* �ӳ�����NV�رգ���Ҫ�����ϱ� */
    if (VOS_FALSE == TAF_MMA_IsDelayRptFeatureActive())
    {
        NAS_NORMAL_LOG(WUEPS_PID_MMA, "TAF_MMA_IsNeedDelayReportServiceStatus(): No delay as delay functionality is not enabled ");
        return VOS_FALSE;
    }


    /* ������Чʱ��Ҫ�����ϱ� */
    if (VOS_TRUE == TAF_SDC_IsSpecDomainUsimStatusInvalid(enCnDomainId))
    {
        NAS_NORMAL_LOG(WUEPS_PID_MMA, "TAF_MMA_IsNeedDelayReportServiceStatus(): No delay as SIM invalid");
        return VOS_FALSE;
    }

    /* �û��������µķ���״̬�ı�,��������ʱ�ϱ� */
    if ((TAF_MMA_FSM_SYS_CFG == TAF_MMA_GetCurrFsmId())
     || (STA_FSM_ENABLE      != g_StatusContext.ulFsmState))
    {
        NAS_NORMAL_LOG(WUEPS_PID_MMA, "TAF_MMA_IsNeedDelayReportServiceStatus(): No delay as Curr FSM is SYSCFG");
        /* �û��������µķ���״̬�ı�,��������ʱ�ϱ� */
        return VOS_FALSE;
    }


    /* MMC��û���ϱ�MMA_MMC_SERVICE_STATUS_NO_IMSI/MMA_MMC_SERVICE_STATUS_NO_CHANGE/MMA_MMC_SERVICE_STATUS_DEEP_SLEEP�ĵط� */

    switch(enServiceStatus)
    {
        case NAS_MSCC_PIF_SERVICE_STATUS_NORMAL_SERVICE:
            NAS_NORMAL_LOG(WUEPS_PID_MMA, "TAF_MMA_IsNeedDelayReportServiceStatus(): No need delay report as Curr Service state is NAS_MSCC_PIF_SERVICE_STATUS_NORMAL_SERVICE");
            /* ��������ϱ��ķ���״̬Ϊ��������, */
            ucIsNeedDelayRpt    = VOS_FALSE;
            break;

         case NAS_MSCC_PIF_SERVICE_STATUS_LIMITED_SERVICE:
         case NAS_MSCC_PIF_SERVICE_STATUS_LIMITED_SERVICE_REGION:
         case NAS_MSCC_PIF_SERVICE_STATUS_NO_SERVICE:

            /* APP�еķ���״̬�Ƿ�normal service����Ҫֱ���ϱ� */
            if (TAF_SDC_REPORT_SRVSTA_NORMAL_SERVICE != TAF_SDC_GetAppServiceStatus())
            {
                NAS_NORMAL_LOG(WUEPS_PID_MMA, "TAF_MMA_IsNeedDelayReportServiceStatus(): APP is not normal status, No need delay report");
                ucIsNeedDelayRpt    = VOS_FALSE;
            }
            else
            {
                /* APP����ʾ������������: ����ӳٶ�ʱ���������У���ʾ��ǰ��ķ���״̬�����ӳ٣�������һ����ķ���״̬/ע��״̬�����ӳ٣���Ҫ�����ӳ� */
                if (TAF_MMA_TIMER_STATUS_RUNING == TAF_MMA_GetTimerStatus(TI_TAF_MMA_DELAY_REPORT_SERVICE_STATUS))
                {
                    NAS_NORMAL_LOG(WUEPS_PID_MMA, "TAF_MMA_IsNeedDelayReportServiceStatus(): TI_TAF_MMA_DELAY_REPORT_SERVICE_STATUS running, need delay report");
                    return VOS_TRUE;
                }

                /* APP����ʾ�������������ӳٶ�ʱ����������,CS/PS��ͬʱ��Ϊ������������Ҫ�ӳ��ϱ� */
                if ((NAS_MSCC_PIF_SRVDOMAIN_CS_PS == enCnDomainId)
                 || (NAS_MSCC_PIF_SRVDOMAIN_NOT_REG_PLMN_SEARCHING == enCnDomainId))
                {
                    NAS_NORMAL_LOG1(WUEPS_PID_MMA, "TAF_MMA_IsNeedDelayReportServiceStatus(): need delay report as curr domain is ", enCnDomainId);
                    return VOS_TRUE;
                }

                /* APP����ʾ������������:����ӳٶ�ʱ���������У�����APP�е�פ����Ϣ��SDC�е���ͬ��
                   ��ʾ��ǰ���ע��״̬��Ҫ�ϱ��Ѿ�������APP�е�פ����Ϣ����������һ����ķ���״̬/ע��״̬��Ҫ�ϱ��Ѿ�������APP�е�פ����Ϣ
                   ��������������������ϱ���ǰ��ķ���״̬ */
                if (VOS_FALSE == ulCellInfoChg)
                {
                    NAS_NORMAL_LOG(WUEPS_PID_MMA, "TAF_MMA_IsNeedDelayReportServiceStatus(): No need delay report as cell info not changed");
                    return VOS_FALSE;
                }
            }

            break;

        default:
            break;

    }

    return ucIsNeedDelayRpt;

}

/*****************************************************************************
 �� �� ��  : TAF_MMA_IsNeedReportServiceStatus_DelayRptTimerRun
 ��������  : ��ʱ��ʱ�������ڼ䣬�Ƿ���Ҫ�ϱ�����״̬ȷ����ע��״̬�ϱ�һ��
 �������  : enCnDomainId             -- ������
             enServiceStatus          -- �����״̬
 �������  : ��
 �� �� ֵ  : VOS_TRUE:  ��Ҫ�ϱ�
             VOS_FALSE: ����Ҫ�ϱ�
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2015��05��11��
    ��    ��   : w00281933
    �޸�����   : �����ɺ���
*****************************************************************************/
VOS_UINT32 TAF_MMA_IsNeedReportServiceStatus_DelayRptTimerRun(
    NAS_MSCC_PIF_SRVDOMAIN_ENUM_UINT32       enCnDomainId
)
{
    TAF_SDC_SERVICE_STATUS_ENUM_UINT8  enCsSrvSta;
    TAF_SDC_SERVICE_STATUS_ENUM_UINT8  enPsSrvSta;
    TAF_SDC_REG_STATUS_ENUM_UINT8      enAppCsRegState;
    TAF_SDC_REG_STATUS_ENUM_UINT8      enAppPsRegState;

    /*��ȡAPP���ϱ������ע��״̬*/
    enAppCsRegState   = TAF_SDC_GetAppCsRegStatus();
    enAppPsRegState   = TAF_SDC_GetAppPsRegStatus();

    /*��ȡNETWORKINFO������ڲ�����ķ���״̬����*/
    enCsSrvSta     = TAF_SDC_GetCsServiceStatus();
    enPsSrvSta     = TAF_SDC_GetPsServiceStatus();


    if ((NAS_MSCC_PIF_SERVICE_STATUS_NORMAL_SERVICE == enCsSrvSta)
     && ((NAS_MSCC_PIF_SRVDOMAIN_CS                 == enCnDomainId)
      || (NAS_MSCC_PIF_SRVDOMAIN_CS_PS              == enCnDomainId)))
    {
        return VOS_TRUE;
    }

    if ((NAS_MSCC_PIF_SERVICE_STATUS_NORMAL_SERVICE == enPsSrvSta)
     && ((NAS_MSCC_PIF_SRVDOMAIN_PS                 == enCnDomainId)
      ||(NAS_MSCC_PIF_SRVDOMAIN_CS_PS               == enCnDomainId)))
    {
        return VOS_TRUE;
    }

    /*����ע��״̬�ͷ���״̬�ϱ�һ��*/
    if ((NAS_MSCC_PIF_SRVDOMAIN_CS           == enCnDomainId)
     && (TAF_SDC_REG_REGISTERED_HOME_NETWORK != enAppCsRegState)
     && (TAF_SDC_REG_REGISTERED_ROAM         != enAppCsRegState))
    {
        return VOS_TRUE;
    }

    if ((NAS_MSCC_PIF_SRVDOMAIN_PS           == enCnDomainId)
     && (TAF_SDC_REG_REGISTERED_HOME_NETWORK != enAppPsRegState)
     && (TAF_SDC_REG_REGISTERED_ROAM         != enAppPsRegState))
    {
        return VOS_TRUE;

    }

    return VOS_FALSE;
}

/*****************************************************************************
 �� �� ��  : TAF_MMA_IsNeedReportServiceStatus
 ��������  : �ж��Ƿ���Ҫ�ϱ�����״̬
 �������  : enCnDomainId             -- ������
             enServiceStatus          -- �����״̬
 �������  : ��
 �� �� ֵ  : VOS_TRUE:  ��Ҫ�ϱ�
             VOS_FALSE: ����Ҫ�ϱ�
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2015��02��11��
    ��    ��   : w00281933
    �޸�����   : �����ɺ���
*****************************************************************************/
VOS_UINT32 TAF_MMA_IsNeedReportServiceStatus(
    NAS_MSCC_PIF_SRVDOMAIN_ENUM_UINT32                      enCnDomainId,
    NAS_MSCC_PIF_SERVICE_STATUS_ENUM_UINT32                 enServiceStatus
)
{
    VOS_UINT8                           ucEnableDaleyRptSrvSta;
    TAF_MMA_TIMER_STATUS_ENUM_UINT8     enDelayTimerStatus;


    ucEnableDaleyRptSrvSta = VOS_FALSE;
    enDelayTimerStatus     = TAF_MMA_TIMER_STATUS_BUTT;

    /*��ȡ�Ƿ�����ʱ�ϱ�����*/
    ucEnableDaleyRptSrvSta = TAF_MMA_GetDelayReportServiceStatusFlg();

    if (VOS_TRUE == ucEnableDaleyRptSrvSta)
    {
        enDelayTimerStatus = TAF_MMA_GetTimerStatus(TI_TAF_MMA_DELAY_REPORT_SERVICE_STATUS);
    }

    /*��APP����״̬��ͬ��Ӧ��Ҫ����Ҫ�ϱ�*/
    if (VOS_TRUE == TAF_MMA_IsSameAsAppServiceStatus((TAF_SDC_SERVICE_STATUS_ENUM_UINT8)enServiceStatus, enCnDomainId))
    {
        return VOS_FALSE;
    }

    /*Ҫ���µ���Ŀ�״̬Ϊ��Ч������Ҫ�ϱ�*/
    if (VOS_TRUE == TAF_SDC_IsSpecDomainUsimStatusInvalid(enCnDomainId))
    {
        return VOS_TRUE;
    }

    /*���µķ���״̬ʱnormal����Ҫ�ϱ�*/
    if (NAS_MSCC_PIF_SERVICE_STATUS_NORMAL_SERVICE == enServiceStatus)
    {
        return VOS_TRUE;
    }

    if (TAF_MMA_TIMER_STATUS_RUNING == enDelayTimerStatus)
    {
        /*��ʱ��ʱ�������ڼ䣬ȷ����ע��״̬����һ��*/
        if (VOS_FALSE == TAF_MMA_IsNeedReportServiceStatus_DelayRptTimerRun(enCnDomainId))
        {
            return VOS_FALSE;
        }

    }

    return VOS_TRUE;
}


/*****************************************************************************
 �� �� ��  : TAF_MMA_ProcServiceStatusReport
 ��������  : ����״ָ̬ʾ����Ϣ�ϱ�����
 �������  : ucNewSrvSta--MMA�ϱ��ķ���״̬��Ϣ
             ucOldSrvSta--MMA old �ķ���״̬��Ϣ
 �������  : ��
 �� �� ֵ  : ��
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2015��02��11��
    ��    ��   : w00281933
    �޸�����   : Service_State_Optimize_PhaseII�޸�
  2.��    ��   : 2015��10��21��
    ��    ��   : l00324781
    �޸�����   : CDMA Iteration 18 �������޸�
*****************************************************************************/
VOS_VOID TAF_MMA_ProcServiceStatusReport(
    TAF_SDC_REPORT_SRVSTA_ENUM_UINT8    ucNewSrvSta,
    TAF_SDC_REPORT_SRVSTA_ENUM_UINT8    ucOldSrvSta
)
{
    if (ucOldSrvSta != ucNewSrvSta)
    {
        TAF_MMA_ReportSrvStatus();
    }

    return;
}
/*****************************************************************************
 �� �� ��  : TAF_MMA_IsNeedDelayReportRegStatus
 ��������  : �ж�ע��״̬0(REG_NOT_REGISTERED_NOT_SEARCH)�Ƿ���Ҫ��ʱ�ϱ�ע��״̬
 �������  : enNewRegState           -- ע��״̬

 �������  : ��
 �� �� ֵ  : VOS_TRUE:  ��Ҫ��ʱ�ϱ�
             VOS_FALSE: ����Ҫ��ʱ�ϱ�
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2015��07��21��
    ��    ��   : w00281933
    �޸�����   : �����ɺ���
*****************************************************************************/
VOS_UINT32 TAF_MMA_IsNeedDelayReportRegStatus_NotRegNotSearch(
    NAS_MSCC_PIF_REG_STATE_ENUM_UINT8   enNewRegState
)
{
    TAF_SDC_SERVICED_PLMN_INFO_STRU    *pstAppServPlmnInfo = VOS_NULL_PTR;
    VOS_UINT32                          ulCellInfoChg;


    pstAppServPlmnInfo  = &(TAF_SDC_GetAppNetworkInfo()->stAppSysInfo.stServPlmnInfo);
    ulCellInfoChg       = TAF_MMA_IsAppNetworkInfoCellChange(pstAppServPlmnInfo);

    /* �ú���ֻ����NAS_MML_REG_NOT_REGISTERED_NOT_SEARCHʱ�Ƿ���Ҫ�ӳ��ϱ� */
    if (NAS_MSCC_PIF_REG_NOT_REGISTERED_NOT_SEARCH != enNewRegState)
    {
        return VOS_TRUE;
    }

    /* ���APP����ʾ���Ƿ��������񣬲���Ҫ�ӳ٣�ֱ���ϱ� */
    if (TAF_SDC_REPORT_SRVSTA_NORMAL_SERVICE != TAF_SDC_GetAppServiceStatus())
    {
        NAS_NORMAL_LOG(WUEPS_PID_MMA, "TAF_MMA_IsNeedDelayReportRegStatus_NotRegNotSearch(): Not TAF_SDC_REPORT_SRVSTA_NORMAL_SERVICE, no need delay report");
        return VOS_FALSE;
    }

    /* APP����ʾ������������: ����ӳٶ�ʱ���������У���ʾ��ǰ��ķ���״̬�����ӳ٣�������һ����ķ���״̬/ע��״̬�����ӳ٣���Ҫ�����ӳ� */
    if (TAF_MMA_TIMER_STATUS_RUNING == TAF_MMA_GetTimerStatus(TI_TAF_MMA_DELAY_REPORT_SERVICE_STATUS))
    {
        NAS_NORMAL_LOG(WUEPS_PID_MMA, "TAF_MMA_IsNeedDelayReportRegStatus_NotRegNotSearch(): TI_TAF_MMA_DELAY_REPORT_SERVICE_STATUS running, need delay report");
        return VOS_TRUE;
    }

    /* APP����ʾ������������:����ӳٶ�ʱ���������У�����APP�е�פ����Ϣ��SDC�е���ͬ��
       ��ʾ��ǰ��ķ���״̬��Ҫ�ϱ��Ѿ�������APP�е�פ����Ϣ����������һ����ķ���״̬/ע��״̬��Ҫ�ϱ��Ѿ�������APP�е�פ����Ϣ
       ��������������������ϱ���ǰ���ע��״̬ */
    if (VOS_FALSE == ulCellInfoChg)
    {
        NAS_NORMAL_LOG(WUEPS_PID_MMA, "TAF_MMA_IsNeedDelayReportRegStatus_NotRegNotSearch(): Cell info not changed, no need delay report");
        return VOS_FALSE;
    }

    /* ��û�п���CS+PS:normal service,������LAU/RAU/TAUʱʧ��?���ֳ���ulCellInfoChg�в����� */
    return VOS_TRUE;

}

/*****************************************************************************
 �� �� ��  : TAF_MMA_IsNeedDelayReportRegStatus
 ��������  : �ж��Ƿ���Ҫ��ʱ�ϱ�ע��״̬
 �������  : enCnDomainId           -- ������
             enNewRegState          -- ���ע��״̬
 �������  : ��
 �� �� ֵ  : VOS_TRUE:  ��Ҫ��ʱ�ϱ�
             VOS_FALSE: ����Ҫ��ʱ�ϱ�
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2015��02��11��
    ��    ��   : w00281933
    �޸�����   : �����ɺ���
*****************************************************************************/
VOS_UINT32 TAF_MMA_IsNeedDelayReportRegStatus(
    NAS_MSCC_PIF_SRVDOMAIN_ENUM_UINT32  enCnDomainId,
    NAS_MSCC_PIF_REG_STATE_ENUM_UINT8   enNewRegState
)
{
    VOS_UINT8                           ucIsNeedDelayRpt;

    ucIsNeedDelayRpt                    = VOS_TRUE;


    /*��ʱ�ϱ�����δ����*/
    if (VOS_FALSE == TAF_MMA_IsDelayRptFeatureActive())
    {
        NAS_NORMAL_LOG(WUEPS_PID_MMA, "TAF_MMA_IsNeedDelayReportRegStatus(): No delay as delay functionality is not enabled ");
        return VOS_FALSE;
    }

    if (VOS_TRUE == TAF_SDC_IsSpecDomainUsimStatusInvalid(enCnDomainId))
    {
        NAS_NORMAL_LOG(WUEPS_PID_MMA, "TAF_MMA_IsNeedDelayReportRegStatus(): No delay as SIM invalid");
        return VOS_FALSE;
    }

    if ((TAF_MMA_FSM_SYS_CFG == TAF_MMA_GetCurrFsmId())
     || (STA_FSM_ENABLE      != g_StatusContext.ulFsmState))
    {
        NAS_NORMAL_LOG(WUEPS_PID_MMA, "TAF_MMA_IsNeedDelayReportRegStatus(): No delay as Curr FSM is SYSCFG");
        /*�û��������µķ���״̬�ı�,��������ʱ�ϱ�*/
        return VOS_FALSE;
    }

    switch(enNewRegState)
    {
        case NAS_MSCC_PIF_REG_REGISTERED_HOME_NETWORK:
        case NAS_MSCC_PIF_REG_REGISTERED_ROAM:
            NAS_NORMAL_LOG1(WUEPS_PID_MMA, "TAF_MMA_IsNeedDelayReportRegStatus(): No need delay report as Curr Reg state is normal ", enNewRegState);
            /*�ָ���normal register statusֱ���ϱ�*/
            ucIsNeedDelayRpt = VOS_FALSE;
            break;

        case NAS_MSCC_PIF_REG_NOT_REGISTERED_SEARCHING:
            if (VOS_TRUE == TAF_SDC_IsCurrentAppNormalRegStatus())
            {
                NAS_NORMAL_LOG(WUEPS_PID_MMA, "TAF_MMA_IsNeedDelayReportRegStatus(): Need delay report as changing from normal to searching");
                /*��normal��������Ҫ��ʱ*/
                ucIsNeedDelayRpt = VOS_TRUE;
            }
            else
            {
                NAS_NORMAL_LOG(WUEPS_PID_MMA, "TAF_MMA_IsNeedDelayReportRegStatus(): No Need delay report as curr APP Reg status is not normal");
                ucIsNeedDelayRpt = VOS_FALSE;
            }
            break;

        case NAS_MSCC_PIF_REG_REGISTERED_DENIED:
            NAS_NORMAL_LOG(WUEPS_PID_MMA, "TAF_MMA_IsNeedDelayReportRegStatus(): No need delay report when NAS_MSCC_PIF_REG_REGISTERED_DENIED");
            ucIsNeedDelayRpt = VOS_FALSE;
            break;

        case NAS_MSCC_PIF_REG_NOT_REGISTERED_NOT_SEARCH:

            if (VOS_FALSE == TAF_MMA_IsNeedDelayReportRegStatus_NotRegNotSearch(NAS_MSCC_PIF_REG_NOT_REGISTERED_NOT_SEARCH))
            {
                NAS_NORMAL_LOG(WUEPS_PID_MMA, "TAF_MMA_IsNeedDelayReportRegStatus(): No need delay report when NAS_MSCC_PIF_REG_NOT_REGISTERED_NOT_SEARCH");
                ucIsNeedDelayRpt = VOS_FALSE;
            }
            break;

        default:
            break;
    }

    return ucIsNeedDelayRpt;

}


/*****************************************************************************
 �� �� ��  : TAF_MMA_IsNeedDelayReportApsNoServiceStatus
 ��������  : �ж��Ƿ���Ҫ��ʱ�ϱ�APS DO��DO + L�޷���״̬
 �������  : TAF_MMA_DELAY_CL_REPORT_TYPE_ENUM_UINT8 enDelayType:�ӳ�����(DO����DO+L)
 �������  : ��
 �� �� ֵ  : VOS_TRUE:  ��Ҫ��ʱ�ϱ�
             VOS_FALSE: ����Ҫ��ʱ�ϱ�
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2016��01��09��
    ��    ��   : h00313353
    �޸�����   : �����ɺ���
*****************************************************************************/
VOS_UINT32 TAF_MMA_IsNeedDelayReportApsNoServiceStatus(
    TAF_MMA_DELAY_CL_REPORT_TYPE_ENUM_UINT8                 enDelayType
)
{
    TAF_SDC_SYS_SUBMODE_ENUM_UINT8                          enSubSysMode;
    TAF_MMA_CL_NO_SERVICE_DELAY_RPT_STRU                   *pstClNoServiceDelayRpt  = VOS_NULL_PTR;

    enSubSysMode            = TAF_SDC_GetAppSysSubMode();
    pstClNoServiceDelayRpt  = TAF_MMA_GetCLNoServiceDelayRptInfo();

    if (enDelayType >= TAF_MMA_DELAY_CL_REPORT_TYPE_BUTT)
    {
        MMA_WARNINGLOG("TAF_MMA_IsNeedDelayReportApsNoServiceStatus: enDelayType >= BUTT! Return False");

        return VOS_FALSE;
    }

    /* �����ӳٹ����У����ϱ���Ϣ */
    if (TAF_MMA_TIMER_STATUS_RUNING == TAF_MMA_GetTimerStatus(TI_TAF_MMA_DELAY_RPT_APS_CL_NO_SERVICE))
    {
        MMA_INFOLOG("TAF_MMA_IsNeedDelayReportApsNoServiceStatus: CL Delay Timer Already Running!");

        return VOS_TRUE;
    }

    if (TAF_MMA_TIMER_STATUS_RUNING == TAF_MMA_GetTimerStatus(TI_TAF_MMA_DELAY_RPT_APS_DO_NO_SERVICE))
    {
        MMA_INFOLOG("TAF_MMA_IsNeedDelayReportApsNoServiceStatus: DO Delay Timer Already Running!");

        return VOS_TRUE;
    }

    /* EHPRD LTE�²��ӳ��ϱ�APS DO ����DO + L�޷��� */
    if ((TAF_SDC_SYS_SUBMODE_EHRPD      != enSubSysMode)
     && (TAF_SDC_SYS_SUBMODE_LTE        != enSubSysMode))
    {
        MMA_INFOLOG1("TAF_MMA_IsNeedDelayReportApsNoServiceStatus:Current SubMode Not In Lte Or Hrpd, SubMode:", (VOS_UINT32)enSubSysMode);

        return VOS_FALSE;
    }

    pstClNoServiceDelayRpt->enDelayType   = enDelayType;

    if (TAF_SDC_SYS_SUBMODE_EHRPD == enSubSysMode)
    {
        if (0 == pstClNoServiceDelayRpt->ucDoNoServiceDelayRptLen)
        {
            MMA_INFOLOG("TAF_MMA_IsNeedDelayReportApsNoServiceStatus:enDelayType DO,TimerLen 0,No Need Delay!");

            return VOS_FALSE;
        }

        TAF_MMA_StartTimer(TI_TAF_MMA_DELAY_RPT_APS_DO_NO_SERVICE, (pstClNoServiceDelayRpt->ucDoNoServiceDelayRptLen * 1000));

        return VOS_TRUE;
    }

    if (0 == pstClNoServiceDelayRpt->ucCLNoServiceDelayRptLen)
    {
        MMA_INFOLOG("TAF_MMA_IsNeedDelayReportApsNoServiceStatus:enDelayType DO+LTE,TimerLen 0,No Need Delay!");

        return VOS_FALSE;
    }

    TAF_MMA_StartTimer(TI_TAF_MMA_DELAY_RPT_APS_CL_NO_SERVICE, (pstClNoServiceDelayRpt->ucCLNoServiceDelayRptLen * 1000));

    return VOS_TRUE;
}

/*****************************************************************************
 �� �� ��  : TAF_MMA_Proc3gppMsccServiceStatusIndInGulMode
 ��������  : GUL�յ�MSCC�ķ���״ָ̬ʾ����Ϣ����
 �������  : pstServiceStatus--MSCC�ϱ��ķ���״̬��Ϣ
 �������  : ��
 �� �� ֵ  : ��
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2015��5��24��
    ��    ��   : h00313353
    �޸�����   : �����ɺ���
  2.��    ��   : 2015��02��11��
    ��    ��   : w00281933
    �޸�����   : Service_State_Optimize_PhaseII�޸�
  3.��    ��   : 2015��9��17��
    ��    ��   : s00217060
    �޸�����   : DTS2015091409113�޸�
  4.��    ��   : 2015��10��8��
    ��    ��   : l00324781
    �޸�����   : Iteration 18 ,CLģ����״̬��ʾ�Ż�
*****************************************************************************/
VOS_VOID TAF_MMA_Proc3gppMsccServiceStatusIndInGulMode(
    MSCC_MMA_SERVICE_STATUS_IND_STRU    *pstServiceStatus
)
{
    TAF_SDC_SYS_MODE_ENUM_UINT8         enOldAppSysMode;
    TAF_SDC_SYS_SUBMODE_ENUM_UINT8      enOldAppSysSubMode;
    TAF_SDC_SERVICED_PLMN_INFO_STRU     stOldAppPlmnInfo;
    VOS_UINT8                           ucOldCsSrvSta;
    VOS_UINT8                           ucOldPsSrvSta;

    ucOldPsSrvSta   = TAF_SDC_GetPsServiceStatus();
    ucOldCsSrvSta   = TAF_SDC_GetCsServiceStatus();

    /* ����stAppNetworkInfo֮ǰ�Ȼ�ȡһ�¾ɵ�ϵͳģʽ���µķ���״̬ */
    enOldAppSysMode = TAF_SDC_GetAppSysMode();

    enOldAppSysSubMode = TAF_SDC_GetAppSysSubMode();

    PS_MEM_SET(&stOldAppPlmnInfo, 0, sizeof(TAF_SDC_SERVICED_PLMN_INFO_STRU));
    PS_MEM_CPY(&stOldAppPlmnInfo, &(TAF_SDC_GetAppNetworkInfo()->stAppSysInfo.stServPlmnInfo), sizeof(TAF_SDC_SERVICED_PLMN_INFO_STRU));

    Sta_UpdateServiceStatus(pstServiceStatus->enServiceStatus, pstServiceStatus->enCnDomainId);

#if (FEATURE_ON == FEATURE_BASTET)
    /* ��Ȧ���Ӷ�:��zhongwenguoȷ�ϣ�NO RF���µ��޷���Ҳ��Ҫ�ϱ� */
    TAF_MMA_ProcBastetServiceStatusInd(ucOldCsSrvSta, ucOldPsSrvSta);
#endif

#if (FEATURE_ON == FEATURE_DSDS)
    if (VOS_FALSE == TAF_SDC_Get3GppRfAvailFlag())
    {
        return;
    }
#endif

    /* PS����״̬�����仯֪ͨIMSA��SPMģ�� */
    TAF_MMA_NotifySrvInfoToSpm(pstServiceStatus->enCnDomainId, pstServiceStatus->enServiceStatus, ucOldPsSrvSta);

    /* ֪ͨSTK SERVICE INFO */
    TAF_MMA_ProcCsServiceStatusChanged(ucOldCsSrvSta);
    TAF_MMA_ProcLociStatusEvent();

    /* �ϱ�׼��:
        1.�ӳ�����NV�ر�ʱ�����ϱ�
        2.�������������ϱ�
        3.ע�ᱻ�ܵ��¿���Ч���߿�����λ�����ϱ�
        4.�û��������µķ���״̬�仯�����ϱ�
        5.����һ�����Ѿ��ϱ�(ͨ���Ƚ�APP�е�פ����Ϣ��SDC�е�פ����Ϣ���ж�)����ǰ��Ҳ�����ϱ�
        6.����������״̬�仯����һ������������״̬�����ϱ�
        7.�������񻯵����������񣬲����ӳ�NV�򿪣�����Ч���ӳ��ϱ�
    */

    /* �յ�MMC�ķ���״̬ʱ���Է���״̬�Ƿ���Ҫ�ϱ���AP�Ĵ��� */
    TAF_MMA_ProcServiceStatusReport_ServiceStatusInd(pstServiceStatus);

    /* �յ�MMC�ķ���״̬ʱ����ע��״̬�Ƿ���Ҫ�ϱ���AP�Ĵ��� */
    TAF_MMA_ProcRegStatusReport_ServiceStatusInd(enOldAppSysMode, enOldAppSysSubMode, &stOldAppPlmnInfo);

    /* �յ�MMC�ķ���״̬ʱ�����ź�ǿ���Ƿ���Ҫ�ϱ���AP�Ĵ��� */
    TAF_MMA_ProcRssiReport_ServiceStatusInd(enOldAppSysMode);

    return;
}

#if (FEATURE_ON == FEATURE_UE_MODE_CDMA)
/*****************************************************************************
 �� �� ��  : TAF_MMA_ConvertSdcStaToReportSta
 ��������  : ��SDC����״̬תΪRpt״̬
 �������  : pstServiceStatus--MSCC�ϱ��ķ���״̬��Ϣ
 �������  : ��
 �� �� ֵ  : ��
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2015��5��24��
    ��    ��   : h00313353
    �޸�����   : �����ɺ���
*****************************************************************************/
TAF_SDC_REPORT_SRVSTA_ENUM_UINT8 TAF_MMA_ConvertSdcStaToReportSta(
    TAF_SDC_SERVICE_STATUS_ENUM_UINT8                       enSrvStatus
)
{
    switch (enSrvStatus)
    {
        case TAF_SDC_SERVICE_STATUS_NORMAL_SERVICE:
            return TAF_SDC_REPORT_SRVSTA_NORMAL_SERVICE;

        case TAF_SDC_SERVICE_STATUS_LIMITED_SERVICE:
        case TAF_SDC_SERVICE_STATUS_NO_IMSI:
            return TAF_SDC_REPORT_SRVSTA_LIMITED_SERVICE;

        case TAF_SDC_SERVICE_STATUS_LIMITED_SERVICE_REGION:
            return TAF_SDC_REPORT_SRVSTA_REGIONAL_LIMITED_SERVICE;

        case TAF_SDC_SERVICE_STATUS_NO_SERVICE:
            return TAF_SDC_REPORT_SRVSTA_NO_SERVICE;

        case TAF_SDC_SERVICE_STATUS_NO_CHANGE:
            return TAF_SDC_GetServiceStatus();

        case TAF_SDC_SERVICE_STATUS_DEEP_SLEEP:
            return TAF_SDC_REPORT_SRVSTA_DEEP_SLEEP;

        default:
            return TAF_SDC_REPORT_SRVSTA_BUTT;
    }
}

/*****************************************************************************
 �� �� ��  : TAF_MMA_Update3GppServiceStatusAndDomainCLMode
 ��������  : CLģ�£�����lte(PS��)�ķ���״̬���ܷ���״̬����
 �������  : pstServiceStatus--MSCC�ϱ��ķ���״̬��Ϣ
 �������  :
 �� �� ֵ  : ��
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2015��10��13��
    ��    ��   : l00324781
    �޸�����   : Iteration 18 �����ɺ���
*****************************************************************************/
VOS_VOID TAF_MMA_Update3GppServiceStatusAndDomainCLMode(
    MSCC_MMA_SERVICE_STATUS_IND_STRU   *pstServiceStatus
)
{
    TAF_SDC_SYS_MODE_ENUM_UINT8                             enSysMode;
    TAF_SDC_SERVICE_STATUS_ENUM_UINT8                       enSrvStatus;

    /* ��ʹ��SysMode֮ǰ����ֵ������ˢ�£��˴�����ʹ���µ�SysMode */
    enSysMode   = TAF_SDC_GetSysMode();
    enSrvStatus = (TAF_SDC_SERVICE_STATUS_ENUM_UINT8)pstServiceStatus->enServiceStatus;

    /* ����coverity�澯 */
    if (TAF_SDC_SYS_MODE_BUTT == enSysMode)
    {
        TAF_WARNING_LOG(WUEPS_PID_MMA,
                        "TAF_MMA_Update3GppServiceStatusAndDomainCLMode: System Mode is BUTT!");
    }

    /* ����PS�����״̬ */
    TAF_SDC_SetPsServiceStatus(enSrvStatus);

    /* ���·����� */
    TAF_MMA_UpdateServiceDomainInClMode(enSysMode);


    /* �����ܷ���״̬,����CS�����״̬��PS�����״̬�����ܷ���״̬ */
    TAF_MMA_UpdateReportService();
}

#endif

/*****************************************************************************
 �� �� ��  : TAF_MMA_ProcMsccServiceStatusInd
 ��������  : �յ�MSCC�ķ���״ָ̬ʾ����Ϣ����
 �������  : pstServiceStatus--MSCC�ϱ��ķ���״̬��Ϣ
 �������  : ��
 �� �� ֵ  : ��
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2013��6��4��
    ��    ��   : s00217060
    �޸�����   : �����ɺ���
  2.��    ��   : 2014��11��25��
    ��    ��   : s00217060
    �޸�����   : Service_State_Optimize_PhaseI��Ŀ�޸�
  3.��    ��   : 2015��01��28��
    ��    ��   : y00245242
    �޸�����   : iteration 9����������IMSA�ӿڵ�MSCCģ��
  4.��    ��   : 2015��4��27��
    ��    ��   : b00269685
    �޸�����   : �ϱ�rssiʱ��Ҫ�ж�һ��rat
  5.��    ��   : 2015��5��26��
    ��    ��   : h00313353
    �޸�����   : ���Ӵ���LTE��SVLTE
  6.��    ��   : 2015��10��13��
    ��    ��   : l00324781
    �޸�����   : Iteration 18 �޸�
*****************************************************************************/
VOS_VOID TAF_MMA_Proc3gppMsccServiceStatusInd(
    MSCC_MMA_SERVICE_STATUS_IND_STRU   *pstServiceStatus
)
{

#if (FEATURE_ON == FEATURE_UE_MODE_CDMA)
    TAF_SDC_REPORT_SRVSTA_ENUM_UINT8    enOldRptSrvStatus;
    TAF_SDC_SYS_MODE_ENUM_UINT8         enSysMode;
    TAF_SDC_SYS_SUBMODE_ENUM_UINT8      enSubMode;
    pTafSdcSysmodServiceRegStaUpdateFunc                    pFuncTafSdcSysmodServiceRegStaUpdate;

    enSysMode                           = TAF_SDC_SYS_MODE_BUTT;
    enSubMode                           = TAF_SDC_SYS_SUBMODE_BUTT;
    pFuncTafSdcSysmodServiceRegStaUpdate = VOS_NULL_PTR;

    if (VOS_TRUE == TAF_SDC_IsConfigCLMode())
    {
        /* �����ʱ�ϱ��Ĳ���PS��ķ���״̬����ֱ�ӹ��˵� */
        if ((NAS_MSCC_PIF_SRVDOMAIN_PS == pstServiceStatus->enCnDomainId)
         || (NAS_MSCC_PIF_SRVDOMAIN_CS_PS == pstServiceStatus->enCnDomainId))
        {
            /* ����״̬��ʱ��ά�ɲ� */
            TAF_MMA_LogCLDelayRptSrvStatusCtx(TAF_MMA_LOG_CL_DELAY_REPORT_CTX_TYPE_ENTER);

            if (NAS_MSCC_PIF_SERVICE_STATUS_NORMAL_SERVICE == pstServiceStatus->enServiceStatus)
            {
                TAF_MMA_MapCdmaNetworkExistanceSrvStaToSysMode(TAF_SDC_LTE_NETWORK_EXIST, &enSysMode, &enSubMode, &pFuncTafSdcSysmodServiceRegStaUpdate);
                Mma_ModeChgReport(enSysMode, enSubMode);

                TAF_SDC_SetSysMode(enSysMode);
                TAF_SDC_SetSysSubMode(enSubMode);

                TAF_MMA_StopTimer(TI_TAF_MMA_DELAY_RPT_APS_CL_NO_SERVICE);
                TAF_MMA_StopTimer(TI_TAF_MMA_DELAY_RPT_APS_DO_NO_SERVICE);
                TAF_MMA_GetCLNoServiceDelayRptInfo()->enDelayType   = TAF_MMA_DELAY_CL_REPORT_TYPE_BUTT;
            }

            /* �����ϵ��ܷ���״̬ */
            enOldRptSrvStatus = TAF_SDC_GetServiceStatus();

            /* ����PS�����״̬����״̬�������� */
            TAF_MMA_Update3GppServiceStatusAndDomainCLMode(pstServiceStatus);

            /* ����״̬�и���ʱ�Ž��뺯������ */
            if (enOldRptSrvStatus != TAF_SDC_GetServiceStatus())
            {
                TAF_MMA_ReportHrpdAndLteServiceState();
            }
            else
            {
                /* ����PS�������Ϣ */
                if (TAF_MMA_TIMER_STATUS_RUNING != TAF_MMA_GetTimerStatus(TI_TAF_MMA_PS_SERVICE_STATUS_DELAY_REPORT_IN_CL_MODE))
                {
                    TAF_MMA_UpdateAppPsSrvInfoInClMode();
                }
            }

            TAF_MMA_LogCLDelayRptSrvStatusCtx(TAF_MMA_LOG_CL_DELAY_REPORT_CTX_TYPE_EXIT);

        }

    }
    else
#endif
    {
        /* ����GU */
        TAF_MMA_Proc3gppMsccServiceStatusIndInGulMode(pstServiceStatus);
    }

    return;
}

/* Added by w00176964 for VoLTE_PhaseII ��Ŀ, 2013-10-10, end */

/*****************************************************************************
 �� �� ��  : TAF_MMA_Proc3gppMsccRegStatusInd
 ��������  : �յ�MMC��ע��״̬״ָ̬ʾ����Ϣ����
 �������  : pstServiceStatus--MMC�ϱ��ķ���״̬��Ϣ
 �������  : ��
 �� �� ֵ  : ��
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2015��4��1��
    ��    ��   : b00269685
    �޸�����   : �����ɺ���
  2.��    ��   : 2015��02��11��
    ��    ��   : w00281933
    �޸�����   : Service_State_Optimize_PhaseII�޸�
  3.��    ��   : 2015��9��30��
    ��    ��   : j00354216
    �޸�����   : CDMA Iteration 18 �޸�,ԭ����TAF_MMA_Proc3gppMsccRegStatusInd
*****************************************************************************/
VOS_VOID TAF_MMA_Proc3gppMsccRegStatusIndGulMode(
    MSCC_MMA_SERVICE_STATUS_IND_STRU   *pstServiceStatus
)
{
    TAF_SDC_REG_STATUS_ENUM_UINT8       enOldCsRegState;
    TAF_SDC_REG_STATUS_ENUM_UINT8       enOldPsRegState;
    VOS_UINT32                          ucIsNeedRptRegStatus;
    NAS_MSCC_PIF_SRVDOMAIN_ENUM_UINT32  enCnDomainId;
    TAF_SDC_SYS_MODE_ENUM_UINT8         enOldAppSysMode;
#if (FEATURE_ON == FEATURE_PTM)
    VOS_UINT32                          ucIsCLWork;
    VOS_UINT32                          ucIsUsimSrvAvail;
#endif

    /* ����stAppNetworkInfo֮ǰ�Ȼ�ȡһ�¾ɵ�ϵͳģʽ */
    enOldAppSysMode                     = TAF_SDC_GetAppSysMode();

    enCnDomainId                        = pstServiceStatus->enCnDomainId;

    ucIsNeedRptRegStatus                = VOS_FALSE;

    enOldCsRegState                     = TAF_SDC_GetCsRegStatus();
    enOldPsRegState                     = TAF_SDC_GetPsRegStatus();

#if (FEATURE_ON == FEATURE_PTM)
    ucIsCLWork       = TAF_SDC_IsConfigCLInterWorkCOutside();
    ucIsUsimSrvAvail = TAF_MMA_IsUsimServiceAvailable();
#endif

    /* CLģʽ�£�Ӧ�ù���CS��ע��״̬ */



    /*�����ڲ������б���RoamFlag*/
    TAF_MMA_UpdateRoamFlag((TAF_SDC_REG_STATUS_ENUM_UINT8)pstServiceStatus->enRegState);

    /*�����ڲ����������ע��״̬*/
    if (NAS_MSCC_PIF_SRVDOMAIN_CS == enCnDomainId)
    {
        TAF_SDC_SetCsRegStatus(pstServiceStatus->enRegState);
    }
    else if (NAS_MSCC_PIF_SRVDOMAIN_PS == enCnDomainId)
    {
        TAF_SDC_SetPsRegStatus(pstServiceStatus->enRegState);
    }
    else
    {
        STA_TRACE (STA_WARNING_PRINT,
            "TAF_MMA_ProcMsccRegStatusInd():WARNING:enCurRegStatus is TAF_SDC_REG_STATUS_BUTT");
    }

#if (FEATURE_ON == FEATURE_DSDS)
    if (VOS_FALSE == TAF_SDC_Get3GppRfAvailFlag())
    {
        return;
    }
#endif

    /* �ϱ�׼��:
        1.�ӳ�����NV�ر�ʱ�����ϱ�
        2.ע��ɹ������ϱ�
        3.ע�ᱻ�ܵ��¿���Ч���߿�����λ�����ϱ�
        4.�û��������µ�ע��״̬�����ϱ�
        5.����һ�����Ѿ��ϱ�(ͨ���Ƚ�APP�е�פ����Ϣ��SDC�е�פ����Ϣ���ж�)����ǰ��Ҳ�����ϱ�
        6.��ע��ɹ�״̬�仯����һ����ע��ɹ�״̬�����ϱ�
        7.ע��ɹ��仯����ע��ɹ�״̬�������ӳ�NV�򿪣�����Ч���ӳ��ϱ�
    */

    /*�ж��Ƿ���Ҫ�ϱ�*/
    ucIsNeedRptRegStatus = TAF_MMA_IsNeedReportRegStatus_RegStatusInd(enCnDomainId,
                                                                      enOldCsRegState,
                                                                      enOldPsRegState,
                                                                      pstServiceStatus->enRegState);

    /*��Ҫ�ϱ���AT*/
    if (VOS_TRUE == ucIsNeedRptRegStatus)
    {
        /*��Ҫ������ʱ�ϱ���ʱ��*/
        if (VOS_TRUE == TAF_MMA_IsNeedDelayReportRegStatus(enCnDomainId, pstServiceStatus->enRegState))
        {
            /* ��������״̬��ע��״̬�ӳ��ϱ� */
            TAF_MMA_ProcDelayReport();
        }
        else
        {
            /* ʡ���Ż�����ʶ�� */
            if (VOS_TRUE == TAF_SDC_IsNeedReportRegStatusWhenNonnormalService((TAF_SDC_SERVICE_DOMAIN_ENUM_UINT8)enCnDomainId, pstServiceStatus->enRegState))
            {
                /*�ϱ�ע��״̬*/
                TAF_MMA_SndAtRegStatus(enCnDomainId, pstServiceStatus->enRegState);
            }

            /*ֹͣ��ʱ��*/
            if ((NAS_MSCC_PIF_REG_REGISTERED_HOME_NETWORK == pstServiceStatus->enRegState)
             || (NAS_MSCC_PIF_REG_REGISTERED_ROAM         == pstServiceStatus->enRegState))
            {
                TAF_MMA_StopTimer(TI_TAF_MMA_DELAY_REPORT_SERVICE_STATUS);
            }

            /*����APP�б����ע��״̬*/
            TAF_MMA_UpdateAppRegStatusInfo(enCnDomainId);
        }
    }
    else
    {

        /*ֹͣ��ʱ��*/
        if ((NAS_MSCC_PIF_REG_REGISTERED_HOME_NETWORK == pstServiceStatus->enRegState)
         || (NAS_MSCC_PIF_REG_REGISTERED_ROAM         == pstServiceStatus->enRegState))
        {
            TAF_MMA_StopTimer(TI_TAF_MMA_DELAY_REPORT_SERVICE_STATUS);
        }
    }

#if (FEATURE_ON == FEATURE_PTM)
    /* �ڷ�CL����̬�²��ϱ� */
    if ((VOS_FALSE == ucIsCLWork)
     && (VOS_TRUE  == ucIsUsimSrvAvail))
    {
        TAF_MMA_ProcErrlogOosReport(enOldCsRegState,
                                    enOldPsRegState,
                                    pstServiceStatus);
    }
#endif


    /* MMC�п����ȱ�ע��״̬��MMA���appnetwork�����Ϣ���£��յ�����״̬ʱ�в������ź��Ƿ���Ҫ�ϱ� */
    TAF_MMA_ProcRssiReport_ServiceStatusInd(enOldAppSysMode);

    return;
}

#if (FEATURE_ON == FEATURE_UE_MODE_CDMA)
/*****************************************************************************
 �� �� ��  : TAF_MMA_Proc3gppMsccRegStatusIndClMode
 ��������  : �յ�MMC��ע��״̬״ָ̬ʾ����Ϣ����
 �������  : pstServiceStatus--MMC�ϱ��ķ���״̬��Ϣ
 �������  : ��
 �� �� ֵ  : ��
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2015��4��1��
    ��    ��   : b00269685
    �޸�����   : �����ɺ���
  2.��    ��   : 2015��02��11��
    ��    ��   : w00281933
    �޸�����   : Service_State_Optimize_PhaseII�޸�
  3.��    ��   : 2015��9��30��
    ��    ��   : j00354216
    �޸�����   : CDMA Iteration 18 �޸�

  4.��    ��   : 2015��11��19��
    ��    ��   : Y00213812
    �޸�����   : �ϱ�^MODE,ɾ�������߼�
*****************************************************************************/
VOS_VOID TAF_MMA_Proc3gppMsccRegStatusIndClMode(
    MSCC_MMA_SERVICE_STATUS_IND_STRU   *pstServiceStatus
)
{
    TAF_SDC_SYS_MODE_ENUM_UINT8                             enSysMode;
    TAF_SDC_SYS_SUBMODE_ENUM_UINT8                          enSubMode;
    pTafSdcSysmodServiceRegStaUpdateFunc                    pFuncTafSdcSysmodServiceRegStaUpdate;

    TAF_MMA_UpdateRoamFlag((TAF_SDC_REG_STATUS_ENUM_UINT8)pstServiceStatus->enRegState);

    /*���������PS�򣬲����� */
    if((NAS_MSCC_PIF_SRVDOMAIN_CS_PS == pstServiceStatus->enCnDomainId)
    || (NAS_MSCC_PIF_SRVDOMAIN_PS == pstServiceStatus->enCnDomainId))
    {
        /* ����״̬��ʱ��ά�ɲ� */
        TAF_MMA_LogCLDelayRptSrvStatusCtx(TAF_MMA_LOG_CL_DELAY_REPORT_CTX_TYPE_ENTER);

        /* ���±��ص�ģʽ���ϱ� */
        if ((NAS_MSCC_PIF_REG_REGISTERED_HOME_NETWORK == pstServiceStatus->enRegState)
         || (NAS_MSCC_PIF_REG_REGISTERED_ROAM == pstServiceStatus->enRegState))
        {
            TAF_MMA_MapCdmaNetworkExistanceSrvStaToSysMode(TAF_SDC_LTE_NETWORK_EXIST, &enSysMode, &enSubMode, &pFuncTafSdcSysmodServiceRegStaUpdate);
            Mma_ModeChgReport(enSysMode, enSubMode);

            TAF_SDC_SetSysMode(enSysMode);
            TAF_SDC_SetSysSubMode(enSubMode);

            TAF_MMA_StopTimer(TI_TAF_MMA_DELAY_RPT_APS_CL_NO_SERVICE);
            TAF_MMA_StopTimer(TI_TAF_MMA_DELAY_RPT_APS_DO_NO_SERVICE);
            TAF_MMA_GetCLNoServiceDelayRptInfo()->enDelayType   = TAF_MMA_DELAY_CL_REPORT_TYPE_BUTT;

            /* ֪ͨAPS��ǰ�ķ���ģʽ */
            TAF_MMA_SndTafCLServiceStatusInd(MMA_TAF_RAT_TYPE_LTE, VOS_FALSE);

            /* CS��ʱ��ʱ�����������У����Բ���ֱ�Ӹ��� */
            TAF_MMA_UpdateAppSysModeAndSysSubModeInClModeLte(TAF_SDC_LTE_NETWORK_EXIST);

            /* ����SubMode���·����� */
            TAF_MMA_UpdateAppServiceDomainInClMode(TAF_SDC_GetAppSysMode());
        }


        TAF_MMA_ReportPsRegStatusInClMode(pstServiceStatus->enRegState);

        TAF_MMA_LogCLDelayRptSrvStatusCtx(TAF_MMA_LOG_CL_DELAY_REPORT_CTX_TYPE_EXIT);
    }

    return;
}
#endif

/*****************************************************************************
 �� �� ��  : TAF_MMA_Proc3gppMsccRegStatusInd
 ��������  : �յ�MMC��ע��״̬״ָ̬ʾ����Ϣ����
 �������  : pstServiceStatus--MMC�ϱ��ķ���״̬��Ϣ
 �������  : ��
 �� �� ֵ  : ��
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2015��4��1��
    ��    ��   : b00269685
    �޸�����   : �����ɺ���
  2.��    ��   : 2015��02��11��
    ��    ��   : w00281933
    �޸�����   : Service_State_Optimize_PhaseII�޸�
  3.��    ��   : 2015��9��30��
    ��    ��   : j00354216
    �޸�����   : CDMA Iteration 18 �޸�
*****************************************************************************/
VOS_VOID TAF_MMA_Proc3gppMsccRegStatusInd(
    MSCC_MMA_SERVICE_STATUS_IND_STRU   *pstServiceStatus
)
{
#if (FEATURE_ON == FEATURE_UE_MODE_CDMA)
    if (VOS_TRUE == TAF_SDC_IsConfigCLMode())
    {
        /* ����CL */
        TAF_MMA_Proc3gppMsccRegStatusIndClMode(pstServiceStatus);
    }
    else
#endif
    {
        /* ����GU */
        TAF_MMA_Proc3gppMsccRegStatusIndGulMode(pstServiceStatus);
    }

    return;
}

/*************************************************
  Function:
    Sta_ServiceStatusInd
  Description:
    ����MSCC_SERVICE_STATUS_IND��Ϣ
  Calls:                 �����������õĺ����嵥
  Called By:             ���ñ������ĺ����嵥
  Input:
    MSCC_MMA_SERVICE_STATUS_IND_STRU *pServiceStatus; ��������ṹָ��
  Output:
    ��
  Return:
    STA_SUCCESS         =0, ��������
    STA_ERROR           =1, ���󷵻�
  Others:
    author:   l48197 2005-10-21
    modified:
        ��attach,detach�������յ�service_status_ind��ֱ�ӷ��أ�
        enable״̬�£�����ǰ��״̬����
  2.��    ��   : 2006��12��7��
    ��    ��   : H59254
    �޸�����   : ���ⵥ�ţ�A32D07836

  3.��    ��   : 2010��5��13��
    ��    ��   : o00132663
    �޸�����   : AT2D19345,����Ż�����ΪOAM�������������ѯ��ʽ

  3.��    ��   : 2012��10��16��
    ��    ��   : z40661
    �޸�����   : DTS202090604118
  4.��    ��   : 2013��4��2��
    ��    ��   : z00161729
    �޸�����   : �����ϱ�AT�������������C�˼�mma��mscc�ӿڵ���
  5.��    ��   : 2013��06��3��
    ��    ��   : s46746
    �޸�����   : SS FDN&Call Control��Ŀ��ע��״̬�ػ�Ҳ��Ҫ�ϱ�
  6.��    ��   : 2013��07��26��
    ��    ��   : l00208543
    �޸�����   : CS����״̬�仯ʱ����STK���ͷ���״̬�仯��Ϣ
  7.��    ��   : 2012��07��15��
    ��    ��   : w00176964
    �޸�����   : VoLTE_PhaseI��Ŀ�޸�:�޸ĺ��������ͷ���ֵ
  8.��    ��   : 2013��07��27��
    ��    ��   : y00245242
    �޸�����   : VoLTE_PhaseI��Ŀ�޸�:PSҵ��״̬�����ı䣬֪ͨIMSA
  9.��    ��   : 2012��07��15��
    ��    ��   : w00176964
    �޸�����   : VoLTE_PhaseI��Ŀ�޸�:�޸ĺ��������ͷ���ֵ
 10.��    ��   : 2013��07��27��
    ��    ��   : y00245242
    �޸�����   : VoLTE_PhaseI��Ŀ�޸�:PSҵ��״̬�����ı䣬֪ͨIMSA
 12.��    ��   : 2013��10��9��
    ��    ��   : w00176964
    �޸�����   : VoLTE_PhaseII��Ŀ:����״̬���ϱ�������װ�ɺ���
 13.��    ��   : 2013��11��15��
    ��    ��   : l65478
    �޸�����   : DTS2013111808478:�ػ������з���״̬��ѯ�Ľ��ʱ��������
 14.��    ��   : 2014��1��23��
    ��    ��   : z00161729
    �޸�����   : DTS2014012305088:svlte���Կ�������Ч����mtc�����ϱ�pstransfer:0��1
 15.��    ��   : 2014��3��20��
    ��    ��   : s00246516
    �޸�����   : L-C��������Ŀ����CMMCA�ϱ�����״̬
 16.��    ��   : 2014��4��30��
    ��    ��   : w00176964
    �޸�����   : V3R3C60_eCall��Ŀ����:�ϱ�SIMST�ĵط����Ƶ�����
 17.��    ��   : 2014��6��16��
    ��    ��   : w00167002
    �޸�����   : ����no rf��־����ֱ�Ӳ�����
 18.��    ��   : 2014��11��25��
    ��    ��   : s00217060
    �޸�����   : Service_State_Optimize_PhaseI�޸�
 19.��    ��   : 2015��4��1��
    ��    ��   : B00269685
    �޸�����   : ���յ�ע��״̬ʱ����roam flg
 20.��    ��   : 2015��02��11��
    ��    ��   : w00281933
    �޸�����   : Service_State_Optimize_PhaseII�޸�
*************************************************/
VOS_UINT32 Sta_ServiceStatusInd(
    VOS_UINT32                          ulEventType,
    struct MsgCB                       *pstMsg
)
{
    STA_PHONE_DATA_S                    Update;         /* ��Ҫ���µ�ȫ������ */
    VOS_UINT32                          ulRet;
    TAF_SDC_PLMN_ID_STRU               *pstPlmnId = VOS_NULL_PTR;

    VOS_UINT8                           ucLastSimCsRegStatus;
    VOS_UINT8                           ucLastSimPsRegStatus;

#if ((FEATURE_MULTI_MODEM == FEATURE_ON) || (FEATURE_CL_INTERWORK == FEATURE_ON))
    VOS_UINT32                          ulOldUsimValidStatus;
    VOS_UINT32                          ulNewUsimValidStatus;
#endif
    TAF_SDC_SYS_MODE_ENUM_UINT8         enSysMode;

#if (FEATURE_CL_INTERWORK == FEATURE_ON)
    VOS_UINT8                           ulOldSrvSta;
#endif

    MSCC_MMA_SERVICE_STATUS_IND_STRU    *pServiceStatus;

    pServiceStatus = (MSCC_MMA_SERVICE_STATUS_IND_STRU*)pstMsg;

    pstPlmnId = TAF_SDC_GetCurrCampPlmnId();

#if (FEATURE_CL_INTERWORK == FEATURE_ON)
    ulOldSrvSta     = TAF_SDC_GetServiceStatus();
#endif

#if (FEATURE_MULTI_MODEM == FEATURE_ON)
    ulOldUsimValidStatus = TAF_SDC_IsUsimStausValid();
#endif

    ucLastSimCsRegStatus    = TAF_SDC_GetSimCsRegStatus();
    ucLastSimPsRegStatus    = TAF_SDC_GetSimPsRegStatus();

    /* ����SDC�е�SIM����CS/PS��ע��״̬ */
    TAF_SDC_SetSimCsRegStatus(pServiceStatus->ucSimCsRegStatus);
    TAF_SDC_SetSimPsRegStatus(pServiceStatus->ucSimPsRegStatus);

    Sta_IccStatusReport(ucLastSimCsRegStatus, ucLastSimPsRegStatus);

#if (FEATURE_MULTI_MODEM == FEATURE_ON)
    ulNewUsimValidStatus = TAF_SDC_IsUsimStausValid();

    /* ���cs ps��״̬�����ı���Ҫ֪ͨmtc */
    if (ulOldUsimValidStatus != ulNewUsimValidStatus)
    {
        TAF_MMA_SndMtcRegStatusInd((VOS_UINT8)ulNewUsimValidStatus);
    }
#endif

    enSysMode = TAF_SDC_GetSysMode();

    /* ���±��صķ���״̬ */
    if (VOS_TRUE == pServiceStatus->bitOpSrvSta)
    {
        if (((TAF_SDC_SYS_MODE_EVDO == enSysMode)
          || (TAF_SDC_SYS_MODE_HYBRID == enSysMode))
          && (NAS_MSCC_PIF_SERVICE_STATUS_NORMAL_SERVICE != pServiceStatus->enServiceStatus))
        {
        }
        else
        {
            TAF_MMA_Proc3gppMsccServiceStatusInd(pServiceStatus);
        }
    }

    /*ע��״̬�ϱ�����*/
    if (VOS_TRUE == pServiceStatus->bitOpRegSta)
    {
        if (((TAF_SDC_SYS_MODE_EVDO == enSysMode)
          || (TAF_SDC_SYS_MODE_HYBRID == enSysMode))
          && (NAS_MSCC_PIF_REG_REGISTERED_HOME_NETWORK != pServiceStatus->enRegState)
          && (NAS_MSCC_PIF_REG_REGISTERED_ROAM         != pServiceStatus->enRegState))
        {

        }
        else
        {
            TAF_MMA_Proc3gppMsccRegStatusInd(pServiceStatus);
        }
    }

#if (FEATURE_CL_INTERWORK == FEATURE_ON)
    if ((ulOldSrvSta != TAF_SDC_GetServiceStatus())
     || (ulOldUsimValidStatus != ulNewUsimValidStatus))
    {
        if (VOS_TRUE == TAF_MMA_IsPowerOnCLInterWork())
        {
            TAF_MMA_SndCmmcaServiceInd();
        }
    }
#endif

    switch ( g_StatusContext.ulFsmState )
    {/* ϵͳ״̬ */
        case  STA_FSM_PLMN_SEL:

            Sta_UpdateLocalState(pServiceStatus, STA_FSMSUB_UPDATE);

            break;

        case  STA_FSM_ENABLE:

            /*ȡ��PS��CS��ķ�����Ϣ*/
            /* Modified by z00161729 for �����ϱ�AT�������������C��, 2013-4-3, begin */
            Update.ulCsServiceStatus = TAF_SDC_GetCsServiceStatus();
            Update.ulPsServiceStatus = TAF_SDC_GetPsServiceStatus();
            Update.ucDomainFlag      = (VOS_UINT8)pServiceStatus->enCnDomainId;
            Update.ulCsCause         = 0;
            Update.ulPsCause         = 0;

            Update.PlmnId.Mcc        = pstPlmnId->ulMcc;
            Update.PlmnId.Mnc        = pstPlmnId->ulMnc;

            /* Modified by z00161729 for �����ϱ�AT�������������C��, 2013-4-3, end */

            Update.ucFsmSubOperate   = STA_FSMSUB_FINISH;
            Update.ulFsmState        = STA_FSM_ENABLE;
            Update.ucFsmStateSub     = STA_FSMSUB_NULL;
            Update.ucFsmUpdateFlag   = STA_UPDATE_DUAL_CLEAR;


            ulRet = Sta_UpdateData (&Update);
            if ( STA_ERROR == ulRet )
            {
                STA_TRACE (STA_WARNING_PRINT,
                    "Sta_ServiceStatusInd():WARNING:Sta_UpdateData failed");
            }

            break;

        default:

            break;
    }

    return VOS_TRUE;         /* �������� */
}

/*************************************************
  Function:
    Sta_DetachInd
  Description:
    ����MSCC_DETACH_IND��Ϣ
  Calls:                 �����������õĺ����嵥
  Called By:             ���ñ������ĺ����嵥
  Input:
    ST_MSCC_DETACH_IND   *pDetachInd; ��������ṹָ��
  Output:
    ��
  Return:
    STA_SUCCESS         =0, ��������
    STA_ERROR           =1, ���󷵻�
  Others:
     author:   l48197 2005-10-21
     modified:
        ��attach,detach�������յ�service_status_ind��ֱ�ӷ��أ�
        enable״̬�£�����ǰ��״̬����
 2.��    ��   : 2013��4��2��
   ��    ��   : z00161729
   �޸�����   : �����ϱ�AT�������������C�˼�mma��mscc�ӿڵ���
 3.��    ��   : 2013��7��26��
   ��    ��   : l00208543
   �޸�����   : STK������Ŀ
 4.��    ��   : 2012��07��15��
   ��    ��   : w00176964
   �޸�����   : VoLTE_PhaseI��Ŀ�޸�:�޸ĺ��������ͷ���ֵ
*************************************************/
VOS_UINT32 Sta_DetachInd(
    VOS_UINT32                          ulEventType,
    struct MsgCB                       *pstMsg
)
{
    STA_PHONE_DATA_S                    Update; /* ��Ҫ���µ�ȫ������ */
    VOS_UINT32                          ulRet;
    VOS_UINT32                          ulOldSrvSta;
    /* Added by l00208543 for V9R1 STK����, 2013-07-26, begin */
    VOS_UINT8                           ucOldCsSrvSta;
    /* Added by l00208543 for V9R1 STK����, 2013-07-26, end */

    /* Added by w00176964 for VoLTE_PhaseI��Ŀ, 2013-7-15, begin */
    MSCC_MMA_DETACH_IND_STRU            *pDetachInd;

    pDetachInd = (MSCC_MMA_DETACH_IND_STRU*)pstMsg;
    /* Added by w00176964 for VoLTE_PhaseI��Ŀ, 2013-7-15, end */

   /* Modified by z00161729 for �����ϱ�AT�������������C��, 2013-4-2, begin */

    /* ENABLE״̬*/
    if ( g_StatusContext.ulFsmState & STA_FSM_ENABLE )
    {
        ulOldSrvSta = TAF_SDC_GetServiceStatus();

        /* Added by l00208543 for V9R1 STK����, 2013-07-26, begin */
        ucOldCsSrvSta = TAF_SDC_GetCsServiceStatus();
        /* Added by l00208543 for V9R1 STK����, 2013-07-26, end */

        Sta_UpdateServiceStatus(pDetachInd->enServiceStatus, pDetachInd->enCnDomainId);

        /* Added by l00208543 for V9R1 STK����, 2013-07-26, begin */
        TAF_MMA_ProcCsServiceStatusChanged(ucOldCsSrvSta);
        /* Added by l00208543 for V9R1 STK����, 2013-07-26, end */

        /*ȡ��PS��CS��ķ�����Ϣ*/
        Update.ulCsServiceStatus = TAF_SDC_GetCsServiceStatus();
        Update.ulPsServiceStatus = TAF_SDC_GetPsServiceStatus();
        Update.ulCsCause         = 0;
        Update.ulPsCause         = 0;
        Update.ucDomainFlag      = (VOS_UINT8)pDetachInd->enCnDomainId;

        Update.ucFsmSubOperate   = STA_FSMSUB_FINISH;
        Update.ulFsmState        = STA_FSM_ENABLE;
        Update.ucFsmStateSub     = STA_FSMSUB_NULL;
        Update.ucFsmUpdateFlag   = STA_UPDATE_DUAL_CLEAR;
        ulRet = Sta_UpdateData (&Update);
        if ( STA_ERROR == ulRet )
        {
            STA_TRACE (STA_WARNING_PRINT,
                "Sta_DetachInd():WARNING:Sta_UpdateData failed");
        }

        if (ulOldSrvSta != TAF_SDC_GetServiceStatus())
        {
            TAF_MMA_ReportSrvStatus();
        }

        /* Modified by w00176964 for VoLTE_PhaseI��Ŀ, 2013-7-15, begin */
        return VOS_TRUE;
        /* Modified by w00176964 for VoLTE_PhaseI��Ŀ, 2013-7-15, end */
    }

    /* Modified by z00161729 for �����ϱ�AT�������������C��, 2013-4-2, end */

    /* û�������� */
    STA_TRACE (STA_WARNING_PRINT,
        "Sta_DetachInd():WARNING:invalid state, do nothing");

    /* Modified by w00176964 for VoLTE_PhaseI��Ŀ, 2013-7-15, begin */
    return VOS_TRUE;
    /* Modified by w00176964 for VoLTE_PhaseI��Ŀ, 2013-7-15, end */
}

/*************************************************
  Function:
    Sta_ReOrderPlmnList
  Description:
    ��˫ģ�б��������ϱ����,����������,��ǰפ��PLMN�ж�����뼼��ʱ,����ǰע����б��������ǰ��
  Calls:                 �����������õĺ����嵥
  Called By:             ���ñ������ĺ����嵥
  Input:
    TAF_PLMN_LIST_STRU    *pPlmnList; ��������ṹָ��
  Output:
    ��
  Return:
    ��
  Others:
  1.��    ��   : 2008��01��05��
    ��    ��   : l00130025
    �޸�����   : ���ⵥ�ţ�AT2D07968
  2.��    ��   : 2011��6��29��
    ��    ��   : z00161729
    �޸�����   : V7R1 phase II֧��syscfgex�����޸�
  3.��    ��   : 2011��09��14��
    ��    ��   : w00166186
    �޸�����   : V7R1 phase II֧��Lģ�б���
*************************************************/
VOS_VOID Sta_ReOrderPlmnList (TAF_PLMN_LIST_STRU* pPlmnList)
{
    VOS_UINT32   ulRegPlmnIndx = TAF_MAX_PLMN_NUM;
    VOS_UINT32   ulSamePlmnIndx = TAF_MAX_PLMN_NUM;
    TAF_MMA_RAT_ORDER_STRU             *pstRatOrder = VOS_NULL_PTR;
    VOS_UINT32   ulIndx = 0;

    TAF_PLMN_ID_STRU    stPlmnId;
    TAF_PLMN_STATUS_STRU    stStatus;
    PS_MEM_SET(&stPlmnId, 0, sizeof(stPlmnId));
    PS_MEM_SET(&stStatus, 0, sizeof(stStatus));

    pstRatOrder     = TAF_MMA_GetRatPrioListAddr();

    /* �ϱ��б���С��2��ǰģʽ��˫ģ,��ֱ�ӷ��� */
    if( (pPlmnList->ucPlmnNum < 2 )
     || (pstRatOrder->ucRatOrderNum <= 1) )
    {
        return;
    }
    /* ȷ����ǰ�Ƿ���ע���PLMN */
    for( ulIndx = 0; ulIndx < pPlmnList->ucPlmnNum; ++ulIndx)
    {
        if( TAF_PH_NETWORK_STATUS_CURRENT == pPlmnList->PlmnInfo[ulIndx].PlmnStatus)
        {
            ulRegPlmnIndx = ulIndx;
        }
    }
    if(TAF_MAX_PLMN_NUM == ulRegPlmnIndx)
    {
        return; /* �ϱ��б���û��ע���PLMN ���ش���*/
    }
    stPlmnId.Mcc = pPlmnList->Plmn[ulRegPlmnIndx].Mcc;
    stPlmnId.Mnc = pPlmnList->Plmn[ulRegPlmnIndx].Mnc;
    /* ��ǰ��˫ģ����ע���PLMN,ȷ���б����Ƿ��������б����뵱ǰע���PLMN��ͬ */
    for( ulIndx = 0; ulIndx < pPlmnList->ucPlmnNum; ++ulIndx)
    {
        if( (stPlmnId.Mnc == pPlmnList->Plmn[ulIndx].Mnc)
            && (stPlmnId.Mcc == pPlmnList->Plmn[ulIndx].Mcc)
            && (ulIndx != ulRegPlmnIndx) )
        {
            ulSamePlmnIndx = ulIndx;
        }
    }
    if(TAF_MAX_PLMN_NUM == ulSamePlmnIndx)
    {
       return; /* �ϱ��б���û����ע��PLMN��ͬ���б��� */
    }
    if(ulRegPlmnIndx < ulSamePlmnIndx)
    {
       return; /* �ϱ��б��е�ע��PLMN��˳�������� ,����*/
    }
    /* ����ע��PLMN�ǰ�� ����*/
    PS_MEM_CPY(&stStatus, &(pPlmnList->PlmnInfo[ulSamePlmnIndx]), sizeof(TAF_PLMN_STATUS_STRU));
    PS_MEM_CPY(&(pPlmnList->PlmnInfo[ulSamePlmnIndx]), &(pPlmnList->PlmnInfo[ulRegPlmnIndx]), sizeof(TAF_PLMN_STATUS_STRU));
    PS_MEM_CPY(&(pPlmnList->PlmnInfo[ulRegPlmnIndx]), &stStatus, sizeof(TAF_PLMN_STATUS_STRU));
    return; /* �ϱ��б��е�ע��PLMN��˳��������,����*/
}

#if (FEATURE_ON == FEATURE_CSG)
/*****************************************************************************
 �� �� ��  : TAF_MMA_ClearCsgListSearchOperCtx
 ��������  : �ͷ�csg�б���ʱ�����OperCtx
 �������  : ��
 �������  : ��
 �� �� ֵ  : ��
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2015��9��28��
    ��    ��   : z00161729
    �޸�����   : ֧��LTE CSG��������

*****************************************************************************/
VOS_VOID TAF_MMA_ClearCsgListSearchOperCtx(VOS_VOID)
{
    TAF_MMA_OPER_CTX_STRU              *pstMmaOperCtx   = VOS_NULL_PTR;
    VOS_UINT8                           ucCtxIndex;

    pstMmaOperCtx   = TAF_MMA_GetOperCtxAddr();

    if (VOS_FALSE == TAF_MMA_GetSpecOperTypeIndex(TAF_MMA_OPER_CSG_LIST_SEARCH_REQ, &ucCtxIndex))
    {
        return;
    }

    /* ���CTX������,�����paraǰ��϶������  */
    if (VOS_NULL_PTR != pstMmaOperCtx[ucCtxIndex].pPara)
    {
        PS_MEM_FREE(WUEPS_PID_MMA, pstMmaOperCtx[ucCtxIndex].pPara);
        pstMmaOperCtx[ucCtxIndex].pPara = VOS_NULL_PTR;
    }

    TAF_MMA_ClearOperCtx(ucCtxIndex);

    return;
}

/*****************************************************************************
 �� �� ��  : TAF_MMA_ReportCsgListSearchResult
 ��������  : �б��ѽ���ϱ�
 �������  : pstCtrl         - ������Ϣ
             pstPlmnListCtrl - at csg list������Ϣ
 �������  : ��
 �� �� ֵ  : ��
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2015��9��28��
    ��    ��   : z00161729
    �޸�����   : ֧��LTE CSG��������

*****************************************************************************/
VOS_VOID TAF_MMA_ReportCsgListSearchResult(
    TAF_MMA_CTRL_STRU                  *pstCtrl,
    TAF_MMA_PLMN_LIST_CTRL_STRU        *pstPlmnListCtrl
)
{
    TAF_MMA_CSG_LIST_CNF_PARA_STRU     *pstPlmnListCnfPara = VOS_NULL_PTR;
    TAF_MMA_CSG_LIST_CTX_STRU          *pstCsgListCtx      = VOS_NULL_PTR;
    VOS_UINT32                          ulSendNum;
    VOS_UINT32                          ulLeftNum;
    VOS_UINT32                          ulCurrIndex;
    VOS_UINT32                          ulIndex;
    TAF_PH_OPERATOR_NAME_FORMAT_OP_STRU stAtOperName;

    PS_MEM_SET(&stAtOperName, 0, sizeof(stAtOperName));
    ulSendNum     = 0;
    ulLeftNum     = 0;
    ulCurrIndex   = 0;
    ulIndex       = 0;
    pstCsgListCtx = TAF_MMA_GetCsgListCtxAddr();

    pstPlmnListCnfPara = (TAF_MMA_CSG_LIST_CNF_PARA_STRU *)PS_MEM_ALLOC(WUEPS_PID_MMA, sizeof(TAF_MMA_CSG_LIST_CNF_PARA_STRU));

    if (VOS_NULL_PTR == pstPlmnListCnfPara)
    {
        STA_TRACE(PS_LOG_LEVEL_ERROR,"TAF_MMA_ReportCsgListSearchResult:ERROR:ALLOC MEMORY FAIL.");
        return;
    }

    PS_MEM_SET(pstPlmnListCnfPara, 0, sizeof(TAF_MMA_CSG_LIST_CNF_PARA_STRU));

    pstPlmnListCnfPara->ucOpError          = VOS_FALSE;
    pstPlmnListCnfPara->ulCurrIndex        = pstPlmnListCtrl->usCurrIndex;
    pstPlmnListCnfPara->ucPlmnWithCsgIdNum = 0;

    ulSendNum = pstPlmnListCtrl->usReadNum;

    /* ���Ҫ���ȡ��index���ڵ���csg PLmn list������Ŀ����Ϊ�����һ���ϱ����ϱ�һ�����б� */
    if (pstPlmnListCtrl->usCurrIndex >= (VOS_UINT16)pstCsgListCtx->ulPlmnWithCsgIdNum)
    {
        ulSendNum = 0;
    }
    else
    {
        ulLeftNum = (pstCsgListCtx->ulPlmnWithCsgIdNum - pstPlmnListCtrl->usCurrIndex);

        if (ulSendNum > ulLeftNum)
        {
            ulSendNum = ulLeftNum;
        }
    }

    for (ulIndex = 0; ulIndex < ulSendNum; ulIndex++)
    {
        if (ulIndex >= TAF_MMA_MAX_CSG_ID_LIST_NUM)
        {
            break;
        }

        ulCurrIndex = ulIndex + pstPlmnListCtrl->usCurrIndex;

        pstPlmnListCnfPara->astCsgIdListInfo[ulIndex].stPlmnId.Mcc = pstCsgListCtx->astCsgIdListInfo[ulCurrIndex].stPlmnId.Mcc;
        pstPlmnListCnfPara->astCsgIdListInfo[ulIndex].stPlmnId.Mnc = pstCsgListCtx->astCsgIdListInfo[ulCurrIndex].stPlmnId.Mnc;
        MMA_PlmnId2Bcd(&(pstPlmnListCnfPara->astCsgIdListInfo[ulIndex].stPlmnId));

        pstPlmnListCnfPara->astCsgIdListInfo[ulIndex].ulCsgId = pstCsgListCtx->astCsgIdListInfo[ulCurrIndex].ulCsgId;

        pstPlmnListCnfPara->astCsgIdListInfo[ulIndex].stCsgType.ucCsgTypeLen = pstCsgListCtx->astCsgIdListInfo[ulCurrIndex].stCsgType.ucCsgTypeLen;
        PS_MEM_CPY(pstPlmnListCnfPara->astCsgIdListInfo[ulIndex].stCsgType.aucCsgType, \
                   pstCsgListCtx->astCsgIdListInfo[ulCurrIndex].stCsgType.aucCsgType,  \
                   TAF_SDC_MIN(pstPlmnListCnfPara->astCsgIdListInfo[ulIndex].stCsgType.ucCsgTypeLen, TAF_MMA_MAX_CSG_TYPE_LEN));

        pstPlmnListCnfPara->astCsgIdListInfo[ulIndex].enPlmnWithCsgIdType = pstCsgListCtx->astCsgIdListInfo[ulCurrIndex].enPlmnWithCsgIdType;

        pstPlmnListCnfPara->astCsgIdListInfo[ulIndex].stCsgIdHomeNodeBName.ucHomeNodeBNameLen = pstCsgListCtx->astCsgIdListInfo[ulCurrIndex].stCsgIdHomeNodeBName.ucHomeNodeBNameLen;
        PS_MEM_CPY(pstPlmnListCnfPara->astCsgIdListInfo[ulIndex].stCsgIdHomeNodeBName.aucHomeNodeBName, \
                   pstCsgListCtx->astCsgIdListInfo[ulCurrIndex].stCsgIdHomeNodeBName.aucHomeNodeBName,  \
                   TAF_SDC_MIN(pstPlmnListCnfPara->astCsgIdListInfo[ulIndex].stCsgIdHomeNodeBName.ucHomeNodeBNameLen, TAF_MMA_MAX_HOME_NODEB_NAME_LEN));

        pstPlmnListCnfPara->astCsgIdListInfo[ulIndex].ucRaMode = pstCsgListCtx->astCsgIdListInfo[ulCurrIndex].ucRaMode;

        PS_MEM_SET(&stAtOperName,0,sizeof(stAtOperName));
        stAtOperName.OperName.PlmnId.Mcc  = pstPlmnListCnfPara->astCsgIdListInfo[ulIndex].stPlmnId.Mcc;
        stAtOperName.OperName.PlmnId.Mnc  = pstPlmnListCnfPara->astCsgIdListInfo[ulIndex].stPlmnId.Mnc;
        stAtOperName.ListOp               = TAF_PH_OPER_NAME_PLMN2ALPHANUMERICNAME;

        /* ��ȡ��������ĳ����� */
        if (MMA_SUCCESS == Taf_PhoneGetNetworkNameForListPlmn(&stAtOperName))
        {
            PS_MEM_CPY(pstPlmnListCnfPara->astCsgIdListInfo[ulIndex].aucOperatorNameLong, stAtOperName.OperName.aucOperatorNameLong,TAF_PH_OPER_NAME_LONG);
            PS_MEM_CPY(pstPlmnListCnfPara->astCsgIdListInfo[ulIndex].aucOperatorNameShort, stAtOperName.OperName.aucOperatorNameShort,TAF_PH_OPER_NAME_SHORT);
        }
        else
        {
            pstPlmnListCnfPara->astCsgIdListInfo[ulIndex].aucOperatorNameLong[0]  = '\0';
            pstPlmnListCnfPara->astCsgIdListInfo[ulIndex].aucOperatorNameShort[0] = '\0';
        }

        pstPlmnListCnfPara->ucPlmnWithCsgIdNum++;
    }

    /* �ϱ� */
    TAF_MMA_SndCsgListSearchCnf(pstCtrl, pstPlmnListCnfPara);

    TAF_MMA_ClearCsgListSearchOperCtx();

    PS_MEM_FREE(WUEPS_PID_MMA, pstPlmnListCnfPara);

    return;
}

/*****************************************************************************
 �� �� ��  : TAF_MMA_ReportCsgListError
 ��������  : CSG�б��Ѵ������ϱ�
 �������  : pstCtrl - mma ctrl��Ϣ
             enError - ������
 �������  : ��
 �� �� ֵ  : ��
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2015��9��30��
    ��    ��   : z00161729
    �޸�����   : ֧��LTE CSG��������
*****************************************************************************/
VOS_VOID TAF_MMA_ReportCsgListError(
    TAF_MMA_CTRL_STRU                  *pstCtrl,
    TAF_ERROR_CODE_ENUM_UINT32          enError
)
{
    TAF_MMA_CSG_LIST_CNF_PARA_STRU     *pstPlmnListCnfPara = VOS_NULL_PTR;
    pstPlmnListCnfPara = (TAF_MMA_CSG_LIST_CNF_PARA_STRU *)PS_MEM_ALLOC(WUEPS_PID_MMA, sizeof(TAF_MMA_CSG_LIST_CNF_PARA_STRU));

    if (VOS_NULL_PTR == pstPlmnListCnfPara)
    {
        STA_TRACE(PS_LOG_LEVEL_ERROR, "TAF_MMA_ReportCsgListError:ERROR:ALLOC MEMORY FAIL.");

        return;
    }

    PS_MEM_SET(pstPlmnListCnfPara, 0, sizeof(TAF_MMA_CSG_LIST_CNF_PARA_STRU));

    /* ����CSG LIST���ظ��¼� */
    pstPlmnListCnfPara->ucOpError    = VOS_TRUE;
    pstPlmnListCnfPara->enPhoneError = enError;

    TAF_MMA_SndCsgListSearchCnf(pstCtrl, pstPlmnListCnfPara);

    /* ���csg list����oper ctx */
    TAF_MMA_ClearCsgListSearchOperCtx();

    PS_MEM_FREE(WUEPS_PID_MMA, pstPlmnListCnfPara);

    return;
}
#endif
/*****************************************************************************
 �� �� ��  : TAF_MMA_PlmnListReport
 ��������  : �б��ѽ���ϱ�
 �������  :
 �������  :
 �� �� ֵ  :
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2015��3��6��
    ��    ��   : b00269685
    �޸�����   : �½�����
*****************************************************************************/
VOS_VOID TAF_MMA_PlmnListReport(
    TAF_MMA_PLMN_LIST_CNF_PARA_STRU    *pstPlmnListCnfPara
)
{
    TAF_MMA_OPER_CTX_STRU              *pstMmaOperCtx   = VOS_NULL_PTR;
    VOS_UINT8                           ucCtxIndex;

    pstMmaOperCtx   = TAF_MMA_GetOperCtxAddr();

    if (VOS_FALSE == TAF_MMA_GetSpecOperTypeIndex(TAF_MMA_OPER_PLMN_LIST_REQ, &ucCtxIndex))
    {
        STA_TRACE(PS_LOG_LEVEL_ERROR,"TAF_MMA_PlmnListReport:ERROR: GET CTX FAIL.");
        return;
    }

    /* �ϱ� */
    TAF_MMA_SndPlmnListCnf(&(pstMmaOperCtx[ucCtxIndex].stCtrl), pstPlmnListCnfPara);

    TAF_MMA_PlmnListClearOperCtx();

    return;
}



/*****************************************************************************
 �� �� ��  : TAF_MMA_PlmnListClearOperCtx
 ��������  : �ͷ��б���ʱ�����OperCtx
 �������  : ��
 �������  : ��
 �� �� ֵ  : ��
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2015��4��3��
    ��    ��   : c00318887
    �޸�����   : �½�����
*****************************************************************************/
VOS_VOID TAF_MMA_PlmnListClearOperCtx(VOS_VOID)
{
    TAF_MMA_OPER_CTX_STRU              *pstMmaOperCtx   = VOS_NULL_PTR;
    VOS_UINT8                           ucCtxIndex;

    pstMmaOperCtx   = TAF_MMA_GetOperCtxAddr();

    if (VOS_FALSE == TAF_MMA_GetSpecOperTypeIndex(TAF_MMA_OPER_PLMN_LIST_REQ, &ucCtxIndex))
    {
        STA_TRACE(PS_LOG_LEVEL_ERROR,"TAF_MMA_PlmnListReport:ERROR: GET CTX FAIL.");
        return;
    }

    /* ���CTX������,�����paraǰ��϶������  */
    if (VOS_NULL_PTR != pstMmaOperCtx[ucCtxIndex].pPara)
    {
        PS_MEM_FREE(WUEPS_PID_MMA, pstMmaOperCtx[ucCtxIndex].pPara);
        pstMmaOperCtx[ucCtxIndex].pPara = VOS_NULL_PTR;
    }

    TAF_MMA_ClearOperCtx(ucCtxIndex);

    return;
}


/*****************************************************************************
 �� �� ��  : TAF_MMA_PlmnListErrorReport
 ��������  : �б��Ѵ������ϱ�
 �������  :
 �������  :
 �� �� ֵ  :
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2015��3��6��
    ��    ��   : b00269685
    �޸�����   : �½�����
*****************************************************************************/
VOS_VOID TAF_MMA_PlmnListErrorReport(
    TAF_ERROR_CODE_ENUM_UINT32          enError
)
{
    TAF_MMA_PLMN_LIST_CNF_PARA_STRU    *pstPlmnListCnfPara = VOS_NULL_PTR;

    pstPlmnListCnfPara = (TAF_MMA_PLMN_LIST_CNF_PARA_STRU *)PS_MEM_ALLOC(WUEPS_PID_MMA, sizeof(TAF_MMA_PLMN_LIST_CNF_PARA_STRU));

    if (VOS_NULL_PTR == pstPlmnListCnfPara)
    {
        STA_TRACE(PS_LOG_LEVEL_ERROR, "TAF_MMA_PlmnListErrorReport:ERROR:ALLOC MEMORY FAIL.");

        return;
    }

    PS_MEM_SET(pstPlmnListCnfPara, 0, sizeof(TAF_MMA_PLMN_LIST_CNF_PARA_STRU));

    /* ����LIST�����ظ��¼� */
    pstPlmnListCnfPara->ucOpError    = VOS_TRUE;
    pstPlmnListCnfPara->enPhoneError = enError;

    TAF_MMA_PlmnListReport(pstPlmnListCnfPara);

    PS_MEM_FREE(WUEPS_PID_MMA, pstPlmnListCnfPara);

    return;
}

/*****************************************************************************
 �� �� ��  : TAF_MMA_PlmnListQryAbortReport
 ��������  : �б��Ѵ������ϱ�
 �������  : ulOpID - operation ID
 �������  : ��
 �� �� ֵ  : ��
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2015��3��6��
    ��    ��   : b00269685
    �޸�����   : �½�����
*****************************************************************************/
VOS_VOID TAF_MMA_PlmnListQryAbortReport()
{
    TAF_MMA_PLMN_LIST_CNF_PARA_STRU    *pstPlmnListCnfPara = VOS_NULL_PTR;

    pstPlmnListCnfPara = (TAF_MMA_PLMN_LIST_CNF_PARA_STRU *)PS_MEM_ALLOC(WUEPS_PID_MMA, sizeof(TAF_MMA_PLMN_LIST_CNF_PARA_STRU));

    if (VOS_NULL_PTR == pstPlmnListCnfPara)
    {
        STA_TRACE(PS_LOG_LEVEL_ERROR, "TAF_MMA_PlmnListQryAbortReport:ERROR:ALLOC MEMORY FAIL.");

        return;
    }

    PS_MEM_SET(pstPlmnListCnfPara, 0, sizeof(TAF_MMA_PLMN_LIST_CNF_PARA_STRU));

    /* ���SIM��״̬,LIST�����¼�����ϵ�������п��ظ����б�,�޿��ظ�ERROR */
    if (TAF_ERR_NO_ERROR == MMA_CheckUsimStatusForPlmnSel())
    {
        /* ����LIST�����ظ��¼� */
        pstPlmnListCnfPara->ulPlmnNum    = 0;
        pstPlmnListCnfPara->ucOpError    = VOS_FALSE;

        TAF_MMA_PlmnListReport(pstPlmnListCnfPara);

        PS_MEM_FREE(WUEPS_PID_MMA, pstPlmnListCnfPara);

        return;
    }

    pstPlmnListCnfPara->ucOpError    = VOS_TRUE;
    pstPlmnListCnfPara->enPhoneError = TAF_ERR_USIM_SIM_CARD_NOTEXIST;

    /* �ϱ� */
    TAF_MMA_PlmnListReport(pstPlmnListCnfPara);

    PS_MEM_FREE(WUEPS_PID_MMA, pstPlmnListCnfPara);

    return;
}

/*****************************************************************************
 �� �� ��  : Sta_PlmnListEventReport
 ��������  : �б��ѽ���ϱ�
 �������  :
 �������  :
 �� �� ֵ  :
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2011��11��5��
    ��    ��   : c00173809
    �޸�����   : AT�ں���Ŀ���б��ѽ���ϱ���A��
  2.��    ��   : 2015��3��6��
    ��    ��   : b00269685
    �޸�����   : ��Ϊ�ֶ��ϱ�
*****************************************************************************/

VOS_VOID Sta_PlmnListEventReport(VOS_VOID)
{
    TAF_MMA_PLMN_LIST_CNF_PARA_STRU    *pstPlmnListCnfPara = VOS_NULL_PTR;
    TAF_MMA_OPER_CTX_STRU              *pstMmaOperCtx      = VOS_NULL_PTR;
    TAF_MMA_PLMN_LIST_CTRL_STRU        *pstPlmnListCtrl    = VOS_NULL_PTR;
    VOS_UINT8                           ucSendNum;
    VOS_UINT8                           ucLeftNum;
    VOS_UINT8                           ucCurrIndex;
    VOS_UINT8                           ucCtxIndex;
    VOS_UINT32                          ulIndex;
    TAF_PH_OPERATOR_NAME_FORMAT_OP_STRU stAtOperName;

    PS_MEM_SET(&stAtOperName, 0, sizeof(stAtOperName));
    ucSendNum   = 0;
    ucLeftNum   = 0;
    ucCurrIndex = 0;
    ulIndex     = 0;
    pstMmaOperCtx = TAF_MMA_GetOperCtxAddr();


    if (VOS_FALSE == TAF_MMA_GetSpecOperTypeIndex(TAF_MMA_OPER_PLMN_LIST_REQ, &ucCtxIndex))
    {
        STA_TRACE(PS_LOG_LEVEL_ERROR,"Sta_PlmnListEventReport:ERROR: GET CTX FAIL.");
        return;
    }

    pstPlmnListCtrl = (TAF_MMA_PLMN_LIST_CTRL_STRU *)pstMmaOperCtx[ucCtxIndex].pPara;

    pstPlmnListCnfPara = (TAF_MMA_PLMN_LIST_CNF_PARA_STRU *)PS_MEM_ALLOC(WUEPS_PID_MMA, sizeof(TAF_MMA_PLMN_LIST_CNF_PARA_STRU));

    if (VOS_NULL_PTR == pstPlmnListCnfPara)
    {
        STA_TRACE(PS_LOG_LEVEL_ERROR,"Sta_PlmnListEventReport:ERROR:ALLOC MEMORY FAIL.");
        return;
    }

    PS_MEM_SET(pstPlmnListCnfPara, 0, sizeof(TAF_MMA_PLMN_LIST_CNF_PARA_STRU));

    pstPlmnListCnfPara->ucOpError    = VOS_FALSE;
    pstPlmnListCnfPara->ulCurrIndex  = pstPlmnListCtrl->usCurrIndex;
    pstPlmnListCnfPara->ulPlmnNum    = 0;

    ucSendNum = (VOS_UINT8)pstPlmnListCtrl->usReadNum;

    /* ���Ҫ���ȡ��index���ڵ���PLmn list������Ŀ����Ϊ�����һ���ϱ����ϱ�һ�����б� */
    if (pstPlmnListCtrl->usCurrIndex >= (VOS_UINT16)g_StatusContext.PlmnList.ucPlmnNum)
    {
        ucSendNum = 0;
    }
    else
    {
        ucLeftNum = (g_StatusContext.PlmnList.ucPlmnNum - (VOS_UINT8)pstPlmnListCtrl->usCurrIndex);

        if (ucSendNum > ucLeftNum)
        {
            ucSendNum = ucLeftNum;
        }
    }

    for (ulIndex = 0; ulIndex < ucSendNum; ulIndex++)
    {
        if (ulIndex >= TAF_MMA_MAX_PLMN_NAME_LIST_NUM)
        {
            break;
        }

        ucCurrIndex = (VOS_UINT8)ulIndex + (VOS_UINT8)pstPlmnListCtrl->usCurrIndex;

        pstPlmnListCnfPara->astPlmnName[ulIndex].PlmnId.Mcc = g_StatusContext.PlmnList.Plmn[ucCurrIndex].Mcc;
        pstPlmnListCnfPara->astPlmnName[ulIndex].PlmnId.Mnc = g_StatusContext.PlmnList.Plmn[ucCurrIndex].Mnc;
        MMA_PlmnId2Bcd(&(pstPlmnListCnfPara->astPlmnName[ulIndex].PlmnId));
        pstPlmnListCnfPara->astPlmnInfo[ulIndex].PlmnStatus = g_StatusContext.PlmnList.PlmnInfo[ucCurrIndex].PlmnStatus;
        pstPlmnListCnfPara->astPlmnInfo[ulIndex].RaMode     = g_StatusContext.PlmnList.PlmnInfo[ucCurrIndex].RaMode;

        PS_MEM_SET(&stAtOperName,0,sizeof(stAtOperName));
        stAtOperName.OperName.PlmnId.Mcc  = pstPlmnListCnfPara->astPlmnName[ulIndex].PlmnId.Mcc;
        stAtOperName.OperName.PlmnId.Mnc  = pstPlmnListCnfPara->astPlmnName[ulIndex].PlmnId.Mnc;
        stAtOperName.ListOp               = TAF_PH_OPER_NAME_PLMN2ALPHANUMERICNAME;

        /* ��ȡ��������ĳ����� */
        if (MMA_SUCCESS == Taf_PhoneGetNetworkNameForListPlmn(&stAtOperName))
        {
            PS_MEM_CPY(pstPlmnListCnfPara->astPlmnName[ulIndex].aucOperatorNameLong, stAtOperName.OperName.aucOperatorNameLong,TAF_PH_OPER_NAME_LONG);
            PS_MEM_CPY(pstPlmnListCnfPara->astPlmnName[ulIndex].aucOperatorNameShort, stAtOperName.OperName.aucOperatorNameShort,TAF_PH_OPER_NAME_SHORT);
        }
        else
        {
            pstPlmnListCnfPara->astPlmnName[ulIndex].aucOperatorNameLong[0]  = '\0';
            pstPlmnListCnfPara->astPlmnName[ulIndex].aucOperatorNameShort[0] = '\0';
        }

        pstPlmnListCnfPara->ulPlmnNum++;
    }

    TAF_MMA_PlmnListReport(pstPlmnListCnfPara);

    PS_MEM_FREE(WUEPS_PID_MMA, pstPlmnListCnfPara);

    return;
}

/*************************************************
  Function:
    Sta_PlmnListInd
  Description:
    ����MSCC_PLMN_LIST_IND��Ϣ
  Calls:                 �����������õĺ����嵥
  Called By:             ���ñ������ĺ����嵥
  Input:
    ST_MSCC_PLMN_LIST_IND    *pPlmnListInd; ��������ṹָ��
  Output:
    ��
  Return:
    STA_SUCCESS         =0, ��������
    STA_ERROR           =1, ���󷵻�
  Others:

  1.��    ��   : 2006��3��27��
    ��    ��   : liuyang id:48197
    �޸�����   : ���ⵥ�ţ�A32D02372
  2.��    ��   : 2009��01��05��
    ��    ��   : l00130025
    �޸�����   : �������ⵥAT2D07968,˫ģ�б��������,����״̬�жϺ��������
  3.��    ��   : 2012��4��11��
    ��    ��   : l00130025
    �޸�����   : DTS2012032600471,��ʱ��ֹͣ����û�й��������������ⶨλ
  4.��    ��   : 2012��8��10��
    ��    ��   : y00213812
    �޸�����   : DTS2012082204471, TQE����
  5.��    ��   : 2013��4��2��
    ��    ��   : z00161729
    �޸�����   : �����ϱ�AT�������������C�˼�mma��mscc�ӿڵ���
  6.��    ��   : 2012��07��15��
    ��    ��   : w00176964
    �޸�����   : VoLTE_PhaseI��Ŀ�޸�:�޸ĺ��������ͷ���ֵ
*************************************************/
VOS_UINT32 Sta_PlmnListInd(
    VOS_UINT32                          ulEventType,
    struct MsgCB                       *pstMsg
)
{
    /* Added by w00176964 for VoLTE_PhaseI��Ŀ, 2013-7-15, begin */
    MSCC_MMA_PLMN_LIST_CNF_STRU         *pPlmnListInd = VOS_NULL_PTR;
    VOS_UINT32                          ulRet;
    VOS_UINT8                           n;          /* ѭ������ */

    pPlmnListInd = (MSCC_MMA_PLMN_LIST_CNF_STRU*)pstMsg;
    /* Added by w00176964 for VoLTE_PhaseI��Ŀ, 2013-7-15, end */

    /* ϵͳ״̬ */
    switch ( g_StatusContext.ulFsmState )
    {
        case  STA_FSM_PLMN_LIST:
            /* �ر�״̬��ʱ�� */

            ulRet = NAS_StopRelTimer(WUEPS_PID_MMA,
                                     g_StatusContext.aFsmSub[0].TimerName,
                                     &g_StatusContext.ahStaTimer[0]);

            if ( VOS_OK != ulRet )
            {
                STA_TRACE (STA_WARNING_PRINT,
                    "Sta_PlmnListInd():WARNING:NAS_StopRelTimer failed");
            }
            g_StatusContext.ahStaTimer[0] = 0;

            /* ���������� */
            for ( n = 0; n < pPlmnListInd->ulCnt; n++ )
            {
                g_StatusContext.PlmnList.Plmn[n].Mcc
                    = pPlmnListInd->aPlmnList[n].ulMcc;
                g_StatusContext.PlmnList.Plmn[n].Mnc
                    = pPlmnListInd->aPlmnList[n].ulMnc;
                /*����ÿ��PLMN��״̬�ͽ���ģʽ*/
                g_StatusContext.PlmnList.PlmnInfo[n].PlmnStatus
                    = pPlmnListInd->aucPlmnStatus[n];
                g_StatusContext.PlmnList.PlmnInfo[n].RaMode
                    = pPlmnListInd->aucRaMode[n];
            }
            g_StatusContext.PlmnList.ucPlmnNum = (VOS_UINT8)pPlmnListInd->ulCnt;

            /*���ϱ���PLMN�б����е��� */
            Sta_ReOrderPlmnList(&g_StatusContext.PlmnList);
            /* ��APP�ϱ��¼�*/
            g_StatusContext.ucOperateType = STA_OP_PLMNLIST;

            /* �б��ѻظ����ͨ��ר�е��¼��ظ� */
            Sta_PlmnListEventReport();
            break;

        case  STA_FSM_PLMN_RESEL:

            /* Modified by w00176964 for VoLTE_PhaseI��Ŀ, 2013-7-15, begin */
            return VOS_TRUE;
            /* Modified by w00176964 for VoLTE_PhaseI��Ŀ, 2013-7-15, end */
        case STA_FSM_ENABLE:
            /*ֱ���ϱ��б�*/
            for ( n = 0; n < pPlmnListInd->ulCnt; n++ )
            {
                g_StatusContext.PlmnList.Plmn[n].Mcc
                    = pPlmnListInd->aPlmnList[n].ulMcc;
                g_StatusContext.PlmnList.Plmn[n].Mnc
                    = pPlmnListInd->aPlmnList[n].ulMnc;
                /*����ÿ��PLMN��״̬�ͽ���ģʽ*/
                g_StatusContext.PlmnList.PlmnInfo[n].PlmnStatus
                    = pPlmnListInd->aucPlmnStatus[n];
                g_StatusContext.PlmnList.PlmnInfo[n].RaMode
                    = pPlmnListInd->aucRaMode[n];
            }
            g_StatusContext.PlmnList.ucPlmnNum = (VOS_UINT8)pPlmnListInd->ulCnt;
            /*Ӧ���ϱ�plmn�б�*/
            g_StatusContext.ucOperateType = STA_OP_PLMNLIST
                                           |STA_OP_PLMNRESELMODE;
            Sta_EventReport (g_StatusContext.ulCurOpId,
                             TAF_PH_EVT_PLMN_LIST_IND);

            /* Modified by w00176964 for VoLTE_PhaseI��Ŀ, 2013-7-15, begin */
            return VOS_TRUE;
            /* Modified by w00176964 for VoLTE_PhaseI��Ŀ, 2013-7-15, end */
        default :
            /* do nothing */
            STA_TRACE (STA_WARNING_PRINT,
                "Sta_PlmnListInd():WARNING:invalid state, do nothing");

            /* Modified by w00176964 for VoLTE_PhaseI��Ŀ, 2013-7-15, begin */
            return VOS_TRUE;
            /* Modified by w00176964 for VoLTE_PhaseI��Ŀ, 2013-7-15, end */
    }

    /*�����״̬*/
    /*modified by Y00213812 for DTS2012082204471 TQE����, 2012-08-10, begin*/
    ulRet = Sta_UpdateFsmFlag(STA_FSMSUB_NULL, STA_FSM_ENABLE, STA_UPDATE_MONO_CLEAR);
    if (STA_ERROR == ulRet)
    {
        STA_TRACE(STA_WARNING_PRINT, "Sta_PlmnListInd():WARNING:Sta_UpdateFsmFlag failed\n");
    }
    /*modified by Y00213812 for DTS2012082204471 TQE����, 2012-08-10, end*/
    /* Modified by w00176964 for VoLTE_PhaseI��Ŀ, 2013-7-15, begin */
    return VOS_TRUE;
    /* Modified by w00176964 for VoLTE_PhaseI��Ŀ, 2013-7-15, end */
}

/*****************************************************************************
 �� �� ��  : TAF_MMA_ProcGULCoverageAreaInd
 ��������  : ����GULģʽ��ϵͳ��Ϣ�ϱ�
 �������  : MSCC_MMA_3GPP_SYS_INFO_IND_STRU *pMsg
 �������  : ��
 �� �� ֵ  : VOS_VOID
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2015��5��26��
    ��    ��   : w00242748
    �޸�����   : CDMA Iteration 15 modified:��MMA�յ�������Ϣ�ĺ��������GUL��CLģʽ��������
*****************************************************************************/
VOS_VOID TAF_MMA_Proc3gppCoverageAreaIndInGulMode(
    MSCC_MMA_COVERAGE_AREA_IND_STRU    *pstCoverageAreaInd
)
{
    STA_PHONE_DATA_S                                        Update;         /* ��Ҫ���µ�ȫ������ */
    VOS_UINT32                                              ulRet;
    /* Added by w00176964 for VoLTE_PhaseI��Ŀ, 2013-7-15, begin */

    TAF_SDC_SYS_MODE_ENUM_UINT8                             ucSysMode;
    TAF_SDC_SYS_SUBMODE_ENUM_UINT8                          ucSysSubmode;

#if (FEATURE_MULTI_MODEM == FEATURE_ON)
    MMA_MTC_CURR_CAMP_PLMN_INFO_IND_STRU                    stSndMtcPlmnInfo;
#endif

    /* Added by w00176964 for VoLTE_PhaseI��Ŀ, 2013-7-15, end */

#if (FEATURE_ON == FEATURE_DSDS)
    if (VOS_FALSE == TAF_SDC_Get3GppRfAvailFlag())
    {
        return;
    }
#endif

    g_StatusContext.ulTimMaxFlg = pstCoverageAreaInd->ulTimMaxFlg;

    if (NAS_MSCC_PIF_COVERAGE_AREA_CHANGE_MODE_LOST == pstCoverageAreaInd->enCoverageChgMode)
    {
        /* Added by y00245242 for VoLTE_PhaseII ��Ŀ, 2013-10-11, begin */
        TAF_SDC_SetCampOnFlag(VOS_FALSE);
        /* Added by y00245242 for VoLTE_PhaseII ��Ŀ, 2013-10-11, end */

        TAF_MMA_SndMtaAreaLostInd();

#if (FEATURE_MULTI_MODEM == FEATURE_ON)
        if (VOS_TRUE == TAF_SDC_GetUtranSkipWPlmnSearchFlag())
        {
            PS_MEM_SET(&stSndMtcPlmnInfo, 0, sizeof(stSndMtcPlmnInfo));
            stSndMtcPlmnInfo.enRatMode             = MTC_RATMODE_BUTT;
            stSndMtcPlmnInfo.ucIsForbiddenPlmnFlag = VOS_FALSE;
            stSndMtcPlmnInfo.ucPsAttachAllowFlag   = TAF_SDC_GetPsAttachAllowFlg();
            stSndMtcPlmnInfo.stPlmnId.ulMcc        = TAF_SDC_INVALID_MCC;
            stSndMtcPlmnInfo.stPlmnId.ulMnc        = TAF_SDC_INVALID_MCC;
            TAF_MMA_SndMtcCurrCampPlmnInfoInd(&stSndMtcPlmnInfo);
        }
#endif

        ucSysMode = TAF_SDC_GetSysMode();
        ucSysSubmode = TAF_SDC_GetSysSubMode();
        if ((TAF_SDC_SYS_MODE_BUTT    != ucSysMode)
         || (TAF_SDC_SYS_SUBMODE_NONE != ucSysSubmode)){
            Mma_ModeChgReport(TAF_SDC_SYS_MODE_BUTT, TAF_SYS_SUBMODE_NONE);
            TAF_SDC_SetSysMode(TAF_SDC_SYS_MODE_BUTT);
            TAF_SDC_SetSysSubMode(TAF_SYS_SUBMODE_NONE);
        }
    }

    switch ( g_StatusContext.ulFsmState )
    {
        case  STA_FSM_ENABLE :
            /*����������ʱ��MSCC������MMA����service status ind��ָʾCS/PS����״̬
              �Լ�PLMNID�����ɾ���������*/
            /* Modified by w00176964 for VoLTE_PhaseI��Ŀ, 2013-7-15, begin */
            return;
            /* Modified by w00176964 for VoLTE_PhaseI��Ŀ, 2013-7-15, end */

        case  STA_FSM_PLMN_RESEL: /* PLMN_RESEL״̬ */
            /* ��״̬Ϊ�Զ���ѡģʽ*/
            if ( STA_FSMSUB_PLMN_RESEL_AUTO
                == g_StatusContext.aFsmSub[0].ucFsmStateSub )
            {
                /* ����Ϊ���븲����*/
                if ( NAS_MSCC_PIF_COVERAGE_AREA_CHANGE_MODE_ENTER == pstCoverageAreaInd->enCoverageChgMode )
                { /* PLMNפ���� */
                    /* do nothing */
                    STA_TRACE (STA_NORMAL_PRINT,
                                "Sta_CoverageAreaInd():NORMAL:resident PLMN indicator,\
                                do nothing");
                    /* Modified by w00176964 for VoLTE_PhaseI��Ŀ, 2013-7-15, begin */
                    return;
                    /* Modified by w00176964 for VoLTE_PhaseI��Ŀ, 2013-7-15, end */
                }
                else /* ��������*/
                {
                    /* �ر�PLMN_RESEL״̬��ʱ��*/
                    if ( 0 != g_StatusContext.ahStaTimer[0] )
                    {
                        ulRet = NAS_StopRelTimer(WUEPS_PID_MMA,
                                                 g_StatusContext.aFsmSub[0].TimerName,
                                                 &g_StatusContext.ahStaTimer[0]);


                        if ( VOS_OK != ulRet )
                        {
                            STA_TRACE (STA_WARNING_PRINT,
                                        "Sta_CoverageAreaInd():WARNING:\
                                        NAS_StopRelTimer failed");
                        }
                        g_StatusContext.ahStaTimer[0] = 0;
                    }

                    /* ���������� */
                    Update.ulCsServiceStatus = pstCoverageAreaInd->enCsSvcSta;
                    Update.ulPsServiceStatus = pstCoverageAreaInd->enPsSvcSta;

                    /* Modified by z00161729 for �����ϱ�AT�������������C��, 2013-4-7, begin */
                    Update.ulCsCause         = NAS_MSCC_PIF_CAUSE_NULL;
                    Update.ulPsCause         = NAS_MSCC_PIF_CAUSE_NULL;
                    /* Modified by z00161729 for �����ϱ�AT�������������C��, 2013-4-7, end */

                    Update.ucFsmSubOperate   = STA_FSMSUB_FINISH;
                    Update.ulFsmState        = STA_FSM_ENABLE;
                    Update.ucFsmStateSub     = STA_FSMSUB_NULL;
                    Update.ucFsmUpdateFlag   = STA_UPDATE_MONO_CLEAR;
                    ulRet = Sta_UpdateData (&Update);
                    if ( STA_ERROR == ulRet )
                    {
                        STA_TRACE (STA_WARNING_PRINT,
                                    "Sta_CoverageAreaInd():WARNING:\
                                    Sta_UpdateData failed");
                    }

                    /* ��APP�ϱ��¼�*/
                    g_StatusContext.ucOperateType = STA_OP_CSSERVICESTATUS
                        |STA_OP_PSSERVICESTATUS|STA_OP_PLMNRESELMODE;
                    TAF_MMA_ProcPlmnAutoReselCnf(TAF_ERR_NO_ERROR);
                }
                /* Modified by w00176964 for VoLTE_PhaseI��Ŀ, 2013-7-15, begin */
                return;
                /* Modified by w00176964 for VoLTE_PhaseI��Ŀ, 2013-7-15, end */
            }/* ���� ��״̬Ϊ�Զ���ѡģʽ */

            /* ��״̬Ϊ�ֶ���ѡģʽ */
            if ( STA_FSMSUB_PLMN_RESEL_MANUAL
                == g_StatusContext.aFsmSub[0].ucFsmStateSub )
            {
                /* ����Ϊ��������*/
                if ( NAS_MSCC_PIF_COVERAGE_AREA_CHANGE_MODE_LOST == pstCoverageAreaInd->enCoverageChgMode )
                {
                    /* �ر�PLMN_RESEL״̬��ʱ��*/
                    if ( 0 != g_StatusContext.ahStaTimer[0] )
                    {
                        ulRet = NAS_StopRelTimer(WUEPS_PID_MMA,
                                                 g_StatusContext.aFsmSub[0].TimerName,
                                                 &g_StatusContext.ahStaTimer[0]);


                        if ( VOS_OK != ulRet )
                        {
                            STA_TRACE (STA_WARNING_PRINT,
                                "Sta_CoverageAreaInd():WARNING:\
                                NAS_StopRelTimer failed  ");
                        }
                        g_StatusContext.ahStaTimer[0] = 0;
                    }

                    /* ���������� */
                    Update.ulCsServiceStatus = pstCoverageAreaInd->enCsSvcSta;
                    Update.ulPsServiceStatus = pstCoverageAreaInd->enPsSvcSta;

                    /* Modified by z00161729 for �����ϱ�AT�������������C��, 2013-4-7, begin */
                    Update.ulCsCause         = NAS_MSCC_PIF_CAUSE_NULL;
                    Update.ulPsCause         = NAS_MSCC_PIF_CAUSE_NULL;
                    /* Modified by z00161729 for �����ϱ�AT�������������C��, 2013-4-7, end */

                    Update.ucFsmSubOperate   = STA_FSMSUB_FINISH;
                    Update.ulFsmState        = STA_FSM_ENABLE;
                    Update.ucFsmStateSub     = STA_FSMSUB_NULL;
                    Update.ucFsmUpdateFlag   = STA_UPDATE_MONO_CLEAR;
                    ulRet = Sta_UpdateData (&Update);
                    if ( STA_ERROR == ulRet )
                    {
                        STA_TRACE (STA_WARNING_PRINT,
                            "Sta_CoverageAreaInd():WARNING:Sta_UpdateData failed  ");
                    }

                    /* ��APP�ϱ��¼�*/
                    TAF_MMA_ProcPlmnAutoReselCnf(TAF_ERR_NO_ERROR);
                }
                /* Modified by w00176964 for VoLTE_PhaseI��Ŀ, 2013-7-15, begin */
                return;
                /* Modified by w00176964 for VoLTE_PhaseI��Ŀ, 2013-7-15, end */
            }
            /* Modified by w00176964 for VoLTE_PhaseI��Ŀ, 2013-7-15, begin */
            return;
            /* Modified by w00176964 for VoLTE_PhaseI��Ŀ, 2013-7-15, end */

        /* Modified by z00161729 for �����ϱ�AT�������������C��, 2013-4-2, end */
        case  STA_FSM_PLMN_SEL:  /* PLMN_SEL״̬ */
            /* ����Ϊ���븲����*/
            /* ɾ��֮ǰ������ı�������,Ŀǰ�û�ָ������ʱ,MSCC�����ϱ�ָ���������
               ����˴����б��� */
            /* Modified by w00176964 for VoLTE_PhaseI��Ŀ, 2013-7-15, begin */
            return;
            /* Modified by w00176964 for VoLTE_PhaseI��Ŀ, 2013-7-15, end */

        default:
            STA_TRACE (STA_WARNING_PRINT,
                "Sta_CoverageAreaInd():WARNING:invalid state, do nothing  ");
            /* Modified by w00176964 for VoLTE_PhaseI��Ŀ, 2013-7-15, begin */
            return;
            /* Modified by w00176964 for VoLTE_PhaseI��Ŀ, 2013-7-15, end */
    }
}
#if (FEATURE_ON == FEATURE_UE_MODE_CDMA)

/*****************************************************************************
 �� �� ��  : TAF_MMA_ProcCLCoverageAreaInd
 ��������  : ����GULģʽ��ϵͳ��Ϣ�ϱ�
 �������  : MSCC_MMA_3GPP_SYS_INFO_IND_STRU *pMsg
 �������  : ��
 �� �� ֵ  : VOS_VOID
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2015��5��26��
    ��    ��   : w00242748
    �޸�����   : CDMA Iteration 15 modified:��MMA�յ�������Ϣ�ĺ��������GUL��CLģʽ��������
*****************************************************************************/
VOS_UINT32 TAF_MMA_Proc3gppCoverageAreaIndInClMode(
    MSCC_MMA_COVERAGE_AREA_IND_STRU    *pstCoverageAreaInd
)
{
    TAF_SDC_SYS_MODE_ENUM_UINT8                             enSysMode;
    TAF_SYS_SUBMODE_ENUM_UINT8                              enSubMode;
    pTafSdcSysmodServiceRegStaUpdateFunc                    pFuncUpdateSysModSrvRegSta;

    TAF_SDC_SRV_REG_INFO_STRU                               stSrvRegInfo;
    PS_MEM_SET(&stSrvRegInfo, 0x00, sizeof(stSrvRegInfo));

    /* ����״̬��ʱ��ά�ɲ� */
    TAF_MMA_LogCLDelayRptSrvStatusCtx(TAF_MMA_LOG_CL_DELAY_REPORT_CTX_TYPE_ENTER);

    pFuncUpdateSysModSrvRegSta          = VOS_NULL_PTR;
    enSysMode                           = TAF_SDC_SYS_MODE_BUTT;
    enSubMode                           = TAF_SDC_SYS_SUBMODE_BUTT;

    if (VOS_FALSE == TAF_SDC_Get3GppRfAvailFlag())
    {
        return VOS_TRUE;
    }

    if (NAS_MSCC_PIF_COVERAGE_AREA_CHANGE_MODE_LOST == pstCoverageAreaInd->enCoverageChgMode)
    {
        TAF_SDC_SetCampOnFlag(VOS_FALSE);

        TAF_MMA_SndMtaAreaLostInd();

        /* todo conver to network existance */
        TAF_MMA_MapCdmaNetworkExistanceSrvStaToSysMode(TAF_SDC_LTE_NETWORK_NOT_EXIST,
                                                       &enSysMode,
                                                       &enSubMode,
                                                       &pFuncUpdateSysModSrvRegSta);

        /* ִ�и��·���״̬��ע��״̬���� */
        if (VOS_NULL_PTR != pFuncUpdateSysModSrvRegSta)
        {
            pFuncUpdateSysModSrvRegSta(&stSrvRegInfo);

            /* �жϷ���״̬��ע��״̬�Ƿ�仯���仯�Ļ������ϱ� */
            TAF_MMA_UpdateSrvRegSta_Main(&stSrvRegInfo, TAF_PH_ACCESS_TECH_E_UTRAN);
        }

    }

    TAF_MMA_LogCLDelayRptSrvStatusCtx(TAF_MMA_LOG_CL_DELAY_REPORT_CTX_TYPE_EXIT);

    return VOS_TRUE;
}
#endif

/*************************************************
  Function:
    Sta_CoverageAreaInd
  Description:
    ����MSCC_COVERAGE_AREA_IND��Ϣ
  Calls:             �����������õĺ����嵥
  Called By:         ���ñ������ĺ����嵥
  Input:
    ST_MSCC_COVERAGE_AREA_IND *pCoverageAreaInd; ��������ṹָ��
  Output:
    ��
  Return:
    STA_SUCCESS     =0, ��������
    STA_ERROR       =1, ���󷵻�
  Others:
    author:   l48197 2005-10-21
    modified:
        ��attach,detach�������յ�service_status_ind��ֱ�ӷ��أ�
        enable״̬�£�����ǰ��״̬����

  2.��    ��   : 2006��3��30��
    ��    ��   : liuyang id: 48197
    �޸�����   : ���ⵥ�ţ�A32D02372
  3.��    ��   : 2009��01��14��
    ��    ��   : l65478
    �޸�����   : ���ⵥ�ţ�AT2D07971,������״̬���ϱ��Ľ��뼼������
  4.��    ��   : 2012��4��11��
    ��    ��   : l00130025
    �޸�����   : DTS2012032600471,��ʱ��ֹͣ����û�й��������������ⶨλ
  5.��    ��   : 2012��12��13��
    ��    ��   : w00176964
    �޸�����   : DTS2012111204234:U��ָ������������,�û�ָ������,MMA�յ�MSCC��
                 ��������ָʾ,��ǰ��������ʧ��
  6.��    ��   : 2013��4��2��
    ��    ��   : z00161729
    �޸�����   : �����ϱ�AT�������������C�˼�mma��mscc�ӿڵ���
  7.��    ��   : 2012��07��15��
    ��    ��   : w00176964
    �޸�����   : VoLTE_PhaseI��Ŀ�޸�:�޸ĺ��������ͷ���ֵ
  8.��    ��   : 2013��11��22��
    ��    ��   : z00161729
    �޸�����   : SVLTE�Ż�G-TL ps�л������޸�
  9.��    ��   : 2014��05��31��
    ��    ��   : s00246516
    �޸�����   : ·�������¹����г�������������л����Detach��û�лظ�
 10.��    ��   : 2014��6��16��
    ��    ��   : w00167002
    �޸�����   : ����no rf��־����ֱ�Ӳ�����
*************************************************/
VOS_UINT32 Sta_CoverageAreaInd(
    VOS_UINT32                          ulEventType,
    struct MsgCB                       *pstMsg
)
{
    MSCC_MMA_COVERAGE_AREA_IND_STRU    *pstCoverageAreaInd = VOS_NULL_PTR;

    pstCoverageAreaInd = (MSCC_MMA_COVERAGE_AREA_IND_STRU*)pstMsg;

#if (FEATURE_ON == FEATURE_UE_MODE_CDMA)
    if (VOS_TRUE == TAF_SDC_IsConfigCLMode())
    {
        TAF_MMA_Proc3gppCoverageAreaIndInClMode(pstCoverageAreaInd);
    }
    else
#endif
    {
        TAF_MMA_Proc3gppCoverageAreaIndInGulMode(pstCoverageAreaInd);
    }

    return VOS_TRUE;
}


/*****************************************************************************
 �� �� ��  : TAF_MMA_ReportSpecPlmnSrchResult
 ��������  : ���������Ľ��֪ͨ�û�
 �������  : VOS_UINT32                  ulResult
 �������  : ��
 �� �� ֵ  : VOS_VOID
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2011��3��7��
    ��    ��   : l65478
    �޸�����   : �����ɺ���
  2.��    ��   : 2011��11��15��
    ��    ��   : ��ӳ��/f62575
    �޸�����   : E5�꿪�ش򿪺��������
  3.��    ��   : 2013��4��7��
    ��    ��   : z00161729
    �޸�����   : �����ϱ�AT�������������C�˼�mma��mscc�ӿڵ���
*****************************************************************************/
VOS_VOID TAF_MMA_ReportSpecPlmnSrchResult(
    VOS_UINT32                  ulResult
)
{
    /* Modified by z00161729 for �����ϱ�AT�������������C��, 2013-4-4, begin */
    if ( NAS_MSCC_PIF_USER_PLMN_SEARCH_RESULT_SUCCESS == ulResult )
    /* Modified by z00161729 for �����ϱ�AT�������������C��, 2013-4-4, end */
    {
        /* �ϱ���ǰָ�������ɹ� */
        if(STA_FSM_PLMN_SEL == g_StatusContext.ulFsmState)
        {
            /* �����ϱ��¼����ͣ����ϱ�APP�����ɹ� */
            TAF_MMA_ProcPlmnSpecialSelCnf(TAF_ERR_NO_ERROR);
        }
        else
        {
        }
    }
    else
    {
        /* �ϱ���ǰָ������ʧ�� */
        /* �ϱ�APP��ǰ״̬�¼� */
        if(STA_FSM_PLMN_SEL == g_StatusContext.ulFsmState)
        {
            /* �ϱ�APP��ǰ״̬�¼� */
            TAF_MMA_ProcPlmnSpecialSelCnf(TAF_ERR_NO_NETWORK_SERVICE);

            STA_TRACE(STA_NORMAL_PRINT, "TAF_MMA_ReportSpecPlmnSrchResult: TAF_PH_EVT_PLMN_SEL_CNF reported to AT!");
        }
        else
        {
        }
    }
}
/*****************************************************************************
 �� �� ��  : TAF_MMA_ReportAutoPlmnSrchResult
 ��������  : ���������Ľ��֪ͨ�û�
 �������  : VOS_UINT32                  ulResult
 �������  : ��
 �� �� ֵ  : VOS_VOID
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2011��3��7��
    ��    ��   : l65478
    �޸�����   : �����ɺ���
  2.��    ��   : 2011��11��15��
    ��    ��   : ��ӳ��/f62575
    �޸�����   : E5�꿪�ش򿪺��������
  3.��    ��   : 2013��4��7��
    ��    ��   : z00161729
    �޸�����   : �����ϱ�AT�������������C�˼�mma��mscc�ӿڵ���
*****************************************************************************/
VOS_VOID TAF_MMA_ReportAutoPlmnSrchResult(
    VOS_UINT32                  ulResult
)
{
    /* Modified by z00161729 for �����ϱ�AT�������������C��, 2013-4-4, begin */
    if ( NAS_MSCC_PIF_USER_PLMN_SEARCH_RESULT_SUCCESS == ulResult )
    /* Modified by z00161729 for �����ϱ�AT�������������C��, 2013-4-4, end */
    {
        /* �ϱ���ǰauto�����ɹ� */
        if (STA_FSM_PLMN_RESEL == g_StatusContext.ulFsmState)
        {
            /* �ϱ�APP��ǰ״̬�¼� */
            TAF_MMA_ProcPlmnAutoReselCnf(TAF_ERR_NO_ERROR);
            STA_TRACE(STA_NORMAL_PRINT, "TAF_MMA_ReportAutoPlmnSrchResult: TAF_PH_EVT_PLMN_RESEL_CNF reported to AT!");
        }
        else
        {
        }
    }
    else
    {
        /* �ϱ���ǰauto����ʧ�� */
        MMA_NORMAILLOG("TAF_MMA_ReportAutoPlmnSrchResult():NORMAIL:SPECIALIZE THE PLMN FAILURE!");
        /* �ϱ�APP��ǰ״̬�¼� */
        if (STA_FSM_PLMN_RESEL == g_StatusContext.ulFsmState)
        {
            /* �ϱ�APP��ǰ״̬�¼� */
            TAF_MMA_ProcPlmnAutoReselCnf(TAF_ERR_NO_NETWORK_SERVICE);
            STA_TRACE(STA_NORMAL_PRINT, "TAF_MMA_ReportAutoPlmnSrchResult: TAF_PH_EVT_PLMN_RESEL_CNF reported to AT!");
        }
        else
        {
        }
    }
}

/*************************************************
  Function:
    Sta_PlmnListRej
  Description:
    ����MSCC_PLMN_LIST_REJ��Ϣ
  Calls:             �����������õĺ����嵥
  Called By:         ���ñ������ĺ����嵥
  Input:
    ST_MSCC_PLMN_LIST_REJ *pPlmnListRej; ��������ṹָ��
  Output:
    ��
  Return:
    STA_SUCCESS     =0, ��������
    STA_ERROR       =1, ���󷵻�
  Others:
  1.��    ��   : 2012��4��11��
    ��    ��   : l00130025
    �޸�����   : DTS2012032600471,��ʱ��ֹͣ����û�й��������������ⶨλ
  2.��    ��   : 2012��8��10��
    ��    ��   : y00213812
    �޸�����   : DTS2012082204471, TQE����
  3.��    ��   : 2013��4��2��
    ��    ��   : z00161729
    �޸�����   : �����ϱ�AT�������������C�˼�mma��mscc�ӿڵ���
  4.��    ��   : 2012��07��15��
    ��    ��   : w00176964
    �޸�����   : VoLTE_PhaseI��Ŀ�޸�:�޸ĺ��������ͷ���ֵ
  5.��    ��   : 2015��3��13��
    ��    ��   : b00269685
    �޸�����   : �б����ϱ��ӿڵ���
*************************************************/
VOS_UINT32 Sta_PlmnListRej(
    VOS_UINT32                          ulEventType,
    struct MsgCB                       *pstMsg
)
{
    VOS_UINT32          ulRet;

    /* ����PLMN_LIST״̬ */
    if ( VOS_FALSE == (g_StatusContext.ulFsmState & STA_FSM_PLMN_LIST) )
    {
        g_StatusContext.PhoneError = TAF_ERR_PHONE_MSG_UNMATCH;

        /* ������ٵ�����Ϣ */
        STA_TRACE (STA_WARNING_PRINT,
            "Sta_PlmnListInd():WARNING:unmatched system FSM state\n" );

        /* Modified by w00176964 for VoLTE_PhaseI��Ŀ, 2013-7-15, begin */
        return VOS_TRUE;
        /* Modified by w00176964 for VoLTE_PhaseI��Ŀ, 2013-7-15, end */
    }

    /* �ر�״̬��ʱ��*/

    ulRet = NAS_StopRelTimer(WUEPS_PID_MMA,
                             g_StatusContext.aFsmSub[0].TimerName,
                             &g_StatusContext.ahStaTimer[0]);


    if ( VOS_OK != ulRet )
    {
        STA_TRACE (STA_WARNING_PRINT,
            "Sta_PlmnListRej():WARNING:NAS_StopRelTimer failed  ");
    }
    g_StatusContext.ahStaTimer[0]    = 0;
    /* ���б�־ */
    g_StatusContext.aucFsmSubFlag[0] = STA_FSMSUB_NULL;

    /*�����״̬*/
    /*modified by Y00213812 for DTS2012082204471 TQE����, 2012-08-10, begin*/
    ulRet = Sta_UpdateFsmFlag(STA_FSMSUB_NULL, STA_FSM_ENABLE, STA_UPDATE_MONO_CLEAR);
    if (STA_ERROR == ulRet)
    {
        STA_TRACE(STA_WARNING_PRINT, "Sta_PlmnListRej():WARNING:Sta_UpdateFsmFlag failed\n");
    }
    /*modified by Y00213812 for DTS2012082204471 TQE����, 2012-08-10, end*/

    /* Э��ջ�ܾ�PLMN����*/
    /* ��APP�ϱ��¼�*/
    TAF_MMA_PlmnListErrorReport(TAF_ERR_CMD_TYPE_ERROR);

    /* Modified by w00176964 for VoLTE_PhaseI��Ŀ, 2013-7-15, begin */
    return VOS_TRUE;
    /* Modified by w00176964 for VoLTE_PhaseI��Ŀ, 2013-7-15, end */
}
/*****************************************************************************
 �� �� ��  : Sta_PlmnListAortCnf
 ��������  : MMA�յ�MSCC_PLMN_LIST_ABORT_CNF�Ĵ���
 �������  : ST_MSCC_PLMN_LIST_ABORT_CNF* pPlmnListAbortCnf
 �������  : ��
 �� �� ֵ  : ��
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2011��09��14��
    ��    ��   : w00166186
    �޸�����   : �����ɺ���
  2.��    ��   : 2011��11��08��
    ��    ��   : c00173809
    �޸�����   : AT Project
  3.��    ��   : 2012��5��28��
    ��    ��   : z00161729
    �޸�����   : GUL BG�����޸�
  4.��    ��   : 2012��9��22��
    ��    ��   : s00217060
    �޸�����   : for V7R1C50_At_Abort
  5.��    ��   : 2013��4��2��
    ��    ��   : z00161729
    �޸�����   : �����ϱ�AT�������������C�˼�mma��mscc�ӿڵ���
*****************************************************************************/
VOS_VOID Sta_PlmnListAortCnf (MSCC_MMA_PLMN_LIST_ABORT_CNF_STRU *pPlmnListAbortCnf)
{

    VOS_UINT32                          ulIndex;

    VOS_UINT32                          ulRet;

    /* stop cnf��search cnf�Գ�ʱ�п��ܴ��������б���Ϊ�գ���Ҫ�ϱ�*/
    if (pPlmnListAbortCnf->ulCnt > 0)
    {
        for ( ulIndex = 0; ulIndex < pPlmnListAbortCnf->ulCnt; ulIndex++ )
        {
            g_StatusContext.PlmnList.Plmn[ulIndex].Mcc
                = pPlmnListAbortCnf->aPlmnList[ulIndex].ulMcc;
            g_StatusContext.PlmnList.Plmn[ulIndex].Mnc
                = pPlmnListAbortCnf->aPlmnList[ulIndex].ulMnc;

            /*����ÿ��PLMN��״̬�ͽ���ģʽ*/
            g_StatusContext.PlmnList.PlmnInfo[ulIndex].PlmnStatus
                = pPlmnListAbortCnf->aucPlmnStatus[ulIndex];
            g_StatusContext.PlmnList.PlmnInfo[ulIndex].RaMode
                = pPlmnListAbortCnf->aucRaMode[ulIndex];

        }
        g_StatusContext.PlmnList.ucPlmnNum = (VOS_UINT8)pPlmnListAbortCnf->ulCnt;

        /*���ϱ���PLMN�б����е��� */
        Sta_ReOrderPlmnList(&g_StatusContext.PlmnList);

        /* ��APP�ϱ��¼�*/
        g_StatusContext.ucOperateType = STA_OP_PLMNLIST;

        /* �б��ѻظ����ͨ��ר�е��¼��ظ� */
        Sta_PlmnListEventReport();
    }
    else
    {
        /* ��AT�ظ��б��ѳ�ʱ��� */

        TAF_MMA_PlmnListErrorReport(TAF_ERR_TIME_OUT);

    }


    /* ����״̬��־ */
    ulRet = Sta_UpdateFsmFlag (STA_FSMSUB_NULL, STA_FSM_ENABLE, STA_UPDATE_MONO_CLEAR);

    if (STA_ERROR == ulRet)
    {
        STA_TRACE(STA_WARNING_PRINT, "Sta_PlmnListAortCnf():WARNING:Sta_UpdateFsmFlag failed\n");
    }

    /* ���õ�ǰû�д����û��б��Ѵ�Ϲ��� */
    g_StatusContext.ucPlmnListAbortProc = TAF_MMA_PLMN_LIST_ABORT_BUTT;

    return;
}


/*****************************************************************************
 �� �� ��  : TAF_MMA_PlmnListAbortCnfUserAbort
 ��������  : MMA�յ�MSCC_PLMN_LIST_ABORT_CNF�Ĵ���,Abortԭ��ֵΪ�û����
 �������  : ST_MMC_PLMN_LIST_ABORT_CNF* pPlmnListAbortCnf
 �������  : ��
 �� �� ֵ  : ��
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2012��09��18��
    ��    ��   : s00217060
    �޸�����   : �����ɺ���
  2.��    ��   : 2013��4��2��
    ��    ��   : z00161729
    �޸�����   : �����ϱ�AT�������������C�˼�mma��mscc�ӿڵ���
*****************************************************************************/
VOS_VOID TAF_MMA_PlmnListAbortCnfUserAbort (MSCC_MMA_PLMN_LIST_ABORT_CNF_STRU *pPlmnListAbortCnf)
{
    /* ��AT�ظ��б��Ѵ�� */
    TAF_MMA_ProcPlmnListAbortCnf(TAF_ERR_NO_ERROR);
    /* ����״̬��־ */
    g_StatusContext.ulFsmState = STA_FSM_ENABLE;

    /* ���õ�ǰû�д����û��б��Ѵ�Ϲ��� */
    g_StatusContext.ucPlmnListAbortProc = TAF_MMA_PLMN_LIST_ABORT_BUTT;

    return;
}

/*****************************************************************************
 �� �� ��  : TAF_MMA_RcvPlmnListAbortCnf
 ��������  : MMA�յ�MSCC_PLMN_LIST_ABORT_CNF�Ĵ���
 �������  : ST_MSCC_PLMN_LIST_ABORT_CNF* pPlmnListAbortCnf
 �������  : ��
 �� �� ֵ  : STA_SUCCESS: ����������Ϣ�ɹ�
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2012��09��18��
    ��    ��   : s00217060
    �޸�����   : �����ɺ���
  2.��    ��   : 2013��4��2��
    ��    ��   : z00161729
    �޸�����   : �����ϱ�AT�������������C�˼�mma��mscc�ӿڵ���
  3.��    ��   : 2012��07��15��
    ��    ��   : w00176964
    �޸�����   : VoLTE_PhaseI��Ŀ�޸�:�޸ĺ��������ͷ���ֵ
*****************************************************************************/
VOS_UINT32 TAF_MMA_RcvPlmnListAbortCnf(
    VOS_UINT32                          ulEventType,
    struct MsgCB                       *pstMsg
)
{
    /* Added by w00176964 for VoLTE_PhaseI��Ŀ, 2013-7-15, begin */
    MSCC_MMA_PLMN_LIST_ABORT_CNF_STRU   *pPlmnListAbortCnf;

    /* ֹͣ������ʱ�� */
    TAF_MMA_StopTimer(TI_TAF_MMA_WAIT_MSCC_ABORT_PLMN_LIST_CNF);

    pPlmnListAbortCnf = (MSCC_MMA_PLMN_LIST_ABORT_CNF_STRU*)pstMsg;
    /* Added by w00176964 for VoLTE_PhaseI��Ŀ, 2013-7-15, end */

    /* ��ǰ����PLMN LIST״̬��ֱ�ӷ��� */
    if (STA_FSM_PLMN_LIST != g_StatusContext.ulFsmState)
    {
        STA_TRACE(STA_WARNING_PRINT, "TAF_MMA_RcvPlmnListAbortCnf():WARNING:Sta_UpdateFsmFlag failed\n");
        /* Modified by w00176964 for VoLTE_PhaseI��Ŀ, 2013-7-15, begin */
        return VOS_TRUE;
        /* Modified by w00176964 for VoLTE_PhaseI��Ŀ, 2013-7-15, end */
    }

    /* �쳣��������ǰû�����ڴ����û��б��Ѵ�ϣ�ֱ�ӷ��� */
    if (TAF_MMA_PLMN_LIST_ABORT_BUTT == g_StatusContext.ucPlmnListAbortProc)
    {
        STA_TRACE(STA_WARNING_PRINT, "TAF_MMA_RcvPlmnListAbortCnf():WARNING:Sta_UpdateFsmFlag failed\n");
        /* Modified by w00176964 for VoLTE_PhaseI��Ŀ, 2013-7-15, begin */
        return VOS_TRUE;
        /* Modified by w00176964 for VoLTE_PhaseI��Ŀ, 2013-7-15, end */
    }


    /* Modified by w00176964 for VoLTE_PhaseI��Ŀ, 2013-7-15, begin */
    /* ��ʱ����ʱ���µ�PLMN LIST ABORT�Ĵ��� */
    if ( TAF_MMA_PLMN_LIST_ABORT_PROCESSING_TIMEOUT == g_StatusContext.ucPlmnListAbortProc)
    {
        Sta_PlmnListAortCnf(pPlmnListAbortCnf);
    }
    else
    {
        TAF_MMA_PlmnListAbortCnfUserAbort(pPlmnListAbortCnf);
    }

    return VOS_TRUE;
    /* Modified by w00176964 for VoLTE_PhaseI��Ŀ, 2013-7-15, end */
}

/*****************************************************************************
�� �� ��  : TAF_MMA_RcvSpecPlmnSearchAbortCnf
��������  : MMA�յ�TAFMSCC_SPEC_PLMN_SEARCH_ABORT_CNF�Ĵ���
�������  : pSpecPlmnSearchAbortCnf - AFMSCC_SPEC_PLMN_SEARCH_ABORT_CNF��Ϣ����
�������  : ��
�� �� ֵ  : STA_SUCCESS: ����������Ϣ�ɹ�
���ú���  :
��������  :

�޸���ʷ      :
1.��    ��   : 2011��11��28��
  ��    ��   : z00161729
  �޸�����   : �����ɺ���
2.��    ��   : 2013��4��2��
  ��    ��   : z00161729
  �޸�����   : �����ϱ�AT�������������C�˼�mma��mscc�ӿڵ���
3.��    ��   : 2012��07��15��
  ��    ��   : w00176964
  �޸�����   : VoLTE_PhaseI��Ŀ�޸�:�޸ĺ��������ͷ���ֵ

*****************************************************************************/
VOS_UINT32 TAF_MMA_RcvSpecPlmnSearchAbortCnf(
    VOS_UINT32                          ulEventType,
    struct MsgCB                       *pstMsg
)
{
    /* ֹͣ������ʱ�� */
    TAF_MMA_StopTimer(TI_TAF_MMA_WAIT_MSCC_ABORT_SPEC_PLMN_SEL_CNF);
    /* �ϱ�APP��ǰ״̬�¼� */
    TAF_MMA_ProcPlmnSpecialSelCnf(TAF_ERR_TIME_OUT);

    /* Ǩ��״̬��ENABLE״̬ */
    g_StatusContext.ulFsmState = STA_FSM_ENABLE;

    /* Modified by w00176964 for VoLTE_PhaseI��Ŀ, 2013-7-15, begin */
    return VOS_TRUE;
    /* Modified by w00176964 for VoLTE_PhaseI��Ŀ, 2013-7-15, end */
}

/* Deleted by w00176964 for VoLTE_PhaseI��Ŀ, 2013-7-10, begin */
/* ����Sta_MsgIndɾ�� */
/* Deleted by w00176964 for VoLTE_PhaseI��Ŀ, 2013-7-10, end */

/* Added by l00208543 for V9R1 STK����, 2013-08-01, begin */
/*****************************************************************************
 �� �� ��  : TAF_MMA_ConvertTafSrvStaToStkType
 ��������  : ת��service status�����ͣ�deep sleepΪno service, regional limited service ת��Ϊlimited service
 �������  : enTafSrvType
 �������  : ��
 �� �� ֵ  : ת�����service type
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2013��8��1��
    ��    ��   : l00208543
    �޸�����   : �����ɺ���

*****************************************************************************/

TAF_SDC_REPORT_SRVSTA_ENUM_UINT8 TAF_MMA_ConvertTafSrvStaToStkType(
                                    TAF_SDC_REPORT_SRVSTA_ENUM_UINT8  enTafSrvType
                                    )
{
    TAF_SDC_REPORT_SRVSTA_ENUM_UINT8 enRtType;

    enRtType = enTafSrvType;

    if(TAF_SDC_REPORT_SRVSTA_REGIONAL_LIMITED_SERVICE == enTafSrvType)
    {
        enRtType = TAF_SDC_REPORT_SRVSTA_LIMITED_SERVICE;
    }

    if(TAF_SDC_REPORT_SRVSTA_DEEP_SLEEP == enTafSrvType)
    {
        enRtType = TAF_SDC_REPORT_SRVSTA_NO_SERVICE;
    }

    return enRtType;
}

/*****************************************************************************
 �� �� ��  : TAF_MMA_ConvertSrvTypeForStk
 ��������  : ת��service status�����ͣ�deep sleepΪno service, regional limited service ת��Ϊlimited service
 �������  : enTafSrvType
 �������  : ��
 �� �� ֵ  : ת�����service type
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2013��8��1��
    ��    ��   : l00208543
    �޸�����   : �����ɺ���

*****************************************************************************/

TAF_SDC_SERVICE_STATUS_ENUM_UINT8 TAF_MMA_ConvertSrvTypeForStk(
                                    TAF_SDC_SERVICE_STATUS_ENUM_UINT8  enTafSrvType
                                    )
{
    TAF_SDC_SERVICE_STATUS_ENUM_UINT8 enRtType;

    enRtType = enTafSrvType;

    if (TAF_SDC_SERVICE_STATUS_LIMITED_SERVICE_REGION == enTafSrvType)
    {
        enRtType = TAF_SDC_SERVICE_STATUS_LIMITED_SERVICE;
    }

    if (TAF_SDC_SERVICE_STATUS_DEEP_SLEEP == enTafSrvType)
    {
        enRtType = TAF_SDC_SERVICE_STATUS_NO_SERVICE;
    }

    return enRtType;
}


/*****************************************************************************
 �� �� ��  : TAF_MMA_GetSrvTypeForStk
 ��������  : ����CS PS�ķ���״̬���ж��ܵķ���״̬(�����µĹ����������STK�ϱ�LOCI�¼�������)
 �������  : ��
 �������  : ��
 �� �� ֵ  : ת�����service type
 ���ú���  :
 ��������  :
  ��ȡenTafSrvType
 1.    CS PS ת��NORMAL NO SERVICE LIMIT
 2.    CS            PS
     NORMAL          NORMAL          NORMAL
     NORMAL          LIMIT           NORMAL
     NORMAL          NO SERVICE      NORMAL
     LIMIT           NORMAL          NORMAL
     LIMIT           LIMIT           LIMIT
     LIMIT           NO SERVICE      NO SERVICE(cs+ps or ps only)   MN_MMA_GetLastSyscfgSetAddr()->ucSrvDomain
     LIMIT           NO SERVICE      LIMIT(cs only)
     NO SERVICE      NORMAL          NORMAL
     NO SERVICE      LIMIT           NO SERVICE
     NO SERVICE      NO SERVICE      NO SERVICE

 �޸���ʷ      :
  1.��    ��   : 2013��8��7��
    ��    ��   : l00208543
    �޸�����   : �����ɺ���
  2.��    ��   : 2015��4��9��
    ��    ��   : h00313353
    �޸�����   : SysCfg SrvDomain�궨��תö������
*****************************************************************************/

TAF_SDC_REPORT_SRVSTA_ENUM_UINT8 TAF_MMA_GetSrvTypeForStk(VOS_VOID)
{
    TAF_SDC_REPORT_SRVSTA_ENUM_UINT8    enRtType;
    TAF_SDC_SERVICE_STATUS_ENUM_UINT8   enCsServiceStatus;
    TAF_SDC_SERVICE_STATUS_ENUM_UINT8   enPsServiceStatus;
    TAF_MMA_LAST_SETTED_SYSCFG_SET_STRU *pstSysCfg;

    pstSysCfg         = TAF_MMA_GetLastSyscfgSetAddr();

    enCsServiceStatus = TAF_MMA_ConvertSrvTypeForStk(TAF_SDC_GetCsServiceStatus());
    enPsServiceStatus = TAF_MMA_ConvertSrvTypeForStk(TAF_SDC_GetPsServiceStatus());

    if ((TAF_SDC_SERVICE_STATUS_NORMAL_SERVICE == enCsServiceStatus)
     || (TAF_SDC_SERVICE_STATUS_NORMAL_SERVICE == enPsServiceStatus))
    {
        enRtType = TAF_SDC_REPORT_SRVSTA_NORMAL_SERVICE;
    }
    else if ((TAF_SDC_SERVICE_STATUS_NO_SERVICE == enCsServiceStatus)
          || (TAF_SDC_SERVICE_STATUS_NO_SERVICE == enPsServiceStatus))
    {
        if ((TAF_MMA_SERVICE_DOMAIN_CS == pstSysCfg->enSrvDomain)
         && (TAF_SDC_SERVICE_STATUS_LIMITED_SERVICE == enCsServiceStatus))
        {
            enRtType = TAF_SDC_REPORT_SRVSTA_LIMITED_SERVICE;
        }
        else
        {
            enRtType = TAF_SDC_REPORT_SRVSTA_NO_SERVICE;
        }
    }
    else
    {
        enRtType = TAF_SDC_REPORT_SRVSTA_LIMITED_SERVICE;
    }

    return enRtType;
}

/*****************************************************************************
 �� �� ��  : TAF_MMA_ProcServiceStaReportForStk
 ��������  : ת��service status�����ͣ�deep sleepΪno service, regional limited service ת��Ϊlimited service
 �������  : enTafSrvType
 �������  : ��
 �� �� ֵ  : ת�����service type
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2013��8��1��
    ��    ��   : l00208543
    �޸�����   : �����ɺ���

*****************************************************************************/

VOS_VOID TAF_MMA_ProcLociStatusEvent(VOS_VOID)
{
   TAF_SDC_REPORT_SRVSTA_ENUM_UINT8    enStkServiceType;

   enStkServiceType = TAF_MMA_GetSrvTypeForStk();

   if (enStkServiceType != g_stMmsStkLocStaSysInfo.enServiceStatus)
   {
       if (VOS_FALSE == MN_MMA_GetRoamingBrokerFlg())
       {
          NAS_MMA_ReportLociStatus();
       }
       else
       {
           if (TAF_SDC_REPORT_SRVSTA_NORMAL_SERVICE == enStkServiceType)
           {
               NAS_MMA_ReportLociStatus();
           }
       }
   }
}
/* Added by l00208543 for V9R1 STK����, 2013-08-01, end */

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
/*--------------- STATUS�ڲ����ݴ�������  ---------------*/
/*=======================================================*/

/*************************************************
  Function:
    Sta_EventReport
  Description:
    ��TAFM�����¼�״̬����
  Calls:                     �����������õĺ����嵥
  Called By:                 ���ñ������ĺ����嵥
  Input:
    VOS_UINT32  ulOpId;         ���������ʶ
    VOS_UINT32  ulEventType;    �¼�����
  Output:
    ��
  Return:
    ��
  Others:
  History:
  1. s46746  2006-09-04 �������ⵥA32D05624�޸�
  2.��    ��   : 2011��7��11��
    ��    ��   : sunxibo 46746
    �޸�����   : V7R1 phase II,autoplmnsrch״̬������ΪPlmnSelection״̬��
  3.��    ��   : 2012��04��10��
    ��    ��   : f00179208
    �޸�����   : ���ⵥ��:DTS2012041003283, USMI�Ȳ������
  4.��    ��   : 2012��6��15��
    ��    ��   : w00176964
    �޸�����   : DTS2012061408865:LIST���������аο��ϱ�32��������
  5.��    ��   : 2013��4��3��
   ��    ��   : z00161729
   �޸�����   : �����ϱ�AT�������������C�˼�mma��mscc�ӿڵ���
  6.��    ��   : 2013��8��1��
   ��    ��   : l00208543
   �޸�����   : STK����
  7.��    ��   : 2013��8��1��
    ��    ��   : w00176964
    �޸�����   : VoLTE_PhaseI��Ŀ:���ػ��ڼ��simst���ϱ�Ŀǰ���ɿ�״ָ̬ʾ����
  8.��    ��   : 2015��3��4��
   ��    ��   : b00269685
   �޸�����   : �б��Ѹ�Ϊ�ֶ��ϱ�
*************************************************/
VOS_VOID Sta_EventReport ( VOS_UINT32 ulOpID, VOS_UINT32 ulEventType )
{
    TAF_PHONE_EVENT_INFO_STRU      *pstPhoneEvent;

    /* Modified by z00161729 for �����ϱ�AT�������������C��, 2013-4-3, begin */
    TAF_SDC_SERVICE_STATUS_ENUM_UINT8   enCsServiceStatus;
    TAF_SDC_SERVICE_STATUS_ENUM_UINT8   enPsServiceStatus;

    enCsServiceStatus = TAF_SDC_GetCsServiceStatus();
    enPsServiceStatus = TAF_SDC_GetPsServiceStatus();

    /* Modified by z00161729 for �����ϱ�AT�������������C��, 2013-4-3, end */


    pstPhoneEvent = (TAF_PHONE_EVENT_INFO_STRU *)PS_MEM_ALLOC(WUEPS_PID_MMA, sizeof(TAF_PHONE_EVENT_INFO_STRU));

    if (VOS_NULL_PTR == pstPhoneEvent)
    {
        STA_TRACE(PS_LOG_LEVEL_ERROR,"Sta_EventReport:ERROR:ALLOC MEMORY FAIL.");
        return;
    }

    PS_MEM_SET(pstPhoneEvent, 0, sizeof(TAF_PHONE_EVENT_INFO_STRU));
    /* ����ṹ������־ */
    pstPhoneEvent->OP_CsServiceStatus    = 0;
    pstPhoneEvent->OP_PhoneError         = 0;
    pstPhoneEvent->OP_PlmnReselMode      = 0;
    pstPhoneEvent->OP_PsServiceStatus    = 0;
    pstPhoneEvent->OP_RegPlmn            = 0;
    pstPhoneEvent->OP_Spare              = 0;
    /*�����ϱ��¼�ѡ���ʼ��*/
    pstPhoneEvent->OP_CurRegSta          = 0;
    pstPhoneEvent->OP_Rssi               = 0;
    pstPhoneEvent->OP_BatteryPower       = 0;
    pstPhoneEvent->OP_Pin                = 0;
    pstPhoneEvent->OP_Srvst              = 0;

    /* ��д�ϱ��¼����� */
    /* ������� */
    pstPhoneEvent->OpId = (VOS_UINT8)ulOpID;         /*д��ulOpId*/
    pstPhoneEvent->PhoneEvent = (TAF_PHONE_EVENT)ulEventType;
    pstPhoneEvent->PhoneError = TAF_ERR_NO_ERROR;
    /* ��ѡ�������� */
    if ( STA_OP_REGPLMN & g_StatusContext.ucOperateType )
    {
        pstPhoneEvent->OP_RegPlmn = 1;
        pstPhoneEvent->RegPlmn.Mcc= g_StatusContext.StaPlmnId.Mcc;
        pstPhoneEvent->RegPlmn.Mnc= g_StatusContext.StaPlmnId.Mnc;
        MMA_PlmnId2Bcd(&(pstPhoneEvent->RegPlmn));
    }

    if ( STA_OP_PLMNLIST & g_StatusContext.ucOperateType )
    {
        /* �˴�����Ҫ����� */
    }

    if ( STA_OP_PLMNRESELMODE & g_StatusContext.ucOperateType )
    {
        pstPhoneEvent->OP_PlmnReselMode = 1;
        pstPhoneEvent->PlmnReselMode
            = (TAF_PLMN_RESEL_MODE_TYPE)g_StatusContext.ucReselMode;
    }

    if ( STA_OP_CSSERVICESTATUS & g_StatusContext.ucOperateType )
    {
        pstPhoneEvent->OP_CsServiceStatus = 1;

        /* CS�����״ֵ̬ */
        /* Modified by z00161729 for �����ϱ�AT�������������C��, 2013-4-3, begin */
        pstPhoneEvent->CsServiceStatus
            = (TAF_PHONE_SERVICE_STATUS)enCsServiceStatus;
        /* Modified by z00161729 for �����ϱ�AT�������������C��, 2013-4-3, end */
    }

    if ( STA_OP_PSSERVICESTATUS & g_StatusContext.ucOperateType )
    {
        pstPhoneEvent->OP_PsServiceStatus = 1;

        /* PS�����״ֵ̬ */
        pstPhoneEvent->PsServiceStatus
            = (TAF_PHONE_SERVICE_STATUS)enPsServiceStatus;
    }

    if ( STA_OP_PHONEERROR & g_StatusContext.ucOperateType )
    {
        pstPhoneEvent->OP_PhoneError = 1;
        pstPhoneEvent->PhoneError    = g_StatusContext.PhoneError;
    }




    /* ���õ绰�����¼��ϱ����� ��APP����Ӧ���¼�*/
    Taf_PhoneEvent (pstPhoneEvent);

    PS_MEM_FREE(WUEPS_PID_MMA, pstPhoneEvent);

    /* Deleted by w00176964 for VoLTE_PhaseI��Ŀ, 2013-8-1, begin */

    /* Deleted by w00176964 for VoLTE_PhaseI��Ŀ, 2013-8-1, end */

    return ;    /* �������� */
}

/*************************************************
  Function:
    Sta_IsFsmSubValid
  Description:
     �ж���״̬�Ƿ�ƥ��FSM��״̬
  Calls:                 �����������õĺ����嵥
  Called By:             ���ñ������ĺ����嵥
  Input:
    VOS_UINT8   ucFsmSub;   ��״ֵ̬
    VOS_UINT32  ulFsm;      FSM״ֵ̬
  Output:
    ��
  Return:
    STA_TRUE,  ��Ч����״ֵ̬��ƥ�䣻
    STA_FALSE, ��Ч����״ֵ̬����ƥ�䣻
  Others:
  1.��    ��   : 2007��07��24��
    ��    ��   : l60022475
    �޸�����   : A32D12535
*************************************************/
VOS_BOOL Sta_IsFsmSubValid ( VOS_UINT8 ucFsmSub, VOS_UINT32 ulFsm )
{
    switch ( ulFsm )
    {
        case STA_FSM_RESTART:
        case STA_FSM_STOP:
        case STA_FSM_PLMN_LIST:
        case STA_FSM_PLMN_SEL:
            /* ==>A32D12535 */
            if ( (STA_FSMSUB_MONO == ucFsmSub)
               ||(STA_FSM_RESTART == ucFsmSub)
                )
            /* <==A32D12535 */
            {
                return STA_TRUE;
            }
            return STA_FALSE;

        /*
          ����CS&PSͬʱDETACH��ATTACH״̬�ĺϷ��ԣ�
          modified by roger in 2005-07-11
        */

        case STA_FSM_PLMN_RESEL:
            if ( (STA_FSMSUB_PLMN_RESEL_AUTO == ucFsmSub)
              || (STA_FSMSUB_PLMN_RESEL_MANUAL == ucFsmSub) )
            {
                return STA_TRUE;
            }
            return STA_FALSE;

        /* �ڲ���������ʱʹ�õ��м�״̬������Ϊ��Ч״̬ */
        case STA_FSM_NO_UPDATE:
        /* FSM����̬������״ֵ̬û��ƥ��Ҫ�� */
        case STA_FSM_ENABLE:
        case STA_FSM_NULL:
            return STA_TRUE;

        default :
            return STA_FALSE;
    }
}

/*************************************************
  Function:
    Sta_IsInvalidOpId
  Description:
    �Ƿ�����Ч��OPID
  Calls:                  �����������õĺ����嵥
  Called By:              ���ñ������ĺ����嵥
  Input:
    VOS_UINT32  ulOpId;      �����ʶ
  Output:
    ��
  Return:
    STA_TRUE,   ָ����ulOpId��Ч��
    STA_FALSE,  ָ����ulOpId��Ч��
  Others:
*************************************************/
VOS_BOOL Sta_IsInvalidOpId ( VOS_UINT32 ulOpId )
{
    if ( STA_OPID_INSIDE == ulOpId )
    {
        return STA_FALSE;
    }

    if ( ulOpId <= STA_OPID_MAX )
    {
        return STA_FALSE;
    }

    return STA_TRUE;
}


/*�˺����Ѿ�����*/
/*************************************************
  Function:
    Sta_IsDualFsmSub
  Description:
    �Ƿ����������״̬ͬʱ��Ч�����ͬһ��OPID
  Calls:                  �����������õĺ����嵥
  Called By:              ���ñ������ĺ����嵥
  Input:
    VOS_UINT32  ulOpId;      �����ʶ
  Output:
    ��
  Return:
    STA_TRUE,   ����˫����Ч��״̬��
    STA_FALSE,  ������˫����Ч��״̬��
  Others:
*************************************************/
VOS_UINT32 Sta_IsDualFsmSub ( VOS_VOID )
{
    /*��ǰ���е�˫����״̬��OpId����һ���ģ�
    ����жϵ���״̬��־λ��Ϊ��ͬʱ,��״̬Ϊ˫����״̬*/
    if  ( g_StatusContext.aucFsmSubFlag[0]
          != g_StatusContext.aucFsmSubFlag[1])
    {
        return STA_FALSE;
    }
    /* ��״̬OPID����ͬ������˫����״̬ */
    /*if ( g_StatusContext.aFsmSub[0].ulOpId
        != g_StatusContext.aFsmSub[1].ulOpId )
    {
        return STA_FALSE;
    }
    */
    return STA_TRUE;
}

/*************************************************
  Function:
    Sta_FindFsmSubBySubSta
  Description:
     ����ָ�����������ʶ�Ķ�Ӧ��״̬������
  Calls:                  �����������õĺ����嵥
  Called By:              ���ñ������ĺ����嵥
  Input:
    VOS_UINT32  ulOpId;       �����ʶ
  Output:
    ��
  Return:
    STA_FSMSUB_INDEX_NULL, ��Ч����״̬����ֵ��
    0< ret <STA_TIMER_MAX, ����������ֵret��
  Others:
*************************************************/
/*
VOS_UINT32 Sta_FindFsmSubBySubSta ( VOS_UINT32 ulOpId )
{
    VOS_UINT8       ucIndex;
    VOS_UINT8       n;

    ucIndex = STA_FSMSUB_INDEX_NULL;
    for ( n = 0; n < STA_TIMER_MAX; n++ )
    {
        if ( ulOpId == g_StatusContext.aFsmSub[n].ulOpId )
        {
            ucIndex = n;
            break;
        }
    }

    return ucIndex;
}
*/
/*************************************************
  Function:
    Sta_FindFsmSubBySubSta
  Description:
     ����ָ��ָ����״̬�Ķ�Ӧ��״̬������
  Calls:                  �����������õĺ����嵥
  Called By:              ���ñ������ĺ����嵥
  Input:
    VOS_UINT8  ucFsmSubSta;       �����ʶ
  Output:
    ��
  Return:
    STA_FSMSUB_INDEX_NULL, ��Ч����״̬����ֵ��
    0< ret <STA_TIMER_MAX, ����������ֵret��
  Others:
*************************************************/
VOS_UINT8 Sta_FindFsmSubBySubSta ( VOS_UINT8 ucFsmSubSta )
{
    VOS_UINT8       ucIndex;
    VOS_UINT8       n;

    ucIndex = STA_FSMSUB_INDEX_NULL;

    for ( n = 0; n < STA_TIMER_MAX; n++ )
    {
        if (ucFsmSubSta == g_StatusContext.aFsmSub[n].ucFsmStateSub)
        {
            ucIndex = n;
            break;
        }
    }

    return ucIndex;
}

/*************************************************
  Function:
    Sta_FindIdleFsmSub
  Description:
     ����ָ����״ֵ̬�Ķ�Ӧ�Ŀ�����Դ������
  Calls:                  �����������õĺ����嵥
  Called By:              ���ñ������ĺ����嵥
  Input:
    VOS_UINT32  ulOpId;      �����ʶ
  Output:
    ��
  Return:
    STA_FSMSUB_INDEX_NULL, ��Ч����״̬����ֵ��
    0< ret <STA_TIMER_MAX, ����������ֵret��
  Others:
*************************************************/
VOS_UINT32 Sta_FindIdelFsmSub ( VOS_UINT8 ucSubState )
{
    VOS_UINT8       ucRetIndex;
    VOS_UINT8       n;                  /* ѭ������ */

    ucRetIndex = STA_FSMSUB_INDEX_NULL;

    /* ���ҿ�����״̬ */
    for ( n = 0; n < STA_TIMER_MAX; n++ )
    {
        if ( STA_FSMSUB_NULL == g_StatusContext.aucFsmSubFlag[n] )
        {
            ucRetIndex = n;
            break;
        }
    }

    /* �޿��õ���״̬��Դ��ֱ�ӷ�����Ч����ֵ */
    if ( STA_FSMSUB_INDEX_NULL == ucRetIndex )
    {
        return STA_FSMSUB_INDEX_NULL;      /* ������Чֵ */
    }


    /* ����״ֱ̬�ӷ��ؿ�����״̬���� */
    if ( (STA_FSMSUB_NULL == ucSubState)
        || (STA_FSMSUB_OK == ucSubState)
        || (STA_FSMSUB_MONO == ucSubState) )
    {
        return ucRetIndex;
    }

    /* �ǿ��е���״ֻ̬��������һ�� */
    for ( n = 0; n < STA_TIMER_MAX; n++ )
    {
        if ( ucSubState == g_StatusContext.aucFsmSubFlag[n] )
        {
            return STA_FSMSUB_INDEX_NULL;   /* ������Чֵ */
        }
    }

    return ucRetIndex;
}

/*************************************************
  Function:
    Sta_UpdateFsmFlag
  Description:
     ����״̬����״̬������־
  Calls:                 �����������õĺ����嵥
  Called By:             ���ñ������ĺ����嵥
  Input:
    VOS_UINT8   ucFsmSub;   ��״ֵ̬
    VOS_UINT32  ulFsm;      FSM״ֵ̬
    VOS_UINT32  ulType;     ��������
  Output:
    ��
  Return:
    STA_SUCCESS,        =0, ��������
    STA_ERROR,          =1, ���󷵻�
  Others:
  1.��    ��   : 2012��4��11��
    ��    ��   : l00130025
    �޸�����   : DTS2012032600471,��ʱ��ֹͣ����û�й��������������ⶨλ

  2.��    ��   : 2012��5��31��
    ��    ��   : z40661
    �޸�����   : DTS2012052902643:ʹ��AT^CGCATT=1,3���ٴ�ȥ����MMAֱ�ӷ���ʧ��

*************************************************/
VOS_UINT32 Sta_UpdateFsmFlag ( VOS_UINT8 ucFsmSub,
                           VOS_UINT32 ulFsm,
                           VOS_UINT32 ulType )
{
    VOS_UINT8                           n;                  /* ѭ������*/

    /* ���ո������ͽ��в��� */
    switch ( ulType )
    {
        case STA_UPDATE_SETNEW:
            if (  STA_FSM_NO_UPDATE == ulFsm )
            {
               return STA_SUCCESS;
            }

            /* ˫����״̬�ĵ�һ���� */

            /* ������״̬�ĸ��� */
            g_StatusContext.aFsmSub[0].ucFsmStateSub  = ucFsmSub;
            g_StatusContext.aucFsmSubFlag[0]          = ucFsmSub;
            break;

        /* ������״̬�ĸ���,�������ʱ������Դ */
        case STA_UPDATE_MONO_CLEAR:

            if (VOS_NULL_PTR != g_StatusContext.ahStaTimer[0])
            {
                if (VOS_OK != NAS_StopRelTimer(WUEPS_PID_MMA,
                                 g_StatusContext.aFsmSub[0].TimerName,
                                &g_StatusContext.ahStaTimer[0]))
                {
                    STA_TRACE(STA_WARNING_PRINT, "Sta_UpdateFsmFlag():WARNING:NAS_StopRelTimer failed!");
                }
            }
            g_StatusContext.aFsmSub[0].ucFsmStateSub  = ucFsmSub;
            g_StatusContext.aucFsmSubFlag[0]          = ucFsmSub;
            g_StatusContext.aFsmSub[0].TimerName      = STA_TIMER_NULL;
            g_StatusContext.ahStaTimer[0]             = VOS_NULL_PTR;



            if ( STA_FSM_INVALID != ulFsm )
            {
                g_StatusContext.ulFsmState = ulFsm;
            }

            /*����OpID��Чֵ*/
            g_StatusContext.aFsmSub[0].ulOpId        = STA_OPID_INVALID;
            /*�����ǰ������־*/
            g_StatusContext.aucStaPhoneOperator[0]   = STA_FSMSUB_NULL;
            break;

        /* ˫����״̬ͬʱ����, ����������Դ���綨ʱ�� */
        case STA_UPDATE_DUAL_CLEAR:

            for ( n = 0; n < STA_TIMER_MAX; n++ )
            {
                if (VOS_NULL_PTR != g_StatusContext.ahStaTimer[n])
                {
                    if (VOS_OK != NAS_StopRelTimer(WUEPS_PID_MMA,
                                     g_StatusContext.aFsmSub[n].TimerName,
                                    &g_StatusContext.ahStaTimer[n]))
                    {
                        STA_TRACE(STA_WARNING_PRINT, "Sta_UpdateFsmFlag():WARNING:NAS_StopRelTimer failed!");
                    }
                }
                g_StatusContext.aFsmSub[n].ucFsmStateSub  = ucFsmSub;
                g_StatusContext.aucFsmSubFlag[n]          = ucFsmSub;
                g_StatusContext.aFsmSub[n].TimerName      = STA_TIMER_NULL;
                g_StatusContext.ahStaTimer[n]             = VOS_NULL_PTR;


                /*����OpID��Чֵ*/
                g_StatusContext.aFsmSub[n].ulOpId        = STA_OPID_INVALID;

                /*�����ǰ������־*/
                g_StatusContext.aucStaPhoneOperator[n]   = STA_FSMSUB_NULL;
            }
            if ( (STA_FSM_INVALID != ulFsm)
                && (STA_FSM_NO_UPDATE != ulFsm) )
            {
                g_StatusContext.ulFsmState = ulFsm;
            }
            break;

       /* ˫����״̬�ĵ�һ���£��������ʱ������Դ */
        case STA_UPDATE_SINGL_CLEAR:

            break;

        /* δʹ�õ�״̬�����ش��� */
        default:
            STA_TRACE (STA_WARNING_PRINT,
                "Sta_UpdateFsmFlag():WARNING:unused state, do nothing  ");
            return STA_ERROR;
    }

    return STA_SUCCESS;
}

/*************************************************
  Function:
    Sta_UpdateData
  Description:
    ���¹���ȫ�ֱ��������ݡ�
  Calls:             �����������õĺ����嵥
  Called By:         ���ñ������ĺ����嵥
  Input:
    STA_PHONE_DATA_S   *pData;�����������ݵĽṹָ��
  Output:
    ��
  Return:
    STA_SUCCESS     =0,���سɹ�
    STA_ERROR       =1,����ʧ��
  Others:
  2.��    ��   : 2009��01��14��
    ��    ��   : l65478
    �޸�����   : ���ⵥ�ţ�AT2D07971,������״̬���ϱ��Ľ��뼼������
  3.��    ��   : 2013��4��2��
    ��    ��   : z00161729
    �޸�����   : �����ϱ�AT�������������C�˼�mma��mscc�ӿڵ���
*************************************************/
VOS_UINT32 Sta_UpdateData ( STA_PHONE_DATA_S *pData )
{
    VOS_UINT32  ulRet;
    VOS_UINT8   ucFsmSub;
    VOS_UINT32  ulFsm;
    VOS_UINT8   ucFsmFlag;

    /* ����ָ����Ч���ɵ����߱�֤��Ĭ����Ч */
    ucFsmSub  = pData->ucFsmStateSub;
    ulFsm     = pData->ulFsmState;
    ucFsmFlag = pData->ucFsmUpdateFlag;

    /* �ж���״ֵ̬�Ƿ���Ч */
    if ( VOS_FALSE == Sta_IsFsmSubValid (ucFsmSub,ulFsm) )
    {
        STA_TRACE (STA_WARNING_PRINT,
            "Sta_UpdateData():WARNING:unmatched FSM state  ");

        return STA_ERROR;     /* ���󷵻� */
    }

    /* ������״̬�ĸ���ģʽ������ */
    switch ( pData->ucFsmSubOperate )
    {
        /* ����FSM״̬��־������ʼ�µ���״̬ */
        case STA_FSMSUB_NEW:
            g_StatusContext.ulCurOpId = pData->ulOpId;  /*��¼�����ʶ��*/
            ulRet = Sta_UpdateFsmFlag (ucFsmSub, ulFsm, STA_UPDATE_SETNEW);
            if ( STA_ERROR == ulRet )
            {
                STA_TRACE (STA_WARNING_PRINT,
                    "Sta_UpdateData():WARNING:Sta_UpdateFsmFlag failed  ");
            }
            break;

        /* ˢ����״̬������Ϣ */
        case STA_FSMSUB_UPDATE:
            g_StatusContext.ulNewOpId = pData->ulOpId;  /* ���θ��µı�ʶ��*/
            break;

        /* ��״̬������ɣ������״̬��־ */
        case STA_FSMSUB_FINISH:
            ulRet = Sta_UpdateFsmFlag (ucFsmSub, ulFsm, ucFsmFlag);
            if ( STA_ERROR == ulRet )
            {
                STA_TRACE (STA_WARNING_PRINT,
                    "Sta_UpdateData():WARNING:Sta_UpdateFsmFlag failed  ");
            }
            break;

        /* ����ģʽ��֧�֣�ֱ�ӷ��� */
        default:
            STA_TRACE (STA_WARNING_PRINT,
                "Sta_UpdateData():WARNING:invalid operate ");
            return STA_ERROR;
    }

    /* ����STATUSҵ����Ϣ��¼ */
    g_StatusContext.StaPlmnId.Mcc       = pData->PlmnId.Mcc;
    g_StatusContext.StaPlmnId.Mnc       = pData->PlmnId.Mnc;

    g_StatusContext.ulMmProc            = pData->ulMmProc ;
    g_StatusContext.ucDomainFlag        = pData->ucDomainFlag;
    /*��֤ÿ��ֻ����Ч���򷵻صķ���״̬����ȫ�ֱ���*/
    /* Modified by z00161729 for �����ϱ�AT�������������C��, 2013-4-3, begin */
    switch ( pData->ucDomainFlag )
    {
        case NAS_MSCC_PIF_SRVDOMAIN_CS :
            TAF_SDC_SetCsServiceStatus((VOS_UINT8)pData->ulCsServiceStatus);
            g_StatusContext.ulCsCause = pData->ulCsCause;
            break;
        case NAS_MSCC_PIF_SRVDOMAIN_PS:
            TAF_SDC_SetPsServiceStatus((VOS_UINT8)pData->ulPsServiceStatus);
            g_StatusContext.ulPsCause = pData->ulPsCause;
            break;
        case NAS_MSCC_PIF_SRVDOMAIN_CS_PS:
            TAF_SDC_SetCsServiceStatus((VOS_UINT8)pData->ulCsServiceStatus);
            TAF_SDC_SetPsServiceStatus((VOS_UINT8)pData->ulPsServiceStatus);
            g_StatusContext.ulCsCause = pData->ulCsCause;
            g_StatusContext.ulPsCause = pData->ulPsCause;
            break;
        default :
            break;
    }
    /* Modified by z00161729 for �����ϱ�AT�������������C��, 2013-4-3, end */

    return STA_SUCCESS;       /* �������� */
}




/*
    �ڽ���PLMN����̬֮��ͨ��MSCC���ϱ���Ϣ����
    ������������
    modified by liuyang id:48197 date:2005-9-5 for V200R001
*/
/*****************************************************************************
 �� �� ��  : ClearCurPlmnId
 ��������  : ��PLMNID���㣬��Ϊ��ЧPLMN
 �������  : ��
 �� �� ֵ  : VOS_UINT8
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2005��9��5��
    ��    ��   : liuyang
    �޸�����   : �����ɺ���

*****************************************************************************/
VOS_VOID   Sta_ClearCurPlmnId(TAF_PLMN_ID_STRU *pstNewPlmnId)
{
    pstNewPlmnId->Mcc  = 0;
    pstNewPlmnId->Mnc  = 0;
}

/*****************************************************************************
 �� �� ��  : Sta_InitCurPlmnId
 ��������  : ����ǰPLMNidװ�뵱ǰȫ�ֱ���
 �������  : TAF_PLMN_ID_STRU NewPlmnId
 �������  : ��
 �� �� ֵ  : VOS_VOID
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2005��9��5��
    ��    ��   : liuyang
    �޸�����   : �����ɺ���

*****************************************************************************/
VOS_VOID   Sta_InitCurPlmnId(TAF_PLMN_ID_STRU    stSrcPlmnId,
                             TAF_PLMN_ID_STRU   *pstDstPlmnId)
{
    *pstDstPlmnId = stSrcPlmnId;
}

/* Deleted by z00161729 for �����ϱ�AT�������������C��, 2013-3-30, begin */

/* Deleted by z00161729 for �����ϱ�AT�������������C��, 2013-3-30, end */

/*****************************************************************************
 �� �� ��  : Sta_StopAllRunningTimer
 ��������  : ֹͣ�������еĶ�ʱ�����������ʱ��״̬��������صı���
 �������  : ��
 �� �� ֵ  : VOS_UINT32
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2006��1��19��
    ��    ��   : liuyang id:48197
    �޸�����   : �����ɺ���

*****************************************************************************/
VOS_UINT32 Sta_StopAllRunningTimer()
{
    VOS_UINT32      ulI;
    VOS_UINT32      ulRet = VOS_OK;

    for ( ulI = 0; ulI < STA_TIMER_MAX; ulI++ )
    {
        if (STA_TIMER_NULL != g_StatusContext.aFsmSub[ulI].TimerName )
        {
            ulRet = VOS_StopRelTimer (&g_StatusContext.ahStaTimer[ulI]);
            if ( VOS_OK != ulRet )
            {
                STA_TRACE (STA_WARNING_PRINT,
                    "Sta_StopAllRunningTimer():WARNING:VOS_StopRelTimer failed ");
            }
            g_StatusContext.aFsmSub[ulI].TimerName = STA_TIMER_NULL;
        }
    }
    return ulRet;
}



/*****************************************************************************
 �� �� ��  : Sta_GetStatusForSat
 ��������  : ���ײ��ϱ���״̬ת��Ϊ��SAT��״̬
 �������  : ucServiceStatus
 �������  : ��
 �� �� ֵ  : VOS_UINT8
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2008��3��25��
    ��    ��   : s46746
    �޸�����   : �����ɺ���
  2.��    ��   : 2013��4��4��
    ��    ��   : z00161729
    �޸�����   : �����ϱ�AT�������������C�˼�mma��mscc�ӿڵ���
*****************************************************************************/
VOS_UINT8 Sta_GetStatusForSat(VOS_UINT32 ulServiceStatus)
{
    VOS_UINT8 ucSatServiceStatus;

    /* Modified by z00161729 for �����ϱ�AT�������������C��, 2013-4-4, begin */
    switch (ulServiceStatus)
    {
        case NAS_MSCC_PIF_SERVICE_STATUS_NORMAL_SERVICE:
            ucSatServiceStatus = STA_SAT_LOCATION_NORMAL_SERVICE;
            break;

        case NAS_MSCC_PIF_SERVICE_STATUS_LIMITED_SERVICE :
        case NAS_MSCC_PIF_SERVICE_STATUS_LIMITED_SERVICE_REGION :
        case NAS_MSCC_PIF_SERVICE_STATUS_NO_IMSI :
            ucSatServiceStatus = STA_SAT_LOCATION_LIMIT_SERVICE;
            break;

        case NAS_MSCC_PIF_SERVICE_STATUS_NO_SERVICE:
            ucSatServiceStatus = STA_SAT_LOCATION_NO_SERVICE;
            break;

        default :
            ucSatServiceStatus = STA_SAT_LOCATION_NO_SERVICE;
            break;
    }
    /* Modified by z00161729 for �����ϱ�AT�������������C��, 2013-4-4, end */

    return ucSatServiceStatus;
}

/*****************************************************************************
 �� �� ��  : Sta_SndSatLocationStatus
 ��������  : MMA����Location Status Event
 �������  : pServiceStatus
 �������  : ��
 �� �� ֵ  : VOS_UINT32
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2008��3��25��
    ��    ��   : s46746
    �޸�����   : �����ɺ���
  2.��    ��   : 2013��4��7��
    ��    ��   : z00161729
    �޸�����   : �����ϱ�AT�������������C�˼�mma��mmc�ӿڵ���
*****************************************************************************/
VOS_VOID Sta_GetLocInfoForSat(
    MMA_MSCC_PLMN_ID_STRU                stPlmnId,
    VOS_UINT16                          usLac,
    VOS_UINT16                          usCellId,
    VOS_UINT8                          *pucLocInfo
)
{
    VOS_UINT8 ucSn = 0;
    /*lint -e961*/
    pucLocInfo[ucSn]    = (VOS_UINT8)(stPlmnId.ulMcc & 0x0000000f);
    pucLocInfo[ucSn++] |= (VOS_UINT8)((stPlmnId.ulMcc & 0x00000f00) >> 4);
    pucLocInfo[ucSn]    = (VOS_UINT8)((stPlmnId.ulMcc & 0x000f0000) >> 16);
    pucLocInfo[ucSn++] |= (VOS_UINT8)((stPlmnId.ulMnc & 0x000f0000) >> 12);
    pucLocInfo[ucSn]    = (VOS_UINT8)(stPlmnId.ulMnc & 0x0000000f);
    pucLocInfo[ucSn++] |= (VOS_UINT8)((stPlmnId.ulMnc & 0x00000f00) >> 4);

    pucLocInfo[ucSn++]  = (VOS_UINT8)(usLac >> 8);
    pucLocInfo[ucSn++]  = (VOS_UINT8)(usLac & 0x000000ff);

    pucLocInfo[ucSn++]  = (VOS_UINT8)(usCellId >> 8);
    pucLocInfo[ucSn++]  = (VOS_UINT8)(usCellId & 0x000000ff);
    /*lint +e961*/

    for (ucSn = 0; ucSn < STA_SAT_LOCATION_INFORMATON_LEN; ucSn ++)
    {
        STA_TRACE1(STA_INFO_PRINT,
                   "Sta_GetLocInfoForSat():INFO:Locinfo:",pucLocInfo[ucSn]);
    }

    return;
}

/* Deleted by z00161729 for �����ϱ�AT�������������C��, 2013-4-4, begin */
/* Deleted by z00161729 for �����ϱ�AT�������������C��, 2013-4-4, end */


/*****************************************************************************
 �� �� ��  : Mma_ModeChgReport
 ��������  : ϵͳģʽ��ϵͳ��ģʽ�仯�����ϱ�
 �������  : MSCC_CUR_NETWORK CurNetWork
 �������  : ��
 �� �� ֵ  :
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2008��03��27��
    ��    ��   : x00115505
    �޸�����   : �����ɺ���


  2.��    ��   : 2010��6��11��
    ��    ��   : ŷ����
    �޸�����   : ����ϵͳ�л�����GSM����ģʽ�����ı�ʱ����Ҫ�ϱ�^MODE֪ͨӦ
                 �ã��ϱ�������̬�µ���ģʽ��
  3.��    ��   : 2011��8��4��
    ��    ��   : z00161729
    �޸�����   : V7R1 phase II�޸�
  4.��    ��   : 2012��8��8��
    ��    ��   : s00217060
    �޸�����   : for V7R1C50_GUTL_PhaseII�޸�
  5.��    ��   : 2013��4��7��
    ��    ��   : z00161729
    �޸�����   : �����ϱ�AT�������������C�˼�mma��mscc�ӿڵ���
  6.��    ��   : 2015��2��26��
    ��    ��   : w00208541
    �޸�����   : ����CDMA����ϱ�
  7.��    ��   : 2015��08��22��
    ��    ��   : y00307564
    �޸�����   : DTS2015081005519�޸�
*****************************************************************************/
VOS_VOID Mma_ModeChgReport(
    TAF_SDC_SYS_MODE_ENUM_UINT8         enCurNetWork,
    VOS_UINT8                           ucSysSubMode
)
{
    /* Modified by z00161729 for �����ϱ�AT�������������C��, 2013-4-7, begin */

    VOS_UINT8                            ucModeChangeFlg;

    ucModeChangeFlg = TAF_MMA_IsModeChange(enCurNetWork, ucSysSubMode);

    if (VOS_TRUE == ucModeChangeFlg)
    {
        if (TAF_SDC_SYS_MODE_WCDMA == enCurNetWork)
        {
            if (NAS_UTRANCTRL_UTRAN_MODE_FDD == NAS_UTRANCTRL_GetCurrUtranMode())
            {
                /* G->W�£����ϱ�ȱʡģʽ: ^MODE:5,4,�����ϱ�ʱ����RRMM_AT_MSG_IND���� */
                Sta_ModeChangeEventReport(TAF_PH_INFO_WCDMA_RAT, TAF_SYS_SUBMODE_WCDMA);

#if (FEATURE_ON == FEATURE_PTM)
                TAF_MMA_RatSwitchRecord(TAF_PH_INFO_WCDMA_RAT);
#endif
            }
            else
            {
                /* G->TD�£����ϱ�ȱʡģʽ: ^MODE:15,8,�����ϱ�ʱ����RRMM_AT_MSG_IND���� */
                Sta_ModeChangeEventReport(TAF_PH_INFO_TD_SCDMA_RAT, TAF_SYS_SUBMODE_TD_SCDMA);

#if (FEATURE_ON == FEATURE_PTM)
                TAF_MMA_RatSwitchRecord(TAF_PH_INFO_TD_SCDMA_RAT);
#endif
            }

            /* ����ȫ�ֱ����б����UtranMode */
            g_StatusContext.ucPreUtranMode = NAS_UTRANCTRL_GetCurrUtranMode();
        }
        else if (TAF_SDC_SYS_MODE_GSM == enCurNetWork)
        {
            Sta_ModeChangeEventReport(TAF_PH_INFO_GSM_RAT, ucSysSubMode);

#if (FEATURE_ON == FEATURE_PTM)
            TAF_MMA_RatSwitchRecord(TAF_PH_INFO_GSM_RAT);
#endif
        }
        else if (TAF_SDC_SYS_MODE_LTE == enCurNetWork)
        {
            Sta_ModeChangeEventReport(TAF_PH_INFO_LTE_RAT, ucSysSubMode);

#if (FEATURE_ON == FEATURE_PTM)
            TAF_MMA_RatSwitchRecord(TAF_PH_INFO_LTE_RAT);
#endif
        }

#if (FEATURE_ON == FEATURE_UE_MODE_CDMA)
        else if (TAF_SDC_SYS_MODE_CDMA_1X == enCurNetWork)
        {
            Sta_ModeChangeEventReport(TAF_PH_INFO_CDMA_1X_RAT, ucSysSubMode);
        }
        else if (TAF_SDC_SYS_MODE_EVDO == enCurNetWork)
        {
            Sta_ModeChangeEventReport(TAF_PH_INFO_HRPD_RAT, ucSysSubMode);
        }
        else if (TAF_SDC_SYS_MODE_HYBRID == enCurNetWork)
        {
            Sta_ModeChangeEventReport(TAF_PH_INFO_HYBRID_RAT, ucSysSubMode);
        }
#endif
        else if (TAF_SDC_SYS_MODE_SVLTE == enCurNetWork)
        {
            Sta_ModeChangeEventReport(TAF_PH_INFO_SVLTE_SRLTE_RAT, ucSysSubMode);
        }
        else
        {
            Sta_ModeChangeEventReport(TAF_PH_INFO_NONE_RAT, TAF_SYS_SUBMODE_NONE);
        }
    }

    /* Modified by z00161729 for �����ϱ�AT�������������C��, 2013-4-7, end */
    return;
}

/* Added by l00208543 for V9R1 STK����, 2013-07-22, begin */
/*****************************************************************************
 �� �� ��  : TAF_MMA_ConvertMmaRatToStkRat
 ��������  : ��MMA��Rat Typeת�����ϱ���STK��Rat Type
 �������  : TAF_SDC_SYS_MODE_ENUM_UINT8    enCurNetWork
 �������  : ��
 �� �� ֵ  :
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2013��7��22��
    ��    ��   : l00208543
    �޸�����   : �����ɺ���

  2.��    ��   : 2015��4��10��
    ��    ��   : h00313353
    �޸�����   : SysCfg�ع�
*****************************************************************************/
TAF_MMA_RAT_TYPE_ENUM_UINT8 TAF_MMA_ConvertMmaRatToStkRat(
                                         TAF_SDC_SYS_MODE_ENUM_UINT8 enMmaRatType
                                         )
{
    switch (enMmaRatType)
    {
        case TAF_SDC_SYS_MODE_GSM:
             return TAF_MMA_RAT_GSM;

        case TAF_SDC_SYS_MODE_WCDMA:
             return TAF_MMA_RAT_WCDMA;

        case TAF_SDC_SYS_MODE_LTE:
             return TAF_MMA_RAT_LTE;

        default:
            MN_ERR_LOG("TAF_MMA_ConvertMmaRatToStkRat: The input is invalid");
            return TAF_MMA_RAT_BUTT;
    }
}
/* Added by l00208543 for V9R1 STK����, 2013-07-22, end */

/* Deleted by z00161729 for V9R1 STK����, 2013-7-24, begin */
/* ɾ��TAF_MMA_SndStkAccTechChgEvt */
/* Deleted by z00161729 for V9R1 STK����, 2013-7-24, end */

/*****************************************************************************
 �� �� ��  : Sta_MmInfo
 ��������  : ����MM INFO��Ϣ�ϱ�
 �������  : MSCC_MMA_MM_INFO_IND_STRU *pstMmInfo - MM INFO�ṹָ��
 �������  : ��
 �� �� ֵ  :
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2010��3��23��
    ��    ��   : o00132663
    �޸�����   : �����ɺ���
  2.��    ��   : 2013��4��3��
    ��    ��   : z00161729
    �޸�����   : �����ϱ�AT�������������C�˼�mma��mmc�ӿڵ���
  3.��    ��   : 2012��07��15��
    ��    ��   : w00176964
    �޸�����   : VoLTE_PhaseI��Ŀ�޸�:�޸ĺ��������ͷ���ֵ
  4.��    ��   : 2015��2��25��
    ��    ��   : z00161729
    �޸�����   : AT&T ֧��EONS�����޸�
*****************************************************************************/
VOS_UINT32 Sta_MmInfo(
    VOS_UINT32                          ulEventType,
    struct MsgCB                       *pstMsg
)
{
    /* Modified by w00176964 for VoLTE_PhaseI��Ŀ, 2013-7-15, begin */
    TAF_MMA_TIME_CHANGE_IND_STRU        *pstTimeChangeInd      = VOS_NULL_PTR;
    MSCC_MMA_MM_INFO_IND_STRU           *pstMmInfo             = VOS_NULL_PTR;
    TAF_SDC_CURC_RPT_CTRL_STRU          *pstCurcRptCtrl        = VOS_NULL_PTR;
    TAF_SDC_UNSOLICITED_RPT_CTRL_STRU   *pstUnsolicitedRptCtrl = VOS_NULL_PTR;
    TAF_SDC_MM_INFO_STRU                *pstSdcMmInfo = VOS_NULL_PTR;

    pstSdcMmInfo = TAF_SDC_GetMmInfo();

    pstMmInfo             = (MSCC_MMA_MM_INFO_IND_STRU*)pstMsg;
    pstCurcRptCtrl        = TAF_SDC_GetCurcRptCtrl();
    pstUnsolicitedRptCtrl = TAF_SDC_GetUnsolicitedRptCtrl();

    if ( VOS_TRUE != TAF_MMA_IsTimeChangeNeedRpt())
    {
        return VOS_TRUE;
    }

    pstTimeChangeInd = (TAF_MMA_TIME_CHANGE_IND_STRU *)PS_ALLOC_MSG_WITH_HEADER_LEN(WUEPS_PID_MMA, sizeof(TAF_MMA_TIME_CHANGE_IND_STRU));

    if (VOS_NULL_PTR == pstTimeChangeInd)
    {
        MMA_ERRORLOG("Sta_MmInfo:ERROR:ALLOC MEMORY FAIL.");
        return VOS_TRUE;
    }

    PS_MEM_SET((VOS_CHAR *)pstTimeChangeInd + VOS_MSG_HEAD_LENGTH,
            0x00,
            (sizeof(TAF_MMA_TIME_CHANGE_IND_STRU) - VOS_MSG_HEAD_LENGTH));

    pstTimeChangeInd->MsgHeader.ulReceiverPid          = WUEPS_PID_AT;
    pstTimeChangeInd->MsgHeader.ulMsgName              = ID_TAF_MMA_TIME_CHANGE_IND;

    /* Modified by z00161729 for �����ϱ�AT�������������C��, 2013-4-3, begin */
    pstSdcMmInfo->stOperatorPlmnId.ulMcc        = pstMmInfo->stName.stOperatorPlmnId.ulMcc;
    pstSdcMmInfo->stOperatorPlmnId.ulMnc        = pstMmInfo->stName.stOperatorPlmnId.ulMnc;

    pstSdcMmInfo->stOperatorNameLong.ucLength   = 0;

    if (0 != pstMmInfo->stName.aucOperatorNameLong[0])
    {
        pstSdcMmInfo->stOperatorNameLong.ucLength   = pstMmInfo->stName.aucOperatorNameLong[0] - 1;
        pstSdcMmInfo->stOperatorNameLong.bitExt     = (pstMmInfo->stName.aucOperatorNameLong[1] & 0x80) >> TAF_SDC_OCTET_MOVE_SEVEN_BITS;
        pstSdcMmInfo->stOperatorNameLong.bitCoding  = (pstMmInfo->stName.aucOperatorNameLong[1] & 0x70) >> TAF_SDC_OCTET_MOVE_FOUR_BITS;
        pstSdcMmInfo->stOperatorNameLong.bitSpare   = pstMmInfo->stName.aucOperatorNameLong[1] & 0x07;
        pstSdcMmInfo->stOperatorNameLong.bitAddCi   = pstMmInfo->stName.aucOperatorNameLong[1] & 0x08;

        if (pstSdcMmInfo->stOperatorNameLong.ucLength > TAF_SDC_MAX_OPER_NAME_NUM)
        {
            pstSdcMmInfo->stOperatorNameLong.ucLength = TAF_SDC_MAX_OPER_NAME_NUM;
        }

    }

    pstSdcMmInfo->stOperatorNameShort.ucLength = 0;

    if (0 != pstMmInfo->stName.aucOperatorNameShort[0])
    {
        pstSdcMmInfo->stOperatorNameShort.ucLength  = pstMmInfo->stName.aucOperatorNameShort[0] - 1;
        pstSdcMmInfo->stOperatorNameShort.bitExt    = (pstMmInfo->stName.aucOperatorNameShort[1] & 0x80) >> TAF_SDC_OCTET_MOVE_SEVEN_BITS;
        pstSdcMmInfo->stOperatorNameShort.bitCoding = (pstMmInfo->stName.aucOperatorNameShort[1] & 0x70) >> TAF_SDC_OCTET_MOVE_FOUR_BITS;
        pstSdcMmInfo->stOperatorNameShort.bitSpare  = pstMmInfo->stName.aucOperatorNameShort[1] & 0x07;
        pstSdcMmInfo->stOperatorNameShort.bitAddCi  = pstMmInfo->stName.aucOperatorNameShort[1] & 0x08;

        if (pstSdcMmInfo->stOperatorNameShort.ucLength > TAF_SDC_MAX_OPER_NAME_NUM)
        {
            pstSdcMmInfo->stOperatorNameShort.ucLength = TAF_SDC_MAX_OPER_NAME_NUM;
        }
    }

    PS_MEM_CPY(pstSdcMmInfo->stOperatorNameLong.aucOperatorName, &pstMmInfo->stName.aucOperatorNameLong[2], pstSdcMmInfo->stOperatorNameLong.ucLength);
    PS_MEM_CPY(pstSdcMmInfo->stOperatorNameShort.aucOperatorName, &pstMmInfo->stName.aucOperatorNameShort[2], pstSdcMmInfo->stOperatorNameShort.ucLength);
    PS_MEM_CPY(pstTimeChangeInd->aucLSAID, pstMmInfo->aucLSAID, sizeof(pstTimeChangeInd->aucLSAID));
    pstTimeChangeInd->stUniversalTimeandLocalTimeZone  = pstMmInfo->stUniversalTimeandLocalTimeZone;
    pstTimeChangeInd->cLocalTimeZone                   = pstMmInfo->cLocalTimeZone;
    pstTimeChangeInd->ucDST                            = pstMmInfo->ucDST;
    pstTimeChangeInd->ucIeFlg                          = pstMmInfo->ucIeFlg;
    pstTimeChangeInd->usClientId                       = MN_GetRealClientId(MMA_CLIENTID_BROADCAST, WUEPS_PID_TAF);
    pstTimeChangeInd->ucOpId                           = MMA_OP_ID_INTERNAL;
    PS_MEM_CPY(pstTimeChangeInd->aucCurcRptCfg, pstCurcRptCtrl->aucRptCfg, TAF_MMA_RPT_CFG_MAX_SIZE);
    PS_MEM_CPY(pstTimeChangeInd->aucUnsolicitedRptCfg, pstUnsolicitedRptCtrl->aucRptCfg, TAF_MMA_RPT_CFG_MAX_SIZE);
    /* Modified by s00217060 for �����ϱ�AT�������������C��, 2013-4-3, end */

    PS_SEND_MSG(WUEPS_PID_MMA, pstTimeChangeInd);
    /* Modified by z00161729 for �����ϱ�AT�������������C��, 2013-4-3, end */
    return VOS_TRUE;
    /* Modified by w00176964 for VoLTE_PhaseI��Ŀ, 2013-7-15, end */
}

/*****************************************************************************
 �� �� ��  : TAF_MMA_ConvertServiceTypeToAtType
 ��������  : ��MMA��PlmnSelRsltת�����ϱ���At��PlmnSelRslt Type
 �������  : TAF_SDC_SYS_MODE_ENUM_UINT8    enCurNetWork
 �������  : ��
 �� �� ֵ  :
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2013��7��22��
    ��    ��   : l00208543
    �޸�����   : �����ɺ���

*****************************************************************************/

TAF_PH_PLMN_SELECTION_RESULT_ENUM_UINT32 TAF_MMA_ConvertServiceTypeToAtType(
    NAS_MSCC_PIF_PLMN_SELECTION_RESULT_ENUM_UINT32 enMmaServiceType
)
{
    switch (enMmaServiceType)
    {
        case NAS_MSCC_PIF_PLMN_SELECTION_RESULT_NORMAL_SERVICE:
             return TAF_PH_PLMN_SELECTION_RESULT_NORMAL_SERVICE;

        case NAS_MSCC_PIF_PLMN_SELECTION_RESULT_LIMITED_SERVICE:
             return TAF_PH_PLMN_SELECTION_RESULT_LIMITED_SERVICE;

        case NAS_MSCC_PIF_PLMN_SELECTION_RESULT_NO_SERVICE:
             return TAF_PH_PLMN_SELECTION_RESULT_NO_SERVICE;

        case NAS_MSCC_PIF_PLMN_SELECTION_RESULT_INTERRUPT:
        case NAS_MSCC_PIF_PLMN_SELECTION_RESULT_NO_RF:
             return TAF_PH_PLMN_SELECTION_RESULT_INTERRUPT;

        default:
            MN_ERR_LOG("TAF_MMA_ConvertServiceTypeToAtType: The input is invalid");
            return TAF_PH_PLMN_SELECTION_RESULT_BUTT;
    }
}



/*****************************************************************************
 �� �� ��  : MN_PH_GetRegCostTime
 ��������  : ���ص�ǰ���������ɹ�ע�Ứ�ѵ�ʱ��
 �������  : ��
 �������  : VOS_UINT32:��������ע�Ứ�ѵ�ʱ��,��λΪs
 �� �� ֵ  :
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2010��9��8��
    ��    ��   : zhoujun /40661
    �޸�����   : �����ɺ���

*****************************************************************************/
VOS_UINT32  MN_PH_GetRegCostTime( VOS_VOID )
{
    return g_stRegTimeInfo.ulCostTime;
}

/* Deleted by z00161729 for �����ϱ�AT�������������C��, 2013-4-4, begin */
/* Deleted by z00161729 for �����ϱ�AT�������������C��, 2013-4-4, end */

/*****************************************************************************
 �� �� ��  : MMA_GetCurrPhMode
 ��������  : ��ȡ��ǰ�ֻ�ģʽ
 �������  : VOS_VOID
 �������  : ��
 �� �� ֵ  : TAF_PH_MODE
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2012��2��15��
    ��    ��   : A00165503
    �޸�����   : �����ɺ���

*****************************************************************************/
TAF_PH_MODE MMA_GetCurrPhMode(VOS_VOID)
{
    /* Modified by w00176964 for VoLTE_PhaseI��Ŀ, 2013-7-12, begin */
    return TAF_SDC_GetCurPhoneMode();
    /* Modified by w00176964 for VoLTE_PhaseI��Ŀ, 2013-7-12, end */
}

/* Deleted by w00176964 for VoLTE_PhaseI��Ŀ, 2013-7-11, begin */

/* Deleted by w00176964 for VoLTE_PhaseI��Ŀ, 2013-7-11, end */

/*****************************************************************************
 �� �� ��  : TAF_MMA_ReportPlmnModeEvent
 ��������  : �ϱ�+PACSP
 �������  : VOS_UINT8 ucPlmnMode
 �������  : ��
 �� �� ֵ  : VOS_VOID
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2012��6��13��
    ��    ��   : l60609
    �޸�����   : �����ɺ���

*****************************************************************************/
VOS_VOID TAF_MMA_ReportPlmnModeEvent(VOS_UINT8 ucPlmnMode)
{
    TAF_PHONE_EVENT_INFO_STRU          *pstPhoneEvent = VOS_NULL_PTR;

    pstPhoneEvent = (TAF_PHONE_EVENT_INFO_STRU *)PS_MEM_ALLOC(WUEPS_PID_MMA, sizeof(TAF_PHONE_EVENT_INFO_STRU));

    if (VOS_NULL_PTR == pstPhoneEvent)
    {
        MMA_ERRORLOG("TAF_MMA_ReportPlmnModeEvent:ERROR:ALLOC MEMORY FAIL.");
        return;
    }

    PS_MEM_SET(pstPhoneEvent, 0, sizeof(TAF_PHONE_EVENT_INFO_STRU));

    pstPhoneEvent->OP_PlmnMode  = VOS_TRUE;
    pstPhoneEvent->PhoneEvent   = TAF_PH_EVT_NSM_STATUS_IND;
    pstPhoneEvent->ucPlmnMode   = ucPlmnMode;

    Taf_PhoneEvent(pstPhoneEvent);

    PS_MEM_FREE(WUEPS_PID_MMA, pstPhoneEvent);

    return;
}

/*****************************************************************************
 �� �� ��  : TAF_MMA_IsEnablePlmnList
 ��������  : ���ݵ�ǰ״̬���ж��Ƿ������û�����list��������
 �������  : VOS_VOID
 �������  : ��
 �� �� ֵ  : VOS_UINT32
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2012��6��13��
    ��    ��   : l60609
    �޸�����   : �����ɺ���

*****************************************************************************/
VOS_UINT32 TAF_MMA_IsEnablePlmnList(VOS_VOID)
{
    TAF_MMA_AUTO_PLMN_SEL_USER_ENUM_UINT8 enAutoPlmnSelUser;

    enAutoPlmnSelUser = TAF_MMA_GetAutoPlmnSelUser();

    if (STA_FSM_ENABLE == g_StatusContext.ulFsmState)
    {
        return VOS_TRUE;
    }

    /* refresh�������Զ����� */
    if ((STA_FSM_PLMN_RESEL == g_StatusContext.ulFsmState)
     && (TAF_MMA_AUTO_PLMN_SEL_USER_USIM_REFRESH == enAutoPlmnSelUser))
    {
        return VOS_TRUE;
    }

    return VOS_FALSE;
}

/*****************************************************************************
 �� �� ��  : TAF_MMA_IsEnablePlmnSelect
 ��������  : ���ݵ�ǰ״̬���ж��Ƿ������û�����ָ����������
 �������  : VOS_VOID
 �������  : ��
 �� �� ֵ  : VOS_UINT32
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2012��6��15��
    ��    ��   : l60609
    �޸�����   : �����ɺ���

*****************************************************************************/
VOS_UINT32 TAF_MMA_IsEnablePlmnSelect(VOS_VOID)
{
    TAF_MMA_PLMN_MODE_ENUM_UINT8        enPlmnMode;

    enPlmnMode = TAF_MMA_GetPlmnMode_Refresh();

    /* ֻ����ENABLE״̬����������û��disable������ѡ��˵������ܽ���ָ������ */
    if ((STA_FSM_ENABLE == g_StatusContext.ulFsmState)
     && (TAF_MMA_PLMN_MODE_ENUM_ENABLE == enPlmnMode))
    {
        return VOS_TRUE;
    }

    return VOS_FALSE;
}

/*****************************************************************************
 �� �� ��  : TAF_MMA_IsEnableDeAttach
 ��������  : ���ݵ�ǰ״̬���ж��Ƿ������û�����ATTACH��DETACH����
 �������  : VOS_VOID
 �������  : ��
 �� �� ֵ  : VOS_UINT32
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2012��6��13��
    ��    ��   : l60609
    �޸�����   : �����ɺ���

*****************************************************************************/
VOS_UINT32 TAF_MMA_IsEnableDeAttach(VOS_VOID)
{
    TAF_MMA_AUTO_PLMN_SEL_USER_ENUM_UINT8 enAutoPlmnSelUser;

    enAutoPlmnSelUser = TAF_MMA_GetAutoPlmnSelUser();

    if (STA_FSM_ENABLE == g_StatusContext.ulFsmState)
    {
        return VOS_TRUE;
    }



    /* refresh�������Զ����� */
    if ((STA_FSM_PLMN_RESEL == g_StatusContext.ulFsmState)
     && (TAF_MMA_AUTO_PLMN_SEL_USER_USIM_REFRESH == enAutoPlmnSelUser))
    {
        return VOS_TRUE;
    }

    /* refresh������SYSCFG�����յ�CNF֮����ܻᴥ��attach��
       ��ʱ�û��·�attach����detach�����ܴ��SYSCFG��
       ����MMAĿǰû�л�����ƣ�����ֱ�Ӹ��û�����ERROR��
    */

    return VOS_FALSE;
}


/*****************************************************************************
 �� �� ��  : TAF_MMA_SndAutoPlmnReselect_Refresh
 ��������  : ����Refresh�������Զ���������
 �������  : VOS_VOID
 �������  : ��
 �� �� ֵ  : ��
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2012��6��14��
    ��    ��   : l60609
    �޸�����   : �����ɺ���
  2.��    ��   : 2013��4��1��
    ��    ��   : z00161729
    �޸�����   : �����ϱ�AT�������������C�˼�mma��mscc�ӿڵ���
*****************************************************************************/
VOS_VOID TAF_MMA_SndAutoPlmnReselect_Refresh(VOS_VOID)
{
    VOS_UINT32                          ulRet;

    /* Modified by z00161729 for �����ϱ�AT�������������C��, 2013-4-1, begin */
    ulRet = TAF_MMA_SndMsccPlmnUserReselReq(NAS_MSCC_PIF_PLMN_SEL_MODE_AUTO);

    if (VOS_ERR == ulRet)
    {
        NAS_ERROR_LOG(WUEPS_PID_MMA, "TAF_MMA_SndAutoPlmnReselect_Refresh(): send msg fail");
        return;
    }

    /* ��¼PLMN�������� */
    g_StatusContext.ucReselMode   = NAS_MSCC_PIF_PLMN_SEL_MODE_AUTO;
    /* Modified by z00161729 for �����ϱ�AT�������������C��, 2013-4-1, end */

    /* ��¼��ǰ����״̬ */
    g_StatusContext.ulPreFsmState = g_StatusContext.ulFsmState;

    /* ������״̬ */
    g_StatusContext.ulFsmState    = STA_FSM_PLMN_RESEL;

    /* ������״̬ */
    g_StatusContext.aucFsmSubFlag[0]         = STA_FSMSUB_PLMN_RESEL_AUTO;
    g_StatusContext.aFsmSub[0].ucFsmStateSub = STA_FSMSUB_PLMN_RESEL_AUTO;
    g_StatusContext.aFsmSub[0].TimerName     = STA_TIMER_PLMN_RESEL;

    /* ����PLMN_RESEL״̬��ʱ�� */
    ulRet = NAS_StartRelTimer(&g_StatusContext.ahStaTimer[0],
                              WUEPS_PID_MMA,
                              aStaTimerLen[STA_TIMER_PLMN_RESEL],
                              TAF_MMA,
                              MMA_MAKELPARAM(0, STA_TIMER_PLMN_RESEL),
                              VOS_RELTIMER_NOLOOP
                              );
    if (VOS_OK != ulRet)
    {
        NAS_ERROR_LOG(WUEPS_PID_MMA, "TAF_MMA_SndAutoPlmnReselect_Refresh(): start timer fail");
        return;
    }

    return;
}


/*****************************************************************************
 �� �� ��  : TAF_MMA_RcvMsccPlmnReselCnf
 ��������  : MMA��at+cops=0�Ļظ��Ĵ���
 �������  : MSCC_MMA_PLMN_RESEL_CNF_STRU *pstMsg
 �������  : ��
 �� �� ֵ  : VOS_UINT32
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2012��6��14��
    ��    ��   : l60609
    �޸�����   : �����ɺ���
  2.��    ��   : 2013��4��2��
    ��    ��   : z00161729
    �޸�����   : �����ϱ�AT�������������C�˼�mma��mscc�ӿڵ���
  3.��    ��   : 2012��07��15��
    ��    ��   : w00176964
    �޸�����   : VoLTE_PhaseI��Ŀ�޸�:�޸ĺ��������ͷ���ֵ

*****************************************************************************/
VOS_UINT32 TAF_MMA_RcvMsccPlmnReselCnf(
    VOS_UINT32                          ulEventType,
    struct MsgCB                       *pstMsg
)
{
    /* Modified by w00176964 for VoLTE_PhaseI��Ŀ, 2013-7-15, begin */
    MSCC_MMA_PLMN_RESEL_CNF_STRU        *pstPlmnReselCnfMsg;

    pstPlmnReselCnfMsg = (MSCC_MMA_PLMN_RESEL_CNF_STRU*)pstMsg;

    /* ֹͣ������ʱ�� */
    TAF_MMA_StopTimer(TI_TAF_MMA_WAIT_MSCC_PLMN_AUTO_RESEL_CNF);

    /* Modified by z00161729 for �����ϱ�AT�������������C��, 2013-4-2, begin */
    TAF_MMA_SetPlmnSelectionMode(TAF_PH_PLMN_SEL_MODE_AUTO);

    /* �����6F15�ļ�refresh�������Զ����� */
    if (TAF_MMA_AUTO_PLMN_SEL_USER_USIM_REFRESH == TAF_MMA_GetAutoPlmnSelUser())
    {
        /* MSCC��MMA�ظ�ָ���Ѻ��Զ��Ѷ���D_MSCC_PLMN_SEL_CNF��Ϣ��refreshֻ�ᴥ���Զ����� */
        if (STA_FSM_PLMN_RESEL != g_StatusContext.ulFsmState)
        {
            return VOS_TRUE;
        }

        g_StatusContext.ulFsmState = STA_FSM_ENABLE;
    }
    /* AT������Զ�������ָ����������ԭ������ */
    else
    {
        (VOS_VOID)Sta_SelPlmnAutoSelCnf(pstPlmnReselCnfMsg->enResult);
    }

    /* Modified by z00161729 for �����ϱ�AT�������������C��, 2013-4-2, end */

    return VOS_TRUE;
    /* Modified by w00176964 for VoLTE_PhaseI��Ŀ, 2013-7-15, end */
}

/*****************************************************************************
 �� �� ��  : TAF_MMA_RcvMsccPlmnSpecialSelCnf
 ��������  : MMA�յ�MSCC �û�ָ�������ظ���Ϣ
 �������  : MMA_MSCC_PLMN_SPECIAL_REQ_STRU *pstMsg
 �������  : ��
 �� �� ֵ  : VOS_UINT32
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2013��4��2��
    ��    ��   : z00161729
    �޸�����   : �����ɺ���
  2.��    ��   : 2012��07��15��
    ��    ��   : w00176964
    �޸�����   : VoLTE_PhaseI��Ŀ�޸�:�޸ĺ��������ͷ���ֵ
  3.��    ��   : 2013��11��1��
    ��    ��   : z00161729
    �޸�����   : DTS2013111103301: svlte��Ҫ�ػ�״̬֧��cops���ã�����nv������ģʽ
  4.��    ��   : 2014��3��7��
    ��    ��   : w00176964
    �޸�����   : DTS2014030610626:�ػ�ģʽ�����ֶ�ģʽ��Ҫˢ��ȫ�ֱ���

*****************************************************************************/
VOS_UINT32 TAF_MMA_RcvMsccPlmnSpecialSelCnf(
    VOS_UINT32                          ulEventType,
    struct MsgCB                       *pstMsg
)
{
    /* Modified by w00176964 for VoLTE_PhaseI��Ŀ, 2013-7-15, begin */
    MSCC_MMA_PLMN_SPECIAL_SEL_CNF_STRU  *pstPlmnSpecSelCnfMsg;

    pstPlmnSpecSelCnfMsg = (MSCC_MMA_PLMN_SPECIAL_SEL_CNF_STRU*)pstMsg;

    /* ֹͣ������ʱ�� */
    TAF_MMA_StopTimer(TI_TAF_MMA_WAIT_MSCC_PLMN_SPECIAL_SEL_CNF);

    /* svlte nv���������ػ�״̬����cops */
    if (TAF_PH_MODE_FULL != TAF_SDC_GetCurPhoneMode())
    {
        TAF_MMA_SetPlmnSelectionMode(NAS_MSCC_PIF_PLMN_SEL_MODE_MANUAL);

        TAF_MMA_ProcPlmnSpecialSelCnf(TAF_ERR_NO_ERROR);

        return VOS_TRUE;
    }

    /* Modified by z00161729 for �����ϱ�AT�������������C��, 2013-4-2, begin */
    TAF_MMA_SetPlmnSelectionMode(TAF_PH_PLMN_SEL_MODE_MANUAL);

    (VOS_VOID)Sta_SelPlmnSpecializeCnf(pstPlmnSpecSelCnfMsg->enResult);

    /* Modified by z00161729 for �����ϱ�AT�������������C��, 2013-4-2, end */

    return VOS_TRUE;
    /* Modified by w00176964 for VoLTE_PhaseI��Ŀ, 2013-7-15, end */
}

/*****************************************************************************
 �� �� ��  : TAF_MMA_StopStatusCtxTimer
 ��������  : ֹͣ״̬���Ķ�ʱ��
 �������  : VOS_VOID
 �������  : ��
 �� �� ֵ  : VOS_VOID
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2012��6��20��
    ��    ��   : l60609
    �޸�����   : �����ɺ���

*****************************************************************************/
VOS_VOID TAF_MMA_StopStatusCtxTimer(VOS_VOID)
{
    VOS_UINT32                            ulRet;

    /* �رյ�ǰ״̬�Ķ�ʱ������*/
    if (VOS_NULL != g_StatusContext.ahStaTimer[0])
    {
        ulRet = NAS_StopRelTimer(WUEPS_PID_MMA,
                                 g_StatusContext.aFsmSub[0].TimerName,
                                 &g_StatusContext.ahStaTimer[0]);
        if ( VOS_OK != ulRet )
        {
            STA_TRACE (STA_WARNING_PRINT,
                "TAT_MMA_ProcPhoneStop_NotEnableStatus():WARNING:NAS_StopRelTimer failed  ");
        }
        g_StatusContext.ahStaTimer[0] = VOS_NULL;
    }

    if ( VOS_NULL != g_StatusContext.ahStaTimer[1] )
    {
        ulRet = NAS_StopRelTimer(WUEPS_PID_MMA,
                                 g_StatusContext.aFsmSub[1].TimerName,
                                 &g_StatusContext.ahStaTimer[1]);


        if ( VOS_OK != ulRet )
        {
            STA_TRACE (STA_WARNING_PRINT,
                "TAT_MMA_ProcPhoneStop_NotEnableStatus():WARNING:NAS_StopRelTimer failed  ");
        }
        g_StatusContext.ahStaTimer[1] = VOS_NULL;
    }
}

/*****************************************************************************
 �� �� ��  : TAF_MMA_ProcPhoneStop_NotEnableStatus
 ��������  : �ڷ�ENABLE״̬������Э��ջֹͣ�ĺ���
 �������  : VOS_VOID
 �������  : ��
 �� �� ֵ  : ��
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2012��6��15��
    ��    ��   : l60609
    �޸�����   : �����ɺ���

*****************************************************************************/
VOS_VOID TAF_MMA_ProcPhoneStop_NotEnableStatus(VOS_VOID)
{
    VOS_UINT32                            ulRet;
    VOS_UINT32                            ulIsRefreshAutoPlmnSel;
    TAF_MMA_AUTO_PLMN_SEL_USER_ENUM_UINT8 enAutoPlmnSelUser;

    enAutoPlmnSelUser = TAF_MMA_GetAutoPlmnSelUser();

    ulIsRefreshAutoPlmnSel = VOS_FALSE;

    /* refresh�������Զ����� */
    if ((STA_FSM_PLMN_RESEL == g_StatusContext.ulFsmState)
     && (TAF_MMA_AUTO_PLMN_SEL_USER_USIM_REFRESH == enAutoPlmnSelUser))
    {
        ulIsRefreshAutoPlmnSel = VOS_TRUE;
    }

    /* �����SYSCFG���̣���SYSCFG״̬���д���abort���˴�ɾ�� */

    /* �����Refresh�������Զ�����������Ҫ�ϱ���Ӧ�¼�֪ͨAPP*/
    if (VOS_TRUE != ulIsRefreshAutoPlmnSel)
    {
        /* ��ֹ��ǰ��������̣��ϱ���Ӧ�¼�֪ͨAPP */
        ulRet = Sta_MsgReqAbort (STA_MSGABORT_ERR);
        if (STA_ERROR == ulRet)
        {
            NAS_WARNING_LOG(WUEPS_PID_MMA,
                "TAF_MMA_ProcPhoneStop_NotEnableStatus(): different request abort failed  ");
        }
    }

    TAF_MMA_StopStatusCtxTimer();

    return;
}

/*****************************************************************************
 �� �� ��  : TAF_MMA_DeleteRatType
 ��������  : �ӽ��뼼���б���ɾ��ָ����ģʽ
 �������  : TAF_MMA_RAT_TYPE_ENUM_UINT8           ucRatType
             MMA_MSCC_PLMN_RAT_PRIO_STRU           *pstPlmnRatPrioList
 �������  : ��
 �� �� ֵ  : VOS_VOID
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2012��6��28��
    ��    ��   : l60609
    �޸�����   : �����ɺ���
  2.��    ��   : 2013��4��4��
    ��    ��   : z00161729
    �޸�����   : �����ϱ�AT�������������C�˼�mma��mscc�ӿڵ���
  3.��    ��   : 2013��07��222��
    ��    ��   : j00177245
    �޸�����   : ����Coverity
*****************************************************************************/
VOS_VOID TAF_MMA_DeleteRatType(
    TAF_MMA_RAT_TYPE_ENUM_UINT8          ucRatType,
    TAF_MMA_RAT_ORDER_STRU              *pstPlmnRatPrioList
)
{
    VOS_UINT32                          i;

    /* Modified by z00161729 for �����ϱ�AT�������������C��, 2013-4-4, begin */
    TAF_MMA_RAT_ORDER_STRU              stOldPlmnRatPrioList;

    PS_MEM_SET(&stOldPlmnRatPrioList, 0, sizeof(TAF_MMA_RAT_ORDER_STRU));

    /* ��¼����Ľ��뼼���б� */
    PS_MEM_CPY(&stOldPlmnRatPrioList, pstPlmnRatPrioList, sizeof(TAF_MMA_RAT_ORDER_STRU));


    pstPlmnRatPrioList->ucRatOrderNum = 0;

    /* ���뼼����ʼ��ΪBUTT */
    for (i = 0 ; i < TAF_PH_MAX_GUL_RAT_NUM; i++)
    {
        pstPlmnRatPrioList->aenRatOrder[i] = TAF_SDC_SYS_MODE_BUTT;
    }

    /* Modified by z00161729 for �����ϱ�AT�������������C��, 2013-4-4, end */

    if (stOldPlmnRatPrioList.ucRatOrderNum > TAF_PH_MAX_GUL_RAT_NUM)
    {
        stOldPlmnRatPrioList.ucRatOrderNum = TAF_PH_MAX_GUL_RAT_NUM;
    }

    for (i = 0 ; i < stOldPlmnRatPrioList.ucRatOrderNum; i++)
    {
        if (ucRatType == stOldPlmnRatPrioList.aenRatOrder[i])
        {
            continue;
        }
        pstPlmnRatPrioList->aenRatOrder[pstPlmnRatPrioList->ucRatOrderNum] = stOldPlmnRatPrioList.aenRatOrder[i];
        pstPlmnRatPrioList->ucRatOrderNum++;
    }

    return;
}
/*****************************************************************************
 �� �� ��  : TAF_MMA_GetAvailablePlmnRatPrio
 ��������  : ��ȡ��Ч�Ľ��뼼���б�
 �������  : MMA_MSCC_PLMN_RAT_PRIO_STRU *pstPlmnRatPrioList
 �������  : ��
 �� �� ֵ  : VOS_VOID
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2012��6��18��
    ��    ��   : l60609
    �޸�����   : �����ɺ���
  2.��    ��   : 2012��11��09��
    ��    ��   : s00217060
    �޸�����   : DTS2012102902559 ������SIM��ʱ��������SYSCFG��ΪLTE only��Ҳ��ɾ��Lģ
  3.��    ��   : 2012��12��11��
    ��    ��   : L00171473
    �޸�����   : DTS2012121802573, TQE����
  4.��    ��   : 2012��12��28��
    ��    ��   : s46746
    �޸�����   : DSDA GUNAS C CORE��Ŀ������ƽ̨���뼼�������ж�
  5.��    ��   : 2013��3��26��
    ��    ��   : z00161729
    �޸�����   : �����ϱ�AT�������������C����Ŀ��mscc����ȫ�ֱ�������sdc
  6.��    ��   : 2013��6��5��
    ��    ��   : w00242748
    �޸�����   : svlte��usim�ӿڵ���
  7.��    ��   : 2015��4��10��
    ��    ��   : h00313353
    �޸�����   : SysCfg�ع�
*****************************************************************************/
VOS_VOID TAF_MMA_GetAvailablePlmnRatPrio(TAF_MMA_RAT_ORDER_STRU *pstPlmnRatPrioList)
{

    VOS_UINT32                          ulGsmAccessForbidden;
#if (FEATURE_ON == FEATURE_LTE)
    VOS_UINT8                           ucCardType;
    VOS_UINT32                          ulGsmForbidden;
    VOS_UINT8                           i;

    VOS_UINT8                           ucRatBalancingEnableFlg;

    ucRatBalancingEnableFlg = TAF_MMA_GetRatBalancingEnableFlg();

    ucCardType = 0;
#endif


    ulGsmAccessForbidden = TAF_MMA_IsGsmAccessForbidden();

    /* ���UE��֧��GSM���룬�����÷�G��ģȥ��Gģ�������G��ģ����MSCC�����ṩ���Ʒ��� */
    if ((VOS_FALSE == MN_MMA_IsGOnlyMode((TAF_MMA_RAT_ORDER_STRU *)pstPlmnRatPrioList))
     && (VOS_TRUE == ulGsmAccessForbidden))
    {
        TAF_MMA_DeleteRatType(TAF_MMA_RAT_GSM, pstPlmnRatPrioList);
    }

#if (FEATURE_ON == FEATURE_LTE)
    /* SIM��У��ȥ��Lģ */
    (VOS_VOID)NAS_USIMMAPI_GetCardType(VOS_NULL_PTR, &ucCardType) ;

    /* SIM��ʱ�������LTE only����ɾ��Lģ */
    if ( (USIMM_CARD_SIM == ucCardType)
      && (VOS_TRUE == ucRatBalancingEnableFlg) )
    {
        TAF_MMA_DeleteRatType(TAF_MMA_RAT_LTE, pstPlmnRatPrioList);
    }

    /* �������Ϊ0,����ǰ������L��ģҲ�����ֹʱ,Ĭ��ΪGWģ */
    if (0 == pstPlmnRatPrioList->ucRatOrderNum)
    {
        i = 0;
        if (VOS_TRUE == TAF_SDC_IsPlatformSupportUtran())
        {
            pstPlmnRatPrioList->aenRatOrder[i] = TAF_MMA_RAT_WCDMA;
            i ++;
        }

        ulGsmForbidden = MMA_IsGsmForbidden();
        if ((VOS_TRUE == TAF_SDC_IsPlatformSupportGsm())
         && ((VOS_FALSE == ulGsmForbidden)))
        {
            pstPlmnRatPrioList->aenRatOrder[i] = TAF_MMA_RAT_GSM;
            i ++;
        }
        pstPlmnRatPrioList->ucRatOrderNum      = i;
    }
#endif

    return;

}


/*****************************************************************************
 �� �� ��  : TAF_MMA_IsModeChange
 ��������  : �ж�ģʽ(����ϵͳģʽ��ϵͳ��ģʽ)�Ƿ�仯
 �������  : MSCC_CUR_NETWORK ucCurNetWork :��ǰ����
              VOS_UINT8       ucSysSubMode :ϵͳ��ģʽ
 �������  : ��
 �� �� ֵ  : VOS_FALSE :ģʽû�仯
              VOS_TRUE : ģʽ�仯
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2012��08��15��
    ��    ��   : s00217060
    �޸�����   : �����ɺ���
  2.��    ��   : 2013��4��3��
    ��    ��   : z00161729
    �޸�����   : �����ϱ�AT�������������C�˼�mma��mscc�ӿڵ���
  3.��    ��   : 2013��6��4��
    ��    ��   : z00161729
    �޸�����   : SVLTE ��usim�ӿڵ����޸�
  4.��    ��   : 2013��7��24��
    ��    ��   : z00161729
    �޸�����   : V9R1 STK�����޸�
*****************************************************************************/
VOS_UINT8 TAF_MMA_IsModeChange(
    TAF_SDC_SYS_MODE_ENUM_UINT8         enCurNetWork,
    VOS_UINT8                           ucSysSubMode
)
{
    VOS_UINT8                           ucModeChangeFlg;
    NAS_UTRANCTRL_UTRAN_MODE_ENUM_UINT8 enCurrUtranMode;

    enCurrUtranMode = NAS_UTRANCTRL_GetCurrUtranMode();

    ucModeChangeFlg = VOS_FALSE;

    /* ������뼼������ͬ����Ҫ�ϱ�Mode */
    /* Modified by z00161729 for �����ϱ�AT�������������C��, 2013-4-3, begin */
    if (enCurNetWork != TAF_SDC_GetSysMode())
    {
        ucModeChangeFlg = VOS_TRUE;
#ifndef __PS_WIN32_RECUR__
        /* Deleted by z00161729 for V9R1 STK����, 2013-7-24, begin */
        /* Deleted by z00161729 for V9R1 STK����, 2013-7-24, end */
#endif
    }
    /* ���뼼��ΪGʱ��ϵͳ��ģʽ��ͬʱ����Ҫ�ϱ�Mode */
    else if (TAF_SDC_SYS_MODE_GSM == enCurNetWork)
    {
        if (ucSysSubMode != TAF_SDC_GetSysSubMode())
        {
            ucModeChangeFlg = VOS_TRUE;
        }
    }

    /* ��ǰ����ΪWCDMAʱ���п���TD->W��W->TD,��Ҫ��һ���ж�UtranMode
       ���UtranMode�����仯����Ҫ�ϱ�Mode */
    else if (TAF_SDC_SYS_MODE_WCDMA == enCurNetWork)
    {
        if (enCurrUtranMode != g_StatusContext.ucPreUtranMode)
        {
            ucModeChangeFlg             = VOS_TRUE;
        }
    }

    else if ((TAF_SDC_SYS_MODE_CDMA_1X == enCurNetWork)
          || (TAF_SDC_SYS_MODE_EVDO    == enCurNetWork)
          || (TAF_SDC_SYS_MODE_HYBRID  == enCurNetWork))
    {
        if (ucSysSubMode != TAF_SDC_GetSysSubMode())
        {
            ucModeChangeFlg = VOS_TRUE;
        }
    }

    else
    {
    }

    /* Modified by z00161729 for �����ϱ�AT�������������C��, 2013-4-3, end */

    return ucModeChangeFlg;

}

/*****************************************************************************
 �� �� ��  : TAF_MMA_RcvMsccPlmnReselCnf
 ��������  : MMA�յ�MSCC D_MSCC_PLMN_SEL_CNF��Ϣ�Ĵ���
 �������  : MSCC_PLMN_SEL_CNF_ST *pstMsg
 �������  : ��
 �� �� ֵ  : VOS_UINT32
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2012��10��19��
    ��    ��   : z40661
    �޸�����   : �����ɺ���
  2.��    ��   : 2013��4��2��
    ��    ��   : z00161729
    �޸�����   : �����ϱ�AT�������������C�˼�mma��mscc�ӿڵ���
  3.��    ��   : 2012��07��15��
    ��    ��   : w00176964
    �޸�����   : VoLTE_PhaseI��Ŀ�޸�:�޸ĺ��������ͷ���ֵ
*****************************************************************************/
VOS_UINT32 TAF_MMA_RcvMsccUserPlmnRej(
    VOS_UINT32                          ulEventType,
    struct MsgCB                       *pstMsg
)
{
    /* ֹͣ������ʱ�� */
    TAF_MMA_StopTimer(TI_TAF_MMA_WAIT_MSCC_PLMN_SPECIAL_SEL_CNF);

    /* �ϱ���ǰָ������ʧ�� */
    MMA_NORMAILLOG("NAS_MN_ReportPlmnSrchResult():NORMAIL:SPECIALIZE THE PLMN FAILURE!");

    /* �ϱ�APP��ǰ״̬�¼� */
    TAF_MMA_ProcPlmnSpecialSelCnf(TAF_ERR_CMD_TYPE_ERROR);

    STA_TRACE(STA_NORMAL_PRINT, "NAS_MN_ReportPlmnSrchResult: TAF_PH_EVT_PLMN_SEL_CNF reported to AT!");

    g_StatusContext.ulFsmState = STA_FSM_ENABLE;
    /*modified by Y00213812 for DTS2012082204471 TQE����, 2012-08-10, end*/

    /* Modified by w00176964 for VoLTE_PhaseI��Ŀ, 2013-7-15, begin */
    return VOS_TRUE;

    /* Modified by w00176964 for VoLTE_PhaseI��Ŀ, 2013-7-15, end */
}




/*****************************************************************************
 �� �� ��  : TAF_MMA_RcvTimerPlmnListCnfExpired
 ��������  : Plmn List����ϵĴ���
 �������  : VOS_UINT32 OpId
 �������  : ��
 �� �� ֵ  : VOS_VOID
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2012��9��18��
    ��    ��   : s00217060
    �޸�����   : �����ɺ���
  2.��    ��   : 2013��4��1��
    ��    ��   : z00161729
    �޸�����   : �����ϱ�AT�������������C�˼�mma��mscc�ӿڵ���
*****************************************************************************/
VOS_VOID  TAF_MMA_RcvTimerPlmnListCnfExpired( VOS_UINT32 ulOpId )
{
    VOS_UINT32                          ulRet;

    /* ��ǰ״̬����PLMN LIST״̬��ֱ�ӷ��� */
    if ( STA_FSM_PLMN_LIST != g_StatusContext.ulFsmState )
    {
        STA_TRACE(STA_WARNING_PRINT, "TAF_MMA_RcvUserAbortPlmnList():WARNING: no plmn list searching");
        return;
    }

    /* MMA��LIST����������ʱ����ʱ��������MSCC����ֹͣLIST��������
       �յ�MSCC�Ļظ�������AT�ظ� */
    /*modified by Y00213812 for DTS2012082204471 TQE����, 2012-08-10, begin*/
    /* Modified by z00161729 for �����ϱ�AT�������������C��, 2013-4-1, begin */
    ulRet = TAF_MMA_SndMsccPlmnListAbortReq();

    if (VOS_ERR == ulRet)
    /* Modified by z00161729 for �����ϱ�AT�������������C��, 2013-4-1, end */
    {
        STA_TRACE(STA_ERROR_PRINT, "TAF_MMA_AbortPlmnList():ERROR: failed");
    }


    /* ����STA_TIMER_PLMN_LIST_ABORT 10s��ʱ���������ʱδ�յ�MSCC�Ļظ����ϱ�ATʧ�� */
    /* ����STA_TIMER_PLMN_LIST_ABORT 10s��ʱ���������ʱδ�յ�MSCC�Ļظ����ϱ�ATʧ�� */
    TAF_MMA_StartTimer(TI_TAF_MMA_WAIT_MSCC_ABORT_PLMN_LIST_CNF, TAF_MMA_GetPlmnListAbortTimerLen());

    /*modified by Y00213812 for DTS2012082204471 TQE����, 2012-08-10, end*/

    /* ���õ�ǰ���ڴ�����ʱ����ʱ���б��Ѵ�Ϲ��� */
    g_StatusContext.ucPlmnListAbortProc = TAF_MMA_PLMN_LIST_ABORT_PROCESSING_TIMEOUT;

    return;
}


/*****************************************************************************
 �� �� ��  : TAF_MMA_RcvPlmnListAbortReq_Main
 ��������  : Plmn List����ϵĴ���
 �������  : VOS_UINT32 OpId
 �������  : ��
 �� �� ֵ  : VOS_VOID
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2015��3��25��
    ��    ��   : f00279542
    �޸�����   : CDMA Iteration 11 �ع��޸�
*****************************************************************************/
VOS_UINT32  TAF_MMA_RcvPlmnListAbortReq_Main(
    VOS_UINT32                          ulEventType,
    struct MsgCB                       *pstMsg
)
{
    TAF_MMA_PLMN_LIST_ABORT_REQ_STRU    *pstPlmnListAbortMsg = VOS_NULL_PTR;
    VOS_UINT32                           ulRet;
    VOS_UINT8                            ucCtxIndex;

    pstPlmnListAbortMsg = (TAF_MMA_PLMN_LIST_ABORT_REQ_STRU *)pstMsg;

    /* MMA�ϱ�PLMN LIST CNF���б��Ѵ�϶Գ�ʱ����ǰ״̬�Ѳ���PLMN LIST״̬��
       ֱ�Ӹ�AT�ظ�TAF_PH_EVT_PLMN_LIST_ABORT_CNF */
    if ( STA_FSM_PLMN_LIST != g_StatusContext.ulFsmState )
    {
        STA_TRACE(STA_ERROR_PRINT, "TAF_MMA_RcvPlmnListAbortReq_Main():WARNING: no plmn list searching");

        /* �ϱ�AT��ǰ״̬�¼� */
        TAF_MMA_SndPlmnListAbortCnf(&pstPlmnListAbortMsg->stCtrl, TAF_ERR_NO_ERROR);

        return VOS_TRUE;
    }

    /* ��ʱ����ʱ����б��Ѻ��û�����б��ѶԳ�ʱ�����û����Ϊ׼ */
    if (TAF_MMA_PLMN_LIST_ABORT_PROCESSING_TIMEOUT == g_StatusContext.ucPlmnListAbortProc)
    {
        STA_TRACE(STA_ERROR_PRINT, "TAF_MMA_RcvPlmnListAbortReq_Main():WARNING: plmn list abort processing");

        /* ���õ�ǰ���ڴ����û�����б��ѹ��� */
        g_StatusContext.ucPlmnListAbortProc = TAF_MMA_PLMN_LIST_ABORT_PROCESSING_USER_ABORT;

        return VOS_TRUE;
    }

    /* ͣ�б��Ѷ�ʱ�� */
    if (VOS_OK != NAS_StopRelTimer(WUEPS_PID_MMA,
                                   STA_TIMER_PLMN_LIST,
                                  &g_StatusContext.ahStaTimer[0]))
    {
        STA_TRACE(STA_ERROR_PRINT, "TAF_MMA_RcvPlmnListAbortReq_Main():WARNING: NAS_StopRelTimer failed");
    }

    /* ���g_stTafMmaCtx.astMmaOperCtx��TAF_MMA_OPER_PLMN_LIST_ABORT_REQ���ͽṹ���ڱ�ʹ�� */
    if (VOS_TRUE == TAF_MMA_IsOperTypeUsed(TAF_MMA_OPER_PLMN_LIST_ABORT_REQ))
    {
        /* ֱ�ӻظ�PLMN LIST ABORT����ʧ�� */
        TAF_MMA_SndPlmnListAbortCnf(&pstPlmnListAbortMsg->stCtrl, TAF_ERR_ERROR);
        return VOS_TRUE;
    }

    /* �Ҳ���δ��ʹ�õģ��ظ�ʧ�� */
    if (VOS_FALSE == TAF_MMA_GetUnusedOperCtxIndex(&ucCtxIndex))
    {
        TAF_MMA_SndPlmnListAbortCnf(&pstPlmnListAbortMsg->stCtrl, TAF_ERR_NO_ERROR);
        return VOS_TRUE;
    }

    /* ����һ��g_stTafMmaCtx.astMmaOperCtx����Ӧ���� */
    TAF_MMA_SetOperCtx(pstPlmnListAbortMsg->stCtrl,
                       TAF_MMA_OPER_PLMN_LIST_ABORT_REQ, ucCtxIndex);

    /* MMA��LIST����������ʱ����ʱ��������MSCC����ֹͣLIST��������
       �յ�MSCC�Ļظ�������AT�ظ� */
    ulRet = TAF_MMA_SndMsccPlmnListAbortReq();
    if (VOS_ERR == ulRet)
    {
        STA_TRACE(STA_ERROR_PRINT, "TAF_MMA_RcvPlmnListAbortReq_Main():ERROR: failed");
    }

    /* ����STA_TIMER_PLMN_LIST_ABORT 10s��ʱ���������ʱδ�յ�MSCC�Ļظ����ϱ�ATʧ�� */
    TAF_MMA_StartTimer(TI_TAF_MMA_WAIT_MSCC_ABORT_PLMN_LIST_CNF, TAF_MMA_GetPlmnListAbortTimerLen());
    /* ���õ�ǰ���ڽ����û�����б��ѹ��� */
    g_StatusContext.ucPlmnListAbortProc = TAF_MMA_PLMN_LIST_ABORT_PROCESSING_USER_ABORT;
    return VOS_TRUE;
}


/*****************************************************************************
 �� �� ��  : TAF_MMA_IsGsmAccessForbidden
 ��������  : �ж��Ƿ��ֹGSM����
 �������  : ��
 �������  : ��
 �� �� ֵ  : VOS_TRUE:��ֹGSM����
              VOS_FALSE:����GSM����
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2012��12��26��
    ��    ��   : s46746
    �޸�����   : DSDA GUNAS C CORE��Ŀ
  2.��    ��   : 2013��6��5��
    ��    ��   : w00242748
    �޸�����   : svlte��usim�ӿڵ���
  3.��    ��   : 2013��7��29��
    ��    ��   : y00245242
    �޸�����   : �����µ�USIM�ӿ�
*****************************************************************************/
VOS_UINT32 TAF_MMA_IsGsmAccessForbidden(VOS_VOID)
{
    VOS_UINT32   ulEfustGsmAccess;
    VOS_UINT32   ulEfustGsmSecContext;
    VOS_UINT8    ucSimStatus;
    VOS_UINT8    ucSimType;

    if (MMA_QUICK_START_ENABLE == gstMmaValue.ulQuickStartFlg)
    {
        return VOS_FALSE;
    }

    if (VOS_TRUE == gstMmaValue.stEfustServiceCfg.ucForbidReg2GNetWork)
    {
        /*��ȡ��״̬�Ϳ�����*/
        (VOS_VOID)MMA_PhoneGetUsimStatus(&ucSimStatus);
        (VOS_VOID)MMA_PhoneGetUsimType(&ucSimType);

        if ( ( MMA_USIM_PRESENT == ucSimStatus )
            && (MMA_USIM_TYPE_USIM == ucSimType) )
        {
            /* ����USIM���ļ���EFust����27��38���ж��Ƿ�����GSM���� */
            /* Modified by y00245242 for VoLTE_PhaseI  ��Ŀ, 2013-7-29, begin */
            ulEfustGsmAccess     = NAS_USIMMAPI_IsServiceAvailable(NAS_USIM_SVR_GSM_ACCESS_IN_USIM);
            ulEfustGsmSecContext = NAS_USIMMAPI_IsServiceAvailable(NAS_USIM_SVR_GSM_SECURITY_CONTEXT);
            /* Modified by y00245242 for VoLTE_PhaseI  ��Ŀ, 2013-7-29, end */

            if ((0 == ulEfustGsmAccess) && (0 == ulEfustGsmSecContext))
            {
                return VOS_TRUE;
            }
        }

    }

    return VOS_FALSE;
}

/* Deleted by s00217060 for VoLTE_PhaseI  ��Ŀ, 2013-07-13, begin */
/* TAF_MMA_InitTimerLen�ƶ�λ�� */
/* Deleted by s00217060 for VoLTE_PhaseI  ��Ŀ, 2013-07-13, end */


/*****************************************************************************
 �� �� ��  : TAF_MMA_IsExistPlmnRatAllowAccess
 ��������  : �ж��Ƿ���ڿ��Է������Ľ��뼼��
 �������  : ��
 �������  : ��
 �� �� ֵ  : VOS_TRUE:���ڿ��Է������Ľ��뼼��
              VOS_FALSE:�����ڿ��Է������Ľ��뼼��
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2013��02��25��
    ��    ��   : s00217060
    �޸�����   : ��������
  2.��    ��   : 2013��06��5��
    ��    ��   : w00242748
    �޸�����   : svlte��usim�ӿڵ���
*****************************************************************************/
VOS_UINT32 TAF_MMA_IsExistPlmnRatAllowAccess(VOS_VOID)
{
    TAF_MMA_RAT_ORDER_STRU              *pstRatPrioList = VOS_NULL_PTR;
    VOS_UINT32                          ulGOnlyModeFlg;
#if (FEATURE_ON == FEATURE_LTE)
    VOS_UINT32                          ulLOnlyModeFlg;
    VOS_UINT8                           ucCardType;

	ucCardType = 0;
#endif

    ulGOnlyModeFlg = VOS_FALSE;
    pstRatPrioList = TAF_MMA_GetRatPrioListAddr();
    ulGOnlyModeFlg = MN_MMA_IsGOnlyMode(pstRatPrioList);

#if (FEATURE_ON == FEATURE_LTE)
    ulLOnlyModeFlg = VOS_FALSE;
    (VOS_VOID)NAS_USIMMAPI_GetCardType(VOS_NULL_PTR, &ucCardType);
    ulLOnlyModeFlg = MN_MMA_IsLOnlyMode(pstRatPrioList);
#endif

    /* USIM����ֹGSM���벢����G��ģʱ���������û�ָ���� */
    if ((VOS_TRUE == TAF_MMA_IsGsmAccessForbidden())
     && (VOS_TRUE == ulGOnlyModeFlg))
    {
        return VOS_FALSE;
    }

#if (FEATURE_ON == FEATURE_LTE)
    /* SIM��������L��ģʱ��Ҳ�������û�ָ���� */
    if ((USIMM_CARD_SIM == ucCardType)
     && (VOS_TRUE == ulLOnlyModeFlg))
    {
        return VOS_FALSE;
    }
#endif

    return VOS_TRUE;

}

/* Modified by z00161729 for �����ϱ�AT�������������C��, 2013-4-3, begin */
/*****************************************************************************
 �� �� ��  : TAF_MMA_ReportRegStatus
 ��������  : ע��״̬�ϱ�
 �������  : enCsRegState - ע��״̬
             enCnDomainId - ������
 �������  : ��
 �� �� ֵ  :
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2013��04��3��
    ��    ��   : z00161729
    �޸�����   : ��������
  2.��    ��   : 2013��06��3��
    ��    ��   : s46746
    �޸�����   : SS FDN&Call Control��Ŀ��ע��״̬�ػ�Ҳ��Ҫ�ϱ�
  3.��    ��   : 2014��2��18��
    ��    ��   : y00245242
    �޸�����   : ���ⵥ��dts2014021501200, CGREG/CREG�����ϱ������޷��ϱ�
  4.��    ��   : 2015��2��15��
    ��    ��   : s00217060
    �޸�����   : reg state report�޸ģ��仯�����ϱ������仯����Ҫ�ϱ�
  5.��    ��   : 2015��5��15��
    ��    ��   : w00281933
    �޸�����   : Service_State_Optimize_PhaseII�޸�
  6.��    ��   : 2015��10��8��
    ��    ��   : l00324781
    �޸�����   : Iteration 18 ,CLģ����״̬��ʾ�Ż�
*****************************************************************************/
VOS_VOID TAF_MMA_ReportRegStatus(
    NAS_MSCC_PIF_REG_STATE_ENUM_UINT8        enRegState,
    NAS_MSCC_PIF_SRVDOMAIN_ENUM_UINT32       enCnDomainId
)
{
    VOS_UINT32                          ulCellInfoChg;
    TAF_SDC_SERVICED_PLMN_INFO_STRU    *pstAppServPlmnInfo;
    TAF_SDC_REPORT_SRVSTA_ENUM_UINT8    enServiceStatus;
    TAF_SDC_CEREG_TYPE_ENUM_UINT8       enCeregType;

    enCeregType                         = TAF_SDC_CEREG_TYPE_BUTT;
    enServiceStatus                     = TAF_SDC_GetServiceStatus();
    pstAppServPlmnInfo                  = &(TAF_SDC_GetAppNetworkInfo()->stAppSysInfo.stServPlmnInfo);
    ulCellInfoChg                       = TAF_MMA_IsAppNetworkInfoCellChange(pstAppServPlmnInfo);

    /*ָ�����ע��ı䣬�ϱ�ע��״̬*/
    if (VOS_TRUE == TAF_SDC_IsAppSepcDomainRegStaChg((TAF_SDC_SERVICE_DOMAIN_ENUM_UINT8)enCnDomainId,enRegState))
    {
        TAF_MMA_SndAtRegStatus(enCnDomainId, enRegState);
    }
    else
    {
        /* CREG/CGREG�ϱ�����Ϊ2ʱ������lac,cellid,rat�������������������PLMN�仯ʱ����Ҫ�ϱ� */
        if ((VOS_TRUE                             == ulCellInfoChg)
         && (TAF_SDC_REPORT_SRVSTA_NORMAL_SERVICE == enServiceStatus))
        {
            /* CREGΪ2ʱ */
            if ((TAF_SDC_CREG_TYPE_ENTIRE == TAF_SDC_GetCregType())
             && (NAS_MSCC_PIF_SRVDOMAIN_CS     == enCnDomainId))
            {
                TAF_MMA_SndAtRegStatus(NAS_MSCC_PIF_SRVDOMAIN_CS, TAF_SDC_GetCsRegStatus());
            }

            /* CGREG��CEREGΪ2 */
            enCeregType = TAF_SDC_GetCeregType();

            if (((TAF_SDC_CGREG_TYPE_ENTIRE == TAF_SDC_GetCgregType())
              || (TAF_SDC_CEREG_TYPE_ENTIRE == enCeregType))
             && (NAS_MSCC_PIF_SRVDOMAIN_PS       == enCnDomainId))
            {
                TAF_MMA_SndAtRegStatus(NAS_MSCC_PIF_SRVDOMAIN_PS, TAF_SDC_GetPsRegStatus());
            }
        }
    }

    /* SPN INFOδ������ʹ�õĵط��������߼�ɾ�� */


    return;
}



/* Modified by z00161729 for �����ϱ�AT�������������C��, 2013-4-3, end */

/*****************************************************************************
 �� �� ��  : TAF_MMA_IsCsServDomainAvail
 ��������  : �����ֻ�ģʽ�ж�CS�������Ƿ����
 �������  : ��
 �� �� ֵ  : VOS_TRUE:CS���������ã�VOS_FALSE:CS������������
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2013��6��4��
    ��    ��   : s00217060
    �޸�����   : �����ɺ���
*****************************************************************************/
VOS_UINT32 TAF_MMA_IsCsServDomainAvail(
    TAF_PH_MS_CLASS_TYPE                enMsClassType
)
{
    /* �ֻ�ģʽ��Aģʽ����CCģʽ������ΪCS����ã����������ΪCS�򲻿��� */
    if ( (TAF_PH_MS_CLASS_A  == enMsClassType)
      || (TAF_PH_MS_CLASS_CC == enMsClassType) )
    {
        return VOS_TRUE;
    }

    return VOS_FALSE;
}

/*****************************************************************************
 �� �� ��  : TAF_MMA_IsPsServDomainAvail
 ��������  : �����ֻ�ģʽ�ж�PS�������Ƿ����
 �������  : ��
 �� �� ֵ  : VOS_TRUE:PS���������ã�VOS_FALSE:PS������������
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2014��3��25��
    ��    ��   : s00217060
    �޸�����   : �����ɺ���
*****************************************************************************/
VOS_UINT32 TAF_MMA_IsPsServDomainAvail(
    TAF_PH_MS_CLASS_TYPE                enMsClassType
)
{
    /* �ֻ�ģʽ��Aģʽ����CGģʽ������ΪPS����ã����������ΪPS�򲻿��� */
    if ( (TAF_PH_MS_CLASS_A  == enMsClassType)
      || (TAF_PH_MS_CLASS_CG == enMsClassType) )
    {
        return VOS_TRUE;
    }

    return VOS_FALSE;
}


/*****************************************************************************
 �� �� ��  : TAF_MMA_SndStkCsServiceChangeNotify
 ��������  : ��STK����ģʽ���֪ͨ
 �������  : enCsState - cs����������
 �������  : ��
 �� �� ֵ  : ��
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2013��6��3��
    ��    ��   : s00217060
    �޸�����   : �����ɺ���
*****************************************************************************/
VOS_VOID TAF_MMA_SndStkCsServiceChangeNotify(
    TAF_CS_SERVICE_ENUM_UINT32          enCsState
)
{
    VOS_UINT32                          ulRet;
    TAF_STK_CS_SERVICE_IND             *pstMsg = VOS_NULL_PTR;

    pstMsg = (TAF_STK_CS_SERVICE_IND *)PS_ALLOC_MSG(WUEPS_PID_TAF,
                           sizeof(TAF_STK_CS_SERVICE_IND) - VOS_MSG_HEAD_LENGTH);

    if ( VOS_NULL_PTR == pstMsg )
    {
        NAS_ERROR_LOG(WUEPS_PID_TAF, "TAF_MMA_SndStkCsServiceChangeNotify:ERROR: Memory Alloc Error for pMsg");
        return;
    }

    PS_MEM_SET((VOS_INT8*)pstMsg + VOS_MSG_HEAD_LENGTH, 0,
                     sizeof(TAF_STK_CS_SERVICE_IND) - VOS_MSG_HEAD_LENGTH);

    pstMsg->ulReceiverCpuId  = VOS_LOCAL_CPUID;
    pstMsg->ulReceiverPid    = NAS_GetOamReceivePid(MAPS_STK_PID);
    pstMsg->ulSenderCpuId    = VOS_LOCAL_CPUID;
    pstMsg->ulSenderPid      = WUEPS_PID_TAF;
    pstMsg->ulLength         = sizeof(TAF_STK_CS_SERVICE_IND) - VOS_MSG_HEAD_LENGTH;
    pstMsg->ulMsgName        = TAF_STK_CS_STATE_IND;
    pstMsg->enCSState        = enCsState;

    /* ����VOS����ԭ�� */
    ulRet = PS_SEND_MSG( WUEPS_PID_TAF, pstMsg );

    if ( VOS_OK != ulRet )
    {
        NAS_ERROR_LOG(WUEPS_PID_TAF, "TAF_MMA_SndStkCsServiceChangeNotify:ERROR:PS_SEND_MSG FAILURE");
        return;
    }

    return;

}

/* Deleted by w00176964 for VoLTE_PhaseII ��Ŀ, 2013-10-10, begin */

/* Deleted by w00176964 for VoLTE_PhaseII ��Ŀ, 2013-10-10, end */



/*****************************************************************************
 �� �� ��  : TAF_MMA_IsNeedSndStkEvt
 ��������  : ���뼼���仯�Ƿ���Ҫ�ϱ���STK,SVLTE��̬�£����û��CS�������������ϱ�
 �������  : ��
 �������  : ��
 �� �� ֵ  : VOS_TRUE:��Ҫ��VOS_FALSE:����Ҫ
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2013��6��4��
    ��    ��   : z00161729
    �޸�����   : SVLTE ��usim�ӿڵ����޸�
*****************************************************************************/
VOS_UINT32 TAF_MMA_IsNeedSndStkEvt(VOS_VOID)
{
    if (VOS_TRUE == TAF_SDC_GetSvlteSupportFlag())
    {
       if (VOS_TRUE == TAF_MMA_IsCsServDomainAvail(gstMmaValue.stSetMsClass.MsClassType))
       {
           return VOS_TRUE;
       }
       return VOS_FALSE;
    }
    else
    {
        return VOS_TRUE;
    }
}


/*****************************************************************************
 �� �� ��  : TAF_MMA_SndMtaAreaLostInd
 ��������  : MMA��MTA���Ͷ���ָʾ
 �������  : VOS_VOID
 �������  : ��
 �� �� ֵ  : ��
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2013��7��19��
    ��    ��   : z60575
    �޸�����   : ��������

*****************************************************************************/
VOS_VOID TAF_MMA_SndMtaAreaLostInd(VOS_VOID)
{
    VOS_UINT32                          ulRet;
    NAS_MTA_AREA_LOST_IND_STRU         *pstMsg = VOS_NULL_PTR;

    /* �����ڴ�  */
    pstMsg = (NAS_MTA_AREA_LOST_IND_STRU *)PS_ALLOC_MSG(WUEPS_PID_MMA,
                           sizeof(NAS_MTA_AREA_LOST_IND_STRU) - VOS_MSG_HEAD_LENGTH);

    if ( VOS_NULL_PTR == pstMsg )
    {
        NAS_ERROR_LOG(WUEPS_PID_MMA, "TAF_MMA_SndMtaAreaLostInd:ERROR: Memory Alloc Error for pMsg");
        return;
    }

    PS_MEM_SET((VOS_INT8*)pstMsg + VOS_MSG_HEAD_LENGTH, 0,
                     sizeof(NAS_MTA_AREA_LOST_IND_STRU) - VOS_MSG_HEAD_LENGTH);

    pstMsg->stMsgHeader.ulReceiverCpuId  = VOS_LOCAL_CPUID;
    pstMsg->stMsgHeader.ulReceiverPid    = UEPS_PID_MTA;
    pstMsg->stMsgHeader.ulSenderCpuId    = VOS_LOCAL_CPUID;
    pstMsg->stMsgHeader.ulSenderPid      = WUEPS_PID_MMA;
    pstMsg->stMsgHeader.ulLength         = sizeof(NAS_MTA_AREA_LOST_IND_STRU) - VOS_MSG_HEAD_LENGTH;
    pstMsg->stMsgHeader.ulMsgName        = ID_NAS_MTA_AREA_LOST_IND;

    /* ����VOS����ԭ�� */
    ulRet = PS_SEND_MSG( WUEPS_PID_MMA, pstMsg );

    if ( VOS_OK != ulRet )
    {
        NAS_ERROR_LOG(WUEPS_PID_MMA, "TAF_MMA_SndMsgCsServiceChangeNotify:ERROR:PS_SEND_MSG FAILURE");
        return;
    }

    return;
}

/*****************************************************************************
 �� �� ��  : TAF_MMA_PlmnReselectAutoReq_PowerOff
 ��������  : MMA�ػ�״̬���յ�at+cops=0�Ĵ���
 �������  : ulOpId - ���������ʶ
             stPlmnId - ָ����PLMN
             ucAccessMode - ָ���Ľ���ģʽ
             ucReselMode - ָ��PLMNʧ�ܺ����ѡģʽ
 �������  : ��
 �� �� ֵ  : ��
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2013��11��04��
    ��    ��   : z00161729
    �޸�����   : ��������
  2.��    ��   : 2014��3��7��
    ��    ��   : w00176964
    �޸�����   : DTS2014030610626:MMAдNVʱ��Ҫˢ��ȫ�ֱ���

*****************************************************************************/
VOS_UINT32  TAF_MMA_PlmnReselectAutoReq_PowerOff(VOS_UINT32 ulOpID)
{
    TAF_SDC_MS_CAP_INFO_STRU           *pstMsCapInfo = VOS_NULL_PTR;

    pstMsCapInfo = TAF_SDC_GetMsCapInfo();
    TAF_SDC_InitSvlteSupportFlag(TAF_SDC_INIT_CTX_STARTUP, pstMsCapInfo);

    if (VOS_TRUE == TAF_SDC_GetSvlteSupportFlag())
    {
        /* ֱ��д8214 nv��*/
        TAF_MMA_WritePlmnSelectionModeNvim(NAS_MSCC_PIF_PLMN_SEL_MODE_AUTO);

        TAF_MMA_SetPlmnSelectionMode(NAS_MSCC_PIF_PLMN_SEL_MODE_AUTO);

        /* ֱ���ϱ���� */
        TAF_MMA_ProcPlmnAutoReselCnf(TAF_ERR_NO_ERROR);
        return STA_SUCCESS;
    }

    /* svlte nv�ر��ϱ�error */
    TAF_MMA_ProcPlmnAutoReselCnf(TAF_ERR_PHONE_MSG_UNMATCH);
    return STA_ERROR;
}

/*****************************************************************************
 �� �� ��  : TAF_MMA_RcvPlmnSelectionReq_PowerOff
 ��������  : MMA�ػ�״̬���յ�cops�Ĵ���
 �������  : stCtrl - MODULE OPID
             stPlmnId - ָ����PLMN
             ucAccessMode - ָ���Ľ���ģʽ
             ucReselMode - ָ��PLMNʧ�ܺ����ѡģʽ
 �������  : ��
 �� �� ֵ  : ��
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2013��11��04��
    ��    ��   : z00161729
    �޸�����   : ��������

*****************************************************************************/
VOS_UINT32  TAF_MMA_RcvPlmnSelectionReq_PowerOff(
    TAF_MMA_PLMN_SPECIAL_SEL_REQ_STRU  *pstPlmnUserSelMsg,
    TAF_PLMN_ID_STRU                    stPlmnId,
    TAF_PH_RA_MODE                      ucAccessMode,
    VOS_UINT8                           ucReselMode
)
{
    TAF_SDC_MS_CAP_INFO_STRU           *pstMsCapInfo = VOS_NULL_PTR;
    VOS_UINT8                           ucCtxIndex;

    pstMsCapInfo = TAF_SDC_GetMsCapInfo();
    TAF_SDC_InitSvlteSupportFlag(TAF_SDC_INIT_CTX_STARTUP, pstMsCapInfo);

    if (VOS_TRUE == TAF_SDC_GetSvlteSupportFlag())
    {
        (VOS_VOID)TAF_MMA_SndMsccPlmnSpecialReq((MMA_MSCC_PLMN_ID_STRU *)&stPlmnId, ucAccessMode);
        g_StatusContext.ulCurOpId = pstPlmnUserSelMsg->stCtrl.ucOpId;
        g_StatusContext.StaPlmnId.Mcc = stPlmnId.Mcc;
        g_StatusContext.StaPlmnId.Mnc = stPlmnId.Mnc;

        TAF_MMA_StartTimer(TI_TAF_MMA_WAIT_MSCC_PLMN_SPECIAL_SEL_CNF, TI_TAF_MMA_WAIT_MSCC_PLMN_SPECIAL_RESEL_SET_CNF_LEN);

        /* ���g_stTafMmaCtx.astMmaOperCtx��TAF_MMA_OPER_PLMN_SPEC_SEL_REQ���ͽṹ���ڱ�ʹ�� */
        if (VOS_TRUE == TAF_MMA_IsOperTypeUsed(TAF_MMA_OPER_PLMN_SPEC_SEL_REQ))
        {
            /* ֱ�ӻظ�SEL����ʧ�� */
            TAF_MMA_SndPlmnSpecialSelCnf(&pstPlmnUserSelMsg->stCtrl, TAF_ERR_ERROR);
            return VOS_TRUE;
        }

        /* �Ҳ���δ��ʹ�õģ��ظ�ʧ�� */
        if (VOS_FALSE == TAF_MMA_GetUnusedOperCtxIndex(&ucCtxIndex))
        {
            TAF_MMA_SndPlmnSpecialSelCnf(&pstPlmnUserSelMsg->stCtrl, TAF_ERR_ERROR);
            return VOS_TRUE;
        }

        /* ����һ��g_stTafMmaCtx.astMmaOperCtx����Ӧ���� */
        TAF_MMA_SetOperCtx(pstPlmnUserSelMsg->stCtrl,
                           TAF_MMA_OPER_PLMN_SPEC_SEL_REQ, ucCtxIndex);

        return STA_SUCCESS;
    }

    /* svlte nv�ر��ϱ�error */
    TAF_MMA_SndPlmnSpecialSelCnf(&pstPlmnUserSelMsg->stCtrl, TAF_ERR_ERROR);

    return STA_ERROR;

}

/* �Ƶ�TafMmaComFun.c�� */


/*****************************************************************************
 �� �� ��  : TAF_MMA_NotifySrvInfoToSpm
 ��������  : ������״̬��Ϣ֪ͨ��SPMģ��
 �������  : enCnDomainId          --����״̬����Ϣ
             enServiceStatus       --����״̬
             enOldPsServiceStatus  --�ɵ�PS����״̬
 �������  : ��
 �� �� ֵ  : ��
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2015��02��11��
    ��    ��   : w00281933
    �޸�����   : �����ɺ���
*****************************************************************************/
VOS_VOID TAF_MMA_NotifySrvInfoToSpm(
    NAS_MSCC_PIF_SRVDOMAIN_ENUM_UINT32          enCnDomainId,
    NAS_MSCC_PIF_SERVICE_STATUS_ENUM_UINT32     enServiceStatus,
    NAS_MSCC_PIF_SERVICE_STATUS_ENUM_UINT32     enOldPsServiceStatus
)
{

#if (FEATURE_IMS == FEATURE_ON)
    if (VOS_TRUE  == TAF_SDC_GetImsSupportFlag())
    {
        /* PS����״̬�����仯֪ͨIMSA��SPMģ�� */
        if (((NAS_MSCC_PIF_SRVDOMAIN_PS    == enCnDomainId)
          || (NAS_MSCC_PIF_SRVDOMAIN_CS_PS == enCnDomainId))
         && (enOldPsServiceStatus != enServiceStatus))
        {
            /* ֪ͨSPM����״̬���������SPM�����������Ϣ����Ϣ�в���������ͷ���״̬����SPMȡSDCȫ�ֱ����е� */
            TAF_MMA_SndSpmServiceStatusChangeNotify();
        }
    }
#endif

    return;
}



/*lint -restore */


/*****************************************************************************
 �� �� ��  : TAF_MMA_IsNeedReportRegStatus_ServiceStatusInd
 ��������  : �յ�����״̬ʱ���Ƿ���Ҫ�ϱ�ע��״̬
 �������  : �ɵ�ϵͳģʽ
             �ɵ�ϵͳ��ģʽ
             �ɵ�λ����Ϣ
 �������  : ��
 �� �� ֵ  : VOS_TRUE:  ��Ҫ�ϱ�
             VOS_FALSE: ����Ҫ�ϱ�
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2015��02��15��
    ��    ��   : s00217060
    �޸�����   : ��������
  2.��    ��   : 2015��06��10��
    ��    ��   : w00281933
    �޸�����   : �������� Service_State_Optimize_PhaseII
*****************************************************************************/
VOS_UINT32 TAF_MMA_IsNeedReportRegStatus_ServiceStatusInd(
    TAF_SDC_SYS_MODE_ENUM_UINT8         enOldAppSysMode,
    TAF_SDC_SYS_SUBMODE_ENUM_UINT8      enOldAppSysSubMode,
    TAF_SDC_SERVICED_PLMN_INFO_STRU    *pstOldPlmnInfo
)
{

    TAF_SDC_SYS_INFO_STRU              *pstCurCampInfo = VOS_NULL_PTR;

    pstCurCampInfo = TAF_SDC_GetSysInfo();

    /*��ʱ��ʱ�������ڼ�,��Ҫ�ϱ�*/
    if (TAF_MMA_TIMER_STATUS_RUNING == TAF_MMA_GetTimerStatus(TI_TAF_MMA_DELAY_REPORT_SERVICE_STATUS))
    {
        return VOS_FALSE;
    }

    if (TAF_SDC_REPORT_SRVSTA_NORMAL_SERVICE != TAF_SDC_GetServiceStatus())
    {
        return VOS_FALSE;
    }

    if (enOldAppSysSubMode != (TAF_SDC_GetSysSubMode()))
    {
        return VOS_TRUE;
    }

    /* CREG/CGREG�ϱ�����Ϊ2ʱ������lac,cellid,rat�������������������PLMN�仯ʱ����Ҫ�ϱ� */
    /* rat�Ƿ�仯 */
    if (enOldAppSysMode != (TAF_SDC_GetSysMode()))
    {
        return VOS_TRUE;
    }

    /* PLMN�Ƿ�仯 */
    if ( (pstOldPlmnInfo->stServicePlmnId.ulMcc) != (pstCurCampInfo->st3gppSysInfo.stPlmnId.ulMcc)
      || (pstOldPlmnInfo->stServicePlmnId.ulMnc) != (pstCurCampInfo->st3gppSysInfo.stPlmnId.ulMnc) )
    {
        return VOS_TRUE;
    }

    /* lac�Ƿ�仯 */
    if ((pstOldPlmnInfo->usServiceLac) != (pstCurCampInfo->st3gppSysInfo.usLac))
    {
        return VOS_TRUE;
    }

    /* rac�Ƿ�仯 */
    if ((pstOldPlmnInfo->ucServiceRac) != (pstCurCampInfo->st3gppSysInfo.ucRac))
    {
        return VOS_TRUE;
    }

    /* cellid�Ƿ�仯 */
    if ((pstOldPlmnInfo->ulServiceCellId) != (pstCurCampInfo->st3gppSysInfo.ulCellId))
    {
        return VOS_TRUE;
    }

    return VOS_FALSE;

}

/*****************************************************************************
 �� �� ��  : TAF_MMA_IsNeedReportRegState_DelayRptTimerRun
 ��������  : ��ʱ��ʱ�������ڼ䣬�Ƿ���Ҫ�ϱ�ע��״̬�ͷ���״̬����һ��
 �������  : enCnDomainId             -- ������
             enRegState               -- ��ע��ץ������
 �������  : ��
 �� �� ֵ  : VOS_TRUE:  ��Ҫ�ϱ�
             VOS_FALSE: ����Ҫ�ϱ�
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2015��05��11��
    ��    ��   : w00281933
    �޸�����   : �����ɺ���
*****************************************************************************/
VOS_UINT32 TAF_MMA_IsNeedReportRegState_DelayRptTimerRun(
    NAS_MSCC_PIF_SRVDOMAIN_ENUM_UINT32  enCnDomainId,
    TAF_SDC_REG_STATUS_ENUM_UINT8       enRegState
)
{
    TAF_SDC_SERVICE_STATUS_ENUM_UINT8  enAppCsSrvSta;
    TAF_SDC_SERVICE_STATUS_ENUM_UINT8  enAppPsSrvSta;
    TAF_SDC_REG_STATUS_ENUM_UINT8      enCsRegState;
    TAF_SDC_REG_STATUS_ENUM_UINT8      enPsRegState;

    enAppCsSrvSta   = TAF_SDC_GetAppCsServiceStatus();
    enAppPsSrvSta   = TAF_SDC_GetAppPsServiceStatus();

    /*��ȡ�ڲ������ע��״̬��Ϣ*/
    enCsRegState = TAF_SDC_GetCsRegStatus();
    enPsRegState = TAF_SDC_GetPsRegStatus();

    if ((TAF_SDC_REG_REGISTERED_HOME_NETWORK == enRegState)
     || (TAF_SDC_REG_REGISTERED_ROAM         == enRegState))
    {
        return VOS_TRUE;
    }

    /*��ʱ��ʱ������ʱ,�ڲ������ע��״̬���Ƿ�����ע��,�����ϱ�
      ����ᵼ���ϲ�������ʾ�޷���*/
    if ((TAF_SDC_REG_REGISTERED_HOME_NETWORK  != enPsRegState)
     && (TAF_SDC_REG_REGISTERED_ROAM          != enPsRegState)
     && (TAF_SDC_REG_REGISTERED_HOME_NETWORK  != enCsRegState)
     && (TAF_SDC_REG_REGISTERED_ROAM          != enCsRegState))
    {
        return VOS_FALSE;
    }

    /*�����ϱ���ע��״̬���ϱ��ķ���״̬һֱ*/
    if ((NAS_MSCC_PIF_SRVDOMAIN_CS == enCnDomainId)
     && (TAF_SDC_SERVICE_STATUS_NORMAL_SERVICE != enAppCsSrvSta))
    {
        return VOS_TRUE;
    }
    else if ((NAS_MSCC_PIF_SRVDOMAIN_PS == enCnDomainId)
          && (TAF_SDC_SERVICE_STATUS_NORMAL_SERVICE != enAppPsSrvSta))
    {
        return VOS_TRUE;
    }
    else
    {
        return VOS_FALSE;
    }
}

/*****************************************************************************
 �� �� ��  : TAF_MMA_IsNeedReportRegStatus_RegStatusInd
 ��������  : �յ�ע��״̬ʱ���Ƿ���Ҫ�ϱ�ע��״̬
 �������  : �����򣬾ɵ�ע��״̬���µ�ע��״̬
 �������  : ��
 �� �� ֵ  : VOS_TRUE:  ��Ҫ�ϱ�
             VOS_FALSE: ����Ҫ�ϱ�
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2015��02��15��
    ��    ��   : s00217060
    �޸�����   : ��������
  2.��    ��   : 2015��04��11��
    ��    ��   : w00281933
    �޸�����   : ����״̬�Ż�Phase II
*****************************************************************************/
VOS_UINT32 TAF_MMA_IsNeedReportRegStatus_RegStatusInd(
    NAS_MSCC_PIF_SRVDOMAIN_ENUM_UINT32  enCnDomainId,
    TAF_SDC_REG_STATUS_ENUM_UINT8       enOldCsRegState,
    TAF_SDC_REG_STATUS_ENUM_UINT8       enOldPsRegState,
    TAF_SDC_REG_STATUS_ENUM_UINT8       enRegState
)
{
    VOS_UINT8                           ucIsSpecDomainUsimInvalid;
    TAF_MMA_TIMER_STATUS_ENUM_UINT8     enDelayTimerStatus;

    enDelayTimerStatus    = TAF_MMA_GetTimerStatus(TI_TAF_MMA_DELAY_REPORT_SERVICE_STATUS);

    /*��ȡָ����Ŀ�״̬�Ƿ���Ч*/
    ucIsSpecDomainUsimInvalid = TAF_SDC_IsSpecDomainUsimStatusInvalid(enCnDomainId);

    /* �жϵ�ǰע��״̬��APP�б���Ĳ���ͬ���ϱ� */
    if (VOS_FALSE == TAF_SDC_IsAppSepcDomainRegStaChg((TAF_SDC_SERVICE_DOMAIN_ENUM_UINT8)enCnDomainId,enRegState))
    {
        return VOS_FALSE;
    }

    /*normal ��Ҫ�ϱ�*/
    if ((TAF_SDC_REG_REGISTERED_HOME_NETWORK == enRegState)
     || (TAF_SDC_REG_REGISTERED_ROAM == enRegState))
    {
        return VOS_TRUE;
    }

    /*ָ����״̬��Ч����Ҫ�ϱ�*/
    if (VOS_TRUE == ucIsSpecDomainUsimInvalid)
    {
        return VOS_TRUE;
    }

    if (TAF_MMA_TIMER_STATUS_RUNING == enDelayTimerStatus)
    {
        if (VOS_FALSE == TAF_MMA_IsNeedReportRegState_DelayRptTimerRun(enCnDomainId,enRegState))
        {
            return VOS_FALSE;
        }
    }

    return VOS_TRUE;

}

#if (FEATURE_ON == FEATURE_BASTET)
/*****************************************************************************
 �� �� ��  : TAF_MMA_ProcBastetServiceStatusInd
 ��������  : �յ�MMC�ķ���״̬�ϱ�ʱ�������Ƿ�֪ͨBastet����״̬
 �������  : �ɵ�CS�����״̬�;ɵ�PS�����״̬
 �������  : ��
 �� �� ֵ  : ��
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2015��02��15��
    ��    ��   : s00217060
    �޸�����   : ��������

*****************************************************************************/
VOS_VOID TAF_MMA_ProcBastetServiceStatusInd(
    TAF_SDC_SERVICE_STATUS_ENUM_UINT8   enOldCsSrvSta,
    TAF_SDC_SERVICE_STATUS_ENUM_UINT8   enOldPsSrvSta
)
{

    TAF_SDC_SERVICE_STATUS_ENUM_UINT8   enBstNewCsSrvSta;
    TAF_SDC_SERVICE_STATUS_ENUM_UINT8   enBstNewPsSrvSta;

    enBstNewCsSrvSta   =  TAF_SDC_GetCsServiceStatus();
    enBstNewPsSrvSta   =  TAF_SDC_GetPsServiceStatus();

    if(VOS_TRUE == TAF_SDC_GetBastetSupportFlag())
    {
        /* cs�����״̬�仯��ps�����״̬�仯��֪ͨBASTET */
        if ((enOldCsSrvSta != enBstNewCsSrvSta)
          ||(enOldPsSrvSta != enBstNewPsSrvSta))
        {
            TAF_MMA_SndBastetServiceStatusInd();
        }
    }

    return;
}
#endif


/*****************************************************************************
 �� �� ��  : TAF_MMA_ProcAppServPlmnInfo_SysInfoInd
 ��������  : �յ�ϵͳ��Ϣʱ����AppServPlmnInfo���µĴ���
 �������  : MMC_MMA_SYS_INFO_IND_STRU          *pstSysInfoInd
 �������  : ��
 �� �� ֵ  : VOS_VOID
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2015��7��14��
    ��    ��   : s00217060
    �޸�����   : �����ɺ���

*****************************************************************************/
VOS_VOID TAF_MMA_ProcAppServPlmnInfo_SysInfoInd(
    MSCC_MMA_3GPP_SYS_INFO_IND_STRU    *pstSysInfoInd
)
{
    TAF_SDC_REPORT_SRVSTA_ENUM_UINT8    enAppSrvState;

    enAppSrvState   = TAF_SDC_GetAppServiceStatus();

    switch(pstSysInfoInd->enCurNetWork)
    {
        case NAS_MSCC_PIF_NET_RAT_TYPE_LTE:
        case NAS_MSCC_PIF_NET_RAT_TYPE_WCDMA:
        case NAS_MSCC_PIF_NET_RAT_TYPE_GSM:

            /* ���APP��ķ���״̬Ϊlimited service��Ҳ���µ�פ����Ϣ��APP�
               ��Ϊlimited service->limited serviceʱMMC���ϱ�����״̬��ע��״̬�����ܵ���С����Ϣδ���¹��� */
            if ( (TAF_SDC_REPORT_SRVSTA_LIMITED_SERVICE          == enAppSrvState)
              || (TAF_SDC_REPORT_SRVSTA_REGIONAL_LIMITED_SERVICE == enAppSrvState) )
            {
                TAF_MMA_UpdateAppServPlmnInfo();
            }

            break;

        default:

            TAF_ERROR_LOG(WUEPS_PID_MMA, "TAF_MMA_ProcAppServPlmnInfo_SysInfoInd: enCurNetWork ERROR");

            break;
    }

    return;
}

/*****************************************************************************
 �� �� ��  : TAF_MMA_ProcServiceStatusReport_ServiceStatusInd
 ��������  : �յ�MMC�ķ���״̬ʱ���Է���״̬�Ƿ���Ҫ�ϱ���AP�Ĵ���
 �������  : MMC_MMA_SERVICE_STATUS_IND_STRU    *pstServiceStatus
 �������  : ��
 �� �� ֵ  : VOS_VOID
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2015��7��17��
    ��    ��   : s00217060
    �޸�����   : �����ɺ���

*****************************************************************************/
VOS_VOID TAF_MMA_ProcServiceStatusReport_ServiceStatusInd(
    MSCC_MMA_SERVICE_STATUS_IND_STRU   *pstServiceStatus
)
{
    VOS_UINT32                          ucIsNeedRptSrvSta;
    VOS_UINT32                          ucIsNeedDelayRptSrvSta;

    ucIsNeedRptSrvSta      = VOS_FALSE;
    ucIsNeedDelayRptSrvSta = VOS_FALSE;

    /*�ж��Ƿ���Ҫ�ϱ�����״̬*/
    ucIsNeedRptSrvSta = TAF_MMA_IsNeedReportServiceStatus(pstServiceStatus->enCnDomainId, pstServiceStatus->enServiceStatus);

    if (VOS_TRUE == ucIsNeedRptSrvSta)
    {
        /*��Ҫ��ʱ�ϱ�����״̬*/
        ucIsNeedDelayRptSrvSta = TAF_MMA_IsNeedDelayReportServiceStatus(pstServiceStatus->enCnDomainId, pstServiceStatus->enServiceStatus);

        if (VOS_TRUE == ucIsNeedDelayRptSrvSta)
        {
            /* ��������״̬��ע��״̬�ӳ��ϱ� */
            TAF_MMA_ProcDelayReport();
        }
        else
        {
            /* ��������״̬�����ϱ� */
            TAF_MMA_ProcServiceStatusImmediatelyReport(pstServiceStatus);
        }
    }
    else
    {
        /* ��������״̬���ϱ� */
        TAF_MMA_ProcServiceStatusNotReport(pstServiceStatus);
    }


    return;
}


/*****************************************************************************
 �� �� ��  : TAF_MMA_ProcRegStatusReport_ServiceStatusInd
 ��������  : �յ�MMC�ķ���״̬ʱ����ע��״̬�Ƿ���Ҫ�ϱ���AP�Ĵ���
 �������  : TAF_SDC_SYS_MODE_ENUM_UINT8         enOldAppSysMode
             TAF_SDC_SYS_SUBMODE_ENUM_UINT8      enOldAppSysSubMode
             TAF_SDC_SERVICED_PLMN_INFO_STRU    *pstOldPlmnInfo
 �������  : ��
 �� �� ֵ  : VOS_VOID
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2015��7��17��
    ��    ��   : s00217060
    �޸�����   : �����ɺ���

*****************************************************************************/
VOS_VOID TAF_MMA_ProcRegStatusReport_ServiceStatusInd(
    TAF_SDC_SYS_MODE_ENUM_UINT8         enOldAppSysMode,
    TAF_SDC_SYS_SUBMODE_ENUM_UINT8      enOldAppSysSubMode,
    TAF_SDC_SERVICED_PLMN_INFO_STRU    *pstOldPlmnInfo
)
{
    TAF_SDC_CEREG_TYPE_ENUM_UINT8       enCeregType;

    /* �յ�ע��״̬ʱ��APP�ﱣ���פ����Ϣ��δ���£��޷��ж�С���Ƿ����仯��
       �������յ�����״̬ʱ�����С�������仯����Ҫ����һ��AT CREG/CGREG */
    if (VOS_TRUE == TAF_MMA_IsNeedReportRegStatus_ServiceStatusInd(enOldAppSysMode, enOldAppSysSubMode, pstOldPlmnInfo))
    {
        /* CREGΪ2ʱ */
        if (TAF_SDC_CREG_TYPE_ENTIRE == TAF_SDC_GetCregType())
        {
            TAF_MMA_SndAtRegStatus(NAS_MSCC_PIF_SRVDOMAIN_CS, TAF_SDC_GetCsRegStatus());
        }

        /* CGREG��CEREGΪ2 */
        enCeregType = TAF_SDC_GetCeregType();
        if ((TAF_SDC_CGREG_TYPE_ENTIRE == TAF_SDC_GetCgregType())
         || (TAF_SDC_CEREG_TYPE_ENTIRE == enCeregType))
         {
            TAF_MMA_SndAtRegStatus(NAS_MSCC_PIF_SRVDOMAIN_PS, TAF_SDC_GetPsRegStatus());
         }

        /*ͬ������פ����Ϣ��APPINFO*/
        TAF_MMA_UpdateAppRegStatusInfo(NAS_MSCC_PIF_SRVDOMAIN_CS_PS);
    }

    return;
}


/*****************************************************************************
 �� �� ��  : TAF_MMA_ProcRssiReport_ServiceStatusInd
 ��������  : �յ�MMC�ϱ�״̬ʱ�����ź�ǿ���Ƿ���Ҫ�ϱ���AP�Ĵ���
 �������  : TAF_SDC_SYS_MODE_ENUM_UINT8         enOldSysMode
             TAF_SDC_SYS_MODE_ENUM_UINT8         enNewSysMode
             TAF_SDC_REPORT_SRVSTA_ENUM_UINT8    enOldSrvSta
             TAF_SDC_REPORT_SRVSTA_ENUM_UINT8    enNewSrvSta
 �������  : ��
 �� �� ֵ  : VOS_VOID
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2015��7��17��
    ��    ��   : s00217060
    �޸�����   : �����ɺ���
  2.��    ��   : 2015��9��17��
    ��    ��   : s00217060
    �޸�����   : DTS2015091409113�޸ĺ������
  3.��    ��   : 2015��10��8��
    ��    ��   : l00324781
    �޸�����   : Iteration 18 ,CLģ����״̬��ʾ�Ż�
*****************************************************************************/
VOS_VOID TAF_MMA_ProcRssiReport_ServiceStatusInd(
    TAF_SDC_SYS_MODE_ENUM_UINT8         enOldSysMode
)
{
    TAF_SDC_NETWORK_INFO_STRU          *pstCurNetworkInfo   = VOS_NULL_PTR;
    TAF_SDC_APPNETWORK_INFO            *pstAppNetworkInfo   = VOS_NULL_PTR;

    pstCurNetworkInfo   = TAF_SDC_GetCurrNetworkInfo();
    pstAppNetworkInfo   = TAF_SDC_GetAppNetworkInfo();

    /* ���뼼����A->B,B������Ѿ��ϱ����ź�ǿ�ȣ�����APP����ʾ���Ѿ���B��ע��״̬�����״̬������һ��B�µ��ź�ǿ�� */
    if ((pstCurNetworkInfo->stSigQuaInfo.st3GppRssiInfo.enRat == pstAppNetworkInfo->stAppSysInfo.enSysMode)
     && (pstCurNetworkInfo->stSigQuaInfo.st3GppRssiInfo.enRat != enOldSysMode))
    {
        TAF_MMA_SndAtRssiInd();
    }

    return;
}

#ifdef  __cplusplus
  #if  __cplusplus
  }
  #endif
#endif
