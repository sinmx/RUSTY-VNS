/*******************************************************************************
  Copyright     : 2005-2007, Huawei Tech. Co., Ltd.
  File name     : EmmTAU.c
  Description   : EMM TAU REQUEST������ش�����Դ�ļ�
  Function List :
    01.   NAS_EMM_MsRegSsNormalMsgSysinfo
    02.   NAS_EMM_MsRegSsNormalMsgT3411Exp
    03.   NAS_EMM_MsRegSsNormalMsgT3412Exp
    04.   NAS_EMM_MsRegSsNormalMsgT3402Exp
    05.   NAS_EMM_MsRegSsNormalMsgMmIntraTAUReq
    06.   NAS_EMM_MsRegSsAtpUpdataMsgSysinfo
    07.   NAS_EMM_MsRegSsAtpUpdataMsgT3411Exp
    08.   NAS_EMM_MsRegSsAtpUpdataMsgT3402Exp
    09.   NAS_EMM_MsRegSsLimitSRMsgSysinfo
    10.   NAS_EMM_MsRegSsPLMNSearchMsgSysinfo
    11.   NAS_EMM_MsRegSsUpdataNeedMsgSysinfo
    12.   NAS_EMM_MsRegSsNocellMsgSysinfo
    13.   NAS_EMM_MsTAUInitSsWaitCNCnfMsgTAUAcp
    14.   NAS_EMM_MsTAUInitSsWaitCNCnfMsgTAURej
    15.   NAS_EMM_MsTAUInitSsWaitCNCnfMsgT3430Exp
    16.   NAS_EMM_MsTAUInitSsWaitCNCnfMsgSysinfo
    17.   NAS_EMM_MsTauInitSsWaitCNCnfMsgIntraConnectFailInd
    18.   NAS_EMM_MsTAUInitSsWaitCNCnfMsgRrcRelInd
    19.   NAS_EMM_MsTAUInitSsWaitMrrcRelMsgMrrcRelInd
    20.   NAS_EMM_MsSERInitSsWaitCNCnfMsgSysinfo
    21.   NAS_EMM_MsSERInitSsWaitCNCnfMsgT3411Exp
    22.   NAS_EMM_MsSERInitSsWaitCNCnfMsgT3412Exp
    23.   NAS_EMM_MsSERInitSsWaitCNCnfMsgT3402Exp
    24.   NAS_EMM_MsSERInitSsWaitCNCnfMsgMmIntraTAUReq

  History       :
    1.  Zhouyan     00125190    2008.09.17  �¹�����
    2.  luojian     00107747    2009.01.13  Э����µ�8.0.0
    3.  hanlufeng   41410       2009.04.25  BJ9D00494 ��BAR��Ĵ���������¬�ܾ�
                                ȷ�ϣ����뱻BAR��RRC������ѡ������FORBIDDEN LIST
                                ��С��
    4.  leili       00132387    2009.06.25   BJ9001269 �յ�ϵͳ��Ϣ�����Ż�
*******************************************************************************/

/*****************************************************************************
  1 Include HeadFile
*****************************************************************************/
#include "NasEmmTauSerInclude.h"
#include "NasEmmAttDetInclude.h"
#include "NasEmmTauInterface.h"

/*lint -e767*/
#define    THIS_FILE_ID            PS_FILE_ID_NASEMMTAUREQ_C
#define    THIS_NAS_FILE_ID        NAS_FILE_ID_NASEMMTAUREQ_C
/*lint +e767*/


/*****************************************************************************
  1.1 Cplusplus Announce
*****************************************************************************/
#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif
/*****************************************************************************
  2 Declare the Global Variable
*****************************************************************************/
VOS_UINT32    g_ulIntraHoIgnoreForbidTaFlag = PS_FALSE;



/*******************************************************************************
  Function : NAS_EMM_TAU_StartTAUREQ
  Input    :
  Output   :
  NOTE     :
  Return   :
  History  :
    1.Zhouyan 00125190  2008.09.17  �¹�����
    2.z00148421  2009.03.06
    3.sunjitan 00193151    2012-07-10 Modify: Last attempt reg TA ά��,����save Last TA����
    4.leixiantiao 00258641 2015-07-23 Modify: �������TAU����ԭ��,�����ϱ���HIDS
*******************************************************************************/
VOS_VOID    NAS_EMM_TAU_StartTAUREQ(NAS_LMM_OM_TAU_START_TYPE_ENUM_UINT32 enTauStartType)
{
#if (FEATURE_MULTI_MODEM == FEATURE_ON)
    TAF_CTRL_STRU                                           stCtrl;
    MTC_SESSION_TYPE_ENUM_UINT8                             enMtcSessionType = MTC_SESSION_TYPE_BUTT;
    PS_MEM_SET(&stCtrl, 0x00, sizeof(TAF_CTRL_STRU));
#endif

    /* ��ӡ����ú����� INFO_LEVEL */
    NAS_EMM_TAU_LOG_NORM( "NAS_EMM_TAU_StartTAUREQ is entered");
    TLPS_PRINT2LAYER_INFO(NAS_EMM_TAU_StartTAUREQ_ENUM,LNAS_ENTRY);

    /* �������L����������������TAU���򲻷���תΪ����DETACH����ATTACH */
    if (NAS_LMM_UE_RADIO_CAP_LTE_CHG == NAS_LMM_GetEmmInfoUeRadioCapChgFlag())
        {
            /*��Ҫ����TAU��SER��Դ, ������ĺ��������н��������������Դ*/
            NAS_EMM_TAU_LOG_NORM("NAS_EMM_TAU_StartTAUREQ:  LTE change, local detach and re-attach needed.");
             TLPS_PRINT2LAYER_INFO(NAS_EMM_TAU_StartTAUREQ_ENUM,LNAS_FUNCTION_LABEL1);
            NAS_EMM_SomeStateRcvMsgSysInfoLteRadioCapChgCommProc();
            return;
    }
    /* ����TAU�������� */
    NAS_LMM_SndOmTauStartTypeInfo(enTauStartType);

    /* ������:����TAU������� */
    NAS_LMM_AddTauCounter(NAS_LMM_OM_PCE_TIMES_TYPE_TOTAL);
    /*������ʱ��T3430*/
    NAS_LMM_StartStateTimer(TI_NAS_EMM_STATE_TAU_T3430);

    NAS_LMM_Stop3402Timer();
    NAS_LMM_StopPtlTimer(TI_NAS_EMM_PTL_T3411);

    NAS_LMM_StopStateTimer(TI_NAS_EMM_STATE_SERVICE_T3442);

    /* ���UPDATE_MM��ʶ */
    /*NAS_LMM_SetEmmInfoUpdateMmFlag(NAS_EMM_UPDATE_MM_FLAG_INVALID);*/

    /* DTS201202070220 �����Ƿ����������ݺ�����pending���ж� */
    NAS_EMM_TAU_IsUplinkPending();

    /*ת��EMM״̬��MS_TAU_INIT+SS_TAU_WAIT_CN_TAU_CNF*/
    NAS_EMM_TAUSER_FSMTranState(EMM_MS_TAU_INIT, EMM_SS_TAU_WAIT_CN_TAU_CNF, TI_NAS_EMM_STATE_TAU_T3430);

    #if (FEATURE_ON == FEATURE_DSDS)
    /*����begin notify��Ϣ��RRC��֪ͨRRC������Դ*/
    NAS_EMM_TAU_SendRrcDsdsBeginNotify();
    #endif

    /*��ϲ�����MRRC_DATA_REQ(TAU_REQ)*/
    if(NAS_EMM_TRIGGER_TAU_RRC_REL_LOAD_BALANCE ==
                                        NAS_LMM_GetEmmInfoTriggerTauRrcRel())
    {
        NAS_EMM_TAU_SendMrrcDataReq_TAUReq(       NAS_EMM_MSG_LOAD_BALANCING_TAU);
    }
    else
    {
        NAS_EMM_TAU_SendMrrcDataReq_TAUReq(       NAS_EMM_MSG_NOT_LOAD_BALANCING_TAU);
    }

    /* ����TAU������ǰ������Ϣͬ����Last���Է���ע���������Ϣ�� */
    NAS_EMM_SaveLastAttemptRegTa();


    /*���TAU_REQ����ʧ��ԭ����LRRC�ͷű�ʶ*/
    NAS_LMM_SetTauReqSndFailFlag(PS_FALSE);

#if (FEATURE_MULTI_MODEM == FEATURE_ON)
    stCtrl.ulModuleId = PS_PID_MM;
    enMtcSessionType = NAS_EMM_GetTAUMtcSessionType();

    MTC_SetBeginSessionInfo(&stCtrl,enMtcSessionType);
#endif
    return;
}

/*******************************************************************************
  Module   :
  Function : Nas_Emm_TAU_RcvSysinfo
  Input    :
  Output   :
  NOTE     :
  Return   :
  History  :
    1.  Zhouyan 00125190  2008.09.17  �¹�����
*******************************************************************************/
/*lint -e960*/
/*lint -e961*/
VOS_UINT32 NAS_EMM_TAU_IsCurrentTAInTaList(VOS_VOID)
{
    VOS_UINT32                          ulTARslt         = NAS_EMM_FAIL;
    NAS_MM_TA_STRU                      stPresentTa;
    NAS_MM_TA_LIST_STRU                 stLastTaiList;

    NAS_LMM_MEM_SET_S(  &stLastTaiList,
                        sizeof(NAS_MM_TA_LIST_STRU),
                        0,
                        sizeof(NAS_MM_TA_LIST_STRU));

    /*��ȡ��ǰ��TA*/
    NAS_LMM_MEM_CPY_S(      &(stPresentTa.stPlmnId),
                            sizeof(NAS_MM_PLMN_ID_STRU),
                            &(g_stEmmInfo.stNetInfo.stPresentNetId.stPlmnId),
                            sizeof(NAS_MM_PLMN_ID_STRU));

    NAS_LMM_MEM_CPY_S(      &(stPresentTa.stTac),
                            sizeof(NAS_MM_TAC_STRU),
                            &(g_stEmmInfo.stNetInfo.stPresentNetId.stTac),
                            sizeof(NAS_MM_TAC_STRU));

    /*��ȡ�ϴ�ע���TA List*/
    NAS_LMM_MEM_CPY_S(      &(stLastTaiList),
                            sizeof(NAS_MM_TA_LIST_STRU),
                            &(g_stEmmInfo.stNetInfo.stTaiList),
                            sizeof(NAS_MM_TA_LIST_STRU));

    /*�жϵ�ǰTA�Ƿ���TA List��*/
    ulTARslt = NAS_LMM_TaMatchTaList(&stPresentTa, &stLastTaiList);

    /*����µ�TA��TA List��*/
    if(NAS_LMM_MATCH_SUCCESS == ulTARslt)
    {
        NAS_EMM_TAU_LOG_INFO("NAS_EMM_TAU_IsCurrentTAInTaList:TA is in the TAI List.");
        TLPS_PRINT2LAYER_INFO(NAS_EMM_TAU_IsCurrentTAInTaList_ENUM,LNAS_FUNCTION_LABEL1);
        return NAS_EMM_SUCC;
    }
    /*TA����TA List�У���Ҫ����TAU����*/
    else
    {
        NAS_EMM_TAU_LOG_INFO( "NAS_EMM_TAU_IsCurrentTAInTaList:TA is not in the TAI List,TAU Need.");
        TLPS_PRINT2LAYER_INFO(NAS_EMM_TAU_IsCurrentTAInTaList_ENUM,LNAS_EMM_TA_NOT_IN_TA_LIST);
        return NAS_EMM_FAIL;
    }
}
#if(FEATURE_ON == FEATURE_CSG)
/*******************************************************************************
  Function : NAS_EMM_TAU_IsCSGIdInAllowedOrOperaterCSGList
  Input    :
  Output   :
  NOTE     :
  Return   :
  History  :
    1.yanglei 00307272  2015-09-24  �¹�����
*******************************************************************************/
VOS_UINT32 NAS_EMM_TAU_IsCsgIdInAllowedOrOperatorCsgList(VOS_VOID)
{
    VOS_UINT32                          ulCsgRslt         = NAS_EMM_FAIL;

    NAS_MML_PLMN_WITH_CSG_ID_LIST_STRU  *pstAllowedCsgList;
    NAS_MML_PLMN_WITH_CSG_ID_LIST_STRU  *pstOperatorCsgList;


    pstAllowedCsgList  = NAS_MML_GetAllowedCsgList();
    pstOperatorCsgList = NAS_MML_GetOperatorCsgList();


    /*�жϵ�ǰCSG ID�Ƿ���CSG List��*/
    ulCsgRslt = NAS_LMM_CsgIdMatchAllowedOrOperatorCsgList(pstAllowedCsgList,pstOperatorCsgList);

    /*����µ�CSG��CSG List��*/
    if(NAS_LMM_MATCH_SUCCESS == ulCsgRslt)
    {
        NAS_EMM_TAU_LOG_INFO("NAS_EMM_TAU_IsCSGIdInAllowedOrOperatorCSGList:CSG ID is in the CSG List.");
        TLPS_PRINT2LAYER_INFO(NAS_EMM_TAU_IsCSGIdInAllowedOrOperatorCSGList_ENUM,LNAS_FUNCTION_LABEL1);
        return NAS_EMM_SUCC;
    }
    /*CSG����CSG List�У���Ҫ����TAU����*/
    else
    {
        NAS_EMM_TAU_LOG_INFO( "NAS_EMM_TAU_IsCSGIdInAllowedOrOperatorCSGList:CSG ID is not in the CSG List,TAU Need.");
        TLPS_PRINT2LAYER_INFO(NAS_EMM_TAU_IsCSGIdInAllowedOrOperatorCSGList_ENUM,LNAS_FUNCTION_LABEL2);
        return NAS_EMM_FAIL;
    }
}
#endif

/*******************************************************************************
  Module   :
  Function : NAS_EMM_MsRegSsNormalMsgSysinfo
  Input    :
  Output   :
  NOTE     :
  Return   :
  History  :
    1.  Zhouyan 00125190  2008.09.10  �¹�����
    2.  zhengjunyan 00148421 2011-02-15 DTS2011021401149
    3.  sunjitan 00193151     2011-09-13    DTS2011080801319
    4.  sunjitan 00193151     2012-02-02   Modify for UE radio capability
    5.  lihong 00150010       2012-12-18   Modify:Emergency
    6.  leixiantiao 00258641  2015-07-03   fix DTS2015062301014
*******************************************************************************/
VOS_UINT32 NAS_EMM_MsRegSsNormalMsgSysinfo(VOS_UINT32  ulMsgId,
                                                   VOS_VOID   *pMsgStru)
{
    VOS_UINT32                          ulRslt          = NAS_EMM_FAIL;
    EMMC_EMM_SYS_INFO_IND_STRU         *pstsysinfo      = NAS_EMM_NULL_PTR;
    EMMC_EMM_FORBIDDEN_INFO_ENUM_UINT32  ulForbiddenInfo = EMMC_EMM_NO_FORBIDDEN;

    pstsysinfo                          = (EMMC_EMM_SYS_INFO_IND_STRU*)pMsgStru;

    (VOS_VOID)ulMsgId;

    /* ��ӡ����ú����� INFO_LEVEL */
    NAS_EMM_TAU_LOG_INFO("Nas_Emm_MsRegSsNormalMsgSysinfo is entered.");
    TLPS_PRINT2LAYER_INFO(NAS_EMM_MsRegSsNormalMsgSysinfo_ENUM,LNAS_ENTRY);

    ulRslt = NAS_EMM_TAU_CHKFSMStateMsgp(EMM_MS_REG,EMM_SS_REG_NORMAL_SERVICE,pMsgStru);

    /* ��������ָ��������, ״̬ƥ����,����ƥ��,�˳�*/
    if(NAS_EMM_SUCC != ulRslt)
    {
        /* ��ӡ�쳣 */
        NAS_EMM_TAU_LOG_WARN("NAS_EMM_MsRegSsNormalMsgSysinfo:ERROR !!");
        TLPS_PRINT2LAYER_WARNING(NAS_EMM_MsRegSsNormalMsgSysinfo_ENUM,LNAS_ERROR);
        return NAS_LMM_MSG_DISCARD;
    }
    /* ����ϵͳ���л�������С��,���Ա���:������LС��A��B(������TA)
        UE��С��B��פ��������MMEĳЩ�쳣,��UE�·�ԭ��ֵ#15����MMEδ��
        TA���뱻���б���(δ�汻����ֻ����ʱ����)����UE�յ�#15ԭ��ֵ,
        ����������פ����AС����֮��������UE�л���BС�������л�ʱLRRC
        �����ж�С���Ƿ񱻽���LMM�յ�ϵͳ��Ϣ����BС�����յ���#15ԭ
        ��ֵ,LMM�����ͷŽ������Ʒ���̬��LRRC�ͷź���С��A��פ�����Ӷ�����ƹ���л� */
    ulForbiddenInfo = pstsysinfo->ulForbiddenInfo;
    if(NAS_EMM_YES == NAS_EMM_IsIntraHoIgnoreForbSysInfo())
    {
        /* ����FORBIDDEN TA FOR ROAMING,���ڱ�#15ԭ��ֵ�ܺ�,פ����TA������FORBIDDEN TA LIST��,����TAILIST��ɾ�������Ժ�������TAU */
        if(EMMC_EMM_FORBIDDEN_TA_FOR_ROAMING == pstsysinfo->ulForbiddenInfo)
        {
            NAS_EMM_PUBU_LOG1_INFO("NAS_EMM_MsRegSsNormalMsgSysinfo Ignore ForbTaForRoaming:forbiddenInfo = ",
                               pstsysinfo->ulForbiddenInfo);
            TLPS_PRINT2LAYER_INFO1(NAS_EMM_MsRegSsNormalMsgSysinfo_ENUM,LNAS_EMM_FORB_INFO,
                               pstsysinfo->ulForbiddenInfo );
            ulForbiddenInfo = EMMC_EMM_NO_FORBIDDEN;
            #if (FEATURE_ON == FEATURE_PTM)
            NAS_EMM_ImprovePerformceeErrReport(EMM_OM_ERRLOG_IMPROVEMENT_TYPE_HO_TO_FORBIDDEN_TA);
            #endif
        }
    }
    /*���ݽ�ֹ��Ϣ�ж��Ƿ�����ǰ��ϵͳ��Ϣ*/
    if ((NAS_LMM_REG_STATUS_NORM_REGED == NAS_LMM_GetEmmInfoRegStatus())
        && ((EMMC_EMM_NO_FORBIDDEN != ulForbiddenInfo)
            || (EMMC_EMM_CELL_STATUS_ANYCELL == pstsysinfo->ulCellStatus)))
    {
        NAS_EMM_SetTauTypeNoProcedure();

        /*ת��EMM״̬��*/
        NAS_EMM_TAUSER_FSMTranState(EMM_MS_REG,
                                    EMM_SS_REG_LIMITED_SERVICE,
                                    TI_NAS_EMM_STATE_NO_TIMER);

        /*��MMC����LMM_MMC_TAU_RESULT_IND��Ϣ*/
        NAS_EMM_MmcSendTauActionResultIndForbType((VOS_VOID*)&pstsysinfo->ulForbiddenInfo);
        /* �����ǰCSFB��ʱ��ʱ�������У�˵��֮ǰ���ͷŹ������յ���CSFB��
           ���������ֱ�ӱ�SERVICEʧ�ܴ���MMC����ȥGU */
        if(NAS_LMM_TIMER_RUNNING == NAS_LMM_IsPtlTimerRunning(TI_NAS_EMM_PTL_CSFB_DELAY))
        {
            /* ֹͣCSFBʱ�Ӷ�ʱ�� */
            NAS_LMM_StopPtlTimer(TI_NAS_EMM_PTL_CSFB_DELAY);

            /* ��MMC�ϱ�SERVICEʧ�ܴ�������ȥGU */
            NAS_EMM_MmcSendSerResultIndOtherType(MMC_LMM_SERVICE_RSLT_FAILURE);
        }
        if (MMC_LMM_CONN_IDLE != NAS_EMM_GetConnState())
        {
            NAS_EMM_TAU_LOG_INFO("Nas_Emm_MsRegSsNormalMsgSysinfo: Connected");
            TLPS_PRINT2LAYER_INFO(NAS_EMM_MsRegSsNormalMsgSysinfo_ENUM,LNAS_FUNCTION_LABEL1);

            /*����NAS_EMM_REL_REQ*/
            NAS_EMM_RelReq(         NAS_LMM_NOT_BARRED);
        }
        return NAS_LMM_MSG_HANDLED;
    }

    /* �����ǰCSFB��ʱ��ʱ�������У�˵��֮ǰ��REG-NORMAL̬�ͷŹ������յ���CSFB��
       �����յ�ϵͳ��Ϣ������Ҫ����TAU�����߳�ͻ��������������ȷ���TAU��֮���ٽ��SERVICE�ĳ�ͻ */
    if(NAS_LMM_TIMER_RUNNING == NAS_LMM_IsPtlTimerRunning(TI_NAS_EMM_PTL_CSFB_DELAY))
    {
        /* ֹͣCSFBʱ�Ӷ�ʱ�� */
        NAS_LMM_StopPtlTimer(TI_NAS_EMM_PTL_CSFB_DELAY);

        /* �������̳�ͻ��־λ�����淢��TAUʱ������ڳ�ͻ��ȻЯ��active flag��
           SERVICE����ԭ�򲻱ؼ�¼��������CSFB��ʱ��ʱ��ʱ�Ѿ��������� */
        NAS_EMM_TAU_SaveEmmCollisionCtrl(NAS_EMM_COLLISION_SERVICE);
        /* �������,�����ж�С����Ϣ�Ƿ����ı� */
        NAS_EMM_MsRegSsNormalCsfbDelayProc(pstsysinfo->ulChangeInfo);
    }
    else
    {
        /* �������,�����ж�С����Ϣ�Ƿ����ı� */
        NAS_EMM_RegNormalServiceOrUpdateMMMsgSysInfoCommProc(pstsysinfo->ulChangeInfo);
    }

    return NAS_LMM_MSG_HANDLED;
}

/*****************************************************************************
 Function Name   : NAS_EMM_MsRegSsRegAttemptUpdateMmMsgSysinfo
 Description     : ״̬REG+REG_ATTEMPTING_TO_UPDATE_MM�յ�ϵͳ��Ϣ
 Input           : None
 Output          : None
 Return          : VOS_UINT32

 History         :
    1.leili 00132387      2011-7-12  Draft Enact
    2.sunjitan 00193151   2012-02-07 Modify  for UE Radio capability
    3.l00150010           2012-12-19 Modify:Emergency
*****************************************************************************/
VOS_UINT32  NAS_EMM_MsRegSsRegAttemptUpdateMmMsgSysinfo
(
    VOS_UINT32  ulMsgId,
    VOS_VOID   *pMsgStru
)
{
    VOS_UINT32                          ulRslt          = NAS_EMM_FAIL;
    EMMC_EMM_SYS_INFO_IND_STRU         *pstsysinfo      = NAS_EMM_NULL_PTR;
    EMMC_EMM_FORBIDDEN_INFO_ENUM_UINT32  ulForbiddenInfo = EMMC_EMM_NO_FORBIDDEN;

    pstsysinfo                          = (EMMC_EMM_SYS_INFO_IND_STRU*)pMsgStru;

    (VOS_VOID)ulMsgId;

    /* ��ӡ����ú����� INFO_LEVEL */
    NAS_EMM_TAU_LOG_INFO("NAS_EMM_MsRegSsRegAttemptUpdateMmMsgSysinfo is entered.");
    TLPS_PRINT2LAYER_INFO(NAS_EMM_MsRegSsRegAttemptUpdateMmMsgSysinfo_ENUM,LNAS_ENTRY);

    ulRslt = NAS_EMM_TAU_CHKFSMStateMsgp(   EMM_MS_REG,
                                            EMM_SS_REG_ATTEMPTING_TO_UPDATE_MM,
                                            pMsgStru);

    /* ��������ָ��������, ״̬ƥ����,����ƥ��,�˳�*/
    if(NAS_EMM_SUCC != ulRslt)
    {
        /* ��ӡ�쳣 */
        NAS_EMM_TAU_LOG_WARN("NAS_EMM_MsRegSsRegAttemptUpdateMmMsgSysinfo:ERROR !!");
        TLPS_PRINT2LAYER_WARNING(NAS_EMM_MsRegSsRegAttemptUpdateMmMsgSysinfo_ENUM,LNAS_ERROR);
        return NAS_LMM_MSG_DISCARD;
    }
    /* ����ϵͳ���л�������С��,���Ա���:������LС��A��B(������TA)
        UE��С��B��פ��������MMEĳЩ�쳣,��UE�·�ԭ��ֵ#15����MMEδ��
        TA���뱻���б���(δ�汻����ֻ����ʱ����)����UE�յ�#15ԭ��ֵ,
        ����������פ����AС����֮��������UE�л���BС�������л�ʱLRRC
        �����ж�С���Ƿ񱻽���LMM�յ�ϵͳ��Ϣ����BС�����յ���#15ԭ
        ��ֵ,LMM�����ͷŽ������Ʒ���̬��LRRC�ͷź���С��A��פ�����Ӷ�����ƹ���л� */
    ulForbiddenInfo = pstsysinfo->ulForbiddenInfo;
    if(NAS_EMM_YES == NAS_EMM_IsIntraHoIgnoreForbSysInfo())
    {
        /* ����FORBIDDEN TA FOR ROAMING,���ڱ�#15ԭ��ֵ�ܺ�,פ����TA������FORBIDDEN TA LIST��,����TAILIST��ɾ�������Ժ�������TAU */
        if(EMMC_EMM_FORBIDDEN_TA_FOR_ROAMING == pstsysinfo->ulForbiddenInfo)
        {
            NAS_EMM_PUBU_LOG1_INFO("NAS_EMM_MsRegSsNormalMsgSysinfo Ignore ForbTaForRoaming:forbiddenInfo = ",
                               pstsysinfo->ulForbiddenInfo);
            TLPS_PRINT2LAYER_INFO1(NAS_EMM_MsRegSsRegAttemptUpdateMmMsgSysinfo_ENUM,LNAS_EMM_FORB_INFO,
                               pstsysinfo->ulForbiddenInfo);
            ulForbiddenInfo = EMMC_EMM_NO_FORBIDDEN;
            #if (FEATURE_ON == FEATURE_PTM)
            NAS_EMM_ImprovePerformceeErrReport(EMM_OM_ERRLOG_IMPROVEMENT_TYPE_HO_TO_FORBIDDEN_TA);
            #endif
        }
    }
    /*���ݽ�ֹ��Ϣ�ж��Ƿ�����ǰ��ϵͳ��Ϣ*/
    if ((NAS_LMM_REG_STATUS_NORM_REGED == NAS_LMM_GetEmmInfoRegStatus())
        && ((EMMC_EMM_NO_FORBIDDEN != ulForbiddenInfo)
            || (EMMC_EMM_CELL_STATUS_ANYCELL == pstsysinfo->ulCellStatus)))
    {
        /*NAS_LMM_SetEmmInfoUpdateMmFlag(NAS_EMM_UPDATE_MM_FLAG_VALID);*/

        NAS_EMM_SetTauTypeNoProcedure();

        /*ת��EMM״̬��*/
        NAS_EMM_TAUSER_FSMTranState(    EMM_MS_REG,
                                        EMM_SS_REG_LIMITED_SERVICE,
                                        TI_NAS_EMM_STATE_NO_TIMER);

        /*��MMC����LMM_MMC_TAU_RESULT_IND��Ϣ*/
        NAS_EMM_MmcSendTauActionResultIndForbType((VOS_VOID*)&pstsysinfo->ulForbiddenInfo);

        if (MMC_LMM_CONN_IDLE != NAS_EMM_GetConnState())
        {
            NAS_EMM_TAU_LOG_INFO("NAS_EMM_MsRegSsRegAttemptUpdateMmMsgSysinfo: Limited Srv Connected");
            TLPS_PRINT2LAYER_INFO(NAS_EMM_MsRegSsRegAttemptUpdateMmMsgSysinfo_ENUM,LNAS_FUNCTION_LABEL1);

            /*����NAS_EMM_REL_REQ*/
            NAS_EMM_RelReq(         NAS_LMM_NOT_BARRED);
        }
        return NAS_LMM_MSG_HANDLED;
    }
     /*�ж�TA�����仯������TAU ATTEMPT COUNTER,����TAU*/
    if((EMMC_EMM_CHANGE_PLMN == pstsysinfo->ulChangeInfo)
      ||(EMMC_EMM_CHANGE_TA == pstsysinfo->ulChangeInfo))
    {
        NAS_EMM_TAU_SaveEmmTAUAttemptCnt(NAS_EMM_TAU_ATTEMPT_CNT_ZERO);
    }

    /* �������,�����ж�С����Ϣ�Ƿ����ı� */
    NAS_EMM_RegNormalServiceOrUpdateMMMsgSysInfoCommProc(pstsysinfo->ulChangeInfo);
    return NAS_LMM_MSG_HANDLED;
}


