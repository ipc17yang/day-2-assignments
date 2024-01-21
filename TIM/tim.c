#include "tim.h"
#include "sys.h"
#include "led.h"
#include "stm32f4xx.h"
#include "exit.h"  
#include "delay.h"
//定义三个变量
volatile unsigned char Second;
volatile unsigned char Minute;
volatile unsigned char Hour;
void TIM3_Init(u16 arr,u16 psc){

TIM_TimeBaseInitTypeDef TIM_BaseInitStructure;

NVIC_InitTypeDef NVIC_InitStructure;

    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);
	TIM_BaseInitStructure.TIM_Period=arr-1;
    TIM_BaseInitStructure.TIM_Prescaler=psc-1;
	TIM_BaseInitStructure.TIM_CounterMode=TIM_CounterMode_Up;//向上
	TIM_BaseInitStructure.TIM_ClockDivision=TIM_CKD_DIV1;
	TIM_TimeBaseInit(TIM3,&TIM_BaseInitStructure);

	
	NVIC_InitStructure.NVIC_IRQChannel=TIM3_IRQn;                                                    
 
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=0x00;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority=0x00;
	NVIC_InitStructure.NVIC_IRQChannelCmd=ENABLE;
	NVIC_Init(&NVIC_InitStructure);//NVIC使能
	
	TIM_ITConfig(TIM3,TIM_IT_Update,ENABLE);//中断使能
	TIM_Cmd(TIM3,ENABLE);
	
	
}

void TIM4_Init(u16 arr,u16 psc){

TIM_TimeBaseInitTypeDef TIM_BaseInitStructure;

NVIC_InitTypeDef NVIC_InitStructure;

    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4, ENABLE);
	TIM_BaseInitStructure.TIM_Period=arr-1;
    TIM_BaseInitStructure.TIM_Prescaler=psc-1;
	TIM_BaseInitStructure.TIM_CounterMode=TIM_CounterMode_Up;//向上
	TIM_BaseInitStructure.TIM_ClockDivision=TIM_CKD_DIV1;
	TIM_TimeBaseInit(TIM4,&TIM_BaseInitStructure);

	
	NVIC_InitStructure.NVIC_IRQChannel=TIM4_IRQn;                                                            
  
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=0x00;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority=0x00;
	NVIC_InitStructure.NVIC_IRQChannelCmd=ENABLE;
	NVIC_Init(&NVIC_InitStructure);//NVIC使能
	
	TIM_ITConfig(TIM4,TIM_IT_Update,ENABLE);//中断使能
	TIM_Cmd(TIM4,ENABLE);
	
	
}
//定时器3中断服务函数
void TIM3_IRQHandler(void)//未使用
{
	if(TIM_GetITStatus(TIM3,TIM_IT_Update)==SET) //溢出中断
	{
	//GPIO_ToggleBits(GPIOB,GPIO_Pin_14);//翻转电平
	}
	TIM_ClearITPendingBit(TIM3,TIM_IT_Update);  //清除中断标志位
}



//定时器4中断服务函数
void TIM4_IRQHandler(void)
{
	if(TIM_GetITStatus(TIM4,TIM_IT_Update)==SET) //溢出中断
	{
		Second++;//用TIM4来实现每秒加一，每一秒进入一次中断
		//TIM3_Init(8400,Pscnum[musicnum[flag++]]);//设置预分频系数psc
	}
	TIM_ClearITPendingBit(TIM4,TIM_IT_Update);  //清除中断标志位
}
void show_time(void)//显示时钟
{  
        OLED_ShowString(1,3,"time:");
	OLED_ShowSignedNum(3, 1,Hour, 2);//时
	OLED_ShowChar(3,5,':');
	OLED_ShowSignedNum(3, 6,Minute, 2);//分
	OLED_ShowChar(3,9,':');
	OLED_ShowSignedNum(3, 10,Second, 2);//秒
	
}
