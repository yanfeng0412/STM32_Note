#include "OLED_Font.h"
#include "stm32f10x.h"
#include "Delay.h"

//PB12接D0、PB13接D1、PB14接RES、PB15接DC、PA8接CS（也可根据自己的引脚改）
/*引脚配置*/
#define OLED_W_D0(x)		GPIO_WriteBit(GPIOA, GPIO_Pin_5, (BitAction)(x))
#define OLED_W_D1(x)		GPIO_WriteBit(GPIOA, GPIO_Pin_7, (BitAction)(x))
#define OLED_W_RES(x)		GPIO_WriteBit(GPIOB, GPIO_Pin_0, (BitAction)(x))
#define OLED_W_DC(x)		GPIO_WriteBit(GPIOB, GPIO_Pin_1, (BitAction)(x))
#define OLED_W_CS(x)		GPIO_WriteBit(GPIOA, GPIO_Pin_4, (BitAction)(x))

/*引脚初始化*/
void OLED_SPI_Init(void)
{
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructure;
 	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5; //D0
 	GPIO_Init(GPIOA, &GPIO_InitStructure);
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7; //D1
 	GPIO_Init(GPIOA, &GPIO_InitStructure);
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0; //RES
 	GPIO_Init(GPIOB, &GPIO_InitStructure);
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1; //DC
 	GPIO_Init(GPIOB, &GPIO_InitStructure);
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4;  //CS
 	GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	OLED_W_D0(1);
	OLED_W_D1(1);
	OLED_W_RES(1);
	OLED_W_DC(1);
	OLED_W_CS(1);
}

/**
  * @brief  SPI发送一个字节
  * @param  Byte 要发送的一个字节
  * @retval 无
  */
void OLED_SPI_SendByte(uint8_t Byte)
{
	uint8_t i;
	for (i = 0; i < 8; i++)
	{
		OLED_W_D0(0);
		OLED_W_D1(Byte & (0x80 >> i));
		OLED_W_D0(1);
	}
}

/**
  * @brief  OLED写命令
  * @param  Command 要写入的命令
  * @retval 无
  */
void OLED_WriteCmd(uint8_t Command)
{
	OLED_W_CS(0);
	OLED_W_DC(0);
	OLED_SPI_SendByte(Command);
	OLED_W_CS(1);
}

/**
  * @brief  OLED写数据
  * @param  Data 要写入的数据
  * @retval 无
  */
void OLED_WriteData(uint8_t Data)
{
	OLED_W_CS(0);
	OLED_W_DC(1);
	OLED_SPI_SendByte(Data);
	OLED_W_CS(1);
}

/**
  * @brief  OLED设置光标位置
  * @param  Y 以左上角为原点，向下方向的坐标，范围：0~7
  * @param  X 以左上角为原点，向右方向的坐标，范围：0~127
  * @retval 无
  */
void OLED_SetCursor(uint8_t Y, uint8_t X)
{
	OLED_WriteCmd(0xB0 | Y);									//设置Y位置
	OLED_WriteCmd(0x10 | ((X & 0xF0) >> 4));	//设置X位置高4位
	OLED_WriteCmd(0x00 | (X & 0x0F));					//设置X位置低4位
}

/**
  * @brief  OLED清屏
  * @param  无
  * @retval 无
  */
void OLED_Clear(void)
{  
	uint8_t i, j;
	for (j = 0; j < 8; j++)
	{
		OLED_SetCursor(j, 0);
		for(i = 0; i < 128; i++)
		{
			OLED_WriteData(0x00);
		}
	}
}

/**
  * @brief  OLED显示一个字符
  * @param  Line 行位置，范围：1~4
  * @param  Column 列位置，范围：1~16
  * @param  Char 要显示的一个字符，范围：ASCII可见字符
  * @retval 无
  */
void OLED_ShowChar(uint8_t Line, uint8_t Column, char Char)
{      	
	uint8_t i;
	OLED_SetCursor((Line - 1) * 2, (Column - 1) * 8);		//设置光标位置在上半部分
	for (i = 0; i < 8; i++)
	{
		OLED_WriteData(OLED_F8x16[Char - ' '][i]);			//显示上半部分内容
	}
	OLED_SetCursor((Line - 1) * 2 + 1, (Column - 1) * 8);	//设置光标位置在下半部分
	for (i = 0; i < 8; i++)
	{
		OLED_WriteData(OLED_F8x16[Char - ' '][i + 8]);		//显示下半部分内容
	}
}

