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
* File Name    : r_cg_main.c
* Version      : Code Generator for RX23T V1.00.01.01 [30 Oct 2015]
* Device(s)    : R5F523T5AxFM
* Tool-Chain   : CCRX
* Description  : This file implements main function.
* Creation Date: 2017/7/12
***********************************************************************************************************************/

/***********************************************************************************************************************
Pragma directive
***********************************************************************************************************************/
/* Start user code for pragma. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
#include "r_cg_macrodriver.h"
#include "r_cg_cgc.h"
#include "r_cg_lpc.h"
#include "r_cg_sci.h"
/* Start user code for include. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
#include "r_cg_userdefine.h"

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
/* Start user code for global. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */


void R_MAIN_UserInit(void);
/***********************************************************************************************************************
* Function Name: main
* Description  : This function implements main function.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void main(void)
{
    R_MAIN_UserInit();
    /* Start user code. Do not edit comment generated here */
    while (1U)
    {
    	Msg_FMU_To_Ctrl_Update();           // 接收、解析飞控发送的信息
    	Msg_Smp_To_Ctrl_Update();           // 接收、解析采集板发送的信息
        Update_Key_Value();                 // 更新按键状态值
        Update_Encoder_Value();             // 更新编码器当前值

       //Msg_FMU_To_Ctrl_Update();           两者都需要调用接收函数，暂未定义// 接收、解析飞控发送的信息
       //Msg_Smp_To_Ctrl_Update();           // 接收、解析采集板发送的信息

        //Debug_Message_Handle();          串口三接收数据，暂未定义   //处理调试信息

        Unlock_FMU_By_Key_Handle();         // 解锁按件信息处理

        SysCtrl_Update_PID();               // 更新系统PID设定值等
        SysCtrl_Update_Act();               // 更新系统控制状态(动作)
        SysCtrl_Update_Lost_Info();         //更新系统丢失特征点如何继续追踪信息
       //从串口一发送数据 SysCtrl_Update_Msg_Ctrl_To_FMU();   //更新控制板发送给飞控的信息
        //从串口三发送调试信息，串口三暂未定义Dbg_U3_Send_Msg();                  //
    }
    /* End user code. Do not edit comment generated here */
}
/***********************************************************************************************************************
* Function Name: R_MAIN_UserInit
* Description  : This function adds user code before implementing main function.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_MAIN_UserInit(void)
{
    /* Start user code. Do not edit comment generated here */
	    R_SCI1_Create();
	    R_SCI5_Create();

	    R_SCI1_Stop();
	    R_SCI5_Stop();

	    SysCtrl_Msg_Ctrl_To_FMU_Init();     // 初始化控制板发送给飞控的信息
	    Msg_Ctrl_To_Smp_Init();             // 初始化控制板发送给采集板的信息

	    PID_Parameter_Init();               // 系统PID参数初始化
	    Dbg_PID_Cache_Init();               // PID调试缓存值初始化
	    Usart_Rx_Buf_Init ();               // 串口接收缓存区初始化

	    Update_Key_PowerOn_Value();         // 获取按键系统上电时的状态
	    Update_Encoder_PowerOn_Value();     // 获取编码器在系统上电时的初始状态
	    SysDelay_ms(1000);                  // 延时等待系统稳定

	    SysCtrl_Init_Find_Start_Point();    // 初始化找起点的数据记录


	//三个串口各自接收一次初始化的数据，需要关调用一次接收数据的函数R_SCI1_Serial_Receive(uint8_t * const rx_buf, uint16_t rx_num);，三个串口名暂未定义
	Usart_Receive_IT(&huart1, U1RxBuf, sizeof(Msg_FMUToCtrl_t));    // 串口1接收一次飞控发送的数据包
	Usart_Receive_IT(&huart2, U2RxBuf, sizeof(Msg_SmpToCtrl_t));    // ´®¿Ú2×¼±¸½ÓÊÕ²É¼¯°å·¢ËÍµÄÊý¾Ý°ü
	//Usart_Receive_IT(&huart3, U3RxBuf, 1);                          // ´®¿Ú3×¼±¸½ÓÊÕ1¸ö×Ö½ÚµÄµ÷ÊÔÃüÁî

	//开启串口
	R_SCI1_Start();
	R_SCI5_Start();

	//Key_PowerOn_Event_Handle();//保存遥控器微调参数,需要保存到flash中，暂未定义
    /* End user code. Do not edit comment generated here */
}

/* Start user code for adding. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
