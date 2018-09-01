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
File        : TOUCH_DemoTouch.c
Purpose     : Example demonstrates the use of the touch screen module
----------------------------------------------------------------------
*/

#include "gui.h"

/*******************************************************************
*
*        Draw rectangle and wait until it has been touched
*
********************************************************************
*/

static void DemoTouch(void) {
  GUI_TOUCH_tState State;
  GUI_SetBkColor(GUI_WHITE);
  GUI_Clear();
  GUI_SetColor(GUI_GREEN);
  GUI_FillRect(50, 50, 90, 90);
  GUI_SetColor(GUI_BLACK);
  GUI_DispString("Please touch the green rectangle to continue...\n");
  GUI_SetPenSize(5);
  while(1) {
    /* Get state of touch screen */
    GUI_TOUCH_GetState(&State);
    if (State.Pressed) {
      if ((State.x >= 50) && (State.y >= 50) && (State.x <= 90) && (State.y <= 90)) {
        /* Break if position inside */
        break;
      } else {
        /* Display position */
        GUI_SetColor(GUI_RED);
        GUI_DispStringAt("Position ", 0, GUI_GetDispPosY());
        GUI_DispDec(State.x, 3);
        GUI_DispString("/");
        GUI_DispDec(State.y, 3);
        GUI_DispString(" is not inside the rectangle");
        GUI_SetColor(GUI_BLUE);
        GUI_DrawPoint(State.x, State.y);
      }
    }
    GUI_Delay(50);
  }
  GUI_SetColor(GUI_BLUE);
  GUI_DispString("\nOK");
}

/*******************************************************************
*
*                 main
*
********************************************************************
*/

void main(void) {
  GUI_Init();
  DemoTouch();
  while(1)
    GUI_Delay(100);
}
