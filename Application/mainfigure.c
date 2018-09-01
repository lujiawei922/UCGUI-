/*
*********************************************************************************************************
*                                                礐/GUI
*                        Universal graphic software for embedded applications
*
*                       (c) Copyright 2002, Micrium Inc., Weston, FL
*                       (c) Copyright 2000, SEGGER Microcontroller Systeme GmbH          
*
*              礐/GUI is protected by international copyright laws. Knowledge of the
*              source code may not be used to write a similar product. This file may
*              only be used in accordance with a license and should not be redistributed 
*              in any way. We appreciate your understanding and fairness.
*
* File        : Main.c
* Purpose     : Application program in windows simulator
*********************************************************************************************************
*/


#include "GUI.h"

extern const GUI_BITMAP bmMicriumLogo;
extern const GUI_BITMAP bmMicriumLogo_1bpp;


/*
  *******************************************************************
  *
  *              main()
  *
  *******************************************************************
*/
void main(void) {

  while(1)
  {
	
	float f = 123.45678;
  //int LCDXSize = LCD_GET_XSIZE();
  //int LCDYSize = LCD_GET_YSIZE();
    GUI_Init();
  //int tmp = -12345;
	//GUI_DispDec(-123456,8);			//描写8个数字，不足空位补0
	/*
	GUI_DispString("Min");
	GUI_DispDec(12,2);
	GUI_DispString("Sec:");
	GUI_DispDec(2,2);
	*/	
	//GUI_DispDecAt(-1234,54,89,9);		//显示数字数量最大为9不足补0
	//GUI_DispDecMin(-1234567);			//自动使用最小的长度值
	
	//GUI_DispDecShift(2131234,9,2);		//最多9位，两位小数，不足补0
	
	//GUI_DispDecSpace(342674,100);			//空格补位，最多9个数字
	
	//GUI_DispSDecShift(12231,9,2);			//一定带符号，不足补0
	/*
	//浮点数
	GUI_SetFont(&GUI_Font8x8);
	GUI_DispStringAt("GUI_DispFloat:\n",0,0);
	GUI_DispFloat(f,9);					//不支持首位为0，数值为负时显示负数
    
	*/
	//GUI_DispFloatFix(-3213.234,9,1);	//支持首位为0,小数点为1位
	
	//GUI_DispFloatMin(-12313.22,1);		//最小位数显示，小数位为1
	
		
	 //GUI_DispSFloatFix(13312.11,9,1);					//支持首位为0，总显示符号
	 //GUI_DispSFloatMin(1231.123,2);				//不支持首位为0，总显示符号,小数两位
	 //二进制
	 //GUI_DispBin(1233,16);					      //显示二进制数值			
	 
	 //GUI_DispBinAt(1233,10,10,8);					//在固定位置显示二进制
	 
	 //十六进制
	 //GUI_DispHex(3312332,8);						//显示16进制，8个数字不全补0
	 //GUI_DispHexAt(798432,67,78,8);								//在指定位置显示16进制数字

	 //GUI_GetVersionString();						//显示uc/GUI的版本
	 
	GUI_Delay(10000);
  }
}

