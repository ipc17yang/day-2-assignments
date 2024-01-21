#ifndef __TIM_H
#define  __TIM_H
#include "stm32f4xx.h"
 #include "delay.h"
#include "usart.h"
#include "OLED.h"
#include "sys.h"
void TIM3_Init(u16 arr,u16 psc);//arr自动重装载值，psc
void TIM4_Init(u16 arr,u16 psc);
void TIM3_IRQHandler(void);
void TIM4_IRQHandler(void);
 void show_time(void);
#endif