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
File        : WIDGET_ListBox.c
Purpose     : Example demonstrating the LISTBOX widget
----------------------------------------------------------------------
*/

#include "gui.H"
#include "framewin.h"
#include "listbox.h"
#include <stddef.h>

const GUI_ConstString ListBox[] = {
  "English", "Deutsch", "Français", "Japanese", "Italiano", NULL
};

#define countof(Array) (sizeof(Array) / sizeof(Array[0]))

/*******************************************************************
*
*               Uses only the LISTBOX widget
*
********************************************************************
*/

void DemoListBox(void) {
  int i;
  int Entries = countof(ListBox) - 1;
  LISTBOX_Handle hListBox;
  int ySize = GUI_GetFontSizeYOf(&GUI_Font13B_1) * Entries;
  /* Create the listbox */
  hListBox = LISTBOX_Create(ListBox, 10, 10, 120, ySize, WM_CF_SHOW);
  /* Modify listbox attributes */
  LISTBOX_SetFont(hListBox, &GUI_Font13B_1);
  LISTBOX_SetBackColor(hListBox, 0, GUI_BLUE);
  LISTBOX_SetBackColor(hListBox, 1, GUI_LIGHTBLUE);
  LISTBOX_SetTextColor(hListBox, 0, GUI_WHITE);
  LISTBOX_SetTextColor(hListBox, 1, GUI_BLACK);
  /* Change current selection of the listbox */
  for (i = 0; i < Entries - 1; i++) {
    GUI_Delay(500);
    LISTBOX_IncSel(hListBox);
	}
  for (i = 0; i < Entries - 1; i++) {
    GUI_Delay(500);
    LISTBOX_DecSel(hListBox);
	}
  GUI_Delay(500);
  /* Delete listbox widget */
  LISTBOX_Delete(hListBox);
  GUI_Clear();
}

/*******************************************************************
*
*      Uses LISTBOX widget as child of a FRAMEWIN widget
*
********************************************************************
*/

void DemoListBoxAsChild(void) {
  int i;
  int Entries = countof(ListBox) - 1;
  FRAMEWIN_Handle hFrame;
  LISTBOX_Handle hListBox;
  int ySize = GUI_GetFontSizeYOf(&GUI_Font13B_1) * Entries
            + GUI_GetFontSizeYOf(&GUI_Font16B_ASCII)
            + 7;
  /* Create the frame window */
  hFrame = FRAMEWIN_Create("List box", NULL, WM_CF_SHOW, 10, 10, 120, ySize);
  /* Modify frame window attributes */
  FRAMEWIN_SetFont(hFrame, &GUI_Font16B_ASCII);
  FRAMEWIN_SetTextColor(hFrame, GUI_RED);
  FRAMEWIN_SetBarColor(hFrame, 0, GUI_GREEN);
  FRAMEWIN_SetTextAlign(hFrame, GUI_TA_HCENTER);
  /* Create the listbox */
  hListBox = LISTBOX_CreateAsChild(ListBox, hFrame, 0, 0, 0, 0, WM_CF_SHOW);
  /* Modify listbox attributes */
  LISTBOX_SetBackColor(hListBox, 0, GUI_BLUE);
  LISTBOX_SetBackColor(hListBox, 1, GUI_LIGHTBLUE);
  LISTBOX_SetTextColor(hListBox, 0, GUI_WHITE);
  LISTBOX_SetTextColor(hListBox, 1, GUI_BLACK);
  LISTBOX_SetFont(hListBox, &GUI_Font13B_1);
  /* Change current selection of the listbox */
  for (i = 0; i < Entries - 1; i++) {
    GUI_Delay(500);
    LISTBOX_IncSel(hListBox);
	}
  for (i = 0; i < Entries - 1; i++) {
    GUI_Delay(500);
    LISTBOX_DecSel(hListBox);
	}
  GUI_Delay(500);
  /* Delete listbox widget */
  LISTBOX_Delete(hListBox);
  /* Delete framewin widget */
  FRAMEWIN_Delete(hFrame);
  GUI_Clear();
}

/*******************************************************************
*
*             Demonstrates LISTBOX widget
*
********************************************************************
*/

static void DemoListbox(void) {
  GUI_SetBkColor(GUI_GRAY);
  GUI_Clear();
  while(1) {
    DemoListBox();
    DemoListBoxAsChild();
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
