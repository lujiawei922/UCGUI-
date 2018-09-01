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
File        : MEMDEV_Banding.c
Purpose     : Example demonstrating the use of banding memory devices
----------------------------------------------------------------------
*/

#include "gui.h"

static const GUI_POINT aPoints[] = {
  {-50,  0},
  {-10, 10},
  {  0, 50},
  { 10, 10},
  { 50,  0},
  { 10,-10},
  {  0,-50},
  {-10,-10}
};

#define SIZE_OF_ARRAY(Array) (sizeof(Array) / sizeof(Array[0]))

typedef struct {
  int XPos_Poly, YPos_Poly;
  int XPos_Text, YPos_Text;
  GUI_POINT aPointsDest[8];
} tDrawItContext;

/*******************************************************************
*
*                 Drawing routine
*
********************************************************************
*/

static void DrawIt(void * pData) {
  tDrawItContext * pDrawItContext = (tDrawItContext *)pData;
  GUI_Clear();
  GUI_SetFont(&GUI_Font8x8);
  GUI_SetTextMode(GUI_TM_TRANS);
  /* draw background */
  GUI_SetColor(GUI_GREEN);
  GUI_FillRect(pDrawItContext->XPos_Text, 
               pDrawItContext->YPos_Text - 25,
               pDrawItContext->XPos_Text + 100,
               pDrawItContext->YPos_Text - 5);
  /* draw polygon */
  GUI_SetColor(GUI_BLUE);
  GUI_FillPolygon(pDrawItContext->aPointsDest, SIZE_OF_ARRAY(aPoints), 160, 120);
  /* draw foreground */
  GUI_SetColor(GUI_RED);
  GUI_FillRect(220 - pDrawItContext->XPos_Text, 
               pDrawItContext->YPos_Text + 5,
               220 - pDrawItContext->XPos_Text + 100,
               pDrawItContext->YPos_Text + 25);
}

/*******************************************************************
*
*           Demonstrates the banding memory device
*
********************************************************************
*/

#define USE_BANDING_MEMDEV (1) /* Set to 0 for drawing without banding memory device */

void DemoBandingMemdev(void) {
  int i;
  int XSize = LCD_GET_XSIZE();
  int YSize = LCD_GET_YSIZE();
  tDrawItContext DrawItContext;
  GUI_SetFont(&GUI_Font8x9);
  GUI_SetColor(GUI_WHITE);
  GUI_DispStringHCenterAt("Banding memory device\nwithout flickering", 
                          XSize / 2, 40);
  DrawItContext.XPos_Poly = XSize / 2;
  DrawItContext.YPos_Poly = YSize / 2;
  DrawItContext.YPos_Text = YSize / 2 - 4;
  for (i = 0; i < (XSize - 100); i++) {
    float angle = i * 3.1415926 / 60;
    DrawItContext.XPos_Text = i;
    /* Rotate the polygon */
    GUI_RotatePolygon(DrawItContext.aPointsDest, 
                      aPoints, 
                      SIZE_OF_ARRAY(aPoints), angle);
    #if USE_BANDING_MEMDEV
    {
      GUI_RECT Rect = {0, 70, 320,170};
      /* Use banding memory device for drawing */
      GUI_MEMDEV_Draw(&Rect, &DrawIt, &DrawItContext, 0, 0);
    }
    #else
      /* Simple drawing without using memory devices */
      DrawIt((void *)&DrawItContext);
    #endif
    #ifdef WIN32
      GUI_Delay(20); /* Use a short delay only in the simulation */
    #endif
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
  while(1) {
    DemoBandingMemdev();
  }
}

