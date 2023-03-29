/**
 * @file spi.c
 * @author YEWANhub
 * @brief ʵ������SPI
 * @version V1.0.0
 * @date 2022-06-10
 * @encoding GB2312
 */
/******************************************************************************
	˵��: 
	----------------------------------------------------------------
	GND    ��Դ��
	VCC  ��5V��3.3v��Դ
	D0   ��PA5��SCL��
	D1   ��PA7��SDA��
	RES  ��PB0
	DC   ��PB1
	CS   ��PA4               
	----------------------------------------------------------------
******************************************************************************/
#include "sys.h"
#include "stm32f10x_rcc.h"
#include "stm32f10x_gpio.h"
#include "stm32f10x_spi.h"
#include "spi.h"

/**
 * @fn SPI_GPIO_Init
 * @brief ��ʼ��SPI
 * @return None
 */
void SPI_GPIO_Init(void)
{
	GPIO_InitTypeDef  GPIO_InitStructure;
 	
 	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	GPIO_InitStructure.GPIO_Pin = SPI_CS_Pin|SPI_SCLK_Pin|SPI_SDIN_Pin;
 	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
 	GPIO_Init(GPIOA, &GPIO_InitStructure);
 	GPIO_SetBits(GPIOA,SPI_SCLK_Pin|SPI_SDIN_Pin|SPI_CS_Pin);
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	GPIO_InitStructure.GPIO_Pin = SPI_RST_Pin|SPI_DC_Pin;
 	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
 	GPIO_Init(GPIOB, &GPIO_InitStructure);
 	GPIO_SetBits(GPIOB,SPI_RST_Pin|SPI_DC_Pin);
}

/**
 * @brief ������ӻ���SSD1306��д��һ���ֽ�
 * @param dat Ҫд�������/����
 * @param cmd ����/�����־ 0,��ʾ����;1,��ʾ����
 * @return None
 */
void SPI_WR_Byte(u8 dat, u8 cmd)
{
	u8 i;
	if(cmd) SPI_DC_Set();
	else SPI_DC_Clr();
	SPI_CS_Clr();
	for(i=0;i<8;i++)
	{
		SPI_SCLK_Clr();
		if(dat&0x80) SPI_SDIN_Set();
		else SPI_SDIN_Clr();
		SPI_SCLK_Set();
		dat<<=1;   
	}				 		  
	SPI_CS_Set();
	SPI_DC_Set();
}