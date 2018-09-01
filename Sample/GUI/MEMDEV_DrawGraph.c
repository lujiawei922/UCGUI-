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
File        : MEMDEV_DrawGraph.c
Purpose     : Example for drawing graphs
----------------------------------------------------------------------
*/

#include "gui.h"
#include "LCD_ConfDefaults.h"
#include <math.h>
#include <stdlib.h>

/*******************************************************************
*
*      Structure containing information for drawing routine
*
*******************************************************************
*/

typedef struct {
  I16 *aY;
} PARAM;

/*******************************************************************
*
*                    Defines
*
********************************************************************
*/

#define YSIZE   (LCD_YSIZE - 100)
#define DEG2RAD (3.1415926f / 180)

#if LCD_BITSPERPIXEL == 1
  #define COLOR_GRAPH0 GUI_WHITE
  #define COLOR_GRAPH1 GUI_WHITE
#else
  #define COLOR_GRAPH0 GUI_GREEN
  #define COLOR_GRAPH1 GUI_YELLOW
#endif

/*******************************************************************
*
*                    Draws the graph area
*
********************************************************************
*/

static void Draw(void * p) {
  int i;
  PARAM * pParam = (PARAM *)p;
  GUI_SetBkColor(GUI_BLACK);
  GUI_SetColor(GUI_DARKGRAY);
  GUI_ClearRect(19, (LCD_YSIZE - 20) - YSIZE, (LCD_XSIZE - 2), (LCD_YSIZE - 21));
  for (i = 0; i < (YSIZE / 2); i += 20) {
    GUI_DrawHLine((LCD_YSIZE - 20) - (YSIZE / 2) + i, 19, (LCD_XSIZE - 2));
    if (i) {
      GUI_DrawHLine((LCD_YSIZE - 20) - (YSIZE / 2) - i, 19, (LCD_XSIZE - 2));
    }
  }
  for (i = 40; i < (LCD_XSIZE - 20); i += 40) {
    GUI_DrawVLine(18 + i, (LCD_YSIZE - 20) - YSIZE, (LCD_YSIZE - 21));
  }
  GUI_SetColor(COLOR_GRAPH0);
  GUI_DrawGraph(pParam->aY, (LCD_XSIZE - 20), 19, (LCD_YSIZE - 20) - YSIZE);
}

static void Draw2(void * p) {
  PARAM * pParam = (PARAM *)p;
  Draw(p);
  GUI_SetColor(COLOR_GRAPH1);
  GUI_DrawGraph(pParam->aY+15, (LCD_XSIZE - 20), 19, (LCD_YSIZE - 20) - YSIZE);
}
/*******************************************************************
*
*                    Labels the x & y-axis
*
********************************************************************
*/

static void Label(void) {
  int x, y;
  GUI_SetBkColor(GUI_RED);
  GUI_Clear();
  GUI_SetPenSize(1);
  GUI_ClearRect(0, (LCD_YSIZE - 21) - YSIZE, (LCD_XSIZE - 1), (LCD_YSIZE - 1));
  GUI_DrawRect(18, (LCD_YSIZE - 21) - YSIZE, (LCD_XSIZE - 1), (LCD_YSIZE - 20));
  GUI_SetFont(&GUI_Font6x8);
  for (x = 0; x < (LCD_XSIZE - 20); x += 40) {
    int xPos = x + 18;
    GUI_DrawVLine(xPos, (LCD_YSIZE - 20), (LCD_YSIZE - 14));
    GUI_DispDecAt(x / 40, xPos - 2, (LCD_YSIZE - 9), 1);
  }
  for (y = 0; y < YSIZE / 2; y += 20) {
    int yPos = (LCD_YSIZE - 20) - YSIZE / 2 + y;
    GUI_DrawHLine(yPos, 13, 18);
    if (y) {
      GUI_GotoXY(1, yPos - 4);
      GUI_DispSDec(-y / 20, 2);
      yPos = (LCD_YSIZE - 20) - YSIZE / 2 - y;
      GUI_DrawHLine(yPos, 13, 18);
      GUI_GotoXY(1, yPos - 4);
      GUI_DispSDec(y / 20, 2);
    } else {
      GUI_DispCharAt('0', 7, yPos - 4);
    }
  }
}

/*******************************************************************
*
*               Draws random data
*
********************************************************************
*/

static void GetRandomData(I16 * paY, int Time, int n) {
  int aDiff, i;
  if (Time > 5000)
    Time -= 5000;
  if (Time > 2500)
    Time = 5000 - Time;
  Time /= 200;
  aDiff = Time * Time + 1;
  for (i = 0; i < n; i++) {
    if (!i) {
      paY[i] = rand() % YSIZE;
    } else {
      I16 yNew;
      int yD = aDiff - (rand() % aDiff);
      if (rand() & 1) {
        yNew = paY[i-1] + yD;
      } else {
        yNew = paY[i-1] - yD;
      }
      if (yNew > YSIZE) {
        yNew -= yD;
      } else { if (yNew < 0)
        yNew += yD;
      }
      paY[i] = yNew;
    }
  }
}

