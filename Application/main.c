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
<<<<<<< HEAD
=======
#include "GUITYPE.h"
>>>>>>> 6e13ebed3951febe16d72b2b8ab347d26e2a619b

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
  }
  GUI_Delay(1000);
  GUI_Clear();
  if (LCD_GET_YSIZE()>(100+bmMicriumLogo_1bpp.YSize)) {
    pBitmap=&bmMicriumLogo;
  } else {
    GUI_SetColor(GUI_BLUE);
    pBitmap=&bmMicriumLogo_1bpp;
  }
  GUI_DrawBitmap(pBitmap,(LCDXSize-pBitmap->XSize)/2,10);
  YPos=20+pBitmap->YSize;
  GUI_SetFont(&GUI_FontComic24B_1);
  GUI_DispStringHCenterAt("www.micrium.com",LCDXSize/2,YPos);
  GUI_Delay(1000);
  GUI_SetColor(GUI_RED);
  GUI_DispStringHCenterAt("� 2002\n", LCDXSize/2,YPos+30);
  GUI_SetFont(&GUI_Font10S_1);
  GUI_DispStringHCenterAt("Micri�m Inc.",LCDXSize/2,YPos+60);;
  GUI_Delay(1000);
}
}
=======
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
>>>>>>> 6e13ebed3951febe16d72b2b8ab347d26e2a619b
