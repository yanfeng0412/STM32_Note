#include "stm32f10x.h"                  // Device header
#include "OLED.h"
#include "stdio.h"
#include "OLED_BMP.h"
#include "OLED_GIF.h"
#include "Delay.h"


int main(void)
{
	uint8_t Num=66;
	OLED_Init();	//OLED��ʼ��
	
	while(1)
	{
		OLED_Clear();
		
		//OLED��ʾ����
		OLED_ShowChinese(1,1,0);	//��
		OLED_ShowChinese(1,2,1);  //��
		OLED_ShowChinese(1,3,2);  //��
		OLED_ShowChinese(1,4,3);  //Ϣ
		OLED_ShowChinese(1,5,4);  //��
		OLED_ShowChinese(1,6,5);  //��
		
		//OLED��ʾ�ַ���
		OLED_ShowString(2,1,"Hello world");	
		
		//OLED��ʾ�����ַ�
		OLED_ShowChar(3,1,'A');
		
		//OLED��ʾ����
		OLED_ShowNum(3,3,Num,2);
		
		Delay_ms(2000);
		OLED_Clear();	//��������ʾͼ��
		
		//OLED��ʾͼ��
		OLED_ShowBMP(0,0,8,64,BMP);	//OLED��ʾͼ��
		
		Delay_ms(2000);
		OLED_Clear();	//��������ʾgif
		
		//OLED��ʾgif
		for(int i=0;i<12;i++)
		{
			OLED_ShowBMP(0,0,8,64,cxk[i]);	//OLED��ʾgif
			Delay_ms(150);
		}
	}
}
