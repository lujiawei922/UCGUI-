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


/*********************************************************************
*
*       Dialog resource
*
* This table conatins the info required to create the dialog.
* It has been created manually, but could also be created by a GUI-builder.
*/
static const GUI_WIDGET_CREATE_INFO _aDialogCreate[] = {
  { FRAMEWIN_CreateIndirect, "Radio button sample", 0,         10,  10, 260, 100, FRAMEWIN_CF_MOVEABLE},
  { RADIO_CreateIndirect,     NULL,     GUI_ID_RADIO0,   5, 10,0,0,0, 3  },
  { TEXT_CreateIndirect,     "Suspend" ,  0,            25,  10,  70,  20, TEXT_CF_LEFT },
  { TEXT_CreateIndirect,     "Shut down", 0,            25,  30,  70,  20, TEXT_CF_LEFT },
  { TEXT_CreateIndirect,     "Restart after",  0,       25,  50,  70,  20, TEXT_CF_LEFT },
  { TEXT_CreateIndirect,     "seconds",  0,            130,  50,  70,  20, TEXT_CF_LEFT },
  { EDIT_CreateIndirect,     "200",     GUI_ID_EDIT0,   95,  47,  30,  19, 0, 3},
  { BUTTON_CreateIndirect,   "OK",      GUI_ID_OK,     180,  10,  60,  20 },
  { BUTTON_CreateIndirect,   "Cancel",  GUI_ID_CANCEL, 180,  40,  60,  20 }
};

/*********************************************************************
*
*       static code
*
**********************************************************************
*/

/*********************************************************************
*
*       Dialog callback routine
*/
static void _cbCallback(WM_MESSAGE * pMsg) {
  int Sel;
  int NCode, Id;
  WM_HWIN hDlg, hItem;
  hDlg = pMsg->hWin;
  switch (pMsg->MsgId) {
    case WM_INIT_DIALOG:
      hItem = WM_GetDialogItem(hDlg, GUI_ID_EDIT0);
      EDIT_SetDecMode(hItem, 30,   0, 999, 0, 0);    /* Select decimal mode */
      WM_DisableWindow(hItem);
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
        case WM_NOTIFICATION_VALUE_CHANGED:
          hItem = WM_GetDialogItem(hDlg, GUI_ID_RADIO0);
          Sel   = RADIO_GetValue(hItem);
          hItem = WM_GetDialogItem(hDlg, GUI_ID_EDIT0);
          WM_SetEnableState(hItem, Sel == 2);      
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
