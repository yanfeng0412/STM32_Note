//////////////////////////////////////////////////////////////////////////////////	 
//������ֻ��ѧϰʹ�ã�δ��������ɣ��������������κ���;
//�о�԰����
//���̵�ַ��http://shop73023976.taobao.com
//
//  �� �� ��   : main.c
//  �� �� ��   : v2.0
//  ��    ��   : HuangKai
//  ��������   : 2018-10-31
//  ����޸�   : 
//  ��������   : OLED I2C�ӿ���ʾ����(STM32F103ϵ��)
//              ˵��: 
//              ----------------------------------------------------------------
//              GND  ��Դ��
//              VCC  3.3v��Դ
//              D0   PA0��SCL��
//              D1   PA1��SDA��
//              RES  PA2��SPIģ��ĳ�IICģ����Ҫ�Ӵ����ţ�IICģ���û�����ԣ�
//              ----------------------------------------------------------------
// �޸���ʷ   :
// ��    ��   : 
// ��    ��   : HuangKai
// �޸�����   : �����ļ�
//��Ȩ���У�����ؾ���
//Copyright(C) �о�԰����2018-10-31
//All rights reserved
//******************************************************************************/

#include "delay.h"
#include "sys.h"
#include "oled.h"
#include "bmp.h"
int time = 150;
const int NUM_BMPS = 18;
int BMP[NUM_BMPS];
#include <stdio.h>      // ���� snprintf ����
#include <stdlib.h>     // ���� atoi ����
#include <string.h>     // �����ַ���������

int main(void)
{
	u8 t=' ';
	delay_init();
	
	OLED_Init();
	OLED_ColorTurn(0);//0������ʾ��1 ��ɫ��ʾ
  OLED_DisplayTurn(0);//0������ʾ 1 ��Ļ��ת��ʾ
	while(1)
	{
//		for (int i = 0; i <NUM_BMPS;i++){
//			   char str[20];
//			snprintf(str, 20, "BMP_%d", i + 1);
//			BMP[i] = atoi(str);
//			 BMP[i] = atoi(("BMP_" + to_string(i+1)).c_str());
//			OLED_ShowPicture(0,0,128,32,BMP[i],1);
//			OLED_Refresh();
//			delay_ms(time);
//			OLED_Clear();
//		}
		OLED_ShowPicture(0,0,128,32,BMP50,1);
		OLED_Refresh();
		delay_ms(time);
		OLED_Clear();
		OLED_ShowPicture(0,0,128,32,BMP51,1);
		OLED_Refresh();
		delay_ms(time);
		OLED_Clear();
		OLED_ShowPicture(0,0,128,32,BMP52,1);
		OLED_Refresh();
		delay_ms(time);
		OLED_Clear();
		OLED_ShowPicture(0,0,128,32,BMP53,1);
		OLED_Refresh();
		delay_ms(time);
		OLED_Clear();
		OLED_ShowPicture(0,0,128,32,BMP54,1);
		OLED_Refresh();
		delay_ms(time);
		OLED_Clear();
		OLED_ShowPicture(0,0,128,32,BMP55,1);
		OLED_Refresh();
		delay_ms(time);
		OLED_Clear();
		OLED_ShowPicture(0,0,128,32,BMP56,1);
		OLED_Refresh();
		delay_ms(time);
		OLED_Clear();
		OLED_ShowPicture(0,0,128,32,BMP57,1);
		OLED_Refresh();
		delay_ms(time);
		OLED_Clear();
		OLED_ShowPicture(0,0,128,32,BMP58,1);
		OLED_Refresh();
		delay_ms(time);
		OLED_Clear();
		OLED_ShowPicture(0,0,128,32,BMP59,1);
		OLED_Refresh();
		delay_ms(time);
		OLED_Clear();
		OLED_ShowPicture(0,0,128,32,BMP60,1);
		OLED_Refresh();
		delay_ms(time);
		OLED_Clear();
		OLED_ShowPicture(0,0,128,32,BMP61,1);
		OLED_Refresh();
		delay_ms(time);
		OLED_Clear();
		OLED_ShowPicture(0,0,128,32,BMP62,1);
		OLED_Refresh();
		delay_ms(time);
		OLED_Clear();
		OLED_ShowPicture(0,0,128,32,BMP63,1);
		OLED_Refresh();
		delay_ms(time);
		OLED_Clear();
		OLED_ShowPicture(0,0,128,32,BMP64,1);
		OLED_Refresh();
		delay_ms(time);
		OLED_Clear();
		OLED_ShowPicture(0,0,128,32,BMP65,1);
		OLED_Refresh();
		delay_ms(time);
		OLED_Clear();
		OLED_ShowPicture(0,0,128,32,BMP66,1);
		OLED_Refresh();
		delay_ms(time);
		OLED_Clear();
		OLED_ShowPicture(0,0,128,32,BMP67,1);
		OLED_Refresh();
		delay_ms(time);
		OLED_Clear();
		OLED_ShowPicture(0,0,128,32,BMP68,1);
		OLED_Refresh();
		delay_ms(time);
		OLED_Clear();
//		OLED_ShowPicture(0,0,128,32,BMP20,1);
//		OLED_Refresh();
//		delay_ms(time);
//		OLED_Clear();
//		OLED_ShowPicture(0,0,128,32,BMP21,1);
//		OLED_Refresh();
//		delay_ms(time);
//		OLED_Clear();
//		OLED_ShowPicture(0,0,128,32,BMP22,1);
//		OLED_Refresh();
//		delay_ms(time);
//		OLED_Clear();
		
		
		


	}
}