/*****************************************************************************
 Function Name   : NAS_EMM_MsRegSsNmlSrvProcMsgRrcRelInd
 Description     : ����RRC_REL_IND��Ϣ
 Input           : None
 Output          : None
 Return          : VOS_UINT32

 History         :
    1.X00148705    2009-9-30  Draft Enact
    2.X00148705    2009-11-13 �޸ĺ��ع�
    3.Z00148421    2009-12-15 ��Ϣ����ʧ�ܵĴ���
    4.Z00148421    2010-12-22 DTS2010111701490:CONN_FAIL�� LOAD_BALANCE_REQԭ��ֵ
                              ����������TAU���յ�SYS_INFO_IND�ٴ�����
*****************************************************************************/
VOS_VOID  NAS_EMM_MsRegSsNmlSrvProcMsgRrcRelInd( VOS_UINT32 ulCause )
{

    NAS_EMM_TAU_LOG_INFO(                         "NAS_EMM_MsRegSsNmlSrvProcMsgRrcRelInd is entered.");
    TLPS_PRINT2LAYER_INFO(NAS_EMM_MsRegSsNmlSrvProcMsgRrcRelInd_ENUM,LNAS_ENTRY);

    /*�����ڲ���Ϣ INTRA_CONN2IDLE_REQ,��������״̬*/
    NAS_EMM_CommProcConn2Ilde();

    /* ͣT3411��ʱ�� */
    NAS_LMM_StopPtlTimer(TI_NAS_EMM_PTL_T3411);

    /* ����RRCЯ�����ͷ�ԭ��ֵ����ͬ����*/
    switch(ulCause)
    {
        case LRRC_LNAS_REL_CAUSE_LOAD_BALANCE_REQ:
            /*NAS_EMM_TAU_SaveEmmTAUStartCause(NAS_EMM_TAU_START_CAUSE_RRC_REL_LOAD_BALANCE);*/
            NAS_EMM_TAU_SaveEmmTAUStartCause(NAS_EMM_TAU_START_CAUSE_OTHERS);
            NAS_LMM_SetEmmInfoTriggerTauRrcRel(NAS_EMM_TRIGGER_TAU_RRC_REL_LOAD_BALANCE);
            /*
            NAS_EMM_TAUSER_FSMTranState(   EMM_MS_REG,
                                           EMM_SS_REG_PLMN_SEARCH,
                                           TI_NAS_EMM_STATE_NO_TIMER);
            */
             break;

        case LRRC_LNAS_REL_CAUSE_CONN_FAIL:
            /*NAS_EMM_TAU_SaveEmmTAUStartCause(NAS_EMM_TAU_START_CAUSE_RRC_REL_CONN_FAILURE);*/
            NAS_EMM_TAU_SaveEmmTAUStartCause(NAS_EMM_TAU_START_CAUSE_OTHERS);
            NAS_LMM_SetEmmInfoTriggerTauRrcRel(NAS_EMM_TRIGGER_TAU_RRC_REL_CONN_FAILURE);
            /*
            NAS_EMM_TAUSER_FSMTranState(   EMM_MS_REG,
                                           EMM_SS_REG_PLMN_SEARCH,
                                           TI_NAS_EMM_STATE_NO_TIMER);
            */
            break;

        default:
            /* ����ԭ�򲻻ᵼ��TAU�������� */;
            NAS_EMM_TAU_LOG1_INFO("NAS_EMM_MsRegSsNmlSrvProcMsgRrcRelInd: ulCause = ", ulCause);
            TLPS_PRINT2LAYER_INFO1(NAS_EMM_MsRegSsNmlSrvProcMsgRrcRelInd_ENUM,LNAS_CAUSE_NUMBER,ulCause);
            break;

    }

    return;
}

/*****************************************************************************
 Function Name   : NAS_EMM_MsRegSsRegAttemptUpdateMmProcMsgRrcRelInd
 Description     : ����RRC_REL_IND��Ϣ
 Input           : None
 Output          : None
 Return          : VOS_UINT32

 History         :
    1.lihong00150010    2014-09-03  Draft Enact
*****************************************************************************/
VOS_VOID  NAS_EMM_MsRegSsRegAttemptUpdateMmProcMsgRrcRelInd
(
    VOS_UINT32                          ulCause
)
{
    /*�����ڲ���Ϣ INTRA_CONN2IDLE_REQ,��������״̬*/
    NAS_EMM_CommProcConn2Ilde();

    /* ����RRCЯ�����ͷ�ԭ��ֵ����ͬ����*/
    switch(ulCause)
    {
        case LRRC_LNAS_REL_CAUSE_LOAD_BALANCE_REQ:

            /* ��¼UPDATE_MM��ʶ */
            /*NAS_LMM_SetEmmInfoUpdateMmFlag(NAS_EMM_UPDATE_MM_FLAG_VALID);*/
            /*NAS_EMM_TAU_SaveEmmTAUStartCause(NAS_EMM_TAU_START_CAUSE_RRC_REL_LOAD_BALANCE);*/
            NAS_EMM_TAU_SaveEmmTAUStartCause(NAS_EMM_TAU_START_CAUSE_OTHERS);
            NAS_LMM_SetEmmInfoTriggerTauRrcRel(NAS_EMM_TRIGGER_TAU_RRC_REL_LOAD_BALANCE);
            /*
            NAS_EMM_TAUSER_FSMTranState(    EMM_MS_REG,
                                            EMM_SS_REG_PLMN_SEARCH,
                                            TI_NAS_EMM_STATE_NO_TIMER);
            */
            break;

        case LRRC_LNAS_REL_CAUSE_CONN_FAIL:

            /* ��¼UPDATE_MM��ʶ */
            /* NAS_LMM_SetEmmInfoUpdateMmFlag(NAS_EMM_UPDATE_MM_FLAG_VALID);*/
            /*NAS_EMM_TAU_SaveEmmTAUStartCause(NAS_EMM_TAU_START_CAUSE_RRC_REL_CONN_FAILURE);*/
            NAS_EMM_TAU_SaveEmmTAUStartCause(NAS_EMM_TAU_START_CAUSE_OTHERS);
            NAS_LMM_SetEmmInfoTriggerTauRrcRel(NAS_EMM_TRIGGER_TAU_RRC_REL_CONN_FAILURE);
            /*
            NAS_EMM_TAUSER_FSMTranState(   EMM_MS_REG,
                                           EMM_SS_REG_PLMN_SEARCH,
                                           TI_NAS_EMM_STATE_NO_TIMER);
            */
            break;

        default:
            /* ����ԭ�򲻻ᵼ��TAU�������� */;
            NAS_EMM_TAU_LOG1_INFO("NAS_EMM_MsRegSsRegAttemptUpdateMmProcMsgRrcRelInd: ulCause = ", ulCause);
            TLPS_PRINT2LAYER_INFO1(NAS_EMM_MsRegSsRegAttemptUpdateMmProcMsgRrcRelInd_ENUM,LNAS_CAUSE_NUMBER,ulCause);
            break;

    }

    return ;
}
/*****************************************************************************
 Function Name  : NAS_EMM_MsRegSsNmlSrvMsgRrcRelInd
 Discription    : sRegSsNmlSrv״̬�£��յ�RRC_REL_IND��Ϣ
 Input          : None
 Output         : None
 Return         :
 History:
      1.  z00148421  2008-12.29  Draft Enact
      2.  X00148705  2009-09-30  �ع�
*****************************************************************************/
VOS_UINT32  NAS_EMM_MsRegSsNmlSrvMsgRrcRelInd(
                                                    VOS_UINT32 ulMsgId,
                                                    VOS_VOID *pMsgStru)
{
    LRRC_LMM_REL_IND_STRU        *pMsgRrcRelInd  =    (LRRC_LMM_REL_IND_STRU *)pMsgStru;
    VOS_UINT32                  ulCause;

    (VOS_VOID)ulMsgId;

    NAS_EMM_TAU_LOG_NORM("NAS_EMM_MsRegSsNmlSrvMsgRrcRelInd is entered.");
    TLPS_PRINT2LAYER_INFO(NAS_EMM_MsRegSsNmlSrvMsgRrcRelInd_ENUM,LNAS_ENTRY);

    /*���ԭ��ֵ*/
    ulCause                                    =    pMsgRrcRelInd->enRelCause;

    NAS_EMM_MsRegSsNmlSrvProcMsgRrcRelInd(          ulCause);

    return NAS_LMM_MSG_HANDLED;
}

/*****************************************************************************
 Function Name   : NAS_EMM_MsRegSsRegAttemptUpdateMmMsgRrcRelInd
 Description     : ״̬REG+REG_ATTEMPTING_TO_UPDATE_MM�յ�RRC_MM_REL_IND��Ϣ
 Input           : ulMsgId-------------------------��ϢID
                   pMsgStru------------------------��Ϣָ��
 Output          : None
 Return          : VOS_UINT32

 History         :
    1.leili 00132387      2011-7-12     Draft Enact
    2.lihong 00150010     2011-11-17    Modify

*****************************************************************************/
VOS_UINT32  NAS_EMM_MsRegSsRegAttemptUpdateMmMsgRrcRelInd
(
    VOS_UINT32                          ulMsgId,
    VOS_VOID                           *pMsgStru
)
{
    LRRC_LMM_REL_IND_STRU        *pMsgRrcRelInd  = (LRRC_LMM_REL_IND_STRU *)pMsgStru;

    (VOS_VOID)ulMsgId;

    NAS_EMM_TAU_LOG_NORM("NAS_EMM_MsRegSsRegAttemptUpdateMmMsgRrcRelInd is entered.");
    TLPS_PRINT2LAYER_INFO(NAS_EMM_MsRegSsRegAttemptUpdateMmMsgRrcRelInd_ENUM,LNAS_ENTRY);

    NAS_EMM_MsRegSsRegAttemptUpdateMmProcMsgRrcRelInd(pMsgRrcRelInd->enRelCause);

    return NAS_LMM_MSG_HANDLED;
}

/*******************************************************************************
  Module   :
  Function : NAS_EMM_MsRegSsNormalMsgT3411Exp
  Input    :
  Output   :
  NOTE     :
  Return   :
  History  :
    1.  Zhouyan 00125190  2008.09.10  �¹�����
*******************************************************************************/
VOS_UINT32 NAS_EMM_MsRegSsNormalMsgT3411Exp(VOS_UINT32  ulMsgId,
                                                   VOS_VOID   *pMsgStru )
{
    VOS_UINT32                          ulRslt  = NAS_EMM_FAIL;

    (VOS_VOID)ulMsgId;

    /* ��ӡ����ú����� INFO_LEVEL */
    NAS_EMM_TAU_LOG_INFO("NAS_EMM_MsRegSsNormalMsgT3411Exp is entered.");
    TLPS_PRINT2LAYER_INFO(NAS_EMM_MsRegSsNormalMsgT3411Exp_ENUM,LNAS_ENTRY);

    ulRslt = NAS_EMM_TAU_CHKFSMStateMsgp(EMM_MS_REG,EMM_SS_REG_NORMAL_SERVICE,pMsgStru);

    /* ��������ָ��������, ״̬ƥ����,����ƥ��,�˳�*/
    if(NAS_EMM_SUCC != ulRslt)
    {
        /* ��ӡ�쳣 */
        NAS_EMM_TAU_LOG_WARN("NAS_EMM_MsRegSsNormalMsgT3411Exp ERROR !!");
        TLPS_PRINT2LAYER_WARNING(NAS_EMM_MsRegSsNormalMsgT3411Exp_ENUM,LNAS_ERROR);
        return NAS_LMM_MSG_DISCARD;
    }

    /*������Ϣ��������*/
    /* �������TAU����ԭ�� */
    NAS_EMM_TAU_StartTAUREQ(NAS_LMM_OM_TAU_START_TYPE_3411OR3402);

    return NAS_LMM_MSG_HANDLED;

}
/*******************************************************************************
  Module   : REG+ATTEMPT_TO_UPDATE_MM״̬���յ�T3411��ʱ
  Function : NAS_EMM_MsRegSsRegAttemptUpdateMmMsgT3411Exp
  Input    :
  Output   :
  NOTE     :
  Return   :
  History  :
    1.  lihong00150010  2011.11.17  �¹�����
*******************************************************************************/
VOS_UINT32 NAS_EMM_MsRegSsRegAttemptUpdateMmMsgT3411Exp
(
    VOS_UINT32                          ulMsgId,
    VOS_VOID                           *pMsgStru
)
{
    VOS_UINT32                          ulRslt  = NAS_EMM_FAIL;

    (VOS_VOID)ulMsgId;

    /* ��ӡ����ú����� INFO_LEVEL */
    NAS_EMM_TAU_LOG_INFO("NAS_EMM_MsRegSsRegAttemptUpdateMmMsgT3411Exp is entered.");
    TLPS_PRINT2LAYER_INFO(NAS_EMM_MsRegSsRegAttemptUpdateMmMsgT3411Exp_ENUM,LNAS_ENTRY);

    ulRslt = NAS_EMM_TAU_CHKFSMStateMsgp(EMM_MS_REG,EMM_SS_REG_ATTEMPTING_TO_UPDATE_MM,pMsgStru);

    /* ��������ָ��������, ״̬ƥ����,����ƥ��,�˳�*/
    if(NAS_EMM_SUCC != ulRslt)
    {
        /* ��ӡ�쳣 */
        NAS_EMM_TAU_LOG_WARN("NAS_EMM_MsRegSsRegAttemptUpdateMmMsgT3411Exp ERROR !!");
        TLPS_PRINT2LAYER_WARNING(NAS_EMM_MsRegSsRegAttemptUpdateMmMsgT3411Exp_ENUM,LNAS_ERROR);
        return NAS_LMM_MSG_DISCARD;
    }

    /*NAS_EMM_TAU_SaveEmmTAUStartCause(NAS_EMM_TAU_START_CAUSE_IMSI_ATTACH);*/
    NAS_EMM_TAU_SaveEmmTAUStartCause(NAS_EMM_TAU_START_CAUSE_OTHERS);

    /*������Ϣ��������*/
    /* �������TAU����ԭ�� */
    NAS_EMM_TAU_StartTAUREQ(NAS_LMM_OM_TAU_START_TYPE_3411OR3402);

    return NAS_LMM_MSG_HANDLED;

}

/*******************************************************************************
  Module   : REG+ATTEMPT_TO_UPDATE_MM״̬���յ�T3402ʱ
  Function : NAS_EMM_MsRegSsRegAttemptUpdateMmMsgT3402Exp
  Input    :
  Output   :
  NOTE     :
  Return   :
  History  :
    1.  lihong00150010  2011.11.17  �¹�����
*******************************************************************************/
VOS_UINT32 NAS_EMM_MsRegSsRegAttemptUpdateMmMsgT3402Exp
(
    VOS_UINT32                          ulMsgId,
    VOS_VOID                           *pMsgStru
)
{
    VOS_UINT32                                  ulRslt          = NAS_EMM_FAIL;

    (VOS_VOID)ulMsgId;

    /* ��ӡ����ú����� INFO_LEVEL */
    NAS_EMM_TAU_LOG_INFO( "NAS_EMM_MsRegSsRegAttemptUpdateMmMsgT3402Exp is entered.");
    TLPS_PRINT2LAYER_INFO(NAS_EMM_MsRegSsRegAttemptUpdateMmMsgT3402Exp_ENUM,LNAS_ENTRY);

    /* ��������ָ��������, ״̬ƥ����,����ƥ��,�˳�*/
    ulRslt = NAS_EMM_TAU_CHKFSMStateMsgp(EMM_MS_REG,EMM_SS_REG_ATTEMPTING_TO_UPDATE_MM,pMsgStru);
    if ( NAS_EMM_SUCC != ulRslt )
    {
        /* ��ӡ�쳣 */
        NAS_EMM_TAU_LOG_WARN( "NAS_EMM_MsRegSsRegAttemptUpdateMmMsgT3402Exp ERROR !!");
        TLPS_PRINT2LAYER_WARNING(NAS_EMM_MsRegSsRegAttemptUpdateMmMsgT3402Exp_ENUM,LNAS_ERROR);
        return NAS_LMM_MSG_DISCARD;
    }

    /*NAS_EMM_TAU_SaveEmmTAUStartCause(NAS_EMM_TAU_START_CAUSE_IMSI_ATTACH);*/
    NAS_EMM_TAU_SaveEmmTAUStartCause(NAS_EMM_TAU_START_CAUSE_OTHERS);

    /*������Ϣ��������*/
    /* �������TAU����ԭ�� */
    NAS_EMM_TAU_StartTAUREQ(NAS_LMM_OM_TAU_START_TYPE_3411OR3402);

    return NAS_LMM_MSG_HANDLED;

}
/*******************************************************************************
  Module   :
  Function : NAS_EMM_MsRegSsNormalMsgT3412Exp
  Input    :
  Output   :
  NOTE     :
  Return   :
  History  :
    1.  zhengjunyan 00148421  2008.12.29  �¹�����
*******************************************************************************/
VOS_UINT32 NAS_EMM_MsRegSsNormalMsgT3412Exp(VOS_UINT32  ulMsgId,
                                                   VOS_VOID   *pMsgStru )
{
    VOS_UINT32                          ulRslt  = NAS_EMM_FAIL;

    (VOS_VOID)ulMsgId;

    NAS_EMM_TAU_LOG_NORM("NAS_EMM_MsRegSsNormalMsgT3412Exp is entered.");
    TLPS_PRINT2LAYER_INFO(NAS_EMM_MsRegSsNormalMsgT3412Exp_ENUM,LNAS_ENTRY);

    /* ��������ָ��������, ״̬ƥ����,����ƥ��,�˳�*/
    ulRslt = NAS_EMM_TAU_CHKFSMStateMsgp(EMM_MS_REG,EMM_SS_REG_NORMAL_SERVICE,pMsgStru);
    if ( NAS_EMM_SUCC != ulRslt)
    {
        NAS_EMM_TAU_LOG_WARN("NAS_EMM_MsRegSsNormalMsgT3412Exp ERROR !!");
        TLPS_PRINT2LAYER_WARNING(NAS_EMM_MsRegSsNormalMsgT3412Exp_ENUM,LNAS_ERROR);
        return NAS_LMM_MSG_DISCARD;
    }

    /* ����������TAU
       ע:Reg.Normal_Service״̬���յ�T3412Exp˵��û��ҵ�����󣬲��ж���������*/
    NAS_EMM_TAU_SaveEmmTAUStartCause(NAS_EMM_TAU_START_CAUSE_T3412EXP);
    NAS_LMM_SetEmmInfoT3412ExpCtrl(NAS_EMM_T3412_EXP_YES_OTHER_STATE);

    /* �������TAU����ԭ�� */
    NAS_EMM_TAU_StartTAUREQ(NAS_LMM_OM_TAU_START_TYPE_3412_EXP);
    return NAS_LMM_MSG_HANDLED;
}

/*****************************************************************************
 Function Name   : NAS_EMM_MsRegSsRegAttemptUpdateMmMsgT3412Exp
 Description     : ״̬REG+REG_ATTEMPTING_TO_UPDATE_MM�յ�3412��ʱ��Ϣ
 Input           : ulMsgId-------------------------��ϢID
                   pMsgStru------------------------��Ϣָ��
 Output          : None
 Return          : VOS_UINT32

 History         :
    1.lihong 00150010     2011-11-17     Draft Enact

*****************************************************************************/
VOS_UINT32  NAS_EMM_MsRegSsRegAttemptUpdateMmMsgT3412Exp
(
    VOS_UINT32                              ulMsgId,
    VOS_VOID                               *pMsgStru
)
{
    VOS_UINT32                          ulRslt  = NAS_EMM_FAIL;

    (VOS_VOID)ulMsgId;

    NAS_EMM_TAU_LOG_NORM("NAS_EMM_MsRegSsRegAttemptUpdateMmMsgT3412Exp is entered.");
    TLPS_PRINT2LAYER_INFO(NAS_EMM_MsRegSsRegAttemptUpdateMmMsgT3412Exp_ENUM,LNAS_ENTRY);

    /* ��������ָ��������, ״̬ƥ����,����ƥ��,�˳�*/
    ulRslt = NAS_EMM_TAU_CHKFSMStateMsgp(EMM_MS_REG,EMM_SS_REG_ATTEMPTING_TO_UPDATE_MM,pMsgStru);
    if ( NAS_EMM_SUCC != ulRslt)
    {
        NAS_EMM_TAU_LOG_WARN("NAS_EMM_MsRegSsRegAttemptUpdateMmMsgT3412Exp ERROR !!");
        TLPS_PRINT2LAYER_WARNING(NAS_EMM_MsRegSsRegAttemptUpdateMmMsgT3412Exp_ENUM,LNAS_ERROR);
        return NAS_LMM_MSG_DISCARD;
    }

    /* 3412��ʱ��һ������±�3411��3402��������˴˳��������ĸ��ʺ�С��Ŀǰ��
       ������������������TAU������ֱ�ӷ�������TAU */
    /*NAS_EMM_TAU_SaveEmmTAUStartCause(     NAS_EMM_TAU_START_CAUSE_SYSINFO);*/
    NAS_EMM_TAU_SaveEmmTAUStartCause(NAS_EMM_TAU_START_CAUSE_OTHERS);
    NAS_LMM_SetEmmInfoT3412ExpCtrl(NAS_EMM_T3412_EXP_YES_OTHER_STATE);
    /* �������TAU����ԭ�� */
    NAS_EMM_TAU_StartTAUREQ(NAS_LMM_OM_TAU_START_TYPE_3412_EXP);

    return NAS_LMM_MSG_HANDLED;
}

/*****************************************************************************
 Function Name   : NAS_EMM_MsSuspendSsAnyMsgT3412Exp
 Description     : ���������3412��ʱ��ֻ��¼��ʱ��
                   ��ϵͳ�任���ˣ�����NO CELL���յ�ϵͳ��Ϣʱʹ�ô˱�ʶ��
                   ���任��GUȥ������˳�ʱ��ʶ
 Input           : None
 Output          : None
 Return          : VOS_UINT32

 History         :
    1.HanLufeng 41410      2011-5-11  Draft Enact

*****************************************************************************/
VOS_UINT32  NAS_EMM_MsSuspendSsAnyMsgT3412Exp(
                                            VOS_UINT32  ulMsgId,
                                            VOS_VOID   *pMsgStru  )
{
    (VOS_VOID)ulMsgId;
    (VOS_VOID)pMsgStru;

    NAS_EMM_TAU_LOG_NORM("NAS_EMM_MsSuspendSsAnyMsgT3412Exp: entered.");
    TLPS_PRINT2LAYER_INFO(NAS_EMM_MsSuspendSsAnyMsgT3412Exp_ENUM,LNAS_ENTRY);


    /*  �����������ø�ֵ*/
    NAS_LMM_SetEmmInfoT3412ExpCtrl(NAS_EMM_T3412_EXP_YES_OTHER_STATE);
    return NAS_LMM_MSG_HANDLED;
}


