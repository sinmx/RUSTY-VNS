/******************************************************************************

                 ��Ȩ���� (C), 2001-2015, ��Ϊ�������޹�˾

 ******************************************************************************
  �� �� ��   : soc_dss_rch_g_interface.h
  �� �� ��   : ����
  ��    ��   : Excel2Code
  ��������   : 2015-07-15 15:56:26
  ����޸�   :
  ��������   : �ӿ�ͷ�ļ�
  �����б�   :
  �޸���ʷ   :
  1.��    ��   : 2015��7��15��
    ��    ��   : s00249479
    �޸�����   : �ӡ�Hi6250V100 SOC�Ĵ����ֲ�_DSS_RCH_G.xml���Զ�����

******************************************************************************/

/*****************************************************************************
  1 ����ͷ�ļ�����
*****************************************************************************/

#ifndef __SOC_DSS_RCH_G_INTERFACE_H__
#define __SOC_DSS_RCH_G_INTERFACE_H__

#ifdef __cplusplus
    #if __cplusplus
        extern "C" {
    #endif
#endif



/*****************************************************************************
  2 �궨��
*****************************************************************************/

/****************************************************************************
                     (1/1) RCH_G
 ****************************************************************************/
/* �Ĵ���˵����RDMA����ͼ���WDMAд��ͼ�����Ͻ������buffer��ˮƽƫ��
   λ����UNION�ṹ:  SOC_DSS_RCH_G_DMA_OFT_X0_UNION */
#define SOC_DSS_RCH_G_DMA_OFT_X0_ADDR(base)           ((base) + (0x0000))

/* �Ĵ���˵����RDMA����ͼ���WDMAд��ͼ�����Ͻ������buffer�Ĵ�ֱƫ��
   λ����UNION�ṹ:  SOC_DSS_RCH_G_DMA_OFT_Y0_UNION */
#define SOC_DSS_RCH_G_DMA_OFT_Y0_ADDR(base)           ((base) + (0x0004))

/* �Ĵ���˵��������ͼ�����½������buffer��ˮƽƫ��
   λ����UNION�ṹ:  SOC_DSS_RCH_G_DMA_OFT_X1_UNION */
#define SOC_DSS_RCH_G_DMA_OFT_X1_ADDR(base)           ((base) + (0x0008))

/* �Ĵ���˵��������ͼ�����½������buffer�Ĵ�ֱƫ��
   λ����UNION�ṹ:  SOC_DSS_RCH_G_DMA_OFT_Y1_UNION */
#define SOC_DSS_RCH_G_DMA_OFT_Y1_ADDR(base)           ((base) + (0x000C))

/* �Ĵ���˵����RDMA��Mask���Ͻ�����
   λ����UNION�ṹ:  SOC_DSS_RCH_G_DMA_MASK0_UNION */
#define SOC_DSS_RCH_G_DMA_MASK0_ADDR(base)            ((base) + (0x0010))

/* �Ĵ���˵����RDMA��Mask���½�����
   λ����UNION�ṹ:  SOC_DSS_RCH_G_DMA_MASK1_UNION */
#define SOC_DSS_RCH_G_DMA_MASK1_ADDR(base)            ((base) + (0x0014))

/* �Ĵ���˵����Yƽ��RDMA��ֱStretch֮��ĸ߶�-1
   λ����UNION�ṹ:  SOC_DSS_RCH_G_DMA_STRETCH_SIZE_VRT_UNION */
#define SOC_DSS_RCH_G_DMA_STRETCH_SIZE_VRT_ADDR(base) ((base) + (0x0018))

/* �Ĵ���˵����RDMA����
   λ����UNION�ṹ:  SOC_DSS_RCH_G_DMA_CTRL_UNION */
#define SOC_DSS_RCH_G_DMA_CTRL_ADDR(base)             ((base) + (0x001C))

/* �Ĵ���˵����tile��ʽ��ַ��֯ʹ��
   λ����UNION�ṹ:  SOC_DSS_RCH_G_DMA_TILE_SCRAM_UNION */
#define SOC_DSS_RCH_G_DMA_TILE_SCRAM_ADDR(base)       ((base) + (0x0020))

/* �Ĵ���˵����1PULSE�Ĵ���
   λ����UNION�ṹ:  SOC_DSS_RCH_G_DMA_PULSE_UNION */
#define SOC_DSS_RCH_G_DMA_PULSE_ADDR(base)            ((base) + (0x0028))

/* �Ĵ���˵��������
   λ����UNION�ṹ:  SOC_DSS_RCH_G_RWCH_CFG0_UNION */
#define SOC_DSS_RCH_G_RWCH_CFG0_ADDR(base)            ((base) + (0x0030))

/* �Ĵ���˵����RDMA����ͼ���WDMAд��ͼ���Yƽ��Data����ַ�Ĵ���
   λ����UNION�ṹ:  SOC_DSS_RCH_G_DMA_DATA_ADDR0_UNION */
#define SOC_DSS_RCH_G_DMA_DATA_ADDR0_ADDR(base)       ((base) + (0x0060))

/* �Ĵ���˵����RDMA����ͼ���WDMAд��ͼ���ԭͼY�е�ַƫ��
   λ����UNION�ṹ:  SOC_DSS_RCH_G_DMA_STRIDE0_UNION */
#define SOC_DSS_RCH_G_DMA_STRIDE0_ADDR(base)          ((base) + (0x0064))

/* �Ĵ���˵����Yƽ������֮��Ķ�Ӧ��stride
   λ����UNION�ṹ:  SOC_DSS_RCH_G_DMA_STRETCH_STRIDE0_UNION */
#define SOC_DSS_RCH_G_DMA_STRETCH_STRIDE0_ADDR(base)  ((base) + (0x0068))

/* �Ĵ���˵����RDMA��WDMA���ͼ��Yƽ�����128bit���ݵĸ���
   λ����UNION�ṹ:  SOC_DSS_RCH_G_DMA_DATA_NUM0_UNION */
#define SOC_DSS_RCH_G_DMA_DATA_NUM0_ADDR(base)        ((base) + (0x006C))

/* �Ĵ���˵������ά�ɲ�Ĵ���
   λ����UNION�ṹ:  SOC_DSS_RCH_G_DMA_TEST0_UNION */
#define SOC_DSS_RCH_G_DMA_TEST0_ADDR(base)            ((base) + (0x0070))

/* �Ĵ���˵������ά�ɲ�Ĵ���
   λ����UNION�ṹ:  SOC_DSS_RCH_G_DMA_TEST1_UNION */
#define SOC_DSS_RCH_G_DMA_TEST1_ADDR(base)            ((base) + (0x0074))

/* �Ĵ���˵������ά�ɲ�Ĵ���
   λ����UNION�ṹ:  SOC_DSS_RCH_G_DMA_TEST3_UNION */
#define SOC_DSS_RCH_G_DMA_TEST3_ADDR(base)            ((base) + (0x0078))

/* �Ĵ���˵������ά�ɲ�Ĵ���
   λ����UNION�ṹ:  SOC_DSS_RCH_G_DMA_TEST4_UNION */
#define SOC_DSS_RCH_G_DMA_TEST4_ADDR(base)            ((base) + (0x007C))

/* �Ĵ���˵����״̬�ϱ��Ĵ���
   λ����UNION�ṹ:  SOC_DSS_RCH_G_DMA_STATUS_Y_UNION */
#define SOC_DSS_RCH_G_DMA_STATUS_Y_ADDR(base)         ((base) + (0x0080))

/* �Ĵ���˵�������Ĵ���ѡ��
   λ����UNION�ṹ:  SOC_DSS_RCH_G_CH_RD_SHADOW_UNION */
#define SOC_DSS_RCH_G_CH_RD_SHADOW_ADDR(base)         ((base) + (0x00D0))

/* �Ĵ���˵����ͨ�����ƼĴ���
   λ����UNION�ṹ:  SOC_DSS_RCH_G_CH_CTL_UNION */
#define SOC_DSS_RCH_G_CH_CTL_ADDR(base)               ((base) + (0x00D4))

/* �Ĵ���˵����ͨ����ȫʹ��
   λ����UNION�ṹ:  SOC_DSS_RCH_G_CH_SECU_EN_UNION */
#define SOC_DSS_RCH_G_CH_SECU_EN_ADDR(base)           ((base) + (0x00D8))

/* �Ĵ���˵���������峡�Ĵ���
   λ����UNION�ṹ:  SOC_DSS_RCH_G_CH_SW_END_REQ_UNION */
#define SOC_DSS_RCH_G_CH_SW_END_REQ_ADDR(base)        ((base) + (0x00DC))

/* �Ĵ���˵����һ��ģ��ʱ��ѡ���ź�
   λ����UNION�ṹ:  SOC_DSS_RCH_G_CH_CLK_SEL_UNION */
#define SOC_DSS_RCH_G_CH_CLK_SEL_ADDR(base)           ((base) + (0x00E0))

/* �Ĵ���˵����һ��ģ��ʱ��ʹ���ź�
   λ����UNION�ṹ:  SOC_DSS_RCH_G_CH_CLK_EN_UNION */
#define SOC_DSS_RCH_G_CH_CLK_EN_ADDR(base)            ((base) + (0x00E4))

/* �Ĵ���˵����ͼ���С
   λ����UNION�ṹ:  SOC_DSS_RCH_G_DFC_DISP_SIZE_UNION */
#define SOC_DSS_RCH_G_DFC_DISP_SIZE_ADDR(base)        ((base) + (0x0100))

/* �Ĵ���˵�����������������
   λ����UNION�ṹ:  SOC_DSS_RCH_G_DFC_PIX_IN_NUM_UNION */
#define SOC_DSS_RCH_G_DFC_PIX_IN_NUM_ADDR(base)       ((base) + (0x0104))

/* �Ĵ���˵����͸��������
   λ����UNION�ṹ:  SOC_DSS_RCH_G_DFC_GLB_ALPHA_UNION */
#define SOC_DSS_RCH_G_DFC_GLB_ALPHA_ADDR(base)        ((base) + (0x0108))

/* �Ĵ���˵������ʾ��ʽ
   λ����UNION�ṹ:  SOC_DSS_RCH_G_DFC_DISP_FMT_UNION */
#define SOC_DSS_RCH_G_DFC_DISP_FMT_ADDR(base)         ((base) + (0x010C))

/* �Ĵ���˵����ˮƽ�ü�����
   λ����UNION�ṹ:  SOC_DSS_RCH_G_DFC_CLIP_CTL_HRZ_UNION */
#define SOC_DSS_RCH_G_DFC_CLIP_CTL_HRZ_ADDR(base)     ((base) + (0x0110))

/* �Ĵ���˵������ֱ�ü�����
   λ����UNION�ṹ:  SOC_DSS_RCH_G_DFC_CLIP_CTL_VRZ_UNION */
#define SOC_DSS_RCH_G_DFC_CLIP_CTL_VRZ_ADDR(base)     ((base) + (0x0114))

/* �Ĵ���˵����ͼ�����ʹ��
   λ����UNION�ṹ:  SOC_DSS_RCH_G_DFC_CTL_CLIP_EN_UNION */
#define SOC_DSS_RCH_G_DFC_CTL_CLIP_EN_ADDR(base)      ((base) + (0x0118))

/* �Ĵ���˵����ʱ���ſ�ģʽ
   λ����UNION�ṹ:  SOC_DSS_RCH_G_DFC_ICG_MODULE_UNION */
#define SOC_DSS_RCH_G_DFC_ICG_MODULE_ADDR(base)       ((base) + (0x011C))

/* �Ĵ���˵������������ʹ��
   λ����UNION�ṹ:  SOC_DSS_RCH_G_DFC_DITHER_ENABLE_UNION */
#define SOC_DSS_RCH_G_DFC_DITHER_ENABLE_ADDR(base)    ((base) + (0x0120))

/* �Ĵ���˵�����������ؿ���
   λ����UNION�ṹ:  SOC_DSS_RCH_G_DFC_PADDING_CTL_UNION */
#define SOC_DSS_RCH_G_DFC_PADDING_CTL_ADDR(base)      ((base) + (0x0124))

/* �Ĵ���˵����ˮƽ��������ʹ��
   λ����UNION�ṹ:  SOC_DSS_RCH_G_SCF_EN_HSCL_STR_UNION */
#define SOC_DSS_RCH_G_SCF_EN_HSCL_STR_ADDR(base)      ((base) + (0x0200))

/* �Ĵ���˵������ֱ��������ʹ��
   λ����UNION�ṹ:  SOC_DSS_RCH_G_SCF_EN_VSCL_STR_UNION */
#define SOC_DSS_RCH_G_SCF_EN_VSCL_STR_ADDR(base)      ((base) + (0x0204))

/* �Ĵ���˵����ˮƽ�ʹ�ֱ�˲��Լ�video����ģʽ����
   λ����UNION�ṹ:  SOC_DSS_RCH_G_SCF_H_V_ORDER_UNION */
#define SOC_DSS_RCH_G_SCF_H_V_ORDER_ADDR(base)        ((base) + (0x0208))

/* �Ĵ���˵����ͨ��ʱ���ſ�
   λ����UNION�ṹ:  SOC_DSS_RCH_G_SCF_CH_CORE_GT_UNION */
#define SOC_DSS_RCH_G_SCF_CH_CORE_GT_ADDR(base)       ((base) + (0x020C))

/* �Ĵ���˵�����������
   λ����UNION�ṹ:  SOC_DSS_RCH_G_SCF_INPUT_WIDTH_HEIGHT_UNION */
#define SOC_DSS_RCH_G_SCF_INPUT_WIDTH_HEIGHT_ADDR(base) ((base) + (0x0210))

/* �Ĵ���˵�����������
   λ����UNION�ṹ:  SOC_DSS_RCH_G_SCF_OUTPUT_WIDTH_HEIGHT_UNION */
#define SOC_DSS_RCH_G_SCF_OUTPUT_WIDTH_HEIGHT_ADDR(base) ((base) + (0x0214))

/* �Ĵ���˵��������MEM�͹��Ŀ���
   λ����UNION�ṹ:  SOC_DSS_RCH_G_SCF_COEF_MEM_CTRL_UNION */
#define SOC_DSS_RCH_G_SCF_COEF_MEM_CTRL_ADDR(base)    ((base) + (0x0218))

/* �Ĵ���˵����ˮƽ����ʹ���ź�
   λ����UNION�ṹ:  SOC_DSS_RCH_G_SCF_EN_HSCL_UNION */
#define SOC_DSS_RCH_G_SCF_EN_HSCL_ADDR(base)          ((base) + (0x021C))

/* �Ĵ���˵������ֱ����ʹ���ź�
   λ����UNION�ṹ:  SOC_DSS_RCH_G_SCF_EN_VSCL_UNION */
#define SOC_DSS_RCH_G_SCF_EN_VSCL_ADDR(base)          ((base) + (0x0220))

/* �Ĵ���˵����ˮƽ��ʼ��λ
   λ����UNION�ṹ:  SOC_DSS_RCH_G_SCF_ACC_HSCL_UNION */
#define SOC_DSS_RCH_G_SCF_ACC_HSCL_ADDR(base)         ((base) + (0x0224))

/* �Ĵ���˵����ͨ��1ˮƽ��λ�����ƫ����
   λ����UNION�ṹ:  SOC_DSS_RCH_G_SCF_ACC_HSCL1_UNION */
#define SOC_DSS_RCH_G_SCF_ACC_HSCL1_ADDR(base)        ((base) + (0x0228))

/* �Ĵ���˵����ˮƽ���ű���
   λ����UNION�ṹ:  SOC_DSS_RCH_G_SCF_INC_HSCL_UNION */
#define SOC_DSS_RCH_G_SCF_INC_HSCL_ADDR(base)         ((base) + (0x0234))

/* �Ĵ���˵������ֱ��ʼ��λ
   λ����UNION�ṹ:  SOC_DSS_RCH_G_SCF_ACC_VSCL_UNION */
#define SOC_DSS_RCH_G_SCF_ACC_VSCL_ADDR(base)         ((base) + (0x0238))

/* �Ĵ���˵����ͨ��1��ֱ��λ�����ƫ����
   λ����UNION�ṹ:  SOC_DSS_RCH_G_SCF_ACC_VSCL1_UNION */
#define SOC_DSS_RCH_G_SCF_ACC_VSCL1_ADDR(base)        ((base) + (0x023C))

/* �Ĵ���˵������ֱ���ű���
   λ����UNION�ṹ:  SOC_DSS_RCH_G_SCF_INC_VSCL_UNION */
#define SOC_DSS_RCH_G_SCF_INC_VSCL_ADDR(base)         ((base) + (0x0248))

/* �Ĵ���˵��������λ�Ĵ���
   λ����UNION�ṹ:  SOC_DSS_RCH_G_SCF_EN_NONLINEAR_UNION */
#define SOC_DSS_RCH_G_SCF_EN_NONLINEAR_ADDR(base)     ((base) + (0x024C))

/* �Ĵ���˵�������崦��ʹ���ź�
   λ����UNION�ṹ:  SOC_DSS_RCH_G_SCF_EN_MMP_UNION */
#define SOC_DSS_RCH_G_SCF_EN_MMP_ADDR(base)           ((base) + (0x027C))

/* �Ĵ���˵����ˮƽ�˲������ڲ�״̬�Ĵ���0
   λ����UNION�ṹ:  SOC_DSS_RCH_G_SCF_DB_H0_UNION */
#define SOC_DSS_RCH_G_SCF_DB_H0_ADDR(base)            ((base) + (0x0280))

/* �Ĵ���˵����ˮƽ�˲������ڲ�״̬�Ĵ���1
   λ����UNION�ṹ:  SOC_DSS_RCH_G_SCF_DB_H1_UNION */
#define SOC_DSS_RCH_G_SCF_DB_H1_ADDR(base)            ((base) + (0x0284))

/* �Ĵ���˵������ֱ�˲������ڲ�״̬�Ĵ���0
   λ����UNION�ṹ:  SOC_DSS_RCH_G_SCF_DB_V0_UNION */
#define SOC_DSS_RCH_G_SCF_DB_V0_ADDR(base)            ((base) + (0x0288))

/* �Ĵ���˵������ֱ�˲������ڲ�״̬�Ĵ���1
   λ����UNION�ṹ:  SOC_DSS_RCH_G_SCF_DB_V1_UNION */
#define SOC_DSS_RCH_G_SCF_DB_V1_ADDR(base)            ((base) + (0x028C))

/* �Ĵ���˵����LINE BUFFER POWER MANAGER
   λ����UNION�ṹ:  SOC_DSS_RCH_G_SCF_LB_MEM_CTRL_UNION */
#define SOC_DSS_RCH_G_SCF_LB_MEM_CTRL_ADDR(base)      ((base) + (0x0290))

/* �Ĵ���˵����ͼ���С
   λ����UNION�ṹ:  SOC_DSS_RCH_G_POST_CLIP_DISP_SIZE_UNION */
#define SOC_DSS_RCH_G_POST_CLIP_DISP_SIZE_ADDR(base)  ((base) + (0x03A0))

/* �Ĵ���˵����ˮƽ�ü�����
   λ����UNION�ṹ:  SOC_DSS_RCH_G_POST_CLIP_CTL_HRZ_UNION */
#define SOC_DSS_RCH_G_POST_CLIP_CTL_HRZ_ADDR(base)    ((base) + (0x03B0))

/* �Ĵ���˵������ֱ�ü�����
   λ����UNION�ṹ:  SOC_DSS_RCH_G_POST_CLIP_CTL_VRZ_UNION */
#define SOC_DSS_RCH_G_POST_CLIP_CTL_VRZ_ADDR(base)    ((base) + (0x03B4))

/* �Ĵ���˵����ͼ�����ʹ��
   λ����UNION�ṹ:  SOC_DSS_RCH_G_POST_CLIP_EN_UNION */
#define SOC_DSS_RCH_G_POST_CLIP_EN_ADDR(base)         ((base) + (0x03B8))

/* �Ĵ���˵��������ѡ��Ĵ���
   λ����UNION�ṹ:  SOC_DSS_RCH_G_CH_DEBUG_SEL_UNION */
#define SOC_DSS_RCH_G_CH_DEBUG_SEL_ADDR(base)         ((base) + (0x600))

/* �Ĵ���˵����DMA_BUF���ƼĴ���
   λ����UNION�ṹ:  SOC_DSS_RCH_G_DMA_BUF_CTRL_UNION */
#define SOC_DSS_RCH_G_DMA_BUF_CTRL_ADDR(base)         ((base) + (0x0800))

/* �Ĵ���˵����DMA_BUF ����ѡ��Ĵ�����
   λ����UNION�ṹ:  SOC_DSS_RCH_G_DMA_BUF_CPU_CTL_UNION */
#define SOC_DSS_RCH_G_DMA_BUF_CPU_CTL_ADDR(base)      ((base) + (0x0804))

/* �Ĵ���˵����DMA_BUF ���������Ĵ�����
   λ����UNION�ṹ:  SOC_DSS_RCH_G_DMA_BUF_CPU_START_UNION */
#define SOC_DSS_RCH_G_DMA_BUF_CPU_START_ADDR(base)    ((base) + (0x0808))

/* �Ĵ���˵����DMA_BUF ��ַ�Ĵ�����
   λ����UNION�ṹ:  SOC_DSS_RCH_G_DMA_BUF_CPU_ADDR_UNION */
#define SOC_DSS_RCH_G_DMA_BUF_CPU_ADDR_ADDR(base)     ((base) + (0x080C))

/* �Ĵ���˵����DMA_BUF �����ݶ˿ڼĴ���0��
   λ����UNION�ṹ:  SOC_DSS_RCH_G_DMA_BUF_CPU_RDATA0_UNION */
#define SOC_DSS_RCH_G_DMA_BUF_CPU_RDATA0_ADDR(base)   ((base) + (0x0810))

/* �Ĵ���˵����DMA_BUF �����ݶ˿ڼĴ���1��
   λ����UNION�ṹ:  SOC_DSS_RCH_G_DMA_BUF_CPU_RDATA1_UNION */
#define SOC_DSS_RCH_G_DMA_BUF_CPU_RDATA1_ADDR(base)   ((base) + (0x814))

/* �Ĵ���˵����DMA_BUF �����ݶ˿ڼĴ���2��
   λ����UNION�ṹ:  SOC_DSS_RCH_G_DMA_BUF_CPU_RDATA2_UNION */
#define SOC_DSS_RCH_G_DMA_BUF_CPU_RDATA2_ADDR(base)   ((base) + (0x818))

/* �Ĵ���˵����DMA_BUF �����ݶ˿ڼĴ���3��
   λ����UNION�ṹ:  SOC_DSS_RCH_G_DMA_BUF_CPU_RDATA3_UNION */
#define SOC_DSS_RCH_G_DMA_BUF_CPU_RDATA3_ADDR(base)   ((base) + (0x81C))

/* �Ĵ���˵����DMA_BUF д���ݶ˿ڼĴ���0��
   λ����UNION�ṹ:  SOC_DSS_RCH_G_DMA_BUF_CPU_WDATA0_UNION */
#define SOC_DSS_RCH_G_DMA_BUF_CPU_WDATA0_ADDR(base)   ((base) + (0x820))

/* �Ĵ���˵����DMA_BUF д���ݶ˿ڼĴ���1��
   λ����UNION�ṹ:  SOC_DSS_RCH_G_DMA_BUF_CPU_WDATA1_UNION */
#define SOC_DSS_RCH_G_DMA_BUF_CPU_WDATA1_ADDR(base)   ((base) + (0x824))

/* �Ĵ���˵����DMA_BUF д���ݶ˿ڼĴ���2��
   λ����UNION�ṹ:  SOC_DSS_RCH_G_DMA_BUF_CPU_WDATA2_UNION */
#define SOC_DSS_RCH_G_DMA_BUF_CPU_WDATA2_ADDR(base)   ((base) + (0x828))

/* �Ĵ���˵����DMA_BUF д���ݶ˿ڼĴ���3��
   λ����UNION�ṹ:  SOC_DSS_RCH_G_DMA_BUF_CPU_WDATA3_UNION */
#define SOC_DSS_RCH_G_DMA_BUF_CPU_WDATA3_ADDR(base)   ((base) + (0x82C))

/* �Ĵ���˵����MMU TLB �����ݶ˿ڼĴ���0��
   λ����UNION�ṹ:  SOC_DSS_RCH_G_DMA_REQ_END_UNION */
#define SOC_DSS_RCH_G_DMA_REQ_END_ADDR(base)          ((base) + (0x830))

/* �Ĵ���˵����DMA_BUF ���ԼĴ���
   λ����UNION�ṹ:  SOC_DSS_RCH_G_DMA_BUF_DBGCFG_UNION */
#define SOC_DSS_RCH_G_DMA_BUF_DBGCFG_ADDR(base)       ((base) + (0x834))

/* �Ĵ���˵����DMA_BUF����ֻ���Ĵ���0
   λ����UNION�ṹ:  SOC_DSS_RCH_G_DMA_BUF_DBG0_UNION */
#define SOC_DSS_RCH_G_DMA_BUF_DBG0_ADDR(base)         ((base) + (0x838))

/* �Ĵ���˵����DMA_BUF����ֻ���Ĵ���1
   λ����UNION�ṹ:  SOC_DSS_RCH_G_DMA_BUF_DBG1_UNION */
#define SOC_DSS_RCH_G_DMA_BUF_DBG1_ADDR(base)         ((base) + (0x83C))

/* �Ĵ���˵����DMA_BUF����ֻ���Ĵ���0
   λ����UNION�ṹ:  SOC_DSS_RCH_G_DMA_BUF_DBG2_UNION */
#define SOC_DSS_RCH_G_DMA_BUF_DBG2_ADDR(base)         ((base) + (0x840))

/* �Ĵ���˵����DMA_BUF����ֻ���Ĵ���1
   λ����UNION�ṹ:  SOC_DSS_RCH_G_DMA_BUF_DBG3_UNION */
#define SOC_DSS_RCH_G_DMA_BUF_DBG3_ADDR(base)         ((base) + (0x844))

/* �Ĵ���˵����DMA_BUF����ֻ���Ĵ���0
   λ����UNION�ṹ:  SOC_DSS_RCH_G_DMA_BUF_DBG4_UNION */
#define SOC_DSS_RCH_G_DMA_BUF_DBG4_ADDR(base)         ((base) + (0x848))

/* �Ĵ���˵����DMA_BUF����ֻ���Ĵ���1
   λ����UNION�ṹ:  SOC_DSS_RCH_G_DMA_BUF_DBG5_UNION */
#define SOC_DSS_RCH_G_DMA_BUF_DBG5_ADDR(base)         ((base) + (0x84C))

/* �Ĵ���˵����ͼ���С
   λ����UNION�ṹ:  SOC_DSS_RCH_G_DMA_BUF_SIZE_UNION */
#define SOC_DSS_RCH_G_DMA_BUF_SIZE_ADDR(base)         ((base) + (0x850))

/* �Ĵ���˵����DMA_BUF SRAM���ƼĴ�����TP��
   λ����UNION�ṹ:  SOC_DSS_RCH_G_DMA_BUF_MEM_CTRL_UNION */
#define SOC_DSS_RCH_G_DMA_BUF_MEM_CTRL_ADDR(base)     ((base) + (0x0854))

/* �Ĵ���˵����ѹ��Header��ʼ��ַ��λ
   λ����UNION�ṹ:  SOC_DSS_RCH_G_AFBCD_HREG_HDR_PTR_LO_UNION */
#define SOC_DSS_RCH_G_AFBCD_HREG_HDR_PTR_LO_ADDR(base) ((base) + (0x0900))

/* �Ĵ���˵����ѹ��ͼ�����
   λ����UNION�ṹ:  SOC_DSS_RCH_G_AFBCD_HREG_PIC_WIDTH_UNION */
#define SOC_DSS_RCH_G_AFBCD_HREG_PIC_WIDTH_ADDR(base) ((base) + (0x0904))

/* �Ĵ���˵����ѹ��ͼ��߶�
   λ����UNION�ṹ:  SOC_DSS_RCH_G_AFBCD_HREG_PIC_HEIGHT_UNION */
#define SOC_DSS_RCH_G_AFBCD_HREG_PIC_HEIGHT_ADDR(base) ((base) + (0x090C))

/* �Ĵ���˵����ѹ��ͼ���ʽ
   λ����UNION�ṹ:  SOC_DSS_RCH_G_AFBCD_HREG_FORMAT_UNION */
#define SOC_DSS_RCH_G_AFBCD_HREG_FORMAT_ADDR(base)    ((base) + (0x0910))

/* �Ĵ���˵����AFBCD����
   λ����UNION�ṹ:  SOC_DSS_RCH_G_AFBCD_CTL_UNION */
#define SOC_DSS_RCH_G_AFBCD_CTL_ADDR(base)            ((base) + (0x0914))

/* �Ĵ���˵����STRETCH PARAMETER
   λ����UNION�ṹ:  SOC_DSS_RCH_G_AFBCD_STR_UNION */
#define SOC_DSS_RCH_G_AFBCD_STR_ADDR(base)            ((base) + (0x0918))

/* �Ĵ���˵����TOP AND BOTTOM LINT NUMBER BE CROPPED
   λ����UNION�ṹ:  SOC_DSS_RCH_G_LINE_CROP_UNION */
#define SOC_DSS_RCH_G_LINE_CROP_ADDR(base)            ((base) + (0x091C))

/* �Ĵ���˵����INPUT HEADER STRIDE
   λ����UNION�ṹ:  SOC_DSS_RCH_G_INPUT_HEADER_STRIDE_UNION */
#define SOC_DSS_RCH_G_INPUT_HEADER_STRIDE_ADDR(base)  ((base) + (0x0920))

/* �Ĵ���˵����output payload stride
   λ����UNION�ṹ:  SOC_DSS_RCH_G_AFBCD_PAYLOAD_STRIDE_UNION */
#define SOC_DSS_RCH_G_AFBCD_PAYLOAD_STRIDE_ADDR(base) ((base) + (0x0924))

/* �Ĵ���˵����mm buffer base 0
   λ����UNION�ṹ:  SOC_DSS_RCH_G_MM_BASE_0_UNION */
#define SOC_DSS_RCH_G_MM_BASE_0_ADDR(base)            ((base) + (0x0928))

/* �Ĵ���˵����mm buffer base 1
   λ����UNION�ṹ:  SOC_DSS_RCH_G_MM_BASE_1_UNION */
#define SOC_DSS_RCH_G_MM_BASE_1_ADDR(base)            ((base) + (0x092C))

/* �Ĵ���˵����input payload point
   λ����UNION�ṹ:  SOC_DSS_RCH_G_AFBCD_PAYLOAD_POINTER_UNION */
#define SOC_DSS_RCH_G_AFBCD_PAYLOAD_POINTER_ADDR(base) ((base) + (0x0930))

/* �Ĵ���˵����input height
   λ����UNION�ṹ:  SOC_DSS_RCH_G_HEIGHT_BF_STR_UNION */
#define SOC_DSS_RCH_G_HEIGHT_BF_STR_ADDR(base)        ((base) + (0x0934))

/* �Ĵ���˵����OUSTANDING CFG
   λ����UNION�ṹ:  SOC_DSS_RCH_G_OS_CFG_UNION */
#define SOC_DSS_RCH_G_OS_CFG_ADDR(base)               ((base) + (0x0938))

/* �Ĵ���˵����AFBCE SRAM���ƼĴ�����SP��
   λ����UNION�ṹ:  SOC_DSS_RCH_G_AFBCD_MEM_CTRL_UNION */
#define SOC_DSS_RCH_G_AFBCD_MEM_CTRL_ADDR(base)       ((base) + (0x093C))

/* �Ĵ���˵����SCRAMBLEģʽѡ��
   λ����UNION�ṹ:  SOC_DSS_RCH_G_AFBCD_SCRAMBLE_MODE_UNION */
#define SOC_DSS_RCH_G_AFBCD_SCRAMBLE_MODE_ADDR(base)  ((base) + (0x0940))

/* �Ĵ���˵������ͼheader pointer����ͼheader pointer֮���offset
   λ����UNION�ṹ:  SOC_DSS_RCH_G_AFBCD_HEADER_POINTER_OFFSET_UNION */
#define SOC_DSS_RCH_G_AFBCD_HEADER_POINTER_OFFSET_ADDR(base) ((base) + (0x0944))

/* �Ĵ���˵������ά�ɲ�Ĵ���1��
   λ����UNION�ṹ:  SOC_DSS_RCH_G_AFBCD_MONITOR_REG1_UNION */
#define SOC_DSS_RCH_G_AFBCD_MONITOR_REG1_ADDR(base)   ((base) + (0x0948))

/* �Ĵ���˵������ά�ɲ�Ĵ���2��
   λ����UNION�ṹ:  SOC_DSS_RCH_G_AFBCD_MONITOR_REG2_UNION */
#define SOC_DSS_RCH_G_AFBCD_MONITOR_REG2_ADDR(base)   ((base) + (0x094C))

/* �Ĵ���˵������ά�ɲ�Ĵ���3��
   λ����UNION�ṹ:  SOC_DSS_RCH_G_AFBCD_MONITOR_REG3_UNION */
#define SOC_DSS_RCH_G_AFBCD_MONITOR_REG3_ADDR(base)   ((base) + (0x0950))

/* �Ĵ���˵����ģ��Ӱ�ӼĴ����ָ���Ĭ��ֵ
   λ����UNION�ṹ:  SOC_DSS_RCH_G_REG_DEFAULT_UNION */
#define SOC_DSS_RCH_G_REG_DEFAULT_ADDR(base)          ((base) + (0x0A00))





/*****************************************************************************
  3 ö�ٶ���
*****************************************************************************/



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

/****************************************************************************
                     (1/1) RCH_G
 ****************************************************************************/
/*****************************************************************************
 �ṹ��    : SOC_DSS_RCH_G_DMA_OFT_X0_UNION
 �ṹ˵��  : DMA_OFT_X0 �Ĵ����ṹ���塣��ַƫ����:0x0000����ֵ:0x00000000������:32
 �Ĵ���˵��: RDMA����ͼ���WDMAд��ͼ�����Ͻ������buffer��ˮƽƫ��
*****************************************************************************/
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int      value;
    struct
    {
        unsigned int  dma_oft_x0 : 12; /* bit[0-11] : RDMA����ͼ���WDMAд��ͼ����Yƽ������Ͻ�x���꣨������Ϊ�����buffer�����Ͻǵ����꣬1����128bit��(0,0)�����Ӧ��buffer�����Ͻǣ���
                                                      dma_oft_x0_y = dma_oft_x0;
                                                      dma_oft_x0_u/v = planar?dma_oft_x0:dma_oft_x0/2;
                                                      (
                                                      eg.�����ͼ��ߴ�Ϊ320*480���Ҷ���ͼ�����Ͻ���buffer�����Ͻǡ���������������Ϊp0 = 0���յ������Ϊp1 = 319����
                                                       1. ���������ꡱ�򡰶������ꡱ�ο����㹫ʽ��
                                                       RGB32bpp�� x0 = int[p0/4] = 0 ��
                                                       x1 = int[p1/4] = 79��
                                                       YUV422pkt��x0 = int[p0/8] = 0 ��
                                                       x1 = int[p1/8] = 39��
                                                       2. ���������ꡱ��á�ͼ�����ؿ��ȡ���
                                                       RGB32bpp��ʽ�£� pix_wid=(x1-x0+1)*4��
                                                       YUV422pkt��ʽ�£�pix_wid=(x1-x0+1)*8��
                                                      )
                                                      Լ��������
                                                      1. ��x1-x0����[0,2047]
                                                      ע:buffer�����ϽǼ�Ϊ����ԭ��,buffer����ʼ�洢��ַ��Լ��Ϊ:
                                                       Linear��ʽ128bit���룻
                                                       Tile��ʽ256KByte���롣
                                                      2. ��planar 420��planar 422��ʽʱ��y������dma_oft_x0�������Ϊż����dma_oft_x1�������Ϊ����������x1-x0+1Ϊż���� */
        unsigned int  reserved   : 20; /* bit[12-31]: ���� */
    } reg;
} SOC_DSS_RCH_G_DMA_OFT_X0_UNION;
#endif
#define SOC_DSS_RCH_G_DMA_OFT_X0_dma_oft_x0_START  (0)
#define SOC_DSS_RCH_G_DMA_OFT_X0_dma_oft_x0_END    (11)