/**
  * @brief  OLED显示字符串
  * @param  Line 起始行位置，范围：1~4
  * @param  Column 起始列位置，范围：1~16
  * @param  String 要显示的字符串，范围：ASCII可见字符
  * @retval 无
  */
void OLED_ShowString(uint8_t Line, uint8_t Column, char *String)
{
	uint8_t i;
	for (i = 0; String[i] != '\0'; i++)
	{
		OLED_ShowChar(Line, Column + i, String[i]);
	}
}

/**
  * @brief  OLED显示汉字
  * @param  Line 起始行位置，范围：1~4
  * @param  Column 起始列位置，范围：1~16
  * @param  No：要显示汉字的个数
  * @param  Length 要显示数字的长度，范围：1~16
  * @retval 无
  */
void OLED_ShowChinese(uint8_t Line,uint8_t Column,uint8_t No)
{
	uint8_t i;
	OLED_SetCursor((Line-1)*2,(Column-1)*16);
	for(i=0;i<16;i++)
	{
		OLED_WriteData(Chinese[2*No][i]);
	}
	OLED_SetCursor((Line-1)*2+1,(Column-1)*16);
	for(i=0;i<16;i++)
	{
		OLED_WriteData(Chinese[2*No+1][i]);
	}
}

/**
  * @brief  OLED显示图像
  * @param  Row1 起始行位置，范围：0~8
  * @param  Column1 起始列位置，范围：0~128
  * @param  Row2 起始行位置，范围：0~8
  * @param  Column2 起始列位置，范围：0~128
  * @param  BMP1：要显示gif的数组
  * @retval 无
  */
void OLED_ShowBMP(uint8_t Row1, uint8_t Column1,uint8_t Row2, uint8_t Column2,uint8_t BMP1[])
{     
 unsigned int i=0;
 unsigned char x,y;
  
//  if(y1%8==0) y=y1/8;      
//  else y=y1/8+1;
    for(x=Row1;x<Row2;x++)
    {
        OLED_SetCursor(x,Column1);
    for(y=Column1;y<Column2;y++)
        {      
            OLED_WriteData(BMP1[i++]);            
        }
    }
} 

/**
  * @brief  OLED次方函数
  * @retval 返回值等于X的Y次方
  */
uint32_t OLED_Pow(uint32_t X, uint32_t Y)
{
	uint32_t Result = 1;
	while (Y--)
	{
		Result *= X;
	}
	return Result;
}

/**
  * @brief  OLED显示数字（十进制，正数）
  * @param  Line 起始行位置，范围：1~4
  * @param  Column 起始列位置，范围：1~16
  * @param  Number 要显示的数字，范围：0~4294967295
  * @param  Length 要显示数字的长度，范围：1~10
  * @retval 无
  */
void OLED_ShowNum(uint8_t Line, uint8_t Column, uint32_t Number, uint8_t Length)
{
	uint8_t i;
	for (i = 0; i < Length; i++)							
	{
		OLED_ShowChar(Line, Column + i, Number / OLED_Pow(10, Length - i - 1) % 10 + '0');
	}
}

/**
  * @brief  OLED显示数字（十进制，带符号数）
  * @param  Line 起始行位置，范围：1~4
  * @param  Column 起始列位置，范围：1~16
  * @param  Number 要显示的数字，范围：-2147483648~2147483647
  * @param  Length 要显示数字的长度，范围：1~10
  * @retval 无
  */
void OLED_ShowSignedNum(uint8_t Line, uint8_t Column, int32_t Number, uint8_t Length)
{
	uint8_t i;
	uint32_t Number1;
	if (Number >= 0)
	{
		OLED_ShowChar(Line, Column, '+');
		Number1 = Number;
	}
	else
	{
		OLED_ShowChar(Line, Column, '-');
		Number1 = -Number;
	}
	for (i = 0; i < Length; i++)							
	{
		OLED_ShowChar(Line, Column + i + 1, Number1 / OLED_Pow(10, Length - i - 1) % 10 + '0');
	}
}

