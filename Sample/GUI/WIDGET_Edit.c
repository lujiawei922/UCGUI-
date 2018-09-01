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
File        : WIDGET_Edit.c
Purpose     : Example demonstrating the use of a EDIT widget
----------------------------------------------------------------------
*/

#include "gui.H"
#include "edit.h"

/*******************************************************************
*
*          Edit a string until ESC or ENTER is pressed
*
********************************************************************
*/

static int Edit(void) {
  int Key;
  EDIT_Handle hEdit;
  char aBuffer[28];
  GUI_SetFont(&GUI_Font8x16);
  GUI_DispStringHCenterAt("Use keyboard to modify string...", 160, 0);
  /* Create edit widget */
  hEdit = EDIT_Create( 50, 20, 219, 25, ' ', sizeof(aBuffer), 0 );
  /* Modify edit widget */
  EDIT_SetText(hEdit, "Press <ENTER> when done...");
  EDIT_SetFont(hEdit, &GUI_Font8x16);
  EDIT_SetTextColor(hEdit, 0, GUI_RED);
  /* Set keyboard focus to edit widget */
  WM_SetFocus(hEdit);
  /* Handle keyboard until ESC or ENTER is pressed */
  do {
    Key = GUI_WaitKey();
  } while ((Key != GUI_ID_ESCAPE) && (Key != GUI_ID_ENTER) && (Key != 0));
  /* Fetch result from edit widget */
  if (Key == GUI_ID_ENTER)
    EDIT_GetText(hEdit, aBuffer, sizeof(aBuffer));
  else
    aBuffer[0] = 0;
  EDIT_Delete(hEdit);
  GUI_DispStringHCenterAt(aBuffer, 160, 50);
  return Key;
}

/*******************************************************************
*
*                 main
*
********************************************************************
*/

void main(void) {
  GUI_Init();
  Edit();
  while(1)
    GUI_Delay(100);
}