/*******************************************************************************
  Module   :
  Function : NAS_EMM_MsRegSsAtpUpdataMsgSysinfo
  Input    :
  Output   :
  NOTE     :
  Return   :
  History  :
    1.  Zhouyan 00125190  2008.09.10  �¹�����
    2.  zhengjunyan 00148421 2011-02-15 DTS2011021401149
    3.  liuhua      00212067 2012-05-29 ���յ�С��������Ϣ�󣬲���ҪֹͣT3411, T3402
    4.  sunjitan 00193151    2012-07-10 modify: Last attempt reg TA ά��
    5.  lihong 00150010      2012-12-19 Modify:Emergency
*******************************************************************************/
VOS_UINT32 NAS_EMM_MsRegSsAtpUpdataMsgSysinfo(VOS_UINT32  ulMsgId,
                                                   VOS_VOID   *pMsgStru )
{
    VOS_UINT32                          ulRslt            = NAS_EMM_FAIL;
    EMMC_EMM_SYS_INFO_IND_STRU         *pstsysinfo        = NAS_EMM_NULL_PTR;
    NAS_LMM_PTL_TI_ENUM_UINT16          enPtlTimerId    = NAS_LMM_PTL_TI_BUTT;
    MMC_LMM_TAU_RSLT_ENUM_UINT32        ulTauRslt;


    pstsysinfo                          = (EMMC_EMM_SYS_INFO_IND_STRU*)pMsgStru;

    (VOS_VOID)ulMsgId;

    /* ��ӡ����ú����� INFO_LEVEL */
    NAS_EMM_TAU_LOG_INFO("Nas_Emm_MsRegSsAtpUpdataMsgSysinfo is entered.");
    TLPS_PRINT2LAYER_INFO(NAS_EMM_MsRegSsAtpUpdataMsgSysinfo_ENUM,LNAS_ENTRY);

    ulRslt = NAS_EMM_TAU_CHKFSMStateMsgp(EMM_MS_REG,EMM_SS_REG_ATTEMPTING_TO_UPDATE,pMsgStru);

    /* ��������ָ��������, ״̬ƥ����,����ƥ��,�˳�*/
    if ( NAS_EMM_SUCC != ulRslt)
    {
        /* ��ӡ�쳣 */
        NAS_EMM_TAU_LOG_WARN("NAS_EMM_MsRegSsAtpUpdataMsgSysinfo ERROR !!");
        TLPS_PRINT2LAYER_WARNING(NAS_EMM_MsRegSsAtpUpdataMsgSysinfo_ENUM,LNAS_ERROR);
        return NAS_LMM_MSG_DISCARD;
    }
    /*���ݽ�ֹ��Ϣ�ж��Ƿ�����ǰ��ϵͳ��Ϣ*/
    if ((NAS_LMM_REG_STATUS_NORM_REGED == NAS_LMM_GetEmmInfoRegStatus())
        && ((EMMC_EMM_NO_FORBIDDEN != pstsysinfo->ulForbiddenInfo)
            || (EMMC_EMM_CELL_STATUS_ANYCELL == pstsysinfo->ulCellStatus)))
    {
        NAS_EMM_SetTauTypeNoProcedure();

        /*ת��EMM״̬��*/
        NAS_EMM_TAUSER_FSMTranState(    EMM_MS_REG,
                                        EMM_SS_REG_LIMITED_SERVICE,
                                        TI_NAS_EMM_STATE_NO_TIMER);

        /*��MMC����LMM_MMC_TAU_RESULT_IND��Ϣ*/
        NAS_EMM_MmcSendTauActionResultIndForbType((VOS_VOID*)&pstsysinfo->ulForbiddenInfo);


        return NAS_LMM_MSG_HANDLED;
    }
#if(FEATURE_ON == FEATURE_CSG)
    if(NAS_EMM_YES == NAS_EMM_MsRegSsAtpUpdataIsCsgIdNotInListTauStart())
    {
        return NAS_LMM_MSG_HANDLED;
    }
#endif

    /* �����ǰTA��TAI LIST */
    if (NAS_EMM_SUCC == NAS_EMM_TAU_IsCurrentTAInTaList())
    {
        /* ����ж�ʱ��(�������ã�����һ����) */
        if (NAS_EMM_YES == NAS_EMM_IsT3411orT3402Running(&enPtlTimerId))
        {
            /* ��ǰTA���ϴγ��Է���ע���TAU��TA��Ч���ȳ�ʱ */
            if (NAS_EMM_YES == NAS_LMM_IsLastAttemptRegTaInTaiList())
            {
                NAS_EMM_TAU_LOG_NORM("NAS_EMM_MsRegSsAtpUpdataMsgSysinfo: Equivalent TA, wait timer expired.");
                TLPS_PRINT2LAYER_INFO(NAS_EMM_MsRegSsAtpUpdataMsgSysinfo_ENUM,LNAS_FUNCTION_LABEL1);

                /* ��֮ǰ�й���RRC_REL���µ�TAU_REQ����ʧ�ܵ��������ô��ʱӦ����TAU */
                if(PS_TRUE == NAS_LMM_GetTauReqSndFailFlag())
                {
                     TLPS_PRINT2LAYER_ERROR(NAS_EMM_MsRegSsAtpUpdataMsgSysinfo_ENUM,LNAS_FUNCTION_LABEL2);

                     /* �������TAU����ԭ�� */
                     NAS_EMM_TAU_StartTAUREQ(NAS_LMM_OM_TAU_START_TYPE_SND_MSG_FAIL);

                     return NAS_LMM_MSG_HANDLED;
                }

                /* ������Ϣ����,MMA������������������Ϣ,��Ҫ�յ�TAU IND�Ż����,Ϊ��ܸ�����,
                   LMM����һ�������κβ���TAU IND��Ϣ�ϱ���MMC */
                /* ��UE�յ�MMC������ϵͳ��Ϣ֮����Ҫ����attach��tau���̣�����ԭ�����̴���������T3411��T3402��run����ô��MMC�ϱ�TAU����ļ���Ϣ */
                /* �ж�ʱ����3402������, ���ϱ�TAU��� */
                if ( TI_NAS_EMM_PTL_T3402 == enPtlTimerId )
                {
                    NAS_EMM_SetTauTypeNoProcedure();

                    ulTauRslt = MMC_LMM_TAU_RSLT_T3402_RUNNING;
                    NAS_EMM_MmcSendTauActionResultIndOthertype((VOS_VOID*)&ulTauRslt);

                }
                /* �ж�ʱ����3411������, ���ϱ�TAU��� */
                if ( TI_NAS_EMM_PTL_T3411 == enPtlTimerId )
                {
                    NAS_EMM_SetTauTypeNoProcedure();

                    ulTauRslt = MMC_LMM_TAU_RSLT_FAILURE;
                    NAS_EMM_MmcSendTauActionResultIndOthertype((VOS_VOID*)&ulTauRslt);
                }
                return NAS_LMM_MSG_HANDLED;
            }
        }

        /* �ǵ�ЧTA������û��ʱ��������������TAU */
        /* ����TAU���� */
        NAS_EMM_TAU_SaveEmmTAUAttemptCnt(NAS_EMM_TAU_ATTEMPT_CNT_ZERO);
        NAS_EMM_TAU_SaveEmmTAUStartCause(NAS_EMM_TAU_START_CAUSE_OTHERS);

        /*����TAU Procedure*/
        /* �������TAU����ԭ�� */
        NAS_EMM_TAU_StartTAUREQ(NAS_LMM_OM_TAU_START_TYPE_LAST_ATTEMPT_TA_NOT_IN_TAI_LIST);

    }
    else /* ��ǰTA����TAI LIST */
    {
        NAS_EMM_MsRegSsAtpUpdataTaIsNotListProc();

    }

    return NAS_LMM_MSG_HANDLED;

}

/*******************************************************************************
  Module   :
  Function : NAS_EMM_MsRegSsAtpUpdataMsgT3411Exp
  Input    :
  Output   :
  NOTE     :
  Return   :
  History  :
    1.  Zhouyan 00125190  2008.09.10  �¹�����
*******************************************************************************/
VOS_UINT32 NAS_EMM_MsRegSsAtpUpdataMsgT3411Exp(VOS_UINT32  ulMsgId,
                                                   VOS_VOID   *pMsgStru
                               )
{
    VOS_UINT32                                  ulRslt          = NAS_EMM_FAIL;


    (VOS_VOID)ulMsgId;

    /* ��ӡ����ú����� INFO_LEVEL */
    NAS_EMM_TAU_LOG_NORM("Nas_Emm_MsRegSsAtpUpdataMsgT3411Exp is entered.");
    TLPS_PRINT2LAYER_INFO(NAS_EMM_MsRegSsAtpUpdataMsgT3411Exp_ENUM,LNAS_ENTRY);

    /* ��������ָ��������, ״̬ƥ����,����ƥ��,�˳�*/
    ulRslt = NAS_EMM_TAU_CHKFSMStateMsgp(EMM_MS_REG,EMM_SS_REG_ATTEMPTING_TO_UPDATE,pMsgStru);
    if ( NAS_EMM_SUCC != ulRslt )
    {
        /* ��ӡ�쳣 */
        NAS_EMM_TAU_LOG_WARN( "NAS_EMM_TAUSER_CHKFSMStateMsgp ERROR !!");
        TLPS_PRINT2LAYER_WARNING(NAS_EMM_MsRegSsAtpUpdataMsgT3411Exp_ENUM,LNAS_ERROR);
        return NAS_LMM_MSG_DISCARD;
    }

    /*���·���TAU*/
    /* �������TAU����ԭ�� */
    NAS_EMM_TAU_StartTAUREQ(NAS_LMM_OM_TAU_START_TYPE_3411OR3402);

    return NAS_LMM_MSG_HANDLED;

}

/*******************************************************************************
  Module   :
  Function : NAS_EMM_MsRegSsAtpUpdataMsgT3402Exp
  Input    :
  Output   :
  NOTE     :
  Return   :
  History  :
    1.  Zhouyan 00125190  2008.09.10  �¹�����
*******************************************************************************/
VOS_UINT32 NAS_EMM_MsRegSsAtpUpdataMsgT3402Exp(VOS_UINT32  ulMsgId,
                                                   VOS_VOID   *pMsgStru
                               )
{
    VOS_UINT32                                  ulRslt          = NAS_EMM_FAIL;

    (VOS_VOID)ulMsgId;

    /* ��ӡ����ú����� INFO_LEVEL */
    NAS_EMM_TAU_LOG_INFO( "Nas_Emm_MsRegSsAtpUpdataMsgT3402Exp is entered.");
    TLPS_PRINT2LAYER_INFO(NAS_EMM_MsRegSsAtpUpdataMsgT3402Exp_ENUM,LNAS_ENTRY);

    /* ��������ָ��������, ״̬ƥ����,����ƥ��,�˳�*/
    ulRslt = NAS_EMM_TAU_CHKFSMStateMsgp(EMM_MS_REG,EMM_SS_REG_ATTEMPTING_TO_UPDATE,pMsgStru);
    if ( NAS_EMM_SUCC != ulRslt )
    {
        /* ��ӡ�쳣 */
        NAS_EMM_TAU_LOG_WARN( "NAS_EMM_TAUSER_CHKFSMStateMsgp ERROR !!");
        TLPS_PRINT2LAYER_WARNING(NAS_EMM_MsRegSsAtpUpdataMsgT3402Exp_ENUM,LNAS_ERROR);
        return NAS_LMM_MSG_DISCARD;
    }

    /*������Ϣ��������*/
    /* �������TAU����ԭ�� */
    NAS_EMM_TAU_StartTAUREQ(NAS_LMM_OM_TAU_START_TYPE_3411OR3402);

    return NAS_LMM_MSG_HANDLED;

}

/*******************************************************************************
  Module   :
  Function : NAS_EMM_MsRegSsAtpUpdataMsgT3346Exp
  Input    :
  Output   :
  NOTE     :
  Return   :
  History  :
    1.  wangchen 00209181   2015-02-10  �¹�����
*******************************************************************************/
VOS_UINT32 NAS_EMM_MsRegSsAtpUpdataMsgT3346Exp
(
    VOS_UINT32  ulMsgId,
    VOS_VOID   *pMsgStru
)
{
    VOS_UINT32                                  ulRslt          = NAS_EMM_FAIL;

    (VOS_VOID)ulMsgId;

    /* ��ӡ����ú����� INFO_LEVEL */
    NAS_EMM_TAU_LOG_INFO( "NAS_EMM_MsRegSsAtpUpdataMsgT3346Exp is entered.");
    TLPS_PRINT2LAYER_INFO(NAS_EMM_MsRegSsAtpUpdataMsgT3346Exp_ENUM,LNAS_ENTRY);

    /* ��������ָ��������, ״̬ƥ����,����ƥ��,�˳�*/
    ulRslt = NAS_EMM_TAU_CHKFSMStateMsgp(EMM_MS_REG,EMM_SS_REG_ATTEMPTING_TO_UPDATE,pMsgStru);
    if ( NAS_EMM_SUCC != ulRslt )
    {
        /* ��ӡ�쳣 */
        NAS_EMM_TAU_LOG_WARN( "NAS_EMM_TAUSER_CHKFSMStateMsgp ERROR !!");
        TLPS_PRINT2LAYER_WARNING(NAS_EMM_MsRegSsAtpUpdataMsgT3346Exp_ENUM,LNAS_ERROR);
        return NAS_LMM_MSG_DISCARD;
    }

    /*������Ϣ��������*/
    /* �������TAU����ԭ�� */
    NAS_EMM_TAU_StartTAUREQ(NAS_LMM_OM_TAU_START_TYPE_3346);

    return NAS_LMM_MSG_HANDLED;

}

/*******************************************************************************
  Module   :
  Function : NAS_EMM_MsRegSsSomeStateMsgEsmDataReq
  Input    : ulMsgId--------------------��ϢID
             pMsgStru-------------------��Ϣָ��
  Output   : None
  NOTE     : REG+ATTEMPT_TO_UPDATE��REG+WAIT_ACCESS_GRANT_IND״̬���յ�ESM��Ϣ
  Return   : VOS_UINT32
  History  :
    1.  lihong 00150010  2012.12.13  �¹�����
*******************************************************************************/
VOS_UINT32 NAS_EMM_MsRegSsSomeStateMsgEsmDataReq
(
    VOS_UINT32                          ulMsgId,
    VOS_VOID                           *pMsgStru
)
{
    VOS_UINT32                          ulRslt1          = NAS_EMM_FAIL;
    VOS_UINT32                          ulRslt2          = NAS_EMM_FAIL;

    EMM_ESM_DATA_REQ_STRU              *pstEsmDataReq   = (EMM_ESM_DATA_REQ_STRU*)pMsgStru;

    (VOS_VOID)ulMsgId;

    /* ��ӡ����ú����� INFO_LEVEL */
    NAS_EMM_TAU_LOG_INFO( "NAS_EMM_MsRegSsSomeStateMsgEsmDataReq is entered.");
    TLPS_PRINT2LAYER_INFO(NAS_EMM_MsRegSsSomeStateMsgEsmDataReq_ENUM,LNAS_ENTRY);

/* �˴���ദ���ò���ֻ��һ�����״̬ */
    /* ��������ָ��������, ״̬ƥ����,����ƥ��,�˳�*/
    ulRslt1 = NAS_EMM_TAU_CHKFSMStateMsgp(EMM_MS_REG,EMM_SS_REG_ATTEMPTING_TO_UPDATE,pMsgStru);
    ulRslt2 = NAS_EMM_TAU_CHKFSMStateMsgp(EMM_MS_REG,EMM_SS_REG_WAIT_ACCESS_GRANT_IND,pMsgStru);

    if (( NAS_EMM_SUCC != ulRslt1 ) && ( NAS_EMM_SUCC != ulRslt2 ))
    {
        /* ��ӡ�쳣 */
        NAS_EMM_TAU_LOG_WARN( "NAS_EMM_MsRegSsAtpUpdataMsgEsmDataReq ERROR !");
        TLPS_PRINT2LAYER_WARNING(NAS_EMM_MsRegSsSomeStateMsgEsmDataReq_ENUM,LNAS_ERROR);
        return NAS_LMM_MSG_DISCARD;
    }

    /* ������ǽ������ͣ����� */
    if (VOS_TRUE != pstEsmDataReq->ulIsEmcType)
    {
        NAS_EMM_TAU_LOG_NORM( "NAS_EMM_MsRegSsSomeStateMsgEsmDataReq:NOT EMC!");
        TLPS_PRINT2LAYER_INFO(NAS_EMM_MsRegSsSomeStateMsgEsmDataReq_ENUM,LNAS_FUNCTION_LABEL1);
        return  NAS_LMM_MSG_DISCARD;
    }

    NAS_LMM_SetEmmInfoIsEmerPndEsting(VOS_TRUE);

    /* ���LRRC REL��С��פ���ϱ�ϵͳ��Ϣǰ�յ�ESM�������ؽ����������ڿտڷ���ʧ�ܣ�����detach,�������ATTACH����
       ����:�ȸ����ȼ����棬�ȵ��յ�LRRCϵͳ��Ϣ����*/
    if((NAS_EMM_CONN_WAIT_SYS_INFO == NAS_EMM_GetConnState())
        ||(NAS_EMM_CONN_RELEASING == NAS_EMM_GetConnState()))
    {
        return NAS_LMM_STORE_HIGH_PRIO_MSG;
    }

    /* ����������͵�ESM��Ϣ */
    NAS_EMM_SaveEmcEsmMsg(pMsgStru);

    NAS_EMM_TAU_SaveEmmTAUStartCause(NAS_EMM_TAU_START_CAUSE_ESM_EMC_PDN_REQ);

    /*������Ϣ��������*/
    /* �������TAU����ԭ�� */
    NAS_EMM_TAU_StartTAUREQ(NAS_LMM_OM_TAU_START_TYPE_EMC_PDN_EST_REQ);

    return NAS_LMM_MSG_HANDLED;
}

/*******************************************************************************
  Module   :
  Function : NAS_EMM_MsRegSsLimitSRMsgSysinfo
  Input    :
  Output   :
  NOTE     :
  Return   :
  History  :
    1.Zhouyan     00125190  2008.09.10  �¹�����
    2.zhengjunyan 00148421  2009.08.13  BJ9D01691:�����ж�TAI List
    3.X00148705             2009.11.17  ����TAU������ԭ��ֵ����ͬ���͵�TAU
    4.z00148421             2009.09.15  �Ż�:ͨ���ж�TA�Ƿ���TAI List��,
                                        UeNeCapOrDrxChange��־��T3412��ʱ��־��
                                        ���ٶ��ഥ��TAU������֤TAU������ȷ��
    5.z00148421             2010-12-23   DTS2010111701490:�޸�DrxNetCapChange�Ĵ���
                                        ����TauStartCause����TAU
    6.z00148421             2011-01-11   DTS2010122201496
    7.l00150010             2012-12-19   Modify:Emergency
*******************************************************************************/
VOS_UINT32 NAS_EMM_MsRegSsLimitSRMsgSysinfo(VOS_UINT32  ulMsgId,
                                                   VOS_VOID   *pMsgStru )
{
    VOS_UINT32                          ulRslt          = NAS_EMM_FAIL;
    EMMC_EMM_SYS_INFO_IND_STRU         *pstsysinfo      = VOS_NULL_PTR;

    (VOS_VOID)ulMsgId;
    NAS_EMM_TAU_LOG_INFO("NAS_EMM_MsRegSsLimitSRMsgSysinfo entered.");
    TLPS_PRINT2LAYER_INFO(NAS_EMM_MsRegSsLimitSRMsgSysinfo_ENUM,LNAS_ENTRY);

    /* ��������ָ��������, ״̬ƥ����,����ƥ��,�˳�*/
    ulRslt = NAS_EMM_TAU_CHKFSMStateMsgp(EMM_MS_REG,EMM_SS_REG_LIMITED_SERVICE,pMsgStru);
    if (NAS_EMM_SUCC != ulRslt )
    {
        NAS_EMM_TAU_LOG_WARN("NAS_EMM_MsRegSsLimitSRMsgSysinfo:INPUT ERROR.");
        TLPS_PRINT2LAYER_WARNING(NAS_EMM_MsRegSsLimitSRMsgSysinfo_ENUM,LNAS_ERROR);
        return NAS_LMM_MSG_DISCARD;
    }

    /* ��ȡϵͳ��Ϣ*/
    pstsysinfo                          = (EMMC_EMM_SYS_INFO_IND_STRU*)pMsgStru;
    /* ���ϵͳ��Ϣ������״̬���䣬��������*/
    if ((NAS_LMM_REG_STATUS_NORM_REGED == NAS_LMM_GetEmmInfoRegStatus())
        && ((EMMC_EMM_NO_FORBIDDEN != pstsysinfo->ulForbiddenInfo)
            || (EMMC_EMM_CELL_STATUS_ANYCELL == pstsysinfo->ulCellStatus)))
    {
        NAS_EMM_TAU_LOG_WARN("NAS_EMM_MsRegSsLimitSRMsgSysinfo:Cell Forb.");
        TLPS_PRINT2LAYER_WARNING(NAS_EMM_MsRegSsLimitSRMsgSysinfo_ENUM,LNAS_EMM_FORBIDDEN);

        NAS_EMM_SetTauTypeNoProcedure();

        /*��MMC����LMM_MMC_TAU_RESULT_IND��Ϣ*/
        NAS_EMM_MmcSendTauActionResultIndForbType((VOS_VOID*)&pstsysinfo->ulForbiddenInfo);

        return NAS_LMM_MSG_HANDLED;
    }

    /* �����յ�SYS_INFO�Ĺ�������*/
    NAS_EMM_RegSomeStateMsgSysInfoCommProc();

    return NAS_LMM_MSG_HANDLED;
}

/*******************************************************************************
  Module   :
  Function : NAS_EMM_MsRegSsPLMNSearchMsgSysinfo
  Input    :
  Output   :
  NOTE     :
  Return   :
  History  :
    1.  Zhouyan 00125190  2008.09.10  �¹�����
    2.  leili   00132387  2009.06.16  ���ⵥBJ9D00875�޸�
    3.  X00148705         2009-11-13  �޸�TAU���ͺ�DRXNetCap�ı�ʱ����TAU
    4.  z00148421         2010-07-30  ��TauStartCause����EU��Ϊ�ж�����
    5.  z00148421         2010-09-15  1)������LVR TAI�Ƶ�������TAU��λ��
                                      2)����TAUStartCause��DrxNetCapChange����
                                        �������ж�˳��
    6.  z00148421         2010-12-23   DTS2010111701490:�޸�DrxNetCapChange�Ĵ���
                                       ����TauStartCause����TAU
    7.  z00148421         2011-02-14   DTS2011021401149
    8.  sunjitan 00193151 2012-02-02 Modify for UE radio capability
    9.  l00150010         2012-12-19   Modify:Emergency
*******************************************************************************/
VOS_UINT32 NAS_EMM_MsRegSsPLMNSearchMsgSysinfo(VOS_UINT32  ulMsgId,
                                                   VOS_VOID   *pMsgStru )
{
    VOS_UINT32                          ulRslt          = NAS_EMM_FAIL;
    EMMC_EMM_SYS_INFO_IND_STRU         *pstsysinfo      = NAS_EMM_NULL_PTR;

    (VOS_VOID)ulMsgId;
    NAS_EMM_TAU_LOG_INFO(               "Nas_Emm_MsRegSsPLMNSearchMsgSysinfo is entered.");
    TLPS_PRINT2LAYER_INFO(NAS_EMM_MsRegSsPLMNSearchMsgSysinfo_ENUM,LNAS_ENTRY);

    /* ��������ָ��������, ״̬ƥ����,����ƥ��,�˳�*/
    ulRslt = NAS_EMM_TAU_CHKFSMStateMsgp(EMM_MS_REG,EMM_SS_REG_PLMN_SEARCH,pMsgStru);
    if ( NAS_EMM_SUCC                   != ulRslt )
    {
        NAS_EMM_TAU_LOG_WARN(           "Nas_Emm_MsRegSsPLMNSearchMsgSysinfo ERROR.");
        TLPS_PRINT2LAYER_WARNING(NAS_EMM_MsRegSsPLMNSearchMsgSysinfo_ENUM,LNAS_ERROR);
        return NAS_LMM_MSG_DISCARD;
    }

    /*��ȡϵͳ��Ϣ��������Ϣ*/
    pstsysinfo                          = (EMMC_EMM_SYS_INFO_IND_STRU*)pMsgStru;
    /*����յ���ϵͳ��Ϣ������״̬Ǩ�Ƶ�Reg.Limite_Service����������*/
    if ((NAS_LMM_REG_STATUS_NORM_REGED == NAS_LMM_GetEmmInfoRegStatus())
        && ((EMMC_EMM_NO_FORBIDDEN != pstsysinfo->ulForbiddenInfo)
            || (EMMC_EMM_CELL_STATUS_ANYCELL == pstsysinfo->ulCellStatus)))
    {
        NAS_EMM_TAU_LOG_INFO("NAS_EMM_MsRegSsPLMNSearchMsgSysinfo:SysInfo Forb.");
        TLPS_PRINT2LAYER_INFO(NAS_EMM_MsRegSsPLMNSearchMsgSysinfo_ENUM,LNAS_EMM_FORBIDDEN);

        NAS_EMM_SetTauTypeNoProcedure();

        NAS_EMM_TAUSER_FSMTranState(    EMM_MS_REG,
                                        EMM_SS_REG_LIMITED_SERVICE,
                                        TI_NAS_EMM_STATE_NO_TIMER);

        /*��MMC����LMM_MMC_TAU_RESULT_IND��Ϣ*/
        NAS_EMM_MmcSendTauActionResultIndForbType((VOS_VOID*)&pstsysinfo->ulForbiddenInfo);


        return NAS_LMM_MSG_HANDLED;
    }

    NAS_EMM_RegSomeStateMsgSysInfoCommProc();

    return NAS_LMM_MSG_HANDLED;
}

/*******************************************************************************
  Module   :
  Function : NAS_EMM_MsRegSsNocellMsgSysinfo
  Input    :
  Output   :
  NOTE     :
  Return   :
  History  :
    1.  Zhouyan 00125190  2008.09.10  �¹�����
    2.  luojian 00107747  2009.01.13  Э����µ�8.0.0
    3.  yangfan 00159566  2009.09.01  �޸�
    4.  X00148705         2009.11.13  �޸�TAU����Ϣ����
    5.  z00148421         2010-12-23  DTS2010111701490:�޸�DrxNetCapChange�Ĵ���
                                      ����TauStartCause����TAU
    6.  z00148421         2011-12-22  �����쳣������֧:����̬�²�����SYS_INFO
    7.  l00150010         2012-12-19   Modify:Emergency
*******************************************************************************/
VOS_UINT32 NAS_EMM_MsRegSsNocellMsgSysinfo(VOS_UINT32  ulMsgId,
                                                   VOS_VOID   *pMsgStru )
{

    VOS_UINT32  ulRslt                            = NAS_EMM_FAIL;
    EMMC_EMM_SYS_INFO_IND_STRU   *pstsysinfo       = NAS_EMM_NULL_PTR;

    (VOS_VOID)ulMsgId;
    NAS_EMM_TAU_LOG_INFO(                         "Nas_Emm_MsRegSsNocellMsgSysinfo is entered.");
    TLPS_PRINT2LAYER_INFO(NAS_EMM_MsRegSsNocellMsgSysinfo_ENUM,LNAS_ENTRY);

    /*check the input params*/
    ulRslt = NAS_EMM_TAU_CHKFSMStateMsgp(         EMM_MS_REG,EMM_SS_REG_NO_CELL_AVAILABLE,pMsgStru);
    if( NAS_EMM_SUCC                              != ulRslt )
    {
        NAS_EMM_TAU_LOG_WARN(                     "NAS_EMM_TAUSER_CHKFSMStateMsgp ERROR !!");
        TLPS_PRINT2LAYER_WARNING(NAS_EMM_MsRegSsNocellMsgSysinfo_ENUM,LNAS_ERROR);
        return NAS_LMM_MSG_DISCARD;
    }

    /* �����ǰ���ڹ���̬���򲻴���SYS_INFO,ֱ�Ӷ���*/
    if(NAS_LMM_CUR_LTE_SUSPEND == NAS_EMM_GetCurLteState())
    {
        NAS_EMM_TAU_LOG_ERR("Nas_Emm_MsRegSsNocellMsgSysinfo:LTE SUSPEND.");
        TLPS_PRINT2LAYER_ERROR(NAS_EMM_MsRegSsNocellMsgSysinfo_ENUM,LNAS_FUNCTION_LABEL1);
        return NAS_LMM_MSG_HANDLED;
    }

    /* ��ȡϵͳ��Ϣ��������Ϣ*/
    pstsysinfo                                    = (EMMC_EMM_SYS_INFO_IND_STRU*)pMsgStru;

    /*���ݽ�ֹ��Ϣ�ж��Ƿ�����ǰ��ϵͳ��Ϣ*/
    if ((NAS_LMM_REG_STATUS_NORM_REGED == NAS_LMM_GetEmmInfoRegStatus())
        && ((EMMC_EMM_NO_FORBIDDEN != pstsysinfo->ulForbiddenInfo)
            || (EMMC_EMM_CELL_STATUS_ANYCELL == pstsysinfo->ulCellStatus)))
    {
        NAS_EMM_TAU_LOG_WARN("NAS_EMM_MsRegSsNocellMsgSysinfo:Cell Forb.");
        TLPS_PRINT2LAYER_WARNING(NAS_EMM_MsRegSsNocellMsgSysinfo_ENUM,LNAS_EMM_FORBIDDEN);

        NAS_EMM_SetTauTypeNoProcedure();

        /*ת��EMM״̬��*/
        NAS_EMM_TAUSER_FSMTranState(    EMM_MS_REG,
                                        EMM_SS_REG_LIMITED_SERVICE,
                                        TI_NAS_EMM_STATE_NO_TIMER);

        /*��MMC����LMM_MMC_TAU_RESULT_IND��Ϣ*/
        NAS_EMM_MmcSendTauActionResultIndForbType((VOS_VOID*)&pstsysinfo->ulForbiddenInfo);

        return NAS_LMM_MSG_HANDLED;
    }
    /*inform ESM that return to E-UTRAN*/
    NAS_EMM_TAU_SendEsmStatusInd(       EMM_ESM_ATTACH_STATUS_AREA_RE_ENTRY);

    /* �����յ�SYS_INFO�Ĺ�������*/
    NAS_EMM_RegSomeStateMsgSysInfoCommProc();

    return NAS_LMM_MSG_HANDLED;
}


