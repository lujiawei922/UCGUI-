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
File        : WIDGET_PhoneButton.c
Purpose     : Example demonstrating the use of a BUTTON widget
----------------------------------------------------------------------
*/

#include "gui.h"
#include "button.h"

/*******************************************************************
*
*                 Bitmap data, 2 phone logos
*
********************************************************************
*/

static const GUI_COLOR Colors[] = { 0x000000, 0xFFFFFF };
static const GUI_LOGPALETTE Palette = { 2, 1, Colors };
static const unsigned char acPhone0[] = {
  ________, ________, ________, ________,
  ________, ________, ________, ________,
  ________, ________, ________, ________,
  ________, ________, ________, ________,
  ________, ________, ________, ________,
  ________, ________, ________, ________,
  ________, ________, ________, ________,
  ________, ________, ________, ________,
  ________, ________, ________, ________,
  ________, ________, ________, ________,
  ________, ________, ________, ________,
  _____XXX, XXXXXXXX, XXXXXXXX, XXX_____,
  ___XXXXX, XXXXXXXX, XXXXXXXX, XXXXX___,
  __XXXXXX, XXXXXXXX, XXXXXXXX, XXXXXX__,
  _XXXXXXX, X_______, _______X, XXXXXXX_,
  _XXXXXXX, X__XX___, ___XX__X, XXXXXXX_,
  _XXXXXXX, X__XX___, ___XX__X, XXXXXXX_,
  _XXXXXXX, X__XX___, ___XX__X, XXXXXXX_,
  ________, ___XX___, ___XX___, ________,
  _______X, XXXXXXXX, XXXXXXXX, X_______,
  ______XX, XXXXXXXX, XXXXXXXX, XX______,
  _____XXX, XXXX__X_, _X__XXXX, XXX_____,
  ____XXXX, XXXX__X_, _X__XXXX, XXXX____,
  ___XXXXX, XXXXXXXX, XXXXXXXX, XXXXX___,
  ___XXXXX, XXXX__X_, _X__XXXX, XXXXX___,
  ___XXXXX, XXXX__X_, _X__XXXX, XXXXX___,
  ___XXXXX, XXXXXXXX, XXXXXXXX, XXXXX___,
  ___XXXXX, XXXX__X_, _X__XXXX, XXXXX___,
  ___XXXXX, XXXX__X_, _X__XXXX, XXXXX___,
  ___XXXXX, XXXXXXXX, XXXXXXXX, XXXXX___,
  ___XXXXX, XXXXXXXX, XXXXXXXX, XXXXX___
};
static const unsigned char acPhone1[] = {
  ______XX, X_______, ________, ________,
  ____XXXX, XXXXX___, ________, ________,
  ____XXXX, XXXXXXX_, ________, ________,
  ___XXXXX, XXXXXXXX, X_______, ________,
  ___XXXXX, XXXXXXXX, XXX_____, ________,
  _____XXX, XXXX_XXX, XXXXX___, ________,
  _______X, XXXX___X, XXXXXXX_, ________,
  ________, _XX_____, _XXXXXXX, X_______,
  ________, ________, ___XXXXX, XXX_____,
  ________, ________, _____XXX, XXXXX___,
  ________, ________, _______X, XXXXXX__,
  ________, ________, ________, XXXXXXX_,
  ________, ________, ________, XXXXXXX_,
  ________, ________, _______X, XXXXXXXX,
  ________, ________, _______X, XXXXXXXX,
  ________, ___XX___, ___XX___, _XXXXXXX,
  ________, ___XX___, ___XX___, ___XXXX_,
  ________, ___XX___, ___XX___, _____XX_,
  ________, ___XX___, ___XX___, ________,
  _______X, XXXXXXXX, XXXXXXXX, X_______,
  ______XX, XXXXXXXX, XXXXXXXX, XX______,
  _____XXX, XXXX__X_, _X__XXXX, XXX_____,
  ____XXXX, XXXX__X_, _X__XXXX, XXXX____,
  ___XXXXX, XXXXXXXX, XXXXXXXX, XXXXX___,
  ___XXXXX, XXXX__X_, _X__XXXX, XXXXX___,
  ___XXXXX, XXXX__X_, _X__XXXX, XXXXX___,
  ___XXXXX, XXXXXXXX, XXXXXXXX, XXXXX___,
  ___XXXXX, XXXX__X_, _X__XXXX, XXXXX___,
  ___XXXXX, XXXX__X_, _X__XXXX, XXXXX___,
  ___XXXXX, XXXXXXXX, XXXXXXXX, XXXXX___,
  ___XXXXX, XXXXXXXX, XXXXXXXX, XXXXX___
};
static const GUI_BITMAP bm_1bpp_0 = { 32, 31, 4, 1, acPhone0, &Palette};
static const GUI_BITMAP bm_1bpp_1 = { 32, 31, 4, 1, acPhone1, &Palette};

/*******************************************************************
*
*            Demonstrates the use of a BUTTON widget
*
********************************************************************
*/

static void DemoButton(void) {
  BUTTON_Handle hButton;
  int Stat = 0;
  GUI_Init();
  GUI_SetFont(&GUI_Font8x16);
  GUI_DispStringHCenterAt("Click on phone button...", 160,0);
  /* Create the button */
  hButton = BUTTON_Create(142, 20, 36, 40, GUI_ID_OK, WM_CF_SHOW);
  /* Modify the button attributes */
  BUTTON_SetBkColor(hButton, 1, GUI_RED);
  BUTTON_SetBitmapEx(hButton, 0, &bm_1bpp_0, 2, 4);
  BUTTON_SetBitmapEx(hButton, 1, &bm_1bpp_1, 2, 4);
  /* Loop until button is pressed */
  while(GUI_GetKey() != GUI_ID_OK) {
    if (Stat ^= 1) {
      BUTTON_SetState(hButton, 
                      BUTTON_STATE_HASFOCUS | BUTTON_STATE_INACTIVE);
    } else {
      BUTTON_SetState(hButton, 
                      BUTTON_STATE_HASFOCUS | BUTTON_STATE_PRESSED);
    }
    GUI_Delay(500);
  }
  /* Delete button object */
  BUTTON_Delete(hButton);
}

/*******************************************************************
*
*                 main
*
********************************************************************
*/

void main(void) {
  GUI_Init();
  DemoButton();
}