/*****************************************************************************
 �ṹ��    : SOC_DSS_RCH_G_DMA_OFT_Y0_UNION
 �ṹ˵��  : DMA_OFT_Y0 �Ĵ����ṹ���塣��ַƫ����:0x0004����ֵ:0x00000000������:32
 �Ĵ���˵��: RDMA����ͼ���WDMAд��ͼ�����Ͻ������buffer�Ĵ�ֱƫ��
*****************************************************************************/
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int      value;
    struct
    {
        unsigned int  dma_oft_y0 : 16; /* bit[0-15] : RDMA����ͼ���WDMAд��ͼ����Yƽ������Ͻ�y���꣨������Ϊ�����buffer�����Ͻǵ����꣬(0,0)�����Ӧ��buffer�����Ͻǣ�
                                                      dma_oft_y0_y = dma_oft_y0;
                                                      dma_oft_y0_u/v = 420?dma_oft_y0:dma_oft_y0/2;
                                                      (
                                                      eg.�����ͼ��ߴ�Ϊ320*480���Ҷ���ͼ�����Ͻ���buffer�����Ͻǡ���y0=0,y1=479
                                                      )
                                                      Լ��������
                                                      1. ����תʱ��y1-y0����[0,8191]��
                                                       ������תʱ��y1-y0����[0,2559]��
                                                       ������תʱ��y1-y0����[0,259]��
                                                      2. ��semi planar 420/planar 420��ʽʱ��y������dma_oft_y0�������Ϊż����dma_oft_y1�������Ϊ����������y1-y0+1Ϊż���� */
        unsigned int  reserved   : 16; /* bit[16-31]: ���� */
    } reg;
} SOC_DSS_RCH_G_DMA_OFT_Y0_UNION;
#endif
#define SOC_DSS_RCH_G_DMA_OFT_Y0_dma_oft_y0_START  (0)
#define SOC_DSS_RCH_G_DMA_OFT_Y0_dma_oft_y0_END    (15)


/*****************************************************************************
 �ṹ��    : SOC_DSS_RCH_G_DMA_OFT_X1_UNION
 �ṹ˵��  : DMA_OFT_X1 �Ĵ����ṹ���塣��ַƫ����:0x0008����ֵ:0x00000000������:32
 �Ĵ���˵��: ����ͼ�����½������buffer��ˮƽƫ��
*****************************************************************************/
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int      value;
    struct
    {
        unsigned int  dma_oft_x1 : 12; /* bit[0-11] : Yƽ��RDMA����ͼ���WDMAд��ͼ�����½�x���꣨������Ϊ�����buffer�����Ͻǵ����꣬1����128bit��(0,0)�����Ӧ��buffer�����Ͻǣ���
                                                      dma_oft_x1_y = dma_oft_x1;
                                                      dma_oft_x1_u/v = planar?dma_oft_x1:dma_oft_x1/2;
                                                      (
                                                      eg.�����ͼ��ߴ�Ϊ320*480���Ҷ���ͼ�����Ͻ���buffer�����Ͻǡ���������������Ϊp0 = 0���յ������Ϊp1 = 319����
                                                       1. ���������ꡱ�򡰶������ꡱ�ο����㹫ʽ��
                                                       RGB32bpp�� x0 = int[p0/4] = 0 ��
                                                       x1 = int[p1/4] = 79��
                                                       YUV422pkt��x0 = int[p0/8] = 0 ��
                                                       x1 = int[p1/8] = 39��
                                                       2. ���������ꡱ��á�ͼ�����ؿ��ȡ���
                                                       RGB32bpp��ʽ�£� pix_wid=(x1-x0+1)*4��
                                                       YUV422pkt��ʽ�£�pix_wid=(x1-x0+1)*8��
                                                      )
                                                      Լ��������
                                                      1. ��x1-x0����[0,2047]
                                                      ע:buffer�����ϽǼ�Ϊ����ԭ��,buffer����ʼ�洢��ַ��Լ��Ϊ:
                                                       Linear��ʽ128bit���룻
                                                       Tile��ʽ256KByte���롣
                                                      2. ��planar 420��planar 422��ʽʱ��y������dma_oft_x0�������Ϊż����dma_oft_x1�������Ϊ����������x1-x0+1Ϊż���� */
        unsigned int  reserved   : 20; /* bit[12-31]: ���� */
    } reg;
} SOC_DSS_RCH_G_DMA_OFT_X1_UNION;
#endif
#define SOC_DSS_RCH_G_DMA_OFT_X1_dma_oft_x1_START  (0)
#define SOC_DSS_RCH_G_DMA_OFT_X1_dma_oft_x1_END    (11)


/*****************************************************************************
 �ṹ��    : SOC_DSS_RCH_G_DMA_OFT_Y1_UNION
 �ṹ˵��  : DMA_OFT_Y1 �Ĵ����ṹ���塣��ַƫ����:0x000C����ֵ:0x00000000������:32
 �Ĵ���˵��: ����ͼ�����½������buffer�Ĵ�ֱƫ��
*****************************************************************************/
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int      value;
    struct
    {
        unsigned int  dma_oft_y1 : 16; /* bit[0-15] : RDMA����ͼ���WDMAд��ͼ����Yƽ������Ͻ�y���꣨������Ϊ�����buffer�����Ͻǵ����꣬(0,0)�����Ӧ��buffer�����Ͻǣ�
                                                      dma_oft_y1_y = dma_oft_y1;
                                                      dma_oft_y1_u/v = 420?dma_oft_y1:dma_oft_y1/2;
                                                      (
                                                      eg.�����ͼ��ߴ�Ϊ320*480���Ҷ���ͼ�����Ͻ���buffer�����Ͻǡ���y0=0,y1=479
                                                      )
                                                      Լ��������
                                                      1. ����תʱ��y1-y0����[0,8191]��
                                                       ������תʱ��y1-y0����[0,2559]��
                                                       ������תʱ��y1-y0����[0,259]��
                                                      2. ��semi planar 420/planar 420��ʽʱ��y������dma_oft_y0�������Ϊż����dma_oft_y1�������Ϊ����������y1-y0+1Ϊż���� */
        unsigned int  reserved   : 16; /* bit[16-31]: ���� */
    } reg;
} SOC_DSS_RCH_G_DMA_OFT_Y1_UNION;
#endif
#define SOC_DSS_RCH_G_DMA_OFT_Y1_dma_oft_y1_START  (0)
#define SOC_DSS_RCH_G_DMA_OFT_Y1_dma_oft_y1_END    (15)


/*****************************************************************************
 �ṹ��    : SOC_DSS_RCH_G_DMA_MASK0_UNION
 �ṹ˵��  : DMA_MASK0 �Ĵ����ṹ���塣��ַƫ����:0x0010����ֵ:0x00000000������:32
 �Ĵ���˵��: RDMA��Mask���Ͻ�����
*****************************************************************************/
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int      value;
    struct
    {
        unsigned int  dma_mask_y0 : 16; /* bit[0-15] : RDMA��mask�����������Ͻ�y���꣨�����buffer�����Ͻǣ�����Ϊ��λ��
                                                       RDMA����ͼ���Yƽ���mask������������Ͻ��ڴ�ֱ�������������
                                                       ע��
                                                       1��WDMA����ע����
                                                       
                                                       Լ��1�����õ�Mask��������ͼ���ڣ���dma_mask_y0>dma_oft_y0, dma_mask_y1<dma_oft_y1
                                                       Լ��2��Mask���������С������������
                                                       Լ��3����semi planar 420/planar 420��ʽʱ��y������dma_oft_y0�������Ϊż����dma_oft_y1�������Ϊ����������y1-y0+1Ϊż���� */
        unsigned int  dma_mask_x0 : 12; /* bit[16-27]: RDMA��mask�����������Ͻ�x���꣨�����buffer�����Ͻǣ�1����128bit����(0,0)�����Ӧ��buffer�����Ͻǣ�
                                                       ���128bitȡ������.
                                                       ��תǰԭʼͼ���Mask�������Ͻǡ�
                                                       RDMA����ͼ���Yƽ���mask������������Ͻ���ˮƽ�������������
                                                       ע��
                                                       1��WDMA����ע����
                                                       
                                                       Լ��1�����õ�Mask��������ͼ���ڣ���dma_mask_x0>dma_oft_x0, dma_mask_x1<dma_oft_x1
                                                       Լ��2��Mask���������С������������
                                                       Լ��3����planar 420��planar 422��ʽʱ��y������dma_mask_x0�������Ϊż����dma_mask_x1�������Ϊ����������x1-x0+1Ϊż���� */
        unsigned int  reserved    : 4;  /* bit[28-31]: ���� */
    } reg;
} SOC_DSS_RCH_G_DMA_MASK0_UNION;
#endif
#define SOC_DSS_RCH_G_DMA_MASK0_dma_mask_y0_START  (0)
#define SOC_DSS_RCH_G_DMA_MASK0_dma_mask_y0_END    (15)
#define SOC_DSS_RCH_G_DMA_MASK0_dma_mask_x0_START  (16)
#define SOC_DSS_RCH_G_DMA_MASK0_dma_mask_x0_END    (27)