/**
  * @brief  OLED显示数字（十六进制，正数）
  * @param  Line 起始行位置，范围：1~4
  * @param  Column 起始列位置，范围：1~16
  * @param  Number 要显示的数字，范围：0~0xFFFFFFFF
  * @param  Length 要显示数字的长度，范围：1~8
  * @retval 无
  */
void OLED_ShowHexNum(uint8_t Line, uint8_t Column, uint32_t Number, uint8_t Length)
{
	uint8_t i, SingleNumber;
	for (i = 0; i < Length; i++)							
	{
		SingleNumber = Number / OLED_Pow(16, Length - i - 1) % 16;
		if (SingleNumber < 10)
		{
			OLED_ShowChar(Line, Column + i, SingleNumber + '0');
		}
		else
		{
			OLED_ShowChar(Line, Column + i, SingleNumber - 10 + 'A');
		}
	}
}

/**
  * @brief  OLED显示数字（二进制，正数）
  * @param  Line 起始行位置，范围：1~4
  * @param  Column 起始列位置，范围：1~16
  * @param  Number 要显示的数字，范围：0~1111 1111 1111 1111
  * @param  Length 要显示数字的长度，范围：1~16
  * @retval 无
  */
void OLED_ShowBinNum(uint8_t Line, uint8_t Column, uint32_t Number, uint8_t Length)
{
	uint8_t i;
	for (i = 0; i < Length; i++)							
	{
		OLED_ShowChar(Line, Column + i, Number / OLED_Pow(2, Length - i - 1) % 2 + '0');
	}
}


void OLED_CloseRoll(void)
{
    //以下添加水平滚动效果
    OLED_WriteCmd(0x2e);//关滚动
    OLED_WriteCmd(0x2a);//29向右，2a向左
    OLED_WriteCmd(0x00);//A:空字节
    OLED_WriteCmd(0x00);//B:水平起始页
    OLED_WriteCmd(0x07);//C:水平滚动速度
    OLED_WriteCmd(0x07);//D:水平结束页
    OLED_WriteCmd(0x00);//E:每次垂直滚动位移
//    OLED_WriteCmd(0x2f);//开滚动
}
void OLED_OpenRoll(void)
{
    //以下添加水平滚动效果
    OLED_WriteCmd(0x2f);//开滚动
}

/**
  * @brief  OLED初始化
  * @param  无
  * @retval 无
  */
void OLED_Init(void)
{
	Delay_ms(5);	//上电延时一小会
	
	OLED_SPI_Init();			//端口初始化
	
	OLED_WriteCmd(0xAE);	//关闭显示
	
	OLED_WriteCmd(0xD5);	//设置显示时钟分频比/振荡器频率
	OLED_WriteCmd(0x80);
	
	OLED_WriteCmd(0xA8);	//设置多路复用率
	OLED_WriteCmd(0x3F);
	
	OLED_WriteCmd(0xD3);	//设置显示偏移
	OLED_WriteCmd(0x00);
	
	OLED_WriteCmd(0x40);	//设置显示开始行
	
	OLED_WriteCmd(0xA1);	//设置左右方向，0xA1正常 0xA0左右反置
	
	OLED_WriteCmd(0xC8);	//设置上下方向，0xC8正常 0xC0上下反置

	OLED_WriteCmd(0xDA);	//设置COM引脚硬件配置
	OLED_WriteCmd(0x12);
	
	OLED_WriteCmd(0x81);	//设置对比度控制
	OLED_WriteCmd(0xCF);

	OLED_WriteCmd(0xD9);	//设置预充电周期
	OLED_WriteCmd(0xF1);

	OLED_WriteCmd(0xDB);	//设置VCOMH取消选择级别
	OLED_WriteCmd(0x30);

	OLED_WriteCmd(0xA4);	//设置整个显示打开/关闭

	OLED_WriteCmd(0xA6);	//设置正常/倒转显示

	OLED_WriteCmd(0x8D);	//设置充电泵
	OLED_WriteCmd(0x14);

	OLED_WriteCmd(0xAF);	//开启显示
		
	OLED_Clear();				//OLED清屏
}
