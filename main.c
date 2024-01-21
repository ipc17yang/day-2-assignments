#include "sys.h" //The <lwoopc.h> is already included here
#include "delay.h"
#include "usart.h"
#include "led.h"//����
#include "stdio.h"
#include "math.h"
#include "OLED.h"
#include "bee.h"  
#include "w25q128.h"
#include "HMC5883L.h"
#include "math.h"
//#include "icm20602.h"
#include "bmi088.h"
#include "bmp280.h"
#include "SPI1.h"
#include "exit.h"
#include "tim.h"
uint16_t DID;							//�������ڴ��DID�ŵı���

uint8_t ArrayWrite[] = {0x01, 0x02, 0x03, 0x04};	//����Ҫд�����ݵĲ�������
uint8_t ArrayRead[4];								//����Ҫ��ȡ���ݵĲ�������
extern volatile unsigned char Second;
extern volatile unsigned char Minute;
extern volatile unsigned char Hour;
int main(void)
{  

	delay_init(168);
	uart_init(9600);
	LED_Init();
	OLED_Init();
	 TIM4_Init(7500,16800);
	delay_ms(200);
	i2c_init();
	delay_ms(10);
	//exti_Init();
	while(1)
{
	
	show_time();//OLED显示
	//时钟时分秒变化
	if(Second>=60){
	    
		Minute++;
		Second=0;
	}
	if(Minute>=60){
	    Hour++;
		Minute=0;
	}
	if(Hour>=24){
	Hour=0;
	}
	
	delay_ms(500);
}
}