/*****************************************************************************
 �ṹ��    : SOC_DSS_RCH_G_DMA_MASK1_UNION
 �ṹ˵��  : DMA_MASK1 �Ĵ����ṹ���塣��ַƫ����:0x0014����ֵ:0x00000000������:32
 �Ĵ���˵��: RDMA��Mask���½�����
*****************************************************************************/
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int      value;
    struct
    {
        unsigned int  dma_mask_y1 : 16; /* bit[0-15] : RDMA��mask�����������½�y���꣨�����buffer�����Ͻǣ�����Ϊ��λ��
                                                       ע��
                                                       1��WDMA����ע����
                                                       
                                                       Լ��1�����õ�Mask��������ͼ���ڣ���dma_mask_y0>dma_oft_y0, dma_mask_y1<dma_oft_y1
                                                       Լ��2��Mask���������С������������
                                                       Լ��3����semi planar 420/planar 420��ʽʱ��y������dma_oft_y0�������Ϊż����dma_oft_y1�������Ϊ����������y1-y0+1Ϊż���� */
        unsigned int  dma_mask_x1 : 12; /* bit[16-27]: RDMA��mask�����������½�x���꣨�����buffer�����Ͻǣ�1����128bit��
                                                       ��С��128bitȡ������.
                                                       ��תǰԭʼͼ���Mask�������½ǡ�
                                                       ע��
                                                       1��WDMA����ע����
                                                       
                                                       Լ��1�����õ�Mask��������ͼ���ڣ���dma_mask_x0>dma_oft_x0, dma_mask_x1<dma_oft_x1
                                                       Լ��2��Mask���������С������������
                                                       Լ��3����planar 420��planar 422��ʽʱ��y������dma_mask_x0�������Ϊż����dma_mask_x1�������Ϊ����������x1-x0+1Ϊż���� */
        unsigned int  reserved    : 4;  /* bit[28-31]: ���� */
    } reg;
} SOC_DSS_RCH_G_DMA_MASK1_UNION;
#endif
#define SOC_DSS_RCH_G_DMA_MASK1_dma_mask_y1_START  (0)
#define SOC_DSS_RCH_G_DMA_MASK1_dma_mask_y1_END    (15)
#define SOC_DSS_RCH_G_DMA_MASK1_dma_mask_x1_START  (16)
#define SOC_DSS_RCH_G_DMA_MASK1_dma_mask_x1_END    (27)


/*****************************************************************************
 �ṹ��    : SOC_DSS_RCH_G_DMA_STRETCH_SIZE_VRT_UNION
 �ṹ˵��  : DMA_STRETCH_SIZE_VRT �Ĵ����ṹ���塣��ַƫ����:0x0018����ֵ:0x00000000������:32
 �Ĵ���˵��: Yƽ��RDMA��ֱStretch֮��ĸ߶�-1
*****************************************************************************/
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int      value;
    struct
    {
        unsigned int  dma_stretch_size_vrt : 13; /* bit[0-12] : Yƽ��RDMA������߶�-1�������Ƿ�ʹ��stretch����Ҫ���øüĴ�������ʽ����
                                                                dma_stretch_size_vrt=
                                                                dma_stretch_en?(����ȡ��((dma_oft_y1-dma_oft_y0+1)/dma_line_skip_step)-1)
                                                                 :(dma_oft_y1 - dma_oft_y0��
                                                                ע��
                                                                1��WDMA����ע���� */
        unsigned int  dma_line_skip_step   : 6;  /* bit[13-18]: Yƽ�洹ֱ��������6λ������ʽ��
                                                                ע��
                                                                6'd0. 0Ϊ�Ƿ�ֵ��
                                                                6'd1. ����Ϊ1ʱ����������y��y+1��y+1*2��y+1*3��
                                                                6'd2. ����Ϊ2ʱ����������y��y+2��y+2*2��y+2*3��
                                                                ... . ��������
                                                                Լ������semi planar 420/planar 420��ʽʱ��y������dma_line_skip_step������Ϊż����
                                                                
                                                                dma_line_skip_step_u/v = 420?dma_line_skip_step/2:dma_line_skip_step
                                                                ע��
                                                                1��WDMA����ע���� */
        unsigned int  reserved             : 13; /* bit[19-31]: ���� */
    } reg;
} SOC_DSS_RCH_G_DMA_STRETCH_SIZE_VRT_UNION;
#endif
#define SOC_DSS_RCH_G_DMA_STRETCH_SIZE_VRT_dma_stretch_size_vrt_START  (0)
#define SOC_DSS_RCH_G_DMA_STRETCH_SIZE_VRT_dma_stretch_size_vrt_END    (12)
#define SOC_DSS_RCH_G_DMA_STRETCH_SIZE_VRT_dma_line_skip_step_START    (13)
#define SOC_DSS_RCH_G_DMA_STRETCH_SIZE_VRT_dma_line_skip_step_END      (18)


/*****************************************************************************
 �ṹ��    : SOC_DSS_RCH_G_DMA_CTRL_UNION
 �ṹ˵��  : DMA_CTRL �Ĵ����ṹ���塣��ַƫ����:0x001C����ֵ:0x00000000������:32
 �Ĵ���˵��: RDMA����
*****************************************************************************/
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int      value;
    struct
    {
        unsigned int  dma_page_8k         : 1;  /* bit[0]    : �洢�ռ�ҳ��С��
                                                               0: 4K Byte����ͨ��32bit DDR��
                                                               1: 8K byte (˫ͨ��32bit DDR�� */
        unsigned int  dma_tile_en         : 1;  /* bit[1]    : RDMA����ͼ���WDMA����洢��ʽ��
                                                               0��Linear��ʽ
                                                               1��Tile��ʽ */
        unsigned int  reserved_0          : 1;  /* bit[2]    : ���� */
        unsigned int  dma_pix_fmt         : 5;  /* bit[3-7]  : RDMA����ͼ���WDMAд��ͼ������ظ�ʽ��
                                                               0000��RGB565
                                                               0001��ARGB4444
                                                               0010��XRGB4444
                                                               0011��ARGB1555
                                                               0100��XRGB1555
                                                               0101��ARGB8888
                                                               0110��XRGB8888
                                                               0111��reserved
                                                               1000��YUYV Packet
                                                               1001��YUV420 Semi Planar HP
                                                               1010��YUV420 Planar HP
                                                               1011��YUV422 Semi Planar HP
                                                               1100��YUV422 Planar HP
                                                               1101��AYUV444
                                                               others��illegal reserved 
                                                               ע��
                                                               1��planar��ʽֻ������RCH_V1 */
        unsigned int  dma_va_en           : 1;  /* bit[8]    : RDMA��WDMAʹ�������ַʹ�ܣ�
                                                               0��RDMAֱ��ʹ��������ַ��
                                                               1��RDMAʹ�������ַ����ͨ��MMUת����������ַ */
        unsigned int  dma_mirror_hrz_en   : 1;  /* bit[9]    : ˮƽ����ʹ�ܱ�־��
                                                               0������
                                                               1��ʹ�� */
        unsigned int  dma_mirror_vrt_en   : 1;  /* bit[10]   : ��ֱ����ʹ�ܱ�־��
                                                               0������
                                                               1��ʹ�� */
        unsigned int  dma_rot             : 1;  /* bit[11]   : rotģ��ʹ�ܱ�־��
                                                               0���ر�
                                                               1����
                                                               ע��
                                                               1������WDMA������ֱ����ʹ����rotģ��ʹ��ͬʱ��ʱ����Ӧ˳ʱ����ת90�㣻��ˮƽ����ʹ����rotģ��ʹ��ͬʱ��ʱ����Ӧ˳ʱ����ת270��
                                                               2�����о���ʹ����rch������
                                                               �Ӿ�Ч�����������õ�������Ӧ��ϵ���£�
                                                               �Ӿ�Ч������ת�޾��� : {dma_rot,dma_mirror_vrt_en, dma_mirror_hrz_en}==3'b000;
                                                               �Ӿ�Ч����ֱ���� : {dma_rot,dma_mirror_vrt_en, dma_mirror_hrz_en}==3'b010;
                                                               �Ӿ�Ч��ˮƽ���� : {dma_rot,dma_mirror_vrt_en, dma_mirror_hrz_en}==3'b001;
                                                               �Ӿ�Ч��˳ʱ����ת90�� : {dma_rot,dma_mirror_vrt_en, dma_mirror_hrz_en}==3'b110;
                                                               �Ӿ�Ч��˳ʱ����ת180�� : {dma_rot,dma_mirror_vrt_en, dma_mirror_hrz_en}==3'b011;
                                                               �Ӿ�Ч��˳ʱ����ת270�� : {dma_rot,dma_mirror_vrt_en, dma_mirror_hrz_en}==3'b101;
                                                               �Ӿ�Ч��˳ʱ����ת90����ˮƽ���� : {dma_rot,dma_mirror_vrt_en, dma_mirror_hrz_en}==3'b100;
                                                               �Ӿ�Ч��˳ʱ����ת270����ˮƽ���� ��
                                                               �Ӿ�Ч��˳ʱ����ת90���Ҵ�ֱ���� : {dma_rot,dma_mirror_vrt_en, dma_mirror_hrz_en}==3'b111;
                                                               
                                                               2��RDMA����ע���� */
        unsigned int  dma_stretch_en      : 1;  /* bit[12]   : stretchʹ�ܱ�־
                                                               0: ����
                                                               1: ʹ��
                                                               ע��
                                                               1��WDMA����ע���� */
        unsigned int  reserved_1          : 4;  /* bit[13-16]: ���� */
        unsigned int  dma_mask_en         : 1;  /* bit[17]   : RDMA��maskʹ�ܱ�־
                                                               0: ����
                                                               1: ʹ��
                                                               ע��
                                                               1��WDMA����ע���� */
        unsigned int  dma_phy_scrambl_4   : 1;  /* bit[18]   : ����reserve�ռ�Linear��ʽ�µ�������ַ��֯��ʽ4��
                                                               [27:4],addr_4_3,[2:0]���н�֯������addr_4_3 = addr[4]^addr[3]
                                                               ע��
                                                               1��WDMA����ע���� */
        unsigned int  dma_phy_scrambl_3   : 1;  /* bit[19]   : ����reserve�ռ�Linear��ʽ�µ�������ַ��֯��ʽ3��
                                                               28λ��ַ����[27:16],[11:4],[15:12],addr_4_3,[2:0]���н�֯������addr_4_3 = addr[4]^addr[3]
                                                               ע��
                                                               1��WDMA����ע���� */
        unsigned int  dma_phy_scrambl_2   : 1;  /* bit[20]   : ����reserve�ռ�Linear��ʽ�µ�������ַ��֯��ʽ2��
                                                               28λ��ַ����[27:15],[10:4],[14:11],addr_4_3,[2:0]���н�֯������addr_4_3 = addr[4]^addr[3]
                                                               ע��
                                                               1��WDMA����ע���� */
        unsigned int  dma_phy_scrambl_1   : 1;  /* bit[21]   : ����reserve�ռ�Linear��ʽ�µ�������ַ��֯��ʽ1:
                                                               28λ��ַ����[27:14],[9:4],[13:10],addr_4_3,[2:0]���н�֯������addr_4_3 = addr[4]^addr[3]
                                                               ע��
                                                               1��WDMA����ע���� */
        unsigned int  reserved_2          : 1;  /* bit[22]   : ���� */
        unsigned int  dma_cross_128       : 1;  /* bit[23]   : ���� */
        unsigned int  dma_tile_128byte_en : 1;  /* bit[24]   : ���� */
        unsigned int  reserved_3          : 1;  /* bit[25]   : ���� */
        unsigned int  reserved_4          : 6;  /* bit[26-31]: ���� */
    } reg;
} SOC_DSS_RCH_G_DMA_CTRL_UNION;
#endif
#define SOC_DSS_RCH_G_DMA_CTRL_dma_page_8k_START          (0)
#define SOC_DSS_RCH_G_DMA_CTRL_dma_page_8k_END            (0)
#define SOC_DSS_RCH_G_DMA_CTRL_dma_tile_en_START          (1)
#define SOC_DSS_RCH_G_DMA_CTRL_dma_tile_en_END            (1)
#define SOC_DSS_RCH_G_DMA_CTRL_dma_pix_fmt_START          (3)
#define SOC_DSS_RCH_G_DMA_CTRL_dma_pix_fmt_END            (7)
#define SOC_DSS_RCH_G_DMA_CTRL_dma_va_en_START            (8)
#define SOC_DSS_RCH_G_DMA_CTRL_dma_va_en_END              (8)
#define SOC_DSS_RCH_G_DMA_CTRL_dma_mirror_hrz_en_START    (9)
#define SOC_DSS_RCH_G_DMA_CTRL_dma_mirror_hrz_en_END      (9)
#define SOC_DSS_RCH_G_DMA_CTRL_dma_mirror_vrt_en_START    (10)
#define SOC_DSS_RCH_G_DMA_CTRL_dma_mirror_vrt_en_END      (10)
#define SOC_DSS_RCH_G_DMA_CTRL_dma_rot_START              (11)
#define SOC_DSS_RCH_G_DMA_CTRL_dma_rot_END                (11)
#define SOC_DSS_RCH_G_DMA_CTRL_dma_stretch_en_START       (12)
#define SOC_DSS_RCH_G_DMA_CTRL_dma_stretch_en_END         (12)
#define SOC_DSS_RCH_G_DMA_CTRL_dma_mask_en_START          (17)
#define SOC_DSS_RCH_G_DMA_CTRL_dma_mask_en_END            (17)
#define SOC_DSS_RCH_G_DMA_CTRL_dma_phy_scrambl_4_START    (18)
#define SOC_DSS_RCH_G_DMA_CTRL_dma_phy_scrambl_4_END      (18)
#define SOC_DSS_RCH_G_DMA_CTRL_dma_phy_scrambl_3_START    (19)
#define SOC_DSS_RCH_G_DMA_CTRL_dma_phy_scrambl_3_END      (19)
#define SOC_DSS_RCH_G_DMA_CTRL_dma_phy_scrambl_2_START    (20)
#define SOC_DSS_RCH_G_DMA_CTRL_dma_phy_scrambl_2_END      (20)
#define SOC_DSS_RCH_G_DMA_CTRL_dma_phy_scrambl_1_START    (21)
#define SOC_DSS_RCH_G_DMA_CTRL_dma_phy_scrambl_1_END      (21)
#define SOC_DSS_RCH_G_DMA_CTRL_dma_cross_128_START        (23)
#define SOC_DSS_RCH_G_DMA_CTRL_dma_cross_128_END          (23)
#define SOC_DSS_RCH_G_DMA_CTRL_dma_tile_128byte_en_START  (24)
#define SOC_DSS_RCH_G_DMA_CTRL_dma_tile_128byte_en_END    (24)


/*****************************************************************************
 �ṹ��    : SOC_DSS_RCH_G_DMA_TILE_SCRAM_UNION
 �ṹ˵��  : DMA_TILE_SCRAM �Ĵ����ṹ���塣��ַƫ����:0x0020����ֵ:0x00000000������:32
 �Ĵ���˵��: tile��ʽ��ַ��֯ʹ��
*****************************************************************************/
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int      value;
    struct
    {
        unsigned int  dma_tile_scrambling_en : 1;  /* bit[0]   : tileģʽ�µ�ַ��֯(addr[9:8] = addr[9:8] xor addr[13:12])ʹ�ܣ�
                                                                 1��ʹ��
                                                                 0������ */
        unsigned int  reserved               : 31; /* bit[1-31]: ���� */
    } reg;
} SOC_DSS_RCH_G_DMA_TILE_SCRAM_UNION;
#endif
#define SOC_DSS_RCH_G_DMA_TILE_SCRAM_dma_tile_scrambling_en_START  (0)
#define SOC_DSS_RCH_G_DMA_TILE_SCRAM_dma_tile_scrambling_en_END    (0)


/*****************************************************************************
 �ṹ��    : SOC_DSS_RCH_G_DMA_PULSE_UNION
 �ṹ˵��  : DMA_PULSE �Ĵ����ṹ���塣��ַƫ����:0x0028����ֵ:0x00000000������:32
 �Ĵ���˵��: 1PULSE�Ĵ���
*****************************************************************************/
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int      value;
    struct
    {
        unsigned int  dma_pulse : 1;  /* bit[0]   : ��ά�ɲ�Ĵ����������壺
                                                    1'b1�����¿�ά�ɲ�Ĵ���
                                                    1'b0�����ֿ�ά�ɲ�Ĵ��� */
        unsigned int  reserved  : 31; /* bit[1-31]: ���� */
    } reg;
} SOC_DSS_RCH_G_DMA_PULSE_UNION;
#endif
#define SOC_DSS_RCH_G_DMA_PULSE_dma_pulse_START  (0)
#define SOC_DSS_RCH_G_DMA_PULSE_dma_pulse_END    (0)


/*****************************************************************************
 �ṹ��    : SOC_DSS_RCH_G_RWCH_CFG0_UNION
 �ṹ˵��  : RWCH_CFG0 �Ĵ����ṹ���塣��ַƫ����:0x0030����ֵ:0x00000000������:32
 �Ĵ���˵��: ����
*****************************************************************************/
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int      value;
    struct
    {
        unsigned int  rwch_cfg0 : 32; /* bit[0-31]: ������
                                                    31: ����Ϊ1ʱ��ʵȡģ��ʱ���ſ�bypass
                                                    30: ����Ϊ1ʱ��Ԥȡģ��ʱ���ſ�bypass
                                                    29: ����Ϊ1ʱ������ģ��ʱ���ſ�bypass
                                                    1: ����Ϊ1ʱ��dma_inte_err�жϿ�ˢ��
                                                    0: ����Ϊ1ʱ��monitor ʱ���ſ�ǿ����Ч */
    } reg;
} SOC_DSS_RCH_G_RWCH_CFG0_UNION;
#endif
#define SOC_DSS_RCH_G_RWCH_CFG0_rwch_cfg0_START  (0)
#define SOC_DSS_RCH_G_RWCH_CFG0_rwch_cfg0_END    (31)


/*****************************************************************************
 �ṹ��    : SOC_DSS_RCH_G_DMA_DATA_ADDR0_UNION
 �ṹ˵��  : DMA_DATA_ADDR0 �Ĵ����ṹ���塣��ַƫ����:0x0060����ֵ:0x00000000������:32
 �Ĵ���˵��: RDMA����ͼ���WDMAд��ͼ���Yƽ��Data����ַ�Ĵ���
*****************************************************************************/
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int      value;
    struct
    {
        unsigned int  dma_addr0 : 32; /* bit[0-31]: RDMA����ͼ���WDMAд��ͼ���Yƽ�����ڴ��еĴ洢��ʼ��Byte��ַ:
                                                    1. �޾������Ͻ�Byte��ַ
                                                    2. ˮƽ�������Ͻ�Byte��ַ
                                                    3. ��ֱ�����½�Byte��ַ
                                                    4. ˮƽ��ֱ�����½�Byte��ַ
                                                    
                                                    ע��RDMA��16Byte���룬��4bitʼ����0��WDMA��Լ�� */
    } reg;
} SOC_DSS_RCH_G_DMA_DATA_ADDR0_UNION;
#endif
#define SOC_DSS_RCH_G_DMA_DATA_ADDR0_dma_addr0_START  (0)
#define SOC_DSS_RCH_G_DMA_DATA_ADDR0_dma_addr0_END    (31)


/*****************************************************************************
 �ṹ��    : SOC_DSS_RCH_G_DMA_STRIDE0_UNION
 �ṹ˵��  : DMA_STRIDE0 �Ĵ����ṹ���塣��ַƫ����:0x0064����ֵ:0x00000000������:32
 �Ĵ���˵��: RDMA����ͼ���WDMAд��ͼ���ԭͼY�е�ַƫ��
*****************************************************************************/
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int      value;
    struct
    {
        unsigned int  dma_stride0           : 13; /* bit[0-12] : RDMA����ͼ���WDMAд��ͼ���Vƽ���е�ַƫ�������е�ַƫ����Ϊͼ�����ڴ����������������ش洢��ַ֮���1����128bit��
                                                                 ����תʱLinear��ʽStride��128bit���룬����С����ֵΪ1����ʾStrideΪ128bit��
                                                                 ��תʱLinear��ʽStride��4*128bit���룬����С����ֵΪ4����ʾStrideΪ4*128bit��
                                                                 Tile��ʽStride��2���ݴη�Byte���룬��С256Byte������С����ֵ��256Byte/128bit = 16 = 10000��
                                                                 ע��
                                                                 1����ƽ���ʽ����ע���� */
        unsigned int  reserved_0            : 3;  /* bit[13-15]: ���� */
        unsigned int  dma_l2t_interleave_n0 : 4;  /* bit[16-19]: Video Tile: Linear VAתTile VAʱ��֯��λ�ţ�
                                                                 CPU Tile��Linear PAתTile PA ��֯��λ�ţ�
                                                                 ���㷽���ǣ�l2t_interleave_n=7 + log2(dma_stride0*16/256)���Ϸ���Χ�ǣ�7~15��
                                                                 ����Ҫע����ǣ���Stride=256Byteʱ����ͼ����Ⱦ���һ��tile�Ŀ��ȣ���ʱn=7��Linear��ַ��Tile��ַʵ����һ�µģ�������Ҫת���� */
        unsigned int  reserved_1            : 12; /* bit[20-31]: ���� */
    } reg;
} SOC_DSS_RCH_G_DMA_STRIDE0_UNION;
#endif
#define SOC_DSS_RCH_G_DMA_STRIDE0_dma_stride0_START            (0)
#define SOC_DSS_RCH_G_DMA_STRIDE0_dma_stride0_END              (12)
#define SOC_DSS_RCH_G_DMA_STRIDE0_dma_l2t_interleave_n0_START  (16)
#define SOC_DSS_RCH_G_DMA_STRIDE0_dma_l2t_interleave_n0_END    (19)


/*****************************************************************************
 �ṹ��    : SOC_DSS_RCH_G_DMA_STRETCH_STRIDE0_UNION
 �ṹ˵��  : DMA_STRETCH_STRIDE0 �Ĵ����ṹ���塣��ַƫ����:0x0068����ֵ:0x00000000������:32
 �Ĵ���˵��: Yƽ������֮��Ķ�Ӧ��stride
*****************************************************************************/
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int      value;
    struct
    {
        unsigned int  dma_stretch_stride0 : 19; /* bit[0-18] : Yƽ������֮���stride������dma_stretch_line_num0 * dma_stride0 */
        unsigned int  reserved            : 13; /* bit[19-31]: ���� */
    } reg;
} SOC_DSS_RCH_G_DMA_STRETCH_STRIDE0_UNION;
#endif
#define SOC_DSS_RCH_G_DMA_STRETCH_STRIDE0_dma_stretch_stride0_START  (0)
#define SOC_DSS_RCH_G_DMA_STRETCH_STRIDE0_dma_stretch_stride0_END    (18)


/*****************************************************************************
 �ṹ��    : SOC_DSS_RCH_G_DMA_DATA_NUM0_UNION
 �ṹ˵��  : DMA_DATA_NUM0 �Ĵ����ṹ���塣��ַƫ����:0x006C����ֵ:0x00000000������:32
 �Ĵ���˵��: RDMA��WDMA���ͼ��Yƽ�����128bit���ݵĸ���
*****************************************************************************/
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int      value;
    struct
    {
        unsigned int  dma_data_num0 : 30; /* bit[0-29] : ���� */
        unsigned int  reserved      : 2;  /* bit[30-31]: ���� */
    } reg;
} SOC_DSS_RCH_G_DMA_DATA_NUM0_UNION;
#endif
#define SOC_DSS_RCH_G_DMA_DATA_NUM0_dma_data_num0_START  (0)
#define SOC_DSS_RCH_G_DMA_DATA_NUM0_dma_data_num0_END    (29)


/*****************************************************************************
 �ṹ��    : SOC_DSS_RCH_G_DMA_TEST0_UNION
 �ṹ˵��  : DMA_TEST0 �Ĵ����ṹ���塣��ַƫ����:0x0070����ֵ:0x00000000������:32
 �Ĵ���˵��: ��ά�ɲ�Ĵ���
*****************************************************************************/
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int      value;
    struct
    {
        unsigned int  dma_test0_y : 32; /* bit[0-31]: ������ */
    } reg;
} SOC_DSS_RCH_G_DMA_TEST0_UNION;
#endif
#define SOC_DSS_RCH_G_DMA_TEST0_dma_test0_y_START  (0)
#define SOC_DSS_RCH_G_DMA_TEST0_dma_test0_y_END    (31)


