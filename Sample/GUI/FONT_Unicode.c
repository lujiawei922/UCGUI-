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
File        : FONT_Unicode.c
Purpose     : Example demonstrating UNICODE capabilities of emWin
----------------------------------------------------------------------
*/

#include "GUI.H"

/*******************************************************************
*
*         Definition of font containing UNICODE characters
*
********************************************************************
*/

/* Start of unicode area <Basic Latin> */
static const unsigned char acFontUC13_0041[ 13] = { /* code 0041 */
  ________,
  ________,
  ___X____,
  ___X____,
  __X_X___,
  __X_X___,
  __X_X___,
  _XXXXX__,
  _X___X__,
  _X___X__,
  XXX_XXX_,
  ________,
  ________};

static const unsigned char acFontUC13_0042[ 13] = { /* code 0042 */
  ________,
  ________,
  XXXXX___,
  _X___X__,
  _X___X__,
  _X___X__,
  _XXXX___,
  _X___X__,
  _X___X__,
  _X___X__,
  XXXXX___,
  ________,
  ________};

static const unsigned char acFontUC13_0043[ 13] = { /* code 0043 */
  ________,
  ________,
  __XX_X__,
  _X__XX__,
  X____X__,
  X_______,
  X_______,
  X_______,
  X_______,
  _X___X__,
  __XXX___,
  ________,
  ________};

/* Start of unicode area <Hiragana> */
static const unsigned char acFontUC13_3060[ 26] = { /* code 3060 */
  ___XX___,X_X_____,
  ____X___,_X_X____,
  X___XXX_,________,
  _XXXX___,________,
  ___X__XX,XXX_____,
  ___X____,X_______,
  ___X___X,________,
  __X_____,________,
  __X__X__,________,
  _X___X__,________,
  _X____XX,XXX_____,
  ________,________,
  ________,________};

static const unsigned char acFontUC13_3061[ 26] = { /* code 3061 */
  ___XX___,________,
  ____X___,________,
  X___XXXX,XX______,
  _XXXX___,________,
  ___X____,________,
  ___X_XXX,X_______,
  __XXX___,_X______,
  __X_____,__X_____,
  ________,__X_____,
  ________,_X______,
  ___XXXXX,X_______,
  ________,________,
  ________,________};

static const unsigned char acFontUC13_3062[ 26] = { /* code 3062 */
  ___XX___,X_X_____,
  ____X___,_X_X____,
  X___XXXX,X_______,
  _XXXX___,________,
  ___X____,________,
  ___X_XXX,X_______,
  __XXX___,_X______,
  __X_____,__X_____,
  ________,__X_____,
  ________,_X______,
  ___XXXXX,X_______,
  ________,________,
  ________,________};

static const GUI_CHARINFO GUI_FontUC13_CharInfo[6] = {
   {   7,   7,  1, (void *)&acFontUC13_0041 } /* code 0041 */
  ,{   7,   7,  1, (void *)&acFontUC13_0042 } /* code 0042 */
  ,{   7,   7,  1, (void *)&acFontUC13_0043 } /* code 0043 */
  ,{  14,  14,  2, (void *)&acFontUC13_3060 } /* code 3060 */
  ,{  14,  14,  2, (void *)&acFontUC13_3061 } /* code 3061 */
  ,{  14,  14,  2, (void *)&acFontUC13_3062 } /* code 3062 */
};

static const GUI_FONT_PROP GUI_FontUC13_Prop2 = {
   0x3060 /* first character */
  ,0x3062 /* last character  */
  ,&GUI_FontUC13_CharInfo[  3] /* address of first character */
  ,(void*)0 /* pointer to next GUI_FONT_PROP */
};

static const GUI_FONT_PROP GUI_FontUC13_Prop1 = {
   0x0041 /* first character */
  ,0x0043 /* last character  */
  ,&GUI_FontUC13_CharInfo[  0] /* address of first character */
  ,(void *)&GUI_FontUC13_Prop2 /* pointer to next GUI_FONT_PROP */
};

static const GUI_FONT GUI_FontUC13 = {
   GUI_FONTTYPE_PROP /* type of font    */
  ,13 /* height of font  */
  ,13 /* space of font y */
  ,1 /* magnification x */
  ,1 /* magnification y */
  ,(void *)&GUI_FontUC13_Prop1
};

/*******************************************************************
*
*  Definition of string containing ASCII and UNICODE characters
*
********************************************************************
*/

static const char sUC_ASCII [] = {
  "ABC"GUI_UC_START"\x30\x60\x30\x61\x30\x62"GUI_UC_END"\x0"
};

/*******************************************************************
*
*        Demonstrates output of UNICODE characters
*
********************************************************************
*/

static void DemoUNICODE(void) {
  GUI_SetFont(&GUI_Font13HB_1);
  GUI_DispStringHCenterAt("µC/GUI-sample: UNICODE characters", 160, 0);
  /* Set ShiftJIS font */
  GUI_SetFont(&GUI_FontUC13);
  /* Display string */
  GUI_DispStringHCenterAt(sUC_ASCII, 160, 40);
}

/*******************************************************************
*
*                 main
*
********************************************************************
*/

void main(void) {
  GUI_Init();
  DemoUNICODE();
  while(1)
    GUI_Delay(100);
}
