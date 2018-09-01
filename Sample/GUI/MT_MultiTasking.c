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
File        : MT_MultiTasking.c
Purpose     : Example demonstrates MultiTasking capabilities of emWin
----------------------------------------------------------------------
*/

#include "GUI.h"
#include "GUI_X.h"
#include "FrameWin.h"
#include <stddef.h>

#if GUI_OS == 0
  #error Multitasking sample requires task awareness (#define GUI_OS 1)
#endif
/*******************************************************************
*
*          Define how to create a task and start multitasking
*
********************************************************************

  If not using embOS you have to change the hardware
  dependent macros to work with your OS

*/

#ifndef WIN32 
  #include "RTOS.h"    /* Definitions for embOS */
  #define CREATE_TASK(pTCB, pName, pFunc, Priority, pStack)  OS_CREATETASK(pTCB, pName, pFunc, Priority, pStack)
  #define START_MT() OS_Start()
  #define Delay(t) OS_Delay(t)
#else
  #include "SIM.h"     /* Definitions for the Win32 simulation */
  #define CREATE_TASK(pTCB, pName, pFunc, Priority, pStack)   SIM_CreateTask(pName, pFunc, Priority)
  #define START_MT()  SIM_Start()
  #define Delay(t)    SIM_Delay(t)
#endif

/*******************************************************************
*
*          Callback routine of child window from task 0
*
********************************************************************
*/

static int XPos;
static const char aText[] = "Moving text...";

static void cbCallbackT0(WM_MESSAGE * pMsg) {
  switch (pMsg->MsgId) {
  case WM_PAINT:
    /* Handle the paint message */
    GUI_SetBkColor(GUI_RED);
    GUI_SetColor(GUI_BLACK);
    GUI_SetFont(&GUI_FontComic24B_ASCII);
    GUI_Clear();
    GUI_DispStringAt(aText, XPos, 0);
    break;
  default:
    WM_DefaultProc(pMsg);
  }
}

/*******************************************************************
*
*          Callback routine of child window from task 1
*
********************************************************************
*/

static void cbCallbackT1(WM_MESSAGE * pMsg) {
  WM_HWIN hWin = (FRAMEWIN_Handle)(pMsg->hWin);
  switch (pMsg->MsgId) {
  case WM_PAINT:
    /* Handle the paint message */
    GUI_SetBkColor(GUI_BLUE);
    GUI_SetColor(GUI_WHITE);
    GUI_SetFont(&GUI_FontComic24B_ASCII);
    GUI_SetTextAlign(GUI_TA_HCENTER | GUI_TA_VCENTER);
    GUI_Clear();
    GUI_DispStringHCenterAt("Moving window...", 
                            WM_GetWindowSizeX(hWin) / 2, 
                            WM_GetWindowSizeY(hWin) / 2);
    break;
  default:
    WM_DefaultProc(pMsg);
  }
}
/*******************************************************************
*
*          Callback routine of background window
*
********************************************************************
*/

static void cbBackgroundWin(WM_MESSAGE* pMsg) {
  switch (pMsg->MsgId) {
  case WM_PAINT:
    /* Handle only the paint message */
    GUI_SetBkColor(GUI_GREEN);
    GUI_Clear();
    GUI_SetFont(&GUI_Font13HB_1);
    GUI_DispStringHCenterAt("µC/GUI - multitasking demo\n", 160, 0);
    GUI_SetFont(&GUI_Font13_1);
    GUI_DispStringHCenterAt("Scrolling text and moving windows without flickering", 
                            160, GUI_GetDispPosY());
  default:
    WM_DefaultProc(pMsg);
  }
}
/*******************************************************************
*
*          Task 0: Moves the text in the client window
*
********************************************************************
*/