/*******************************************************************************
  Module   :
  Function : NAS_EMM_MsRegSsNormalCsfbDelayProc
  Input    : VOS_VOID
  Output   : VOS_VOID
  NOTE     :
  Return   : VOS_VOID
  History  :
    1.  sunjitan 00193151    2014-05-15  �¹�����
    2.  leixiantiao 00258641 2015-07-02  �������
    3.  leixiantiao 00258641   2015-07-09  fix DTS2015062509266
*******************************************************************************/
VOS_VOID NAS_EMM_MsRegSsNormalCsfbDelayProc(EMMC_EMM_CHANGE_INFO_ENUM_UINT32    ulChangeInfo)
{

    /* ��ӡ����ú����� INFO_LEVEL */
    NAS_EMM_TAU_LOG_INFO("NAS_EMM_MsRegSsNormalCsfbDelayProc is entered.");
    TLPS_PRINT2LAYER_INFO(NAS_EMM_MsRegSsNormalCsfbDelayProc_ENUM,LNAS_ENTRY);
    /* �������,�����ж�С����Ϣ�Ƿ����ı� */
    NAS_EMM_RegNormalServiceOrUpdateMMMsgSysInfoCommProc(ulChangeInfo);

    /* ����NORMAL̬�������� */
    /* �����ǰCSFB��ʱ��ʱ�������У�˵��֮ǰ���ͷŹ������յ���CSFB��
       ���������ֱ�ӷ���EXTEND SERVICE */
    if((EMM_MS_REG == NAS_LMM_GetEmmCurFsmMS())
        &&(EMM_SS_REG_NORMAL_SERVICE ==NAS_LMM_GetEmmCurFsmSS()))
    {
        /* ����UE����CSFB */
        NAS_EMM_SER_SaveEmmSerCsfbRsp(NAS_EMM_CSFB_RSP_ACCEPTED_BY_UE);

        /*������ʱ��3417*/
        NAS_LMM_StartStateTimer(TI_NAS_EMM_STATE_SERVICE_T3417_EXT);

        /*ת��EMM״̬��MS_SER_INIT+SS_SER_WAIT_CN_CNF*/
        NAS_EMM_TAUSER_FSMTranState(EMM_MS_SER_INIT, EMM_SS_SER_WAIT_CN_SER_CNF, TI_NAS_EMM_STATE_SERVICE_T3417_EXT);

        /* ESR�տڷ���ǰ,֪ͨLRRC CSFB����INIT,LRRC��һ��ȫ�ֱ���,��ESR����ʱ�����ؽ�,ֱ�ӻ�LMM REL,����ȥGU */
        NAS_EMM_SndLrrcLmmCsfbNotify(LRRC_LNAS_CSFB_STATUS_INIT);

        /*��ϲ�����MRRC_DATA_REQ(SERVICE_REQ)*/
        NAS_EMM_SER_SendMrrcDataReq_ExtendedServiceReq();

        /* ���֮ǰ��¼��SERVICE��ͻ */
        NAS_EMM_TAU_SaveEmmCollisionCtrl(NAS_EMM_COLLISION_NONE);
    }
    /* ���״̬������REG NORMAL��˵��������TAU���������̣�������������ٽ����ͻ */

    return;

}



VOS_VOID  NAS_EMM_ProcTauBar( VOS_VOID )
{
    /* ���BarType�����ȫ���������Ǩ�Ƶ�REG.NORMAL_SERVICE*/
    if(0 == (NAS_EMM_TAU_GetRegBarType()&NAS_LMM_LOW_HALF_BYTE_F))
    {
        /*���BarProcedure*/
        NAS_EMM_TAU_SetRegBarProcedure(NAS_EMM_BAR_PROCEDURE_NULL);
        NAS_EMM_TranStatePsNormalServiceOrPsLimitService();

        /*ת��EMM״̬��Reg Normal̬*/
        /*NAS_EMM_TAUSER_FSMTranState(EMM_MS_REG, EMM_SS_REG_NORMAL_SERVICE, TI_NAS_EMM_STATE_NO_TIMER);*/
    }

    /*���MO Signalû�б�bar������TAU*/
    if( NAS_EMM_SUCC != NAS_EMM_JudgeBarType(NAS_EMM_BAR_TYPE_MO_SIGNAL))
    {
        /* �ж��Ƿ��������Pending*/
        NAS_EMM_TAU_IsUplinkPending();

        NAS_EMM_RegSomeStateMsgSysInfoCommProc();
    }
}


/*****************************************************************************
 Function Name   : NAS_EMM_SrvBarIsTauStarted
 Description     : Service���̱�Bar,�յ�Grant_Ind��Ϣ���ж������Ҫ�򴥷�Я��
                   'ACTIVE'��TAU
                   ������TAU,���� NAS_EMM_YES
                   û�д���TAU,�򷵻� NAS_EMM_NO
 Input           : None
 Output          : None
 Return          : VOS_UINT32

 History         :
    1.zhengjunyan 00148421      2010-12-14  Draft Enact
    2.zhengjunyan 00148421      2011-1-12   DTS2010122201496
    3.zhengjunyan 00148421      2011-2-15   DTS2011021501149
*****************************************************************************/
VOS_UINT32  NAS_EMM_SrvBarIsTauStarted( VOS_VOID)
{
    /*���Mo_Signal�������룬�ж��Ƿ���Ҫ����TAU*/
    if(NAS_EMM_SUCC != NAS_EMM_JudgeBarType(NAS_EMM_BAR_TYPE_MO_SIGNAL))
    {
        /* �ж��Ƿ��������Pending*/
        NAS_EMM_TAU_IsUplinkPending();

        if (NAS_EMM_SER_START_CAUSE_MO_CSFB_REQ == NAS_EMM_SER_GetEmmSERStartCause())
        {
            NAS_EMM_TAU_SaveEmmCollisionCtrl(NAS_EMM_COLLISION_SERVICE);
        }

        /*�ж��Ƿ���Ҫ����TAU���߱���Detach*/
        NAS_EMM_RegSomeStateMsgSysInfoCommProc();

        if (EMM_MS_REG == NAS_LMM_GetEmmCurFsmMS())
        {
            NAS_EMM_TAU_SaveEmmCollisionCtrl(NAS_EMM_COLLISION_NONE);
            return NAS_EMM_NO;
        }
        else
        {
            /* �����Ҫ����TAU�������������������ı���Detach������Attach,�򷵻�NAS_EMM_YES */
            return NAS_EMM_YES;
        }
    }
    return NAS_EMM_NO;

}

/*****************************************************************************
 Function Name   : NAS_EMM_ProcSrvBar
 Description     :
 Input           : None
 Output          : None
 Return          : VOS_UINT32

 History         :
    1.    leili  00132387      2010-8-24  Draft Enact
    2.    sunbing 49683        2010-11-16 Service���̽�bar���ж��Ƿ���TAU������Ҫִ��
    3.    zhengjunyan 00148421 2010-11-23 MOD:���´���TAUʱЯ��'ACTIVE'��־����Ҫ
                                              ����TauStartCause
    4.    lihong00150010       2012-12-18 Modify:Emergency
    5.    leixiantiao 00258641 2015-07-09 fix DTS2015062509266
*****************************************************************************/
VOS_VOID  NAS_EMM_ProcSrvBar( VOS_VOID )
{
    VOS_UINT32                          ulRslt;
    /* ���BarType�����ȫ���������Ǩ�Ƶ�REG.NORMAL_SERVICE*/
    if(0 == (NAS_EMM_TAU_GetRegBarType()&NAS_LMM_LOW_HALF_BYTE_F))
    {
        /*���BarProcedure*/
        NAS_EMM_TAU_SetRegBarProcedure(NAS_EMM_BAR_PROCEDURE_NULL);
        NAS_EMM_TranStatePsNormalServiceOrPsLimitService();

        /*ת��EMM״̬��Reg Normal̬*/
        /*NAS_EMM_TAUSER_FSMTranState(EMM_MS_REG, EMM_SS_REG_NORMAL_SERVICE, TI_NAS_EMM_STATE_NO_TIMER);*/
    }

    /*�ж������Ҫ�򴥷�Я��'active'��TAU���̣��������أ��������*/
    ulRslt = NAS_EMM_SrvBarIsTauStarted();
    if(NAS_EMM_YES == ulRslt)
    {
        return;
    }
    /*���MT call��bar������ServiceĿ����ӦѰ��������Service����*/
    if( (NAS_EMM_SUCC != NAS_EMM_JudgeBarType(NAS_EMM_BAR_TYPE_MT))
       && (NAS_EMM_SER_START_CAUSE_RRC_PAGING == NAS_EMM_SER_GetEmmSERStartCause())
       && (VOS_TRUE != NAS_EMM_IsEnterRegLimitService()))
    {
        /*����Service����*/
        NAS_EMM_SER_RcvRrcStmsiPagingInd();
        return;
    }

    /*���MT call����bar������EXTENDED ServiceĿ����ӦѰ��������EXTENDED Service����*/
    if( (NAS_EMM_SUCC != NAS_EMM_JudgeBarType(NAS_EMM_BAR_TYPE_MT))
       &&(NAS_EMM_SER_START_CAUSE_MT_CSFB_REQ == NAS_EMM_SER_GetEmmSERStartCause()))
    {
        /* ����UE����CSFB */
        NAS_EMM_SER_SaveEmmSerCsfbRsp(NAS_EMM_CSFB_RSP_ACCEPTED_BY_UE);

        /*������ʱ��3417*/
        NAS_LMM_StartStateTimer(TI_NAS_EMM_STATE_SERVICE_T3417_EXT);

        /*ת��EMM״̬��MS_SER_INIT+SS_SER_WAIT_CN_CNF*/
        NAS_EMM_TAUSER_FSMTranState(EMM_MS_SER_INIT, EMM_SS_SER_WAIT_CN_SER_CNF, TI_NAS_EMM_STATE_SERVICE_T3417_EXT);

        /* ESR�տڷ���ǰ,֪ͨLRRC CSFB����INIT,LRRC��һ��ȫ�ֱ���,��ESR����ʱ�����ؽ�,ֱ�ӻ�LMM REL,����ȥGU */

        NAS_EMM_SndLrrcLmmCsfbNotify(LRRC_LNAS_CSFB_STATUS_INIT);

        /*��ϲ�����MRRC_DATA_REQ(SERVICE_REQ)*/
        NAS_EMM_SER_SendMrrcDataReq_ExtendedServiceReq();
        return;
    }

     /*���MO csfb����bar������CSFBû��abort������Service����*/
    if ( (NAS_EMM_SUCC != NAS_EMM_JudgeBarType(NAS_EMM_BAR_TYPE_MO_CSFB))
       &&(NAS_EMM_SER_START_CAUSE_MO_CSFB_REQ == NAS_EMM_SER_GetEmmSERStartCause())
       && (NAS_EMM_CSFB_ABORT_FLAG_VALID != NAS_EMM_SER_GetEmmSerCsfbAbortFlag()))
    {
        /*������ʱ��3417*/
        NAS_LMM_StartStateTimer(TI_NAS_EMM_STATE_SERVICE_T3417_EXT);

        /*ת��EMM״̬��MS_SER_INIT+SS_SER_WAIT_CN_CNF*/
        NAS_EMM_TAUSER_FSMTranState(EMM_MS_SER_INIT, EMM_SS_SER_WAIT_CN_SER_CNF, TI_NAS_EMM_STATE_SERVICE_T3417_EXT);

        /* ESR�տڷ���ǰ,֪ͨLRRC CSFB����INIT,LRRC��һ��ȫ�ֱ���,��ESR����ʱ�����ؽ�,ֱ�ӻ�LMM REL,����ȥGU */

        NAS_EMM_SndLrrcLmmCsfbNotify(LRRC_LNAS_CSFB_STATUS_INIT);

        /*��ϲ�����MRRC_DATA_REQ(SERVICE_REQ)*/
        NAS_EMM_SER_SendMrrcDataReq_ExtendedServiceReq();
    }
    return;
}



VOS_UINT32 NAS_EMM_MsRegSsWaitAccessGrantIndMsgRrcGrantInd(VOS_UINT32  ulMsgId,
                                                   VOS_VOID   *pMsgStru)
 {
    VOS_UINT32                              ulRslt;

    LRRC_LMM_ACCESS_GRANT_IND_STRU            *pRrcMmGrantInd = NAS_EMM_NULL_PTR;

    (VOS_VOID)ulMsgId;

    NAS_EMM_TAU_LOG_INFO("NAS_EMM_MsRegSsWaitAccessGrantIndMsgRrcGrantInd is entered.");
    TLPS_PRINT2LAYER_INFO(NAS_EMM_MsRegSsWaitAccessGrantIndMsgRrcGrantInd_ENUM,LNAS_ENTRY);

    /*check the input params and states*/
    ulRslt = NAS_EMM_TAU_CHKFSMStateMsgp(EMM_MS_REG,EMM_SS_REG_WAIT_ACCESS_GRANT_IND,pMsgStru);
    if ( NAS_EMM_SUCC != ulRslt )
    {
        NAS_EMM_TAU_LOG_WARN( "NAS_EMM_TAUSER_CHKFSMStateMsgp ERROR !!");
        TLPS_PRINT2LAYER_WARNING(NAS_EMM_MsRegSsWaitAccessGrantIndMsgRrcGrantInd_ENUM,LNAS_ERROR);
        return NAS_LMM_MSG_DISCARD;
    }

    /*get the msg info*/
    pRrcMmGrantInd = (LRRC_LMM_ACCESS_GRANT_IND_STRU *) pMsgStru;

    NAS_EMM_TAU_LOG1_INFO("NAS_EMM_MsRegSsWaitAccessGrantIndMsgRrcGrantInd: Granttype =.",pRrcMmGrantInd->enAccessGrantType);
    TLPS_PRINT2LAYER_INFO1(NAS_EMM_MsRegSsWaitAccessGrantIndMsgRrcGrantInd_ENUM,LNAS_FUNCTION_LABEL1,
                                        pRrcMmGrantInd->enAccessGrantType);

    /* ���bar����*/
    NAS_EMM_ClearBarType(pRrcMmGrantInd->enAccessGrantType);

    /* ����REG̬�½�Bar�Ĺ�������*/
    NAS_EMM_RegBarCommProc();

    return NAS_LMM_MSG_HANDLED;
 }

/*****************************************************************************
 Function Name   : NAS_EMM_RegBarCommProc
 Description     : REG̬��bar�Ĺ�������
 Input           : None
 Output          : None
 Return          : VOS_UINT32

 History         :
    1.zhengjunyan 00148421      2011-12-1  Draft Enact

*****************************************************************************/
VOS_VOID  NAS_EMM_RegBarCommProc( VOS_VOID )
{
    /* ����BarProcedure���벻ͬ�Ĵ���*/
    if (NAS_EMM_BAR_PROCEDURE_TAU == NAS_EMM_GetBarProcedure())
    {
        NAS_EMM_TAU_LOG_NORM("NAS_EMM_RegBarCommProc:TAU BAR");
        TLPS_PRINT2LAYER_INFO(NAS_EMM_RegBarCommProc_ENUM,LNAS_FUNCTION_LABEL1);
        NAS_EMM_ProcTauBar();
    }
    else if (NAS_EMM_BAR_PROCEDURE_SERVICE == NAS_EMM_GetBarProcedure())
    {
        NAS_EMM_TAU_LOG_NORM("NAS_EMM_RegBarCommProc:SERVICE BAR");
        TLPS_PRINT2LAYER_INFO(NAS_EMM_RegBarCommProc_ENUM,LNAS_FUNCTION_LABEL2);
        NAS_EMM_ProcSrvBar();
    }
    else
    {
        ;
    }

    return;
}


/*****************************************************************************
 Function Name   : NAS_EMM_MsRegSsWaitAccessGrantIndMsgSysinfoInd
 Description     : Reg.WtAccessGrantInd״̬���յ�SYS_INFO_IND������ֹ��Ϣ
 Input           : None
 Output          : None
 Return          : VOS_UINT32

 History         :
    1.zhengjunyan 00148421      2010-12-14  Draft Enact
    2.lihong 00150010           2012-12-19  Modify:Emergency

*****************************************************************************/
VOS_UINT32  NAS_EMM_MsRegSsWaitAccessGrantIndMsgSysinfoInd( VOS_UINT32  ulMsgId,
                                                   VOS_VOID   *pMsgStru )
{
    VOS_UINT32                          ulRslt;
    EMMC_EMM_SYS_INFO_IND_STRU          *pstsysinfo = NAS_EMM_NULL_PTR;

    NAS_EMM_TAU_LOG_INFO("NAS_EMM_MsRegSsWaitAccessGrantIndMsgSysinfoInd entered.");
    TLPS_PRINT2LAYER_INFO(NAS_EMM_MsRegSsWaitAccessGrantIndMsgSysinfoInd_ENUM,LNAS_ENTRY);
    (VOS_VOID)ulMsgId;

    /* ��μ��*/
    ulRslt = NAS_EMM_TAU_CHKFSMStateMsgp(EMM_MS_REG,EMM_SS_REG_WAIT_ACCESS_GRANT_IND,pMsgStru);
    if ( NAS_EMM_SUCC != ulRslt )
    {
        NAS_EMM_TAU_LOG_WARN( "NAS_EMM_TAUSER_CHKFSMStateMsgp ERROR !!");
        TLPS_PRINT2LAYER_WARNING(NAS_EMM_MsRegSsWaitAccessGrantIndMsgSysinfoInd_ENUM,LNAS_ERROR);
        return NAS_LMM_MSG_DISCARD;
    }

    /* ���ϵͳ��Ϣ�����������Bar��Ϣ��Ǩ�Ƶ� Reg.Limite_Service*/
    pstsysinfo                          = (EMMC_EMM_SYS_INFO_IND_STRU*)pMsgStru;
    if ((NAS_LMM_REG_STATUS_NORM_REGED == NAS_LMM_GetEmmInfoRegStatus())
        && ((EMMC_EMM_NO_FORBIDDEN != pstsysinfo->ulForbiddenInfo)
            || (EMMC_EMM_CELL_STATUS_ANYCELL == pstsysinfo->ulCellStatus)))
    {
        NAS_EMM_SetTauTypeNoProcedure();

        /* ���Bar��Ϣ*/
        NAS_EMM_ClearBarResouce();

        /* ״̬Ǩ��: Reg.Limite_Service*/
        NAS_EMM_TAUSER_FSMTranState(    EMM_MS_REG,
                                        EMM_SS_REG_LIMITED_SERVICE,
                                        TI_NAS_EMM_STATE_NO_TIMER);

        /*��MMC����LMM_MMC_TAU_RESULT_IND��Ϣ*/
        NAS_EMM_MmcSendTauActionResultIndForbType((VOS_VOID*)&pstsysinfo->ulForbiddenInfo);
    }

    return NAS_LMM_MSG_HANDLED;
}


VOS_UINT32  NAS_EMM_MsRegSsWaitAccessGrantIndMsgIntraTauReq( VOS_UINT32  ulMsgId,
                                                   VOS_VOID   *pMsgStru )
{
    VOS_UINT32                               ulRslt;
    NAS_LMM_INTRA_TAU_REQ_STRU         *pIntraTauReq = NAS_EMM_NULL_PTR;

    (VOS_VOID)ulMsgId;
    pIntraTauReq    = (NAS_LMM_INTRA_TAU_REQ_STRU*)pMsgStru;

    NAS_EMM_TAU_LOG_NORM("NAS_EMM_MsRegSsWaitAccessGrantIndMsgIntraTauReq is entered.");
    TLPS_PRINT2LAYER_INFO(NAS_EMM_MsRegSsWaitAccessGrantIndMsgIntraTauReq_ENUM,LNAS_ENTRY);

    /*check the input params and states*/
    ulRslt = NAS_EMM_TAU_CHKFSMStateMsgp(EMM_MS_REG,EMM_SS_REG_WAIT_ACCESS_GRANT_IND,pMsgStru);
    if ( NAS_EMM_SUCC != ulRslt )
    {
        NAS_EMM_TAU_LOG_WARN( "NAS_EMM_TAUSER_CHKFSMStateMsgp ERROR !!");
        TLPS_PRINT2LAYER_WARNING(NAS_EMM_MsRegSsWaitAccessGrantIndMsgIntraTauReq_ENUM,LNAS_ERROR);
        return NAS_LMM_MSG_DISCARD;
    }
    if(NAS_LMM_INTRA_TAU_TYPE_PARA_CHANGE == pIntraTauReq->enIntraTauType)
    {
        /*����DRX��NetCapability�ı��־*/
        NAS_LMM_SetEmmInfoDrxNetCapChange( NAS_EMM_YES);
    }

    else if(NAS_LMM_INTRA_TAU_TYPE_IMSI_ATTACH == pIntraTauReq->enIntraTauType)
    {
        if (NAS_EMM_SUCC == NAS_EMM_JudgeBarType(NAS_EMM_BAR_TYPE_MO_SIGNAL))
        {
            NAS_EMM_TAU_LOG_WARN( "NAS_EMM_MsRegSsWaitAccessGrantIndMsgIntraTauReq TAU_IMSI_ATTACH MO SIGNAL!!");
            TLPS_PRINT2LAYER_WARNING(NAS_EMM_MsRegSsWaitAccessGrantIndMsgIntraTauReq_ENUM,LNAS_FUNCTION_LABEL1);
            NAS_EMM_AppSendAttRstInTau(MMC_LMM_ATT_RSLT_FAILURE);
            return NAS_LMM_MSG_HANDLED;
        }
    }
    else
    {

    }

    if (NAS_EMM_SUCC != NAS_EMM_JudgeBarType(NAS_EMM_BAR_TYPE_MO_SIGNAL))
    {
        NAS_EMM_TAU_LOG_NORM("NAS_EMM_MsRegSsWaitAccessGrantIndMsgIntraTauReq:TAU is start");
        TLPS_PRINT2LAYER_INFO(NAS_EMM_MsRegSsWaitAccessGrantIndMsgIntraTauReq_ENUM,LNAS_FUNCTION_LABEL2);

        /* �ж��Ƿ��������Pending*/
        NAS_EMM_TAU_IsUplinkPending();

        /* �������TAU����ԭ�� */
        NAS_EMM_TAU_StartTAUREQ(NAS_LMM_OM_TAU_START_TYPE_OTHERS);
    }

    return NAS_LMM_MSG_HANDLED;
}


VOS_UINT32  NAS_EMM_MsRegSsWaitAccessGrantIndMsgBearerStatusReq(
                                                    VOS_UINT32  ulMsgId,
                                                    VOS_VOID   *pMsgStru )
{
    VOS_UINT32                               ulRslt;

    (VOS_VOID)ulMsgId;
    NAS_EMM_TAU_LOG_NORM("NAS_EMM_MsRegSsWaitAccessGrantIndMsgBearerStatusReq entered.");
    TLPS_PRINT2LAYER_INFO(NAS_EMM_MsRegSsWaitAccessGrantIndMsgBearerStatusReq_ENUM,LNAS_ENTRY);

    /* ��鵱ǰ״̬�����*/
    ulRslt = NAS_EMM_TAU_CHKFSMStateMsgp(EMM_MS_REG,EMM_SS_REG_WAIT_ACCESS_GRANT_IND,pMsgStru);
    if ( NAS_EMM_SUCC != ulRslt )
    {
        NAS_EMM_TAU_LOG_WARN( "NAS_EMM_TAUSER_CHKFSMStateMsgp ERROR !!");
        TLPS_PRINT2LAYER_WARNING(NAS_EMM_MsRegSsWaitAccessGrantIndMsgBearerStatusReq_ENUM,LNAS_ERROR);
        return NAS_LMM_MSG_DISCARD;
    }

    /* ���ó��������ı仯*/
    NAS_EMM_SetEpsContextStatusChange(NAS_EMM_EPS_BEARER_STATUS_CHANGEED);

    /* �ж����MO_Signal�������룬����������TAU��Я��'ACTIVE'*/
    if (NAS_EMM_SUCC != NAS_EMM_JudgeBarType(NAS_EMM_BAR_TYPE_MO_SIGNAL))
    {
        NAS_EMM_TAU_LOG_NORM("NAS_EMM_MsRegSsWaitAccessGrantIndMsgBearerStatusReq:Init TAU");
        TLPS_PRINT2LAYER_INFO(NAS_EMM_MsRegSsWaitAccessGrantIndMsgBearerStatusReq_ENUM,LNAS_FUNCTION_LABEL1);

        /* �ж��Ƿ��������Pending*/
        NAS_EMM_TAU_IsUplinkPending();

        /* �������δ��ɵ�LOAD_BALANCE TAU���򴥷�LOAD_BALANCE����TAU
           ���򣬴������������ĸı䴥����TAU*/

        /*NAS_EMM_TAU_SaveEmmTAUStartCause(     NAS_EMM_TAU_START_CAUSE_SYSINFO);*/
        NAS_EMM_TAU_SaveEmmTAUStartCause(NAS_EMM_TAU_START_CAUSE_OTHERS);
        /* �������TAU����ԭ�� */
        NAS_EMM_TAU_StartTAUREQ(NAS_LMM_OM_TAU_START_TYPE_BEARER_STATUS_CHANGEED);
    }

    return NAS_LMM_MSG_HANDLED;
}