/*****************************************************************************
 �ṹ��    : SOC_DSS_RCH_G_DMA_TEST1_UNION
 �ṹ˵��  : DMA_TEST1 �Ĵ����ṹ���塣��ַƫ����:0x0074����ֵ:0x00000000������:32
 �Ĵ���˵��: ��ά�ɲ�Ĵ���
*****************************************************************************/
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int      value;
    struct
    {
        unsigned int  dma_test1_y : 32; /* bit[0-31]: ������ */
    } reg;
} SOC_DSS_RCH_G_DMA_TEST1_UNION;
#endif
#define SOC_DSS_RCH_G_DMA_TEST1_dma_test1_y_START  (0)
#define SOC_DSS_RCH_G_DMA_TEST1_dma_test1_y_END    (31)


/*****************************************************************************
 �ṹ��    : SOC_DSS_RCH_G_DMA_TEST3_UNION
 �ṹ˵��  : DMA_TEST3 �Ĵ����ṹ���塣��ַƫ����:0x0078����ֵ:0x00000000������:32
 �Ĵ���˵��: ��ά�ɲ�Ĵ���
*****************************************************************************/
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int      value;
    struct
    {
        unsigned int  dma_test3_y : 32; /* bit[0-31]: ������ */
    } reg;
} SOC_DSS_RCH_G_DMA_TEST3_UNION;
#endif
#define SOC_DSS_RCH_G_DMA_TEST3_dma_test3_y_START  (0)
#define SOC_DSS_RCH_G_DMA_TEST3_dma_test3_y_END    (31)


/*****************************************************************************
 �ṹ��    : SOC_DSS_RCH_G_DMA_TEST4_UNION
 �ṹ˵��  : DMA_TEST4 �Ĵ����ṹ���塣��ַƫ����:0x007C����ֵ:0x00000000������:32
 �Ĵ���˵��: ��ά�ɲ�Ĵ���
*****************************************************************************/
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int      value;
    struct
    {
        unsigned int  dma_test4_y : 32; /* bit[0-31]: ������ */
    } reg;
} SOC_DSS_RCH_G_DMA_TEST4_UNION;
#endif
#define SOC_DSS_RCH_G_DMA_TEST4_dma_test4_y_START  (0)
#define SOC_DSS_RCH_G_DMA_TEST4_dma_test4_y_END    (31)


/*****************************************************************************
 �ṹ��    : SOC_DSS_RCH_G_DMA_STATUS_Y_UNION
 �ṹ˵��  : DMA_STATUS_Y �Ĵ����ṹ���塣��ַƫ����:0x0080����ֵ:0x00000000������:32
 �Ĵ���˵��: ״̬�ϱ��Ĵ���
*****************************************************************************/
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int      value;
    struct
    {
        unsigned int  dma_status_y : 32; /* bit[0-31]: ������ */
    } reg;
} SOC_DSS_RCH_G_DMA_STATUS_Y_UNION;
#endif
#define SOC_DSS_RCH_G_DMA_STATUS_Y_dma_status_y_START  (0)
#define SOC_DSS_RCH_G_DMA_STATUS_Y_dma_status_y_END    (31)


/*****************************************************************************
 �ṹ��    : SOC_DSS_RCH_G_CH_RD_SHADOW_UNION
 �ṹ˵��  : CH_RD_SHADOW �Ĵ����ṹ���塣��ַƫ����:0x00D0����ֵ:0x00000000������:32
 �Ĵ���˵��: ���Ĵ���ѡ��
*****************************************************************************/
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int      value;
    struct
    {
        unsigned int  rwch_rd_shadow : 1;  /* bit[0]   : ���Ĵ���ѡ��
                                                         0�������Ĵ���
                                                         1��Ӱ�ӼĴ��� */
        unsigned int  reserved       : 31; /* bit[1-31]: ���� */
    } reg;
} SOC_DSS_RCH_G_CH_RD_SHADOW_UNION;
#endif
#define SOC_DSS_RCH_G_CH_RD_SHADOW_rwch_rd_shadow_START  (0)
#define SOC_DSS_RCH_G_CH_RD_SHADOW_rwch_rd_shadow_END    (0)


/*****************************************************************************
 �ṹ��    : SOC_DSS_RCH_G_CH_CTL_UNION
 �ṹ˵��  : CH_CTL �Ĵ����ṹ���塣��ַƫ����:0x00D4����ֵ:0x0000F000������:32
 �Ĵ���˵��: ͨ�����ƼĴ���
*****************************************************************************/
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int      value;
    struct
    {
        unsigned int  ch_en          : 1;  /* bit[0]    : RCH��WCHʹ�� */
        unsigned int  ch_version_sel : 1;  /* bit[1]    : 0��K3V3ԭ���ܰ汾��
                                                          1������ */
        unsigned int  ch_afbcd_en    : 1;  /* bit[2]    : 0���ر�ѹ������
                                                          1������ѹ������ */
        unsigned int  ch_block_en    : 1;  /* bit[3]    : 0��frameģʽ��
                                                          1��blockģʽ�� */
        unsigned int  reserved_0     : 8;  /* bit[4-11] : ���� */
        unsigned int  ch_frm_end_dly : 4;  /* bit[12-15]: ���ݴ���֮���ӳ������ĳ�frame_end���üĴ�����ʾ�ӳٵ����� */
        unsigned int  ch_block_h     : 13; /* bit[16-28]: blockģʽ����Ч����ʾ��ǰblock�ĸ߶� */
        unsigned int  reserved_1     : 3;  /* bit[29-31]: ���� */
    } reg;
} SOC_DSS_RCH_G_CH_CTL_UNION;
#endif
#define SOC_DSS_RCH_G_CH_CTL_ch_en_START           (0)
#define SOC_DSS_RCH_G_CH_CTL_ch_en_END             (0)
#define SOC_DSS_RCH_G_CH_CTL_ch_version_sel_START  (1)
#define SOC_DSS_RCH_G_CH_CTL_ch_version_sel_END    (1)
#define SOC_DSS_RCH_G_CH_CTL_ch_afbcd_en_START     (2)
#define SOC_DSS_RCH_G_CH_CTL_ch_afbcd_en_END       (2)
#define SOC_DSS_RCH_G_CH_CTL_ch_block_en_START     (3)
#define SOC_DSS_RCH_G_CH_CTL_ch_block_en_END       (3)
#define SOC_DSS_RCH_G_CH_CTL_ch_frm_end_dly_START  (12)
#define SOC_DSS_RCH_G_CH_CTL_ch_frm_end_dly_END    (15)
#define SOC_DSS_RCH_G_CH_CTL_ch_block_h_START      (16)
#define SOC_DSS_RCH_G_CH_CTL_ch_block_h_END        (28)


/*****************************************************************************
 �ṹ��    : SOC_DSS_RCH_G_CH_SECU_EN_UNION
 �ṹ˵��  : CH_SECU_EN �Ĵ����ṹ���塣��ַƫ����:0x00D8����ֵ:0x00000000������:32
 �Ĵ���˵��: ͨ����ȫʹ��
*****************************************************************************/
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int      value;
    struct
    {
        unsigned int  ch_secu_en : 1;  /* bit[0]   : 0���ǰ�ȫ
                                                     1����ȫ */
        unsigned int  reserved   : 31; /* bit[1-31]: ���� */
    } reg;
} SOC_DSS_RCH_G_CH_SECU_EN_UNION;
#endif
#define SOC_DSS_RCH_G_CH_SECU_EN_ch_secu_en_START  (0)
#define SOC_DSS_RCH_G_CH_SECU_EN_ch_secu_en_END    (0)


/*****************************************************************************
 �ṹ��    : SOC_DSS_RCH_G_CH_SW_END_REQ_UNION
 �ṹ˵��  : CH_SW_END_REQ �Ĵ����ṹ���塣��ַƫ����:0x00DC����ֵ:0x00000000������:32
 �Ĵ���˵��: �����峡�Ĵ���
*****************************************************************************/
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int      value;
    struct
    {
        unsigned int  ch_sw_end_req : 1;  /* bit[0]   : ����д1�����峡��������ɺ��λ�Զ����㡣 */
        unsigned int  reserved      : 31; /* bit[1-31]: ���� */
    } reg;
} SOC_DSS_RCH_G_CH_SW_END_REQ_UNION;
#endif
#define SOC_DSS_RCH_G_CH_SW_END_REQ_ch_sw_end_req_START  (0)
#define SOC_DSS_RCH_G_CH_SW_END_REQ_ch_sw_end_req_END    (0)


/*****************************************************************************
 �ṹ��    : SOC_DSS_RCH_G_CH_CLK_SEL_UNION
 �ṹ˵��  : CH_CLK_SEL �Ĵ����ṹ���塣��ַƫ����:0x00E0����ֵ:0xFFFFFFFF������:32
 �Ĵ���˵��: һ��ģ��ʱ��ѡ���ź�
*****************************************************************************/
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int      value;
    struct
    {
        unsigned int  ch_clk_sel : 32; /* bit[0-31]: ��һ��ģ���ʱ��ѡ���źţ�
                                                     1����ʾǿ�ƴ�ʱ�ӡ�
                                                     0����ʾ��Ҫ����������Ӳ����ʱ��ʹ����������ر�ʱ��
                                                     bit0������apb��
                                                     bit1������ch_ctl��
                                                     bit2������reg��
                                                     bit3������dma��afbcd��
                                                     bit4������dfc��
                                                     bit5������gscf��
                                                     bit6��������
                                                     bit7������sharp��
                                                     bit8��������
                                                     bit9������csc��
                                                     bit10������rot��
                                                     bit11������vpp��
                                                     bit12������postclip��
                                                     bit13-29��reserved��
                                                     bit30������dma_buf��
                                                     bit31��reserved�� */
    } reg;
} SOC_DSS_RCH_G_CH_CLK_SEL_UNION;
#endif
#define SOC_DSS_RCH_G_CH_CLK_SEL_ch_clk_sel_START  (0)
#define SOC_DSS_RCH_G_CH_CLK_SEL_ch_clk_sel_END    (31)


/*****************************************************************************
 �ṹ��    : SOC_DSS_RCH_G_CH_CLK_EN_UNION
 �ṹ˵��  : CH_CLK_EN �Ĵ����ṹ���塣��ַƫ����:0x00E4����ֵ:0xFFFFFFFF������:32
 �Ĵ���˵��: һ��ģ��ʱ��ʹ���ź�
*****************************************************************************/
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int      value;
    struct
    {
        unsigned int  ch_clk_en : 32; /* bit[0-31]: ��һ��ģ�������ʱ��ʹ���ź�
                                                    1����ʾ����ʱ��ʹ����Ч������Ӳ������
                                                    0����ʾ����ʱ��ʹ����Ч����ֹӲ������
                                                    bit0������apb��
                                                    bit1������ch_ctl��
                                                    bit2������reg��
                                                    bit3������dma��afbcd��
                                                    bit4������dfc��
                                                    bit5������gscf��
                                                    bit6��������
                                                    bit7������sharp��
                                                    bit8��������
                                                    bit9������csc��
                                                    bit10������rot��
                                                    bit11������vpp��
                                                    bit12������postclip��
                                                    bit13-29��reserved��
                                                    bit30������dma_buf��
                                                    bit31��reserved�� */
    } reg;
} SOC_DSS_RCH_G_CH_CLK_EN_UNION;
#endif
#define SOC_DSS_RCH_G_CH_CLK_EN_ch_clk_en_START  (0)
#define SOC_DSS_RCH_G_CH_CLK_EN_ch_clk_en_END    (31)


/*****************************************************************************
 �ṹ��    : SOC_DSS_RCH_G_DFC_DISP_SIZE_UNION
 �ṹ˵��  : DFC_DISP_SIZE �Ĵ����ṹ���塣��ַƫ����:0x0100����ֵ:0x00000000������:32
 �Ĵ���˵��: ͼ���С
*****************************************************************************/
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int      value;
    struct
    {
        unsigned int  dfc_size_vrt : 13; /* bit[0-12] : ����DFC��ͼ��Ĵ�ֱ�߶�-1 */
        unsigned int  reserved_0   : 3;  /* bit[13-15]: ���� */
        unsigned int  dfc_size_hrz : 13; /* bit[16-28]: ����DFC��ͼ��ÿ�д����������-1��������2pixel������4pxiel���䣬����SIZE_HRZ+1����Ϊ2����4�ı����� */
        unsigned int  reserved_1   : 3;  /* bit[29-31]: ���� */
    } reg;
} SOC_DSS_RCH_G_DFC_DISP_SIZE_UNION;
#endif
#define SOC_DSS_RCH_G_DFC_DISP_SIZE_dfc_size_vrt_START  (0)
#define SOC_DSS_RCH_G_DFC_DISP_SIZE_dfc_size_vrt_END    (12)
#define SOC_DSS_RCH_G_DFC_DISP_SIZE_dfc_size_hrz_START  (16)
#define SOC_DSS_RCH_G_DFC_DISP_SIZE_dfc_size_hrz_END    (28)


/*****************************************************************************
 �ṹ��    : SOC_DSS_RCH_G_DFC_PIX_IN_NUM_UNION
 �ṹ˵��  : DFC_PIX_IN_NUM �Ĵ����ṹ���塣��ַƫ����:0x0104����ֵ:0x00000000������:32
 �Ĵ���˵��: �������������
*****************************************************************************/
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int      value;
    struct
    {
        unsigned int  dfc_pix_in_num : 1;  /* bit[0]   : DFC��ͨ���������дͨ�������������Ŀ
                                                         0:2pixel (RDMA�������ÿ����Ϊ32bit����24bit���� ��RGB888,YUV444)
                                                         1:4pixel (RDMA�������ÿ����Ϊ16bit���� ��RGB565,XRGB1555,XRGB4444��YUV422) */
        unsigned int  reserved       : 31; /* bit[1-31]: ���� */
    } reg;
} SOC_DSS_RCH_G_DFC_PIX_IN_NUM_UNION;
#endif
#define SOC_DSS_RCH_G_DFC_PIX_IN_NUM_dfc_pix_in_num_START  (0)
#define SOC_DSS_RCH_G_DFC_PIX_IN_NUM_dfc_pix_in_num_END    (0)


/*****************************************************************************
 �ṹ��    : SOC_DSS_RCH_G_DFC_GLB_ALPHA_UNION
 �ṹ˵��  : DFC_GLB_ALPHA �Ĵ����ṹ���塣��ַƫ����:0x0108����ֵ:0x00000000������:32
 �Ĵ���˵��: ͸��������
*****************************************************************************/
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int      value;
    struct
    {
        unsigned int  dfc_glb_alpha1 : 8;  /* bit[0-7]  : ��ARGB1555 AΪ1ʱѡ���͸�������� */
        unsigned int  dfc_glb_alpha0 : 8;  /* bit[8-15] : ��ARGB1555 AΪ0ʱѡ���͸�������� */
        unsigned int  reserved       : 16; /* bit[16-31]: ���� */
    } reg;
} SOC_DSS_RCH_G_DFC_GLB_ALPHA_UNION;
#endif
#define SOC_DSS_RCH_G_DFC_GLB_ALPHA_dfc_glb_alpha1_START  (0)
#define SOC_DSS_RCH_G_DFC_GLB_ALPHA_dfc_glb_alpha1_END    (7)
#define SOC_DSS_RCH_G_DFC_GLB_ALPHA_dfc_glb_alpha0_START  (8)
#define SOC_DSS_RCH_G_DFC_GLB_ALPHA_dfc_glb_alpha0_END    (15)


/*****************************************************************************
 �ṹ��    : SOC_DSS_RCH_G_DFC_DISP_FMT_UNION
 �ṹ˵��  : DFC_DISP_FMT �Ĵ����ṹ���塣��ַƫ����:0x010C����ֵ:0x00000000������:32
 �Ĵ���˵��: ��ʾ��ʽ
*****************************************************************************/
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int      value;
    struct
    {
        unsigned int  dfc_ax_swap : 1;  /* bit[0]   : AX �ߵ�λ�л�(RGBA->ARGB YUVA->AYUV)
                                                      0��������
                                                      1������ */
        unsigned int  dfc_img_fmt : 5;  /* bit[1-5] : ����ʱ�����ʽ/д�������ʽ
                                                      00000:RGB565
                                                      00001:XRGB4444
                                                      00010:ARGB4444
                                                      00011:XRGB1555
                                                      00100:ARGB1555
                                                      00101:XRGB8888
                                                      00110:ARGB8888
                                                      00111:BGR565
                                                      01000:XBGR4444
                                                      01001:ABGR4444
                                                      01010:XBGR1555
                                                      01011:ABGR1555
                                                      01100:XBGR8888
                                                      01101:ABGR8888
                                                      01110:YUV444
                                                      01111:YVU444
                                                      10000:YUYV422
                                                      10001:YVYU422
                                                      10010:VYUY422
                                                      10011:UYVY422 */
        unsigned int  dfc_uv_swap : 1;  /* bit[6]   : U��V������־��
                                                      0��������
                                                      1������ */
        unsigned int  dfc_rb_swap : 1;  /* bit[7]   : R��B������־��
                                                      0��������
                                                      1������ */
        unsigned int  reserved    : 24; /* bit[8-31]: ���� */
    } reg;
} SOC_DSS_RCH_G_DFC_DISP_FMT_UNION;
#endif
#define SOC_DSS_RCH_G_DFC_DISP_FMT_dfc_ax_swap_START  (0)
#define SOC_DSS_RCH_G_DFC_DISP_FMT_dfc_ax_swap_END    (0)
#define SOC_DSS_RCH_G_DFC_DISP_FMT_dfc_img_fmt_START  (1)
#define SOC_DSS_RCH_G_DFC_DISP_FMT_dfc_img_fmt_END    (5)
#define SOC_DSS_RCH_G_DFC_DISP_FMT_dfc_uv_swap_START  (6)
#define SOC_DSS_RCH_G_DFC_DISP_FMT_dfc_uv_swap_END    (6)
#define SOC_DSS_RCH_G_DFC_DISP_FMT_dfc_rb_swap_START  (7)
#define SOC_DSS_RCH_G_DFC_DISP_FMT_dfc_rb_swap_END    (7)


/*****************************************************************************
 �ṹ��    : SOC_DSS_RCH_G_DFC_CLIP_CTL_HRZ_UNION
 �ṹ˵��  : DFC_CLIP_CTL_HRZ �Ĵ����ṹ���塣��ַƫ����:0x0110����ֵ:0x00000000������:32
 �Ĵ���˵��: ˮƽ�ü�����
*****************************************************************************/
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int      value;
    struct
    {
        unsigned int  dfc_right_clip : 6;  /* bit[0-5]  : ͼ���ұ߽���CLIP���������� */
        unsigned int  reserved_0     : 10; /* bit[6-15] : ���� */
        unsigned int  dfc_left_clip  : 6;  /* bit[16-21]: ͼ����߽���CLIP���������� */
        unsigned int  reserved_1     : 10; /* bit[22-31]: ���� */
    } reg;
} SOC_DSS_RCH_G_DFC_CLIP_CTL_HRZ_UNION;
#endif
#define SOC_DSS_RCH_G_DFC_CLIP_CTL_HRZ_dfc_right_clip_START  (0)
#define SOC_DSS_RCH_G_DFC_CLIP_CTL_HRZ_dfc_right_clip_END    (5)
#define SOC_DSS_RCH_G_DFC_CLIP_CTL_HRZ_dfc_left_clip_START   (16)
#define SOC_DSS_RCH_G_DFC_CLIP_CTL_HRZ_dfc_left_clip_END     (21)


/*****************************************************************************
 �ṹ��    : SOC_DSS_RCH_G_DFC_CLIP_CTL_VRZ_UNION
 �ṹ˵��  : DFC_CLIP_CTL_VRZ �Ĵ����ṹ���塣��ַƫ����:0x0114����ֵ:0x00000000������:32
 �Ĵ���˵��: ��ֱ�ü�����
*****************************************************************************/
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int      value;
    struct
    {
        unsigned int  dfc_bot_clip : 6;  /* bit[0-5]  : ͼ��ױ߽���CLIP���������� */
        unsigned int  reserved_0   : 10; /* bit[6-15] : ���� */
        unsigned int  dfc_top_clip : 6;  /* bit[16-21]: ͼ�񶥱߽���CLIP���������� */
        unsigned int  reserved_1   : 10; /* bit[22-31]: ���� */
    } reg;
} SOC_DSS_RCH_G_DFC_CLIP_CTL_VRZ_UNION;
#endif
#define SOC_DSS_RCH_G_DFC_CLIP_CTL_VRZ_dfc_bot_clip_START  (0)
#define SOC_DSS_RCH_G_DFC_CLIP_CTL_VRZ_dfc_bot_clip_END    (5)
#define SOC_DSS_RCH_G_DFC_CLIP_CTL_VRZ_dfc_top_clip_START  (16)
#define SOC_DSS_RCH_G_DFC_CLIP_CTL_VRZ_dfc_top_clip_END    (21)


/*****************************************************************************
 �ṹ��    : SOC_DSS_RCH_G_DFC_CTL_CLIP_EN_UNION
 �ṹ˵��  : DFC_CTL_CLIP_EN �Ĵ����ṹ���塣��ַƫ����:0x0118����ֵ:0x00000000������:32
 �Ĵ���˵��: ͼ�����ʹ��
*****************************************************************************/
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int      value;
    struct
    {
        unsigned int  dfc_ctl_clip_enable : 1;  /* bit[0]   : ͼ�����ʹ�� */
        unsigned int  reserved            : 31; /* bit[1-31]: ���� */
    } reg;
} SOC_DSS_RCH_G_DFC_CTL_CLIP_EN_UNION;
#endif
#define SOC_DSS_RCH_G_DFC_CTL_CLIP_EN_dfc_ctl_clip_enable_START  (0)
#define SOC_DSS_RCH_G_DFC_CTL_CLIP_EN_dfc_ctl_clip_enable_END    (0)


/*****************************************************************************
 �ṹ��    : SOC_DSS_RCH_G_DFC_ICG_MODULE_UNION
 �ṹ˵��  : DFC_ICG_MODULE �Ĵ����ṹ���塣��ַƫ����:0x011C����ֵ:0x00000000������:32
 �Ĵ���˵��: ʱ���ſ�ģʽ
*****************************************************************************/
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int      value;
    struct
    {
        unsigned int  dfc_module_en : 1;  /* bit[0]   : 1'b1:��ģ��enable
                                                        1'b0:��ģ��disable */
        unsigned int  reserved      : 31; /* bit[1-31]: ���� */
    } reg;
} SOC_DSS_RCH_G_DFC_ICG_MODULE_UNION;
#endif
#define SOC_DSS_RCH_G_DFC_ICG_MODULE_dfc_module_en_START  (0)
#define SOC_DSS_RCH_G_DFC_ICG_MODULE_dfc_module_en_END    (0)


