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
File        : DIALOG_MessageBox.c
Purpose     : Example demonstrating GUI_MessageBox
----------------------------------------------------------------------
*/

#include "GUI.h"

/*******************************************************************
*
*                 main
*
********************************************************************
*/

void main(void) {
  GUI_Init();
  WM_SetDesktopColor(GUI_RED);     /* Automacally update desktop window */
  /* Create message box and wait until it is closed */
  GUI_MessageBox("This text is shown\nin a message box",
                 "Caption/Title", GUI_MESSAGEBOX_CF_MOVEABLE);
  GUI_Delay(500);                    /* Wait for a short moment ... */
  GUI_MessageBox("New message !",
                 "Caption/Title", GUI_MESSAGEBOX_CF_MOVEABLE);
}
