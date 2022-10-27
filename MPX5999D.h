// License       : License.txt
// Specifications: Spec-MPX5999D.pdf
/*-- File Header Comment Start -----------------------------------------------*/
// File Name        : MPX5999D.h
// Reason for change: 01.00.00 : 20/10/'22 : New Release
// Nickname         : Blue Dragon
/*-- File Header Comment End -------------------------------------------------*/

#ifndef __MPX5999D_H__
#define __MPX5999D_H__

#include "user_define.h"

// Components number
#define iMPX5999D               118U                    // NXP MPX5999D

// MPX5999D System Parts definitions
#define iMPX5999D_xoff          ( 0.04F*iADC_vdd )      // X offset [V]
#define iMPX5999D_yoff          0.0F                    // Y offset [kPa]
#define iMPX5999D_gain          ( 0.000901F*iADC_vdd )  // Gain [V/kPa]
#define iMPX5999D_max           1000.0F                 // Pressure Max [kPa]
#define iMPX5999D_min           0.0F                    // Pressure Min [kPa]

extern const tbl_adc_t tbl_MPX5999D;

#endif /*__MPX5999D_H__*/
