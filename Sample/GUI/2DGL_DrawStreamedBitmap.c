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
File        : 2DGL_DrawStreamedBitmap.c
Purpose     : Shows how to draw bitmap stream data
----------------------------------------------------------------------
*/

#include "GUI.H"

/*******************************************************************
*
*       Bitmap stream, created by the bitmap converter
*
********************************************************************
*/

unsigned char abPhone[0x70] = {
  0x42, 0x4D, 0x64, 0x00, 0x20, 0x00, 0x16, 0x00, 0x04, 0x00, 0x01, 0x00, 0x02, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xF8, 0x00, 0x00, 0x1F, 
  0xE0, 0x00, 0x00, 0x07, 0xC0, 0x00, 0x00, 0x03, 0x80, 0x3F, 0xFC, 0x01, 0x80, 0x67, 0xE6, 0x01, 
  0x80, 0x67, 0xE6, 0x01, 0x80, 0x67, 0xE6, 0x01, 0xFF, 0xE7, 0xE7, 0xFF, 0xFE, 0x00, 0x00, 0x7F, 
  0xFC, 0x00, 0x00, 0x3F, 0xF8, 0x0D, 0xB0, 0x1F, 0xF0, 0x0D, 0xB0, 0x0F, 0xE0, 0x00, 0x00, 0x07, 
  0xE0, 0x0D, 0xB0, 0x07, 0xE0, 0x0D, 0xB0, 0x07, 0xE0, 0x00, 0x00, 0x07, 0xE0, 0x0D, 0xB0, 0x07, 
  0xE0, 0x0D, 0xB0, 0x07, 0xE0, 0x00, 0x00, 0x07, 0xE0, 0x00, 0x00, 0x07, 0xFF, 0xFF, 0xFF, 0xFF
};

/*******************************************************************
*
*       main
*
********************************************************************
*/

void main(void) {
  int x, y;
  GUI_BITMAP_STREAM * pStream = (GUI_BITMAP_STREAM *)abPhone;
  GUI_Init();
  while(1) {
    GUI_Clear();
    GUI_DispStringHCenterAt("Draws a streamed bitmap", 160, 0);
    GUI_Delay(500);
    for (x = 1; x < LCD_GetXSize() - pStream->XSize; x += pStream->XSize + 1) {
      for (y = 16; y < LCD_GetYSize() - pStream->YSize; y += pStream->YSize + 1) {
        GUI_DrawStreamedBitmap((GUI_BITMAP_STREAM *)abPhone, x, y);
      }
    }
    GUI_Delay(500);
  }
}
