/*
*********************************************************************************************************
*                                                uC/GUI
*                        Universal graphic software for embedded applications
*
*                       (c) Copyright 2002, Micrium Inc., Weston, FL
*                       (c) Copyright 2002, SEGGER Microcontroller Systeme GmbH
*
*              µC/GUI is protected by international copyright laws. Knowledge of the
*              source code may not be used to write a similar product. This file may
*              only be used in accordance with a license and should not be redistributed
*              in any way. We appreciate your understanding and fairness.
*
----------------------------------------------------------------------
File        : 2DGL_DrawScale.c
Purpose     : Drawing a scale using GUI-functions
----------------------------------------------------------------------
*/

#include "gui.h"
#include <math.h>
#include <stddef.h>

/*******************************************************************
*
*                 Draw scale using GUI-functions
*
********************************************************************
*/

static void DrawScale(void) {
  int XSize = LCD_GetXSize();
  int YSize = LCD_GetYSize();
  int XMid = XSize / 2;
  {
    int a;
    int c = 0;
    int r1 = 110;
    int r2 = 140;
    int rt = 100;
    int y = 180;
    int step = 15;
    int r = (r1 + r2) / 2;
    GUI_Clear();
    GUI_SetFont(&GUI_Font8x16);
    GUI_DispStringHCenterAt("Drawing a scale using GUI-functions", XMid, 0);
    GUI_SetPenSize(r2 - r1);
    GUI_SetColor(0x0000AA);
    GUI_AA_DrawArc(XMid, y, r, r,  45, 60);
    GUI_SetColor(0x00AA00);
    GUI_AA_DrawArc(XMid, y, r, r,  60, 90);
    GUI_SetPenSize(2);
    GUI_SetColor(GUI_WHITE);
    GUI_AA_DrawArc(XMid, y, r1, r1, 45, 135);
    GUI_AA_DrawArc(XMid, y, r2, r2, 45, 135);
    for (a=45; a<=135; a+=step) {
      float co = cos(a*3.1415926/180);
      float si = sin(a*3.1415926/180);
      int x1 = XMid - r1 * co;
      int y1 = y    - r1 * si;
      int x2 = XMid - (r2 - 1) * co;
      int y2 = y    - (r2 - 1) * si;
      int xt = XMid - rt * co;
      int yt = y    - rt * si;
      GUI_SetColor(GUI_WHITE);
      GUI_SetPenSize(2);
      GUI_AA_DrawLine(x1,y1,x2,y2);
      GUI_SetColor(GUI_GREEN);
      GUI_SetFont(&GUI_Font8x8);
      GUI_DispCharAt('0' + c++, xt - 4, yt - 4);
    }
  }
}

/*******************************************************************
*
*                 main
*
********************************************************************
*/

void main(void) {
  GUI_Init();
  DrawScale();
  while(1); 
}