static void Task_0(void) {
  /* Create frame window */
  FRAMEWIN_Handle hFrameWin = FRAMEWIN_Create("Task 0",  NULL, WM_CF_SHOW | WM_CF_STAYONTOP,  0, 40, 200, 40);
  /* Create child window */
  WM_HWIN         hChildWin = WM_CreateWindowAsChild(0, 0, 0, 0, hFrameWin, 
                                                     WM_CF_SHOW | WM_CF_MEMDEV,  cbCallbackT0, 0);
  FRAMEWIN_SetActive(hFrameWin, 0);
  /* Make sure the right window is active... */
  WM_SelectWindow(hChildWin);
  /* ...and the right font is selected */
  GUI_SetFont(&GUI_FontComic24B_ASCII);
  while(1) {
    GUI_RECT Rect;
    int XLen = GUI_GetStringDistX(aText);   /* Get the length of the string */
    WM_GetClientRect(&Rect);                /* Get the size of the window */
    /* Show moving text */
    for (XPos = 0; XPos < (Rect.x1 - Rect.x0) - XLen; XPos++) {
      WM_InvalidateWindow(hChildWin);
      Delay(50);
    }
    for (; XPos >= 0; XPos--) {
      WM_InvalidateWindow(hChildWin);
      Delay(100);
    }
  }
}


/*******************************************************************
*
*          Task 1: Moves frame- and client window continously
*/

static void Task_1(void) {
  /* Create frame window */
  FRAMEWIN_Handle hFrameWin = FRAMEWIN_Create("Task 1", NULL, WM_CF_SHOW | WM_CF_STAYONTOP, 
                                              20, 170, 200, 40);
  /* Create child window */
  WM_HWIN         hChildWin = WM_CreateWindowAsChild(0, 0, 0, 0, hFrameWin, WM_CF_SHOW | WM_CF_MEMDEV, cbCallbackT1, 0);
  FRAMEWIN_SetActive(hFrameWin, 0);
  while(1) {
    int i;
    int nx =  80;
    int ny = 160;
    /* Move window continously */
    for (i = 0; i < ny; i++) {
      WM_MoveWindow(hFrameWin, 0, -2);
      Delay(50);
    }
    for (i = 0; i < nx; i++) {
      WM_MoveWindow(hFrameWin, 2, 0);
      Delay(50);
    }
    for (i = 0; i < ny; i++) {
      WM_MoveWindow(hFrameWin, 0, 2);
      Delay(50);
    }
    for (i = 0; i < nx; i++) {
      WM_MoveWindow(hFrameWin, -2, 0);
      Delay(50);
    }
  }
}


/*******************************************************************
*
*          GUI background processing
*
* This task does the background processing.
* The main job is to update invalid windows, but other things such as
* evaluating mouse or touch input may also be done.
*/
void GUI_Task(void) {
  while(1) {
    GUI_Exec();           /* Do the background work ... Update windows etc.) */
    GUI_X_ExecIdle();     /* Nothing left to do for the moment ... Idle processing */
  }
}


/*******************************************************************
*
*                 main
*/

#ifndef WIN32
  /* Stacks */
  static OS_STACKPTR int Stack_0[600];
  static OS_STACKPTR int Stack_1[600];
  static OS_STACKPTR int Stack_2[600];
  static OS_TASK aTCB[3];                   /* Task control blocks */
#endif

void main(void) {
  #ifndef WIN32
    /* Init hardware */
    OS_InitKern();
    OS_InitHW();
  #endif
  /* Init GUI */
  GUI_Init();
  WM_SetCallback(WM_HBKWIN, cbBackgroundWin);    /* Set callback for background window */
  /* Create tasks */
  CREATE_TASK(&aTCB[0], "Task_0", Task_0, 100, Stack_0);
  CREATE_TASK(&aTCB[1], "Task_1", Task_1,  50, Stack_1);
  CREATE_TASK(&aTCB[2], "GUI_TASK", GUI_Task,  1, Stack_2);
  /* Start multitasking */
  START_MT();
}
