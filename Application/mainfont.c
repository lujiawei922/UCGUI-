/*
*********************************************************************************************************
*                                                �C/GUI
*                        Universal graphic software for embedded applications
*
*                       (c) Copyright 2002, Micrium Inc., Weston, FL
*                       (c) Copyright 2000, SEGGER Microcontroller Systeme GmbH          
*
*              �C/GUI is protected by international copyright laws. Knowledge of the
*              source code may not be used to write a similar product. This file may
*              only be used in accordance with a license and should not be redistributed 
*              in any way. We appreciate your understanding and fairness.
*
* File        : Main.c
* Purpose     : Application program in windows simulator
*********************************************************************************************************
*/


#include "GUI.h"
#include "GUITYPE.h"

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
  //int LCDXSize = LCD_GET_XSIZE();
  //int LCDYSize = LCD_GET_YSIZE();
  GUI_Init();
  //GUI_RECT &rClinet;
  //GUI_GetClientRect(&rClinet);
  //GUI_DispStringInRect("hello I am lujiawei", &rClient, GUI_TA_HCENTER|GUI_TA_VCENTER);
  //GUI_GotoXY(400,240);						//�ƶ��ı�����
  //GUI_GotoX();								//�ƶ�x����
  //GUI_Gotoy();								//�ƶ�y����
  //GUI_DispCharAt('c',567,89);
  //GUI_DispString("HELLO World !");
  //GUI_Delay(500);
  //GUI_DispStringAtCEOL("hi !",400 ,240);		//���������ַ���д����ַ���
	//GUI_DispStringLen("½��ΰ ",10);
/*
	GUI_SetFont(&GUI_Font8x16);
	GUI_SetBkColor(GUI_BLUE);
	GUI_Clear();								//���һ���Ӵ����������ֵĺ���
	GUI_SetPenSize(10);
	GUI_SetColor(GUI_RED);
	GUI_DrawLine(80,10,240,90);
	GUI_DrawLine(80,90,240,10);
	GUI_SetBkColor(GUI_BLACK);
	GUI_SetColor(GUI_WHITE);
	GUI_SetTextMode(GUI_TM_NORMAL);				//�����ı�
	GUI_DispStringHCenterAt("GUI_TM_NORMAL",160,10);	//���ж���
	GUI_SetTextMode(GUI_TM_REV);				//�����ı�
	GUI_DispStringHCenterAt("GUI_TM_REV",160,26);

	GUI_SetTextMode(GUI_TM_TRANS);			//͸���ı�
	GUI_DispStringHCenterAt("GUI_TM_TRANS",160,42);
	
	GUI_SetTextMode(GUI_TM_XOR);			//����ı�
    GUI_DispStringHCenterAt("GUI_TM_XOR",160,58);
*/
	GUI_SetTextAlign(GUI_TA_HCENTER | GUI_TA_VCENTER);					//���뷽ʽ
    GUI_DispDecAt(1234,100,100,4);							//д����
	GUI_GetDispPosX();							//�����ı���ǰ����
	GUI_GetDispPosY();
    GUI_Delay(10000);

}
}