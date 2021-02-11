#include "reg52.h"
#include "PWM.h"

void Timer0Init()
{
	TMOD|=0X01;		//选择为定时器1模式，工作方式1，仅用TR1打开启动。

	TH0 = 0xFF; 
	TL0 = 0xff;		//1us
		
	ET0=1;			//打开定时器1中断允许
	EA=1;			//打开总中断
	TR0=1;			//打开定时器

	timer0 = 0;
}

void Timer1Init()
{
	TMOD|=0X10;		//选择为定时器1模式，工作方式1，仅用TR1打开启动。

	TH1 = 0xFF; 
	TL1 = 0xff;		//1us
		
	ET1=1;			//打开定时器1中断允许
	EA=1;			//打开总中断
	TR1=1;			//打开定时器

	timer0 = 0;
}

bit Time0_Flag(u16 max,u16 opp)
{
	bit flag;
	if(timer0 < opp)
	{
		flag = 1;
	}else{
		flag = 0;
	}
	if(timer0 == max)
	{
		timer0 = 0;
	}
	return flag;
}

bit Time1_Flag(u16 max,u16 opp)
{
	bit flag;
	if(timer1 < opp)
	{
		flag = 1;
	}else{
		flag = 0;
	}
	if(timer1 == max)
	{
		timer1 = 0;
	}
	return flag;
}

void duoji0(u8 baifenbi)
{
	u16 N_baifenbi;
	N_baifenbi = 200*baifenbi;
	PWM0 = Time0_Flag(20000,N_baifenbi);
	PWM1 = PWM0;
}

void duoji1(u8 baifenbi)
{
	u16 N_baifenbi;
	N_baifenbi = 200*baifenbi;
	PWM2 = Time1_Flag(20000,N_baifenbi);
	PWM3 = PWM2;
}

void Time0(void) interrupt 1    //3 为定时器1的中断号  1 定时器0的中断号 0 外部中断1 2 外部中断2  4 串口中断
{
	TH1 = 0xFF; 
	TL1 = 0xff;   //1us
	timer0++; 
}

void Time1(void) interrupt 3	//1us触发一次中断
{
	TH1 = 0xFF; 
	TL1 = 0xff;   //1us
	timer1++; 
}