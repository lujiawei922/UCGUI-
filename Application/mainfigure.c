/*
*********************************************************************************************************
*                                                �C/GUI
*                        Universal graphic software for embedded applications
*
*                       (c) Copyright 2002, Micrium Inc., Weston, FL
*                       (c) Copyright 2000, SEGGER Microcontroller Systeme GmbH          
*
*              �C/GUI is protected by international copyright laws. Knowledge of the
*              source code may not be used to write a similar product. This file may
*              only be used in accordance with a license and should not be redistributed 
*              in any way. We appreciate your understanding and fairness.
*
* File        : Main.c
* Purpose     : Application program in windows simulator
*********************************************************************************************************
*/


#include "GUI.h"

extern const GUI_BITMAP bmMicriumLogo;
extern const GUI_BITMAP bmMicriumLogo_1bpp;


/*
  *******************************************************************
  *
  *              main()
  *
  *******************************************************************
*/
void main(void) {

  while(1)
  {
	
	float f = 123.45678;
  //int LCDXSize = LCD_GET_XSIZE();
  //int LCDYSize = LCD_GET_YSIZE();
    GUI_Init();
  //int tmp = -12345;
	//GUI_DispDec(-123456,8);			//��д8�����֣������λ��0
	/*
	GUI_DispString("Min");
	GUI_DispDec(12,2);
	GUI_DispString("Sec:");
	GUI_DispDec(2,2);
	*/	
	//GUI_DispDecAt(-1234,54,89,9);		//��ʾ�����������Ϊ9���㲹0
	//GUI_DispDecMin(-1234567);			//�Զ�ʹ����С�ĳ���ֵ
	
	//GUI_DispDecShift(2131234,9,2);		//���9λ����λС�������㲹0
	
	//GUI_DispDecSpace(342674,100);			//�ո�λ�����9������
	
	//GUI_DispSDecShift(12231,9,2);			//һ�������ţ����㲹0
	/*
	//������
	GUI_SetFont(&GUI_Font8x8);
	GUI_DispStringAt("GUI_DispFloat:\n",0,0);
	GUI_DispFloat(f,9);					//��֧����λΪ0����ֵΪ��ʱ��ʾ����
    
	*/
	//GUI_DispFloatFix(-3213.234,9,1);	//֧����λΪ0,С����Ϊ1λ
	
	//GUI_DispFloatMin(-12313.22,1);		//��Сλ����ʾ��С��λΪ1
	
		
	 //GUI_DispSFloatFix(13312.11,9,1);					//֧����λΪ0������ʾ����
	 //GUI_DispSFloatMin(1231.123,2);				//��֧����λΪ0������ʾ����,С����λ
	 //������
	 //GUI_DispBin(1233,16);					      //��ʾ��������ֵ			
	 
	 //GUI_DispBinAt(1233,10,10,8);					//�ڹ̶�λ����ʾ������
	 
	 //ʮ������
	 //GUI_DispHex(3312332,8);						//��ʾ16���ƣ�8�����ֲ�ȫ��0
	 //GUI_DispHexAt(798432,67,78,8);								//��ָ��λ����ʾ16��������

	 //GUI_GetVersionString();						//��ʾuc/GUI�İ汾
	 
	GUI_Delay(10000);
  }
}

