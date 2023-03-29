#ifndef __OLED_H__
#define __OLED_H__


void OLED_Init(void);
void OLED_Clear(void);
void OLED_ShowChar(uint8_t Line, uint8_t Column, char Char);
void OLED_ShowString(uint8_t Line, uint8_t Column, char *String);
void OLED_ShowNum(uint8_t Line, uint8_t Column, uint32_t Number, uint8_t Length);
void OLED_ShowSignedNum(uint8_t Line, uint8_t Column, int32_t Number, uint8_t Length);
void OLED_ShowHexNum(uint8_t Line, uint8_t Column, uint32_t Number, uint8_t Length);
void OLED_ShowBinNum(uint8_t Line, uint8_t Column, uint32_t Number, uint8_t Length);
void OLED_ShowChinese(uint8_t Line,uint8_t Column,uint8_t No);
void OLED_ShowBMP(uint8_t Row1, uint8_t Column1,uint8_t Row2, uint8_t Column2,uint8_t BMP1[]);
void OLED_ShowChinese(uint8_t Line,uint8_t Column,uint8_t No);

#endif