VOS_UINT32  NAS_EMM_MsRegSsWaitAccessGrantIndMsgT3412Exp(  VOS_UINT32  ulMsgId,
                                                   VOS_VOID   *pMsgStru)
{
    VOS_UINT32                               ulRslt;

    (VOS_VOID)ulMsgId;

    NAS_EMM_TAU_LOG_NORM("NAS_EMM_MsRegSsWaitAccessGrantIndMsgT3412Exp is entered.");
    TLPS_PRINT2LAYER_INFO(NAS_EMM_MsRegSsWaitAccessGrantIndMsgT3412Exp_ENUM,LNAS_ENTRY);

     /*check the input params and states*/
    ulRslt = NAS_EMM_TAU_CHKFSMStateMsgp(EMM_MS_REG,EMM_SS_REG_WAIT_ACCESS_GRANT_IND,pMsgStru);
    if ( NAS_EMM_SUCC != ulRslt )
    {
        NAS_EMM_TAU_LOG_WARN( "NAS_EMM_TAUSER_CHKFSMStateMsgp ERROR !!");
        TLPS_PRINT2LAYER_WARNING(NAS_EMM_MsRegSsWaitAccessGrantIndMsgT3412Exp_ENUM,LNAS_ERROR);
        return NAS_LMM_MSG_DISCARD;
    }


    /*��������TAU��������ʱ��־*/
    NAS_LMM_SetEmmInfoT3412ExpCtrl(NAS_EMM_T3412_EXP_YES_OTHER_STATE);

    if (MMC_LMM_TIN_RAT_RELATED_TMSI == NAS_EMM_GetTinType())
    {
        /*������ʱ��T3423*/
        NAS_LMM_StartPtlTimer(TI_NAS_EMM_PTL_T3423);

        /*֪ͨGUģT3423����*/
        NAS_EMM_SendTimerStateNotify(TI_NAS_EMM_PTL_T3423, LMM_MMC_TIMER_START);

    }

    if (NAS_EMM_SUCC != NAS_EMM_JudgeBarType(NAS_EMM_BAR_TYPE_MO_SIGNAL))
    {
        NAS_EMM_TAU_LOG_NORM("NAS_EMM_MsRegSsWaitAccessGrantIndMsgT3412Exp:TAU is start");
        TLPS_PRINT2LAYER_INFO(NAS_EMM_MsRegSsWaitAccessGrantIndMsgT3412Exp_ENUM,LNAS_FUNCTION_LABEL1);

        /* �ж��Ƿ��������Pending*/
        NAS_EMM_TAU_IsUplinkPending();

        /*����������TAU*/
        NAS_EMM_TAU_SaveEmmTAUStartCause(NAS_EMM_TAU_START_CAUSE_T3412EXP);
        NAS_LMM_SetEmmInfoT3412ExpCtrl(NAS_EMM_T3412_EXP_YES_OTHER_STATE);
        /* �������TAU����ԭ�� */
        NAS_EMM_TAU_StartTAUREQ(NAS_LMM_OM_TAU_START_TYPE_3412_EXP);
    }

    return NAS_LMM_MSG_HANDLED;
}

/*****************************************************************************
 Function Name   : NAS_EMM_MsRegSsWaitAccessGrantIndMsgT3411Exp
 Description     : Reg.WtAccessGrantInd״̬���յ�t3411��ʱ���ж������Ҫ����
                   �´���TAU:���ܵĳ���
                   1)����״̬�仯����TAU���ײ��������Reg.Normal_Service״̬������T3411
                   2)������������Service�����뱻Bar������Reg.WtAccGrantInd
                   3)��Reg.WtAccGrantInd״̬���յ�T3411��ʱ
 Input           : None
 Output          : None
 Return          : VOS_UINT32

 History         :
    1.zhengjunyan 00148421    2010-11-23  Draft Enact

*****************************************************************************/
VOS_UINT32  NAS_EMM_MsRegSsWaitAccessGrantIndMsgT3411Exp( VOS_UINT32  ulMsgId,
                                                   VOS_VOID   *pMsgStru )
{
    MMC_LMM_TAU_RSLT_ENUM_UINT32        ulTauRslt = MMC_LMM_TAU_RSLT_BUTT;
    VOS_UINT32                               ulRslt;

   (VOS_VOID)ulMsgId;
   NAS_EMM_TAU_LOG_NORM("NAS_EMM_MsRegSsWaitAccessGrantIndMsgT3411Exp entered.");
   TLPS_PRINT2LAYER_INFO(NAS_EMM_MsRegSsWaitAccessGrantIndMsgT3411Exp_ENUM,LNAS_ENTRY);


    /*״̬����μ��*/
    ulRslt = NAS_EMM_TAU_CHKFSMStateMsgp(EMM_MS_REG,EMM_SS_REG_WAIT_ACCESS_GRANT_IND,pMsgStru);
    if ( NAS_EMM_SUCC != ulRslt )
    {
        NAS_EMM_TAU_LOG_WARN( "NAS_EMM_TAUSER_CHKFSMStateMsgp ERROR !!");
        TLPS_PRINT2LAYER_WARNING(NAS_EMM_MsRegSsWaitAccessGrantIndMsgT3411Exp_ENUM,LNAS_ERROR);
        return NAS_LMM_MSG_DISCARD;
    }

    /*���MO_SIGNAL�������룬�����Ƿ���δ��ɵ�TAU*/
    if (NAS_EMM_SUCC != NAS_EMM_JudgeBarType(NAS_EMM_BAR_TYPE_MO_SIGNAL))
    {
        /*�����δ��ɵ�TAU�����´�������Я��'ACTIVE'��־*/
        if(NAS_EMM_YES == NAS_EMM_SER_AbnormalNeedtoContinueTau())
        {
            NAS_EMM_TAU_SaveEmmCollisionCtrl(    NAS_EMM_COLLISION_SERVICE);
            /* �������TAU����ԭ�� */
            NAS_EMM_TAU_StartTAUREQ(NAS_LMM_OM_TAU_START_TYPE_3411OR3402);
        }
    }
    else
    {
        if (NAS_EMM_YES == NAS_EMM_TAU_CanTriggerComTauWithIMSI())
        {
            NAS_EMM_TAU_SaveTAUtype(NAS_EMM_CN_TAU_TYPE_COMBINED_TA_LA_WITH_IMSI);

            ulTauRslt = MMC_LMM_TAU_RSLT_ACCESS_BARED;
            NAS_EMM_MmcSendTauActionResultIndOthertype((VOS_VOID*)&ulTauRslt);
        }

    }
    return NAS_LMM_MSG_HANDLED;
}

/*******************************************************************************
  Module   :
  Function : NAS_EMM_MsDeRegInitSsWaitCNDetachCnfMsgSysinfo
  Input    :
  Output   :
  NOTE     :
  Return   :
  History  :
    1.Zhouyan 00125190  2008.09.10  �¹�����
    2.zhengjunyan 00148421 2010-10-25 Mod:���Ӷ�Forb��Ϣ���жϴ���
    3.zhengjunyan 00148421 2010-11-16 ����:TA��TAI LIST�и��� LVR TAI
    4.lihong 00150010      2012-12-17 Modify:Emergency
    5.lifuxin 00253982     2014-11-06 �����ع�
*******************************************************************************/
VOS_UINT32 NAS_EMM_MsDeRegInitSsWaitCNDetachCnfMsgSysinfo(VOS_UINT32  ulMsgId,
                                                   VOS_VOID   *pMsgStru )
{
    VOS_UINT32                          ulRslt      = NAS_EMM_FAIL;
    VOS_UINT32                          ulTaRslt    = NAS_EMM_FAIL;
    EMMC_EMM_SYS_INFO_IND_STRU          *pstsysinfo  = NAS_EMM_NULL_PTR;
    NAS_LMM_NETWORK_INFO_STRU           *pMmNetInfo  = NAS_EMM_NULL_PTR;
    EMMC_EMM_FORBIDDEN_INFO_ENUM_UINT32  ulForbiddenInfo = EMMC_EMM_NO_FORBIDDEN;
    (VOS_VOID)ulMsgId;
    NAS_EMM_TAU_LOG_NORM("Nas_Emm_MsDeRegInitSsWaitCNDetachCnfMsgSysinfo entered.");
    TLPS_PRINT2LAYER_INFO(NAS_EMM_MsDeRegInitSsWaitCNDetachCnfMsgSysinfo_ENUM,LNAS_ENTRY);

    /* ��������ָ��������, ״̬ƥ����,����ƥ��,�˳�*/
    ulRslt = NAS_EMM_TAU_CHKFSMStateMsgp(EMM_MS_DEREG_INIT,EMM_SS_DETACH_WAIT_CN_DETACH_CNF,pMsgStru);
    if ( NAS_EMM_SUCC != ulRslt)
    {
        NAS_EMM_TAU_LOG_WARN( "NAS_EMM_MsDeRegInitSsWaitCNDetachCnfMsgSysinfo ERROR !!");
        TLPS_PRINT2LAYER_WARNING(NAS_EMM_MsDeRegInitSsWaitCNDetachCnfMsgSysinfo_ENUM,LNAS_ERROR);
        return NAS_LMM_MSG_DISCARD;
    }

    pstsysinfo = (EMMC_EMM_SYS_INFO_IND_STRU *)pMsgStru;

    /*�����������յ�ϵͳ��Ϣ���ȴ������ظ���ֱ�Ӵ�������*/
    if(NAS_EMM_CONN_ESTING == NAS_EMM_GetConnState())
    {
        return  NAS_LMM_STORE_HIGH_PRIO_MSG;
    }

    /* �ж�TA�Ƿ���TA List��*/
    ulTaRslt = NAS_EMM_TAU_IsCurrentTAInTaList();
    if (VOS_TRUE == NAS_EMM_GLO_AD_GetUsimPullOutFlag())
    {
         if (NAS_EMM_FAIL == ulTaRslt)
         {
             /*ֹͣ��ʱ��T3421*/
             NAS_LMM_StopStateTimer(          TI_NAS_EMM_T3421);

            #if (FEATURE_ON == FEATURE_DSDS)
            /*����end notify��Ϣ��RRC��֪ͨRRC�ͷ���Դ*/
            NAS_LMM_SendRrcDsdsEndNotify(LRRC_LNAS_SESSION_TYPE_PS_DETACH);
            #endif

             /*��ESM����ID_EMM_ESM_STATUS_IND��Ϣ*/
             NAS_EMM_TAU_SendEsmStatusInd(EMM_ESM_ATTACH_STATUS_DETACHED);

             NAS_EMM_ProcLocalNoUsim();

             /* ֪ͨAPP_DETACH_IND(APP_MM_DETACH_ENTITY_ME)*/
             NAS_EMM_MmcSendDetIndLocal(MMC_LMM_L_LOCAL_DETACH_OTHERS);

            #if (FEATURE_PTM == FEATURE_ON)
            NAS_EMM_LocalDetachErrRecord(EMM_ERR_LOG_LOCAL_DETACH_TYPE_OTHER);
            #endif
             NAS_EMM_ClearAppMsgPara();

             NAS_EMM_RelReq(                 NAS_LMM_NOT_BARRED);
         }
         return NAS_LMM_MSG_HANDLED;
    }
    /* ����ϵͳ���л�������С��,���Ա���:������LС��A��B(������TA)
        UE��С��B��פ��������MMEĳЩ�쳣,��UE�·�ԭ��ֵ#15����MMEδ��
        TA���뱻���б���(δ�汻����ֻ����ʱ����)����UE�յ�#15ԭ��ֵ,
        ����������פ����AС����֮��������UE�л���BС�������л�ʱLRRC
        �����ж�С���Ƿ񱻽���LMM�յ�ϵͳ��Ϣ����BС�����յ���#15ԭ
        ��ֵ,LMM�����ͷŽ������Ʒ���̬��LRRC�ͷź���С��A��פ�����Ӷ�����ƹ���л� */
    ulForbiddenInfo = pstsysinfo->ulForbiddenInfo;
    if(NAS_EMM_YES == NAS_EMM_IsIntraHoIgnoreForbSysInfo())
    {
        /* ����FORBIDDEN TA FOR ROAMING,���ڱ�#15ԭ��ֵ�ܺ�,פ����TA������FORBIDDEN TA LIST��,����TAILIST��ɾ�������Ժ�������TAU */
        if(EMMC_EMM_FORBIDDEN_TA_FOR_ROAMING == pstsysinfo->ulForbiddenInfo)
        {
            NAS_EMM_PUBU_LOG1_INFO("NAS_EMM_MsRegSsNormalMsgSysinfo Ignore ForbTaForRoaming:forbiddenInfo = ",
                               pstsysinfo->ulForbiddenInfo);
            TLPS_PRINT2LAYER_INFO1(NAS_EMM_MsDeRegInitSsWaitCNDetachCnfMsgSysinfo_ENUM,LNAS_EMM_FORB_INFO,
                               pstsysinfo->ulForbiddenInfo);
            ulForbiddenInfo = EMMC_EMM_NO_FORBIDDEN;
            #if (FEATURE_ON == FEATURE_PTM)
            NAS_EMM_ImprovePerformceeErrReport(EMM_OM_ERRLOG_IMPROVEMENT_TYPE_HO_TO_FORBIDDEN_TA);
            #endif
        }
    }
    /* ��ȡϵͳ��Ϣ + ��ǰ������Ϣ*/
    pstsysinfo                          = (EMMC_EMM_SYS_INFO_IND_STRU*)pMsgStru;
    pMmNetInfo                          = NAS_LMM_GetEmmInfoNetInfoAddr();
    /* ���ϵͳ��Ϣ���������ͷ�����,�������DETACH,����Dereg.Limite_Service*/
    if ((NAS_LMM_REG_STATUS_NORM_REGED == NAS_LMM_GetEmmInfoRegStatus())
        && ((EMMC_EMM_NO_FORBIDDEN != ulForbiddenInfo)
            || (EMMC_EMM_CELL_STATUS_ANYCELL == pstsysinfo->ulCellStatus)))
    {
        NAS_EMM_TAU_LOG_WARN("NAS_EMM_MsDeRegInitSsWaitCNDetachCnfMsgSysinfo: Cell Forb.");
        TLPS_PRINT2LAYER_WARNING(NAS_EMM_MsDeRegInitSsWaitCNDetachCnfMsgSysinfo_ENUM,LNAS_EMM_FORBIDDEN);

        /* ��ֹDETACH����,�ͷ�����,ע��:��RRC����REL_REQ��Ϣ��״̬ת����˳���ܵߵ�*/
        NAS_EMM_DetProcEnterForbTA();

        return  NAS_LMM_MSG_HANDLED;
    }

#if(FEATURE_ON == FEATURE_CSG)
    if(NAS_EMM_YES == NAS_EMM_MsDeRegInitSsWaitCNDetachCnfIsCsgIdNotInListTauStart())
    {
        return NAS_LMM_MSG_HANDLED;
    }
#endif

    if (NAS_EMM_FAIL == ulTaRslt)
    {
         NAS_EMM_TAU_LOG_INFO("NAS_EMM_MsDeRegInitSsWaitCNDetachCnfMsgSysinfo:TA not in TAI List.");
         TLPS_PRINT2LAYER_INFO(NAS_EMM_MsDeRegInitSsWaitCNDetachCnfMsgSysinfo_ENUM,LNAS_EMM_TA_NOT_IN_TA_LIST);

         /* �������̳�ͻ��־λDETACH*/
         NAS_EMM_TAU_SaveEmmCollisionCtrl(NAS_EMM_COLLISION_DETACH);

         /*NAS_EMM_TAU_SaveEmmTAUStartCause(     NAS_EMM_TAU_START_CAUSE_SYSINFO);*/
         NAS_EMM_TAU_SaveEmmTAUStartCause(NAS_EMM_TAU_START_CAUSE_OTHERS);

         /* �����DETACH����ΪEPS/IMSI������������DETACH��TAU��ϱ�ʶ������
            �����TAU����Ϊ����TAU */
         if (MMC_LMM_MO_DET_CS_PS == NAS_EMM_GetDetachType())
         {
            /* ��������DETACH��TAU��ϱ�ʶ���������������TAU������ȻΪ����TAU */
            NAS_EMM_TAU_SetEmmCombinedDetachBlockFlag(NAS_EMM_COM_DET_BLO_YES);
         }

         /* ����DETACH�ĺ���������DETACH����*/
         NAS_EMM_DetachToTAU();

         /* ����TAU Procedure
            ע:MO_DETACH�����д���TAU����ΪDETACH_COLLISION��־����ȻЯ��ACTVIE,
           ���ж���������*/
         /* �������TAU����ԭ�� */
         NAS_EMM_TAU_StartTAUREQ(NAS_LMM_OM_TAU_START_TYPE_NOT_IN_TAI_LIST);
    }
    /* TA��TAI List�У����� L.V.R TAI*/
    else
    {
        NAS_EMM_SetLVRTai(&pMmNetInfo->stPresentNetId);
        if (NAS_LMM_REG_STATUS_EMC_REGED != NAS_LMM_GetEmmInfoRegStatus())
        {
            /*����PS LOC��Ϣ*/
            NAS_LMM_WritePsLoc(NAS_NV_ITEM_UPDATE);
        }

        /* ������Ϣ���,MMA������������������Ϣ,��Ҫ�յ�TAU IND�Ż����,Ϊ��ܸ�����,
            LMM����һ�������κβ���TAU IND��Ϣ�ϱ���MMC */
        NAS_EMM_SetTauTypeNoProcedure();

        /*��MMC����LMM_MMC_TAU_RESULT_IND��Ϣ*/
        NAS_EMM_MmcSendTauActionResultIndSuccWithoutPara();
    }

    return NAS_LMM_MSG_HANDLED;
}

/*******************************************************************************
  Module   : ��REG+IMSI_DETACH_INIT״̬�´���ϵͳ��Ϣ
  Function : NAS_EMM_MsRegImsiDetachWtCnDetCnfMsgSysinfo
  Input    : ulMsgId----------------------��ϢID
             pMsgStru---------------------ϵͳ��Ϣָ��
  Output   : NONE
  NOTE     :
  Return   : VOS_UINT32
  History  :
    1.lihong 00150010  2011.09.17  �¹�����
    2.lihong 00150010  2012.12.18  Modify:Emergency
*******************************************************************************/
VOS_UINT32 NAS_EMM_MsRegImsiDetachWtCnDetCnfMsgSysinfo
(
    VOS_UINT32                          ulMsgId,
    VOS_VOID                           *pMsgStru
)
{
    VOS_UINT32                          ulRslt      = NAS_EMM_FAIL;
    VOS_UINT32                          ulTaRslt    = NAS_EMM_FAIL;
    EMMC_EMM_SYS_INFO_IND_STRU          *pstsysinfo  = NAS_EMM_NULL_PTR;
    NAS_LMM_NETWORK_INFO_STRU           *pMmNetInfo  = NAS_EMM_NULL_PTR;
    EMMC_EMM_FORBIDDEN_INFO_ENUM_UINT32  ulForbiddenInfo = EMMC_EMM_NO_FORBIDDEN;

    (VOS_VOID)ulMsgId;
    NAS_EMM_TAU_LOG_NORM("NAS_EMM_MsRegImsiDetachWtCnDetCnfMsgSysinfo entered.");
    TLPS_PRINT2LAYER_INFO(NAS_EMM_MsRegImsiDetachWtCnDetCnfMsgSysinfo_ENUM,LNAS_ENTRY);

    /* ��������ָ��������, ״̬ƥ����,����ƥ��,�˳�*/
    ulRslt = NAS_EMM_TAU_CHKFSMStateMsgp(EMM_MS_REG,EMM_SS_REG_IMSI_DETACH_WATI_CN_DETACH_CNF,pMsgStru);
    if ( NAS_EMM_SUCC != ulRslt)
    {
        NAS_EMM_TAU_LOG_WARN( "NAS_EMM_MsRegImsiDetachWtCnDetCnfMsgSysinfo ERROR !!");
        TLPS_PRINT2LAYER_WARNING(NAS_EMM_MsRegImsiDetachWtCnDetCnfMsgSysinfo_ENUM,LNAS_ERROR);
        return NAS_LMM_MSG_DISCARD;
    }

    pstsysinfo = (EMMC_EMM_SYS_INFO_IND_STRU *)pMsgStru;

    /* �ж�TA�Ƿ���TA List��*/
    ulTaRslt = NAS_EMM_TAU_IsCurrentTAInTaList();
    /* ����ϵͳ���л�������С��,���Ա���:������LС��A��B(������TA)
        UE��С��B��פ��������MMEĳЩ�쳣,��UE�·�ԭ��ֵ#15����MMEδ��
        TA���뱻���б���(δ�汻����ֻ����ʱ����)����UE�յ�#15ԭ��ֵ,
        ����������פ����AС����֮��������UE�л���BС�������л�ʱLRRC
        �����ж�С���Ƿ񱻽���LMM�յ�ϵͳ��Ϣ����BС�����յ���#15ԭ
        ��ֵ,LMM�����ͷŽ������Ʒ���̬��LRRC�ͷź���С��A��פ�����Ӷ�����ƹ���л� */
    ulForbiddenInfo = pstsysinfo->ulForbiddenInfo;
    if(NAS_EMM_YES == NAS_EMM_IsIntraHoIgnoreForbSysInfo())
    {
        /* ����FORBIDDEN TA FOR ROAMING,���ڱ�#15ԭ��ֵ�ܺ�,פ����TA������FORBIDDEN TA LIST��,����TAILIST��ɾ�������Ժ�������TAU */
        if(EMMC_EMM_FORBIDDEN_TA_FOR_ROAMING == pstsysinfo->ulForbiddenInfo)
        {
            NAS_EMM_PUBU_LOG1_INFO("NAS_EMM_MsRegSsNormalMsgSysinfo Ignore ForbTaForRoaming:forbiddenInfo = ",
                               pstsysinfo->ulForbiddenInfo);
            TLPS_PRINT2LAYER_INFO1(NAS_EMM_MsRegImsiDetachWtCnDetCnfMsgSysinfo_ENUM,LNAS_EMM_FORB_INFO,
                               pstsysinfo->ulForbiddenInfo);
            ulForbiddenInfo = EMMC_EMM_NO_FORBIDDEN;
            #if (FEATURE_ON == FEATURE_PTM)
            NAS_EMM_ImprovePerformceeErrReport(EMM_OM_ERRLOG_IMPROVEMENT_TYPE_HO_TO_FORBIDDEN_TA);
            #endif
        }
    }

    /* ��ȡϵͳ��Ϣ + ��ǰ������Ϣ*/
    pstsysinfo                          = (EMMC_EMM_SYS_INFO_IND_STRU*)pMsgStru;
    pMmNetInfo                          = NAS_LMM_GetEmmInfoNetInfoAddr();
    /* ���ϵͳ��Ϣ���������ͷ�����,�������DETACH,����Dereg.Limite_Service*/
    if ((NAS_LMM_REG_STATUS_NORM_REGED == NAS_LMM_GetEmmInfoRegStatus())
        && ((EMMC_EMM_NO_FORBIDDEN != ulForbiddenInfo)
            || (EMMC_EMM_CELL_STATUS_ANYCELL == pstsysinfo->ulCellStatus)))
    {
        NAS_EMM_TAU_LOG_WARN("NAS_EMM_MsRegImsiDetachWtCnDetCnfMsgSysinfo: Cell Forb.");
        TLPS_PRINT2LAYER_WARNING(NAS_EMM_MsRegImsiDetachWtCnDetCnfMsgSysinfo_ENUM,LNAS_EMM_FORBIDDEN);

        /* ��ֹDETACH���̣������Ƿ���ڽ��������أ������Ƿ��ͷ���· */
        NAS_EMM_ImsiDetProcEnterForbTA();

        return  NAS_LMM_MSG_HANDLED;
    }
#if(FEATURE_ON == FEATURE_CSG)
    if((NAS_EMM_YES == NAS_LMM_IsCsgCampOn())
        &&(NAS_EMM_FAIL == NAS_EMM_TAU_IsCsgIdInAllowedOrOperatorCsgList()))
    {
         NAS_EMM_TAU_LOG_INFO("NAS_EMM_MsRegImsiDetachWtCnDetCnfMsgSysinfo:CSG ID not in CSG List.");
         TLPS_PRINT2LAYER_INFO(NAS_EMM_MsRegImsiDetachWtCnDetCnfMsgSysinfo_ENUM,LNAS_FUNCTION_LABEL1);


       /* �������̳�ͻ��־λDETACH*/
        NAS_EMM_TAU_SaveEmmCollisionCtrl(NAS_EMM_COLLISION_DETACH);

        /*NAS_EMM_TAU_SaveEmmTAUStartCause(     NAS_EMM_TAU_START_CAUSE_SYSINFO);*/
        NAS_EMM_TAU_SaveEmmTAUStartCause(NAS_EMM_TAU_START_CAUSE_OTHERS);

        /* ��������DETACH��TAU��ϱ�ʶ���������������TAU������ȻΪ����TAU */
        NAS_EMM_TAU_SetEmmCombinedDetachBlockFlag(NAS_EMM_COM_DET_BLO_YES);

        /* ����DETACH�ĺ���������DETACH����*/
        NAS_EMM_DetachToTAU();

        /* �������TAU����ԭ�� */
        NAS_EMM_TAU_StartTAUREQ(NAS_LMM_OM_TAU_START_TYPE_NOT_IN_CSG_LIST);

        return NAS_LMM_MSG_HANDLED;
    }
#endif
    if (NAS_EMM_FAIL == ulTaRslt)
    {
         NAS_EMM_TAU_LOG_INFO("NAS_EMM_MsRegImsiDetachWtCnDetCnfMsgSysinfo:TA not in TAI List.");
         TLPS_PRINT2LAYER_INFO(NAS_EMM_MsRegImsiDetachWtCnDetCnfMsgSysinfo_ENUM,LNAS_EMM_TA_NOT_IN_TA_LIST);

         /* �������̳�ͻ��־λDETACH*/
         NAS_EMM_TAU_SaveEmmCollisionCtrl(NAS_EMM_COLLISION_DETACH);

         /*NAS_EMM_TAU_SaveEmmTAUStartCause(     NAS_EMM_TAU_START_CAUSE_SYSINFO);*/
         NAS_EMM_TAU_SaveEmmTAUStartCause(NAS_EMM_TAU_START_CAUSE_OTHERS);

         /* ��������DETACH��TAU��ϱ�ʶ���������������TAU������ȻΪ����TAU */
         NAS_EMM_TAU_SetEmmCombinedDetachBlockFlag(NAS_EMM_COM_DET_BLO_YES);

         /* ����DETACH�ĺ���������DETACH����*/
         NAS_EMM_DetachToTAU();

         /* ����TAU Procedure
            ע:MO_DETACH�����д���TAU����ΪDETACH_COLLISION��־����ȻЯ��ACTVIE,
               ���ж���������*/
         /* �������TAU����ԭ�� */
         NAS_EMM_TAU_StartTAUREQ(NAS_LMM_OM_TAU_START_TYPE_NOT_IN_TAI_LIST);
    }
    /* TA��TAI List�У����� L.V.R TAI*/
    else
    {
        NAS_EMM_SetLVRTai(&pMmNetInfo->stPresentNetId);
        if (NAS_LMM_REG_STATUS_EMC_REGED != NAS_LMM_GetEmmInfoRegStatus())
        {
            /*����PS LOC��Ϣ*/
            NAS_LMM_WritePsLoc(NAS_NV_ITEM_UPDATE);
        }
        /* С����Ϣ����,MMA������������������Ϣ,��Ҫ�յ�TAU IND�Ż����,Ϊ��ܸ�����,
            LMM����һ�������κβ���TAU IND��Ϣ�ϱ���MMC */
        NAS_EMM_SetTauTypeNoProcedure();

        /*��MMC����LMM_MMC_TAU_RESULT_IND��Ϣ*/
        NAS_EMM_MmcSendTauActionResultIndSuccWithoutPara();
    }

    return NAS_LMM_MSG_HANDLED;
}

