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
File        : DIALOG_SliderColor.c
Purpose     : Example demonstrating the use of a DIALOG widget
----------------------------------------------------------------------
*/

#include <stddef.h>
#include "GUI.H"
#include "DIALOG.h"

/*********************************************************************
*
*       static data
*
**********************************************************************
*/

static U8 _aColorSep[3] = {0, 127, 255};  /* Red, green and blue components */

/*********************************************************************
*
*       Dialog resource
*
* This table conatins the info required to create the dialog.
* It has been created manually, but could also be created by a GUI-builder.
*/
static const GUI_WIDGET_CREATE_INFO _aDialogCreate[] = {
  { FRAMEWIN_CreateIndirect, "Adjust color", 0,         10,  10, 300, 160 , FRAMEWIN_CF_MOVEABLE},
  { TEXT_CreateIndirect,     "Red:" ,  0,                5,  20,  35,  20, TEXT_CF_LEFT },
  { TEXT_CreateIndirect,     "Green:", 0,                5,  50,  35,  20, TEXT_CF_LEFT },
  { TEXT_CreateIndirect,     "Blue:",  0,                5,  80,  35,  20, TEXT_CF_LEFT },
  { TEXT_CreateIndirect,     "Preview",0,              205,   4,  81,  15, TEXT_CF_HCENTER },
  { SLIDER_CreateIndirect,   NULL,     GUI_ID_SLIDER0,  40,  20, 100,  20 },
  { SLIDER_CreateIndirect,   NULL,     GUI_ID_SLIDER1,  40,  50, 100,  20 },
  { SLIDER_CreateIndirect,   NULL,     GUI_ID_SLIDER2,  40,  80, 100,  20 },
  { EDIT_CreateIndirect,     NULL,     GUI_ID_EDIT0,   145,  20,  30,  20, 0, 3 },
  { EDIT_CreateIndirect,     NULL,     GUI_ID_EDIT1,   145,  50,  30,  20, 0, 3 },
  { EDIT_CreateIndirect,     NULL,     GUI_ID_EDIT2,   145,  80,  30,  20, 0, 3 },
  { BUTTON_CreateIndirect,   "OK",     GUI_ID_OK,       10, 110,  60,  20 },
  { BUTTON_CreateIndirect,   "Cancel", GUI_ID_CANCEL,  230, 110,  60,  20 },
};

/*********************************************************************
*
*       static code
*
**********************************************************************
*/

/*********************************************************************
*
*       _OnPaint

  This routine draws the color rectangles.
  The widgets are drawn automatically.
*/
static void _OnPaint(WM_HWIN hWin) {
  /* Draw RGB values */
  GUI_SetColor(_aColorSep[0]);
  GUI_FillRect(180, 20, 199, 39);
  GUI_SetColor(_aColorSep[1] << 8);
  GUI_FillRect(180, 50, 199, 69);
  GUI_SetColor(_aColorSep[2] << 16);
  GUI_FillRect(180, 80, 199, 99);
  /* Draw resulting color */
  GUI_SetColor(_aColorSep[0] | (_aColorSep[1] << 8) | (_aColorSep[2] << 16));
  GUI_FillRect(205, 20, 285, 99);
}

/*********************************************************************
*
*       _OnValueChanged
*/
static void _OnValueChanged(WM_HWIN hDlg, int Id) {
  unsigned Index, v;
  WM_HWIN hSlider, hEdit;
  if ((Id >= GUI_ID_SLIDER0) && (Id <= GUI_ID_SLIDER2)) {
    Index = Id - GUI_ID_SLIDER0;
    /* SLIDER-widget has changed, update EDIT-widget */
    hSlider = WM_GetDialogItem(hDlg, GUI_ID_SLIDER0 + Index);
    hEdit   = WM_GetDialogItem(hDlg, GUI_ID_EDIT0 + Index);
    v = SLIDER_GetValue(hSlider);
    EDIT_SetValue(hEdit, v);
  } else if ((Id >= GUI_ID_EDIT0) && (Id <= GUI_ID_EDIT2)) {
    Index = Id - GUI_ID_EDIT0;
    /* If EDIT-widget has changed, update SLIDER-widget */
    hSlider = WM_GetDialogItem(hDlg, GUI_ID_SLIDER0 + Index);
    hEdit   = WM_GetDialogItem(hDlg, GUI_ID_EDIT0 + Index);
    v = EDIT_GetValue(hEdit);
    SLIDER_SetValue(hSlider, v);
  }
  _aColorSep[Index] = v;
  /* At last invalidate dialog client window */
  WM_InvalidateWindow(WM_GetClientWindow(hDlg));
}

/*********************************************************************
*
*       Dialog callback routine
*/
static void _cbCallback(WM_MESSAGE * pMsg) {
  int i;
  int NCode, Id;
  WM_HWIN hDlg, hItem;
  hDlg = pMsg->hWin;
  switch (pMsg->MsgId) {
    case WM_PAINT:
      _OnPaint(hDlg);
      return;
    case WM_INIT_DIALOG:
      for (i = 0; i < 3; i++) {
        hItem = WM_GetDialogItem(hDlg, GUI_ID_SLIDER0 + i);
        SLIDER_SetRange(hItem, 0, 255);
        SLIDER_SetValue(hItem, _aColorSep[i]);
        /* Init EDIT-widgets */
        hItem = WM_GetDialogItem(hDlg, GUI_ID_EDIT0 + i);
        EDIT_SetDecMode(hItem, _aColorSep[i],   0, 255, 0, 0);
      }
      break;
    case WM_KEY:
      switch (((WM_KEY_INFO*)(pMsg->Data.p))->Key) {
        case GUI_ID_ESCAPE:
          GUI_EndDialog(hDlg, 1);
          break;
        case GUI_ID_ENTER:
          GUI_EndDialog(hDlg, 0);
          break;
      }
      break;
    case WM_NOTIFY_PARENT:
      Id    = WM_GetId(pMsg->hWinSrc);      /* Id of widget */
      NCode = pMsg->Data.v;                 /* Notification code */
      switch (NCode) {
        case WM_NOTIFICATION_RELEASED:      /* React only if released */
          if (Id == GUI_ID_OK) {            /* OK Button */
            GUI_EndDialog(hDlg, 0);
          }
          if (Id == GUI_ID_CANCEL) {        /* Cancel Button */
            GUI_EndDialog(hDlg, 1);
          }
          break;
        case WM_NOTIFICATION_VALUE_CHANGED: /* Value has changed */
          _OnValueChanged(hDlg, Id);
          break;
      }
      break;
    default:
      WM_DefaultProc(pMsg);
  }
}


/*********************************************************************
*
*       main
*
**********************************************************************
*/

void main(void) {
  GUI_Init();
  WM_SetDesktopColor(GUI_RED);      /* Automacally update desktop window */
  WM_SetCreateFlags(WM_CF_MEMDEV);  /* Use memory devices on all windows to avoid flicker */
  GUI_ExecDialogBox(_aDialogCreate, GUI_COUNTOF(_aDialogCreate), &_cbCallback, 0, 0, 0);
}
