#include "reg52.h"


unsigned char pwm_left_val = 150;
unsigned char pwm_right_val = 210;
unsigned char pwm_t;

//定义红外扫描的传感器
sbit IN_OUT1_R = P3^1;
sbit IN_OUT2_L = P3^0;

//
sbit ENA = P3^6;
sbit ENB = P3^7;

sbit IN1 = P2^7;
sbit IN2 = P2^6;
sbit IN3 = P2^5;
sbit IN4 = P2^4;

void main()
{
	TMOD |= 0x02;
	TH0 = 0XFE;
	TL0 = 0X33;
	TR0 = 1;
	ET0 = 1;
	EA	= 1;
	while(1)
	{
		IN1 = 0;
		IN2 = 1;
		IN3 = 1;
		IN4 = 0;
	}
}

void timer0() interrupt 1
{
	pwm_t++;
	if(pwm_t == 255)
		pwm_t = ENA = ENB = 0;
	if(pwm_left_val <= pwm_t)
	{
		ENA = 1;
		ENB = 1;
	}		
}