/*******************************************************************************
  Module   :
  Function : NAS_EMM_MsTAUInitSsWaitCNCnfMsgSysinfo
  Input    :
  Output   :
  NOTE     :
  Return   :
  History  :
    1.  Zhouyan 00125190  2008.09.10  �¹�����
    2.  yangfan 00159566  2009.08.06  �޸�
    3.  zhengjunyan 00148421 2010.10.25 Mod:����ϵͳ��Ϣ�����Ĵ�����New TA�Ĵ���
    4.  liuhua      00212067 2012.05.29 TA�����仯ʱ������EUֵΪEU2
    5.  lihong  00150010  2012.12.14  Modify:Emergency
    6.  lifuxin 00253982  2014.11.06  �����ع�
*******************************************************************************/
VOS_UINT32 NAS_EMM_MsTauInitSsWaitCNCnfMsgSysinfo(VOS_UINT32  ulMsgId,
                                                   VOS_VOID   *pMsgStru )
{
    VOS_UINT32                          ulRslt      = NAS_EMM_FAIL;
    EMMC_EMM_SYS_INFO_IND_STRU          *pstsysinfo  = NAS_EMM_NULL_PTR;
    NAS_EMM_TAU_START_CAUSE_ENUM_UINT8  enTauStartCause;

    (VOS_VOID)ulMsgId;
    NAS_EMM_TAU_LOG_INFO("Nas_Emm_MsTauInitSsWaitCNCnfMsgSysinfo is entered.");
    TLPS_PRINT2LAYER_INFO(NAS_EMM_MsTauInitSsWaitCNCnfMsgSysinfo_ENUM,LNAS_ENTRY);

    /* ��������ָ��������, ״̬ƥ����,����ƥ��,�˳�*/
    ulRslt = NAS_EMM_TAU_CHKFSMStateMsgp(EMM_MS_TAU_INIT,EMM_SS_TAU_WAIT_CN_TAU_CNF,pMsgStru);
    if ( NAS_EMM_SUCC != ulRslt )
    {
        NAS_EMM_TAU_LOG_WARN("NAS_EMM_MsTauInitSsWaitCNCnfMsgSysinfo ERROR !!");
        TLPS_PRINT2LAYER_WARNING(NAS_EMM_MsTauInitSsWaitCNCnfMsgSysinfo_ENUM,LNAS_ERROR);
        return NAS_LMM_MSG_DISCARD;
    }

    /* ��ȡϵͳ��Ϣ*/
    pstsysinfo                          = (EMMC_EMM_SYS_INFO_IND_STRU*)pMsgStru;
    /*���ϵͳ��Ϣ�������򻺴棬��������̾��崦��*/
    if(((EMMC_EMM_NO_FORBIDDEN != pstsysinfo->ulForbiddenInfo)
        || (EMMC_EMM_CELL_STATUS_ANYCELL == pstsysinfo->ulCellStatus))
        && (NAS_EMM_CONN_ESTING == NAS_EMM_GetConnState()))
    {
        return  NAS_LMM_STORE_HIGH_PRIO_MSG;
    }

    /* ���ϵͳ��Ϣ����,��ֹTAU���̣��ͷ�����*/
    if ((NAS_LMM_REG_STATUS_NORM_REGED == NAS_LMM_GetEmmInfoRegStatus())
        && ((EMMC_EMM_NO_FORBIDDEN != pstsysinfo->ulForbiddenInfo)
            || (EMMC_EMM_CELL_STATUS_ANYCELL == pstsysinfo->ulCellStatus)))
    {
        /* ��ֹTAU����*/
        NAS_LMM_StopStateTimer(          TI_NAS_EMM_STATE_TAU_T3430);

        #if (FEATURE_ON == FEATURE_DSDS)
        /*����end notify��Ϣ��RRC��֪ͨRRC�ͷ���Դ*/
        NAS_EMM_TAU_SendRrcDsdsEndNotify();
        #endif

#if (FEATURE_MULTI_MODEM == FEATURE_ON)
        NAS_EMM_SendMtcTAUEndType();
#endif

        if (NAS_EMM_TAU_START_CAUSE_ESM_EMC_PDN_REQ == NAS_EMM_TAU_GetEmmTAUStartCause())
        {
            NAS_EMM_TAU_LOG_INFO("NAS_EMM_MsTauInitSsWaitCNCnfMsgSysinfo:CAUSE_ESM_EMC_PDN_REQ");
            TLPS_PRINT2LAYER_INFO(NAS_EMM_MsTauInitSsWaitCNCnfMsgSysinfo_ENUM,LNAS_FUNCTION_LABEL1);

            NAS_EMM_EmcPndReqTauAbnormalCommProc(   NAS_EMM_MmcSendTauActionResultIndForbType,
                                                    (VOS_VOID*)&pstsysinfo->ulForbiddenInfo,
                                                    EMM_SS_DEREG_LIMITED_SERVICE);
        }
        else
        {
            /* ״̬Ǩ��*/
            NAS_EMM_TAUSER_FSMTranState(EMM_MS_REG,
                            EMM_SS_REG_LIMITED_SERVICE,
                            TI_NAS_EMM_STATE_NO_TIMER);

            /*��MMC����LMM_MMC_TAU_RESULT_IND��Ϣ�ڳ�ͻ������ִ��*/
            NAS_EMM_TAU_ProcEnterForbTA(pstsysinfo->ulForbiddenInfo);
        }
        NAS_EMM_RelReq(NAS_LMM_NOT_BARRED);

        return NAS_LMM_MSG_HANDLED;
    }

    /*��TAU_INIT+WAIT_CN_CNF���յ�ϵͳ��Ϣ����ǰ������״̬��NAS_EMM_CONN_ESTING
      ,����յ���ϵͳ��Ϣ�ڱ����б��У����ͷ���·��ת�����Ʒ���̬������������Ե�TAU
      ������ȼ����棬����ֱ�Ӷ������ȱ��εĽ����ظ�
    */
    enTauStartCause = NAS_EMM_TAU_GetTauStartCause();
    if(NAS_EMM_CONN_ESTING == NAS_EMM_GetConnState())
    {
        if(NAS_EMM_TAU_START_CAUSE_T3412EXP == enTauStartCause)
        {
            return NAS_LMM_STORE_HIGH_PRIO_MSG;
        }
        else
        {
            return NAS_LMM_MSG_HANDLED;
        }
    }

#if(FEATURE_ON == FEATURE_CSG)
    if(NAS_EMM_YES == NAS_EMM_MsTauInitSsWaitCNCnfIsCsgIdChangeTauStart())
    {
        return NAS_LMM_MSG_HANDLED;
    }
#endif

    NAS_EMM_MsTauInitSsWaitCNCnfSysChangeOrNotProc(pstsysinfo->ulChangeInfo);
    return NAS_LMM_MSG_HANDLED;
}

VOS_VOID NAS_EMM_ProcHoWaitSysInfoBufferMsg( VOS_VOID )
{
    NAS_EMM_MRRC_MGMT_DATA_STRU         *pEmmMrrcMgmtData = NAS_EMM_NULL_PTR;
    NAS_EMM_MRRC_DATA_REQ_STRU          *pMrrcDataMsg = VOS_NULL_PTR;
    VOS_UINT32                          ulIndex;
    VOS_UINT32                          ulCurSaveMsgNum = 0;
    VOS_UINT32                          ulMmRrcOpId;

    ulCurSaveMsgNum = g_ulSaveMsgNum;

    pEmmMrrcMgmtData                    = NAS_EMM_GET_MRRC_MGMT_DATA_ADDR();

    /* ������Ϣ�ڴ�*/
    /* �տ���Ϣ�����ڴ�ֱ������1024�ֽڶ�����ʵ�ʳ���, ���:�������ڴ�Ϊʵ�ʳ���,
        �ڼ��ܼӱ�����, ���ϰ�ȫͷ����, �ڴ�Խ��6���ֽ����� */
    pMrrcDataMsg = (NAS_EMM_MRRC_DATA_REQ_STRU *)(VOS_VOID*)NAS_LMM_MEM_ALLOC(NAS_EMM_INTRA_MSG_MAX_SIZE);

    if(VOS_NULL_PTR == pMrrcDataMsg)
    {
        NAS_EMM_PUBU_LOG_ERR("NAS_EMM_ProcHoWaitSysInfoBufferMsg: Mem Alloc Fail");
        TLPS_PRINT2LAYER_ERROR(NAS_EMM_ProcHoWaitSysInfoBufferMsg_ENUM,LNAS_NULL_PTR);
        return;
    }

    /* ����HO WAIT SYS INFO �����¼ */
    for (ulIndex = 0; ulIndex < ulCurSaveMsgNum; ++ulIndex)
    {
        if (VOS_TRUE == pEmmMrrcMgmtData->ulHoWaitSysInfoFlag)
        {
            /* �ط���Ϣ֮�󣬵�ǰָ��ָ�����Ϣ�����Ѿ��ı䣬������Ҫ����ǰ��Ϣ��OPID���棬
            ���ں����建��ʹ��*/
            ulMmRrcOpId = pEmmMrrcMgmtData->ulMmRrcOpId;

            if (NAS_EMM_MSG_SERVICE_REQ == pEmmMrrcMgmtData->enLastMsgId)
            {
                /* �ط�SERVICE����EXTENDED SERVICE REQ��Ϣ */
                pMrrcDataMsg->enDataCnf = LRRC_LMM_DATA_CNF_NEED;

                pMrrcDataMsg->enEmmMsgType = NAS_EMM_MSG_SERVICE_REQ;
                pMrrcDataMsg->ulMsgId = ID_NAS_LMM_INTRA_MRRC_DATA_REQ;
                pMrrcDataMsg->ulEsmMmOpId = pEmmMrrcMgmtData->ulEsmMmOpId;

                pMrrcDataMsg->stNasMsg.ulNasMsgSize = pEmmMrrcMgmtData->ulNasMsgLength;

                /* ����MRRC_DATA_REQ �е� NAS_MSG_STRU,��CN��Ϣ(Compose the msg of): SER_REQ */
                NAS_EMM_SER_CompCnServiceReq(&(pMrrcDataMsg->stNasMsg));

                NAS_EMM_SndUplinkNasMsg(pMrrcDataMsg);

            }
            else if (NAS_EMM_MSG_EXTENDED_SERVICE_REQ == pEmmMrrcMgmtData->enLastMsgId)
            {
                /* �ط�EXTENDED SERVICE REQ��Ϣ */
                /* �����ع� */
                NAS_EMM_ExtSerReqRetranProc(pEmmMrrcMgmtData->ulMmRrcOpId);
            }
            else if (NAS_EMM_MSG_TAU_CMP == pEmmMrrcMgmtData->enLastMsgId)
            {
                pMrrcDataMsg->enDataCnf = LRRC_LMM_DATA_CNF_NEED;

                pMrrcDataMsg->enEmmMsgType = NAS_EMM_MSG_TAU_CMP;
                pMrrcDataMsg->ulMsgId = ID_NAS_LMM_INTRA_MRRC_DATA_REQ;
                pMrrcDataMsg->ulEsmMmOpId = pEmmMrrcMgmtData->ulEsmMmOpId;

                pMrrcDataMsg->stNasMsg.ulNasMsgSize = pEmmMrrcMgmtData->ulNasMsgLength;

                NAS_LMM_MEM_CPY_S(  pMrrcDataMsg->stNasMsg.aucNasMsg,
                                    pEmmMrrcMgmtData->ulNasMsgLength,
                                    pEmmMrrcMgmtData->aucNasMsgContent,
                                    pEmmMrrcMgmtData->ulNasMsgLength);

                NAS_EMM_SndUplinkNasMsg(pMrrcDataMsg);

            }
            #if (FEATURE_LPP == FEATURE_ON)
            else if (NAS_EMM_NAS_UPLINK_GENERIC_NAS_TRANSPORT == pEmmMrrcMgmtData->enLastMsgId)
            {
                pMrrcDataMsg->enDataCnf             = LRRC_LMM_DATA_CNF_NEED;
                pMrrcDataMsg->enEmmMsgType          = NAS_EMM_NAS_UPLINK_GENERIC_NAS_TRANSPORT;
                pMrrcDataMsg->ulMsgId               = ID_NAS_LMM_INTRA_MRRC_DATA_REQ;
                pMrrcDataMsg->ulEmmLppOrSsOpId      = pEmmMrrcMgmtData->ulEmmLppOrSsOpId;
                pMrrcDataMsg->ulLppSsFlag           = pEmmMrrcMgmtData->ulLppSsFlag;

                pMrrcDataMsg->stNasMsg.ulNasMsgSize = pEmmMrrcMgmtData->ulNasMsgLength;
                NAS_LMM_MEM_CPY_S(  pMrrcDataMsg->stNasMsg.aucNasMsg,
                                    pEmmMrrcMgmtData->ulNasMsgLength,
                                    pEmmMrrcMgmtData->aucNasMsgContent,
                                    pEmmMrrcMgmtData->ulNasMsgLength);

                NAS_EMM_SndUplinkNasMsg(pMrrcDataMsg);
            }
            #endif
            else
            {

            }

            NAS_EMM_ClrDataReqBufferMsg(ulMmRrcOpId);
        }
        else
        {
            pEmmMrrcMgmtData++;
        }

    }
    /*�ͷ��������ڴ� */
    NAS_LMM_MEM_FREE(pMrrcDataMsg);
    return;
}
/* NO RF����ֱ����Ϣ�ش����������� */
NAS_LMM_BUFFER_MSG_RETRAN_ACT_STRU  gstEmmBufferMsgActTbl[]=
{
    {NAS_EMM_MSG_EXTENDED_SERVICE_REQ,      NAS_EMM_ExtSerReqRetranProc},
};
VOS_UINT32        g_ulEmmBufferMsgActTblLen = sizeof(gstEmmBufferMsgActTbl)
                                                / sizeof(NAS_LMM_BUFFER_MSG_RETRAN_ACT_STRU);
/*******************************************************************************
  Function : NAS_EMM_ProcNoRfWaitSysInfoBufferMsg
  Input    : NONE
  Output   : NONE
  NOTE     : NO RF����һЩ����ֱ������ʧ��,���յ�ϵͳ��Ϣ��һЩ��Ҫ�ش�
  Return   : NONE
  History  :
    1.leixiantiao 00258641     2015-02-04  NEW draf
*******************************************************************************/
VOS_VOID NAS_EMM_ProcNoRfWaitSysInfoBufferMsg( VOS_VOID )
{
    NAS_EMM_MRRC_MGMT_DATA_STRU         *pEmmMrrcMgmtData = NAS_EMM_NULL_PTR;
    VOS_UINT32                          ulLoop;
    VOS_UINT32                          ulIndex;
    VOS_UINT32                          ulCurSaveMsgNum = 0;
    VOS_UINT32                          ulMmRrcOpId;
    NAS_LMM_BUFFER_MSG_RETRAN_ACT_FUN   pActFun;

    ulCurSaveMsgNum = g_ulSaveMsgNum;

    pEmmMrrcMgmtData                    = NAS_EMM_GET_MRRC_MGMT_DATA_ADDR();

    /* ����HO WAIT SYS INFO �����¼ */
    for (ulIndex = 0; ulIndex < ulCurSaveMsgNum; ++ulIndex)
    {
        if (VOS_TRUE == pEmmMrrcMgmtData->ulNoRfWaitSysInfoFlag)
        {
            /* �ط���Ϣ֮�󣬵�ǰָ��ָ�����Ϣ�����Ѿ��ı䣬������Ҫ����ǰ��Ϣ��OPID���棬
            ���ں����建��ʹ��*/
            ulMmRrcOpId = pEmmMrrcMgmtData->ulMmRrcOpId;

            for(ulLoop = 0; ulLoop < g_ulEmmBufferMsgActTblLen; ulLoop++)
            {
                if(gstEmmBufferMsgActTbl[ulLoop].enMsgId == pEmmMrrcMgmtData->enLastMsgId)
                {
                    pActFun = gstEmmBufferMsgActTbl[ulLoop].pfMsgReTranFun;
                    if(VOS_NULL_PTR != pActFun)
                    {
                        (VOS_VOID)pActFun(pEmmMrrcMgmtData->ulMmRrcOpId);
                    }
                    break;
                }
            }
            NAS_EMM_ClrDataReqBufferMsg(ulMmRrcOpId);
        }
        else
        {
            pEmmMrrcMgmtData++;
        }
    }
    return;
}

NAS_LMM_BUFFER_MSG_RETRAN_ACT_STRU  gstEmmBufferMsgActConnRelTbl[]=
{
    {NAS_EMM_MSG_ESM,      NAS_EMM_EsmDataReqRetranProc},
};
VOS_UINT32        g_ulEmmBufferMsgActConnRelTblLen = sizeof(gstEmmBufferMsgActConnRelTbl)
                                                / sizeof(NAS_LMM_BUFFER_MSG_RETRAN_ACT_STRU);

/*******************************************************************************
  Function : NAS_EMM_ProcConnRelWaitSysInfoBufferMsg
  Input    : NONE
  Output   : NONE
  NOTE     : �����������̶Գ壬RRC CONN REL��������ֱ������ʧ��,���յ�ϵͳ��Ϣ��һЩ��Ҫ�ش������
  Return   : NONE
  History  :
    1.chengmin 00285307     2015-02-04  draf enact
*******************************************************************************/
VOS_VOID NAS_EMM_ProcConnRelWaitSysInfoBufferMsg( VOS_VOID )
{
    NAS_EMM_MRRC_MGMT_DATA_STRU        *pEmmMrrcMgmtData = NAS_EMM_NULL_PTR;
    VOS_UINT32                          ulLoop;
    VOS_UINT32                          ulIndex;
    VOS_UINT32                          ulCurSaveMsgNum = 0;
    VOS_UINT32                          ulMmRrcOpId;
    NAS_LMM_BUFFER_MSG_RETRAN_ACT_FUN   pActFun;

    ulCurSaveMsgNum                     = g_ulSaveMsgNum;

    pEmmMrrcMgmtData                    = NAS_EMM_GET_MRRC_MGMT_DATA_ADDR();

    /* ����CONN REL WAIT SYS INFO �����¼ */
    for (ulIndex = 0; ulIndex < ulCurSaveMsgNum; ++ulIndex)
    {
        if (VOS_TRUE == pEmmMrrcMgmtData->ulConnRelWaitSysInfoFlag)
        {
            /* �ط���Ϣ֮�󣬵�ǰָ��ָ�����Ϣ�����Ѿ��ı䣬������Ҫ����ǰ��Ϣ��OPID���棬
            ���ں����建��ʹ��*/
            ulMmRrcOpId = pEmmMrrcMgmtData->ulMmRrcOpId;

            for(ulLoop = 0; ulLoop < g_ulEmmBufferMsgActConnRelTblLen; ulLoop++)
            {
                if(gstEmmBufferMsgActConnRelTbl[ulLoop].enMsgId == pEmmMrrcMgmtData->enLastMsgId)
                {
                    pActFun = gstEmmBufferMsgActConnRelTbl[ulLoop].pfMsgReTranFun;
                    if(VOS_NULL_PTR != pActFun)
                    {
                        pActFun(pEmmMrrcMgmtData->ulMmRrcOpId);
                    }
                    break;
                }
            }
            NAS_EMM_ClrDataReqBufferMsg(ulMmRrcOpId);
        }
        else
        {
            pEmmMrrcMgmtData++;
        }
    }
}




/*******************************************************************************
  Module   :
  Function : NAS_EMM_MsSerInitSsWaitCNCnfMsgSysInfoCommProc
  Input    :
  Output   :
  NOTE     : SERVICE_INIT+WAIT_CN_CNF״̬���յ�ϵͳ��Ϣ�Ĺ�������
  Return   : VOS_UINT32
  History  :
    1.lihong 00150010       2012.12.20      �¹�����
*******************************************************************************/
VOS_VOID NAS_EMM_MsSerInitSsWaitCNCnfMsgSysInfoCommProc( VOS_VOID )
{
    VOS_UINT32                          ulTaRslt    = NAS_EMM_FAIL;
    NAS_LMM_NETWORK_INFO_STRU           *pMmNetInfo = NAS_EMM_NULL_PTR;

    /* ��ȡEMMά����������Ϣ*/
    pMmNetInfo                          = NAS_LMM_GetEmmInfoNetInfoAddr();


#if(FEATURE_ON == FEATURE_CSG)
    if((NAS_EMM_YES == NAS_LMM_IsCsgCampOn())
        &&(NAS_EMM_FAIL == NAS_EMM_TAU_IsCsgIdInAllowedOrOperatorCsgList()))
    {

        NAS_EMM_TAU_LOG_INFO("NAS_EMM_MsSerInitSsWaitCNCnfMsgSysInfoCommProc:CSGID not in CSG LIST.");
        TLPS_PRINT2LAYER_INFO(NAS_EMM_MsSerInitSsWaitCNCnfMsgSysInfoCommProc_ENUM,LNAS_FUNCTION_LABEL1);

        /*ֹͣT3417��ʱ��*/
        NAS_LMM_StopStateTimer(TI_NAS_EMM_STATE_SERVICE_T3417);

        /*ֹͣT3417ext��ʱ��*/
        NAS_LMM_StopStateTimer(TI_NAS_EMM_STATE_SERVICE_T3417_EXT);

        if (VOS_TRUE != NAS_EMM_SER_IsCsfbProcedure())
        {
            /*Inform RABM that SER fail*/
            NAS_EMM_SER_SendRabmReestInd(EMM_ERABM_REEST_STATE_FAIL);
        }

        /* ���ulHoWaitSysInfoFlag��ʶ���ڵĻ����¼ */
        (VOS_VOID)NAS_EMM_ClrWaitSysInfoBufferMsg();

        /*�������̳�ͻ��־λ*/
        NAS_EMM_TAU_SaveEmmCollisionCtrl(NAS_EMM_COLLISION_SERVICE);

        if (NAS_EMM_SER_START_CAUSE_ESM_DATA_REQ_EMC == NAS_EMM_SER_GetEmmSERStartCause())
        {
            NAS_EMM_TAU_SaveEmmTAUStartCause(NAS_EMM_TAU_START_CAUSE_ESM_EMC_PDN_REQ);
        }
        else
        {
            NAS_EMM_TAU_SaveEmmTAUStartCause(NAS_EMM_TAU_START_CAUSE_OTHERS);
        }

        /*����TAU Procedure*/
        NAS_EMM_TAU_StartTAUREQ(NAS_LMM_OM_TAU_START_TYPE_NOT_IN_CSG_LIST);

        return;
    }
#endif

    /*�ж�TA����TA List�У���Ҫ����TAU Procedure,TA���ϴ�ע���TA List�У����ԶԵ�ǰϵͳ��Ϣ�Ĵ���*/
    ulTaRslt = NAS_EMM_TAU_IsCurrentTAInTaList();
    if (NAS_EMM_FAIL == ulTaRslt)
    {
        NAS_EMM_TAU_LOG_INFO("NAS_EMM_MsSerInitSsWaitCNCnfMsgSysInfoCommProc:TA not in TAI LIST.");
        TLPS_PRINT2LAYER_INFO(NAS_EMM_MsSerInitSsWaitCNCnfMsgSysInfoCommProc_ENUM,LNAS_EMM_TA_NOT_IN_TA_LIST);

        /*ֹͣT3417��ʱ��*/
        NAS_LMM_StopStateTimer(TI_NAS_EMM_STATE_SERVICE_T3417);

        /*ֹͣT3417ext��ʱ��*/
        NAS_LMM_StopStateTimer(TI_NAS_EMM_STATE_SERVICE_T3417_EXT);

        if (VOS_TRUE != NAS_EMM_SER_IsCsfbProcedure())
        {
            /*Inform RABM that SER fail*/
            NAS_EMM_SER_SendRabmReestInd(EMM_ERABM_REEST_STATE_FAIL);
        }

        /* ���ulHoWaitSysInfoFlag��ʶ���ڵĻ����¼ */
        /* �޸ĺ������� */
        (VOS_VOID)NAS_EMM_ClrWaitSysInfoBufferMsg();

        /*�������̳�ͻ��־λ*/
        NAS_EMM_TAU_SaveEmmCollisionCtrl(NAS_EMM_COLLISION_SERVICE);

        if (NAS_EMM_SER_START_CAUSE_ESM_DATA_REQ_EMC == NAS_EMM_SER_GetEmmSERStartCause())
        {
            NAS_EMM_TAU_SaveEmmTAUStartCause(NAS_EMM_TAU_START_CAUSE_ESM_EMC_PDN_REQ);
        }
        else
        {
            NAS_EMM_TAU_SaveEmmTAUStartCause(NAS_EMM_TAU_START_CAUSE_OTHERS);
        }

        /*����TAU Procedure*/
        /* �������TAU����ԭ�� */
        NAS_EMM_TAU_StartTAUREQ(NAS_LMM_OM_TAU_START_TYPE_NOT_IN_TAI_LIST);
    }
    else
    {
        /*����L.V.R TAI*/
        NAS_EMM_SetLVRTai(&pMmNetInfo->stPresentNetId);
        /* ��������ȱ���Ż�:
           UE����ESR��Ϣ,�����ѵ����緢�ͳɹ���Ϣ����Ӧ,��ʱ����X2�ӿڵ��л�
           UE�л��ɹ���,MMEӦ�����´���eNB����CSFB����,��Ϊ�����쳣,CSFB����û�з�����
           UEδ�յ��ض���GU����ϵͳ����,����T3417ext��ʱ
           �Ż�Ϊ:UEʶ��ó���,���·���һ��ESR,�������緢��CSFB���� */
        NAS_EMM_ProcHoRetransESRMsg();

        NAS_EMM_ProcHoWaitSysInfoBufferMsg();
        #if (FEATURE_ON == FEATURE_DSDS)
        /* ��������RF��Դ������������ֱ��û�з��ͳɹ���Ҫ�ش���buffer */
        NAS_EMM_ProcNoRfWaitSysInfoBufferMsg();
        #endif

        if (NAS_LMM_REG_STATUS_EMC_REGED != NAS_LMM_GetEmmInfoRegStatus())
        {
            /*����PS LOC��Ϣ*/
            NAS_LMM_WritePsLoc(NAS_NV_ITEM_UPDATE);
        }
        /* ������Ϣ����,MMA������������������Ϣ,��Ҫ�յ�TAU IND�Ż����,Ϊ��ܸ�����,
            LMM����һ�������κβ���TAU IND��Ϣ�ϱ���MMC */
        NAS_EMM_SetTauTypeNoProcedure();

        /*��MMC����LMM_MMC_TAU_RESULT_IND��Ϣ*/
        NAS_EMM_MmcSendTauActionResultIndSuccWithoutPara();
    }
}

