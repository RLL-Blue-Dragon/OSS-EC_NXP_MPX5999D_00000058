// License       : License.txt
// Specifications: Spec-MPX5999D.pdf
/*-- File Header Comment Start -----------------------------------------------*/
// File Name        : MPX5999D.cpp
// Reason for change: 01.00.00 : 20/10/'22 : New Release
// Nickname         : Blue Dragon
/*-- File Header Comment End -------------------------------------------------*/

#include        "MPX5999D.h"

#if     iMPX5999D_ma == iSMA                            // Simple moving average filter
static float32 MPX5999D_sma_buf[iMPX5999D_SMA_num];
static sma_f32_t MPX5999D_Phy_SMA =
{
        iInitial ,                                      // Initial state
        iMPX5999D_SMA_num ,                             // Simple moving average number & buf size
        0U ,                                            // buffer position
        0.0F ,                                          // sum
        &MPX5999D_sma_buf[0]                            // buffer
};

#elif   iMPX5999D_ma == iEMA                            // Exponential moving average filter
static ema_f32_t MPX5999D_Phy_EMA =
{
        iInitial ,                                      // Initial state
        0.0F ,                                          // Xn-1
        iMPX5999D_EMA_K                                 // Exponential smoothing factor 
};

#elif   iMPX5999D_ma == iWMA                            // Weighted moving average filter
static float32 MPX5999D_wma_buf[iMPX5999D_WMA_num];
static wma_f32_t MPX5999D_Phy_WMA =
{
        iInitial ,                                      // Initial state
        iMPX5999D_WMA_num ,                             // Weighted moving average number & buf size
        0U ,                                            // buffer poition
        iMPX5999D_WMA_num * (iMPX5999D_WMA_num + 1)/2 , // kn sum
        &MPX5999D_wma_buf[0]                            // Xn buffer
};

#else                                                   // Non-moving average filter
#endif

#define iDummy_adr       0xffffffff                     // Dummy address

const tbl_adc_t tbl_MPX5999D =
{
        iMPX5999D               ,
        iMPX5999D_pin           ,
        iMPX5999D_xoff          ,
        iMPX5999D_yoff          ,
        iMPX5999D_gain          ,
        iMPX5999D_max           ,
        iMPX5999D_min           ,
        iMPX5999D_ma            ,
        
#if     iMPX5999D_ma == iSMA                            // Simple moving average filter
        &MPX5999D_Phy_SMA       ,
        (ema_f32_t*)iDummy_adr  ,
        (wma_f32_t*)iDummy_adr
#elif   iMPX5999D_ma == iEMA                            // Exponential moving average filter
        (sma_f32_t*)iDummy_adr  ,
        &MPX5999D_Phy_EMA       ,
        (wma_f32_t*)iDummy_adr
#elif   iMPX5999D_ma == iWMA                            // Weighted moving average filter
        (sma_f32_t*)iDummy_adr  ,
        (ema_f32_t*)iDummy_adr  ,
        &MPX5999D_Phy_WMA
#else                                                   // Non-moving average filter
        (sma_f32_t*)iDummy_adr  ,
        (ema_f32_t*)iDummy_adr  ,
        (wma_f32_t*)iDummy_adr
#endif

};
