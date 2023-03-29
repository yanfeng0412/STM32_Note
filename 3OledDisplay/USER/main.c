/******************************************************************

ʵ������:

	STM32C8T6+0.96��OLED
	
ʵ��Ŀ��:

	����̫����ÿ֡ͼƬ
	
Ӳ����Դ:

	OLED0A��
	SCK <-------> PB9
	SDA <-------> PB8
	
	OLED0B��
	SCK <-------> PB10
	SDA <-------> PB11
	
	SPI OLED1��
		PA4 ------> CS
		PA5 ------> SCL/D0
		PA6 ------> D/C������/���
		PA7 ------> SDA/D1
		PB0 ------> RESET

ע������:

	ԭ�����ߣ�Bilibili --->ϲ���������ķ��ѽ� ---> UID 151266770 
	
******************************************************************/

/***********************************************************************************************
 ***                   P R O J E C T  ---  I N F O R M A T I O N                             ***
 ***********************************************************************************************
 *                                                                                             *
 *                 Project Name : ����OLED����̫���˶���                                       *
 *                                                                                             *
 *                    File Name : MAIN.C                                                       *
 *                                                                                             *
 *                   Programmer : Ƕ��ʽ����  UID:606618908[Bilibili]                          *
 *                                                                                             *
 *                   Start Date : ---------------                                              *
 *                                                                                             *
 *                  Last Update : February 21, 2023                                            *
 *                                                                                             *
 *---------------------------------------------------------------------------------------------*/
#include "led.h"
#include "delay.h"
#include "sys.h"
#include "oled.h"
#include "bmp.h"
#include "bmp1.h"
uint8_t dsp_flg = 0;   // 0:������Ļһ����ʾ�� 1����A ��   2����B��
uint32_t dsp_count = 0;  // ��ʾ����
void display_startup(void)  //��������
{	
	OLED_DrawBMPFast(cartoon1);
	OLED1_DrawBMPFast(cartoon1);
	OLED_DrawBMPFast(cartoon2);
	OLED1_DrawBMPFast(cartoon2);
	OLED_DrawBMPFast(cartoon3);
	OLED1_DrawBMPFast(cartoon3);
	OLED_DrawBMPFast(cartoon1_1);
	OLED1_DrawBMPFast(cartoon1_1);
	OLED_DrawBMPFast(cartoon1_2);
	OLED1_DrawBMPFast(cartoon1_2);
	OLED_DrawBMPFast(cartoon1_3);
	OLED1_DrawBMPFast(cartoon1_3);
	OLED_DrawBMPFast(cartoon1_4);
	OLED1_DrawBMPFast(cartoon1_4);
	OLED_DrawBMPFast(cartoon1_5);
	OLED1_DrawBMPFast(cartoon1_5);
	OLED_DrawBMPFast(cartoon1_6);
	OLED1_DrawBMPFast(cartoon1_6);
	OLED_DrawBMPFast(cartoon1_5);
	OLED1_DrawBMPFast(cartoon1_5);
	OLED_DrawBMPFast(cartoon1_4);
	OLED1_DrawBMPFast(cartoon1_4);
	OLED_DrawBMPFast(cartoon1_3);
	OLED1_DrawBMPFast(cartoon1_3);
	OLED_DrawBMPFast(cartoon1_2);
	OLED1_DrawBMPFast(cartoon1_2);
	OLED1_DrawBMPFast(cartoon1_1);
	OLED_DrawBMPFast(cartoon1_1);
	OLED1_DrawBMPFast(cartoon3);
	OLED_DrawBMPFast(cartoon3);
	OLED1_DrawBMPFast(cartoon2);
	OLED_DrawBMPFast(cartoon2);
	OLED1_DrawBMPFast(cartoon1);	
	OLED_DrawBMPFast(cartoon1);
	delay_ms(1000);
	OLED_Clear(); //OLED����
}