/*****************************************************************************
 �ṹ��    : SOC_DSS_RCH_G_DFC_DITHER_ENABLE_UNION
 �ṹ˵��  : DFC_DITHER_ENABLE �Ĵ����ṹ���塣��ַƫ����:0x0120����ֵ:0x00000000������:32
 �Ĵ���˵��: ��������ʹ��
*****************************************************************************/
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int      value;
    struct
    {
        unsigned int  dfc_dither_en : 1;  /* bit[0]   : 
                                                        ��������ʹ�� */
        unsigned int  reserved      : 31; /* bit[1-31]: ���� */
    } reg;
} SOC_DSS_RCH_G_DFC_DITHER_ENABLE_UNION;
#endif
#define SOC_DSS_RCH_G_DFC_DITHER_ENABLE_dfc_dither_en_START  (0)
#define SOC_DSS_RCH_G_DFC_DITHER_ENABLE_dfc_dither_en_END    (0)


/*****************************************************************************
 �ṹ��    : SOC_DSS_RCH_G_DFC_PADDING_CTL_UNION
 �ṹ˵��  : DFC_PADDING_CTL �Ĵ����ṹ���塣��ַƫ����:0x0124����ֵ:0x00000000������:32
 �Ĵ���˵��: �������ؿ���
*****************************************************************************/
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int      value;
    struct
    {
        unsigned int  dfc_left_pad       : 4;  /* bit[0-3]  : ��߽����������� */
        unsigned int  reserved_0         : 4;  /* bit[4-7]  : ���� */
        unsigned int  dfc_right_pad      : 4;  /* bit[8-11] : �ұ߽����������� */
        unsigned int  reserved_1         : 4;  /* bit[12-15]: ���� */
        unsigned int  dfc_top_pad        : 4;  /* bit[16-19]: �ϱ߽����������� */
        unsigned int  reserved_2         : 4;  /* bit[20-23]: ���� */
        unsigned int  dfc_bot_pad        : 4;  /* bit[24-27]: �±߽����������� */
        unsigned int  reserved_3         : 3;  /* bit[28-30]: ���� */
        unsigned int  dfc_ctl_pad_enable : 1;  /* bit[31]   : ��������ʹ�� */
    } reg;
} SOC_DSS_RCH_G_DFC_PADDING_CTL_UNION;
#endif
#define SOC_DSS_RCH_G_DFC_PADDING_CTL_dfc_left_pad_START        (0)
#define SOC_DSS_RCH_G_DFC_PADDING_CTL_dfc_left_pad_END          (3)
#define SOC_DSS_RCH_G_DFC_PADDING_CTL_dfc_right_pad_START       (8)
#define SOC_DSS_RCH_G_DFC_PADDING_CTL_dfc_right_pad_END         (11)
#define SOC_DSS_RCH_G_DFC_PADDING_CTL_dfc_top_pad_START         (16)
#define SOC_DSS_RCH_G_DFC_PADDING_CTL_dfc_top_pad_END           (19)
#define SOC_DSS_RCH_G_DFC_PADDING_CTL_dfc_bot_pad_START         (24)
#define SOC_DSS_RCH_G_DFC_PADDING_CTL_dfc_bot_pad_END           (27)
#define SOC_DSS_RCH_G_DFC_PADDING_CTL_dfc_ctl_pad_enable_START  (31)
#define SOC_DSS_RCH_G_DFC_PADDING_CTL_dfc_ctl_pad_enable_END    (31)


/*****************************************************************************
 �ṹ��    : SOC_DSS_RCH_G_SCF_EN_HSCL_STR_UNION
 �ṹ˵��  : SCF_EN_HSCL_STR �Ĵ����ṹ���塣��ַƫ����:0x0200����ֵ:0x00000000������:32
 �Ĵ���˵��: ˮƽ��������ʹ��
*****************************************************************************/
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int      value;
    struct
    {
        unsigned int  scf_en_hscl_str   : 1;  /* bit[0]   : ˮƽ��������ʹ�ܣ�����EN_HSCL��Чʱ��Ч
                                                            0��ˮƽ�˲�����
                                                            1��ˮƽ�������� */
        unsigned int  scf_en_hscl_str_a : 1;  /* bit[1]   : alphaˮƽ��������ʹ�ܣ�����EN_HSCL��Чʱ��Ч
                                                            0��ˮƽ�˲�����
                                                            1��ˮƽ�������� */
        unsigned int  reserved          : 30; /* bit[2-31]: ���� */
    } reg;
} SOC_DSS_RCH_G_SCF_EN_HSCL_STR_UNION;
#endif
#define SOC_DSS_RCH_G_SCF_EN_HSCL_STR_scf_en_hscl_str_START    (0)
#define SOC_DSS_RCH_G_SCF_EN_HSCL_STR_scf_en_hscl_str_END      (0)
#define SOC_DSS_RCH_G_SCF_EN_HSCL_STR_scf_en_hscl_str_a_START  (1)
#define SOC_DSS_RCH_G_SCF_EN_HSCL_STR_scf_en_hscl_str_a_END    (1)


/*****************************************************************************
 �ṹ��    : SOC_DSS_RCH_G_SCF_EN_VSCL_STR_UNION
 �ṹ˵��  : SCF_EN_VSCL_STR �Ĵ����ṹ���塣��ַƫ����:0x0204����ֵ:0x00000000������:32
 �Ĵ���˵��: ��ֱ��������ʹ��
*****************************************************************************/
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int      value;
    struct
    {
        unsigned int  scf_en_vscl_str   : 1;  /* bit[0]   : ��ֱ��������ʹ�ܣ�����EN_VSCL��Чʱ��Ч
                                                            0����ֱ�˲�����
                                                            1����ֱ��������
                                                            ������ǽ�ʡ����������RDMAģ������ֱ�����������������С */
        unsigned int  scf_en_vscl_str_a : 1;  /* bit[1]   : alpha��ֱ��������ʹ�ܣ�����EN_VSCL��Чʱ��Ч
                                                            0����ֱ�˲�����
                                                            1����ֱ��������
                                                            ������ǽ�ʡ����������RDMAģ������ֱ�����������������С */
        unsigned int  reserved          : 30; /* bit[2-31]: ���� */
    } reg;
} SOC_DSS_RCH_G_SCF_EN_VSCL_STR_UNION;
#endif
#define SOC_DSS_RCH_G_SCF_EN_VSCL_STR_scf_en_vscl_str_START    (0)
#define SOC_DSS_RCH_G_SCF_EN_VSCL_STR_scf_en_vscl_str_END      (0)
#define SOC_DSS_RCH_G_SCF_EN_VSCL_STR_scf_en_vscl_str_a_START  (1)
#define SOC_DSS_RCH_G_SCF_EN_VSCL_STR_scf_en_vscl_str_a_END    (1)


/*****************************************************************************
 �ṹ��    : SOC_DSS_RCH_G_SCF_H_V_ORDER_UNION
 �ṹ˵��  : SCF_H_V_ORDER �Ĵ����ṹ���塣��ַƫ����:0x0208����ֵ:0x00000000������:32
 �Ĵ���˵��: ˮƽ�ʹ�ֱ�˲��Լ�video����ģʽ����
*****************************************************************************/
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int      value;
    struct
    {
        unsigned int  scf_h_v_order : 1;  /* bit[0]   : ˮƽ�ʹ�ֱ�˲���˳��
                                                        0��ˮƽ����
                                                        1��ˮƽ����
                                                        �Ƽ��Ŵ�����£�ֻҪˮƽ�Ŵ����Ŵ󣩣�ʹ��ˮƽ������ʽ��Ҳ���ǸüĴ���Ϊ1;���������ʹ��ˮƽ������ʽ��Ҳ���ǸüĴ�����Ϊ0 */
        unsigned int  reserved      : 31; /* bit[1-31]: ���� */
    } reg;
} SOC_DSS_RCH_G_SCF_H_V_ORDER_UNION;
#endif
#define SOC_DSS_RCH_G_SCF_H_V_ORDER_scf_h_v_order_START  (0)
#define SOC_DSS_RCH_G_SCF_H_V_ORDER_scf_h_v_order_END    (0)


/*****************************************************************************
 �ṹ��    : SOC_DSS_RCH_G_SCF_CH_CORE_GT_UNION
 �ṹ˵��  : SCF_CH_CORE_GT �Ĵ����ṹ���塣��ַƫ����:0x020C����ֵ:0x00000000������:32
 �Ĵ���˵��: ͨ��ʱ���ſ�
*****************************************************************************/
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int      value;
    struct
    {
        unsigned int  scf_a_core_gt : 1;  /* bit[0]   : ͨ��alpha�����ſ�ʹ�ܣ�
                                                        1����ʾ��ͨ��alpha�����ڻ򲻹���ʱ�����Թر�ͨ��alpha����߼�ʱ��,Ӳ���Զ�ʱ���ſأ�
                                                        0��ͨ��alphaʹ�ܣ�ʱ�Ӳ����Թر�,����ǿ�ƴ�ʱ�ӣ� */
        unsigned int  scf_r_core_gt : 1;  /* bit[1]   : ͨ��R��Y�����ſ�ʹ�ܣ�
                                                        1����ʾ��ͨ��R��Y�����ڻ򲻹���ʱ�����Թر�ͨ��R��Y����߼�ʱ��,Ӳ���Զ�ʱ���ſأ�
                                                        0��ͨ��R��Yʹ�ܣ�ʱ�Ӳ����Թر�,����ǿ�ƴ�ʱ�ӣ� */
        unsigned int  scf_g_core_gt : 1;  /* bit[2]   : ͨ��G��U�����ſ�ʹ�ܣ�
                                                        1����ʾ��ͨ��G��U�����ڻ򲻹���ʱ�����Թر�ͨ��G��U����߼�ʱ��,Ӳ���Զ�ʱ���ſأ�
                                                        0��ͨ��G��Uʹ�ܣ�ʱ�Ӳ����Թر�,����ǿ�ƴ�ʱ�ӣ� */
        unsigned int  scf_b_core_gt : 1;  /* bit[3]   : ͨ��B��V�����ſ�ʹ�ܣ�
                                                        1����ʾ��ͨ��B��V�����ڻ򲻹���ʱ�����Թر�ͨ��B��V����߼�ʱ��,Ӳ���Զ�ʱ���ſأ�
                                                        0��ͨ��B��Vʹ�ܣ�ʱ�Ӳ����Թر�,����ǿ�ƴ�ʱ�ӣ� */
        unsigned int  reserved      : 28; /* bit[4-31]: ���� */
    } reg;
} SOC_DSS_RCH_G_SCF_CH_CORE_GT_UNION;
#endif
#define SOC_DSS_RCH_G_SCF_CH_CORE_GT_scf_a_core_gt_START  (0)
#define SOC_DSS_RCH_G_SCF_CH_CORE_GT_scf_a_core_gt_END    (0)
#define SOC_DSS_RCH_G_SCF_CH_CORE_GT_scf_r_core_gt_START  (1)
#define SOC_DSS_RCH_G_SCF_CH_CORE_GT_scf_r_core_gt_END    (1)
#define SOC_DSS_RCH_G_SCF_CH_CORE_GT_scf_g_core_gt_START  (2)
#define SOC_DSS_RCH_G_SCF_CH_CORE_GT_scf_g_core_gt_END    (2)
#define SOC_DSS_RCH_G_SCF_CH_CORE_GT_scf_b_core_gt_START  (3)
#define SOC_DSS_RCH_G_SCF_CH_CORE_GT_scf_b_core_gt_END    (3)


/*****************************************************************************
 �ṹ��    : SOC_DSS_RCH_G_SCF_INPUT_WIDTH_HEIGHT_UNION
 �ṹ˵��  : SCF_INPUT_WIDTH_HEIGHT �Ĵ����ṹ���塣��ַƫ����:0x0210����ֵ:0x00000000������:32
 �Ĵ���˵��: �������
*****************************************************************************/
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int      value;
    struct
    {
        unsigned int  scf_input_height : 13; /* bit[0-12] : ʵ������߶� - 1;�üĴ�������ֵ���ڵ���15 */
        unsigned int  reserved_0       : 3;  /* bit[13-15]: ���� */
        unsigned int  scf_input_width  : 13; /* bit[16-28]: ʵ��������� - 1;�üĴ�������ֵ���ڵ���15,scf_h_v_order�����Ƽ�����ʱ����ˮƽ�Ŵ�������С�ڵ���1199�� */
        unsigned int  reserved_1       : 3;  /* bit[29-31]: ���� */
    } reg;
} SOC_DSS_RCH_G_SCF_INPUT_WIDTH_HEIGHT_UNION;
#endif
#define SOC_DSS_RCH_G_SCF_INPUT_WIDTH_HEIGHT_scf_input_height_START  (0)
#define SOC_DSS_RCH_G_SCF_INPUT_WIDTH_HEIGHT_scf_input_height_END    (12)
#define SOC_DSS_RCH_G_SCF_INPUT_WIDTH_HEIGHT_scf_input_width_START   (16)
#define SOC_DSS_RCH_G_SCF_INPUT_WIDTH_HEIGHT_scf_input_width_END     (28)


/*****************************************************************************
 �ṹ��    : SOC_DSS_RCH_G_SCF_OUTPUT_WIDTH_HEIGHT_UNION
 �ṹ˵��  : SCF_OUTPUT_WIDTH_HEIGHT �Ĵ����ṹ���塣��ַƫ����:0x0214����ֵ:0x00000000������:32
 �Ĵ���˵��: �������
*****************************************************************************/
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int      value;
    struct
    {
        unsigned int  scf_output_height : 13; /* bit[0-12] : ʵ������߶� - 1���üĴ�������ֵ���ڵ���15�� */
        unsigned int  reserved_0        : 3;  /* bit[13-15]: ���� */
        unsigned int  scf_output_width  : 13; /* bit[16-28]: ʵ��������� - 1;�üĴ�������ֵ���ڵ���15��scf_h_v_order�����Ƽ�����ʱ����ˮƽ��С�������С�ڵ���1199�� */
        unsigned int  reserved_1        : 3;  /* bit[29-31]: ���� */
    } reg;
} SOC_DSS_RCH_G_SCF_OUTPUT_WIDTH_HEIGHT_UNION;
#endif
#define SOC_DSS_RCH_G_SCF_OUTPUT_WIDTH_HEIGHT_scf_output_height_START  (0)
#define SOC_DSS_RCH_G_SCF_OUTPUT_WIDTH_HEIGHT_scf_output_height_END    (12)
#define SOC_DSS_RCH_G_SCF_OUTPUT_WIDTH_HEIGHT_scf_output_width_START   (16)
#define SOC_DSS_RCH_G_SCF_OUTPUT_WIDTH_HEIGHT_scf_output_width_END     (28)


/*****************************************************************************
 �ṹ��    : SOC_DSS_RCH_G_SCF_COEF_MEM_CTRL_UNION
 �ṹ˵��  : SCF_COEF_MEM_CTRL �Ĵ����ṹ���塣��ַƫ����:0x0218����ֵ:0x00000000������:32
 �Ĵ���˵��: ����MEM�͹��Ŀ���
*****************************************************************************/
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int      value;
    struct
    {
        unsigned int  scf_hcoef_mem_ctrl : 4;  /* bit[0-3] : �����üĴ�����ˮƽ�˲�ϵ��LUT�������ã�
                                                             [3] mem_ctrl_auto_en , �Զ�ģʽ����������ģʽѡ��,0�Զ�ģʽ��1��������ģʽ 
                                                             [2]: ��������ģʽ����Ч��Ϊ1��ʾ����Shut Downģʽ
                                                             [1]: ��������ģʽ����Ч��Ϊ1��ʾ����Deep Sleepģʽ
                                                             [0]: ��������ģʽ����Ч��Ϊ1��ʾ����Sleepģʽ */
        unsigned int  scf_vcoef_mem_ctrl : 4;  /* bit[4-7] : �����üĴ�������ֱ�˲�ϵ��LUT�������ã�
                                                             [3] mem_ctrl_auto_en , �Զ�ģʽ����������ģʽѡ��,0�Զ�ģʽ��1��������ģʽ 
                                                             [2]: ��������ģʽ����Ч��Ϊ1��ʾ����Shut Downģʽ
                                                             [1]: ��������ģʽ����Ч��Ϊ1��ʾ����Deep Sleepģʽ
                                                             [0]: ��������ģʽ����Ч��Ϊ1��ʾ����Sleepģʽ */
        unsigned int  reserved           : 24; /* bit[8-31]: ���� */
    } reg;
} SOC_DSS_RCH_G_SCF_COEF_MEM_CTRL_UNION;
#endif
#define SOC_DSS_RCH_G_SCF_COEF_MEM_CTRL_scf_hcoef_mem_ctrl_START  (0)
#define SOC_DSS_RCH_G_SCF_COEF_MEM_CTRL_scf_hcoef_mem_ctrl_END    (3)
#define SOC_DSS_RCH_G_SCF_COEF_MEM_CTRL_scf_vcoef_mem_ctrl_START  (4)
#define SOC_DSS_RCH_G_SCF_COEF_MEM_CTRL_scf_vcoef_mem_ctrl_END    (7)


/*****************************************************************************
 �ṹ��    : SOC_DSS_RCH_G_SCF_EN_HSCL_UNION
 �ṹ˵��  : SCF_EN_HSCL �Ĵ����ṹ���塣��ַƫ����:0x021C����ֵ:0x00000000������:32
 �Ĵ���˵��: ˮƽ����ʹ���ź�
*****************************************************************************/
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int      value;
    struct
    {
        unsigned int  scf_en_hscl_en : 1;  /* bit[0]   : ˮƽ����ʹ���ź� */
        unsigned int  reserved       : 31; /* bit[1-31]: ���� */
    } reg;
} SOC_DSS_RCH_G_SCF_EN_HSCL_UNION;
#endif
#define SOC_DSS_RCH_G_SCF_EN_HSCL_scf_en_hscl_en_START  (0)
#define SOC_DSS_RCH_G_SCF_EN_HSCL_scf_en_hscl_en_END    (0)


/*****************************************************************************
 �ṹ��    : SOC_DSS_RCH_G_SCF_EN_VSCL_UNION
 �ṹ˵��  : SCF_EN_VSCL �Ĵ����ṹ���塣��ַƫ����:0x0220����ֵ:0x00000000������:32
 �Ĵ���˵��: ��ֱ����ʹ���ź�
*****************************************************************************/
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int      value;
    struct
    {
        unsigned int  scf_en_vscl_en    : 1;  /* bit[0]   : ��ֱ����ʹ���ź� */
        unsigned int  scf_out_buffer_en : 1;  /* bit[1]   : ����ֱ��������ͼ��߶�С�ڵ�������ͼ��߶�ʱ��ʹ��scf����buffer���������ʹ�����üĴ�����
                                                            1.ʹ����buffer��������棻
                                                            0.��ʹ����buffer��������� */
        unsigned int  reserved          : 30; /* bit[2-31]: ���� */
    } reg;
} SOC_DSS_RCH_G_SCF_EN_VSCL_UNION;
#endif
#define SOC_DSS_RCH_G_SCF_EN_VSCL_scf_en_vscl_en_START     (0)
#define SOC_DSS_RCH_G_SCF_EN_VSCL_scf_en_vscl_en_END       (0)
#define SOC_DSS_RCH_G_SCF_EN_VSCL_scf_out_buffer_en_START  (1)
#define SOC_DSS_RCH_G_SCF_EN_VSCL_scf_out_buffer_en_END    (1)


/*****************************************************************************
 �ṹ��    : SOC_DSS_RCH_G_SCF_ACC_HSCL_UNION
 �ṹ˵��  : SCF_ACC_HSCL �Ĵ����ṹ���塣��ַƫ����:0x0224����ֵ:0x00000000������:32
 �Ĵ���˵��: ˮƽ��ʼ��λ
*****************************************************************************/
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int      value;
    struct
    {
        unsigned int  scf_acc_hscl : 30; /* bit[0-29] : ˮƽ��ʼ��λ������ˮƽSC��ʲôλ�ÿ�ʼ�����š�
                                                        VSCF������[17:0]λΪС�����֣�[29:18]λΪ�������֡�
                                                        GSCF������[17:2]λΪС�����֣�[29:18]λΪ��������,[1:0]λ������ */
        unsigned int  reserved     : 2;  /* bit[30-31]: ���� */
    } reg;
} SOC_DSS_RCH_G_SCF_ACC_HSCL_UNION;
#endif
#define SOC_DSS_RCH_G_SCF_ACC_HSCL_scf_acc_hscl_START  (0)
#define SOC_DSS_RCH_G_SCF_ACC_HSCL_scf_acc_hscl_END    (29)


/*****************************************************************************
 �ṹ��    : SOC_DSS_RCH_G_SCF_ACC_HSCL1_UNION
 �ṹ˵��  : SCF_ACC_HSCL1 �Ĵ����ṹ���塣��ַƫ����:0x0228����ֵ:0x00000000������:32
 �Ĵ���˵��: ͨ��1ˮƽ��λ�����ƫ����
*****************************************************************************/
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int      value;
    struct
    {
        unsigned int  scf_acc_hscl1 : 19; /* bit[0-18] : ͨ��1ˮƽ��λ�����ƫ�����������ACC_HSCL�� */
        unsigned int  reserved      : 13; /* bit[19-31]: ���� */
    } reg;
} SOC_DSS_RCH_G_SCF_ACC_HSCL1_UNION;
#endif
#define SOC_DSS_RCH_G_SCF_ACC_HSCL1_scf_acc_hscl1_START  (0)
#define SOC_DSS_RCH_G_SCF_ACC_HSCL1_scf_acc_hscl1_END    (18)


/*****************************************************************************
 �ṹ��    : SOC_DSS_RCH_G_SCF_INC_HSCL_UNION
 �ṹ˵��  : SCF_INC_HSCL �Ĵ����ṹ���塣��ַƫ����:0x0234����ֵ:0x00005000������:32
 �Ĵ���˵��: ˮƽ���ű���
*****************************************************************************/
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int      value;
    struct
    {
        unsigned int  scf_inc_hscl : 24; /* bit[0-23] : ˮƽ���ű��������㹫ʽΪ
                                                        inc_hscl = floor((input_width*262144+131072-acc_hscl)/output_width)
                                                        �Ĵ�������ֵinput_widthΪʵ���������-1��
                                                        �Ĵ�������ֵoutput_widthΪʵ���������-1��
                                                        acc_hscl��SCF���õļĴ���ֵ��ˮƽ��ʼ��λ����
                                                        floor()Ϊ����ȡ����
                                                        
                                                        ˮƽ���ű����Ķ���Ϊr=ʵ�ʵ����ͼ�����/ʵ�ʵ�����ͼ����ȣ�
                                                        inc_hscl�ĵ�18����Ϊratio��С�����֣���6����Ϊ�������֡���������6���أ�֧��60�����£���60��������С���Ŵ�ı��������SCF_H_V_ORDER�����Ƽ����ã��Ŵ�������Ϊ60������60�������Ŵ󳡾���SCF_H_V_ORDER��Ϊ0�����Ŵ���Ϊmin(60,floor(1200/ʵ�ʵ�����ͼ����ȣ�)
                                                        ����min��ʾ2����ֵȡ��Сֵ��floor��ʾ����ȡ���� */
        unsigned int  reserved     : 8;  /* bit[24-31]: ���� */
    } reg;
} SOC_DSS_RCH_G_SCF_INC_HSCL_UNION;
#endif
#define SOC_DSS_RCH_G_SCF_INC_HSCL_scf_inc_hscl_START  (0)
#define SOC_DSS_RCH_G_SCF_INC_HSCL_scf_inc_hscl_END    (23)


