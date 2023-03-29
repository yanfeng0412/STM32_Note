#include "stm32f10x.h"                  // Device header
#include "OLED.h"
#include "stdio.h"
#include "OLED_BMP.h"
#include "OLED_GIF.h"
#include "Delay.h"


int main(void)
{
	uint8_t Num=66;
	OLED_Init();	//OLED初始化
	
	while(1)
	{
		OLED_Clear();
		
		//OLED显示汉字
		OLED_ShowChinese(1,1,0);	//电
		OLED_ShowChinese(1,2,1);  //子
		OLED_ShowChinese(1,3,2);  //信
		OLED_ShowChinese(1,4,3);  //息
		OLED_ShowChinese(1,5,4);  //工
		OLED_ShowChinese(1,6,5);  //程
		
		//OLED显示字符串
		OLED_ShowString(2,1,"Hello world");	
		
		//OLED显示单个字符
		OLED_ShowChar(3,1,'A');
		
		//OLED显示数字
		OLED_ShowNum(3,3,Num,2);
		
		Delay_ms(2000);
		OLED_Clear();	//清屏，显示图像
		
		//OLED显示图像
		OLED_ShowBMP(0,0,8,64,BMP);	//OLED显示图像
		
		Delay_ms(2000);
		OLED_Clear();	//清屏，显示gif
		
		//OLED显示gif
		for(int i=0;i<12;i++)
		{
			OLED_ShowBMP(0,0,8,64,cxk[i]);	//OLED显示gif
			Delay_ms(150);
		}
	}
}
