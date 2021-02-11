#include "PWM.h"

void stop()
{
	IN1 = 0;
	IN2 = 0;
	IN3 = 0;
	IN4 = 0;
}

void stright()
{
	IN1 = 0;
	IN2 = 1;
	IN3 = 1;
	IN4 = 0;
}

void back()
{
	IN1 = 1;
	IN2 = 0;
	IN3 = 0;
	IN4 = 1;
}

void left()
{
	IN1 = 1;
	IN2 = 0;
	IN3 = 1;
	IN4 = 0;
}

void right()
{
	IN1 = 0;
	IN2 = 1;
	IN3 = 0;
	IN4 = 1;
}

void int_time1()
{
	TMOD|=0x01;
	TH0 = TEMP1;
	TL0 = TEMP2;
	ET0 = 1;
	EA = 1;
	TR0 = 1;
}

void int_time2()
{
	TMOD|=0x10;
	TH1 = TEMP1;
	TL1 = TEMP2;
	ET1 = 1;
	EA = 1;
	TR1 = 1;
}

void time1()interrupt 1
{
	static unsigned int i = 0;
	TH0 = TEMP1;
	TL0 = TEMP2;
	i++;
	if(i > left_time)
	{
		ENA = 1;
	}else{
		ENA = 0;
	}
	i = i%100;
}

void time2()interrupt 3
{
	static unsigned int j = 0;
	TH1 = TEMP1;
	TL2 = TEMP2;
	j++;
	if(j > right_time)
	{
		ENB = 1;
	}else{
		ENB = 0;
	}
	j = j%100;
}
