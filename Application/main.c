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
<<<<<<< HEAD
=======
<<<<<<< HEAD
=======
#include "GUITYPE.h"
>>>>>>> 6e13ebed3951febe16d72b2b8ab347d26e2a619b
>>>>>>> 0ecd8ba54a88b7b74b2113cf11b208fb2fec78f3

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

<<<<<<< HEAD
  while(1)
  {
	
	float f = 123.45678;
  //int LCDXSize = LCD_GET_XSIZE();
  //int LCDYSize = LCD_GET_YSIZE();
    GUI_Init();
  /
	GUI_Delay(10000);
=======
while(1)
{
<<<<<<< HEAD
  int Cnt =0;
  int i,YPos;
  int LCDXSize = LCD_GET_XSIZE();
  int LCDYSize = LCD_GET_YSIZE();
  const GUI_BITMAP *pBitmap;
  GUI_Init();
  GUI_SetBkColor(GUI_RED); GUI_Clear();
  GUI_Delay(1000);
  GUI_SetBkColor(GUI_BLUE); GUI_Clear();
  GUI_Delay(1000);
  GUI_SetColor(GUI_WHITE);
  for (i=0; i<1000; i+=10) {
    GUI_DrawHLine(i,0,100);
    GUI_DispStringAt("Line ",0,i);
    GUI_DispDecMin(i);
  }
  GUI_Delay(1000);
  GUI_SetColor(0x0);
  GUI_SetBkColor(0xffffff);
  for (i=0; i<160; i++) {
    int len = (i<80) ? i : 160-i;
    GUI_DrawHLine(i,20,len+20);
>>>>>>> 0ecd8ba54a88b7b74b2113cf11b208fb2fec78f3
  }
}
<<<<<<< HEAD

=======
=======
  //int LCDXSize = LCD_GET_XSIZE();
  //int LCDYSize = LCD_GET_YSIZE();
  GUI_Init();
  //GUI_RECT &rClinet;
  //GUI_GetClientRect(&rClinet);
  //GUI_DispStringInRect("hello I am lujiawei", &rClient, GUI_TA_HCENTER|GUI_TA_VCENTER);
  //GUI_GotoXY(400,240);						//移动文本坐标
  //GUI_GotoX();								//移动x坐标
  //GUI_Gotoy();								//移动y坐标
  //GUI_DispCharAt('c',567,89);
  //GUI_DispString("HELLO World !");
  //GUI_Delay(500);
  //GUI_DispStringAtCEOL("hi !",400 ,240);		//擦除改行字符串写这次字符串
	//GUI_DispStringLen("陆佳伟 ",10);
/*
	GUI_SetFont(&GUI_Font8x16);
	GUI_SetBkColor(GUI_BLUE);
	GUI_Clear();								//清除一个视窗或其他部分的函数
	GUI_SetPenSize(10);
	GUI_SetColor(GUI_RED);
	GUI_DrawLine(80,10,240,90);
	GUI_DrawLine(80,90,240,10);
	GUI_SetBkColor(GUI_BLACK);
	GUI_SetColor(GUI_WHITE);
	GUI_SetTextMode(GUI_TM_NORMAL);				//正常文本
	GUI_DispStringHCenterAt("GUI_TM_NORMAL",160,10);	//居中对齐
	GUI_SetTextMode(GUI_TM_REV);				//反向文本
	GUI_DispStringHCenterAt("GUI_TM_REV",160,26);

	GUI_SetTextMode(GUI_TM_TRANS);			//透明文本
	GUI_DispStringHCenterAt("GUI_TM_TRANS",160,42);
	
	GUI_SetTextMode(GUI_TM_XOR);			//异或文本
    GUI_DispStringHCenterAt("GUI_TM_XOR",160,58);
*/
	GUI_SetTextAlign(GUI_TA_HCENTER | GUI_TA_VCENTER);					//对齐方式
    GUI_DispDecAt(1234,100,100,4);							//写数字
	GUI_GetDispPosX();							//返回文本当前坐标
	GUI_GetDispPosY();
    GUI_Delay(10000);

}
}
>>>>>>> 6e13ebed3951febe16d72b2b8ab347d26e2a619b
>>>>>>> 0ecd8ba54a88b7b74b2113cf11b208fb2fec78f3