/*****************************************************************************
 �ṹ��    : SOC_DSS_RCH_G_SCF_ACC_VSCL_UNION
 �ṹ˵��  : SCF_ACC_VSCL �Ĵ����ṹ���塣��ַƫ����:0x0238����ֵ:0x00000000������:32
 �Ĵ���˵��: ��ֱ��ʼ��λ
*****************************************************************************/
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int      value;
    struct
    {
        unsigned int  scf_acc_vscl : 30; /* bit[0-29] : ��ֱ��ʼ��λ��������ֱSC��ʲôλ�ÿ�ʼ�����ţ����е�18λΪС�����֣���12λΪ�������֡� */
        unsigned int  reserved     : 2;  /* bit[30-31]: ���� */
    } reg;
} SOC_DSS_RCH_G_SCF_ACC_VSCL_UNION;
#endif
#define SOC_DSS_RCH_G_SCF_ACC_VSCL_scf_acc_vscl_START  (0)
#define SOC_DSS_RCH_G_SCF_ACC_VSCL_scf_acc_vscl_END    (29)


/*****************************************************************************
 �ṹ��    : SOC_DSS_RCH_G_SCF_ACC_VSCL1_UNION
 �ṹ˵��  : SCF_ACC_VSCL1 �Ĵ����ṹ���塣��ַƫ����:0x023C����ֵ:0x00000000������:32
 �Ĵ���˵��: ͨ��1��ֱ��λ�����ƫ����
*****************************************************************************/
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int      value;
    struct
    {
        unsigned int  scf_acc_vscl1 : 19; /* bit[0-18] : ͨ��1��ֱ��λ�����ƫ�����������ACC_VSCL��
                                                         V5�汾Ϊ����ɫ��UV���������Y������ƫ��ֵ������Чλ��Ϊ17bit�з����� */
        unsigned int  reserved      : 13; /* bit[19-31]: ���� */
    } reg;
} SOC_DSS_RCH_G_SCF_ACC_VSCL1_UNION;
#endif
#define SOC_DSS_RCH_G_SCF_ACC_VSCL1_scf_acc_vscl1_START  (0)
#define SOC_DSS_RCH_G_SCF_ACC_VSCL1_scf_acc_vscl1_END    (18)


/*****************************************************************************
 �ṹ��    : SOC_DSS_RCH_G_SCF_INC_VSCL_UNION
 �ṹ˵��  : SCF_INC_VSCL �Ĵ����ṹ���塣��ַƫ����:0x0248����ֵ:0x00005000������:32
 �Ĵ���˵��: ��ֱ���ű���
*****************************************************************************/
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int      value;
    struct
    {
        unsigned int  scf_inc_vscl : 24; /* bit[0-23] : ��ֱ���ű��������㹫ʽ����Ϊ
                                                        inc_vscl = floor((intput_height*262144+131072-acc_vscl)/output_height)
                                                        �Ĵ�������ֵoutput_heightΪʵ������߶�-1��
                                                        �Ĵ�������ֵinput_heightΪʵ������߶�-1��
                                                        acc_vscl��SCF���õļĴ���ֵ����ֱ��ʼ��λ����
                                                        floor()Ϊ����ȡ����
                                                        
                                                        ��ֱ���ű����Ķ���Ϊ��ʵ�ʵ����ͼ��߶�/ʵ�ʵ�����ͼ��߶ȣ�
                                                        inc_vscl�ĵ�18����Ϊratio��С�����֣���6����Ϊ�������֡���������6���أ�֧��60�����£���60��������С�����Ŵ���Ϊ60������60������ */
        unsigned int  reserved     : 8;  /* bit[24-31]: ���� */
    } reg;
} SOC_DSS_RCH_G_SCF_INC_VSCL_UNION;
#endif
#define SOC_DSS_RCH_G_SCF_INC_VSCL_scf_inc_vscl_START  (0)
#define SOC_DSS_RCH_G_SCF_INC_VSCL_scf_inc_vscl_END    (23)


/*****************************************************************************
 �ṹ��    : SOC_DSS_RCH_G_SCF_EN_NONLINEAR_UNION
 �ṹ˵��  : SCF_EN_NONLINEAR �Ĵ����ṹ���塣��ַƫ����:0x024C����ֵ:0x00000000������:32
 �Ĵ���˵��: ����λ�Ĵ���
*****************************************************************************/
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int      value;
    struct
    {
        unsigned int  scf_sw_rst : 1;  /* bit[0]   : scfģ������λ���üĴ�����1��Ч */
        unsigned int  reserved   : 31; /* bit[1-31]: ���� */
    } reg;
} SOC_DSS_RCH_G_SCF_EN_NONLINEAR_UNION;
#endif
#define SOC_DSS_RCH_G_SCF_EN_NONLINEAR_scf_sw_rst_START  (0)
#define SOC_DSS_RCH_G_SCF_EN_NONLINEAR_scf_sw_rst_END    (0)


/*****************************************************************************
 �ṹ��    : SOC_DSS_RCH_G_SCF_EN_MMP_UNION
 �ṹ˵��  : SCF_EN_MMP �Ĵ����ṹ���塣��ַƫ����:0x027C����ֵ:0x00000001������:32
 �Ĵ���˵��: ���崦��ʹ���ź�
*****************************************************************************/
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int      value;
    struct
    {
        unsigned int  scf_en_mmp : 1;  /* bit[0]   : ���崦��ʹ���źţ�1��ʾʹ�ܣ�0��ʾ��ʹ�� */
        unsigned int  reserved   : 31; /* bit[1-31]: ���� */
    } reg;
} SOC_DSS_RCH_G_SCF_EN_MMP_UNION;
#endif
#define SOC_DSS_RCH_G_SCF_EN_MMP_scf_en_mmp_START  (0)
#define SOC_DSS_RCH_G_SCF_EN_MMP_scf_en_mmp_END    (0)


/*****************************************************************************
 �ṹ��    : SOC_DSS_RCH_G_SCF_DB_H0_UNION
 �ṹ˵��  : SCF_DB_H0 �Ĵ����ṹ���塣��ַƫ����:0x0280����ֵ:0x00000000������:32
 �Ĵ���˵��: ˮƽ�˲������ڲ�״̬�Ĵ���0
*****************************************************************************/
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int      value;
    struct
    {
        unsigned int  scf_debug_h0 : 32; /* bit[0-31]:  */
    } reg;
} SOC_DSS_RCH_G_SCF_DB_H0_UNION;
#endif
#define SOC_DSS_RCH_G_SCF_DB_H0_scf_debug_h0_START  (0)
#define SOC_DSS_RCH_G_SCF_DB_H0_scf_debug_h0_END    (31)


/*****************************************************************************
 �ṹ��    : SOC_DSS_RCH_G_SCF_DB_H1_UNION
 �ṹ˵��  : SCF_DB_H1 �Ĵ����ṹ���塣��ַƫ����:0x0284����ֵ:0x00000000������:32
 �Ĵ���˵��: ˮƽ�˲������ڲ�״̬�Ĵ���1
*****************************************************************************/
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int      value;
    struct
    {
        unsigned int  scf_debug_h1 : 32; /* bit[0-31]:  */
    } reg;
} SOC_DSS_RCH_G_SCF_DB_H1_UNION;
#endif
#define SOC_DSS_RCH_G_SCF_DB_H1_scf_debug_h1_START  (0)
#define SOC_DSS_RCH_G_SCF_DB_H1_scf_debug_h1_END    (31)


/*****************************************************************************
 �ṹ��    : SOC_DSS_RCH_G_SCF_DB_V0_UNION
 �ṹ˵��  : SCF_DB_V0 �Ĵ����ṹ���塣��ַƫ����:0x0288����ֵ:0x00000000������:32
 �Ĵ���˵��: ��ֱ�˲������ڲ�״̬�Ĵ���0
*****************************************************************************/
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int      value;
    struct
    {
        unsigned int  scf_debug_v0 : 32; /* bit[0-31]:  */
    } reg;
} SOC_DSS_RCH_G_SCF_DB_V0_UNION;
#endif
#define SOC_DSS_RCH_G_SCF_DB_V0_scf_debug_v0_START  (0)
#define SOC_DSS_RCH_G_SCF_DB_V0_scf_debug_v0_END    (31)


/*****************************************************************************
 �ṹ��    : SOC_DSS_RCH_G_SCF_DB_V1_UNION
 �ṹ˵��  : SCF_DB_V1 �Ĵ����ṹ���塣��ַƫ����:0x028C����ֵ:0x30000000������:32
 �Ĵ���˵��: ��ֱ�˲������ڲ�״̬�Ĵ���1
*****************************************************************************/
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int      value;
    struct
    {
        unsigned int  scf_debug_v1 : 32; /* bit[0-31]:  */
    } reg;
} SOC_DSS_RCH_G_SCF_DB_V1_UNION;
#endif
#define SOC_DSS_RCH_G_SCF_DB_V1_scf_debug_v1_START  (0)
#define SOC_DSS_RCH_G_SCF_DB_V1_scf_debug_v1_END    (31)


/*****************************************************************************
 �ṹ��    : SOC_DSS_RCH_G_SCF_LB_MEM_CTRL_UNION
 �ṹ˵��  : SCF_LB_MEM_CTRL �Ĵ����ṹ���塣��ַƫ����:0x0290����ֵ:0x00000000������:32
 �Ĵ���˵��: LINE BUFFER POWER MANAGER
*****************************************************************************/
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int      value;
    struct
    {
        unsigned int  scf_lb_mem_ctrl : 4;  /* bit[0-3] : �����üĴ�����line buffer memory�͹������ã�
                                                          [3] mem_ctrl_auto_en , �Զ�ģʽ����������ģʽѡ��,0�Զ�ģʽ��1��������ģʽ 
                                                          [2]: ��������ģʽ����Ч��Ϊ1��ʾ����Shut Downģʽ
                                                          [1]: ��������ģʽ����Ч��Ϊ1��ʾ����Deep Sleepģʽ
                                                          [0]: ��������ģʽ����Ч��Ϊ1��ʾ����Sleepģʽ */
        unsigned int  reserved        : 28; /* bit[4-31]: ���� */
    } reg;
} SOC_DSS_RCH_G_SCF_LB_MEM_CTRL_UNION;
#endif
#define SOC_DSS_RCH_G_SCF_LB_MEM_CTRL_scf_lb_mem_ctrl_START  (0)
#define SOC_DSS_RCH_G_SCF_LB_MEM_CTRL_scf_lb_mem_ctrl_END    (3)


/*****************************************************************************
 �ṹ��    : SOC_DSS_RCH_G_POST_CLIP_DISP_SIZE_UNION
 �ṹ˵��  : POST_CLIP_DISP_SIZE �Ĵ����ṹ���塣��ַƫ����:0x03A0����ֵ:0x00000000������:32
 �Ĵ���˵��: ͼ���С
*****************************************************************************/
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int      value;
    struct
    {
        unsigned int  post_clip_size_vrt : 13; /* bit[0-12] : ����DFC��ͼ��Ĵ�ֱ�߶�-1 */
        unsigned int  reserved_0         : 3;  /* bit[13-15]: ���� */
        unsigned int  post_clip_size_hrz : 13; /* bit[16-28]: ����DFC��ͼ��ÿ�д����������-1��������2pixel������4pxiel���䣬����SIZE_HRZ+1����Ϊ2����4�ı����� */
        unsigned int  reserved_1         : 3;  /* bit[29-31]: ���� */
    } reg;
} SOC_DSS_RCH_G_POST_CLIP_DISP_SIZE_UNION;
#endif
#define SOC_DSS_RCH_G_POST_CLIP_DISP_SIZE_post_clip_size_vrt_START  (0)
#define SOC_DSS_RCH_G_POST_CLIP_DISP_SIZE_post_clip_size_vrt_END    (12)
#define SOC_DSS_RCH_G_POST_CLIP_DISP_SIZE_post_clip_size_hrz_START  (16)
#define SOC_DSS_RCH_G_POST_CLIP_DISP_SIZE_post_clip_size_hrz_END    (28)


/*****************************************************************************
 �ṹ��    : SOC_DSS_RCH_G_POST_CLIP_CTL_HRZ_UNION
 �ṹ˵��  : POST_CLIP_CTL_HRZ �Ĵ����ṹ���塣��ַƫ����:0x03B0����ֵ:0x00000000������:32
 �Ĵ���˵��: ˮƽ�ü�����
*****************************************************************************/
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int      value;
    struct
    {
        unsigned int  post_clip_right : 6;  /* bit[0-5]  : ͼ���ұ߽���CLIP���������� */
        unsigned int  reserved_0      : 10; /* bit[6-15] : ���� */
        unsigned int  post_clip_left  : 6;  /* bit[16-21]: ͼ����߽���CLIP���������� */
        unsigned int  reserved_1      : 10; /* bit[22-31]: ���� */
    } reg;
} SOC_DSS_RCH_G_POST_CLIP_CTL_HRZ_UNION;
#endif
#define SOC_DSS_RCH_G_POST_CLIP_CTL_HRZ_post_clip_right_START  (0)
#define SOC_DSS_RCH_G_POST_CLIP_CTL_HRZ_post_clip_right_END    (5)
#define SOC_DSS_RCH_G_POST_CLIP_CTL_HRZ_post_clip_left_START   (16)
#define SOC_DSS_RCH_G_POST_CLIP_CTL_HRZ_post_clip_left_END     (21)


/*****************************************************************************
 �ṹ��    : SOC_DSS_RCH_G_POST_CLIP_CTL_VRZ_UNION
 �ṹ˵��  : POST_CLIP_CTL_VRZ �Ĵ����ṹ���塣��ַƫ����:0x03B4����ֵ:0x00000000������:32
 �Ĵ���˵��: ��ֱ�ü�����
*****************************************************************************/
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int      value;
    struct
    {
        unsigned int  post_clip_bot : 6;  /* bit[0-5]  : ͼ��ױ߽���CLIP���������� */
        unsigned int  reserved_0    : 10; /* bit[6-15] : ���� */
        unsigned int  post_clip_top : 6;  /* bit[16-21]: ͼ�񶥱߽���CLIP���������� */
        unsigned int  reserved_1    : 10; /* bit[22-31]: ���� */
    } reg;
} SOC_DSS_RCH_G_POST_CLIP_CTL_VRZ_UNION;
#endif
#define SOC_DSS_RCH_G_POST_CLIP_CTL_VRZ_post_clip_bot_START  (0)
#define SOC_DSS_RCH_G_POST_CLIP_CTL_VRZ_post_clip_bot_END    (5)
#define SOC_DSS_RCH_G_POST_CLIP_CTL_VRZ_post_clip_top_START  (16)
#define SOC_DSS_RCH_G_POST_CLIP_CTL_VRZ_post_clip_top_END    (21)


/*****************************************************************************
 �ṹ��    : SOC_DSS_RCH_G_POST_CLIP_EN_UNION
 �ṹ˵��  : POST_CLIP_EN �Ĵ����ṹ���塣��ַƫ����:0x03B8����ֵ:0x00000000������:32
 �Ĵ���˵��: ͼ�����ʹ��
*****************************************************************************/
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int      value;
    struct
    {
        unsigned int  post_clip_enable : 1;  /* bit[0]   : ͼ�����ʹ�� */
        unsigned int  reserved         : 31; /* bit[1-31]: ���� */
    } reg;
} SOC_DSS_RCH_G_POST_CLIP_EN_UNION;
#endif
#define SOC_DSS_RCH_G_POST_CLIP_EN_post_clip_enable_START  (0)
#define SOC_DSS_RCH_G_POST_CLIP_EN_post_clip_enable_END    (0)


/*****************************************************************************
 �ṹ��    : SOC_DSS_RCH_G_CH_DEBUG_SEL_UNION
 �ṹ˵��  : CH_DEBUG_SEL �Ĵ����ṹ���塣��ַƫ����:0x600����ֵ:0x00000000������:32
 �Ĵ���˵��: ����ѡ��Ĵ���
*****************************************************************************/
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int      value;
    struct
    {
        unsigned int  ch_debug_sel : 4;  /* bit[0-3] : ����ģ���module_debug��ch_debug�����ѡ���ź�, ����ֵΪ��
                                                       'b0000:dma_y_debug
                                                       'b0001:dma_u_debug
                                                       'b0010:dma_v_debug
                                                       'b0011:rot_debug
                                                       'b0100:dfc_debug
                                                       'b0101:scf_debug
                                                       'b0110:sharp_debug
                                                       'b0111:ce_debug
                                                       'b1000:csc_debug */
        unsigned int  reserved     : 28; /* bit[4-31]: ���� */
    } reg;
} SOC_DSS_RCH_G_CH_DEBUG_SEL_UNION;
#endif
#define SOC_DSS_RCH_G_CH_DEBUG_SEL_ch_debug_sel_START  (0)
#define SOC_DSS_RCH_G_CH_DEBUG_SEL_ch_debug_sel_END    (3)


/*****************************************************************************
 �ṹ��    : SOC_DSS_RCH_G_DMA_BUF_CTRL_UNION
 �ṹ˵��  : DMA_BUF_CTRL �Ĵ����ṹ���塣��ַƫ����:0x0800����ֵ:0x00000004������:32
 �Ĵ���˵��: DMA_BUF���ƼĴ���
*****************************************************************************/
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int      value;
    struct
    {
        unsigned int  dma_buf_os_cfg    : 6;  /* bit[0-5]  : dma_buf�������ƼĴ�����
                                                             1. ����rdma_buf����ʾʹ�õ�bufռ��buf�ı�������������Ϊ1~5����AΪ����ֵ��
                                                             ��ƽ���ʽʱʹ�õ�bufռ��buf�ı���ΪA/5��
                                                             ˫ƽ���ʽʱʹ�õ�bufռ��buf�ı���Ϊint[(A+1)/2]*2/5��
                                                             ��ƽ���ʽʱʹ�õ�bufռ��buf�ı���Ϊint[(A+3)/4]*4/5��
                                                             2. ����wdma_buf���������ص�yͨ�����������ˮ��ֵ����������Ϊ3~7����AΪ����ֵ��
                                                             ������ˮ��ֵΪ(A+1)* 8 * 16B��package��ʽ��
                                                             ������ˮ��ֵΪ(A+1)* 4 * 16B����package��ʽ�� */
        unsigned int  reserved_0        : 2;  /* bit[6-7]  : ���� */
        unsigned int  dma_buf_qos_mask  : 1;  /* bit[8]    : �ⲿqos��Ϣ���μĴ���
                                                             0���ⲿqos��Ϣ��Ч����
                                                             1���ⲿqos��Ϣ���δ���
                                                             ע��
                                                             1��wdma_buf����ע���� */
        unsigned int  dma_buf_cont_mask : 1;  /* bit[9]    : ��βcont���͹������μĴ���
                                                             0����βcont����ʹ��
                                                             1����βcont��������
                                                             ע��
                                                             1��wdma_buf����ע���� */
        unsigned int  dma_buf_l_e_mask  : 1;  /* bit[10]   : ��βbuf��ת�������μĴ���
                                                             0����βbuf��תʹ��
                                                             1����βbuf��ת����
                                                             ע��
                                                             1��wdma_buf����ע���� */
        unsigned int  reserved_1        : 21; /* bit[11-31]: ���� */
    } reg;
} SOC_DSS_RCH_G_DMA_BUF_CTRL_UNION;
#endif
#define SOC_DSS_RCH_G_DMA_BUF_CTRL_dma_buf_os_cfg_START     (0)
#define SOC_DSS_RCH_G_DMA_BUF_CTRL_dma_buf_os_cfg_END       (5)
#define SOC_DSS_RCH_G_DMA_BUF_CTRL_dma_buf_qos_mask_START   (8)
#define SOC_DSS_RCH_G_DMA_BUF_CTRL_dma_buf_qos_mask_END     (8)
#define SOC_DSS_RCH_G_DMA_BUF_CTRL_dma_buf_cont_mask_START  (9)
#define SOC_DSS_RCH_G_DMA_BUF_CTRL_dma_buf_cont_mask_END    (9)
#define SOC_DSS_RCH_G_DMA_BUF_CTRL_dma_buf_l_e_mask_START   (10)
#define SOC_DSS_RCH_G_DMA_BUF_CTRL_dma_buf_l_e_mask_END     (10)


/*****************************************************************************
 �ṹ��    : SOC_DSS_RCH_G_DMA_BUF_CPU_CTL_UNION
 �ṹ˵��  : DMA_BUF_CPU_CTL �Ĵ����ṹ���塣��ַƫ����:0x0804����ֵ:0x00000000������:32
 �Ĵ���˵��: DMA_BUF ����ѡ��Ĵ�����
*****************************************************************************/
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int      value;
    struct
    {
        unsigned int  dma_buf_cpu_ctl : 1;  /* bit[0]   : ������ */
        unsigned int  reserved        : 31; /* bit[1-31]: ���� */
    } reg;
} SOC_DSS_RCH_G_DMA_BUF_CPU_CTL_UNION;
#endif
#define SOC_DSS_RCH_G_DMA_BUF_CPU_CTL_dma_buf_cpu_ctl_START  (0)
#define SOC_DSS_RCH_G_DMA_BUF_CPU_CTL_dma_buf_cpu_ctl_END    (0)


/*****************************************************************************
 �ṹ��    : SOC_DSS_RCH_G_DMA_BUF_CPU_START_UNION
 �ṹ˵��  : DMA_BUF_CPU_START �Ĵ����ṹ���塣��ַƫ����:0x0808����ֵ:0x00000000������:32
 �Ĵ���˵��: DMA_BUF ���������Ĵ�����
*****************************************************************************/
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int      value;
    struct
    {
        unsigned int  dma_buf_cpu_start : 1;  /* bit[0]   : ������ */
        unsigned int  reserved          : 31; /* bit[1-31]: ���� */
    } reg;
} SOC_DSS_RCH_G_DMA_BUF_CPU_START_UNION;
#endif
#define SOC_DSS_RCH_G_DMA_BUF_CPU_START_dma_buf_cpu_start_START  (0)
#define SOC_DSS_RCH_G_DMA_BUF_CPU_START_dma_buf_cpu_start_END    (0)


/*****************************************************************************
 �ṹ��    : SOC_DSS_RCH_G_DMA_BUF_CPU_ADDR_UNION
 �ṹ˵��  : DMA_BUF_CPU_ADDR �Ĵ����ṹ���塣��ַƫ����:0x080C����ֵ:0x00000000������:32
 �Ĵ���˵��: DMA_BUF ��ַ�Ĵ�����
*****************************************************************************/
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int      value;
    struct
    {
        unsigned int  dma_buf_cpu_addr : 9;  /* bit[0-8] : ������ */
        unsigned int  reserved         : 22; /* bit[9-30]: ���� */
        unsigned int  dma_buf_cpu_rw   : 1;  /* bit[31]  : ������ */
    } reg;
} SOC_DSS_RCH_G_DMA_BUF_CPU_ADDR_UNION;
#endif
#define SOC_DSS_RCH_G_DMA_BUF_CPU_ADDR_dma_buf_cpu_addr_START  (0)
#define SOC_DSS_RCH_G_DMA_BUF_CPU_ADDR_dma_buf_cpu_addr_END    (8)
#define SOC_DSS_RCH_G_DMA_BUF_CPU_ADDR_dma_buf_cpu_rw_START    (31)
#define SOC_DSS_RCH_G_DMA_BUF_CPU_ADDR_dma_buf_cpu_rw_END      (31)


