/* *  sonyimx328 camera driver head file * *  CopyRight (C) Hisilicon Co., Ltd.
*	Author : *  Version:  1.2
* This program is free software; you can
* redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation; either version 2 of the License, or
* (at your option) any later version.
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY;without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
* You should have received a copy of the GNU General Public License
* along with this program; if not, write to the Free Software
* Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*/

#ifndef _SONYIMX328_ALICE_H_
#define _SONYIMX328_ALICE_H_


//#include "k3_isp_io.h"
#include "k3_isp.h"
#include "k3_ispv1.h"
/***********************************************************************
 *
 * sonyimx328 init sensor registers list
 *
 ***********************************************************************/
static const struct _sensor_reg_t sonyimx328_alice_init_regs[] = {
{	0x3087	,	0x53	},
{	0x309D	,	0x94	},
{	0x30A1	,	0x08	},
{	0x30AA	,	0x04	},
{	0x30B1	,	0x03	},//bl normal tracking mode
{	0x30C7	,	0x00	},
{	0x3115	,	0x0E	},
{	0x3118	,	0x42	},
{	0x311D	,	0x34	},
{	0x3121	,	0x0D	},
{	0x3212	,	0xF2	},
{	0x3213	,	0x0F	},
{	0x3215	,	0x0F	},
{	0x3217	,	0x0B	},
{	0x3219	,	0x0B	},
{	0x321B	,	0x0D	},
{	0x321D	,	0x0D	},
{	0x3099	,	0x12	},
{	0x3095	,	0x87	},
{	0x3032	,	0x40	},
{	0x0202	,	0x01	},
{	0x0203	,	0xFF	},
{	0x0205	,	0x00	},
{	0x020E	,	0x01	},
{	0x020F	,	0x00	},
{	0x0210	,	0x01	},
{	0x0211	,	0x00	},
{	0x0212	,	0x01	},
{	0x0213	,	0x00	},
{	0x0214	,	0x01	},
{	0x0215	,	0x00	},
{	0x0101	,	0x03	},
};

static const struct _sensor_reg_t sonyimx328_alice_framesize_quater[] ={
/*RES_2080x1560,fps = 30,data rate = 282.84MHz/lane*/
{	0x0100	,	0x00	},
{	0x0305	,	0x02	},
{	0x0307	,	0x37	},
{	0x30A4	,	0x02	},
{	0x303C	,	0x40	},
{	0x0112	,	0x0A	},
{	0x0113	,	0x0A	},
{	0x0340	,	0x06	},
{	0x0341	,	0x6C	},
{	0x0342	,	0x12	},
{	0x0343	,	0x0C	},
{	0x0344	,	0x00	},
{	0x0345	,	0x20	},
{	0x0346	,	0x00	},
{	0x0347	,	0x30	},
{	0x0348	,	0x10	},
{	0x0349	,	0x5F	},
{	0x034A	,	0x0C	},
{	0x034B	,	0x5F	},
{	0x034C	,	0x08	},
{	0x034D	,	0x20	},
{	0x034E	,	0x06	},
{	0x034F	,	0x18	},
{	0x0381	,	0x01	},
{	0x0383	,	0x03	},
{	0x0385	,	0x01	},
{	0x0387	,	0x03	},
{	0x3033	,	0x00	},
{	0x303D	,	0x10	},
{	0x303E	,	0xD0	},
{	0x3040	,	0x08	},
{	0x3041	,	0x97	},
{	0x3048	,	0x01	},
{	0x304C	,	0x7F	},
{	0x304D	,	0x04	},
{	0x3064   ,	0x12       },
{	0x309B   ,	0x28       },
{	0x309E   ,	0x00       },
{	0x30A0   ,	0x14       },
{	0x30B2   ,	0x00       },
{	0x30D5   ,	0x09       },
{	0x30D6   ,	0x01       },
{	0x30D7   ,	0x01       },
{	0x30D8   ,	0x64       },
{	0x30D9   ,	0x89       },
{	0x30DA   ,	0x00       },
{	0x30DB   ,	0x00       },
{	0x30DC   ,	0x00       },
{	0x30DD   ,	0x00       },
{	0x30DE   ,	0x02       },
{	0x3102   ,	0x10       },
{	0x3103   ,	0x44       },

{	0x3104   ,	0x40       },
{	0x3105   ,	0x00       },
{	0x3106   ,	0x0D       },
{	0x3107   ,	0x01       },
{	0x310A   ,	0x0A       },
{	0x315C   ,	0x99       },
{	0x315D   ,	0x98       },
{	0x316E   ,	0x9A       },
{	0x316F   ,	0x99       },
{	0x3301   ,	0x03       },
{	0x3304   ,	0x05       },
{	0x3305   ,	0x04       },
{	0x3306   ,	0x12       },
{	0x3307   ,	0x03       },
{	0x3308   ,	0x0D       },
{	0x3309   ,	0x05       },
{	0x330A   ,	0x09       },
{	0x330B   ,	0x04       },
{	0x330C   ,	0x08       },
{	0x330D   ,	0x05       },
{	0x330E   ,	0x03       },
{	0x3318   ,	0x73       },
{	0x3322   ,	0x02       },
{	0x3342   ,	0x0F       },
{	0x3348   ,	0xE0       },
{   0x30B1   ,  0x43       },//set optical black level to fast tracking mode

{	0x0100   ,	0x01	},

};