void OLED0(void)
{
	OLED_DrawBMPFast(gImage_1);
	OLED_DrawBMPFast(gImage_2);
	OLED_DrawBMPFast(gImage_3);
	OLED_DrawBMPFast(gImage_4);
	OLED_DrawBMPFast(gImage_5);
	OLED_DrawBMPFast(gImage_6);
	OLED_DrawBMPFast(gImage_7);
	OLED_DrawBMPFast(gImage_8);
	OLED_DrawBMPFast(gImage_9);
	OLED_DrawBMPFast(gImage_10);
	OLED_DrawBMPFast(gImage_11);
	OLED_DrawBMPFast(gImage_12);
	OLED_DrawBMPFast(gImage_13);
	OLED_DrawBMPFast(gImage_14);
	OLED_DrawBMPFast(gImage_15);
	OLED_DrawBMPFast(gImage_16);
	OLED_DrawBMPFast(gImage_17);	
	OLED_DrawBMPFast(gImage_18);
	OLED_DrawBMPFast(gImage_19);
	OLED_DrawBMPFast(gImage_20);
}
uint8_t speed = 10;
void OLED1(void)
{
	dsp_flg = 0;
	OLED_DrawBMPFast(BMP1);
	for(dsp_count = 0 ; dsp_count <10 ; dsp_count++)
	{
		OLED1_DrawBMPFast(gImage_1);delay_ms(speed);
		OLED1_DrawBMPFast(gImage_2);delay_ms(speed);
		OLED1_DrawBMPFast(gImage_3);delay_ms(speed);
		OLED1_DrawBMPFast(gImage_4);delay_ms(speed);
		OLED1_DrawBMPFast(gImage_5);delay_ms(speed);
		OLED1_DrawBMPFast(gImage_6);delay_ms(speed);
		OLED1_DrawBMPFast(gImage_7);delay_ms(speed);
		OLED1_DrawBMPFast(gImage_8);delay_ms(speed);
		OLED1_DrawBMPFast(gImage_9);delay_ms(speed);
		OLED1_DrawBMPFast(gImage_10);delay_ms(speed);
		OLED1_DrawBMPFast(gImage_11);delay_ms(speed);
		OLED1_DrawBMPFast(gImage_12);delay_ms(speed);
		OLED1_DrawBMPFast(gImage_13);delay_ms(speed);
		OLED1_DrawBMPFast(gImage_14);delay_ms(speed);
		OLED1_DrawBMPFast(gImage_15);delay_ms(speed);
		OLED1_DrawBMPFast(gImage_16);delay_ms(speed);
		OLED1_DrawBMPFast(gImage_17);	delay_ms(speed);
		OLED1_DrawBMPFast(gImage_18);delay_ms(speed);
		OLED1_DrawBMPFast(gImage_19);delay_ms(speed);
		OLED1_DrawBMPFast(gImage_20);delay_ms(speed);
	}
}

void OLED1AndOLED(void)
{
	dsp_flg = 0;
	for(dsp_count = 0 ; dsp_count <100 ; dsp_count++)
	{
		OLED_DrawBMPFast(gImage_1);
		OLED1_DrawBMPFast(gImage_1);
		OLED_DrawBMPFast(gImage_2);
		OLED1_DrawBMPFast(gImage_2);
		OLED_DrawBMPFast(gImage_3);
		OLED1_DrawBMPFast(gImage_3);
		OLED_DrawBMPFast(gImage_4);
		OLED1_DrawBMPFast(gImage_4);
		OLED_DrawBMPFast(gImage_5);
		OLED1_DrawBMPFast(gImage_5);
		OLED_DrawBMPFast(gImage_6);
		OLED1_DrawBMPFast(gImage_6);
		OLED_DrawBMPFast(gImage_7);
		OLED1_DrawBMPFast(gImage_7);
		OLED_DrawBMPFast(gImage_8);
		OLED1_DrawBMPFast(gImage_8);
		OLED_DrawBMPFast(gImage_9);
		OLED1_DrawBMPFast(gImage_9);
		OLED_DrawBMPFast(gImage_10);
		OLED1_DrawBMPFast(gImage_10);
		OLED_DrawBMPFast(gImage_11);
		OLED1_DrawBMPFast(gImage_11);
		OLED_DrawBMPFast(gImage_12);
		OLED1_DrawBMPFast(gImage_12);
		OLED_DrawBMPFast(gImage_13);
		OLED1_DrawBMPFast(gImage_13);
		OLED_DrawBMPFast(gImage_14);
		OLED1_DrawBMPFast(gImage_14);
		OLED_DrawBMPFast(gImage_15);
		OLED1_DrawBMPFast(gImage_15);
		OLED_DrawBMPFast(gImage_16);
		OLED1_DrawBMPFast(gImage_16);
		OLED_DrawBMPFast(gImage_17);	
		OLED1_DrawBMPFast(gImage_17);
		OLED_DrawBMPFast(gImage_18);
		OLED1_DrawBMPFast(gImage_18);
		OLED_DrawBMPFast(gImage_19);
		OLED1_DrawBMPFast(gImage_19);
		OLED_DrawBMPFast(gImage_20);
		OLED1_DrawBMPFast(gImage_20);
	}
	OLED_Clear(); //OLED����
	OLED1_Clear(); //OLED����
}
 
void OnlyOLED0_A(void)
{
//	dsp_flg = 0;
////	OLED_Clear();
	dsp_flg = 2;
	for(dsp_count = 0 ; dsp_count <10 ; dsp_count++)
	{
		OLED0();
	}
}

void OnlyOLED0_B(void)
{
	dsp_flg = 0;
	OLED_DrawBMPFast(BMP1);
	dsp_flg = 1;
	for(dsp_count = 0 ; dsp_count <10 ; dsp_count++)
	{
		OLED0();
	}
	OLED_Clear();
}

void OLED0_AB_ALL(void)
{
	dsp_flg = 0;
	OLED0();
}

int main(void)
 {	
	delay_init();	    	 //��ʱ������ʼ��	  
	OLED_Init();
	OLED1_Init();
	OLED_Clear(); //OLED����
	OLED1_Clear();
	display_startup();
	OLED_DrawBMPFast(BMP1);
	OLED1_DrawBMPFast(BMP1); 
	while(1)
	{
		OnlyOLED0_A();
		OnlyOLED0_B();
		OLED1();
		OLED1AndOLED();
//		OLED0_AB_ALL();
	}
 }