/*****************************************************************************
 �ṹ��    : SOC_DSS_RCH_G_DMA_BUF_CPU_RDATA0_UNION
 �ṹ˵��  : DMA_BUF_CPU_RDATA0 �Ĵ����ṹ���塣��ַƫ����:0x0810����ֵ:0x00000000������:32
 �Ĵ���˵��: DMA_BUF �����ݶ˿ڼĴ���0��
*****************************************************************************/
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int      value;
    struct
    {
        unsigned int  dma_buf_cpu_rdata0 : 32; /* bit[0-31]: ������ */
    } reg;
} SOC_DSS_RCH_G_DMA_BUF_CPU_RDATA0_UNION;
#endif
#define SOC_DSS_RCH_G_DMA_BUF_CPU_RDATA0_dma_buf_cpu_rdata0_START  (0)
#define SOC_DSS_RCH_G_DMA_BUF_CPU_RDATA0_dma_buf_cpu_rdata0_END    (31)


/*****************************************************************************
 �ṹ��    : SOC_DSS_RCH_G_DMA_BUF_CPU_RDATA1_UNION
 �ṹ˵��  : DMA_BUF_CPU_RDATA1 �Ĵ����ṹ���塣��ַƫ����:0x814����ֵ:0x00000000������:32
 �Ĵ���˵��: DMA_BUF �����ݶ˿ڼĴ���1��
*****************************************************************************/
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int      value;
    struct
    {
        unsigned int  dma_buf_cpu_rdata1 : 32; /* bit[0-31]: ������ */
    } reg;
} SOC_DSS_RCH_G_DMA_BUF_CPU_RDATA1_UNION;
#endif
#define SOC_DSS_RCH_G_DMA_BUF_CPU_RDATA1_dma_buf_cpu_rdata1_START  (0)
#define SOC_DSS_RCH_G_DMA_BUF_CPU_RDATA1_dma_buf_cpu_rdata1_END    (31)


/*****************************************************************************
 �ṹ��    : SOC_DSS_RCH_G_DMA_BUF_CPU_RDATA2_UNION
 �ṹ˵��  : DMA_BUF_CPU_RDATA2 �Ĵ����ṹ���塣��ַƫ����:0x818����ֵ:0x00000000������:32
 �Ĵ���˵��: DMA_BUF �����ݶ˿ڼĴ���2��
*****************************************************************************/
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int      value;
    struct
    {
        unsigned int  dma_buf_cpu_rdata2 : 32; /* bit[0-31]: ������ */
    } reg;
} SOC_DSS_RCH_G_DMA_BUF_CPU_RDATA2_UNION;
#endif
#define SOC_DSS_RCH_G_DMA_BUF_CPU_RDATA2_dma_buf_cpu_rdata2_START  (0)
#define SOC_DSS_RCH_G_DMA_BUF_CPU_RDATA2_dma_buf_cpu_rdata2_END    (31)


/*****************************************************************************
 �ṹ��    : SOC_DSS_RCH_G_DMA_BUF_CPU_RDATA3_UNION
 �ṹ˵��  : DMA_BUF_CPU_RDATA3 �Ĵ����ṹ���塣��ַƫ����:0x81C����ֵ:0x00000000������:32
 �Ĵ���˵��: DMA_BUF �����ݶ˿ڼĴ���3��
*****************************************************************************/
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int      value;
    struct
    {
        unsigned int  dma_buf_cpu_rdata3 : 32; /* bit[0-31]: ������ */
    } reg;
} SOC_DSS_RCH_G_DMA_BUF_CPU_RDATA3_UNION;
#endif
#define SOC_DSS_RCH_G_DMA_BUF_CPU_RDATA3_dma_buf_cpu_rdata3_START  (0)
#define SOC_DSS_RCH_G_DMA_BUF_CPU_RDATA3_dma_buf_cpu_rdata3_END    (31)


/*****************************************************************************
 �ṹ��    : SOC_DSS_RCH_G_DMA_BUF_CPU_WDATA0_UNION
 �ṹ˵��  : DMA_BUF_CPU_WDATA0 �Ĵ����ṹ���塣��ַƫ����:0x820����ֵ:0x00000000������:32
 �Ĵ���˵��: DMA_BUF д���ݶ˿ڼĴ���0��
*****************************************************************************/
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int      value;
    struct
    {
        unsigned int  dma_buf_cpu_wdata0 : 32; /* bit[0-31]: ������ */
    } reg;
} SOC_DSS_RCH_G_DMA_BUF_CPU_WDATA0_UNION;
#endif
#define SOC_DSS_RCH_G_DMA_BUF_CPU_WDATA0_dma_buf_cpu_wdata0_START  (0)
#define SOC_DSS_RCH_G_DMA_BUF_CPU_WDATA0_dma_buf_cpu_wdata0_END    (31)


/*****************************************************************************
 �ṹ��    : SOC_DSS_RCH_G_DMA_BUF_CPU_WDATA1_UNION
 �ṹ˵��  : DMA_BUF_CPU_WDATA1 �Ĵ����ṹ���塣��ַƫ����:0x824����ֵ:0x00000000������:32
 �Ĵ���˵��: DMA_BUF д���ݶ˿ڼĴ���1��
*****************************************************************************/
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int      value;
    struct
    {
        unsigned int  dma_buf_cpu_wdata1 : 32; /* bit[0-31]: ������ */
    } reg;
} SOC_DSS_RCH_G_DMA_BUF_CPU_WDATA1_UNION;
#endif
#define SOC_DSS_RCH_G_DMA_BUF_CPU_WDATA1_dma_buf_cpu_wdata1_START  (0)
#define SOC_DSS_RCH_G_DMA_BUF_CPU_WDATA1_dma_buf_cpu_wdata1_END    (31)


/*****************************************************************************
 �ṹ��    : SOC_DSS_RCH_G_DMA_BUF_CPU_WDATA2_UNION
 �ṹ˵��  : DMA_BUF_CPU_WDATA2 �Ĵ����ṹ���塣��ַƫ����:0x828����ֵ:0x00000000������:32
 �Ĵ���˵��: DMA_BUF д���ݶ˿ڼĴ���2��
*****************************************************************************/
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int      value;
    struct
    {
        unsigned int  dma_buf_cpu_wdata2 : 32; /* bit[0-31]: ������ */
    } reg;
} SOC_DSS_RCH_G_DMA_BUF_CPU_WDATA2_UNION;
#endif
#define SOC_DSS_RCH_G_DMA_BUF_CPU_WDATA2_dma_buf_cpu_wdata2_START  (0)
#define SOC_DSS_RCH_G_DMA_BUF_CPU_WDATA2_dma_buf_cpu_wdata2_END    (31)


/*****************************************************************************
 �ṹ��    : SOC_DSS_RCH_G_DMA_BUF_CPU_WDATA3_UNION
 �ṹ˵��  : DMA_BUF_CPU_WDATA3 �Ĵ����ṹ���塣��ַƫ����:0x82C����ֵ:0x00000000������:32
 �Ĵ���˵��: DMA_BUF д���ݶ˿ڼĴ���3��
*****************************************************************************/
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int      value;
    struct
    {
        unsigned int  dma_buf_cpu_wdata3 : 32; /* bit[0-31]: ������ */
    } reg;
} SOC_DSS_RCH_G_DMA_BUF_CPU_WDATA3_UNION;
#endif
#define SOC_DSS_RCH_G_DMA_BUF_CPU_WDATA3_dma_buf_cpu_wdata3_START  (0)
#define SOC_DSS_RCH_G_DMA_BUF_CPU_WDATA3_dma_buf_cpu_wdata3_END    (31)


/*****************************************************************************
 �ṹ��    : SOC_DSS_RCH_G_DMA_REQ_END_UNION
 �ṹ˵��  : DMA_REQ_END �Ĵ����ṹ���塣��ַƫ����:0x830����ֵ:0x00000000������:32
 �Ĵ���˵��: MMU TLB �����ݶ˿ڼĴ���0��
*****************************************************************************/
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int      value;
    struct
    {
        unsigned int  dma_req_end : 1;  /* bit[0]   : ������ */
        unsigned int  reserved    : 31; /* bit[1-31]: ���� */
    } reg;
} SOC_DSS_RCH_G_DMA_REQ_END_UNION;
#endif
#define SOC_DSS_RCH_G_DMA_REQ_END_dma_req_end_START  (0)
#define SOC_DSS_RCH_G_DMA_REQ_END_dma_req_end_END    (0)


/*****************************************************************************
 �ṹ��    : SOC_DSS_RCH_G_DMA_BUF_DBGCFG_UNION
 �ṹ˵��  : DMA_BUF_DBGCFG �Ĵ����ṹ���塣��ַƫ����:0x834����ֵ:0x00000000������:32
 �Ĵ���˵��: DMA_BUF ���ԼĴ���
*****************************************************************************/
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int      value;
    struct
    {
        unsigned int  dma_buf_dbgcfg : 32; /* bit[0-31]: ������ */
    } reg;
} SOC_DSS_RCH_G_DMA_BUF_DBGCFG_UNION;
#endif
#define SOC_DSS_RCH_G_DMA_BUF_DBGCFG_dma_buf_dbgcfg_START  (0)
#define SOC_DSS_RCH_G_DMA_BUF_DBGCFG_dma_buf_dbgcfg_END    (31)


/*****************************************************************************
 �ṹ��    : SOC_DSS_RCH_G_DMA_BUF_DBG0_UNION
 �ṹ˵��  : DMA_BUF_DBG0 �Ĵ����ṹ���塣��ַƫ����:0x838����ֵ:0x00000000������:32
 �Ĵ���˵��: DMA_BUF����ֻ���Ĵ���0
*****************************************************************************/
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int      value;
    struct
    {
        unsigned int  dma_buf_dbg0 : 32; /* bit[0-31]: ������ */
    } reg;
} SOC_DSS_RCH_G_DMA_BUF_DBG0_UNION;
#endif
#define SOC_DSS_RCH_G_DMA_BUF_DBG0_dma_buf_dbg0_START  (0)
#define SOC_DSS_RCH_G_DMA_BUF_DBG0_dma_buf_dbg0_END    (31)


/*****************************************************************************
 �ṹ��    : SOC_DSS_RCH_G_DMA_BUF_DBG1_UNION
 �ṹ˵��  : DMA_BUF_DBG1 �Ĵ����ṹ���塣��ַƫ����:0x83C����ֵ:0x00000000������:32
 �Ĵ���˵��: DMA_BUF����ֻ���Ĵ���1
*****************************************************************************/
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int      value;
    struct
    {
        unsigned int  dma_buf_dbg1 : 32; /* bit[0-31]: ������ */
    } reg;
} SOC_DSS_RCH_G_DMA_BUF_DBG1_UNION;
#endif
#define SOC_DSS_RCH_G_DMA_BUF_DBG1_dma_buf_dbg1_START  (0)
#define SOC_DSS_RCH_G_DMA_BUF_DBG1_dma_buf_dbg1_END    (31)


/*****************************************************************************
 �ṹ��    : SOC_DSS_RCH_G_DMA_BUF_DBG2_UNION
 �ṹ˵��  : DMA_BUF_DBG2 �Ĵ����ṹ���塣��ַƫ����:0x840����ֵ:0x00000000������:32
 �Ĵ���˵��: DMA_BUF����ֻ���Ĵ���0
*****************************************************************************/
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int      value;
    struct
    {
        unsigned int  dma_buf_dbg2 : 32; /* bit[0-31]: ������ */
    } reg;
} SOC_DSS_RCH_G_DMA_BUF_DBG2_UNION;
#endif
#define SOC_DSS_RCH_G_DMA_BUF_DBG2_dma_buf_dbg2_START  (0)
#define SOC_DSS_RCH_G_DMA_BUF_DBG2_dma_buf_dbg2_END    (31)


/*****************************************************************************
 �ṹ��    : SOC_DSS_RCH_G_DMA_BUF_DBG3_UNION
 �ṹ˵��  : DMA_BUF_DBG3 �Ĵ����ṹ���塣��ַƫ����:0x844����ֵ:0x00000000������:32
 �Ĵ���˵��: DMA_BUF����ֻ���Ĵ���1
*****************************************************************************/
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int      value;
    struct
    {
        unsigned int  dma_buf_dbg3 : 32; /* bit[0-31]: ������ */
    } reg;
} SOC_DSS_RCH_G_DMA_BUF_DBG3_UNION;
#endif
#define SOC_DSS_RCH_G_DMA_BUF_DBG3_dma_buf_dbg3_START  (0)
#define SOC_DSS_RCH_G_DMA_BUF_DBG3_dma_buf_dbg3_END    (31)


/*****************************************************************************
 �ṹ��    : SOC_DSS_RCH_G_DMA_BUF_DBG4_UNION
 �ṹ˵��  : DMA_BUF_DBG4 �Ĵ����ṹ���塣��ַƫ����:0x848����ֵ:0x00000000������:32
 �Ĵ���˵��: DMA_BUF����ֻ���Ĵ���0
*****************************************************************************/
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int      value;
    struct
    {
        unsigned int  dma_buf_dbg4 : 32; /* bit[0-31]: ������ */
    } reg;
} SOC_DSS_RCH_G_DMA_BUF_DBG4_UNION;
#endif
#define SOC_DSS_RCH_G_DMA_BUF_DBG4_dma_buf_dbg4_START  (0)
#define SOC_DSS_RCH_G_DMA_BUF_DBG4_dma_buf_dbg4_END    (31)


/*****************************************************************************
 �ṹ��    : SOC_DSS_RCH_G_DMA_BUF_DBG5_UNION
 �ṹ˵��  : DMA_BUF_DBG5 �Ĵ����ṹ���塣��ַƫ����:0x84C����ֵ:0x00000000������:32
 �Ĵ���˵��: DMA_BUF����ֻ���Ĵ���1
*****************************************************************************/
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int      value;
    struct
    {
        unsigned int  dma_buf_dbg5 : 32; /* bit[0-31]: ������ */
    } reg;
} SOC_DSS_RCH_G_DMA_BUF_DBG5_UNION;
#endif
#define SOC_DSS_RCH_G_DMA_BUF_DBG5_dma_buf_dbg5_START  (0)
#define SOC_DSS_RCH_G_DMA_BUF_DBG5_dma_buf_dbg5_END    (31)


/*****************************************************************************
 �ṹ��    : SOC_DSS_RCH_G_DMA_BUF_SIZE_UNION
 �ṹ˵��  : DMA_BUF_SIZE �Ĵ����ṹ���塣��ַƫ����:0x850����ֵ:0x00000000������:32
 �Ĵ���˵��: ͼ���С
*****************************************************************************/
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int      value;
    struct
    {
        unsigned int  dma_buf_img_width  : 13; /* bit[0-12] : WDMA_BUF�������Чͼ����ȣ�������Ϊ��λ����һ���á� */
        unsigned int  reserved_0         : 3;  /* bit[13-15]: ���� */
        unsigned int  dma_buf_img_height : 13; /* bit[16-28]: WDMA_BUF�������Чͼ��߶ȣ�����Ϊ��λ����һ���á� */
        unsigned int  reserved_1         : 3;  /* bit[29-31]: ���� */
    } reg;
} SOC_DSS_RCH_G_DMA_BUF_SIZE_UNION;
#endif
#define SOC_DSS_RCH_G_DMA_BUF_SIZE_dma_buf_img_width_START   (0)
#define SOC_DSS_RCH_G_DMA_BUF_SIZE_dma_buf_img_width_END     (12)
#define SOC_DSS_RCH_G_DMA_BUF_SIZE_dma_buf_img_height_START  (16)
#define SOC_DSS_RCH_G_DMA_BUF_SIZE_dma_buf_img_height_END    (28)


/*****************************************************************************
 �ṹ��    : SOC_DSS_RCH_G_DMA_BUF_MEM_CTRL_UNION
 �ṹ˵��  : DMA_BUF_MEM_CTRL �Ĵ����ṹ���塣��ַƫ����:0x0854����ֵ:0x00000000������:32
 �Ĵ���˵��: DMA_BUF SRAM���ƼĴ�����TP��
*****************************************************************************/
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int      value;
    struct
    {
        unsigned int  dma_buf_mem_ctrl : 4;  /* bit[0-3] : �����üĴ���
                                                           [3] mem_ctrl_auto_en , �Զ�ģʽ����������ģʽѡ��,0�Զ�ģʽ��1��������ģʽ 
                                                           [2]: ��������ģʽ����Ч��Ϊ1��ʾ����Shut Downģʽ
                                                           [1]: ��������ģʽ����Ч��Ϊ1��ʾ����Deep Sleepģʽ
                                                           [0]: ��������ģʽ����Ч��Ϊ1��ʾ����Sleepģʽ */
        unsigned int  reserved         : 28; /* bit[4-31]: ���� */
    } reg;
} SOC_DSS_RCH_G_DMA_BUF_MEM_CTRL_UNION;
#endif
#define SOC_DSS_RCH_G_DMA_BUF_MEM_CTRL_dma_buf_mem_ctrl_START  (0)
#define SOC_DSS_RCH_G_DMA_BUF_MEM_CTRL_dma_buf_mem_ctrl_END    (3)


/*****************************************************************************
 �ṹ��    : SOC_DSS_RCH_G_AFBCD_HREG_HDR_PTR_LO_UNION
 �ṹ˵��  : AFBCD_HREG_HDR_PTR_LO �Ĵ����ṹ���塣��ַƫ����:0x0900����ֵ:0x00000000������:32
 �Ĵ���˵��: ѹ��Header��ʼ��ַ��λ
*****************************************************************************/
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int      value;
    struct
    {
        unsigned int  afbcd_hdr_ptr_lo : 32; /* bit[0-31]: ����Header��ʼ��ַ[31:0]����ַ64Byte���� */
    } reg;
} SOC_DSS_RCH_G_AFBCD_HREG_HDR_PTR_LO_UNION;
#endif
#define SOC_DSS_RCH_G_AFBCD_HREG_HDR_PTR_LO_afbcd_hdr_ptr_lo_START  (0)
#define SOC_DSS_RCH_G_AFBCD_HREG_HDR_PTR_LO_afbcd_hdr_ptr_lo_END    (31)


/*****************************************************************************
 �ṹ��    : SOC_DSS_RCH_G_AFBCD_HREG_PIC_WIDTH_UNION
 �ṹ˵��  : AFBCD_HREG_PIC_WIDTH �Ĵ����ṹ���塣��ַƫ����:0x0904����ֵ:0x0000000F������:32
 �Ĵ���˵��: ѹ��ͼ�����
*****************************************************************************/
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int      value;
    struct
    {
        unsigned int  afbcd_pic_width : 16; /* bit[0-15] : ѹ��ͼ��������ظ���-1��ѹ��ͼ��������������16������ */
        unsigned int  reserved        : 16; /* bit[16-31]: ���� */
    } reg;
} SOC_DSS_RCH_G_AFBCD_HREG_PIC_WIDTH_UNION;
#endif
#define SOC_DSS_RCH_G_AFBCD_HREG_PIC_WIDTH_afbcd_pic_width_START  (0)
#define SOC_DSS_RCH_G_AFBCD_HREG_PIC_WIDTH_afbcd_pic_width_END    (15)


/*****************************************************************************
 �ṹ��    : SOC_DSS_RCH_G_AFBCD_HREG_PIC_HEIGHT_UNION
 �ṹ˵��  : AFBCD_HREG_PIC_HEIGHT �Ĵ����ṹ���塣��ַƫ����:0x090C����ֵ:0x0000000F������:32
 �Ĵ���˵��: ѹ��ͼ��߶�
*****************************************************************************/
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int      value;
    struct
    {
        unsigned int  afbcd_pic_height : 16; /* bit[0-15] : ѹ��ͼ��߶����ظ���-1��ѹ��ͼ��������������8������(��stretch֮��crop֮ǰ�ĸ߶ȣ� */
        unsigned int  reserved         : 16; /* bit[16-31]: ���� */
    } reg;
} SOC_DSS_RCH_G_AFBCD_HREG_PIC_HEIGHT_UNION;
#endif
#define SOC_DSS_RCH_G_AFBCD_HREG_PIC_HEIGHT_afbcd_pic_height_START  (0)
#define SOC_DSS_RCH_G_AFBCD_HREG_PIC_HEIGHT_afbcd_pic_height_END    (15)


/*****************************************************************************
 �ṹ��    : SOC_DSS_RCH_G_AFBCD_HREG_FORMAT_UNION
 �ṹ˵��  : AFBCD_HREG_FORMAT �Ĵ����ṹ���塣��ַƫ����:0x0910����ֵ:0x00050001������:32
 �Ĵ���˵��: ѹ��ͼ���ʽ
*****************************************************************************/
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int      value;
    struct
    {
        unsigned int  afbcd_block_split     : 1;  /* bit[0]    : block split mode
                                                                 1=enable, 0=disable */
        unsigned int  reserved_0            : 15; /* bit[1-15] : ���� */
        unsigned int  reserved_1            : 5;  /* bit[16-20]: bit[20] reserved��
                                                                 bit[19:16] pixel format
                                                                 0x0: RGB565
                                                                 0x1: ARGB4444
                                                                 0x2: XRGB4444
                                                                 0x3: ARGB1555
                                                                 0x4: XRGB1555
                                                                 0x5: ARGB8888
                                                                 0x6: XRGB8888
                                                                 0x7: reserved
                                                                 0x8: YUYV packet, ֻ֧��color transform=0����֧��color transform=1
                                                                 0x9: YUV420 Semi Planar HP����֧��
                                                                 0xA: YUV420 Planar HP����֧��
                                                                 0xB: YUV422 Semi Planar HP����֧��
                                                                 0xC: YUV422 Planar HP����֧��
                                                                 0xD: AYUV444����֧��
                                                                 0xE: UYVY Packet, ��֧��
                                                                 others: reserved */
        unsigned int  afbcd_color_transform : 1;  /* bit[21]   : color transform, 1-enable, 0-disable��(������ȡ����) */
        unsigned int  reserved_2            : 10; /* bit[22-31]: ���� */
    } reg;
} SOC_DSS_RCH_G_AFBCD_HREG_FORMAT_UNION;
#endif
#define SOC_DSS_RCH_G_AFBCD_HREG_FORMAT_afbcd_block_split_START      (0)
#define SOC_DSS_RCH_G_AFBCD_HREG_FORMAT_afbcd_block_split_END        (0)
#define SOC_DSS_RCH_G_AFBCD_HREG_FORMAT_afbcd_color_transform_START  (21)
#define SOC_DSS_RCH_G_AFBCD_HREG_FORMAT_afbcd_color_transform_END    (21)


