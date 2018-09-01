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
			GUI_SetTextAlign(GUI_TA_VCENTER);		//y轴方向对中
			GUI_DispStringHCenterAt(ac,x,y);
			
		}
	}
	//画圆
	/*
	for(i = 10; i<50 ; i+=3)
	{
		//GUI_SetColor(0x0);
		GUI_DrawCircle(120,60,i);
	}
	
	GUI_FillCircle(240,60,50);
	*/
	
	/*椭圆
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
		GUI_RotatePolygon(tem_point,aPointArrow,countof(aPointArrow),i/2.0);//多边形旋转
		GUI_Delay(1000);
		GUI_FillPolygon(tem_point,7,100,100);			//填充一块区域
	}
	*/
	

	
	
	
	/*整列显示一个多边形
	GUI_Clear();
	GUI_SetDrawMode(GUI_DM_XOR);
	GUI_FillPolygon(aPoints,countof(aPoints),140,110);			//填充一块区域
	for(i = 1;i<10;i++)
	{
		GUI_EnlargePolygon(aEnlargedPoints,aPoints,countof(aPoints),i*10);//放大
		GUI_FillPolygon(aEnlargedPoints,countof(aPoints),140,110);			//填充一块区域
	}
	*/

  //int LCDXSize = LCD_GET_XSIZE();
  //int LCDYSize = LCD_GET_YSIZE();

	/*
	GUI_Clear();
	GUI_SetDrawMode(GUI_DRAWMODE_NORMAL);
	GUI_FillCircle(120,64,40);		//画一个填充的圆
	GUI_SetDrawMode(GUI_DRAWMODE_XOR);
	GUI_FillCircle(140,84,40);
	 */	

	/*
	GUI_SetDrawMode(GUI_DRAWMODE_NORMAL);
	GUI_FillCircle(120,64,40);		//画一个填充的圆
	
	//GUI_DrawPixel(2,2);				//绘制一个像素点
	
	GUI_DrawPoint(5,5);				//用当前绘制一个点
	//GUI_ClearRect(120,64,160,104);	//用背景色清除该区域
	//GUI_FillRect(120,64,160,104);		//绘制一个矩形填充区域
	//GUI_InvertRect(120,64,160,104);		//绘制反相区域
	*/
	/*
	//GUI_DrawBitmap(&bmMicriumLogo,45,20);   //进行位图绘画
	
	GUI_DrawBitmapMag(&bmMicriumLogo,45,20,2,2);	//xy像素都放大2倍
	*/
	//GUI_DrawHLine(10,10,100);                   //画一根水平线
	//GUI_DrawLine(0,0,100,100);					//两点之间画一根线线
	
	//GUI_DrawLineRel(100,20);		//在当前视图画一条直线，长宽为100,20
	
	//GUI_DrawPolyLine(point,sizeof(point)/sizeof(GUI_POINT),9,9);	//将几个相连，首尾不相连
	
	//GUI_DrawVLine(4,4,100);			//画一条水平线
	
	//GUI_DrawPolygon(point,sizeof(point)/sizeof(GUI_POINT),9,9);	//将几个相连，首尾相连
	
	GUI_Delay(100000);
  }
}

