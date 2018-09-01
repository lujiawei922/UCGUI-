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
File        : WIDGET_SimpleListBox.c
Purpose     : Example demonstrating the LISTBOX widget
----------------------------------------------------------------------
*/

#include "gui.H"
#include "listbox.h"
#include <stddef.h>

const GUI_ConstString ListBox[] = {
  "English", "Deutsch", "Français", "Japanese", "Italiano", NULL
};

#define countof(Array) (sizeof(Array) / sizeof(Array[0]))

/*******************************************************************
*
*              Simple use of the LISTBOX widget
*
********************************************************************
*/

void DemoListBox(void) {
  int i;
  int Entries = countof(ListBox) - 1;
  LISTBOX_Handle hListBox;
  int ySize = GUI_GetFontSizeYOf(&GUI_Font13B_1) * Entries;
  /* Create the listbox */
  hListBox = LISTBOX_Create(ListBox, 10, 10, 60, ySize, WM_CF_SHOW);
  /* Change current selection of the listbox */
  for (i = 0; i < Entries-1; i++) {
    GUI_Delay(500);
    LISTBOX_IncSel(hListBox);
    WM_ExecIdle();
	}
  for (i = 0; i < Entries-1; i++) {
    GUI_Delay(500);
    LISTBOX_DecSel(hListBox);
    WM_ExecIdle();
	}
  /* Delete listbox widget */
  LISTBOX_Delete(hListBox);
  GUI_Clear();
}

/*******************************************************************
*
*             Demonstrates LISTBOX widget
*
********************************************************************
*/

static void DemoListbox(void) {
  GUI_SetBkColor(GUI_BLUE);
  GUI_Clear();
  while(1) {
    DemoListBox();
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
  DemoListbox();
}
