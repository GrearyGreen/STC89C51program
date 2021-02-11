#include "reg52.h"
#include "intrins.h"

typedef unsigned char u8;
typedef unsigned int u16;

sbit LSA=P2^4;
sbit LSB=P2^3;
sbit LSC=P2^2;

u8 j,k = 0;

u8 code smgduan[10]={0x3f,0x06,0x5b,0x4f,0x66,
			0x6d,0x7d,0x07,0x7f,0x6f};

void Timer0Init();
void delay(u16 i);
void display();

void main()
{
	Timer0Init();
	while(1)
	{
		display();
	}
}

void Time0() interrupt 1
{
	static u16 i;
	TH0=0XFC;
	TL0=0X18;
	i++;
	if(i==1000)    // 1s
	{
		i=0;
		j++;
		if(j > 9)
		{
			j = 0;
			k++;
			if(k > 9)
			{
				k = 0;
			}
		}
	}
}

void display()
{
	LSA=0;LSB=0;LSC=0;
	P0=smgduan[j];
	delay(100);
	P0=0x00;
	LSA=0;LSB=0;LSC=1;
	P0=smgduan[k];
	delay(100);
	P0=0x00;
}

void Timer0Init()   // timer set 1ms
{
   TMOD|=0X01;
	 TH0=0XFC;
	 TL0=0X18;
	 ET0=1;
	 EA=1;
	 TR0=1;
}

void DigDisplay()
{
	u8 i;
	for(i=0;i<8;i++)
	{
		switch(i)
		{
			case (0): LSA=0;LSB=0;LSC=0;break;
			case (1): LSA=1;LSB=0;LSC=0;break;
			case (2): LSA=0;LSB=1;LSC=0;break;
			case (3): LSA=1;LSB=1;LSC=0;break;
			case (4): LSA=0;LSB=0;LSC=1;break;
			case (5): LSA=1;LSB=0;LSC=1;break;
			case (6): LSA=0;LSB=1;LSC=1;break;
			case (7): LSA=1;LSB=1;LSC=1;break;
		}
		P0=smgduan[i];
		delay(50000);
		P0=0x00;
	}
}

void delay(u16 i)
{
	while(i--);
}