static const struct _sensor_reg_t sonyimx328_alice_framesize_fullsize_nonzsl[] ={
#if 0 //10fps
/*RES_4160x3120,fps = 10,data rate = 390.83MHz/lane*/
{	0x0100	,	0x00	},
{	0x0305	,	0x02	},
{	0x0307	,	0x26	},
{	0x30A4	,	0x02	},
{	0x303C	,	0x40	},
{	0x0112	,	0x0A	},
{	0x0113	,	0x0A	},
{	0x0340	,	0x0D	},
{	0x0341	,	0x38	},
{	0x0342	,	0x12	},
{	0x0343	,	0x0C	},
{	0x0344	,	0x00	},
{	0x0345	,	0x20	},
{	0x0346	,	0x00	},
{	0x0347	,	0x30	},
{	0x0348	,	0x10	},
{	0x0349	,	0x5F	},
{	0x034A	,	0x0C	},
{	0x034B	,	0x5F	},
{	0x034C	,	0x10	},
{	0x034D	,	0x40	},
{	0x034E	,	0x0C	},
{	0x034F	,	0x30	},
{	0x0381	,	0x01	},
{	0x0383	,	0x01	},
{	0x0385	,	0x01	},
{	0x0387	,	0x01	},
{	0x3033	,	0x00	},
{	0x303D	,	0x10	},
{	0x303E	,	0xD0	},
{	0x3040	,	0x08	},
{	0x3041	,	0x97	},
{	0x3048	,	0x00	},
{	0x304C	,	0x7F	},
{	0x304D	,	0x04	},
{	0x3064   ,	0x12       },
{	0x309B   ,	0x20       },
{	0x309E   ,	0x00       },
{	0x30A0   ,	0x14       },
{	0x30B2   ,	0x00       },
{	0x30D5   ,	0x00       },
{	0x30D6   ,	0x85       },
{	0x30D7   ,	0x2A       },
{	0x30D8   ,	0x64       },
{	0x30D9   ,	0x89       },
{	0x30DA   ,	0x00       },
{	0x30DB   ,	0x00       },
{	0x30DC   ,	0x00       },
{	0x30DD   ,	0x00       },
{	0x30DE   ,	0x00       },
{	0x3102   ,	0x10       },
{	0x3103   ,	0x44       },

{	0x3104   ,	0x40       },
{	0x3105   ,	0x00       },
{	0x3106   ,	0x0D       },
{	0x3107   ,	0x01       },
{	0x310A   ,	0x0A       },
{	0x315C   ,	0x99       },
{	0x315D   ,	0x98       },
{	0x316E   ,	0x9A       },
{	0x316F   ,	0x99       },
{	0x3301   ,	0x03       },
{	0x3304   ,	0x05       },
{	0x3305   ,	0x04       },
{	0x3306   ,	0x12       },
{	0x3307   ,	0x03       },
{	0x3308   ,	0x0D       },
{	0x3309   ,	0x05       },
{	0x330A   ,	0x09       },
{	0x330B   ,	0x04       },
{	0x330C   ,	0x08       },
{	0x330D   ,	0x05       },
{	0x330E   ,	0x03       },
{	0x3318   ,	0x67       },
{	0x3322   ,	0x02       },
{	0x3342   ,	0x0F       },
{	0x3348   ,	0xE0       },
{	0x0100   ,	0x01	},
#else//13fps
/*RES_4160x3120,fps = 13,data rate = 483.395MHz/lane*/
{0x0100, 0x00},
{0x0305, 0x02},
{0x0307, 0x2F},
{0x30A4, 0x02},
{0x303C, 0x40},

{0x0112, 0x0A},
{0x0113, 0x0A},
{0x0340, 0x0C},
{0x0341, 0x96},
{0x0342, 0x12},
{0x0343, 0x0C},
{0x0344, 0x00},
{0x0345, 0x20},
{0x0346, 0x00},
{0x0347, 0x30},
{0x0348, 0x10},
{0x0349, 0x5F},
{0x034A, 0x0C},
{0x034B, 0x5F},
{0x034C, 0x10},
{0x034D, 0x40},
{0x034E, 0x0C},
{0x034F, 0x30},
{0x0381, 0x01},
{0x0383, 0x01},
{0x0385, 0x01},
{0x0387, 0x01},
{0x3033, 0x00},
{0x303D, 0x10},
{0x303E, 0xD0},
{0x3040, 0x08},
{0x3041, 0x97},
{0x3048, 0x00},
{0x304C, 0x7F},
{0x304D, 0x04},
{0x3064, 0x12},
{0x309B, 0x20},
{0x309E, 0x00},
{0x30A0, 0x14},
{0x30B2, 0x00},
{0x30D5, 0x00},
{0x30D6, 0x85},
{0x30D7, 0x2A},
{0x30D8, 0x64},
{0x30D9, 0x89},
{0x30DA, 0x00},
{0x30DB, 0x00},
{0x30DC, 0x00},
{0x30DD, 0x00},
{0x30DE, 0x00},
{0x3102, 0x10},
{0x3103, 0x44},
{0x3104, 0x40},
{0x3105, 0x00},
{0x3106, 0x0D},
{0x3107, 0x01},
{0x310A, 0x0A},
{0x315C, 0x99},
{0x315D, 0x98},
{0x316E, 0x9A},
{0x316F, 0x99},
{0x3301, 0x03},
{0x3304, 0x05},
{0x3305, 0x04},
{0x3306, 0x12},
{0x3307, 0x03},
{0x3308, 0x0D},
{0x3309, 0x05},
{0x330A, 0x09},
{0x330B, 0x04},
{0x330C, 0x08},
{0x330D, 0x05},
{0x330E, 0x03},
{0x3318, 0x65},
{0x3322, 0x02},
{0x3342, 0x0F},
{0x3348, 0xE0},
{0x30B1, 0x43},//set optical black level to fast tracking mode

{0x0100, 0x01}
#endif
};
static sensor_setting_t sonyimx328_alice_init_array[] = {
    {sonyimx328_alice_init_regs, ARRAY_SIZE(sonyimx328_alice_init_regs)},
};

static framesize_s sonyimx328_alice_framesizes[] = {
    {0, 0, 2080, 1560, 4620, 1644, 30, 30, 0x1EA, 0x198, 0x100, VIEW_FULL, RESOLUTION_4_3, false, false,{sonyimx328_alice_framesize_quater, ARRAY_SIZE(sonyimx328_alice_framesize_quater)}, CLK_300M },
    //{0, 0, 4160, 3120, 4620, 3290, 10, 10, 0x152, 0x11A, 0xB1, VIEW_FULL, RESOLUTION_4_3, false, false,{sonyimx328_framesize_fullsize_nonzsl, ARRAY_SIZE(sonyimx328_framesize_fullsize_nonzsl)}, CLK_400M},
    {0, 0, 4160, 3120, 4620, 3222, 13, 13, 0x1A2, 0x15C, 0xE0, VIEW_FULL, RESOLUTION_4_3, false, false,{sonyimx328_alice_framesize_fullsize_nonzsl, ARRAY_SIZE(sonyimx328_alice_framesize_fullsize_nonzsl)}, CLK_500M}
};

#endif//_SONYIMX328_ALICE_H_

/************************** END ***************************/
