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
#include <math.h>
#include <stdio.h>

#define countof(Array) (sizeof(Array) / sizeof(Array[0]))
  /*******************************************************************
*/

const GUI_POINT aPoints[] = {
	{0,20},
	{40,20},
	{20,0}
};

GUI_POINT aEnlargedPoints[countof(aPoints)];

void main(void) {

  while(1)
  {
	int Cnt = 0;
	int i = 0;
	int x0 = 160;
	int y0 = 180;
	char ac[4];
	static const GUI_POINT aPointArrow[] =
	{
		{0,-5},
		{-40,-35},
		{-10,-25},
		{-10,-85},
		{10,-85},
		{10,-25},
		{40,-35},
	};
	GUI_POINT tem_point[countof(aPointArrow)];
	
	GUI_Init();
	
	GUI_SetBkColor(GUI_WHITE);
	GUI_Clear();
	GUI_SetPenSize(5);
	GUI_SetFont(&GUI_FontComic18B_ASCII);
	GUI_SetColor(GUI_BLACK);
	GUI_DrawArc(x0,y0,150,150,-30,210);
	for(i = 0 ;i<=23; i++)
	{
		float a= (-30+i*10)*3.1415926/180;
		int x = -141*cos(a) + x0;
		int y = -141*sin(a) + y0;
		if(i%2 == 0)
			GUI_SetPenSize(5);
		else 
			GUI_SetPenSize(4);
		GUI_DrawPoint(x,y);
		if(i%2 == 0)
		{
			x = -123*cos(a) + x0;
			y = -125*sin(a) + y0;
			sprintf(ac,"%d",10*i);
			GUI_SetTextAlign(GUI_TA_VCENTER);		//y�᷽�����
			GUI_DispStringHCenterAt(ac,x,y);
			
		}
	}
	//��Բ
	/*
	for(i = 10; i<50 ; i+=3)
	{
		//GUI_SetColor(0x0);
		GUI_DrawCircle(120,60,i);
	}
	
	GUI_FillCircle(240,60,50);
	*/
	
	/*��Բ
	GUI_DrawEllipse(100,180,50,70);
	GUI_FillEllipse(150,180,50,70);
	*/
	
	
	/*
	GUI_SetBkColor(GUI_WHITE);
	GUI_Clear();
	GUI_SetFont(&GUI_Font8x16);
	GUI_SetColor(0x0);
	GUI_DispStringAt("Polygons of arbitrary shape",0,0);
	GUI_DispStringAt("in any color",120,20);
	GUI_SetColor(GUI_BLUE);
	
	GUI_FillPolygon(&aPointArrow[0],7,100,100);
	
	for(i = 1;i<100;i++)
	{
		GUI_RotatePolygon(tem_point,aPointArrow,countof(aPointArrow),i/2.0);//�������ת
		GUI_Delay(1000);
		GUI_FillPolygon(tem_point,7,100,100);			//���һ������
	}
	*/
	

	
	
	
	/*������ʾһ�������
	GUI_Clear();
	GUI_SetDrawMode(GUI_DM_XOR);
	GUI_FillPolygon(aPoints,countof(aPoints),140,110);			//���һ������
	for(i = 1;i<10;i++)
	{
		GUI_EnlargePolygon(aEnlargedPoints,aPoints,countof(aPoints),i*10);//�Ŵ�
		GUI_FillPolygon(aEnlargedPoints,countof(aPoints),140,110);			//���һ������
	}
	*/

  //int LCDXSize = LCD_GET_XSIZE();
  //int LCDYSize = LCD_GET_YSIZE();

	/*
	GUI_Clear();
	GUI_SetDrawMode(GUI_DRAWMODE_NORMAL);
	GUI_FillCircle(120,64,40);		//��һ������Բ
	GUI_SetDrawMode(GUI_DRAWMODE_XOR);
	GUI_FillCircle(140,84,40);
	 */	

	/*
	GUI_SetDrawMode(GUI_DRAWMODE_NORMAL);
	GUI_FillCircle(120,64,40);		//��һ������Բ
	
	//GUI_DrawPixel(2,2);				//����һ�����ص�
	
	GUI_DrawPoint(5,5);				//�õ�ǰ����һ����
	//GUI_ClearRect(120,64,160,104);	//�ñ���ɫ���������
	//GUI_FillRect(120,64,160,104);		//����һ�������������
	//GUI_InvertRect(120,64,160,104);		//���Ʒ�������
	*/
	/*
	//GUI_DrawBitmap(&bmMicriumLogo,45,20);   //����λͼ�滭
	
	GUI_DrawBitmapMag(&bmMicriumLogo,45,20,2,2);	//xy���ض��Ŵ�2��
	*/
	//GUI_DrawHLine(10,10,100);                   //��һ��ˮƽ��
	//GUI_DrawLine(0,0,100,100);					//����֮�仭һ������
	
	//GUI_DrawLineRel(100,20);		//�ڵ�ǰ��ͼ��һ��ֱ�ߣ�����Ϊ100,20
	
	//GUI_DrawPolyLine(point,sizeof(point)/sizeof(GUI_POINT),9,9);	//��������������β������
	
	//GUI_DrawVLine(4,4,100);			//��һ��ˮƽ��
	
	//GUI_DrawPolygon(point,sizeof(point)/sizeof(GUI_POINT),9,9);	//��������������β����
	
	GUI_Delay(100000);
  }
}