/*****************************************************************************
 �ṹ��    : SOC_DSS_RCH_G_AFBCD_CTL_UNION
 �ṹ˵��  : AFBCD_CTL �Ĵ����ṹ���塣��ַƫ����:0x0914����ֵ:0x00000000������:32
 �Ĵ���˵��: AFBCD����
*****************************************************************************/
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int      value;
    struct
    {
        unsigned int  reserved_0            : 1;  /* bit[0-0] : �ϲ���ch_afbcd_en */
        unsigned int  reserved_1            : 1;  /* bit[1-1] : �ϲ���ch_afbcd_en */
        unsigned int  reserved_2            : 1;  /* bit[2-2] : �ϲ���dma_mirror_hrz_en */
        unsigned int  reserved_3            : 1;  /* bit[3-3] : �ϲ���dma_mirror_vrt_en */
        unsigned int  reserved_4            : 1;  /* bit[4-4] : �ϲ���dma_stretch_en */
        unsigned int  reserved_5            : 1;  /* bit[5-5] : �ϲ���ch_secu */
        unsigned int  afbcd_half_block_mode : 2;  /* bit[6-7] : decoeder order
                                                                2'b0:upper 8 line, then lower 8 line
                                                                2'b1:lower I line ,then upper 8 line
                                                                2'b2:upper 8 line only
                                                                2'b3:lower 8 line only */
        unsigned int  reserved_6            : 24; /* bit[8-31]:  */
    } reg;
} SOC_DSS_RCH_G_AFBCD_CTL_UNION;
#endif
#define SOC_DSS_RCH_G_AFBCD_CTL_afbcd_half_block_mode_START  (6)
#define SOC_DSS_RCH_G_AFBCD_CTL_afbcd_half_block_mode_END    (7)


/*****************************************************************************
 �ṹ��    : SOC_DSS_RCH_G_AFBCD_STR_UNION
 �ṹ˵��  : AFBCD_STR �Ĵ����ṹ���塣��ַƫ����:0x0918����ֵ:0x00000001������:32
 �Ĵ���˵��: STRETCH PARAMETER
*****************************************************************************/
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int      value;
    struct
    {
        unsigned int  afbcd_stretch_inc : 8;  /* bit[0-7]  : step (16��Ϊ��λ��for stretch */
        unsigned int  afbcd_stretch_acc : 4;  /* bit[8-11] : init block line for strecth */
        unsigned int  reserved          : 20; /* bit[12-31]:  */
    } reg;
} SOC_DSS_RCH_G_AFBCD_STR_UNION;
#endif
#define SOC_DSS_RCH_G_AFBCD_STR_afbcd_stretch_inc_START  (0)
#define SOC_DSS_RCH_G_AFBCD_STR_afbcd_stretch_inc_END    (7)
#define SOC_DSS_RCH_G_AFBCD_STR_afbcd_stretch_acc_START  (8)
#define SOC_DSS_RCH_G_AFBCD_STR_afbcd_stretch_acc_END    (11)


/*****************************************************************************
 �ṹ��    : SOC_DSS_RCH_G_LINE_CROP_UNION
 �ṹ˵��  : LINE_CROP �Ĵ����ṹ���塣��ַƫ����:0x091C����ֵ:0x00000000������:32
 �Ĵ���˵��: TOP AND BOTTOM LINT NUMBER BE CROPPED
*****************************************************************************/
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int      value;
    struct
    {
        unsigned int  afbcd_bottom_crop_num : 4;  /* bit[0-3] : line number be cropped in the bottom after stretch and vertical mirror
                                                                0: 0 line
                                                                n: n line */
        unsigned int  afbcd_top_crop_num    : 4;  /* bit[4-7] : line number to be cropped in the top after stretch and vertical mirror
                                                                0: 0 line
                                                                n: n line */
        unsigned int  reserved              : 24; /* bit[8-31]:  */
    } reg;
} SOC_DSS_RCH_G_LINE_CROP_UNION;
#endif
#define SOC_DSS_RCH_G_LINE_CROP_afbcd_bottom_crop_num_START  (0)
#define SOC_DSS_RCH_G_LINE_CROP_afbcd_bottom_crop_num_END    (3)
#define SOC_DSS_RCH_G_LINE_CROP_afbcd_top_crop_num_START     (4)
#define SOC_DSS_RCH_G_LINE_CROP_afbcd_top_crop_num_END       (7)


/*****************************************************************************
 �ṹ��    : SOC_DSS_RCH_G_INPUT_HEADER_STRIDE_UNION
 �ṹ˵��  : INPUT_HEADER_STRIDE �Ĵ����ṹ���塣��ַƫ����:0x0920����ֵ:0x00000040������:32
 �Ĵ���˵��: INPUT HEADER STRIDE
*****************************************************************************/
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int      value;
    struct
    {
        unsigned int  afbcd_header_stride    : 14; /* bit[0-13] : can be used for decoding a sub picture of a full picture
                                                                  ������64byte�ı��� */
        unsigned int  afbcd_header_start_pos : 2;  /* bit[14-15]: valid header in first burst
                                                                  2��b00����1����ʼ��Ч
                                                                  2��b01����2����ʼ��Ч
                                                                  2��b10����3����ʼ��Ч
                                                                  2��b11����4����ʼ��Ч */
        unsigned int  reserved               : 16; /* bit[16-31]:  */
    } reg;
} SOC_DSS_RCH_G_INPUT_HEADER_STRIDE_UNION;
#endif
#define SOC_DSS_RCH_G_INPUT_HEADER_STRIDE_afbcd_header_stride_START     (0)
#define SOC_DSS_RCH_G_INPUT_HEADER_STRIDE_afbcd_header_stride_END       (13)
#define SOC_DSS_RCH_G_INPUT_HEADER_STRIDE_afbcd_header_start_pos_START  (14)
#define SOC_DSS_RCH_G_INPUT_HEADER_STRIDE_afbcd_header_start_pos_END    (15)


/*****************************************************************************
 �ṹ��    : SOC_DSS_RCH_G_AFBCD_PAYLOAD_STRIDE_UNION
 �ṹ˵��  : AFBCD_PAYLOAD_STRIDE �Ĵ����ṹ���塣��ַƫ����:0x0924����ֵ:0x00000400������:32
 �Ĵ���˵��: output payload stride
*****************************************************************************/
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int      value;
    struct
    {
        unsigned int  afbcd_payload_stride : 20; /* bit[0-19] : payload�Ļ��п��ȣ���byteΪ��λ��
                                                                32���ظ�ʽ��ʱ��1024Byte����������16���ظ�ʽ��ʱ��512Byte�������� */
        unsigned int  reserved             : 12; /* bit[20-31]:  */
    } reg;
} SOC_DSS_RCH_G_AFBCD_PAYLOAD_STRIDE_UNION;
#endif
#define SOC_DSS_RCH_G_AFBCD_PAYLOAD_STRIDE_afbcd_payload_stride_START  (0)
#define SOC_DSS_RCH_G_AFBCD_PAYLOAD_STRIDE_afbcd_payload_stride_END    (19)


/*****************************************************************************
 �ṹ��    : SOC_DSS_RCH_G_MM_BASE_0_UNION
 �ṹ˵��  : MM_BASE_0 �Ĵ����ṹ���塣��ַƫ����:0x0928����ֵ:0x00000000������:32
 �Ĵ���˵��: mm buffer base 0
*****************************************************************************/
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int      value;
    struct
    {
        unsigned int  afbcd_mm_base_0 : 32; /* bit[0-31]: base 0 address in MM buffer
                                                          ������64byte��������������С�ڣ�0x48000-8��ͼ������������������MM_BASE��ַ֮��Ĵ洢�ռ�Ҫ����ͼ��8�ж�Ӧ�����ݴ�С�� */
    } reg;
} SOC_DSS_RCH_G_MM_BASE_0_UNION;
#endif
#define SOC_DSS_RCH_G_MM_BASE_0_afbcd_mm_base_0_START  (0)
#define SOC_DSS_RCH_G_MM_BASE_0_afbcd_mm_base_0_END    (31)


/*****************************************************************************
 �ṹ��    : SOC_DSS_RCH_G_MM_BASE_1_UNION
 �ṹ˵��  : MM_BASE_1 �Ĵ����ṹ���塣��ַƫ����:0x092C����ֵ:0x00000200������:32
 �Ĵ���˵��: mm buffer base 1
*****************************************************************************/
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int      value;
    struct
    {
        unsigned int  afbcd_mm_base_1 : 32; /* bit[0-31]: base 1 address in MM buffer
                                                          ������64byte��������������С�ڣ�0x48000-8��ͼ������������������MM_BASE��ַ֮��Ĵ洢�ռ�Ҫ����ͼ��8�ж�Ӧ�����ݴ�С�� */
    } reg;
} SOC_DSS_RCH_G_MM_BASE_1_UNION;
#endif
#define SOC_DSS_RCH_G_MM_BASE_1_afbcd_mm_base_1_START  (0)
#define SOC_DSS_RCH_G_MM_BASE_1_afbcd_mm_base_1_END    (31)


/*****************************************************************************
 �ṹ��    : SOC_DSS_RCH_G_AFBCD_PAYLOAD_POINTER_UNION
 �ṹ˵��  : AFBCD_PAYLOAD_POINTER �Ĵ����ṹ���塣��ַƫ����:0x0930����ֵ:0x00000400������:32
 �Ĵ���˵��: input payload point
*****************************************************************************/
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int      value;
    struct
    {
        unsigned int  afbcd_payload_ptr : 32; /* bit[0-31]: ����payload��ʼ��ַ[31:0]����ַ1K Byte���� */
    } reg;
} SOC_DSS_RCH_G_AFBCD_PAYLOAD_POINTER_UNION;
#endif
#define SOC_DSS_RCH_G_AFBCD_PAYLOAD_POINTER_afbcd_payload_ptr_START  (0)
#define SOC_DSS_RCH_G_AFBCD_PAYLOAD_POINTER_afbcd_payload_ptr_END    (31)


/*****************************************************************************
 �ṹ��    : SOC_DSS_RCH_G_HEIGHT_BF_STR_UNION
 �ṹ˵��  : HEIGHT_BF_STR �Ĵ����ṹ���塣��ַƫ����:0x0934����ֵ:0x0000000F������:32
 �Ĵ���˵��: input height
*****************************************************************************/
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int      value;
    struct
    {
        unsigned int  afbcd_pic_height_bf_stretch : 16; /* bit[0-15] : ѹ��ͼ��߶����ظ���-1��ѹ��ͼ��������������16������(�Ƕ���block��֮ǰ�ĸ߶ȣ�---�����ӵ� */
        unsigned int  reserved                    : 16; /* bit[16-31]: ���� */
    } reg;
} SOC_DSS_RCH_G_HEIGHT_BF_STR_UNION;
#endif
#define SOC_DSS_RCH_G_HEIGHT_BF_STR_afbcd_pic_height_bf_stretch_START  (0)
#define SOC_DSS_RCH_G_HEIGHT_BF_STR_afbcd_pic_height_bf_stretch_END    (15)


/*****************************************************************************
 �ṹ��    : SOC_DSS_RCH_G_OS_CFG_UNION
 �ṹ˵��  : OS_CFG �Ĵ����ṹ���塣��ַƫ����:0x0938����ֵ:0x00000F46������:32
 �Ĵ���˵��: OUSTANDING CFG
*****************************************************************************/
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int      value;
    struct
    {
        unsigned int  afbcd_mmrd_os : 4;  /* bit[0-3]  : VBIF MM���ӿڵ�outstanding���ã���ֵ+1Ϊʵ��outstandingֵ�����ֵ0x7 */
        unsigned int  afbcd_mmwr_os : 4;  /* bit[4-7]  : VBIF MMд�ӿڵ�outstanding���ã���ֵ+1Ϊʵ��outstandingֵ�����ֵ0x7 */
        unsigned int  afbcd_ddrr_os : 6;  /* bit[8-13] : VBIF DDR���ӿڵ�outstanding���ã���ֵ+1Ϊʵ��outstandingֵ�����ֵ0x1F */
        unsigned int  reserved      : 18; /* bit[14-31]:  */
    } reg;
} SOC_DSS_RCH_G_OS_CFG_UNION;
#endif
#define SOC_DSS_RCH_G_OS_CFG_afbcd_mmrd_os_START  (0)
#define SOC_DSS_RCH_G_OS_CFG_afbcd_mmrd_os_END    (3)
#define SOC_DSS_RCH_G_OS_CFG_afbcd_mmwr_os_START  (4)
#define SOC_DSS_RCH_G_OS_CFG_afbcd_mmwr_os_END    (7)
#define SOC_DSS_RCH_G_OS_CFG_afbcd_ddrr_os_START  (8)
#define SOC_DSS_RCH_G_OS_CFG_afbcd_ddrr_os_END    (13)


/*****************************************************************************
 �ṹ��    : SOC_DSS_RCH_G_AFBCD_MEM_CTRL_UNION
 �ṹ˵��  : AFBCD_MEM_CTRL �Ĵ����ṹ���塣��ַƫ����:0x093C����ֵ:0x00000000������:32
 �Ĵ���˵��: AFBCE SRAM���ƼĴ�����SP��
*****************************************************************************/
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int      value;
    struct
    {
        unsigned int  afbcd_mem_ctrl_0 : 4;  /* bit[0-3]  : �����üĴ���,afbcd_br memory�͹�����������
                                                            [3] mem_ctrl_auto_en , �Զ�ģʽ����������ģʽѡ��,0�Զ�ģʽ��1��������ģʽ 
                                                            [2]: ��������ģʽ����Ч��Ϊ1��ʾ����Shut Downģʽ
                                                            [1]: ��������ģʽ����Ч��Ϊ1��ʾ����Deep Sleepģʽ
                                                            [0]: ��������ģʽ����Ч��Ϊ1��ʾ����Sleepģʽ */
        unsigned int  afbcd_mem_ctrl_1 : 4;  /* bit[4-7]  : �����üĴ���,vbif_rdata_ram memory�͹�����������
                                                            [3] mem_ctrl_auto_en , �Զ�ģʽ����������ģʽѡ��,0�Զ�ģʽ��1��������ģʽ 
                                                            [2]: ��������ģʽ����Ч��Ϊ1��ʾ����Shut Downģʽ
                                                            [1]: ��������ģʽ����Ч��Ϊ1��ʾ����Deep Sleepģʽ
                                                            [0]: ��������ģʽ����Ч��Ϊ1��ʾ����Sleepģʽ */
        unsigned int  afbcd_mem_ctrl_2 : 4;  /* bit[8-11] : �����üĴ���,afbcd_write memory�͹������ã�
                                                            [3] mem_ctrl_auto_en , �Զ�ģʽ����������ģʽѡ��,0�Զ�ģʽ��1��������ģʽ 
                                                            [2]: ��������ģʽ����Ч��Ϊ1��ʾ����Shut Downģʽ
                                                            [1]: ��������ģʽ����Ч��Ϊ1��ʾ����Deep Sleepģʽ
                                                            [0]: ��������ģʽ����Ч��Ϊ1��ʾ����Sleepģʽ */
        unsigned int  reserved         : 20; /* bit[12-31]: ���� */
    } reg;
} SOC_DSS_RCH_G_AFBCD_MEM_CTRL_UNION;
#endif
#define SOC_DSS_RCH_G_AFBCD_MEM_CTRL_afbcd_mem_ctrl_0_START  (0)
#define SOC_DSS_RCH_G_AFBCD_MEM_CTRL_afbcd_mem_ctrl_0_END    (3)
#define SOC_DSS_RCH_G_AFBCD_MEM_CTRL_afbcd_mem_ctrl_1_START  (4)
#define SOC_DSS_RCH_G_AFBCD_MEM_CTRL_afbcd_mem_ctrl_1_END    (7)
#define SOC_DSS_RCH_G_AFBCD_MEM_CTRL_afbcd_mem_ctrl_2_START  (8)
#define SOC_DSS_RCH_G_AFBCD_MEM_CTRL_afbcd_mem_ctrl_2_END    (11)


/*****************************************************************************
 �ṹ��    : SOC_DSS_RCH_G_AFBCD_SCRAMBLE_MODE_UNION
 �ṹ˵��  : AFBCD_SCRAMBLE_MODE �Ĵ����ṹ���塣��ַƫ����:0x0940����ֵ:0x00000000������:32
 �Ĵ���˵��: SCRAMBLEģʽѡ��
*****************************************************************************/
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int      value;
    struct
    {
        unsigned int  afbcd_scramble_mode : 2;  /* bit[0-1] : Ҫ��GPU����AFBCD������һ�£���DALLAS��ֻ�����2'b00
                                                               2'b00 ��scramble ���ݵ�ǰ�Ĺ��ܡ�
                                                              ����ֵ�������� */
        unsigned int  reserved            : 30; /* bit[2-31]: ���� */
    } reg;
} SOC_DSS_RCH_G_AFBCD_SCRAMBLE_MODE_UNION;
#endif
#define SOC_DSS_RCH_G_AFBCD_SCRAMBLE_MODE_afbcd_scramble_mode_START  (0)
#define SOC_DSS_RCH_G_AFBCD_SCRAMBLE_MODE_afbcd_scramble_mode_END    (1)


/*****************************************************************************
 �ṹ��    : SOC_DSS_RCH_G_AFBCD_HEADER_POINTER_OFFSET_UNION
 �ṹ˵��  : AFBCD_HEADER_POINTER_OFFSET �Ĵ����ṹ���塣��ַƫ����:0x0944����ֵ:0x00000000������:32
 �Ĵ���˵��: ��ͼheader pointer����ͼheader pointer֮���offset
*****************************************************************************/
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int      value;
    struct
    {
        unsigned int  afbcd_header_pointer_offset : 32; /* bit[0-31]: ��ͼheader pointer����ͼheader pointer֮���offset */
    } reg;
} SOC_DSS_RCH_G_AFBCD_HEADER_POINTER_OFFSET_UNION;
#endif
#define SOC_DSS_RCH_G_AFBCD_HEADER_POINTER_OFFSET_afbcd_header_pointer_offset_START  (0)
#define SOC_DSS_RCH_G_AFBCD_HEADER_POINTER_OFFSET_afbcd_header_pointer_offset_END    (31)


/*****************************************************************************
 �ṹ��    : SOC_DSS_RCH_G_AFBCD_MONITOR_REG1_UNION
 �ṹ˵��  : AFBCD_MONITOR_REG1 �Ĵ����ṹ���塣��ַƫ����:0x0948����ֵ:0x00000000������:32
 �Ĵ���˵��: ��ά�ɲ�Ĵ���1��
*****************************************************************************/
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int      value;
    struct
    {
        unsigned int  afbcd_monitor_reg1 : 32; /* bit[0-31]: afbcd_monitor_reg1��activeģ���ddr rdģ����ԼĴ���
                                                             [31:16] ������Ŀǰ��0��
                                                             [15] activeģ��frame_start_internal
                                                             [14] activeģ��end_req_internal
                                                             [13] activeʱ���ſ�ʹ���ź�
                                                             [12] activeģ��sd_en
                                                             [11:8] activeģ��״̬��frame_cur
                                                             [7:6] ������Ŀǰ��0��
                                                             [5:0] DDR RD�ӿ�outstanding������ */
    } reg;
} SOC_DSS_RCH_G_AFBCD_MONITOR_REG1_UNION;
#endif
#define SOC_DSS_RCH_G_AFBCD_MONITOR_REG1_afbcd_monitor_reg1_START  (0)
#define SOC_DSS_RCH_G_AFBCD_MONITOR_REG1_afbcd_monitor_reg1_END    (31)


/*****************************************************************************
 �ṹ��    : SOC_DSS_RCH_G_AFBCD_MONITOR_REG2_UNION
 �ṹ˵��  : AFBCD_MONITOR_REG2 �Ĵ����ṹ���塣��ַƫ����:0x094C����ֵ:0x00000000������:32
 �Ĵ���˵��: ��ά�ɲ�Ĵ���2��
*****************************************************************************/
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int      value;
    struct
    {
        unsigned int  afbcd_monitor_reg2 : 32; /* bit[0-31]: afbcd_monitor_reg2��mm writeģ����ԼĴ���
                                                             [31:23] ������Ŀǰ��0��
                                                             [22] mm writeģ��ͬ����λ���ָʾ�ź� srst_all_ack
                                                             [21] id_afifo ��״̬
                                                             [20] id_afifo ��״̬
                                                             [19] data_fifo ��״̬
                                                             [18] data_fifo ��״̬
                                                             [17] aw_afifo ��״̬
                                                             [16] aw_afifo ��״̬
                                                             [15] burst_afifo ��״̬
                                                             [14] burst_afifo ��״̬
                                                             [13] resp_fifo ��״̬
                                                             [12] resp_fifo ��״̬
                                                             [11:8] mm write�ӿ�outstanding������
                                                             [7] pingģ��ɶ�ָʾ b0_read_enable
                                                             [6] pongģ��ɶ�ָʾ b1_read_enable
                                                             [5:0] mm writeģ��״̬�� */
    } reg;
} SOC_DSS_RCH_G_AFBCD_MONITOR_REG2_UNION;
#endif
#define SOC_DSS_RCH_G_AFBCD_MONITOR_REG2_afbcd_monitor_reg2_START  (0)
#define SOC_DSS_RCH_G_AFBCD_MONITOR_REG2_afbcd_monitor_reg2_END    (31)


/*****************************************************************************
 �ṹ��    : SOC_DSS_RCH_G_AFBCD_MONITOR_REG3_UNION
 �ṹ˵��  : AFBCD_MONITOR_REG3 �Ĵ����ṹ���塣��ַƫ����:0x0950����ֵ:0x00000000������:32
 �Ĵ���˵��: ��ά�ɲ�Ĵ���3��
*****************************************************************************/
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int      value;
    struct
    {
        unsigned int  afbcd_monitor_reg3 : 32; /* bit[0-31]: afbcd_monitor_reg3��mm readģ����ԼĴ���
                                                             [31:21] ������Ŀǰ��0��
                                                             [20] rdata_blast_afifo ��״̬
                                                             [19] rdata_blast_afifo ��״̬
                                                             [18] sfifo ��״̬
                                                             [17] sfifo ��״̬
                                                             [16] mm readģ��ͬ����λ���ָʾ�ź� srst_all_ack
                                                             [15:12] mm read�ӿ�outstanding������
                                                             [11] blast_afifo ��״̬
                                                             [10] blast_afifo ��״̬
                                                             [9:8] λ��ת��״̬��
                                                             [7:0] mm readģ��״̬�� */
    } reg;
} SOC_DSS_RCH_G_AFBCD_MONITOR_REG3_UNION;
#endif
#define SOC_DSS_RCH_G_AFBCD_MONITOR_REG3_afbcd_monitor_reg3_START  (0)
#define SOC_DSS_RCH_G_AFBCD_MONITOR_REG3_afbcd_monitor_reg3_END    (31)


/*****************************************************************************
 �ṹ��    : SOC_DSS_RCH_G_REG_DEFAULT_UNION
 �ṹ˵��  : REG_DEFAULT �Ĵ����ṹ���塣��ַƫ����:0x0A00����ֵ:0x00000000������:32
 �Ĵ���˵��: ģ��Ӱ�ӼĴ����ָ���Ĭ��ֵ
*****************************************************************************/
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int      value;
    struct
    {
        unsigned int  reg_default : 1;  /* bit[0]   : ģ������Ӱ�ӼĴ����ָ���Ĭ��ֵ������Ч */
        unsigned int  reserved    : 31; /* bit[1-31]:  */
    } reg;
} SOC_DSS_RCH_G_REG_DEFAULT_UNION;
#endif
#define SOC_DSS_RCH_G_REG_DEFAULT_reg_default_START  (0)
#define SOC_DSS_RCH_G_REG_DEFAULT_reg_default_END    (0)






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

#endif /* end of soc_dss_rch_g_interface.h */