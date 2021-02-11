#include "reg52.h"
#include "PWM.h"

void Timer0Init()
{
	TMOD|=0X01;		//ѡ��Ϊ��ʱ��1ģʽ��������ʽ1������TR1��������

	TH0 = 0xFF; 
	TL0 = 0xff;		//1us
		
	ET0=1;			//�򿪶�ʱ��1�ж�����
	EA=1;			//�����ж�
	TR0=1;			//�򿪶�ʱ��

	timer0 = 0;
}

void Timer1Init()
{
	TMOD|=0X10;		//ѡ��Ϊ��ʱ��1ģʽ��������ʽ1������TR1��������

	TH1 = 0xFF; 
	TL1 = 0xff;		//1us
		
	ET1=1;			//�򿪶�ʱ��1�ж�����
	EA=1;			//�����ж�
	TR1=1;			//�򿪶�ʱ��

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

void Time0(void) interrupt 1    //3 Ϊ��ʱ��1���жϺ�  1 ��ʱ��0���жϺ� 0 �ⲿ�ж�1 2 �ⲿ�ж�2  4 �����ж�
{
	TH1 = 0xFF; 
	TL1 = 0xff;   //1us
	timer0++; 
}

void Time1(void) interrupt 3	//1us����һ���ж�
{
	TH1 = 0xFF; 
	TL1 = 0xff;   //1us
	timer1++; 
}