/*******************************************************************************
  Module   :
  Function : NAS_EMM_MsSerInitSsWaitCNCnfMsgForbiddenAnycellSysinfoProc
  Input    : None
  Output   : None
  NOTE     : SERVICE_INIT+WAIT_CN_CNF״̬���յ�������ANYCELLϵͳ��Ϣ����
  Return   : VOS_UINT32
  History  :
    1.lihong 00150010       2012.12.20      �¹�����
*******************************************************************************/
VOS_VOID NAS_EMM_MsSerInitSsWaitCNCnfMsgForbiddenAnycellSysinfoProc( VOS_VOID )
{
    if (NAS_LMM_REG_STATUS_NORM_REGED != NAS_LMM_GetEmmInfoRegStatus())
    {
        if ((NAS_EMM_SER_START_CAUSE_RRC_PAGING == NAS_EMM_SER_GetEmmSERStartCause())
            || (NAS_EMM_SER_START_CAUSE_RABM_REEST_EMC == NAS_EMM_SER_GetEmmSERStartCause()))
        {
            NAS_EMM_MsSerInitSsWaitCNCnfMsgSysInfoCommProc();
            return ;
        }

        if (VOS_TRUE == NAS_EMM_SER_IsCsfbProcedure())
        {
            /*��MMC����LMM_MMC_SERVICE_RESULT_IND��Ϣ*/
            NAS_EMM_MmcSendSerResultIndOtherType( MMC_LMM_SERVICE_RSLT_FAILURE);
        }

        /* ��ֹSER����*/
        NAS_EMM_SER_AbnormalOver();

        NAS_EMM_TAUSER_FSMTranState(    EMM_MS_REG,
                                        EMM_SS_REG_LIMITED_SERVICE,
                                        TI_NAS_EMM_STATE_NO_TIMER);

        /* ���Serviceģ��*/
        NAS_EMM_SER_ClearResource();

        NAS_EMM_RelReq(                 NAS_LMM_NOT_BARRED);

        return ;
    }

    if (VOS_TRUE == NAS_EMM_SER_IsCsfbProcedure())
    {
        /*��MMC����LMM_MMC_SERVICE_RESULT_IND��Ϣ*/
        NAS_EMM_MmcSendSerResultIndOtherType( MMC_LMM_SERVICE_RSLT_FAILURE);
    }

    /* ��ֹSER����*/
    NAS_EMM_SER_AbnormalOver();

    if (NAS_EMM_SER_START_CAUSE_ESM_DATA_REQ_EMC == NAS_EMM_SER_GetEmmSERStartCause())
    {
        NAS_EMM_TAU_LOG_INFO("NAS_EMM_MsSerInitSsWaitCNCnfMsgForbiddenAnycellSysinfoProc: CAUSE_ESM_DATA_REQ_EMC.");
        TLPS_PRINT2LAYER_INFO(NAS_EMM_MsSerInitSsWaitCNCnfMsgForbiddenAnycellSysinfoProc_ENUM,LNAS_FUNCTION_LABEL1);

        NAS_EMM_EmcPndReqSerAbnormalCommProc(EMM_SS_DEREG_LIMITED_SERVICE);
    }
    else
    {
        /* ״̬Ǩ��:Reg.Limite_Service*/
        NAS_EMM_TAUSER_FSMTranState(    EMM_MS_REG,
                                        EMM_SS_REG_LIMITED_SERVICE,
                                        TI_NAS_EMM_STATE_NO_TIMER);
    }

    /* ���Serviceģ��*/
    NAS_EMM_SER_ClearResource();

    NAS_EMM_RelReq(                 NAS_LMM_NOT_BARRED);
}
/*******************************************************************************
  Module   :
  Function : NAS_EMM_MsSERInitSsWaitCNCnfMsgSysinfo
  Input    :
  Output   :
  NOTE     :
  Return   :
  History  :
    1.  Zhouyan 00125190    2008.09.10  �¹�����
    2.zhengjunyan 00148421  2010-10-25  MOD:�޸�ϵͳ��Ϣ�����Ĵ���
    3.3.lihong 00150010     2012-02-27  Modify:CSFB
    4.wangchen 00209181     2012-08-21  Modify
    5.lihong 00150010       2012-12-13  Modify:Emergency
    6.lifuxin 00253982      2014-11-06  �����ع�
*******************************************************************************/
VOS_UINT32 NAS_EMM_MsSerInitSsWaitCNCnfMsgSysinfo(VOS_UINT32  ulMsgId,
                                                   VOS_VOID   *pMsgStru)
{

    VOS_UINT32                          ulRslt       = NAS_EMM_FAIL;
    EMMC_EMM_SYS_INFO_IND_STRU         *pstsysinfo   = NAS_EMM_NULL_PTR;
    EMMC_EMM_FORBIDDEN_INFO_ENUM_UINT32  ulForbiddenInfo = EMMC_EMM_NO_FORBIDDEN;
    (VOS_VOID)ulMsgId;
    NAS_EMM_TAU_LOG_INFO("NAS_EMM_MsSerInitSsWaitCNCnfMsgSysinfo entered.");
    TLPS_PRINT2LAYER_INFO(NAS_EMM_MsSerInitSsWaitCNCnfMsgSysinfo_ENUM,LNAS_ENTRY);

    /* ��������ָ��������, ״̬ƥ����,����ƥ��,�˳�*/
    ulRslt = NAS_EMM_TAU_CHKFSMStateMsgp(EMM_MS_SER_INIT,EMM_SS_SER_WAIT_CN_SER_CNF,pMsgStru);
    if ( NAS_EMM_SUCC != ulRslt )
    {
        NAS_EMM_TAU_LOG_WARN("NAS_EMM_MsSerInitSsWaitCNCnfMsgSysinfo ERROR !!");
        TLPS_PRINT2LAYER_WARNING(NAS_EMM_MsSerInitSsWaitCNCnfMsgSysinfo_ENUM,LNAS_ERROR);
        return NAS_LMM_MSG_DISCARD;
    }

    /* ��ȡϵͳ��Ϣ*/
    pstsysinfo                          = (EMMC_EMM_SYS_INFO_IND_STRU*)pMsgStru;

    if(NAS_EMM_CONN_ESTING == NAS_EMM_GetConnState())
    {
        return  NAS_LMM_STORE_HIGH_PRIO_MSG;
    }
    /* ����ϵͳ���л�������С��,���Ա���:������LС��A��B(������TA)
        UE��С��B��פ��������MMEĳЩ�쳣,��UE�·�ԭ��ֵ#15����MMEδ��
        TA���뱻���б���(δ�汻����ֻ����ʱ����)����UE�յ�#15ԭ��ֵ,
        ����������פ����AС����֮��������UE�л���BС�������л�ʱLRRC
        �����ж�С���Ƿ񱻽���LMM�յ�ϵͳ��Ϣ����BС�����յ���#15ԭ
        ��ֵ,LMM�����ͷŽ������Ʒ���̬��LRRC�ͷź���С��A��פ�����Ӷ�����ƹ���л� */
    ulForbiddenInfo = pstsysinfo->ulForbiddenInfo;
    if(NAS_EMM_YES == NAS_EMM_IsIntraHoIgnoreForbSysInfo())
    {
        /* ����FORBIDDEN TA FOR ROAMING,���ڱ�#15ԭ��ֵ�ܺ�,פ����TA������FORBIDDEN TA LIST��,����TAILIST��ɾ�������Ժ�������TAU */
        if(EMMC_EMM_FORBIDDEN_TA_FOR_ROAMING == pstsysinfo->ulForbiddenInfo)
        {
            NAS_EMM_PUBU_LOG1_INFO("NAS_EMM_MsRegSsNormalMsgSysinfo Ignore ForbTaForRoaming:forbiddenInfo = ",
                               pstsysinfo->ulForbiddenInfo);
            TLPS_PRINT2LAYER_INFO1(NAS_EMM_MsSerInitSsWaitCNCnfMsgSysinfo_ENUM,LNAS_EMM_FORB_INFO,
                               pstsysinfo->ulForbiddenInfo );
            ulForbiddenInfo = EMMC_EMM_NO_FORBIDDEN;
            #if (FEATURE_ON == FEATURE_PTM)
            NAS_EMM_ImprovePerformceeErrReport(EMM_OM_ERRLOG_IMPROVEMENT_TYPE_HO_TO_FORBIDDEN_TA);
            #endif
        }
    }
    /* ���ϵͳ��Ϣ��������ֹSER���̣��ͷ�����*/
    if ((EMMC_EMM_NO_FORBIDDEN != ulForbiddenInfo)
            || (EMMC_EMM_CELL_STATUS_ANYCELL == pstsysinfo->ulCellStatus))
    {
        NAS_EMM_TAU_LOG_WARN("NAS_EMM_MsSerInitSsWaitCNCnfMsgSysinfo:CELL FORB.");
        TLPS_PRINT2LAYER_WARNING(NAS_EMM_MsSerInitSsWaitCNCnfMsgSysinfo_ENUM,LNAS_EMM_FORBIDDEN);

        NAS_EMM_MsSerInitSsWaitCNCnfMsgForbiddenAnycellSysinfoProc();

        return NAS_LMM_MSG_HANDLED;
    }

    NAS_EMM_MsSerInitSsWaitCNCnfMsgSysInfoCommProc();

    return NAS_LMM_MSG_HANDLED;
}
/*******************************************************************************
  Module   :
  Function : NAS_EMM_MsRegSsNormalServiceMsgIntraTauReq
  Input    :
  Output   :
  NOTE     :
  Return   :
  History  :
    1.  leili 00132387  2009.03.09  �¹�����
    2.  X00148705                   NAS_EMM_TAU_UE_NET_CAP_BIT��NAS_EMM_TAU_DRX_BIT()��OM����ʱ������
    3.  X00148705       2009-11-17  �޸����ݲ�ͬ��ԭ��ֵ����TAU
    4.  sunbing 49683   2010.09.13  ��������״̬���յ�����������������֮ǰ��TAUû�гɹ�����Ҫ�ȶ�ʱ����ʱ�ٷ���TAU
*******************************************************************************/
VOS_UINT32 NAS_EMM_MsRegSsNormalServiceMsgIntraTauReq(VOS_UINT32  ulMsgId,
                                                   VOS_VOID   *pMsgStru)
{

    NAS_LMM_INTRA_TAU_REQ_STRU         *pIntraTauReq = NAS_EMM_NULL_PTR;
    (VOS_VOID)ulMsgId;

    /* ��ӡ����ú���*/
    NAS_EMM_TAU_LOG_NORM(               "NAS_EMM_MsRegSsNormalServiceMsgIntraTauReq is entered.");
    TLPS_PRINT2LAYER_INFO(NAS_EMM_MsRegSsNormalServiceMsgIntraTauReq_ENUM,LNAS_ENTRY);

    /* ��������ָ��������*/
    if(NAS_EMM_NULL_PTR                 == pMsgStru)
    {
       NAS_EMM_TAU_LOG_ERR(             "NAS_EMM_MsRegSsNormalServiceMsgIntraTauReq TpCmdType Err!!");
       TLPS_PRINT2LAYER_ERROR(NAS_EMM_MsRegSsNormalServiceMsgIntraTauReq_ENUM,LNAS_NULL_PTR);
       return NAS_LMM_MSG_DISCARD;
    }

    /* �ж��Ƿ��������Pending*/
    NAS_EMM_TAU_IsUplinkPending();
    /*����ڲ�TAU������ΪNAS_LMM_INTRA_TAU_TYPE_IMSI_ATTACH�����������������Ϊ
    NAS_LMM_UE_RADIO_CAP_LTE_CHG���Ҵ洢��APP��Ϣ����ΪATTACH REQ����ظ�ATTACH CNF��
    ���ΪMMC_LMM_ATT_RSLT_FAILURE*/
    pIntraTauReq = (NAS_LMM_INTRA_TAU_REQ_STRU*)pMsgStru;
    if((NAS_LMM_INTRA_TAU_TYPE_IMSI_ATTACH == pIntraTauReq->enIntraTauType)   &&
        (NAS_LMM_UE_RADIO_CAP_LTE_CHG == NAS_LMM_GetEmmInfoUeRadioCapChgFlag())&&
        (NAS_EMM_OK == NAS_EMM_CheckAppMsgPara(ID_MMC_LMM_ATTACH_REQ)))
      {
            NAS_EMM_MmcSendAttCnf(MMC_LMM_ATT_RSLT_FAILURE);
      }

    /* ����ϴ�TAUû�гɹ��������ò��������ʶ���ȴ�T3411��ʱ*/
    if ((NAS_EMM_YES == NAS_EMM_SER_AbnormalNeedtoContinueTau())
        &&(NAS_LMM_TIMER_RUNNING == NAS_LMM_IsPtlTimerRunning(TI_NAS_EMM_PTL_T3411)))
    {
        NAS_LMM_SetEmmInfoDrxNetCapChange(NAS_EMM_YES);
        /*�޸�TAU����ԭ��*/
        /*NAS_EMM_TAU_SaveEmmTAUStartCause( NAS_EMM_TAU_START_CAUSE_INTRA_TAU_REQ);*/
        NAS_EMM_TAU_SaveEmmTAUStartCause(NAS_EMM_TAU_START_CAUSE_OTHERS);
    }
    else
    {
        NAS_LMM_SetEmmInfoDrxNetCapChange(NAS_EMM_YES);
        /*NAS_EMM_TAU_SaveEmmTAUStartCause( NAS_EMM_TAU_START_CAUSE_INTRA_TAU_REQ);*/
        NAS_EMM_TAU_SaveEmmTAUStartCause(NAS_EMM_TAU_START_CAUSE_OTHERS);

        /* �������TAU����ԭ�� */
        NAS_EMM_TAU_StartTAUREQ(NAS_LMM_OM_TAU_START_TYPE_DRX_CHANGEED);
    }

    return NAS_LMM_MSG_HANDLED;

}

/*****************************************************************************
 Function Name   : NAS_EMM_MsRegSsNormalMsgBearerStatusReq
 Description     : Reg.Normal_Service״̬��ESM�����޸ĳ��������ģ�����TAU���̣�
                   ͬ��UE��MME����ά���ĳ���������
 Input           : None
 Output          : None
 Return          : VOS_UINT32

 History         :
    1.zhengjunyan 00148421     2011-1-11  Draft Enact

*****************************************************************************/
VOS_UINT32  NAS_EMM_MsRegSsNormalMsgBearerStatusReq( VOS_UINT32  ulMsgId,
                                                   VOS_VOID   *pMsgStru )
{

    (VOS_VOID)ulMsgId;

    NAS_EMM_TAU_LOG_NORM("NAS_EMM_MsRegSsNormalMsgBearerStatusReq entered.");
    TLPS_PRINT2LAYER_INFO(NAS_EMM_MsRegSsNormalMsgBearerStatusReq_ENUM,LNAS_ENTRY);

    /* ��������ָ��������*/
    if(NAS_EMM_NULL_PTR                 == pMsgStru)
    {
       NAS_EMM_TAU_LOG_ERR("NAS_EMM_MsRegSsNormalMsgBearerStatusReq:NULL PTR.");
       TLPS_PRINT2LAYER_ERROR(NAS_EMM_MsRegSsNormalMsgBearerStatusReq_ENUM,LNAS_NULL_PTR);
       return NAS_LMM_MSG_DISCARD;
    }


    /* ����ϴ�TAUû�гɹ������޸�TAU����ԭ�򣬵ȴ�T3411��ʱ*/
    if ((NAS_EMM_YES == NAS_EMM_SER_AbnormalNeedtoContinueTau())
        &&(NAS_LMM_TIMER_RUNNING == NAS_LMM_IsPtlTimerRunning(TI_NAS_EMM_PTL_T3411)))
    {
        /*NAS_EMM_TAU_SaveEmmTAUStartCause(NAS_EMM_TAU_START_CAUSE_BEARER_CNTXT_LOCAL_CHANGED);*/
        NAS_EMM_TAU_SaveEmmTAUStartCause(NAS_EMM_TAU_START_CAUSE_OTHERS);
        NAS_EMM_SetEpsContextStatusChange(NAS_EMM_EPS_BEARER_STATUS_CHANGEED);
    }
    else
    {
        /* �ж��Ƿ��������Pending*/
        NAS_EMM_TAU_IsUplinkPending();

        /* ����TAU*/
        /*NAS_EMM_TAU_SaveEmmTAUStartCause(NAS_EMM_TAU_START_CAUSE_BEARER_CNTXT_LOCAL_CHANGED);*/
        NAS_EMM_TAU_SaveEmmTAUStartCause(NAS_EMM_TAU_START_CAUSE_OTHERS);
        NAS_EMM_SetEpsContextStatusChange(NAS_EMM_EPS_BEARER_STATUS_CHANGEED);
        /* �������TAU����ԭ�� */
        NAS_EMM_TAU_StartTAUREQ(NAS_LMM_OM_TAU_START_TYPE_BEARER_STATUS_CHANGEED);
    }

    return NAS_LMM_MSG_HANDLED;

}

/*****************************************************************************
 Function Name   : NAS_EMM_MsRegSsRegAttemptUpdateMmMsgBearerStatusReq
 Description     : Reg.Attempting_to_update_mm״̬��ESM�����޸ĳ��������ģ�
                    ����TAU���̣�ͬ��UE��MME����ά���ĳ���������
 Input           : None
 Output          : None
 Return          : VOS_UINT32

 History         :
    1.leili 00132387      2011-7-12  Draft Enact

*****************************************************************************/
VOS_UINT32  NAS_EMM_MsRegSsRegAttemptUpdateMmMsgBearerStatusReq
(
    VOS_UINT32  ulMsgId,
    VOS_VOID   *pMsgStru
)
{
    (VOS_VOID)ulMsgId;
    (VOS_VOID)pMsgStru;
    NAS_EMM_TAU_LOG_NORM("NAS_EMM_MsRegSsRegAttemptUpdateMmMsgBearerStatusReq entered.");
    TLPS_PRINT2LAYER_INFO(NAS_EMM_MsRegSsRegAttemptUpdateMmMsgBearerStatusReq_ENUM,LNAS_ENTRY);

    /* ��������ָ��������*/
    if(NAS_EMM_NULL_PTR                 == pMsgStru)
    {
       NAS_EMM_TAU_LOG_ERR("NAS_EMM_MsRegSsRegAttemptUpdateMmMsgBearerStatusReq:NULL PTR.");
       TLPS_PRINT2LAYER_ERROR(NAS_EMM_MsRegSsRegAttemptUpdateMmMsgBearerStatusReq_ENUM,LNAS_NULL_PTR);
       return NAS_LMM_MSG_DISCARD;
    }

    /* ����ϴ�TAUû�гɹ������޸�TAU����ԭ�򣬵ȴ�T3411����T3402��ʱ*/
    if ((NAS_LMM_TIMER_RUNNING == NAS_LMM_IsPtlTimerRunning(TI_NAS_EMM_PTL_T3402))
        ||(NAS_LMM_TIMER_RUNNING == NAS_LMM_IsPtlTimerRunning(TI_NAS_EMM_PTL_T3411)))
    {
        /*NAS_EMM_TAU_SaveEmmTAUStartCause(NAS_EMM_TAU_START_CAUSE_BEARER_CNTXT_LOCAL_CHANGED);*/
        NAS_EMM_TAU_SaveEmmTAUStartCause(NAS_EMM_TAU_START_CAUSE_OTHERS);
    }
    else
    {
        /* �ж��Ƿ��������Pending*/
        NAS_EMM_TAU_IsUplinkPending();

        /* ����TAU*/
        /*NAS_EMM_TAU_SaveEmmTAUStartCause(NAS_EMM_TAU_START_CAUSE_BEARER_CNTXT_LOCAL_CHANGED);*/
        NAS_EMM_TAU_SaveEmmTAUStartCause(NAS_EMM_TAU_START_CAUSE_OTHERS);
        /* �������TAU����ԭ�� */
        NAS_EMM_TAU_StartTAUREQ(NAS_LMM_OM_TAU_START_TYPE_BEARER_STATUS_CHANGEED);
    }

    return NAS_LMM_MSG_HANDLED;
}


/*****************************************************************************
 Function Name   : NAS_EMM_MsTauInitSsWaitCnCnfMsgBearerStatusReq
 Description     : TauInit.WtCnTauCnf״̬��ESM�����޸��˳��������ģ���ֹ��ǰ���̣�
                   ���´���TAU.
 Input           : None
 Output          : None
 Return          : VOS_UINT32

 History         :
    1.zhengjunyan 00148421  2011-1-12  Draft Enact
    2.lihong00150010        2012-12-14 Modify:Emergency

*****************************************************************************/
VOS_UINT32  NAS_EMM_MsTauInitSsWaitCnCnfMsgBearerStatusReq(
                                                    VOS_UINT32  ulMsgId,
                                                    VOS_VOID   *pMsgStru )
{
    VOS_UINT32                          ulRslt = NAS_EMM_FAIL;

    (VOS_VOID)(ulMsgId);
    (VOS_VOID)(pMsgStru);
    NAS_EMM_TAU_LOG_NORM("NAS_EMM_MsTauInitSsWaitCnCnfMsgBearerStatusReq entered.");
    TLPS_PRINT2LAYER_INFO(NAS_EMM_MsTauInitSsWaitCnCnfMsgBearerStatusReq_ENUM,LNAS_ENTRY);

    /* ��������ָ��������, ״̬ƥ����,����ƥ��,�˳�*/
    ulRslt = NAS_EMM_TAU_CHKFSMStateMsgp(EMM_MS_TAU_INIT,EMM_SS_TAU_WAIT_CN_TAU_CNF,pMsgStru);
    if ( NAS_EMM_SUCC != ulRslt )
    {
        NAS_EMM_TAU_LOG_WARN("NAS_EMM_TAUSER_CHKFSMStateMsgp ERROR !!");
        TLPS_PRINT2LAYER_WARNING(NAS_EMM_MsTauInitSsWaitCnCnfMsgBearerStatusReq_ENUM,LNAS_ERROR);
        return NAS_LMM_MSG_DISCARD;
    }

     /*��ֹ��ǰTAU����*/
    NAS_LMM_StopStateTimer(TI_NAS_EMM_STATE_TAU_T3430);

    #if (FEATURE_ON == FEATURE_DSDS)
    /*����end notify��Ϣ��RRC��֪ͨRRC�ͷ���Դ*/
    NAS_EMM_TAU_SendRrcDsdsEndNotify();
    #endif

#if (FEATURE_MULTI_MODEM == FEATURE_ON)
    NAS_EMM_SendMtcTAUEndType();
#endif

    NAS_EMM_TAU_SaveEmmTAUAttemptCnt(NAS_EMM_TAU_ATTEMPT_CNT_ZERO);

    NAS_EMM_TAU_ProcAbnormal();
    if (NAS_EMM_TAU_START_CAUSE_ESM_EMC_PDN_REQ == NAS_EMM_TAU_GetEmmTAUStartCause())
    {
        NAS_EMM_TAU_LOG_INFO("NAS_EMM_MsTauInitSsWaitCNCnfMsgSysinfo:CAUSE_ESM_EMC_PDN_REQ");
        TLPS_PRINT2LAYER_INFO(NAS_EMM_MsTauInitSsWaitCnCnfMsgBearerStatusReq_ENUM,LNAS_FUNCTION_LABEL1);

        NAS_EMM_EmcPndReqTauAbnormalCommProc(   NAS_EMM_MmcSendTauActionResultIndFailWithPara,
                                                (VOS_VOID*)NAS_EMM_NULL_PTR,
                                                EMM_SS_DEREG_NORMAL_SERVICE);
    }
    else
    {
        /* �ϱ�TAU����ڳ�ͻ������ִ�� */
        NAS_EMM_TAU_RelIndCollisionProc(NAS_EMM_MmcSendTauActionResultIndFailWithPara,
                             (VOS_VOID*)NAS_EMM_NULL_PTR);
    }
    /*��MRRC����NAS_EMM_MRRC_REL_REQ��Ϣ*/
    NAS_EMM_RelReq(NAS_LMM_NOT_BARRED);

    return  NAS_LMM_MSG_HANDLED;
}
/*****************************************************************************
 Function Name   : NAS_EMM_MsRegSsNoVailableCellMsgT3412Exp
 Description     : REG+NO_VAILABLE_CELL״̬���յ�T3412��ʱ����ʱ
 Input           : None
 Output          : None
 Return          : VOS_UINT32

 History         :
    1.    lihong  00150010      2011-08-26  Draft Enact

*****************************************************************************/
VOS_UINT32  NAS_EMM_MsRegSsNoVailableCellMsgT3412Exp
(
    VOS_UINT32                          ulMsgId,
    VOS_VOID                     *pMsgStru
)
{
    (VOS_VOID)ulMsgId;

    /* ��ӡ����ú���*/
    NAS_EMM_TAU_LOG_INFO( "NAS_EMM_MsRegSsNoVailableCellMsgT3412Exp is entered.");
    TLPS_PRINT2LAYER_INFO(NAS_EMM_MsRegSsNoVailableCellMsgT3412Exp_ENUM,LNAS_ENTRY);

    /* ��������ָ��������*/
    if(NAS_EMM_NULL_PTR == pMsgStru)
    {
        NAS_EMM_TAU_LOG_ERR("NAS_EMM_MsRegSsNoVailableCellMsgT3412Exp PARA NULL!!");
        TLPS_PRINT2LAYER_ERROR(NAS_EMM_MsRegSsNoVailableCellMsgT3412Exp_ENUM,LNAS_NULL_PTR);
        return NAS_LMM_MSG_DISCARD;
    }

    /* Э��24301 5.3.5�½���������REG+NO_AVAILABLE_CELL״̬�£�T3412��ʱ�����
       ISR���������T3423��ʱ��;���ISRû�м�����
       ��ǰ������ע��ɹ�����ص�REG+NORMAL_SERVICE̬�󣬷�������TAU��TAU����Ϊ
       combined TA/LA updating with IMSI attach�������������ע��ɹ�������������TAU */

    /*��������TAU��������ʱ��־*/
    NAS_LMM_SetEmmInfoT3412ExpCtrl(NAS_EMM_T3412_EXP_YES_REG_NO_AVALABLE_CELL);

    if (MMC_LMM_TIN_RAT_RELATED_TMSI == NAS_EMM_GetTinType())
    {
        /*������ʱ��T3423*/
        NAS_LMM_StartPtlTimer(TI_NAS_EMM_PTL_T3423);

        /*֪ͨGUģT3423����*/
        NAS_EMM_SendTimerStateNotify(TI_NAS_EMM_PTL_T3423, LMM_MMC_TIMER_START);

    }
    return NAS_LMM_MSG_HANDLED;

}

