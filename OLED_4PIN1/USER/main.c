//////////////////////////////////////////////////////////////////////////////////	 
//本程序只供学习使用，未经作者许可，不得用于其它任何用途
//中景园电子
//店铺地址：http://shop73023976.taobao.com
//
//  文 件 名   : main.c
//  版 本 号   : v2.0
//  作    者   : HuangKai
//  生成日期   : 2018-10-31
//  最近修改   : 
//  功能描述   : OLED I2C接口演示例程(STM32F103系列)
//              说明: 
//              ----------------------------------------------------------------
//              GND  电源地
//              VCC  3.3v电源
//              D0   PA0（SCL）
//              D1   PA1（SDA）
//              RES  PA2（SPI模块改成IIC模块需要接此引脚，IIC模块用户请忽略）
//              ----------------------------------------------------------------
// 修改历史   :
// 日    期   : 
// 作    者   : HuangKai
// 修改内容   : 创建文件
//版权所有，盗版必究。
//Copyright(C) 中景园电子2018-10-31
//All rights reserved
//******************************************************************************/

#include "delay.h"
#include "sys.h"
#include "oled.h"
#include "bmp.h"
int time = 150;
const int NUM_BMPS = 18;
int BMP[NUM_BMPS];
#include <stdio.h>      // 包含 snprintf 函数
#include <stdlib.h>     // 包含 atoi 函数
#include <string.h>     // 包含字符串处理函数

int main(void)
{
	u8 t=' ';
	delay_init();
	
	OLED_Init();
	OLED_ColorTurn(0);//0正常显示，1 反色显示
  OLED_DisplayTurn(0);//0正常显示 1 屏幕翻转显示
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