static void DemoRandomGraph(void) {
  PARAM Param;
  int tDiff, t0;
  GUI_RECT Rect = {19, (LCD_YSIZE - 20) - YSIZE, (LCD_XSIZE - 2), (LCD_YSIZE - 21)};
  GUI_HMEM hMem = GUI_ALLOC_Alloc((LCD_XSIZE - 20) * sizeof(I16));
  GUI_SetColor(GUI_WHITE);
  GUI_SetBkColor(GUI_RED);
  GUI_ClearRect(0, 0, LCD_XSIZE, 60);
  GUI_SetFont(&GUI_FontComic18B_1);
  GUI_DispStringAt("Random graph", 10, 20);
  Param.aY = GUI_ALLOC_h2p(hMem);
  GUI_SetFont(&GUI_Font6x8);
  t0 = GUI_GetTime();
  while((tDiff = (GUI_GetTime() - t0)) < 10000) {
    int t1, tDiff2;
    GetRandomData(Param.aY, tDiff, (LCD_XSIZE - 20));
    t1 = GUI_GetTime();
    GUI_MEMDEV_Draw(&Rect, Draw, &Param, 0, 0);
    tDiff2 = GUI_GetTime() - t1;
    if (tDiff2 < 100) {
      GUI_Delay(100 - tDiff2);
    }
  }
  GUI_ALLOC_Free(hMem);
}

/*******************************************************************
*
*               Draws a sine wave
*
********************************************************************
*/

static void GetSineData(I16 * paY, int n) {
  int i;
  for (i = 0; i < n; i++) {
    float s = sin(i * DEG2RAD * 4);
    paY[i] = s * YSIZE / 2 + YSIZE / 2;
  }
}

static void DemoSineWave(void) {
  PARAM Param;
  I16 * pStart;
  int t0, Cnt = 0;
  GUI_RECT Rect = {19, (LCD_YSIZE - 20) - YSIZE, (LCD_XSIZE - 2), (LCD_YSIZE - 21)};
  GUI_HMEM hMem = GUI_ALLOC_Alloc(405 * sizeof(I16));
  GUI_SetColor(GUI_WHITE);
  GUI_SetBkColor(GUI_RED);
  GUI_ClearRect(0, 0, LCD_XSIZE, 60);
  GUI_SetFont(&GUI_FontComic18B_1);
  GUI_DispStringAt("Sine wave", 10, 20);
  pStart = GUI_ALLOC_h2p(hMem);
  GetSineData(pStart, 405);
  GUI_SetFont(&GUI_Font6x8);
  t0 = GUI_GetTime();
  while((GUI_GetTime() - t0) < 10000) {
    int t1, tDiff2;
    if (Cnt++ % 90) {
      Param.aY++;
    } else {
      Param.aY = pStart;
    }
    t1 = GUI_GetTime();
    GUI_MEMDEV_Draw(&Rect, Draw2, &Param, 0, 0);
    tDiff2 = GUI_GetTime() - t1;
    if (tDiff2 < 100) {
      GUI_Delay(100 - tDiff2);
    }
  }
  GUI_ALLOC_Free(hMem);
}

/*******************************************************************
*
*               Adds several waves
*
********************************************************************
*/

static void DrawOrData(GUI_COLOR Color, I16 * paY) {
  GUI_SetColor(Color);
  GUI_DrawGraph(paY, (LCD_XSIZE - 20), 19, (LCD_YSIZE - 20) - YSIZE);
}

static void DemoOrData(void) {
  int i;
  PARAM Param;
  GUI_RECT Rect = {19, (LCD_YSIZE - 20) - YSIZE, (LCD_XSIZE - 2), (LCD_YSIZE - 21)};
  GUI_HMEM hMem = GUI_ALLOC_Alloc(405 * sizeof(I16));
  GUI_SetColor(GUI_WHITE);
  GUI_SetBkColor(GUI_RED);
  GUI_ClearRect(0, 0, LCD_XSIZE, 60);
  GUI_SetFont(&GUI_FontComic18B_1);
  GUI_DispStringAt("Several waves...",0,20);
  Param.aY = GUI_ALLOC_h2p(hMem);
  GetSineData(Param.aY, 405);
  GUI_MEMDEV_Draw(&Rect, Draw, &Param, 0, 0);
  for (i = 0; (i < 90); i++) {
    DrawOrData(GUI_GREEN, ++Param.aY);
    GUI_Delay(10);
  }
  GUI_ALLOC_Free(hMem);
}

/*******************************************************************
*
*               main
*
********************************************************************
*/

void main(void) {
  GUI_Init();
  GUI_MEMDEV_Load();
  Label();
  while(1) {
    DemoRandomGraph();
    DemoSineWave();
    DemoOrData();
  }
}
