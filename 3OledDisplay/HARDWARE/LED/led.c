#include "led.h"
  

//��ʼ��PA0Ϊ�����.��ʹ��ʱ��		    
//LED ��ʼ��


void LED_Init(void)
{
 
 GPIO_InitTypeDef  GPIO_InitStructure;
 	
 RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);	 //ʹ��PA0�˿�ʱ��
	
 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13;				 //LED0-->PA0�˿�����
 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 //�������
 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //IO���ٶ�Ϊ50MHz
 GPIO_Init(GPIOC, &GPIO_InitStructure);	  				
 GPIO_SetBits(GPIOC,GPIO_Pin_13);	
}
 
