/***********************************************************************************************************************
* DISCLAIMER
* This software is supplied by Renesas Electronics Corporation and is only intended for use with Renesas products.
* No other uses are authorized. This software is owned by Renesas Electronics Corporation and is protected under all
* applicable laws, including copyright laws. 
* THIS SOFTWARE IS PROVIDED "AS IS" AND RENESAS MAKES NO WARRANTIESREGARDING THIS SOFTWARE, WHETHER EXPRESS, IMPLIED
* OR STATUTORY, INCLUDING BUT NOT LIMITED TO WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
* NON-INFRINGEMENT.  ALL SUCH WARRANTIES ARE EXPRESSLY DISCLAIMED.TO THE MAXIMUM EXTENT PERMITTED NOT PROHIBITED BY
* LAW, NEITHER RENESAS ELECTRONICS CORPORATION NOR ANY OF ITS AFFILIATED COMPANIES SHALL BE LIABLE FOR ANY DIRECT,
* INDIRECT, SPECIAL, INCIDENTAL OR CONSEQUENTIAL DAMAGES FOR ANY REASON RELATED TO THIS SOFTWARE, EVEN IF RENESAS OR
* ITS AFFILIATES HAVE BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.
* Renesas reserves the right, without notice, to make changes to this software and to discontinue the availability 
* of this software. By using this software, you agree to the additional terms and conditions found by accessing the 
* following link:
* http://www.renesas.com/disclaimer
*
* Copyright (C) 2015 Renesas Electronics Corporation. All rights reserved.
***********************************************************************************************************************/

/***********************************************************************************************************************
* File Name    : r_cg_lpc.h
* Version      : Code Generator for RX23T V1.00.01.01 [30 Oct 2015]
* Device(s)    : R5F523T5AxFM
* Tool-Chain   : CCRX
* Description  : This file implements device driver for LPC module.
* Creation Date: 2017/7/12
***********************************************************************************************************************/
#ifndef LPC_H
#define LPC_H

/***********************************************************************************************************************
Macro definitions (Register bit)
***********************************************************************************************************************/
/* 
    Operating Power Control Register (OPCCR)
*/
/* Operating Power Control Mode Select (OPCM[2:0]) */
#define _00_LPC_HIGH_SPEED_MODE             (0x00U) /* High-speed operating mode */
#define _02_LPC_MIDDLE_SPEED_MODE           (0x02U) /* Middle-speed operating mode */


/***********************************************************************************************************************
Macro definitions
***********************************************************************************************************************/

/***********************************************************************************************************************
Typedef definitions
***********************************************************************************************************************/
typedef enum
{
    RESERVED,
    MIDDLE_SPEED,
    HIGH_SPEED
} operating_mode_t;


/***********************************************************************************************************************
Global functions
***********************************************************************************************************************/
void R_LPC_Create(void);
MD_STATUS R_LPC_Sleep(void);
MD_STATUS R_LPC_DeepSleep(void);
MD_STATUS R_LPC_SoftwareStandby(void);
MD_STATUS R_LPC_ChangeOperatingPowerControl(operating_mode_t mode);

/* Start user code for function. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
#endif