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
File        : WIDGET_FrameWin.c
Purpose     : Example demonstrating the use of a FRAMEWIN widget
----------------------------------------------------------------------
*/

#include "gui.H"
#include "framewin.h"
#include <stddef.h>

/*******************************************************************
*
*             Callback routine of client window
*
********************************************************************
*/

static void CallbackChild(WM_MESSAGE * pMsg) {
  WM_HWIN hWin = (FRAMEWIN_Handle)(pMsg->hWin);
  switch (pMsg->MsgId) {
  case WM_PAINT:
    /* Handle the paint message */
    GUI_SetBkColor(GUI_BLUE);
    GUI_SetColor(GUI_WHITE);
    GUI_SetFont(&GUI_FontComic24B_ASCII);
    GUI_SetTextAlign(GUI_TA_HCENTER | GUI_TA_VCENTER);
    GUI_Clear();
    GUI_DispStringHCenterAt("Child window", 
                            WM_GetWindowSizeX(hWin) / 2, 
                            WM_GetWindowSizeY(hWin) / 2);
    break;
  }
}

/*******************************************************************
*
*             Create frame- and childwindow
*
********************************************************************
*/

static void DemoFramewin(void) {
  /* Create frame window */
  FRAMEWIN_Handle hFrame = FRAMEWIN_Create("Frame window", 
                                           NULL, WM_CF_SHOW, 
                                           10, 10, 150, 60);
  FRAMEWIN_SetFont(hFrame, &GUI_Font16B_ASCII);
  FRAMEWIN_SetTextColor(hFrame, GUI_RED);
  FRAMEWIN_SetBarColor(hFrame, 0, GUI_GREEN);
  FRAMEWIN_SetTextAlign(hFrame, GUI_TA_HCENTER);
  /* Create client window */
  WM_CreateWindowAsChild(0, 0, 0, 0, hFrame, WM_CF_SHOW, CallbackChild, 0);
}

/*******************************************************************
*
*                 main
*
********************************************************************
*/

void main(void) {
  GUI_Init();
  DemoFramewin();
  while(1)
    GUI_Delay(100);
}

