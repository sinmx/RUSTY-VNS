/* MD5: f15bfab7f1d30b720661c5c55bb7bcaa*/
#if !defined(__PRODUCT_CONFIG_GUCPHY_H__)
#define __PRODUCT_CONFIG_GUCPHY_H__

#ifndef ZSP_DSP_CHIP_BB_TYPE		
#define ZSP_DSP_CHIP_BB_TYPE		 11 
#endif 

#ifndef ZSP_DSP_PRODUCT_FORM		
#define ZSP_DSP_PRODUCT_FORM		 4 
#endif 

#ifndef BOARD
#define BOARD SFT 
#endif 

#ifndef FEATURE_TEMP_DSP_CORE_POWER_DOWN
#define FEATURE_TEMP_DSP_CORE_POWER_DOWN FEATURE_OFF 
#endif 

#ifndef FEATURE_TUNER				
#define FEATURE_TUNER				 FEATURE_ON 
#endif 

#ifndef FEATURE_TEMP_MULTI_MODE_LP
#define FEATURE_TEMP_MULTI_MODE_LP FEATURE_ON 
#endif 

#ifndef FEATURE_SRAM_400K
#define FEATURE_SRAM_400K FEATURE_OFF 
#endif 

#ifndef FEATURE_EXTERNAL_32K_CLK		
#define FEATURE_EXTERNAL_32K_CLK		 FEATURE_ON 
#endif 

#ifndef FEATURE_SOCP_ON_DEMAND			
#define FEATURE_SOCP_ON_DEMAND			 FEATURE_OFF 
#endif 

#ifndef FEATURE_GU_DSP_SPLIT
#define FEATURE_GU_DSP_SPLIT FEATURE_ON 
#endif 

#ifndef FEATURE_DC_DPA			
#define FEATURE_DC_DPA			 FEATURE_ON 
#endif 

#ifndef FEATURE_HARQ_OUT
#define FEATURE_HARQ_OUT FEATURE_OFF 
#endif 

#ifndef FEATURE_MULTI_RFIC_MEAS			
#define FEATURE_MULTI_RFIC_MEAS			 FEATURE_ON 
#endif 

#ifndef FEATURE_RFIC_RESET_GPIO_ON		
#define FEATURE_RFIC_RESET_GPIO_ON		 FEATURE_OFF 
#endif 

#ifndef FEATURE_UPHY_SIO_WPLL_ELUSION_ON
#define FEATURE_UPHY_SIO_WPLL_ELUSION_ON FEATURE_OFF 
#endif 

#ifndef FEATURE_VIRTUAL_BAND			
#define FEATURE_VIRTUAL_BAND			 FEATURE_OFF 
#endif 

#ifndef FEATURE_ANT_SHARE				
#define FEATURE_ANT_SHARE				 FEATURE_OFF 
#endif 

#ifndef CPHY_PUB_DTCM_BASE	
#define CPHY_PUB_DTCM_BASE	 0x49400000 
#endif 

#ifndef CPHY_PUB_ITCM_BASE	
#define CPHY_PUB_ITCM_BASE	 0x49500000 
#endif 

#ifndef CPHY_PRV_DTCM_BASE	
#define CPHY_PRV_DTCM_BASE	 0x49480000 
#endif 

#ifndef CPHY_PRV_ITCM_BASE	
#define CPHY_PRV_ITCM_BASE	 0x49580000 
#endif 

#ifndef CPHY_PUB_DTCM_SIZE		
#define CPHY_PUB_DTCM_SIZE		 0x80000 
#endif 

#ifndef CPHY_PUB_ITCM_SIZE		
#define CPHY_PUB_ITCM_SIZE		 0x80000 
#endif 

#ifndef CPHY_PRV_DTCM_SIZE		
#define CPHY_PRV_DTCM_SIZE		 0x80000 
#endif 

#ifndef CPHY_PRV_ITCM_SIZE		
#define CPHY_PRV_ITCM_SIZE		 0x80000 
#endif 

#ifndef XTENSA_CORE_X_CACHE
#define XTENSA_CORE_X_CACHE p532_bbe16_cache 
#endif 

#endif /*__PRODUCT_CONFIG_H__*/ 
