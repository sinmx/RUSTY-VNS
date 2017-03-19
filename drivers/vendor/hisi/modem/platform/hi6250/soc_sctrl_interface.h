/******************************************************************************

                 ��Ȩ���� (C), 2001-2012, ��Ϊ�������޹�˾

 ******************************************************************************
  �� �� ��   : soc_sctrl_interface.h
  �� �� ��   : ����
  ��    ��   : Excel2Code
  ��������   : 2013-01-25 14:01:14
  ����޸�   :
  ��������   : �ӿ�ͷ�ļ�
  �����б�   :
  �޸���ʷ   :
  1.��    ��   : 2013��1��25��
    ��    ��   : x59651
    �޸�����   : ����SFTĿ¼��ͬ���ļ���д��Ϊ�˲�Ʒ����֧����

******************************************************************************/

/*****************************************************************************
  1 ����ͷ�ļ�����
*****************************************************************************/

#ifndef __SOC_SCTRL_INTERFACE_H__
#define __SOC_SCTRL_INTERFACE_H__

#ifdef __cplusplus
    #if __cplusplus
        extern "C" {
    #endif
#endif


/*****************************************************************************
  2 �궨��
*****************************************************************************/

/****************************************************************************
                     (1/1) register_define
 ****************************************************************************/

/* ʱ��ʹ�ܿ��� */
#define SOC_SCTRL_MDM_CRG_PERIPH_CLKEN_ADDR(base)       ((base) + (0x000))

/* ʱ�ӹرտ��� */
#define SOC_SCTRL_MDM_CRG_PERIPH_CLKDIS_ADDR(base)      ((base) + (0x004))

/* ʱ�ӿ���״̬ */
#define SOC_SCTRL_MDM_CRG_PERIPH_CLKSTAT_ADDR(base)     ((base) + (0x008))

/* �Ĵ���˵����������ƼĴ���1������CICOMģʽѡ��Ϊ��FPGA��SFT��֧һ�£�ʹ��ͬ��������
   λ����UNION�ṹ:  SOC_SCtrl_SC_PERIPH_CTRL1_UNION */
#define SOC_SCTRL_SC_PERIPH_CTRL4_ADDR(base)            ((base) + (0x410))

/*****************************************************************************
  3 ö�ٶ���
*****************************************************************************/
/*****************************************************************************
 �ṹ��    : SOC_PERICTRL_CICOM0_MOD_SEL_UNION
 �ṹ˵��  : CICOM0_MOD_SEL �Ĵ����ṹ���塣��ַƫ����:0x410����ֵ:0x00000000������:32
 �Ĵ���˵��: 
*****************************************************************************/
typedef union
{
    unsigned int      value;
    struct
    {
        unsigned int  gucicom0sel_mode : 1;  /* bit[0]   : CICOM0ģʽ����
                                                           0��WCDMA�ӽ���ģʽ
                                                           1��GSM�ӽ���ģʽ */  
        unsigned int  gucicom1sel_mode : 1;  /* bit[1]   : CICOM1ģʽ����
                                                           0��WCDMA�ӽ���ģʽ
                                                           1��GSM�ӽ���ģʽ */ 
        unsigned int  reserved         : 30; /* bit[2-31]: ���� */
    } reg;
} SOC_SCtrl_SC_PERIPH_CTRL1_UNION;
#define SOC_SCtrl_SC_PERIPH_CTRL1_cicomsel_mode_START                   (0)
#define SOC_SCtrl_SC_PERIPH_CTRL1_cicomsel_mode_END                     (0)


/*****************************************************************************
  4 ��Ϣͷ����
*****************************************************************************/


/*****************************************************************************
  5 ��Ϣ����
*****************************************************************************/



/*****************************************************************************
  6 STRUCT����
*****************************************************************************/



/*****************************************************************************
  7 UNION����
*****************************************************************************/




/*****************************************************************************
  8 OTHERS����
*****************************************************************************/



/*****************************************************************************
  9 ȫ�ֱ�������
*****************************************************************************/


/*****************************************************************************
  10 ��������
*****************************************************************************/


#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif

#endif /* end of soc_sctrl_interface.h */