VOS_UINT32  NAS_EMM_MsRegSsAnyStatusMsgT3412Exp( VOS_UINT32  ulMsgId,
                                                   VOS_VOID   *pMsgStru )
{
    (VOS_VOID)ulMsgId;

    /* ��ӡ����ú���*/
    NAS_EMM_TAU_LOG_INFO( "NAS_EMM_MsRegSsAnyStatusMsgT3412Exp is entered.");
    TLPS_PRINT2LAYER_INFO(NAS_EMM_MsRegSsAnyStatusMsgT3412Exp_ENUM,LNAS_ENTRY);

    /* ��������ָ��������*/
    if(NAS_EMM_NULL_PTR == pMsgStru)
    {
        NAS_EMM_TAU_LOG_ERR("NAS_EMM_MsRegSsAnyStatusMsgT3412Exp PARA NULL!!");
        TLPS_PRINT2LAYER_ERROR(NAS_EMM_MsRegSsAnyStatusMsgT3412Exp_ENUM,LNAS_NULL_PTR);
        return NAS_LMM_MSG_DISCARD;
    }

    /* ���GCF9.2.3.1.5 ������ʱ���� ,UE����,MMC�������� ,�����ڼ�T3412��ʱ,�����TAU������combined TAU with IMSI���ͣ�
       ������������,��������������,UE������������פ��,�����޷�ת��no cell̬��
       ���GCF���ԣ��ó���TAU��ʱ����ʱ��־��ΪREG_NO_AVALABLE_CELL */
    if((PS_SUCC == LPS_OM_IsTestMode())
        &&(EMM_MS_REG == NAS_LMM_GetEmmCurFsmMS())
        &&(EMM_SS_REG_LIMITED_SERVICE == NAS_LMM_GetEmmCurFsmSS()))
    {
        /*��������TAU��������ʱ��־*/
        NAS_LMM_SetEmmInfoT3412ExpCtrl(NAS_EMM_T3412_EXP_YES_REG_NO_AVALABLE_CELL);
    }
    else
    {
        /*��������TAU��������ʱ��־*/
        NAS_LMM_SetEmmInfoT3412ExpCtrl(NAS_EMM_T3412_EXP_YES_OTHER_STATE);
    }


    if (MMC_LMM_TIN_RAT_RELATED_TMSI == NAS_EMM_GetTinType())
    {
        /*������ʱ��T3423*/
        NAS_LMM_StartPtlTimer(TI_NAS_EMM_PTL_T3423);

        /*֪ͨGUģT3423����*/
        NAS_EMM_SendTimerStateNotify(TI_NAS_EMM_PTL_T3423, LMM_MMC_TIMER_START);

    }
    return NAS_LMM_MSG_HANDLED;

}


VOS_UINT32  NAS_EMM_MsRegSsSomeStatusMsgIntraTauReq( VOS_UINT32  ulMsgId,
                                                   VOS_VOID   *pMsgStru )
{
    NAS_LMM_INTRA_TAU_REQ_STRU         *pIntraTauReq = NAS_EMM_NULL_PTR;
    (VOS_VOID)ulMsgId;
    pIntraTauReq    = (NAS_LMM_INTRA_TAU_REQ_STRU*)pMsgStru;

    /* ��ӡ����ú���*/
    NAS_EMM_TAU_LOG_INFO(               "NAS_EMM_MsRegSsSomeStatusMsgIntraTauReq is entered.");
    TLPS_PRINT2LAYER_INFO(NAS_EMM_MsRegSsSomeStatusMsgIntraTauReq_ENUM,LNAS_ENTRY);

    /* ��������ָ��������*/
    if(NAS_EMM_NULL_PTR                 == pMsgStru)
    {
        NAS_EMM_TAU_LOG_ERR(            "NAS_EMM_MsRegSsSomeStatusMsgIntraTauReq PARA NULL!!");
        TLPS_PRINT2LAYER_ERROR(NAS_EMM_MsRegSsSomeStatusMsgIntraTauReq_ENUM,LNAS_NULL_PTR);
        return NAS_LMM_MSG_DISCARD;
    }

    /*����DRX��NetCapability�ı��־*/
    if(NAS_LMM_INTRA_TAU_TYPE_PARA_CHANGE == pIntraTauReq->enIntraTauType)
    {
        NAS_LMM_SetEmmInfoDrxNetCapChange( NAS_EMM_YES);
    }

    return NAS_LMM_MSG_HANDLED;
}

/*****************************************************************************
 Function Name   : NAS_EMM_MsRegSsSomeStateMsgBearerStatusReq
 Description     : Reg.Limite_Service
                   Reg.No_Cell_Available
                   Reg.Plmn_Search
                   ������״̬�£�ESM�����޸ĳ��������ģ���¼��־
 Input           : None
 Output          : None
 Return          : VOS_UINT32

 History         :
    1.zhengjunyan 00148421    2011-1-11  Draft Enact

*****************************************************************************/
VOS_UINT32  NAS_EMM_MsRegSsSomeStateMsgBearerStatusReq( VOS_UINT32  ulMsgId,
                                                   VOS_VOID   *pMsgStru )
{
    NAS_EMM_TAU_LOG_INFO("NAS_EMM_MsRegSsSomeStateMsgBearerStatusReq entered.");
    TLPS_PRINT2LAYER_INFO(NAS_EMM_MsRegSsSomeStateMsgBearerStatusReq_ENUM,LNAS_ENTRY);
    (VOS_VOID)ulMsgId;

    /* ��������ָ��������*/
    if(NAS_EMM_NULL_PTR == pMsgStru)
    {
        NAS_EMM_TAU_LOG_ERR("NAS_EMM_MsRegSsSomeStateMsgBearerStatusReq:NULL PTR.");
        TLPS_PRINT2LAYER_ERROR(NAS_EMM_MsRegSsSomeStateMsgBearerStatusReq_ENUM,LNAS_NULL_PTR);
        return NAS_LMM_MSG_DISCARD;
    }

    /* ���ó��������ı仯*/
    NAS_EMM_SetEpsContextStatusChange(NAS_EMM_EPS_BEARER_STATUS_CHANGEED);

    return NAS_LMM_MSG_HANDLED;
}
/*****************************************************************************
 Function Name   : NAS_EMM_MsRegSsLimitedSrvMsgRrcRelInd
 Description     : ��Reg.LimitedService״̬���յ�LRRC_LMM_REL_IND��Ϣ�Ĵ���
 Input           : None
 Output          : None
 Return          : VOS_UINT32

 History         :
    1.leili 00132387      2011-9-24  Draft Enact
    2.lihong00150010      2012-12-19 Modify:Emergency

*****************************************************************************/
VOS_UINT32  NAS_EMM_MsRegSsLimitedSrvMsgRrcRelInd
(
    VOS_UINT32                              ulMsgId,
    VOS_VOID                                *pMsgStru
)
{
    LRRC_LMM_REL_IND_STRU              *pMsgRrcRelInd  = (LRRC_LMM_REL_IND_STRU *)pMsgStru;
    VOS_UINT32                          ulCause;

    (VOS_VOID)ulMsgId;

    NAS_EMM_TAU_LOG_NORM("NAS_EMM_MsRegSsLimitedSrvMsgRrcRelInd is entered.");
    TLPS_PRINT2LAYER_INFO(NAS_EMM_MsRegSsLimitedSrvMsgRrcRelInd_ENUM,LNAS_ENTRY);

    /*���ԭ��ֵ*/
    ulCause = pMsgRrcRelInd->enRelCause;

    NAS_EMM_MsRegSsNmlSrvProcMsgRrcRelInd(ulCause);

    return NAS_LMM_MSG_HANDLED;
}
/*****************************************************************************
 Function Name   : NAS_LMM_PreProcIntraTauReq
 Description     : ����NAS_LMM_INTRA_TAU_TYPE_UPDATE_MM���͵��ڲ�TAU����������
                   ���ڲ�TAU��״̬������
 Input           : None
 Output          : None
 Return          : VOS_UINT32

 History         :
    1.lihong00150010      2011-11-16  Draft Enact
*****************************************************************************/
VOS_UINT32  NAS_LMM_PreProcIntraTauReq
(
    MsgBlock                           *pMsg
)
{
    NAS_LMM_INTRA_TAU_REQ_STRU         *pEmmIntraTauReq = VOS_NULL_PTR;
    VOS_UINT32                          ulCurEmmStat;

    NAS_EMM_TAU_LOG_INFO("NAS_LMM_PreProcIntraTauReq is enter!");
    TLPS_PRINT2LAYER_INFO(NAS_LMM_PreProcIntraTauReq_ENUM,LNAS_ENTRY);

    pEmmIntraTauReq                     = (VOS_VOID*)pMsg;
    ulCurEmmStat = NAS_LMM_PUB_COMP_EMMSTATE(NAS_EMM_CUR_MAIN_STAT,
                                            NAS_EMM_CUR_SUB_STAT);

    /*
    �Ķ�����: ��ϵͳTAU��bar����bar֮����TAU��ʱ�����������
    ����TAU�ĳ�������һ��TAU����ԭ��: CSFB��G����LAU���ص�LȻ��
    ����Ϊps only��Ȼ����reg-update_mm״̬��ʱ�����ڲ�TAU��
    ��Ԥ������ʱ��ᷢTAU. �ڶ���TAU����ԭ��:TAU��bar֮���յ�
    ��bar֮����Ҫ��������TAU��
    ��θĶ�: ����ڶ���TAU��ʱ��������ʱ�򣬸����ȼ�����
    ���ڲ�TAU��Ϣ���ȵ���̬��ʱ���ٷ���
    */
    if((NAS_EMM_CONN_RELEASING == NAS_EMM_GetConnState())
        || (NAS_LMM_TIMER_RUNNING == NAS_LMM_IsStaTimerRunning(TI_NAS_EMM_STATE_T3440))
        || (NAS_LMM_TIMER_RUNNING == NAS_LMM_IsPtlTimerRunning(TI_NAS_EMM_PTL_REATTACH_DELAY))
        || (NAS_EMM_CONN_ESTING == NAS_EMM_GetConnState()))
    {
        NAS_EMM_TAU_LOG_INFO("NAS_LMM_PreProcIntraTauReq: REL_INIT or EST_INIT is high priority store");
        TLPS_PRINT2LAYER_INFO(NAS_LMM_PreProcIntraTauReq_ENUM,LNAS_FUNCTION_LABEL1);
        return NAS_LMM_STORE_HIGH_PRIO_MSG;
    }

    if (EMM_MS_TAU_INIT == NAS_LMM_GetEmmCurFsmMS())
    {
        NAS_EMM_TAU_LOG_INFO("NAS_LMM_PreProcIntraTauReq: EMM_MS_TAU_INIT is discard");
        TLPS_PRINT2LAYER_INFO(NAS_LMM_PreProcIntraTauReq_ENUM,LNAS_FUNCTION_LABEL2);
        return NAS_LMM_MSG_HANDLED;
    }

    /* Ԥ������ֻ����UPDATE_MM���͵��ڲ�TAU */
    /*ֻ����reg+normal_service�Լ�reg+attempt_updata_mm��ʱ��ŷ���TAU*/
    if ((NAS_LMM_INTRA_TAU_TYPE_UPDATE_MM == pEmmIntraTauReq->enIntraTauType) &&
         ((ulCurEmmStat == NAS_LMM_PUB_COMP_EMMSTATE(EMM_MS_REG, EMM_SS_REG_NORMAL_SERVICE)) ||
          (ulCurEmmStat == NAS_LMM_PUB_COMP_EMMSTATE(EMM_MS_REG, EMM_SS_REG_ATTEMPTING_TO_UPDATE_MM))))
    {
        /* ���UPDATE_MM��ʶ */
        /*NAS_LMM_SetEmmInfoUpdateMmFlag(NAS_EMM_UPDATE_MM_FLAG_INVALID);*/

        if (NAS_LMM_TIMER_RUNNING == NAS_LMM_IsPtlTimerRunning(TI_NAS_EMM_PTL_T3411))
        {
            NAS_EMM_TAU_LOG_NORM("NAS_LMM_PreProcIntraTauReq:3411 is running");
            TLPS_PRINT2LAYER_INFO(NAS_LMM_PreProcIntraTauReq_ENUM,LNAS_EMM_T3411_RUNNING);

            /*�޸�״̬��������״̬REG��״̬REG_ATTEMPTING_TO_UPDATE_MM*/
            NAS_EMM_AdStateConvert(         EMM_MS_REG,
                                            EMM_SS_REG_ATTEMPTING_TO_UPDATE_MM,
                                            TI_NAS_EMM_STATE_NO_TIMER);
        }
        else if (NAS_LMM_TIMER_RUNNING == NAS_LMM_IsPtlTimerRunning(TI_NAS_EMM_PTL_T3402))
        {
            NAS_EMM_TAU_LOG_NORM("NAS_LMM_PreProcIntraTauReq:3402 is running");
            TLPS_PRINT2LAYER_INFO(NAS_LMM_PreProcIntraTauReq_ENUM,LNAS_EMM_T3402_RUNNING);

            /*�޸�״̬��������״̬REG��״̬REG_ATTEMPTING_TO_UPDATE_MM*/
            NAS_EMM_AdStateConvert(         EMM_MS_REG,
                                            EMM_SS_REG_ATTEMPTING_TO_UPDATE_MM,
                                            TI_NAS_EMM_STATE_NO_TIMER);
        }
        else
        {
            NAS_EMM_TAU_LOG_NORM("NAS_LMM_PreProcIntraTauReq:3411 and 3402 is not running");
            TLPS_PRINT2LAYER_INFO(NAS_LMM_PreProcIntraTauReq_ENUM,LNAS_FUNCTION_LABEL3);

            /* �ж��Ƿ��������Pending*/
            NAS_EMM_TAU_IsUplinkPending();

            /*����TAU Procedure*/
            /*NAS_EMM_TAU_SaveEmmTAUStartCause(NAS_EMM_TAU_START_CAUSE_IMSI_ATTACH);*/
            NAS_EMM_TAU_SaveEmmTAUStartCause(NAS_EMM_TAU_START_CAUSE_OTHERS);
            /* �������TAU����ԭ�� */
            NAS_EMM_TAU_StartTAUREQ(NAS_LMM_OM_TAU_START_TYPE_OTHERS);
        }

        return NAS_LMM_MSG_HANDLED;
    }

    return NAS_LMM_MSG_DISCARD;
}
/*****************************************************************************
 Function Name   : NAS_LMM_SendMmcUtranModeCnf
 Description     : ��MMC����ID_LMM_MMC_UTRAN_MODE_CNF��Ϣ
 Input           : VOS_VOID
 Output          : None
 Return          : NAS_EMM_SEND_RRC_OK   ���ͳɹ�
                   NAS_EMM_SEND_RRC_ERR  ����ʧ��
 History         :
    1.sunjitan 00193151      2012-07-21  Draft Enact
*****************************************************************************/
VOS_UINT32  NAS_LMM_SendMmcUtranModeCnf(VOS_VOID)
{
    LMM_MMC_UTRAN_MODE_CNF_STRU  *pstLmmUtranModCnf = NAS_EMM_NULL_PTR;

    /*�����ڴ�*/
    /* ����MMC�ڲ���Ϣ */
    pstLmmUtranModCnf  = (VOS_VOID*)NAS_LMM_GetLmmMmcMsgBuf(sizeof(LMM_MMC_UTRAN_MODE_CNF_STRU));
    if(NAS_EMM_NULL_PTR == pstLmmUtranModCnf)
    {
        NAS_EMM_PUBU_LOG_WARN("NAS_LMM_SendMmcUtranModeCnf: MSG ALLOC ERR!");
        TLPS_PRINT2LAYER_WARNING(NAS_LMM_SendMmcUtranModeCnf_ENUM,LNAS_NULL_PTR);
        return NAS_EMM_SEND_MMC_ERR;
    }

    /*������뵽����Ϣ�ռ�*/
    NAS_LMM_MEM_SET_S(  pstLmmUtranModCnf,
                        sizeof(LMM_MMC_UTRAN_MODE_CNF_STRU),
                        0,
                        sizeof(LMM_MMC_UTRAN_MODE_CNF_STRU));

    /* ����MMC��DOPRAͷ */
    EMM_PUBU_COMP_MMC_MSG_HEADER(pstLmmUtranModCnf,
                                 sizeof(LMM_MMC_UTRAN_MODE_CNF_STRU) -
                                 EMM_LEN_VOS_MSG_HEADER);

    /* �����ϢID */
    pstLmmUtranModCnf->ulMsgId       = ID_LMM_MMC_UTRAN_MODE_CNF;

    /* ����LMM_MMC_UTRAN_MODE_CNF��Ϣ */
    NAS_LMM_SendLmmMmcMsg(pstLmmUtranModCnf);

    return NAS_EMM_SEND_MMC_OK;
}

/*****************************************************************************
 Function Name   : NAS_LMM_SendRrcUtranModeNotifyReq
 Description     : ��RRC����ID_LRRC_LMM_UTRAN_MODE_NTF��Ϣ
 Input           : RRC_NAS_UTRAN_MODE_ENUM_UINT8
 Output          : None
 Return          : NAS_EMM_SEND_RRC_OK   ���ͳɹ�
                   NAS_EMM_SEND_RRC_ERR  ����ʧ��
 History         :
    1.sunjitan 00193151      2012-07-21  Draft Enact
*****************************************************************************/
VOS_UINT32  NAS_LMM_SendRrcUtranModeReq
(
    LRRC_LNAS_UTRAN_MODE_ENUM_UINT8       enUtranMode
)
{
    LRRC_LMM_UTRAN_MODE_REQ_STRU  *pstLmmUtranModReq = NAS_EMM_NULL_PTR;

    /*�����ڴ�*/
    pstLmmUtranModReq = (VOS_VOID *)NAS_LMM_ALLOC_MSG(sizeof(LRRC_LMM_UTRAN_MODE_REQ_STRU));
    if(NAS_EMM_NULL_PTR == pstLmmUtranModReq)
    {
        return NAS_EMM_SEND_RRC_ERR;
    }

    /*������뵽����Ϣ�ռ�*/
    NAS_LMM_MEM_SET_S(  pstLmmUtranModReq,
                        sizeof(LRRC_LMM_UTRAN_MODE_REQ_STRU),
                        0,
                        sizeof(LRRC_LMM_UTRAN_MODE_REQ_STRU));

    /*���VOS��Ϣͷ*/
    NAS_EMM_SET_RRC_MSG_HEADER(pstLmmUtranModReq, sizeof(LRRC_LMM_UTRAN_MODE_REQ_STRU)-VOS_MSG_HEAD_LENGTH);

    /* �����ϢID */
    pstLmmUtranModReq->enMsgId       = ID_LRRC_LMM_UTRAN_MODE_REQ;

    /* �����Ϣ�� */
    pstLmmUtranModReq->enUtranMode   = enUtranMode;

    /* ����ID_LRRC_LMM_UTRAN_MODE_NTF */
    NAS_LMM_SEND_MSG(pstLmmUtranModReq);

    return NAS_EMM_SEND_RRC_OK;
}
/*lint +e961*/
/*lint +e960*/


/*****************************************************************************
 Function Name   : NAS_LMM_PreProcUtranModeNotifyReq
 Description     :  ��MMC�������޸�Utran������ָʾ����Ԥ����
 Input           : None
 Output          : None
 Return          : VOS_UINT32

 History         :
    1.sunjitan 00193151      2012-07-21  Draft Enact
*****************************************************************************/
VOS_UINT32  NAS_LMM_PreProcMmcUtranModeReq( MsgBlock  *pMsg )
{
    MMC_LMM_UTRAN_MODE_REQ_STRU     *pstMmcUtranModReq = NAS_EMM_NULL_PTR;

    NAS_LMM_PUBM_LOG_INFO("NAS_LMM_PreProcUtranModeReq is entered.");
    TLPS_PRINT2LAYER_INFO(NAS_LMM_PreProcMmcUtranModeReq_ENUM,LNAS_ENTRY);

    pstMmcUtranModReq = (MMC_LMM_UTRAN_MODE_REQ_STRU *)(VOS_VOID *)pMsg;

    if ( NAS_EMM_NULL_PTR == pstMmcUtranModReq )
    {
        NAS_EMM_PUBU_LOG_ERR("NAS_LMM_PreProcUtranModeReq: NULL  Msg!");
        TLPS_PRINT2LAYER_ERROR(NAS_LMM_PreProcMmcUtranModeReq_ENUM,LNAS_NULL_PTR);
        return NAS_LMM_MSG_HANDLED;
    }

    /* ֻ�п�����ɻ��յ�ϵͳ��ϢMMC�ſ����·�����˿��ػ��������յ����� */
    if ( EMM_MS_NULL == NAS_EMM_CUR_MAIN_STAT )
    {
        NAS_LMM_PUBM_LOG_INFO("NAS_LMM_PreProcUtranModeReq : Power_on or power_off, discard message!");
        TLPS_PRINT2LAYER_INFO(NAS_LMM_PreProcMmcUtranModeReq_ENUM,LNAS_FUNCTION_LABEL1);
        return NAS_LMM_MSG_HANDLED;
    }

    /* �յ���ģʽ������ͷǷ������� */
    if ( MMC_LMM_UTRAN_MODE_BUTT <= pstMmcUtranModReq->enUtranMode )
    {
        NAS_LMM_PUBM_LOG_ERR("NAS_LMM_PreProcUtranModeReq: ERROR: Utran mode is invalid.");
        TLPS_PRINT2LAYER_ERROR(NAS_LMM_PreProcMmcUtranModeReq_ENUM,LNAS_FUNCTION_LABEL2);
        return NAS_LMM_MSG_HANDLED;
    }

    /*sunbing 49683 2013-10-14 VoLTE begin*/
    /*��¼UTRANģʽ����classmark3����ʱ��Ҫ*/
    NAS_LMM_SetEmmInfoUtranMode(pstMmcUtranModReq->enUtranMode);
    /*sunbing 49683 2013-10-14 VoLTE end*/

    /* ��RRC��ϵͳ����������Ϣ*/
    (VOS_VOID)NAS_LMM_SendRrcUtranModeReq(pstMmcUtranModReq->enUtranMode);

    return NAS_LMM_MSG_HANDLED;
}

/*****************************************************************************
 Function Name   : NAS_LMM_PreProcRrcUtranModeNotifyCnf
 Description     :
 Input           : None
 Output          : None
 Return          : VOS_UINT32
 History         :
    1.sunjitan 00193151     2012-07-21  Draft Enact
    2.lihong 00150010       2012-12-22  Modify:DTS2012121306127��ϵͳ��Ϣ���Ʊ��
*****************************************************************************/
VOS_UINT32  NAS_LMM_PreProcRrcUtranModeCnf( MsgBlock  *pMsg )
{
    /*VOS_UINT32                            ulRslt = NAS_LMM_MSG_DISCARD;*/
    LRRC_LMM_UTRAN_MODE_CNF_STRU  *pstRrcUtranModCnf = NAS_EMM_NULL_PTR;

    NAS_LMM_PUBM_LOG_INFO("NAS_LMM_PreProcRrcUtranModeCnf  is entered.");
    TLPS_PRINT2LAYER_INFO(NAS_LMM_PreProcRrcUtranModeCnf_ENUM,LNAS_ENTRY);

    pstRrcUtranModCnf = (LRRC_LMM_UTRAN_MODE_CNF_STRU*)(VOS_VOID*)pMsg;

    if (NAS_EMM_NULL_PTR == pstRrcUtranModCnf)
    {
        NAS_LMM_PUBM_LOG_ERR("NAS_LMM_PreProcRrcUtranModeCnf: NULL  Msg!");
        TLPS_PRINT2LAYER_ERROR(NAS_LMM_PreProcRrcUtranModeCnf_ENUM,LNAS_ERROR);
        return NAS_LMM_MSG_HANDLED;
    }

    /* Utran����δ�����仯 */
    if (LRRC_LNAS_UE_CAPABILITY_CHANGE != pstRrcUtranModCnf->enCapChangeInd)
    {
        NAS_LMM_PUBM_LOG_INFO("NAS_LMM_PreProcRrcUtranModeNotifyCnf: Utran mode isn't changed.");
        TLPS_PRINT2LAYER_INFO(NAS_LMM_PreProcRrcUtranModeCnf_ENUM,LNAS_FUNCTION_LABEL1);

        /* ��MMC�سɹ� */
        (VOS_VOID)NAS_LMM_SendMmcUtranModeCnf();
        return NAS_LMM_MSG_HANDLED;
    }

    /* Utran���������仯 */
    /* ��������ģ��ֻҪ���Ƿ�ע��̬�������� */
    if (NAS_EMM_NO == NAS_EMM_IsDeregState())
    {
        /* ֻ�е�ǰ����LTE���������GU�������ʱ�ż�¼����ֹ���LTE��� */
        if ( NAS_LMM_UE_RADIO_CAP_NOT_CHG == NAS_LMM_GetEmmInfoUeRadioCapChgFlag() )
        {
            /* ��¼Utran�����ı仯���*/
            NAS_LMM_SetEmmInfoUeRadioCapChgFlag(NAS_LMM_UE_RADIO_CAP_GU_CHG);
        }
    }


    /* �����DEREG̬�򲻴���*/
    /* ��MMC�سɹ� */
    (VOS_VOID)NAS_LMM_SendMmcUtranModeCnf();

    return NAS_LMM_MSG_HANDLED;
}

/*****************************************************************************
 Function Name   : NAS_EMM_IsIntraHoIgnoreForbSysInfo
 Description     : ����ϵͳ���л�������С��,���Ա���:������LС��A��B(A�����Բ�)
                    UE��С��B��פ��������MMEĳЩ�쳣,��UE�·�ԭ��ֵ#15����MMEδ��
                    TA���뱻���б���(δ�汻����ֻ����ʱ����)����UE�յ�#15ԭ��ֵ,
                    ����������פ����AС����֮��������UE�л���BС�������л�ʱLRRC
                    �����ж�С���Ƿ񱻽���LMM�յ�ϵͳ��Ϣ����BС�����յ���#15ԭ
                    ��ֵ,LMM�����ͷŽ������Ʒ���̬��LRRC�ͷź���С��A��פ�����Ӷ�����ƹ���л�
 Input           : None
 Output          : None
 Return          : VOS_UINT32

 History         :
    leixiantiao 00258641 2015-6-3  ����
*****************************************************************************/
VOS_UINT32 NAS_EMM_IsIntraHoIgnoreForbSysInfo(VOS_VOID)
{
    /* �ǲ��Կ�,NV���ش��ҵ�ǰ����״̬Ϊ����̬ʱ���Ա��� */
    if((PS_TRUE == g_ulIntraHoIgnoreForbidTaFlag)
        &&(PS_SUCC != LPS_OM_IsTestMode())
        &&(NAS_EMM_CONN_DATA == NAS_EMM_GetConnState()))
    {
        return NAS_EMM_YES;
    }
    return NAS_EMM_NO;
}

#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif



