// License       : License.txt
// Specifications: Spec-00000058.pdf
/*-- File Header Comment Start -----------------------------------------------*/
// File Name        : MPX5999D_00000058.cpp
// BSL              : 00000058
// Model number     : NXP MPX5999D
// Spec               Component type       : ADC
//                    OS                   : Mbed
//                    Calculation          : Floating-point
//                    Conversion type      : Linear
//                    Moving average filter: Moving average filter select
//                    Diagnosis            : Range (Min to Max)
// Reason for change: 01.00.00 : 20/10/'22 : New Release
// Nickname         : Blue Dragon
/*-- File Header Comment End -------------------------------------------------*/

#include "MPX5999D.h"

AnalogIn MPX5999D_adc( iMPX5999D_pin , iVref );         // AnalogIn object

// Main Function
pp2ap_adc_t MPX5999D_00000058( void )
{
        pp2ap_adc_t res = pp_00000058( MPX5999D_adc , tbl_MPX5999D );
        return( res );
}
