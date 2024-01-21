#include "tim.h"
#include "sys.h"
#include "led.h"
#include "stm32f4xx.h"
#include "exit.h"  
#include "delay.h"
volatile unsigned char Second;
volatile unsigned char Minute;
volatile unsigned char Hour;
void TIM3_Init(u16 arr,u16 psc){

TIM_TimeBaseInitTypeDef TIM_BaseInitStructure;

NVIC_InitTypeDef NVIC_InitStructure;

    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);
	TIM_BaseInitStructure.TIM_Period=arr-1;
    TIM_BaseInitStructure.TIM_Prescaler=psc-1;
	TIM_BaseInitStructure.TIM_CounterMode=TIM_CounterMode_Up;//����
	TIM_BaseInitStructure.TIM_ClockDivision=TIM_CKD_DIV1;
	TIM_TimeBaseInit(TIM3,&TIM_BaseInitStructure);

	
	NVIC_InitStructure.NVIC_IRQChannel=TIM3_IRQn;                                                    
 
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=0x00;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority=0x00;
	NVIC_InitStructure.NVIC_IRQChannelCmd=ENABLE;
	NVIC_Init(&NVIC_InitStructure);//NVICʹ��
	
	TIM_ITConfig(TIM3,TIM_IT_Update,ENABLE);//�ж�ʹ��
	TIM_Cmd(TIM3,ENABLE);
	
	
}

void TIM4_Init(u16 arr,u16 psc){

TIM_TimeBaseInitTypeDef TIM_BaseInitStructure;

NVIC_InitTypeDef NVIC_InitStructure;

    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4, ENABLE);
	TIM_BaseInitStructure.TIM_Period=arr-1;
    TIM_BaseInitStructure.TIM_Prescaler=psc-1;
	TIM_BaseInitStructure.TIM_CounterMode=TIM_CounterMode_Up;//����
	TIM_BaseInitStructure.TIM_ClockDivision=TIM_CKD_DIV1;
	TIM_TimeBaseInit(TIM4,&TIM_BaseInitStructure);

	
	NVIC_InitStructure.NVIC_IRQChannel=TIM4_IRQn;                                                            
  
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=0x00;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority=0x00;
	NVIC_InitStructure.NVIC_IRQChannelCmd=ENABLE;
	NVIC_Init(&NVIC_InitStructure);//NVICʹ��
	
	TIM_ITConfig(TIM4,TIM_IT_Update,ENABLE);//�ж�ʹ��
	TIM_Cmd(TIM4,ENABLE);
	
	
}
//��ʱ��3�жϷ�����
void TIM3_IRQHandler(void)
{
	if(TIM_GetITStatus(TIM3,TIM_IT_Update)==SET) //����ж�
	{
	//GPIO_ToggleBits(GPIOB,GPIO_Pin_14);//��ת��ƽ
	}
	TIM_ClearITPendingBit(TIM3,TIM_IT_Update);  //����жϱ�־λ
}



//��ʱ��4�жϷ�����
void TIM4_IRQHandler(void)
{
	if(TIM_GetITStatus(TIM4,TIM_IT_Update)==SET) //����ж�
	{
		Second++;
		//TIM3_Init(8400,Pscnum[musicnum[flag++]]);//����Ԥ��Ƶϵ��psc
	}
	TIM_ClearITPendingBit(TIM4,TIM_IT_Update);  //����жϱ�־λ
}
void show_time(void)//��ʾʱ��
{  
		//float icm20602_temp;
		
		
    OLED_ShowString(1,3,"time:");
//	OLED_ShowSignedNum(3, 1, icm20602_gyro[0], 2);
//    OLED_ShowSignedNum(3, 5, icm20602_gyro[1], 2);
//	OLED_ShowSignedNum(3, 9, icm20602_gyro[2], 2);
	OLED_ShowSignedNum(3, 1,Hour, 2);//ʱ
	OLED_ShowChar(3,5,':');
	OLED_ShowSignedNum(3, 6,Minute, 2);//��
	OLED_ShowChar(3,9,':');
	OLED_ShowSignedNum(3, 10,Second, 2);//��
	
}