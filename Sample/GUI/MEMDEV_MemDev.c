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
File        : MEMDEV_MemDev.c
Purpose     : Simple demo shows the use of memory devices
----------------------------------------------------------------------
*/

#include "GUI.H"

static GUI_RECT Rect = {0, 75, 100, 100};

/*******************************************************************
*
*            Drawing routine
*
********************************************************************
*/

static void Draw(int Delay) {
  GUI_SetPenSize(5);
  GUI_SetColor(GUI_RED);
  GUI_DrawLine(Rect.x0 + 3, Rect.y0 + 3, Rect.x1 - 3, Rect.y1 - 3);
  GUI_Delay(Delay);
  GUI_SetColor(GUI_GREEN);
  GUI_DrawLine(Rect.x0 + 3, Rect.y1 - 3, Rect.x1 - 3, Rect.y0 + 3);
  GUI_Delay(Delay);
  GUI_SetColor(GUI_WHITE);
  GUI_SetFont(&GUI_FontComic24B_ASCII);
  GUI_SetTextMode(GUI_TM_TRANS);
  GUI_DispStringInRect("Closed", &Rect, GUI_TA_HCENTER | GUI_TA_VCENTER);
  GUI_Delay(Delay);
}

/*******************************************************************
*
*            Shows the use of memory devices
*
********************************************************************
*/

static void ShowUsageOfMemDev(void) {
  GUI_Clear();
  GUI_SetFont(&GUI_Font8x16);
  GUI_SetColor(GUI_WHITE);
  GUI_DispStringHCenterAt("Shows the advantage of using a\nmemorydevice", 160,0);
  GUI_SetFont(&GUI_Font8_1);
  GUI_DispStringHCenterAt("Draws the picture\nwithout a\nmemory device", 50, 32);
  GUI_DispStringHCenterAt("Draws the picture\nusing a\nmemory device", 270, 32);
  GUI_Delay(500);
  {
    /* Uses a memory device for the drawing operations */
    int i;
    GUI_MEMDEV_Handle hMem = GUI_MEMDEV_Create(Rect.x0, Rect.y0, Rect.x1, Rect.y1);
    GUI_MEMDEV_Select(hMem); /* Routes the drawing operations to the memory device */
    Draw(0);
    GUI_MEMDEV_Select(0);    /* Routes the drawing operations to the LCD */
    for (i = 0; i < 3; i++) {
      if (i) {
        GUI_Delay(250);
        GUI_ClearRect(LCD_GetXSize() - Rect.x1, Rect.y0, LCD_GetXSize(), Rect.y1);
        GUI_Delay(250);
      }
      GUI_MEMDEV_CopyToLCDAt(hMem, LCD_GetXSize() - Rect.x1, Rect.y0);
    }
    GUI_MEMDEV_Delete(hMem); /* Destroy memory device */
    GUI_Delay(500);
  }
  {
    /* Uses no memory device */
    Draw(500);
    GUI_Delay(500);
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
  while(1) {
    ShowUsageOfMemDev();
  }
}
