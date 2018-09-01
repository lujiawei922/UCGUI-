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
File        : WIDGET_SimpleButton.c
Purpose     : Example demonstrating the use of a BUTTON widget
----------------------------------------------------------------------
*/

#include "gui.h"
#include "button.h"

/*******************************************************************
*
*            Demonstrates the use of a BUTTON widget
*
********************************************************************
*/

static void DemoButton(void) {
  BUTTON_Handle hButton;
  int Key = 0;
  GUI_Init();
  GUI_SetFont(&GUI_Font8x16);
  GUI_DispStringHCenterAt("Click on button...", 160,0);
  /* Create the button */
  hButton = BUTTON_Create(110, 20, 100, 40, GUI_ID_OK, WM_CF_SHOW);
  /* Set the button text */
  BUTTON_SetText(hButton, "Click me...");
  Key = GUI_WaitKey();
  /* Delete button object */
  BUTTON_Delete(hButton);
}

/*******************************************************************
*
*                 main
*
********************************************************************
*/

void main(void) {
  GUI_Init();
  DemoButton();
}
